#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/MediGuy.h"
#include "sprite/npc/GrooveGuy.h"

#define NAMESPACE A(groove_guy)

extern ActorBlueprint A(red_shy_guy);
extern ActorBlueprint A(medi_guy);

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_RandomSummon);
extern EvtScript N(EVS_SummonShyGuy);
extern EvtScript N(EVS_SummonGrooveGuy);
extern EvtScript N(EVS_SummonMediGuy);

extern Formation N(ShyGuyFormation);
extern Formation N(GrooveGuyFormation);
extern Formation N(MediGuyFormation);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Generation = 0,
};

enum N(ActorParams) {
    DMG_TACKLE      = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GrooveGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_GrooveGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_GrooveGuy_Anim06,
    STATUS_KEY_POISON,    ANIM_GrooveGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_GrooveGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_GrooveGuy_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_GrooveGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_GrooveGuy_Anim07,
    STATUS_KEY_FEAR,      ANIM_GrooveGuy_Anim07,
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
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

BSS PlayerStatus N(DummyPlayerStatus);

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
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GROOVE_GUY,
    .level = ACTOR_LEVEL_GROOVE_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 28, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
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
            Call(N(SetAbsoluteStatusOffsets), -13, 15, 4, 13)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 24)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -10)
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
    SetConst(LVar1, ANIM_GrooveGuy_Anim04)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim01)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim0E)
            SetConst(LVar2, ANIM_GrooveGuy_Anim0F)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim0E)
            SetConst(LVar2, ANIM_GrooveGuy_Anim0F)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim0F)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim04)
            SetConst(LVar2, ANIM_GrooveGuy_Anim11)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim04)
            ExecWait(EVS_Enemy_AirLift)
        CaseOrEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GrooveGuy_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
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
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim04)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim10)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, false)
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
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
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
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim01)
            Wait(8)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_SleepySpin) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim10)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_TWIRL)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    Set(LVar0, 0)
    Loop(30)
        Add(LVar0, 48)
        Mod(LVar0, 360)
        Call(SetActorYaw, ACTOR_SELF, LVar0)
        Wait(1)
    EndLoop
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
            Wait(20)
            IfEq(LVar0, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_KEY(STATUS_FLAG_DIZZY, 2, 50), 0, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(WasStatusInflicted, ACTOR_SELF, LVar0)
            IfEq(LVar0, true)
                Thread
                    Set(LVar0, 0)
                    Loop(30)
                        Add(LVar0, 48)
                        Mod(LVar0, 360)
                        Call(SetActorYaw, ACTOR_PLAYER, LVar0)
                        Wait(1)
                    EndLoop
                    Call(SetActorYaw, ACTOR_PLAYER, 0)
                EndThread
            EndIf
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_LEAP)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
            Set(LVar0, 0)
            Loop(15)
                Add(LVar0, 24)
                Mod(LVar0, 360)
                Call(SetActorYaw, ACTOR_SELF, LVar0)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_SPIN_DOWN)
            Thread
                Set(LVar0, 0)
                Loop(20)
                    Add(LVar0, 72)
                    Mod(LVar0, 360)
                    Call(SetActorYaw, ACTOR_SELF, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorYaw, ACTOR_SELF, LVar0)
            EndThread
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0A)
            Wait(25)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_GetAvailableColumn) = {
    Set(LFlag1, false)
    Set(LFlag2, false)
    Set(LFlag3, false)
    Set(LFlag4, false)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar5)
        Call(GetIndexFromHome, LVar0, LVar5)
        Mod(LVar5, 4)
        Switch(LVar5)
            CaseEq(0)
                Set(LFlag1, true)
            CaseEq(1)
                Set(LFlag2, true)
            CaseEq(2)
                Set(LFlag3, true)
            CaseEq(3)
                Set(LFlag4, true)
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    IfEq(LFlag1, false)
        Set(LVarA, 0)
        Return
    EndIf
    IfEq(LFlag2, false)
        Set(LVarA, 1)
        Return
    EndIf
    IfEq(LFlag3, false)
        Set(LVarA, 2)
        Return
    EndIf
    IfEq(LFlag4, false)
        Set(LVarA, 3)
        Return
    EndIf
    Set(LVarA, -1)
    Return
    End
};

EvtScript N(EVS_CountActiveSummoners) = {
    Set(LVar9, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        Switch(LVar2)
            CaseEq(ACTOR_TYPE_GROOVE_GUY)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    Call(GetActorVar, LVar0, AVAR_Generation, LVar3)
                    IfNe(LVar3, 2)
                        Add(LVar9, 1)
                    EndIf
                EndIf
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    IfEq(LVar0, 2)
        Call(RandInt, 100, LVar0)
        IfLt(LVar0, 60)
            Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
            IfFlag(LVar0, STATUS_FLAG_DIZZY)
                ExecWait(N(EVS_Attack_Tackle))
            Else
                ExecWait(N(EVS_Attack_SleepySpin))
            EndIf
        Else
            ExecWait(N(EVS_Attack_Tackle))
        EndIf
        Return
    EndIf
    ExecWait(N(EVS_GetAvailableColumn))
    IfEq(LVarA, -1)
        Call(RandInt, 100, LVar0)
        IfLt(LVar0, 60)
            Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
            IfFlag(LVar0, STATUS_FLAG_DIZZY)
                ExecWait(N(EVS_Attack_Tackle))
            Else
                ExecWait(N(EVS_Attack_SleepySpin))
            EndIf
        Else
            ExecWait(N(EVS_Attack_Tackle))
        EndIf
        Return
    EndIf
    ExecWait(N(EVS_CountActiveSummoners))
    Switch(LVar9)
        CaseEq(1)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 300)
                ExecWait(N(EVS_RandomSummon))
                Return
            EndIf
        CaseEq(2)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 150)
                ExecWait(N(EVS_RandomSummon))
                Return
            EndIf
        CaseEq(3)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 100)
                ExecWait(N(EVS_RandomSummon))
                Return
            EndIf
    EndSwitch
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 60)
        Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
        IfFlag(LVar0, STATUS_FLAG_DIZZY)
            ExecWait(N(EVS_Attack_Tackle))
        Else
            ExecWait(N(EVS_Attack_SleepySpin))
        EndIf
    Else
        ExecWait(N(EVS_Attack_Tackle))
    EndIf
    Return
    End
};

EvtScript N(EVS_RandomSummon) = {
    Call(UseBattleCamPreset, BTL_CAM_MIDPOINT_NORMAL)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(RandInt, 2, LVar1)
    Switch(LVar1)
        CaseEq(0)
            ExecWait(N(EVS_SummonShyGuy))
        CaseEq(1)
            ExecWait(N(EVS_SummonGrooveGuy))
        CaseEq(2)
            ExecWait(N(EVS_SummonMediGuy))
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
    Return
    End
};

API_CALLABLE(N(SpawnSpinFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x, y, z;
    f32 scale;
    s32 duration;

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    scale = evt_get_float_variable(script, *args++);
    duration = evt_get_variable(script, *args++);

    N(DummyPlayerStatus).pos.x = x;
    N(DummyPlayerStatus).pos.y = y;
    N(DummyPlayerStatus).pos.z = z;
    fx_effect_46(6, &N(DummyPlayerStatus), scale, duration);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_PerformSummonDance) = {
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0D)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0D)
    Wait(4)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        SetF(LVar3, Float(1.0))
    Else
        SetF(LVar3, Float(0.4))
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(N(SpawnSpinFX), LVar0, LVar1, LVar2, LVar3, 48)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_SUMMON)
    Set(LVar0, 0)
    Loop(48)
        Add(LVar0, 30)
        IfGe(LVar0, 360)
            Sub(LVar0, 360)
        EndIf
        Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0A)
    Wait(8)
    Return
    End
};

EvtScript N(EVS_SummonShyGuy) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    ExecWait(N(EVS_PerformSummonDance))
    Call(SummonEnemy, Ref(N(ShyGuyFormation)), false)
    Set(LVarB, LVar0)
    Set(LVar0, 200)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Call(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetGoalToIndex, LVarB, LVarA)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetActorSpeed, LVarB, Float(4.0))
    Call(RunToGoal, LVarB, 0, false)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVarB)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_SummonGrooveGuy) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    ExecWait(N(EVS_PerformSummonDance))
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SummonEnemy, Ref(N(GrooveGuyFormation)), false)
    Set(LVarB, LVar0)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    Call(SetGoalToIndex, LVarB, LVarA)
    Call(GetGoalPos, LVarB, LVar3, LVar4, LVar5)
    Add(LVar3, 200)
    Call(SetActorPos, LVarB, LVar3, LVar4, LVar5)
    Thread
        Set(LVar6, 0)
        Loop(50)
            Add(LVar6, 30)
            Mod(LVar6, 360)
            Call(SetActorYaw, LVarB, LVar6)
            Wait(1)
        EndLoop
        Call(SetActorYaw, LVarB, 0)
    EndThread
    Call(SetActorSounds, LVarB, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Thread
        Loop(2)
            Call(PlaySoundAtActor, LVarB, SOUND_GROOVE_GUY_TWIRL)
            Wait(25)
        EndLoop
    EndThread
    Call(SetActorSpeed, LVarB, Float(4.0))
    Call(RunToGoal, LVarB, 0, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_GrooveGuy_Anim0A)
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    Wait(25)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_GrooveGuy_Anim01)
    Call(HPBarToHome, LVarB)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetActorVar, LVarB, AVAR_Generation, 1)
        CaseEq(1)
            Call(SetActorVar, LVarB, AVAR_Generation, 2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SummonMediGuy) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    ExecWait(N(EVS_PerformSummonDance))
    Call(SummonEnemy, Ref(N(MediGuyFormation)), false)
    Set(LVarB, LVar0)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_MediGuy_Anim05)
    Add(LVarA, 4)
    Call(SetGoalToIndex, LVarB, LVarA)
    Call(GetGoalPos, LVarB, LVar3, LVar4, LVar5)
    Set(LVar0, 200)
    Set(LVar1, LVar4)
    Set(LVar2, LVar5)
    Call(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(SetActorSounds, LVarB, ACTOR_SOUND_WALK, SOUND_SHY_GUY_FLY, SOUND_NONE)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetActorSpeed, LVarB, Float(4.0))
    Call(RunToGoal, LVarB, 0, false)
    Call(SetAnimation, LVarB, PRT_MAIN, ANIM_MediGuy_Anim01)
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVarB)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(ShyGuyFormation) = {
    ACTOR_BY_POS(A(red_shy_guy), N(SummonPos), 100),
};

Formation N(GrooveGuyFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 100),
};

Formation N(MediGuyFormation) = {
    ACTOR_BY_POS(A(medi_guy), N(SummonPos), 100),
};
