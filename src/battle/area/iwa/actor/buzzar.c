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
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_WindBlast)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_3, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 40)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_DummyHit))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_WindBlast)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_ClawSwipe)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Move_WindBlast)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_GrappleThenSwipe)
            EVT_EXEC_WAIT(N(EVS_Attack_WindBlast))
        EVT_CASE_EQ(AVAL_Move_ClawSwipe)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_GrappleThenFling)
            EVT_EXEC_WAIT(N(EVS_Attack_ClawSwipe))
        EVT_CASE_EQ(AVAL_Move_FlingFeather)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_GrappleThenWind)
            EVT_EXEC_WAIT(N(EVS_Attack_FeatherFling))
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
            EVT_IF_EQ(LVar0, AVAL_Move_GrappleThenWind)
                EVT_SET(LVar0, AVAL_Move_WindBlast)
            EVT_ELSE
                EVT_ADD(LVar0, 1)
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
            EVT_EXEC_WAIT(N(EVS_Attack_GrappleDrop))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Attack_WindBlast) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 120)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 70, LVar2)
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_COS_IN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    EVT_WAIT(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim11)
                    EVT_WAIT(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim13)
                    EVT_WAIT(6)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WHIRLWIND)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(MoveBattleCamOver, 50)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 90, EVT_FLOAT(0.5))
                    EVT_END_THREAD
                    EVT_CALL(N(StartRumbleWithParams), 70, 100)
                    EVT_THREAD
                        EVT_LOOP(20)
                            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_ADD(LVar0, 10)
                            EVT_PLAY_EFFECT(EFFECT_WINDY_LEAVES, 2, LVar0, 10, LVar2, 0)
                            EVT_WAIT(3)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_WAIT(60)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
                    EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(25)
                    EVT_EXEC_WAIT(N(EVS_FlyToHome))
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_REDUCE_DAMAGE, 90)
                    EVT_CALL(ShowActionHud, TRUE)
                    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
                    EVT_CALL(action_command_whirlwind_init, 1)
                    EVT_CALL(SetupMashMeter, 3, 40, 70, 100, 0, 0)
                    EVT_WAIT(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim11)
                    EVT_WAIT(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim13)
                    EVT_WAIT(6)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WHIRLWIND)
                    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
                    EVT_CALL(action_command_whirlwind_start, 0, 88 * DT, 3)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, -25, 60, 0)
                    EVT_CALL(SetBattleCamZoom, 460)
                    EVT_CALL(SetBattleCamOffsetZ, 0)
                    EVT_CALL(MoveBattleCamOver, 50)
                    EVT_CALL(N(StartRumbleWithParams), 70, 130)
                    EVT_THREAD
                        EVT_LOOP(30)
                            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_ADD(LVar0, 10)
                            EVT_PLAY_EFFECT(EFFECT_WINDY_LEAVES, 2, LVar0, 10, LVar2, 0)
                            EVT_WAIT(3)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 90, EVT_FLOAT(0.5))
                    EVT_END_THREAD
                    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
                    EVT_IF_EQ(LVar0, TRUE)
                        EVT_THREAD
                            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                            EVT_SET(LVar0, 0)
                            EVT_SET(LVar1, 3)
                            EVT_LOOP(93)
                                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
                                EVT_ADD(LVar0, LVar1)
                                EVT_ADD(LVar1, 1)
                                EVT_WAIT(1)
                            EVT_END_LOOP
                            EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_WAIT(90)
                    EVT_CALL(GetActionQuality, LVar1)
                    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
                    EVT_IF_EQ(LVar0, TRUE)
                        EVT_WAIT(3)
                        EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
                    EVT_END_IF
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
                    EVT_WAIT(25)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_EXEC_WAIT(N(EVS_FlyToHome))
                    EVT_RETURN
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_REDUCE_DAMAGE, 90)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
    EVT_CALL(action_command_whirlwind_init, 1)
    EVT_CALL(SetupMashMeter, 3, 40, 70, 100, 0, 0)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim11)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim13)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WHIRLWIND)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(action_command_whirlwind_start, 0, 88 * DT, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -25, 60, 0)
    EVT_CALL(SetBattleCamZoom, 460)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_CALL(N(StartRumbleWithParams), 70, 130)
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 10)
            EVT_PLAY_EFFECT(EFFECT_WINDY_LEAVES, 2, LVar0, 10, LVar2, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 90, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar1)
    EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_STONE)
        EVT_THREAD
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_FallBack)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar1, 3)
            EVT_LOOP(90)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
                EVT_ADD(LVar0, LVar1)
                EVT_ADD(LVar1, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_THREAD
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            EVT_SET(LVar0, 0)
            EVT_SET(LVar1, 3)
            EVT_LOOP(93)
                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
                EVT_ADD(LVar0, LVar1)
                EVT_ADD(LVar1, 1)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(FreezeBattleState, TRUE)
    EVT_WAIT(90)
    EVT_CALL(GetActionQuality, LVar1)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_WAIT(3)
        EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    EVT_WAIT(25)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_EXEC_WAIT(N(EVS_FlyToHome))
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_FeatherFling) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_05)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 90, 35, 0)
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -15, EASING_COS_IN_OUT)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -30)
    EVT_ADD(LVar1, 25)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -30)
    EVT_ADD(LVar1, 35)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_ADD(LVar1, 25)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim0E)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 24)
    EVT_ADD(LVar1, 24)
    EVT_PLAY_EFFECT(EFFECT_SHINY_FLARE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.6), 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
    EVT_WAIT(10)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_FEATHER_1, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_FEATHER_2, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_FEATHER_3, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim10)
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_1, 0, 0, -45)
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_2, 0, 0, -45)
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_3, 0, 0, -45)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_1, ANIM_Buzzar_Anim14)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_2, ANIM_Buzzar_Anim14)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_3, ANIM_Buzzar_Anim14)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_FEATHER_1, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_1, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_FEATHER_2, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_2, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_FEATHER_3, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_3, EVT_FLOAT(0.1))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_THROW)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(RandInt, 10, LVar3)
                EVT_SUB(LVar3, 30)
                EVT_ADD(LVar0, LVar3)
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_FEATHER_2, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_2, ANIM_Buzzar_Anim15)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(RandInt, 10, LVar3)
                EVT_SUB(LVar3, 40)
                EVT_ADD(LVar0, LVar3)
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_FEATHER_3, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_3, ANIM_Buzzar_Anim15)
            EVT_END_THREAD
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_FEATHER_1, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_1, ANIM_Buzzar_Anim15)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_1, ANIM_Buzzar_Anim14)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_2, ANIM_Buzzar_Anim14)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FEATHER_3, ANIM_Buzzar_Anim14)
                EVT_WAIT(20)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(10)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_SUB(LVar3, 10)
        EVT_ADD(LVar1, LVar3)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar1, LVar3)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EVT_END_THREAD
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_FEATHER, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_DEFAULT
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_2, 0, 45, 90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 40)
                EVT_SET(LVar1, 2)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_2, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_FEATHER_2, LVar0, LVar1, LVar2, 10, TRUE)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_2, 0, 80, 90)
                EVT_WAIT(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_3, 0, 45, -90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 20)
                EVT_SET(LVar1, 4)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_3, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_FEATHER_3, LVar0, LVar1, LVar2, 10, TRUE)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_3, 0, 90, -90)
                EVT_WAIT(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_1, 0, 45, -90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 5)
                EVT_SET(LVar1, 4)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FEATHER_1, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_FEATHER_1, LVar0, LVar1, LVar2, 10, TRUE)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEATHER_1, 0, 90, -90)
                EVT_WAIT(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEATHER_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT(30)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LiftMario) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -8, 0)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(StartRumbleWithParams), 100, 10)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 180)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_PLAYER, 99, 0, EASING_LINEAR)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 180)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 99, 0, EASING_LINEAR)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_GrappleDrop) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 45, 55, 0)
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_COS_IN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 240)
            EVT_CALL(SetBattleCamOffsetZ, -10)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 12, -12, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_FlyToHome_GrappleFail))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 240)
            EVT_CALL(SetBattleCamOffsetZ, -10)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -15, -10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 8, -5, EASING_LINEAR)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DROP, BS_FLAGS1_TRIGGER_EVENTS)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
                    EVT_LOOP(0)
                        EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                        EVT_IF_EQ(LVar0, 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 360)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamZoom, 360)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 27)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -15, -10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 8, -5, EASING_LINEAR)
    EVT_IF_EQ(LVarA, HIT_RESULT_HIT_STATIC)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_GRAB)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim16)
    EVT_CALL(N(StartRumbleWithParams), 180, 20)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
    EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_BREAK_FREE, 90)
    EVT_THREAD
        EVT_LOOP(90)
            EVT_CALL(SetMessageBoxDuration, 99)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetMessageBoxDuration, 0)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_BREAK_FREE)
    EVT_CALL(action_command_whirlwind_init)
    EVT_CALL(SetupMashMeter, 1, 30, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim17)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(action_command_break_free_start, 0, 60 * DT, 30, 3)
    EVT_EXEC_GET_TID(N(EVS_LiftMario), LVarA)
    EVT_WAIT(62)
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
        EVT_WAIT(2)
        EVT_KILL_THREAD(LVarA)
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Jump, ANIM_Mario1_Land)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerFallToGoal, 15)
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_WAIT(8)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_EXEC_WAIT(N(EVS_FlyToHome_GrappleFail))
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 360)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 50)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(MoveBattleCamOver, 200)
    EVT_WAIT(39)
    EVT_WAIT(10)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_PanicRun, ANIM_Mario1_PanicRun, ANIM_Mario1_PanicRun)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.2))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayerFallToGoal, 24)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
                    EVT_LOOP(0)
                        EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                        EVT_IF_EQ(LVar0, 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 60, 15, 0)
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -15, EASING_COS_IN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 12, -12, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_WINDUP)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BUZZAR_DIVE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -5, -10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim18)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 8, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SWIPE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
                    EVT_LOOP(0)
                        EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                        EVT_IF_EQ(LVar0, 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim02)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyToHome) = {
    EVT_EXEC_WAIT(N(EVS_FlyToHome_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyToHome_GrappleFail) = {
    EVT_EXEC_WAIT(N(EVS_FlyToHome_GrappleFail_Impl))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyToHome_Impl) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -20, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyToHome_GrappleFail_Impl) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -20, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 45, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Buzzar_Anim01)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DummyHit) = {
    EVT_RETURN
    EVT_RETURN
    EVT_END
};
