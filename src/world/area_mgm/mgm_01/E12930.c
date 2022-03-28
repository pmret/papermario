#include "mgm_01.h"
#include "hud_element.h"
#include "effects.h"

extern s32 MessagePlural;
extern s16 MessageSingular;

extern s32 D_80241B44_E142A4[11];
extern s32 D_80241B70_E142D0[11];

extern s8 D_80241AC8_E14228[12];
extern s8 D_80241AD4_E14234[12];
extern s8 D_80241AE0_E14240[12];

extern f32 D_80241AEC_E1424C[11];
extern f32 D_80241B18_E14278[11];

extern s32 D_80243560_E15CC0; /* TODO: assign proper type for this data */

extern s32 D_80241B9C_E142FC[4][11];
extern EntityBlueprint D_802EA0C4;
extern EvtScript* D_802435E8_E15D48[11];   /* script pointers */

#define SCOREKEEPER_ENEMY_IDX 0
#define BROKEN_BLOCKS_VAR_IDX 2
#define TOTAL_BLOCKS_VAR_IDX 4
#define JUMP_DATA_VAR_IDX 5

#define PLAY_COST 10

/* N(DrawScoreDisplay) */
void func_802401D0_E12930(void) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    JumpGameData* data = (JumpGameData*)scorekeeper->varTable[JUMP_DATA_VAR_IDX];
    s32 hudElemID;
    s32 diff;

    if (scorekeeper->varTable[2] == -1) {
        if (data->scoreWindowPosX < 321) {
            data->scoreWindowPosX += 10;
            if (data->scoreWindowPosX > 321) {
                data->scoreWindowPosX = 321;
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

    if (data->scoreWindowPosX < 321) {
        draw_box(0, 9, data->scoreWindowPosX, 0x1C, 0, 0x48, 0x14, (u8) 0xFF, (u8) 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, 0x140, 0xF0, NULL);
        hudElemID = data->hudElemID;
        hud_element_set_render_pos(hudElemID, data->scoreWindowPosX + 0xF, 0x27);
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
        draw_number(data->currentScore, data->scoreWindowPosX + 0x3F, 0x20, 1, 0, 0xFF, 3);
    }
}

/* N(draw_score_display) */
void func_802403C4_E12B24(void) {
    RenderTask task;

    task.renderMode = RENDER_MODE_2D;
    task.appendGfxArg = 0;
    task.appendGfx = &func_802401D0_E12930;
    task.distance = 0;

    queue_render_task(&task);
}

ApiStatus func_802403FC_E12B5C(Evt* script, s32 isInitialCall) {
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_MENUS;
    func_800E9894();
    close_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus func_80240438_E12B98(Evt* script, s32 isInitialCall) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_MENUS;
    return ApiStatus_DONE2;
}

ApiStatus func_8024045C_E12BBC(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);

    evt_set_variable(script, LW(0), data->arr[index].unk_00);
    evt_set_variable(script, LW(1), data->arr[index].unk_04);
    evt_set_variable(script, LW(2), data->arr[index].unk_08);
    evt_set_variable(script, LW(3), data->arr[index].unk_10);

    return ApiStatus_DONE2;
}

ApiStatus func_8024050C_E12C6C(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32* args = script->ptrReadPos;
    s32 index = evt_get_variable(script, *args++);
    s32 value = evt_get_variable(script, *args++);

    data->arr[index].unk_00 = value;

    return ApiStatus_DONE2;
}

ApiStatus func_8024058C_E12CEC(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);
    f32 x, y, z;
    s32 temp;

    data->arr[index].lerpElapsed = 0;
    data->arr[index].lerpDuration = 5;

    temp = data->arr[index].unk_0C;

    data->arr[index].unk_20 = D_80241AC8_E14228[temp];
    data->arr[index].unk_24 = D_80241AD4_E14234[temp] + 15.0;
    data->arr[index].unk_28 = D_80241AE0_E14240[temp] + 12;

    data->arr[index].unk_2C = data->arr[index].unk_20;
    data->arr[index].unk_30 = data->arr[index].unk_24;
    data->arr[index].unk_34 = data->arr[index].unk_28;

    data->arr[index].unk_38 = data->arr[index].unk_20;
    data->arr[index].unk_3C = data->arr[index].unk_24 + 35.0;
    data->arr[index].unk_40 = data->arr[index].unk_28;

    data->arr[index].unk_44 = 0;
    data->arr[index].unk_58 = 2.0;
    data->arr[index].unk_50 = 1.0;
    data->arr[index].unk_54 = 1.0;

    return ApiStatus_DONE2;
}

ApiStatus func_802406C4_E12E24(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);

    /* TODO: interp modes enum */
    data->arr[index].unk_20 = update_lerp(4, data->arr[index].unk_2C, data->arr[index].unk_38, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    data->arr[index].unk_24 = update_lerp(4, data->arr[index].unk_30, data->arr[index].unk_3C, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    data->arr[index].unk_28 = update_lerp(4, data->arr[index].unk_34, data->arr[index].unk_40, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    data->arr[index].unk_50 = update_lerp(0, data->arr[index].unk_54, data->arr[index].unk_58, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);

    data->arr[index].lerpElapsed++;

    if (data->arr[index].lerpElapsed >= data->arr[index].lerpDuration) {
        evt_set_variable(script, LW(3), TRUE);
    } else {
        evt_set_variable(script, LW(3), FALSE);
    }
   
    return ApiStatus_DONE2;
}

ApiStatus func_802407E4_E12F44(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);

    data->arr[index].lerpElapsed = 0;
    data->arr[index].lerpDuration = 0xA;

    return ApiStatus_DONE2;
}

ApiStatus func_8024084C_E12FAC(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);

    data->arr[index].lerpElapsed++;
    if ( data->arr[index].lerpElapsed >= data->arr[index].lerpDuration) {
        evt_set_variable(script, LW(3), TRUE);
    } else {
        evt_set_variable(script, LW(3), FALSE);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802408EC_E1304C(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);
    f32 dist;

    data->arr[index].lerpElapsed = 0;
    data->arr[index].unk_44 = 0;
    data->arr[index].unk_48 = 0;
    data->arr[index].unk_2C = data->arr[index].unk_20;
    data->arr[index].unk_30 = data->arr[index].unk_24;
    data->arr[index].unk_34 = data->arr[index].unk_28;
    data->arr[index].unk_54 = data->arr[index].unk_50;

    if (data->arr[index].unk_08 != 3) {
        data->arr[index].unk_38 = D_80241AEC_E1424C[data->arr[index].unk_10];
        data->arr[index].unk_3C = D_80241B18_E14278[data->arr[index].unk_10];
        data->arr[index].unk_40 = 110.0f;
        data->arr[index].unk_4C = 360.0f;
        data->arr[index].unk_58 = 1.0f;
    } else {
        data->arr[index].unk_38 = 0;
        data->arr[index].unk_3C = 100.0f;
        data->arr[index].unk_40 = 120.0f;
        data->arr[index].unk_4C = 720.0f;
        data->arr[index].unk_58 = 4.0f;
    }

    dist = dist3D(
        data->arr[index].unk_2C, data->arr[index].unk_30, data->arr[index].unk_34,
        data->arr[index].unk_38, data->arr[index].unk_3C, data->arr[index].unk_40);
    if (data->arr[index].unk_08 != 3) {
        data->arr[index].lerpDuration = (dist * 0.125) + 0.5;
    } else {
        data->arr[index].lerpDuration = (dist / 5.0) + 0.5;
    }
    
    return ApiStatus_DONE2;
}

ApiStatus func_80240AAC_E1320C(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);

    data->arr[index].lerpElapsed++;
    data->arr[index].unk_20 = update_lerp(4, data->arr[index].unk_2C, data->arr[index].unk_38, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    data->arr[index].unk_24 = update_lerp(4, data->arr[index].unk_30, data->arr[index].unk_3C, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    data->arr[index].unk_28 = update_lerp(0, data->arr[index].unk_34, data->arr[index].unk_40, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    data->arr[index].unk_44 = update_lerp(0, data->arr[index].unk_48, data->arr[index].unk_4C, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    data->arr[index].unk_50 = update_lerp(0, data->arr[index].unk_54, data->arr[index].unk_58, data->arr[index].lerpElapsed, data->arr[index].lerpDuration);
    
    if (data->arr[index].lerpElapsed >= data->arr[index].lerpDuration) {
        evt_set_variable(script, -0x01C9C37D, TRUE);
    } else {
        evt_set_variable(script, -0x01C9C37D, FALSE);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240BF4_E13354(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);

    data->arr[index].unk_44 = 0;

    return ApiStatus_DONE2;
}

ApiStatus func_80240C54_E133B4(Evt* script, s32 isInitialCall) {
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

/* N(GiveCoinReward) */
ApiStatus func_80240CD0_E13430(Evt* script, s32 isInitialCall) {
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

    return (data->currentScore > 0) ? ApiStatus_BLOCK : ApiStatus_DONE2;
}

ApiStatus func_80240D84_E134E4(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 score = 2 * data->currentScore;
    data->currentScore = score;
    data->targetScore = score;

    return ApiStatus_DONE2;
}

ApiStatus func_80240DB8_E13518(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 i;

    for(i = 0; i < ARRAY_COUNT(data->arr); i++) {
        if(data->arr[i].unk_08 == 3 && data->arr[i].unk_00 == 9)
            break;
    }

    data->arr[i].unk_20 = D_80241AEC_E1424C[data->arr[i].unk_10];
    data->arr[i].unk_24 = D_80241B18_E14278[data->arr[i].unk_10];
    data->arr[i].unk_28 = 110.0f;

    evt_set_variable(script, LW(1), data->arr[i].unk_04);
    evt_set_float_variable(script, LW(5), data->arr[i].unk_20);
    evt_set_float_variable(script, LW(6), data->arr[i].unk_24);
    evt_set_float_variable(script, LW(7), data->arr[i].unk_28);

    return ApiStatus_DONE2;
}

ApiStatus func_80240ECC_E1362C(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 index = evt_get_variable(script, *script->ptrReadPos);

    evt_set_float_variable(script, LW(5), data->arr[index].unk_20);
    evt_set_float_variable(script, LW(6), data->arr[index].unk_24);
    evt_set_float_variable(script, LW(7), data->arr[index].unk_28);
    evt_set_float_variable(script, LW(8), data->arr[index].unk_44);
    evt_set_float_variable(script, LW(9), data->arr[index].unk_50);
    
    return ApiStatus_DONE2;
}

ApiStatus func_80240F90_E136F0(Evt* script, s32 isInitialCall) {
    JumpGameData* data = (JumpGameData*)get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 i; 
    
    for(i = 0; i < ARRAY_COUNT(data->arr); i++)
    {
        if (data->arr[i].entityIndex >= 0) {
            fx_walking_dust(1, D_80241AC8_E14228[i], D_80241AD4_E14234[i] + 13, D_80241AE0_E14240[i] + 5, 0, 0);
            delete_entity(data->arr[i].entityIndex);
        }
    }

    sfx_play_sound_with_params(0x283, 0x50, 0, 0);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mgm/mgm_01/E12930", func_80241090_E137F0);

INCLUDE_ASM(s32, "world/area_mgm/mgm_01/E12930", func_80241234_E13994);

/*
ApiStatus func_80241234_E13994(Evt* script, s32 isInitialCall) {
    JumpGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    EvtScript* scriptArray[11];
    s32 entityIndex;
    s32 configuration;
    s32 indexA, indexB;
    s32 curBlockIdx;
    s32 temp;
    s32 i;
    
    memcpy(scriptArray, D_802435E8_E15D48, sizeof(D_802435E8_E15D48));

    if (isInitialCall) {
        // choose one of four initial configurations at random
        configuration = rand_int(1000) % 4;
        for(i = 0; i < 11; i++) {
            data->unk_1C[i] = D_80241B9C_E142FC[configuration][i];
        }

        // randomly swap 1000 pairs
        for(i = 0; i < 1000; i++) {
            indexA = rand_int(10000) % 11;
            indexB = rand_int(10000) % 11;

            if (indexA != indexB) {
                temp = data->unk_1C[indexB];
                data->unk_1C[indexB] = data->unk_1C[indexA];
                data->unk_1C[indexA] = temp;
            }
        }

        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
    }

    if (--script->functionTemp[0] <= 0) {
        curBlockIdx = script->functionTemp[1];
        entityIndex = create_entity(&D_802EA0C4, 
            D_80241AC8_E14228[curBlockIdx], 
            D_80241AD4_E14234[curBlockIdx], 
            D_80241AE0_E14240[curBlockIdx],
            0, 0, 0, 0, 0x80000000);
        data->arr[curBlockIdx].entityIndex = entityIndex;
        get_entity_by_index(entityIndex)->boundScriptBytecode = scriptArray[curBlockIdx];
        fx_sparkles(3, 
            D_80241AC8_E14228[curBlockIdx], 
            D_80241AD4_E14234[curBlockIdx] + 13, 
            D_80241AE0_E14240[curBlockIdx] + 5,
            23.0f);
        sfx_play_sound(0x213);
        script->functionTemp[0] = 3;
        script->functionTemp[1]++;
    }

    return (script->functionTemp[1] < 11) ? ApiStatus_BLOCK : ApiStatus_DONE2;
}
*/

/* N(TakeCoinCost) */
ApiStatus func_80241510_E13C70(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        playerData->jumpGamePlays++;
        script->functionTemp[0] = 0;
    }
    add_coins(-1);
    sfx_play_sound(SOUND_211);

    return (++script->functionTemp[0] == PLAY_COST) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

ApiStatus func_80241574_E13CD4(Evt* script, s32 isInitialCall) {
    JumpGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];
    s32 i;

    data->currentScore = 0;
    data->targetScore = 0;

    for(i = 0; i < ARRAY_COUNT(data->arr); i++) {
        data->arr[i].unk_00 = 0;
        data->arr[i].unk_04 = D_80241B44_E142A4[i];
        data->arr[i].unk_08 = D_80241B70_E142D0[i];
        data->arr[i].unk_10 = -1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802415EC_E13D4C(Evt* script, s32 isInitialCall) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    JumpGameData* data = general_heap_malloc(sizeof(JumpGameData));
    s32 hudElemID;

    scorekeeper->varTable[JUMP_DATA_VAR_IDX] = data;
    data->workerID = create_generic_entity_world(NULL, &func_802403C4_E12B24);

    hudElemID = hud_element_create(&HudScript_StatusCoin);
    data->hudElemID = hudElemID;
    hud_element_set_flags(data->hudElemID, HUD_ELEMENT_FLAGS_80);
    hud_element_set_tint(data->hudElemID, 255, 255, 255);

    data->scoreWindowPosX = 0x141;
    data->unk_18 = 0x1C;
    func_800E9894();
    close_status_menu();

    return ApiStatus_DONE2;
}

ApiStatus func_80241690_E13DF0(Evt* script, s32 isInitialCall) {
    JumpGameData* data = get_enemy(SCOREKEEPER_ENEMY_IDX)->varTable[JUMP_DATA_VAR_IDX];

    free_generic_entity(data->workerID);
    hud_element_free(data->hudElemID);

    return ApiStatus_DONE2;
}

/* N(GetCoinCount) */
ApiStatus func_802416CC_E13E2C(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, LW(0xA), gPlayerData.coins);
    return ApiStatus_DONE2;
}

/* N(SetStringVars_BlocksRemaining) */
ApiStatus func_802416F8_E13E58(Evt* script, s32 isInitialCall) {
    Enemy* scorekeeper = get_enemy(SCOREKEEPER_ENEMY_IDX);
    s32 remaining = (scorekeeper->varTable[TOTAL_BLOCKS_VAR_IDX] - scorekeeper->varTable[BROKEN_BLOCKS_VAR_IDX]) + 1;

    set_message_value(remaining, 0);
    set_message_msg((remaining == 1) ? &MessageSingular : &MessagePlural, 1);
    
    return ApiStatus_DONE2;
}

ApiStatus func_80241760_E13EC0(Evt* script, s32 isInitialCall) {
    func_800E96C8();
    return ApiStatus_DONE2;
}

ApiStatus func_80241780_E13EE0(Evt* script, s32 isInitialCall) {
    set_message_images(&D_80243560_E15CC0);
    return ApiStatus_DONE2;
}
