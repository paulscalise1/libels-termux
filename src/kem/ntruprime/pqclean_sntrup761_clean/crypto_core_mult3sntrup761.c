#include "crypto_core_mult3sntrup761.h"
#include "params.h"


#define int8 int8_t
#define int16 int16_t
typedef int8 small;

/* works for -16384 <= x < 16384 */
static small F3_freeze(int16 x) {
    return (small) (x - 3 * ((10923 * x + 16384) >> 15));
}

int PQCLEAN_SNTRUP761_CLEAN_crypto_core_mult3sntrup761(unsigned char *outbytes, const unsigned char *inbytes, const unsigned char *kbytes) {
    small *h = (void *) outbytes;
    small f[px];
    small g[px];
    small fg[px + px - 1];
    int16 result;
    int i, j;

    for (i = 0; i < px; ++i) {
        small fi = (small) inbytes[i];
        small fi0 = fi & 1;
        f[i] = (small) (fi0 - (fi & (fi0 << 1)));
    }
    for (i = 0; i < px; ++i) {
        small gi = (small) kbytes[i];
        small gi0 = gi & 1;
        g[i] = (small) (gi0 - (gi & (gi0 << 1)));
    }

    for (i = 0; i < px; ++i) {
        result = 0;
        for (j = 0; j <= i; ++j) {
            result += (small) (f[j] * g[i - j]);
        }
        fg[i] = F3_freeze(result);
    }
    for (i = px; i < px + px - 1; ++i) {
        result = 0;
        for (j = i - px + 1; j < px; ++j) {
            result += (small) (f[j] * g[i - j]);
        }
        fg[i] = F3_freeze(result);
    }

    for (i = px + px - 2; i >= px; --i) {
        fg[i - px] = F3_freeze(fg[i - px] + fg[i]);
        fg[i - px + 1] = F3_freeze(fg[i - px + 1] + fg[i]);
    }

    for (i = 0; i < px; ++i) {
        h[i] = fg[i];
    }
    return 0;
}
