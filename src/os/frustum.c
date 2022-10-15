#include "PR/guint.h"

void guFrustumF(f32 mf[4][4], f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    s32 i, j;

    guMtxIdentF(mf);

    mf[0][0] = 2*n/(r-l);
    mf[1][1] = 2*n/(t-b);
    mf[2][0] = (r+l)/(r-l);
    mf[2][1] = (t+b)/(t-b);
    mf[2][2] = -(f+n)/(f-n);
    mf[2][3] = -1;
    mf[3][2] = -2*f*n/(f-n);
    mf[3][3] = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            mf[i][j] *= scale;
        }
    }
}

void guFrustum(Mtx* m, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    f32 mf[4][4];

    guFrustumF(mf, l, r, b, t, n, f, scale);

    guMtxF2L(mf, m);
}
