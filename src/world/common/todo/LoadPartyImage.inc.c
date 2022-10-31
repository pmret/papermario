#include "common.h"
#include "npc.h"

#ifndef PARTY_IMAGE
#error "Define PARTY_IMAGE to the asset name to use LoadPartyImage."
#endif

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

#undef PARTY_IMAGE
