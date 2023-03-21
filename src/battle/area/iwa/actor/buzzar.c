#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Buzzar.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"

#define NAMESPACE b_area_iwa_buzzar

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_NextTurn);
extern EvtScript N(EVS_Attack_WindBlast);
extern EvtScript N(EVS_Attack_FeatherFling);
extern EvtScript N(EVS_Attack_GrappleDrop);
extern EvtScript N(EVS_Attack_ClawSwipe);
extern EvtScript N(EVS_FlyToHome);
extern EvtScript N(EVS_FlyToHome_GrappleFail);
extern EvtScript N(EVS_FlyToHome_Impl);
extern EvtScript N(EVS_FlyToHome_GrappleFail_Impl);
extern EvtScript N(8021FC34);


s32 N(IdleAnimations_8021B600)[] = {
    STATUS_NORMAL,    ANIM_Buzzar_Anim01,
    STATUS_STONE,     ANIM_Buzzar_Anim00,
    STATUS_SLEEP,     ANIM_Buzzar_Anim19,
    STATUS_STOP,      ANIM_Buzzar_Anim00,
    STATUS_STATIC,    ANIM_Buzzar_Anim0C,
    STATUS_PARALYZE,  ANIM_Buzzar_Anim0C,
    STATUS_DIZZY,     ANIM_Buzzar_Anim0C,
    STATUS_SHRINK,    ANIM_Buzzar_Anim01,
    STATUS_END,
};

s32 N(IdleAnimations_8021B644)[] = {
    STATUS_NORMAL,    ANIM_Buzzar_Anim14,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 70,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 70,
    STATUS_SHRINK, 75,
    STATUS_STOP, 70,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -20, 60 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B600),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 31, 0 },
        .targetOffset = { -14, 20 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B600),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -14 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B644),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B644),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B644),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BUZZAR,
    .level = 35,
    .maxHP = 40,
    .partCount = ARRAY_COUNT( N(PartsTable)),
    .partsData = N(PartsTable),
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
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -35, 65 },
    .statusMessageOffset = { 1, 58 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(EVS_NextTurn)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 40)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NextTurn) = {
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
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021FC34))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim0B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Buzzar_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_EXEC_WAIT(N(EVS_Attack_WindBlast))
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
            EVT_EXEC_WAIT(N(EVS_Attack_ClawSwipe))
        EVT_CASE_EQ(4)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 5)
            EVT_EXEC_WAIT(N(EVS_Attack_FeatherFling))
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 5)
                EVT_SET(LVar0, 0)
            EVT_ELSE
                EVT_ADD(LVar0, 1)
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_EXEC_WAIT(N(EVS_Attack_GrappleDrop))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
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
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_COS_IN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    EVT_WAIT(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim11)
                    EVT_WAIT(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim13)
                    EVT_WAIT(6)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F0)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
                    EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_WAIT(25)
                    EVT_EXEC_WAIT(N(EVS_FlyToHome))
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(ShowMessageBox, BTL_MSG_41, 90)
                    EVT_CALL(ShowActionHud, TRUE)
                    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
                    EVT_CALL(action_command_whirlwind_init, 1)
                    EVT_CALL(SetupMashMeter, 3, 40, 70, 100, 0, 0)
                    EVT_WAIT(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim11)
                    EVT_WAIT(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim13)
                    EVT_WAIT(6)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F0)
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
                    EVT_CALL(GetActionResult, LVar1)
                    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
                    EVT_IF_EQ(LVar0, TRUE)
                        EVT_WAIT(3)
                        EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_IF
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
                    EVT_WAIT(25)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_EXEC_WAIT(N(EVS_FlyToHome))
                    EVT_RETURN
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(ShowMessageBox, BTL_MSG_41, 90)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
    EVT_CALL(action_command_whirlwind_init, 1)
    EVT_CALL(SetupMashMeter, 3, 40, 70, 100, 0, 0)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim11)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim13)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F0)
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
    EVT_CALL(func_8026BF48, 1)
    EVT_WAIT(90)
    EVT_CALL(GetActionResult, LVar1)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ActorExists, ACTOR_PARTNER, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_WAIT(3)
        EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
    EVT_WAIT(25)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_EXEC_WAIT(N(EVS_FlyToHome))
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_FeatherFling) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 90, 35, 0)
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -15, EASING_COS_IN_OUT)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -30)
    EVT_ADD(LVar1, 25)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -30)
    EVT_ADD(LVar1, 35)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -20)
    EVT_ADD(LVar1, 25)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim0E)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 24)
    EVT_ADD(LVar1, 24)
    EVT_PLAY_EFFECT(EFFECT_SHINY_FLARE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.6), 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F3)
    EVT_WAIT(10)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 4, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 5, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim10)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 0, -45)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 0, -45)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 0, -45)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_Buzzar_Anim14)
    EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_Buzzar_Anim14)
    EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_Buzzar_Anim14)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 4, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 4, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 5, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 5, EVT_FLOAT(0.1))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F4)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_10)
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
                EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_Buzzar_Anim15)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(RandInt, 10, LVar3)
                EVT_SUB(LVar3, 40)
                EVT_ADD(LVar0, LVar3)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_Buzzar_Anim15)
            EVT_END_THREAD
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, 5, LVar2, 9, 0, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_Buzzar_Anim15)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_Buzzar_Anim14)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_Buzzar_Anim14)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_Buzzar_Anim14)
                EVT_WAIT(20)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(10)
            EVT_CALL(func_8024ECF8, 0, 1, 0)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(func_8024ECF8, 0, 1, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_SUB(LVar3, 10)
        EVT_ADD(LVar1, LVar3)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(RandInt, 10, LVar3)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar1, LVar3)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EVT_END_THREAD
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 6, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_DEFAULT
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 45, 90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 40)
                EVT_SET(LVar1, 2)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 4, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, 4, LVar0, LVar1, LVar2, 10, TRUE)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 80, 90)
                EVT_WAIT(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 45, -90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 20)
                EVT_SET(LVar1, 4)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 5, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, 5, LVar0, LVar1, LVar2, 10, TRUE)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 90, -90)
                EVT_WAIT(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 45, -90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 5)
                EVT_SET(LVar1, 4)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 10, TRUE)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 90, -90)
                EVT_WAIT(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT(30)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LiftMarioario) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
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
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 45, 55, 0)
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_COS_IN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 4, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 240)
            EVT_CALL(SetBattleCamOffsetZ, -10)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F2)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 12, -12, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_FlyToHome_GrappleFail))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 240)
            EVT_CALL(SetBattleCamOffsetZ, -10)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F2)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -15, -10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 8, -5, EASING_LINEAR)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
                    EVT_LOOP(0)
                        EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
                        EVT_IF_EQ(LVar0, 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim02)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F2)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -15, -10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim18)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 8, -5, EASING_LINEAR)
    EVT_IF_EQ(LVarA, HIT_RESULT_HIT_STATIC)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim16)
    EVT_CALL(N(StartRumbleWithParams), 180, 20)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
    EVT_CALL(ShowMessageBox, BTL_MSG_40, 90)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim17)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(action_command_break_free_start, 0, 60 * DT, 30, 3)
    EVT_EXEC_GET_TID(N(EVS_LiftMarioario), LVarA)
    EVT_WAIT(62)
    EVT_CALL(GetActionSuccessCopy, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
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
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_EXEC_WAIT(N(EVS_FlyToHome_GrappleFail))
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
                    EVT_LOOP(0)
                        EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
                        EVT_IF_EQ(LVar0, 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -14, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim02)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 60, 15, 0)
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -15, EASING_COS_IN_OUT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F2)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 12, -12, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F2)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -5, -10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim18)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 8, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
                EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
                    EVT_LOOP(0)
                        EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim02)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_FlyToHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
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
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -20, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyToHome_GrappleFail_Impl) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim01)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim02)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim0D)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim16)
        EVT_CASE_OR_EQ(ANIM_Buzzar_Anim17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY_INCREMENT, -20, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 45, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Buzzar_Anim01)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021FC34) = {
    EVT_RETURN
    EVT_RETURN
    EVT_END
};
