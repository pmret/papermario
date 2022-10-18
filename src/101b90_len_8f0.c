#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

// TODO generate this somehow, or prevent it from shifting. must be resolved at compile time
#ifdef SHIFT
#define SPRITE_ROM_START _1943000_ROM_START + 0x10
#else
#define SPRITE_ROM_START 0x1943000 + 0x10
#endif

extern s32 spr_allocateBtlComponentsOnWorldHeap;

BSS s32 D_802DFEB0[2];
BSS s32 D_802DFEB8[101];
BSS s32 PlayerRasterSetsLoaded;
BSS s32 PlayerRasterBufferSetOffsets[13];
BSS s32 D_802D0084[3]; // unused?
BSS s32 D_802E0090[0x2E0]; // correct length?

BSS s32 PlayerRasterHeader;
BSS s32 D_802E0C14[3];
BSS s32 D_802E0C20[14];
BSS s32 PlayerRasterCacheSize;
BSS s32 PlayerRasterMaxSize;
BSS s32 SpriteDataHeader[1]; // ?
BSS s32 D_802E0C64;
BSS s32 D_802E0C68;
BSS s32 D_802E0C6C; // unused?
BSS PlayerSpriteCacheEntry PlayerRasterCache[18];

#define ALIGN4(v) (((u32)(v) >> 2) << 2)
#define SPR_SWIZZLE(base,offset) ((void*)((s32)(offset) + (s32)(base)))

void spr_swizzle_anim_offsets(s32 arg0, s32 base, void* spriteData) {
    u8* buffer;
    SpriteAnimComponent*** animList;
    SpriteAnimComponent** compList;
    SpriteAnimComponent* comp;
    s32 animOffset;
    s32 compOffset;
    s32 temp;

    // required to match, spriteData->animList would be nicer
    animList = (SpriteAnimComponent***) spriteData;
    animList += 4;

    while (TRUE) {
        if (*animList == PTR_LIST_END) {
            break;
        }
        compList = (SpriteAnimComponent**) ((s32)*animList - ALIGN4(base));
        compList = SPR_SWIZZLE(ALIGN4(spriteData), compList);
        *animList = compList;
        while (TRUE) {
            if (*compList == PTR_LIST_END) {
                break;
            }
            *compList = comp = SPR_SWIZZLE(ALIGN4(spriteData), (s32)*compList - ALIGN4(base));
            comp->cmdList = SPR_SWIZZLE(ALIGN4(spriteData), (s32)comp->cmdList - ALIGN4(base));
            compList++;
        }
        animList++;
    }
}

#ifdef NON_EQUIVALENT
SpriteAnimData* spr_load_sprite(s32 idx, s32 arg1, s32 arg2) {
    SpriteAnimData* animData;
    s32 base;
    s32 i;

    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32* temp_a1_3;
    s32** var_s2;
    u16** var_v1;
    s32* temp_v0;

    if (arg1) {
        base = D_802E0C64;
    } else {
        base = D_802E0C68;
    }
    nuPiReadRom(base + (idx * 4), &D_802DFEB0, 8U);

    temp_s0 = ALIGN8(D_802DFEB0[1] - D_802DFEB0[0]);
    temp_v0 = general_heap_malloc(temp_s0);
    nuPiReadRom(base + D_802DFEB0[0], temp_v0, temp_s0);

    if (arg2) {
        temp_v0++;
        animData = _heap_malloc_tail(&gSpriteHeapPtr, *temp_v0);
    } else {
        temp_v0++;
        animData = _heap_malloc(&gSpriteHeapPtr, *temp_v0);
    }

    decode_yay0(temp_v0, animData);
    general_heap_free(temp_v0);

    temp_v0_2 = ((u32) animData / 4) * 4;
    var_s2 = animData->rastersOffset + temp_v0_2;
    animData->rastersOffset = var_s2;

    while (*var_s2 != PTR_LIST_END) {
        temp_a1_3 = *var_s2 + temp_v0_2;
        *var_s2 = temp_a1_3;
        var_s2++;
        if (!arg1) {
            *temp_a1_3 += temp_v0_2;
        }
    }

    if (arg1) {
        D_802E0050[idx] = D_802E004C;
        temp_s0_2 = D_802E0C20[idx + 1] - D_802E0C20[idx];
        nuPiReadRom(D_802E0C60[0] + D_802E0C14[0] + D_802E0C20[idx], &D_802DFEB8, 0x194);
        for (i = 0; i < temp_s0_2; i++) {
            D_802E0090[D_802E004C++] = D_802DFEB8[i];
        }
    }

    temp_v0_3 = ((u32) animData / 4) * 4;
    var_v1 = animData->palettesOffset + temp_v0_3;
    animData->palettesOffset = var_v1;

    while (*var_v1 != -1) {
        *var_v1 += temp_v0_3;
        var_v1++;
    }

    spr_swizzle_anim_offsets(0, 0, animData);
    return animData;
}
#else
INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_sprite);
#endif

void spr_init_player_raster_cache(s32 cacheSize, s32 maxRasterSize) {
    void* raster;
    s32 i;

    nuPiReadRom(SPRITE_ROM_START, &SpriteDataHeader, 0xC);
    PlayerRasterCacheSize = cacheSize;
    PlayerRasterMaxSize = maxRasterSize;
    SpriteDataHeader[0] += SPRITE_ROM_START;
    SpriteDataHeader[1] += SPRITE_ROM_START;
    SpriteDataHeader[2] += SPRITE_ROM_START;
    raster = _heap_malloc(&gSpriteHeapPtr, maxRasterSize * cacheSize);

    for (i = 0; i < ARRAY_COUNT(PlayerRasterCache); i++) {
        PlayerRasterCache[i].raster = raster;
        raster += PlayerRasterMaxSize;
        PlayerRasterCache[i].lazyDeleteTime = 0;
        PlayerRasterCache[i].rasterIndex = 0;
        PlayerRasterCache[i].spriteIndex = 0xFF;
    }

    for (i = 0; i < ARRAY_COUNT(PlayerRasterBufferSetOffsets); i++)    {
        PlayerRasterBufferSetOffsets[i] = 0;
    }
    PlayerRasterSetsLoaded = 0;
    nuPiReadRom(SpriteDataHeader[0], &PlayerRasterHeader, 0xC);
    nuPiReadRom(SpriteDataHeader[0] + PlayerRasterHeader, D_802E0C20, 0x38);
}

IMG_PTR spr_get_player_raster(s32 rasterIndex, s32 playerSpriteID) {
    PlayerSpriteCacheEntry* temp_s0;
    u32 temp_a2;
    s32 idx = -1;
    s32 i;

    for (i = 0; i < PlayerRasterCacheSize; i++) {
        if (PlayerRasterCache[i].lazyDeleteTime != 0) {
            if (PlayerRasterCache[i].rasterIndex == rasterIndex && PlayerRasterCache[i].spriteIndex == playerSpriteID) {
                PlayerRasterCache[i].lazyDeleteTime = 2;
                return PlayerRasterCache[i].raster;
            }
        } else if (idx == -1) {
            idx = i;
        }
    }

    if (idx == -1) {
        return NULL;
    }

    temp_s0 = &PlayerRasterCache[idx];
    temp_s0->rasterIndex = rasterIndex;
    temp_s0->spriteIndex = playerSpriteID;
    temp_s0->lazyDeleteTime = 2;
    temp_a2 = D_802E0090[PlayerRasterBufferSetOffsets[playerSpriteID] + rasterIndex];
    nuPiReadRom(*SpriteDataHeader + (temp_a2 & 0xFFFFF), temp_s0->raster, (temp_a2 >> 0x10) & 0xFFF0);
    return temp_s0->raster;
}

void spr_update_player_raster_cache(void) {
    s32 i;

    func_8013A4D0();

    for (i = 0; i < PlayerRasterCacheSize; i++) {
        if (PlayerRasterCache[i].lazyDeleteTime != 0) {
            PlayerRasterCache[i].lazyDeleteTime--;
        }
    }
}

void spr_load_npc_extra_anims(SpriteAnimData*, u32*);
INCLUDE_ASM(s32, "101b90_len_8f0", spr_load_npc_extra_anims);

#ifdef NON_MATCHING
SpriteComponent** spr_allocate_components(s32 count) {
    s32 listSize;
    void** heap;
    SpriteComponent** listStart;
    SpriteComponent* component;
    SpriteComponent** listPos;
    u32 totalSize;
    s32 i;

    // data will contain a -1 terminated list, followed by the SpriteComponents
    // corresponding to that list
    listSize = (count + 1) * 4;
    totalSize = (count * sizeof(SpriteComponent)) + listSize;

    if (spr_allocateBtlComponentsOnWorldHeap) {
        heap = _heap_malloc(&heap_generalHead, totalSize);
    } else {
        heap = _heap_malloc(&gSpriteHeapPtr, totalSize);
    }

    listStart = (SpriteComponent**) heap;
    listPos = listStart;
    component = (SpriteComponent*)(heap + (listSize / 4));

    // fill list values
    for (i = 0; i < count; i++) {
        *listPos = component;
        listPos++;
        component++;
    }
    *listPos = PTR_LIST_END;

    return listStart;
}
#else
INCLUDE_ASM(s32, "101b90_len_8f0", spr_allocate_components);
#endif
