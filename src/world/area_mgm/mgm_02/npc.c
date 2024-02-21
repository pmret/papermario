#include "mgm_02.h"
#include "hud_element.h"
#include "effects.h"
#include "model.h"
#include "entity.h"
#include "sprite/player.h"

void delete_entity(s32);
void partner_enable_input(void);

#define SCOREKEEPER_ENEMY_IDX 0
#define SMASH_DATA_VAR_IDX 0

#define PLAY_COST   10
#define PLAY_TIME   ((s32)(900 * DT))
#define FRAME_RATE ((s32)(30 * DT))
#define NUM_BOXES   35
#define NUM_PANELS  10

#define SMASH_DATA_VAR_IDX 0
#define SMASH_DATA_VAR_IDX 0

#define FUZZY_NPC_ID_BASE  NPC_Fuzzy_01
#define BOBOMB_NPC_ID_BASE NPC_Bobomb_01
#define LUIGI_NPC_ID_BASE  NPC_Luigi_01

extern HudScript HES_BlueMeter;
extern HudScript HES_AButton;
extern HudScript HES_MashAButton;

extern s32 N(InitialConfigurations)[3][NUM_BOXES];
extern s32 N(BoxModelIDs)[NUM_BOXES];
extern s32 N(BoxColliderIDs)[NUM_BOXES];
extern s32 N(PanelModelIDs)[NUM_PANELS];

BSS s32 D_80248600[NUM_PANELS]; //TODO set name: PanelModelsAssigned

extern IMG_BIN N(panel_peach_img);
extern PAL_BIN N(panel_peach_pal);

API_CALLABLE(N(SetMsgImgs_Panel));

extern EvtScript N(read_sign_instructions); // EVT_ReadSign

typedef enum SmashGameBoxCotent {
    BOX_CONTENT_FUZZY       = 0,
    BOX_CONTENT_BOMB        = 1,
    BOX_CONTENT_PEACH       = 2,
    BOX_CONTENT_EMPTY       = 3
} SmashGameBoxCotent;

typedef enum SmashGameStunFlags {
    STUN_FLAG_STUNNED      = 1,
    STUN_FLAG_CHANGED      = 2,
    STUN_FLAG_GRABBED      = 4
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
    /* 0x020 */ s32 curScore;
    /* 0x024 */ s32 mashProgress;
    /* 0x028 */ SmashGameStunFlags stunFlags;
    /* 0x02C */ SmashGameBoxData box[NUM_BOXES];
} SmashGameData; /* size = 0x400 */

#if VERSION_PAL
#define COUNT_POS_Y 31
#define TEXT_POS_Y 39
#else
#define TEXT_POS_Y 28
#define COUNT_POS_Y 43
#endif

void N(appendGfx_score_display)(void* renderData) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    SmashGameData* data = scorekeeper->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 hudElemA;
    s32 hudElemMeter;
    s32 timeLeft;
    s32 seconds;
    s32 deciseconds;

    // show mash meter while grabbed by a fuzzy
    if (data->stunFlags & STUN_FLAG_GRABBED) {
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

    draw_box(0, WINDOW_STYLE_9, data->windowA_posX, 23, 0, 80, 38, 180, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    draw_msg(MSG_MGM_0047, data->windowA_posX + 42, TEXT_POS_Y, 255, MSG_PAL_WHITE, 0);
    draw_number(NUM_PANELS - data->found, data->windowA_posX + 65, COUNT_POS_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, 255, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
    draw_ci_image_with_clipping(&N(panel_peach_img), 32, 32, G_IM_FMT_CI, G_IM_SIZ_4b, &N(panel_peach_pal),
        data->windowA_posX + 5, 26, 10, 20, 300, 200, 255);

    timeLeft = MIN(data->timeLeft, PLAY_TIME);
    deciseconds = ((f32)(timeLeft % FRAME_RATE) * 10.0) / FRAME_RATE;
    seconds = timeLeft / FRAME_RATE;

    draw_box(0, WINDOW_STYLE_11, data->windowB_posX, 27, 0, 60, 20, 180, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    // draw whole seconds
    draw_number(seconds, data->windowB_posX + 29, 31, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, 255, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
    // draw tenths of seconds
    draw_number(deciseconds, data->windowB_posX + 40, 31, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, 255, 0);
    // draw dot
    draw_msg(MSG_MGM_0024, data->windowB_posX + 30, 29, 255, MSG_PAL_WHITE, 0);
}

void N(worker_draw_score)(void) {
    RenderTask task;

    task.renderMode = RENDER_MODE_CLOUD_NO_ZCMP;
    task.appendGfxArg = 0;
    task.appendGfx = &N(appendGfx_score_display);
    task.dist = 0;

    queue_render_task(&task);
}

API_CALLABLE(N(CreateScoreDisplay)) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 hudElemA, hudElemMeter;

    if (isInitialCall) {
        data->workerID = create_worker_world(NULL, &N(worker_draw_score));

        hudElemA = hud_element_create(&HES_AButton);
        data->hudElemID_AButton = hudElemA;
        hud_element_set_render_depth(hudElemA, 0);
        hud_element_set_flags(hudElemA, HUD_ELEMENT_FLAG_80);
        hud_element_set_tint(hudElemA, 255, 255, 255);
        hud_element_set_script(hudElemA, &HES_AButton);

        hudElemMeter = hud_element_create(&HES_BlueMeter);
        data->hudElemID_Meter = hudElemMeter;
        hud_element_set_render_depth(hudElemMeter, 0);
        hud_element_set_flags(hudElemMeter, HUD_ELEMENT_FLAG_80);
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(DisableMenus)) {
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_MENUS;
    status_bar_ignore_changes();
    close_status_bar();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(EnableMenus)) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_MENUS;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroySignpost)) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    delete_entity(data->signpostEntity);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateSignpost)) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 entityIndex = create_entity(&Entity_Signpost, 355, 20, -180, 0, 0, 0, 0, MAKE_ENTITY_END);
    data->signpostEntity = entityIndex;
    get_entity_by_index(entityIndex)->boundScriptBytecode = &N(read_sign_instructions);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(OnHitBox)) {
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

#if VERSION_PAL
API_CALLABLE(N(SetBoxContents));
INCLUDE_ASM(ApiResult, "world/area_mgm/mgm_02/mgm_02_2_npc", mgm_02_SetBoxContents);
#else
API_CALLABLE(N(SetBoxContents)) {
    s32 initialConfiguration;
    s32 configuration[NUM_BOXES];
    s32 indexA, indexB, temp;
    s32 i, j;

    Enemy* enemy;
    Npc* npc;

    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    data->found = 0;
    data->timeLeft = PLAY_TIME + 10;
    data->curScore = 0;
    data->mashProgress = 0;
    data->stunFlags = 0;

     // choose one of three initial configurations at random
    initialConfiguration = rand_int(1000) % ARRAY_COUNT(N(InitialConfigurations));
    for (i = 0; i < NUM_BOXES; i++) {
        configuration[i] = N(InitialConfigurations[initialConfiguration][i]);
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
        data->box[i].modelID = N(BoxModelIDs[i]);
        data->box[i].colliderID = N(BoxColliderIDs[i]);
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
                        npc->flags |= NPC_FLAG_INVISIBLE;
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
                        npc->flags |= NPC_FLAG_INVISIBLE;
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
                        npc->flags |= NPC_FLAG_INVISIBLE;
                        break;
                    }
                }
                // ARRAY BOUNDS ERROR IN ORIGINAL CODE!
                for (j = 0; j <= ARRAY_COUNT(D_80248600); j++) {
                    if (!D_80248600[j]) {
                        D_80248600[j] = TRUE;
                        data->box[i].peachPanelModelID = N(PanelModelIDs[j]);
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
#endif

#if VERSION_PAL
API_CALLABLE(N(RunMinigame));
INCLUDE_ASM(ApiResult, "world/area_mgm/mgm_02/mgm_02_2_npc", mgm_02_RunMinigame);
#else
API_CALLABLE(N(RunMinigame)) {
    SmashGameData* data;
    Enemy* enemy;

    Npc* npc;
    EffectInstance* writeback;

    Model* model;
    Matrix4f mtx;
    f32 centerX, centerY, centerZ;
    f32 sizeX, sizeY, sizeZ;
    s32 i;

    s32 gameFinished;
    s32 hittingPeachBlock;

    gameFinished = FALSE;
    hittingPeachBlock = FALSE;
    data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];

    for (i = 0; i < NUM_BOXES; i++) {
        if (data->box[i].npcID != -1) {
            enemy = get_enemy(data->box[i].npcID);
            npc = get_npc_unsafe(enemy->npcID);
            switch (data->box[i].state) {
                case BOX_STATE_FUZZY_INIT:
                    data->box[i].state = BOX_STATE_FUZZY_IDLE;
                    data->box[i].stateTimer = rand_int(210);
                    npc->pos.y = NPC_DISPOSE_POS_Y;
                    npc->flags &= ~NPC_FLAG_INVISIBLE;
                    disable_npc_shadow(npc);
                    // fallthrough
                case BOX_STATE_FUZZY_IDLE:
                    data->box[i].stateTimer--;
                    if (data->box[i].stateTimer <= 0) {
                        npc->curAnim = ANIM_Fuzzy_Walk;
                        data->box[i].state = BOX_STATE_FUZZY_POPUP;
                        sfx_play_sound_at_position(enemy->varTable[8], SOUND_SPACE_DEFAULT | SOUND_PARAM_MOST_QUIET, npc->pos.x, npc->pos.y, npc->pos.z);
                        get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                        npc->jumpVel = 10.5f;
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
                    npc->pos.y += npc->jumpVel;
                    npc->jumpVel -= npc->jumpScale;
                    if ((npc->moveToPos.y + 20.0f) < npc->pos.y) {
                        enable_npc_shadow(npc);
                    } else {
                        disable_npc_shadow(npc);
                    }
                    if ((npc->jumpVel < 0.0) && (npc->pos.y <= npc->moveToPos.y)) {
                        data->box[i].state = BOX_STATE_FUZZY_IDLE;
                        data->box[i].stateTimer = rand_int(330) + 90;
                        npc->pos.y = NPC_DISPOSE_POS_Y;
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
                    data->stunFlags |= STUN_FLAG_GRABBED;
                    enable_npc_shadow(npc);
                    data->stunFlags |= (STUN_FLAG_STUNNED | STUN_FLAG_CHANGED);
                    npc->duration = 8;
                    sfx_play_sound(enemy->varTable[8]);
                    data->box[i].state = BOX_STATE_FUZZY_ATTACH;
                    gPlayerStatusPtr->anim = ANIM_Mario1_TiredStill;
                    npc->curAnim = ANIM_Fuzzy_Run;
                    get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                    npc->pos.x = centerX;
                    npc->pos.y = centerY;
                    npc->pos.z = centerZ + 2.0;
                    npc->moveToPos.y = gPlayerStatusPtr->pos.y + 35.0f;
                    npc->jumpVel = 10.5f;
                    npc->jumpScale = 1.5f;

                    data->box[i].stateTimer = 0;
                    fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 10, &writeback);
                    enemy->varTable[1] = npc->pos.x * 10.0f;
                    enemy->varTable[2] = npc->pos.y * 10.0f;
                    enemy->varTable[3] = npc->pos.z * 10.0f;
                    enemy->varTable[4] = gPlayerStatusPtr->pos.x * 10.0f;
                    enemy->varTable[5] = (gPlayerStatusPtr->pos.y + 28.0f) * 10.0f;
                    enemy->varTable[6] = (gPlayerStatusPtr->pos.z + 2.0f) * 10.0f;
                    enemy->varTable[7] = 0;
                    break;
                case BOX_STATE_FUZZY_ATTACH:
                    enemy->varTable[7]++;
                    npc->pos.x = update_lerp(EASING_LINEAR, (f32)enemy->varTable[1] / 10.0, (f32)enemy->varTable[4] / 10.0, enemy->varTable[7], 8);
                    npc->pos.y = update_lerp(EASING_LINEAR, (f32)enemy->varTable[2] / 10.0, (f32)enemy->varTable[5] / 10.0, enemy->varTable[7], 8);
                    npc->pos.z = update_lerp(EASING_LINEAR, (f32)enemy->varTable[3] / 10.0, (f32)enemy->varTable[6] / 10.0, enemy->varTable[7], 8);
                    gPlayerStatusPtr->anim = ANIM_Mario1_TiredStill;
                    npc->duration--;
                    if (npc->duration <= 0) {
                        npc->curAnim = ANIM_Fuzzy_Stunned;
                        gPlayerStatusPtr->anim = ANIM_Mario1_PanicRun;
                        data->mashProgress = 0;
                        npc->pos.x = gPlayerStatusPtr->pos.x;
                        npc->pos.y = gPlayerStatusPtr->pos.y + 28.0;
                        npc->pos.z = gPlayerStatusPtr->pos.z + 2.0;
                        hud_element_set_script(data->hudElemID_AButton, &HES_MashAButton);
                        hud_element_set_alpha(data->hudElemID_AButton, 255);
                        hud_element_set_alpha(data->hudElemID_Meter, 255);
                        data->box[i].state = BOX_STATE_FUZZY_GRAB;
                    }
                    break;
                case BOX_STATE_FUZZY_GRAB:
                    gPlayerStatusPtr->anim = ANIM_Mario1_PanicRun;
                    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                        data->mashProgress++;
                    }
                    if (data->mashProgress >= 12) {
                        gPlayerStatusPtr->anim = ANIM_Mario1_Idle;
                        data->stunFlags &= ~STUN_FLAG_STUNNED;
                        data->stunFlags |= STUN_FLAG_CHANGED;
                        data->box[i].state = BOX_STATE_FUZZY_DETACH;
                        npc->duration = 10;
                        hud_element_set_script(data->hudElemID_AButton, &HES_AButton);
                        hud_element_set_alpha(data->hudElemID_AButton, 160);
                        hud_element_set_alpha(data->hudElemID_Meter, 160);
                        npc->curAnim = ANIM_Fuzzy_Hurt;
                        npc->pos.y += 3.0;
                    }
                    break;
                case BOX_STATE_FUZZY_DETACH:
                    npc->duration--;
                    if (npc->duration == 8) {
                        data->stunFlags &= ~STUN_FLAG_GRABBED;
                    }
                    if (npc->duration <= 0) {
                        data->box[i].state = BOX_STATE_FUZZY_DONE;
                        disable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_INVISIBLE;
                        fx_walking_dust(1, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 1.0f, 0, 0);
                    }
                    break;
                case BOX_STATE_FUZZY_DONE:
                    break;

                case BOX_STATE_BOMB_INIT:
                    data->box[i].state = BOX_STATE_BOMB_IDLE;
                    data->box[i].stateTimer = rand_int(210);
                    npc->pos.y = NPC_DISPOSE_POS_Y;
                    disable_npc_shadow(npc);
                    npc->flags &= ~NPC_FLAG_INVISIBLE;
                    // fallthrough
                case BOX_STATE_BOMB_IDLE:
                    data->box[i].stateTimer--;
                    if (data->box[i].stateTimer <= 0) {
                        data->box[i].state = BOX_STATE_BOMB_POPUP;
                        sfx_play_sound_at_position(enemy->varTable[8], 0x100000, npc->pos.x, npc->pos.y, npc->pos.z);
                        get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                        npc->jumpVel = 10.5f;
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
                    npc->pos.y += npc->jumpVel;
                    npc->jumpVel -= npc->jumpScale;
                    if ((npc->moveToPos.y + 20.0f) < npc->pos.y) {
                        enable_npc_shadow(npc);
                    } else {
                        disable_npc_shadow(npc);
                    }
                    if ((npc->jumpVel < 0.0) && (npc->pos.y <= npc->moveToPos.y)) {
                        data->box[i].state = BOX_STATE_BOMB_IDLE;
                        data->box[i].stateTimer = rand_int(330) + 90;
                        npc->pos.y = NPC_DISPOSE_POS_Y;
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
                    npc->curAnim = ANIM_Bobomb_WalkLit;
                    data->stunFlags |= (STUN_FLAG_STUNNED | STUN_FLAG_CHANGED);
                    data->box[i].state = BOX_STATE_BOMB_ATTACK;
                    get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                    npc->pos.x = centerX;
                    npc->pos.y = centerY - 10.0f;
                    npc->pos.z = centerZ + 8.0;
                    fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 10, &writeback);
                    if (npc->pos.x > gPlayerStatusPtr->pos.x) {
                        npc->yaw = 270.0f;
                        gPlayerStatusPtr->targetYaw = 95.0f;
                    } else {
                        npc->yaw = 90.0f;
                        gPlayerStatusPtr->targetYaw = 265.0f;
                    }
                    // rest of case could simply use fallthough, but wouldnt match
                    gPlayerStatusPtr->anim = ANIM_Mario1_TiredStill;
                    npc->duration--;
                    if (npc->duration <= 0) {
                        fx_explosion(0, npc->pos.x, npc->pos.y, npc->pos.z + 1.0f);
                        npc->duration = 30;
                        npc->pos.y = NPC_DISPOSE_POS_Y;
                        data->box[i].state = BOX_STATE_BOMB_STUN;
                        sfx_play_sound(SOUND_BOMB_BLAST);
                    }
                    break;
                case BOX_STATE_BOMB_ATTACK:
                    gPlayerStatusPtr->anim = ANIM_Mario1_TiredStill;
                    npc->duration--;
                    if (npc->duration <= 0) {
                        fx_explosion(0, npc->pos.x, npc->pos.y, npc->pos.z + 1.0f);
                        npc->duration = 30;
                        npc->pos.y = NPC_DISPOSE_POS_Y;
                        data->box[i].state = BOX_STATE_BOMB_STUN;
                        sfx_play_sound(SOUND_BOMB_BLAST);
                    }
                    break;
                case BOX_STATE_BOMB_STUN:
                    npc->duration--;
                    if (npc->duration == 25) {
                        gPlayerStatusPtr->anim = ANIM_Mario1_Burnt;
                    }
                    if (npc->duration <= 0) {
                        gPlayerStatusPtr->anim = ANIM_Mario1_Idle;
                        data->stunFlags &= ~STUN_FLAG_STUNNED;
                        data->stunFlags |= STUN_FLAG_CHANGED;
                        data->box[i].state = BOX_STATE_BOMB_DONE;
                        disable_npc_shadow(npc);
                        npc->flags |= NPC_FLAG_INVISIBLE;
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
                        sfx_play_sound_at_position(SOUND_HEART_BOUNCE, SOUND_PARAM_MORE_QUIET | SOUND_SPACE_DEFAULT, npc->pos.x, npc->pos.y, npc->pos.z);
                        get_model_center_and_size(data->box[i].modelID, &centerX, &centerY, &centerZ, &sizeX, &sizeY, &sizeZ);
                        npc->jumpVel = 10.0f;
                        npc->pos.y = npc->moveToPos.y;
                        npc->jumpScale = 1.1f;
                        data->box[i].stateTimer = 0;
                        model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                        model->flags &= ~MODEL_FLAG_HIDDEN;
                        if (!(model->flags & MODEL_FLAG_HAS_TRANSFORM)) {
                            guTranslateF(model->userTransformMtx, npc->pos.x, npc->pos.y, npc->pos.z);
                            model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
                        }
                        else {
                            guTranslateF(mtx, npc->pos.x, npc->pos.y, npc->pos.z);
                            guMtxCatF(mtx, model->userTransformMtx, model->userTransformMtx);
                        }
                    }
                    break;
                case BOX_STATE_PEACH_POPUP:
                    data->box[i].stateTimer++;
                    npc->pos.y += npc->jumpVel;
                    npc->jumpVel -= npc->jumpScale;
                    model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                    if (!(model->flags & MODEL_FLAG_HAS_TRANSFORM)) {
                        guTranslateF(model->userTransformMtx, npc->pos.x, npc->pos.y, npc->pos.z);
                        model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
                    } else {
                        guTranslateF(mtx, npc->pos.x, npc->pos.y, npc->pos.z);
                        guMtxCatF(mtx, model->userTransformMtx, model->userTransformMtx);
                    }
                    if ((npc->moveToPos.y + 20.0f) < npc->pos.y) {
                        enable_npc_shadow(npc);
                    } else {
                        disable_npc_shadow(npc);
                    }
                    if ((npc->jumpVel < 0.0) && (npc->pos.y <= npc->moveToPos.y)) {
                        data->box[i].state = BOX_STATE_PEACH_IDLE;
                        data->box[i].stateTimer = rand_int(330) + 90;
                        disable_npc_shadow(npc);
                        model->flags |= MODEL_FLAG_HIDDEN;
                    }
                    break;
                case BOX_STATE_PEACH_HIT:
                    sfx_play_sound(SOUND_APPROVE);
                    model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                    enable_npc_shadow(npc);
                    npc->duration = 0;
                    data->box[i].state = BOX_STATE_PEACH_EMERGE;
                    model->flags &= ~MODEL_FLAG_HIDDEN;
                    // fallthrough
                case BOX_STATE_PEACH_EMERGE:
                    hittingPeachBlock = TRUE;
                    model = get_model_from_list_index(get_model_list_index_from_tree_index(data->box[i].peachPanelModelID));
                    centerY = update_lerp(EASING_QUADRATIC_OUT, npc->moveToPos.y, npc->moveToPos.y + 30.0, npc->duration, 30);
                    if (!(model->flags & MODEL_FLAG_HAS_TRANSFORM)) {
                        guTranslateF(model->userTransformMtx, npc->pos.x, centerY, npc->pos.z);
                        model->flags |= MODEL_FLAG_MATRIX_DIRTY | MODEL_FLAG_HAS_TRANSFORM;
                    } else {
                        guTranslateF(mtx, npc->pos.x, centerY, npc->pos.z);
                        guMtxCatF(mtx, model->userTransformMtx, model->userTransformMtx);
                    }
                    npc->duration++;
                    if (npc->duration >= 30) {
                        data->box[i].state = BOX_STATE_PEACH_DONE;
                        disable_npc_shadow(npc);
                        model->flags |= MODEL_FLAG_HIDDEN;
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
                sfx_play_sound(SOUND_OMO_BOX_CHIME_1);
            } else if (data->timeLeft == 600) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_1);
            } else if (data->timeLeft == 450) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_1);
            } else if (data->timeLeft == 300) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_2);
            } else if (data->timeLeft == 270) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_2);
            } else if (data->timeLeft == 240) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_2);
            } else if (data->timeLeft == 210) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_2);
            } else if (data->timeLeft == 180) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_2);
            } else if (data->timeLeft == 150) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_3);
            } else if (data->timeLeft == 120) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_3);
            } else if (data->timeLeft == 90) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_3);
            } else if (data->timeLeft == 60) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_3);
            } else if (data->timeLeft == 30) {
                sfx_play_sound(SOUND_OMO_BOX_CHIME_3);
            }
        }
        if ((data->timeLeft > 0) && (data->found == NUM_PANELS)) {
            if (!(data->stunFlags & STUN_FLAG_STUNNED)) {
                data->stunFlags |= (STUN_FLAG_STUNNED | STUN_FLAG_CHANGED);
            }
        }
    }
    if ((data->timeLeft == 0) && hittingPeachBlock) {
        if (!(data->stunFlags & STUN_FLAG_STUNNED)) {
            data->stunFlags |= (STUN_FLAG_STUNNED | STUN_FLAG_CHANGED);
        }
    }
    if (data->stunFlags & STUN_FLAG_CHANGED) {
        data->stunFlags &= ~STUN_FLAG_CHANGED;
        if (data->stunFlags & STUN_FLAG_STUNNED) {
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
        if (data->stunFlags & STUN_FLAG_STUNNED) {
            enable_player_input();
            partner_enable_input();
        }
        data->stunFlags = 0;

        gPlayerStatusPtr->targetYaw = 180.0;
        if (data->timeLeft == 0) {
            sfx_play_sound(SOUND_MENU_ERROR);
            gPlayerStatusPtr->anim = ANIM_Mario1_Idle;
        } else {
            sfx_play_sound(SOUND_JINGLE_WON_BATTLE);
            gPlayerStatusPtr->anim = ANIM_Mario1_Idle;
        }

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#endif

API_CALLABLE(N(UpdateRecords)) {
    PlayerData* playerData = &gPlayerData;
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 seconds, deciseconds;
    s32 outScore;

    seconds = data->timeLeft  / FRAME_RATE;
    deciseconds = ((f32)(data->timeLeft % FRAME_RATE) * 10.0) / FRAME_RATE;

    data->curScore = (seconds * 10) + deciseconds;
    playerData->smashGameTotal += data->curScore;

    if (playerData->smashGameTotal > 99999) {
        playerData->smashGameTotal = 99999;
    }
    if (playerData->smashGameRecord < data->curScore) {
        playerData->smashGameRecord = data->curScore;
    }

    set_message_int_var(seconds, 0);
    set_message_int_var(deciseconds, 1);
    set_message_int_var(data->curScore, 2);

    outScore = data->curScore;
    if (data->curScore == 0 && data->found == NUM_PANELS) {
        outScore = -1;
    }
    evt_set_variable(script, LVar0, outScore);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GiveCoinReward)) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];
    s32 coinsLeft = data->curScore;
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

    data->curScore -= increment;
    add_coins(increment);
    sfx_play_sound(SOUND_COIN_PICKUP);

    return (data->curScore > 0) ? ApiStatus_BLOCK : ApiStatus_DONE2;
}

API_CALLABLE(N(CleanupGame)) {
    Enemy* enemy = get_enemy(SCOREKEEPER_ENEMY_IDX);
    SmashGameData* data = enemy->varTablePtr[SMASH_DATA_VAR_IDX];
    Npc* npc;
    u32 screenX, screenY,screenZ;
    EffectInstance* writeback;
    s32 i;

    if (enemy->varTable[3] == 4) {
        for (i = 0; i < NUM_BOXES; i++) {
            if (data->box[i].npcID == -1) {
                continue;
            }
            enemy = get_enemy(data->box[i].npcID);
            npc = get_npc_unsafe(enemy->npcID);
            if ((npc->flags & NPC_FLAG_INVISIBLE)) {
                continue;
            }

            get_screen_coords(CAM_DEFAULT, npc->pos.x, npc->pos.y, npc->pos.z, &screenX, &screenY, &screenZ);
            if (screenX - 1 < SCREEN_WIDTH - 1) {
                fx_walking_dust(1, npc->pos.x, npc->pos.y, npc->pos.z, 0, 0);
                sfx_play_sound(SOUND_KOOPER_SHELL_KICK);
            }
            npc->flags |= NPC_FLAG_INVISIBLE;
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
            if ((npc->flags & NPC_FLAG_INVISIBLE)) {
                continue;
            }

            switch (data->box[i].content) {
                case BOX_CONTENT_FUZZY:
                    if (data->box[i].state != BOX_STATE_FUZZY_END) {
                        data->box[i].state = BOX_STATE_FUZZY_END;
                        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 30, &writeback);
                        npc->curAnim = ANIM_Fuzzy_Sleep;
                        enable_npc_shadow(npc);
                    }
                    break;

                case BOX_CONTENT_BOMB:
                    if (data->box[i].state != BOX_STATE_BOMB_END) {
                        data->box[i].state = BOX_STATE_BOMB_END;
                        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, 0.0f, 30, &writeback);
                        npc->curAnim = ANIM_Bobomb_Dizzy;
                        enable_npc_shadow(npc);
                    }
                    break;
            }
        }
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(CreateMinigame)) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    SmashGameData* data = heap_malloc(sizeof(*data));
    scorekeeper->varTablePtr[SMASH_DATA_VAR_IDX] = data;

    data->windowA_posX = -80;
    data->windowB_posX = SCREEN_WIDTH;
    data->timeLeft = PLAY_TIME;

    status_bar_ignore_changes();
    close_status_bar();

    return ApiStatus_DONE2;
}

API_CALLABLE(N(DestroyMinigame)) {
    SmashGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[SMASH_DATA_VAR_IDX];

    free_worker(data->workerID);
    hud_element_free(data->hudElemID_AButton);
    hud_element_free(data->hudElemID_Meter);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetCoinCount)) {
    evt_set_variable(script, LVarA, gPlayerData.coins);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(TakeCoinCost)) {
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        playerData->smashGamePlays++;
        script->functionTemp[0] = 0;
    }
    add_coins(-1);
    sfx_play_sound(SOUND_COIN_PICKUP);

    script->functionTemp[0]++;
    return (script->functionTemp[0] == PLAY_COST) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

API_CALLABLE(N(HideCoinCounter)) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Dummy) = {
    Return
    End
};

#include "world/common/npc/Toad_Stationary.inc.c"
#include "world/common/npc/Luigi.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"
#include "world/common/enemy/Bobomb.inc.c"

s32 N(InitialConfigurations)[3][NUM_BOXES] = {
    { 2, 0, 2, 0, 2, 3, 3, 3, 3, 3, 2, 3, 2, 1, 3, 3, 2, 3, 0, 3, 3, 2, 3, 3, 1, 2, 3, 3, 2, 3, 3, 1, 3, 3, 2 },
    { 2, 0, 2, 1, 2, 3, 2, 3, 3, 3, 3, 1, 3, 2, 3, 0, 3, 3, 3, 3, 3, 2, 3, 2, 3, 3, 1, 0, 3, 2, 3, 3, 2, 3, 2 },
    { 3, 3, 0, 3, 3, 1, 0, 1, 2, 3, 3, 3, 2, 3, 0, 3, 2, 2, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 3, 3, 2, 3, 1, 3, 3 },
};

s32 N(BoxModelIDs)[NUM_BOXES] = {
    MODEL_a1, MODEL_b1, MODEL_c1, MODEL_d1, MODEL_e1, MODEL_f1, MODEL_g1,
    MODEL_a2, MODEL_b2, MODEL_c2, MODEL_d2, MODEL_e2, MODEL_f2, MODEL_g2,
    MODEL_a3, MODEL_b3, MODEL_c3, MODEL_d3, MODEL_e3, MODEL_f3, MODEL_g3,
    MODEL_a4, MODEL_b4, MODEL_c4, MODEL_d4, MODEL_e4, MODEL_f4, MODEL_g4,
    MODEL_a5, MODEL_b5, MODEL_c5, MODEL_d5, MODEL_e5, MODEL_f5, MODEL_g5,
};

s32 N(BoxColliderIDs)[NUM_BOXES] = {
    COLLIDER_a1, COLLIDER_b1, COLLIDER_c1, COLLIDER_d1, COLLIDER_e1, COLLIDER_f1, COLLIDER_g1,
    COLLIDER_a2, COLLIDER_b2, COLLIDER_c2, COLLIDER_d2, COLLIDER_e2, COLLIDER_f2, COLLIDER_g2,
    COLLIDER_a3, COLLIDER_b3, COLLIDER_c3, COLLIDER_d3, COLLIDER_e3, COLLIDER_f3, COLLIDER_g3,
    COLLIDER_a4, COLLIDER_b4, COLLIDER_c4, COLLIDER_d4, COLLIDER_e4, COLLIDER_f4, COLLIDER_g4,
    COLLIDER_a5, COLLIDER_b5, COLLIDER_c5, COLLIDER_d5, COLLIDER_e5, COLLIDER_f5, COLLIDER_g5,
};

s32 N(PanelModelIDs)[NUM_PANELS] = {
    MODEL_o50, MODEL_o51, MODEL_o52, MODEL_o53, MODEL_o54,
    MODEL_o55, MODEL_o56, MODEL_o57, MODEL_o58, MODEL_o59
};

#if VERSION_PAL
s32 N(pal_variable) = 0;
#endif

EvtScript N(EVS_CreateScoreDisplay) = {
    Call(N(CreateScoreDisplay))
    Return
    End
};

EvtScript N(read_sign_instructions) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(SetMsgImgs_Panel))
    Call(ShowMessageAtScreenPos, MSG_MGM_0046, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_ShowBox) = {
    Call(EnableModel, LVar0, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar1, COLLIDER_FLAGS_UPPER_MASK)
    Call(TranslateModel, LVar0, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_MakeBoxAppear) = {
    Exec(N(EVS_ShowBox))
    Set(LVarA, -25)
    Loop(13)
        Add(LVarA, 2)
        Call(TranslateModel, LVar0, 0, LVarA, 0)
        Wait(1)
    EndLoop
    Call(TranslateModel, LVar0, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_HideBox) = {
    Call(TranslateModel, LVar0, 0, 0, 0)
    Call(EnableModel, LVar0, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar1, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_HideBoxWithSmoke) = {
    Exec(N(EVS_HideBox))
    Wait(1)
    Call(GetColliderCenter, LVar1)
    Sub(LVar1, 5)
    PlayEffect(EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2)
    Return
    End
};

EvtScript N(EVS_HideAllBoxes) = {
    Set(LVar0, MODEL_a1)
    Set(LVar1, MODEL_a1)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_a2)
    Set(LVar1, MODEL_a2)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_a3)
    Set(LVar1, MODEL_a3)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_a4)
    Set(LVar1, MODEL_a4)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_a5)
    Set(LVar1, MODEL_a5)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_b1)
    Set(LVar1, MODEL_b1)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_b2)
    Set(LVar1, MODEL_b2)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_b3)
    Set(LVar1, MODEL_b3)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_b4)
    Set(LVar1, MODEL_b4)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_b5)
    Set(LVar1, MODEL_b5)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_c1)
    Set(LVar1, MODEL_c1)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_c2)
    Set(LVar1, MODEL_c2)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_c3)
    Set(LVar1, MODEL_c3)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_c4)
    Set(LVar1, MODEL_c4)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_c5)
    Set(LVar1, MODEL_c5)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_d1)
    Set(LVar1, MODEL_d1)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_d2)
    Set(LVar1, MODEL_d2)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_d3)
    Set(LVar1, MODEL_d3)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_d4)
    Set(LVar1, MODEL_d4)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_d5)
    Set(LVar1, MODEL_d5)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_e1)
    Set(LVar1, MODEL_e1)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_e2)
    Set(LVar1, MODEL_e2)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_e3)
    Set(LVar1, MODEL_e3)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_e4)
    Set(LVar1, MODEL_e4)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_e5)
    Set(LVar1, MODEL_e5)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_f1)
    Set(LVar1, MODEL_f1)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_f2)
    Set(LVar1, MODEL_f2)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_f3)
    Set(LVar1, MODEL_f3)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_f4)
    Set(LVar1, MODEL_f4)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_f5)
    Set(LVar1, MODEL_f5)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_g1)
    Set(LVar1, MODEL_g1)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_g2)
    Set(LVar1, MODEL_g2)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_g3)
    Set(LVar1, MODEL_g3)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_g4)
    Set(LVar1, MODEL_g4)
    Exec(N(EVS_HideBox))
    Set(LVar0, MODEL_g5)
    Set(LVar1, MODEL_g5)
    Exec(N(EVS_HideBox))
    Return
    End
};

EvtScript N(EVS_HideAllBoxesWithSmoke) = {
    Set(LVar0, MODEL_a1)
    Set(LVar1, MODEL_a1)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_a2)
    Set(LVar1, MODEL_a2)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_a3)
    Set(LVar1, MODEL_a3)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_a4)
    Set(LVar1, MODEL_a4)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_a5)
    Set(LVar1, MODEL_a5)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_b1)
    Set(LVar1, MODEL_b1)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_b2)
    Set(LVar1, MODEL_b2)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_b3)
    Set(LVar1, MODEL_b3)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_b4)
    Set(LVar1, MODEL_b4)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_b5)
    Set(LVar1, MODEL_b5)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_c1)
    Set(LVar1, MODEL_c1)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_c2)
    Set(LVar1, MODEL_c2)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_c3)
    Set(LVar1, MODEL_c3)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_c4)
    Set(LVar1, MODEL_c4)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_c5)
    Set(LVar1, MODEL_c5)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_d1)
    Set(LVar1, MODEL_d1)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_d2)
    Set(LVar1, MODEL_d2)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_d3)
    Set(LVar1, MODEL_d3)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_d4)
    Set(LVar1, MODEL_d4)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_d5)
    Set(LVar1, MODEL_d5)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_e1)
    Set(LVar1, MODEL_e1)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_e2)
    Set(LVar1, MODEL_e2)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_e3)
    Set(LVar1, MODEL_e3)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_e4)
    Set(LVar1, MODEL_e4)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_e5)
    Set(LVar1, MODEL_e5)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_f1)
    Set(LVar1, MODEL_f1)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_f2)
    Set(LVar1, MODEL_f2)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_f3)
    Set(LVar1, MODEL_f3)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_f4)
    Set(LVar1, MODEL_f4)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_f5)
    Set(LVar1, MODEL_f5)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_g1)
    Set(LVar1, MODEL_g1)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_g2)
    Set(LVar1, MODEL_g2)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_g3)
    Set(LVar1, MODEL_g3)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_g4)
    Set(LVar1, MODEL_g4)
    Exec(N(EVS_HideBoxWithSmoke))
    Set(LVar0, MODEL_g5)
    Set(LVar1, MODEL_g5)
    Exec(N(EVS_HideBoxWithSmoke))
    Return
    End
};

EvtScript N(EVS_MakeAllBoxesAppear) = {
    Set(LVar0, MODEL_a1)
    Set(LVar1, MODEL_a1)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_a2)
    Set(LVar1, MODEL_a2)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_a3)
    Set(LVar1, MODEL_a3)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_a4)
    Set(LVar1, MODEL_a4)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_a5)
    Set(LVar1, MODEL_a5)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_b1)
    Set(LVar1, MODEL_b1)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_b2)
    Set(LVar1, MODEL_b2)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_b3)
    Set(LVar1, MODEL_b3)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_b4)
    Set(LVar1, MODEL_b4)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_b5)
    Set(LVar1, MODEL_b5)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_c1)
    Set(LVar1, MODEL_c1)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_c2)
    Set(LVar1, MODEL_c2)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_c3)
    Set(LVar1, MODEL_c3)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_c4)
    Set(LVar1, MODEL_c4)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_c5)
    Set(LVar1, MODEL_c5)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_d1)
    Set(LVar1, MODEL_d1)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_d2)
    Set(LVar1, MODEL_d2)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_d3)
    Set(LVar1, MODEL_d3)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_d4)
    Set(LVar1, MODEL_d4)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_d5)
    Set(LVar1, MODEL_d5)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_e1)
    Set(LVar1, MODEL_e1)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_e2)
    Set(LVar1, MODEL_e2)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_e3)
    Set(LVar1, MODEL_e3)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_e4)
    Set(LVar1, MODEL_e4)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_e5)
    Set(LVar1, MODEL_e5)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_f1)
    Set(LVar1, MODEL_f1)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_f2)
    Set(LVar1, MODEL_f2)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_f3)
    Set(LVar1, MODEL_f3)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_f4)
    Set(LVar1, MODEL_f4)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_f5)
    Set(LVar1, MODEL_f5)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_g1)
    Set(LVar1, MODEL_g1)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_g2)
    Set(LVar1, MODEL_g2)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_g3)
    Set(LVar1, MODEL_g3)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_g4)
    Set(LVar1, MODEL_g4)
    Exec(N(EVS_MakeBoxAppear))
    Set(LVar0, MODEL_g5)
    Set(LVar1, MODEL_g5)
    Exec(N(EVS_MakeBoxAppear))
    Return
    End
};

EvtScript N(EVS_HidePeachPanels) = {
    Call(EnableModel, MODEL_o50, FALSE)
    Call(EnableModel, MODEL_o51, FALSE)
    Call(EnableModel, MODEL_o52, FALSE)
    Call(EnableModel, MODEL_o53, FALSE)
    Call(EnableModel, MODEL_o54, FALSE)
    Call(EnableModel, MODEL_o55, FALSE)
    Call(EnableModel, MODEL_o56, FALSE)
    Call(EnableModel, MODEL_o57, FALSE)
    Call(EnableModel, MODEL_o58, FALSE)
    Call(EnableModel, MODEL_o59, FALSE)
    Return
    End
};

EvtScript N(EVS_OnHitBox) = {
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Call(N(OnHitBox))
    Call(GetColliderCenter, LVarB)
    Switch(LVarC)
        CaseEq(2)
            Add(LVar1, 2)
            PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 25)
        CaseEq(3)
            Call(TranslateModel, LVarA, 0, -9, 0)
            Wait(1)
            Call(TranslateModel, LVarA, 0, -15, 0)
            Wait(1)
            Call(TranslateModel, LVarA, 0, -21, 0)
            Wait(1)
            Call(EnableModel, LVarA, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, COLLIDER_FLAGS_UPPER_MASK)
            Wait(4)
            Sub(LVar1, 5)
            PlayEffect(EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2)
        CaseOrEq(0)
        CaseOrEq(1)
            Sub(LVar1, 5)
            PlayEffect(EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2)
        EndCaseGroup
    EndSwitch
    Call(EnableModel, LVarA, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVarB, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(D_802441E4_E19F64) = {
    Set(LVar0, MODEL_a1)
    Set(LVar1, MODEL_a1)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_a2)
    Set(LVar1, MODEL_a2)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_a3)
    Set(LVar1, MODEL_a3)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_a4)
    Set(LVar1, MODEL_a4)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_a5)
    Set(LVar1, MODEL_a5)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_b1)
    Set(LVar1, MODEL_b1)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_b2)
    Set(LVar1, MODEL_b2)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_b3)
    Set(LVar1, MODEL_b3)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_b4)
    Set(LVar1, MODEL_b4)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_b5)
    Set(LVar1, MODEL_b5)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_c1)
    Set(LVar1, MODEL_c1)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_c2)
    Set(LVar1, MODEL_c2)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_c3)
    Set(LVar1, MODEL_c3)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_c4)
    Set(LVar1, MODEL_c4)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_c5)
    Set(LVar1, MODEL_c5)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_d1)
    Set(LVar1, MODEL_d1)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_d2)
    Set(LVar1, MODEL_d2)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_d3)
    Set(LVar1, MODEL_d3)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_d4)
    Set(LVar1, MODEL_d4)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_d5)
    Set(LVar1, MODEL_d5)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_e1)
    Set(LVar1, MODEL_e1)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_e2)
    Set(LVar1, MODEL_e2)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_e3)
    Set(LVar1, MODEL_e3)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_e4)
    Set(LVar1, MODEL_e4)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_e5)
    Set(LVar1, MODEL_e5)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_f1)
    Set(LVar1, MODEL_f1)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_f2)
    Set(LVar1, MODEL_f2)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_f3)
    Set(LVar1, MODEL_f3)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_f4)
    Set(LVar1, MODEL_f4)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_f5)
    Set(LVar1, MODEL_f5)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_g1)
    Set(LVar1, MODEL_g1)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_g2)
    Set(LVar1, MODEL_g2)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_g3)
    Set(LVar1, MODEL_g3)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_g4)
    Set(LVar1, MODEL_g4)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Set(LVar0, MODEL_g5)
    Set(LVar1, MODEL_g5)
    BindTrigger(Ref(N(EVS_OnHitBox)), TRIGGER_WALL_HAMMER, LVar1, 1, 0)
    Return
    End
};

EvtScript N(EVS_SetBoxContents) = {
    Call(N(SetBoxContents))
    Return
    End
};

EvtScript N(EVS_CleanupGame) = {
    Call(N(CleanupGame))
    Return
    End
};

EvtScript N(EVS_Toad_GovernGame) = {
    Call(N(DisableMenus))
    Call(N(RunMinigame))
    Call(N(EnableMenus))
    Call(DisablePlayerInput, TRUE)
    Call(SetSelfVar, 3, 3)
    Call(PopSong)
    Exec(N(EVS_CleanupGame))
    Call(ShowMessageAtScreenPos, MSG_MGM_0041, 160, 40)
    Wait(5)
    Call(SetSelfVar, 3, 4)
    Exec(N(EVS_HidePeachPanels))
    Exec(N(EVS_HideAllBoxesWithSmoke))
    Wait(15)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, 358, -20, 185)
        Call(SetPanTarget, CAM_DEFAULT, 358, -20, 185)
        Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    EndThread
    Call(SetNpcFlagBits, NPC_Toad, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(N(CreateSignpost))
    PlayEffect(EFFECT_WALKING_DUST, 1, 355, 45, -175)
    Thread
        Call(SetNpcPos, NPC_Toad, 358, -20, 185)
        Call(EnableNpcShadow, NPC_Toad, TRUE)
        PlayEffect(EFFECT_WALKING_DUST, 1, 358, 5, 189)
        Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER, 0)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(GetNpcPos, NPC_Toad, LVar3, LVar4, LVar5)
    Call(GetDist2D, LVarA, LVar0, LVar2, LVar3, LVar5)
    Div(LVarA, 8)
    IfLt(LVarA, 3)
        Set(LVarA, 3)
    EndIf
    Call(PlayerMoveTo, 330, 185, LVarA)
    Call(WaitForPlayerMoveToComplete)
    Call(SetNpcFlagBits, NPC_Toad, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    Wait(5)
    Call(SetSelfVar, 3, 5)
    Call(N(UpdateRecords))
    Switch(LVar0)
        CaseEq(-1)
            Call(SetSelfVar, 3, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0043)
        CaseEq(0)
            Call(SetSelfVar, 3, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0044)
#if VERSION_PAL
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_PAL_MGM_0046)
            Call(ShowCoinCounter, TRUE)
            Wait(10)
            Call(N(GiveCoinReward))
            Wait(15)
            Call(ShowCoinCounter, FALSE)
            Call(SetSelfVar, 3, 0)
            Wait(5)
            Call(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0045)
#endif
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0042)
            Call(ShowCoinCounter, TRUE)
            Wait(10)
            Call(N(GiveCoinReward))
            Wait(15)
            Call(ShowCoinCounter, FALSE)
            Call(SetSelfVar, 3, 0)
            Wait(5)
            Call(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0045)
    EndSwitch
    Wait(5)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_InitializeMinigame) = {
    Call(N(CreateMinigame))
    Exec(N(EVS_HideAllBoxes))
    Call(N(CreateSignpost))
    Exec(N(EVS_CreateScoreDisplay))
    Exec(N(D_802441E4_E19F64))
    Exec(N(EVS_HidePeachPanels))
    Return
    End
};

EvtScript N(EVS_DestroyMinigame) = {
    Call(N(DestroyMinigame))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Toad) = {
    IfEq(GF_MGM_Met_SmashAttack, FALSE)
        Call(N(SetMsgImgs_Panel))
        Set(GF_MGM_Met_SmashAttack, TRUE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_003C)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_003D)
    EndIf
    Call(ShowCoinCounter, TRUE)
    Call(N(GetCoinCount))
    IfLt(LVarA, 10)
        Call(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_003E)
        Call(N(HideCoinCounter))
        Wait(12)
        Exec(N(EVS_DestroyMinigame))
        Call(GotoMap, Ref("mgm_00"), mgm_00_ENTRY_2)
        Wait(100)
        Return
    EndIf
    Call(ShowChoice, MSG_Choice_004F)
    Switch(LVar0)
        CaseEq(0)
            Call(GetSelfVar, 4, LVar1)
            IfLt(LVar1, 100)
                Add(LVar1, 1)
                Call(SetSelfVar, 4, LVar1)
            EndIf
            Thread
                Call(N(TakeCoinCost))
            EndThread
            Call(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_003F)
            Call(N(HideCoinCounter))
        CaseDefault
            Call(N(HideCoinCounter))
            Wait(5)
            Call(ContinueSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 0, MSG_MGM_0040)
            Exec(N(EVS_DestroyMinigame))
            Call(GotoMap, Ref("mgm_00"), mgm_00_ENTRY_2)
            Wait(100)
            Return
    EndSwitch
    Thread
        Call(DisablePartnerAI, 0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Sub(LVar2, 3)
        Call(NpcMoveTo, NPC_PARTNER, LVar0, LVar2, 10)
    EndThread
    Call(EndSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 5)
    Call(SetSelfVar, 3, 1)
    Call(PlaySoundWithVolume, SOUND_SPAWN_BLOCK, 80)
    Exec(N(EVS_MakeAllBoxesAppear))
    Exec(N(EVS_SetBoxContents))
    Wait(25)
    Thread
        Wait(12)
        PlayEffect(EFFECT_WALKING_DUST, 1, 358, -10, 185)
        Call(SetNpcPos, NPC_Toad, 358, 500, 185)
        Call(EnableNpcShadow, NPC_Toad, FALSE)
        Call(N(DestroySignpost))
        PlayEffect(EFFECT_WALKING_DUST, 1, 355, 30, -180)
    EndThread
    Call(EndSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 5)
    Call(PushSong, SONG_PLAYROOM, 0)
    Wait(8)
    Call(EndSpeech, NPC_Toad, ANIM_Toad_Red_Talk, ANIM_Toad_Red_Idle, 5)
    Call(EnablePartnerAI)
    Call(SetSelfVar, 3, 2)
    Exec(N(EVS_Toad_GovernGame))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad) = {
    Call(SetNpcPos, NPC_Toad, 358, -20, 185)
    Call(SetSelfVar, 4, 0)
    Call(SetSelfVar, 3, 0)
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Toad)))
    Return
    End
};

NpcData N(NpcData_GuideToad) = {
    .id = NPC_Toad,
    .pos = { 353.0f, -20.0f, 185.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_Toad),
    .settings = &N(NpcSettings_Toad_Stationary),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = TOAD_RED_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

EvtScript N(EVS_NpcInit_Fuzzy) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Run)
    Call(SetSelfVar, 0, 0)
    Call(GetSelfNpcID, LVar0)
    Switch(LVar0)
        CaseEq(NPC_Fuzzy_01)
            Call(SetSelfVar, 8, SOUND_FUZZY_HOP_A)
        CaseEq(NPC_Fuzzy_02)
            Call(SetSelfVar, 8, SOUND_FUZZY_HOP_B)
        CaseEq(NPC_Fuzzy_03)
            Call(SetSelfVar, 8, SOUND_FUZZY_HOP_C)
        CaseEq(NPC_Fuzzy_04)
            Call(SetSelfVar, 8, SOUND_FUZZY_HOP_A)
        CaseDefault
            Call(SetSelfVar, 8, SOUND_FUZZY_HOP_B)
    EndSwitch
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_JUMPING, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 50)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Else
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Bobomb_AngryIdle)
    Call(SetSelfVar, 0, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_JUMPING, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(GetSelfNpcID, LVar0)
    Switch(LVar0)
        CaseEq(NPC_Bobomb_01)
            Call(SetSelfVar, 8, SOUND_NPC_JUMP)
        CaseEq(NPC_Bobomb_02)
            Call(SetSelfVar, 8, SOUND_LOWER_NPC_JUMP)
        CaseEq(NPC_Bobomb_03)
            Call(SetSelfVar, 8, SOUND_NPC_JUMP)
        CaseDefault
            Call(SetSelfVar, 8, SOUND_LOWER_NPC_JUMP)
    EndSwitch
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 50)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Else
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInit_Luigi) = {
    Call(SetNpcAnimation, NPC_SELF, ANIM_Luigi_Jump)
    Call(SetSelfVar, 0, 0)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING | NPC_FLAG_JUMPING, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 50)
        Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Else
        Call(InterpNpcYaw, NPC_SELF, 270, 0)
    EndIf
    Return
    End
};

NpcData N(NpcData_Fuzzy_01) = {
    .id = NPC_Fuzzy_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Fuzzy_02) = {
    .id = NPC_Fuzzy_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Fuzzy_03) = {
    .id = NPC_Fuzzy_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Fuzzy_04) = {
    .id = NPC_Fuzzy_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Fuzzy_05) = {
    .id = NPC_Fuzzy_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Fuzzy),
    .settings = &N(NpcSettings_Fuzzy),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = FUZZY_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Bobomb_01) = {
    .id = NPC_Bobomb_01,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bobomb),
    .settings = &N(NpcSettings_Bobomb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = BOBOMB_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Bobomb_02) = {
    .id = NPC_Bobomb_02,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bobomb),
    .settings = &N(NpcSettings_Bobomb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = BOBOMB_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Bobomb_03) = {
    .id = NPC_Bobomb_03,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bobomb),
    .settings = &N(NpcSettings_Bobomb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = BOBOMB_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Bobomb_04) = {
    .id = NPC_Bobomb_04,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bobomb),
    .settings = &N(NpcSettings_Bobomb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = BOBOMB_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Bobomb_05) = {
    .id = NPC_Bobomb_05,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 0,
    .init = &N(EVS_NpcInit_Bobomb),
    .settings = &N(NpcSettings_Bobomb),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
    .drops = NO_DROPS,
    .animations = BOBOMB_ANIMS,
    .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
};

NpcData N(NpcData_Luigis)[] = {
    {
        .id = NPC_Luigi_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
    {
        .id = NPC_Luigi_10,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Luigi),
        .settings = &N(NpcSettings_Luigi),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER | ENEMY_FLAG_IGNORE_SPIN,
        .drops = NO_DROPS,
        .animations = LUIGI_ANIMS,
        .tattle = MSG_NpcTattle_MGM_SmashAttackGuide,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GuideToad)),
    NPC_GROUP(N(NpcData_Fuzzy_01)),
    NPC_GROUP(N(NpcData_Fuzzy_02)),
    NPC_GROUP(N(NpcData_Fuzzy_03)),
    NPC_GROUP(N(NpcData_Fuzzy_04)),
    NPC_GROUP(N(NpcData_Fuzzy_05)),
    NPC_GROUP(N(NpcData_Bobomb_01)),
    NPC_GROUP(N(NpcData_Bobomb_02)),
    NPC_GROUP(N(NpcData_Bobomb_03)),
    NPC_GROUP(N(NpcData_Bobomb_04)),
    NPC_GROUP(N(NpcData_Bobomb_05)),
    NPC_GROUP(N(NpcData_Luigis)),
    {}
};
