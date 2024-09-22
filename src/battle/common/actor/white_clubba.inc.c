#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleClubba.h"

#define NAMESPACE A(white_clubba)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_HEAVY_STRIKE    = 5,
    DMG_QUICK_STRIKE    = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleClubba_Frost_Anim01,
    STATUS_KEY_STONE,     ANIM_BattleClubba_Frost_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BattleClubba_Frost_Anim03,
    STATUS_KEY_POISON,    ANIM_BattleClubba_Frost_Anim01,
    STATUS_KEY_STOP,      ANIM_BattleClubba_Frost_Anim00,
    STATUS_KEY_STATIC,    ANIM_BattleClubba_Frost_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_BattleClubba_Frost_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BattleClubba_Frost_Anim05,
    STATUS_KEY_FEAR,      ANIM_BattleClubba_Frost_Anim05,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,    -2,
    ELEMENT_ICE,     99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -12, 32 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 8, -3 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_WHITE_CLUBBA,
    .level = ACTOR_LEVEL_WHITE_CLUBBA,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 50,
    .hurricaneChance = 60,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 42, 42 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 35 },
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

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim06)
            SetConst(LVar2, ANIM_BattleClubba_Frost_Anim07)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim06)
            SetConst(LVar2, ANIM_BattleClubba_Frost_Anim07)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim02)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim02)
            SetConst(LVar2, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim04)
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
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 27)
        Set(LVar1, 0)
        Sub(LVar2, 6)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Wait(15)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim02)
        Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(AddGoalPos, ACTOR_SELF, 27, 0, -6)
        Else
            Call(AddGoalPos, ACTOR_SELF, 10, 0, -6)
        EndIf
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim01)
        Wait(10)
    EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLUBBA_SWING)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim08)
            Wait(20)
            IfEq(LVar0, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                Wait(20)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim02)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Goto(40)
    EndIf
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    MulF(LVar0, Float(100.0))
    DivF(LVar0, LVar1)
    IfLt(LVar0, 30)
        Goto(50)
    EndIf
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 25)
        Goto(50)
    EndIf
    Label(40) // heavy club attack
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim09)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLUBBA_SWING)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim0A)
    Wait(2)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_HEAVY_STRIKE, BS_FLAGS1_TRIGGER_EVENTS)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.5))
    EndThread
    Goto(100)
    Label(50) // swift club attack
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim09)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLUBBA_SWING)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim0A)
    Wait(2)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_QUICK_STRIKE, BS_FLAGS1_INCLUDE_POWER_UPS)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.5))
    EndThread
    Call(GetActorHP, ACTOR_PLAYER, LVar0)
    IfEq(LVar0, 0)
        Goto(100)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim09)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLUBBA_SWING)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim0A)
    Wait(2)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_QUICK_STRIKE, BS_FLAGS1_NICE_HIT)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.5))
    EndThread
    Call(GetActorHP, ACTOR_PLAYER, LVar0)
    IfEq(LVar0, 0)
        Goto(100)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim09)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLUBBA_SWING)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleClubba_Frost_Anim0A)
    Wait(2)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_QUICK_STRIKE, BS_FLAGS1_TRIGGER_EVENTS)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.5))
    EndThread
    Label(100)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(19)
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleClubba_Frost_Anim02)
            ExecWait(EVS_Enemy_ReturnHome)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
