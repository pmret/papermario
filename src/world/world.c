#include "common.h"
#include "ld_addrs.h"
#include "npc.h"
#include "camera.h"
#include "hud_element.h"
#include "rumble.h"
#include "sprite.h"
#include "model.h"
#include "gcc/string.h"

s32 WorldReverbModeMapping[] = { 0, 1, 2, 3 };

//TODO possible data split here

Vec3s gEntityColliderFaces[] = {
    { 4, 6, 5 }, { 4, 7, 6 },
    { 0, 3, 4 }, { 3, 7, 4 },
    { 3, 2, 7 }, { 2, 6, 7 },
    { 2, 1, 6 }, { 1, 5, 6 },
    { 1, 0, 5 }, { 0, 4, 5 },
    { 0, 1, 2 }, { 0, 2, 3 },
};

Vec3f gEntityColliderNormals[] = {
    {  0.0f,  1.0f,  0.0f }, {  0.0f,  1.0f,  0.0f },
    {  1.0f,  0.0f,  0.0f }, {  1.0f,  0.0f,  0.0f },
    {  0.0f,  0.0f, -1.0f }, {  0.0f,  0.0f, -1.0f },
    { -1.0f,  0.0f,  0.0f }, { -1.0f,  0.0f,  0.0f },
    {  0.0f,  0.0f,  1.0f }, {  0.0f,  0.0f,  1.0f },
    {  0.0f, -1.0f,  0.0f }, {  0.0f, -1.0f,  0.0f },
};

//TODO data split here!
s32 pad_map_table[] = { 0, 0 };

#ifdef SHIFT
#define ASSET_TABLE_ROM_START (s32) mapfs_ROM_START
#elif VERSION_JP
#define ASSET_TABLE_ROM_START 0x1E00000
#else
#define ASSET_TABLE_ROM_START 0x1E40000
#endif

#define ASSET_TABLE_HEADER_SIZE 0x20
#define ASSET_TABLE_FIRST_ENTRY (ASSET_TABLE_ROM_START + ASSET_TABLE_HEADER_SIZE)

SHIFT_BSS MapSettings gMapSettings;
SHIFT_BSS MapConfig* gMapConfig;
SHIFT_BSS char wMapHitName[0x18];
SHIFT_BSS char wMapShapeName[0x18];
SHIFT_BSS char wMapTexName[0x18];
SHIFT_BSS char wMapBgName[0x18];

typedef struct {
    /* 0x00 */ char name[16];
    /* 0x10 */ u32 offset;
    /* 0x14 */ u32 compressedLength;
    /* 0x18 */ u32 decompressedLength;
} AssetHeader; // size = 0x1C

void fio_deserialize_state(void);
void load_map_hit_asset(void);

#ifdef SHIFT
#define shim_general_heap_create_obfuscated general_heap_create
#endif

extern ShapeFile gMapShapeData;

void load_map_script_lib(void) {
    DMA_COPY_SEGMENT(world_script_api);
}

void load_map_by_IDs(s16 areaID, s16 mapID, s16 loadType) {
    s32 skipLoadingAssets = 0;
    MapConfig* mapConfig;
    MapSettings* mapSettings;
    char texStr[17];
    s32 decompressedSize;

    sfx_stop_env_sounds();
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_FLOOR_REFLECTION;

    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_WORLD;

#if VERSION_IQUE
    general_heap_create();
#else
    load_obfuscation_shims();
    shim_general_heap_create_obfuscated();
#endif

#if VERSION_JP
    reset_max_rumble_duration();
#endif
    clear_render_tasks();
    clear_worker_list();
    clear_script_list();

    switch (loadType) {
        case LOAD_FROM_MAP:
            clear_area_flags();
            gGameStatusPtr->loadType = LOAD_FROM_MAP;
            break;
        case LOAD_FROM_FILE_SELECT:
            fio_deserialize_state();
            areaID = gGameStatusPtr->areaID;
            mapID = gGameStatusPtr->mapID;
            gGameStatusPtr->prevArea = areaID;
            gGameStatusPtr->loadType = LOAD_FROM_FILE_SELECT;
            break;
    }

    gGameStatusPtr->mapShop = NULL;

    mapConfig = &gAreas[areaID].maps[mapID];

    sprintf(wMapShapeName, "%s_shape", mapConfig->id);
    sprintf(wMapHitName, "%s_hit", mapConfig->id);
    strcpy(texStr, mapConfig->id);
    texStr[3] = '\0';
    sprintf(wMapTexName, "%s_tex", texStr);

    gMapConfig = mapConfig;
    if (mapConfig->bgName != NULL) {
        strcpy(wMapBgName, mapConfig->bgName);
    }
    load_map_script_lib();

    if (mapConfig->dmaStart != NULL) {
        dma_copy(mapConfig->dmaStart, mapConfig->dmaEnd, mapConfig->dmaDest);
    }

    gMapSettings = *mapConfig->settings;

    mapSettings = &gMapSettings;
    if (mapConfig->init != NULL) {
        skipLoadingAssets = mapConfig->init();
    }

    if (!skipLoadingAssets) {
        ShapeFile* shapeFile = &gMapShapeData;
        void* yay0Asset = load_asset_by_name(wMapShapeName, &decompressedSize);

        decode_yay0(yay0Asset, shapeFile);
        general_heap_free(yay0Asset);

        mapSettings->modelTreeRoot = shapeFile->header.root;
        mapSettings->modelNameList = shapeFile->header.modelNames;
        mapSettings->colliderNameList = shapeFile->header.colliderNames;
        mapSettings->zoneNameList = shapeFile->header.zoneNames;
    }

    if (mapConfig->bgName != NULL) {
        load_map_bg(wMapBgName);
    }

#if VERSION_IQUE
    general_heap_create();
#else
    load_obfuscation_shims();
    shim_general_heap_create_obfuscated();
#endif

    sfx_clear_env_sounds(0);
    clear_worker_list();
    clear_script_list();
    create_cameras_a();
    spr_init_sprites(gGameStatusPtr->playerSpriteSet);
    clear_animator_list();
    clear_entity_models();
    clear_npcs();
    hud_element_clear_cache();
    clear_trigger_data();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();

    if (gGameStatusPtr->introPart == INTRO_PART_NONE) {
        func_80138188();
    }

    if (!skipLoadingAssets) {
        initialize_collision();
        load_map_hit_asset();
    }

    reset_battle_status();
    clear_encounter_status();
    clear_entity_data(TRUE);
    clear_effect_data();
    clear_player_status();
    player_reset_data();
    partner_reset_data();
    clear_printers();
    clear_item_entity_data();

    gPlayerStatus.targetYaw = gPlayerStatus.curYaw;

    sfx_set_reverb_mode(WorldReverbModeMapping[*(s32*)mapConfig->unk_1C & 0x3]);
    sfx_reset_door_sounds();

    if (!skipLoadingAssets) {
        s32 texturesOffset = get_asset_offset(wMapTexName, &decompressedSize);

        if (mapSettings->modelTreeRoot != NULL) {
            load_data_for_models(mapSettings->modelTreeRoot, texturesOffset, decompressedSize);
        }
    }

    if (mapSettings->background != NULL) {
        set_background(mapSettings->background);
    } else {
        set_background_size(296, 200, 12, 20);
    }

    gCurrentCameraID = CAM_DEFAULT;
    gCameras[CAM_DEFAULT].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_BATTLE].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_TATTLE].flags |= CAMERA_FLAG_DISABLED;
    gCameras[CAM_3].flags |= CAMERA_FLAG_DISABLED;

    if (gGameStatusPtr->introPart == INTRO_PART_NONE) {
        set_cam_viewport(CAM_DEFAULT, 12, 20, 296, 200);
    } else {
        set_cam_viewport(CAM_DEFAULT, 29, 28, 262, 162);
    }

    initialize_status_bar();
    gGameStatusPtr->unk_90 = 1000;
    gGameStatusPtr->unk_92 = 1000;
    gGameStatusPtr->mainScriptID = start_script_in_group(mapSettings->main, EVT_PRIORITY_0, 0, 0)->id;
}

MapConfig* get_current_map_config(void) {
    return gMapConfig;
}

MapSettings* get_current_map_settings(void) {
    return &gMapSettings;
}

s32 get_map_IDs_by_name(const char* mapName, s16* areaID, s16* mapID) {
    s32 i;
    s32 j;
    MapConfig* maps;

    // TODO: Potentially a fake match? Difficult to not set the temp in the for conditional.
    for (i = 0; (maps = gAreas[i].maps) != NULL; i++) {
        for (j = 0; j < gAreas[i].mapCount; j++) {
            if (strcmp(maps[j].id, mapName) == 0) {
                *areaID = i;
                *mapID = j;
                return TRUE;
            }
        }
    }

    return FALSE;
}

void* load_asset_by_name(const char* assetName, u32* decompressedSize) {
    AssetHeader firstHeader;
    AssetHeader* assetTableBuffer;
    AssetHeader* curAsset;
    void* ret;

    dma_copy((u8*) ASSET_TABLE_FIRST_ENTRY, (u8*) ASSET_TABLE_FIRST_ENTRY + sizeof(AssetHeader), &firstHeader);
    assetTableBuffer = heap_malloc(firstHeader.offset);
    curAsset = &assetTableBuffer[0];
    dma_copy((u8*) ASSET_TABLE_FIRST_ENTRY, (u8*) ASSET_TABLE_FIRST_ENTRY + firstHeader.offset, assetTableBuffer);
    while (strcmp(curAsset->name, assetName) != 0) {
        curAsset++;
    }
    *decompressedSize = curAsset->decompressedLength;
    ret = general_heap_malloc(curAsset->compressedLength);
    dma_copy((u8*) ASSET_TABLE_FIRST_ENTRY + curAsset->offset,
             (u8*) ASSET_TABLE_FIRST_ENTRY + curAsset->offset + curAsset->compressedLength, ret);
    heap_free(assetTableBuffer);
    return ret;
}

s32 get_asset_offset(char* assetName, s32* compressedSize) {
    AssetHeader firstHeader;
    AssetHeader* assetTableBuffer;
    AssetHeader* curAsset;
    s32 ret;

    dma_copy((u8*) ASSET_TABLE_FIRST_ENTRY, (u8*) ASSET_TABLE_FIRST_ENTRY + sizeof(AssetHeader), &firstHeader);
    assetTableBuffer = heap_malloc(firstHeader.offset);
    curAsset = &assetTableBuffer[0];
    dma_copy((u8*) ASSET_TABLE_FIRST_ENTRY, (u8*) ASSET_TABLE_FIRST_ENTRY + firstHeader.offset, assetTableBuffer);
    while (strcmp(curAsset->name, assetName) != 0) {
        curAsset++;
    }
    *compressedSize = curAsset->compressedLength;
    ret = ASSET_TABLE_FIRST_ENTRY + curAsset->offset;
    heap_free(assetTableBuffer);
    return ret;
}

#define AREA(area, jp_name) { ARRAY_COUNT(area##_maps), area##_maps, "area_" #area, jp_name }

#define MAP(map) \
    .id = #map, \
    .settings = &map##_settings, \
    .dmaStart = map##_ROM_START, \
    .dmaEnd = map##_ROM_END, \
    .dmaDest = map##_VRAM \

#define MAP_WITH_INIT(map) \
    MAP(map), \
    .init = &map##_map_init \

/// Toad Town
#include "area_mac/mac.h"
MapConfig mac_maps[] = {
    { MAP(machi), .bgName = "nok_bg" },
    { MAP(mac_00), .bgName = "nok_bg" },
    { MAP(mac_01), .bgName = "nok_bg" },
    { MAP(mac_02), .bgName = "nok_bg" },
    { MAP(mac_03), .bgName = "nok_bg" },
    { MAP_WITH_INIT(mac_04), .bgName = "nok_bg" },
    { MAP(mac_05), .bgName = "nok_bg" },
    { MAP(mac_06), .bgName = "nok_bg" },
};

/// Toad Town Tunnels
#include "area_tik/tik.h"
MapConfig tik_maps[] = {
    { MAP(tik_01), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_02), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_03), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_04), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_05), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_06), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_07), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_08), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_09), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_10), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_12), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_14), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_15), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_17), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_18), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_19), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_20), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_21), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_22), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_23), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(tik_24), .songVariation = 1, .sfxReverb = 2 },
    { MAP(tik_25), .songVariation = 1, .sfxReverb = 2 },
};

/// Inside the Whale
#include "area_kgr/kgr.h"
MapConfig kgr_maps[] = {
    { MAP(kgr_01), .sfxReverb = 1 },
    { MAP(kgr_02), .sfxReverb = 1 },
};

/// Goomba Region
#include "area_kmr/kmr.h"
MapConfig kmr_maps[] = {
    { MAP(kmr_00), .bgName = "kmr_bg", .sfxReverb = 1 },
    { MAP(kmr_02), .bgName = "kmr_bg" },
    { MAP(kmr_03), .bgName = "kmr_bg" },
    { MAP(kmr_04), .bgName = "kmr_bg" },
    { MAP(kmr_05), .bgName = "kmr_bg" },
    { MAP(kmr_06), .bgName = "kmr_bg" },
    { MAP(kmr_07), .bgName = "kmr_bg" },
    { MAP(kmr_09), .bgName = "kmr_bg" },
    { MAP(kmr_10), .bgName = "kmr_bg" },
    { MAP(kmr_11), .bgName = "kmr_bg" },
    { MAP(kmr_12), .bgName = "kmr_bg" },
    { MAP(kmr_20), .bgName = "kmr_bg" }, // Mario's House
    { MAP_WITH_INIT(kmr_21) },
    { MAP_WITH_INIT(kmr_22) },
    { MAP_WITH_INIT(kmr_23) },
    { MAP_WITH_INIT(kmr_24) },
    { MAP(kmr_30) },
};

/// Mt. Rugged
#include "area_iwa/iwa.h"
MapConfig iwa_maps[] = {
    { MAP(iwa_00), .bgName = "iwa_bg" },
    { MAP(iwa_01), .bgName = "iwa_bg" },
    { MAP(iwa_02), .bgName = "iwa_bg" },
    { MAP(iwa_03), .bgName = "iwa_bg" },
    { MAP(iwa_04), .bgName = "iwa_bg" },
    { MAP(iwa_10), .bgName = "iwa_bg" },
    { MAP(iwa_11), .bgName = "iwa_bg" },
};

/// Dry Dry Outpost
#include "area_dro/dro.h"
MapConfig dro_maps[] = {
    { MAP(dro_01), .bgName = "sbk_bg" },
    { MAP(dro_02), .bgName = "sbk_bg" },
};

/// Dry Dry Desert
#include "area_sbk/sbk.h"
MapConfig sbk_maps[] = {
    { MAP(sbk_00), .bgName = "sbk_bg" },
    { MAP(sbk_01), .bgName = "sbk_bg" },
    { MAP(sbk_02), .bgName = "sbk_bg" },
    { MAP(sbk_03), .bgName = "sbk_bg" },
    { MAP(sbk_04), .bgName = "sbk_bg" },
    { MAP(sbk_05), .bgName = "sbk_bg" },
    { MAP(sbk_06), .bgName = "sbk_bg" },
    { MAP(sbk_10), .bgName = "sbk_bg" },
    { MAP(sbk_11), .bgName = "sbk_bg" },
    { MAP(sbk_12), .bgName = "sbk_bg" },
    { MAP(sbk_13), .bgName = "sbk_bg" },
    { MAP(sbk_14), .bgName = "sbk_bg" },
    { MAP(sbk_15), .bgName = "sbk_bg" },
    { MAP(sbk_16), .bgName = "sbk_bg" },
    { MAP(sbk_20), .bgName = "sbk_bg" },
    { MAP(sbk_21), .bgName = "sbk_bg" },
    { MAP(sbk_22), .bgName = "sbk_bg" },
    { MAP(sbk_23), .bgName = "sbk_bg" },
    { MAP(sbk_24), .bgName = "sbk_bg" },
    { MAP(sbk_25), .bgName = "sbk_bg" },
    { MAP(sbk_26), .bgName = "sbk_bg" },
    { MAP(sbk_30), .bgName = "sbk_bg" },
    { MAP(sbk_31), .bgName = "sbk_bg" },
    { MAP(sbk_32), .bgName = "sbk_bg" },
    { MAP(sbk_33), .bgName = "sbk_bg" },
    { MAP(sbk_34), .bgName = "sbk_bg" },
    { MAP(sbk_35), .bgName = "sbk_bg" },
    { MAP(sbk_36), .bgName = "sbk_bg" },
    { MAP(sbk_40), .bgName = "sbk_bg" },
    { MAP(sbk_41), .bgName = "sbk_bg" },
    { MAP(sbk_42), .bgName = "sbk_bg" },
    { MAP(sbk_43), .bgName = "sbk_bg" },
    { MAP(sbk_44), .bgName = "sbk_bg" },
    { MAP(sbk_45), .bgName = "sbk_bg" },
    { MAP(sbk_46), .bgName = "sbk_bg" },
    { MAP(sbk_50), .bgName = "sbk_bg" },
    { MAP(sbk_51), .bgName = "sbk_bg" },
    { MAP(sbk_52), .bgName = "sbk_bg" },
    { MAP(sbk_53), .bgName = "sbk_bg" },
    { MAP(sbk_54), .bgName = "sbk_bg" },
    { MAP(sbk_55), .bgName = "sbk_bg" },
    { MAP(sbk_56), .bgName = "sbk_bg" },
    { MAP(sbk_60), .bgName = "sbk_bg" },
    { MAP(sbk_61), .bgName = "sbk_bg" },
    { MAP(sbk_62), .bgName = "sbk_bg" },
    { MAP(sbk_63), .bgName = "sbk_bg" },
    { MAP(sbk_64), .bgName = "sbk_bg" },
    { MAP(sbk_65), .bgName = "sbk_bg" },
    { MAP(sbk_66), .bgName = "sbk_bg" },
    { MAP(sbk_99), .bgName = "sbk_bg" },
};

/// Dry Dry Ruins
#include "area_isk/isk.h"
MapConfig isk_maps[] = {
    { MAP(isk_01), .bgName = "sbk3_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_02), .bgName = "sbk3_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_03), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_04), .bgName = "sbk3_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_05), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_06), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_07), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_08), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_09), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_10), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_11), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_12), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_13), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_14), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_16), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_18), .songVariation = 1, .sfxReverb = 2 },
    { MAP(isk_19), .songVariation = 1, .sfxReverb = 2 },
};

/// Koopa Bros. Fortress
#include "area_trd/trd.h"
MapConfig trd_maps[] = {
    { MAP(trd_00), .bgName = "nok_bg" },
    { MAP(trd_01), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_02), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_03), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_04), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_05), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_06), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_07), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_08), .songVariation = 1, .sfxReverb = 3 },
    { MAP(trd_09), .bgName = "nok_bg" },
    { MAP(trd_10), .songVariation = 1, .sfxReverb = 3 },
};

/// Koopa Region
#include "area_nok/nok.h"
MapConfig nok_maps[] = {
    { MAP(nok_01), .bgName = "nok_bg" },
    { MAP(nok_02), .bgName = "nok_bg" },
    { MAP(nok_03), .bgName = "nok_bg" },
    { MAP(nok_04), .bgName = "nok_bg" },
    { MAP(nok_11), .bgName = "nok_bg" },
    { MAP(nok_12), .bgName = "nok_bg" },
    { MAP(nok_13), .bgName = "nok_bg" },
    { MAP(nok_14), .bgName = "nok_bg" },
    { MAP(nok_15), .bgName = "nok_bg" },
};

/// Star Region
#include "area_hos/hos.h"
MapConfig hos_maps[] = {
    { MAP_WITH_INIT(hos_00), .bgName = "nok_bg" },
    { MAP(hos_01), .bgName = "hos_bg" },
    { MAP(hos_02), .bgName = "hos_bg" },
    { MAP(hos_03), .bgName = "hos_bg" },
    { MAP(hos_04), .bgName = "hos_bg" },
    { MAP(hos_05), .bgName = "hos_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(hos_06), .bgName = "hos_bg" },
    { MAP_WITH_INIT(hos_10), .bgName = "hos_bg" },
    { MAP(hos_20), .bgName = "hos_bg" },
};

/// Bowser's Castle
#include "area_kpa/kpa.h"
MapConfig kpa_maps[] = {
    { MAP(kpa_01), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_03), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_04), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_08), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_09), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_10), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_11), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_12), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_13), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_14), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_15), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_16), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_17), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_32), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_33), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_40), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_41), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_50), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(kpa_51), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_52), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(kpa_53), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_60), .bgName = "kpa_bg" },
    { MAP(kpa_61), .bgName = "kpa_bg" },
    { MAP(kpa_62), .bgName = "kpa_bg" },
    { MAP(kpa_63), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_70), .songVariation = 1, .sfxReverb = 3 },
    { MAP_WITH_INIT(kpa_81), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(kpa_82), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(kpa_83), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_90), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_91), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_94), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_95), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_96), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(kpa_100), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(kpa_101), .songVariation = 1, .sfxReverb = 1 },
    { MAP(kpa_102), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_111), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_112), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_113), .songVariation = 1, .sfxReverb = 3 },
    { MAP_WITH_INIT(kpa_114), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_115), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_116), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_117), .songVariation = 1, .sfxReverb = 1 },
    { MAP(kpa_118), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_119), .songVariation = 1, .sfxReverb = 1 },
    { MAP(kpa_121), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kpa_130), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_133), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kpa_134), .songVariation = 1, .sfxReverb = 3 },
};

/// Peach's Castle Grounds
#include "area_osr/osr.h"
MapConfig osr_maps[] = {
    { MAP(osr_00), .bgName = "nok_bg" },
    { MAP_WITH_INIT(osr_01), .bgName = "nok_bg" },
    { MAP_WITH_INIT(osr_02), .bgName = "kpa_bg" },
    { MAP_WITH_INIT(osr_03), .bgName = "kpa_bg" },
    { MAP_WITH_INIT(osr_04), .bgName = "nok_bg" },
};

/// Peach's Castle
/// @bug There are two entries for kkj_26; the latter is unreachable.
#include "area_kkj/kkj.h"
MapConfig kkj_maps[] = {
    { MAP_WITH_INIT(kkj_00), .bgName = "nok_bg", .songVariation = 1, .sfxReverb = 3 },
    { MAP(kkj_01), .bgName = "nok_bg", .songVariation = 1, .sfxReverb = 3 },
    { MAP(kkj_02), .bgName = "nok_bg", .sfxReverb = 2 },
    { MAP_WITH_INIT(kkj_03), .bgName = "nok_bg", .sfxReverb = 3 },
    { MAP(kkj_10), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kkj_11), .songVariation = 1, .sfxReverb = 3 },
    { MAP(kkj_12), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(kkj_13), .bgName = "kpa_bg",  .songVariation = 1, .sfxReverb = 3},
    { MAP_WITH_INIT(kkj_14), .bgName = "kpa_bg" },
    { MAP(kkj_15) },
    { MAP(kkj_16), .sfxReverb = 1 },
    { MAP(kkj_17) },
    { MAP(kkj_18), .bgName = "kpa_bg" },
    { MAP(kkj_19) },
    { MAP(kkj_20) },
    { MAP(kkj_21), .sfxReverb = 1 },
    { MAP(kkj_22), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(kkj_23), .bgName = "kpa_bg" },
    { MAP(kkj_24), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(kkj_25), .bgName = "kpa_bg" },
    { MAP(kkj_26), .bgName = "kpa_bg" },
    { MAP(kkj_26), .sfxReverb = 2 },
    { MAP(kkj_27), .sfxReverb = 1 },
    { MAP(kkj_28), .sfxReverb = 1 },
    { MAP(kkj_29), .sfxReverb = 1 },
};

/// Jade Jungle
#include "area_jan/jan.h"
MapConfig jan_maps[] = {
    { MAP(jan_00), .bgName = "yos_bg" },
    { MAP(jan_01), .bgName = "yos_bg" },
    { MAP(jan_02), .bgName = "yos_bg" },
    { MAP(jan_03), .bgName = "yos_bg" },
    { MAP(jan_04), .bgName = "yos_bg" },
    { MAP(jan_05), .bgName = "yos_bg" },
    { MAP(jan_06), .bgName = "jan_bg" },
    { MAP(jan_07), .bgName = "yos_bg" },
    { MAP(jan_08), .bgName = "yos_bg" },
    { MAP(jan_09), .bgName = "yos_bg" },
    { MAP(jan_10), .bgName = "yos_bg" },
    { MAP(jan_11), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(jan_12), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(jan_13), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(jan_14), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(jan_15), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(jan_16), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(jan_17), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(jan_18), .bgName = "yos_bg" },
    { MAP(jan_19), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(jan_22), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(jan_23), .bgName = "yos_bg" },
};

/// Forever Forest
#include "area_mim/mim.h"
MapConfig mim_maps[] = {
    { MAP(mim_01), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_02), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_03), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_04), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_05), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_06), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_07), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_08), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_09), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_10), .bgName = "nok_bg" },
    { MAP(mim_11), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(mim_12), .bgName = "arn_bg", .songVariation = 1, .sfxReverb = 2 },
};

/// Boo's Mansion
#include "area_obk/obk.h"
MapConfig obk_maps[] = {
    { MAP(obk_01), .songVariation = 1, .sfxReverb = 2 },
    { MAP(obk_02), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(obk_03), .songVariation = 1, .sfxReverb = 1 },
    { MAP(obk_04), .songVariation = 1, .sfxReverb = 1 },
    { MAP(obk_05), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(obk_06), .songVariation = 1, .sfxReverb = 1 },
    { MAP(obk_07), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(obk_08), .bgName = "obk_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(obk_09), .songVariation = 1, .sfxReverb = 2 },
};

/// Gusty Gulch
#include "area_arn/arn.h"
MapConfig arn_maps[] = {
    { MAP(arn_02), .bgName = "arn_bg" },
    { MAP(arn_03), .bgName = "arn_bg" },
    { MAP(arn_04), .bgName = "arn_bg" },
    { MAP(arn_05), .bgName = "arn_bg" },
    { MAP(arn_07), .bgName = "arn_bg" },
    { MAP(arn_08), .songVariation = 1, .sfxReverb = 1 },
    { MAP(arn_09), .songVariation = 1, .sfxReverb = 1 },
    { MAP(arn_10), .songVariation = 1, .sfxReverb = 1 },
    { MAP(arn_11), .songVariation = 1, .sfxReverb = 1 },
    { MAP(arn_12), .songVariation = 1, .sfxReverb = 1 },
    { MAP(arn_13), .songVariation = 1, .sfxReverb = 1 },
};

/// Tubba Blubba's Castle
#include "area_dgb/dgb.h"
MapConfig dgb_maps[] = {
    { MAP_WITH_INIT(dgb_00), .bgName = "arn_bg" },
    { MAP(dgb_01), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_02), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_03), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_04), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_05), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_06), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_07), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_08), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_09), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_10), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_11), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_12), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_13), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_14), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_15), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_16), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_17), .songVariation = 1, .sfxReverb = 2 },
    { MAP(dgb_18), .songVariation = 1, .sfxReverb = 2 },
};

/// Mt. Lavalava
#include "area_kzn/kzn.h"
MapConfig kzn_maps[] = {
    { MAP(kzn_01), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_02), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_03), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_04), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_05), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_06), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_07), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_08), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_09), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_10), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_11), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_17), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_18), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_19), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_20), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_22), .songVariation = 1, .sfxReverb = 2 },
    { MAP(kzn_23), .bgName = "yos_bg", .songVariation = 1, .sfxReverb = 2 },
};

/// Flower Fields
#include "area_flo/flo.h"
MapConfig flo_maps[] = {
    { MAP(flo_00), .bgName = "fla_bg" },
    { MAP(flo_03), .bgName = "fla_bg" },
    { MAP(flo_07), .bgName = "fla_bg" },
    { MAP(flo_08), .bgName = "fla_bg" },
    { MAP(flo_09), .bgName = "fla_bg" },
    { MAP(flo_10), .bgName = "fla_bg" },
    { MAP(flo_11), .bgName = "fla_bg" },
    { MAP(flo_12), .bgName = "fla_bg" },
    { MAP(flo_13), .bgName = "fla_bg" },
    { MAP(flo_14), .bgName = "fla_bg" },
    { MAP(flo_15), .bgName = "fla_bg" },
    { MAP(flo_16), .bgName = "fla_bg" },
    { MAP(flo_17), .bgName = "fla_bg" },
    { MAP(flo_18), .bgName = "fla_bg" },
    { MAP(flo_19), .bgName = "sra_bg" },
    { MAP(flo_21), .bgName = "sra_bg" },
    { MAP(flo_22), .bgName = "fla_bg" },
    { MAP(flo_23), .bgName = "fla_bg" },
    { MAP(flo_24), .bgName = "fla_bg" },
    { MAP(flo_25), .bgName = "fla_bg" },
};

/// Shiver Region
#include "area_sam/sam.h"
MapConfig sam_maps[] = {
    { MAP(sam_01), .bgName = "yki_bg" },
    { MAP(sam_02), .bgName = "yki_bg" },
    { MAP(sam_03), .bgName = "yki_bg" },
    { MAP(sam_04), .bgName = "yki_bg" },
    { MAP(sam_05), .bgName = "sam_bg" },
    { MAP(sam_06), .bgName = "sam_bg" },
    { MAP(sam_07), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(sam_08), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(sam_09), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(sam_10), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP(sam_11), .bgName = "yki_bg" },
    { MAP(sam_12), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
};

/// Crystal Palace
#include "area_pra/pra.h"
MapConfig pra_maps[] = {
    { MAP_WITH_INIT(pra_01), .bgName = "yki_bg", .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_02), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_03), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_04), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_05), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_06), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_09), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_10), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_11), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_12), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_13), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_14), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_15), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_16), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_18), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_19), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_20), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_21), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_22), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_27), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_28), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_29), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_31), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_32), .bgName = "sam_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_33), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_34), .songVariation = 1, .sfxReverb = 1 },
    { MAP_WITH_INIT(pra_35), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_36), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_37), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_38), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_39), .songVariation = 1, .sfxReverb = 2 },
    { MAP_WITH_INIT(pra_40), .songVariation = 1, .sfxReverb = 1 },
};

/// Shy Guy's Toy Box
#include "area_omo/omo.h"
MapConfig omo_maps[] = {
    { MAP(omo_01), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_02), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_03), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_04), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_05), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_06), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_07), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_08), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_09), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_10), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_11), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_12), .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_13), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_14), .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_15), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_16), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP(omo_17), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
};

/// Debug
#include "area_tst/tst.h"
MapConfig tst_maps[] = {
    { MAP(tst_01), .bgName = "nok_bg" },
    { MAP(tst_02), .bgName = "nok_bg" },
    { MAP(tst_03), .bgName = "nok_bg" },
    { MAP(tst_04), .bgName = "nok_bg" },
    { MAP(tst_10), .bgName = "nok_bg" },
    { MAP(tst_11), .bgName = "nok_bg" },
    { MAP(tst_12), .bgName = "nok_bg" },
    { MAP(tst_13), .bgName = "nok_bg" },
    { MAP(tst_20), .bgName = "nok_bg" },
};

/// Credits
#include "area_end/end.h"
MapConfig end_maps[] = {
    { MAP_WITH_INIT(end_00) },
    { MAP_WITH_INIT(end_01) },
};

/// Toad Town Playroom
#include "area_mgm/mgm.h"
MapConfig mgm_maps[] = {
    { MAP(mgm_00) },
    { MAP(mgm_01) },
    { MAP(mgm_02) },
    { MAP(mgm_03) },
};

/// Game Over
#include "area_gv/gv.h"
MapConfig gv_maps[] = {
    { MAP(gv_01) },
};

AreaConfig gAreas[] = {
    AREA(kmr, "クリむら"),  // kuri mura [kuribou village, Goomba Village]
    AREA(mac, "まち"),  // machi [town, Toad Town]
    AREA(tik, "まちのちか"),  // machi no chika [under the town, Toad Town Tunnels]
    AREA(kgr, "くじらのなか"),  // kujira no naka [inside the whale]
    AREA(kkj, "きのこ城"),  // kinoko shiro [mushroom castle, Princess Peach's Castle]
    AREA(hos, "星ふる丘"),  // hoshi furu oka [star fall hill, Shooting Star Summit]
    AREA(nok, "ノコノコむら"),  // nokonoko mura [nokonoko village, Koopa Village]
    AREA(trd, "とりで"),  // toride [fortress, Koopa Bros. Fortress]
    AREA(iwa, "岩山"),  // iwayama [rock mountain, Mt. Rugged]
    AREA(dro, "カラカラタウン"),  // karakara taun [dried up town, Dry Dry Outpost]
    AREA(sbk, "カラカラ砂漠"),  // karakara sabaku [dried up desert, Dry Dry Desert]
    AREA(isk, "カラカラいせき"),  // karakara iseki [dried up ruins, Dry Dry Ruins]
    AREA(mim, "迷いの森"),  // mayoi no mori [lost forest, Forever Forest]
    AREA(obk, "テレサハウス"),  // teresa hausu [teresa house, Boo's Mansion]
    AREA(arn, "あれの"),  // areno [wasteland, Gusty Gulch]
    AREA(dgb, "ドガボンの城"),  // dogabon no shiro [dogabon's castle, Tubba Blubba's Castle]
    AREA(omo, "ヘイホーのおもちゃばこ"),  // heiho no omochabako [heiho's toy box, Shy Guy's Toy Box]
    AREA(jan, "ジャングル"),  // janguru [jungle, Jade Jungle]
    AREA(kzn, "火山"),  // kazan [volcano, Mt. Lavalava]
    AREA(flo, "フラワーランド"),  // furawaa rando [flower land, Flower Fields]
    AREA(sam, "さむいさむい村"),  // samui samui mura [cold cold village, Shiver City]
    AREA(pra, "パラレルきゅうでん"),  // parareru kyuuden [parallel palace, Crystal Palace]
    AREA(kpa, "クッパ城"),  // kuppa shiro [koopa's castle, Bowser's Castle]
    AREA(osr, "きのこ城そと"),  // kinoko shiro soto [outside mushroom castle, Outside Peach's Castle]
    AREA(end, "エンディング"),  // endingu [Ending]
    AREA(mgm, "ミニゲーム"),  // minige-mu [Minigames]
    AREA(gv, "ゲームオーバー"),  // ge-mu o-ba- [Game Over]
    AREA(tst, "テストマップ"),  // tesuto mappu [Test map]
    {},
};
