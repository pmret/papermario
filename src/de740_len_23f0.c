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

INCLUDE_ASM(s32, "de740_len_23f0", render_shaded_sprite);

extern s32* D_80159880;

INCLUDE_ASM(s32, "de740_len_23f0", appendGfx_shaded_sprite);
// void appendGfx_shaded_sprite(Matrix4f mtx, s32 tileULS, s32 tileULT, s32 tileSizeS, s32 tileSizeT, s32 alpha,
//                              f32 shadowDirX, f32 shadowDirY, f32 shadowDirZ, s32 shadowR, s32 shadowG, s32 shadowB,
//                              s32 highlightR, s32 highlightG, s32 highlightB, s32 ambientPower, s32 arg10)
// {
//     Camera* camera;
//     Gfx* temp_a3;
//     f32 temp_f12;
//     f32 temp_f12_2;
//     f32 temp_f20_2;
//     f32 temp_f28;
//     f32 temp_f4;
//     f32 temp_f6;
//     f32 temp_f6_2;
//     f32 temp_f8;
//     f32 phi_f30;
//     f32 phi_f2;
//     f32 phi_f26;

//     temp_f12 = SQ(shadowDirX) + SQ(shadowDirY) + SQ(shadowDirZ);
//     camera = &gCameras[gCurrentCameraID];
//     if (temp_f12 < 1.0) {
//         ambientPower *= temp_f12;
//     }
//     if (temp_f12 != 0.0f) {
//         temp_f12 = 1.0f / sqrtf(temp_f12);
//     }
//     shadowDirX *= temp_f12;
//     shadowDirY *= temp_f12;
//     shadowDirZ *= temp_f12;
//     temp_f6 = mtx[0][2];
//     temp_f4 = -temp_f6;
//     temp_f8 = mtx[2][2];

//     if (((temp_f4 * camera->perspectiveMatrix[0][2]) + (temp_f8 * camera->perspectiveMatrix[2][2])) < 0.0f) {
//         phi_f30 = 1.0f;
//     } else {
//         phi_f30 = -1.0f;
//     }

//     phi_f2 = temp_f6;
//     if (phi_f30 < 0.0f) {
//         temp_f8 = -temp_f8;
//     } else {
//         phi_f2 = temp_f4;
//     }
//     temp_f6_2 = (shadowDirX * -camera->perspectiveMatrix[2][2]) + (shadowDirZ * camera->perspectiveMatrix[0][2]);

//     if (((phi_f2 * shadowDirX) + (mtx[1][2] * shadowDirY) + (temp_f8 * shadowDirZ)) > 0.0f) {
//         phi_f26 = (f32) ambientPower * temp_f6_2;
//     } else {
//         phi_f26 = (f32) ambientPower * temp_f6_2;
//     }
//     temp_f20_2 = SQ(shadowDirX) + SQ(shadowDirZ);
//     if (temp_f20_2 != 0.0f) {
//         temp_f20_2 = sqrtf(temp_f20_2);
//     }
//     temp_f12_2 = SQ(-mtx[0][4]) + SQ(mtx[2][1]);
//     if (temp_f12_2 != 0.0f) {
//         temp_f12_2 = sqrtf(temp_f12_2);
//     }
//     temp_f28 = -((temp_f20_2 * temp_f12_2) + (shadowDirY * mtx[1][1])) * ambientPower;
//     if (shadowR > 0xFF) {
//         shadowR = 0xFF;
//     }
//     if (shadowG > 0xFF) {
//         shadowG = 0xFF;
//     }
//     if (shadowB > 0xFF) {
//         shadowB = 0xFF;
//     }
//     if (highlightR > 0xFF) {
//         highlightR = 0xFF;
//     }
//     if (highlightG > 0xFF) {
//         highlightG = 0xFF;
//     }
//     if (highlightB > 0xFF) {
//         highlightB = 0xFF;
//     }

//     gDPSetPrimColor(gMasterGfxPos++, 0, 0, shadowR, shadowG, shadowB, alpha);
//     gDPSetCombineLERP(gMasterGfxPos++, TEXEL1, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, COMBINED, TEXEL0, COMBINED_ALPHA,
//                       TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
//     gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, D_80159880);
//     gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 16, 1);

//     //temp_s0_2->unk18 = E3000A1100000CF0
//     //temp_s0_2->unk20 = E200001C0F0A4000
//     gDPSetRenderMode(gMasterGfxPos++, G_RM_PASS, G_RM_NOOP2);
//     gDPSetRenderMode(gMasterGfxPos++, G_RM_PASS, G_RM_NOOP2);


//     gDPSetPrimColor(gMasterGfxPos++, 0, 0, shadowR, shadowG, shadowB, alpha);
//     gDPSetEnvColor(gMasterGfxPos++, highlightR, highlightG, highlightB, 0);
//     gDPSetCombineLERP(gMasterGfxPos++, PRIMITIVE, ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, 1, PRIMITIVE,
//                       ENVIRONMENT, TEXEL0_ALPHA, ENVIRONMENT, 0, 0, 0, 1);
//     gSPTextureRectangle(gMasterGfxPos++, 0, 0, 0x0040, 0x0004, 2, 0, 0, 0x1000, 0x0400);
//     gDPPipeSync(gMasterGfxPos++);
//     gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
//     gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
//                   camera->viewportStartX, camera->viewportStartY,
//                   camera->viewportStartX + camera->viewportW, camera->viewportStartY + camera->viewportH);
//     gDPLoadTLUT_pal16(gMasterGfxPos++, 1, D_80159880);

//     //temp_t2_2->unk30 = E3000A110018AC30
//     //temp_t2_2->unk38 = E200001C0C080000 //| arg10
//     gDPSetRenderMode(gMasterGfxPos++, G_RM_PASS, G_RM_NOOP2);
//     gDPSetRenderMode(gMasterGfxPos++, G_RM_PASS, G_RM_NOOP2 | arg10);

//     gDPSetEnvColor(gMasterGfxPos++, 100, 100, 100, 255);

//     if (alpha == 0xFF) {
//         gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, TEXEL1, 0, 0, 0, 0, TEXEL1, SHADE, ENVIRONMENT, COMBINED,
//                           COMBINED, 0, 0, 0, COMBINED);
//     } else {
//         gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, TEXEL1, 0, PRIMITIVE, 0, TEXEL1, 0, SHADE, ENVIRONMENT, COMBINED,
//                           COMBINED, 0, 0, 0, COMBINED)
//     }

//     temp_a3->words.w0 = (((((tileULS + 0x100) * 4) + (s32) (phi_f26 * phi_f30)) & 0xFFF) << 0xC) | (((((tileULT + 0x100) * 4) + (s32)temp_f28) & 0xFFF) | 0xF2000000);
//     temp_a3->words.w1 = (((((tileSizeS + 0xFF) * 4) + (s32) (phi_f26 * phi_f30)) & 0xFFF) << 0xC) | ((((tileSizeT + 0xFF) * 4) + (s32)temp_f28) & 0xFFF);
// }

void func_801491E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 alpha) {
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);

    if (alpha == 255) {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL1, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    } else {
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    }
}
