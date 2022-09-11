#include "PR/guint.h"

f32 sin_rad(f32 x);
f32 cos_rad(f32 x);

void guPositionF(f32 mf[4][4], f32 r, f32 p, f32 h, f32 s, f32 x, f32 y, f32 z) {
        static f32 dtor = 3.1415926 / 180.0;
        f32   sinr, sinp, sinh;
        f32   cosr, cosp, cosh;

        r *= dtor;
        p *= dtor;
        h *= dtor;
        sinr = sin_rad(r);
        cosr = cos_rad(r);
        sinp = sin_rad(p);
        cosp = cos_rad(p);
        sinh = sin_rad(h);
        cosh = cos_rad(h);

        mf[0][0] = (cosp * cosh) * s;
        mf[0][1] = (cosp * sinh) * s;
        mf[0][2] = (-sinp) * s;
        mf[0][3] = 0.0;

        mf[1][0] = (sinr * sinp * cosh - cosr * sinh) * s;
        mf[1][1] = (sinr * sinp * sinh + cosr * cosh) * s;
        mf[1][2] = (sinr * cosp) * s;
        mf[1][3] = 0.0;

        mf[2][0] = (cosr * sinp * cosh + sinr * sinh) * s;
        mf[2][1] = (cosr * sinp * sinh - sinr * cosh) * s;
        mf[2][2] = (cosr * cosp) * s;
        mf[2][3] = 0.0;

        mf[3][0] = x;
        mf[3][1] = y;
        mf[3][2] = z;
        mf[3][3] = 1.0;
}

void guPosition(Mtx* m, f32 r, f32 p, f32 h, f32 s,
                                f32 x, f32 y, f32 z) {
    f32 mf[4][4];

    guPositionF(mf, r, p, h, s, x, y, z);

    guMtxF2L(mf, m);
}
