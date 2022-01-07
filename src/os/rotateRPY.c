#include "common.h"
#include "include_asm_libultra.h"

#ifndef KMC_ASM
void guRotateRPYF(Matrix4f mf, f32 r, f32 p, f32 h) {
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
#else
static f32 dtor = 3.1415926 / 180.0;
INCLUDE_ASM_LIBULTRA("rotateRPY", guRotateRPYF);
#endif

#ifndef KMC_ASM
void guRotateRPY(Mtx *m, f32 r, f32 p, f32 h) {
    Matrix4f mf;

    guRotateRPYF(mf, r, p, h);

    guMtxF2L(mf, m);
}
#else
INCLUDE_ASM_LIBULTRA("rotateRPY", guRotateRPY);
#endif
