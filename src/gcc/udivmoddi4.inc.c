typedef unsigned int UQItype    __attribute__ ((mode (QI)));
typedef          int SItype     __attribute__ ((mode (SI)));
typedef unsigned int USItype    __attribute__ ((mode (SI)));
typedef          int DItype     __attribute__ ((mode (DI)));
typedef unsigned int UDItype    __attribute__ ((mode (DI)));
typedef          int word_type  __attribute__ ((mode (__word__)));

#define BITS_PER_UNIT 8
#define SI_TYPE_SIZE (sizeof (SItype) * BITS_PER_UNIT)

struct DIstruct {
    SItype high;
    SItype low;
};

typedef union {
  struct DIstruct s;
  DItype ll;
} DIunion;

#define __BITS4 (SI_TYPE_SIZE / 4)
#define __ll_B (1L << (SI_TYPE_SIZE / 2))
#define __ll_lowpart(t) ((USItype) (t) % __ll_B)
#define __ll_highpart(t) ((USItype) (t) / __ll_B)

#ifndef OLD_GCC
#define umul_ppmm(w1, w0, u, v)                     \
  do {                                  \
    UDItype __x = (UDItype) (USItype) (u) * (USItype) (v);      \
    (w1) = (USItype) (__x >> 32);                   \
    (w0) = (USItype) (__x);                     \
  } while (0)
#else
#define umul_ppmm(w1, w0, u, v)     \
    __asm__ ("multu %2,%3"          \
        : "=l" ((USItype) (w0)),    \
          "=h" ((USItype) (w1))     \
        : "d" ((USItype) (u)),      \
          "d" ((USItype) (v)))
#endif

#define sub_ddmmss(sh, sl, ah, al, bh, bl)  \
    do {                                    \
        USItype __x;                        \
        __x = (al) - (bl);                  \
        (sh) = (ah) - (bh) - (__x > (al));  \
        (sl) = __x;                         \
    } while (0)

#define udiv_qrnnd(q, r, n1, n0, d) \
    do {                                                                            \
        USItype __d1, __d0, __q1, __q0;                                             \
        USItype __r1, __r0, __m;                                                    \
        __d1 = __ll_highpart (d);                                                   \
        __d0 = __ll_lowpart (d);                                                    \
                                                                                    \
        __r1 = (n1) % __d1;                                                         \
        __q1 = (n1) / __d1;                                                         \
        __m = (USItype) __q1 * __d0;                                                \
        __r1 = __r1 * __ll_B | __ll_highpart (n0);                                  \
        if (__r1 < __m) {                                                           \
            __q1--, __r1 += (d);                                                    \
            if (__r1 >= (d)) { /* i.e. we didn't get carry when adding to __r1 */   \
                if (__r1 < __m) {                                                   \
                    __q1--, __r1 += (d);                                            \
                }                                                                   \
            }                                                                       \
        }                                                                           \
        __r1 -= __m;                                                                \
                                                                                    \
        __r0 = __r1 % __d1;                                                         \
        __q0 = __r1 / __d1;                                                         \
        __m = (USItype) __q0 * __d0;                                                \
        __r0 = __r0 * __ll_B | __ll_lowpart (n0);                                   \
        if (__r0 < __m) {                                                           \
            __q0--, __r0 += (d);                                                    \
            if (__r0 >= (d)) {                                                      \
                if (__r0 < __m) {                                                   \
                    __q0--, __r0 += (d);                                            \
                }                                                                   \
            }                                                                       \
        }                                                                           \
        __r0 -= __m;                                                                \
                                                                                    \
        (q) = (USItype) __q1 * __ll_B | __q0;                                       \
        (r) = __r0;                                                                 \
    } while (0)

#define count_leading_zeros(count, x)                                           \
    do {                                                                        \
        USItype __xr = (x);                                                     \
        USItype __a;                                                            \
                                                                                \
        if (SI_TYPE_SIZE <= 32) {                                               \
            __a = __xr < ((USItype)1<<2*__BITS4)                                \
                ? (__xr < ((USItype)1<<__BITS4) ? 0 : __BITS4)                  \
                : (__xr < ((USItype)1<<3*__BITS4) ?  2*__BITS4 : 3*__BITS4);    \
        } else {                                                                \
            for (__a = SI_TYPE_SIZE - 8; __a > 0; __a -= 8) {                   \
                if (((__xr >> __a) & 0xff) != 0) {                              \
                    break;                                                      \
                }                                                               \
            }                                                                   \
        }                                                                       \
                                                                                \
        (count) = SI_TYPE_SIZE - (__clz_tab[__xr >> __a] + __a);                \
    } while (0)

static inline DItype __negdi2(DItype u) {
    DIunion w;
    DIunion uu;

    uu.ll = u;

    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((USItype) w.s.low > 0);

    return w.ll;
}

static const UQItype __clz_tab[] = {
    0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};

static inline UDItype __udivmoddi4(UDItype n, UDItype d, UDItype *rp) {
    DIunion ww;
    DIunion nn, dd;
    DIunion rr;
    USItype d0, d1, n0, n1, n2;
    USItype q0, q1;
    USItype b, bm;

    nn.ll = n;
    dd.ll = d;

    d0 = dd.s.low;
    d1 = dd.s.high;
    n0 = nn.s.low;
    n1 = nn.s.high;

    if (d1 == 0) {
        if (d0 > n1) {
            /* 0q = nn / 0D */

            count_leading_zeros (bm, d0);

            if (bm != 0) {
                /* Normalize, i.e. make the most significant bit of the
                   denominator set.  */

                d0 = d0 << bm;
                n1 = (n1 << bm) | (n0 >> (SI_TYPE_SIZE - bm));
                n0 = n0 << bm;
            }

            udiv_qrnnd(q0, n0, n1, n0, d0);
            q1 = 0;

            /* Remainder in n0 >> bm.  */
        } else {
            /* qq = NN / 0d */

            if (d0 == 0) {
                d0 = 1 / d0;    /* Divide intentionally by zero.  */
            }

            count_leading_zeros (bm, d0);

            if (bm == 0) {
                /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
                   conclude (the most significant bit of n1 is set) /\ (the
                   leading quotient digit q1 = 1).

                   This special case is necessary, not an optimization.
                   (Shifts counts of SI_TYPE_SIZE are undefined.)  */

                n1 -= d0;
                q1 = 1;
            } else {
                /* Normalize.  */

                b = SI_TYPE_SIZE - bm;

                d0 = d0 << bm;
                n2 = n1 >> b;
                n1 = (n1 << bm) | (n0 >> b);
                n0 = n0 << bm;

                udiv_qrnnd(q1, n1, n2, n1, d0);
            }

            /* n1 != d0...  */

            udiv_qrnnd(q0, n0, n1, n0, d0);

            /* Remainder in n0 >> bm.  */
        }

        if (rp != 0) {
            rr.s.low = n0 >> bm;
            rr.s.high = 0;
            *rp = rr.ll;
        }
    } else {
        if (d1 > n1) {
            /* 00 = nn / DD */

            q0 = 0;
            q1 = 0;

            /* Remainder in n1n0.  */
            if (rp != 0) {
                rr.s.low = n0;
                rr.s.high = n1;
                *rp = rr.ll;
            }
        } else {
            /* 0q = NN / dd */

            count_leading_zeros (bm, d1);
            if (bm == 0) {
                /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
                   conclude (the most significant bit of n1 is set) /\ (the
                   quotient digit q0 = 0 or 1).

                   This special case is necessary, not an optimization.  */

                /* The condition on the next line takes advantage of that
                   n1 >= d1 (true due to program flow).  */
                if (n1 > d1 || n0 >= d0) {
                    q0 = 1;
                    sub_ddmmss(n1, n0, n1, n0, d1, d0);
                } else {
                    q0 = 0;
                }
                q1 = 0;

                if (rp != 0) {
                    rr.s.low = n0;
                    rr.s.high = n1;
                    *rp = rr.ll;
                }
            } else {
                USItype m1, m0;
                /* Normalize.  */

                b = SI_TYPE_SIZE - bm;

                d1 = (d1 << bm) | (d0 >> b);
                d0 = d0 << bm;
                n2 = n1 >> b;
                n1 = (n1 << bm) | (n0 >> b);
                n0 = n0 << bm;

                udiv_qrnnd(q0, n1, n2, n1, d1);
                umul_ppmm(m1, m0, q0, d0);

                if (m1 > n1 || (m1 == n1 && m0 > n0)) {
                    q0--;
                    sub_ddmmss(m1, m0, m1, m0, d1, d0);
                }

                q1 = 0;

                /* Remainder in (n1n0 - m1m0) >> bm.  */
                if (rp != 0) {
                    sub_ddmmss(n1, n0, n1, n0, m1, m0);
                    rr.s.low = (n1 << b) | (n0 >> bm);
                    rr.s.high = n1 >> bm;
                    *rp = rr.ll;
                }
            }
        }
    }

    ww.s.low = q0;
    ww.s.high = q1;
    return ww.ll;
}
