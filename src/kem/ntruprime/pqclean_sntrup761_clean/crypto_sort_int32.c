#include "crypto_sort_int32.h"
#include <stdint.h>

#define int32 int32_t

#define int32_MINMAX(a,b) \
    do { \
        int32_t ab = (b) ^ (a); \
        int32_t c = (int32_t)((int64_t)(b) - (int64_t)(a)); \
        c ^= ab & (c ^ (b)); \
        c >>= 31; \
        c &= ab; \
        (a) ^= c; \
        (b) ^= c; \
    } while(0)

/* assume 2 <= n <= 0x40000000 */
void PQCLEAN_SNTRUP761_CLEAN_crypto_sort_int32(int32_t *x, long long n) {
    int32 top, px, q, r, i;
    long long j;

    top = 1;
    while (top < n - top) {
        top += top;
    }

    for (px = top; px >= 1; px >>= 1) {
        i = 0;
        while (i + 2 * px <= n) {
            for (j = i; j < i + px; ++j) {
                int32_MINMAX(x[j], x[j + px]);
            }
            i += 2 * px;
        }
        for (j = i; j < n - px; ++j) {
            int32_MINMAX(x[j], x[j + px]);
        }

        i = 0;
        j = 0;
        for (q = top; q > px; q >>= 1) {
            if (j != i) {
                for (;;) {
                    if (j == n - q) {
                        goto done;
                    }
                    int32 a = x[j + px];
                    for (r = q; r > px; r >>= 1) {
                        int32_MINMAX(a, x[j + r]);
                    }
                    x[j + px] = a;
                    ++j;
                    if (j == i + px) {
                        i += 2 * px;
                        break;
                    }
                }
            }
            while (i + px <= n - q) {
                for (j = i; j < i + px; ++j) {
                    int32 a = x[j + px];
                    for (r = q; r > px; r >>= 1) {
                        int32_MINMAX(a, x[j + r]);
                    }
                    x[j + px] = a;
                }
                i += 2 * px;
            }
            /* now i + px > n - q */
            j = i;
            while (j < n - q) {
                int32 a = x[j + px];
                for (r = q; r > px; r >>= 1) {
                    int32_MINMAX(a, x[j + r]);
                }
                x[j + px] = a;
                ++j;
            }

done:
            ;
        }
    }
}
