#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

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

SpriteAnimData* spr_load_sprite(s32 idx, s32 arg1, s32 arg2) {
    SpriteAnimData* animData;
    s32 base;
    s32 i;
    s32 compressedSize;
    s32* ptr1;
    s32* ptr2;
    s32* ptr3;
    s32 count;
    s32** data;
    s32** data2;

    if (arg1) {
        base = D_802E0C64;
    } else {
        base = D_802E0C68;
    }
    // load sprite header
    nuPiReadRom(base + (idx * 4), &D_802DFEB0, 8U);

    compressedSize = ALIGN8(D_802DFEB0[1] - D_802DFEB0[0]); // rom start, rom end
    data = general_heap_malloc(compressedSize);
    nuPiReadRom(base + D_802DFEB0[0], data, compressedSize);

    ptr1 = data;
    ptr1++;
    if (arg2) {
        animData = _heap_malloc_tail(&gSpriteHeapPtr, *ptr1);
    } else {
        animData = _heap_malloc(&gSpriteHeapPtr, *ptr1);
    }
    decode_yay0(data, animData);
    general_heap_free(data);

    data = animData->rastersOffset;
    data = SPR_SWIZZLE(ALIGN4(animData), data);
    animData->rastersOffset = data;

    while (1) {
        ptr1 = *data;
        if (ptr1 == PTR_LIST_END) {
            break;
        }
        ptr1 = SPR_SWIZZLE(ALIGN4(animData), ptr1);
        *data++ = ptr1;
        ptr2 = *ptr1;

        if (!arg1) {
            ptr2 = SPR_SWIZZLE(ALIGN4(animData), ptr2);
            *ptr1 = ptr2;
        }
    }

    if (arg1) {
        PlayerRasterBufferSetOffsets[idx] = PlayerRasterSetsLoaded;
        count = D_802E0C20[idx + 1] - D_802E0C20[idx];
        nuPiReadRom(SpriteDataHeader[0] + D_802E0C14[0] + sizeof(u32) * D_802E0C20[idx], D_802DFEB8, sizeof(D_802DFEB8));
        for (i = 0; i < count; i++) {
            D_802E0090[PlayerRasterSetsLoaded++] = D_802DFEB8[i];
        }
    }

    data2 = SPR_SWIZZLE(ALIGN4(animData), animData->palettesOffset);
    animData->palettesOffset = data2;
    while (1) {
        ptr1 = *data2;
        if (ptr1 == PTR_LIST_END) {
            break;
        }
        ptr1 = SPR_SWIZZLE(ALIGN4(animData), ptr1);
        *data2++ = ptr1;
    }

    spr_swizzle_anim_offsets(0, 0, animData);
    return animData;
}

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

void spr_load_npc_extra_anims(SpriteAnimData* header, u32* extraAnimList) {
    u8* src;
    s32 imgID;
    s32 rasterSize;
    s32 remaining;
    u16 animCmd;
    u16* cmdList;
    u32 extraAnimID;
    u8* dataPos;
    void* copyEnd;
    SpriteAnimComponent* comp;
    SpriteAnimComponent** compList;
    void* writePos;
    SpriteRasterCacheEntry** rasterList;
    SpriteRasterCacheEntry* raster;
    u16** oldPalList;
    u16* palette;
    // one extra required for 'done' sentinel
    s32 sawRaster[0x64 + 1];
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sawRaster) - 1; i++) {
        sawRaster[i] = FALSE;
    }

    while ((extraAnimID = *extraAnimList++) != -1) {
        compList = header->animListStart[extraAnimID & 0xFF]; // TODO WROGN
        while ((comp = *compList++) != PTR_LIST_END) {
            cmdList = comp->cmdList;
            remaining = (s16) comp->cmdListSize / 2;
            while (remaining > 0) {
                animCmd = *cmdList++;
                remaining--;
                switch (animCmd & 0xF000) {
                    case 0x1000:
                        i = animCmd; // required to match
                        imgID = i & 0xFF;
                        if (imgID < ARRAY_COUNT(sawRaster) - 1) {
                            sawRaster[imgID] = TRUE;
                        }
                        break;
                    case 0x3000:
                        cmdList++;
                        remaining--;
                        // fallthrough
                    case 0x4000:
                        cmdList++;
                        remaining--;
                        // fallthrough
                    case 0x7000:
                    case 0x5000:
                        cmdList++;
                        remaining--;
                        // fallthrough
                    case 0x0000:
                    case 0x2000:
                    case 0x6000:
                    case 0x8000:
                        break;
                }
            }
        }
    }

    rasterList = header->rastersOffset;
    raster = *rasterList;
    dataPos = raster->image;

    for (i = 0; i < ARRAY_COUNT(sawRaster) - 1; i++) {
        if ((raster = *rasterList) == PTR_LIST_END) {
            break;
        }
        if (sawRaster[i]) {
            src = raster->image;
            rasterSize = (raster->width * raster->height) / 2;
            copyEnd = &dataPos[rasterSize];
            rasterSize += 8;
            if (dataPos != src) {
                raster->image = dataPos;
                bcopy(src, dataPos, rasterSize);
            }
            *rasterList = copyEnd;
            dataPos += rasterSize;
        }
        rasterList++;
    }
    // sentinel value to mark end of valid data
    sawRaster[i] = TRUE;

    writePos = dataPos;

    // copy raster list
    rasterList = header->rastersOffset;
    header->rastersOffset = writePos;

    for (i = 0; i < ARRAY_COUNT(sawRaster) - 1; i++) {
        raster = *rasterList++;
        if (sawRaster[i]) {
            *(SpriteRasterCacheEntry**) writePos = raster;
        } else {
            *(SpriteRasterCacheEntry**) writePos = (SpriteRasterCacheEntry*) copyEnd;
        }
        writePos += 4;
        if (raster == PTR_LIST_END) {
            break;
        }
    }

    // copy palette list
    oldPalList = header->palettesOffset;
    header->palettesOffset = writePos;

    for (i = 0; i < ARRAY_COUNT(sawRaster) - 1; i++) {
        raster = *oldPalList++;
        *(u16**) writePos = raster;
        writePos += 4;
        if (raster == PTR_LIST_END) {
            break;
        }
    }

    _heap_realloc(&gSpriteHeapPtr, header, (s32)writePos - (s32)header);
}


#ifdef NON_MATCHING
SpriteComponent** spr_allocate_components(s32 count) {
    s32 listSize;
    void** heap;
    SpriteComponent **new_var;
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
        listStart = _heap_malloc(&heap_generalHead, totalSize);
    } else {
        listStart = _heap_malloc(&gSpriteHeapPtr, totalSize);
    }

    component = listPos = listStart;

    component = (SpriteComponent*)((s32)(component) + (listSize / 4) * 4);

    // fill list values
    for (i = 0; i < count; i++) {
        *listPos++ = component;
        component++;
    }
    *listPos = PTR_LIST_END;

    return listStart;
}
#else
INCLUDE_ASM(s32, "101b90_len_8f0", spr_allocate_components);
#endif
