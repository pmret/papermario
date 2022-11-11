#include "mac_05.h"

extern f32 D_80252744_8648B4;

// ordering
#ifdef NON_MATCHING
void func_80243DB0_855F20(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 temp_f8;
    f32 var_f6;
    s32 temp_f10;
    f64 temp_f2;

    if (arg2 <= 0.5f) {
        temp_f2 = (f64) arg2;
        var_f6 = (arg1 * temp_f2) + temp_f2;
    } else {
        var_f6 = (arg2 + arg1) - (arg2 * arg1);
    }

    if (var_f6 == 0.0f) {
        *arg5 = 0.0f;
        *arg4 = 0.0f;
        *arg3 = 0.0f;
        return;
    }
    temp_f12 = arg0 * 6.0f;
    temp_f8 = (2.0f * arg2) - var_f6;
    temp_f4 = (s32) temp_f12;
    temp_f0 = var_f6 * ((var_f6 - temp_f8) / var_f6) * (temp_f12 - temp_f4);
    temp_f2_2 = temp_f8 + temp_f0;
    temp_f0_2 = var_f6 - temp_f0;
    temp_f10 = (s32) temp_f4;
    switch (temp_f10) {
        case 0:
            *arg3 = var_f6;
            *arg4 = temp_f2_2;
            *arg5 = temp_f8;
            break;
        case 1:
            *arg3 = temp_f0_2;
            *arg4 = var_f6;
            *arg5 = temp_f8;
            break;
        case 2:
            *arg3 = temp_f8;
            *arg4 = var_f6;
            *arg5 = temp_f2_2;
            break;
        case 3:
            *arg3 = temp_f8;
            *arg4 = temp_f0_2;
            *arg5 = var_f6;
            break;
        case 4:
            *arg3 = temp_f2_2;
            *arg4 = temp_f8;
            *arg5 = var_f6;
            break;
        case 5:
            *arg3 = var_f6;
            *arg4 = temp_f8;
            *arg5 = temp_f0_2;
            break;
    }
}
#else
void func_80243DB0_855F20(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5);
INCLUDE_ASM(s32, "world/area_mac/mac_05/855F20", func_80243DB0_855F20);
#endif

void func_80243F0C_85607C(s32 index) {
    Vtx* first;
    Vtx* copied;
    s32 numCopied;
    s32 i;
    f32 unk1, unk2, unk3;

    mdl_get_copied_vertices(3, &first, &copied, &numCopied);

    for (i = 0; i < numCopied; i++) {
        u8* colors = copied[i].v.cn;
        f32 temp = D_80252744_8648B4 + (f32)i / (f32)numCopied;
        if (temp > 1.0) {
            temp -= 1.0;
        }
        func_80243DB0_855F20(temp, 1.0f, 0.5f, &unk1, &unk2, &unk3);

        colors[0] = unk1 * 255.0f;
        colors[1] = unk2 * 255.0f;
        colors[2] = unk3 * 255.0f;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(3));
    D_80252744_8648B4 += 0.01;
    if (D_80252744_8648B4 > 1.0) {
        D_80252744_8648B4 -= 1.0f;
    }
}
