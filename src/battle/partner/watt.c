#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "battle/action_cmd/body_slam.h"
#include "battle/action_cmd/power_shock.h"
#include "battle/action_cmd/water_block.h"
#include "battle/action_cmd/mega_shock.h"
#include "sprite/npc/BattleWatt.h"

#define NAMESPACE battle_partner_watt

extern EvtScript N(handleEvent);
extern EvtScript N(idle);
extern EvtScript N(nextTurn);
extern EvtScript N(takeTurn);
extern EvtScript N(init);
extern EvtScript N(executeAction);
extern EvtScript N(celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(electroDash);
extern EvtScript N(powerShock);
extern EvtScript N(turboCharge);
extern EvtScript N(megaShock);

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

API_CALLABLE(N(WattFXUpdate)) {
    Actor* partner = gBattleStatus.partnerActor;
    f32 x, y, z;

    if (isInitialCall) {
        sWattEffectData_isBouncing = TRUE;
        sWattEffectData_bouncePhase = 0;
        sWattEffectData_isActive = TRUE;
        sWattEffectData_currentEffectIndex = 0;
        sWattEffectData_effect1 = fx_static_status(0, partner->currentPos.x, partner->currentPos.y, partner->currentPos.z, 1.0f, 5, 0);
        sWattEffectData_effect2 = fx_static_status(1, partner->currentPos.x, NPC_DISPOSE_POS_Y, partner->currentPos.z, 1.0f, 5, 0);
        sWattEffectData_initialized = TRUE;
    }

    if (sWattEffectData_initialized == 0) {
        return ApiStatus_DONE2;
    }

    if (sWattEffectData_isBouncing) {
        sWattEffectData_bouncePhase += 15;
        sWattEffectData_bouncePhase = clamp_angle(sWattEffectData_bouncePhase);
    }

    partner->verticalRenderOffset = sin_rad(DEG_TO_RAD(sWattEffectData_bouncePhase)) * 3.0f;
    x = partner->currentPos.x + partner->headOffset.x;
    y = partner->currentPos.y + partner->headOffset.y + partner->verticalRenderOffset + 12.0f;
    z = partner->currentPos.z + partner->headOffset.z;
    if ((gBattleStatus.flags2 & (BS_FLAGS2_10 | BS_FLAGS2_4)) == BS_FLAGS2_4) {
        y = NPC_DISPOSE_POS_Y;
    }

    if (sWattEffectData_isActive) {
        switch (sWattEffectData_currentEffectIndex) {
            case 0:
                if (sWattEffectData_effect1 == NULL) {
                    sWattEffectData_effect1 = fx_static_status(0, x, y, z, 1.0f, 5, 0);
                }
                if (sWattEffectData_effect2 != NULL) {
                    sWattEffectData_effect2->flags |= EFFECT_INSTANCE_FLAG_10;
                    sWattEffectData_effect2 = NULL;
                }
                sWattEffectData_effect1->data.staticStatus->pos.x = x;
                sWattEffectData_effect1->data.staticStatus->pos.y = y;
                sWattEffectData_effect1->data.staticStatus->pos.z = z;
                break;
            case 1:
                if (sWattEffectData_effect1 != NULL) {
                    sWattEffectData_effect1->flags |= EFFECT_INSTANCE_FLAG_10;
                    sWattEffectData_effect1 = NULL;
                }
                if (sWattEffectData_effect2 == NULL) {
                    sWattEffectData_effect2 = fx_static_status(1, x, y, z, 1.0f, 5, 0);
                }
                sWattEffectData_effect2->data.staticStatus->pos.x = x;
                sWattEffectData_effect2->data.staticStatus->pos.y = y;
                sWattEffectData_effect2->data.staticStatus->pos.z = z;
                break;
        }
    } else {
        if (sWattEffectData_effect1 != NULL) {
            sWattEffectData_effect1->flags |= EFFECT_INSTANCE_FLAG_10;
            sWattEffectData_effect1 = NULL;
        }
        if (sWattEffectData_effect2 != NULL) {
            sWattEffectData_effect2->flags |= EFFECT_INSTANCE_FLAG_10;
            sWattEffectData_effect2 = NULL;
        }
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(WattFXRemove)) {
    sWattEffectData_initialized = 0;
    if (sWattEffectData_effect1 != NULL) {
        remove_effect(sWattEffectData_effect1);
    }
    if (sWattEffectData_effect2 != NULL) {
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

    if (effect != NULL) {
        effect->flags |= EFFECT_INSTANCE_FLAG_10;
    }
    N(radialShimmer) = NULL;

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
    f32 x = partner->currentPos.x + partner->headOffset.x;
    f32 y = partner->currentPos.y + partner->headOffset.y + partner->verticalRenderOffset + 12.0f;
    f32 z = partner->currentPos.z + partner->headOffset.z;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args++);
        fx_bulb_glow(0, x, y, z, 1.0f, &N(bulbGlow));
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        N(bulbGlow)->data.bulbGlow->unk_14 = 5;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(TargetParalyzeChance)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor = get_actor(partnerActor->targetActorID);
    ActorPart* targetActorPart = get_actor_part(targetActor, partnerActor->targetPartIndex);
    s32 statusChance = lookup_status_chance(targetActor->statusTable, STATUS_PARALYZE);

    if (targetActor->transparentStatus == STATUS_TRANSPARENT) {
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
            partner->state.distance = dist2D(player->currentPos.x, player->currentPos.y, partner->currentPos.x, partner->currentPos.y);

            partner->state.goalPos.x = player->currentPos.x;
            partner->state.goalPos.y = player->currentPos.y + 36.0f;
            partner->state.goalPos.z = player->currentPos.z;

            partner->state.currentPos.x = partner->currentPos.x;
            partner->state.currentPos.y = partner->currentPos.y;
            partner->state.currentPos.z = partner->currentPos.z;

            partner->state.angle = 90.0f;
            partner->state.velocity = 5.0f;
            partner->state.acceleration = 0.5f;
            partner->state.moveTime = 90;
            script->functionTemp[1] = 10;
            script->functionTemp[0] = 1;
            break;
        case 1:
            theta = DEG_TO_RAD(partner->state.angle);
            sinTheta = sin_rad(theta);
            cosTheta = cos_rad(theta);
            partner->state.velocity += partner->state.acceleration;
            angle = partner->state.angle;
            angle += partner->state.velocity;
            deltaX = partner->state.distance * sinTheta;
            deltaY = -partner->state.distance * cosTheta;
            partner->state.currentPos.x = partner->state.goalPos.x + deltaX;
            partner->state.currentPos.y = partner->state.goalPos.y + deltaY;
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
            distance = partner->state.distance;
            angle = partner->state.angle;
            angle += partner->state.velocity;
            deltaX = partner->state.distance * sinTheta;
            deltaY = -partner->state.distance * cosTheta;
            partner->state.currentPos.x = partner->state.goalPos.x + deltaX;
            partner->state.currentPos.y = partner->state.goalPos.y + deltaY;
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

    partner->currentPos.x = partnerState->currentPos.x;
    partner->currentPos.y = partnerState->currentPos.y;
    partner->currentPos.z = partnerState->currentPos.z;
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

    if (gBattleStatus.flags2 & BS_FLAGS2_2) {
        gBattleStatus.flags2 |= BS_FLAGS2_100;
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
                N(thunderboltRing)->flags |= EFFECT_INSTANCE_FLAG_10;
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
        targetActorBlueprintBaseStatusChance = lookup_status_chance(targetActor->statusTable, STATUS_PARALYZE);

        if (targetActor->transparentStatus == STATUS_TRANSPARENT) {
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

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL,      ANIM_BattleWatt_Walk,
    STATUS_STONE,       ANIM_BattleWatt_Still,
    STATUS_SLEEP,       ANIM_BattleWatt_Sleep,
    STATUS_POISON,      ANIM_BattleWatt_Still,
    STATUS_STOP,        ANIM_BattleWatt_Still,
    STATUS_DAZE,        ANIM_BattleWatt_Injured,
    STATUS_TURN_DONE,   ANIM_BattleWatt_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
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
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 10, 22 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_WATT,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
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
    .size = { 34, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_SET_PRIORITY(99)
    EVT_CALL(N(WattFXUpdate))
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(N(WattFXDisableBounce))
    EVT_CALL(N(WattFXEnable))
    EVT_CALL(N(WattFXSetEffect), 0)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_SET_CONST(LVar2,  ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(DoPartnerBlock)
            EVT_CALL(N(WattFXBounce))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_SET_CONST(LVar2, 12)
            EVT_EXEC_WAIT(DoPartnerSpikeContact)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_CALL(N(WattFXDisable))
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_BurnHurt)
            EVT_SET(LVar2, 12)
            EVT_SET_CONST(LVar3, ANIM_BattleWatt_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurnContact)
            EVT_CALL(N(WattFXEnable))
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleWatt_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurn)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_CALL(N(WattFXBounce))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Idle)
            EVT_SET_CONST(LVar2,  ANIM_BattleWatt_Run)
            EVT_SET(LVar3, 20)
            EVT_EXEC_WAIT(DoPartnerRecover)
            EVT_CALL(N(WattFXBounce))
        EVT_CASE_EQ(EVENT_62)
            EVT_CALL(N(WattFXRemove))
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Block)
            EVT_EXEC_WAIT(DoPartnerBlock)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_LIFE_SHROOM_PROC)
            EVT_CALL(N(WattFXDisable))
        EVT_CASE_EQ(EVENT_REVIVE)
            EVT_CALL(N(WattFXEnable))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
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
    EVT_CALL(N(WattFXEnable))
    EVT_CALL(N(WattFXSetEffect), 1)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BattleWatt_Celebrate)
    EVT_SET_CONST(LVar2,  ANIM_BattleWatt_Walk)
    EVT_SET_CONST(LVar3,  ANIM_BattleWatt_Idle)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_CALL(N(WattFXEnable))
    EVT_CALL(N(WattFXSetEffect), 1)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1,  ANIM_BattleWatt_Run)
    EVT_EXEC_WAIT(DoPartnerRunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(N(WattFXEnable))
    EVT_CALL(N(WattFXSetEffect), 1)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(N(WattFXSetEffect), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_ELECTRO_DASH1)
            EVT_EXEC_WAIT(N(electroDash))
        EVT_CASE_EQ(MOVE_ELECTRO_DASH2)
            EVT_EXEC_WAIT(N(electroDash))
        EVT_CASE_EQ(MOVE_ELECTRO_DASH3)
            EVT_EXEC_WAIT(N(electroDash))
        EVT_CASE_EQ(MOVE_POWER_SHOCK)
            EVT_EXEC_WAIT(N(powerShock))
        EVT_CASE_EQ(MOVE_TURBO_CHARGE)
            EVT_EXEC_WAIT(N(turboCharge))
        EVT_CASE_EQ(MOVE_MEGA_SHOCK)
            EVT_EXEC_WAIT(N(megaShock))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome2) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EVT_RETURN
    EVT_END
};

EffectInstance* N(radialShimmer) = NULL;

EvtScript N(dashToTarget) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_LINEAR)
    EVT_RETURN
    EVT_END
};

EvtScript N(charge) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
    EVT_CALL(N(WattFXDisable))
    EVT_CALL(PlayLoopingSoundAtActor, ACTOR_PARTNER, 0, SOUND_289)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 12)
    EVT_CALL(N(ElectroDashFX), LVar0, LVar1, LVar2)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_SET(LVar9, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBigger)
    EVT_LOOP(55)
        EVT_ADD(LVar9, 30)
        EVT_IF_GT(LVar9, 200)
            EVT_SET(LVar9, 200)
        EVT_END_IF
        EVT_CALL(N(SetBackgroundAlpha), LVar9)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 9)
    EVT_RETURN
    EVT_END
};

EvtScript N(electroDash_wait) = {
    EVT_LOOP(30)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(electroDash) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_BODY_SLAM)
    EVT_CALL(action_command_body_slam_init)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_48)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_LOOP(60)
        EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_SET(LocalFlag(2), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(MoveBattleCamOver, 75)
    EVT_IF_EQ(LocalFlag(2), 1)
        EVT_CALL(action_command_body_slam_start, 0, 102, 3, 1)
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(dashToTarget), LVarA)
        EVT_LOOP(20)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_10)
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(charge), LVarA)
        EVT_LOOP(55)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LocalFlag(0), 0)
            EVT_EXEC_GET_TID(N(electroDash_wait), LVarA)
            EVT_LOOP(30)
                EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_KILL_THREAD(LVarA)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(dashToTarget), LVarA)
        EVT_LOOP(20)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_EQ(LocalFlag(2), 0)
                    EVT_CALL(action_command_body_slam_start, 0, 92, 3, 1)
                    EVT_SET(LocalFlag(2), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(2), 1)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_10)
        EVT_SET(LocalFlag(0), 0)
        EVT_EXEC_GET_TID(N(charge), LVarA)
        EVT_LOOP(55)
            EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_IF_EQ(LocalFlag(2), 0)
                    EVT_CALL(action_command_body_slam_start, 0, 92, 3, 1)
                    EVT_SET(LocalFlag(2), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(2), 1)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LocalFlag(0), 1)
            EVT_KILL_THREAD(LVarA)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_EQ(LocalFlag(0), 0)
            EVT_EXEC_GET_TID(N(electroDash_wait), LVarA)
            EVT_LOOP(30)
                EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_KILL_THREAD(LVarA)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(10)
    EVT_WAIT(2)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(N(ElectroDashFXDisable))
    EVT_CALL(StopLoopingSoundAtActor, ACTOR_PARTNER, 0)
    EVT_CALL(func_80269EAC, 19)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 10)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -5, 0, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 5, 0, EASING_LINEAR)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(N(SetBackgroundAlpha), 0)
    EVT_END_THREAD
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        EVT_END_THREAD
        EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 10, 0)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, -20, EASING_QUADRATIC_OUT)
        EVT_WAIT(20)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(WattFXEnable))
    EVT_CALL(N(WattFXBounce))
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_ELECTRO_DASH1)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 3)
        EVT_CASE_EQ(MOVE_ELECTRO_DASH2)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 4)
        EVT_CASE_EQ(MOVE_ELECTRO_DASH3)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 5)
    EVT_END_SWITCH
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarE, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_CALL(PartnerYieldTurn)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(powerShock) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_POWER_SHOCK)
    EVT_CALL(action_command_power_shock_init)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_SET(LocalFlag(15), 0)
    EVT_CALL(GetOwnerTarget, LVarA, LVarB)
    EVT_CALL(GetActorFlags, LVarA, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_UPSIDE_DOWN)
        EVT_SET(LocalFlag(15), 1)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_47)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    EVT_CALL(N(WattFXSetEffect), 1)
    EVT_CALL(AddGoalPos, ACTOR_PARTNER, -15, -10, 0)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_10)
    EVT_CALL(AddBattleCamZoom, -100)
    EVT_CALL(MoveBattleCamOver, 80)
    EVT_CALL(N(WattFXDisable))
    EVT_CALL(N(TargetParalyzeChance))
    EVT_CALL(action_command_power_shock_start, 0, 75 * DT - 3, 3, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 75 * DT, 0)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_SET(LVar9, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBigger)
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 10)
    EVT_THREAD
        EVT_LOOP(75 * DT)
            EVT_ADD(LVar9, 3)
            EVT_CALL(N(SetBackgroundAlpha), LVar9)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(75 * DT)
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 9)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_28A)
    EVT_THREAD
        EVT_SETF(LVar0, EVT_FLOAT(1.0))
        EVT_LOOP(3)
            EVT_ADDF(LVar0, EVT_FLOAT(0.4))
            EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 8)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.8), 30, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_ADD(LVar2, 5)
    EVT_CALL(N(PowerShockFX), LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_47)
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_THREAD
        EVT_CALL(N(PowerShockDischargeFX), 20)
    EVT_END_THREAD
    EVT_LOOP(3)
        EVT_CALL(N(SetBackgroundAlpha), 0)
        EVT_WAIT(1)
        EVT_CALL(N(SetBackgroundAlpha), 200)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(SetBackgroundAlpha), 0)
    EVT_WAIT(10)
    EVT_CALL(N(WattFXEnable))
    EVT_CALL(N(WattFXSetEffect), 0)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 20, 0)
        EVT_SETF(LVar0, EVT_FLOAT(2.2))
        EVT_LOOP(12)
            EVT_SUBF(LVar0, EVT_FLOAT(0.1))
            EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EVT_END_THREAD
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_WAIT(15)
        EVT_EXEC_WAIT(N(returnHome))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActionResult, LVarF)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), 254, 0, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), 255, 0, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_CALL(PartnerYieldTurn)
    EVT_IF_NE(LocalFlag(15), 1)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -25, 10, 0)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, -10, EASING_COS_IN_OUT)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -25, -10, 0)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, -10, EASING_COS_IN_OUT)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8023AE8C) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    EVT_CALL(action_command_water_block_init, 1)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_20000000, TRUE)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    EVT_WAIT(5)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -125, 42, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 340)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 180)
    EVT_WAIT(10)
    EVT_CALL(action_command_water_block_start, 0, 100 * DT, 3)
    EVT_CALL(AddBattleCamZoom, -75)
    EVT_CALL(MoveBattleCamOver, 100 * DT)
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
        EVT_CALL(N(TurboChargeUnwindWatt), 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_CUBIC_OUT)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        EVT_WAIT(10)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 0)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_28B)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 42)
    EVT_CALL(N(TurboChargeFX), LVar0, LVar1, LVar2)
    EVT_WAIT(59)
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_160)
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 20, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208E)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_CALL(N(ApplyTurboCharge))
    EVT_SET(LVarE, LVarF)
    EVT_IF_GT(LVarA, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 35)
        EVT_ADD(LVarF, 0)
        EVT_PLAY_EFFECT(EFFECT_STAT_CHANGE, LVarF, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 60, 0)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
    EVT_ELSE
        EVT_CALL(ShowVariableMessageBox, BTL_MSG_2A, 60, LVarA)
    EVT_END_IF
    EVT_CALL(WaitForMessageBoxDone)
    EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_20000000, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023B450) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WATER_BLOCK)
    EVT_CALL(action_command_water_block_init, 1)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_WAIT(5)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -125, 42, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 340)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 180)
    EVT_WAIT(10)
    EVT_CALL(action_command_water_block_start, 0, 100 * DT, 3)
    EVT_CALL(AddBattleCamZoom, -100)
    EVT_CALL(MoveBattleCamOver, 100 * DT)
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
        EVT_CALL(N(TurboChargeUnwindWatt), 1)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, -10, EASING_CUBIC_OUT)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
        EVT_WAIT(10)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 0)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_28B)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 42)
    EVT_CALL(N(TurboChargeFX), LVar0, LVar1, LVar2)
    EVT_WAIT(59)
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208E)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_CALL(N(ApplyTurboCharge))
    EVT_SET(LVarE, LVarF)
    EVT_IF_GT(LVarA, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 15)
        EVT_ADD(LVar1, 35)
        EVT_ADD(LVarF, 0)
        EVT_PLAY_EFFECT(EFFECT_STAT_CHANGE, LVarF, LVar0, LVar1, LVar2, EVT_FLOAT(1.5), 60, 0)
        EVT_WAIT(4)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
    EVT_ELSE
        EVT_CALL(ShowVariableMessageBox, BTL_MSG_2A, 60, LVarA)
    EVT_END_IF
    EVT_CALL(WaitForMessageBoxDone)
    EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_20000000, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(turboCharge) = {
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_EXEC_WAIT(N(8023B450))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8023AE8C))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 D_8023B948_707438[] = { 3, 3, 4, 7, 10, 13, 16, 16, 16, 16, };

EvtScript N(megaShock) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_MEGA_SHOCK)
    EVT_CALL(action_command_mega_shock_init)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -54, 63, 10)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(SetBattleCamZoom, 314)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_ADD(LVar1, 30)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Run)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_SET(LVar9, 0)
    EVT_THREAD
        EVT_LOOP(75 * DT)
            EVT_ADD(LVar9, 3)
            EVT_CALL(N(SetBackgroundAlpha), LVar9)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(AverageTargetParalyzeChance))
    EVT_CALL(action_command_mega_shock_start, 0, 87 * DT, 3, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 90 * DT, 0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 12)
    EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, EVT_FLOAT(1.3), 90 * DT, 0)
    EVT_CALL(AddBattleCamZoom, -100)
    EVT_CALL(MoveBattleCamOver, 90 * DT)
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBigger)
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 10)
    EVT_CALL(N(WattFXDisable))
    EVT_CALL(GetActionResult, LVar1)
    EVT_WAIT(90 * DT)
    EVT_CALL(N(SetBackgroundAlpha), 0)
    EVT_THREAD
        EVT_SET(LVar9, 60)
        EVT_LOOP(20)
            EVT_SUB(LVar9, 3)
            EVT_CALL(N(SetBackgroundAlpha), LVar9)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 9)
    EVT_CALL(InitTargetIterator)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 12)
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_28C)
        EVT_PLAY_EFFECT(EFFECT_FLASHING_BOX_SHOCKWAVE, 2, LVar0, LVar1, LVar2, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_2024)
        EVT_PLAY_EFFECT(EFFECT_FLASHING_BOX_SHOCKWAVE, 2, LVar0, LVar1, LVar2, 0, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_StrainBiggest)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Strain)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleWatt_Idle)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetBattleCamZoom, 420)
        EVT_CALL(SetBattleCamTarget, 6, 63, 10)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(4)
        EVT_SET(LVar0, 6)
        EVT_LOOP(30)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleCamTarget, LVar0, 63, 10)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(PowerShockDischargeFX), 10)
    EVT_END_THREAD
    EVT_CALL(GetActionResult, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar1, LVar2, LVar3)
    EVT_ADD(LVar2, 12)
    EVT_CALL(N(MegaShockFX), LVar0, LVar1, LVar2, LVar3)
    EVT_LOOP(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActionCommandResult, LVarF)
        EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_IF_EQ(LVarF, 100)
            EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), 254, 0, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_ELSE
            EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_ALWAYS(STATUS_FLAG_PARALYZE, 3), LVarF, 0, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_40)
        EVT_END_IF
        EVT_LABEL(11)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_EQ(LVar0, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_CALL(N(WattFXEnable))
    EVT_CALL(PartnerYieldTurn)
    EVT_WAIT(30)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(returnHome))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
