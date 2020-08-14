#include "common.h"

void load_map_bg(char* optAssetName) {
    UNK_PTR compressedData;
    u32 assetSize;
    char* assetName;

    if (optAssetName == NULL) return;
    assetName = optAssetName;

    // StoryProgress check
    if (get_variable(0, 0xF5DE0180) >= 0x35) {
        // Use sunny Flower Fields bg rather than cloudy
        // TODO: these globals should be string literals
        if (!strcmp(assetName, gCloudyFlowerFieldsBg)) {
            assetName = gSunnyFlowerFieldsBg;
        }
    }

    compressedData = load_asset_by_name(assetName, &assetSize);
    decode_yay0(compressedData, &gBackgroundImage);
    general_heap_free(compressedData);
}

void func_80145DF8(void) {
    game_status* gameStatus = *gGameStatusPtr;
    D_801595A0 = 0;
    D_8014F12F = 0;
    
    gameStatus->unk_15C = 0xB4;
    gameStatus->enableBackground &= 0xF0;
}

void read_background_size(bg_header *bg) {
    game_status* gameStatus = *gGameStatusPtr;

    gameStatus->backgroundMaxW = bg->width;
    gameStatus->backgroundMaxH = bg->height;
    gameStatus->backgroundMinW = bg->startX;
    gameStatus->backgroundMinH = bg->startY;
    gameStatus->backgroundRaster = bg->raster;
    gameStatus->backgroundPalette = bg->palette;
    gameStatus->enableBackground |= 1;
}

void set_background_size(s16 startX, s16 startY, s16 sizeX, s16 sizeY) {
    game_status* gameStatus = *gGameStatusPtr;

    gameStatus->enableBackground &= ~1;
    gameStatus->backgroundMaxW = startX;
    gameStatus->backgroundMaxH = startY;
    gameStatus->backgroundMinW = sizeX;
    gameStatus->backgroundMinH = sizeY;
}

u16 func_80145E98(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_lo;

    temp_lo = (arg1 - (u16)(arg0)) * arg2;
    if (temp_lo < 0) {
        temp_lo = temp_lo + 0xFF;
    }
    temp_lo = arg0 + (temp_lo >> 8);
    return temp_lo;
}

INCLUDE_ASM(code_dc470_len_14c0, func_80145EC0);
