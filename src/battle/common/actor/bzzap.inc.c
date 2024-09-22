#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Bzzap.h"

#define NAMESPACE A(bzzap)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_SWARM_1     = 2,
    PRT_SWARM_2     = 3,
    PRT_SWARM_3     = 4,
    PRT_SWARM_4     = 5,
    PRT_SWARM_5     = 6,
};

enum N(ActorParams) {
    DMG_STING       = 6,
    DMG_SWARM       = 1,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bzzap_Anim01,
    STATUS_KEY_STONE,     ANIM_Bzzap_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Bzzap_Anim09,
    STATUS_KEY_POISON,    ANIM_Bzzap_Anim01,
    STATUS_KEY_STOP,      ANIM_Bzzap_Anim00,
    STATUS_KEY_STATIC,    ANIM_Bzzap_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Bzzap_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Bzzap_Anim0A,
    STATUS_KEY_FEAR,      ANIM_Bzzap_Anim0A,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
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
        .targetOffset = { -7, 33 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BZZAP,
    .level = ACTOR_LEVEL_BZZAP,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 95,
    .hurricaneChance = 95,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 38, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

API_CALLABLE(N(AddVecXZ)) {
    Bytecode* args = script->ptrReadPos;
    s32 prevX = evt_get_variable(script, *args++);
    s32 prevZ = evt_get_variable(script, *args++);
    s32 length = evt_get_variable(script, *args++);
    s32 yaw = evt_get_variable(script, *args++);

    f32 outX = prevX + (length * cos_deg(yaw));
    f32 outZ = prevZ - (length * sin_deg(yaw));

    evt_set_float_variable(script, *args++, outX);
    evt_set_float_variable(script, *args++, outZ);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetPartScale, ACTOR_SELF, PRT_SWARM_1, Float(0.4), Float(0.4), Float(0.4))
    Call(SetPartScale, ACTOR_SELF, PRT_SWARM_2, Float(0.4), Float(0.4), Float(0.4))
    Call(SetPartScale, ACTOR_SELF, PRT_SWARM_3, Float(0.4), Float(0.4), Float(0.4))
    Call(SetPartScale, ACTOR_SELF, PRT_SWARM_4, Float(0.4), Float(0.4), Float(0.4))
    Call(SetPartScale, ACTOR_SELF, PRT_SWARM_5, Float(0.4), Float(0.4), Float(0.4))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -7, 19)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 2, -6)
            Call(N(SetAbsoluteStatusOffsets), -20, 20, 10, 27)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -7, 33)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 2, -10)
            Call(N(SetAbsoluteStatusOffsets), -16, 22, 4, 22)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim03)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim07)
            SetConst(LVar2, ANIM_Bzzap_Anim08)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim07)
            SetConst(LVar2, ANIM_Bzzap_Anim08)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim03)
            SetConst(LVar2, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim01)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                Else
                    Call(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bzzap_Anim06)
            ExecWait(EVS_Enemy_BlowAway)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Sting) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim03)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 52, 10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_COS_IN)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Wait(10)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 20)
            Add(LVar2, 1)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            Wait(5)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BZZAP_STING)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim04)
            Wait(10)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Wait(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Add(LVar2, 1)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
    Wait(5)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BZZAP_STING)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim04)
    Wait(6)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 40), DMG_STING, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(20)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_SummonSwarmPart) = {
    Set(LVar9, LVar0)
    Call(SetPartYaw, ACTOR_SELF, LVar9, 0)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Add(LVarA, 200)
    Add(LVarB, 100)
    Call(SetPartPos, ACTOR_SELF, LVar9, LVarA, LVarB, LVarC)
    Call(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetAnimation, ACTOR_SELF, LVar9, ANIM_Bzzap_Anim03)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Add(LVarB, 50)
    Sub(LVarC, 30)
    Call(SetPartMoveSpeed, ACTOR_SELF, LVar9, Float(6.0))
    Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(1.0))
    Call(FlyPartTo, ACTOR_SELF, LVar9, LVarA, LVarB, LVarC, 0, -10, EASING_LINEAR)
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(GetPartOffset, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
    Call(MakeLerp, 90, 450, 50, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(N(AddVecXZ), LVar3, LVar5, 30, LVar0, LVar6, LVar8)
        Call(SetPartPos, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
        IfGt(LVar3, LVar6)
            Call(SetPartYaw, ACTOR_SELF, LVar9, 180)
        Else
            Call(SetPartYaw, ACTOR_SELF, LVar9, 0)
        EndIf
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(SetPartYaw, ACTOR_SELF, LVar9, 0)
    IfEq(LVar9, 2)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
        Call(SetBattleCamDist, 400)
        Call(SetBattleCamOffsetY, 30)
        Call(BattleCamTargetActor, ACTOR_PLAYER)
        Call(MoveBattleCamOver, 60)
    EndIf
    Call(SetAnimation, ACTOR_SELF, LVar9, ANIM_Bzzap_Anim03)
    Call(GetActorPos, ACTOR_PLAYER, LVarA, LVarB, LVarC)
    Add(LVarB, 30)
    Add(LVarC, 30)
    Call(SetPartMoveSpeed, ACTOR_SELF, LVar9, Float(6.0))
    Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(1.0))
    Call(FlyPartTo, ACTOR_SELF, LVar9, LVarA, LVarB, LVarC, 0, -10, EASING_LINEAR)
    Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(GetPartOffset, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
    Call(MakeLerp, -90, -720, 100, EASING_LINEAR)
    Label(1)
        Call(UpdateLerp)
        Call(N(AddVecXZ), LVar3, LVar5, 30, LVar0, LVar6, LVar8)
        Call(SetPartPos, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
        IfGt(LVar3, LVar6)
            Call(SetPartYaw, ACTOR_SELF, LVar9, 180)
        Else
            Call(SetPartYaw, ACTOR_SELF, LVar9, 0)
        EndIf
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Return
    End
};

EvtScript N(EVS_Attack_CallSwarm) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetPartSounds, ACTOR_SELF, PRT_SWARM_1, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_SWARM_2, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_SWARM_3, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_SWARM_4, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_SWARM_5, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BZZAP_CALL_SWARM)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim05)
    Wait(40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim01)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(PlaySound, SOUND_MINI_BZZAP_BUZZ)
    Set(LVar0, PRT_SWARM_1)
    ExecGetTID(N(EVS_SummonSwarmPart), LVarA)
    Wait(11)
    Set(LVar0, PRT_SWARM_2)
    Exec(N(EVS_SummonSwarmPart))
    Wait(11)
    Set(LVar0, PRT_SWARM_3)
    Exec(N(EVS_SummonSwarmPart))
    Wait(11)
    Set(LVar0, PRT_SWARM_4)
    Exec(N(EVS_SummonSwarmPart))
    Wait(11)
    Set(LVar0, PRT_SWARM_5)
    Exec(N(EVS_SummonSwarmPart))
    Label(0)
        IsThreadRunning(LVarA, LVar0)
        Wait(1)
        IfEq(LVar0, 1)
            Goto(0)
        EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_1, SOUND_MINI_BZZAP_STING)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim04)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_1, Float(3.0))
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim03)
                Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_1, 180)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 100)
                Add(LVar2, 100)
                Call(AddActorDecoration, ACTOR_SELF, PRT_SWARM_1, 0, ACTOR_DECORATION_SWEAT)
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_1, 0)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            Wait(11)
            Thread
                Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_2, SOUND_MINI_BZZAP_STING)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim04)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_2, Float(3.0))
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim03)
                Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_2, 180)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 100)
                Add(LVar2, 100)
                Call(AddActorDecoration, ACTOR_SELF, PRT_SWARM_2, 0, ACTOR_DECORATION_SWEAT)
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_2, 0)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            Wait(11)
            Thread
                Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_3, SOUND_MINI_BZZAP_STING)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim04)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_3, Float(3.0))
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim03)
                Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_3, 180)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 100)
                Add(LVar2, 100)
                Call(AddActorDecoration, ACTOR_SELF, PRT_SWARM_3, 0, ACTOR_DECORATION_SWEAT)
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_3, 0)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            Wait(11)
            Thread
                Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_4, SOUND_MINI_BZZAP_STING)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim04)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_4, Float(3.0))
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim03)
                Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_4, 180)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 100)
                Add(LVar2, 100)
                Call(AddActorDecoration, ACTOR_SELF, PRT_SWARM_4, 0, ACTOR_DECORATION_SWEAT)
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_4, 0)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            Wait(11)
            Thread
                Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_5, SOUND_MINI_BZZAP_STING)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim04)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_5, Float(3.0))
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                Call(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim03)
                Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_5, 180)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 100)
                Add(LVar2, 100)
                Call(AddActorDecoration, ACTOR_SELF, PRT_SWARM_5, 0, ACTOR_DECORATION_SWEAT)
                Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_5, 0)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            Wait(11)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(30)
            Call(StopSound, SOUND_MINI_BZZAP_BUZZ)
            Call(YieldTurn)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_1, SOUND_MINI_BZZAP_STING)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim04)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_1, Float(3.0))
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        Wait(2)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_INCLUDE_POWER_UPS)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim03)
        Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_1, 180)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 100)
        Add(LVar2, 100)
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndThread
    Wait(11)
    Thread
        Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_2, SOUND_MINI_BZZAP_STING)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim04)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_2, Float(3.0))
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        Wait(2)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_NICE_HIT)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim03)
        Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_2, 180)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 100)
        Add(LVar2, 100)
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndThread
    Wait(11)
    Thread
        Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_3, SOUND_MINI_BZZAP_STING)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim04)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_3, Float(3.0))
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        Wait(2)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_NICE_HIT)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim03)
        Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_3, 180)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 100)
        Add(LVar2, 100)
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndThread
    Wait(11)
    Thread
        Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_4, SOUND_MINI_BZZAP_STING)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim04)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_4, Float(3.0))
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        Wait(2)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_NICE_HIT)
        Call(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim03)
        Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_4, 180)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 100)
        Add(LVar2, 100)
        Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndThread
    Wait(11)
    Wait(1)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_5, SOUND_MINI_BZZAP_STING)
    Call(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim04)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, -10, -10, 1)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_5, Float(3.0))
    Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim03)
            Call(SetPartYaw, ACTOR_SELF, PRT_SWARM_5, 180)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 100)
            Add(LVar2, 100)
            Call(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(StopSound, SOUND_MINI_BZZAP_BUZZ)
            Call(YieldTurn)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        ExecWait(N(EVS_Attack_Sting))
        Return
    EndIf
    Call(RandInt, 1000, LVar0)
    IfLt(LVar0, 500)
        ExecWait(N(EVS_Attack_Sting))
    Else
        ExecWait(N(EVS_Attack_CallSwarm))
    EndIf
    Return
    End
};
