#include "common.h"

extern SpriteShadingProfile D_801595C0;
extern SpriteShadingProfile D_80159670;
extern SpriteShadingProfile D_80159720;
extern SpriteShadingProfile D_801597D0;

void init_sprite_shading_data(void);

void clear_sprite_shading_data(void) {
    s32 i;

    init_sprite_shading_data();

    for (i = 0; i < ARRAY_COUNT(D_80151328->sources); i++) {
        D_80151328->sources[i].flags = 0;
        D_801512B0->sources[i].flags = 0;
    }

    D_80151328->flags = 0;
    D_80151328->ambientColor.r = D_80151328->ambientColor.g = D_80151328->ambientColor.b = 50;
    D_80151328->ambientPower = 10;

    D_801512B0->flags = 0;
    D_801512B0->ambientColor.r = D_801512B0->ambientColor.g = D_801512B0->ambientColor.b = 50;
    D_801512B0->ambientPower = 20;
}

void init_sprite_shading_data(void) {
    if (!gGameStatusPtr->isBattle) {
        D_80151328 = &D_801595C0;
        D_801512B0 = &D_80159720;
    } else {
        D_80151328 = &D_80159670;
        D_801512B0 = &D_801597D0;
    }
}

void sprite_shading_set_light_source(u32 idx, s8 flags, f32 x, f32 y, f32 z, u8 r, u8 g, u8 b, f32 falloff, s8 arg9) {
    SpriteShadingLightSource* lightSource;

    if (idx < ARRAY_COUNT(D_80151328->sources)) {
        lightSource = &D_80151328->sources[idx];
        lightSource->flags = flags;
        lightSource->pos.x = x;
        lightSource->pos.y = y;
        lightSource->pos.z = z;
        lightSource->rgb.r = r;
        lightSource->rgb.g = g;
        lightSource->rgb.b = b;
        lightSource->falloff = falloff;
        lightSource->unk_14 = arg9;
    }
}

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
