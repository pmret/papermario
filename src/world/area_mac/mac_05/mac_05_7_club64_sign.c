#include "mac_05.h"

s32 N(UnusedInt) = 0;

f32 N(Club64SignAlphaModulus) = 0.0f;

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

void N(gfx_build_club_64)(s32 index) {
    Vtx* first;
    Vtx* copied;
    s32 numCopied;
    s32 i;
    f32 colR, colG, colB;

    mdl_get_copied_vertices(3, &first, &copied, &numCopied);

    for (i = 0; i < numCopied; i++) {
        u8* colors = copied[i].v.cn;
        f32 alpha = N(Club64SignAlphaModulus) + (f32)i / (f32)numCopied;
        if (alpha > 1.0) {
            alpha -= 1.0;
        }
        func_80243DB0_855F20(alpha, 1.0f, 0.5f, &colR, &colG, &colB);

        colors[0] = colR * 255.0f;
        colors[1] = colG * 255.0f;
        colors[2] = colB * 255.0f;
    }

    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(3));
    N(Club64SignAlphaModulus) += 0.01;
    if (N(Club64SignAlphaModulus) > 1.0) {
        N(Club64SignAlphaModulus) -= 1.0f;
    }
}

EvtScript N(EVS_AnimateClub64Sign) = {
    EVT_CALL(MakeLocalVertexCopy, 3, MODEL_o187, TRUE)
    EVT_CALL(SetCustomGfxBuilders, 3, EVT_PTR(N(gfx_build_club_64)), 0)
    EVT_CALL(SetModelCustomGfx, MODEL_o187, 3, -1)
    EVT_RETURN
    EVT_END
};
