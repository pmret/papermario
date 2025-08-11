#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "battle/action_cmd/body_slam.h"
#include "battle/action_cmd/power_shock.h"
#include "battle/action_cmd/three_chances.h"
#include "battle/action_cmd/mega_shock.h"
#include "sprite/npc/BattleWatt.h"
#include "sprite/player.h"

#define NAMESPACE battle_partner_watt

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(EVS_RunAway);
extern EvtScript N(EVS_RunAwayFail);
extern EvtScript N(EVS_Attack_ElectroDash);
extern EvtScript N(EVS_Attack_PowerShock);
extern EvtScript N(EVS_Attack_MegaShock);
extern EvtScript N(EVS_Move_TurboCharge);

extern EffectInstance* N(radialShimmer);
extern s32 D_8023B948_707438[];

static EffectInstance* N(bulbGlow);
static EffectInstance* N(thunderboltRing);

// surprisingly this can't be replaced by 'static WattEffectData sWattEffectData;'
static s32 sWattEffectData_initialized;
static s32 sWattEffectData_isBouncing;
static s32 sWattEffectData_bouncePhase;
static s32 sWattEffectData_isActive;
static s32 sWattEffectData_currentEffectIndex;
static EffectInstance* sWattEffectData_effect1;
static EffectInstance* sWattEffectData_effect2;

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_2           = 2,
};

API_CALLABLE(N(WattFXUpdate)) {
    Actor* partner = gBattleStatus.partnerActor;
    f32 x, y, z;

    if (isInitialCall) {
        sWattEffectData_isBouncing = true;
        sWattEffectData_bouncePhase = 0;
        sWattEffectData_isActive = true;
        sWattEffectData_currentEffectIndex = 0;
        sWattEffectData_effect1 = fx_static_status(0, partner->curPos.x, partner->curPos.y, partner->curPos.z, 1.0f, 5, 0);
        sWattEffectData_effect2 = fx_static_status(1, partner->curPos.x, NPC_DISPOSE_POS_Y, partner->curPos.z, 1.0f, 5, 0);
        sWattEffectData_initialized = true;
    }

    if (!sWattEffectData_initialized) {
        return ApiStatus_DONE2;
    }

    if (sWattEffectData_isBouncing) {
        sWattEffectData_bouncePhase += 15;
        sWattEffectData_bouncePhase = clamp_angle(sWattEffectData_bouncePhase);
    }

    partner->verticalRenderOffset = sin_rad(DEG_TO_RAD(sWattEffectData_bouncePhase)) * 3.0f;
    x = partner->curPos.x + partner->headOffset.x;
    y = partner->curPos.y + partner->headOffset.y + partner->verticalRenderOffset + 12.0f;
    z = partner->curPos.z + partner->headOffset.z;
    if (!(gBattleStatus.flags2 & BS_FLAGS2_OVERRIDE_INACTIVE_PARTNER) && (gBattleStatus.flags2 & BS_FLAGS2_PARTNER_TURN_USED)) {
        y = NPC_DISPOSE_POS_Y;
    }

    if (sWattEffectData_isActive) {
        switch (sWattEffectData_currentEffectIndex) {
            case 0:
                if (sWattEffectData_effect1 == nullptr) {
                    sWattEffectData_effect1 = fx_static_status(0, x, y, z, 1.0f, 5, 0);
                }
                if (sWattEffectData_effect2 != nullptr) {
                    sWattEffectData_effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
                    sWattEffectData_effect2 = nullptr;
                }
                sWattEffectData_effect1->data.staticStatus->pos.x = x;
                sWattEffectData_effect1->data.staticStatus->pos.y = y;
                sWattEffectData_effect1->data.staticStatus->pos.z = z;
                break;
            case 1:
                if (sWattEffectData_effect1 != nullptr) {
                    sWattEffectData_effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
                    sWattEffectData_effect1 = nullptr;
                }
                if (sWattEffectData_effect2 == nullptr) {
                    sWattEffectData_effect2 = fx_static_status(1, x, y, z, 1.0f, 5, 0);
                }
                sWattEffectData_effect2->data.staticStatus->pos.x = x;
                sWattEffectData_effect2->data.staticStatus->pos.y = y;
                sWattEffectData_effect2->data.staticStatus->pos.z = z;
                break;
        }
    } else {
        if (sWattEffectData_effect1 != nullptr) {
            sWattEffectData_effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
            sWattEffectData_effect1 = nullptr;
        }
        if (sWattEffectData_effect2 != nullptr) {
            sWattEffectData_effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
            sWattEffectData_effect2 = nullptr;
        }
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(WattFXRemove)) {
    sWattEffectData_initialized = false;
    if (sWattEffectData_effect1 != nullptr) {
        remove_effect(sWattEffectData_effect1);
    }
    if (sWattEffectData_effect2 != nullptr) {
        remove_effect(sWattEffectData_effect2);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXBounce)) {
    sWattEffectData_isBouncing = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXDisableBounce)) {
    sWattEffectData_isBouncing = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXEnable)) {
    sWattEffectData_isActive = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXDisable)) {
    sWattEffectData_isActive = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXSetEffect)) {
    sWattEffectData_currentEffectIndex = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

API_CALLABLE(N(ElectroDashFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    N(radialShimmer) = fx_radial_shimmer(8, x, y, z, 1.3f, 55);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ElectroDashFXDisable)) {
    EffectInstance* effect = N(radialShimmer);

    if (effect != nullptr) {
        effect->flags |= FX_INSTANCE_FLAG_DISMISS;
    }
    N(radialShimmer) = nullptr;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PowerShockFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    ThunderboltRingFXData* data;

    N(thunderboltRing) = fx_thunderbolt_ring(0, x, y, z, 1.0f, 10);
    data = N(thunderboltRing)->data.thunderboltRing;
    data->unk_30 = 3;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(PowerShockDischargeFX)) {
    Bytecode* args = script->ptrReadPos;
    Actor* partner = gBattleStatus.partnerActor;
    f32 x = partner->curPos.x + partner->headOffset.x;
    f32 y = partner->curPos.y + partner->headOffset.y + partner->verticalRenderOffset + 12.0f;
    f32 z = partner->curPos.z + partner->headOffset.z;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        fx_bulb_glow(0, x, y, z, 1.0f, &N(bulbGlow));
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        N(bulbGlow)->data.bulbGlow->timeLeft = 5;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(TargetParalyzeChance)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartID);
    s32 statusChance = lookup_status_chance(targetActor->statusTable, STATUS_KEY_PARALYZE);

    if (targetActor->transparentStatus == STATUS_KEY_TRANSPARENT) {
        statusChance = 0;
    }
    if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        statusChance = 0;
    }

    script->varTable[0] = statusChance;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(TurboChargeUnwindWatt)) {
    Bytecode* args = script->ptrReadPos;
    Actor* partner = gBattleStatus.partnerActor;
    Actor* player = gBattleStatus.playerActor;
    ActorState* partnerState = &partner->state;
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    f32 distance;
    f32 angle;
    f32 deltaX;
    f32 deltaY;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[2] = evt_get_variable(script, *args++);
            partner->state.dist = dist2D(player->curPos.x, player->curPos.y, partner->curPos.x, partner->curPos.y);

            partner->state.goalPos.x = player->curPos.x;
            partner->state.goalPos.y = player->curPos.y + 36.0f;
            partner->state.goalPos.z = player->curPos.z;

            partner->state.curPos.x = partner->curPos.x;
            partner->state.curPos.y = partner->curPos.y;
            partner->state.curPos.z = partner->curPos.z;

            partner->state.angle = 90.0f;
            partner->state.vel = 5.0f;
            partner->state.acceleration = 0.5f;
            partner->state.moveTime = 90;
            script->functionTemp[1] = 10;
            script->functionTemp[0] = 1;
            break;
        case 1:
            theta = DEG_TO_RAD(partner->state.angle);
            sinTheta = sin_rad(theta);
            cosTheta = cos_rad(theta);
            partner->state.vel += partner->state.acceleration;
            angle = partner->state.angle;
            angle += partner->state.vel;
            deltaX = partner->state.dist * sinTheta;
            deltaY = -partner->state.dist * cosTheta;
            partner->state.curPos.x = partner->state.goalPos.x + deltaX;
            partner->state.curPos.y = partner->state.goalPos.y + deltaY;
            partner->state.angle = angle;
            partner->state.angle = clamp_angle(angle);

            partner->state.moveTime--;
            if (partner->state.moveTime == 0) {
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            theta = DEG_TO_RAD(partner->state.angle);
            sinTheta = sin_rad(theta);
            cosTheta = cos_rad(theta);
            distance = partner->state.dist;
            angle = partner->state.angle;
            angle += partner->state.vel;
            deltaX = partner->state.dist * sinTheta;
            deltaY = -partner->state.dist * cosTheta;
            partner->state.curPos.x = partner->state.goalPos.x + deltaX;
            partner->state.curPos.y = partner->state.goalPos.y + deltaY;
            partner->state.angle = angle;
            partner->state.angle = clamp_angle(angle);
            if (partner->state.angle < 45.0f) {
                script->functionTemp[0] = 3;
                break;
            }
        case 3:
            player->yaw = 0.0f;
            partner->yaw = 0.0f;
            return ApiStatus_DONE2;
    }

    if (partnerState->angle > 180.0f) {
        partner->yaw = 0.0f;
    } else {
        partner->yaw = 180.0f;
    }

    partner->curPos.x = partnerState->curPos.x;
    partner->curPos.y = partnerState->curPos.y;
    partner->curPos.z = partnerState->curPos.z;
    if (script->functionTemp[2] == 0) {
        player->yaw += script->functionTemp[1];
        script->functionTemp[1]++;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(TurboChargeFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    ThunderboltRingFXData* data;

    N(thunderboltRing) = fx_thunderbolt_ring(0, x, y, z, 1.0f, 60);
    data = N(thunderboltRing)->data.thunderboltRing;
    data->unk_30 = 2;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ApplyTurboCharge)) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 actionCommandResult = script->varTable[0];

    if (actionCommandResult > 0) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = 0;
    script->varTable[10] = actionCommandResult;
    if (battleStatus->turboChargeTurnsLeft < actionCommandResult) {
        battleStatus->turboChargeTurnsLeft = actionCommandResult;
        battleStatus->turboChargeAmount = 1;
        battleStatus->buffEffect->data.partnerBuff->unk_0C[FX_BUFF_DATA_TURBO_CHARGE].turnsLeft = battleStatus->turboChargeTurnsLeft;
    }

    if (gBattleStatus.flags2 & BS_FLAGS2_PLAYER_TURN_USED) {
        gBattleStatus.flags2 |= BS_FLAGS2_STORED_TURBO_CHARGE_TURN;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(MegaShockFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x;
    s32 y;
    s32 z;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTemp[1] = evt_get_variable(script, *args++);
            x = evt_get_variable(script, *args++);
            y = evt_get_variable(script, *args++);
            z = evt_get_variable(script, *args++);
            script->functionTemp[2] = 20;
            script->functionTemp[3] = 10;
            N(thunderboltRing) = fx_thunderbolt_ring(0, x, y, z, 1.0f, script->functionTemp[2] + 10);
            N(thunderboltRing)->data.thunderboltRing->unk_30 = 3;
            script->functionTemp[1] = D_8023B948_707438[script->functionTemp[1] / 16];
            script->functionTemp[0] = 1;
            break;
        case 1:
            N(thunderboltRing)->data.thunderboltRing->unk_30 =
                ((script->functionTemp[3] * 3) + (script->functionTemp[1] * (10 - script->functionTemp[3]))) / 10;
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
            }
            if (script->functionTemp[2] == 0) {
                N(thunderboltRing)->flags |= FX_INSTANCE_FLAG_DISMISS;
                return ApiStatus_DONE2;
            }
            script->functionTemp[2]--;
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(AverageTargetParalyzeChance)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    s32 targetActorBlueprintBaseStatusChance;
    s32 chanceTotal = 0;
    s32 nTargets = 0;
    s32 i;

    for (i = 0; i < partnerActor->targetListLength; i++) {
        targetActor = get_actor(partnerActor->targetData[i].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[i].partID);
        targetActorBlueprintBaseStatusChance = lookup_status_chance(targetActor->statusTable, STATUS_KEY_PARALYZE);

        if (targetActor->transparentStatus == STATUS_KEY_TRANSPARENT) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorBlueprintBaseStatusChance > 0) {
            chanceTotal += targetActorBlueprintBaseStatusChance;
            nTargets++;
        }
    }

    if (nTargets > 0) {
        script->varTable[0] = chanceTotal / nTargets;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleWatt_Walk,
    STATUS_KEY_STONE,     ANIM_BattleWatt_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleWatt_Sleep,
    STATUS_KEY_POISON,    ANIM_BattleWatt_Still,
    STATUS_KEY_STOP,      ANIM_BattleWatt_Still,
    STATUS_KEY_DAZE,      ANIM_BattleWatt_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleWatt_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,   99,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 10, 22 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_WATT,
    .level = ACTOR_LEVEL_WATT,
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
    .size = { 34, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    SetPriority(99)
    Call(N(WattFXUpdate))
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, false)
    Call(InterruptActionCommand)
    Call(N(WattFXDisableBounce))
    Call(N(WattFXEnable))
    Call(N(WattFXSetEffect), 0)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            SetConst(LVar2,  ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Partner_Hit)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Partner_NoDamageHit)
            Call(N(WattFXBounce))
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            SetConst(LVar2, 12)
            ExecWait(EVS_Partner_SpikeContact)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            Call(N(WattFXDisable))
            SetConst(LVar1,  ANIM_BattleWatt_BurnHurt)
            Set(LVar2, 12)
            SetConst(LVar3, ANIM_BattleWatt_BurnStill)
            ExecWait(EVS_Partner_BurnContact)
            Call(N(WattFXEnable))
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1,  ANIM_BattleWatt_BurnHurt)
            SetConst(LVar2, ANIM_BattleWatt_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            Set(LVar2, 12)
            ExecWait(EVS_Partner_ShockHit)
        CaseEq(EVENT_33)
            SetConst(LVar1,  ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            Call(N(WattFXBounce))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1,  ANIM_BattleWatt_Idle)
            SetConst(LVar2,  ANIM_BattleWatt_Run)
            Set(LVar3, 20)
            ExecWait(EVS_Partner_Recover)
            Call(N(WattFXBounce))
        CaseEq(EVENT_PUT_PARTNER_AWAY)
            Call(N(WattFXRemove))
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Block)
            ExecWait(EVS_Partner_NoDamageHit)
            Wait(10)
        EndCaseGroup
        CaseEq(EVENT_LIFE_SHROOM_PROC)
            Call(N(WattFXDisable))
        CaseEq(EVENT_REVIVE)
            Call(N(WattFXEnable))
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
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
    Call(N(WattFXEnable))
    Call(N(WattFXSetEffect), 1)
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleWatt_Celebrate)
    SetConst(LVar2,  ANIM_BattleWatt_Walk)
    SetConst(LVar3,  ANIM_BattleWatt_Idle)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(EVS_RunAway) = {
    Call(N(WattFXEnable))
    Call(N(WattFXSetEffect), 1)
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1,  ANIM_BattleWatt_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(EVS_RunAwayFail) = {
    Call(N(WattFXEnable))
    Call(N(WattFXSetEffect), 1)
    Call(UseIdleAnimation, ACTOR_PARTNER, false)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, true)
    Call(N(WattFXSetEffect), 0)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(ShowActionHud, true)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, false)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_ELECTRO_DASH1)
            ExecWait(N(EVS_Attack_ElectroDash))
        CaseEq(MOVE_ELECTRO_DASH2)
            ExecWait(N(EVS_Attack_ElectroDash))
        CaseEq(MOVE_ELECTRO_DASH3)
            ExecWait(N(EVS_Attack_ElectroDash))
        CaseEq(MOVE_POWER_SHOCK)
            ExecWait(N(EVS_Attack_PowerShock))
        CaseEq(MOVE_TURBO_CHARGE)
            ExecWait(N(EVS_Move_TurboCharge))
        CaseEq(MOVE_MEGA_SHOCK)
            ExecWait(N(EVS_Attack_MegaShock))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ReturnHome_Success) = {
    Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    Return
    End
};

EvtScript N(EVS_ReturnHome_Miss) = {
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    Return
    End
};

EffectInstance* N(radialShimmer) = nullptr;

EvtScript N(dashToTarget) = {
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_LINEAR)
    Return
    End
};

EvtScript N(charge) = {
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
    Call(N(WattFXDisable))
    Call(PlayLoopingSoundAtActor, ACTOR_PARTNER, 0, SOUND_WATT_CHARGE)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 12)
    Call(N(ElectroDashFX), LVar0, LVar1, LVar2)
    Call(N(UnkBackgroundFunc3))
    Set(LVar9, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBigger)
    Loop(55)
        Add(LVar9, 30)
        IfGt(LVar9, 200)
            Set(LVar9, 200)
        EndIf
        Call(N(SetBackgroundAlpha), LVar9)
        Wait(1)
    EndLoop
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_WATT_IDLE)
    Return
    End
};

EvtScript N(EVS_ElectroDashDelay) = {
    Loop(30)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Attack_ElectroDash) = {
    Call(LoadActionCommand, ACTION_COMMAND_BODY_SLAM)
    Call(action_command_body_slam_init)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_CLOSER_PARTNER_APPROACH)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    Set(LFlag2, false)
    Loop(60)
        Call(CheckButtonDown, BUTTON_A, LVar0)
        IfNe(LVar0, 0)
            Set(LFlag2, true)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(MoveBattleCamOver, 75)
    IfEq(LFlag2, true)
        Call(action_command_body_slam_start, 0, 102, AC_DIFFICULTY_STANDARD, ACV_SLAM_WATT)
        Set(LFlag0, false)
        ExecGetTID(N(dashToTarget), LVarA)
        Loop(20)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfEq(LVar0, 0)
                Set(LFlag0, true)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, true)
            KillThread(LVarA)
            Goto(10)
        EndIf
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
        Set(LFlag0, false)
        ExecGetTID(N(charge), LVarA)
        Loop(55)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfEq(LVar0, 0)
                Set(LFlag0, true)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, true)
            KillThread(LVarA)
            Goto(10)
        EndIf
        IfEq(LFlag0, false)
            ExecGetTID(N(EVS_ElectroDashDelay), LVarA)
            Loop(30)
                Call(CheckButtonDown, BUTTON_A, LVar0)
                IfEq(LVar0, 0)
                    Set(LFlag0, true)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, true)
                KillThread(LVarA)
                Goto(10)
            EndIf
        EndIf
    Else
        Set(LFlag0, false)
        ExecGetTID(N(dashToTarget), LVarA)
        Loop(20)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfNe(LVar0, 0)
                IfEq(LFlag2, false)
                    Call(action_command_body_slam_start, 0, 92, AC_DIFFICULTY_STANDARD, ACV_SLAM_WATT)
                    Set(LFlag2, true)
                EndIf
            EndIf
            IfEq(LFlag2, true)
                IfEq(LVar0, 0)
                    Set(LFlag0, true)
                    BreakLoop
                EndIf
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, true)
            KillThread(LVarA)
            Goto(10)
        EndIf
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
        Set(LFlag0, false)
        ExecGetTID(N(charge), LVarA)
        Loop(55)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfNe(LVar0, 0)
                IfEq(LFlag2, false)
                    Call(action_command_body_slam_start, 0, 92, AC_DIFFICULTY_STANDARD, ACV_SLAM_WATT)
                    Set(LFlag2, true)
                EndIf
            EndIf
            IfEq(LFlag2, true)
                IfEq(LVar0, 0)
                    Set(LFlag0, true)
                    BreakLoop
                EndIf
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, true)
            KillThread(LVarA)
            Goto(10)
        EndIf
        IfEq(LFlag0, false)
            ExecGetTID(N(EVS_ElectroDashDelay), LVarA)
            Loop(30)
                Call(CheckButtonDown, BUTTON_A, LVar0)
                IfEq(LVar0, 0)
                    Set(LFlag0, true)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, true)
                KillThread(LVarA)
                Goto(10)
            EndIf
        EndIf
    EndIf
    Label(10)
    Wait(2)
    Call(InterruptActionCommand)
    Call(N(ElectroDashFXDisable))
    Call(StopLoopingSoundAtActor, ACTOR_PARTNER, 0)
    Call(SetDamageSource, DMG_SRC_ELECTRO_DASH)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_WATT_ATTACK)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -5, 0, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    Thread
        Wait(2)
        Call(N(SetBackgroundAlpha), 0)
    EndThread
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Thread
            Wait(5)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        EndThread
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(AddGoalPos, ACTOR_PARTNER, 40, 10, 0)
        Call(FlyToGoal, ACTOR_PARTNER, 10, -20, EASING_QUADRATIC_OUT)
        Wait(20)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
        Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        Return
    EndIf
    Call(N(WattFXEnable))
    Call(N(WattFXBounce))
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_ELECTRO_DASH1)
            Set(LVarE, 1)
            Set(LVarF, 3)
        CaseEq(MOVE_ELECTRO_DASH2)
            Set(LVarE, 1)
            Set(LVarF, 4)
        CaseEq(MOVE_ELECTRO_DASH3)
            Set(LVarE, 1)
            Set(LVarF, 5)
    EndSwitch
    Call(GetPartnerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarF, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Call(PartnerYieldTurn)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome_Success))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome_Miss))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_PowerShock) = {
    Call(LoadActionCommand, ACTION_COMMAND_POWER_SHOCK)
    Call(action_command_power_shock_init)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Call(SetActionHudPrepareTime, 0)
    Set(LFlagF, false)
    Call(GetOwnerTarget, LVarA, LVarB)
    Call(GetActorFlags, LVarA, LVar0)
    IfFlag(LVar0, ACTOR_FLAG_UPSIDE_DOWN)
        Set(LFlagF, true)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_APPROACH)
    Call(MoveBattleCamOver, 40)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    Call(N(WattFXSetEffect), 1)
    Call(AddGoalPos, ACTOR_PARTNER, -15, -10, 0)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Call(AddBattleCamDist, -100)
    Call(MoveBattleCamOver, 80)
    Call(N(WattFXDisable))
    Call(N(TargetParalyzeChance))
    Call(action_command_power_shock_start, 0, 75 * DT - 3, AC_DIFFICULTY_STANDARD, LVar0)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Add(LVar2, 5)
    PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(1.0), 75 * DT, 0)
    Call(N(UnkBackgroundFunc3))
    Set(LVar9, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBigger)
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_WATT_ATTACK)
    Thread
        Loop(75 * DT)
            Add(LVar9, 3)
            Call(N(SetBackgroundAlpha), LVar9)
            Wait(1)
        EndLoop
    EndThread
    Wait(75 * DT)
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_WATT_IDLE)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_WATT_POWER_SHOCK)
    Thread
        SetF(LVar0, Float(1.0))
        Loop(3)
            AddF(LVar0, Float(0.4))
            Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 8)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.8), 30, 0)
    EndThread
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Add(LVar2, 5)
    Call(N(PowerShockFX), LVar0, LVar1, LVar2)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_APPROACH)
    Call(AddBattleCamDist, 100)
    Call(MoveBattleCamOver, 5)
    Thread
        Call(N(PowerShockDischargeFX), 20)
    EndThread
    Loop(3)
        Call(N(SetBackgroundAlpha), 0)
        Wait(1)
        Call(N(SetBackgroundAlpha), 200)
        Wait(1)
    EndLoop
    Call(N(SetBackgroundAlpha), 0)
    Wait(10)
    Call(N(WattFXEnable))
    Call(N(WattFXSetEffect), 0)
    Thread
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 20, 0)
        SetF(LVar0, Float(2.2))
        Loop(12)
            SubF(LVar0, Float(0.1))
            Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EndThread
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Wait(15)
        ExecWait(N(EVS_ReturnHome_Miss))
        Return
    EndIf
    Call(GetActionProgress, LVarF)
    Call(GetPartnerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), 254, 0, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        CaseDefault
            Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), 255, 0, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Call(PartnerYieldTurn)
    IfNe(LFlagF, true)
        Call(AddGoalPos, ACTOR_PARTNER, -25, 10, 0)
        Call(FlyToGoal, ACTOR_PARTNER, 15, -10, EASING_COS_IN_OUT)
    Else
        Call(AddGoalPos, ACTOR_PARTNER, -25, -10, 0)
        Call(FlyToGoal, ACTOR_PARTNER, 15, -10, EASING_COS_IN_OUT)
    EndIf
    Wait(30)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome_Success))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome_Miss))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TurboCharge_HealthyPlayer) = {
    Call(LoadActionCommand, ACTION_COMMAND_THREE_CHANCES)
    Call(action_command_three_chances_init, ACV_THREE_CHANCES_TURBO_CHARGE)
    Call(SetActionHudPrepareTime, 0)
    Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_NO_INACTIVE_ANIM, true)
    Call(UseIdleAnimation, ACTOR_PLAYER, false)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    Wait(5)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, -125, 42, 0)
    Call(SetBattleCamOffsetY, 0)
    Call(SetBattleCamDist, 340)
    Call(MoveBattleCamOver, 30)
    Call(SetActorYaw, ACTOR_PARTNER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 180)
    Wait(10)
    Call(action_command_three_chances_start, 0, 100 * DT, AC_DIFFICULTY_STANDARD)
    Call(AddBattleCamDist, -75)
    Call(MoveBattleCamOver, 100 * DT)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_NONE, BTL_CAM_XADJ_NONE, true)
    Thread
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
        Call(N(TurboChargeUnwindWatt), 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_CUBIC_OUT)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        Wait(10)
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    EndThread
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_WATT_TURBO_CHARGE)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 42)
    Call(N(TurboChargeFX), LVar0, LVar1, LVar2)
    Wait(59)
    Call(AddBattleCamDist, 100)
    Call(MoveBattleCamOver, 5)
    Thread
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
        Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerHopToGoal, 20, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EndThread
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GROW)
    Call(GetPartnerActionQuality, LVar0)
    Call(N(ApplyTurboCharge))
    Set(LVarE, LVarF)
    IfGt(LVarA, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Add(LVarF, 0)
        PlayEffect(EFFECT_STAT_CHANGE, LVarF, LVar0, LVar1, LVar2, Float(1.5), 60, 0)
        Wait(4)
    EndIf
    IfEq(LVar0, 0)
    Else
        Call(ShowVariableMessageBox, BTL_MSG_TURBO_CHARGE_BEGIN, 60, LVarA)
    EndIf
    Call(WaitForMessageBoxDone)
    Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_NO_INACTIVE_ANIM, false)
    Return
    End
};

EvtScript N(EVS_TurboCharge_ImmobilePlayer) = {
    Call(LoadActionCommand, ACTION_COMMAND_THREE_CHANCES)
    Call(action_command_three_chances_init, ACV_THREE_CHANCES_TURBO_CHARGE)
    Call(SetActionHudPrepareTime, 0)
    Call(UseIdleAnimation, ACTOR_PLAYER, false)
    Wait(5)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, -125, 42, 0)
    Call(SetBattleCamOffsetY, 0)
    Call(SetBattleCamDist, 340)
    Call(MoveBattleCamOver, 30)
    Call(SetActorYaw, ACTOR_PARTNER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PARTNER, 180)
    Wait(10)
    Call(action_command_three_chances_start, 0, 100 * DT, AC_DIFFICULTY_STANDARD)
    Call(AddBattleCamDist, -100)
    Call(MoveBattleCamOver, 100 * DT)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_NONE, BTL_CAM_XADJ_NONE, true)
    Thread
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
        Call(N(TurboChargeUnwindWatt), 1)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_CUBIC_OUT)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        Wait(10)
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
    EndThread
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_WATT_TURBO_CHARGE)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 42)
    Call(N(TurboChargeFX), LVar0, LVar1, LVar2)
    Wait(59)
    Call(AddBattleCamDist, 100)
    Call(MoveBattleCamOver, 5)
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_GROW)
    Call(GetPartnerActionQuality, LVar0)
    Call(N(ApplyTurboCharge))
    Set(LVarE, LVarF)
    IfGt(LVarA, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 35)
        Add(LVarF, 0)
        PlayEffect(EFFECT_STAT_CHANGE, LVarF, LVar0, LVar1, LVar2, Float(1.5), 60, 0)
        Wait(4)
    EndIf
    IfEq(LVar0, 0)
    Else
        Call(ShowVariableMessageBox, BTL_MSG_TURBO_CHARGE_BEGIN, 60, LVarA)
    EndIf
    Call(WaitForMessageBoxDone)
    Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_NO_INACTIVE_ANIM, false)
    Return
    End
};

EvtScript N(EVS_Move_TurboCharge) = {
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        ExecWait(N(EVS_TurboCharge_ImmobilePlayer))
    Else
        ExecWait(N(EVS_TurboCharge_HealthyPlayer))
    EndIf
    Return
    End
};

s32 D_8023B948_707438[] = { 3, 3, 4, 7, 10, 13, 16, 16, 16, 16 };

EvtScript N(EVS_Attack_MegaShock) = {
    Call(LoadActionCommand, ACTION_COMMAND_MEGA_SHOCK)
    Call(action_command_mega_shock_init)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Call(SetActionHudPrepareTime, 0)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, -54, 63, 10)
    Call(SetBattleCamOffsetY, 15)
    Call(SetBattleCamDist, 314)
    Call(MoveBattleCamOver, 30)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Add(LVar1, 30)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    Call(N(UnkBackgroundFunc3))
    Set(LVar9, 0)
    Thread
        Loop(75 * DT)
            Add(LVar9, 3)
            Call(N(SetBackgroundAlpha), LVar9)
            Wait(1)
        EndLoop
    EndThread
    Call(N(AverageTargetParalyzeChance))
    Call(action_command_mega_shock_start, 0, 87 * DT, AC_DIFFICULTY_STANDARD, LVar0)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Add(LVar2, 5)
    PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(1.0), 90 * DT, 0)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 12)
    PlayEffect(EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, Float(1.3), 90 * DT, 0)
    Call(AddBattleCamDist, -100)
    Call(MoveBattleCamOver, 90 * DT)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_NONE, BTL_CAM_XADJ_NONE, true)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBigger)
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_WATT_ATTACK)
    Call(N(WattFXDisable))
    Call(GetActionProgress, LVar1)
    Wait(90 * DT)
    Call(N(SetBackgroundAlpha), 0)
    Thread
        Set(LVar9, 60)
        Loop(20)
            Sub(LVar9, 3)
            Call(N(SetBackgroundAlpha), LVar9)
            Wait(1)
        EndLoop
    EndThread
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_WATT_IDLE)
    Call(InitTargetIterator)
    Thread
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 12)
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_WATT_MEGA_DISCHARGE)
        PlayEffect(EFFECT_FLASHING_BOX_SHOCKWAVE, FX_SHOCK_OVERLAY_MEGA_SHOCK, LVar0, LVar1, LVar2, 0, 0, 0)
        Wait(10)
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_WATT_MEGA_CHARGE_WAVE)
        PlayEffect(EFFECT_FLASHING_BOX_SHOCKWAVE, FX_SHOCK_OVERLAY_MEGA_SHOCK, LVar0, LVar1, LVar2, 0, 0, 0)
    EndThread
    Thread
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBiggest)
        Wait(5)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
        Wait(30)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EndThread
    Thread
        Call(SetBattleCamDist, 420)
        Call(SetBattleCamTarget, 6, 63, 10)
        Call(MoveBattleCamOver, 15)
        Wait(4)
        Set(LVar0, 6)
        Loop(30)
            Add(LVar0, 1)
            Call(SetBattleCamTarget, LVar0, 63, 10)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(N(PowerShockDischargeFX), 10)
    EndThread
    Call(GetActionProgress, LVar0)
    Call(GetActorPos, ACTOR_PARTNER, LVar1, LVar2, LVar3)
    Add(LVar2, 12)
    Call(N(MegaShockFX), LVar0, LVar1, LVar2, LVar3)
    Loop(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetPartnerActionQuality, LVarF)
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(11)
        EndIf
        IfEq(LVarF, 100)
            Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), 254, 0, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        Else
            Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), LVarF, 0, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_NICE_HIT)
        EndIf
        Label(11)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfEq(LVar0, ITER_NO_MORE)
            BreakLoop
        EndIf
        Wait(5)
    EndLoop
    Call(N(WattFXEnable))
    Call(PartnerYieldTurn)
    Wait(30)
    Call(GetPartnerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(99)
            ExecWait(N(EVS_ReturnHome_Success))
        CaseDefault
            ExecWait(N(EVS_ReturnHome_Miss))
    EndSwitch
    Return
    End
};
