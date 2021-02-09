#include "common.h"

INCLUDE_ASM(void, "os/guLookAt", guLookAtF, float mf[4][4], float xEye, float yEye, float zEye, float xAt,
            float yAt, float zAt, float xUp, float yUp, float zUp);

INCLUDE_ASM(void, "os/guLookAt", guLookAt, Mtx* m, float xEye, float yEye, float zEye, float xAt, float yAt,
            float zAt, float xUp, float yUp, float zUp);
