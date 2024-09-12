#include "common.h"
#include "npc.h"

#ifndef PARTY_IMAGE
#error "Define PARTY_IMAGE to the asset name to use LoadPartyImage."
#endif

#ifdef SHIFT
//this is required on modern compilers to guarantee the raster comes directly after the palette
typedef struct Img {
    u16 palette[256];
    u8 raster[0x3D90]; // 10 bytes added for padding: 150 * 105 = 0x3D86
} PartyImage;

static PartyImage img;

API_CALLABLE(N(LoadPartyImage)) {
    static MessageImageData image;

    u32 decompressedSize;
    void* compressed = load_asset_by_name(PARTY_IMAGE, &decompressedSize);

    decode_yay0(compressed, &img);
    general_heap_free(compressed);

    image.raster = img.raster;
    image.palette = img.palette;
    image.width = 150;
    image.height = 105;
    image.format = G_IM_FMT_CI;
    image.bitDepth = G_IM_SIZ_8b;
    set_message_images(&image);
    return ApiStatus_DONE2;
}
#else

API_CALLABLE(N(LoadPartyImage)) {
    static PAL_BIN palette[256];
    static IMG_BIN raster[0x3D90]; // 10 bytes added for padding: 150 * 105 = 3D86
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

#endif

#undef PARTY_IMAGE
