#include "common.h"
#include "map.h"

#ifndef PARTY_IMAGE
#error "Define PARTY_IMAGE to the asset name to use LoadPartyImage."
#endif

ApiStatus N(LoadPartyImage)(Evt* script, s32 isInitialCall) {
    static u16 palette[256];
    static u8 raster[0x3D90];
    static struct {
        /* 0x00 */ void* raster;
        /* 0x04 */ void* palette;
        /* 0x08 */ s16 width;
        /* 0x0A */ s16 height;
        /* 0x0C */ s32 unk_0C;
        /* 0x10 */ s32 unk_10;
    } images[1];

    u32 decompressedSize;
    void* compressed = load_asset_by_name(PARTY_IMAGE, &decompressedSize);

    decode_yay0(compressed, &palette);
    general_heap_free(compressed);

    images[0].raster = &raster;
    images[0].width = 150;
    images[0].height = 105;
    images[0].unk_0C = 2;
    images[0].palette = &palette;
    images[0].unk_10 = 1;
    set_message_images(images);
    return ApiStatus_DONE2;
}

#undef PARTY_IMAGE
