#include "../area.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/npc/TubbasHeart.h"
#include "sprite/player.h"

#define NAMESPACE A(tubbas_heart)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Move_Charge);
extern EvtScript N(EVS_Attack_Leap);
extern EvtScript N(EVS_Attack_DarkSwarm);
extern EvtScript N(EVS_FleeFromBattle);
extern EvtScript N(EVS_ReturnHome);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_NextMove           = 0,
    AVAL_NextMove_Charge    = 0,
    AVAL_NextMove_Swarm     = 1,
    AVAL_NextMove_Leap      = 2,
    AVAR_ChargeLevel        = 1,
    AVAR_Flags              = 2,
    AVAL_Flag_TauntBow      = 1,
    AVAL_Flag_HidStatusBar  = 2,
    AVAR_ChargeTaunt        = 3,
    AVAR_ChargedEffectID    = 4,
    AVAR_SwarmCount         = 5,
};

enum N(ActorParams) {
    DMG_LEAP        = 6,
    DMG_SWARM       = 12,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TubbasHeart_Anim01,
    STATUS_KEY_STONE,     ANIM_TubbasHeart_Anim00,
    STATUS_KEY_SLEEP,     ANIM_TubbasHeart_Anim04,
    STATUS_KEY_POISON,    ANIM_TubbasHeart_Anim01,
    STATUS_KEY_STOP,      ANIM_TubbasHeart_Anim00,
    STATUS_KEY_STATIC,    ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_FEAR,      ANIM_TubbasHeart_Anim0A,
    STATUS_END,
};

s32 N(ChargedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TubbasHeart_Anim0B,
    STATUS_KEY_STONE,     ANIM_TubbasHeart_Anim00,
    STATUS_KEY_SLEEP,     ANIM_TubbasHeart_Anim04,
    STATUS_KEY_POISON,    ANIM_TubbasHeart_Anim0B,
    STATUS_KEY_STOP,      ANIM_TubbasHeart_Anim00,
    STATUS_KEY_STATIC,    ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_KEY_FEAR,      ANIM_TubbasHeart_Anim0A,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,                0,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET,
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
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 54, 0 },
        .targetOffset = { 0, -30 },
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
    .type = ACTOR_TYPE_TUBBA_HEART,
    .level = ACTOR_LEVEL_TUBBA_HEART,
    .maxHP = 50,
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
    .size = { 30, 30 },
    .healthBarOffset = { 5, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Charge)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargeLevel, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Flags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_SwarmCount, 0)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetPartTargetFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_TARGET_NO_SMASH, true)
    Return
    End
};

API_CALLABLE(N(UpdateChargeEffectPos)) {
    Bytecode *args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    f32 scale = evt_get_float_variable(script, *args++);

    effect->data.energyInOut->pos.x = x;
    effect->data.energyInOut->pos.y = y;
    effect->data.energyInOut->pos.z = z;
    effect->data.energyInOut->scale = scale;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(ActorExists, ACTOR_SELF, LVar0)
        IfNe(LVar0, false)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, LVar0)
            IfNe(LVar0, 0)
                Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                Call(GetStatusFlags, ACTOR_SELF, LVar4)
                IfNotFlag(LVar4, STATUS_FLAG_SHRINK)
                    Add(LVar2, 15)
                    SetF(LVar4, Float(1.0))
                Else
                    Add(LVar2, 6)
                    SetF(LVar4, Float(0.4))
                EndIf
                Call(N(UpdateChargeEffectPos), LVar0, LVar1, LVar2, LVar3, LVar4)
            EndIf
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SelectAnimation) = {
    Set(LVar1, ANIM_TubbasHeart_Anim0E)
    Call(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
    IfNe(LVar0, 0)
        Set(LVar1, ANIM_TubbasHeart_Anim0B)
    EndIf
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            ExecWait(N(EVS_SelectAnimation))
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TubbasHeart_Anim10)
            SetConst(LVar2, ANIM_TubbasHeart_Anim11)
            ExecWait(EVS_Enemy_BurnHit)
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_SelectAnimation))
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseOrEq(EVENT_SHOCK_HIT)
        CaseOrEq(EVENT_SHOCK_DEATH)
            ExecWait(N(EVS_SelectAnimation))
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_ShockHit)
            ExecWait(N(EVS_SelectAnimation))
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Set(LVar1, ANIM_TubbasHeart_Anim01)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
            IfNe(LVar0, 0)
                Set(LVar1, ANIM_TubbasHeart_Anim0B)
            EndIf
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseOrEq(EVENT_DEATH)
            ExecWait(N(EVS_SelectAnimation))
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(N(EVS_SelectAnimation))
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIKE_CONTACT)
        CaseEq(EVENT_BURN_CONTACT)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TubbasHeart_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(GetActorHP, ACTOR_SELF, LVar0)
    IfLe(LVar0, 5)
        ExecWait(N(EVS_FleeFromBattle))
        Return
    Else
        Call(UseIdleAnimation, ACTOR_SELF, true)
    EndIf
    Return
    End
};

EvtScript N(EVS_FleeFromBattle) = {
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(ActorSpeak, MSG_CH3_00C6, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0D, ANIM_TubbasHeart_Anim0D)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 25)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, true)
    Call(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, true)
    Call(SetEndBattleFadeOutRate, 20)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 45)
    Set(LVar1, 0)
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 12, false, true, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim01)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfNe(LVar0, HIT_RESULT_MISS)
        Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
        IfNotFlag(LVar0, AVAL_Flag_TauntBow)
            Call(GetCurrentPartnerID, LVar0)
            IfEq(LVar0, PARTNER_BOW)
                Call(EnableBattleStatusBar, false)
                //@bug -- meant to OR 3 with value of AVAR_Flags, not PARTNER_BOW
                BitwiseOrConst(LVar0, AVAL_Flag_TauntBow | AVAL_Flag_HidStatusBar)
                Call(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
                Call(UseBattleCamPreset, BTL_CAM_ACTOR)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(MoveBattleCamOver, 40)
                Wait(40)
                Call(ActorSpeak, MSG_CH3_00C3, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01)
                Call(UseBattleCamPreset, BTL_CAM_ACTOR)
                Call(BattleCamTargetActor, ACTOR_PARTNER)
                Call(MoveBattleCamOver, 25)
                Wait(25)
                Call(UseIdleAnimation, ACTOR_PARTNER, false)
                Call(SetAnimation, ACTOR_PARTNER, 1, ANIM_BattleBow_Talk)
                Call(ActorSpeak, MSG_CH3_00C4, ACTOR_PARTNER, 1, ANIM_BattleBow_Talk, ANIM_BattleBow_Idle)
                Call(SetAnimation, ACTOR_PARTNER, 1, ANIM_BattleBow_Laugh)
                Call(EndActorSpeech, ACTOR_PARTNER, 1, -1, -1)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(UseIdleAnimation, ACTOR_PARTNER, true)
                Call(MoveBattleCamOver, 30)
                Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
                IfEq(LVar0, AVAL_NextMove_Charge)
                    Call(GetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, LVar0)
                    IfTrue(LVar0)
                        Call(EnableBattleStatusBar, true)
                    EndIf
                Else
                    Call(EnableBattleStatusBar, true)
                EndIf
            EndIf
        EndIf
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_NextMove_Charge)
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, LVar0)
            IfEq(LVar0, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_ChargeTaunt, true)
                Call(UseBattleCamPreset, BTL_CAM_ACTOR)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(MoveBattleCamOver, 40)
                Wait(40)
                Call(ActorSpeak, MSG_CH3_00C5, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01)
            EndIf
            ExecWait(N(EVS_Move_Charge))
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Swarm)
            Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
            IfFlag(LVar0, AVAL_Flag_HidStatusBar)
                Call(EnableBattleStatusBar, true)
            EndIf
        CaseEq(AVAL_NextMove_Swarm)
            ExecWait(N(EVS_Attack_DarkSwarm))
            Call(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
            IfEq(LVar0, 0)
                Call(GetActorVar, ACTOR_SELF, AVAR_SwarmCount, LVar1)
                Add(LVar1, 1)
                Call(SetActorVar, ACTOR_SELF, AVAR_SwarmCount, LVar1)
                IfGe(LVar1, 2)
                    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Leap)
                Else
                    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Charge)
                EndIf
            EndIf
        CaseEq(AVAL_NextMove_Leap)
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_NextMove_Charge)
            ExecWait(N(EVS_Attack_Leap))
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AVAL_Flag_HidStatusBar)
    Call(SetActorVar, ACTOR_SELF, AVAR_Flags, LVar0)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_Leap) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 45)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 12, false, true, false)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Set(LVar1, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim01)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim16)
    Wait(5)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim15)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseDefault
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
            Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
    EndSwitch
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim01)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Wait(1)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Add(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
            Wait(8)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim03)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Move_Charge) = {
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, 85, 50, 0)
    Call(SetBattleCamDist, 280)
    Call(SetBattleCamOffsetY, 0)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar4)
    IfNotFlag(LVar4, STATUS_FLAG_SHRINK)
        Add(LVar1, 15)
        SetF(LVar3, Float(1.0))
    Else
        Add(LVar1, 6)
        SetF(LVar3, Float(0.4))
    EndIf
    PlayEffect(EFFECT_GATHER_MAGIC, 1, LVar0, LVar1, LVar2, LVar3, 60, 0)
    PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, LVar3, 60, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TUBBAS_HEART_CHARGE)
    Wait(60)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargeLevel, 1)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar4)
    IfNotFlag(LVar4, STATUS_FLAG_SHRINK)
        Add(LVar1, 15)
        SetF(LVar3, Float(1.0))
    Else
        Add(LVar1, 6)
        SetF(LVar3, Float(0.4))
    EndIf
    PlayEffect(EFFECT_ENERGY_IN_OUT, 3, LVar0, LVar1, LVar2, LVar3, 0, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, LVarF)
    Call(EnableActorGlow, ACTOR_SELF, true)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ChargedAnims)))
    Return
    End
};

EvtScript N(EVS_Attack_DarkSwarm) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, 85, 50, 0)
    Call(SetBattleCamDist, 280)
    Call(SetBattleCamOffsetY, 0)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0C)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 16)
    Else
        Add(LVar1, 6)
    EndIf
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
    Wait(60)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TubbasHeart_Anim0B)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 18, false, true, false)
    EndThread
    Call(GetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
    Sub(LVar0, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_ChargeLevel, LVar0)
    IfEq(LVar0, 0)
        Call(EnableActorGlow, ACTOR_SELF, false)
        Call(GetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, LVar0)
        Call(RemoveEffect, LVar0)
        Call(SetActorVar, ACTOR_SELF, AVAR_ChargedEffectID, 0)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
    EndIf
    Call(PlaySound, SOUND_TUBBAS_HEART_SWARM_ATTACK)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Add(LVar1, 5)
            PlayEffect(EFFECT_TUBBA_HEART_ATTACK, FX_HEART_SWARM_MISS, LVar0, LVar1, LVar2, Float(1.0), 200, 0)
            Wait(145)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            Else
            EndIf
            Return
        EndCaseGroup
    EndSwitch
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 5)
    PlayEffect(EFFECT_TUBBA_HEART_ATTACK, FX_HEART_SWARM_HIT, LVar0, LVar1, LVar2, Float(1.0), 200, 0)
    Thread
        Wait(160)
        Call(PlaySound, SOUND_TUBBAS_HEART_SWARM_VANISH)
    EndThread
    Call(UseIdleAnimation, ACTOR_PLAYER, false)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 300)
    Call(SetBattleCamOffsetY, 35)
    Call(MoveBattleCamOver, 50)
    Wait(56)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SQUEEZE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
    Wait(37)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_SQUEEZE)
    Wait(22)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TUBBAS_HEART_SWARM_DISPERSE)
    Call(UseIdleAnimation, ACTOR_PLAYER, true)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_TRIGGER_EVENTS)
    Return
    End
};
