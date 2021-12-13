#include "common.h"

char gCloudyFlowerFieldsBg[] = "fla_bg";
char gSunnyFlowerFieldsBg[] = "flb_bg";
s8 D_8014F12F = 0;
s32 D_8014F130 = 0;
f32 D_8014F134[] = { 0.0f, 0.0f, 0.0f };

void load_map_bg(char* optAssetName) {
    if (optAssetName != NULL) {
        UNK_PTR compressedData;
        u32 assetSize;
        char* assetName = optAssetName;

        if (evt_get_variable(NULL, EVT_STORY_PROGRESS) >= STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE) {
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
    D_8014F12F = 0;
    gGameStatusPtr->unk_15C = 180;
    gGameStatusPtr->enableBackground &= 0xF0;
}

void read_background_size(BackgroundHeader* bg) {
    gGameStatusPtr->backgroundMaxW = bg->width;
    gGameStatusPtr->backgroundMaxH = bg->height;
    gGameStatusPtr->backgroundMinW = bg->startX;
    gGameStatusPtr->backgroundMinH = bg->startY;
    gGameStatusPtr->backgroundRaster = bg->raster;
    gGameStatusPtr->backgroundPalette = bg->palette;
    gGameStatusPtr->enableBackground |= 1;
}

void set_background_size(s16 startX, s16 startY, s16 sizeX, s16 sizeY) {
    gGameStatusPtr->enableBackground &= ~1;
    gGameStatusPtr->backgroundMaxW = startX;
    gGameStatusPtr->backgroundMaxH = startY;
    gGameStatusPtr->backgroundMinW = sizeX;
    gGameStatusPtr->backgroundMinH = sizeY;
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

INCLUDE_ASM(s32, "dc470_len_14c0", appendGfx_background_texture);

void enable_background_wave(void) {
    D_8014F12F = 1;
}

void disable_background_wave(void) {
    D_8014F12F = 0;
}
