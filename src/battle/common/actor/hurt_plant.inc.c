#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/HurtPlant.h"

#define NAMESPACE A(hurt_plant)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_BITE        = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HurtPlant_Anim02,
    STATUS_KEY_STONE,     ANIM_HurtPlant_Anim00,
    STATUS_KEY_SLEEP,     ANIM_HurtPlant_Anim0C,
    STATUS_KEY_POISON,    ANIM_HurtPlant_Anim02,
    STATUS_KEY_STOP,      ANIM_HurtPlant_Anim00,
    STATUS_KEY_STATIC,    ANIM_HurtPlant_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_HurtPlant_Anim00,
    STATUS_KEY_DIZZY,     ANIM_HurtPlant_Anim09,
    STATUS_KEY_FEAR,      ANIM_HurtPlant_Anim09,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,     0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              95,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
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
        .targetOffset = { -10, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -8, -5 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HURT_PLANT,
    .level = ACTOR_LEVEL_HURT_PLANT,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 70,
    .airLiftChance = 20,
    .hurricaneChance = 20,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 40, 35 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -18, 23 },
    .statusTextOffset = { 1, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    Label(0)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseFlag(STATUS_FLAG_SLEEP)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -6, 14)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -2, -5)
            Call(N(SetAbsoluteStatusOffsets), -20, 8, 0, 14)
        CaseDefault
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -10, 24)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -8, -5)
            Call(N(SetAbsoluteStatusOffsets), -18, 23, 1, 20)
    EndSwitch
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim04)
    Wait(10)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim03)
    Wait(10)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim0D)
            Wait(3)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0A)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0A)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0A)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim0D)
            Wait(3)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim0D)
            Wait(3)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim0D)
            Wait(3)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_ShockHit)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim0D)
            Wait(3)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim02)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim0D)
            Wait(3)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim02)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim0D)
            Wait(3)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim0E)
            ExecWait(EVS_Enemy_Hit)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim04)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
            Wait(20)
            Call(HideHealthBar, ACTOR_SELF)
            Call(UseIdleAnimation, ACTOR_SELF, FALSE)
            Call(RemoveActor, ACTOR_SELF)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim02)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_HurtPlant_Anim02)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim04)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        Call(MoveBattleCamOver, 1)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 27)
        Set(LVar1, 0)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Wait(15)
        Goto(123)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim04)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    Wait(8)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 27)
    Set(LVar1, 0)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamZoom, 350)
    Call(SetBattleCamOffsetZ, 45)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(MoveBattleCamOver, 20)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 27)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    Label(123)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim03)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim05)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HURT_PLANT_BITE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim06)
    Wait(6)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim07)
            Wait(5)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(2)
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAG_POISON)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_BITE, BS_FLAGS1_TRIGGER_EVENTS)
    Else
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), DMG_BITE, BS_FLAGS1_TRIGGER_EVENTS)
    EndIf
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HurtPlant_Anim07)
            Wait(5)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
