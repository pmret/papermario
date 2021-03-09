#include "common.h"

f32 dtor = M_DTOR;

INCLUDE_ASM(void, "os/code_3f310_len_3c0", guPositionF, float mf[4][4], float r, float p, float h, float s, float x,
            float y, float z);

INCLUDE_ASM(void, "os/code_3f310_len_3c0", guPosition, Mtx* m, float r, float p, float h, float s, float x, float y,
            float z);
