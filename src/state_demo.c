#include "common.h"
#include "hud_element.h"
#include "battle/battle.h"
#include "sprite.h"
#include "game_modes.h"

typedef struct DemoSceneData {
    /* 0x0 */ s16 sceneType;
    /* 0x2 */ u16 index; // entryID for WORLD, battle index for BATTLE
    /* 0x4 */ char unk_4;
    /* 0x5 */ s8 partnerID;
    /* 0x6 */ s8 storyProgress;
    /* 0x7 */ char unk_7;
    /* 0x8 */ char* mapName;
} DemoSceneData; // size = 0xC;

enum DemoSceneType {
    DEMO_SCENE_WORLD        = 0,
    DEMO_SCENE_PEACH        = 1,
    DEMO_SCENE_BATTLE       = 2,
    DEMO_SCENE_DONE         = 3,
    DEMO_SCENE_EXIT         = 4,
};

DemoSceneData DemoScenes[] = {
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "nok_12",
        .index = nok_12_ENTRY_2,
        .partnerID = PARTNER_GOOMBARIO,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_BATTLE,
        .index = 0
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "isk_04",
        .index = isk_04_ENTRY_5,
        .partnerID = PARTNER_PARAKARRY,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "tik_03",
        .index = tik_03_ENTRY_2,
        .partnerID = PARTNER_KOOPER,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "trd_09",
        .index = trd_09_ENTRY_2,
        .partnerID = PARTNER_PARAKARRY,
        .storyProgress = STORY_CH1_STAR_SPIRIT_RESCUED
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "jan_04",
        .index = jan_04_ENTRY_4,
        .partnerID = PARTNER_SUSHIE,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_BATTLE,
        .index = 1
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "mac_00",
        .index = mac_00_ENTRY_6,
        .partnerID = PARTNER_BOMBETTE,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "kzn_02",
        .index = kzn_02_ENTRY_2,
        .partnerID = PARTNER_KOOPER,
        .storyProgress = STORY_CH5_LAVA_STREAM_BLOCKED
    },
    {
        .sceneType = DEMO_SCENE_BATTLE,
        .index = 2
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "mac_03",
        .index = mac_03_ENTRY_3,
        .partnerID = PARTNER_BOMBETTE,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "nok_02" ,
        .index = nok_02_ENTRY_4,
        .partnerID = PARTNER_GOOMBARIO,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_BATTLE,
        .index = 3
    },
    {
        .sceneType = DEMO_SCENE_PEACH,
        .mapName = "kkj_11",
        .index = kkj_11_ENTRY_8,
        .partnerID = PARTNER_TWINK,
        .storyProgress = STORY_CH5_BEGAN_PEACH_MISSION
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "arn_08",
        .index = arn_08_ENTRY_2,
        .partnerID = PARTNER_BOW,
        .storyProgress = STORY_CH3_UNLOCKED_WINDY_MILL
    },
    {
        .sceneType = DEMO_SCENE_BATTLE,
        .index = 4
    },
    {
        .sceneType = DEMO_SCENE_WORLD,
        .mapName = "nok_12",
        .index = nok_12_ENTRY_3,
        .partnerID = PARTNER_GOOMBARIO,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    {
        .sceneType = DEMO_SCENE_PEACH,
        .mapName = "kkj_26",
        .index = kkj_26_ENTRY_3,
        .partnerID = PARTNER_NONE,
        .storyProgress = STORY_CH1_KNOCKED_SWITCH_FROM_TREE
    },
    [LAST_DEMO_SCENE_IDX] {
        .sceneType = DEMO_SCENE_DONE,
        .mapName = "end"
    },
    {} // final entry blank
};

void state_init_demo(void) {
    if (gGameStatusPtr->demoState == DEMO_STATE_NONE) {
        gGameStatusPtr->nextDemoScene = 0;
        gGameStatusPtr->demoState = DEMO_STATE_ACTIVE;
    }

    gGameStatusPtr->demoButtonInput = 0;
    gGameStatusPtr->demoStickX = 0;
    gGameStatusPtr->demoStickY = 0;

    disable_sounds();
    set_map_transition_effect(TRANSITION_END_DEMO_SCENE_BLACK);
    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, 255.0f);
    clear_saved_variables();
    clear_script_list();
}

void state_step_demo(void) {
    PlayerData* playerData = &gPlayerData;
    DemoSceneData* demoSceneData = &DemoScenes[gGameStatusPtr->nextDemoScene];
    s16 mode = demoSceneData->sceneType;
    s16 mapID;
    s16 areaID;

    if (gGameStatusPtr->demoState == DEMO_STATE_4) {
        mode = DEMO_SCENE_DONE;
    }
    if (gGameStatusPtr->demoState == DEMO_STATE_DONE) {
        mode = DEMO_SCENE_EXIT;
    }

    switch (mode) {
        case DEMO_SCENE_DONE:
            startup_set_fade_screen_alpha(255);
            startup_set_fade_screen_color(224);
            gGameStatusPtr->startupState = 3;
            gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
            startup_fade_screen_update();
            gGameStatusPtr->demoState = DEMO_STATE_DONE;
            break;
        case DEMO_SCENE_EXIT:
            if (gGameStatusPtr->startupState != 0) {
                gGameStatusPtr->startupState--;
            }

            if (gGameStatusPtr->startupState == 0) {
                gGameStatusPtr->nextDemoScene = 0;
                gGameStatusPtr->demoState = DEMO_STATE_NONE;
                gGameStatusPtr->peachFlags = 0;
                enable_sounds();
                gGameStatusPtr->isBattle = FALSE;
                gGameStatusPtr->debugUnused1 = FALSE;
                gGameStatusPtr->debugScripts = DEBUG_SCRIPTS_NONE;
                gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_DRAW_FRAME;
                general_heap_create();
                clear_render_tasks();
                clear_worker_list();
                clear_script_list();
                create_cameras_a();
                spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
                clear_entity_models();
                clear_animator_list();
                clear_model_data();
                clear_sprite_shading_data();
                reset_background_settings();
                hud_element_clear_cache();
                clear_trigger_data();
                clear_printers();
                clear_entity_data(FALSE);
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
                set_game_mode(GAME_MODE_TITLE_SCREEN);
            }
            return;
        case DEMO_SCENE_WORLD:
            get_map_IDs_by_name(demoSceneData->mapName, &areaID, &mapID);
            gGameStatusPtr->areaID = areaID;
            gGameStatusPtr->mapID = mapID;
            gGameStatusPtr->entryID = demoSceneData->index;
            gGameStatusPtr->peachFlags = 0;
            playerData->curPartner = demoSceneData->partnerID;
            set_cam_viewport(CAM_DEFAULT, 29, 20, -262, 177);
            evt_set_variable(NULL, GB_StoryProgress, demoSceneData->storyProgress);

            if (gGameStatusPtr->nextDemoScene == 0) {
                set_map_transition_effect(TRANSITION_END_DEMO_SCENE_WHITE);
            } else {
                set_map_transition_effect(TRANSITION_END_DEMO_SCENE_BLACK);
            }

            set_game_mode(GAME_MODE_ENTER_DEMO_WORLD);
            break;
        case DEMO_SCENE_PEACH:
            get_map_IDs_by_name(demoSceneData->mapName, &areaID, &mapID);
            gGameStatusPtr->areaID = areaID;
            gGameStatusPtr->mapID = mapID;
            gGameStatusPtr->entryID = demoSceneData->index;
            gGameStatusPtr->peachFlags = PEACH_FLAG_IS_PEACH;
            playerData->curPartner = demoSceneData->partnerID;
            set_cam_viewport(CAM_DEFAULT, 29, 20, -262, 177);
            evt_set_variable(NULL, GB_StoryProgress, demoSceneData->storyProgress);

            if (gGameStatusPtr->nextDemoScene == 0) {
                set_map_transition_effect(TRANSITION_END_DEMO_SCENE_WHITE);
            } else {
                set_map_transition_effect(TRANSITION_END_DEMO_SCENE_BLACK);
            }

            set_game_mode(GAME_MODE_ENTER_DEMO_WORLD);
            break;
        case DEMO_SCENE_BATTLE:
            load_demo_battle(demoSceneData->index);
            break;
    }

    gGameStatusPtr->nextDemoScene++;
    if (gGameStatusPtr->nextDemoScene > LAST_DEMO_SCENE_IDX) {
        gGameStatusPtr->nextDemoScene = LAST_DEMO_SCENE_IDX;
    }
}

void state_drawUI_demo(void) {

}

#if VERSION_JP
char versionString[] = "Prg Ver.00/07/06 22:22";
#elif VERSION_US
char versionString[] = "Prg Ver.00/12/05 16:54";
#elif VERSION_IQUE
char versionString[] = "Prg Ver.04/05/18 10:52";
#else
char versionString[] = "Prg Ver.??/??/?? ??:??";
#endif

static const f32 pad[] = {0.0f, 0.0f};
