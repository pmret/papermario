#include "mgm_02.h"
#include "hud_element.h"

extern HudScript HudScript_BlueMeter[];
extern HudScript HudScript_AButton[];

extern s32 D_8024273C_E184BC[3][35]; /* configurations */
extern s32 D_802428E0_E18660[35]; /* model IDs */
extern s32 D_8024296C_E186EC[35]; /* collider IDs */
extern s32 D_802429F8_E18778[10]; /* panel model IDs */
extern s32 D_80248600[10]; /* bss */

extern s32 D_802482A0_E1E020;
extern s32 D_802484A0_E1E220;

extern s32 D_802EAFDC; // SIGNPOST
extern s32 D_80242A3C_E187BC[];

#define SCOREKEEPER_ENEMY_IDX 0
#define SMASH_DATA_VAR_IDX 0

#define PLAY_COST 10
#define PLAY_TIME 900

typedef enum SmashGameContentType {
    BOX_CONTENT_FUZZY   = 0,
    BOX_CONTENT_BOMB    = 1,
    BOX_CONTENT_PEACH   = 2,
    BOX_CONTENT_EMPTY   = 3 // luigi???
} JumpGamePanelType;

typedef struct SmashGameBoxData {
/* 0x00 */ s32 state;
/* 0x04 */ s32 stateTimer;
/* 0x08 */ s32 content;
/* 0x0C */ s32 modelID;
/* 0x10 */ s32 colliderID;
/* 0x14 */ s32 npcID;
/* 0x18 */ s32 unk_18;
} SmashGameBoxData; /* size = 0x1C */

typedef struct SmashGameData {
/* 0x000 */ s32 workerID;
/* 0x004 */ s32 found;
/* 0x008 */ s32 timeLeft; /* frames = 30 * seconds */
/* 0x00C */ s32 hudElemID_AButton;
/* 0x010 */ s32 hudElemID_Meter;
/* 0x014 */ s32 windowA_posX;
/* 0x018 */ s32 windowB_posX;
/* 0x01C */ s32 signpostEntity; /* unk entity */
/* 0x020 */ s32 currentScore;
/* 0x024 */ s32 mashProgress;
/* 0x028 */ s32 mashFlags;
/* 0x02C */ SmashGameBoxData arr[35];
} SmashGameData; /* size = 0x400 */

//TODO: matches on decomp.me, but not OK here
INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240000_E15D80);
extern void func_80240000_E15D80(void);
/* N(draw_score_display) */
/*
void func_80240000_E15D80(void) {
    Enemy* scorekeeper = get_enemy(0);
    SmashGameData* data = (SmashGameData*)scorekeeper->varTable[0];
    s32 hudElemA;
    s32 hudElemMeter;
    s32 timeLeft;
    s32 seconds;
    s32 deciseconds;

    // show mash meter while grabbed by a fuzzy
    if ((data->mashFlags & 4)) {
        hudElemA = data->hudElemID_AButton;
        hud_element_set_render_pos(hudElemA, 90, 90);
        hud_element_draw_clipped(hudElemA);
        hudElemMeter = data->hudElemID_Meter;
        hud_element_set_render_pos(hudElemMeter, 90, 120);
        hud_element_draw_clipped(hudElemMeter);
        startup_draw_prim_rect_COPY(62, 116, 62 + (s32)(((f32)data->mashProgress / 12.0) * 59.0), 116 + 5, 0, 228, 134, 255);
    }

   if (scorekeeper->varTable[3] == 0 || scorekeeper->varTable[3] >= 4) {
        if (data->windowA_posX > -80) {
            data->windowA_posX -= 10;
            if (data->windowA_posX < -80) {
                data->windowA_posX = -80;
            }
        }
    } else {
        if (data->windowA_posX < 23) {
            data->windowA_posX += 10;
            if (data->windowA_posX > 23) {
                data->windowA_posX = 23;
            }
        }
    }

    if (scorekeeper->varTable[3] == 0) {
        if (data->windowB_posX < 320) {
            data->windowB_posX += 10;
            if (data->windowB_posX > 320) {
                data->windowB_posX = 320;
            }
        }
    } else {
        if (data->windowB_posX > 225) {
            data->windowB_posX -= 10;
            if (data->windowB_posX < 225) {
                data->windowB_posX = 225;
            }
        }
    }

    draw_box(0, 9, data->windowA_posX, 23, 0, 80, 38, 180, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, 320, 240, NULL);
    draw_msg(0x80047, data->windowA_posX + 42, 28, 255, 0, 0);
    draw_number(10 - data->found, data->windowA_posX + 65, 43, 1, 0, 255, 3);
    draw_ci_image_with_clipping(&D_802482A0_E1E020, 32, 32, G_IM_FMT_CI, G_IM_SIZ_4b, &D_802484A0_E1E220,
        data->windowA_posX + 5, 26, 10, 20, 300, 200, 255);
    
    timeLeft = MIN(data->timeLeft, 900);
    deciseconds = ((f32)(timeLeft % 30) * 10.0) / 30;
    seconds = timeLeft / 30;

    draw_box(0, 0xB, data->windowB_posX, 27, 0, 60, 20, 180, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, 320, 240, NULL);
    // draw whole seconds
    draw_number(seconds, data->windowB_posX + 29, 31, 1, 0, 255, 3);
    // draw tenths of seconds
    draw_number(deciseconds, data->windowB_posX + 40, 31, 1, 0, 255, 0);
    // draw dot
    draw_msg(0x80024, data->windowB_posX + 30, 29, 255, 0, 0);
}
*/

/* N(work_draw_score) */
void func_80240430_E161B0(void) {
    RenderTask task;

    task.renderMode = RENDER_MODE_2D;
    task.appendGfxArg = 0;
    task.appendGfx = &func_80240000_E15D80;
    task.distance = 0;

    queue_render_task(&task);
}

/* N(CreateScoreDisplay) */
ApiStatus func_80240468_E161E8(Evt* script, s32 isInitialCall) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[SMASH_DATA_VAR_IDX];
    s32 hudElemA, hudElemMeter;

    if (isInitialCall) {
        data->workerID = create_generic_entity_world(NULL, &func_80240430_E161B0);

        hudElemA = hud_element_create(&HudScript_AButton);
        data->hudElemID_AButton = hudElemA;
        hud_element_set_render_depth(hudElemA, 0);
        hud_element_set_flags(hudElemA, HUD_ELEMENT_FLAGS_80);
        hud_element_set_tint(hudElemA, 255, 255, 255);
        hud_element_set_script(hudElemA, &HudScript_AButton);
        
        hudElemMeter = hud_element_create(&HudScript_BlueMeter);
        data->hudElemID_Meter = hudElemMeter;
        hud_element_set_render_depth(hudElemMeter, 0);
        hud_element_set_flags(hudElemMeter, HUD_ELEMENT_FLAGS_80);
    }

    return ApiStatus_BLOCK;
}

/* N(DisableMenus) */
ApiStatus func_80240544_E162C4(Evt* script, s32 isInitialCall) {
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_MENUS;
    func_800E9894();
    close_status_menu();
    return ApiStatus_DONE2;
}

/* N(EnableMenus) */
ApiStatus func_80240580_E16300(Evt* script, s32 isInitialCall) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_MENUS;
    return ApiStatus_DONE2;
}

/* N(DestroySignpost) */
ApiStatus func_802405A4_E16324(Evt* script, s32 isInitialCall) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[SMASH_DATA_VAR_IDX];
    delete_entity(data->signpostEntity);
    return ApiStatus_DONE2;
}

/* N(CreateSignpost) */
ApiStatus func_802405D0_E16350(void) {
    SmashGameData* data;
    s32 entityIndex;

    data = (SmashGameData*)get_enemy(0)->varTable[0];
    entityIndex = create_entity(&D_802EAFDC, 355, 20, -180, 0, 0, 0, 0, 0x80000000);
    data->signpostEntity = entityIndex;
    get_entity_by_index(entityIndex)->boundScriptBytecode = &D_80242A3C_E187BC;

    return ApiStatus_DONE2;
}

ApiStatus func_80240644_E163C4(Evt* script, s32 isInitialCall0) {
    SmashGameData* data = (SmashGameData*)get_enemy(0)->varTable[0];
    s32 hitModelID;
    s32 hitColliderID;
    s32 i;

    hitModelID = evt_get_variable(script, LW(0xA));
    hitColliderID = evt_get_variable(script, LW(0xB)); // unused

    for(i = 0; i < 35; i++) {
        if(hitModelID == data->arr[i].modelID)
            break;
    }

    evt_set_variable(script, LW(0xC), data->arr[i].content);

    switch (data->arr[i].content) {                     
    case BOX_CONTENT_FUZZY:
        evt_set_variable(script, LW(0xD), data->arr[i].npcID);
        data->arr[i].state = 0xD;
        break;
    case BOX_CONTENT_BOMB:
        evt_set_variable(script, LW(0xD), data->arr[i].npcID);
        data->arr[i].state = 0x21;
        break;
    case 3:
        evt_set_variable(script, LW(0xD), data->arr[i].npcID);
        data->arr[i].state = 0x34;
        break;
    case BOX_CONTENT_PEACH:
        data->found++;
        data->arr[i].state = 0x49;
        break;
    }
  
    return ApiStatus_DONE2;
}

//TODO: problem with loop at D_80248600, perhaps start at D_80248624 and go backward?
INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240790_E16510);
/*
ApiStatus func_80240790_E16510(Evt* script, s32 isInitialCall) {
    s32 initialConfiguration;
    s32 configuration[35];
    s32 indexA, indexB, temp;
    s32 i, j;

    Enemy* enemy;
    Npc* npc;

    SmashGameData* data = (SmashGameData*)get_enemy(0)->varTable[0];
    data->found = 0;
    data->timeLeft = 910;
    data->currentScore = 0;
    data->mashProgress = 0;
    data->mashFlags = 0;

     // choose one of three initial configurations at random
    initialConfiguration = rand_int(1000) % 3;
    for(i = 0; i < 35; i++) {
        configuration[i] = D_8024273C_E184BC[initialConfiguration][i];
    }

    // randomly swap 10000 pairs
    for(i = 0; i < 10000; i++) {
        indexA = rand_int(1000) % 35;
        indexB = rand_int(1000) % 35;

        if (indexA != indexB) {
            temp = configuration[indexB];
            configuration[indexB] = configuration[indexA];
            configuration[indexA] = temp;
        }
    }

    for(i = 0; i < 35; i++) {
        data->arr[i].state = -1;
        data->arr[i].stateTimer = 0;
        data->arr[i].content = configuration[i];
        data->arr[i].modelID = D_802428E0_E18660[i];
        data->arr[i].colliderID = D_8024296C_E186EC[i];
        data->arr[i].npcID = -1;
        data->arr[i].unk_18 = -1;
    }

    for(i = 0xA; i < 0xF; i++) {
        get_enemy(i)->varTable[0] = 0;
    }

    for(i = 0x1E; i < 0x23; i++) {
        get_enemy(i)->varTable[0] = 0;
    }

    for(i = 0x64; i < 0x6E; i++) {
        get_enemy(i)->varTable[0] = 0;
    }

    for(i = 0; i < ARRAY_COUNT(D_80248600); i++) {
        D_80248600[i] = 0;
    }

    for(i = 0; i < 35; i++) {
        switch(data->arr[i].content) {
            case 0:
                data->arr[i].state = 0xA;
                for(j = 0xA; j < 0xF; j++) {
                    enemy = get_enemy(j);
                    if(enemy->varTable[0] == 0) {
                        npc = get_npc_unsafe(enemy->npcID);
                        enemy->varTable[0] = 1;
                        data->arr[i].npcID = j;
                        disable_npc_shadow(npc);
                        npc->flags |= 2;
                        break;
                    }
                }
                break;
            case 1:
                data->arr[i].state = 0x1E;
                for(j = 0x1E; j < 0x23; j++) {
                    enemy = get_enemy(j);
                    if(enemy->varTable[0] == 0) {
                        npc = get_npc_unsafe(enemy->npcID);
                        enemy->varTable[0] = 1;
                        data->arr[i].npcID = j;
                        disable_npc_shadow(npc);
                        npc->flags |= 2;
                        break;
                    }
                }
                break;
            case 2:
                data->arr[i].state = 0x46;
                for(j = 0x64; j < 0x6E; j++) {
                    enemy = get_enemy(j);
                    if(enemy->varTable[0] == 0) {
                        npc = get_npc_unsafe(enemy->npcID);
                        enemy->varTable[0] = 1;
                        data->arr[i].npcID = j;
                        disable_npc_shadow(npc);
                        npc->flags |= 2;
                        break;
                    }
                }
                // ARRAY BOUNDS ERROR IN ORIGINAL CODE!
                for(j = 0; j <= ARRAY_COUNT(D_80248600); j++) {
                    if(D_80248600[j] == 0) {
                        D_80248600[j] = 1;
                        data->arr[i].unk_18 = D_802429F8_E18778[j];
                        break;
                    }
                }
                break;
            case 3:
                data->arr[i].state = 0x32;
                break;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80240BB0_E16930);

static char* N(exit_str_0) = "mgm_00";

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80241DCC_E17B4C);

/* N(GiveCoinReward) */
ApiStatus func_80241F38_E17CB8(Evt* script, s32 isInitialCall) {
    SmashGameData* data = (SmashGameData*)get_enemy(0)->varTable[0];
    s32 coinsLeft = data->currentScore;
    s32 increment;

    if (coinsLeft > 100) {
        increment = 40;
    } else if (coinsLeft > 75) {
        increment = 35;
    } else if (coinsLeft > 50) {
        increment = 30;
    } else if (coinsLeft > 30) {
        increment = 10;
    } else if (coinsLeft > 20) {
        increment = 5;
    } else if (coinsLeft > 10) {
        increment = 2;
    } else {
        increment = 1;
    }

    data->currentScore -= increment;
    add_coins(increment);
    sfx_play_sound(SOUND_211);

    return (data->currentScore > 0) ? ApiStatus_BLOCK : ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mgm/mgm_02/E15D80", func_80241FE4_E17D64);

/* N(CreateScoreDisplay) */
ApiStatus func_80242274_E17FF4(Evt* script, s32 isInitialCall) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    SmashGameData* data = heap_malloc(sizeof(SmashGameData));
    scorekeeper->varTable[SMASH_DATA_VAR_IDX] = data;

    data->windowA_posX = -80;
    data->windowB_posX = 320;
    data->timeLeft = PLAY_TIME;

    func_800E9894();
    close_status_menu();

    return ApiStatus_DONE2;
}

/* N(DestroyScoreDisplay) */
ApiStatus func_802422D0_E18050(Evt* script, s32 isInitialCall) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[SMASH_DATA_VAR_IDX];

    free_generic_entity(data->workerID);
    hud_element_free(data->hudElemID_AButton);
    hud_element_free(data->hudElemID_Meter);

    return ApiStatus_DONE2;
}

/* N(GetCoinCount) */
ApiStatus func_80242314_E18094(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, LW(10), gPlayerData.coins);
    return ApiStatus_DONE2;
}

/* N(TakeCoinCost) */
ApiStatus func_80242340_E180C0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        playerData->smashGamePlays++;
        script->functionTemp[0] = 0;
    }
    add_coins(-1);
    sfx_play_sound(SOUND_211);

    return (++script->functionTemp[0] == PLAY_COST) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

/* N(HideCoinCounter) */
ApiStatus func_802423A4_E18124(Evt* script, s32 isInitialCall) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}
