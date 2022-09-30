#include "mac_05.h"

extern f32 D_80252744_8648B4;

INCLUDE_ASM(s32, "world/area_mac/mac_05/855F20", func_80243DB0_855F20);
void func_80243DB0_855F20(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5);

void func_80243F0C_85607C(s32 index) {
    Vtx* first;
    Vtx* copied;
    s32 numCopied;
    s32 i;
    f32 unk1, unk2, unk3;

    mdl_get_copied_vertices(3, &first, &copied, &numCopied);

    for (i = 0; i < numCopied; i++) {
        u8* colors = &copied[i].v.cn;
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
