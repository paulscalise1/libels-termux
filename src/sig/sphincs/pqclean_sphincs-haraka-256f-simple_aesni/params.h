#ifndef PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_PARAMS_H
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_PARAMS_H

/* Hash output length in bytes. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N 32
/* Height of the hypertree. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FULL_HEIGHT 68
/* Number of subtree layer. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_D 17
/* FORS tree dimensions. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_HEIGHT 9
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_TREES 35
/* Winternitz parameter, */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_W 16

/* The hash function is defined by linking a different hash.c file, as opposed
   to setting a #define constant. */

/* For clarity */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_ADDR_BYTES 32

/* WOTS parameters. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LOGW 4

#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LEN1 (8 * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N / PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LOGW)

/* PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LEN2 is floor(log(len_1 * (w - 1)) / log(w)) + 1; we precompute */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LEN2 3

#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LEN (PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LEN1 + PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LEN2)
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_BYTES (PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_LEN * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N)
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_PK_BYTES PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_BYTES

/* Subtree size. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_TREE_HEIGHT (PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FULL_HEIGHT / PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_D)

/* FORS parameters. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_MSG_BYTES ((PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_HEIGHT * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_TREES + 7) / 8)
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_BYTES ((PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_HEIGHT + 1) * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_TREES * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N)
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_PK_BYTES PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N

/* Resulting SPX sizes. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_BYTES (PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N + PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FORS_BYTES + PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_D * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_WOTS_BYTES +\
        PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_FULL_HEIGHT * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N)
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_PK_BYTES (2 * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N)
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_SK_BYTES (2 * PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_N + PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_PK_BYTES)

/* Optionally, signing can be made non-deterministic using optrand.
   This can help counter side-channel attacks that would benefit from
   getting a large number of traces when the signer uses the same nodes. */
#define PQCLEAN_SPHINCSHARAKA256FSIMPLE_AESNI_OPTRAND_BYTES 32

#endif