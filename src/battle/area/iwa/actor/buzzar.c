#include "../area.h"
#include "sprite/npc/Buzzar.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"
#include "sprite/player.h"

#define NAMESPACE A(buzzar)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Attack_WindBlast);
extern EvtScript N(EVS_Attack_FeatherFling);
extern EvtScript N(EVS_Attack_GrappleDrop);
extern EvtScript N(EVS_Attack_ClawSwipe);
extern EvtScript N(EVS_FlyToHome);
extern EvtScript N(EVS_FlyToHome_GrappleFail);
extern EvtScript N(EVS_FlyToHome_Impl);
extern EvtScript N(EVS_FlyToHome_GrappleFail_Impl);
extern EvtScript N(EVS_DummyHit);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
    PRT_FEATHER_1   = 3,
    PRT_FEATHER_2   = 4,
    PRT_FEATHER_3   = 5,
};

enum N(ActorVars) {
    AVAR_NextMove               = 0,
    AVAL_Move_WindBlast         = 0,
    AVAL_Move_GrappleThenSwipe  = 1,
    AVAL_Move_ClawSwipe         = 2,
    AVAL_Move_GrappleThenFling  = 3,
    AVAL_Move_FlingFeather      = 4,
    AVAL_Move_GrappleThenWind   = 5,
    AVAR_Unused_1               = 1,
    AVAR_Unused_2               = 2,
    AVAR_Unused_3               = 3,
};

enum N(ActorParams) {
    DMG_FEATHER     = 2,
    DMG_SWIPE       = 3,
    DMG_DROP        = 4,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Buzzar_Anim01,
    STATUS_KEY_STONE,     ANIM_Buzzar_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Buzzar_Anim19,
    STATUS_KEY_STOP,      ANIM_Buzzar_Anim00,
    STATUS_KEY_STATIC,    ANIM_Buzzar_Anim0C,
    STATUS_KEY_PARALYZE,  ANIM_Buzzar_Anim0C,
    STATUS_KEY_DIZZY,     ANIM_Buzzar_Anim0C,
    STATUS_KEY_SHRINK,    ANIM_Buzzar_Anim01,
    STATUS_END,
};

s32 N(FeatherAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Buzzar_Anim14,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              70,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           70,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               70,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -20, 60 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 31, 0 },
        .targetOffset = { -14, 20 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -14 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FEATHER_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(FeatherAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FEATHER_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(FeatherAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FEATHER_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(FeatherAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BUZZAR,
    .level = ACTOR_LEVEL_BUZZAR,
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
    .spinSmashReq = 4,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 78, 74 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -35, 65 },
    .statusTextOffset = { 1, 58 },
};

EvtScript N(EVS_Init) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_1, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_WindBlast)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_2, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused_3, 0)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 40)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_DummyHit))
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_ShockHit)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_WindBlast)
            ExecWait(N(EVS_FlyToHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Buzzar_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_ClawSwipe)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Move_WindBlast)
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_GrappleThenSwipe)
            ExecWait(N(EVS_Attack_WindBlast))
        CaseEq(AVAL_Move_ClawSwipe)
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_GrappleThenFling)
            ExecWait(N(EVS_Attack_ClawSwipe))
        CaseEq(AVAL_Move_FlingFeather)
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_GrappleThenWind)
            ExecWait(N(EVS_Attack_FeatherFling))
        CaseDefault
            Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
            IfEq(LVar0, AVAL_Move_GrappleThenWind)
                Set(LVar0, AVAL_Move_WindBlast)
            Else
                Add(LVar0, 1)
            EndIf
            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
            ExecWait(N(EVS_Attack_GrappleDrop))
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Attack_WindBlast) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
    Call(SetBattleCamZoom, 180)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 120)
    Call(SetActorSpeed, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 70, LVar2)
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Buzzar_Anim01)
        CaseOrEq(ANIM_Buzzar_Anim02)
        CaseOrEq(ANIM_Buzzar_Anim0D)
        CaseOrEq(ANIM_Buzzar_Anim16)
        CaseOrEq(ANIM_Buzzar_Anim17)
            Loop(0)
                Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_COS_IN_OUT)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarA)
        CaseEq(HIT_RESULT_MISS)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
            Switch(LVarA)
                CaseEq(HIT_RESULT_MISS)
                    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    Wait(8)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim11)
                    Wait(15)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim13)
                    Wait(6)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WHIRLWIND)
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(MoveBattleCamOver, 50)
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 90, Float(0.5))
                    EndThread
                    Call(N(StartRumbleWithParams), 70, 100)
                    Thread
                        Loop(20)
                            Call(SetGoalToTarget, ACTOR_SELF)
                            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Add(LVar0, 10)
                            PlayEffect(EFFECT_WINDY_LEAVES, 2, LVar0, 10, LVar2, 0)
                            Wait(3)
                        EndLoop
                    EndThread
                    Wait(60)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
                    IfEq(LVarA, HIT_RESULT_LUCKY)
                        Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EndIf
                    Wait(25)
                    ExecWait(N(EVS_FlyToHome))
                    Return
                CaseDefault
                    Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    Call(ShowMessageBox, BTL_MSG_ACTION_TIP_REDUCE_DAMAGE, 90)
                    Call(ShowActionHud, TRUE)
                    Call(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
                    Call(action_command_whirlwind_init, 1)
                    Call(SetupMashMeter, 3, 40, 70, 100, 0, 0)
                    Wait(8)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim11)
                    Wait(15)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim13)
                    Wait(6)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WHIRLWIND)
                    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
                    Call(action_command_whirlwind_start, 0, 88 * DT, 3)
                    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    Call(SetBattleCamTarget, -25, 60, 0)
                    Call(SetBattleCamZoom, 460)
                    Call(SetBattleCamOffsetZ, 0)
                    Call(MoveBattleCamOver, 50)
                    Call(N(StartRumbleWithParams), 70, 130)
                    Thread
                        Loop(30)
                            Call(SetGoalToTarget, ACTOR_SELF)
                            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            Add(LVar0, 10)
                            PlayEffect(EFFECT_WINDY_LEAVES, 2, LVar0, 10, LVar2, 0)
                            Wait(3)
                        EndLoop
                    EndThread
                    Thread
                        Call(ShakeCam, CAM_BATTLE, 0, 90, Float(0.5))
                    EndThread
                    Call(ActorExists, ACTOR_PARTNER, LVar0)
                    IfEq(LVar0, TRUE)
                        Thread
                            Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                            Set(LVar0, 0)
                            Set(LVar1, 3)
                            Loop(93)
                                Call(SetActorYaw, ACTOR_PARTNER, LVar0)
                                Add(LVar0, LVar1)
                                Add(LVar1, 1)
                                Wait(1)
                            EndLoop
                            Call(SetActorYaw, ACTOR_PARTNER, 0)
                        EndThread
                    EndIf
                    Wait(90)
                    Call(GetActionQuality, LVar1)
                    Call(ActorExists, ACTOR_PARTNER, LVar0)
                    IfEq(LVar0, TRUE)
                        Wait(3)
                        Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                        Call(SetGoalToTarget, ACTOR_SELF)
                        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
                    EndIf
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
                    Wait(25)
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(MoveBattleCamOver, 20)
                    ExecWait(N(EVS_FlyToHome))
                    Return
            EndSwitch
        CaseDefault
    EndSwitch
    Call(ShowMessageBox, BTL_MSG_ACTION_TIP_REDUCE_DAMAGE, 90)
    Call(ShowActionHud, TRUE)
    Call(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
    Call(action_command_whirlwind_init, 1)
    Call(SetupMashMeter, 3, 40, 70, 100, 0, 0)
    Wait(8)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim11)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim13)
    Wait(6)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WHIRLWIND)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(action_command_whirlwind_start, 0, 88 * DT, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -25, 60, 0)
    Call(SetBattleCamZoom, 460)
    Call(SetBattleCamOffsetZ, 0)
    Call(MoveBattleCamOver, 50)
    Call(N(StartRumbleWithParams), 70, 130)
    Thread
        Loop(30)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 10)
            PlayEffect(EFFECT_WINDY_LEAVES, 2, LVar0, 10, LVar2, 0)
            Wait(3)
        EndLoop
    EndThread
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 90, Float(0.5))
    EndThread
    Call(GetStatusFlags, ACTOR_PLAYER, LVar1)
    IfNotFlag(LVar1, STATUS_FLAG_STONE)
        Thread
            Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FallBack)
            Set(LVar0, 0)
            Set(LVar1, 3)
            Loop(90)
                Call(SetActorYaw, ACTOR_PLAYER, LVar0)
                Add(LVar0, LVar1)
                Add(LVar1, 1)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_PLAYER, 0)
        EndThread
    EndIf
    Call(ActorExists, ACTOR_PARTNER, LVar0)
    IfEq(LVar0, TRUE)
        Thread
            Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            Set(LVar0, 0)
            Set(LVar1, 3)
            Loop(93)
                Call(SetActorYaw, ACTOR_PARTNER, LVar0)
                Add(LVar0, LVar1)
                Add(LVar1, 1)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_PARTNER, 0)
        EndThread
    EndIf
    Call(FreezeBattleState, TRUE)
    Wait(90)
    Call(GetActionQuality, LVar1)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ActorExists, ACTOR_PARTNER, LVar0)
    IfEq(LVar0, TRUE)
        Wait(3)
        Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    Wait(25)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    ExecWait(N(EVS_FlyToHome))
    Call(FreezeBattleState, FALSE)
    Return
    End
};

EvtScript N(EVS_Attack_FeatherFling) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_05)
    Call(SetBattleCamZoom, 180)
    Call(SetBattleCamOffsetZ, 0)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 90, 35, 0)
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Buzzar_Anim01)
        CaseOrEq(ANIM_Buzzar_Anim02)
        CaseOrEq(ANIM_Buzzar_Anim0D)
        CaseOrEq(ANIM_Buzzar_Anim16)
        CaseOrEq(ANIM_Buzzar_Anim17)
            Loop(0)
                Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    Call(FlyToGoal, ACTOR_SELF, 0, -15, EASING_COS_IN_OUT)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -30)
    Add(LVar1, 25)
    Call(SetPartPos, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -30)
    Add(LVar1, 35)
    Call(SetPartPos, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -20)
    Add(LVar1, 25)
    Call(SetPartPos, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim0E)
    Wait(15)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 24)
    Add(LVar1, 24)
    PlayEffect(EFFECT_SHINY_FLARE, 0, LVar0, LVar1, LVar2, Float(0.6), 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
    Wait(10)
    Call(SetPartSounds, ACTOR_SELF, PRT_FEATHER_1, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_FEATHER_2, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_FEATHER_3, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Thread
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim10)
    Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_1, 0, 0, -45)
    Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_2, 0, 0, -45)
    Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_3, 0, 0, -45)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_1, ANIM_Buzzar_Anim14)
    Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_2, ANIM_Buzzar_Anim14)
    Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_3, ANIM_Buzzar_Anim14)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_FEATHER_1, Float(6.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_1, Float(0.1))
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_FEATHER_2, Float(6.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_2, Float(0.1))
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_FEATHER_3, Float(6.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_3, Float(0.1))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_THROW)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Thread
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(RandInt, 10, LVar3)
                Sub(LVar3, 30)
                Add(LVar0, LVar3)
                Call(FlyPartTo, ACTOR_SELF, PRT_FEATHER_2, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
                Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_2, ANIM_Buzzar_Anim15)
            EndThread
            Thread
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(RandInt, 10, LVar3)
                Sub(LVar3, 40)
                Add(LVar0, LVar3)
                Call(FlyPartTo, ACTOR_SELF, PRT_FEATHER_3, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
                Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_3, ANIM_Buzzar_Anim15)
            EndThread
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(FlyPartTo, ACTOR_SELF, PRT_FEATHER_1, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_1, ANIM_Buzzar_Anim15)
            Thread
                Wait(10)
                Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_1, ANIM_Buzzar_Anim14)
                Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_2, ANIM_Buzzar_Anim14)
                Call(SetAnimation, ACTOR_SELF, PRT_FEATHER_3, ANIM_Buzzar_Anim14)
                Wait(20)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            Wait(10)
            Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
            Wait(10)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            ExecWait(N(EVS_FlyToHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Thread
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(RandInt, 10, LVar3)
        Sub(LVar3, 10)
        Add(LVar1, LVar3)
        Call(FlyPartTo, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EndThread
    Thread
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(RandInt, 10, LVar3)
        Add(LVar3, 10)
        Add(LVar1, LVar3)
        Call(FlyPartTo, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EndThread
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyPartTo, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_FEATHER, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseDefault
            Thread
                Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_2, 0, 45, 90)
                Call(GetPartOffset, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2)
                Sub(LVar0, 40)
                Set(LVar1, 2)
                Call(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_2, Float(1.5))
                Call(JumpPartTo, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2, 10, TRUE)
                Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_2, 0, 80, 90)
                Wait(8)
                Loop(15)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Wait(1)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_3, 0, 45, -90)
                Call(GetPartOffset, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2)
                Add(LVar0, 20)
                Set(LVar1, 4)
                Call(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_3, Float(1.5))
                Call(JumpPartTo, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2, 10, TRUE)
                Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_3, 0, 90, -90)
                Wait(8)
                Loop(15)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Wait(1)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_1, 0, 45, -90)
                Call(GetPartOffset, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2)
                Sub(LVar0, 5)
                Set(LVar1, 4)
                Call(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_1, Float(1.5))
                Call(JumpPartTo, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2, 10, TRUE)
                Call(SetPartRotation, ACTOR_SELF, PRT_FEATHER_1, 0, 90, -90)
                Wait(8)
                Loop(15)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Wait(1)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Wait(1)
                EndLoop
            EndThread
            Wait(30)
            Call(YieldTurn)
            ExecWait(N(EVS_FlyToHome))
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_LiftMario) = {
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Buzzar_Anim01)
        CaseOrEq(ANIM_Buzzar_Anim02)
        CaseOrEq(ANIM_Buzzar_Anim0D)
        CaseOrEq(ANIM_Buzzar_Anim16)
        CaseOrEq(ANIM_Buzzar_Anim17)
            Loop(0)
                Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
    EndSwitch
    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -8, 0)
    ChildThread
        Loop(0)
            Call(N(StartRumbleWithParams), 100, 10)
            Wait(10)
        EndLoop
    EndChildThread
    ChildThread
        Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.1))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 180)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_PLAYER, 99, 0, EASING_LINEAR)
    EndChildThread
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 180)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 99, 0, EASING_LINEAR)
    Return
    End
};

EvtScript N(EVS_Attack_GrappleDrop) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamZoom, 240)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 45, 55, 0)
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Buzzar_Anim01)
        CaseOrEq(ANIM_Buzzar_Anim02)
        CaseOrEq(ANIM_Buzzar_Anim0D)
        CaseOrEq(ANIM_Buzzar_Anim16)
        CaseOrEq(ANIM_Buzzar_Anim17)
            Loop(0)
                Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_COS_IN_OUT)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(SetBattleCamZoom, 240)
            Call(SetBattleCamOffsetZ, -10)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
            Call(FlyToGoal, ACTOR_SELF, 12, -12, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            ExecWait(N(EVS_FlyToHome_GrappleFail))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseEq(HIT_RESULT_IMMUNE)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(SetBattleCamZoom, 240)
            Call(SetBattleCamOffsetZ, -10)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -15, -10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
            Call(FlyToGoal, ACTOR_SELF, 8, -5, EASING_LINEAR)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DROP, BS_FLAGS1_TRIGGER_EVENTS)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 40, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            Switch(LVar0)
                CaseOrEq(ANIM_Buzzar_Anim01)
                CaseOrEq(ANIM_Buzzar_Anim02)
                CaseOrEq(ANIM_Buzzar_Anim0D)
                CaseOrEq(ANIM_Buzzar_Anim16)
                CaseOrEq(ANIM_Buzzar_Anim17)
                    Loop(0)
                        Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                        IfEq(LVar0, 1)
                            BreakLoop
                        EndIf
                        Wait(1)
                    EndLoop
                EndCaseGroup
            EndSwitch
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
            Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            ExecWait(N(EVS_FlyToHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseDefault
    EndSwitch
    Wait(10)
    Call(UseBattleCamPresetImmediately, BTL_CAM_PRESET_19)
    Call(SetBattleCamZoom, 360)
    Call(MoveBattleCamOver, 30)
    Thread
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
        Call(SetBattleCamZoom, 360)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Set(LVar1, 27)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(MoveBattleCamOver, 20)
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, -15, -10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
    Call(FlyToGoal, ACTOR_SELF, 8, -5, EASING_LINEAR)
    IfEq(LVarA, HIT_RESULT_HIT_STATIC)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_GRAB)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim16)
    Call(N(StartRumbleWithParams), 180, 20)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
    Call(ShowMessageBox, BTL_MSG_ACTION_TIP_BREAK_FREE, 90)
    Thread
        Loop(90)
            Call(SetMessageBoxDuration, 99)
            Wait(1)
        EndLoop
        Call(SetMessageBoxDuration, 0)
    EndThread
    Wait(20)
    Call(LoadActionCommand, ACTION_COMMAND_BREAK_FREE)
    Call(action_command_whirlwind_init)
    Call(SetupMashMeter, 1, 30, 0, 0, 0, 0)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim17)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
    Call(SetBattleCamZoom, 240)
    Call(SetBattleCamOffsetZ, -10)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 60)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(ShowActionHud, TRUE)
    Call(action_command_break_free_start, 0, 60 * DT, 30, 3)
    ExecGetTID(N(EVS_LiftMario), LVarA)
    Wait(62)
    Call(GetActionSuccessCopy, LVar0)
    IfGt(LVar0, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
        Wait(2)
        KillThread(LVarA)
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_Land)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
        Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerFallToGoal, 15)
        Wait(8)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Wait(8)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        ExecWait(N(EVS_FlyToHome_GrappleFail))
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamZoom, 360)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar1, 50)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(MoveBattleCamOver, 200)
    Wait(39)
    Wait(10)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_PanicRun, ANIM_Mario1_PanicRun, ANIM_Mario1_PanicRun)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.2))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerFallToGoal, 24)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            Switch(LVar0)
                CaseOrEq(ANIM_Buzzar_Anim01)
                CaseOrEq(ANIM_Buzzar_Anim02)
                CaseOrEq(ANIM_Buzzar_Anim0D)
                CaseOrEq(ANIM_Buzzar_Anim16)
                CaseOrEq(ANIM_Buzzar_Anim17)
                    Loop(0)
                        Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                        IfEq(LVar0, 1)
                            BreakLoop
                        EndIf
                        Wait(1)
                    EndLoop
                EndCaseGroup
            EndSwitch
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            ExecWait(N(EVS_FlyToHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamZoom, 240)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 60, 15, 0)
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Buzzar_Anim01)
        CaseOrEq(ANIM_Buzzar_Anim02)
        CaseOrEq(ANIM_Buzzar_Anim0D)
        CaseOrEq(ANIM_Buzzar_Anim16)
        CaseOrEq(ANIM_Buzzar_Anim17)
            Loop(0)
                Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    Call(FlyToGoal, ACTOR_SELF, 0, -15, EASING_COS_IN_OUT)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Wait(10)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
            Call(FlyToGoal, ACTOR_SELF, 12, -12, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            ExecWait(N(EVS_FlyToHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, -5, -10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
    Call(FlyToGoal, ACTOR_SELF, 8, 0, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SWIPE, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            Switch(LVar0)
                CaseOrEq(ANIM_Buzzar_Anim01)
                CaseOrEq(ANIM_Buzzar_Anim02)
                CaseOrEq(ANIM_Buzzar_Anim0D)
                CaseOrEq(ANIM_Buzzar_Anim16)
                CaseOrEq(ANIM_Buzzar_Anim17)
                    Loop(0)
                        Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                        IfEq(LVar0, 1)
                            BreakLoop
                        EndIf
                        Wait(1)
                    EndLoop
                EndCaseGroup
            EndSwitch
            Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
            Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            ExecWait(N(EVS_FlyToHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_FlyToHome) = {
    ExecWait(N(EVS_FlyToHome_Impl))
    Return
    End
};

EvtScript N(EVS_FlyToHome_GrappleFail) = {
    ExecWait(N(EVS_FlyToHome_GrappleFail_Impl))
    Return
    End
};

EvtScript N(EVS_FlyToHome_Impl) = {
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Buzzar_Anim01)
        CaseOrEq(ANIM_Buzzar_Anim02)
        CaseOrEq(ANIM_Buzzar_Anim0D)
        CaseOrEq(ANIM_Buzzar_Anim16)
        CaseOrEq(ANIM_Buzzar_Anim17)
            Loop(0)
                Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
    EndSwitch
    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -20, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_FlyToHome_GrappleFail_Impl) = {
    Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Switch(LVar0)
        CaseOrEq(ANIM_Buzzar_Anim01)
        CaseOrEq(ANIM_Buzzar_Anim02)
        CaseOrEq(ANIM_Buzzar_Anim0D)
        CaseOrEq(ANIM_Buzzar_Anim16)
        CaseOrEq(ANIM_Buzzar_Anim17)
            Loop(0)
                Call(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
        EndCaseGroup
    EndSwitch
    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -20, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 0, 45, EASING_LINEAR)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_DummyHit) = {
    Return
    Return
    End
};
