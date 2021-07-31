#include "common.h"

INCLUDE_ASM(void, "8e790_len_2850", draw_box, s32 flags, s32 windowStyle, s32 posX, s32 posY, s32 posZ, s32 width,
            s32 height, s32 opacity, s32 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ,
            void (*fpDrawContents)(s32),s32 drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY,
            Matrix4f* outMtx);
