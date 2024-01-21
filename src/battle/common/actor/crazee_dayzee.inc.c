#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Dayzee.h"

#define NAMESPACE A(crazee_dayzee)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_SING        = 4,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              95,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             30,
    STATUS_KEY_STOP,               30,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
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
        .targetOffset = { -2, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CRAZEE_DAYZEE,
    .level = ACTOR_LEVEL_CRAZEE_DAYZEE,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 32, 34 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -14, 17 },
    .statusTextOffset = { 9, 25 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Dayzee_Anim01,
    STATUS_KEY_STONE,     ANIM_Dayzee_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Dayzee_Anim0C,
    STATUS_KEY_POISON,    ANIM_Dayzee_Anim01,
    STATUS_KEY_STOP,      ANIM_Dayzee_Anim00,
    STATUS_KEY_STATIC,    ANIM_Dayzee_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Dayzee_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Dayzee_Anim0B,
    STATUS_KEY_FEAR,      ANIM_Dayzee_Anim0B,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Dayzee_Anim03)
    ExecWait(EVS_Enemy_ReturnHome)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim09)
            SetConst(LVar2, ANIM_Dayzee_Anim0A)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim09)
            SetConst(LVar2, ANIM_Dayzee_Anim0A)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim0A)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim04)
            SetConst(LVar2, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim04)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                Else
                    Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Dayzee_Anim08)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Sing) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorPos, ACTOR_SELF, -20, LVar1, LVar2)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        Call(MoveBattleCamOver, 70)
        Set(LFlag0, FALSE)
        Label(0)
        IfEq(LFlag0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim0E)
            Set(LFlag0, TRUE)
        Else
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim0F)
            Set(LFlag0, FALSE)
        EndIf
        Wait(1)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 20)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        IfGt(LVar0, 0)
            Goto(0)
        EndIf
        IfEq(LFlag0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim0E)
            Set(LFlag0, TRUE)
        Else
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim0F)
            Set(LFlag0, FALSE)
        EndIf
        Wait(1)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
        Call(SetGoalPos, ACTOR_SELF, -35, 0, 10)
        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim01)
    Wait(10)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim06)
        Wait(40)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim07)
    EndThread
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DAYZEE_SONG)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Add(LVar2, 2)
    Loop(13)
        Call(RandInt, 30, LVar3)
        Sub(LVar3, 15)
        Add(LVar3, LVar0)
        PlayEffect(EFFECT_MUSIC_NOTE, 1, LVar3, LVar1, LVar2, 0)
        Wait(10)
    EndLoop
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim01)
    Wait(10)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(15)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_KEY(STATUS_FLAG_SLEEP, 3, 20), DMG_SING, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 10)
            Wait(20)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_Flee) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamZoom, 300)
    Call(SetBattleCamOffsetZ, 30)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 20)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(MoveBattleCamOver, 30)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim03)
    Wait(10)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(1.0))
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Dayzee_Anim04)
    Call(SetActorSpeed, ACTOR_SELF, Float(12.0))
    Add(LVar0, 200)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    Call(SetBattleFlagBits, BS_FLAGS1_BATTLE_FLED, TRUE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        ExecWait(N(EVS_Attack_Sing))
        Return
    EndIf
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(RandInt, 100, LVar1)
    Switch(LVar0)
        CaseEq(1)
            IfLt(LVar1, 80)
                ExecWait(N(EVS_Move_Flee))
                Return
            EndIf
        CaseEq(2)
            IfLt(LVar1, 40)
                ExecWait(N(EVS_Move_Flee))
                Return
            EndIf
        CaseEq(3)
            IfLt(LVar1, 20)
                ExecWait(N(EVS_Move_Flee))
                Return
            EndIf
        CaseEq(4)
            IfLt(LVar1, 10)
                ExecWait(N(EVS_Move_Flee))
                Return
            EndIf
    EndSwitch
    ExecWait(N(EVS_Attack_Sing))
    Return
    End
};
