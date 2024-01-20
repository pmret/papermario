#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/ParaJrTroopa.h"

#define NAMESPACE A(para_jr_troopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_JrTroopa_Death);
extern EvtScript N(EVS_JrTroopa_FlyHome);
extern EvtScript N(EVS_TryFearReaction);

enum N(ActorPartIDs) {
    PRT_GROUND      = 1,
    PRT_FLYING      = 2,
};

enum N(ActorVars) {
    AVAR_Transformed        = 0,
    AVAR_SpookReact         = 1,
    AVAL_SpookReact_None    = 0,
    AVAL_SpookReact_Ready   = 1,
};

enum N(ActorParams) {
    DMG_DIVE        = 5,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ParaJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_ParaJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_ParaJrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_ParaJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_ParaJrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_ParaJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_ParaJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_ParaJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(BaseAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 35 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -6 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(BaseAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_JR_TROOPA_3,
    .level = ACTOR_LEVEL_JR_TROOPA_3,
    .maxHP = 40,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 60, 35 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 35 },
    .statusTextOffset = { 10, 25 },
};

EvtScript N(EVS_SetupFearReaction) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar2)
    IfFlag(LVar2, STATUS_FLAGS_IMMOBILIZED)
        Return
    EndIf
    Call(GetBattleFlags, LVar2)
    IfFlag(LVar2, BS_FLAGS1_PARTNER_ACTING)
        Call(GetMenuSelection, LVar0, LVar1, LVar2)
        IfEq(LVar2, MOVE_SPOOK)
            Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_Ready)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMOTE_QUESTION)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 30)
            Call(ShowEmote, 0, EMOTE_QUESTION, -45, 30, EMOTER_POS, LVar0, LVar1, LVar2, 5)
            Wait(30)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Transform) = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 16)
    Else
        Add(LVar1, 6)
    EndIf
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
    Thread
        Set(LVar0, 0)
        Loop(32)
            Wait(1)
            Add(LVar0, 45)
            Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EndLoop
    EndThread
    Wait(32)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_NEW_POWER)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 40, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 4, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 4, 0)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnJrTroopa) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_07)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamOffsetZ, 38)
    Call(SetBattleCamZoom, 256)
    Call(MoveBattleCamOver, 15)
    Return
    End
};

EvtScript N(EVS_Cam_ResetFocus) = {
    Call(EnableBattleStatusBar, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 12)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnGoompa) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_55)
    Call(MoveBattleCamOver, 30)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Transformed, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
            Call(SetTargetOffset, ACTOR_SELF, PRT_GROUND, -12, 28)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, 4, -6)
            Call(N(SetAbsoluteStatusOffsets), -25, 27, -1, 27)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_GROUND, -5, 33)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, 0, -6)
            Call(N(SetAbsoluteStatusOffsets), -22, 30, 2, 28)
        EndIf
        Wait(1)
        Goto(0)
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
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_SetupFearReaction))
            ExecWait(N(EVS_TryFearReaction))
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, PRT_GROUND)
            Set(LVar1, ANIM_ParaJrTroopa_BurnHurt)
            Set(LVar2, ANIM_ParaJrTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, PRT_GROUND)
            Set(LVar1, ANIM_ParaJrTroopa_BurnHurt)
            Set(LVar2, ANIM_ParaJrTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_BurnStill)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_JrTroopa_FlyHome))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Idle)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
            ExecWait(N(EVS_SetupFearReaction))
            ExecWait(N(EVS_TryFearReaction))
        CaseEq(EVENT_SPIKE_CONTACT)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Hurt)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Flail)
                Wait(1000)
            EndIf
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                SetConst(LVar0, PRT_GROUND)
                SetConst(LVar1, ANIM_ParaJrTroopa_Flail)
                ExecWait(EVS_Enemy_NoDamageHit)
                ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                Call(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Talk, ANIM_ParaJrTroopa_Talk)
                ExecWait(N(EVS_Cam_ResetFocus))
            EndIf
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ParaJrTroopa_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Overshoot_Unused) = {
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Add(LVar0, 30)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    Sub(LVar0, 10)
    Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
    Wait(8)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 5, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Sub(LVar0, 80)
            Set(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Dive)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Return
        EndCaseGroup
        CaseDefault
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Dive)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EndSwitch
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            Wait(10)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVarF)
    Switch(LVarF)
        CaseEq(PHASE_PLAYER_BEGIN)
            // trying showing the scene where Jr Troopa transforms
            Call(GetActorVar, ACTOR_SELF, AVAR_Transformed, LVar0)
            IfFalse(LVar0)
                Call(SetActorVar, ACTOR_SELF, AVAR_Transformed, TRUE)
                Wait(15)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(SetBattleCamOffsetZ, 35)
                Call(MoveBattleCamOver, 30)
                Wait(30)
                Call(ActorSpeak, MSG_CH3_0020, ACTOR_SELF, PRT_FLYING, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot)
                Wait(8)
                ExecWait(N(EVS_Transform))
                Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                Wait(30)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, 20)
                Call(SetGoalPos, ACTOR_SELF, LVar0, 60, LVar2)
                Call(FlyToGoal, ACTOR_SELF, 45, 0, EASING_LINEAR)
                Call(ForceHomePos, ACTOR_SELF, LVar0, 60, LVar2)
                Call(HPBarToHome, ACTOR_SELF)
                Wait(8)
                Call(ActorSpeak, MSG_CH3_0021, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Talk, ANIM_ParaJrTroopa_Idle)
                Wait(10)
                ExecWait(N(EVS_Cam_ResetFocus))
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_JrTroopa_Death) = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    IfEq(LVar1, 0)
        Goto(0)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(FallToGoal, ACTOR_SELF, 10)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Call(HPBarToCurrent, ACTOR_SELF)
    Call(ShowHealthBar, ACTOR_SELF)
    Label(0)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        Add(LVar2, 10)
        Loop(3)
            PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            Wait(3)
        EndLoop
    EndThread
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_JrTroopa_DefeatedBegin)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 5)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(SetBattleCamZoom, 260)
    Call(SetBattleCamOffsetZ, 15)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_JrTroopa_Defeated)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(DefeatedAnims)))
    Wait(60)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Return
    End
};

EvtScript N(EVS_JrTroopa_FlyHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar4, LVar1)
    MulF(LVar4, Float(0.3))
    Call(FlyToGoal, ACTOR_SELF, 0, LVar4, EASING_LINEAR)
    Return
    End
};

EvtScript N(EVS_TryFearReaction) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Call(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
        IfEq(LVar0, AVAL_SpookReact_Ready)
            Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
            Wait(15)
            ExecWait(N(EVS_Cam_FocusOnJrTroopa))
            Wait(10)
            Call(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Talk, ANIM_ParaJrTroopa_Idle)
            Wait(10)
            ExecWait(N(EVS_Cam_ResetFocus))
        EndIf
    EndIf
    Return
    End
};
