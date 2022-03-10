#include "PR/guint.h"

f32 sin_rad(f32 x);
f32 cos_rad(f32 x);

void guRotateRPYF(float mf[4][4], f32 r, f32 p, f32 h) {
    static f32 dtor = 3.1415926 / 180.0;
    f32 sinr, sinp, sinh;
    f32 cosr, cosp, cosh;

    r *= dtor;
    p *= dtor;
    h *= dtor;
    sinr = sin_rad(r);
    cosr = cos_rad(r);
    sinp = sin_rad(p);
    cosp = cos_rad(p);
    sinh = sin_rad(h);
    cosh = cos_rad(h);

    guMtxIdentF(mf);

    mf[0][0] = cosp * cosh;
    mf[0][1] = cosp * sinh;
    mf[0][2] = -sinp;

    mf[1][0] = sinr * sinp * cosh - cosr * sinh;
    mf[1][1] = sinr * sinp * sinh + cosr * cosh;
    mf[1][2] = sinr * cosp;

    mf[2][0] = cosr * sinp * cosh + sinr * sinh;
    mf[2][1] = cosr * sinp * sinh - sinr * cosh;
    mf[2][2] = cosr * cosp;
}

void guRotateRPY(Mtx *m, f32 r, f32 p, f32 h) {
    Matrix mf;

    guRotateRPYF(mf, r, p, h);

    guMtxF2L(mf, m);
}
