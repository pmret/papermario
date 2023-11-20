#include "common.h"
#include "sprite.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "sprite/player.h"

#ifdef SHIFT
#define SPRITE_ROM_START (u32) sprites_ROM_START + 0x10
#elif VERSION_US || VERSION_IQUE
#define SPRITE_ROM_START 0x1943000 + 0x10
#elif VERSION_PAL
#define SPRITE_ROM_START 0x1DF0000 + 0x10
#endif

extern s32 spr_allocateBtlComponentsOnWorldHeap;
extern HeapNode heap_generalHead;
extern HeapNode heap_spriteHead;

BSS s32 spr_asset_entry[2];
BSS s32 PlayerRasterLoadDescBuffer[101]; //NOTE: maximum rasters supported for a single player sprite is 101
BSS s32 PlayerRasterLoadDescNumLoaded;
BSS s32 PlayerRasterLoadDescBeginSpriteIndex[SPR_Peach3]; //TODO size linked to number of player sprites
BSS s32 D_802D0084[3]; // unused?
BSS s32 PlayerRasterLoadDesc[0x2E0]; // correct length?

BSS PlayerRastersHeader PlayerRasterHeader;
BSS s32 D_802E0C1C; // unused
BSS s32 PlayerSpriteRasterSets[SPR_Peach3 + 1]; //TODO size linked to number of player sprites
BSS s32 PlayerRasterCacheSize;
BSS s32 PlayerRasterMaxSize;
BSS s32 SpriteDataHeader[3];
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

SpriteAnimData* spr_load_sprite(s32 idx, s32 isPlayerSprite, s32 useTailAlloc) {
    SpriteAnimData* animData;
    s32 base;
    s32 i;
    s32 compressedSize;
    s32* ptr1;
    IMG_PTR image;
    s32 count;
    s32** data;
    s32** palettes;

    if (isPlayerSprite) {
        base = SpriteDataHeader[1];
    } else {
        base = SpriteDataHeader[2];
    }

    // read current and next sprite offsets, so we can find the difference
    nuPiReadRom(base + idx * 4, &spr_asset_entry, sizeof(spr_asset_entry));

    compressedSize = ALIGN8(spr_asset_entry[1] - spr_asset_entry[0]);
    data = general_heap_malloc(compressedSize);
    nuPiReadRom(base + spr_asset_entry[0], data, compressedSize);

    ptr1 = (s32*)data;
    // skip 4 bytes: 'YAY0' signature
    ptr1++;

    if (useTailAlloc) {
        animData = _heap_malloc_tail(&heap_spriteHead, *ptr1);
    } else {
        animData = _heap_malloc(&heap_spriteHead, *ptr1);
    }
    decode_yay0(data, animData);
    general_heap_free(data);

    // swizzle raster array
    data = (s32**)animData->rastersOffset;
    data = SPR_SWIZZLE(ALIGN4(animData), data);
    animData->rastersOffset = (SpriteRasterCacheEntry**)data;

    while (TRUE) {
        ptr1 = *data;
        if (ptr1 == PTR_LIST_END) {
            break;
        }
        // swizzle each raster cache entry
        ptr1 = SPR_SWIZZLE(ALIGN4(animData), ptr1);
        *data++ = ptr1;
        image = ((SpriteRasterCacheEntry*)ptr1)->image;

        if (!isPlayerSprite) {
            // swizzle image pointer in the cache entry
            image = SPR_SWIZZLE(ALIGN4(animData), image);
            *ptr1 = (s32)image;
        }
    }

    if (isPlayerSprite) {
        PlayerRasterLoadDescBeginSpriteIndex[idx] = PlayerRasterLoadDescNumLoaded;
        count = PlayerSpriteRasterSets[idx + 1] - PlayerSpriteRasterSets[idx];
        // load a range of raster loading desciptors to a buffer and copy contents into PlayerRasterLoadDesc
        nuPiReadRom(SpriteDataHeader[0] + PlayerRasterHeader.loadDescriptors + sizeof(u32) * PlayerSpriteRasterSets[idx],
            PlayerRasterLoadDescBuffer, sizeof(PlayerRasterLoadDescBuffer));
        for (i = 0; i < count; i++) {
            PlayerRasterLoadDesc[PlayerRasterLoadDescNumLoaded++] = PlayerRasterLoadDescBuffer[i];
        }
    }

    // swizzle palettes array
    palettes = SPR_SWIZZLE(ALIGN4(animData), animData->palettesOffset);
    animData->palettesOffset = (PAL_PTR*)palettes;
    while (TRUE) {
        ptr1 = *palettes;
        if (ptr1 == PTR_LIST_END) {
            break;
        }
        // swizzle each palette pointer
        ptr1 = SPR_SWIZZLE(ALIGN4(animData), ptr1);
        *palettes++ = ptr1;
    }

    spr_swizzle_anim_offsets(0, 0, animData);
    return animData;
}

void spr_init_player_raster_cache(s32 cacheSize, s32 maxRasterSize) {
    void* raster;
    s32 i;

    nuPiReadRom(SPRITE_ROM_START, &SpriteDataHeader, sizeof(SpriteDataHeader));
    PlayerRasterCacheSize = cacheSize;
    PlayerRasterMaxSize = maxRasterSize;
    SpriteDataHeader[0] += SPRITE_ROM_START;
    SpriteDataHeader[1] += SPRITE_ROM_START;
    SpriteDataHeader[2] += SPRITE_ROM_START;
    raster = _heap_malloc(&heap_spriteHead, maxRasterSize * cacheSize);

    for (i = 0; i < ARRAY_COUNT(PlayerRasterCache); i++) {
        PlayerRasterCache[i].raster = raster;
        raster += PlayerRasterMaxSize;
        PlayerRasterCache[i].lazyDeleteTime = 0;
        PlayerRasterCache[i].rasterIndex = 0;
        PlayerRasterCache[i].spriteIndex = 0xFF;
    }

    for (i = 0; i < ARRAY_COUNT(PlayerRasterLoadDescBeginSpriteIndex); i++)    {
        PlayerRasterLoadDescBeginSpriteIndex[i] = 0;
    }
    PlayerRasterLoadDescNumLoaded = 0;
    nuPiReadRom(SpriteDataHeader[0], &PlayerRasterHeader, sizeof(PlayerRasterHeader));
    nuPiReadRom(SpriteDataHeader[0] + PlayerRasterHeader.indexRanges, PlayerSpriteRasterSets, sizeof(PlayerSpriteRasterSets));
}

IMG_PTR spr_get_player_raster(s32 rasterIndex, s32 playerSpriteID) {
    PlayerSpriteCacheEntry* cacheEntry;
    u32 playerRasterInfo;
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

    cacheEntry = &PlayerRasterCache[idx];
    cacheEntry->rasterIndex = rasterIndex;
    cacheEntry->spriteIndex = playerSpriteID;
    cacheEntry->lazyDeleteTime = 2;

    // each player raster load descriptor has image size (in bytes) and relative offset packed into one word
    // upper three nibbles give size / 16, lower 5 give offset
    playerRasterInfo = PlayerRasterLoadDesc[PlayerRasterLoadDescBeginSpriteIndex[playerSpriteID] + rasterIndex];
    nuPiReadRom(SpriteDataHeader[0] + (playerRasterInfo & 0xFFFFF), cacheEntry->raster, (playerRasterInfo >> 0x10) & 0xFFF0);
    return cacheEntry->raster;
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
    s32 sawRaster[100 + 1];
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sawRaster) - 1; i++) {
        sawRaster[i] = FALSE;
    }

    while ((extraAnimID = *extraAnimList++) != -1) {
        compList = header->animListStart[extraAnimID & 0xFF];
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
        raster = (SpriteRasterCacheEntry*)*oldPalList++; // required to match
        *(u16**)writePos = (u16*)raster;
        writePos += 4;
        if (raster == PTR_LIST_END) {
            break;
        }
    }

    _heap_realloc(&heap_spriteHead, header, (s32)writePos - (s32)header);
}

SpriteComponent** spr_allocate_components(s32 count) {
    s32 listSize;
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
        listPos = listStart;
        component = (SpriteComponent*) listPos;
    } else {
        listStart = _heap_malloc(&heap_spriteHead, totalSize);
        listPos = listStart;
        component = (SpriteComponent*) listPos;
    }

    component = (SpriteComponent*)((s32)(component) + (listSize / 4) * 4);

    // fill list values
    for (i = 0; i < count; i++) {
        *listPos++ = component;
        component++;
    }
    *listPos = PTR_LIST_END;

    return listStart;
}
