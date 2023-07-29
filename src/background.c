#include "common.h"
#include "model.h"
#include "gcc/string.h"

char gCloudyFlowerFieldsBg[] = "fla_bg";
char gSunnyFlowerFieldsBg[] = "flb_bg";
s8 gBackroundWaveEnabled = FALSE;
s16 gBackroundTextureYOffset = 0;
f32 gBackroundWavePhase = 0.0f;

SHIFT_BSS PAL_BIN gBackgroundPalette[256];
SHIFT_BSS f32 gBackroundLastScrollValue;

void load_map_bg(char* optAssetName) {
    if (optAssetName != NULL) {
        UNK_PTR compressedData;
        u32 assetSize;
        char* assetName = optAssetName;

        if (evt_get_variable(NULL, GB_StoryProgress) >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
            // Use sunny Flower Fields bg rather than cloudy
            if (strcmp(assetName, gCloudyFlowerFieldsBg) == 0) {
                assetName = gSunnyFlowerFieldsBg;
            }
        }

        compressedData = load_asset_by_name(assetName, &assetSize);
        decode_yay0(compressedData, &gBackgroundImage);
        general_heap_free(compressedData);
    }
}

void reset_background_settings(void) {
    gBackroundLastScrollValue = 0;
    gBackroundWaveEnabled = FALSE;
    gGameStatusPtr->backgroundDarkness = 180;
    gGameStatusPtr->backgroundFlags &= BACKGROUND_RENDER_STATE_MASK;
}

void read_background_size(BackgroundHeader* bg) {
    gGameStatusPtr->backgroundMaxX = bg->width;
    gGameStatusPtr->backgroundMaxY = bg->height;
    gGameStatusPtr->backgroundMinX = bg->startX;
    gGameStatusPtr->backgroundMinY = bg->startY;
    gGameStatusPtr->backgroundRaster = bg->raster;
    gGameStatusPtr->backgroundPalette = bg->palette;
    gGameStatusPtr->backgroundFlags |= BACKGROUND_FLAG_TEXTURE;
}

void set_background_size(s16 startX, s16 startY, s16 sizeX, s16 sizeY) {
    gGameStatusPtr->backgroundFlags &= ~BACKGROUND_FLAG_TEXTURE;
    gGameStatusPtr->backgroundMaxX = startX;
    gGameStatusPtr->backgroundMaxY = startY;
    gGameStatusPtr->backgroundMinX = sizeX;
    gGameStatusPtr->backgroundMinY = sizeY;
}

u16 blend_background_channel(u16 arg0, s32 arg1, s32 alpha) {
    return arg0 + (arg1 - arg0) * alpha / 256;
}

void appendGfx_background_texture(void) {
    Camera* cam = &gCameras[gCurrentCameraID];
    u16 flags = 0;
    s32 fogR, fogG, fogB, fogA;
    u8 r1, g1, b1, a1;
    u8 r2, g2, b2;
    u16 blendedR, blendedG, blendedB;
    s32 i;

    f32 theta, sinTheta, cosTheta, scrollValue, f5, waveOffset;

    s32 bgMinX;
    s32 bgMinY;
    s32 bgMaxX;
    s32 bgMaxY;
    s32 lineHeight;
    s32 numLines;
    s32 extraHeight;

    s32 bgXOffset;
    s16 texOffsetY;

    u8* newvar;

    if (is_world_fog_enabled()) {
        get_world_fog_color(&fogR, &fogG, &fogB, &fogA);
        flags = 1;
        fogA = gGameStatusPtr->backgroundDarkness;
    }

    switch (*gBackgroundFogModePtr) {
        case FOG_MODE_0:
        case FOG_MODE_1:
            get_background_color_blend(&r1, &g1, &b1, &a1);
            if (a1 != 0) {
                flags |= 2;
            }
            break;
        case FOG_MODE_2:
        case FOG_MODE_3:
        default:
            get_model_env_color_parameters(&r1, &g1, &b1, &r2, &g2, &b2);
            if (!(r1 == 255 && g1 == 255 && b1 == 255 && r2 == 0 && g2 == 0 && b2 == 0)) {
                flags |= 4;
            }
            break;
    }

    switch (flags) {
        case 0:
            gGameStatusPtr->backgroundFlags &= ~BACKGROUND_FLAG_FOG;
            break;
        case 1:
            gGameStatusPtr->backgroundFlags |= BACKGROUND_FLAG_FOG;
            break;
        case 2:
            gGameStatusPtr->backgroundFlags |= BACKGROUND_FLAG_FOG;
            fogR = r1;
            fogG = g1;
            fogB = b1;
            fogA = a1;
            break;
        case 3:
            gGameStatusPtr->backgroundFlags |= BACKGROUND_FLAG_FOG;
            fogR = (fogR * (255 - a1) + r1 * a1) / 255;
            fogG = (fogG * (255 - a1) + g1 * a1) / 255;
            fogB = (fogB * (255 - a1) + b1 * a1) / 255;
            fogA = (fogA * (255 - a1) + a1 * a1) / 255;
            break;
        case 4:
            gGameStatusPtr->backgroundFlags |= BACKGROUND_FLAG_FOG;
            break;
    }

    if (gGameStatusPtr->backgroundFlags & BACKGROUND_FLAG_FOG) {
        switch (*gBackgroundFogModePtr) {
            case FOG_MODE_0:
            case FOG_MODE_1:
                if (fogA == 255) {
                    for (i = 0; i < ARRAY_COUNT(gBackgroundPalette); i++) {
                        gBackgroundPalette[i] = 1;
                    }
                } else {
                    for (i = 0; i < ARRAY_COUNT(gBackgroundPalette); i++) {
                        u16 palColor = gGameStatusPtr->backgroundPalette[i];
                        blendedB = blend_background_channel((palColor >> 1) & 0x1F, fogB >> 3, fogA);
                        blendedG = blend_background_channel((palColor >> 6) & 0x1F, fogG >> 3, fogA);
                        blendedR = blend_background_channel((palColor >> 11) & 0x1F, fogR >> 3, fogA);
                        gBackgroundPalette[i] = blendedB << 1 | blendedG << 6 | blendedR << 11 | 1;
                    }
                }
                break;
            case FOG_MODE_2:
            case FOG_MODE_3:
            default:
                for (i = 0; i < ARRAY_COUNT(gBackgroundPalette); i++) {
                    u16 palColor = gGameStatusPtr->backgroundPalette[i];
                    blendedB = (b2 >> 3) +  ((((palColor >> 1) & 0x1F) * b1) >> 8);
                    blendedG = (g2 >> 3) +  ((((palColor >> 6) & 0x1F) * g1) >> 8);
                    blendedR = (r2 >> 3) +  ((((palColor >> 11) & 0x1F) * r1) >> 8);

                    if (blendedB > 0x1F) {
                        blendedB = 0x1F;
                    }
                    if (blendedG > 0x1F) {
                        blendedG = 0x1F;
                    }
                    if (blendedR > 0x1F) {
                        blendedR = 0x1F;
                    }
                    gBackgroundPalette[i] = blendedB << 1 | blendedG << 6 | blendedR << 11 | 1;
                }
                break;
        }
    }

    theta = clamp_angle(-cam->trueRot.x);
    sinTheta = sin_deg(theta);
    cosTheta = cos_deg(theta);
    f5 = cosTheta * cam->lookAt_obj.x - sinTheta * cam->lookAt_obj.z + cam->leadAmount;
    scrollValue = -f5 * 0.25f;
    scrollValue += gGameStatusPtr->backgroundMaxX * theta * (1 / 90.0f);

    if (fabsf(scrollValue - gBackroundLastScrollValue) < 0.3f) {
        scrollValue = gBackroundLastScrollValue;
    } else {
        gBackroundLastScrollValue = scrollValue;
    }

    while (scrollValue < 0.0f) {
        scrollValue += gGameStatusPtr->backgroundMaxX * 32;
    }

    bgXOffset =gGameStatusPtr->backgroundXOffset = ((s32)scrollValue) % gGameStatusPtr->backgroundMaxX;
    bgMaxX = gGameStatusPtr->backgroundMaxX;
    bgMaxY = gGameStatusPtr->backgroundMaxY;
    bgMinX = gGameStatusPtr->backgroundMinX;
    bgMinY = gGameStatusPtr->backgroundMinY;

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_COPY);
    gDPSetTexturePersp(gMainGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetRenderMode(gMainGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTextureFilter(gMainGfxPos++, G_TF_POINT);
    gDPPipeSync(gMainGfxPos++);

    if (!(gGameStatusPtr->backgroundFlags & BACKGROUND_FLAG_FOG)) {
        gDPLoadTLUT_pal256(gMainGfxPos++, gGameStatusPtr->backgroundPalette);
    } else {
        gDPLoadTLUT_pal256(gMainGfxPos++, gBackgroundPalette);
    }

    if (!gBackroundWaveEnabled) {
        lineHeight = 2048 / gGameStatusPtr->backgroundMaxX;
        numLines = gGameStatusPtr->backgroundMaxY / lineHeight;
        extraHeight = gGameStatusPtr->backgroundMaxY % lineHeight;
        for (i = 0; i < numLines; i++) {
            texOffsetY = gBackroundTextureYOffset + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMainGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, 6,
                               0, 0, 295, 5, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gMainGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4,
                                                 (bgXOffset + bgMinX - 1) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4,
                                                 G_TX_RENDERTILE, (bgMaxX - bgXOffset) * 32, 0, 4096, 1024);
            gSPTextureRectangle(gMainGfxPos++, (bgXOffset + bgMinX) * 4, (lineHeight * i + bgMinY) * 4,
                                                 (bgMaxX + bgMinX - 1) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4,
                                                 G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
        if (extraHeight != 0) {
            texOffsetY = gBackroundTextureYOffset + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMainGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, extraHeight,
                               0, 0, 295, extraHeight - 1, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMainGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4,
                                                 (bgXOffset + bgMinX - 1) * 4, (bgMaxY - 1 + bgMinY) * 4,
                                                 G_TX_RENDERTILE, (bgMaxX - bgXOffset) * 32, 0, 4096, 1024);
            gSPTextureRectangle(gMainGfxPos++, (bgXOffset + bgMinX) * 4, (lineHeight * i + bgMinY) * 4,
                                                 (bgMaxX + bgMinX - 1) * 4, (bgMaxY - 1 + bgMinY) * 4,
                                                 G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
    } else {
        lineHeight = 6;
        numLines = gGameStatusPtr->backgroundMaxY / lineHeight;
        extraHeight = gGameStatusPtr->backgroundMaxY % lineHeight;
        gBackroundWavePhase += TAU / 60; // 60 frames period
        for (i = 0; i < numLines; i++) {
            waveOffset = sin_rad(gBackroundWavePhase + i * (TAU / 15)) * 3.0f;
            bgXOffset = 2.0f * (gGameStatusPtr->backgroundXOffset + waveOffset);
            texOffsetY = gBackroundTextureYOffset + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMainGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, 6,
                               0, 0, 295, 5, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gMainGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4,
                                                 (2 * bgXOffset + (bgMinX - 1)) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4,
                                                 G_TX_RENDERTILE, bgMaxX * 32 - bgXOffset * 16, 0, 4096, 1024);
            gSPTextureRectangle(gMainGfxPos++, bgXOffset * 2 + bgMinX * 4, (lineHeight * i + bgMinY) * 4,
                                                 (bgMaxX + bgMinX - 1) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4,
                                                 G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
        if (extraHeight != 0) {
            waveOffset = sin_rad(gBackroundWavePhase + i * (TAU / 15)) * 3.0f;
            bgXOffset = 2.0f * (gGameStatusPtr->backgroundXOffset + waveOffset);
            texOffsetY = gBackroundTextureYOffset + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMainGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, extraHeight,
                               0, 0, 295, extraHeight - 1, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMainGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4,
                                                 (2 * bgXOffset + (bgMinX - 1)) * 4, (bgMaxY - 1 + bgMinY) * 4, // @bug xh = 2 * bgXOffset + (bgMinX - 1) * 4
                                                 G_TX_RENDERTILE, bgMaxX * 32 - bgXOffset * 16, 0, 4096, 1024);
            gSPTextureRectangle(gMainGfxPos++, bgXOffset * 2  + bgMinX * 4, (lineHeight * i + bgMinY) * 4,
                                                 (bgMaxX + bgMinX - 1) * 4, (bgMaxY - 1 + bgMinY) * 4, // @bug xh = 2 * bgXOffset + (bgMinX - 1) * 4
                                                 G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
    }
}

// TODO figure out why it is needed
static const f32 rodata_padding[] = { 0.0f, 0.0f };

void enable_background_wave(void) {
    gBackroundWaveEnabled = TRUE;
}

void disable_background_wave(void) {
    gBackroundWaveEnabled = FALSE;
}
