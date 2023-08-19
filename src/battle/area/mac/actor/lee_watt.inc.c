s32 N(IdleAnimations_80225974)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleWatt_Idle,
    STATUS_KEY_STONE,     ANIM_BattleWatt_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleWatt_Still,
    STATUS_KEY_POISON,    ANIM_BattleWatt_Idle,
    STATUS_KEY_STOP,      ANIM_BattleWatt_Still,
    STATUS_KEY_STATIC,    ANIM_BattleWatt_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleWatt_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleWatt_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleWatt_Injured,
    STATUS_END,
};

s32 N(DefenseTable_802259C0)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,   99,
    ELEMENT_END,
};

s32 N(StatusTable_802259D4)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(WattParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -1, 20 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80225974),
        .defenseTable = N(DefenseTable_802259C0),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -1, -30 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_802259C0),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

extern EvtScript N(init_Watt);

ActorBlueprint N(watt) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_WATT,
    .level = ACTOR_LEVEL_LEE_WATT,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(WattParts)),
    .partsData = N(WattParts),
    .initScript = &N(init_Watt),
    .statusTable = N(StatusTable_802259D4),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 34, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80226004);
extern EvtScript N(idle_80225B68);
extern EvtScript N(handleEvent_80225B90);
extern EvtScript N(nextTurn_80226880);

EvtScript N(init_Watt) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80226004)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80225B68)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80225B90)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(nextTurn_80226880)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FormDuration, 1)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(func_80219188_465618) {
    WattEffectData* wattEffectData;
    f32 x, y, z;
    Actor* actor = get_actor(script->owner1.enemyID);
    ActorState* state = &actor->state;

    if (isInitialCall) {
        wattEffectData = heap_malloc(sizeof(*wattEffectData));
        actor->state.varTablePtr[3] = wattEffectData;
        wattEffectData->unk_04 = TRUE;
        wattEffectData->angle = 0;
        wattEffectData->unk_0C = TRUE;
        wattEffectData->unk_10 = 0;
        wattEffectData->effect1 = fx_static_status(0, actor->curPos.x, actor->curPos.y, actor->curPos.z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);
        wattEffectData->effect2 = fx_static_status(1, actor->curPos.x, NPC_DISPOSE_POS_Y, actor->curPos.z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);
        wattEffectData->flags = TRUE;
        wattEffectData->debuff = actor->debuff;
    }

    wattEffectData = state->varTablePtr[3];
    if (wattEffectData->flags) {
        if (wattEffectData->unk_04 && actor->debuff != STATUS_KEY_STOP) {
            wattEffectData->angle += 15;
            wattEffectData->angle = clamp_angle(wattEffectData->angle);
        }
        actor->verticalRenderOffset = sin_rad(DEG_TO_RAD(wattEffectData->angle)) * 3.0f;

        x = actor->curPos.x + actor->headOffset.x;
        y = actor->curPos.y + actor->headOffset.y + actor->verticalRenderOffset + (actor->debuff != STATUS_KEY_SHRINK ? 12.0 : 4.800000000000001); // 4.8 doesn't match
        z = actor->curPos.z + actor->headOffset.z;
        if (wattEffectData->unk_0C) {
            switch (wattEffectData->unk_10) {
                case 0:
                    if (wattEffectData->effect1 == NULL) {
                        wattEffectData->effect1 = fx_static_status(0, x, y, z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);
                    }

                    if (wattEffectData->effect2 != NULL) {
                        wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
                        wattEffectData->effect2 = NULL;
                    }
                    wattEffectData->effect1->data.staticStatus->pos.x = x;
                    wattEffectData->effect1->data.staticStatus->pos.y = y;
                    wattEffectData->effect1->data.staticStatus->pos.z = z;
                    break;
                case 1:
                    if (wattEffectData->effect1 != NULL) {
                        wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
                        wattEffectData->effect1 = NULL;
                    }
                    if (wattEffectData->effect2 == NULL) {
                        wattEffectData->effect2 = fx_static_status(1, x, y, z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);

                    }
                    wattEffectData->effect2->data.staticStatus->pos.x = x;
                    wattEffectData->effect2->data.staticStatus->pos.y = y;
                    wattEffectData->effect2->data.staticStatus->pos.z = z;
                    break;
            }
        } else {
            if (wattEffectData->effect1 != NULL) {
                wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect1 = NULL;
            }
            if (wattEffectData->effect2 != NULL) {
                wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect2 = NULL;
            }
        }
        if (wattEffectData->debuff != actor->debuff && wattEffectData->unk_0C) {
            if (wattEffectData->effect1 != NULL) {
                wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect1 = NULL;
            }
            if (wattEffectData->effect2 != NULL) {
                wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect2 = NULL;
            }
        }
        wattEffectData->debuff = actor->debuff;
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80219604_465A94) {
    WattEffectData* wattEffectData = (WattEffectData*)get_actor(script->owner1.actorID)->state.varTable[3];

    wattEffectData->flags = 0;

    if (wattEffectData->effect1 != NULL) {
        wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
    }

    if (wattEffectData->effect2 != NULL) {
        wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
    }

    return ApiStatus_DONE2;
}

EvtScript N(idle_80225B68) = {
    EVT_SET_PRIORITY(99)
    EVT_CALL(func_80219188_465618)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(func_80219658_465AE8) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffects = (WattEffectData*)get_actor(script->owner1.enemyID)->state.varTable[3];

    wattEffects->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802196A4_465B34) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffects = (WattEffectData*)get_actor(script->owner1.enemyID)->state.varTable[3];

    wattEffects->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802196F0_465B80) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffects = (WattEffectData*)get_actor(script->owner1.enemyID)->state.varTable[3];

    wattEffects->unk_10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(handleEvent_80225B90) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_80219658_465AE8, 0)
    EVT_CALL(func_802196A4_465B34, 1)
    EVT_CALL(func_802196F0_465B80, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleWatt_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleWatt_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(EVS_RemoveParentActor))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(EVS_RemoveParentActor))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(EVS_RemoveParentActor))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Run)
            EVT_SET_CONST(LVar2, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Run)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(func_80219658_465AE8, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

EvtScript N(takeTurn_80226004) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(MoveBattleCamOver, 80)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Run)
    EVT_CALL(func_802196F0_465B80, 1)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 15, -10, 5)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
    EVT_CALL(func_802196F0_465B80, 0)
    EVT_WAIT(5)
    EVT_CALL(func_80219658_465AE8, 0)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 25, 20, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -20, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Strain)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, EASING_COS_IN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 10, -20, EASING_QUADRATIC_OUT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(func_802196A4_465B34, 1)
            EVT_CALL(func_80219658_465AE8, 1)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_802196A4_465B34, 0)
    EVT_SET(LVarA, 40)
    EVT_CALL(AddBattleCamZoom, -75)
    EVT_CALL(MoveBattleCamOver, LVarA)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_0289)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 4)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, EVT_FLOAT(0.52), LVarA, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 12)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, EVT_FLOAT(1.3), LVarA, 0)
    EVT_END_IF
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_SET(LVar9, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_StrainBigger)
    EVT_LOOP(LVarA)
        EVT_ADD(LVar9, 3)
        EVT_IF_GT(LVar9, 200)
            EVT_SET(LVar9, 200)
        EVT_END_IF
        EVT_CALL(N(SetBackgroundAlpha), LVar9)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
    EVT_CALL(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, PAL_ADJUST_WATT_IDLE)
    EVT_CALL(AddBattleCamZoom, 75)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(N(SetBackgroundAlpha), 0)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE), SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE), SUPPRESS_EVENT_ALL, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE), SUPPRESS_EVENT_ALL, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(func_802196A4_465B34, 1)
            EVT_CALL(func_80219658_465AE8, 1)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 25, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -10, EASING_COS_IN_OUT)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80226880) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FormDuration, LVar0)
            EVT_IF_GT(LVar0, 0)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FormDuration, LVar0)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleWatt_Hurt)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(EVS_LoseDisguise))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_watt) = {
    ACTOR_BY_POS(N(watt), N(SummonPos), 0)
};
