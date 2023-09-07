// SPDX-License-Identifier: MIT

#include <oqs/oqs.h>
#include <string.h>
#include "sig_stfl_xmss.h"

/* Serialize XMSS secret key data into a byte string */
OQS_STATUS OQS_SECRET_KEY_XMSS_serialize_key(const OQS_SIG_STFL_SECRET_KEY *sk, size_t *sk_len, uint8_t **sk_buf_ptr) {
	if (sk == NULL || sk_len == NULL || sk_buf_ptr == NULL) {
		return OQS_ERROR;
	}

	uint8_t *sk_buf = malloc(sk->length_secret_key * sizeof(uint8_t));
	if (sk_buf == NULL) {
		return OQS_ERROR;
	}

	// Simply copy byte string of secret_key_data
	memcpy(sk_buf, sk->secret_key_data, sk->length_secret_key);

	*sk_buf_ptr = sk_buf;
	*sk_len = sk->length_secret_key;

	return OQS_SUCCESS;
}

/* Deserialize XMSS byte string into an XMSS secret key data */
OQS_STATUS OQS_SECRET_KEY_XMSS_deserialize_key(OQS_SIG_STFL_SECRET_KEY *sk, const size_t sk_len, const uint8_t *sk_buf) {
	if (sk == NULL || sk_buf == NULL || (sk_len == 0) || (sk_len != sk->length_secret_key)) {
		return OQS_ERROR;
	}

	if (sk->secret_key_data != NULL) {
		// Secret key data already present
		// We don't want to trample over exist data
		return OQS_ERROR;
	}

	memcpy(sk->secret_key_data, sk_buf, sk_len);

	return OQS_SUCCESS;
}
