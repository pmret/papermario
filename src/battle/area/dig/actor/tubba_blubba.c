#include "../area.h"
#include "sprite/npc/BattleTubba.h"

#define NAMESPACE A(tubba_blubba)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Attack_BodySlam);
extern EvtScript N(EVS_PlayFootstepQuaking);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_CaughtYouTaunt     = 0, // unused
    AVAR_InvunerableTaunt   = 1,
    AVAL_Taunt_None         = 0,
    AVAL_Taunt_Ready        = 1,
    AVAL_Taunt_Done         = 2,
    AVAR_QuakingScriptID    = 2,
};

enum N(ActorParams) {
    DMG_FIST_POUND  = 4,
    DMG_BODY_SLAM   = 6,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleTubba_Anim02,
    STATUS_KEY_STONE,     ANIM_BattleTubba_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BattleTubba_Anim00,
    STATUS_KEY_POISON,    ANIM_BattleTubba_Anim02,
    STATUS_KEY_STOP,      ANIM_BattleTubba_Anim00,
    STATUS_KEY_STATIC,    ANIM_BattleTubba_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_BattleTubba_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_BattleTubba_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BattleTubba_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BattleTubba_Anim00,
    STATUS_KEY_FEAR,      ANIM_BattleTubba_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           80,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,               80,
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
        .flags = ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -15, 75 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE,
    .level = ACTOR_LEVEL_TUBBA_BLUBBA_INVINCIBLE,
    .maxHP = 10,
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
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 110, 100 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -33, 78 },
    .statusTextOffset = { 10, 75 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_InvunerableTaunt, AVAL_Taunt_None)
    Call(SetActorVar, ACTOR_SELF, AVAR_CaughtYouTaunt, FALSE)
    ExecGetTID(N(EVS_PlayFootstepQuaking), LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_QuakingScriptID, LVar0)
    Return
    End
};

EvtScript N(EVS_PlayFootstepQuaking) = {
    Label(0)
        Wait(1)
        Call(ActorExists, ACTOR_SELF, LVar0)
        IfEq(LVar0, 0)
            Return
        EndIf
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfFlag(LVar0, STATUS_FLAG_SHRINK)
            Goto(0)
        EndIf
        Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        IfEq(LVar0, ANIM_BattleTubba_Anim06)
            Goto(1)
        EndIf
        IfEq(LVar0, ANIM_BattleTubba_Anim07)
            Goto(1)
        EndIf
        Goto(0)
        Label(1)
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim02)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim07)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim02)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim07)
        Call(SetGoalPos, ACTOR_SELF, 0, 0, 0)
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim01)
        Wait(30)
        Set(LVar0, 0)
        Loop(12)
            Add(LVar0, 15)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
        EndLoop
        Wait(10)
        Set(LVar0, 180)
        Loop(12)
            Sub(LVar0, 15)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
        EndLoop
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim02)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar1, 80)
        PlayEffect(EFFECT_EMOTE, EMOTE_QUESTION, 0, LVar0, LVar1, LVar2, 30, 315, 30, 0, 0)
        Wait(40)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim01)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, 12)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
        EndLoop
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim06)
        Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar0, 220)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        Call(GetActorVar, ACTOR_SELF, AVAR_QuakingScriptID, LVar0)
        KillThread(LVar0)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        Call(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, TRUE)
        Call(SetEndBattleFadeOutRate, 10)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_InvunerableTaunt, LVar0)
    IfEq(LVar0, AVAL_Taunt_Ready)
        Call(EnableBattleStatusBar, FALSE)
        Call(SetActorVar, ACTOR_SELF, AVAR_InvunerableTaunt, AVAL_Taunt_Done)
        Call(ActorSpeak, MSG_CH3_0103, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim09, ANIM_BattleTubba_Anim02)
        Thread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim15)
            Wait(4)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim16)
            Wait(15)
        EndThread
        Call(EndActorSpeech, ACTOR_SELF, PRT_MAIN, -1, -1)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim01)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 15)
        Wait(15)
        Call(EnableBattleStatusBar, TRUE)
    EndIf
    ExecWait(N(EVS_Attack_BodySlam))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_SlamFist) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamDist, 150)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim07)
    Call(SetGoalToTarget, ACTOR_SELF)
    IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
        Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Else
        Call(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim15)
    Wait(8)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim16)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim17)
    Wait(3)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0, 0)
        PlayEffect(EFFECT_SHOCKWAVE, 1, LVar0, LVar1, LVar2, 0)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(15.0))
        EndThread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
    EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim02)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(GetStatusFlags, ACTOR_SELF, LVar5)
    IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SHOCKWAVE, 1, LVar0, 0, LVar2, 0)
    EndIf
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
        Call(SetDamageSource, DMG_SRC_TUBBA_SMASH)
    EndIf
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_FIST_POUND, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim02)
            IfEq(LVarF, 10)
                Return
            EndIf
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_BodySlam) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamDist, 180)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim07)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim0F)
    Wait(8)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim10)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Wait(12)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim11)
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 15)
            Set(LVar1, 0)
            Add(LVar2, 5)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(PlaySound, SOUND_ACTOR_JUMP)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 23, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim12)
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            EndThread
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
            EndThread
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Add(LVar2, 5)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Wait(8)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim13)
            Wait(4)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseDefault
            Thread
                Wait(12)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim11)
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(PlaySound, SOUND_ACTOR_JUMP)
            Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EndSwitch
    Wait(2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar5)
    IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
        Call(SetDamageSource, DMG_SRC_CRUSH)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_LANDING)
    EndIf
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_BODY_SLAM, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfFlag(LVar5, STATUS_FLAG_SHRINK)
                Goto(1)
            EndIf
            Call(GetBattleFlags, LVar0)
            IfNotFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_STONE)
                    Call(LandJump, ACTOR_SELF)
                Else
                    Goto(1)
                EndIf
            Else
                Goto(1)
            EndIf
            Label(0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SHOCKWAVE, 0, LVar0, 0, LVar2, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim0D)
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            EndThread
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
            EndThread
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Add(LVar2, 5)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
            Goto(2)
            Label(1)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
                Wait(3)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                PlayEffect(EFFECT_SHOCKWAVE, 1, LVar0, 0, LVar2, 0)
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
            EndIf
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Thread
                Wait(8)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleTubba_Anim0E)
            EndThread
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 60, 8, 10, 20, 0)
                Wait(8)
            EndIf
            Label(2)
            IfEq(LVarF, 10)
                Return
            EndIf
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Return
    End
};
