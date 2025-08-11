#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"

#define NAMESPACE A(anti_guy)

#ifdef ANTIGUY_TRIO
#define ACTOR_TYPE          ACTOR_TYPE_ANTI_GUY_KPA
#define ACTOR_LEVEL         ACTOR_LEVEL_ANTI_GUY_KPA
#define PARALYZE_CHANCE     50
#define ESCAPE_CHANCE       0
#else
#define ACTOR_TYPE          ACTOR_TYPE_ANTI_GUY_OMO
#define ACTOR_LEVEL         ACTOR_LEVEL_ANTI_GUY_OMO
#define PARALYZE_CHANCE     60
#define ESCAPE_CHANCE       50
#endif

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_TACKLE      = 10,
    DMG_VAULT       = 12,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           PARALYZE_CHANCE,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE,
    .level = ACTOR_LEVEL,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = ESCAPE_CHANCE,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 30, 30 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyGuy_Black_Anim01,
    STATUS_KEY_STONE,     ANIM_ShyGuy_Black_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShyGuy_Black_Anim12,
    STATUS_KEY_POISON,    ANIM_ShyGuy_Black_Anim01,
    STATUS_KEY_STOP,      ANIM_ShyGuy_Black_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShyGuy_Black_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyGuy_Black_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShyGuy_Black_Anim13,
    STATUS_KEY_FEAR,      ANIM_ShyGuy_Black_Anim13,
    STATUS_END,
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
    IfFlag(LVar0, STATUS_FLAG_SLEEP)
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 14)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
        Call(N(SetAbsoluteStatusOffsets), -10, 13, 10, 13)
    Else
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 24)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -10)
        Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EndIf
    Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_ShyGuy_Black_Anim03)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim01)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Black_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Black_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim03)
            SetConst(LVar2, ANIM_ShyGuy_Black_Anim14)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim0C)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_Tackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HOP, 0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim04)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Wait(3)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    EndThread
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim04)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim05)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim01)
    Wait(8)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    ExecWait(N(EVS_ReturnHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_Vault) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TIMING_BAR_GO)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim09)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 80)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim04)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Sub(LVar0, 40)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim09)
            Thread
                Wait(12)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim0A)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 24, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim09)
    Thread
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim0A)
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 18, false, true, false)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_VAULT, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Set(LVar3, 0)
                Loop(20)
                    Sub(LVar3, 30)
                    IfLt(LVar3, 0)
                        Add(LVar3, 360)
                    EndIf
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    Wait(1)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Goto(1)
            EndIf
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfEq(LVar0, 0)
                Goto(1)
            EndIf
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING | SOUND_ID_TRIGGER_CHANGE_SOUND)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim09)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim07)
            Wait(15)
            Goto(2)
            Label(1)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim10)
            Wait(10)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISAPPOINTED)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 50)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim11)
            Else
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim13)
            EndIf
            Wait(25)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Label(2)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShyGuy_Black_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Black_Anim01)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(RandInt, 1, LVar0)
    IfEq(LVar0, 0)
        ExecWait(N(EVS_Attack_Tackle))
    Else
        ExecWait(N(EVS_Attack_Vault))
    EndIf
    Return
    End
};
