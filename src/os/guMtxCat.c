#include "PR/guint.h"

void guMtxCatL(Mtx *m, Mtx *n, Mtx *res) {
    float mf[4][4], nf[4][4], resf[4][4];

    guMtxL2F(mf, m);
    guMtxL2F(nf, n);

    guMtxCatF(mf, nf, resf);

    guMtxF2L(resf, res);
}
