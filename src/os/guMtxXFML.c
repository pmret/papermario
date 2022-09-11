#include "PR/guint.h"

void guMtxXFML(Mtx *m, float x, float y, float z, float *ox, float *oy, float *oz)
{
    float mf[4][4];

    guMtxL2F(mf, m);

    guMtxXFMF(mf, x, y, z, ox, oy, oz);
}
