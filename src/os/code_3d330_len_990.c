#include "common.h"

void INCLUDE_ASM("os/code_3d330_len_990", guFrustumF, float mf[4][4], float l, float r, float b, float t, float n,
                 float f, float scale);

void INCLUDE_ASM("os/code_3d330_len_990", guFrustum, Mtx* m, float l, float r, float b, float t, float n, float f,
                 float scale);

void INCLUDE_ASM("os/code_3d330_len_990", guLookAtF, float mf[4][4], float xEye, float yEye, float zEye, float xAt,
                 float yAt, float zAt, float xUp, float yUp, float zUp);

void INCLUDE_ASM("os/code_3d330_len_990", guLookAt, Mtx* m, float xEye, float yEye, float zEye, float xAt, float yAt,
                 float zAt, float xUp, float yUp, float zUp);
