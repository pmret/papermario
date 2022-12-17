#include "jan_04.h"

#define PARTY_IMAGE "party_opuku"
// #include "world/common/todo/LoadPartyImage.inc.c"

BSS PAL_BIN N(palette)[256];
BSS IMG_BIN N(raster)[0x3D90]; // similar to LoadPartyImage include but with D_8024A290 in the middle randomly
BSS Evt* D_8024A290;
BSS char D_8024A294[0xC]; // padding?
BSS MessageImageData N(image);

API_CALLABLE(N(LoadPartyImage)) {
    u32 decompressedSize;
    void* compressed = load_asset_by_name(PARTY_IMAGE, &decompressedSize);

    decode_yay0(compressed, &N(palette));
    general_heap_free(compressed);

    N(image).raster = N(raster);
    N(image).palette = N(palette);
    N(image).width = 150;
    N(image).height = 105;
    N(image).format = G_IM_FMT_CI;
    N(image).bitDepth = G_IM_SIZ_8b;
    set_message_images(&N(image));
    return ApiStatus_DONE2;
}

const char* N(exit_str_2) = "flo_00\0\0\0\0\0\0\0";
