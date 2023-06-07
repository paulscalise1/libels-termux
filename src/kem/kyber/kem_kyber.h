// SPDX-License-Identifier: MIT

#ifndef OQS_KEM_KYBER_H
#define OQS_KEM_KYBER_H

#include <oqs/oqs.h>

#ifdef OQS_ENABLE_KEM_kyber_512
#define OQS_KEM_kyber_512_length_public_key 800
#define OQS_KEM_kyber_512_length_secret_key 1632
#define OQS_KEM_kyber_512_length_ciphertext 768
#define OQS_KEM_kyber_512_length_shared_secret 32
OQS_KEM *OQS_KEM_kyber_512_new(void);
OQS_API OQS_STATUS OQS_KEM_kyber_512_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_KEM_kyber_512_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key);
OQS_API OQS_STATUS OQS_KEM_kyber_512_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key);
#ifdef OQS_HAZARDOUS_ENABLE_DERIVE_KEYPAIR
#define OQS_KEM_kyber_512_length_randomness 64
OQS_API OQS_STATUS OQS_KEM_kyber_512_derive_keypair(const uint8_t *randomness, uint8_t *public_key, uint8_t *secret_key);
#endif
#endif

#ifdef OQS_ENABLE_KEM_kyber_768
#define OQS_KEM_kyber_768_length_public_key 1184
#define OQS_KEM_kyber_768_length_secret_key 2400
#define OQS_KEM_kyber_768_length_ciphertext 1088
#define OQS_KEM_kyber_768_length_shared_secret 32
OQS_KEM *OQS_KEM_kyber_768_new(void);
OQS_API OQS_STATUS OQS_KEM_kyber_768_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_KEM_kyber_768_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key);
OQS_API OQS_STATUS OQS_KEM_kyber_768_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key);
#ifdef OQS_HAZARDOUS_ENABLE_DERIVE_KEYPAIR
#define OQS_KEM_kyber_768_length_randomness 64
OQS_API OQS_STATUS OQS_KEM_kyber_768_derive_keypair(const uint8_t *randomness, uint8_t *public_key, uint8_t *secret_key);
#endif
#endif

#ifdef OQS_ENABLE_KEM_kyber_1024
#define OQS_KEM_kyber_1024_length_public_key 1568
#define OQS_KEM_kyber_1024_length_secret_key 3168
#define OQS_KEM_kyber_1024_length_ciphertext 1568
#define OQS_KEM_kyber_1024_length_shared_secret 32
OQS_KEM *OQS_KEM_kyber_1024_new(void);
OQS_API OQS_STATUS OQS_KEM_kyber_1024_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_KEM_kyber_1024_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key);
OQS_API OQS_STATUS OQS_KEM_kyber_1024_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key);
#ifdef OQS_HAZARDOUS_ENABLE_DERIVE_KEYPAIR
#define OQS_KEM_kyber_1024_length_randomness 64
OQS_API OQS_STATUS OQS_KEM_kyber_1024_derive_keypair(const uint8_t *randomness, uint8_t *public_key, uint8_t *secret_key);
#endif
#endif

#ifdef OQS_ENABLE_KEM_kyber_512_90s
#define OQS_KEM_kyber_512_90s_length_public_key 800
#define OQS_KEM_kyber_512_90s_length_secret_key 1632
#define OQS_KEM_kyber_512_90s_length_ciphertext 768
#define OQS_KEM_kyber_512_90s_length_shared_secret 32
OQS_KEM *OQS_KEM_kyber_512_90s_new(void);
OQS_API OQS_STATUS OQS_KEM_kyber_512_90s_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_KEM_kyber_512_90s_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key);
OQS_API OQS_STATUS OQS_KEM_kyber_512_90s_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key);
#ifdef OQS_HAZARDOUS_ENABLE_DERIVE_KEYPAIR
#define OQS_KEM_kyber_512_90s_length_randomness 64
OQS_API OQS_STATUS OQS_KEM_kyber_512_90s_derive_keypair(const uint8_t *randomness, uint8_t *public_key, uint8_t *secret_key);
#endif
#endif

#ifdef OQS_ENABLE_KEM_kyber_768_90s
#define OQS_KEM_kyber_768_90s_length_public_key 1184
#define OQS_KEM_kyber_768_90s_length_secret_key 2400
#define OQS_KEM_kyber_768_90s_length_ciphertext 1088
#define OQS_KEM_kyber_768_90s_length_shared_secret 32
OQS_KEM *OQS_KEM_kyber_768_90s_new(void);
OQS_API OQS_STATUS OQS_KEM_kyber_768_90s_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_KEM_kyber_768_90s_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key);
OQS_API OQS_STATUS OQS_KEM_kyber_768_90s_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key);
#ifdef OQS_HAZARDOUS_ENABLE_DERIVE_KEYPAIR
#define OQS_KEM_kyber_768_90s_length_randomness 64
OQS_API OQS_STATUS OQS_KEM_kyber_768_90s_derive_keypair(const uint8_t *randomness, uint8_t *public_key, uint8_t *secret_key);
#endif
#endif

#ifdef OQS_ENABLE_KEM_kyber_1024_90s
#define OQS_KEM_kyber_1024_90s_length_public_key 1568
#define OQS_KEM_kyber_1024_90s_length_secret_key 3168
#define OQS_KEM_kyber_1024_90s_length_ciphertext 1568
#define OQS_KEM_kyber_1024_90s_length_shared_secret 32
OQS_KEM *OQS_KEM_kyber_1024_90s_new(void);
OQS_API OQS_STATUS OQS_KEM_kyber_1024_90s_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_KEM_kyber_1024_90s_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key);
OQS_API OQS_STATUS OQS_KEM_kyber_1024_90s_decaps(uint8_t *shared_secret, const uint8_t *ciphertext, const uint8_t *secret_key);
#ifdef OQS_HAZARDOUS_ENABLE_DERIVE_KEYPAIR
#define OQS_KEM_kyber_1024_90s_length_randomness 64
OQS_API OQS_STATUS OQS_KEM_kyber_1024_90s_derive_keypair(const uint8_t *randomness, uint8_t *public_key, uint8_t *secret_key);
#endif
#endif

#endif

