#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Bandit.h"

#define NAMESPACE A(bandit)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_Init_Coin);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

BSS s32 N(DropCoinScript)[1];

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_COIN            = 2,
};

enum N(ActorVars) {
    AVAR_HasCoin        = 0, // has stolen coins
    AVAR_NumCoins       = 1, // number of coins stolen
    AVAR_Coin_NumCoins  = 1, // number of coins stolen also stored in coin actor
};

enum N(ActorParams) {
    DMG_TACKLE          = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bandit_Idle,
    STATUS_KEY_STONE,     ANIM_Bandit_Still,
    STATUS_KEY_SLEEP,     ANIM_Bandit_Sleep,
    STATUS_KEY_POISON,    ANIM_Bandit_Idle,
    STATUS_KEY_STOP,      ANIM_Bandit_Still,
    STATUS_KEY_STATIC,    ANIM_Bandit_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Bandit_Still,
    STATUS_KEY_DIZZY,     ANIM_Bandit_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Bandit_Dizzy,
    STATUS_END,
};

s32 N(HoldingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bandit_IdleHolding,
    STATUS_KEY_STONE,     ANIM_Bandit_StillHolding,
    STATUS_KEY_SLEEP,     ANIM_Bandit_Sleep,
    STATUS_KEY_POISON,    ANIM_Bandit_IdleHolding,
    STATUS_KEY_STOP,      ANIM_Bandit_StillHolding,
    STATUS_KEY_STATIC,    ANIM_Bandit_IdleHolding,
    STATUS_KEY_PARALYZE,  ANIM_Bandit_StillHolding,
    STATUS_KEY_DIZZY,     ANIM_Bandit_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Bandit_Dizzy,
    STATUS_END,
};

s32 N(CoinAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bandit_Coin,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             20,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,               50,
    STATUS_KEY_STATIC,             30,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
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
        .targetOffset = { -2, 28 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_COIN,
        .posOffset = { 0, 30, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorPartBlueprint N(CoinParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_COIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BANDIT,
    .level = ACTOR_LEVEL_BANDIT,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 26, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 25 },
    .statusTextOffset = { 10, 25 },
};

ActorBlueprint N(coin) = {
    .flags = ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY,
    .type = ACTOR_TYPE_BANDIT,
    .level = ACTOR_LEVEL_BANDIT,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(CoinParts)),
    .partsData = N(CoinParts),
    .initScript = &N(EVS_Init_Coin),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 26, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 25 },
    .statusTextOffset = { 10, 25 },
};

Vec3i N(CoinPos) = { NPC_DISPOSE_LOCATION };

Formation N(CoinFormation) = {
    ACTOR_BY_POS(N(coin), N(CoinPos), 0),
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_HasCoin, 0)
    Return
    End
};

EvtScript N(EVS_Dummy) = {
    Return
    End
};

EvtScript N(EVS_Init_Coin) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Dummy)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Dummy)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Dummy)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_DropCoin) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_HasCoin, LVar0)
    Switch(LVar0)
        CaseEq(false)
            // do nothing
        CaseEq(true)
            Call(SetActorVar, ACTOR_SELF, AVAR_HasCoin, false)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
            Call(SummonEnemy, Ref(N(CoinFormation)), false)
            Set(LVarA, LVar0)
            Call(GetPartOffset, ACTOR_SELF, PRT_COIN, LVar1, LVar2, LVar3)
            Call(SetActorPos, LVarA, LVar1, LVar2, LVar3)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(GetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
            Call(SetActorVar, LVarA, AVAR_Coin_NumCoins, LVar0)
            Call(SetActorJumpGravity, LVarA, Float(1.0))
            Call(RandInt, 360, LVar0)
            Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            Add(LVar2, 30)
            Call(SetActorPos, LVarA, LVar1, LVar2, LVar3)
            Call(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(AddVectorPolar, LVar1, LVar3, Float(40.0), LVar0)
            Call(SetGoalPos, LVarA, LVar1, 0, LVar3)
            Call(JumpToGoal, LVarA, 20, false, true, false)
            Call(PlaySoundAtActor, LVarA, SOUND_COIN_BOUNCE)
            Call(AddVectorPolar, LVar1, LVar3, Float(20.0), LVar0)
            Call(SetGoalPos, LVarA, LVar1, 0, LVar3)
            Call(JumpToGoal, LVarA, 10, false, true, false)
            Call(PlaySoundAtActor, LVarA, SOUND_COIN_BOUNCE)
            Call(AddVectorPolar, LVar1, LVar3, Float(10.0), LVar0)
            Call(SetGoalPos, LVarA, LVar1, 0, LVar3)
            Call(JumpToGoal, LVarA, 5, false, true, false)
            Call(PlaySoundAtActor, LVarA, SOUND_COIN_BOUNCE)
            Loop(0)
                Call(GetBattleFlags, LVar1)
                IfFlag(LVar1, BS_FLAGS1_PARTNER_ACTING)
                    BreakLoop
                EndIf
                IfNotFlag(LVar1, BS_FLAGS1_EXECUTING_MOVE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Wait(15)
            Call(SetActorJumpGravity, LVarA, Float(1.0))
            Call(SetActorSpeed, LVarA, Float(6.0))
            Set(LVar0, -70)
            Set(LVar1, 0)
            Set(LVar2, 10)
            Label(5)
            Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            IfEq(LVar3, LVar0)
                Goto(10)
            EndIf
            IfLt(LVar3, LVar0)
                Set(LVar4, LVar0)
                Sub(LVar4, LVar3)
                IfLt(LVar4, 30)
                    Call(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
                    Call(JumpToGoal, LVarA, 5, false, true, false)
                    Call(PlaySoundAtActor, LVarA, SOUND_COIN_BOUNCE)
                Else
                    Set(LVar4, LVar3)
                    Add(LVar3, 30)
                    Call(SetGoalPos, LVarA, LVar3, LVar1, LVar2)
                    Call(JumpToGoal, LVarA, 0, false, true, false)
                    Call(PlaySoundAtActor, LVarA, SOUND_COIN_BOUNCE)
                EndIf
            Else
                Set(LVar4, LVar3)
                Sub(LVar4, LVar0)
                IfLt(LVar4, 30)
                    Call(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
                    Call(JumpToGoal, LVarA, 5, false, true, false)
                    Call(PlaySoundAtActor, LVarA, SOUND_COIN_BOUNCE)
                Else
                    Sub(LVar3, 30)
                    Call(SetGoalPos, LVarA, LVar3, LVar1, LVar2)
                    Call(JumpToGoal, LVarA, 0, false, true, false)
                    Call(PlaySoundAtActor, LVarA, SOUND_COIN_BOUNCE)
                EndIf
            EndIf
            Goto(5)
            Label(10)
            Call(EnableActorBlur, LVarA, ACTOR_BLUR_ENABLE)
            Call(SetTargetActor, LVarA, ACTOR_PLAYER)
            Call(SetGoalToTarget, LVarA)
            Call(JumpToGoal, LVarA, 15, false, false, false)
            Call(GetGoalPos, LVarA, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SMALL_GOLD_SPARKLE, 0, LVar0, LVar1, LVar2, Float(1.0), 0, 0)
            Call(PlaySoundAtActor, LVarA, SOUND_COIN_PICKUP)
            Call(GetActorVar, LVarA, AVAR_Coin_NumCoins, LVar0)
            Call(AddCoin, LVar0)
            Call(RemoveActor, LVarA)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    UseArray(Ref(N(DropCoinScript)))
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_SPIN_SMASH_LAUNCH_HIT)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_BurnHurt)
            SetConst(LVar2, ANIM_Bandit_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        CaseEq(EVENT_BURN_DEATH)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_BurnHurt)
            SetConst(LVar2, ANIM_Bandit_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_Death)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_HasCoin, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar1, ANIM_Bandit_Idle)
                CaseEq(1)
                    SetConst(LVar1, ANIM_Bandit_IdleHolding)
            EndSwitch
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseOrEq(EVENT_DEATH)
        CaseOrEq(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_Death)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Return
        EndCaseGroup
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Run)
            SetConst(LVar2, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            ExecGetTID(N(EVS_DropCoin), ArrayVar(0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            ExecWait(EVS_Enemy_AirLift)
            Loop(0)
                IsThreadRunning(ArrayVar(0), LVar0)
                IfEq(LVar0, 0)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Bandit_Hurt)
            SetConst(LVar2, STATUS_FLAG_DIZZY)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    // if carrying a coin, run away
    Call(GetActorVar, ACTOR_SELF, AVAR_HasCoin, LVar0)
    IfEq(LVar0, 1)
        Call(SetActorYaw, ACTOR_SELF, 180)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_RunHolding)
        Wait(30)
        Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
        Call(SetGoalPos, ACTOR_SELF, 300, 0, 0)
        Call(RunToGoal, ACTOR_SELF, 0, false)
        Call(SetBattleFlagBits, BS_FLAGS1_BATTLE_FLED, true)
        Call(HideHealthBar, ACTOR_SELF)
        Call(RemoveActor, ACTOR_SELF)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 50)
        Set(LVar1, 0)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
        Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
        Call(RunToGoal, ACTOR_SELF, 0, false)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
        Wait(6)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Walk)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 35, 0, 0)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BANDIT_STEAL)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Tackle)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Wait(5)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(5)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Tackle)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            // dont steal coins if no damage, blocked
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfLe(LVar0, 0)
                Set(LVar0, 1)
                Goto(10)
            EndIf
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Set(LVar0, 1)
                Goto(10)
            EndIf
            // cant steal coins if shrunk
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                Set(LVar0, 0)
                Goto(10)
            EndIf
             // cant steal coins if player is stone
            Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
            IfFlag(LVar0, STATUS_FLAG_STONE)
                Set(LVar0, 0)
                Goto(10)
            EndIf
            Call(AddCoin, 0)
            // choose outcome based on stolen coin count
            Switch(LVar0)
                CaseEq(0)
                    Set(LVar0, 1)
                CaseLt(10)
                    Call(SetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
                    Set(LVar0, 2)
                CaseGe(10)
                    // cap num stolen to 10
                    Call(SetActorVar, ACTOR_SELF, AVAR_NumCoins, 10)
                    Set(LVar0, 2)
            EndSwitch
            Label(10)
            Switch(LVar0)
                CaseEq(0)
                    // couldn't steal (from shrunk or player stone)
                    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Add(LVar0, 30)
                    Set(LVar1, 0)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
                    Wait(20)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
                CaseEq(1)
                    // failed to steal (player blocked or damage negated)
                    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Add(LVar0, 30)
                    Set(LVar1, 0)
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_LookUp)
                    Wait(20)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISAPPOINTED)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Sleep)
                    Wait(20)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
                CaseDefault
                    // stole coins
                    Call(SetGoalToTarget, ACTOR_SELF)
                    Call(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
                    Add(LVarA, 30)
                    Set(LVarB, 0)
                    Call(GetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
                    Mul(LVar0, -1)
                    Call(AddCoin, LVar0)
                    Thread
                        Call(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, true)
                        Call(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_INVISIBLE, false)
                        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                        Call(SetPartPos, ACTOR_SELF, PRT_COIN, LVar0, LVar1, LVar2)
                        Call(SetPartJumpGravity, ACTOR_SELF, PRT_COIN, Float(1.0))
                        Add(LVarB, 30)
                        Call(JumpPartTo, ACTOR_SELF, PRT_COIN, LVarA, LVarB, LVarC, 22, true)
                        Call(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
                    EndThread
                    Thread
                        Call(GetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
                        Loop(LVar0)
                            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_COIN_BOUNCE)
                            Wait(1)
                        EndLoop
                    EndThread
                    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
                    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
                    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HoldingAnims)))
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_LookUp)
                    Call(SetActorVar, ACTOR_SELF, AVAR_HasCoin, 1)
                    Wait(7)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_GotCoin)
                    Wait(20)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_RunHolding)
            EndSwitch
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};
