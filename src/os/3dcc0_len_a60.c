#include "common.h"

INCLUDE_ASM(void, "os/3dcc0_len_a60", guLookAtHiliteF, float mf[4][4], LookAt* l, Hilite* h, float xEye,
            float yEye,
            float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp, float xl1, float yl1,
            float zl1, float xl2, float yl2, float zl2, int twidth, int theight);

INCLUDE_ASM(void, "os/3dcc0_len_a60", guLookAtHilite, Mtx* m, LookAt* l, Hilite* h, float xEye, float yEye,
            float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp, float xl1, float yl1,
            float zl1, float xl2, float yl2, float zl2, int twidth, int theight);
