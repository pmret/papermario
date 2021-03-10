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

        // StoryProgress check
        if (get_variable(0, SI_SAVE_VAR(0)) >= 0x35) {
            // Use sunny Flower Fields bg rather than cloudy
            if (!strcmp(assetName, gCloudyFlowerFieldsBg)) {
                assetName = gSunnyFlowerFieldsBg;
            }
        }

        compressedData = load_asset_by_name(assetName, &assetSize);
        decode_yay0(compressedData, &gBackgroundImage);
        general_heap_free(compressedData);
    }
}

void use_default_background_settings(void) {
    GameStatus* gameStatus = *gGameStatusPtr;
    D_801595A0 = 0;
    D_8014F12F = 0;

    gameStatus->unk_15C = 0xB4;
    gameStatus->enableBackground &= 0xF0;
}

void read_background_size(BackgroundHeader* bg) {
    GameStatus* gameStatus = *gGameStatusPtr;

    gameStatus->backgroundMaxW = bg->width;
    gameStatus->backgroundMaxH = bg->height;
    gameStatus->backgroundMinW = bg->startX;
    gameStatus->backgroundMinH = bg->startY;
    gameStatus->backgroundRaster = bg->raster;
    gameStatus->backgroundPalette = bg->palette;
    gameStatus->enableBackground |= 1;
}

void set_background_size(s16 startX, s16 startY, s16 sizeX, s16 sizeY) {
    GameStatus* gameStatus = *gGameStatusPtr;

    gameStatus->enableBackground &= ~1;
    gameStatus->backgroundMaxW = startX;
    gameStatus->backgroundMaxH = startY;
    gameStatus->backgroundMinW = sizeX;
    gameStatus->backgroundMinH = sizeY;
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

INCLUDE_ASM(s32, "code_dc470_len_14c0", enable_background_wave);

void func_8014720C(void) {
    D_8014F12F = 1;
}

void disable_background_wave(void) {
    D_8014F12F = 0;
}
