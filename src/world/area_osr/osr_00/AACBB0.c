#include "osr_00.h"
#include "ld_addrs.h"
#include "charset/peach_letter.png.h"

#include "world/common/atomic/UnkFunc27.inc.c"

ApiStatus func_80240678_AACEA8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 primR = *args++;
    s32 primG = *args++;
    s32 primB = *args++;
    s32 envR = *args++;
    s32 envG = *args++;
    s32 envB = *args++;
    set_model_env_color_parameters(primR, primG, primB, envR, envG, envB);
    return ApiStatus_DONE2;
}

BSS u8 osr_00_802437C0[charset_peach_letter_png_width * charset_peach_letter_png_height];
BSS u16 D_80247548[0x100];
BSS char D_80247748[0x8]; // padding?
BSS MessageImageData D_80247750;

// TODO look into + 1 here...
ApiStatus func_802406E0_AACF10(Evt* script, s32 isInitialCall) {
    s8* romStart = charset_ROM_START;
    u8* rasterOffset = charset_peach_letter_png;
    u16* paletteOffset = (u16*) charset_peach_letter_pal + 1; // todo ???

    dma_copy(romStart + (s32)rasterOffset, romStart + (s32)rasterOffset + sizeof(osr_00_802437C0), &osr_00_802437C0);
    dma_copy(romStart + (s32)paletteOffset, romStart + (s32)paletteOffset + sizeof(D_80247548), &D_80247548);
    D_80247750.width = charset_peach_letter_png_width;
    D_80247750.height = charset_peach_letter_png_height;
    D_80247750.format = G_IM_FMT_CI;
    D_80247750.raster = osr_00_802437C0;
    D_80247750.palette = D_80247548;
    D_80247750.bitDepth = 1;
    set_message_images(&D_80247750);
    return ApiStatus_DONE2;
}
