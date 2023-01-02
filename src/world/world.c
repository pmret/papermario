#include "common.h"
#include "ld_addrs.h"
#include "npc.h"
#include "camera.h"
#include "hud_element.h"
#include "sprite.h"
#include "model.h"

#ifdef SHIFT
#define ASSET_TABLE_ROM_START mapfs_ROM_START
#else
#define ASSET_TABLE_ROM_START 0x1E40000
#endif

#define ASSET_TABLE_HEADER_SIZE 0x20
#define ASSET_TABLE_FIRST_ENTRY (ASSET_TABLE_ROM_START + ASSET_TABLE_HEADER_SIZE)

s32 WorldReverbModeMapping[] = { 0, 1, 2, 3 };

// bss
MapSettings gMapSettings;
MapConfig* gMapConfig;

typedef struct {
    /* 0x00 */ char name[16];
    /* 0x10 */ u32 offset;
    /* 0x14 */ u32 compressedLength;
    /* 0x18 */ u32 decompressedLength;
} AssetHeader; // size = 0x1C

void fio_deserialize_state(void);
void load_map_hit_asset(void);

void load_map_script_lib(void) {
    dma_copy(world_script_api_ROM_START, world_script_api_ROM_END, world_script_api_VRAM);
}

void load_map_by_IDs(s16 areaID, s16 mapID, s16 loadType) {
    s32 skipLoadingAssets = 0;
    MapConfig* mapConfig;
    MapSettings* mapSettings;
    char texStr[17];
    s32 decompressedSize;

    sfx_stop_env_sounds();
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
    gOverrideFlags &= ~GLOBAL_OVERRIDES_80;

    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_WORLD;
    func_8002D160();
    func_802B2078();
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
        ShapeFile* shapeFile = &D_80210000;
        void* yay0Asset = load_asset_by_name(wMapShapeName, &decompressedSize);

        decode_yay0(yay0Asset, shapeFile);
        general_heap_free(yay0Asset);

        mapSettings->modelTreeRoot = shapeFile->root;
        mapSettings->modelNameList = shapeFile->modelNames;
        mapSettings->colliderNameList = shapeFile->colliderNames;
        mapSettings->zoneNameList = shapeFile->zoneNames;
    }

    if (mapConfig->bgName != NULL) {
        load_map_bg(wMapBgName);
    }

    func_8002D160();
    func_802B2078();
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

    if (gGameStatusPtr->creditsViewportMode == -1) {
        func_80138188();
    }

    if (!skipLoadingAssets) {
        initialize_collision();
        load_map_hit_asset();
    }

    reset_battle_status();
    clear_encounter_status();
    clear_entity_data(1);
    clear_effect_data();
    clear_player_status();
    player_reset_data();
    partner_reset_data();
    clear_printers();
    clear_item_entity_data();

    gPlayerStatus.targetYaw = gPlayerStatus.currentYaw;

    sfx_set_reverb_mode(WorldReverbModeMapping[*(s32*)mapConfig->unk_1C & 0x3]);
    sfx_reset_door_sounds();

    if (!skipLoadingAssets) {
        s32 thing = get_asset_offset(wMapTexName, &decompressedSize);

        if (mapSettings->modelTreeRoot != NULL) {
            load_data_for_models(mapSettings->modelTreeRoot, thing, decompressedSize);
        }
    }

    if (mapSettings->background != NULL) {
        read_background_size(mapSettings->background);
    } else {
        set_background_size(296, 200, 12, 20);
    }

    gCurrentCameraID = CAM_DEFAULT;
    gCameras[CAM_DEFAULT].flags |= CAMERA_FLAGS_ENABLED;
    gCameras[CAM_BATTLE].flags |= CAMERA_FLAGS_ENABLED;
    gCameras[CAM_TATTLE].flags |= CAMERA_FLAGS_ENABLED;
    gCameras[CAM_3].flags |= CAMERA_FLAGS_ENABLED;

    if (gGameStatusPtr->creditsViewportMode == -1) {
        set_cam_viewport(0, 12, 20, 296, 200);
    } else {
        set_cam_viewport(0, 29, 28, 262, 162);
    }

    initialize_status_menu();
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

// Should be removed once the data section containing .init and .settings of all maps have been disassembled
#define MAP_UNSPLIT(map, settingsVRAM) \
    .id = #map, \
    .settings = (MapSettings*)(settingsVRAM), \
    .dmaStart = map##_ROM_START, \
    .dmaEnd = map##_ROM_END, \
    .dmaDest = map##_VRAM \

// these, along with all the *_maps, almost certainly belong in the next file
s16 gEntityColliderFaces[] = { 4, 6, 5, 4, 7, 6, 0, 3, 4, 3, 7, 4, 3, 2, 7, 2, 6, 7, 2, 1, 6, 1, 5, 6, 1, 0, 5,
                                 0, 4, 5, 0, 1, 2, 0, 2, 3};

f32 gEntityColliderNormals[] = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
                                       0.0f, -1.0f, 0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                       1.0f, 0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f};

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
MapConfig nok_maps[] = {
    { MAP_UNSPLIT(nok_01, 0x80242B90), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_02, 0x802445F0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_03, 0x80240E40), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_04, 0x80240F40), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_11, 0x80241F70), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_12, 0x80242100), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_13, 0x802414C0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_14, 0x80242440), .bgName = "nok_bg" },
    { MAP_UNSPLIT(nok_15, 0x802427D0), .bgName = "nok_bg" },
};

/// Star Region
MapConfig hos_maps[] = {
    { MAP_UNSPLIT(hos_00, 0x80240D50), .bgName = "nok_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(hos_01, 0x80240E40), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_02, 0x80242B90), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_03, 0x802435F0), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_04, 0x80240EE0), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_05, 0x80245910), .bgName = "hos_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(hos_06, 0x80242570), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_10, 0x80240CE0), .bgName = "hos_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(hos_20, 0x80240390), .bgName = "hos_bg" },
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
    { MAP_UNSPLIT(kpa_14,  0x802408A0), .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kpa_15,  0x802405E0), .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kpa_16,  0x802403B0), .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kpa_17,  0x80240020), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kpa_32,  0x80240350), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kpa_33,  0x80240350), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kpa_40,  0x80240040), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kpa_41,  0x80240040), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kpa_50,  0x80241A40), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kpa_51,  0x80241C40), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_52,  0x80241360), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kpa_53,  0x80240190), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_60,  0x80240450), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kpa_61,  0x80242360), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kpa_62,  0x80240430), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kpa_63,  0x802401B0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kpa_70,  0x80240B10), .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kpa_81,  0x80240480), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_82,  0x80240460), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_83,  0x80240090), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
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
MapConfig osr_maps[] = {
    { MAP_UNSPLIT(osr_00, 0x802407E0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(osr_01, 0x80240B00), .bgName = "nok_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(osr_02, 0x80240170), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(osr_03, 0x802403F0), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(osr_04, 0x802400D0), .bgName = "nok_bg", .init = (MapInit)0x80240000 },
};

/// Peach's Castle
/// @bug There are two entries for kkj_26; the latter is unreachable.
MapConfig kkj_maps[] = {
    { MAP_UNSPLIT(kkj_00, 0x80241030), .bgName = "nok_bg", .init = (MapInit)0x80240000, .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kkj_01, 0x80240F10), .bgName = "nok_bg", .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kkj_02, 0x80240030), .bgName = "nok_bg", .sfxReverb = 2 },
    { MAP_UNSPLIT(kkj_03, 0x80240360), .bgName = "nok_bg", .sfxReverb = 3, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_10, 0x80241120), .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kkj_11, 0x80241160), .songVariation = 1, .sfxReverb = 3 },
    { MAP_UNSPLIT(kkj_12, 0x802408D0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kkj_13, 0x802407A0), .bgName = "kpa_bg",  .songVariation = 1, .sfxReverb = 3, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_14, 0x80240580), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_15, 0x80240640) },
    { MAP_UNSPLIT(kkj_16, 0x80241090), .sfxReverb = 1 },
    { MAP_UNSPLIT(kkj_17, 0x802405B0) },
    { MAP_UNSPLIT(kkj_18, 0x80240830), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kkj_19, 0x80240D20) },
    { MAP_UNSPLIT(kkj_20, 0x80240600) },
    { MAP_UNSPLIT(kkj_21, 0x80240010), .sfxReverb = 1 },
    { MAP_UNSPLIT(kkj_22, 0x80240020), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kkj_23, 0x802409F0), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_24, 0x80240040), .bgName = "kpa_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(kkj_25, 0x80240F50), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_26, 0x80240070), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kkj_26, 0x80240070), .sfxReverb = 2 },
    { MAP_UNSPLIT(kkj_27, 0x802404C0), .sfxReverb = 1 },
    { MAP_UNSPLIT(kkj_28, 0x80240010), .sfxReverb = 1 },
    { MAP_UNSPLIT(kkj_29, 0x80240080), .sfxReverb = 1 },
};

/// Jade Jungle
MapConfig jan_maps[] = {
    { MAP_UNSPLIT(jan_00, 0x80241BD0), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_01, 0x802413F0), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_02, 0x80242940), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_03, 0x802432D0), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_04, 0x80241140), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_05, 0x80242710), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_06, 0x80242620), .bgName = "jan_bg" },
    { MAP_UNSPLIT(jan_07, 0x80241230), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_08, 0x80242460), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_09, 0x80241960), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_10, 0x80241750), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_11, 0x80240810), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(jan_12, 0x80241280), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(jan_13, 0x802405F0), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(jan_14, 0x80241300), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(jan_15, 0x80240320), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(jan_16, 0x80240590), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(jan_17, 0x80240040), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(jan_18, 0x80240020), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_19, 0x80240040), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(jan_22, 0x802419A0), .bgName = "jan_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(jan_23, 0x80240010), .bgName = "yos_bg" },
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
MapConfig dgb_maps[] = {
    { MAP_UNSPLIT(dgb_00, 0x802400D0), .bgName = "arn_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(dgb_01, 0x80243460), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_02, 0x80241470), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_03, 0x80242830), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_04, 0x80243130), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_05, 0x802414A0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_06, 0x802402E0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_07, 0x80241450), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_08, 0x80243CB0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_09, 0x80243840), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_10, 0x80240210), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_11, 0x80240090), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_12, 0x802402D0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_13, 0x80240010), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_14, 0x80240020), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_15, 0x802418A0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_16, 0x80241440), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_17, 0x80240020), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(dgb_18, 0x80241280), .songVariation = 1, .sfxReverb = 2 },
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
MapConfig sam_maps[] = {
    { MAP_UNSPLIT(sam_01, 0x80241F70), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_02, 0x80241C00), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_03, 0x80240940), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_04, 0x80240740), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_05, 0x80241D60), .bgName = "sam_bg" },
    { MAP_UNSPLIT(sam_06, 0x80242630), .bgName = "sam_bg" },
    { MAP_UNSPLIT(sam_07, 0x80242020), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(sam_08, 0x802417D0), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(sam_09, 0x80240420), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(sam_10, 0x80240CE0), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(sam_11, 0x802421A0), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_12, 0x802403B0), .bgName = "yki_bg", .songVariation = 1, .sfxReverb = 1 },
};

/// Crystal Palace
MapConfig pra_maps[] = {
    { MAP_UNSPLIT(pra_01, 0x80241400), .bgName = "yki_bg", .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_02, 0x802416C0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_03, 0x802401E0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_04, 0x80240970), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_05, 0x802411F0), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_06, 0x80240F60), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_09, 0x80241670), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_10, 0x802416D0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_11, 0x802411F0), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_12, 0x80241220), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_13, 0x80241620), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_14, 0x80241200), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_15, 0x80240050), .bgName = "yki_bg", .init = (MapInit)0x80240000, .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(pra_16, 0x80240F60), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_18, 0x80240F50), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_19, 0x802419D0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_20, 0x80240F70), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_21, 0x80240140), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_22, 0x802402F0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_27, 0x80241220), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_28, 0x80241220), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_29, 0x802412C0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_31, 0x802410E0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_32, 0x80240850), .bgName = "sam_bg", .init = (MapInit)0x80240000, .songVariation = 1, .sfxReverb = 1 },
    { MAP_UNSPLIT(pra_33, 0x802410C0), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_34, 0x80241040), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_35, 0x80242C40), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_36, 0x80240F70), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_37, 0x80241840), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_38, 0x80241700), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_39, 0x80241700), .songVariation = 1, .sfxReverb = 2, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_40, 0x80240F40), .songVariation = 1, .sfxReverb = 1, .init = (MapInit)0x80240000 },
};

/// Shy Guy's Toy Box
MapConfig omo_maps[] = {
    { MAP_UNSPLIT(omo_01, 0x80240C40), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_02, 0x80242BD0), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_03, 0x80240900), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_04, 0x80241F30), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_05, 0x80242440), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_06, 0x80240B80), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_07, 0x80243310), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_08, 0x80240E10), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_09, 0x80243700), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_10, 0x802408B0), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_11, 0x802414F0), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_12, 0x802404D0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_13, 0x80241510), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_14, 0x802405E0), .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_15, 0x80240810), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_16, 0x80240620), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
    { MAP_UNSPLIT(omo_17, 0x80243770), .bgName = "omo_bg", .songVariation = 1, .sfxReverb = 2 },
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

const f32 world_rodata_alignment = 0.0f;
