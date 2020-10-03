#include "common.h"

INCLUDE_ASM(void, "os/code_42e70_len_390", guMtxXFMF, float mf[4][4], float x, float y, float z, float* ox, float* oy,
            float* oz);

INCLUDE_ASM(void, "os/code_42e70_len_390", guRotateF, float mf[4][4], float a, float x, float y, float z);

INCLUDE_ASM(void, "os/code_42e70_len_390", guRotate, Mtx* m, float a, float x, float y, float z);
