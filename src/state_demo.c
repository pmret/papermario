#include "common.h"

typedef struct DemoSceneData {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ u16 entryID;
    /* 0x4 */ char unk_4;
    /* 0x5 */ s8 partnerID;
    /* 0x6 */ s8 unk_6;
    /* 0x7 */ char unk_7;
    /* 0x8 */ char* mapName;
} DemoSceneData; // size = 0xC;

// rodata for below map names
// the compiler deduplicates the two identical map name strings, but it's removing the wrong one
const char D_800983F8[] = {
    "end\0kkj_26\0\0arn_08\0\0kkj_11\0\0nok_02\0\0mac_03\0\0kzn_02\0\0mac_00\0\0jan_04\0\0trd_09\0\0tik_03\0\0isk_04\0\0nok_12\0\0"
};

DemoSceneData D_80077AE0[20] = {
    { .unk_0 = 0, .entryID = 2, .unk_4 = 0, .partnerID = PARTNER_GOOMBARIO, .unk_6 = 0x9D, .mapName = &D_800983F8[0x5C] },
    { .unk_0 = 2, .entryID = 0, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0 },
    { .unk_0 = 0, .entryID = 5, .unk_4 = 0, .partnerID = PARTNER_PARAKARRY, .unk_6 = 0x9D, .mapName = &D_800983F8[0x54] },
    { .unk_0 = 0, .entryID = 2, .unk_4 = 0, .partnerID = PARTNER_KOOPER, .unk_6 = 0x9D, .mapName = &D_800983F8[0x4C] },
    { .unk_0 = 0, .entryID = 2, .unk_4 = 0, .partnerID = PARTNER_PARAKARRY, .unk_6 = 0xB3, .mapName = &D_800983F8[0x44] },
    { .unk_0 = 0, .entryID = 4, .unk_4 = 0, .partnerID = PARTNER_SUSHIE, .unk_6 = 0x9D, .mapName = &D_800983F8[0x3C] },
    { .unk_0 = 2, .entryID = 1, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0x00 },
    { .unk_0 = 0, .entryID = 6, .unk_4 = 0, .partnerID = PARTNER_BOMBETTE, .unk_6 = 0x9D, .mapName = &D_800983F8[0x34] },
    { .unk_0 = 0, .entryID = 2, .unk_4 = 0, .partnerID = PARTNER_KOOPER, .unk_6 = 0x1B, .mapName = &D_800983F8[0x2C] },
    { .unk_0 = 2, .entryID = 2, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0x00 },
    { .unk_0 = 0, .entryID = 3, .unk_4 = 0, .partnerID = PARTNER_BOMBETTE, .unk_6 = 0x9D, .mapName = &D_800983F8[0x24] },
    { .unk_0 = 0, .entryID = 4, .unk_4 = 0, .partnerID = PARTNER_GOOMBARIO, .unk_6 = 0x9D, .mapName = &D_800983F8[0x1C] },
    { .unk_0 = 2, .entryID = 3, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0x00 },
    { .unk_0 = 1, .entryID = 8, .unk_4 = 0, .partnerID = PARTNER_TWINK, .unk_6 = 0x26, .mapName = &D_800983F8[0x14] },
    { .unk_0 = 0, .entryID = 2, .unk_4 = 0, .partnerID = PARTNER_BOW, .unk_6 = 0xE8, .mapName = &D_800983F8[0xC] },
    { .unk_0 = 2, .entryID = 4, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0x00 },
    { .unk_0 = 0, .entryID = 3, .unk_4 = 0, .partnerID = PARTNER_GOOMBARIO, .unk_6 = 0x9D, .mapName = &D_800983F8[0x5C] },
    { .unk_0 = 1, .entryID = 3, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0x9D, .mapName = &D_800983F8[4] },
    { .unk_0 = 3, .entryID = 0, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0x00, .mapName = &D_800983F8[0] },
    { .unk_0 = 0, .entryID = 0, .unk_4 = 0, .partnerID = PARTNER_NONE, .unk_6 = 0x00, },
};

char versionString[] = "Prg Ver.00/12/05 16:54";

void state_init_demo(void) {
    if (gGameStatusPtr->demoState == 0) {
        gGameStatusPtr->nextDemoScene = 0;
        gGameStatusPtr->demoState = 1;
    }

    gGameStatusPtr->demoButtonInput = 0;
    gGameStatusPtr->demoStickX = 0;
    gGameStatusPtr->demoStickY = 0;

    func_80056228();
    set_map_transition_effect(2);
    set_screen_overlay_params_front(0, 255.0f);
    clear_saved_variables();
    clear_script_list();
}

void state_step_demo(void) {
    PlayerData* playerData = &gPlayerData;
    DemoSceneData* demoSceneData = &D_80077AE0[gGameStatusPtr->nextDemoScene];
    s16 mode = demoSceneData->unk_0;
    s16 mapID;
    s16 areaID;

    if (gGameStatusPtr->demoState == 4) {
        mode = 3;
    }
    if (gGameStatusPtr->demoState == 5) {
        mode = 4;
    }

    switch (mode) {
        case 3:
            intro_logos_set_fade_alpha(255);
            intro_logos_set_fade_color(224);
            gGameStatusPtr->loadMenuState = 3;
            gOverrideFlags |= 8;
            intro_logos_update_fade();
            gGameStatusPtr->demoState = 5;
            break;
        case 4:
            if (gGameStatusPtr->loadMenuState != 0) {
                gGameStatusPtr->loadMenuState--;
            }

            if (gGameStatusPtr->loadMenuState == 0) {
                gGameStatusPtr->nextDemoScene = 0;
                gGameStatusPtr->demoState = 0;
                gGameStatusPtr->peachFlags = 0;
                func_80056204();
                gGameStatusPtr->isBattle = 0;
                gGameStatusPtr->unk_76 = 0;
                gGameStatusPtr->disableScripts = 0;
                gGameStatusPtr->unk_7D = 0;
                gOverrideFlags &= -9;
                general_heap_create(&gOverrideFlags);
                clear_render_tasks();
                clear_generic_entity_list();
                clear_script_list();
                create_cameras_a();
                spr_init_sprites(0);
                clear_entity_models();
                clear_animator_list();
                clear_model_data();
                clear_sprite_shading_data();
                reset_background_settings();
                clear_hud_element_cache();
                clear_trigger_data();
                clear_printers();
                clear_entity_data(0);
                clear_screen_overlays();
                clear_player_status();
                clear_npcs();
                clear_player_data();
                reset_battle_status();
                init_encounter_status();
                clear_effect_data();
                clear_item_entity_data();
                clear_saved_variables();
                initialize_collision();
                set_game_mode(2);
            }
            return;
        case 0:
            get_map_IDs_by_name(demoSceneData->mapName, &areaID, &mapID);
            gGameStatusPtr->areaID = areaID;
            gGameStatusPtr->mapID = mapID;
            gGameStatusPtr->entryID = demoSceneData->entryID;
            gGameStatusPtr->peachFlags = 0;
            playerData->currentPartner = demoSceneData->partnerID;
            set_cam_viewport(0, 29, 20, -262, 177);
            evt_set_variable(NULL, EVT_STORY_PROGRESS, demoSceneData->unk_6);

            if (gGameStatusPtr->nextDemoScene == 0) {
                set_map_transition_effect(3);
            } else {
                set_map_transition_effect(2);
            }

            set_game_mode(3);
            break;
        case 1:
            get_map_IDs_by_name(demoSceneData->mapName, &areaID, &mapID);
            gGameStatusPtr->areaID = areaID;
            gGameStatusPtr->mapID = mapID;
            gGameStatusPtr->entryID = demoSceneData->entryID;
            gGameStatusPtr->peachFlags = 1;
            playerData->currentPartner = demoSceneData->partnerID;
            set_cam_viewport(0, 29, 20, -262, 177);
            evt_set_variable(NULL, EVT_STORY_PROGRESS, demoSceneData->unk_6);

            if (gGameStatusPtr->nextDemoScene == 0) {
                set_map_transition_effect(3);
            } else {
                set_map_transition_effect(2);
            }

            set_game_mode(3);
            break;
        case 2:
            load_demo_battle(demoSceneData->entryID);
            break;
    }

    gGameStatusPtr->nextDemoScene += 1;
    if (gGameStatusPtr->nextDemoScene > 0x12) {
        gGameStatusPtr->nextDemoScene = 0x12;
    }
}

void state_drawUI_demo(void) {

}

static const f32 pad[] = {0.0f, 0.0f};
