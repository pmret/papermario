#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/buzzar.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"

#define NAMESPACE b_area_iwa_buzzar

extern EvtScript N(init_8021B7E4);
extern EvtScript N(takeTurn_8021BCD8);
extern EvtScript N(idle_8021B930);
extern EvtScript N(handleEvent_8021B940);
extern EvtScript N(nextTurn_8021B918);
extern EvtScript N(8021BEBC);
extern EvtScript N(8021CCE8);
extern EvtScript N(8021DF2C);
extern EvtScript N(8021F030);
extern EvtScript N(8021F7EC);
extern EvtScript N(8021F808);
extern EvtScript N(8021F824);
extern EvtScript N(8021FA2C);
extern EvtScript N(8021FC34);


s32 N(idleAnimations_8021B600)[] = {
    STATUS_NORMAL,    NPC_ANIM_buzzar_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_buzzar_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_buzzar_Palette_00_Anim_19,
    STATUS_STOP,      NPC_ANIM_buzzar_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_buzzar_Palette_00_Anim_C,
    STATUS_PARALYZE,  NPC_ANIM_buzzar_Palette_00_Anim_C,
    STATUS_DIZZY,     NPC_ANIM_buzzar_Palette_00_Anim_C,
    STATUS_SHRINK,    NPC_ANIM_buzzar_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(idleAnimations_8021B644)[] = {
    STATUS_NORMAL,    NPC_ANIM_buzzar_Palette_00_Anim_14,
    STATUS_END,
};

s32 N(defenseTable_8021B650)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021B65C)[] = {
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

ActorPartBlueprint N(partsTable_8021B708)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -20, 60 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B600),
        .defenseTable = N(defenseTable_8021B650),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 31, 0 },
        .targetOffset = { -14, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B600),
        .defenseTable = N(defenseTable_8021B650),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 242,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B644),
        .defenseTable = N(defenseTable_8021B650),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B644),
        .defenseTable = N(defenseTable_8021B650),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B644),
        .defenseTable = N(defenseTable_8021B650),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BUZZAR,
    .level = 35,
    .maxHP = 40,
    .partCount = ARRAY_COUNT(N(partsTable_8021B708)),
    .partsData = N(partsTable_8021B708),
    .script = &N(init_8021B7E4),
    .statusTable = N(statusTable_8021B65C),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 78, 74 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -35, 65 },
    .statusMessageOffset = { 1, 58 },
};

EvtScript N(init_8021B7E4) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021BCD8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021B930)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021B940)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_8021B918)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 40)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021B918) = {
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021B930) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021B940) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021FC34))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_EXEC_WAIT(N(8021F7EC))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_buzzar_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021BCD8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_EXEC_WAIT(N(8021BEBC))
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
            EVT_EXEC_WAIT(N(8021F030))
        EVT_CASE_EQ(4)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 5)
            EVT_EXEC_WAIT(N(8021CCE8))
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 5)
                EVT_SET(LW(0), 0)
            EVT_ELSE
                EVT_ADD(LW(0), 1)
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_EXEC_WAIT(N(8021DF2C))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(8021BEBC) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 120)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 70, LW(2))
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_SWITCH(LW(10))
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    EVT_WAIT_FRAMES(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_11)
                    EVT_WAIT_FRAMES(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_13)
                    EVT_WAIT_FRAMES(6)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F0)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(MoveBattleCamOver, 50)
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 90, EVT_FLOAT(0.5))
                    EVT_END_THREAD
                    EVT_CALL(N(StartRumbleWithParams), 70, 100)
                    EVT_THREAD
                        EVT_LOOP(20)
                            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_ADD(LW(0), 10)
                            EVT_CALL(PlayEffect, EFFECT_WINDY_LEAVES, 2, LW(0), 10, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                            EVT_WAIT_FRAMES(3)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_WAIT_FRAMES(60)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
                    EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_WAIT_FRAMES(25)
                    EVT_EXEC_WAIT(N(8021F7EC))
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(ShowMessageBox, 65, 90)
                    EVT_CALL(func_802694A4, 1)
                    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
                    EVT_CALL(func_802A9000_423C70, 1)
                    EVT_CALL(SetupMashMeter, 3, 40, 70, 100, 0, 0)
                    EVT_WAIT_FRAMES(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_11)
                    EVT_WAIT_FRAMES(15)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_13)
                    EVT_WAIT_FRAMES(6)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F0)
                    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
                    EVT_CALL(func_802A91E0_423E50, 0, 88, 3)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, -25, 60, 0)
                    EVT_CALL(SetBattleCamZoom, 460)
                    EVT_CALL(SetBattleCamOffsetZ, 0)
                    EVT_CALL(MoveBattleCamOver, 50)
                    EVT_CALL(N(StartRumbleWithParams), 70, 130)
                    EVT_THREAD
                        EVT_LOOP(30)
                            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                            EVT_ADD(LW(0), 10)
                            EVT_CALL(PlayEffect, EFFECT_WINDY_LEAVES, 2, LW(0), 10, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                            EVT_WAIT_FRAMES(3)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(ShakeCam, 1, 0, 90, EVT_FLOAT(0.5))
                    EVT_END_THREAD
                    EVT_CALL(ActorExists, ACTOR_PARTNER, LW(0))
                    EVT_IF_EQ(LW(0), TRUE)
                        EVT_THREAD
                            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                            EVT_SET(LW(0), 0)
                            EVT_SET(LW(1), 3)
                            EVT_LOOP(93)
                                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LW(0))
                                EVT_ADD(LW(0), LW(1))
                                EVT_ADD(LW(1), 1)
                                EVT_WAIT_FRAMES(1)
                            EVT_END_LOOP
                            EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_WAIT_FRAMES(90)
                    EVT_CALL(GetActionResult, LW(1))
                    EVT_CALL(ActorExists, ACTOR_PARTNER, LW(0))
                    EVT_IF_EQ(LW(0), TRUE)
                        EVT_WAIT_FRAMES(3)
                        EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, LW(1), BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_IF
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
                    EVT_WAIT_FRAMES(25)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_EXEC_WAIT(N(8021F7EC))
                    EVT_RETURN
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(ShowMessageBox, 65, 90)
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_WHIRLWIND)
    EVT_CALL(func_802A9000_423C70, 1)
    EVT_CALL(SetupMashMeter, 3, 40, 70, 100, 0, 0)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_11)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_13)
    EVT_WAIT_FRAMES(6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F0)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_CALL(func_802A91E0_423E50, 0, 88, 3)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -25, 60, 0)
    EVT_CALL(SetBattleCamZoom, 460)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_CALL(N(StartRumbleWithParams), 70, 130)
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 10)
            EVT_CALL(PlayEffect, EFFECT_WINDY_LEAVES, 2, LW(0), 10, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 90, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(1))
    EVT_IF_NOT_FLAG(LW(1), STATUS_FLAG_STONE)
        EVT_THREAD
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002E)
            EVT_SET(LW(0), 0)
            EVT_SET(LW(1), 3)
            EVT_LOOP(90)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, LW(0))
                EVT_ADD(LW(0), LW(1))
                EVT_ADD(LW(1), 1)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_PARTNER, LW(0))
    EVT_IF_EQ(LW(0), TRUE)
        EVT_THREAD
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            EVT_SET(LW(0), 0)
            EVT_SET(LW(1), 3)
            EVT_LOOP(93)
                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LW(0))
                EVT_ADD(LW(0), LW(1))
                EVT_ADD(LW(1), 1)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(func_8026BF48, 1)
    EVT_WAIT_FRAMES(90)
    EVT_CALL(GetActionResult, LW(1))
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, LW(1), BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ActorExists, ACTOR_PARTNER, LW(0))
    EVT_IF_EQ(LW(0), TRUE)
        EVT_WAIT_FRAMES(3)
        EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, LW(1), BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
    EVT_WAIT_FRAMES(25)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_EXEC_WAIT(N(8021F7EC))
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021CCE8) = {
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
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -15, 10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), -30)
    EVT_ADD(LW(1), 25)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), -30)
    EVT_ADD(LW(1), 35)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), -20)
    EVT_ADD(LW(1), 25)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_E)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 24)
    EVT_ADD(LW(1), 24)
    EVT_CALL(PlayEffect, EFFECT_SHINY_FLARE, 0, LW(0), LW(1), LW(2), EVT_FLOAT(0.6), 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F3)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, 1, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 4, 1, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 5, 1, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_10)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 0, -45)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 0, -45)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 0, -45)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_buzzar_Palette_00_Anim_14)
    EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_buzzar_Palette_00_Anim_14)
    EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_buzzar_Palette_00_Anim_14)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 4, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 4, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 5, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 5, EVT_FLOAT(0.1))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F4)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(RandInt, 10, LW(3))
                EVT_SUB(LW(3), 30)
                EVT_ADD(LW(0), LW(3))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LW(0), 5, LW(2), 9, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_buzzar_Palette_00_Anim_15)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(RandInt, 10, LW(3))
                EVT_SUB(LW(3), 40)
                EVT_ADD(LW(0), LW(3))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LW(0), 5, LW(2), 9, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_buzzar_Palette_00_Anim_15)
            EVT_END_THREAD
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LW(0), 5, LW(2), 9, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_buzzar_Palette_00_Anim_15)
            EVT_THREAD
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_buzzar_Palette_00_Anim_14)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_buzzar_Palette_00_Anim_14)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_buzzar_Palette_00_Anim_14)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 1)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(10)
            EVT_CALL(func_8024ECF8, 0, 1, 0)
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(8021F7EC))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(func_8024ECF8, 0, 1, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(RandInt, 10, LW(3))
        EVT_SUB(LW(3), 10)
        EVT_ADD(LW(1), LW(3))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LW(0), LW(1), LW(2), 6, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(RandInt, 10, LW(3))
        EVT_ADD(LW(3), 10)
        EVT_ADD(LW(1), LW(3))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LW(0), LW(1), LW(2), 6, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 6, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_DEFAULT
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 45, 90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, 4, LW(0), LW(1), LW(2))
                EVT_SUB(LW(0), 40)
                EVT_SET(LW(1), 2)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 4, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, 4, LW(0), LW(1), LW(2), 10, 1)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 80, 90)
                EVT_WAIT_FRAMES(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 1)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 45, -90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, 5, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), 20)
                EVT_SET(LW(1), 4)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 5, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, 5, LW(0), LW(1), LW(2), 10, 1)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 90, -90)
                EVT_WAIT_FRAMES(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 1)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 45, -90)
                EVT_CALL(GetPartOffset, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
                EVT_SUB(LW(0), 5)
                EVT_SET(LW(1), 4)
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(1.5))
                EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 10, 1)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 90, -90)
                EVT_WAIT_FRAMES(8)
                EVT_LOOP(15)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(30)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021F7EC))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021DCB8) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(ResetActorSounds, ACTOR_SELF, 1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 5, -8, 0)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(N(StartRumbleWithParams), 100, 10)
            EVT_WAIT_FRAMES(10)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 180)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(FlyToGoal, ACTOR_PLAYER, 99, 0, 0)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 180)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 99, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021DF2C) = {
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
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 4, BS_FLAGS1_10)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 240)
            EVT_CALL(SetBattleCamOffsetZ, -10)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F2)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 12, -12, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(8021F808))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 240)
            EVT_CALL(SetBattleCamOffsetZ, -10)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F2)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -15, -10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 8, -5, 0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
                    EVT_LOOP(0)
                        EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                        EVT_IF_EQ(LW(0), 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT_FRAMES(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 5, -14, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_2)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(8021F7EC))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 360)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamZoom, 360)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_SET(LW(1), 27)
        EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F2)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -15, -10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_18)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 8, -5, 0)
    EVT_IF_EQ(LW(10), HIT_RESULT_HIT_STATIC)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_16)
    EVT_CALL(N(StartRumbleWithParams), 180, 20)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1002B)
    EVT_CALL(ShowMessageBox, 64, 90)
    EVT_THREAD
        EVT_LOOP(90)
            EVT_CALL(SetMessageBoxDuration, 99)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetMessageBoxDuration, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(20)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_BREAK_FREE)
    EVT_CALL(func_802A9000_423C70)
    EVT_CALL(SetupMashMeter, 1, 30, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_17)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
    EVT_CALL(SetBattleCamZoom, 240)
    EVT_CALL(SetBattleCamOffsetZ, -10)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(func_802A91B0_4235A0, 0, 60, 30, 3)
    EVT_EXEC_GET_TID(N(8021DCB8), LW(10))
    EVT_WAIT_FRAMES(62)
    EVT_CALL(GetActionSuccessCopy, LW(0))
    EVT_IF_GT(LW(0), 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_WAIT_FRAMES(2)
        EVT_KILL_THREAD(LW(10))
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR_STILL, ANIM_10009)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_SET(LW(1), 0)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(PlayerFallToGoal, 15)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_EXEC_WAIT(N(8021F808))
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamZoom, 360)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 50)
    EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
    EVT_CALL(MoveBattleCamOver, 200)
    EVT_WAIT_FRAMES(39)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_RUN_PANIC, ANIM_RUN_PANIC, ANIM_RUN_PANIC)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.2))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(PlayerFallToGoal, 24)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
                    EVT_LOOP(0)
                        EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                        EVT_IF_EQ(LW(0), 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT_FRAMES(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 5, -14, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_2)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021F7EC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F030) = {
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
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -15, 10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F2)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -45, -20, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_18)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 12, -12, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(8021F7EC))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F2)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -5, -10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_18)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 8, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
                EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
                    EVT_LOOP(0)
                        EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                        EVT_IF_EQ(LW(0), 1)
                            EVT_BREAK_LOOP
                        EVT_END_IF
                        EVT_WAIT_FRAMES(1)
                    EVT_END_LOOP
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 5, -14, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_2)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021F7EC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F7EC) = {
    EVT_EXEC_WAIT(N(8021F824))
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F808) = {
    EVT_EXEC_WAIT(N(8021FA2C))
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F824) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(ResetActorSounds, ACTOR_SELF, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 5, -20, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021FA2C) = {
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_1)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_2)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_D)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_16)
        EVT_CASE_OR_EQ(NPC_ANIM_buzzar_Palette_00_Anim_17)
            EVT_LOOP(0)
                EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(ResetActorSounds, ACTOR_SELF, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 5, -20, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 45, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_buzzar_Palette_00_Anim_1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021FC34) = {
    EVT_RETURN
    EVT_RETURN
    EVT_END
};
