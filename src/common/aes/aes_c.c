// Simple, thoroughly commented implementation of 128-bit AES / Rijndael using C
// Chris Hulbert - chris.hulbert@gmail.com - http://splinter.com.au/blog
// References:
// http://en.wikipedia.org/wiki/Advanced_Encryption_Standard
// http://en.wikipedia.org/wiki/Rijndael_key_schedule
// http://en.wikipedia.org/wiki/Rijndael_mix_columns
// http://en.wikipedia.org/wiki/Rijndael_S-box
// This code is public domain, or any OSI-approved license, your choice. No warranty.
// SPDX-License-Identifier: MIT

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "aes.h"
#include <oqs/common.h>

typedef unsigned char byte;

// Here are all the lookup tables for the row shifts, rcon, s-boxes, and galois field multiplications
static const byte shift_rows_table[] = {0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12, 1, 6, 11};
static const byte lookup_rcon[] = {
	0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a
};
static const byte lookup_sbox[] = {
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
static const byte lookup_g2[] = {
	0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
	0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e,
	0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e,
	0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e,
	0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e,
	0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe,
	0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde,
	0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe,
	0x1b, 0x19, 0x1f, 0x1d, 0x13, 0x11, 0x17, 0x15, 0x0b, 0x09, 0x0f, 0x0d, 0x03, 0x01, 0x07, 0x05,
	0x3b, 0x39, 0x3f, 0x3d, 0x33, 0x31, 0x37, 0x35, 0x2b, 0x29, 0x2f, 0x2d, 0x23, 0x21, 0x27, 0x25,
	0x5b, 0x59, 0x5f, 0x5d, 0x53, 0x51, 0x57, 0x55, 0x4b, 0x49, 0x4f, 0x4d, 0x43, 0x41, 0x47, 0x45,
	0x7b, 0x79, 0x7f, 0x7d, 0x73, 0x71, 0x77, 0x75, 0x6b, 0x69, 0x6f, 0x6d, 0x63, 0x61, 0x67, 0x65,
	0x9b, 0x99, 0x9f, 0x9d, 0x93, 0x91, 0x97, 0x95, 0x8b, 0x89, 0x8f, 0x8d, 0x83, 0x81, 0x87, 0x85,
	0xbb, 0xb9, 0xbf, 0xbd, 0xb3, 0xb1, 0xb7, 0xb5, 0xab, 0xa9, 0xaf, 0xad, 0xa3, 0xa1, 0xa7, 0xa5,
	0xdb, 0xd9, 0xdf, 0xdd, 0xd3, 0xd1, 0xd7, 0xd5, 0xcb, 0xc9, 0xcf, 0xcd, 0xc3, 0xc1, 0xc7, 0xc5,
	0xfb, 0xf9, 0xff, 0xfd, 0xf3, 0xf1, 0xf7, 0xf5, 0xeb, 0xe9, 0xef, 0xed, 0xe3, 0xe1, 0xe7, 0xe5
};
static const byte lookup_g3[] = {
	0x00, 0x03, 0x06, 0x05, 0x0c, 0x0f, 0x0a, 0x09, 0x18, 0x1b, 0x1e, 0x1d, 0x14, 0x17, 0x12, 0x11,
	0x30, 0x33, 0x36, 0x35, 0x3c, 0x3f, 0x3a, 0x39, 0x28, 0x2b, 0x2e, 0x2d, 0x24, 0x27, 0x22, 0x21,
	0x60, 0x63, 0x66, 0x65, 0x6c, 0x6f, 0x6a, 0x69, 0x78, 0x7b, 0x7e, 0x7d, 0x74, 0x77, 0x72, 0x71,
	0x50, 0x53, 0x56, 0x55, 0x5c, 0x5f, 0x5a, 0x59, 0x48, 0x4b, 0x4e, 0x4d, 0x44, 0x47, 0x42, 0x41,
	0xc0, 0xc3, 0xc6, 0xc5, 0xcc, 0xcf, 0xca, 0xc9, 0xd8, 0xdb, 0xde, 0xdd, 0xd4, 0xd7, 0xd2, 0xd1,
	0xf0, 0xf3, 0xf6, 0xf5, 0xfc, 0xff, 0xfa, 0xf9, 0xe8, 0xeb, 0xee, 0xed, 0xe4, 0xe7, 0xe2, 0xe1,
	0xa0, 0xa3, 0xa6, 0xa5, 0xac, 0xaf, 0xaa, 0xa9, 0xb8, 0xbb, 0xbe, 0xbd, 0xb4, 0xb7, 0xb2, 0xb1,
	0x90, 0x93, 0x96, 0x95, 0x9c, 0x9f, 0x9a, 0x99, 0x88, 0x8b, 0x8e, 0x8d, 0x84, 0x87, 0x82, 0x81,
	0x9b, 0x98, 0x9d, 0x9e, 0x97, 0x94, 0x91, 0x92, 0x83, 0x80, 0x85, 0x86, 0x8f, 0x8c, 0x89, 0x8a,
	0xab, 0xa8, 0xad, 0xae, 0xa7, 0xa4, 0xa1, 0xa2, 0xb3, 0xb0, 0xb5, 0xb6, 0xbf, 0xbc, 0xb9, 0xba,
	0xfb, 0xf8, 0xfd, 0xfe, 0xf7, 0xf4, 0xf1, 0xf2, 0xe3, 0xe0, 0xe5, 0xe6, 0xef, 0xec, 0xe9, 0xea,
	0xcb, 0xc8, 0xcd, 0xce, 0xc7, 0xc4, 0xc1, 0xc2, 0xd3, 0xd0, 0xd5, 0xd6, 0xdf, 0xdc, 0xd9, 0xda,
	0x5b, 0x58, 0x5d, 0x5e, 0x57, 0x54, 0x51, 0x52, 0x43, 0x40, 0x45, 0x46, 0x4f, 0x4c, 0x49, 0x4a,
	0x6b, 0x68, 0x6d, 0x6e, 0x67, 0x64, 0x61, 0x62, 0x73, 0x70, 0x75, 0x76, 0x7f, 0x7c, 0x79, 0x7a,
	0x3b, 0x38, 0x3d, 0x3e, 0x37, 0x34, 0x31, 0x32, 0x23, 0x20, 0x25, 0x26, 0x2f, 0x2c, 0x29, 0x2a,
	0x0b, 0x08, 0x0d, 0x0e, 0x07, 0x04, 0x01, 0x02, 0x13, 0x10, 0x15, 0x16, 0x1f, 0x1c, 0x19, 0x1a
};
// Xor's all elements in a n byte array a by b
static void xor (byte *a, const byte *b, int n) {
	int i;
	for (i = 0; i < n; i++) {
		a[i] ^= b[i];
	}
}

// Xor the current cipher state by a specific round key
static void xor_round_key(byte *state, const byte *keys, int round) {
	xor(state, keys + round * 16, 16);
}

// Apply the rijndael s-box to all elements in an array
// http://en.wikipedia.org/wiki/Rijndael_S-box
static void sub_bytes(byte *a, int n) {
	int i;
	for (i = 0; i < n; i++) {
		a[i] = lookup_sbox[a[i]];
	}
}

// Rotate the first four bytes of the input eight bits to the left
static inline void rot_word(byte *a) {
	byte temp = a[0];
	a[0] = a[1];
	a[1] = a[2];
	a[2] = a[3];
	a[3] = temp;
}

// Perform the core key schedule transform on 4 bytes, as part of the key expansion process
// http://en.wikipedia.org/wiki/Rijndael_key_schedule#Key_schedule_core
static void key_schedule_core(byte *a, int i) {
	byte temp = a[0]; // Rotate the output eight bits to the left
	a[0] = a[1];
	a[1] = a[2];
	a[2] = a[3];
	a[3] = temp;
	sub_bytes(a, 4);        // Apply Rijndael's S-box on all four individual bytes in the output word
	a[0] ^= lookup_rcon[i]; // On just the first (leftmost) byte of the output word, perform the rcon operation with i
	// as the input, and exclusive or the rcon output with the first byte of the output word
}

// Expand the 16-byte key to 11 round keys (176 bytes)
// http://en.wikipedia.org/wiki/Rijndael_key_schedule#The_key_schedule
void oqs_aes128_load_schedule_c(const uint8_t *key, void **_schedule) {
	*_schedule = malloc(16 * 11);
	OQS_EXIT_IF_NULLPTR(*_schedule);
	uint8_t *schedule = (uint8_t *) *_schedule;
	int bytes = 16;            // The count of how many bytes we've created so far
	int i = 1;                 // The rcon iteration value i is set to 1
	int j;                     // For repeating the second stage 3 times
	byte t[4];                 // Temporary working area known as 't' in the Wiki article
	memcpy(schedule, key, 16); // The first 16 bytes of the expanded key are simply the encryption key

	while (bytes < 176) {                   // Until we have 176 bytes of expanded key, we do the following:
		memcpy(t, schedule + bytes - 4, 4); // We assign the value of the previous four bytes in the expanded key to t
		key_schedule_core(t, i);            // We perform the key schedule core on t, with i as the rcon iteration value
		i++;                                // We increment i by 1
		xor(t, schedule + bytes - 16, 4);   // We exclusive-or t with the four-byte block 16 bytes before the new expanded key.
		memcpy(schedule + bytes, t, 4);     // This becomes the next 4 bytes in the expanded key
		bytes += 4;                         // Keep track of how many expanded key bytes we've added

		// We then do the following three times to create the next twelve bytes
		for (j = 0; j < 3; j++) {
			memcpy(t, schedule + bytes - 4, 4); // We assign the value of the previous 4 bytes in the expanded key to t
			xor(t, schedule + bytes - 16, 4);   // We exclusive-or t with the four-byte block n bytes before
			memcpy(schedule + bytes, t, 4);     // This becomes the next 4 bytes in the expanded key
			bytes += 4;                         // Keep track of how many expanded key bytes we've added
		}
	}
}

void oqs_aes128_free_schedule_c(void *schedule) {
	if (schedule != NULL) {
		OQS_MEM_secure_free(schedule, 176);
	}
}

// Expand the 16-byte key to 15 round keys (240 bytes)
// http://en.wikipedia.org/wiki/Rijndael_key_schedule#The_key_schedule
void oqs_aes256_load_schedule_c(const uint8_t *key, void **_schedule) {
	*_schedule = malloc(16 * 15);
	OQS_EXIT_IF_NULLPTR(*_schedule);
	uint8_t *schedule = (uint8_t *) *_schedule;
	int i = 0;    // The count of how many iterations we've done
	uint8_t t[4]; // Temporary working area

	// The first 32 bytes of the expanded key are simply the encryption key
	memcpy(schedule, key, 8 * 4);

	// The remaining 240-32 bytes of the expanded key are computed in one of three ways:
	for (i = 8; i < 4 * 15; i++) {
		if (i % 8 == 0) {
			memcpy(t, schedule + 4 * (i - 1), 4); // We assign the value of the previous 4 bytes in the expanded key to t
			sub_bytes(t, 4);                      // We apply byte-wise substitution to t
			rot_word(t);                          // We rotate t one byte left
			t[0] ^= lookup_rcon[i / 8];           // We xor in the round constant
			xor(t, schedule + 4 * (i - 8), 4);    // We xor in the four-byte block n bytes before
			memcpy(schedule + 4 * i, t, 4);       // This becomes the next 4 bytes in the expanded key
		} else if (i % 8 == 4) {
			memcpy(t, schedule + 4 * (i - 1), 4); // We assign the value of the previous 4 bytes in the expanded key to t
			sub_bytes(t, 4);                      // We apply byte-wise substitution to t
			xor(t, schedule + 4 * (i - 8), 4);    // We xor in the four-byte block n bytes before
			memcpy(schedule + 4 * i, t, 4);       // This becomes the next 4 bytes in the expanded key
		} else {
			memcpy(t, schedule + 4 * (i - 1), 4); // We assign the value of the previous 4 bytes in the expanded key to t
			xor(t, schedule + 4 * (i - 8), 4);    // We xor in the four-byte block n bytes before
			memcpy(schedule + 4 * i, t, 4);       // This becomes the next 4 bytes in the expanded key
		}
	}
}

void oqs_aes256_free_schedule_c(void *schedule) {
	if (schedule != NULL) {
		OQS_MEM_secure_free(schedule, 16 * 15);
	}
}

// Apply the shift rows step on the 16 byte cipher state
// http://en.wikipedia.org/wiki/Advanced_Encryption_Standard#The_ShiftRows_step
static void shift_rows(byte *state) {
	int i;
	byte temp[16];
	memcpy(temp, state, 16);
	for (i = 0; i < 16; i++) {
		state[i] = temp[shift_rows_table[i]];
	}
}

// Perform the mix columns matrix on one column of 4 bytes
// http://en.wikipedia.org/wiki/Rijndael_mix_columns
static void mix_col(byte *state) {
	byte a0 = state[0];
	byte a1 = state[1];
	byte a2 = state[2];
	byte a3 = state[3];
	state[0] = lookup_g2[a0] ^ lookup_g3[a1] ^ a2 ^ a3;
	state[1] = lookup_g2[a1] ^ lookup_g3[a2] ^ a3 ^ a0;
	state[2] = lookup_g2[a2] ^ lookup_g3[a3] ^ a0 ^ a1;
	state[3] = lookup_g2[a3] ^ lookup_g3[a0] ^ a1 ^ a2;
}

// Perform the mix columns matrix on each column of the 16 bytes
static void mix_cols(byte *state) {
	mix_col(state);
	mix_col(state + 4);
	mix_col(state + 8);
	mix_col(state + 12);
}

// Perform the inverse mix columns matrix on each column of the 16 bytes
static void mix_cols_inv(byte *state) {
	mix_col_inv(state);
	mix_col_inv(state + 4);
	mix_col_inv(state + 8);
	mix_col_inv(state + 12);
}
#endif

void oqs_aes128_enc_sch_block_c(const uint8_t *plaintext, const void *_schedule, uint8_t *ciphertext) {
	const uint8_t *schedule = (const uint8_t *) _schedule;
	int i; // To count the rounds

	// First Round
	memcpy(ciphertext, plaintext, 16);
	xor_round_key(ciphertext, schedule, 0);

	// Middle rounds
	for (i = 0; i < 9; i++) {
		sub_bytes(ciphertext, 16);
		shift_rows(ciphertext);
		mix_cols(ciphertext);
		xor_round_key(ciphertext, schedule, i + 1);
	}

	// Final Round
	sub_bytes(ciphertext, 16);
	shift_rows(ciphertext);
	xor_round_key(ciphertext, schedule, 10);
}

void oqs_aes256_enc_sch_block_c(const uint8_t *plaintext, const void *_schedule, uint8_t *ciphertext) {
	const uint8_t *schedule = (const uint8_t *) _schedule;
	int i; // To count the rounds

	// First Round
	memcpy(ciphertext, plaintext, 16);
	xor_round_key(ciphertext, schedule, 0);

	// Middle rounds
	for (i = 0; i < 13; i++) {
		sub_bytes(ciphertext, 16);
		shift_rows(ciphertext);
		mix_cols(ciphertext);
		xor_round_key(ciphertext, schedule, i + 1);
	}

	// Final Round
	sub_bytes(ciphertext, 16);
	shift_rows(ciphertext);
	xor_round_key(ciphertext, schedule, 14);
}
