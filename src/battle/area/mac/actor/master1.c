#include "../area.h"
#include "sprite/npc/TheMaster.h"

#define NAMESPACE A(master1)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_BattleCry      = 0,
    AVAR_Unused         = 1,
    AVAR_WasHit         = 2,
    AVAR_HitCounter     = 3,
};

enum N(ActorParams) {
    DMG_STRIKE      = 6,
};

// AVAR_HitCounter starts at this value, for some reason
#define INITIAL_HIT_COUNT 2

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TheMaster_Walk,
    STATUS_KEY_STONE,     ANIM_TheMaster_Still,
    STATUS_KEY_SLEEP,     ANIM_TheMaster_Sleep,
    STATUS_KEY_POISON,    ANIM_TheMaster_Still,
    STATUS_KEY_STOP,      ANIM_TheMaster_Still,
    STATUS_KEY_STATIC,    ANIM_TheMaster_Still,
    STATUS_KEY_PARALYZE,  ANIM_TheMaster_Still,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,             50,
    STATUS_KEY_DEFAULT,            50,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               70,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_UNUSED,         0,
    STATUS_TURN_MOD_STATIC,        -1,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 28 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_THE_MASTER_1,
    .level = ACTOR_LEVEL_THE_MASTER_1,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 35 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 10, 30 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_BattleCry, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_WasHit, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_HitCounter, INITIAL_HIT_COUNT)
    Set(GF_FoughtTheMaster, 1)
    Call(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, true)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent_Inner) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_BurnHurt)
            SetConst(LVar2, ANIM_TheMaster_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_BurnHurt)
            SetConst(LVar2, ANIM_TheMaster_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Defeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Walk)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Defeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Defeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Defeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_Run)
            SetConst(LVar2, ANIM_TheMaster_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.6))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Idle)
    Wait(10)
    Thread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_WindupLoop)
    Wait(10)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_WindupStill)
        Wait(7)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_DownwardStrike)
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(RunToGoal, ACTOR_SELF, 8, true)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(10)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 20)
            Set(LVar1, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Run)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(RunToGoal, ACTOR_SELF, 10, true)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Idle)
            Wait(3)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Idle)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(3.8))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Run)
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Idle)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_SMACK)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_STRIKE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 20)
            Set(LVar1, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Run)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(RunToGoal, ACTOR_SELF, 10, true)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Idle)
            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Idle)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Run)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_BattleCry, LVar0)
            IfEq(LVar0, false)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_002E, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Talk, ANIM_TheMaster_Walk)
                Call(SetActorVar, ACTOR_SELF, AVAR_BattleCry, true)
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_DOJO)
                BreakSwitch
            EndIf
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            Div(LVar1, 2)
            IfLe(LVar0, LVar1)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0031, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Talk, ANIM_TheMaster_Walk)
                BreakSwitch
            EndIf
            Call(GetPlayerHP, LVar0)
            IfLe(LVar0, 5)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0032, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Talk, ANIM_TheMaster_Walk)
                BreakSwitch
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    ExecWait(N(EVS_HandleEvent_Inner))
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_DOJO)
        Return
    EndIf
    Call(GetBattleFlags, LVar0)
    IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
        Call(GetLastDamage, ACTOR_SELF, LVar0)
        IfGt(LVar0, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_WasHit, true)
            Call(AddActorVar, ACTOR_SELF, AVAR_HitCounter, 1)
        EndIf
    EndIf
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_SPIN_SMASH_HIT)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_WasHit, LVarA)
            Call(GetActorVar, ACTOR_SELF, AVAR_HitCounter, LVarB)
            Call(SetActorVar, ACTOR_SELF, AVAR_WasHit, false)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_FLAG_SHRINK)
                BreakSwitch
            EndIf
            Set(LFlag0, false)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar0)
                CaseOrEq(BTL_MENU_TYPE_SMASH)
                CaseOrEq(BTL_MENU_TYPE_JUMP)
                    Set(LFlag0, true)
                EndCaseGroup
            EndSwitch
            IfEq(LFlag0, false)
                BreakSwitch
            EndIf
            Call(UseIdleAnimation, ACTOR_SELF, false)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            IfEq(LVarA, 1)
                IfGt(LVarB, INITIAL_HIT_COUNT)
                    // 'Excellent move!'
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(MoveBattleCamOver, 10)
                    Call(ActorSpeak, MSG_MAC_Gate_0030, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Talk, ANIM_TheMaster_Walk)
                    Call(SetActorVar, ACTOR_SELF, AVAR_HitCounter, 0)
                EndIf
            Else
                // 'That won't work on me.'
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_002F, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Talk, ANIM_TheMaster_Walk)
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
        EndCaseGroup
    EndSwitch
    Return
    End
};
