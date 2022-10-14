#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"

extern SpriteShadingProfile D_801595C0;
extern SpriteShadingProfile D_80159670;
extern SpriteShadingProfile D_80159720;
extern SpriteShadingProfile D_801597D0;
extern s8 D_80159880[0x20];

extern int ENVIRONMENT;
extern int COMBINED;
extern int COMBINED_ALPHA;
extern int SHADE;
extern int TEXEL0_ALPHA;

void init_sprite_shading_data(void);
void appendGfx_shading_palette(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha,
                             f32 shadowX, f32 shadowY, f32 shadowZ,
                             s32 shadowR, s32 shadowG, s32 shadowB,
                             s32 highlightR, s32 highlightG, s32 highlightB,
                             s32 ambientPower, s32 otherModeLBits);

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

void create_shading_palette(Matrix4f mtx, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 alpha, s32 otherModeLBits) {
    Camera* camera = &gCameras[gCurrentCameraID];
    SpriteShadingLightSource* lightSource;
    f32 shadowX, shadowY, shadowZ;
    f32 sp54, sp58, sp5C;
    f32 sp60;
    f32 sp64, var_f30, sp68;
    f32 shadowR, shadowG, shadowB;
    f32 sp78, sp7C, sp80;
    f32 sp84, sp88, sp8C;
    f32 sp90, sp94, sp98;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f16;
    f32 temp_f20;
    f32 temp_f26, temp_f24, temp_f22;
    f32 temp_f6;
    f32 var_f0_2;
    f32 var_f2;
    f32 var_f8;
    f32 temp3;
    f32 qx, qy, qz;
    f32 wx, wy, wz;
    f32 ex, ey, ez;
    s32 i;

    shadowX = 0.0f;
    shadowY = 0.0f;
    shadowZ = 0.0f;

    sp54 = mtx[3][0];
    sp58 = mtx[3][1];
    sp5C = mtx[3][2];

    sp78 = 0.0f;
    sp7C = 0.0f;
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

    shadowR = D_80151328->ambientColor.r;
    shadowG = D_80151328->ambientColor.g;
    shadowB = D_80151328->ambientColor.b;

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

            temp_f26 *= var_f0_2;
            temp_f24 *= var_f0_2;
            temp_f22 *= var_f0_2;

            if ((lightSource->flags & 4)) {
                if ((var_f2 == 0.0f) && (lightSource->falloff == 0.0f)) {
                    var_f8 = 1.0f;
                } else {
                    var_f8 = 1.0f / (var_f2 * lightSource->falloff);
                    temp_f26 *= var_f8;
                    temp_f24 *= var_f8;
                    temp_f22 *= var_f8;
                }
            } else {
                if ((lightSource->flags & 8) && (temp_f20 != 0.0f || lightSource->falloff != 0.0f)) {
                    var_f8 = 1.0f / (temp_f20 * lightSource->falloff);
                    temp_f26 *= var_f8;
                    temp_f24 *= var_f8;
                    temp_f22 *= var_f8;
                } else {
                    var_f8 = 1.0f;
                }
            }

            if (var_f8 > 1.0f) {
                var_f8 = 1.0f;
            }
            shadowX += temp_f26;
            shadowY += temp_f24;
            shadowZ += temp_f22;

            if (sp60 < 0.0f) {
                ex = sp64;
                ey = var_f30;
                ez = -sp68;
            } else {
                ex = -sp64;
                ey = var_f30;
                ez = sp68;
            }
            temp_f10 = ex * temp_f26 + ey * temp_f24 + ez * temp_f22;

            if (sp60 < 0.0f) {
                wx = sp68;
                wy = var_f30;
                wz = sp64;
            } else {
                wx = -sp68;
                wy = var_f30;
                wz = -sp64;
            }
            temp3 = wx * temp_f26 + wy * temp_f24 + wz * temp_f22;

            temp_f16 = temp3;
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
                shadowR += lightSource->rgb.r * temp_f12;
                shadowG += lightSource->rgb.g * temp_f12;
                shadowB += lightSource->rgb.b * temp_f12;
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
        qx = sp68;
        qy = var_f30;
        qz = sp64;
    } else {
        qx = -sp68;
        qy = var_f30;
        qz = -sp64;
    }

    if (qx * shadowX + qy * shadowY + qz * shadowZ > 0.0f) {
        appendGfx_shading_palette(
            mtx,
            uls, ult, lrs, lrt,
            alpha,
            shadowX, shadowY, shadowZ,
            shadowR, shadowG, shadowB,
            D_80151328->ambientColor.r + sp78 + sp84,
            D_80151328->ambientColor.g + sp7C + sp88,
            D_80151328->ambientColor.b + sp80 + sp8C,
            D_80151328->ambientPower, otherModeLBits
        );
    } else {
        appendGfx_shading_palette(
            mtx,
            uls, ult, lrs, lrt,
            alpha,
            shadowX, shadowY, shadowZ,
            shadowR, shadowG, shadowB,
            D_80151328->ambientColor.r + sp78 + sp90,
            D_80151328->ambientColor.g + sp7C + sp94,
            D_80151328->ambientColor.b + sp80 + sp98,
            D_80151328->ambientPower, otherModeLBits
        );
    }
}

// float regalloc
#ifdef NON_MATCHING
void appendGfx_shading_palette(
    Matrix4f mtx,
    s32 uls, s32 ult, s32 lrs, s32 lrt,
    s32 alpha,
    f32 shadowX, f32 shadowY, f32 shadowZ,
    s32 shadowR, s32 shadowG, s32 shadowB,
    s32 highlightR, s32 highlightG, s32 highlightB,
    s32 ambientPower, s32 renderMode)
{
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 temp_f0;
    f32 asdasdasd;
    f32 temp_f2;
    f32 var_f26;
    f32 temp_f28 = 0;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f20;
    f32 var_f2;
    f32 var_f30;
    f32 var_f8;
    f32 abc;
    f32 ex, ey, ez;
    f32 t1;

    var_f12 = (shadowX * shadowX) + (shadowY * shadowY) + (shadowZ * shadowZ);

    if (var_f12 < 1.0) {
        ambientPower *= var_f12;
    }
    if (var_f12 != 0.0f) {
        var_f12 = 1.0f / sqrtf(var_f12);
    }
    shadowX *= var_f12;
    shadowY *= var_f12;
    shadowZ *= var_f12;

    if ((-mtx[0][2] * camera->perspectiveMatrix[0][2]) + (mtx[2][2] * camera->perspectiveMatrix[2][2]) < 0.0f) {
        var_f30 = 1.0f;
    } else {
        var_f30 = -1.0f;
    }

    if (var_f30 < 0.0f) {
        ex = mtx[0][2];
        ey = mtx[1][2];
        ez = -mtx[2][2];
    } else {
        ex = -mtx[0][2];
        ey = mtx[1][2];
        ez = mtx[2][2];
    }

    temp_f6 = ex * shadowX;
    temp_f6_2 = (shadowX * -camera->perspectiveMatrix[2][2]) + (shadowZ * camera->perspectiveMatrix[0][2]);
    t1 = temp_f6 + (ey * shadowY) + (ez * shadowZ);
    if (t1 > 0.0f) {
        var_f26 = ambientPower * temp_f6_2;
    } else {
        var_f26 = ambientPower;
        var_f26 = ambientPower * temp_f6_2;
    }
    var_f20 = SQ(shadowX) + SQ(shadowZ);
    if (var_f20 != 0.0f) {
        var_f20 = sqrtf(var_f20);
    }
    temp_f0 = -mtx[0][1];
    asdasdasd = mtx[1][1];
    temp_f2 = mtx[2][1];
    var_f12_2 = SQ(temp_f0) + SQ(temp_f2);
    if (var_f12_2 != 0.0f) {
        var_f12_2 = sqrtf(var_f12_2);
    }
    temp_f28 = -((var_f20 * var_f12_2) + (shadowY * asdasdasd)) * ambientPower;
    if (shadowR > 255) {
        shadowR = 255;
    }
    if (shadowG > 255) {
        shadowG = 255;
    }
    if (shadowB > 255) {
        shadowB = 255;
    }
    if (highlightR > 255) {
        highlightR = 255;
    }
    if (highlightG > 255) {
        highlightG = 255;
    }
    if (highlightB > 255) {
        highlightB = 255;
    }

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, shadowR, shadowG, shadowB, alpha);
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL1, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, COMBINED, TEXEL0, COMBINED_ALPHA,
                      TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, D_80159880);
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 16, 1);

    gSPSetOtherMode(gMasterGfxPos++, G_SETOTHERMODE_H, 4, 18,
                    G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_POINT | G_TT_NONE | G_TL_TILE |
                    G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE);

    gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    gDPSetPrimColor(gMasterGfxPos++, 0, 0, shadowR, shadowG, shadowB, alpha);
    gDPSetEnvColor(gMasterGfxPos++, highlightR, highlightG, highlightB, 0);
    gDPSetCombineLERP(gMasterGfxPos++, PRIMITIVE, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, 1,
                      PRIMITIVE, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, 1);
    gSPTextureRectangle(gMasterGfxPos++, 0, 0, 16 << 2, 1 << 2, 2, 0, 0, 4 << 10, 1 << 10);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));

    gDPSetScissor(
        gMasterGfxPos++, 0,
        camera->viewportStartX,
        camera->viewportStartY,
        camera->viewportStartX + camera->viewportW,
        camera->viewportStartY + camera->viewportH
    );

    gDPLoadTLUT_pal16(gMasterGfxPos++, 1, D_80159880);

    gSPSetOtherMode(gMasterGfxPos++, G_SETOTHERMODE_H, 4, 18,
                    G_AD_DISABLE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE |
                    G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE);

    gDPSetRenderMode(gMasterGfxPos++, G_RM_PASS, renderMode);
    gDPSetEnvColor(gMasterGfxPos++, 100, 100, 100, 255);

    if (alpha == 255) {
        gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, TEXEL1, 0, 0, 0, 0, TEXEL1, SHADE, ENVIRONMENT, COMBINED,
                          COMBINED, 0, 0, 0, COMBINED);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, TEXEL1, 0, PRIMITIVE, 0, TEXEL1, 0, SHADE, ENVIRONMENT, COMBINED,
                          COMBINED, 0, 0, 0, COMBINED);
    }

    abc = var_f26;
    abc *= var_f30;
    gDPSetTileSize(
        gMasterGfxPos++,
        0,
        ((uls + 0x100) << 2) + (s32)abc,
        ((ult + 0x100) << 2) + (s32)temp_f28,
        ((lrs + 0x100 - 1) << 2) + (s32)abc,
        ((lrt + 0x100 - 1) << 2) + (s32)temp_f28
    );
}
#else
INCLUDE_ASM(s32, "de740_len_23f0", appendGfx_shading_palette);
#endif

void func_801491E4(Matrix4f mtx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 alpha) {
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);

    if (alpha == 255) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    }
}
