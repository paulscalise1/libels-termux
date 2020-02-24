include(CMakeDependentOption)

set(OQS_KEM_DEFAULT "OQS_KEM_alg_frodokem_640_aes")
set(OQS_SIG_DEFAULT "OQS_SIG_alg_dilithium_2")

if(NOT WIN32)
    option(OQS_USE_OPENSSL "" ON)
    cmake_dependent_option(OQS_USE_AES_OPENSSL "" ON "OQS_USE_OPENSSL" OFF)
    cmake_dependent_option(OQS_USE_SHA2_OPENSSL "" ON "OQS_USE_OPENSSL" OFF)
    cmake_dependent_option(OQS_USE_SHA3_OPENSSL "" ON "OQS_USE_OPENSSL" OFF)

    option(ENABLE_KEM_BIKE "" ON)
    cmake_dependent_option(OQS_ENABLE_KEM_bike1_l1_cpa "" ON "ENABLE_KEM_BIKE" OFF)
    cmake_dependent_option(OQS_ENABLE_KEM_bike1_l1_fo "" ON "ENABLE_KEM_BIKE" OFF)
    cmake_dependent_option(OQS_ENABLE_KEM_bike1_l3_cpa "" ON "ENABLE_KEM_BIKE" OFF)
    cmake_dependent_option(OQS_ENABLE_KEM_bike1_l3_fo "" ON "ENABLE_KEM_BIKE" OFF)
endif()

option(ENABLE_KEM_FRODOKEM "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_frodokem_640_aes "" ON "ENABLE_KEM_FRODOKEM" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_frodokem_640_shake "" ON "ENABLE_KEM_FRODOKEM" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_frodokem_976_aes "" ON "ENABLE_KEM_FRODOKEM" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_frodokem_976_shake "" ON "ENABLE_KEM_FRODOKEM" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_frodokem_1344_aes "" ON "ENABLE_KEM_FRODOKEM" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_frodokem_1344_shake "" ON "ENABLE_KEM_FRODOKEM" OFF)

option(ENABLE_KEM_SIKE "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p434 "" ON "ENABLE_KEM_SIKE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p434_compressed "" ON "ENABLE_KEM_SIKE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p503 "" ON "ENABLE_KEM_SIKE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p503_compressed "" ON "ENABLE_KEM_SIKE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p610 "" ON "ENABLE_KEM_SIKE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p610_compressed "" ON "ENABLE_KEM_SIKE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p751 "" ON "ENABLE_KEM_SIKE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sike_p751_compressed "" ON "ENABLE_KEM_SIKE" OFF)

option(ENABLE_KEM_SIDH "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p434 "" ON "ENABLE_KEM_SIDH" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p434_compressed "" ON "ENABLE_KEM_SIDH" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p503 "" ON "ENABLE_KEM_SIDH" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p503_compressed "" ON "ENABLE_KEM_SIDH" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p610 "" ON "ENABLE_KEM_SIDH" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p610_compressed "" ON "ENABLE_KEM_SIDH" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p751 "" ON "ENABLE_KEM_SIDH" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_sidh_p751_compressed "" ON "ENABLE_KEM_SIDH" OFF)

option(ENABLE_SIG_PICNIC "" ON)
cmake_dependent_option(OQS_ENABLE_SIG_picnic_L1_UR "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic_L1_FS "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic_L3_UR "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic_L3_FS "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic_L5_UR "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic_L5_FS "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic2_L1_FS "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic2_L3_FS "" ON "ENABLE_SIG_PICNIC" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_picnic2_L5_FS "" ON "ENABLE_SIG_PICNIC" OFF)

option(ENABLE_SIG_QTESLA "" ON)
cmake_dependent_option(OQS_ENABLE_SIG_qTesla_p_I "" ON "ENABLE_SIG_QTESLA" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_qTesla_p_III "" ON "ENABLE_SIG_QTESLA" OFF)

##### OQS_COPY_FROM_PQCLEAN_FRAGMENT_ADD_ENABLE_BY_ALG_START
option(ENABLE_KEM_KYBER "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_kyber_512 "" ON "ENABLE_KEM_KYBER" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_kyber_768 "" ON "ENABLE_KEM_KYBER" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_kyber_1024 "" ON "ENABLE_KEM_KYBER" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_kyber_512_90s "" ON "ENABLE_KEM_KYBER" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_kyber_768_90s "" ON "ENABLE_KEM_KYBER" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_kyber_1024_90s "" ON "ENABLE_KEM_KYBER" OFF)

option(ENABLE_KEM_LEDACRYPT "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_ledacrypt_ledakemlt12 "" ON "ENABLE_KEM_LEDACRYPT" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_ledacrypt_ledakemlt32 "" ON "ENABLE_KEM_LEDACRYPT" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_ledacrypt_ledakemlt52 "" ON "ENABLE_KEM_LEDACRYPT" OFF)

option(ENABLE_KEM_NEWHOPE "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_newhope_512cca "" ON "ENABLE_KEM_NEWHOPE" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_newhope_1024cca "" ON "ENABLE_KEM_NEWHOPE" OFF)

option(ENABLE_KEM_NTRU "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_ntru_hps2048509 "" ON "ENABLE_KEM_NTRU" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_ntru_hps2048677 "" ON "ENABLE_KEM_NTRU" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_ntru_hps4096821 "" ON "ENABLE_KEM_NTRU" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_ntru_hrss701 "" ON "ENABLE_KEM_NTRU" OFF)

option(ENABLE_KEM_SABER "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_saber_lightsaber "" ON "ENABLE_KEM_SABER" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_saber_saber "" ON "ENABLE_KEM_SABER" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_saber_firesaber "" ON "ENABLE_KEM_SABER" OFF)

option(ENABLE_KEM_THREEBEARS "" ON)
cmake_dependent_option(OQS_ENABLE_KEM_threebears_babybear "" ON "ENABLE_KEM_THREEBEARS" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_threebears_babybear_ephem "" ON "ENABLE_KEM_THREEBEARS" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_threebears_mamabear "" ON "ENABLE_KEM_THREEBEARS" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_threebears_mamabear_ephem "" ON "ENABLE_KEM_THREEBEARS" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_threebears_papabear "" ON "ENABLE_KEM_THREEBEARS" OFF)
cmake_dependent_option(OQS_ENABLE_KEM_threebears_papabear_ephem "" ON "ENABLE_KEM_THREEBEARS" OFF)

option(ENABLE_SIG_DILITHIUM "" ON)
cmake_dependent_option(OQS_ENABLE_SIG_dilithium_2 "" ON "ENABLE_SIG_DILITHIUM" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_dilithium_3 "" ON "ENABLE_SIG_DILITHIUM" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_dilithium_4 "" ON "ENABLE_SIG_DILITHIUM" OFF)

option(ENABLE_SIG_MQDSS "" ON)
cmake_dependent_option(OQS_ENABLE_SIG_mqdss_31_48 "" ON "ENABLE_SIG_MQDSS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_mqdss_31_64 "" ON "ENABLE_SIG_MQDSS" OFF)

option(ENABLE_SIG_SPHINCS "" ON)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_128f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_128f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_128s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_128s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_192f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_192f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_192s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_192s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_256f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_256f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_256s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_haraka_256s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_128f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_128f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_128s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_128s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_192f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_192f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_192s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_192s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_256f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_256f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_256s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_sha256_256s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_128f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_128f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_128s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_128s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_192f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_192f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_192s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_192s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_256f_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_256f_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_256s_robust "" ON "ENABLE_SIG_SPHINCS" OFF)
cmake_dependent_option(OQS_ENABLE_SIG_sphincs_shake256_256s_simple "" ON "ENABLE_SIG_SPHINCS" OFF)
##### OQS_COPY_FROM_PQCLEAN_FRAGMENT_ADD_ENABLE_BY_ALG_END
