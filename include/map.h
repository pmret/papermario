#ifndef _MAP_H_
#define _MAP_H_

#include "common_structs.h"
#include "enums.h"
#include "script_api/map.h"
#include "npc.h"

// TODO: consider moving Npc here

#define ENTRY_COUNT(entryList) (sizeof(entryList) / sizeof(Vec4f))
typedef Vec4f EntryList[];

/// Fields other than main, entryList, entryCount, background, and tattle are initialised when the map loads.
typedef struct MapConfig {
    /* 0x00 */ struct ModelNode* modelTreeRoot;
    /* 0x04 */ UNK_PTR collision;
    /* 0x08 */ UNK_PTR unk_08;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ EvtSource* main;
    /* 0x14 */ EntryList* entryList;
    /* 0x18 */ s32 entryCount;
    /* 0x1C */ char unk_1C[12];
    /* 0x28 */ char** modelNameList;
    /* 0x2C */ char** colliderNameList;
    /* 0x30 */ char** zoneNameList;
    /* 0x34 */ char unk_34[4];
    /* 0x38 */ BackgroundHeader* background;
    /* 0x3C */ union {
        s32 msgID;
        UNK_FUN_PTR(get);
    } tattle;
} MapConfig; // size = 0x40

typedef s32(*MapInit)(void);

#define MAP_ID_MAX_LEN 7 ///< "xxx_yyy" excluding null terminator.
typedef struct Map {
    /* 0x00 */ char* id; ///< @see MAP_ID_MAX_LEN
    /* 0x04 */ MapConfig* config;
    /* 0x08 */ void* dmaStart;
    /* 0x0C */ void* dmaEnd;
    /* 0x10 */ void* dmaDest;
    /* 0x14 */ char* bgName;
    /* 0x18 */ MapInit init; ///< Return TRUE to skip normal asset (shape/hit/bg/tex) loading.
    /* 0x1C */ union {
        u32 word;
        struct {
            char unk_1C[0x2];
            s8 songVariation; ///< 0 or 1. @see bgm_get_map_default_variation
            s8 flags;
        } bytes;
    } unk_1C;
} Map; // size = 0x20

typedef struct Area {
    /* 0x00 */ s32 mapCount;
    /* 0x04 */ Map* maps;
    /* 0x08 */ char* id; ///< "area_xxx"
    /* 0x0C */ char* name; ///< JP debug name.
} Area; // size = 0x10

MapConfig* get_current_map_header(void);

/// Zero-terminated.
extern Area gAreas[29];

/// Lists the songs that are forced to use the variation determined by `map.songVariation & 1`.
/// @see bgm_get_map_default_variation
extern s32 gSongsUsingVariationFlag[6];
extern s16 D_8014F738;

#endif
