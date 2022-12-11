#include "jan_04.h"

#define PARTY_IMAGE "party_opuku"
// #include "world/common/todo/LoadPartyImage.inc.c"
API_CALLABLE(N(LoadPartyImage)) {
    static PAL_BIN palette[256];
    static IMG_BIN raster[0x3DA0]; // similar to LoadPartyImage include but with 0x10 bytes added for padding
    static MessageImageData image;

    u32 decompressedSize;
    void* compressed = load_asset_by_name(PARTY_IMAGE, &decompressedSize);

    decode_yay0(compressed, &palette);
    general_heap_free(compressed);

    image.raster = raster;
    image.palette = palette;
    image.width = 150;
    image.height = 105;
    image.format = G_IM_FMT_CI;
    image.bitDepth = G_IM_SIZ_8b;
    set_message_images(&image);
    return ApiStatus_DONE2;
}

const char* N(exit_str_2) = "flo_00\0\0\0\0\0\0\0";
