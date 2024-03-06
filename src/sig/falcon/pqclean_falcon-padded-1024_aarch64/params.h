#ifndef PARAMS_H
#define PARAMS_H

#define FALCON_LOGN 10

#define FALCON_N (1 << FALCON_LOGN)
#define FALCON_Q 12289
#define FALCON_QINV (-12287) // pow(12289, -1, pow(2, 16)) - pow(2, 16)
#define FALCON_V 5461        // Barrett reduction
#define FALCON_MONT 4091     // pow(2, 16, 12289)
#define FALCON_MONT_BR 10908 // (4091 << 16)//q//2

#define FALCON_NINV_MONT 64     // pow(1024, -1, 12289) * pow(2, 16, 12289)
#define FALCON_NINV_MONT_BR 170 // (64 << 16) // q //2
#define FALCON_LOG2_NINV_MONT 6

#endif
