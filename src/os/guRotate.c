#include "common.h"

INCLUDE_ASM(void, "os/guRotate", guRotateF, float mf[4][4], float a, float x, float y, float z);

INCLUDE_ASM(void, "os/guRotate", guRotate, Mtx* m, float a, float x, float y, float z);
