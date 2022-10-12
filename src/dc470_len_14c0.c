#include "common.h"

char gCloudyFlowerFieldsBg[] = "fla_bg";
char gSunnyFlowerFieldsBg[] = "flb_bg";
s8 D_8014F12F = FALSE;
s16 D_8014F130 = 0;
f32 D_8014F134 = 0.0f;

// BSS
extern PAL_BIN D_801593A0[256];
extern f32 D_801595A0;

void get_model_env_color_parameters(u8* primR, u8* primG, u8* primB, u8* envR, u8* envG, u8* envB);

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
    D_801595A0 = 0;
    D_8014F12F = FALSE;
    gGameStatusPtr->backgroundDarkness = 180;
    gGameStatusPtr->backgroundFlags &= 0xF0;
}

void read_background_size(BackgroundHeader* bg) {
    gGameStatusPtr->backgroundMaxX = bg->width;
    gGameStatusPtr->backgroundMaxY = bg->height;
    gGameStatusPtr->backgroundMinX = bg->startX;
    gGameStatusPtr->backgroundMinY = bg->startY;
    gGameStatusPtr->backgroundRaster = bg->raster;
    gGameStatusPtr->backgroundPalette = bg->palette;
    gGameStatusPtr->backgroundFlags |= 1;
}

void set_background_size(s16 startX, s16 startY, s16 sizeX, s16 sizeY) {
    gGameStatusPtr->backgroundFlags &= ~1;
    gGameStatusPtr->backgroundMaxX = startX;
    gGameStatusPtr->backgroundMaxY = startY;
    gGameStatusPtr->backgroundMinX = sizeX;
    gGameStatusPtr->backgroundMinY = sizeY;
}

u16 blend_background_channel(s32 arg0, s32 arg1, s32 alpha) {
    s32 temp_lo;

    temp_lo = (arg1 - (u16)arg0) * alpha;
    if (temp_lo < 0) {
        temp_lo = temp_lo + 0xFF;
    }
    temp_lo = arg0 + (temp_lo >> 8);
    return temp_lo;
}

void appendGfx_background_texture(void) {
    Camera* cam = &gCameras[gCurrentCameraID];
    u16 flags = 0;
    s32 fogR, fogG, fogB, fogA; // 18 1c 20 24
    u8 r1, g1, b1, a1; // 28 29 2a 2b
    u8 r2, g2, b2; // 2c 2d 2e
    u16 blendedR, blendedG, blendedB;
    s32 i;

    f32 theta, sinTheta, cosTheta, f4, f5, f6, f7, f8;

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

    switch (*D_801512F0) {
        case 0:
        case 1:
            get_background_color_blend(&r1, &g1, &b1, &a1);
            if (a1 != 0) {
                flags |= 2;
            }
            break;
        case 2:
        case 3:
        default:
            get_model_env_color_parameters(&r1, &g1, &b1, &r2, &g2, &b2);
            if (!(r1 == 255 && g1 == 255 && b1 == 255 && r2 == 0 && g2 == 0 && b2 == 0)) {
                flags |= 4;
            }
            break;
    }

/*
    switch (*D_801512F0) {
        case 0:
        case 1:
            get_background_color_blend(&r1, &g1, &b1, &a1);
            if (a1 != 0) {
                flags |= 2;
            }
            break;
        default:
            get_model_env_color_parameters(&r1, &g1, &b1, &r2, &g2, &b2);
            if (!(r1 == 255 && g1 == 255 && b1 == 255 && r2 == 0 && g2 == 0 && b2 == 0)) {
                flags |= 4;
            }
    }
*/
    switch (flags) {
        case 0:
            gGameStatusPtr->backgroundFlags &= ~0x2;
            break;
        case 1:
            gGameStatusPtr->backgroundFlags |= 0x2;
            break;
        case 2:
            gGameStatusPtr->backgroundFlags |= 0x2;
            fogR = r1;
            fogG = g1;
            fogB = b1;
            fogA = a1;
            break;
        case 3:
            gGameStatusPtr->backgroundFlags |= 0x2;
            fogR = (fogR * (255 - a1) + r1 * a1) / 255;
            fogG = (fogG * (255 - a1) + g1 * a1) / 255;
            fogB = (fogB * (255 - a1) + b1 * a1) / 255;
            fogA = (fogA * (255 - a1) + a1 * a1) / 255;
            break;
        case 4:
            gGameStatusPtr->backgroundFlags |= 0x2;
            break;
    }

    if (gGameStatusPtr->backgroundFlags & 2) {
        switch (*D_801512F0) {
            case 0:
            case 1:
                if (fogA == 255) {
                    for (i = 0; i < 256; i++) {
                        D_801593A0[i] = 1;
                    }
                } else {
                    for (i = 0; i < 256; i++) {
                        u16 palColor = gGameStatusPtr->backgroundPalette[i];
                        blendedB = blend_background_channel((palColor >> 1) & 0x1F, fogB >> 3, fogA);
                        blendedG = blend_background_channel((palColor >> 6) & 0x1F, fogG >> 3, fogA);
                        blendedR = blend_background_channel((palColor >> 11) & 0x1F, fogR >> 3, fogA);
                        D_801593A0[i] = blendedB << 1 | blendedG << 6 | blendedR << 11 | 1;
                    }
                }
                break;
            case 2:
            case 3:
            default:
                for (i = 0; i < 256; i++) {
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
                    D_801593A0[i] = blendedB << 1 | blendedG << 6 | blendedR << 11 | 1;
                }
                break;
        }
    }

    theta = clamp_angle(-cam->trueRotation.x);
    sinTheta = sin_deg(theta);
    cosTheta = cos_deg(theta);
    f5 = cosTheta * cam->lookAt_obj.x - sinTheta * cam->lookAt_obj.z + cam->leadAmount;
    f4 = -f5 * 0.25f;
    f4 += gGameStatusPtr->backgroundMaxX * theta * (1 / 90.0f);

    if (fabsf(f4 - D_801595A0) < 0.3f) {
        f4 = D_801595A0;
    } else {
        D_801595A0 = f4;
    }

    while (f4 < 0.0f) {
        f4 += gGameStatusPtr->backgroundMaxX * 32;
    }

    bgXOffset =gGameStatusPtr->backgroundXOffset = ((s32)f4) % gGameStatusPtr->backgroundMaxX;
    bgMaxX = gGameStatusPtr->backgroundMaxX;
    bgMaxY = gGameStatusPtr->backgroundMaxY;
    bgMinX = gGameStatusPtr->backgroundMinX;
    bgMinY = gGameStatusPtr->backgroundMinY;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_COPY);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_RGBA16);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);
    gDPPipeSync(gMasterGfxPos++);

    if (!(gGameStatusPtr->backgroundFlags & 2)) {
        gDPLoadTLUT_pal256(gMasterGfxPos++, gGameStatusPtr->backgroundPalette);
    } else {
        gDPLoadTLUT_pal256(gMasterGfxPos++, D_801593A0);
    }

    if (!D_8014F12F) {
        lineHeight = 2048 / gGameStatusPtr->backgroundMaxX;
        numLines = gGameStatusPtr->backgroundMaxY / lineHeight;
        extraHeight = gGameStatusPtr->backgroundMaxY % lineHeight;
        for (i = 0; i < numLines; i++) {
            texOffsetY = D_8014F130 + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMasterGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, 6,
                               0, 0, 295, 5, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gMasterGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4, (bgXOffset + bgMinX - 1) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4, G_TX_RENDERTILE, (bgMaxX - bgXOffset) * 32, 0, 4096, 1024);
            gSPTextureRectangle(gMasterGfxPos++, (bgXOffset + bgMinX) * 4, (lineHeight * i + bgMinY) * 4, (bgMaxX + bgMinX - 1) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4, G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
        if (extraHeight != 0) {
            texOffsetY = D_8014F130 + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMasterGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, extraHeight,
                               0, 0, 295, extraHeight - 1, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMasterGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4, (bgXOffset + bgMinX - 1) * 4, (bgMaxY - 1 + bgMinY) * 4, G_TX_RENDERTILE, (bgMaxX - bgXOffset) * 32, 0, 4096, 1024);
            gSPTextureRectangle(gMasterGfxPos++, (bgXOffset + bgMinX) * 4, (lineHeight * i + bgMinY) * 4, (bgMaxX + bgMinX - 1) * 4, (bgMaxY - 1 + bgMinY) * 4, G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
    } else {
        lineHeight = 6;
        numLines = gGameStatusPtr->backgroundMaxY / lineHeight;
        extraHeight = gGameStatusPtr->backgroundMaxY % lineHeight;
        D_8014F134 += 0.10471967f; // 6°
        for (i = 0; i < numLines; i++) {
            f8 = sin_rad(D_8014F134 + i * 0.41887867f) * 3.0f;
            bgXOffset = 2.0f * (gGameStatusPtr->backgroundXOffset + f8);
            texOffsetY = D_8014F130 + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMasterGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, 6,
                               0, 0, 295, 5, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gMasterGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4, (2 * bgXOffset + (bgMinX - 1)) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4, G_TX_RENDERTILE, bgMaxX * 32 - bgXOffset * 16, 0, 4096, 1024);
            gSPTextureRectangle(gMasterGfxPos++, bgXOffset * 2 + bgMinX * 4, (lineHeight * i + bgMinY) * 4, (bgMaxX + bgMinX - 1) * 4, (lineHeight * i + lineHeight - 1 + bgMinY) * 4, G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
        if (extraHeight != 0) {
            f8 = sin_rad(D_8014F134 + i * 0.41887867f) * 3.0f;
            bgXOffset = 2.0f * (gGameStatusPtr->backgroundXOffset + f8);
            texOffsetY = D_8014F130 + lineHeight * i;
            if (texOffsetY > gGameStatusPtr->backgroundMaxY) {
                texOffsetY -= gGameStatusPtr->backgroundMaxY;
            }
            gDPLoadTextureTile(gMasterGfxPos++, gGameStatusPtr->backgroundRaster + bgMaxX * texOffsetY,
                               G_IM_FMT_CI, G_IM_SIZ_8b, bgMaxX, extraHeight,
                               0, 0, 295, extraHeight - 1, 0,
                               G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gMasterGfxPos++, bgMinX * 4, (lineHeight * i + bgMinY) * 4, (2 * bgXOffset + (bgMinX - 1)) * 4, (bgMaxY - 1 + bgMinY) * 4, G_TX_RENDERTILE, bgMaxX * 32 - bgXOffset * 16, 0, 4096, 1024);
            gSPTextureRectangle(gMasterGfxPos++, bgXOffset * 2  + bgMinX * 4, (lineHeight * i + bgMinY) * 4, (bgMaxX + bgMinX - 1) * 4, (bgMaxY - 1 + bgMinY) * 4, G_TX_RENDERTILE, 0, 0, 4096, 1024);
        }
    }
}

static const f32 rodata_padding[] = { 0.0f, 0.0f };

void enable_background_wave(void) {
    D_8014F12F = TRUE;
}

void disable_background_wave(void) {
    D_8014F12F = FALSE;
}
