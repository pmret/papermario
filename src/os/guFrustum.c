#include "common.h"

INCLUDE_ASM(void, "os/guFrustum", guFrustumF, float mf[4][4], float l, float r, float b, float t, float n,
            float f, float scale);

INCLUDE_ASM(void, "os/guFrustum", guFrustum, Mtx* m, float l, float r, float b, float t, float n, float f,
            float scale);
