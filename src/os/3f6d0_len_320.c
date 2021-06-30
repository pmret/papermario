#include "common.h"

f32 D_80093DD0 = M_DTOR;

INCLUDE_ASM(void, "os/3f6d0_len_320", guRotateRPYF, float mf[4][4], f32 x, f32 y, f32 z);

INCLUDE_ASM(void, "os/3f6d0_len_320", guRotateRPY, Mtx *m, float r, float p, float y);
