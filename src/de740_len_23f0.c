#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"

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

void appendGfx_shaded_sprite(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha,
                             f32 shadowX, f32 shadowY, f32 shadowZ,
                             s32 shadowR, s32 shadowG, s32 shadowB,
                             s32 highlightR, s32 highlightG, s32 highlightB,
                             s32 ambientPower, s32 otherModeLBits);

//help
#ifdef NON_MATCHING
void render_shaded_sprite(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha, s32 otherModeLBits) {
    Camera* camera = &gCameras[gCurrentCameraID];
    SpriteShadingLightSource* lightSource;
    f32 highlightR;
    f32 highlightG;
    f32 highlightB;
    s32 i;

    f32 sp48;
    f32 sp4C;
    f32 sp50;

    f32 sp54;
    f32 sp58;
    f32 sp5C;

    f32 sp60;
    f32 sp64;
    f32 var_f30;
    f32 sp68;
    f32 sp6C;
    f32 sp70;
    f32 sp74;
    f32 sp78;
    f32 sp7C;
    f32 sp80;
    f32 sp84;
    f32 sp88;
    f32 sp8C;
    f32 sp90;
    f32 sp94;
    f32 sp98;

    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f16;

    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;

    f32 temp_f6;
    f32 var_f0_2;
    f32 var_f0_4;
    f32 var_f0_5;
    f32 var_f22;
    f32 var_f24;
    f32 var_f26;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f4;
    f32 var_f4_2;
    f32 var_f6;
    f32 var_f8;

    sp48 = 0.0f;
    sp4C = 0.0f;
    sp50 = 0.0f;

    sp54 = mtx[3][0];
    sp58 = mtx[3][1];
    sp5C = mtx[3][2];

    sp7C = 0.0f;
    sp78 = 0.0f;
    sp80 = 0.0f;

    sp84 = 0.0f;
    sp88 = 0.0f;
    sp8C = 0.0f;

    sp64 = mtx[0][2];
    var_f30 = mtx[1][2];
    sp68 = mtx[2][2];

    sp90 = 0.0f;
    sp94 = 0.0f;
    sp98 = 0.0f;

    sp6C = D_80151328->ambientColor.r;
    sp70 = D_80151328->ambientColor.g;
    sp74 = D_80151328->ambientColor.b;

    if (((-sp64 * camera->perspectiveMatrix[0][2]) + (sp68 * camera->perspectiveMatrix[2][2])) < 0.0f) {
        sp60 = 1.0f;
    } else {
        sp60 = -1.0f;
    }

    for (i = 0; i < ARRAY_COUNT(D_80151328->sources); i++) {
        lightSource = &D_80151328->sources[i];
        if (lightSource->flags & 1) {
            temp_f26 = sp54 - lightSource->pos.x;
            temp_f24 = sp58 - lightSource->pos.y;
            temp_f22 = sp5C - lightSource->pos.z;

            temp_f20 = SQ(temp_f26) + SQ(temp_f24) + SQ(temp_f22);

            if (temp_f20 != 0.0f) {
                var_f2 = sqrtf(temp_f20);
                var_f0_2 = 1.0f / var_f2;
            } else {
                var_f2 = 0.0f;
                var_f0_2 = 0.0f;
            }

            var_f26 = temp_f26 * var_f0_2;
            var_f24 = temp_f24 * var_f0_2;
            var_f22 = temp_f22 * var_f0_2;

            if ((lightSource->flags & 4)) {
                if ((var_f2 == 0.0f) && (lightSource->falloff == 0.0f)) {
                    var_f8 = 1.0f;
                } else {
                    var_f8 = 1.0f / (var_f2 * lightSource->falloff);
                    var_f26 *= var_f8;
                    var_f24 *= var_f8;
                    var_f22 *= var_f8;
                }
            } else {
                if ((lightSource->flags & 8) && ((temp_f20 != 0.0f) || (lightSource->falloff != 0.0f))) {
                    var_f8 = 1.0f / (temp_f20 * lightSource->falloff);
                    var_f26 *= var_f8;
                    var_f24 *= var_f8;
                    var_f22 *= var_f8;
                } else {
                    var_f8 = 1.0f;
                }
            }

            if (var_f8 > 1.0f) {
                var_f8 = 1.0f;
            }
            sp48 += var_f26;
            sp4C += var_f24;
            sp50 += var_f22;

            if (sp60 < 0.0f) {
                var_f0_4 = sp64;
                var_f4 = -sp68;
            } else {
                var_f0_4 = -sp64;
                var_f4 = sp68;
            }
            temp_f10 = (var_f0_4 * var_f26) + (var_f30 * var_f24) + (var_f4 * var_f22);

            if (sp60 < 0.0f) {
                var_f2_2 = sp68;
                var_f6 = sp64;
            } else {
                var_f2_2 = -sp68;
                var_f6 = -sp64;
            }

            temp_f16 = (var_f2_2 * var_f26) + (var_f30 * var_f24) + (var_f6 * var_f22);
            temp_f12 = var_f8 * fabsf(temp_f10);
            temp_f6 = var_f8 * fabsf(temp_f16);
            if (temp_f10 > 0.0f) {
                sp78 += lightSource->rgb.r * temp_f12;
                sp7C += lightSource->rgb.g * temp_f12;
                sp80 += lightSource->rgb.b * temp_f12;
                if (temp_f16 > 0.0f) {
                    sp84 += lightSource->rgb.r * temp_f6;
                    sp88 += lightSource->rgb.g * temp_f6;
                    sp8C += lightSource->rgb.b * temp_f6;
                } else {
                    sp90 += lightSource->rgb.r * temp_f6;
                    sp94 += lightSource->rgb.g * temp_f6;
                    sp98 += lightSource->rgb.b * temp_f6;
                }
            } else {
                sp6C += lightSource->rgb.r * temp_f12;
                sp70 += lightSource->rgb.g * temp_f12;
                sp74 += lightSource->rgb.b * temp_f12;
                if (temp_f16 > 0.0f) {
                    sp84 += lightSource->rgb.r * temp_f6;
                    sp88 += lightSource->rgb.g * temp_f6;
                    sp8C += lightSource->rgb.b * temp_f6;
                } else {
                    sp90 += lightSource->rgb.r * temp_f6;
                    sp94 += lightSource->rgb.g * temp_f6;
                    sp98 += lightSource->rgb.b * temp_f6;
                }
            }
        }
    }

    if (sp60 < 0.0f) {
        var_f0_5 = sp68;
        var_f4_2 = sp64;
    } else {
        var_f0_5 = -sp68;
        var_f4_2 = -sp64;
    }

    if ((var_f0_5 * sp48) + (mtx[1][2] * sp4C) + (var_f4_2 * sp50) > 0.0f) {
        appendGfx_shaded_sprite(
            mtx,
            uls, ult, lrs, lrt,
            alpha,
            sp48, sp4C, sp50,
            sp6C, sp70, sp74,
            D_80151328->ambientColor.r + sp78 + sp84,
            D_80151328->ambientColor.g + sp7C + sp88,
            D_80151328->ambientColor.b + sp80 + sp8C,
            D_80151328->ambientPower, otherModeLBits
        );
    } else {
        appendGfx_shaded_sprite(
            mtx,
            uls, ult, lrs, lrt,
            alpha,
            sp48, sp4C, sp50,
            sp6C, sp70, sp74,
            D_80151328->ambientColor.r + sp78 + sp90,
            D_80151328->ambientColor.g + sp7C + sp94,
            D_80151328->ambientColor.b + sp80 + sp98,
            D_80151328->ambientPower, otherModeLBits
        );
    }
}
#else
INCLUDE_ASM(s32, "de740_len_23f0", render_shaded_sprite);
#endif

INCLUDE_ASM(s32, "de740_len_23f0", appendGfx_shaded_sprite);

void func_801491E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 alpha) {
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);

    if (alpha == 255) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    }
}
