#include "common.h"

void load_map_bg(u8* optAssetName) {
    UNK_PTR compressedData;
    u32 assetSize;
    u8* assetName;

    if (!optAssetName) return;
    assetName = optAssetName;

    // StoryProgress check
    if (get_variable(0, 0xF5DE0180) >= 0x35) {
        // Use sunny Flower Fields bg rather than cloudy
        // TODO: these globals should be string literals
        if (!strcmp(assetName, &gCloudyFlowerFieldsBg)) {
            assetName = &gSunnyFlowerFieldsBg;
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
    gameStatus->unk_148 &= 0xF0;
}

void read_background_size(bg_header *bg) {
    game_status* gameStatus = *gGameStatusPtr;

    gameStatus->unk_14E = bg->width;
    gameStatus->unk_150 = bg->height;
    gameStatus->unk_14A = bg->startX;
    gameStatus->unk_14C = bg->startY;
    gameStatus->unk_154 = bg->palette;
    gameStatus->unk_158 = bg->raster;
    gameStatus->unk_148 |= 1;
}

void set_background_size(s16 startX, s16 startY, s16 sizeX, s16 sizeY) {
    game_status* gameStatus = *gGameStatusPtr;

    gameStatus->unk_148 &= ~1;
    gameStatus->unk_14E = startX;
    gameStatus->unk_150 = startY;
    gameStatus->unk_14A = sizeX;
    gameStatus->unk_14C = sizeY;
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
