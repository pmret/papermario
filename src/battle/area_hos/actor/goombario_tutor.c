#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/npc/battle_goombario.h"

#define NAMESPACE b_area_hos_goombario_tutor

s32 N(idleAnimations_80219010)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_goombario_default_idle,
    STATUS_STONE,     NPC_ANIM_battle_goombario_default_still,
    STATUS_SLEEP,     NPC_ANIM_battle_goombario_default_still,
    STATUS_POISON,    NPC_ANIM_battle_goombario_default_idle,
    STATUS_STOP,      NPC_ANIM_battle_goombario_default_still,
    STATUS_STATIC,    NPC_ANIM_battle_goombario_default_still,
    STATUS_PARALYZE,  NPC_ANIM_battle_goombario_default_still,
    STATUS_DIZZY,     NPC_ANIM_battle_goombario_default_still,
    STATUS_DIZZY,     NPC_ANIM_battle_goombario_default_still,
    STATUS_END,
};

s32 N(defenseTable_8021905C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80219068)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
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

ActorPartBlueprint N(partsTable_80219114)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -4, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219010),
        .defenseTable = N(defenseTable_8021905C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

extern EvtScript N(init_80219160);

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_40000,
    .type = ACTOR_TYPE_GOOMBARIO_TUTOR1,
    .level = 99,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_80219114)),
    .partsData = N(partsTable_80219114),
    .script = N(init_80219160),
    .statusTable = N(statusTable_80219068),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 24, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80219444);
extern EvtScript N(idle_802191D0);
extern EvtScript N(handleEvent_802191E0);
extern EvtScript N(80219C74);

EvtScript N(init_80219160) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80219444)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_802191D0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802191E0)))
    EVT_CALL(SetActorVar, -127, 0, 1)
    EVT_EXEC(N(80219C74))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802191D0) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802191E0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(10)
                EVT_CALL(GetActorVar, -127, 0, LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_CALL(RandInt, 2, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_EQ(0)
                            EVT_CALL(ActorSpeak, 655405, -127, 1, 589834, 589826)
                        EVT_CASE_EQ(1)
                            EVT_CALL(ActorSpeak, 655406, -127, 1, 589834, 589826)
                        EVT_CASE_EQ(2)
                    EVT_END_SWITCH
                EVT_END_IF
        EVT_END_SWITCH
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(48)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(1000)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80219444) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk)
    EVT_CALL(UseBattleCamPreset, 66)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -10, 0, 0)
    EVT_CALL(GetBattleFlags2, LW(0))
    EVT_IF_FLAG(LW(0), 0x200)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 10, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_SET(LW(0), 0)
        EVT_LOOP(4)
            EVT_ADD(LW(0), 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(LoadActionCommand, 1)
        EVT_CALL(action_command_jump_CreateHudElements)
        EVT_CALL(func_802694A4, 1)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(func_802A9120_421B10, 12, 3)
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_JUMP_3E2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 22, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActionCommandMode, LW(0))
    EVT_IF_EQ(LW(0), 2)
        EVT_CALL(SetActionCommandMode, 3)
        EVT_LOOP(0)
            EVT_CALL(GetActionCommandMode, LW(0))
            EVT_IF_LT(LW(0), 2)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(func_80269EAC, 5)
    EVT_END_IF
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, 32)
    EVT_CALL(CloseActionCommandInfo)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(10)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

ApiStatus func_80218000_47F0B0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->currentPartner = PARTNER_GOOMBARIO;
    return ApiStatus_DONE2;
}

EvtScript N(80219C74) = {
    EVT_CALL(SetBattleFlagBits, 33554432, 1)
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(WaitForState, 13)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_PARTNER, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, FALSE, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655385, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(func_8026E020, 1)
    EVT_CALL(SetActionCommandMode, 2)
    EVT_CALL(WaitForState, 18)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, -73, 40, 202)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 20, 10)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655386, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionCommandMode, 1)
    EVT_CALL(SetBattleFlagBits, 16384, 0)
    EVT_CALL(SetMessageBoxDuration, -1)
    EVT_THREAD
        EVT_LOOP(15)
            EVT_CALL(SetMessageBoxDuration, 35)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 20, 10)
    EVT_CALL(SetActionCommandMode, 2)
    EVT_CALL(WaitForState, 0)
    EVT_CALL(SetBattleFlagBits2, 512, 1)
    EVT_LOOP(0)
        EVT_CALL(GetActionCommandMode, LW(0))
        EVT_IF_NE(LW(0), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655387, 256, 1, 2097161, 2097157)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, 32768, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(CheckButtonPress, 32768, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionSuccess, 1)
    EVT_CALL(SetActionCommandMode, 1)
    EVT_CALL(WaitForState, 8)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655389, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(WaitForState, 9)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655390, 512, 1, 589839, 589825)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionCommandMode, 2)
    EVT_CALL(WaitForState, 0)
    EVT_LOOP(0)
        EVT_CALL(GetActionCommandMode, LW(0))
        EVT_IF_NE(LW(0), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655391, 256, 1, 2097161, 2097157)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, 32768, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(CheckButtonPress, 32768, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionSuccess, 1)
    EVT_CALL(SetActionCommandMode, -1)
    EVT_CALL(WaitForState, 6)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetActionCommandMode, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655392, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(WaitForState, 13)
    EVT_CALL(func_8026E020, 2)
    EVT_CALL(SetActionCommandMode, 2)
    EVT_CALL(WaitForState, 18)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655394, 256, 1, 2097161, 2097157)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, 262144, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(CheckButtonPress, 262144, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionCommandMode, 1)
    EVT_CALL(WaitForState, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActionCommandMode, 2)
    EVT_LOOP(0)
        EVT_CALL(GetActionCommandMode, LW(0))
        EVT_IF_NE(LW(0), 2)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 262144, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_CALL(SetActionCommandMode, -1)
            EVT_CALL(PauseTakeTurn, 0)
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            EVT_CALL(ActorSpeak, 655395, 256, 1, 2097161, 2097157)
            EVT_LOOP(0)
                EVT_CALL(CheckButtonPress, 262144, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(EndActorSpeech, 256, 1, 2097161, 2097157)
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
            EVT_CALL(SetActionCommandMode, 2)
            EVT_CALL(ResumeTakeTurn, 0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetActionResult, LW(0))
        EVT_IF_EQ(LW(0), 3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655396, 256, 1, 2097161, 2097157)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, 262144, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionSuccess, 1)
    EVT_CALL(SetActionCommandMode, 1)
    EVT_CALL(WaitForState, 8)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655397, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_ATTACK, 1)
    EVT_CALL(WaitForState, 0)
    EVT_CALL(WaitForState, 13)
    EVT_CALL(ShowBattleChoice, 1966109)
    EVT_CALL(EndActorSpeech, 256, 1, 2097161, 2097157)
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(ActorSpeak, 655399, 256, 1, 2097161, 2097157)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655400, 256, 1, 2097161, 2097157)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetBattleFlagBits2, 512, 0)
    EVT_LABEL(10)
    EVT_CALL(func_8026E020, 131)
    EVT_CALL(SetActionCommandMode, 2)
    EVT_CALL(WaitForState, 18)
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_IF_EQ(LW(0), 7)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(SetActionCommandMode, 1)
    EVT_CALL(WaitForState, 8)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(func_80269524, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(-1)
            EVT_CALL(ActorSpeak, 655402, 256, 1, 2097161, 2097157)
        EVT_CASE_EQ(0)
            EVT_CALL(ActorSpeak, 655403, 256, 1, 2097161, 2097157)
        EVT_CASE_EQ(1)
            EVT_CALL(ActorSpeak, 655401, 256, 1, 2097161, 2097157)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetEnemyHP, 512, 99)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_ATTACK, 0)
    EVT_CALL(SetActionCommandMode, 1)
    EVT_CALL(WaitForState, 6)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(GetBlockResult, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(-1)
            EVT_CALL(ActorSpeak, 655402, 256, 1, 2097161, 2097157)
        EVT_CASE_EQ(0)
            EVT_CALL(ActorSpeak, 655403, 256, 1, 2097161, 2097157)
        EVT_CASE_EQ(1)
            EVT_CALL(ActorSpeak, 655401, 256, 1, 2097161, 2097157)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(WaitForState, 13)
    EVT_GOTO(10)
    EVT_LABEL(99)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, 655404, 256, 1, 2097161, 2097157)
    EVT_LABEL(100)
    EVT_CALL(WaitForState, 0)
    EVT_CALL(SetBattleState, 30)
    EVT_CALL(func_80218000_47F0B0)
    EVT_WAIT_FRAMES(10000)
    EVT_RETURN
    EVT_END
};
