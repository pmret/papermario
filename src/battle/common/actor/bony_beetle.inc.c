#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BonyBeetle.h"
#include "effects.h"

#define NAMESPACE A(bony_beetle)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandleEvent_SmoothUpright);
extern EvtScript N(EVS_HandleEvent_SpikyUpright);
extern EvtScript N(EVS_HandleEvent_SmoothToppled);
extern EvtScript N(EVS_HandleEvent_SpikyToppled);
extern EvtScript N(EVS_TrySwitchingSpikyState);
extern EvtScript N(EVS_TryGettingUp_Smooth);
extern EvtScript N(EVS_TryGettingUp_Spiky);
extern EvtScript N(EVS_Attack_ShellToss);
extern EvtScript N(EVS_Attack_SpikeBounce);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_IN_OnCeiling           = 0,
    AVAR_ShouldTrySwitching     = 1,
    AVAR_State                  = 8,
    AVAL_State_SmoothUpright    = 0,
    AVAL_State_SpikyUpright     = 1,
    AVAL_State_SmoothToppled    = 2,
    AVAL_State_SpikyToppled     = 3,
    AVAR_ToppleTurns            = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS      = 3,
    DMG_SPIKE_BOUNCE    = 5,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim04,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2A,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim04,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim00,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim04,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim26,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim26,
    STATUS_END,
};

s32 N(SpikyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim05,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim01,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2B,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim05,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim01,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim05,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim01,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim27,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim27,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim06,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim02,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2C,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim06,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim02,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim02,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim28,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim28,
    STATUS_END,
};

s32 N(ToppledSpikyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim07,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim03,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2D,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim07,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim03,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim03,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim29,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim29,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   4,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 21 },
        .opacity = 255,
        .idleAnimations = N(SpikyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BONY_BEETLE,
    .level = ACTOR_LEVEL_BONY_BEETLE,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 70,
    .hurricaneChance = 60,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 27, 27 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_IN_OnCeiling, LVar0)
    Call(GetInstigatorValue, ACTOR_SELF, LVar1)
    IfEq(LVar0, 1)
        IfEq(LVar1, 1)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SpikyAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim05)
        Else
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
        EndIf
    Else
        Call(RandInt, 1000, LVar0)
        IfLt(LVar0, 500)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
        Else
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SpikyAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim05)
        EndIf
    EndIf
EndIf
Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
Call(HPBarToHome, ACTOR_SELF)
Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, FALSE)
Return
End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_SmoothUpright)
            ExecWait(N(EVS_HandleEvent_SmoothUpright))
        CaseEq(AVAL_State_SpikyUpright)
            ExecWait(N(EVS_HandleEvent_SpikyUpright))
        CaseEq(AVAL_State_SmoothToppled)
            ExecWait(N(EVS_HandleEvent_SmoothToppled))
        CaseEq(AVAL_State_SpikyToppled)
            ExecWait(N(EVS_HandleEvent_SpikyToppled))
    EndSwitch
    Call(ActorExists, ACTOR_SELF, LVar0)
    IfEq(LVar0, 1)
        Call(GetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, LVar0)
        IfEq(LVar0, TRUE)
            ExecWait(N(EVS_TrySwitchingSpikyState))
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, FALSE)
        EndIf
    EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TrySwitchingSpikyState) = {
    Call(GetLastDamage, ACTOR_SELF, LVar0)
    IfLe(LVar0, 0)
        Return
    EndIf
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Return
    EndIf
    Label(0)
    Call(GetBattleFlags, LVarA)
    IfFlag(LVarA, BS_FLAGS1_EXECUTING_MOVE)
        Wait(1)
        Goto(0)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_SmoothUpright)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BONY_BEETLE_EXTEND_SPIKES)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim2E)
            Wait(25)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SpikyAnims)))
        CaseEq(AVAL_State_SpikyUpright)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BONY_BEETLE_RETRACT_SPIKES)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim2F)
            Wait(25)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        CaseEq(AVAL_State_SmoothToppled)
        CaseEq(AVAL_State_SpikyToppled)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_SmoothUpright)
            ExecWait(N(EVS_Attack_ShellToss))
        CaseEq(AVAL_State_SpikyUpright)
            ExecWait(N(EVS_Attack_SpikeBounce))
        CaseEq(AVAL_State_SmoothToppled)
            ExecWait(N(EVS_TryGettingUp_Smooth))
        CaseEq(AVAL_State_SpikyToppled)
            ExecWait(N(EVS_TryGettingUp_Spiky))
    EndSwitch
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 7, 13, 17, 21, 23, 24, 23, 21, 17, 13, 7, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent_SmoothUpright) = {
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_Hit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1E)
            SetConst(LVar2, ANIM_BonyBeetle_Anim1F)
            ExecWait(EVS_Enemy_BurnHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1E)
            SetConst(LVar2, ANIM_BonyBeetle_Anim1F)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1F)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_SpinSmashHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothToppled)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim08)
            UseBuf(N(FlipPosOffsets))
            Loop(20)
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Wait(20)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0E)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim10)
            ExecWait(EVS_Enemy_NoDamageHit)
            Wait(20)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim12)
                Wait(10)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim04)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0E)
            SetConst(LVar2, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0E)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim18)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_ShellToss) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim16)
        Goto(100)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim10)
    Wait(10)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim16)
    Wait(15)
    Label(100)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim12)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim0E)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim12)
            Wait(5)
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0E)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandleEvent_SpikyUpright) = {
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_Hit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim20)
            SetConst(LVar2, ANIM_BonyBeetle_Anim21)
            ExecWait(EVS_Enemy_BurnHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim20)
            SetConst(LVar2, ANIM_BonyBeetle_Anim21)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim21)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_SpinSmashHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyToppled)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledSpikyAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim09)
            UseBuf(N(FlipPosOffsets))
            Loop(20)
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Wait(20)
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0F)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim11)
            ExecWait(EVS_Enemy_NoDamageHit)
            Wait(20)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim13)
            EndIf
            Wait(10)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
            Wait(10)
            Set(LFlag0, FALSE)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                Add(LVar0, -3)
                Add(LVar1, 10)
                Set(LFlag0, TRUE)
            EndIf
            IfFlag(LVar3, STATUS_FLAG_DIZZY)
                Add(LVar0, 0)
                Add(LVar1, 26)
                Set(LFlag0, TRUE)
            EndIf
            IfEq(LFlag0, FALSE)
                Add(LVar0, -8)
                Add(LVar1, 26)
            EndIf
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            Wait(20)
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim05)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0F)
            SetConst(LVar2, ANIM_BonyBeetle_Anim19)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_SpikeBounce) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim17)
        Wait(10)
        Goto(100)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim11)
    Wait(10)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 6, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 8, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 10, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 12, 0, 10, 0)
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim17)
    Wait(15)
    Label(100)
    Thread
        Loop(20)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 0, 0, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_SPIKE_BOUNCE, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(24.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 180)
                Loop(15)
                    Add(LVar0, 12)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Sub(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 180)
                Loop(5)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Wait(5)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0F)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(24.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Thread
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 18)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SPIKE_BOUNCE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 180)
                Loop(15)
                    Add(LVar0, 12)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Sub(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 180)
                Loop(5)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Wait(5)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim13)
            Wait(5)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim0F)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorYaw, ACTOR_SELF, 0)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

// unused
EvtScript N(EVS_FallFromCeiling) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothToppled)
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim06)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 24)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HandleEvent_SmoothToppled) = {
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim22)
            SetConst(LVar2, ANIM_BonyBeetle_Anim23)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim22)
            SetConst(LVar2, ANIM_BonyBeetle_Anim23)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim23)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothToppled)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1A)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            UseBuf(N(FlipPosOffsets))
            Loop(20)
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Wait(20)
        CaseOrEq(EVENT_SCARE_AWAY)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim06)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim06)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim06)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1A)
            ExecWait(EVS_Enemy_BlowAway)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TryGettingUp_Smooth) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    Sub(LVar0, 1)
    IfGt(LVar0, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1C)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim06)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_FAR)
        Call(SetBattleCamDist, 350)
        Call(SetBattleCamOffsetY, 20)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1C)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim06)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim0A)
        Wait(20)
        Call(SetActorYaw, ACTOR_SELF, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
        Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefenseTable)))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandleEvent_SpikyToppled) = {
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim24)
            SetConst(LVar2, ANIM_BonyBeetle_Anim25)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim24)
            SetConst(LVar2, ANIM_BonyBeetle_Anim25)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim25)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyToppled)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledSpikyAnims)))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1B)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            UseBuf(N(FlipPosOffsets))
            Loop(20)
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Wait(20)
        CaseOrEq(EVENT_SCARE_AWAY)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim07)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim07)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim07)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BonyBeetle_Anim1B)
            ExecWait(EVS_Enemy_BlowAway)
            Return
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TryGettingUp_Spiky) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    Sub(LVar0, 1)
    IfGt(LVar0, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1D)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim07)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_FAR)
        Call(SetBattleCamDist, 350)
        Call(SetBattleCamOffsetY, 20)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1D)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim07)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim0B)
        Wait(20)
        Call(SetActorYaw, ACTOR_SELF, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
        Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefenseTable)))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SpikyAnims)))
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

