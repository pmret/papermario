#include "PR/guint.h"

void guLookAtHiliteF(f32 mf[4][4], LookAt *l, Hilite *h,
                     f32 xEye, f32 yEye, f32 zEye,
                     f32 xAt,  f32 yAt,  f32 zAt,
                     f32 xUp,  f32 yUp,  f32 zUp,
                     f32 xl1,  f32 yl1,  f32 zl1, /* light 1 direction */
                     f32 xl2,  f32 yl2,  f32 zl2, /* light 2 direction */
                     int twidth, int theight) {   /* highlight txtr size*/
    f32 len, xLook, yLook, zLook, xRight, yRight, zRight;
    f32 xHilite, yHilite, zHilite;

    guMtxIdentF(mf);

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    /* Negate because positive Z is behind us: */
    len = -1.0 / sqrtf (xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    /* Right = Up x Look */
    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0 / sqrtf (xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    /* Up = Look x Right */
    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0 / sqrtf (xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    /* hilite vectors */
    len = 1.0 / sqrtf (xl1 * xl1 + yl1 * yl1 + zl1 * zl1);
    xl1 *= len;
    yl1 *= len;
    zl1 *= len;

#define THRESH2 0.1
    xHilite = xl1 + xLook;
    yHilite = yl1 + yLook;
    zHilite = zl1 + zLook;

    len = sqrtf (xHilite * xHilite + yHilite * yHilite + zHilite * zHilite);

    if (len>THRESH2) {
        len = 1.0 / len;
        xHilite *= len;
        yHilite *= len;
        zHilite *= len;

        h->h.x1 = twidth * 4 + (xHilite * xRight + yHilite * yRight + zHilite * zRight) * twidth * 2;

        h->h.y1 = theight * 4 + (xHilite * xUp + yHilite * yUp + zHilite * zUp) * theight * 2;
    } else {
        h->h.x1 = twidth * 2;
        h->h.y1 = theight * 2;
    }

    len = 1.0 / sqrtf (xl2 * xl2 + yl2 * yl2 + zl2 * zl2);
    xl2 *= len;
    yl2 *= len;
    zl2 *= len;

    xHilite = xl2 + xLook;
    yHilite = yl2 + yLook;
    zHilite = zl2 + zLook;
    len = sqrtf (xHilite * xHilite + yHilite * yHilite + zHilite * zHilite);
    if (len>THRESH2) {
        len = 1.0 / len;
        xHilite *= len;
        yHilite *= len;
        zHilite *= len;

        h->h.x2 = twidth * 4 + (xHilite * xRight + yHilite * yRight + zHilite * zRight) * twidth * 2;

        h->h.y2 = theight * 4 + (xHilite * xUp + yHilite * yUp + zHilite * zUp) * theight * 2;
    } else {
        h->h.x2 = twidth * 2;
        h->h.y2 = theight * 2;
    }

    /* reflectance vectors = Up and Right */
    l->l[0].l.dir[0] = FTOFRAC8(xRight);
    l->l[0].l.dir[1] = FTOFRAC8(yRight);
    l->l[0].l.dir[2] = FTOFRAC8(zRight);
    l->l[1].l.dir[0] = FTOFRAC8(xUp);
    l->l[1].l.dir[1] = FTOFRAC8(yUp);
    l->l[1].l.dir[2] = FTOFRAC8(zUp);
    l->l[0].l.col[0] = 0x00;
    l->l[0].l.col[1] = 0x00;
    l->l[0].l.col[2] = 0x00;
    l->l[0].l.pad1 = 0x00;
    l->l[0].l.colc[0] = 0x00;
    l->l[0].l.colc[1] = 0x00;
    l->l[0].l.colc[2] = 0x00;
    l->l[0].l.pad2 = 0x00;
    l->l[1].l.col[0] = 0x00;
    l->l[1].l.col[1] = 0x80;
    l->l[1].l.col[2] = 0x00;
    l->l[1].l.pad1 = 0x00;
    l->l[1].l.colc[0] = 0x00;
    l->l[1].l.colc[1] = 0x80;
    l->l[1].l.colc[2] = 0x00;
    l->l[1].l.pad2 = 0x00;

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = 1;
}

void guLookAtHilite (Mtx *m, LookAt *l, Hilite *h,
                     f32 xEye, f32 yEye, f32 zEye,
                     f32 xAt,  f32 yAt,  f32 zAt,
                     f32 xUp,  f32 yUp,  f32 zUp,
                     f32 xl1,  f32 yl1,  f32 zl1, /* light 1 direction */
                     f32 xl2,  f32 yl2,  f32 zl2, /* light 2 direction */
                     int twidth, int theight) {   /* highlight txtr size*/
    f32 mf[4][4];

    guLookAtHiliteF(mf, l, h, xEye, yEye, zEye, xAt, yAt, zAt,
            xUp, yUp, zUp, xl1, yl1, zl1, xl2, yl2, zl2,
            twidth, theight);

    guMtxF2L(mf, m);
}
