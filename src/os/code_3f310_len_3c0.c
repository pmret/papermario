#include "common.h"

float dtor = 3.1415926 / 180.0;

INCLUDE_ASM(void, "os/code_3f310_len_3c0", guPositionF, float mf[4][4], float r, float p, float h, float s, float x,
            float y, float z);

INCLUDE_ASM(void, "os/code_3f310_len_3c0", guPosition, Mtx* m, float r, float p, float h, float s, float x, float y,
            float z);
