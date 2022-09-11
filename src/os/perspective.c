#include "PR/guint.h"

f32 sin_rad(f32 x);
f32 cos_rad(f32 x);

void guPerspectiveF(f32 mf[4][4], u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 cot;
    s32 i, j;

    guMtxIdentF(mf);

    fovy *= 3.1415926 / 180.0;
    cot = cos_rad(fovy/2) / sin_rad(fovy/2);

    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = -1;
    mf[3][2] = (2 * near * far) / (near - far);
    mf[3][3] = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            mf[i][j] *= scale;
        }
    }

    if (perspNorm != (u16 *) NULL) {
        if (near + far <= 2.0) {
            *perspNorm = (u16) 0xFFFF;
        } else  {
            *perspNorm = (u16) ((2.0 * 65536.0) / (near + far));
            if (*perspNorm <= 0) {
                *perspNorm = (u16) 0x0001;
            }
        }
    }
}

void guPerspective(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 mf[4][4];

    guPerspectiveF(mf, perspNorm, fovy, aspect, near, far, scale);

    guMtxF2L(mf, m);
}
