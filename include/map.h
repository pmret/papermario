#ifndef _MAP_H_
#define _MAP_H_

#include "common_structs.h"
#include "enums.h"
#include "world/entrances.h"
#include "script_api/map.h"
#include "npc.h"

// temporary: some standard script names
#define EVS_MakeEntities        EVS_MakeEntities
#define EVS_SetupMusic          EVS_SetupMusic
#define EVS_SetupRooms          EVS_SetupRooms
#define EVS_SetupFoliage        EVS_SetupFoliage
#define EVS_BindExitTriggers    EVS_BindExitTriggers
#define EVS_EnterMap            EVS_EnterMap

#define CLONED_MODEL(idx)       (10000+(idx))

// TODO: consider moving Npc here

#define ENTRY_COUNT(entryList) (sizeof(entryList) / sizeof(Vec4f))
typedef Vec4f EntryList[];

/// Fields other than main, entryList, entryCount, background, and tattle are initialised when the map loads.
typedef struct MapSettings {
    /* 0x00 */ struct ModelNode* modelTreeRoot;
    /* 0x04 */ s32 hitAssetCollisionOffset;
    /* 0x08 */ s32 hitAssetZoneOffset;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ EvtScript* main;
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
        s32 (*get)(void);
    } tattle;
} MapSettings; // size = 0x40

typedef s32(*MapInit)(void);

#define MAP_ID_MAX_LEN 7 ///< "xxx_yyy" excluding null terminator.
typedef struct MapConfig {
    /* 0x00 */ char* id; ///< @see MAP_ID_MAX_LEN
    /* 0x04 */ MapSettings* settings;
    /* 0x08 */ void* dmaStart;
    /* 0x0C */ void* dmaEnd;
    /* 0x10 */ void* dmaDest;
    /* 0x14 */ char* bgName;
    /* 0x18 */ MapInit init; ///< Return TRUE to skip normal asset (shape/hit/bg/tex) loading.
    /* 0x1C */ char unk_1C[0x2];
    /* 0x1E */ s8 songVariation; ///< 0 or 1. @see bgm_get_map_default_variation
    /* 0x1F */ s8 sfxReverb;
} MapConfig; // size = 0x20

typedef struct AreaConfig {
    /* 0x00 */ s32 mapCount;
    /* 0x04 */ MapConfig* maps;
    /* 0x08 */ char* id; ///< "area_xxx"
    /* 0x0C */ char* name; ///< JP debug name.
} AreaConfig; // size = 0x10

MapSettings* get_current_map_settings(void);

/// Zero-terminated.
extern AreaConfig gAreas[29];

extern EvtScript EVS_NpcHitRecoil;
extern EvtScript EVS_800936C0;

#endif
