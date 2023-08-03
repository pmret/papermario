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

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

API_CALLABLE(N(GetReturnMoveTime)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    f32 posX = partner->curPos.x;
    f32 posY = partner->curPos.y;
    f32 posZ = partner->curPos.z;
    f32 goalX = partner->state.goalPos.x;
    f32 goalY = partner->state.goalPos.y;
    f32 goalZ = partner->state.goalPos.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (battleStatus->actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED) {
        if (script->varTable[0] < 10) {
            script->varTable[0] = 10;
        }
    } else if (script->varTable[0] < 15) {
        script->varTable[0] = 15;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(AdjustPowerBounceChance)) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);

    script->varTable[0] = 99;
    N(powerBounceChance) *= targetActor->actorBlueprint->powerBounceChance;
    N(powerBounceChance) /= 100;
    if (N(powerBounceChance) < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(JumpOnTarget)) {
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
        state->curPos.x = actor->curPos.x;
        state->curPos.y = actor->curPos.y;
        stateGoalX = state->goalPos.x;
        stateGoalZ = state->goalPos.z;
        stateCurrentX = state->curPos.x;
        stateCurrentZ = actor->curPos.z;
        state->curPos.z = stateCurrentZ;
        state->angle = atan2(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        state->dist = dist2D(stateCurrentX, stateCurrentZ, stateGoalX, stateGoalZ);
        if (state->moveTime == 0) {
            state->moveTime = state->dist / state->speed;
            temp = state->dist - (state->moveTime * state->speed);
        } else {
            state->speed = state->dist / state->moveTime;
            temp = state->dist - (state->moveTime * state->speed);
        }

        if (state->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        state->unk_30.x = (state->goalPos.x - state->curPos.x) / state->moveTime;
        state->unk_30.y = (state->goalPos.y - state->curPos.y) / state->moveTime;
        state->unk_30.z = (state->goalPos.z - state->curPos.z) / state->moveTime;
        state->acceleration = PI_S / state->moveTime;
        state->vel = 0.0f;
        state->speed += temp / state->moveTime;

        if (state->moveArcAmplitude < 3) {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            temp = state->dist;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            state->bounceDivisor = temp;
            if (state->moveArcAmplitude == 2) {
                state->bounceDivisor *= 1.12;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            vel3 = state->vel;
            acc3 = state->acceleration;
            state->vel = vel3 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.53 * acc3) + acc3);
        } else {
            state->unk_24 = 90.0f;
            state->unk_28 = 360 / state->moveTime;
            temp = state->dist;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            state->bounceDivisor = temp;
            if (state->moveArcAmplitude == 4) {
                state->bounceDivisor *= 1.25;
            }
            state->unk_18.x = 0.0f;
            state->unk_18.y = 0.0f;
            vel4 = state->vel;
            acc4 = state->acceleration;
            state->vel = vel4 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.8 * acc4) + acc4);
        }
        set_animation(ACTOR_PARTNER, 1, state->animJumpRise);
        script->functionTemp[0] = 1;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (state->vel > PI_S / 2) {
                set_animation(ACTOR_PARTNER, 1, state->animJumpFall);
            }
            oldActorX = actor->curPos.x;
            oldActorY = actor->curPos.y;
            state->curPos.x += state->unk_30.x;
            state->curPos.y = state->curPos.y + state->unk_30.y;
            state->curPos.z = state->curPos.z + state->unk_30.z;
            state->unk_18.x = actor->curPos.y;
            actor->curPos.x = state->curPos.x;
            actor->curPos.y = state->curPos.y + (state->bounceDivisor * sin_rad(state->vel));
            actor->curPos.z = state->curPos.z;
            if (state->goalPos.y > actor->curPos.y && state->moveTime < 3) {
                actor->curPos.y = state->goalPos.y;
            }

            actor->rot.z = -atan2(oldActorX, -oldActorY, actor->curPos.x, -actor->curPos.y);
            state->unk_18.y = actor->curPos.y;
            if (state->moveArcAmplitude < 3) {
                vel1 = state->vel;
                acc1 = state->acceleration;
                state->vel = vel1 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.53 * acc1) + acc1);
            } else {
                vel2 = state->vel;
                acc2 = state->acceleration;
                state->vel = vel2 + ((sin_rad(DEG_TO_RAD(state->unk_24)) * 0.8 * acc2) + acc2);
            }

            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            state->moveTime--;
            if (state->moveTime == 0) {
                actor->curPos.y = state->goalPos.y;
                state->acceleration = 1.8f;
                state->vel = -(state->unk_18.x - state->unk_18.y);
                set_animation(ACTOR_PARTNER, 1, state->animJumpLand);
                return ApiStatus_DONE1;
            }
            break;
        case 2:
            if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
                return ApiStatus_DONE2;
            }
            state->moveTime = 1;
            state->acceleration = 1.8f;
            state->unk_24 = 90.0f;
            state->vel = -(state->unk_18.x - state->unk_18.y);
            state->bounceDivisor = fabsf(state->unk_18.x - state->unk_18.y) / 16.5;
            state->unk_28 = 360 / state->moveTime;
            state->curPos.x = actor->curPos.x;
            state->curPos.y = actor->curPos.y;
            state->curPos.z = actor->curPos.z;
            script->functionTemp[0] = 3;
            // fallthrough
        case 3:
            currentPosX64 = state->curPos.x; // required to match
            state->curPos.x = currentPosX64 + state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24)) / 33.0;
            state->curPos.y -= state->bounceDivisor * sin_rad(DEG_TO_RAD(state->unk_24));
            state->unk_24 += state->unk_28;
            state->unk_24 = clamp_angle(state->unk_24);
            actor->curPos.x = state->curPos.x;
            actor->curPos.y = state->curPos.y;
            actor->curPos.z = state->curPos.z;

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

API_CALLABLE(N(OnMissHeadbonk)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = gBattleStatus.partnerActor;
    Vec3f* pos = &partner->state.curPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        partner->state.curPos.x = partner->curPos.x;
        partner->state.curPos.y = partner->curPos.y;
        partner->state.curPos.z = partner->curPos.z;
        script->functionTemp[0] = 1;
    }

    if (partner->state.vel > 0.0f) {
        set_animation(ACTOR_PARTNER, 0, partner->state.animJumpRise);
    }

    if (partner->state.vel < 0.0f) {
        set_animation(ACTOR_PARTNER, 0, partner->state.animJumpFall);
    }

    partner->state.curPos.y = (partner->state.curPos.y + partner->state.vel);
    partner->state.vel = (partner->state.vel - partner->state.acceleration);
    add_xz_vec3f(pos, partner->state.speed, partner->state.angle);
    partner->curPos.x = partner->state.curPos.x;
    partner->curPos.y = partner->state.curPos.y;
    partner->curPos.z = partner->state.curPos.z;

    if (partner->curPos.y < 10.0f) {
        partner->curPos.y = 10.0f;

        play_movement_dust_effects(2, partner->curPos.x, partner->curPos.y, partner->curPos.z,
                                   partner->yaw);
        sfx_play_sound(SOUND_SOFT_LAND);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(GetTattleMessage)) {
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

API_CALLABLE(N(GetTattleCamPos)) {
    Actor* target = get_actor(gBattleStatus.partnerActor->targetActorID);
    s32 xSize;

    if (!(target->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
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

API_CALLABLE(N(OpenTattleWindow)) {
    N(tattleEffect) = fx_tattle_window(0, 206, 144, 0, 1.0f, 0);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(CloseTattleWindow)) {
    EffectInstance* effect = N(tattleEffect);

    effect->data.tattleWindow->pos.y = 144.0f;
    effect->flags |= FX_INSTANCE_FLAG_DISMISS;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(CanChargeMore)) {
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

API_CALLABLE(N(ChargeAtPos)) {
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

    gBattleStatus.flags1 |= BS_FLAGS1_GOOMBARIO_CHARGED;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(StopCharge)) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->partnerActor->isGlowing = 0;
    battleStatus->flags1 &= ~BS_FLAGS1_GOOMBARIO_CHARGED;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(StopChargeAndGet)) {
    Actor* partner = gBattleStatus.partnerActor;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_GOOMBARIO_CHARGED)) {
        partner->isGlowing = 0;
    }

    script->varTable[0] = partner->isGlowing;
    partner->isGlowing = 0;
    gBattleStatus.flags1 &= ~BS_FLAGS1_GOOMBARIO_CHARGED;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetChargeAmount)) {
    BattleStatus* battleStatus = &gBattleStatus;

    script->varTable[0] = battleStatus->partnerActor->isGlowing;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PlayChargeFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    f32 var4 = evt_get_float_variable(script, *args++);

    fx_energy_in_out(6, var1, var2, var3, var4, 45);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetChargeMessage)) {
    if (N(isCharged) == 0) {
        script->varTable[0] = BTL_MSG_CHARGE_GOOMBARIO;
    } else {
        script->varTable[0] = BTL_MSG_CHARGE_GOOMBARIO_MORE;
    }

    return ApiStatus_DONE2;
}

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleGoombario_Walk,
    STATUS_KEY_STONE,     ANIM_BattleGoombario_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleGoombario_CloseEyes,
    STATUS_KEY_POISON,    ANIM_BattleGoombario_Still,
    STATUS_KEY_STOP,      ANIM_BattleGoombario_Still,
    STATUS_KEY_DAZE,      ANIM_BattleGoombario_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleGoombario_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 8, 22 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBARIO,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 29, 26 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
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
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Hit)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(EVS_Partner_SpikeContact)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET(LVar2, 12)
            EVT_SET_CONST(LVar3, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(EVS_Partner_BurnContact)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(EVS_Partner_BurnHit)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(EVS_Partner_ShockHit)
        EVT_CASE_EQ(EVENT_33)
            EVT_CALL(N(StopCharge))
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Idle)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_Run)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(EVS_Partner_Recover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Block)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
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
        EVT_CASE_EQ(PHASE_CELEBRATE)
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
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BattleGoombario_CelebrateLoop)
    EVT_SET_CONST(LVar2, ANIM_BattleGoombario_Celebrate)
    EVT_SET_CONST(LVar3, ANIM_BattleGoombario_Idle)
    EVT_EXEC_WAIT(EVS_Partner_Celebrate)
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
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
    EVT_EXEC_WAIT(EVS_Partner_RunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_IF_EQ(GF_Tutorial_SwapTurnOrder, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(10)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
                EVT_WAIT(5)
                EVT_CALL(ActorSpeak, MSG_CH0_00BA, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                EVT_WAIT(5)
                EVT_SET(GF_Tutorial_SwapTurnOrder, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
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
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, LVar0, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
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
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, LVar0, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(1)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PARTNER_APPROACH)
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
    EVT_DIVF(LVarB, EVT_FLOAT(10.588))
    EVT_ADDF(LVarB, 15)
    EVT_SET(LVarA, LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(headbonk1) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(action_command_jump_start, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
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
    EVT_CALL(action_command_jump_init)
    EVT_CALL(ShowActionHud, FALSE)
    EVT_CALL(action_command_jump_start, 24, 3)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(N(returnHome2))
    EVT_RETURN
    EVT_END
};

EvtScript N(headbonk2) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(action_command_jump_start, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
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
    EVT_CALL(action_command_jump_init)
    EVT_CALL(ShowActionHud, FALSE)
    EVT_CALL(action_command_jump_start, 24, 3)
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
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_281)
    EVT_CALL(N(JumpOnTarget), LVarA, 3)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, IDLE_SCRIPT_RESTART)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(N(returnHome2))
    EVT_RETURN
    EVT_END
};

EvtScript N(headbonk3) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(action_command_jump_start, LVarA, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
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
    EVT_CALL(action_command_jump_init)
    EVT_CALL(ShowActionHud, FALSE)
    EVT_CALL(action_command_jump_start, 24, 3)
    EVT_SET(LVarA, 24)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
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
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_281)
    EVT_CALL(N(JumpOnTarget), LVarA, 3)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, IDLE_SCRIPT_RESTART)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_CALL(func_80269550, LVarF)
    EVT_EXEC_WAIT(N(returnHome2))
    EVT_RETURN
    EVT_END
};

s32 N(actionCommandTable)[] = { 7, 6, 5, 4, 3, 2, 1, 0 };

s32 N(powerBounceChance) = 200;

EvtScript N(multibonk) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_EXEC_WAIT(N(runToTarget))
    EVT_EXEC_WAIT(N(calcJumpTime))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(action_command_jump_start, LVarA, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_52)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200D)
    EVT_CALL(N(JumpOnTarget), LVarA, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        EVT_CALL(N(OnMissHeadbonk))
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
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
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_50)
        EVT_WAIT(5)
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EVT_END_THREAD
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetActionDifficultyTable, EVT_PTR(N(actionCommandTable)))
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
    EVT_CALL(action_command_jump_init)
    EVT_SET(LVarA, 24)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(0)
            EVT_CALL(action_command_jump_start, LVarA, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(action_command_jump_start, LVarA, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(action_command_jump_start, LVarA, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(action_command_jump_start, LVarA, 4)
        EVT_CASE_DEFAULT
            EVT_CALL(action_command_jump_start, LVarA, 5)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(6)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
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
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_281)
    EVT_CALL(N(JumpOnTarget), LVarA, 3)
    EVT_CALL(EnableActorBlur, ACTOR_PARTNER, IDLE_SCRIPT_RESTART)
    EVT_SUB(LVarD, 1)
    EVT_CALL(N(AdjustPowerBounceChance))
    EVT_IF_GE(LVarF, LVar0)
        EVT_SET(LFlag0, TRUE)
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
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_CALL(N(GetChargeAmount))
                EVT_ADD(LVar0, 3)
                EVT_CALL(PartnerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, LVarD, BS_FLAGS1_40)
            EVT_ELSE
                EVT_CALL(N(StopChargeAndGet))
                EVT_ADD(LVar0, 3)
                EVT_CALL(PartnerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(N(StopChargeAndGet))
            EVT_ADD(LVar0, 3)
            EVT_CALL(PartnerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_SET(LFlag0, FALSE)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_CALL(func_80269550, LVarE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_IF_EQ(LFlag0, TRUE)
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
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, TRUE)
    EVT_CALL(N(OpenTattleWindow))
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, CAM_TATTLE, TRUE)
    EVT_CALL(SetCamFlag80, CAM_TATTLE, FALSE)
    EVT_CALL(SetCamPerspective, CAM_TATTLE, CAM_UPDATE_MODE_6, 25, 16, 1024)
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
    EVT_CALL(SetCamFlag80, CAM_TATTLE, TRUE)
    EVT_WAIT(10)
    EVT_CALL(N(GetTattleMessage))
    EVT_CALL(ActorSpeak, LVar0, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    EVT_CALL(N(CloseTattleWindow))
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, CAM_TATTLE, FALSE)
    EVT_WAIT(32)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, FALSE)
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
        EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 9, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 20, 0)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
        EVT_CALL(SetJumpAnimations, ACTOR_PARTNER, ANIM_BattleGoombario_Jump, 0x00000001, ANIM_BattleGoombario_Jump, ANIM_BattleGoombario_Jump)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, TRUE, TRUE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(MOVE_TATTLE)
                EVT_CALL(ShowMessageBox, BTL_MSG_CHARGE_GOOMBARIO, 60)
            EVT_CASE_EQ(MOVE_CHARGE)
                EVT_CALL(N(GetChargeMessage))
                EVT_CALL(ShowMessageBox, LVar0, 60)
            EVT_CASE_EQ(MOVE_MULTIBONK)
                EVT_CALL(ShowMessageBox, BTL_MSG_CHARGE_GOOMBARIO, 60)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
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
