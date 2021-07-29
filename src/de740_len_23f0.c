#include "common.h"

INCLUDE_ASM(s32, "de740_len_23f0", clear_sprite_shading_data);

INCLUDE_ASM(s32, "de740_len_23f0", init_sprite_shading_data);

INCLUDE_ASM(s32, "de740_len_23f0", sprite_shading_set_light_source);

INCLUDE_ASM(s32, "de740_len_23f0", render_shaded_sprite);

INCLUDE_ASM(s32, "de740_len_23f0", appendGfx_shaded_sprite);

void func_801491E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 alpha) {
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);

    if (alpha == 255) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    }
}
