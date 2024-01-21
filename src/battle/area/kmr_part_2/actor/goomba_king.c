#include "../area.h"
#include "sprite/npc/GoombaKing.h"
#include "sprite/npc/GoombaBros.h"
#include "sprite/player.h"
#include "goomba_king_common.h"

#define NAMESPACE A(goomba_king)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_ShakeScreenWhileWalking);
extern EvtScript N(EVS_Attack_GroundStomp);
extern EvtScript N(EVS_Attack_SpinSwipe);
extern EvtScript N(EVS_GoombaKing_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_Unused_0               = 0,
    AVAR_Unused_1               = 1,
    AVAR_IncreaseShaking        = 2, // when TRUE walking around causes more camera shaking
    AVAR_Scene_BeginBattle      = 3,
    AVAR_ScreenShakingScriptID  = 4,
    AVAR_Unused_5               = 5,
};

enum N(ActorParams) {
    DMG_SPIN        = 1,
    DMG_STOMP       = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Idle,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

// while shuffling around during idle
s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Run,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(UnusedDizzyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Dizzy,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(UnusedAngryAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Angry,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,        -1,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -25, 15 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 80 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBA_KING,
    .level = ACTOR_LEVEL_GOOMBA_KING,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 56, 80 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -6, 38 },
    .statusTextOffset = { 12, 75 },
};

// Unused
API_CALLABLE(N(SpawnImpactDustFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_landing_dust(2, x, y, z, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    ExecGetTID(N(EVS_ShakeScreenWhileWalking), LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_0, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_1, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_IncreaseShaking, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Scene_BeginBattle, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_5, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TREE_DELAY, 0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(RandInt, 80, LVar0)
        Add(LVar0, 80)
        Wait(LVar0)
        Label(1)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Wait(1)
                Goto(1)
            EndIf
        Call(SetGoalToHome, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        Wait(20)
        Label(2)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Wait(1)
                Goto(2)
            EndIf
        Call(SetGoalToHome, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        Wait(80)
        Goto(0)
    Return
    End
};

EvtScript A(EVS_Lee_ShockKnockback) = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
    Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    Call(AddGoalPos, ACTOR_SELF, 15, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    Call(AddGoalPos, ACTOR_SELF, 5, 0, 0)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_BurnHurt)
            SetConst(LVar2, ANIM_GoombaKing_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(A(EVS_Lee_ShockKnockback))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Run)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(EVS_Enemy_ShockHit)
            Call(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            KillThread(LVar0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(N(EVS_GoombaKing_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            Call(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            KillThread(LVar0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(N(EVS_GoombaKing_Death))
            Return
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_BurnHurt)
            SetConst(LVar2, ANIM_GoombaKing_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            Call(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            KillThread(LVar0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_BurnStill)
            ExecWait(N(EVS_GoombaKing_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(EVS_Enemy_SpinSmashHit)
            Call(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            KillThread(LVar0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Dead)
            ExecWait(N(EVS_GoombaKing_Death))
            Return
        CaseEq(EVENT_SPIKE_CONTACT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Dead)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GoombaKing_Idle)
            ExecWait(EVS_Enemy_Recover)
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
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorVar, ACTOR_TREE, AVAR_TREE_DELAY, LVar0)
        IfNe(LVar0, 0)
            Call(RandInt, 100, LVar1)
            IfLt(LVar1, 60)
                Sub(LVar0, 1)
                Call(SetActorVar, ACTOR_TREE, AVAR_TREE_DELAY, LVar0)
                ExecWait(N(EVS_Attack_GroundStomp))
                Return
            EndIf
        EndIf
    EndIf
    ExecWait(N(EVS_Attack_SpinSwipe))
    Return
    Return
    End
};

EvtScript N(EVS_Attack_SpinSwipe) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(AddBattleCamZoom, -100)
        Call(SetBattleCamOffsetZ, 20)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 30)
        Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(AddBattleCamZoom, -100)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EndIf
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(AddGoalPos, ACTOR_SELF, 32, 0, 0)
    Else
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(AddGoalPos, ACTOR_SELF, 12, 0, 0)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
    Wait(8)
    Thread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBA_KING_SPIN)
        Wait(10)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBA_KING_SPIN)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Kick)
    Set(LVar0, 0)
    Loop(20)
        Add(LVar0, 18)
        Call(SetActorYaw, ACTOR_SELF, LVar0)
        Wait(1)
    EndLoop
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Dizzy)
            Set(LVar0, 0)
            Loop(20)
                Add(LVar0, 18)
                Call(SetActorYaw, ACTOR_SELF, LVar0)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarA, 0, 0, 0, DMG_SPIN, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
    Switch(LVarA)
        CaseDefault
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_GroundStomp) = {
    Call(UseBattleCamPreset, BTL_CAM_PRESET_15)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Wait(15)
    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Angry)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Still)
    Thread
        Call(StartRumble, BTL_RUMBLE_PLAYER_MAX)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(ShakeCam, CAM_BATTLE, 0, 10, Float(4.0))
        EndIf
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
        PlayEffect(EFFECT_DROP_LEAVES, 0, -80, 125, 0, 100, 0)
        PlayEffect(EFFECT_DROP_LEAVES, 0, -15, 135, 0, 85, 0)
        PlayEffect(EFFECT_DROP_LEAVES, 0, 100, 103, 0, 70, 0)
    EndThread
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Thread
                Wait(12)
                Call(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_1, SOUND_FALL_QUICK)
            EndThread
            Thread
                Wait(10)
                Call(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_1, Float(1.5))
                Call(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, LVar1, LVar2)
                Call(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 14)
                Sub(LVar0, 12)
                Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 10, TRUE)
                Sub(LVar0, 7)
                Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 7, TRUE)
                Loop(20)
                    Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Wait(1)
                    Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Wait(5)
                Call(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_2, SOUND_FALL_QUICK)
            EndThread
            Thread
                Wait(3)
                Call(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_2, Float(1.5))
                Call(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, LVar1, LVar2)
                Call(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 15)
                Sub(LVar0, 12)
                Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 10, TRUE)
                Sub(LVar0, 7)
                Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 7, TRUE)
                Loop(20)
                    Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Wait(1)
                    Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Wait(17)
                Call(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_3, SOUND_FALL_QUICK)
            EndThread
            Thread
                Wait(15)
                Call(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_3, Float(1.5))
                Call(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, LVar1, LVar2)
                Call(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 17)
                Add(LVar0, 12)
                Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 10, TRUE)
                Add(LVar0, 7)
                Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 7, TRUE)
                Loop(20)
                    Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Wait(1)
                    Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Wait(1)
                EndLoop
            EndThread
            Wait(15)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Wait(12)
        Call(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_1, SOUND_FALL_QUICK)
    EndThread
    Thread
        Wait(10)
        Call(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_1, Float(1.5))
        Call(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, LVar1, LVar2)
        Call(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 35, LVar2, 14)
        Sub(LVar0, 12)
        Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 10, TRUE)
        Sub(LVar0, 7)
        Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 7, TRUE)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(5)
        Call(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_2, SOUND_FALL_QUICK)
    EndThread
    Thread
        Wait(3)
        Call(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_2, Float(1.5))
        Call(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, LVar1, LVar2)
        Call(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 15)
        Sub(LVar0, 12)
        Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 10, TRUE)
        Sub(LVar0, 7)
        Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 7, TRUE)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Wait(17)
        Call(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_3, SOUND_FALL_QUICK)
    EndThread
    Thread
        Wait(15)
        Call(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_3, Float(1.5))
        Call(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, LVar1, LVar2)
        Call(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 17)
        Add(LVar0, 12)
        Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 10, TRUE)
        Add(LVar0, 7)
        Call(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 7, TRUE)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Wait(1)
        EndLoop
    EndThread
    Wait(24)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_STOMP, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseEq(HIT_RESULT_10)
            Return
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Scene_BeginBattle, LVar0)
            IfEq(LVar0, FALSE)
                Call(EnableBattleStatusBar, FALSE)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
                Call(BattleCamTargetActor, ACTOR_RED_GOOMBA)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(UseIdleAnimation, ACTOR_RED_GOOMBA, FALSE)
                Call(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_DISABLE)
                Call(ActorSpeak, MSG_CH0_00CB, ACTOR_RED_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Talk)
                Call(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_ENABLE)
                Call(UseIdleAnimation, ACTOR_RED_GOOMBA, TRUE)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
                Call(BattleCamTargetActor, ACTOR_BLUE_GOOMBA)
                Call(MoveBattleCamOver, 10)
                Wait(10)
                Call(UseIdleAnimation, ACTOR_BLUE_GOOMBA, FALSE)
                Call(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_DISABLE)
                Call(ActorSpeak, MSG_CH0_00CC, ACTOR_BLUE_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Blue_Talk, ANIM_GoombaBros_Blue_Talk)
                Call(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_ENABLE)
                Call(UseIdleAnimation, ACTOR_BLUE_GOOMBA, TRUE)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
                Call(BattleCamTargetActor, ACTOR_KING)
                Call(MoveBattleCamOver, 20)
                Wait(20)
                Call(ActorSpeak, MSG_CH0_00CD, ACTOR_KING, PRT_MAIN, ANIM_GoombaKing_Angry, ANIM_GoombaKing_Angry)
                Call(SetActorVar, ACTOR_SELF, AVAR_Scene_BeginBattle, TRUE)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
                Call(BattleCamTargetActor, ACTOR_PLAYER)
                Call(MoveBattleCamOver, 10)
                Wait(10)
                Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                Call(SetActorYaw, ACTOR_PLAYER, 180)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Question)
                Call(ActorSpeak, MSG_CH0_00CE, ACTOR_PARTNER, 0, -1, -1)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_NodYes)
                Wait(15)
                Call(SetActorYaw, ACTOR_PLAYER, 0)
                Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Wait(20)
                Call(EnableBattleStatusBar, TRUE)
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ShakeScreenWhileWalking) = {
    Label(0)
        Wait(1)
        Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        IfNe(LVar0, ANIM_GoombaKing_Run)
            Goto(0)
        EndIf
        Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        IfNe(LVar0, ANIM_GoombaKing_Run)
            Goto(0)
        EndIf
        Call(StartRumble, BTL_RUMBLE_LONG)
        Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
        IfEq(LVar0, 1)
            Call(GetActorVar, ACTOR_SELF, AVAR_IncreaseShaking, LVar0)
            IfEq(LVar0, FALSE)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
                EndIf
            Else
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.7))
                EndIf
            EndIf
        EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_GoombaKing_Death) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Set(LVar2, 0)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Wait(10)
    Loop(24)
        Call(SetActorYaw, ACTOR_SELF, LVar2)
        Add(LVar2, 30)
        Wait(1)
    EndLoop
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar2, LVar3, LVar4, 0, 0, 0, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Set(LVar3, 0)
    Loop(12)
        Call(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    Wait(30)
    Call(ActorExists, ACTOR_RED_GOOMBA, LVar0)
    IfEq(LVar0, 1)
        Call(GetActorHP, ACTOR_RED_GOOMBA, LVar0)
    EndIf
    IfNe(LVar0, 0)
        Call(UseIdleAnimation, ACTOR_RED_GOOMBA, FALSE)
        Call(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_DISABLE)
        Call(ActorSpeak, MSG_CH0_00CF, ACTOR_RED_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Red_CryTalk, ANIM_GoombaBros_Red_CryTalk)
        Call(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_RED_GOOMBA, TRUE)
    EndIf
    Call(ActorExists, ACTOR_BLUE_GOOMBA, LVar0)
    IfEq(LVar0, 1)
        Call(GetActorHP, ACTOR_BLUE_GOOMBA, LVar0)
    EndIf
    IfNe(LVar0, 0)
        Call(UseIdleAnimation, ACTOR_BLUE_GOOMBA, FALSE)
        Call(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_DISABLE)
        Call(ActorSpeak, MSG_CH0_00D0, ACTOR_BLUE_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Blue_CryTalk, ANIM_GoombaBros_Blue_CryTalk)
        Call(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_BLUE_GOOMBA, TRUE)
    EndIf
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
