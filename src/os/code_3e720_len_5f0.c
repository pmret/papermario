#include "common.h"

INCLUDE_ASM(void, "os/code_3e720_len_5f0", guLookAtReflectF, float mf[4][4], LookAt* l, float xEye, float yEye,
            float zEye, float xAt, float yAt, float zAt, float xUp, float yUp, float zUp);

INCLUDE_ASM(void, "os/code_3e720_len_5f0", guLookAtReflect, Mtx* m, LookAt* l, float xEye, float yEye, float zEye,
            float xAt, float yAt, float zAt, float xUp, float yUp, float zUp);
