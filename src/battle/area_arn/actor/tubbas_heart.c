#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_bow.h"
#include "sprite/npc/tubbas_heart.h"

#define NAMESPACE b_area_arn_tubbas_heart

extern EvtScript N(init_80223DA0);
extern EvtScript N(takeTurn_802245C8);
extern EvtScript N(idle_80223E98);
extern EvtScript N(handleEvent_80224038);
extern EvtScript N(80224414);
extern EvtScript N(802244DC);
extern EvtScript N(80224B3C);
extern EvtScript N(80225258);
extern EvtScript N(802255D8);

s32 N(idleAnimations_80223BC0)[] = {
    STATUS_NORMAL,    NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_tubbas_heart_Palette_00_Anim_4,
    STATUS_POISON,    NPC_ANIM_tubbas_heart_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_tubbas_heart_Palette_00_Anim_D,
    STATUS_DIZZY,     NPC_ANIM_tubbas_heart_Palette_00_Anim_D,
    STATUS_FEAR,      NPC_ANIM_tubbas_heart_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations_80223C1C)[] = {
    STATUS_NORMAL,    NPC_ANIM_tubbas_heart_Palette_00_Anim_B,
    STATUS_STONE,     NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_tubbas_heart_Palette_00_Anim_4,
    STATUS_POISON,    NPC_ANIM_tubbas_heart_Palette_00_Anim_B,
    STATUS_STOP,      NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_tubbas_heart_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_tubbas_heart_Palette_00_Anim_D,
    STATUS_DIZZY,     NPC_ANIM_tubbas_heart_Palette_00_Anim_D,
    STATUS_FEAR,      NPC_ANIM_tubbas_heart_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(defenseTable_80223C78)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80223C84)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 90,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80223D30)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80223BC0),
        .defenseTable = N(defenseTable_80223C78),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 54, 0 },
        .targetOffset = { 0, -30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80223BC0),
        .defenseTable = N(defenseTable_80223C78),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUBBA_HEART,
    .level = 0,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(partsTable_80223D30)),
    .partsData = N(partsTable_80223D30),
    .script = N(init_80223DA0),
    .statusTable = N(statusTable_80223C84),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 30, 30 },
    .hpBarOffset = { 5, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_80223DA0) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802245C8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80223E98)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80224038)))
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 2, 2, 1)
    EVT_RETURN
    EVT_END
};

ApiStatus func_80218680_4FF0D0(Evt* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    Effect6BInstance* effect = (Effect6BInstance*) evt_get_variable(script, *args++);

    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    f32 scale = evt_get_float_variable(script, *args++);

    effect->data->pos.x = x;
    effect->data->pos.y = y;
    effect->data->pos.z = z;
    effect->data->scale = scale;

    return ApiStatus_DONE2;
}

EvtScript N(idle_80223E98) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_SELF, LW(0))
    EVT_IF_NE(LW(0), FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(4))
            EVT_IF_NOT_FLAG(LW(4), STATUS_FLAG_SHRINK)
                EVT_ADD(LW(2), 15)
                EVT_SETF(LW(4), EVT_FLOAT(1.0))
            EVT_ELSE
                EVT_ADD(LW(2), 6)
                EVT_SETF(LW(4), EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_CALL(func_80218680_4FF0D0, LW(0), LW(1), LW(2), LW(3), LW(4))
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80223FD8) = {
    EVT_SET(LW(1), 7077902)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_SET(LW(1), 7077899)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80224038) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_tubbas_heart_Palette_00_Anim_10)
            EVT_SET_CONST(LW(2), NPC_ANIM_tubbas_heart_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_3)
            EVT_EXEC_WAIT(N(802244DC))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET(LW(1), 7077889)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_SET(LW(1), 7077899)
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_3)
            EVT_EXEC_WAIT(N(802244DC))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_tubbas_heart_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorHP, ACTOR_SELF, LW(0))
    EVT_IF_LE(LW(0), 5)
        EVT_EXEC_WAIT(N(80224414))
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80224414) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0E, 0x00C6), ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_D, NPC_ANIM_tubbas_heart_Palette_00_Anim_D)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_20000 | BS_FLAGS1_40000, 1)
    EVT_CALL(func_8026F60C, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(802244DC) = {
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 45)
    EVT_SET(LW(1), 0)
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802245C8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_IF_NE(LW(0), HIT_RESULT_MISS)
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
        EVT_IF_NOT_FLAG(LW(0), 0x00000001)
            EVT_CALL(GetCurrentPartnerID, LW(0))
            EVT_IF_EQ(LW(0), 9)
                EVT_CALL(func_802535B4, 0)
                EVT_BITWISE_OR_CONST(LW(0), 0x3)
                EVT_CALL(SetActorVar, ACTOR_SELF, 2, LW(0))
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 40)
                EVT_WAIT_FRAMES(40)
                EVT_CALL(ActorSpeak, MESSAGE_ID(0x0E, 0x00C3), ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_B, NPC_ANIM_tubbas_heart_Palette_00_Anim_1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_PARTNER)
                EVT_CALL(MoveBattleCamOver, 25)
                EVT_WAIT_FRAMES(25)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, 1, NPC_ANIM_battle_bow_Palette_00_Anim_4)
                EVT_CALL(ActorSpeak, MESSAGE_ID(0x0E, 0x00C4), ACTOR_PARTNER, 1, NPC_ANIM_battle_bow_Palette_00_Anim_4, NPC_ANIM_battle_bow_Palette_00_Anim_1)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, 1, NPC_ANIM_battle_bow_Palette_00_Anim_F)
                EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, -1, -1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(0))
                    EVT_IF_NE(LW(0), 0)
                        EVT_CALL(func_802535B4, 1)
                    EVT_END_IF
                EVT_ELSE
                    EVT_CALL(func_802535B4, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 40)
                EVT_WAIT_FRAMES(40)
                EVT_CALL(ActorSpeak, MESSAGE_ID(0x0E, 0x00C5), ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_B, NPC_ANIM_tubbas_heart_Palette_00_Anim_1)
            EVT_END_IF
            EVT_EXEC_WAIT(N(80225258))
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
            EVT_IF_FLAG(LW(0), 0x00000002)
                EVT_CALL(func_802535B4, 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(802255D8))
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(1))
                EVT_ADD(LW(1), 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 5, LW(1))
                EVT_IF_GE(LW(1), 2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
                EVT_ELSE
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_EXEC_WAIT(N(80224B3C))
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_BITWISE_AND_CONST(LW(0), -3)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80224B3C) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_3)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 45)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 40)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_16)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_3)
            EVT_EXEC_WAIT(N(802244DC))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 30)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(8)
            EVT_IF_EQ(LW(15), HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_3)
            EVT_EXEC_WAIT(N(802244DC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80225258) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 85, 50, 0)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_B)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(4))
    EVT_IF_NOT_FLAG(LW(4), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(1), 15)
        EVT_SETF(LW(3), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_ADD(LW(1), 6)
        EVT_SETF(LW(3), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(PlayEffect, EFFECT_ID_47, 1, LW(0), LW(1), LW(2), LW(3), 60, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, EFFECT_ID_6B, 6, LW(0), LW(1), LW(2), LW(3), 60, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F7)
    EVT_WAIT_FRAMES(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(4))
    EVT_IF_NOT_FLAG(LW(4), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(1), 15)
        EVT_SETF(LW(3), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_ADD(LW(1), 6)
        EVT_SETF(LW(3), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(PlayEffect, EFFECT_ID_6B, 3, LW(0), LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, LW(15))
    EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80223C1C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(802255D8) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 85, 50, 0)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
    EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(1), 16)
    EVT_ELSE
        EVT_ADD(LW(1), 6)
    EVT_END_IF
    EVT_CALL(PlayEffect, EFFECT_ID_13, 0, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 45, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tubbas_heart_Palette_00_Anim_B)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_SUB(LW(0), 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LW(0))
        EVT_CALL(RemoveEffect, LW(0))
        EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80223BC0)))
    EVT_END_IF
    EVT_CALL(PlaySound, 0x20F9)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 5)
            EVT_CALL(PlayEffect, EFFECT_ID_66, 1, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 200, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(145)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_ELSE
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 5)
    EVT_CALL(PlayEffect, EFFECT_ID_66, 0, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 200, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(160)
        EVT_CALL(PlaySound, 0x20FC)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1002B)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, 35)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT_FRAMES(56)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x3DB)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000C)
    EVT_WAIT_FRAMES(37)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x3DB)
    EVT_WAIT_FRAMES(22)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x20FB)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 12, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_RETURN
    EVT_END
};
