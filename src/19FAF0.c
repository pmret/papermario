#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"

ApiStatus func_80271210(Evt* script, s32 isInitialCall) {
    fx_debuff(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80271258(Evt* script, s32 isInitialCall) {
    fx_debuff(1, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_802712A0(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    ((DebuffFXData*)debuffEffect->data)->unk_38 = 200;
    ((DebuffFXData*)debuffEffect->data)->unk_39 = 120;
    ((DebuffFXData*)debuffEffect->data)->unk_3A = 0;
    ((DebuffFXData*)debuffEffect->data)->unk_3B = 234;
    ((DebuffFXData*)debuffEffect->data)->unk_3C = 193;
    ((DebuffFXData*)debuffEffect->data)->unk_3D = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80271328(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    ((DebuffFXData*)debuffEffect->data)->unk_38 = 60;
    ((DebuffFXData*)debuffEffect->data)->unk_39 = 160;
    ((DebuffFXData*)debuffEffect->data)->unk_3A = 0;
    ((DebuffFXData*)debuffEffect->data)->unk_3B = 90;
    ((DebuffFXData*)debuffEffect->data)->unk_3C = 240;
    ((DebuffFXData*)debuffEffect->data)->unk_3D = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802713B0(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    ((DebuffFXData*)debuffEffect->data)->unk_38 = 205;
    ((DebuffFXData*)debuffEffect->data)->unk_39 = 0;
    ((DebuffFXData*)debuffEffect->data)->unk_3A = 40;
    ((DebuffFXData*)debuffEffect->data)->unk_3B = 205;
    ((DebuffFXData*)debuffEffect->data)->unk_3C = 32;
    ((DebuffFXData*)debuffEffect->data)->unk_3D = 242;
    return ApiStatus_DONE2;
}

ApiStatus func_8027143C(Evt* script, s32 isInitialCall) {
    fx_big_snowflakes(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80271484(Evt* script, s32 isInitialCall) {
    Actor* actor = (Actor*)script->varTable[3];
    f32 temp1 = actor->size.y;
    f32 temp2 = actor->size.x / 2;

    fx_misc_particles(0, script->varTable[0], script->varTable[1], script->varTable[2], temp1, temp2, 1.0f, 10, 30);
    fx_misc_particles(1, script->varTable[0], script->varTable[1], script->varTable[2], temp1, temp2, 1.0f, 10, 30);
    return ApiStatus_DONE2;
}

ApiStatus func_80271588(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < 20; i++) {
        fx_floating_cloud_puff(0,
                               script->varTable[0] + rand_int(30) - 15,
                               script->varTable[1] + rand_int(20) - 15,
                               script->varTable[2] + 5,
                               1.0f, 25);
    }
    return ApiStatus_DONE2;
}

EvtScript DoSleepHit = {
    EVT_CALL(func_80271210)
    EVT_RETURN
    EVT_END
};

EvtScript DoDizzyHit = {
    EVT_CALL(func_80271258)
    EVT_RETURN
    EVT_END
};

EvtScript DoParalyzeHit = {
    EVT_CALL(func_802712A0)
    EVT_RETURN
    EVT_END
};

EvtScript DoPoisonHit = {
    EVT_CALL(func_80271328)
    EVT_RETURN
    EVT_END
};

EvtScript DoStopHit = {
    EVT_CALL(func_802713B0)
    EVT_RETURN
    EVT_END
};

EvtScript DoFreezeHit = {
    EVT_CALL(func_8027143C)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(func_8027143C)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(func_80271484)
    EVT_RETURN
    EVT_END
};

EvtScript DoShrinkHit = {
    EVT_CALL(func_80271588)
    EVT_RETURN
    EVT_END
};

void dispatch_damage_event_player_1(s32 damageAmount, s32 event);

void dispatch_event_player(s32 eventType) {
    Actor* player = gBattleStatus.playerActor;
    Evt* oldOnHitScript;
    s32 oldOnHitID;
    Evt* eventScript;

    player->lastEventType = eventType;

    oldOnHitScript = player->onHitScript;
    oldOnHitID = player->onHitID;

    eventScript = start_script(&HandleEvent_Player, 10, 0x20);
    player->onHitScript = eventScript;
    player->onHitID = eventScript->id;
    eventScript->owner1.actor = NULL;

    if (player->takeTurnScript != NULL) {
        kill_script_by_ID(player->takeTurnID);
        player->takeTurnScript = NULL;
    }

    if (oldOnHitScript != NULL) {
        kill_script_by_ID(oldOnHitID);
    }
}

void dispatch_event_player_continue_turn(s32 eventType) {
    Actor* player = gBattleStatus.playerActor;
    Evt* oldOnHitScript;
    s32 oldOnHitID;
    Evt* eventScript;

    player->lastEventType = eventType;

    oldOnHitScript = player->onHitScript;
    oldOnHitID = player->onHitID;

    eventScript = start_script(&HandleEvent_Player, 10, 0x20);
    player->onHitScript = eventScript;
    player->onHitID = eventScript->id;
    eventScript->owner1.actor = NULL;

    if (oldOnHitScript != NULL) {
        kill_script_by_ID(oldOnHitID);
    }
}

//INCLUDE_ASM(s32, "19FAF0", calc_player_test_enemy);
s32 calc_player_test_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    s32 targetPart = battleStatus->currentTargetPart;
    ActorState* state = &player->state;
    Actor* target;
    ActorPart* part;

    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;

    target = get_actor(currentTargetID);


    if (target == NULL) {
        return 0;
    }

    part = get_actor_part(target, targetPart);
    ASSERT(part != NULL);

    if (part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        return 6;
    } else if (target->transStatus == STATUS_E || ((part->eventFlags & ACTOR_EVENT_FLAG_800) &&
               !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE)))
    {
        return 6;
    } else if (target->stoneStatus == STATUS_STONE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return 8;
    } else if ((battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP) && (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP) &&
               !player_team_is_ability_active(player, 2))
    {
        sfx_play_sound_at_position(SOUND_108, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return 4;
    } else if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP)) &&
               (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT) &&
               (!(battleStatus->currentAttackEventSuppression & 4) &&
               !player_team_is_ability_active(player, 2)))
    {
        sfx_play_sound_at_position(SOUND_108, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        dispatch_damage_event_player_1(1, EVENT_SPIKE_CONTACT);
        dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
        return -1;
    } else if (player->staticStatus != STATUS_STATIC && target->staticStatus == STATUS_STATIC) {
        return 7;
    }

    return 0;
}

INCLUDE_ASM(s32, "19FAF0", calc_player_damage_enemy);

s32 dispatch_damage_event_player(s32 damageAmount, s32 event, s32 arg2) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    ActorState* state = &player->state;
    s32 oldHPChangeCounter;
    s32 flags;
    s32 dispatchEvent;
    s32 oldPlayerHP;
    s32 temp;

    battleStatus->currentAttackDamage = damageAmount;

    temp = (s16)damageAmount; // usage of temp here required to match
    player->hpChangeCounter += temp;

    temp = player->hpChangeCounter;
    player->currentHP = playerData->curHP;
    player->damageCounter += temp;
    player->hpChangeCounter -= temp;
    battleStatus->lastAttackDamage = 0;
    player->currentHP -= temp;
    battleStatus->damageTaken += temp;

    oldPlayerHP = player->currentHP;

    dispatchEvent = event;
    if (player->currentHP <= 0) {
        battleStatus->lastAttackDamage += oldPlayerHP;
        player->currentHP = 0;
        dispatchEvent = EVENT_DEATH;
    }
    battleStatus->lastAttackDamage += temp;
    playerData->curHP = player->currentHP;

    if (dispatchEvent == EVENT_HIT_COMBO) {
        dispatchEvent = EVENT_HIT;
    }
    if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
        dispatchEvent = EVENT_IMMUNE;
    }

    if (dispatchEvent == EVENT_DEATH) {
        if (event == EVENT_SPIKE_CONTACT) {
            dispatchEvent = EVENT_SPIKE_DEATH;
        }
        if (event == EVENT_BURN_CONTACT) {
            dispatchEvent = EVENT_BURN_DEATH;
        }
        if (event == EVENT_SHOCK_HIT) {
            dispatchEvent = EVENT_SHOCK_DEATH;
        }
    }

    if (!arg2) {
        set_goal_pos_to_part(state, ACTOR_PLAYER, 0);
        sfx_play_sound_at_position(SOUND_HIT_NORMAL, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 1);
    func_802666E4(player, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(player, 1);
    }

    flags = (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) != 0;
    dispatch_event_player(dispatchEvent);
    return flags;
}

s32 dispatch_damage_event_player_0(s32 damageAmount, s32 event) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->currentAttackElement = ELEMENT_END;
    battleStatus->unk_19A = 0;
    return dispatch_damage_event_player(damageAmount, event, FALSE);
}

void dispatch_damage_event_player_1(s32 damageAmount, s32 event) {
    dispatch_damage_event_player(damageAmount, event, TRUE);
}

ApiStatus GetMenuSelection(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;

    evt_set_variable(script, outVar1, battleStatus->moveCategory);
    evt_set_variable(script, outVar2, battleStatus->selectedItemID);
    evt_set_variable(script, outVar3, battleStatus->selectedMoveID);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_80273444);

INCLUDE_ASM(s32, "19FAF0", PlayerFallToGoal, Evt* script, s32 isInitialCall);

ApiStatus PlayerLandJump(Evt *script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;
    ActorState* walkMovement = &player->state;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        walkMovement->currentPos.x = player->currentPos.x;
        walkMovement->currentPos.y = player->currentPos.y;
        walkMovement->currentPos.z = player->currentPos.z;
        script->functionTemp[0] = 1;
    }

    if (walkMovement->velocity > 0.0f) {
        if (walkMovement->animJumpRise != 0) {
            set_animation(0, 0, walkMovement->animJumpRise);
        }
    }

    if (walkMovement->velocity < 0.0f) {
        if (walkMovement->animJumpFall != 0) {
            set_animation(0, 0, walkMovement->animJumpFall);
        }
    }

    walkMovement->currentPos.y += walkMovement->velocity;
    walkMovement->velocity -= walkMovement->acceleration;

    add_xz_vec3f(&walkMovement->currentPos, walkMovement->speed, walkMovement->angle);

    player->currentPos.x = walkMovement->currentPos.x;
    player->currentPos.y = walkMovement->currentPos.y;
    player->currentPos.z = walkMovement->currentPos.z;

    if (player->currentPos.y < 0.0f) {
        player->currentPos.y = 0.0f;

        play_movement_dust_effects(2, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
        sfx_play_sound_at_position(SOUND_SOFT_LAND, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "19FAF0", PlayerRunToGoal, Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "19FAF0", CancelablePlayerRunToGoal, Evt* script, s32 isInitialCall);

ApiStatus GetPlayerHP(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gPlayerData.curHP);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", PlayerDamageEnemy, Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "19FAF0", PlayerPowerBounceEnemy, Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "19FAF0", PlayerTestEnemy, Evt* script, s32 isInitialCall);

ApiStatus DispatchDamagePlayerEvent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (dispatch_damage_event_player_0(evt_get_variable(script, *args++), *args++) < 0) {
        return ApiStatus_BLOCK;
    }

    if (does_script_exist_by_ref(script)) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus EnablePlayerBlur(Evt* script, s32 isInitialCall) {
    s32 setting = evt_get_variable(script, *script->ptrReadPos);

    if (setting == 0) {
        disable_player_blur();
    } else if (setting == 1) {
        enable_player_blur();
    } else {
        func_80254950();
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802749D8(Evt* script, s32 isInitialCall) {
    func_802549A0();
    return ApiStatus_DONE2;
}

ApiStatus func_802749F8(Evt* script, s32 isInitialCall) {
    func_802549C0();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_80274A18);

INCLUDE_ASM(s32, "19FAF0", func_802752AC);

INCLUDE_ASM(s32, "19FAF0", func_80275F00);

ApiStatus DidActionSucceed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 actionSuccess = gBattleStatus.actionSuccess;
    s32 actionSucceeded = 0;

    if (actionSuccess < 0) {
        actionSuccess = 0;
    }

    if (actionSucceeded < actionSuccess) {
        actionSucceeded = actionSuccess;
    }

    evt_set_variable(script, outVar, actionSucceeded);
    return ApiStatus_DONE2;
}

ApiStatus func_80276EFC(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}

ApiStatus DispatchEventPlayer(Evt* script, s32 isInitialCall) {
    dispatch_event_player(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
