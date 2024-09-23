#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Spiny.h"
#include "sprite/npc/Lakitu.h"

#define NAMESPACE A(spiny)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BALL        = 2,
};

enum N(ActorVars) {
    AVAR_Toppled        = 0,
    AVAR_ToppleTurns    = 1,
};

enum N(ActorParams) {
    DMG_ROLL        = 4,
};

s32 N(UprightAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Spiny_Anim01,
    STATUS_KEY_STONE,     ANIM_Spiny_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Spiny_Anim10,
    STATUS_KEY_POISON,    ANIM_Spiny_Anim01,
    STATUS_KEY_STOP,      ANIM_Spiny_Anim00,
    STATUS_KEY_STATIC,    ANIM_Spiny_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Spiny_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Spiny_Anim12,
    STATUS_KEY_FEAR,      ANIM_Spiny_Anim12,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Spiny_Anim02,
    STATUS_KEY_STONE,     ANIM_Spiny_Anim15,
    STATUS_KEY_SLEEP,     ANIM_Spiny_Anim11,
    STATUS_KEY_POISON,    ANIM_Spiny_Anim02,
    STATUS_KEY_STOP,      ANIM_Spiny_Anim15,
    STATUS_KEY_STATIC,    ANIM_Spiny_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_Spiny_Anim15,
    STATUS_KEY_DIZZY,     ANIM_Spiny_Anim13,
    STATUS_KEY_FEAR,      ANIM_Spiny_Anim13,
    STATUS_END,
};

s32 N(SpinyBallAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lakitu_Anim0B,
    STATUS_END,
};

s32 N(UprightDefense)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_END,
};

s32 N(ToppledDefense)[] = {
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
    STATUS_KEY_STOP,               90,
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
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(UprightAnims),
        .defenseTable = N(UprightDefense),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -4 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BALL,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpinyBallAnims),
        .defenseTable = N(UprightDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPINY,
    .level = ACTOR_LEVEL_SPINY,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 75,
    .hurricaneChance = 75,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 24, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetAnimation, ACTOR_SELF, PRT_BALL, ANIM_Lakitu_Anim0C)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim1A)
    Wait(8)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim01)
    Return
    End
};

EvtScript N(EVS_CheckToppleAnim) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar3)
    IfEq(LVar3, 1)
        Set(LVar1, LVar2)
    EndIf
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 7, 13, 17, 21, 23, 24, 23, 21, 17, 13, 7, 0, 4, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Spiny_Anim09)
            SetConst(LVar2, ANIM_Spiny_Anim0A)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfNe(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Spiny_Anim0B)
                SetConst(LVar2, ANIM_Spiny_Anim0C)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Spiny_Anim0D)
                SetConst(LVar2, ANIM_Spiny_Anim0E)
                ExecWait(EVS_Enemy_BurnHit)
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfNe(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Spiny_Anim0B)
                SetConst(LVar2, ANIM_Spiny_Anim0C)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Spiny_Anim0C)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Spiny_Anim0D)
                SetConst(LVar2, ANIM_Spiny_Anim0E)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Spiny_Anim0E)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Spiny_Anim09)
            SetConst(LVar2, ANIM_Spiny_Anim0A)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Spiny_Anim09)
            SetConst(LVar2, ANIM_Spiny_Anim0A)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Spiny_Anim09)
            SetConst(LVar2, ANIM_Spiny_Anim0A)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim0A)
            Else
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim16)
            EndIf
            Call(SetActorVar, ACTOR_SELF, AVAR_Toppled, 1)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefense)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ALT_SPIKY, FALSE)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            UseBuf(N(FlipPosOffsets))
            Loop(19)
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Wait(20)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim06)
                    ExecWait(EVS_Enemy_NoDamageHit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim07)
                    Wait(10)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim02)
                    ExecWait(EVS_Enemy_NoDamageHit)
            EndSwitch
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
            Wait(10)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVarA)
                IfEq(LVarA, 0)
                    Add(LVar0, 0)
                EndIf
                Add(LVar1, 8)
            Else
                Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVarA)
                IfEq(LVarA, 0)
                    Add(LVar0, -1)
                EndIf
                Add(LVar1, 22)
            EndIf
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            Wait(20)
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Spiny_Anim09)
            SetConst(LVar2, ANIM_Spiny_Anim0A)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Spiny_Anim09)
            SetConst(LVar2, ANIM_Spiny_Anim0A)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim01)
                    ExecWait(EVS_Enemy_Recover)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim02)
                    ExecWait(EVS_Enemy_NoDamageHit)
            EndSwitch
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim04)
                    SetConst(LVar2, ANIM_Spiny_Anim09)
                    ExecWait(EVS_Enemy_ScareAway)
                    Return
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim02)
                    ExecWait(EVS_Enemy_NoDamageHit)
            EndSwitch
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim04)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim02)
            EndSwitch
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim04)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Spiny_Anim02)
            EndSwitch
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
    Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
    IfEq(LVar0, 1)
        Call(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        Sub(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        IfGt(LVar0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim14)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Wait(30)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
        Else
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim14)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Wait(20)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Spiny_Anim02)
            SetConst(LVar2, ANIM_Spiny_Anim01)
            ExecWait(EVS_Enemy_FlipBackUp)
            Call(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(UprightDefense)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ALT_SPIKY, TRUE)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
        EndIf
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
    IfEq(LVar0, 0)
        Wait(10)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim19)
        Wait(8)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim18)
        Wait(10)
    Else
        Wait(20)
    EndIf
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EndThread
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_BALL, ANIM_Lakitu_Anim0C)
    Wait(10)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_BALL, SOUND_SPINY_SPIN_UP)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_BALL, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Thread
                Loop(0)
                    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    Add(LVar0, 30)
                    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    IfGt(LVar0, LVar3)
                        BreakLoop
                    EndIf
                    Wait(1)
                EndLoop
                Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
                IfEq(LVarA, HIT_RESULT_LUCKY)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndIf
                Wait(15)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_ROLL, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_BALL, ANIM_Lakitu_Anim0B)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 20)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Add(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            Call(YieldTurn)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
