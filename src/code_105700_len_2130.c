#include "common.h"

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E3E80);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E3E9C);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E3EE0);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E3F0C);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E4040);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E405C);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E40A0);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E4108);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E4154);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E421C);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E4484);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E44CC);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E44F8);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E4540);

void func_802E455C(s32 entityIndex) {
    Gfx* gfx = gMasterGfxPos;
    Entity* entity = get_entity_by_index(entityIndex);

    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPTexture(gfx++, -1, -1, 0, G_TX_RENDERTILE, G_ON);

    if (entity->alpha >= 255) {
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    } else {
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, entity->alpha);
    }

    gMasterGfxPos = gfx;
}

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E464C);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E4694);

INCLUDE_ASM(s32, "code_105700_len_2130", func_802E46BC);
