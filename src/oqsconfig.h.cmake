// SPDX-License-Identifier: MIT

#cmakedefine OQS_VERSION_TEXT "@OQS_VERSION_TEXT@"
#cmakedefine OQS_COMPILE_BUILD_TARGET "@OQS_COMPILE_BUILD_TARGET@"
#cmakedefine OQS_DIST_BUILD 1
#cmakedefine OQS_DIST_X86_64_BUILD 1
#cmakedefine OQS_DIST_X86_BUILD 1
#cmakedefine OQS_DIST_ARM64_V8_BUILD 1
#cmakedefine OQS_DIST_ARM32_V7_BUILD 1
#cmakedefine OQS_DIST_PPC64LE_BUILD 1
#cmakedefine OQS_DEBUG_BUILD 1
#cmakedefine ARCH_X86_64 1
#cmakedefine ARCH_ARM64v8 1
#cmakedefine ARCH_ARM32v7 1
#cmakedefine BUILD_SHARED_LIBS 1
#cmakedefine OQS_BUILD_ONLY_LIB 1
#cmakedefine OQS_OPT_TARGET "@OQS_OPT_TARGET@"
#cmakedefine USE_SANITIZER "@USE_SANITIZER@"
#cmakedefine CMAKE_BUILD_TYPE "@CMAKE_BUILD_TYPE@"

#cmakedefine OQS_USE_OPENSSL 1
#cmakedefine OQS_USE_AES_OPENSSL 1
#cmakedefine OQS_USE_SHA2_OPENSSL 1
#cmakedefine OQS_USE_SHA3_OPENSSL 1

#cmakedefine OQS_USE_PTHREADS_IN_TESTS 1

#cmakedefine OQS_USE_ADX_INSTRUCTIONS 1
#cmakedefine OQS_USE_AES_INSTRUCTIONS 1
#cmakedefine OQS_USE_AVX_INSTRUCTIONS 1
#cmakedefine OQS_USE_AVX2_INSTRUCTIONS 1
#cmakedefine OQS_USE_AVX512_INSTRUCTIONS 1
#cmakedefine OQS_USE_BMI1_INSTRUCTIONS 1
#cmakedefine OQS_USE_BMI2_INSTRUCTIONS 1
#cmakedefine OQS_USE_PCLMULQDQ_INSTRUCTIONS 1
#cmakedefine OQS_USE_VPCLMULQDQ_INSTRUCTIONS 1
#cmakedefine OQS_USE_POPCNT_INSTRUCTIONS 1
#cmakedefine OQS_USE_SSE_INSTRUCTIONS 1
#cmakedefine OQS_USE_SSE2_INSTRUCTIONS 1
#cmakedefine OQS_USE_SSE3_INSTRUCTIONS 1

#cmakedefine OQS_USE_ARM_AES_INSTRUCTIONS 1
#cmakedefine OQS_USE_ARM_SHA2_INSTRUCTIONS 1
#cmakedefine OQS_USE_ARM_SHA3_INSTRUCTIONS 1
#cmakedefine OQS_USE_ARM_NEON_INSTRUCTIONS 1

#cmakedefine OQS_SPEED_USE_ARM_PMU 1

#cmakedefine OQS_ENABLE_TEST_CONSTANT_TIME 1

#cmakedefine OQS_ENABLE_SHA3_xkcp_low_avx2 1

#cmakedefine OQS_ENABLE_KEM_BIKE 1
#cmakedefine OQS_ENABLE_KEM_bike_l1 1
#cmakedefine OQS_ENABLE_KEM_bike_l3 1
#cmakedefine OQS_ENABLE_KEM_bike_l5 1

#cmakedefine OQS_ENABLE_KEM_FRODOKEM 1
#cmakedefine OQS_ENABLE_KEM_frodokem_640_aes 1
#cmakedefine OQS_ENABLE_KEM_frodokem_640_shake 1
#cmakedefine OQS_ENABLE_KEM_frodokem_976_aes 1
#cmakedefine OQS_ENABLE_KEM_frodokem_976_shake 1
#cmakedefine OQS_ENABLE_KEM_frodokem_1344_aes 1
#cmakedefine OQS_ENABLE_KEM_frodokem_1344_shake 1

#cmakedefine OQS_ENABLE_KEM_NTRUPRIME 1
#cmakedefine OQS_ENABLE_KEM_ntruprime_sntrup761 1
#cmakedefine OQS_ENABLE_KEM_ntruprime_sntrup761_avx2 1

///// OQS_COPY_FROM_UPSTREAM_FRAGMENT_ADD_ALG_ENABLE_DEFINES_START

#cmakedefine OQS_ENABLE_KEM_CLASSIC_MCELIECE 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_348864 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_348864_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_348864f 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_348864f_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_460896 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_460896_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_460896f 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_460896f_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6688128 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6688128_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6688128f 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6688128f_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6960119 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6960119_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6960119f 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_6960119f_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_8192128 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_8192128_avx2 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_8192128f 1
#cmakedefine OQS_ENABLE_KEM_classic_mceliece_8192128f_avx2 1

#cmakedefine OQS_ENABLE_KEM_HQC 1
#cmakedefine OQS_ENABLE_KEM_hqc_128 1
#cmakedefine OQS_ENABLE_KEM_hqc_128_avx2 1
#cmakedefine OQS_ENABLE_KEM_hqc_192 1
#cmakedefine OQS_ENABLE_KEM_hqc_192_avx2 1
#cmakedefine OQS_ENABLE_KEM_hqc_256 1
#cmakedefine OQS_ENABLE_KEM_hqc_256_avx2 1

#cmakedefine OQS_ENABLE_KEM_KYBER 1
#cmakedefine OQS_ENABLE_KEM_kyber_512 1
#cmakedefine OQS_ENABLE_KEM_kyber_512_avx2 1
#cmakedefine OQS_ENABLE_KEM_kyber_512_aarch64 1
#cmakedefine OQS_ENABLE_KEM_kyber_768 1
#cmakedefine OQS_ENABLE_KEM_kyber_768_avx2 1
#cmakedefine OQS_ENABLE_KEM_kyber_768_aarch64 1
#cmakedefine OQS_ENABLE_KEM_kyber_1024 1
#cmakedefine OQS_ENABLE_KEM_kyber_1024_avx2 1
#cmakedefine OQS_ENABLE_KEM_kyber_1024_aarch64 1

#cmakedefine OQS_ENABLE_SIG_DILITHIUM 1
#cmakedefine OQS_ENABLE_SIG_dilithium_2 1
#cmakedefine OQS_ENABLE_SIG_dilithium_2_avx2 1
#cmakedefine OQS_ENABLE_SIG_dilithium_2_aarch64 1
#cmakedefine OQS_ENABLE_SIG_dilithium_3 1
#cmakedefine OQS_ENABLE_SIG_dilithium_3_avx2 1
#cmakedefine OQS_ENABLE_SIG_dilithium_3_aarch64 1
#cmakedefine OQS_ENABLE_SIG_dilithium_5 1
#cmakedefine OQS_ENABLE_SIG_dilithium_5_avx2 1
#cmakedefine OQS_ENABLE_SIG_dilithium_5_aarch64 1

#cmakedefine OQS_ENABLE_SIG_FALCON 1
#cmakedefine OQS_ENABLE_SIG_falcon_512 1
#cmakedefine OQS_ENABLE_SIG_falcon_512_avx2 1
#cmakedefine OQS_ENABLE_SIG_falcon_1024 1
#cmakedefine OQS_ENABLE_SIG_falcon_1024_avx2 1

#cmakedefine OQS_ENABLE_SIG_SPHINCS 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_128f_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_128f_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_128s_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_128s_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_192f_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_192f_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_192s_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_192s_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_256f_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_256f_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_256s_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_sha256_256s_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_128f_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_128f_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_128s_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_128s_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_192f_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_192f_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_192s_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_192s_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_256f_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_256f_simple_avx2 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_256s_simple 1
#cmakedefine OQS_ENABLE_SIG_sphincs_shake256_256s_simple_avx2 1
///// OQS_COPY_FROM_UPSTREAM_FRAGMENT_ADD_ALG_ENABLE_DEFINES_END
