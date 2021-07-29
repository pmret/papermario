#include "common.h"

INCLUDE_ASM(void, "os/3ef90_len_600", guPerspectiveF, float mf[4][4], u16* perspNorm, float fovy, float aspect,
            float near, float far, float scale);

INCLUDE_ASM(void, "os/3ef90_len_600", guPerspective, Mtx* m, u16* perspNorm, float fovy, float aspect,
            float near,
            float far, float scale);
