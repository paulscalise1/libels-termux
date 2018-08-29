/******************************************************************************
 * BIKE -- Bit Flipping Key Encapsulation
 *
 * Copyright (c) 2017 Nir Drucker, Shay Gueron, Rafael Misoczki, Tobias Oder, Tim Gueneysu
 * (drucker.nir@gmail.com, shay.gueron@gmail.com, rafael.misoczki@intel.com, tobias.oder@rub.de, tim.gueneysu@rub.de)
 *
 * Permission to use this code for BIKE is granted.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * The names of the contributors may not be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ""AS IS"" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS CORPORATION OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#ifndef __TYPES_H_INCLUDED__
#define __TYPES_H_INCLUDED__

#include "defs.h"
#include <oqs/common.h>

typedef struct uint128_s {
	union {
		uint8_t bytes[16];
		uint32_t dw[4];
		uint64_t qw[2];
	} u;
} uint128_t;

// For clarity of the code
#define IN
#define OUT

// Bit manipulations
#define BIT(len) (1ULL << (len))
#define MASK(len) (BIT(len) - 1ULL)

#define _INLINE_ static inline

// Make sure no compiler optimizations.
#pragma pack(push, 1)

typedef struct generic_param_n_s {
	union {
		struct
		{
			uint8_t val0[R_SIZE];
			uint8_t val1[R_SIZE];
		} v;
		uint8_t raw[N_SIZE];
	} u;
} generic_param_n_t;

typedef generic_param_n_t sk_t;
typedef generic_param_n_t pk_t;
typedef generic_param_n_t ct_t;

typedef struct ss_s {
	uint8_t raw[ELL_K_SIZE];
} ss_t;

typedef struct syndrome_s {
	uint8_t raw[R_BITS];
} syndrome_t;

enum _seed_id {
	G_SEED = 0,
	H_SEED = 1,
	M_SEED = 2,
	E_SEED = 3
};

typedef struct seed_s {
	uint8_t raw[32];
} seed_t;

// Both keygen and encaps require double seed
typedef struct double_seed_s {
	seed_t s1;
	seed_t s2;
} double_seed_t;

//////////////////////////////
//   Error handling
/////////////////////////////

// This convention will work all over the code
#define ERR(v)     \
	{              \
		res = v;   \
		goto EXIT; \
	}
#define CHECK_STATUS(stat)         \
	{                              \
		if (stat != OQS_SUCCESS) { \
			goto EXIT;             \
		}                          \
	}

#pragma pack(pop)

#endif // __TYPES_H_INCLUDED__
