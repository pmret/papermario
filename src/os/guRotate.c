#include "PR/guint.h"

f32 sin_rad(f32 x);
f32 cos_rad(f32 x);

void guRotateF(float mf[4][4], float a, float x, float y, float z) {
    static float dtor = 3.1415926 / 180.0;
    float sine;
    float cosine;
    float ab, bc, ca, t;
    float xs, ys, zs;

    guNormalize(&x, &y, &z);
    a *= dtor;
    sine = sin_rad(a);
    cosine = cos_rad(a);
    t = 1.0f - cosine;
    ab = x * y * t;
    bc = y * z * t;
    ca = z * x * t;

    guMtxIdentF(mf);

    ys = y * sine;
    xs = x * sine;
    zs = z * sine;

    t = x * x;
    mf[0][0] = t + cosine * (1.0f - t);
    mf[2][1] = bc - xs;
    mf[1][2] = bc + xs;

    t = y * y;
    mf[1][1] = t + cosine * (1.0f - t);
    mf[2][0] = ca + ys;
    mf[0][2] = ca - ys;

    t = z * z;
    mf[2][2] = t + cosine * (1.0f - t);
    mf[1][0] = ab - zs;
    mf[0][1] = ab + zs;
}

void guRotate(Mtx *m, float a, float x, float y, float z) {
    float mf[4][4];

    guRotateF(mf, a, x, y, z);

    guMtxF2L(mf, m);
}
