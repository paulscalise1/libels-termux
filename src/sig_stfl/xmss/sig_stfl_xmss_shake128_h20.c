// SPDX-License-Identifier: MIT

#include <string.h>
#include <stdlib.h>

#include <oqs/oqs.h>
#include "sig_stfl_xmss.h"

#include "external/xmss.h"

#if defined(__GNUC__) || defined(__clang__)
#define XMSS_UNUSED_ATT __attribute__((unused))
#else
#define XMSS_UNUSED_ATT
#endif

// ======================== XMSS-SHAKE_10_256 ======================== //

OQS_SIG_STFL *OQS_SIG_STFL_alg_xmss_shake128_h20_new(void) {

	OQS_SIG_STFL *sig = (OQS_SIG_STFL *)malloc(sizeof(OQS_SIG_STFL));
	if (sig == NULL) {
		return NULL;
	}
	memset(sig, 0, sizeof(OQS_SIG_STFL));

	sig->method_name = "XMSS-SHAKE_20_256";
	sig->alg_version = "https://datatracker.ietf.org/doc/html/rfc8391";
	sig->euf_cma = true;

	sig->length_public_key = OQS_SIG_STFL_alg_xmss_shake128_h20_length_pk;
	sig->length_secret_key = OQS_SIG_STFL_alg_xmss_shake128_h20_length_sk;
	sig->length_signature = OQS_SIG_STFL_alg_xmss_shake128_h20_length_signature;

	sig->keypair = OQS_SIG_STFL_alg_xmss_shake128_h20_keypair;
	sig->sign = OQS_SIG_STFL_alg_xmss_shake128_h20_sign;
	sig->verify = OQS_SIG_STFL_alg_xmss_shake128_h20_verify;
	sig->sigs_remaining = OQS_SIG_STFL_alg_xmss_shake128_h20_sigs_remaining;
	sig->sigs_total = OQS_SIG_STFL_alg_xmss_shake128_h20_sigs_total;

	return sig;
}

OQS_SIG_STFL_SECRET_KEY *OQS_SECRET_KEY_XMSS_SHAKE128_H20_new(void) {

	// Initialize the secret key in the heap with adequate memory
	OQS_SIG_STFL_SECRET_KEY *sk = malloc(sizeof(OQS_SIG_STFL_SECRET_KEY));
	if (sk == NULL) {
		return NULL;
	}
	memset(sk, 0, sizeof(OQS_SIG_STFL_SECRET_KEY));

	sk->length_secret_key = OQS_SIG_STFL_alg_xmss_shake128_h20_length_sk;

	// Assign the sigs_left and sigs_max functions
	sk->sigs_left = NULL;
	sk->sigs_total = NULL;

	// Initialize the key with length_secret_key amount of bytes.
	sk->secret_key_data = (uint8_t *)malloc(sk->length_secret_key * sizeof(uint8_t));
	memset(sk->secret_key_data, 0, sk->length_secret_key);

	sk->free_key = OQS_SECRET_KEY_XMSS_free;

	return sk;
}

OQS_API OQS_STATUS OQS_SIG_STFL_alg_xmss_shake128_h20_keypair(XMSS_UNUSED_ATT uint8_t *public_key, XMSS_UNUSED_ATT uint8_t *secret_key) {

	if (public_key == NULL || secret_key == NULL) {
		return OQS_ERROR;
	}

	const uint32_t xmss_shake128_h20_oid = 0x09;
	if (xmss_keypair(public_key, secret_key, xmss_shake128_h20_oid)) {
		return OQS_ERROR;
	}

	return OQS_SUCCESS;
}

OQS_API OQS_STATUS OQS_SIG_STFL_alg_xmss_shake128_h20_sign(uint8_t *signature, size_t *signature_len, XMSS_UNUSED_ATT const uint8_t *message, XMSS_UNUSED_ATT size_t message_len, XMSS_UNUSED_ATT uint8_t *secret_key) {

	if (signature == NULL || signature_len == NULL || message == NULL || secret_key == NULL) {
		return OQS_ERROR;
	}

	unsigned long long sig_length = 0;
	if (xmss_sign(secret_key, signature, &sig_length, message, message_len)) {
		return OQS_ERROR;
	}
	*signature_len = (size_t) sig_length;

	return OQS_SUCCESS;
}

OQS_API OQS_STATUS OQS_SIG_STFL_alg_xmss_shake128_h20_verify(XMSS_UNUSED_ATT const uint8_t *message, XMSS_UNUSED_ATT size_t message_len, const uint8_t *signature, size_t signature_len, XMSS_UNUSED_ATT const uint8_t *public_key) {

	if (message == NULL || signature == NULL || public_key == NULL) {
		return OQS_ERROR;
	}

	if (xmss_sign_open(message, (unsigned long long) message_len, signature, (unsigned long long) signature_len, public_key)) {
		return OQS_ERROR;
	}

	return OQS_SUCCESS;
}

OQS_API OQS_STATUS OQS_SIG_STFL_alg_xmss_shake128_h20_sigs_remaining(size_t *remain, const uint8_t *secret_key) {
	if (remain == NULL || secret_key == NULL) {
		return OQS_ERROR;
	}

	unsigned long long remaining_signatures = 0;
	if (xmss_remaining_signatures(&remaining_signatures, secret_key)) {
		return OQS_ERROR;
	}
	*remain = (size_t) remaining_signatures;

	return OQS_SUCCESS;
}

OQS_API OQS_STATUS OQS_SIG_STFL_alg_xmss_shake128_h20_sigs_total(size_t *total, const uint8_t *secret_key) {
	if (total == NULL || secret_key == NULL) {
		return OQS_ERROR;
	}

	unsigned long long total_signatures = 0;
	if (xmss_total_signatures(&total_signatures, secret_key)) {
		return OQS_ERROR;
	}
	*total = (size_t) total_signatures;

	return OQS_SUCCESS;
}