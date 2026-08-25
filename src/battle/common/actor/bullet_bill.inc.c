#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BulletBill.h"

#define NAMESPACE A(bullet_bill)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_MakeExplosionFX);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_FiredFromBlaster   = 0,
    AVAR_BlasterID          = 1, // actorID of Bill Blaster that fired this Bullet Bill
};

enum N(ActorParams) {
    DMG_IMPACT      = 2,
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
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_UNUSED,         0,
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
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FIRE_EXPLODE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -6 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BULLET_BILL,
    .level = ACTOR_LEVEL_BULLET_BILL,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 100,
    .hurricaneChance = 100,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 0,
    .size = { 28, 22 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BulletBill_Idle,
    STATUS_KEY_STONE,     ANIM_BulletBill_Still,
    STATUS_KEY_STOP,      ANIM_BulletBill_Still,
    STATUS_KEY_PARALYZE,  ANIM_BulletBill_Still,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(GetActorVar, ACTOR_SELF, AVAR_FiredFromBlaster, LVar0)
    IfFalse(LVar0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 16)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(HPBarToHome, ACTOR_SELF)
    Else
        Call(GetActorVar, ACTOR_SELF, AVAR_BlasterID, LVar0)
        Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
        Call(GetStatusFlags, LVar0, LVar4)
        IfFlag(LVar4, STATUS_FLAG_SHRINK)
            Set(LVar5, -13)
            Set(LVar6, 4)
        Else
            Set(LVar5, -33)
            Set(LVar6, 11)
        EndIf
        Add(LVar1, LVar5)
        Add(LVar2, LVar6)
        Call(SetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(CopyStatusEffects, LVar0, ACTOR_SELF)
        Call(CopyBuffs, LVar0, ACTOR_SELF)
        Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(GetActorPos, LVar0, LVar1, LVarB, LVarC)
        Sub(LVar1, 90)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BulletBill_Tense)
        Call(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BulletBill_Idle)
        Call(ForceHomePos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(HPBarToHome, ACTOR_SELF)
    EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_Explode) = {
    ExecWait(N(EVS_MakeExplosionFX))
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BulletBill_BurnHurt)
    Set(LVar2, EXEC_DEATH_NO_SPINNING)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_BURN_HIT)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_BURN_DEATH)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            ExecWait(N(EVS_Explode))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_EXPLODE_TRIGGER)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_Explode))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Tense)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BulletBill_Tense)
            ExecWait(EVS_Enemy_BlowAway)
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
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BulletBill_Fire)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(15)
    Call(UseBattleCamPresetImmediately, BTL_CAM_REPOSITION)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar3, LVar1)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Set(LVar1, LVar3)
            Sub(LVar0, 90)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 18, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(HideHealthBar, ACTOR_SELF)
            Call(UseIdleAnimation, ACTOR_SELF, false)
            Call(RemoveActor, ACTOR_SELF)
            Return
        EndCaseGroup
    EndSwitch
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar3, LVar1)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar1, LVar3)
    Add(LVar0, 10)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 12, false, true, false)
    ExecWait(N(EVS_MakeExplosionFX))
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_IMPACT, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(YieldTurn)
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BulletBill_BurnHurt)
    Set(LVar2, EXEC_DEATH_NO_SPINNING)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

EvtScript N(EVS_MakeExplosionFX) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, 2)
    PlayEffect(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2, 0)
    Add(LVar1, 16)
    Add(LVar2, 2)
    PlayEffect(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, Float(3.0), 30, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BULLET_BILL_EXPLODE_A)
    Call(StartRumble, BTL_RUMBLE_PLAYER_MAX)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    EndThread
    Return
    End
};
