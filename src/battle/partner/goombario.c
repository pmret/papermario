#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/npc/BattleGoombario.h"

#define NAMESPACE battle_partner_goombario

extern s32 bActorTattles[];

static EffectInstance* N(TattleWindowEffect);
static b32 N(isCharged);
extern s32 N(MultibonkChance);

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Attack_Headbonk1);
extern EvtScript N(EVS_Attack_Headbonk2);
extern EvtScript N(EVS_Attack_Headbonk3);
extern EvtScript N(EVS_Move_Tattle);
extern EvtScript N(EVS_Move_Charge);
extern EvtScript N(EVS_Move_Multibonk);
extern EvtScript N(EVS_FirstStrike);
extern EvtScript N(EVS_RunAway);
extern EvtScript N(EVS_RunAwayFail);
extern EvtScript N(EVS_Celebrate);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
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

API_CALLABLE(N(AdjustMultibonkChance)) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);

    script->varTable[0] = 99;

    /// @bug this value is not reset between Multibonk uses
    N(MultibonkChance) *= targetActor->actorBlueprint->powerBounceChance;
    N(MultibonkChance) /= 100;
    if (N(MultibonkChance) < rand_int(100)) {
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

        state->velStep.x = (state->goalPos.x - state->curPos.x) / state->moveTime;
        state->velStep.y = (state->goalPos.y - state->curPos.y) / state->moveTime;
        state->velStep.z = (state->goalPos.z - state->curPos.z) / state->moveTime;
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
        set_actor_anim(ACTOR_PARTNER, PRT_MAIN, state->animJumpRise);
        script->functionTemp[0] = 1;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (state->vel > PI_S / 2) {
                set_actor_anim(ACTOR_PARTNER, PRT_MAIN, state->animJumpFall);
            }
            oldActorX = actor->curPos.x;
            oldActorY = actor->curPos.y;
            state->curPos.x += state->velStep.x;
            state->curPos.y += state->velStep.y;
            state->curPos.z += state->velStep.z;
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
                set_actor_anim(ACTOR_PARTNER, PRT_MAIN, state->animJumpLand);
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
        set_actor_anim(ACTOR_PARTNER, 0, partner->state.animJumpRise);
    }

    if (partner->state.vel < 0.0f) {
        set_actor_anim(ACTOR_PARTNER, 0, partner->state.animJumpFall);
    }

    partner->state.curPos.y = (partner->state.curPos.y + partner->state.vel);
    partner->state.vel = (partner->state.vel - partner->state.acceleration);
    add_xz_vec3f(pos, partner->state.speed, partner->state.angle);
    partner->curPos.x = partner->state.curPos.x;
    partner->curPos.y = partner->state.curPos.y;
    partner->curPos.z = partner->state.curPos.z;

    if (partner->curPos.y < 10.0f) {
        partner->curPos.y = 10.0f;

        play_movement_dust_effects(2, partner->curPos.x, partner->curPos.y, partner->curPos.z, partner->yaw);
        sfx_play_sound(SOUND_LAND_SOFTLY);

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

    if (target->flags & ACTOR_FLAG_HALF_HEIGHT) {
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
    N(TattleWindowEffect) = fx_tattle_window(0, 206, 144, 0, 1.0f, 0);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(CloseTattleWindow)) {
    EffectInstance* effect = N(TattleWindowEffect);

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

    N(isCharged) = FALSE;
    if (partner->isGlowing > 0) {
        N(isCharged) = TRUE;
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
    if (!N(isCharged)) {
        script->varTable[0] = BTL_MSG_CHARGE_GOOMBARIO;
    } else {
        script->varTable[0] = BTL_MSG_CHARGE_GOOMBARIO_MORE;
    }

    return ApiStatus_DONE2;
}

s32 N(DefaultAnims)[] = {
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
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBARIO,
    .level = ACTOR_LEVEL_GOOMBARIO,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_PARTNER, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_PARTNER, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_PARTNER, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_PARTNER, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(CloseActionCommandInfo)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            SetConst(LVar2, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Partner_Hit)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Partner_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            Set(LVar2, 12)
            ExecWait(EVS_Partner_SpikeContact)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            SetConst(LVar1, ANIM_BattleGoombario_BurnHurt1)
            Set(LVar2, 12)
            SetConst(LVar3, ANIM_BattleGoombario_BurnHurt2)
            ExecWait(EVS_Partner_BurnContact)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1, ANIM_BattleGoombario_BurnHurt1)
            SetConst(LVar2, ANIM_BattleGoombario_BurnHurt2)
            ExecWait(EVS_Partner_BurnHit)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            Set(LVar2, 12)
            ExecWait(EVS_Partner_ShockHit)
        CaseEq(EVENT_33)
            Call(N(StopCharge))
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_Idle)
            SetConst(LVar2, ANIM_BattleGoombario_Run)
            Set(LVar3, 0)
            ExecWait(EVS_Partner_Recover)
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_Block)
            ExecWait(EVS_Partner_NoDamageHit)
            Wait(10)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_FIRST_STRIKE)
            ExecWait(N(EVS_FirstStrike))
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(N(EVS_ExecuteAction))
        CaseEq(PHASE_CELEBRATE)
            ExecWait(N(EVS_Celebrate))
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(N(EVS_RunAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(EVS_RunAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleGoombario_CelebrateLoop)
    SetConst(LVar2, ANIM_BattleGoombario_Celebrate)
    SetConst(LVar3, ANIM_BattleGoombario_Idle)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Call(ShowActionHud, TRUE)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
        CaseEq(BTL_MENU_TYPE_ITEMS)
            Call(LoadItemScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Switch(LVar2)
        CaseEq(MOVE_HEADBONK1)
            ExecWait(N(EVS_Attack_Headbonk1))
        CaseEq(MOVE_HEADBONK2)
            ExecWait(N(EVS_Attack_Headbonk2))
        CaseEq(MOVE_HEADBONK3)
            ExecWait(N(EVS_Attack_Headbonk3))
        CaseEq(MOVE_TATTLE)
            ExecWait(N(EVS_Move_Tattle))
        CaseEq(MOVE_CHARGE)
            ExecWait(N(EVS_Move_Charge))
        CaseEq(MOVE_MULTIBONK)
            ExecWait(N(EVS_Move_Multibonk))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_FirstStrike) = {
    Return
    End
};

EvtScript N(EVS_RunAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleGoombario_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(EVS_RunAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            IfFalse(GF_Tutorial_SwapTurnOrder)
                Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(MoveBattleCamOver, 20)
                Wait(10)
                Call(SetActorYaw, ACTOR_PLAYER, 30)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 60)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 90)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 120)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 150)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 180)
                Wait(5)
                Call(ActorSpeak, MSG_CH0_00BA, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
                Call(SetActorYaw, ACTOR_PLAYER, 150)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 120)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 90)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 60)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 30)
                Wait(1)
                Call(SetActorYaw, ACTOR_PLAYER, 0)
                Wait(5)
                Set(GF_Tutorial_SwapTurnOrder, TRUE)
                Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Thread
        Wait(4)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        Set(LVar0, 180)
        Loop(3)
            Add(LVar0, 60)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EndThread
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 30)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.2))
    Call(N(GetReturnMoveTime))
    Call(JumpToGoal, ACTOR_PARTNER, LVar0, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    Wait(1)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    Wait(1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(2)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Return
    End
};

EvtScript N(returnHome2) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(N(GetReturnMoveTime))
    Thread
        Wait(4)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        Sub(LVar0, 4)
        Set(LVar1, LVar0)
        Div(LVar1, 3)
        IfLt(LVar1, 1)
            Set(LVar1, 1)
        EndIf
        Set(LVar2, LVar1)
        Mod(LVar2, 2)
        IfEq(LVar2, 0)
            Sub(LVar1, 1)
        EndIf
        Set(LVar0, 180)
        Loop(LVar1)
            Loop(3)
                Add(LVar0, 60)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                Wait(1)
            EndLoop
        EndLoop
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EndThread
    Call(JumpToGoal, ACTOR_PARTNER, LVar0, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(1)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(1)
    Call(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Wait(2)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(8.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Return
    End
};

EvtScript N(runToTarget) = {
    Call(SetGoalToFirstTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    Sub(LVar3, Float(70.0))
    IfLt(LVar0, LVar3)
        Set(LVar3, LVar0)
    EndIf
    Call(SetGoalPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_APPROACH)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(5.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Return
    End
};

EvtScript N(calcJumpTime) = {
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVarB, LVar7, LVarD)
    Call(GetActorPos, ACTOR_PARTNER, LVar7, LVarD, LVarE)
    IfGt(LVarB, LVar7)
        Sub(LVarB, LVar7)
    Else
        Sub(LVar7, LVarB)
        Set(LVarB, LVar7)
    EndIf
    Sub(LVarB, 20)
    DivF(LVarB, Float(10.588))
    AddF(LVarB, 15)
    Set(LVarA, LVarB)
    Return
    End
};

EvtScript N(EVS_Attack_Headbonk1) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(runToTarget))
    ExecWait(N(calcJumpTime))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    Wait(1)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(action_command_jump_start, LVarA, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_JUMP)
    Call(N(JumpOnTarget), LVarA, 0)
    Call(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        Call(N(OnMissHeadbonk))
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        EndThread
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_TRIP)
        Wait(20)
        ExecWait(N(EVS_ReturnHome))
        Return
    EndIf
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(N(GetChargeAmount))
            Add(LVar0, 1)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseDefault
            Call(N(StopChargeAndGet))
            Add(LVar0, 1)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Thread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_50)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EndThread
    Call(GetActionResult, LVarF)
    Call(CloseActionCommandInfo)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 24, 3)
    Set(LVarA, 24)
    Thread
        Wait(4)
        Set(LVar0, 0)
        Loop(6)
            Add(LVar0, -30)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_HEADBONK)
    Call(N(JumpOnTarget), LVarA, 3)
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(N(StopChargeAndGet))
    Add(LVar0, 1)
    Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Call(SetActionResult, LVarF)
    ExecWait(N(returnHome2))
    Return
    End
};

EvtScript N(EVS_Attack_Headbonk2) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(runToTarget))
    ExecWait(N(calcJumpTime))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    Wait(1)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(action_command_jump_start, LVarA, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_JUMP)
    Call(N(JumpOnTarget), LVarA, 0)
    Call(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        Call(N(OnMissHeadbonk))
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        EndThread
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_TRIP)
        Wait(20)
        ExecWait(N(EVS_ReturnHome))
        Return
    EndIf
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(N(GetChargeAmount))
            Add(LVar0, 2)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseDefault
            Call(N(StopChargeAndGet))
            Add(LVar0, 2)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Thread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_50)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EndThread
    Call(GetActionResult, LVarF)
    Call(CloseActionCommandInfo)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 24, 3)
    Set(LVarA, 24)
    Thread
        Wait(4)
        Set(LVar0, 0)
        Loop(6)
            Add(LVar0, -30)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_HEADBONK)
    Call(N(JumpOnTarget), LVarA, 3)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_RESET)
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(N(StopChargeAndGet))
    Add(LVar0, 2)
    Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Call(SetActionResult, LVarF)
    ExecWait(N(returnHome2))
    Return
    End
};

EvtScript N(EVS_Attack_Headbonk3) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(runToTarget))
    ExecWait(N(calcJumpTime))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    Wait(1)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(action_command_jump_start, LVarA, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_JUMP)
    Call(N(JumpOnTarget), LVarA, 0)
    Call(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        Call(N(OnMissHeadbonk))
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        EndThread
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_TRIP)
        Wait(20)
        ExecWait(N(EVS_ReturnHome))
        Return
    EndIf
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(N(GetChargeAmount))
            Add(LVar0, 3)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseDefault
            Call(N(StopChargeAndGet))
            Add(LVar0, 3)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Thread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_50)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EndThread
    Call(GetActionResult, LVarF)
    Call(CloseActionCommandInfo)
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Call(ShowActionHud, FALSE)
    Call(action_command_jump_start, 24, 3)
    Set(LVarA, 24)
    Thread
        Wait(4)
        Set(LVar0, 0)
        Loop(6)
            Add(LVar0, -30)
            Call(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
            Wait(1)
        EndLoop
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EndThread
    Thread
        Set(LVar0, 0)
        Loop(LVarA)
            Add(LVar0, 133)
            Call(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
            Wait(1)
        EndLoop
    EndThread
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_HEADBONK)
    Call(N(JumpOnTarget), LVarA, 3)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_RESET)
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(N(StopChargeAndGet))
    Add(LVar0, 3)
    Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Call(SetActionResult, LVarF)
    ExecWait(N(returnHome2))
    Return
    End
};

s32 N(actionCommandTable)[] = { 7, 6, 5, 4, 3, 2, 1, 0 };

s32 N(MultibonkChance) = 200;

EvtScript N(EVS_Move_Multibonk) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(runToTarget))
    ExecWait(N(calcJumpTime))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 18, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    Wait(1)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(action_command_jump_start, LVarA, 1)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_52)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 9, 0)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_JUMP)
    Call(N(JumpOnTarget), LVarA, 0)
    Call(PartnerTestEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
        Call(N(OnMissHeadbonk))
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        EndThread
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_TRIP)
        Wait(20)
        ExecWait(N(EVS_ReturnHome))
        Return
    EndIf
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(N(GetChargeAmount))
            Add(LVar0, 3)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseDefault
            Call(N(StopChargeAndGet))
            Add(LVar0, 3)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Thread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_50)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EndThread
    Call(GetActionResult, LVarF)
    Set(LVarD, 0)
    Set(LVarF, 0)
    Set(LFlag0, FALSE)
    Label(10)
    Thread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_50)
        Wait(5)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_53)
    EndThread
    Call(CloseActionCommandInfo)
    Call(SetActionDifficultyTable, Ref(N(actionCommandTable)))
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    Set(LVarA, 24)
    Switch(LVarF)
        CaseEq(0)
            Call(action_command_jump_start, LVarA, 1)
        CaseEq(1)
            Call(action_command_jump_start, LVarA, 2)
        CaseEq(2)
            Call(action_command_jump_start, LVarA, 3)
        CaseEq(3)
            Call(action_command_jump_start, LVarA, 4)
        CaseDefault
            Call(action_command_jump_start, LVarA, 5)
    EndSwitch
    Thread
        Wait(4)
        Set(LVar0, 0)
        Loop(6)
            Add(LVar0, -30)
            Call(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
            Wait(1)
        EndLoop
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EndThread
    Thread
        Set(LVar0, 0)
        Loop(LVarA)
            Add(LVar0, 133)
            Call(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
            Wait(1)
        EndLoop
    EndThread
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
    Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_HEADBONK)
    Call(N(JumpOnTarget), LVarA, 3)
    Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_RESET)
    Sub(LVarD, 1)
    Call(N(AdjustMultibonkChance))
    IfGe(LVarF, LVar0)
        Set(LFlag0, TRUE)
    EndIf
    ChildThread
        Call(SetActorScale, ACTOR_PARTNER, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            IfEq(LFlag0, FALSE)
                Call(N(GetChargeAmount))
                Add(LVar0, 3)
                Call(PartnerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, LVarD, BS_FLAGS1_NICE_HIT)
            Else
                Call(N(StopChargeAndGet))
                Add(LVar0, 3)
                Call(PartnerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, LVarD, BS_FLAGS1_TRIGGER_EVENTS)
            EndIf
        CaseDefault
            Call(N(StopChargeAndGet))
            Add(LVar0, 3)
            Call(PartnerPowerBounceEnemy, LVar0, DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POWER_BOUNCE, 0, 0, LVar0, LVarD, BS_FLAGS1_TRIGGER_EVENTS)
            Set(LFlag0, FALSE)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Call(SetActionResult, LVarE)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            IfEq(LFlag0, TRUE)
                ExecWait(N(returnHome2))
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Add(LVarF, 1)
    Goto(10)
    Return
    End
};

EvtScript N(EVS_Move_Tattle) = {
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, TRUE)
    Call(N(OpenTattleWindow))
    Wait(12)
    Call(SetCamEnabled, CAM_TATTLE, TRUE)
    Call(SetCamNoDraw, CAM_TATTLE, FALSE)
    Call(SetCamPerspective, CAM_TATTLE, CAM_UPDATE_MODE_6, 25, 16, 1024)
    Call(SetCamViewport, CAM_TATTLE, 137, 95, 138, 99)
    Call(GetOwnerTarget, LVarA, LVarB)
    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(N(GetTattleCamPos))
    Wait(1)
    Call(SetCamLookTarget, CAM_TATTLE, LVar0, LVar1, LVar2)
    Call(SetInterpCamParams, CAM_TATTLE, 0, LVar3, 100, 4)
    Wait(2)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_TATTLE_WINDOW_OPEN)
    Call(SetCamNoDraw, CAM_TATTLE, TRUE)
    Wait(10)
    Call(N(GetTattleMessage))
    Call(ActorSpeak, LVar0, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    Call(N(CloseTattleWindow))
    Wait(12)
    Call(SetCamEnabled, CAM_TATTLE, FALSE)
    Wait(32)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, FALSE)
    Call(PartnerYieldTurn)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.8))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Return
    End
};

EvtScript N(EVS_Move_Charge) = {
    Call(UseBattleCamPreset, BTL_CAM_PRESET_55)
    Wait(10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 19, 0)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_CHARGE_UP)
    Call(N(PlayChargeFX), LVar0, LVar1, LVar2, Float(1.2))
    Wait(3)
    Call(N(PlayChargeFX), LVar0, LVar1, LVar2, Float(0.8))
    Thread
        Wait(15)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 15)
        Add(LVar2, -5)
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GOOMBARIO_GATHERING)
        PlayEffect(EFFECT_ENERGY_ORB_WAVE, 9, LVar0, LVar1, LVar2, Float(2.0), 20, 0)
    EndThread
    Wait(30)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(N(CanChargeMore))
    IfEq(LVar0, 0)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar0, 10)
        Add(LVar1, 25)
        Add(LVar2, 5)
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GROW)
        Call(N(ChargeAtPos), LVar0, LVar1, LVar2)
        Wait(4)
        Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PARTNER, ANIM_BattleGoombario_Jump, 0x00000001, ANIM_BattleGoombario_Jump, ANIM_BattleGoombario_Jump)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_PARTNER, 20, TRUE, TRUE, FALSE)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleGoombario_Idle)
        Call(GetMenuSelection, LVar0, LVar1, LVar2)
        Switch(LVar2)
            CaseEq(MOVE_TATTLE)
                Call(ShowMessageBox, BTL_MSG_CHARGE_GOOMBARIO, 60)
            CaseEq(MOVE_CHARGE)
                Call(N(GetChargeMessage))
                Call(ShowMessageBox, LVar0, 60)
            CaseEq(MOVE_MULTIBONK)
                Call(ShowMessageBox, BTL_MSG_CHARGE_GOOMBARIO, 60)
        EndSwitch
    Else
        Call(ShowMessageBox, BTL_MSG_CANT_CHARGE, 60)
    EndIf
    Label(0)
    Wait(1)
    Call(IsMessageBoxDisplayed, LVar0)
    IfEq(LVar0, 1)
        Goto(0)
    EndIf
    Return
    End
};
