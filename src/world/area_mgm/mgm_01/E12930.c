#include "mgm_01.h"
#include "hud_element.h"
#include "effects.h"
#include "entity.h"

void delete_entity(s32 entityIndex);
void set_message_images(MessageImageData* images);

#define SCOREKEEPER_ENEMY_IDX 0
#define BROKEN_BLOCKS_VAR_IDX 2
#define TOTAL_BLOCKS_VAR_IDX 4
#define JUMP_DATA_VAR_IDX 5

#define PLAY_COST 10
#define NUM_BLOCKS 11

typedef enum JumpGamePanelType {
    PANEL_1_COIN    = 0,
    PANEL_5_COINS   = 1,
    PANEL_TIMES_5   = 2,
    PANEL_BOWSER    = 3
} JumpGamePanelType;

typedef enum JumpGamePanelState {
    PANEL_STATE_INIT            = 0,
    PANEL_STATE_START_ANIM      = 1,
    PANEL_STATE_EMERGE_INIT     = 2,
    PANEL_STATE_EMERGE_UPDATE   = 3,
    PANEL_STATE_HOLD_INIT       = 4,
    PANEL_STATE_HOLD_UPDATE     = 5,
    PANEL_STATE_TO_TALLY_INIT   = 6,
    PANEL_STATE_TO_TALLY_UPDATE = 7,
    PANEL_STATE_STOP_ANIM       = 8,
    PANEL_STATE_DONE            = 9
} JumpGamePanelState;

// the panels found by breaking brick blocks
typedef struct JumpGamePanel {
    /* 0x00 */ JumpGamePanelState state;
    /* 0x04 */ s32 modelID;
    /* 0x08 */ JumpGamePanelType type;
    /* 0x0C */ s32 blockPosIndex;
    /* 0x10 */ s32 tallyPosIndex;
    /* 0x14 */ s32 entityIndex;
    /* 0x18 */ s32 lerpElapsed;
    /* 0x1C */ s32 lerpDuration;
    /* 0x20 */ Vec3f curPos;
    /* 0x2C */ Vec3f startPos;
    /* 0x38 */ Vec3f endPos;
    /* 0x44 */ f32 curAngle;
    /* 0x48 */ f32 startAngle;
    /* 0x4C */ f32 endAngle;
    /* 0x50 */ f32 curScale;
    /* 0x50 */ f32 startScale;
    /* 0x50 */ f32 endScale;
} JumpGamePanel; /* size = 5C */

typedef struct JumpGameData {
    /* 0x000 */ s32 workerID;
    /* 0x004 */ s32 hudElemID;
    /* 0x008 */ s32 unk_08; // unused -- likely hudElemID for an unused/removed hud element
    /* 0x00C */ s32 currentScore;
    /* 0x010 */ s32 targetScore;
    /* 0x014 */ s32 scoreWindowPosX;
    /* 0x018 */ s32 scoreWindowPosY; // unused -- posY is hard-coded while drawing the box
    /* 0x01C */ s32 type[NUM_BLOCKS];
    /* 0x048 */ s32 breakHistory[NUM_BLOCKS];
    /* 0x074 */ JumpGamePanel panels[NUM_BLOCKS];
} JumpGameData; /* size = 0x468 */

extern s32 MessagePlural;
extern s32 MessageSingular;
extern MessageImageData N(MsgImgs_Panels);

extern s8 N(BlockPosX)[NUM_BLOCKS];
extern s8 N(BlockPosY)[NUM_BLOCKS];
extern s8 N(BlockPosZ)[NUM_BLOCKS];

extern f32 N(TallyPosX)[NUM_BLOCKS];
extern f32 N(TallyPosY)[NUM_BLOCKS];

extern s32 N(PanelModelIDs)[NUM_BLOCKS];
extern JumpGamePanelType N(PanelTypes)[NUM_BLOCKS];

extern JumpGamePanelType N(InitialConfigurations)[4][NUM_BLOCKS];
extern EvtScript* D_802435E8_E15D48[NUM_BLOCKS];

extern EvtScript D_80242310;
extern EvtScript D_80242330;
extern EvtScript D_80242350;
extern EvtScript D_80242370;
extern EvtScript D_80242390;
extern EvtScript D_802423B0;
extern EvtScript D_802423D0;
extern EvtScript D_802423F0;
extern EvtScript D_80242410;
extern EvtScript D_80242430;
extern EvtScript D_80242450;

void N(draw_score_display) (void* renderData) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    JumpGameData* data = (JumpGameData*)scorekeeper->varTable[JUMP_DATA_VAR_IDX];
    s32 hudElemID;
    s32 diff;

    if (scorekeeper->varTable[BROKEN_BLOCKS_VAR_IDX] == -1) {
        if (data->scoreWindowPosX < SCREEN_WIDTH + 1) {
            data->scoreWindowPosX += 10;
            if (data->scoreWindowPosX > SCREEN_WIDTH + 1) {
                data->scoreWindowPosX = SCREEN_WIDTH + 1;
            }
        }
    } else {
        if (data->scoreWindowPosX > 220) {
            data->scoreWindowPosX -= 10;
            if (data->scoreWindowPosX < 220) {
                data->scoreWindowPosX = 220;
            }
        }
    }

    if (data->scoreWindowPosX < SCREEN_WIDTH + 1) {
        draw_box(0, 9, data->scoreWindowPosX, 28, 0, 72, 20, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
        hudElemID = data->hudElemID;
        hud_element_set_render_pos(hudElemID, data->scoreWindowPosX + 15, 39);
        hud_element_draw_clipped(hudElemID);
        if (data->currentScore > data->targetScore) {
            data->currentScore = data->targetScore;
        } else if (data->currentScore < data->targetScore) {
            diff = data->targetScore - data->currentScore;
            if (diff > 100) {
                data->currentScore += 40;
            } else if (diff > 75) {
                data->currentScore += 35;
            } else if (diff > 50) {
                data->currentScore += 30;
            } else if (diff > 30) {
                data->currentScore += 20;
            } else if (diff > 20) {
                data->currentScore += 10;
            } else if (diff > 10) {
                data->currentScore += 5;
            } else if (diff > 5) {
                data->currentScore += 2;
            } else {
                data->currentScore++;
            }
            sfx_play_sound_with_params(SOUND_211, 0, 0x40, 0x32);

        }
        draw_number(data->currentScore, data->scoreWindowPosX + 63, 32, 1, 0, 255, 3);
    }
}

void N(work_draw_score)(void) {
    RenderTask task;

    task.renderMode = RENDER_MODE_2D;
    task.appendGfxArg = 0;
    task.appendGfx = &mgm_01_draw_score_display;
    task.distance = 0;

    queue_render_task(&task);
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

// arg0: index
ApiStatus N(GetPanelInfo)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    evt_set_variable(script, LVar0, data->panels[index].state);
    evt_set_variable(script, LVar1, data->panels[index].modelID);
    evt_set_variable(script, LVar2, data->panels[index].type);
    evt_set_variable(script, LVar3, data->panels[index].tallyPosIndex);

    return ApiStatus_DONE2;
}

// arg0: index, arg1: newState
ApiStatus N(SetPanelState)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 value = evt_get_variable(script, *args++);

    data->panels[index].state = value;

    return ApiStatus_DONE2;
}

// arg0: index, arg1: newState
ApiStatus N(InitPanelEmergeFromBlock)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 blockPosIndex;

    data->panels[index].lerpElapsed = 0;
    data->panels[index].lerpDuration = 5;

    blockPosIndex = data->panels[index].blockPosIndex;

    data->panels[index].curPos.x = N(BlockPosX)[blockPosIndex];
    data->panels[index].curPos.y = N(BlockPosY)[blockPosIndex] + 15.0;
    data->panels[index].curPos.z = N(BlockPosZ)[blockPosIndex] + 12;

    data->panels[index].startPos.x = data->panels[index].curPos.x;
    data->panels[index].startPos.y = data->panels[index].curPos.y;
    data->panels[index].startPos.z = data->panels[index].curPos.z;

    data->panels[index].endPos.x = data->panels[index].curPos.x;
    data->panels[index].endPos.y = data->panels[index].curPos.y + 35.0;
    data->panels[index].endPos.z = data->panels[index].curPos.z;

    data->panels[index].curAngle = 0;

    data->panels[index].endScale = 2.0;
    data->panels[index].curScale = 1.0;
    data->panels[index].startScale = 1.0;

    return ApiStatus_DONE2;
}

// arg0: index
ApiStatus N(UpdatePanelEmergeFromBlock)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    data->panels[index].curPos.x = update_lerp(EASING_QUADRATIC_OUT,
        data->panels[index].startPos.x, data->panels[index].endPos.x,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].curPos.y = update_lerp(EASING_QUADRATIC_OUT,
        data->panels[index].startPos.y, data->panels[index].endPos.y,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].curPos.z = update_lerp(EASING_QUADRATIC_OUT,
        data->panels[index].startPos.z, data->panels[index].endPos.z,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].curScale = update_lerp(EASING_LINEAR,
        data->panels[index].startScale, data->panels[index].endScale,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].lerpElapsed++;

    if (data->panels[index].lerpElapsed >= data->panels[index].lerpDuration) {
        evt_set_variable(script, LVar3, TRUE);
    } else {
        evt_set_variable(script, LVar3, FALSE);
    }

    return ApiStatus_DONE2;
}

// arg0: index
ApiStatus N(InitPanelHoldAboveBlock)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    data->panels[index].lerpElapsed = 0;
    data->panels[index].lerpDuration = 10;

    return ApiStatus_DONE2;
}

// arg0: index
ApiStatus N(UpdatetPanelHoldAboveBlock)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    data->panels[index].lerpElapsed++;
    if (data->panels[index].lerpElapsed >= data->panels[index].lerpDuration) {
        evt_set_variable(script, LVar3, TRUE);
    } else {
        evt_set_variable(script, LVar3, FALSE);
    }

    return ApiStatus_DONE2;
}

// arg0: index, arg1: newState
ApiStatus N(InitPanelMoveToTally)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    f32 dist;

    data->panels[index].lerpElapsed = 0;
    data->panels[index].curAngle = 0;
    data->panels[index].startAngle = 0;
    data->panels[index].startPos.x = data->panels[index].curPos.x;
    data->panels[index].startPos.y = data->panels[index].curPos.y;
    data->panels[index].startPos.z = data->panels[index].curPos.z;
    data->panels[index].startScale = data->panels[index].curScale;

    if (data->panels[index].type != PANEL_BOWSER) {
        data->panels[index].endPos.x = N(TallyPosX)[data->panels[index].tallyPosIndex];
        data->panels[index].endPos.y = N(TallyPosY)[data->panels[index].tallyPosIndex];
        data->panels[index].endPos.z = 110.0f;
        data->panels[index].endAngle = 360.0f;
        data->panels[index].endScale = 1.0f;
    } else {
        data->panels[index].endPos.x = 0;
        data->panels[index].endPos.y = 100.0f;
        data->panels[index].endPos.z = 120.0f;
        data->panels[index].endAngle = 720.0f;
        data->panels[index].endScale = 4.0f;
    }

    dist = dist3D(
        data->panels[index].startPos.x, data->panels[index].startPos.y, data->panels[index].startPos.z,
        data->panels[index].endPos.x, data->panels[index].endPos.y, data->panels[index].endPos.z);
    if (data->panels[index].type != PANEL_BOWSER) {
        data->panels[index].lerpDuration = (dist * 0.125) + 0.5;
    } else {
        data->panels[index].lerpDuration = (dist / 5.0) + 0.5;
    }

    return ApiStatus_DONE2;
}

// arg0: index
ApiStatus N(UpdatePanelMoveToTally)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    data->panels[index].lerpElapsed++;

    data->panels[index].curPos.x = update_lerp(EASING_QUADRATIC_OUT,
        data->panels[index].startPos.x, data->panels[index].endPos.x,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].curPos.y = update_lerp(EASING_QUADRATIC_OUT,
        data->panels[index].startPos.y, data->panels[index].endPos.y,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].curPos.z = update_lerp(EASING_LINEAR,
        data->panels[index].startPos.z, data->panels[index].endPos.z,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].curAngle = update_lerp(EASING_LINEAR,
        data->panels[index].startAngle, data->panels[index].endAngle,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    data->panels[index].curScale = update_lerp(EASING_LINEAR,
        data->panels[index].startScale, data->panels[index].endScale,
        data->panels[index].lerpElapsed, data->panels[index].lerpDuration);

    if (data->panels[index].lerpElapsed >= data->panels[index].lerpDuration) {
        evt_set_variable(script, LVar3, TRUE);
    } else {
        evt_set_variable(script, LVar3, FALSE);
    }

    return ApiStatus_DONE2;
}

// arg0: index
ApiStatus N(EndPanelAnimation)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    data->panels[index].curAngle = 0;

    return ApiStatus_DONE2;
}

ApiStatus N(UpdateRecords)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    PlayerData* player = &gPlayerData;

    player->jumpGameTotal += data->currentScore;
    if (player->jumpGameTotal > 99999) {
        player->jumpGameTotal = 99999;
    }
    if (player->jumpGameRecord < data->currentScore) {
        player->jumpGameRecord = data->currentScore;
    }
    set_message_value(data->currentScore, 0);

    return ApiStatus_DONE2;
}

ApiStatus N(GiveCoinReward)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
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
    data->targetScore = data->currentScore;
    sfx_play_sound(SOUND_211);

    if (data->currentScore > 0) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

ApiStatus N(DoubleScore)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 score = 2 * data->currentScore;
    data->currentScore = score;
    data->targetScore = score;

    return ApiStatus_DONE2;
}

ApiStatus N(EndBowserPanelAnimation)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 i;

    for (i = 0; i < ARRAY_COUNT(data->panels); i++) {
        if (data->panels[i].type == PANEL_BOWSER && data->panels[i].state == PANEL_STATE_DONE)
            break;
    }

    data->panels[i].curPos.x = N(TallyPosX)[data->panels[i].tallyPosIndex];
    data->panels[i].curPos.y = N(TallyPosY)[data->panels[i].tallyPosIndex];
    data->panels[i].curPos.z = 110.0f;

    evt_set_variable(script, LVar1, data->panels[i].modelID);
    evt_set_float_variable(script, LVar5, data->panels[i].curPos.x);
    evt_set_float_variable(script, LVar6, data->panels[i].curPos.y);
    evt_set_float_variable(script, LVar7, data->panels[i].curPos.z);

    return ApiStatus_DONE2;
}

// arg0: index
ApiStatus N(GetPanelPos)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);

    evt_set_float_variable(script, LVar5, data->panels[index].curPos.x);
    evt_set_float_variable(script, LVar6, data->panels[index].curPos.y);
    evt_set_float_variable(script, LVar7, data->panels[index].curPos.z);
    evt_set_float_variable(script, LVar8, data->panels[index].curAngle);
    evt_set_float_variable(script, LVar9, data->panels[index].curScale);

    return ApiStatus_DONE2;
}

ApiStatus N(DestroyBlockEntities) (Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 i;

    for (i = 0; i < ARRAY_COUNT(data->panels); i++) {
        if (data->panels[i].entityIndex >= 0) {
            fx_walking_dust(1, N(BlockPosX)[i], N(BlockPosY)[i] + 13, N(BlockPosZ)[i] + 5, 0, 0);
            delete_entity(data->panels[i].entityIndex);
        }
    }

    sfx_play_sound_with_params(SOUND_283, 0x50, 0, 0);

    return ApiStatus_DONE2;
}

ApiStatus N(OnBreakBlock)(Evt* script, s32 isInitialCall) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    JumpGameData* data = (JumpGameData*)scorekeeper->varTable[JUMP_DATA_VAR_IDX];
    Bytecode* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 blockType = data->type[index];
    s32 historyPos = scorekeeper->varTable[BROKEN_BLOCKS_VAR_IDX];
    s32 coins = 0;
    s32 i;

    data->breakHistory[historyPos] = blockType;
    data->panels[index].entityIndex = -1;

    for (i = 0; i < historyPos + 1; i++) {
        switch (data->breakHistory[i]) {
            case PANEL_1_COIN:  coins += 1; break;
            case PANEL_5_COINS: coins += 5; break;
            case PANEL_TIMES_5: coins *= 5; break;
            case PANEL_BOWSER:  sfx_play_sound(SOUND_MENU_ERROR); coins = 0; break;
        }
    }

    data->targetScore = coins;

    for (i = 0; i < ARRAY_COUNT(data->panels); i++) {
        if (blockType == data->panels[i].type && data->panels[i].state == PANEL_STATE_START_ANIM) {
                data->panels[i].state = PANEL_STATE_EMERGE_INIT;
                data->panels[i].blockPosIndex = index;
                data->panels[i].tallyPosIndex = historyPos;
                break;
        }
    }

    scorekeeper->varTable[BROKEN_BLOCKS_VAR_IDX]++;

    return ApiStatus_DONE2;
}

ApiStatus N(CreateBlockEntities)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[JUMP_DATA_VAR_IDX];
    s32 entityIndex;
    s32 initialConfiguration;
    s32 indexA, indexB;
    s32 curBlockIdx;
    s32 temp;
    s32 i;

    EvtScript* scriptArray[] = {
        &D_80242310, &D_80242330, &D_80242350, &D_80242370, &D_80242390, &D_802423B0, &D_802423D0, &D_802423F0,
        &D_80242410, &D_80242430, &D_80242450
    };

    if (isInitialCall) {
        // choose one of four initial configurations at random
        initialConfiguration = rand_int(1000) % ARRAY_COUNT(N(InitialConfigurations));
        for (i = 0; i < NUM_BLOCKS; i++) {
            data->type[i] = N(InitialConfigurations)[initialConfiguration][i];
        }

        // randomly swap 1000 pairs
        for (i = 0; i < 1000; i++) {
            indexA = rand_int(10000) % NUM_BLOCKS;
            indexB = rand_int(10000) % NUM_BLOCKS;

            if (indexA != indexB) {
                temp = data->type[indexB];
                data->type[indexB] = data->type[indexA];
                data->type[indexA] = temp;
            }
        }

        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] <= 0) {
        curBlockIdx = script->functionTemp[1];
        entityIndex = create_entity(&Entity_BrickBlock,
            N(BlockPosX)[curBlockIdx],
            N(BlockPosY)[curBlockIdx],
            N(BlockPosZ)[curBlockIdx],
            0, 0, 0, 0, MAKE_ENTITY_END);
        data->panels[curBlockIdx].entityIndex = entityIndex;
        get_entity_by_index(entityIndex)->boundScriptBytecode = scriptArray[curBlockIdx];
        fx_sparkles(FX_SPARKLES_3,
            N(BlockPosX)[curBlockIdx],
            N(BlockPosY)[curBlockIdx] + 13,
            N(BlockPosZ)[curBlockIdx] + 5,
            23.0f);
        sfx_play_sound(SOUND_213);
        script->functionTemp[0] = 3;
        script->functionTemp[1]++;
    }

    if (script->functionTemp[1] < NUM_BLOCKS) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

const char* mgm_01_str = "mgm_00";

ApiStatus N(TakeCoinCost)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        playerData->jumpGamePlays++;
        script->functionTemp[0] = 0;
    }
    add_coins(-1);
    sfx_play_sound(SOUND_211);

    script->functionTemp[0]++;

    if (script->functionTemp[0] == PLAY_COST) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus N(InitializePanels)(Evt* script, s32 isInitialCall) {
    JumpGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[JUMP_DATA_VAR_IDX];
    s32 i;

    data->currentScore = 0;
    data->targetScore = 0;

    for (i = 0; i < ARRAY_COUNT(data->panels); i++) {
        data->panels[i].state = PANEL_STATE_INIT;
        data->panels[i].modelID = N(PanelModelIDs)[i];
        data->panels[i].type = N(PanelTypes)[i];
        data->panels[i].tallyPosIndex = -1;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(CreateMinigame)(Evt* script, s32 isInitialCall) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    JumpGameData* data = general_heap_malloc(sizeof(*data));
    s32 hudElemID;

    scorekeeper->varTablePtr[JUMP_DATA_VAR_IDX] = data;
    data->workerID = create_generic_entity_world(NULL, &mgm_01_work_draw_score);

    hudElemID = hud_element_create(&HES_StatusCoin);
    data->hudElemID = hudElemID;
    hud_element_set_flags(data->hudElemID, HUD_ELEMENT_FLAGS_80);
    hud_element_set_tint(data->hudElemID, 255, 255, 255);

    data->scoreWindowPosX = SCREEN_WIDTH + 1;
    data->scoreWindowPosY = 28;
    func_800E9894();
    close_status_menu();

    return ApiStatus_DONE2;
}

ApiStatus N(DestroyMinigame) (Evt* script, s32 isInitialCall) {
    JumpGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTablePtr[JUMP_DATA_VAR_IDX];

    free_generic_entity(data->workerID);
    hud_element_free(data->hudElemID);

    return ApiStatus_DONE2;
}

ApiStatus N(GetCoinCount)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, LVarA, gPlayerData.coins);
    return ApiStatus_DONE2;
}

ApiStatus N(SetMsgVars_BlocksRemaining)(Evt* script, s32 isInitialCall) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    s32 remaining = (scorekeeper->varTable[TOTAL_BLOCKS_VAR_IDX] - scorekeeper->varTable[BROKEN_BLOCKS_VAR_IDX]) + 1;

    set_message_value(remaining, 0);
    set_message_msg((remaining == 1) ? (s32)&MessageSingular : (s32)&MessagePlural, 1);

    return ApiStatus_DONE2;
}

ApiStatus N(HideCoinCounter)(Evt* script, s32 isInitialCall) {
    hide_coin_counter_immediately();
    return ApiStatus_DONE2;
}

ApiStatus N(SetMsgImgs_Panels)(Evt* script, s32 isInitialCall) {
    set_message_images(&N(MsgImgs_Panels));
    return ApiStatus_DONE2;
}
