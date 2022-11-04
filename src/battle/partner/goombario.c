#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/npc/BattleGoombario.h"

#define NAMESPACE battle_partner_goombario

extern s32 bActorTattles[ACTOR_TYPE_COUNT];

static EffectInstance* N(tattleEffect);
static s32 N(isCharged);

extern s32 N(powerBounceChance);
extern EvtScript N(init);
extern EvtScript N(celebrate);
extern EvtScript N(executeAction);
extern EvtScript N(firstStrike);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(headbonk1);
extern EvtScript N(headbonk2);
extern EvtScript N(headbonk3);
extern EvtScript N(multibonk);
extern EvtScript N(tattle);
extern EvtScript N(charge);
extern EvtScript N(handleEvent);
extern EvtScript N(idle);
extern EvtScript N(nextTurn);
extern EvtScript N(takeTurn);

ApiStatus N(GetReturnMoveTime)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    f32 posX = partner->currentPos.x;
    f32 posY = partner->currentPos.y;
    f32 posZ = partner->currentPos.z;
    f32 goalX = partner->state.goalPos.x;
    f32 goalY = partner->state.goalPos.y;
    f32 goalZ = partner->state.goalPos.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (battleStatus->unk_83 != 0) {
        if (script->varTable[0] < 10) {
            script->varTable[0] = 10;
        }
    } else if (script->varTable[0] < 15) {
        script->varTable[0] = 15;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(AdjustPowerBounceChance)(Evt* script, s32 isInitialCall) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);

    script->varTable[0] = 99;
    N(powerBounceChance) *= targetActor->actorBlueprint->powerBounceChance;
    N(powerBounceChance) /= 100;
    if (N(powerBounceChance) < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(JumpOnTarget)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->partnerActor;
    ActorState* state = &actor->state;
    f32 stateCurrentX;
    f32 stateCurrentZ;
    f32 stateGoalX;
    f32 stateGoalZ;
    f32 oldActorY;
    f32 oldActorX;
    f64 currentPosX64;
    f64 acc1, acc2;
    f64 acc3, acc4;
    f64 vel1, vel2;
    f64 vel3, vel4;
    f32 temp;

    if (isInitialCall) {
        actor->state.moveTime = evt_get_variable(script, *args++);
        actor->state.moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[1] = 0;
        script->functionTemp[0] = 0;
        if (actor->state.moveArcAmplitude == 1) {
            script->functionTemp[0] = 2;
        }
    }

    if (script->functionTemp[0] == 0) {
        state->currentPos.x = actor->currentPos.x;
        state->currentPos.y = actor->currentPos.y;
        stateGoalX = state->goalPos.x;
        stateGoalZ = state->goalPos.z;
        stateCurrentX = state->currentPos.x;
        stateCurrentZ = actor->currentPos.z;
        state->currentPos.z = stateCurrentZ;
        state->angle = atan2(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        state->distance = dist2D(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        if (state->moveTime == 0) {
            state->moveTime = state->distance / state->speed;
            temp = state->distance - (state->moveTime * state->speed);
        } else {
            state->speed = state->distance / state->moveTime;
            temp = state->distance - (state->moveTime * state->speed);
        }

        if (state->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        state->unk_30.x = (state->goalPos.x - state->currentPos.x) / state->moveTime;
        state->unk_30.y = (state->goalPos.y - state->currentPos.y) / state->moveTime;
        state->unk_30.z = (state->goalPos.z - state->currentPos.z) / state->moveTime;
        state->acceleration = PI_S / state->moveTime;
        state->velocity = 0.0f;
        state->speed += temp / state->moveTime;

        if (state->moveArcAmplitude < 3) {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            temp = state->distance;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            state->bounceDivisor = temp;
            if (state->moveArcAmplitude == 2) {
                state->bounceDivisor *= 1.12;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            vel3 = state->velocity;
            acc3 = state->acceleration;
            state->velocity = vel3 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.53 * acc3) + acc3);
        } else {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            temp = state->distance;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            state->bounceDivisor = temp;
            if (state->moveArcAmplitude == 4) {
                state->bounceDivisor *= 1.25;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            vel4 = state->velocity;
            acc4 = state->acceleration;
            state->velocity = vel4 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.8 * acc4) + acc4);
        }
        set_animation(ACTOR_PARTNER, 1, state->animJumpRise);
        script->functionTemp[0] = 1;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (state->velocity > PI_S / 2) {
                set_animation(ACTOR_PARTNER, 1, state->animJumpFall);
            }
            oldActorX = actor->currentPos.x;
            oldActorY = actor->currentPos.y;
            state->currentPos.x += state->unk_30.x;
            state->currentPos.y = state->currentPos.y + state->unk_30.y;
            state->currentPos.z = state->currentPos.z + state->unk_30.z;
            state->unk_18.x = actor->currentPos.y;
            actor->currentPos.x = state->currentPos.x;
            actor->currentPos.y = state->currentPos.y + (state->bounceDivisor * sin_rad(state->velocity));
            actor->currentPos.z = state->currentPos.z;
            if (state->goalPos.y > actor->currentPos.y && state->moveTime < 3) {
                actor->currentPos.y = state->goalPos.y;
            }

            actor->rotation.z = -atan2(oldActorX, -oldActorY, actor->currentPos.x, -actor->currentPos.y);
            state->unk_18.y = actor->currentPos.y;
            if (state->moveArcAmplitude < 3) {
                vel1 = state->velocity;
                acc1 = state->acceleration;
                state->velocity = vel1 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.53 * acc1) + acc1);
            } else {
                vel2 = state->velocity;
                acc2 = state->acceleration;
                state->velocity = vel2 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.8 * acc2) + acc2);
            }

            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            state->moveTime--;
            if (state->moveTime == 0) {
                actor->currentPos.y = state->goalPos.y;
                state->acceleration = 1.8f;
                state->velocity = -(state->unk_18.x - state->unk_18.y);
                set_animation(ACTOR_PARTNER, 1, state->animJumpLand);
                return ApiStatus_DONE1;
            }
            break;
        case 2:
            if (battleStatus->unk_83 == 0) {
                return ApiStatus_DONE2;
            }
            state->moveTime = 1;
            state->acceleration = 1.8f;
            state->unk_24 = 90.0f;
            state->velocity = -(state->unk_18.x - state->unk_18.y);
            state->bounceDivisor = fabsf(state->unk_18.x - state->unk_18.y) / 16.5;
            state->unk_28 = 360 / state->moveTime;
            state->currentPos.x = actor->currentPos.x;
            state->currentPos.y = actor->currentPos.y;
            state->currentPos.z = actor->currentPos.z;
            script->functionTemp[0] = 3;
            // fallthrough
        case 3:
            currentPosX64 = state->currentPos.x; // required to match
            state->currentPos.x = currentPosX64 + state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24)) / 33.0;
            state->currentPos.y -= state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24));
            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            actor->currentPos.x = state->currentPos.x;
            actor->currentPos.y = state->currentPos.y;
            actor->currentPos.z = state->currentPos.z;

            if (gBattleStatus.flags1 & BS_FLAGS1_2000) {
                return ApiStatus_DONE2;
            }

            state->moveTime--;
            if (state->moveTime == 0) {
                return ApiStatus_DONE1;
            }
            break;
    }

    return ApiStatus_BLOCK;
}


ApiStatus N(OnMissHeadbonk)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = gBattleStatus.partnerActor;
    Vec3f* pos = &partner->state.currentPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        partner->state.currentPos.x = partner->currentPos.x;
        partner->state.currentPos.y = partner->currentPos.y;
        partner->state.currentPos.z = partner->currentPos.z;
        script->functionTemp[0] = 1;
    }

    if (partner->state.velocity > 0.0f) {
        set_animation(ACTOR_PARTNER, 0, partner->state.animJumpRise);
    }

    if (partner->state.velocity < 0.0f) {
        set_animation(ACTOR_PARTNER, 0, partner->state.animJumpFall);
    }

    partner->state.currentPos.y = (partner->state.currentPos.y + partner->state.velocity);
    partner->state.velocity = (partner->state.velocity - partner->state.acceleration);
    add_xz_vec3f(pos, partner->state.speed, partner->state.angle);
    partner->currentPos.x = partner->state.currentPos.x;
    partner->currentPos.y = partner->state.currentPos.y;
    partner->currentPos.z = partner->state.currentPos.z;

    if (partner->currentPos.y < 10.0f) {
        partner->currentPos.y = 10.0f;

        play_movement_dust_effects(2, partner->currentPos.x, partner->currentPos.y, partner->currentPos.z,
                                   partner->yaw);
        sfx_play_sound(SOUND_SOFT_LAND);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(GetTattleMessage)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    Actor* target = get_actor(partner->targetActorID);
    s32* tattle = &bActorTattles[target->actorType];

    script->varTable[0] = *tattle;

    if (script->varTable[0] == NULL) {
        script->varTable[0] = bActorTattles[0];
    }

    save_tattle_flags(target->actorType);

    return ApiStatus_DONE2;
}


ApiStatus N(GetTattleCamPos)(Evt* script, s32 isInitalCall) {
    Actor* target = get_actor(gBattleStatus.partnerActor->targetActorID);
    s32 xSize;

    if (!(target->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
        script->varTable[1] = script->varTable[1] + (((target->size.y / 3) & 0xFF) * target->scalingFactor);
        script->varTable[1] += ((target->size.y / 4) * target->scalingFactor);
    } else {
        script->varTable[1] = script->varTable[1] - (((target->size.y / 3) & 0xFF) * target->scalingFactor);
        script->varTable[1] -= ((target->size.y / 4) * target->scalingFactor);
    }

    if (target->flags & ACTOR_FLAG_8000) {
        script->varTable[1] -= (target->size.y / 2) * target->scalingFactor;
    }

    xSize = target->size.y * target->scalingFactor;
    if (xSize < target->size.x) {
        xSize = target->size.x;
    }

    script->varTable[3] = xSize + 76;
    script->varTable[0] += bActorOffsets[target->actorType].tattleCam.x;
    script->varTable[1] += bActorOffsets[target->actorType].tattleCam.y;
    script->varTable[3] += bActorOffsets[target->actorType].tattleCam.z;

    return ApiStatus_DONE2;
}


ApiStatus N(OpenTattleWindow)(Evt* script, s32 isInitialCall) {
    N(tattleEffect) = fx_tattle_window(0, 206, 144, 0, 1.0f, 0);

    return ApiStatus_DONE2;
}

ApiStatus N(CloseTattleWindow)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = N(tattleEffect);

    effect->data.tattleWindow->pos.y = 144.0f;
    effect->flags |= EFFECT_INSTANCE_FLAGS_10;

    return ApiStatus_DONE2;
}

ApiStatus N(CanChargeMore)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;

    script->varTable[0] = FALSE;

    switch (battleStatus->selectedMoveID) {
        case MOVE_TATTLE:
            if (partner->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
        case MOVE_CHARGE:
            if (partner->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
        case MOVE_MULTIBONK:
            if (partner->isGlowing >= 99) {
                script->varTable[0] = TRUE;
            }
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(ChargeAtPos)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 boostAmount;
    s32 x, y, z;

    N(isCharged) = 0;
    if (partner->isGlowing > 0) {
        N(isCharged) = 1;
    }

    boostAmount = 0;
    switch (battleStatus->selectedMoveID) {
        case MOVE_TATTLE:
            partner->isGlowing += 2;
            boostAmount = 1;
            if (partner->isGlowing >= 99) {
                partner->isGlowing = 99;
            }
            break;
        case MOVE_CHARGE:
            partner->isGlowing += 2;
            boostAmount = 1;
            if (partner->isGlowing >= 99) {
                partner->isGlowing = 99;
            }
            break;
        case MOVE_MULTIBONK:
            partner->isGlowing += 2;
            boostAmount = 1;
            if (partner->isGlowing >= 99) {
                partner->isGlowing = 99;
            }
            break;
    }

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    fx_stat_change(boostAmount, x, y, z, 1.0f, 60);

    gBattleStatus.flags1 |= BS_FLAGS1_40000000;
    return ApiStatus_DONE2;
}

ApiStatus N(StopCharge)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->partnerActor->isGlowing = 0;
    battleStatus->flags1 &= ~BS_FLAGS1_40000000;

    return ApiStatus_DONE2;
}

ApiStatus N(StopChargeAndGet)(Evt* script, s32 isInitialCall) {
    Actor* partner = gBattleStatus.partnerActor;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_40000000)) {
        partner->isGlowing = 0;
    }

    script->varTable[0] = partner->isGlowing;
    partner->isGlowing = 0;
    gBattleStatus.flags1 &= ~BS_FLAGS1_40000000;

    return ApiStatus_DONE2;
}

ApiStatus N(GetChargeAmount)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    script->varTable[0] = battleStatus->partnerActor->isGlowing;

    return ApiStatus_DONE2;
}

ApiStatus N(PlayChargeFX)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    fx_energy_in_out(6, var1, var2, var3, var4, 45);

    return ApiStatus_DONE2;
}

ApiStatus N(GetChargeMessage)(Evt* script, s32 isInitialCall) {
    if (N(isCharged) == 0) {
        script->varTable[0] = 36;
    } else {
        script->varTable[0] = 37;
    }

    return ApiStatus_DONE2;
}

s32 N(idleAnimations)[] = {
    STATUS_NORMAL,    ANIM_BattleGoombario_Walk,
    STATUS_STONE,     ANIM_BattleGoombario_Still,
    STATUS_SLEEP,     ANIM_BattleGoombario_CloseEyes,
    STATUS_POISON,    ANIM_BattleGoombario_Still,
    STATUS_STOP,      ANIM_BattleGoombario_Still,
    STATUS_DAZE,      ANIM_BattleGoombario_Injured,
    STATUS_TURN_DONE, ANIM_BattleGoombario_Still,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 100,
    STATUS_POISON, 100,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = 0,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 8, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBARIO,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 29, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_PARTNER, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_PARTNER, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_PARTNER, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_PARTNER, EVT_PTR(N(nextTurn)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, 0)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoPartnerBlock)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(DoPartnerSpikeContact)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET(LVar2, 12)
            EVT_SET_CONST(LVar3, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(DoPartnerBurnContact)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(DoPartnerBurn)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(EVENT_33)
            EVT_CALL(N(StopCharge))
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_RECOVER_PARTNER)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Idle)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_Run)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(DoPartnerRecover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Block)
            EVT_EXEC_WAIT(DoPartnerBlock)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(firstStrike))
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(executeAction))
        EVT_CASE_EQ(PHASE_5)
            EVT_EXEC_WAIT(N(celebrate))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(runAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(runAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(celebrate) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BattleGoombario_CelebrateLoop)
    EVT_SET_CONST(LVar2, ANIM_BattleGoombario_Celebrate)
    EVT_SET_CONST(LVar3, ANIM_BattleGoombario_Idle)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_CALL(LoadItemScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_HEADBONK1)
            EVT_EXEC_WAIT(N(headbonk1))
        EVT_CASE_EQ(MOVE_HEADBONK2)
            EVT_EXEC_WAIT(N(headbonk2))
        EVT_CASE_EQ(MOVE_HEADBONK3)
            EVT_EXEC_WAIT(N(headbonk3))
        EVT_CASE_EQ(MOVE_TATTLE)
            EVT_EXEC_WAIT(N(tattle))
        EVT_CASE_EQ(MOVE_CHARGE)
            EVT_EXEC_WAIT(N(charge))
        EVT_CASE_EQ(MOVE_MULTIBONK)
            EVT_EXEC_WAIT(N(multibonk))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(firstStrike) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, 0x1)
    EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Run)
    EVT_EXEC_WAIT(DoPartnerRunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, 0)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_IF_EQ(GF_Tutorial_SwapTurnOrder, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(10)
                EVT_CALL(SetActorYaw, 0, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 60)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 90)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 120)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 150)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 180)
                EVT_WAIT(5)
                EVT_CALL(ActorSpeak, MSG_CH0_00BA, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
                EVT_CALL(SetActorYaw, 0, 150)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 120)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 90)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 60)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, 0, 0)
                EVT_WAIT(5)
                EVT_SET(GF_Tutorial_SwapTurnOrder, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        EVT_SET(LVar0, 180)
        EVT_LOOP(3)
            EVT_ADD(LVar0, 60)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.2))
    EVT_CALL(N(GetReturnMoveTime))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, LVar0, 0, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, 0, 0, 1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome2) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(N(GetReturnMoveTime))
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        EVT_SUB(LVar0, 4)
        EVT_SET(LVar1, LVar0)
        EVT_DIV(LVar1, 3)
        EVT_IF_LT(LVar1, 1)
            EVT_SET(LVar1, 1)
        EVT_END_IF
        EVT_SET(LVar2, LVar1)
        EVT_MOD(LVar2, 2)
        EVT_IF_EQ(LVar2, 0)
            EVT_SUB(LVar1, 1)
        EVT_END_IF
        EVT_SET(LVar0, 180)
        EVT_LOOP(LVar1)
            EVT_LOOP(3)
                EVT_ADD(LVar0, 60)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, LVar0, 0, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, 0, 0, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, 0, 0, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(runToTarget) = {
    EVT_CALL(SetGoalToFirstTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, EVT_FLOAT(70.0))
    EVT_IF_LT(LVar0, LVar3)
        EVT_SET(LVar3, LVar0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_47)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(5.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(calcJumpTime) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVarB, LVar7, LVarD)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar7, LVarD, LVarE)
    EVT_IF_GT(LVarB, LVar7)
        EVT_SUB(LVarB, LVar7)
    EVT_ELSE
        EVT_SUB(LVar7, LVarB)
        EVT_SET(LVarB, LVar7)
    EVT_END_IF
    EVT_SUB(LVarB, 20)
    EVT_DIVF(LVarB, EVT_FLOAT(10.5888671875))
    EVT_ADDF(LVarB, 15)
    EVT_SET(LVarA, LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(headbonk1) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, ATTACK_EVENT_FLAG_4 | ATTACK_EVENT_FLAG_10, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_162)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(N(returnHome))
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(N(GetChargeAmount))
            EVT_ADD(LVar0, 1)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_40 | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(N(StopChargeAndGet))
            EVT_ADD(LVar0, 1)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(LVarA, 24)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_281)
    EVT_CALL(N(JumpOnTarget), LVarA, 3)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(N(StopChargeAndGet))
    EVT_ADD(LVar0, 1)
    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(N(returnHome2))
    EVT_RETURN
    EVT_END
};

EvtScript N(headbonk2) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, ATTACK_EVENT_FLAG_4 | ATTACK_EVENT_FLAG_10, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_162)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(N(returnHome))
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(N(GetChargeAmount))
            EVT_ADD(LVar0, 2)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_40 | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(N(StopChargeAndGet))
            EVT_ADD(LVar0, 2)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(LVarA, 24)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_281)
    EVT_CALL(N(JumpOnTarget), LVarA, 3)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, -1)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(N(StopChargeAndGet))
    EVT_ADD(LVar0, 2)
    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(N(returnHome2))
    EVT_RETURN
    EVT_END
};

EvtScript N(headbonk3) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, ATTACK_EVENT_FLAG_4 | ATTACK_EVENT_FLAG_10, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_162)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(N(returnHome))
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(N(GetChargeAmount))
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_40 | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(N(StopChargeAndGet))
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_CALL(func_802694A4, 0)
    EVT_CALL(func_802A9120_421B10, 24, 3)
    EVT_SET(LVarA, 24)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(LVarA)
            EVT_ADD(LVar0, 133)
            EVT_CALL(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_281)
    EVT_CALL(N(JumpOnTarget), LVarA, 3)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, -1)
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(N(StopChargeAndGet))
    EVT_ADD(LVar0, 3)
    EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(N(returnHome2))
    EVT_RETURN
    EVT_END
};

s32 N(actionCommandTable)[] = { 7, 6, 5, 4, 3, 2, 1, 0, };

s32 N(powerBounceChance) = 200;

EvtScript N(multibonk) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(func_802A9120_421B10, LVarA, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, ATTACK_EVENT_FLAG_4 | ATTACK_EVENT_FLAG_10, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_162)
        EVT_WAIT(20)
        EVT_EXEC_WAIT(N(returnHome))
        EVT_RETURN
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(N(GetChargeAmount))
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, BS_FLAGS1_40 | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(N(StopChargeAndGet))
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(func_80269524, LVarF)
    EVT_SET(LVarD, 0)
    EVT_SET(LVarF, 0)
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(func_8026919C, EVT_PTR(N(actionCommandTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_CreateHudElements)
    EVT_SET(LVarA, 24)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(func_802A9120_421B10, LVarA, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(func_802A9120_421B10, LVarA, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(func_802A9120_421B10, LVarA, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(func_802A9120_421B10, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(func_802A9120_421B10, LVarA, 5)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(LVarA)
            EVT_ADD(LVar0, 133)
            EVT_CALL(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_281)
    EVT_CALL(N(JumpOnTarget), LVarA, 3)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, -1)
    EVT_SUB(LVarD, 1)
    EVT_CALL(N(AdjustPowerBounceChance))
    EVT_IF_GE(LVarF, LVar0)
        EVT_SET(LocalFlag(0), 1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_CALL(N(GetChargeAmount))
                EVT_ADD(LVar0, 3)
                EVT_CALL(PartnerPowerBounceEnemy, LVar0, 1048704, 0, 0, LVar0, LVarD, BS_FLAGS1_40)
            EVT_ELSE
                EVT_CALL(N(StopChargeAndGet))
                EVT_ADD(LVar0, 3)
                EVT_CALL(PartnerPowerBounceEnemy, LVar0, 1048704, 0, 0, LVar0, LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(N(StopChargeAndGet))
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerPowerBounceEnemy, LVar0, 1048704, 0, 0, LVar0, LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_SET(LocalFlag(0), 0)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0)
    EVT_CALL(func_80269550, LVarE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_EXEC_WAIT(N(returnHome2))
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_ADD(LVarF, 1)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(tattle) = {
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4, 1)
    EVT_CALL(N(OpenTattleWindow))
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, CAM_TATTLE, 1)
    EVT_CALL(SetCamFlag80, CAM_TATTLE, 0)
    EVT_CALL(SetCamPerspective, CAM_TATTLE, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, CAM_TATTLE, 137, 95, 138, 99)
    EVT_CALL(GetOwnerTarget, LVarA, LVarB)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetTattleCamPos))
    EVT_WAIT(1)
    EVT_CALL(func_802CAE50, CAM_TATTLE, LVar0, LVar1, LVar2)
    EVT_CALL(func_802CABE8, CAM_TATTLE, 0, LVar3, 100, 4)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_282)
    EVT_CALL(SetCamFlag80, CAM_TATTLE, 1)
    EVT_WAIT(10)
    EVT_CALL(N(GetTattleMessage))
    EVT_CALL(ActorSpeak, LVar0, ACTOR_SELF, 1, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    EVT_CALL(N(CloseTattleWindow))
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, CAM_TATTLE, 0)
    EVT_WAIT(32)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4, 0)
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(charge) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208F)
    EVT_CALL(N(PlayChargeFX), LVar0, LVar1, LVar2, EVT_FLOAT(1.2))
    EVT_WAIT(3)
    EVT_CALL(N(PlayChargeFX), LVar0, LVar1, LVar2, EVT_FLOAT(0.8))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_ADD(LVar2, -5)
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2003)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_ORB_WAVE, 9, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 20, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(N(CanChargeMore))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 10)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 5)
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208E)
        EVT_CALL(N(ChargeAtPos), LVar0, LVar1, LVar2)
        EVT_WAIT(4)
        EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, ANIM_BattleGoombario_Jump, 1, ANIM_BattleGoombario_Jump, ANIM_BattleGoombario_Jump)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, 1, 1, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(MOVE_TATTLE)
                EVT_CALL(ShowMessageBox, 36, 60)
            EVT_CASE_EQ(MOVE_CHARGE)
                EVT_CALL(N(GetChargeMessage))
                EVT_CALL(ShowMessageBox, LVar0, 60)
            EVT_CASE_EQ(MOVE_MULTIBONK)
                EVT_CALL(ShowMessageBox, 36, 60)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageBox, 8, 60)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(IsMessageBoxDisplayed, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
