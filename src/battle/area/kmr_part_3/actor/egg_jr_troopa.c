#include "../area.h"
#include "sprite/npc/JrTroopa.h"

#define NAMESPACE A(egg_jr_troopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_SetupHitReaction);
extern EvtScript N(EVS_TryHitReaction);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_ShowedNewPower     = 0,
    AVAR_HitReact_State     = 1,
    AVAL_HitReact_None      = 0,
    AVAL_HitReact_Ready     = 1,
    AVAL_HitReact_Done      = 2,
};

enum N(ActorParams) {
    DMG_LEAP        = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_END,
};

s32 N(UnusedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Still,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_END,
};

s32 N(EggAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_EggIdle,
    STATUS_KEY_STOP,      ANIM_JrTroopa_EggStill,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
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
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -6, 18 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 5, -4 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA_2,
    .level = ACTOR_LEVEL_JR_TROOPA_2,
    .maxHP = 15,
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
    .size = { 32, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 30 },
    .statusTextOffset = { 10, 20 },
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

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

EvtScript N(EVS_JrTroopa_Death) = {
    Set(LVarA, LVar0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, LVarA, LVar1)
    Wait(10)
    Call(GetDamageSource, LVar5)
    Switch(LVar5)
        CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_SPIN_SMASH)
        EndCaseGroup
        CaseDefault
            Set(LVar2, 0)
            Loop(24)
                Call(SetActorYaw, ACTOR_SELF, LVar2)
                Add(LVar2, 30)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_SELF, 0)
    EndSwitch
    Label(0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Add(LVar2, 10)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Call(PlaySound, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(SetBattleCamZoom, 260)
    Call(SetBattleCamOffsetZ, 15)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    Call(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Collapse)
    Wait(12)
    Call(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Defeated)
    Call(SetIdleAnimations, ACTOR_SELF, LVarA, Ref(N(DefeatedAnims)))
    Wait(60)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Return
    End
};

EvtScript N(EVS_ReenterEgg) = {
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLOSE_SHELL)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Add(LVar2, 5)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_EnterEgg)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(EggAnims)))
    Wait(10)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_ShowedNewPower, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_None)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
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
        CaseEq(EVENT_HIT_COMBO)
            ExecWait(N(EVS_SetupHitReaction))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            ExecWait(N(EVS_SetupHitReaction))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_TryHitReaction))
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Panic)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_JrTroopa_BurnHurt)
            Set(LVar2, ANIM_JrTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_JrTroopa_BurnHurt)
            Set(LVar2, ANIM_JrTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_BurnStill)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_SetupHitReaction))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_TryHitReaction))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Panic)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            ExecWait(N(EVS_ReenterEgg))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Panic)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_EggIdle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_JrTroopa_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_SetupHitReaction) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_HitReact_State, LVar0)
    IfEq(LVar0, AVAL_HitReact_None)
        Call(GetLastDamage, ACTOR_SELF, LVar1)
        Call(GetBattleFlags, LVar2)
        IfNotFlag(LVar2, BS_FLAGS1_PARTNER_ACTING)
            IfNe(LVar1, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Ready)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAGS_DOJO)
                    Call(FreezeBattleCam, TRUE)
                EndIf
            EndIf
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_TryHitReaction) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_HitReact_State, LVar0)
    IfEq(LVar0, AVAL_HitReact_Ready)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAGS_DOJO)
            Call(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Done)
            ExecWait(N(EVS_Cam_FocusOnJrTroopa))
            Call(MoveBattleCamOver, 30)
            Wait(30)
            Call(ActorSpeak, MSG_CH1_012A, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Dizzy, ANIM_JrTroopa_Dizzy)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_PointTalk)
            Call(EndActorSpeech, ACTOR_SELF, PRT_MAIN, -1, -1)
            ExecWait(N(EVS_ReenterEgg))
            ExecWait(N(EVS_Cam_ResetFocus))
        Else
            Call(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_None)
        EndIf
    EndIf
    Call(FreezeBattleCam, FALSE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
    Wait(20)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Jump)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_LUCKY)
        CaseOrEq(HIT_RESULT_MISS)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Midair)
            Thread
                Wait(8)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Fall)
            EndThread
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Add(LVar2, 5)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(2)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 25)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_ChargeArmsUp)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            ExecWait(N(EVS_ReenterEgg))
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
    Thread
        Wait(3)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Midair)
        Wait(5)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Fall)
    EndThread
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseDefault
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            Wait(10)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            ExecWait(N(EVS_ReenterEgg))
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
            Call(GetActorVar, ACTOR_SELF, AVAR_ShowedNewPower, LVar0)
            IfFalse(LVar0)
                Call(SetActorVar, ACTOR_SELF, AVAR_ShowedNewPower, TRUE)
                Wait(15)
                ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                Wait(10)
                Call(ActorSpeak, MSG_CH1_0128, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_ChargeArmsUp)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 16)
                PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
                PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
                Wait(30)
                ExecWait(N(EVS_ReenterEgg))
                Wait(30)
                Call(ActorSpeak, MSG_CH1_0129, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_EggTalk, ANIM_JrTroopa_EggIdle)
                Wait(10)
                ExecWait(N(EVS_Cam_ResetFocus))
            Else
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
