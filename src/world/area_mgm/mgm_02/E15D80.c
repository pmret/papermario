#include "mgm_02.h"
#include "hud_element.h"
#include "effects.h"
#include "model.h"
#include "entity.h"
#include "sprite/npc/bob_omb.h"
#include "sprite/npc/fuzzy.h"

void startup_draw_prim_rect_COPY(s16 left, s16 top, s16 right, s16 bottom, u16 r, u16 g, u16 b, u16 a);
void delete_entity(s32);
void partner_enable_input(void);

#define SCOREKEEPER_ENEMY_IDX 0
#define SMASH_DATA_VAR_IDX 0

#define PLAY_COST   10
#define PLAY_TIME   900
#define NUM_BOXES   35
#define NUM_PANELS  10

#define SMASH_DATA_VAR_IDX 0
#define SMASH_DATA_VAR_IDX 0

#define FUZZY_NPC_ID_BASE  0x0A
#define BOBOMB_NPC_ID_BASE 0x1E
#define LUIGI_NPC_ID_BASE  0x64

extern HudScript HES_BlueMeter;
extern HudScript HES_AButton;
extern HudScript HES_MashAButton;

extern s32 mgm_02_InitialConfigurations[3][NUM_BOXES];
extern s32 mgm_02_BoxModelIDs[NUM_BOXES];
extern s32 mgm_02_BoxColliderIDs[NUM_BOXES];
extern s32 mgm_02_PanelModelIDs[NUM_PANELS];
extern s32 D_80248600[NUM_PANELS]; //TODO set name: mgm_02_PanelModelsAssigned

extern IMG_BIN mgm_02_PeachPanelImg;
extern PAL_BIN mgm_02_PeachPanelPal;

extern EvtScript D_80242A3C_E187BC; // EVT_ReadSign

typedef enum SmashGameBoxCotent {
    BOX_CONTENT_FUZZY       = 0,
    BOX_CONTENT_BOMB        = 1,
    BOX_CONTENT_PEACH       = 2,
    BOX_CONTENT_EMPTY       = 3
} SmashGameBoxCotent;

typedef enum SmashGameStunFlags {
    STUN_FLAGS_STUNNED      = 1,
    STUN_FLAGS_CHANGED      = 2,
    STUN_FLAGS_GRABBED      = 4
} SmashGameStunFlags;

typedef enum SmashGameBoxState {
    BOX_STATE_FUZZY_INIT    = 10,
    BOX_STATE_FUZZY_IDLE    = 11,
    BOX_STATE_FUZZY_POPUP   = 12,
    BOX_STATE_FUZZY_HIT     = 13,
    BOX_STATE_FUZZY_ATTACH  = 14,
    BOX_STATE_FUZZY_GRAB    = 15,
    BOX_STATE_FUZZY_DETACH  = 16,
    BOX_STATE_FUZZY_DONE    = 17,
    BOX_STATE_FUZZY_END     = 18,

    BOX_STATE_BOMB_INIT     = 30,
    BOX_STATE_BOMB_IDLE     = 31,
    BOX_STATE_BOMB_POPUP    = 32,
    BOX_STATE_BOMB_HIT      = 33,
    BOX_STATE_BOMB_ATTACK   = 34,
    BOX_STATE_BOMB_STUN     = 35,
    BOX_STATE_BOMB_DONE     = 36,
    BOX_STATE_BOMB_END      = 37,

    BOX_STATE_EMPTY_INIT    = 50,
    BOX_STATE_EMPTY_IDLE    = 51,
    BOX_STATE_EMPTY_HIT     = 52,

    BOX_STATE_PEACH_INIT    = 70,
    BOX_STATE_PEACH_IDLE    = 71,
    BOX_STATE_PEACH_POPUP   = 72,
    BOX_STATE_PEACH_HIT     = 73,
    BOX_STATE_PEACH_EMERGE  = 74,
    BOX_STATE_PEACH_DONE    = 75
} SmashGameBoxState;

typedef struct SmashGameBoxData {
    /* 0x00 */ SmashGameBoxState state;
    /* 0x04 */ s32 stateTimer;
    /* 0x08 */ s32 content;
    /* 0x0C */ s32 modelID;
    /* 0x10 */ s32 colliderID;
    /* 0x14 */ s32 npcID;
    /* 0x18 */ s32 peachPanelModelID;
} SmashGameBoxData; /* size = 0x1C */

typedef struct SmashGameData {
    /* 0x000 */ s32 workerID;
    /* 0x004 */ s32 found;
    /* 0x008 */ s32 timeLeft; // num frames at 30fps
    /* 0x00C */ s32 hudElemID_AButton;
    /* 0x010 */ s32 hudElemID_Meter;
    /* 0x014 */ s32 windowA_posX;
    /* 0x018 */ s32 windowB_posX;
    /* 0x01C */ s32 signpostEntity;
    /* 0x020 */ s32 currentScore;
    /* 0x024 */ s32 mashProgress;
    /* 0x028 */ SmashGameStunFlags stunFlags;
    /* 0x02C */ SmashGameBoxData box[NUM_BOXES];
} SmashGameData; /* size = 0x400 */

void N(draw_score_display)(void* renderData) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    SmashGameData* data = scorekeeper->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 hudElemA;
    s32 hudElemMeter;
    s32 timeLeft;
    s32 seconds;
    s32 deciseconds;

    // show mash meter while grabbed by a fuzzy
    if (data->stunFlags & STUN_FLAGS_GRABBED) {
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
        if (data->windowB_posX < SCREEN_WIDTH) {
            data->windowB_posX += 10;
            if (data->windowB_posX > SCREEN_WIDTH) {
                data->windowB_posX = SCREEN_WIDTH;
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

    draw_box(0, 9, data->windowA_posX, 23, 0, 80, 38, 180, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    draw_msg(MSG_MGM_0047, data->windowA_posX + 42, 28, 255, MSG_PAL_WHITE, 0);
    draw_number(NUM_PANELS - data->found, data->windowA_posX + 65, 43, TRUE, MSG_PAL_WHITE, 255, 3);
    draw_ci_image_with_clipping(&mgm_02_PeachPanelImg, 32, 32, G_IM_FMT_CI, G_IM_SIZ_4b, &mgm_02_PeachPanelPal,
        data->windowA_posX + 5, 26, 10, 20, 300, 200, 255);

    timeLeft = MIN(data->timeLeft, PLAY_TIME);
    deciseconds = ((f32)(timeLeft % 30) * 10.0) / 30;
    seconds = timeLeft / 30;

    draw_box(0, 0xB, data->windowB_posX, 27, 0, 60, 20, 180, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    // draw whole seconds
    draw_number(seconds, data->windowB_posX + 29, 31, TRUE, MSG_PAL_WHITE, 255, 3);
    // draw tenths of seconds
    draw_number(deciseconds, data->windowB_posX + 40, 31, TRUE, MSG_PAL_WHITE, 255, 0);
    // draw dot
    draw_msg(MSG_MGM_0024, data->windowB_posX + 30, 29, 255, MSG_PAL_WHITE, 0);
}

void N(work_draw_score)(void) {
    RenderTask task;

    task.renderMode = RENDER_MODE_2D;
    task.appendGfxArg = 0;
    task.appendGfx = &mgm_02_draw_score_display;
    task.distance = 0;

    queue_render_task(&task);
}

ApiStatus N(CreateScoreDisplay)(Evt* script, s32 isInitialCall) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 hudElemA, hudElemMeter;

    if (isInitialCall) {
        data->workerID = create_generic_entity_world(NULL, &mgm_02_work_draw_score);

        hudElemA = hud_element_create(&HES_AButton);
        data->hudElemID_AButton = hudElemA;
        hud_element_set_render_depth(hudElemA, 0);
        hud_element_set_flags(hudElemA, HUD_ELEMENT_FLAGS_80);
        hud_element_set_tint(hudElemA, 255, 255, 255);
        hud_element_set_script(hudElemA, &HES_AButton);

        hudElemMeter = hud_element_create(&HES_BlueMeter);
        data->hudElemID_Meter = hudElemMeter;
        hud_element_set_render_depth(hudElemMeter, 0);
        hud_element_set_flags(hudElemMeter, HUD_ELEMENT_FLAGS_80);
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(DisableMenus)(Evt* script, s32 isInitialCall) {
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_MENUS;
    func_800E9894();
    close_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus N(EnableMenus)(Evt* script, s32 isInitialCall) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_MENUS;
    return ApiStatus_DONE2;
}

ApiStatus N(DestroySignpost)(Evt* script, s32 isInitialCall) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    delete_entity(data->signpostEntity);
    return ApiStatus_DONE2;
}

ApiStatus N(CreateSignpost)(void) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 entityIndex = create_entity(&Entity_Signpost, 355, 20, -180, 0, 0, 0, 0, MAKE_ENTITY_END);
    data->signpostEntity = entityIndex;
    get_entity_by_index(entityIndex)->boundScriptBytecode = &D_80242A3C_E187BC;

    return ApiStatus_DONE2;
}

ApiStatus N(OnHitBox)(Evt* script, s32 isInitialCall0) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 hitModelID = evt_get_variable(script, LVarA);
    s32 hitColliderID = evt_get_variable(script, LVarB); // unused
    s32 i;

    for (i = 0; i < NUM_BOXES; i++) {
        if (hitModelID == data->box[i].modelID) {
            break;
        }
    }

    evt_set_variable(script, LVarC, data->box[i].content);

    switch (data->box[i].content) {
        case BOX_CONTENT_FUZZY:
            evt_set_variable(script, LVarD, data->box[i].npcID);
            data->box[i].state = BOX_STATE_FUZZY_HIT;
            break;
        case BOX_CONTENT_BOMB:
            evt_set_variable(script, LVarD, data->box[i].npcID);
            data->box[i].state = BOX_STATE_BOMB_HIT;
            break;
        case BOX_CONTENT_EMPTY:
            evt_set_variable(script, LVarD, data->box[i].npcID);
            data->box[i].state = BOX_STATE_EMPTY_HIT;
            break;
        case BOX_CONTENT_PEACH:
            data->found++;
            data->box[i].state = BOX_STATE_PEACH_HIT;
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(SetBoxContents)(Evt* script, s32 isInitialCall) {
    s32 initialConfiguration;
    s32 configuration[NUM_BOXES];
    s32 indexA, indexB, temp;
    s32 i, j;

    Enemy* enemy;
    Npc* npc;

    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    data->found = 0;
    data->timeLeft = PLAY_TIME + 10;
    data->currentScore = 0;
    data->mashProgress = 0;
    data->stunFlags = 0;

     // choose one of three initial configurations at random
    initialConfiguration = rand_int(1000) % ARRAY_COUNT(mgm_02_InitialConfigurations);
    for (i = 0; i < NUM_BOXES; i++) {
        configuration[i] = mgm_02_InitialConfigurations[initialConfiguration][i];
    }

    // randomly swap 10000 pairs
    for (i = 0; i < 10000; i++) {
        indexA = rand_int(1000) % NUM_BOXES;
        indexB = rand_int(1000) % NUM_BOXES;

        if (indexA != indexB) {
            temp = configuration[indexB];
            configuration[indexB] = configuration[indexA];
            configuration[indexA] = temp;
        }
    }

    for (i = 0; i < NUM_BOXES; i++) {
        data->box[i].state = -1;
        data->box[i].stateTimer = 0;
        data->box[i].content = configuration[i];
        data->box[i].modelID = mgm_02_BoxModelIDs[i];
        data->box[i].colliderID = mgm_02_BoxColliderIDs[i];
        data->box[i].npcID = -1;
        data->box[i].peachPanelModelID = -1;
    }

    for (i = FUZZY_NPC_ID_BASE; i < FUZZY_NPC_ID_BASE + 5; i++) {
        enemy = get_enemy(i);
        enemy->varTable[0] = 0;
    }

    for (i = BOBOMB_NPC_ID_BASE; i < BOBOMB_NPC_ID_BASE + 5; i++) {
        enemy = get_enemy(i);
        enemy->varTable[0] = 0;
    }

    for (i = LUIGI_NPC_ID_BASE; i < LUIGI_NPC_ID_BASE + 10; i++) {
        enemy = get_enemy(i);
        enemy->varTable[0] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(D_80248600); i++) {
        D_80248600[i] = FALSE;
    }

    for (i = 0; i < NUM_BOXES; i++) {
        switch (data->box[i].content) {
            case BOX_CONTENT_FUZZY:
                data->box[i].state = BOX_STATE_FUZZY_INIT;
                for (j = FUZZY_NPC_ID_BASE; j < FUZZY_NPC_ID_BASE + 5; j++) {
                    enemy = get_enemy(j);
                    if (enemy->varTable[0] == 0) {
                        npc = get_npc_unsafe(enemy->npcID);
                        enemy->varTable[0] = 1;
                        data->box[i].npcID = j;
                        disable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_2;
                        break;
                    }
                }
                break;
            case BOX_CONTENT_BOMB:
                data->box[i].state = BOX_STATE_BOMB_INIT;
                for (j = BOBOMB_NPC_ID_BASE; j < BOBOMB_NPC_ID_BASE + 5; j++) {
                    enemy = get_enemy(j);
                    if (enemy->varTable[0] == 0) {
                        npc = get_npc_unsafe(enemy->npcID);
                        enemy->varTable[0] = 1;
                        data->box[i].npcID = j;
                        disable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_2;
                        break;
                    }
                }
                break;
            case BOX_CONTENT_PEACH:
                data->box[i].state = BOX_STATE_PEACH_INIT;
                for (j = LUIGI_NPC_ID_BASE; j < LUIGI_NPC_ID_BASE + 10; j++) {
                    enemy = get_enemy(j);
                    if (enemy->varTable[0] == 0) {
                        npc = get_npc_unsafe(enemy->npcID);
                        enemy->varTable[0] = 1;
                        data->box[i].npcID = j;
                        disable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_2;
                        break;
                    }
                }
                // ARRAY BOUNDS ERROR IN ORIGINAL CODE!
                for (j = 0; j <= ARRAY_COUNT(D_80248600); j++) {
                    if (!D_80248600[j]) {
                        D_80248600[j] = TRUE;
                        data->box[i].peachPanelModelID = mgm_02_PanelModelIDs[j];
                        break;
                    }
                }
                break;
            case 3:
                data->box[i].state = BOX_STATE_EMPTY_INIT;
                break;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus N(RunMinigame)(Evt* script, s32 isInitialCall) {
    SmashGameData* data;
    Enemy* enemy;

    Npc* npc;
    s32 writeback;

    Model* model;
    Matrix4f mtx;
    f32 centerX, centerY, centerZ;
    f32 sizeX, sizeY, sizeZ;
    s32 i;

    s32 gameFinished;
    s32 hittingPeachBlock;

    gameFinished = FALSE;
    hittingPeachBlock = FALSE;
    data = get_enemy(0)->varTablePtr[0];

    for (i = 0; i < NUM_BOXES; i++) {
        if (data->box[i].npcID != -1) {
            enemy = get_enemy(data->box[i].npcID);
            npc = get_npc_unsafe(enemy->npcID);
            switch (data->box[i].state) {
                case BOX_STATE_FUZZY_INIT:
                    data->box[i].state = BOX_STATE_FUZZY_IDLE;
                    data->box[i].stateTimer = rand_int(210);
                    npc->pos.y = -1000.0f;
                    npc->flags &= -(NPC_FLAG_PASSIVE | NPC_FLAG_2);
                    disable_npc_shadow(npc);
                    // fallthrough
                case BOX_STATE_FUZZY_IDLE:
                    data->box[i].stateTimer--;
                    if (data->box[i].stateTimer <= 0) {
                        npc->currentAnim = NPC_ANIM_fuzzy_Palette_00_Anim_2;
                        data->box[i].state = BOX_STATE_FUZZY_POPUP;
                        sfx_play_sound_at_position(enemy->varTable[8], 0x100000, npc->pos.x, npc->pos.y, npc->pos.z);
                        get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                        npc->jumpVelocity = 10.5f;
                        npc->pos.x = centerX;
                        npc->jumpScale = 1.5f;
                        npc->pos.y = centerY - 12.5;
                        npc->moveToPos.y = npc->pos.y;
                        npc->pos.z = centerZ + 2.0;
                        data->box[i].stateTimer = 0;
                    }
                    break;
                case BOX_STATE_FUZZY_POPUP:
                    data->box[i].stateTimer++;
                    npc->pos.y += npc->jumpVelocity;
                    npc->jumpVelocity -= npc->jumpScale;
                    if ((npc->moveToPos.y + 20.0f) < npc->pos.y) {
                        enable_npc_shadow(npc);
                    } else {
                        disable_npc_shadow(npc);
                    }
                    if ((npc->jumpVelocity < 0.0) && (npc->pos.y <= npc->moveToPos.y)) {
                        data->box[i].state = BOX_STATE_FUZZY_IDLE;
                        data->box[i].stateTimer = rand_int(330) + 90;
                        npc->pos.y = -1000.0f;
                        if (rand_int(100) < 50) {
                            npc->yaw = 270.0f;
                        } else {
                            npc->yaw = 90.0f;
                        }
                        disable_npc_shadow(npc);
                    }
                    break;
                case BOX_STATE_FUZZY_HIT:
                    hud_element_set_script(data->hudElemID_AButton, &HES_AButton);
                    hud_element_set_alpha(data->hudElemID_AButton, 160);
                    hud_element_set_alpha(data->hudElemID_Meter, 160);
                    data->mashProgress = 0;
                    data->stunFlags |= STUN_FLAGS_GRABBED;
                    enable_npc_shadow(npc);
                    data->stunFlags |= (STUN_FLAGS_STUNNED | STUN_FLAGS_CHANGED);
                    npc->duration = 8;
                    sfx_play_sound(enemy->varTable[8]);
                    data->box[i].state = BOX_STATE_FUZZY_ATTACH;
                    gPlayerStatusPtr->anim = ANIM_Mario_CrouchStill;
                    npc->currentAnim = NPC_ANIM_fuzzy_Palette_00_Anim_3;
                    get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                    npc->pos.x = centerX;
                    npc->pos.y = centerY;
                    npc->pos.z = centerZ + 2.0;
                    npc->moveToPos.y = gPlayerStatusPtr->position.y + 35.0f;
                    npc->jumpVelocity = 10.5f;
                    npc->jumpScale = 1.5f;

                    data->box[i].stateTimer = 0;
                    fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 10, &writeback);
                    enemy->varTable[1] = npc->pos.x * 10.0f;
                    enemy->varTable[2] = npc->pos.y * 10.0f;
                    enemy->varTable[3] = npc->pos.z * 10.0f;
                    enemy->varTable[4] = gPlayerStatusPtr->position.x * 10.0f;
                    enemy->varTable[5] = (gPlayerStatusPtr->position.y + 28.0f) * 10.0f;
                    enemy->varTable[6] = (gPlayerStatusPtr->position.z + 2.0f) * 10.0f;
                    enemy->varTable[7] = 0;
                    break;
                case BOX_STATE_FUZZY_ATTACH:
                    enemy->varTable[7]++;
                    npc->pos.x = update_lerp(EASING_LINEAR, (f32)enemy->varTable[1] / 10.0, (f32)enemy->varTable[4] / 10.0, enemy->varTable[7], 8);
                    npc->pos.y = update_lerp(EASING_LINEAR, (f32)enemy->varTable[2] / 10.0, (f32)enemy->varTable[5] / 10.0, enemy->varTable[7], 8);
                    npc->pos.z = update_lerp(EASING_LINEAR, (f32)enemy->varTable[3] / 10.0, (f32)enemy->varTable[6] / 10.0, enemy->varTable[7], 8);
                    gPlayerStatusPtr->anim = ANIM_Mario_CrouchStill;
                    npc->duration--;
                    if (npc->duration <= 0) {
                        npc->currentAnim = NPC_ANIM_fuzzy_Palette_00_Anim_F;
                        gPlayerStatusPtr->anim = ANIM_Mario_RunPanic;
                        data->mashProgress = 0;
                        npc->pos.x = gPlayerStatusPtr->position.x;
                        npc->pos.y = gPlayerStatusPtr->position.y + 28.0;
                        npc->pos.z = gPlayerStatusPtr->position.z + 2.0;
                        hud_element_set_script(data->hudElemID_AButton, &HES_MashAButton);
                        hud_element_set_alpha(data->hudElemID_AButton, 255);
                        hud_element_set_alpha(data->hudElemID_Meter, 255);
                        data->box[i].state = BOX_STATE_FUZZY_GRAB;
                    }
                    break;
                case BOX_STATE_FUZZY_GRAB:
                    gPlayerStatusPtr->anim = ANIM_Mario_RunPanic;
                    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                        data->mashProgress++;
                    }
                    if (data->mashProgress >= 12) {
                        gPlayerStatusPtr->anim = ANIM_Mario_10002;
                        data->stunFlags &= ~STUN_FLAGS_STUNNED;
                        data->stunFlags |= STUN_FLAGS_CHANGED;
                        data->box[i].state = BOX_STATE_FUZZY_DETACH;
                        npc->duration = 10;
                        hud_element_set_script(data->hudElemID_AButton, &HES_AButton);
                        hud_element_set_alpha(data->hudElemID_AButton, 160);
                        hud_element_set_alpha(data->hudElemID_Meter, 160);
                        npc->currentAnim = NPC_ANIM_fuzzy_Palette_00_Anim_8;
                        npc->pos.y += 3.0;
                    }
                    break;
                case BOX_STATE_FUZZY_DETACH:
                    npc->duration--;
                    if (npc->duration == 8) {
                        data->stunFlags &= ~STUN_FLAGS_GRABBED;
                    }
                    if (npc->duration <= 0) {
                        data->box[i].state = BOX_STATE_FUZZY_DONE;
                        disable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_2;
                        fx_walking_dust(1, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 1.0f, 0, 0);
                    }
                    break;
                case BOX_STATE_FUZZY_DONE:
                    break;

                case BOX_STATE_BOMB_INIT:
                    data->box[i].state = BOX_STATE_BOMB_IDLE;
                    data->box[i].stateTimer = rand_int(210);
                    npc->pos.y = -1000.0f;
                    disable_npc_shadow(npc);
                    npc->flags &= -(NPC_FLAG_PASSIVE | NPC_FLAG_2);
                    // fallthrough
                case BOX_STATE_BOMB_IDLE:
                    data->box[i].stateTimer--;
                    if (data->box[i].stateTimer <= 0) {
                        data->box[i].state = BOX_STATE_BOMB_POPUP;
                        sfx_play_sound_at_position(enemy->varTable[8], 0x100000, npc->pos.x, npc->pos.y, npc->pos.z);
                        get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                        npc->jumpVelocity = 10.5f;
                        npc->pos.x = centerX;
                        npc->jumpScale = 1.5f;
                        npc->pos.y = centerY - 12.5;
                        npc->moveToPos.y = npc->pos.y;
                        npc->pos.z = centerZ + 2.0;
                        data->box[i].stateTimer = 0;
                    }
                    break;
                case BOX_STATE_BOMB_POPUP:
                    data->box[i].stateTimer++;
                    npc->pos.y += npc->jumpVelocity;
                    npc->jumpVelocity -= npc->jumpScale;
                    if ((npc->moveToPos.y + 20.0f) < npc->pos.y) {
                        enable_npc_shadow(npc);
                    } else {
                        disable_npc_shadow(npc);
                    }
                    if ((npc->jumpVelocity < 0.0) && (npc->pos.y <= npc->moveToPos.y)) {
                        data->box[i].state = BOX_STATE_BOMB_IDLE;
                        data->box[i].stateTimer = rand_int(330) + 90;
                        npc->pos.y = -1000.0f;
                        if (rand_int(100) < 50) {
                            npc->yaw = 270.0f;
                        } else {
                            npc->yaw = 90.0f;
                        }
                        disable_npc_shadow(npc);
                    }
                    break;
                case BOX_STATE_BOMB_HIT:
                    enable_npc_shadow(npc);
                    npc->duration = 15;
                    npc->currentAnim = NPC_ANIM_bob_omb_Palette_00_Anim_5;
                    data->stunFlags |= (STUN_FLAGS_STUNNED | STUN_FLAGS_CHANGED);
                    data->box[i].state = BOX_STATE_BOMB_ATTACK;
                    get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                    npc->pos.x = centerX;
                    npc->pos.y = centerY - 10.0f;
                    npc->pos.z = centerZ + 8.0;
                    fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 10, &writeback);
                    if (npc->pos.x > gPlayerStatusPtr->position.x) {
                        npc->yaw = 270.0f;
                        gPlayerStatusPtr->targetYaw = 95.0f;
                    } else {
                        npc->yaw = 90.0f;
                        gPlayerStatusPtr->targetYaw = 265.0f;
                    }
                    // rest of case could simply use fallthough, but wouldnt match
                    gPlayerStatusPtr->anim = ANIM_Mario_CrouchStill;
                    npc->duration--;
                    if (npc->duration <= 0) {
                        fx_explosion(0, npc->pos.x, npc->pos.y, npc->pos.z + 1.0f);
                        npc->duration = 30;
                        npc->pos.y = -1000.0f;
                        data->box[i].state = BOX_STATE_BOMB_STUN;
                        sfx_play_sound(SOUND_BOMB_BLAST);
                    }
                    break;
                case BOX_STATE_BOMB_ATTACK:
                    gPlayerStatusPtr->anim = ANIM_Mario_CrouchStill;
                    npc->duration--;
                    if (npc->duration <= 0) {
                        fx_explosion(0, npc->pos.x, npc->pos.y, npc->pos.z + 1.0f);
                        npc->duration = 30;
                        npc->pos.y = -1000.0f;
                        data->box[i].state = BOX_STATE_BOMB_STUN;
                        sfx_play_sound(SOUND_BOMB_BLAST);
                    }
                    break;
                case BOX_STATE_BOMB_STUN:
                    npc->duration--;
                    if (npc->duration == 25) {
                        gPlayerStatusPtr->anim = ANIM_Mario_Charred;
                    }
                    if (npc->duration <= 0) {
                        gPlayerStatusPtr->anim = ANIM_Mario_10002;
                        data->stunFlags &= ~STUN_FLAGS_STUNNED;
                        data->stunFlags |= STUN_FLAGS_CHANGED;
                        data->box[i].state = BOX_STATE_BOMB_DONE;
                        disable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_2;
                    }
                    break;
                case BOX_STATE_BOMB_DONE:
                    break;

                case BOX_STATE_PEACH_INIT:
                    get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                    data->box[i].state = BOX_STATE_PEACH_IDLE;
                    data->box[i].stateTimer = rand_int(210);
                    npc->pos.x = centerX;
                    npc->pos.y = centerY;
                    npc->moveToPos.y = npc->pos.y;
                    npc->pos.z = centerZ + 2.0;
                    disable_npc_shadow(npc);
                    // fallthrough
                case BOX_STATE_PEACH_IDLE:
                    data->box[i].stateTimer--;
                    if (data->box[i].stateTimer <= 0) {
                        get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                        data->box[i].state = BOX_STATE_PEACH_POPUP;
                        sfx_play_sound_at_position(SOUND_214, 0x200000, npc->pos.x, npc->pos.y, npc->pos.z);
                        get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                        npc->jumpVelocity = 10.0f;
                        npc->pos.y = npc->moveToPos.y;
                        npc->jumpScale = 1.1f;
                        data->box[i].stateTimer = 0;
                        model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                        model->flags &= -(MODEL_FLAGS_FLAG_1 | MODEL_FLAGS_ENABLED);
                        if (!(model->flags & MODEL_FLAGS_HAS_TRANSFORM_APPLIED)) {
                            guTranslateF(model->transformMatrix, npc->pos.x, npc->pos.y, npc->pos.z);
                            model->flags |= (MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED);
                        }
                        else {
                            guTranslateF(mtx, npc->pos.x, npc->pos.y, npc->pos.z);
                            guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
                        }
                    }
                    break;
                case BOX_STATE_PEACH_POPUP:
                    data->box[i].stateTimer++;
                    npc->pos.y += npc->jumpVelocity;
                    npc->jumpVelocity -= npc->jumpScale;
                    model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                    if (!(model->flags & MODEL_FLAGS_HAS_TRANSFORM_APPLIED)) {
                        guTranslateF(model->transformMatrix, npc->pos.x, npc->pos.y, npc->pos.z);
                        model->flags |= (MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED);
                    } else {
                        guTranslateF(mtx, npc->pos.x, npc->pos.y, npc->pos.z);
                        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
                    }
                    if ((npc->moveToPos.y + 20.0f) < npc->pos.y) {
                        enable_npc_shadow(npc);
                    } else {
                        disable_npc_shadow(npc);
                    }
                    if ((npc->jumpVelocity < 0.0) && (npc->pos.y <= npc->moveToPos.y)) {
                        data->box[i].state = BOX_STATE_PEACH_IDLE;
                        data->box[i].stateTimer = rand_int(330) + 90;
                        disable_npc_shadow(npc);
                        model->flags |= MODEL_FLAGS_ENABLED;
                    }
                    break;
                case BOX_STATE_PEACH_HIT:
                    sfx_play_sound(SOUND_21C);
                    model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                    enable_npc_shadow(npc);
                    npc->duration = 0;
                    data->box[i].state = BOX_STATE_PEACH_EMERGE;
                    model->flags &= -(MODEL_FLAGS_FLAG_1 | MODEL_FLAGS_ENABLED);
                    // fallthrough
                case BOX_STATE_PEACH_EMERGE:
                    hittingPeachBlock = TRUE;
                    model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                    centerY = update_lerp(EASING_QUADRATIC_OUT, npc->moveToPos.y, npc->moveToPos.y + 30.0, npc->duration, 30);
                    if (!(model->flags & MODEL_FLAGS_HAS_TRANSFORM_APPLIED)) {
                        guTranslateF(model->transformMatrix, npc->pos.x, centerY, npc->pos.z);
                        model->flags |= (MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED);
                    } else {
                        guTranslateF(mtx, npc->pos.x, centerY, npc->pos.z);
                        guMtxCatF(mtx, model->transformMatrix, model->transformMatrix);
                    }
                    npc->duration++;
                    if (npc->duration >= 30) {
                        data->box[i].state = BOX_STATE_PEACH_DONE;
                        disable_npc_shadow(npc);
                        model->flags |= MODEL_FLAGS_ENABLED;
                    }
                    break;
                case BOX_STATE_PEACH_DONE:
                    break;
            }
        } else {
            if (data->box[i].state == BOX_STATE_EMPTY_INIT) {
                data->box[i].state = BOX_STATE_EMPTY_IDLE;
                data->box[i].stateTimer = 0;
            }
        }
    }

    if (data->timeLeft > 0) {
        if (data->found < NUM_PANELS) {
            data->timeLeft--;
            if (data->timeLeft == 750) {
                sfx_play_sound(SOUND_1A5);
            } else if (data->timeLeft == 600) {
                sfx_play_sound(SOUND_1A5);
            } else if (data->timeLeft == 450) {
                sfx_play_sound(SOUND_1A5);
            } else if (data->timeLeft == 300) {
                sfx_play_sound(SOUND_1A6);
            } else if (data->timeLeft == 270) {
                sfx_play_sound(SOUND_1A6);
            } else if (data->timeLeft == 240) {
                sfx_play_sound(SOUND_1A6);
            } else if (data->timeLeft == 210) {
                sfx_play_sound(SOUND_1A6);
            } else if (data->timeLeft == 180) {
                sfx_play_sound(SOUND_1A6);
            } else if (data->timeLeft == 150) {
                sfx_play_sound(SOUND_1A7);
            } else if (data->timeLeft == 120) {
                sfx_play_sound(SOUND_1A7);
            } else if (data->timeLeft == 90) {
                sfx_play_sound(SOUND_1A7);
            } else if (data->timeLeft == 60) {
                sfx_play_sound(SOUND_1A7);
            } else if (data->timeLeft == 30) {
                sfx_play_sound(SOUND_1A7);
            }
        }
        if ((data->timeLeft > 0) && (data->found == NUM_PANELS)) {
            if (!(data->stunFlags & STUN_FLAGS_STUNNED)) {
                data->stunFlags |= (STUN_FLAGS_STUNNED | STUN_FLAGS_CHANGED);
            }
        }
    }
    if ((data->timeLeft == 0) && hittingPeachBlock) {
        if (!(data->stunFlags & STUN_FLAGS_STUNNED)) {
            data->stunFlags |= (STUN_FLAGS_STUNNED | STUN_FLAGS_CHANGED);
        }
    }
    if (data->stunFlags & STUN_FLAGS_CHANGED) {
        data->stunFlags &= ~STUN_FLAGS_CHANGED;
        if (data->stunFlags & STUN_FLAGS_STUNNED) {
            disable_player_input();
            partner_disable_input();
        } else {
            enable_player_input();
            partner_enable_input();
        }
    }
    if (!hittingPeachBlock && ((data->found == 10) || ((data->timeLeft == 0)
        && (gPlayerStatusPtr->actionState != ACTION_STATE_HAMMER)))) {
        gameFinished = TRUE;
    }
    if (gameFinished) {
        if (data->stunFlags & STUN_FLAGS_STUNNED) {
            enable_player_input();
            partner_enable_input();
        }
        data->stunFlags = 0;

        gPlayerStatusPtr->targetYaw = 180.0;
        if (data->timeLeft == 0) {
            sfx_play_sound(SOUND_MENU_ERROR);
            gPlayerStatusPtr->anim = ANIM_Mario_10002;
        } else {
            sfx_play_sound(SOUND_D4);
            gPlayerStatusPtr->anim = ANIM_Mario_10002;
        }

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}


static char* N(exit_str_0) = "mgm_00";

ApiStatus N(UpdateRecords)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 seconds, deciseconds;
    s32 outScore;

    seconds = data->timeLeft  / 30;
    deciseconds = ((f32)(data->timeLeft % 30) * 10.0) / 30;

    data->currentScore = (seconds * 10) + deciseconds;
    playerData->smashGameTotal += data->currentScore;

    if (playerData->smashGameTotal > 99999) {
        playerData->smashGameTotal = 99999;
    }
    if (playerData->smashGameRecord < data->currentScore) {
        playerData->smashGameRecord = data->currentScore;
    }

    set_message_value(seconds, 0);
    set_message_value(deciseconds, 1);
    set_message_value(data->currentScore, 2);

    outScore = data->currentScore;
    if (data->currentScore == 0 && data->found == NUM_PANELS) {
        outScore = -1;
    }
    evt_set_variable(script, LVar0, outScore);

    return ApiStatus_DONE2;
}

ApiStatus N(GiveCoinReward)(Evt* script, s32 isInitialCall) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
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

ApiStatus N(CleanupGame)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = get_enemy(SCOREKEEPER_ENEMY_IDX);
    SmashGameData* data = enemy->varTablePtr[SMASH_DATA_VAR_IDX];
    Npc* npc;
    u32 screenX, screenY,screenZ;
    s32 writeback;
    s32 i;

    if (enemy->varTable[3] == 4) {
        for (i = 0; i < NUM_BOXES; i++) {
            if (data->box[i].npcID == -1) {
                continue;
            }
            enemy = get_enemy(data->box[i].npcID);
            npc = get_npc_unsafe(enemy->npcID);
            if ((npc->flags & NPC_FLAG_2)) {
                continue;
            }

            get_screen_coords(0, npc->pos.x, npc->pos.y, npc->pos.z, &screenX, &screenY, &screenZ);
            if (screenX - 1 < SCREEN_WIDTH - 1) {
                fx_walking_dust(1, npc->pos.x, npc->pos.y, npc->pos.z, 0, 0);
                sfx_play_sound(SOUND_283);
            }
            npc->flags |= NPC_FLAG_2;
            disable_npc_shadow(npc);
            enemy->varTable[0] = 0;
        }
        return ApiStatus_DONE2;
    } else {
        for (i = 0; i < NUM_BOXES; i++) {
            if (data->box[i].npcID == -1) {
                continue;
            }
            enemy = get_enemy(data->box[i].npcID);
            npc = get_npc_unsafe(enemy->npcID);
            if ((npc->flags & NPC_FLAG_2)) {
                continue;
            }

            switch (data->box[i].content) {
                case BOX_CONTENT_FUZZY:
                    if (data->box[i].state != BOX_STATE_FUZZY_END) {
                        data->box[i].state = BOX_STATE_FUZZY_END;
                        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 30, &writeback);
                        npc->currentAnim = NPC_ANIM_fuzzy_Palette_00_Anim_E;
                        enable_npc_shadow(npc);
                    }
                    break;

                case BOX_CONTENT_BOMB:
                    if (data->box[i].state != BOX_STATE_BOMB_END) {
                        data->box[i].state = BOX_STATE_BOMB_END;
                        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 30, &writeback);
                        npc->currentAnim = NPC_ANIM_bob_omb_Palette_00_Anim_1C;
                        enable_npc_shadow(npc);
                    }
                    break;
            }
        }
        return ApiStatus_BLOCK;
    }
}

ApiStatus N(CreateMinigame)(Evt* script, s32 isInitialCall) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    SmashGameData* data = heap_malloc(sizeof(*data));
    scorekeeper->varTablePtr[SMASH_DATA_VAR_IDX] = data;

    data->windowA_posX = -80;
    data->windowB_posX = SCREEN_WIDTH;
    data->timeLeft = PLAY_TIME;

    func_800E9894();
    close_status_menu();

    return ApiStatus_DONE2;
}

ApiStatus N(DestroyMinigame)(Evt* script, s32 isInitialCall) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];

    free_generic_entity(data->workerID);
    hud_element_free(data->hudElemID_AButton);
    hud_element_free(data->hudElemID_Meter);

    return ApiStatus_DONE2;
}

ApiStatus N(GetCoinCount)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, LVarA, gPlayerData.coins);
    return ApiStatus_DONE2;
}

ApiStatus N(TakeCoinCost)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        playerData->smashGamePlays++;
        script->functionTemp[0] = 0;
    }
    add_coins(-1);
    sfx_play_sound(SOUND_211);

    script->functionTemp[0]++;
    return (script->functionTemp[0] == PLAY_COST) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

ApiStatus N(HideCoinCounter)(Evt* script, s32 isInitialCall) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}
