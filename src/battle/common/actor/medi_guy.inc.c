#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/MediGuy.h"

#define NAMESPACE A(medi_guy)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_SWOOP       = 1,
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"
#include "common/MediGuySpriteRotationFunc.inc.c"

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MediGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_MediGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_MediGuy_Anim04,
    STATUS_KEY_POISON,    ANIM_MediGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_MediGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_MediGuy_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_MediGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_MediGuy_Anim0A,
    STATUS_KEY_FEAR,      ANIM_MediGuy_Anim0A,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
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
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 38 },
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
    .type = ACTOR_TYPE_MEDI_GUY,
    .level = ACTOR_LEVEL_MEDI_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 90,
    .hurricaneChance = 95,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 24, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 12, 31 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 5)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfFlag(LVar0, STATUS_FLAG_SLEEP)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -2, 24)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -5)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -2, 38)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -5)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 12, 31)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim03)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim01)
    Call(SetActorYaw, ACTOR_SELF, 0)
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
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim08)
            SetConst(LVar2, ANIM_MediGuy_Anim09)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim08)
            SetConst(LVar2, ANIM_MediGuy_Anim09)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim09)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_ShockHit)
            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim03)
            SetConst(LVar2, ANIM_MediGuy_Anim0B)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MediGuy_Anim06)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Swoop) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Thread
        SetF(LVar0, Float(0.0))
        Loop(15)
            AddF(LVar0, Float(2.0))
            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim03)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_COS_IN)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(10)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GATHER_SMALL)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim05)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TOSS)
            Thread
                Wait(5)
                Set(LVar0, 0)
                Loop(60)
                    Call(N(MediGuySpriteRotationFunc), LVar0, LVar1, 15, 60, Float(30.0))
                    Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar1)
                    Add(LVar0, 1)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Add(LVar2, 1)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim05)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GATHER_SMALL)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim05)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TOSS)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, 1)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim05)
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SWOOP, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpWithBounce, ACTOR_SELF, 10, Float(2.0))
            Wait(20)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_HealOne) = {
    Set(LVarA, LVar0)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(GetOwnerID, LVar0)
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GATHER_SMALL)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_NONE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim05)
    Add(LVar2, 50)
    PlayEffect(EFFECT_SPARKLES, 1, LVar1, LVar2, LVar3, 10, 0)
    PlayEffect(EFFECT_RECOVER, 2, LVar1, LVar2, LVar3, 0, 0)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MediGuy_Anim01)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, LVarA)
    Call(GetEnemyMaxHP, LVarA, LVar4)
    Mul(LVar4, 60)
    Div(LVar4, 100)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, LVarA, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, LVarA, SOUND_HEART_BOUNCE)
        Wait(30)
        Call(PlaySoundAtActor, LVarA, SOUND_STAR_BOUNCE_A)
    EndThread
    Thread
        Call(FreezeBattleState, TRUE)
        Call(HealActor, LVarA, LVar4, FALSE)
        Call(FreezeBattleState, FALSE)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_FindInjuredActor) = {
    Call(CreateHomeTargetList, TARGET_FLAG_2)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorHP, LVar0, LVar2)
        Call(GetEnemyMaxHP, LVar0, LVar3)
        IfNe(LVar2, LVar3)
            Call(GetOwnerTarget, LVar0, LVar1)
            Return
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    ExecWait(N(EVS_FindInjuredActor))
    IfEq(LVar0, -1)
        ExecWait(N(EVS_Attack_Swoop))
    Else
        Call(RandInt, 1000, LVarA)
        IfLt(LVarA, 600)
            ExecWait(N(EVS_Move_HealOne))
        Else
            ExecWait(N(EVS_Attack_Swoop))
        EndIf
    EndIf
    Return
    End
};
