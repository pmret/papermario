#include "common.h"
#include "ld_addrs.h"
#include "map.h"

#define ASSET_TABLE_ROM_START 0x1E40000
#define ASSET_TABLE_HEADER_SIZE 0x20
#define ASSET_TABLE_FIRST_ENTRY (ASSET_TABLE_ROM_START + ASSET_TABLE_HEADER_SIZE)

s32 D_8008FF60[] = { 0, 1, 2, 3 };

// rodata
const s32 D_800989A0[] = {
    0x82C882B5, 0x00000000, 0x82A982AD, 0x82B982A2,
    0x00000000, 0x82B982C1, 0x82AB82E5, 0x82A40000,
    0x82DE82C9, 0x82E182DE, 0x82C982E1, 0x00000000,
    0x82D082C6, 0x82E882DA, 0x82AF0000, 0x83748340,
    0x83438369, 0x838B837B, 0x83808377, 0x83430000,
    0x83748340, 0x83438369, 0x838B834E, 0x838A8357,
    0x83430000, 0x82C282A4, 0x82B682E5, 0x82A40000,
};

// bss
extern MapConfig D_800A41E8; // gMapHeader?
extern s32 D_800A41E0; // gMapConfig?


extern s32 D_800D9668;

typedef struct {
    /* 0x00 */ char name[16];
    /* 0x10 */ u32 offset;
    /* 0x14 */ u32 compressedLength;
    /* 0x18 */ u32 decompressedLength;
} AssetHeader; // size = 0x1C

void load_world_script_api(void) {
    dma_copy((s32)&world_script_api_ROM_START, (s32)&world_script_api_ROM_END, &world_script_api_VRAM);
}

void load_map_by_IDs(s16 areaID, s16 mapID, s16 loadType) {
    PlayerStatus* playerStatus;
    GameStatus** gameStatus;
    GameStatus** gameStatus2;
    GameStatus** gameStatus3;
    s32 initStatus;
    Map* map;
    MapConfig* temp800A41E8;
    s32* overrideFlags;
    char texStr[17];
    s32 decompressedSize;

    initStatus = 0;
    sfx_stop_env_sounds();
    OVERRIDE_FLAG_UNSET(0x40);
    OVERRIDE_FLAG_UNSET(0x80);

    gameStatus = &gGameStatusPtr;

    (*gameStatus)->unk_84 = 0;
    func_8002D160();
    func_802B2078();
    func_8011D890();
    clear_dynamic_entity_list();
    clear_script_list();

    switch (loadType) {
        case 0:
            clear_area_flags();
            (*gameStatus)->loadType = 0;
            break;
        case 1:
            fio_deserialize_state();
            areaID = (*gameStatus)->areaID;
            mapID = (*gameStatus)->mapID;
            (*gameStatus)->prevArea = areaID;
            (*gameStatus)->loadType = 1;
            break;
    }

    gGameStatusPtr->mapShop = NULL;

    map = &gAreas[areaID].maps[mapID];

    sprintf(&D_800D9230, "%s_shape", map->id);
    sprintf(&D_800D91E0, "%s_hit", map->id);
    strcpy(texStr, map->id);
    texStr[3] = 0;
    sprintf(&D_800B0CF0, "%s_tex", texStr);

    D_800A41E0 = map;
    if (map->bgName != NULL) {
        strcpy(&D_800D9668, map->bgName);
    }
    load_world_script_api();

    if (map->dmaStart != NULL) {
        dma_copy(map->dmaStart, map->dmaEnd, map->dmaDest);
    }

    temp800A41E8 = &D_800A41E8;
    *temp800A41E8 = *map->config;


    temp800A41E8 = &D_800A41E8;
    if (map->init != 0) {
        initStatus = map->init();
    }

    if (initStatus == 0) {
        s32* place = &D_80210000;
        s32 yay0Asset = load_asset_by_name(&D_800D9230, &decompressedSize);

        decode_yay0(yay0Asset, place);
        general_heap_free(yay0Asset);

        temp800A41E8->modelTreeRoot = place[0];
        temp800A41E8->modelNameList = place[2];
        temp800A41E8->colliderNameList = place[3];
        temp800A41E8->zoneNameList = place[4];
    }

    if (map->bgName != NULL) {
        load_map_bg(&D_800D9668);
    }

    func_8002D160();
    func_802B2078();
    func_80149670(0);
    clear_dynamic_entity_list();
    clear_script_list();
    create_cameras_a();
    gameStatus2 = &gGameStatusPtr;
    func_802DD8F8((*gameStatus2)->unk_84);
    func_8011E224();
    clear_entity_models();
    clear_npcs();
    func_80141100();
    clear_trigger_data();
    clear_model_data();
    func_80148040();
    use_default_background_settings();

    if ((*gameStatus2)->unk_A8 == -1) {
        func_80138188();
    }

    if (initStatus == 0) {
        initialize_collision();
        load_hit_asset();
    }

    func_80072B30();
    clear_encounter_status();
    clear_entity_data(1);
    clear_effect_data();
    clear_player_status();
    func_800DFC74();
    partner_reset_data();
    clear_printers();
    clear_item_entity_data();

    playerStatus = &gPlayerStatus;
    playerStatus->targetYaw = playerStatus->currentYaw;

    func_801497FC(D_8008FF60[map->unk_1C.u32 % 4]);
    sfx_reset_door_sounds();

    if (initStatus == 0) {
        s32 thing = get_asset_offset(&D_800B0CF0, &decompressedSize);

        if (temp800A41E8->modelTreeRoot != NULL) {
            load_data_for_models(temp800A41E8->modelTreeRoot, thing, decompressedSize);
       }
    }

    if (temp800A41E8->background != NULL) {
        read_background_size(temp800A41E8->background);
    } else {
        set_background_size(296, 200, 12, 20);
    }

    gCurrentCameraID = 0;
    gCameras[0].flags |= 0x2;
    gCameras[1].flags |= 0x2;
    gCameras[2].flags |= 0x2;
    gCameras[3].flags |= 0x2;

    if (gGameStatusPtr->unk_A8 == -1) {
        set_cam_viewport(0, 12, 20, 296, 200);
    } else {
        set_cam_viewport(0, 29, 28, 262, 162);
    }

    initialize_status_menu();
    gameStatus3 = &gGameStatusPtr;
    (*gameStatus3)->unk_90 = 1000;
    (*gameStatus3)->unk_92 = 1000;
    (*gameStatus3)->mainScriptID = start_script_in_group(temp800A41E8->main, 0, 0, 0)->id;
}

s32 get_current_map_config() {
    return D_800A41E0;
}

MapConfig* get_current_map_header() {
    return &D_800A41E8;
}

// weirdness with gAreas loading, extra lw
#ifdef NON_MATCHING
s32 get_map_IDs_by_name(const char* mapName, s16* areaID, s16* mapID) {
    s32 i;
    s32 j;

    for (i = 0; (gAreas + i)->maps != NULL; i++) {
        Map* maps = (gAreas + i)->maps;

        for (j = 0; j < (gAreas + i)->mapCount; j++) {
            if (strcmp(maps[j].id, mapName) == 0) {
                *areaID = i;
                *mapID = j;
                return TRUE;
            }
        }
    }

    return FALSE;
}
#else
INCLUDE_ASM(s32, "world/world", get_map_IDs_by_name);
#endif

void* load_asset_by_name(char* assetName, s32* decompressedSize) {
    AssetHeader firstHeader;
    AssetHeader* assetTableBuffer;
    AssetHeader* curAsset;
    void* ret;

    dma_copy(ASSET_TABLE_FIRST_ENTRY, ASSET_TABLE_FIRST_ENTRY + sizeof(AssetHeader), &firstHeader);
    assetTableBuffer = heap_malloc(firstHeader.offset);
    curAsset = &assetTableBuffer[0];
    dma_copy(ASSET_TABLE_FIRST_ENTRY, ASSET_TABLE_FIRST_ENTRY + firstHeader.offset, assetTableBuffer);
    while (strcmp(curAsset->name, assetName) != 0) {
        curAsset++;
   }
    *decompressedSize = curAsset->decompressedLength;
    ret = general_heap_malloc(curAsset->compressedLength);
    dma_copy(ASSET_TABLE_FIRST_ENTRY + curAsset->offset, ASSET_TABLE_FIRST_ENTRY + curAsset->offset + curAsset->compressedLength, ret);
    heap_free(assetTableBuffer);
    return ret;
}

s32 get_asset_offset(char* assetName, s32* compressedSize) {
    AssetHeader firstHeader;
    AssetHeader* assetTableBuffer;
    AssetHeader* curAsset;
    s32 ret;

    dma_copy(ASSET_TABLE_FIRST_ENTRY, ASSET_TABLE_FIRST_ENTRY + sizeof(AssetHeader), &firstHeader);
    assetTableBuffer = heap_malloc(firstHeader.offset);
    curAsset = &assetTableBuffer[0];
    dma_copy(ASSET_TABLE_FIRST_ENTRY, ASSET_TABLE_FIRST_ENTRY + firstHeader.offset, assetTableBuffer);
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
    .config = &map##_config, \
    .dmaStart = &code_##map##_ROM_START, \
    .dmaEnd = &code_##map##_ROM_END, \
    .dmaDest = &code_##map##_VRAM \

// Should be removed once the data section containing .init and .config of all maps have been disassembled
#define MAP_UNSPLIT(map, configVRAM) \
    .id = #map, \
    .config = (MapConfig*)(configVRAM), \
    .dmaStart = &code_##map##_ROM_START, \
    .dmaEnd = &code_##map##_ROM_END, \
    .dmaDest = &code_##map##_VRAM \


// these, along with all the *_maps, almost certainly belong in the next file
s16 D_8008FF70[] = { 4, 6, 5, 4, 7, 6, 0, 3, 4, 3, 7, 4, 3, 2, 7, 2, 6, 7, 2, 1, 6, 1, 5, 6, 1, 0, 5, 0, 4, 5, 0, 1, 2,
                     0, 2, 3};

f32 D_8008FFB8[] = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
                     0.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, -1.0f,
                     0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f };

/// Toad Town
Map mac_maps[] = {
    { MAP_UNSPLIT(machi,  0x802407A0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(mac_00, 0x80243BE0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(mac_01, 0x80246730), .bgName = "nok_bg" },
    { MAP_UNSPLIT(mac_02, 0x80243580), .bgName = "nok_bg" },
    { MAP_UNSPLIT(mac_03, 0x802428B0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(mac_04, 0x80242080), .bgName = "nok_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(mac_05, 0x802441A0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(mac_06, 0x802416A0), .bgName = "nok_bg" },
};

/// Toad Town Tunnels
Map tik_maps[] = {
    { MAP_UNSPLIT(tik_01, 0x80240AE0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_02, 0x802409B0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_03, 0x80240B00), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_04, 0x80240CB0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_05, 0x80240A90), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_06, 0x802409A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_07, 0x80242920), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_08, 0x80240B10), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_09, 0x802412D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_10, 0x802413D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_12, 0x80242260), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_14, 0x80240980), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_15, 0x80240B30), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_17, 0x80241380), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_18, 0x802406D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_19, 0x80241340), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_20, 0x80241170), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_21, 0x80240990), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_22, 0x802409D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_23, 0x80241160), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_24, 0x80240ED0), .init = (MapInit)0x80240000, .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(tik_25, 0x802407D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
};

/// Inside the Whale
Map kgr_maps[] = {
    { MAP_UNSPLIT(kgr_01, 0x80240540), .unk_1C = { .bytes = { .flags = 1 } } },
    { MAP_UNSPLIT(kgr_02, 0x80240790), .unk_1C = { .bytes = { .flags = 1 } } },
};

/// Goomba Region
#include "area_kmr/kmr.h"
Map kmr_maps[] = {
    { MAP_UNSPLIT(kmr_00, 0x80240D80), .bgName = "kmr_bg", .unk_1C = { .bytes = { .flags = 1 } } },
    { MAP_UNSPLIT(kmr_02, 0x80243AF0), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_03, 0x80240680), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_04, 0x80240520), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_05, 0x802417A0), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_06, 0x80241DC0), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_07, 0x80240B70), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_09, 0x80241550), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_10, 0x80240640), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_11, 0x80241180), .bgName = "kmr_bg" },
    { MAP(kmr_12), .bgName = "kmr_bg" },
    { MAP_UNSPLIT(kmr_20, 0x80242C00), .bgName = "kmr_bg" }, // Mario's House
    { MAP_UNSPLIT(kmr_21, 0x802402F0), .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kmr_22, 0x80240DA0), .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kmr_23, 0x80241150), .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kmr_24, 0x80240120), .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kmr_30, 0x802404F0) },
};

/// Mt. Rugged
Map iwa_maps[] = {
    { MAP_UNSPLIT(iwa_00, 0x80240310), .bgName = "iwa_bg" },
    { MAP_UNSPLIT(iwa_01, 0x80243320), .bgName = "iwa_bg" },
    { MAP_UNSPLIT(iwa_02, 0x80241140), .bgName = "iwa_bg" },
    { MAP_UNSPLIT(iwa_03, 0x80241360), .bgName = "iwa_bg" },
    { MAP_UNSPLIT(iwa_04, 0x80241100), .bgName = "iwa_bg" },
    { MAP_UNSPLIT(iwa_10, 0x80241810), .bgName = "iwa_bg" },
    { MAP_UNSPLIT(iwa_11, 0x80240330), .bgName = "iwa_bg" },
};

/// Dry Dry Outpost
Map dro_maps[] = {
    { MAP_UNSPLIT(dro_01, 0x80243B70), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(dro_02, 0x80243AB0), .bgName = "sbk_bg" },
};

/// Dry Dry Desert
Map sbk_maps[] = {
    { MAP_UNSPLIT(sbk_00, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_01, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_02, 0x80240C80), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_03, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_04, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_05, 0x802400B0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_06, 0x802403C0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_10, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_11, 0x802401A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_12, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_13, 0x802401A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_14, 0x80240090), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_15, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_16, 0x802402C0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_20, 0x80240180), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_21, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_22, 0x802401A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_23, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_24, 0x802403D0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_25, 0x802403C0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_26, 0x802403E0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_30, 0x80241870), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_31, 0x80240180), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_32, 0x802401B0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_33, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_34, 0x80240A20), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_35, 0x802403C0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_36, 0x802402C0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_40, 0x80240180), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_41, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_42, 0x80240180), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_43, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_44, 0x802401A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_45, 0x80240090), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_46, 0x802403E0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_50, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_51, 0x802401A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_52, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_53, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_54, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_55, 0x802402E0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_56, 0x80241040), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_60, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_61, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_62, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_63, 0x802400A0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_64, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_65, 0x80240080), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_66, 0x802403C0), .bgName = "sbk_bg" },
    { MAP_UNSPLIT(sbk_99, 0x80240020), .bgName = "sbk_bg" },
};

/// Dry Dry Ruins
Map isk_maps[] = {
    { MAP_UNSPLIT(isk_01, 0x80240020), .bgName = "sbk3_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_02, 0x80240140), .bgName = "sbk3_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_03, 0x80240030), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_04, 0x80240AD0), .bgName = "sbk3_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_05, 0x80241ED0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_06, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_07, 0x80240130), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_08, 0x80240930), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_09, 0x80240340), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_10, 0x80240DE0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_11, 0x802401A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_12, 0x80240040), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_13, 0x80242080), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_14, 0x80241D70), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_16, 0x80240B20), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_18, 0x80240910), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(isk_19, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
};

/// Koopa Bros. Fortress
Map trd_maps[] = {
    { MAP_UNSPLIT(trd_00, 0x80240690), .bgName = "nok_bg" },
    { MAP_UNSPLIT(trd_01, 0x80241700), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_02, 0x80241AA0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_03, 0x80240A40), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_04, 0x80243900), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_05, 0x802407B0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_06, 0x80240D60), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_07, 0x80242910), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_08, 0x80240A30), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(trd_09, 0x80240200), .bgName = "nok_bg" },
    { MAP_UNSPLIT(trd_10, 0x80240870), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
};

/// Koopa Region
Map nok_maps[] = {
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
Map hos_maps[] = {
    { MAP_UNSPLIT(hos_00, 0x80240D50), .bgName = "nok_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(hos_01, 0x80240E40), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_02, 0x80242B90), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_03, 0x802435F0), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_04, 0x80240EE0), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_05, 0x80245910), .bgName = "hos_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(hos_06, 0x80242570), .bgName = "hos_bg" },
    { MAP_UNSPLIT(hos_10, 0x80240CE0), .bgName = "hos_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(hos_20, 0x80240390), .bgName = "hos_bg" },
};

/// Bowser's Castle
Map kpa_maps[] = {
    { MAP_UNSPLIT(kpa_01,  0x80240A70), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_03,  0x80241EE0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_04,  0x80240190), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_08,  0x802414C0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_09,  0x80241310), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_10,  0x80240360), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_11,  0x80240B40), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_12,  0x802404A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_13,  0x802404A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_14,  0x802408A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_15,  0x802405E0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_16,  0x802403B0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_17,  0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_32,  0x80240350), .bgName = "kpa_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_33,  0x80240350), .bgName = "kpa_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_40,  0x80240040), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_41,  0x80240040), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_50,  0x80241A40), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_51,  0x80241C40), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_52,  0x80241360), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_53,  0x80240190), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_60,  0x80240450), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kpa_61,  0x80242360), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kpa_62,  0x80240430), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kpa_63,  0x802401B0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_70,  0x80240B10), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_81,  0x80240480), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_82,  0x80240460), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_83,  0x80240090), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_90,  0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_91,  0x80241920), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_94,  0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_95,  0x80241920), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_96,  0x80240040), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(kpa_100, 0x80240060), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_101, 0x80240060), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_102, 0x802435B0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_111, 0x802413E0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_112, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_113, 0x80240AD0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_114, 0x80240070), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kpa_115, 0x802413F0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_116, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_117, 0x80240010), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(kpa_118, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_119, 0x80240010), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(kpa_121, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kpa_130, 0x80240760), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_133, 0x802404B0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kpa_134, 0x80240740), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
};

/// Peach's Castle Grounds
Map osr_maps[] = {
    { MAP_UNSPLIT(osr_00, 0x802407E0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(osr_01, 0x80240B00), .bgName = "nok_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(osr_02, 0x80240170), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(osr_03, 0x802403F0), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(osr_04, 0x802400D0), .bgName = "nok_bg", .init = (MapInit)0x80240000 },
};

/// Peach's Castle
/// @bug There are two entries for kkj_26; the latter is unreachable.
Map kkj_maps[] = {
    { MAP_UNSPLIT(kkj_00, 0x80241030), .bgName = "nok_bg", .init = (MapInit)0x80240000, .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kkj_01, 0x80240F10), .bgName = "nok_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kkj_02, 0x80240030), .bgName = "nok_bg", .unk_1C = { .bytes = { .flags = 2 } } },
    { MAP_UNSPLIT(kkj_03, 0x80240360), .bgName = "nok_bg", .unk_1C = { .bytes = { .flags = 3 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_10, 0x80241120), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kkj_11, 0x80241160), .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } } },
    { MAP_UNSPLIT(kkj_12, 0x802408D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kkj_13, 0x802407A0), .bgName = "kpa_bg",  .unk_1C = { .bytes = { .songVariation = 1, .flags = 3 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_14, 0x80240580), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_15, 0x80240640) },
    { MAP_UNSPLIT(kkj_16, 0x80241090), .unk_1C = { .bytes = { .flags = 1 } } },
    { MAP_UNSPLIT(kkj_17, 0x802405B0) },
    { MAP_UNSPLIT(kkj_18, 0x80240830), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kkj_19, 0x80240D20) },
    { MAP_UNSPLIT(kkj_20, 0x80240600) },
    { MAP_UNSPLIT(kkj_21, 0x80240010), .unk_1C = { .bytes = { .flags = 1 } } },
    { MAP_UNSPLIT(kkj_22, 0x80240020), .bgName = "kpa_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kkj_23, 0x802409F0), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_24, 0x80240040), .bgName = "kpa_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kkj_25, 0x80240F50), .bgName = "kpa_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(kkj_26, 0x80240070), .bgName = "kpa_bg" },
    { MAP_UNSPLIT(kkj_26, 0x80240070), .unk_1C = { .bytes = { .flags = 2 } } },
    { MAP_UNSPLIT(kkj_27, 0x802404C0), .unk_1C = { .bytes = { .flags = 1 } } },
    { MAP_UNSPLIT(kkj_28, 0x80240010), .unk_1C = { .bytes = { .flags = 1 } } },
    { MAP_UNSPLIT(kkj_29, 0x80240080), .unk_1C = { .bytes = { .flags = 1 } } },
};

/// Jade Jungle
Map jan_maps[] = {
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
    { MAP_UNSPLIT(jan_11, 0x80240810), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(jan_12, 0x80241280), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(jan_13, 0x802405F0), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(jan_14, 0x80241300), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(jan_15, 0x80240320), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(jan_16, 0x80240590), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(jan_17, 0x80240040), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(jan_18, 0x80240020), .bgName = "yos_bg" },
    { MAP_UNSPLIT(jan_19, 0x80240040), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(jan_22, 0x802419A0), .bgName = "jan_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(jan_23, 0x80240010), .bgName = "yos_bg" },
};

/// Forever Forest
Map mim_maps[] = {
    { MAP_UNSPLIT(mim_01, 0x80241EF0), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_02, 0x80241220), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_03, 0x80240570), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_04, 0x80241170), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_05, 0x80241A60), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_06, 0x80242D70), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_07, 0x802410D0), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_08, 0x80242F80), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_09, 0x80240F00), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_10, 0x802401B0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(mim_11, 0x80240C20), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(mim_12, 0x80240600), .bgName = "arn_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
};

/// Boo's Mansion
Map obk_maps[] = {
    { MAP_UNSPLIT(obk_01, 0x802411B0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(obk_02, 0x802402E0), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(obk_03, 0x80241020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(obk_04, 0x80240E90), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(obk_05, 0x802409F0), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(obk_06, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(obk_07, 0x80241BA0), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(obk_08, 0x802417B0), .bgName = "obk_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(obk_09, 0x80240460), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
};

/// Gusty Gulch
Map arn_maps[] = {
    { MAP_UNSPLIT(arn_02, 0x80241000), .bgName = "arn_bg" },
    { MAP_UNSPLIT(arn_03, 0x80241740), .bgName = "arn_bg" },
    { MAP_UNSPLIT(arn_04, 0x80243390), .bgName = "arn_bg" },
    { MAP_UNSPLIT(arn_05, 0x80241320), .bgName = "arn_bg" },
    { MAP_UNSPLIT(arn_07, 0x80241ED0), .bgName = "arn_bg" },
    { MAP_UNSPLIT(arn_08, 0x802402C0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(arn_09, 0x80240060), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(arn_10, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(arn_11, 0x80240010), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(arn_12, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(arn_13, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
};

/// Tubba Blubba's Castle
Map dgb_maps[] = {
    { MAP_UNSPLIT(dgb_00, 0x802400D0), .bgName = "arn_bg", .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(dgb_01, 0x80243460), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_02, 0x80241470), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_03, 0x80242830), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_04, 0x80243130), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_05, 0x802414A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_06, 0x802402E0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_07, 0x80241450), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_08, 0x80243CB0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_09, 0x80243840), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_10, 0x80240210), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_11, 0x80240090), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_12, 0x802402D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_13, 0x80240010), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_14, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_15, 0x802418A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_16, 0x80241440), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_17, 0x80240020), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(dgb_18, 0x80241280), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
};

/// Mt. Lavalava
Map kzn_maps[] = {
    { MAP_UNSPLIT(kzn_01, 0x80240330), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_02, 0x80242850), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_03, 0x802430E0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_04, 0x80241770), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_05, 0x80240330), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_06, 0x80240AA0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_07, 0x80242320), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_08, 0x80244130), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_09, 0x80243A40), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_10, 0x802406F0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_11, 0x80242680), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_17, 0x802430C0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_18, 0x802403F0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_19, 0x80241D70), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_20, 0x80240AE0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_22, 0x802403A0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(kzn_23, 0x80240630), .bgName = "yos_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
};

/// Flower Fields
Map flo_maps[] = {
    { MAP_UNSPLIT(flo_00, 0x80241490), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_03, 0x80240660), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_07, 0x80240760), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_08, 0x80241F00), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_09, 0x80241840), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_10, 0x802414A0), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_11, 0x802403A0), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_12, 0x80240710), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_13, 0x80243690), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_14, 0x802423B0), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_15, 0x80240020), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_16, 0x80242990), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_17, 0x80243240), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_18, 0x802407F0), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_19, 0x80240980), .bgName = "sra_bg" },
    { MAP_UNSPLIT(flo_21, 0x80240D00), .bgName = "sra_bg" },
    { MAP_UNSPLIT(flo_22, 0x802402A0), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_23, 0x80240CF0), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_24, 0x802405C0), .bgName = "fla_bg" },
    { MAP_UNSPLIT(flo_25, 0x802422F0), .bgName = "fla_bg" },
};

/// Shiver Region
Map sam_maps[] = {
    { MAP_UNSPLIT(sam_01, 0x80241F70), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_02, 0x80241C00), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_03, 0x80240940), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_04, 0x80240740), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_05, 0x80241D60), .bgName = "sam_bg" },
    { MAP_UNSPLIT(sam_06, 0x80242630), .bgName = "sam_bg" },
    { MAP_UNSPLIT(sam_07, 0x80242020), .bgName = "yki_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(sam_08, 0x802417D0), .bgName = "yki_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(sam_09, 0x80240420), .bgName = "yki_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(sam_10, 0x80240CE0), .bgName = "yki_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(sam_11, 0x802421A0), .bgName = "yki_bg" },
    { MAP_UNSPLIT(sam_12, 0x802403B0), .bgName = "yki_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
};

/// Crystal Palace
Map pra_maps[] = {
    { MAP_UNSPLIT(pra_01, 0x80241400), .bgName = "yki_bg", .unk_1C = { .bytes = { .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_02, 0x802416C0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_03, 0x802401E0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_04, 0x80240970), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_05, 0x802411F0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_06, 0x80240F60), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_09, 0x80241670), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_10, 0x802416D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_11, 0x802411F0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_12, 0x80241220), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_13, 0x80241620), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_14, 0x80241200), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_15, 0x80240050), .bgName = "yki_bg", .init = (MapInit)0x80240000, .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(pra_16, 0x80240F60), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_18, 0x80240F50), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_19, 0x802419D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_20, 0x80240F70), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_21, 0x80240140), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_22, 0x802402F0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_27, 0x80241220), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_28, 0x80241220), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_29, 0x802412C0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_31, 0x802410E0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_32, 0x80240850), .bgName = "sam_bg", .init = (MapInit)0x80240000, .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } } },
    { MAP_UNSPLIT(pra_33, 0x802410C0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_34, 0x80241040), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_35, 0x80242C40), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_36, 0x80240F70), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_37, 0x80241840), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_38, 0x80241700), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_39, 0x80241700), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } }, .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(pra_40, 0x80240F40), .unk_1C = { .bytes = { .songVariation = 1, .flags = 1 } }, .init = (MapInit)0x80240000 },
};

/// Shy Guy's Toy Box
Map omo_maps[] = {
    { MAP_UNSPLIT(omo_01, 0x80240C40), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_02, 0x80242BD0), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_03, 0x80240900), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_04, 0x80241F30), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_05, 0x80242440), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_06, 0x80240B80), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_07, 0x80243310), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_08, 0x80240E10), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_09, 0x80243700), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_10, 0x802408B0), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_11, 0x802414F0), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_12, 0x802404D0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_13, 0x80241510), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_14, 0x802405E0), .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_15, 0x80240810), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_16, 0x80240620), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
    { MAP_UNSPLIT(omo_17, 0x80243770), .bgName = "omo_bg", .unk_1C = { .bytes = { .songVariation = 1, .flags = 2 } } },
};

/// Debug
Map tst_maps[] = {
    { MAP_UNSPLIT(tst_01, 0x802400B0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_02, 0x802400B0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_03, 0x802400B0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_04, 0x80240740), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_10, 0x80240040), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_11, 0x80240780), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_12, 0x80240010), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_13, 0x802403D0), .bgName = "nok_bg" },
    { MAP_UNSPLIT(tst_20, 0x80240010), .bgName = "nok_bg" },
};

/// Credits
Map end_maps[] = {
    { MAP_UNSPLIT(end_00, 0x80242B50), .init = (MapInit)0x80240000 },
    { MAP_UNSPLIT(end_01, 0x80243000), .init = (MapInit)0x80240000 },
};

/// Toad Town Playroom
Map mgm_maps[] = {
    { MAP_UNSPLIT(mgm_00, 0x80241810) },
    { MAP_UNSPLIT(mgm_01, 0x802417C0) },
    { MAP_UNSPLIT(mgm_02, 0x80242410) },
    { MAP_UNSPLIT(mgm_03, 0x80240010) },
};

/// Game Over
Map gv_maps[] = {
    { MAP_UNSPLIT(gv_01, 0x802407D0) },
};

Area gAreas[] = {
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
