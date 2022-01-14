#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/lee.h"
#include "sprite/npc/battle_bombette.h"
#include "sprite/npc/battle_bow.h"
#include "sprite/npc/battle_goombario.h"
#include "sprite/npc/battle_kooper.h"
#include "sprite/npc/battle_lakilester.h"
#include "sprite/npc/battle_parakarry.h"
#include "sprite/npc/battle_sushie.h"
#include "sprite/npc/battle_watt.h"

#define NAMESPACE b_area_mac_lee

s32 N(idleAnimations_8021D360)[] = {
    STATUS_NORMAL,    NPC_ANIM_lee_Palette_00_Anim_2,
    STATUS_STONE,     NPC_ANIM_lee_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_lee_Palette_00_Anim_E,
    STATUS_POISON,    NPC_ANIM_lee_Palette_00_Anim_2,
    STATUS_STOP,      NPC_ANIM_lee_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_lee_Palette_00_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_lee_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_lee_Palette_00_Anim_F,
    STATUS_DIZZY,     NPC_ANIM_lee_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(idleAnimations_8021D3AC)[] = {
    STATUS_NORMAL,    NPC_ANIM_lee_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(unk_missing_8021D3B8)[] = {
    0x00000001, 0x00A40004, 0x00000000,
};

s32 N(defenseTable_8021D3C4)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021D3D0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 75,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 75,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, -1,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021D47C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 25 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D360),
        .defenseTable = N(defenseTable_8021D3C4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -266,
    },
};

extern EvtScript N(init_8021D4C8);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_LEE,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_8021D47C)),
    .partsData = N(partsTable_8021D47C),
    .script = N(init_8021D4C8),
    .statusTable = N(statusTable_8021D3D0),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 36, 36 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80229F9C);
extern EvtScript N(idle_8021D5B4);
extern EvtScript N(handleEvent_8021D600);
extern EvtScript N(nextTurn_8022A038);
extern EvtScript N(copyPartner);

extern s32 D_80232C20[];
extern s32 D_80232C50;

ApiStatus func_802180D0_464560(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_80232C20[i] = 0;
    }
    D_80232C50 = -1;
    return ApiStatus_DONE2;
}

EvtScript N(init_8021D4C8) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80229F9C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021D5B4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021D600)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_8022A038)))
    EVT_CALL(SetActorVar, -127, 8, 0)
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_EXEC_WAIT(N(copyPartner))
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(func_802180D0_464560)
    EVT_CALL(SetBattleFlagBits, 8388608, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021D5B4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D5C4) = {
    EVT_SET_CONST(LW(0), 0x00000001)
    EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_4)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021D600) = {
    EVT_CALL(SetActorVar, -127, 0, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(8021D5C4))
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_4)
            EVT_SET_CONST(LW(2), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_lee_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(flyingTackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorVar, -127, 8, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_lee_Palette_00_Anim_8)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorSounds, -127, 2, 715, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_lee_Palette_00_Anim_9)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.30078125))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 17, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_lee_Palette_00_Anim_2)
            EVT_CALL(ResetActorSounds, -127, 2)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(8021D5C4))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_lee_Palette_00_Anim_9)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), 0x80000)
        EVT_CALL(AddGoalPos, ACTOR_SELF, EVT_FLOAT(4.0), EVT_FLOAT(-6.0), 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -15, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.30078125))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 5, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(ResetActorSounds, -127, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_lee_Palette_00_Anim_A)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021D5C4))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E0E0) = {
    EVT_CALL(GetActorVar, -127, 0, LW(0))
    EVT_CALL(RemoveActor, LW(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E118) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GetActorVar, -127, 0, LW(10))
    EVT_CALL(UseIdleAnimation, LW(10), FALSE)
    EVT_CALL(func_8027D32C, LW(10))
    EVT_CALL(CopyStatusEffects, -127, LW(10))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 3)
        EVT_ADD(LW(2), 5)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, 0x1, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(5)
    EVT_CALL(GetActorHP, -127, LW(11))
    EVT_CALL(SetEnemyHP, LW(10), LW(11))
    EVT_CALL(CopyBuffs, -127, LW(10))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(11), LW(12), LW(13))
    EVT_CALL(SetActorPos, LW(10), LW(11), LW(12), LW(13))
    EVT_CALL(SetPartFlagBits, LW(10), 1, 8388608, 1)
    EVT_CALL(SetPartFlagBits, LW(10), 1, 131073, 0)
    EVT_CALL(SetActorFlagBits, LW(10), (ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY), 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_CALL(SetActorVar, LW(10), 8, 2)
    EVT_CALL(SetPartFlagBits, -127, LW(0), 1, 1)
    EVT_CALL(SetIdleAnimations, LW(10), 1, EVT_ADDR(N(idleAnimations_8021D3AC)))
    EVT_CALL(SetAnimation, LW(10), 1, 0xA4000B)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(GetActorPos, LW(10), LW(11), LW(12), LW(13))
    EVT_IF_GT(LW(12), 0)
        EVT_SET(LW(12), 0)
        EVT_CALL(SetActorJumpGravity, LW(10), EVT_FLOAT(0.5))
        EVT_CALL(SetActorSounds, LW(10), 2, 769, 0)
        EVT_CALL(SetGoalPos, LW(10), LW(11), LW(12), LW(13))
        EVT_CALL(JumpToGoal, LW(10), 15, FALSE, TRUE, FALSE)
        EVT_CALL(ResetActorSounds, LW(10), 2)
        EVT_CALL(SetGoalPos, LW(10), LW(11), LW(12), LW(13))
        EVT_CALL(JumpToGoal, LW(10), 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, LW(10), LW(11), LW(12), LW(13))
        EVT_CALL(JumpToGoal, LW(10), 5, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_CALL(ForceHomePos, LW(10), LW(11), LW(12), LW(13))
    EVT_CALL(HPBarToHome, LW(10))
    EVT_CALL(SetIdleAnimations, LW(10), 1, EVT_ADDR(N(idleAnimations_8021D360)))
    EVT_CALL(SetAnimation, LW(10), 1, 0xA40002)
    EVT_CALL(SetActorPos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, -127)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E5DC) = {
    EVT_CALL(func_8027D32C, -127)
    EVT_SET(LW(10), LW(0))
    EVT_SET(LW(11), LW(1))
    EVT_SET(LW(12), LW(2))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), LW(11))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 15)
    EVT_ADD(LW(1), 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1005859375))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), LW(11))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
    EVT_SET(LW(0), LW(10))
    EVT_SET(LW(1), LW(11))
    EVT_EXEC_WAIT(DoShockHit)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, -127, 0, LW(12), 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LW(0), -48)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 60)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.400390625))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021E940) = { 0, -1000, 0 };

s32 N(idleAnimations_8021E94C)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_goombario_default_idle,
    STATUS_STONE,     NPC_ANIM_battle_goombario_default_still,
    STATUS_SLEEP,     NPC_ANIM_battle_goombario_default_still,
    STATUS_POISON,    NPC_ANIM_battle_goombario_default_idle,
    STATUS_STOP,      NPC_ANIM_battle_goombario_default_still,
    STATUS_STATIC,    NPC_ANIM_battle_goombario_default_idle,
    STATUS_PARALYZE,  NPC_ANIM_battle_goombario_default_still,
    STATUS_DIZZY,     NPC_ANIM_battle_goombario_default_daze,
    STATUS_FEAR,      NPC_ANIM_battle_goombario_default_daze,
    STATUS_END,
};

s32 N(defenseTable_8021E998)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021E9A4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021EA50)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021E94C),
        .defenseTable = N(defenseTable_8021E998),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -9,
    },
};

extern EvtScript N(init_Goombario);

ActorBlueprint N(goombario) = {
    .flags = 0,
    .type = ACTOR_TYPE_LEE_GOOMBARIO,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_8021EA50)),
    .partsData = N(partsTable_8021EA50),
    .script = N(init_Goombario),
    .statusTable = N(statusTable_8021E9A4),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 29, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_802203F4);
extern EvtScript N(idle_8021EB14);
extern EvtScript N(handleEvent_8021EB24);
extern EvtScript N(nextTurn_80220450);

EvtScript N(init_Goombario) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802203F4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021EB14)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021EB24)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80220450)))
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021EB14) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021EB24) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_burn_pain)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_goombario_default_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_burn_pain)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_goombario_default_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_burn_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_SET(LW(2), 12)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CASE_EQ(38)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_SET(LW(2), 12)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_run)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F08C) = {
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
        EVT_SET(LW(0), 180)
        EVT_LOOP(15)
            EVT_SUB(LW(0), 60)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_fall)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 60)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), 0x80000)
        EVT_SETF(LW(5), EVT_FLOAT(7.2001953125))
    EVT_ELSE
        EVT_SET(LW(5), 18)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(5), 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_ADD(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(5), 0)
    EVT_WAIT_FRAMES(1)
    EVT_ADD(LW(0), 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(5), 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F514) = {
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F5F8) = {
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(11), LW(12), LW(13))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(12), LW(13), LW(14))
    EVT_IF_GT(LW(11), LW(12))
        EVT_SUB(LW(11), LW(12))
    EVT_ELSE
        EVT_SUB(LW(12), LW(11))
        EVT_SET(LW(11), LW(12))
    EVT_END_IF
    EVT_SUB(LW(11), 20)
    EVT_DIVF(LW(11), EVT_FLOAT(10.5888671875))
    EVT_ADDF(LW(11), 15)
    EVT_SET(LW(10), LW(11))
    EVT_RETURN
    EVT_END
};

ApiStatus func_80218100_464590(Evt*, s32);
INCLUDE_ASM(s32, "battle/area_mac/actor/lee", func_80218100_464590);

ApiStatus func_80218300_464790(Evt*, s32);
INCLUDE_ASM(s32, "battle/area_mac/actor/lee", func_80218300_464790);

#include "common/ActorJumpToPos.inc.c"

EvtScript N(8021F6E0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(8021F514))
    EVT_EXEC_WAIT(N(8021F5F8))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), 0x80000)
        EVT_SETF(LW(0), EVT_FLOAT(7.2001953125))
        EVT_SETF(LW(1), EVT_FLOAT(7.6005859375))
        EVT_SETF(LW(1), EVT_FLOAT(3.6005859375))
    EVT_ELSE
        EVT_SET(LW(0), 18)
        EVT_SET(LW(1), 19)
        EVT_SET(LW(2), 9)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(0), 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(1), 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(2), 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
    EVT_CALL(func_80218300_464790, LW(10), 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(N(ActorJumpToPos))
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
            EVT_END_THREAD
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021F08C))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.1005859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.30078125), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, 16)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, 16)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, 16)
    EVT_END_SWITCH
    EVT_CALL(GetActorHP, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_SET(LW(10), 24)
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_SET(LW(0), 0)
                EVT_LOOP(6)
                    EVT_ADD(LW(0), 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(func_80218300_464790, LW(10), 3)
        EVT_CASE_EQ(1)
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_SET(LW(0), 0)
                EVT_LOOP(6)
                    EVT_ADD(LW(0), 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, -127, 1)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(func_80218300_464790, LW(10), 3)
            EVT_CALL(EnableActorBlur, -127, 0)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_SET(LW(0), 0)
                EVT_LOOP(6)
                    EVT_ADD(LW(0), 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, -250000000, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_END_THREAD
            EVT_THREAD
                EVT_SET(LW(0), 0)
                EVT_LOOP(LW(10))
                    EVT_ADD(LW(0), 133)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, -250000000, LW(0), -250000000)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, -127, 1)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(func_80218300_464790, LW(10), 3)
            EVT_CALL(EnableActorBlur, -127, 0)
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.1005859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.30078125), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, 32)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, 32)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, 32)
    EVT_END_SWITCH
    EVT_LABEL(100)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021F08C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkActorSizeFunc.inc.c"

#include "common/UnkEffect6CFunc.inc.c"

ApiStatus func_80218DF4_465284(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkStruct0* unkStruct0 = (UnkStruct0*)evt_get_variable(script, *args++);

    unkStruct0->unk_0C->unk_08 = -1000.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80218E2C_4652BC(Evt* script, s32 isInitialCall) {
    UnkStruct0* unkStruct0 = (UnkStruct0*) evt_get_variable(script, *script->ptrReadPos);

    unkStruct0->unk_0C->unk_08 = 144.0f;
    unkStruct0->flags |= 0x10;
    return ApiStatus_DONE2;
}

EvtScript N(80220100) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetBattleFlagBits, 4, 1)
    EVT_CALL(N(UnkEffect6CFunc), LW(5))
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetCamEnabled, 2, 1)
    EVT_CALL(SetCamFlag80, 2, 0)
    EVT_CALL(SetCamPerspective, 2, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, 2, 37, 95, 138, 99)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 8)
    EVT_SET(LW(1), 0)
    EVT_CALL(N(UnkActorSizeFunc))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(func_802CAE50, 2, LW(0), LW(1), LW(2))
    EVT_CALL(func_802CABE8, 2, 0, LW(3), 100, 4)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_282)
    EVT_CALL(SetCamFlag80, 2, 1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ActorSpeak, 1835154, -127, 1, 589839, 589825)
    EVT_CALL(func_80218E2C_4652BC, LW(5))
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetCamEnabled, 2, 0)
    EVT_WAIT_FRAMES(32)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(SetBattleFlagBits, 4, 0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802203F4) = {
    EVT_CALL(RandInt, 100, LW(0))
    EVT_IF_LT(LW(0), 40)
        EVT_EXEC_WAIT(N(80220100))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8021F6E0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80220450) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_goombario) = {
    { .actor = &N(goombario), .home = { .vec = &N(vector3D_8021E940) }},
};

s32 N(idleAnimations_80220540)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_kooper_Palette_00_Anim_4,
    STATUS_STONE,     NPC_ANIM_battle_kooper_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_kooper_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_battle_kooper_Palette_00_Anim_4,
    STATUS_STOP,      NPC_ANIM_battle_kooper_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_kooper_Palette_00_Anim_4,
    STATUS_PARALYZE,  NPC_ANIM_battle_kooper_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_kooper_Palette_00_Anim_1C,
    STATUS_FEAR,      NPC_ANIM_battle_kooper_Palette_00_Anim_1C,
    STATUS_END,
};

s32 N(idleAnimations_8022058C)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_kooper_Palette_00_Anim_19,
    STATUS_STONE,     NPC_ANIM_battle_kooper_Palette_00_Anim_3,
    STATUS_SLEEP,     NPC_ANIM_battle_kooper_Palette_00_Anim_3,
    STATUS_POISON,    NPC_ANIM_battle_kooper_Palette_00_Anim_19,
    STATUS_STOP,      NPC_ANIM_battle_kooper_Palette_00_Anim_3,
    STATUS_STATIC,    NPC_ANIM_battle_kooper_Palette_00_Anim_19,
    STATUS_PARALYZE,  NPC_ANIM_battle_kooper_Palette_00_Anim_3,
    STATUS_DIZZY,     NPC_ANIM_battle_kooper_Palette_00_Anim_19,
    STATUS_FEAR,      NPC_ANIM_battle_kooper_Palette_00_Anim_19,
    STATUS_END,
};

s32 N(defenseTable_802205D8)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(defenseTable_802205E4)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_802205F0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8022069C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80220540),
        .defenseTable = N(defenseTable_802205D8),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 240,
    },
};

extern EvtScript N(init_Kooper);

ActorBlueprint N(kooper) = {
    .flags = 0,
    .type = ACTOR_TYPE_LEE_KOOPER,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_8022069C)),
    .partsData = N(partsTable_8022069C),
    .script = N(init_Kooper),
    .statusTable = N(statusTable_802205F0),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 32, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80221200);
extern EvtScript N(idle_80220790);
extern EvtScript N(handleEvent_80220908);
extern EvtScript N(nextTurn_802221A0);

EvtScript N(init_Kooper) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80221200)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80220790)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80220908)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_802221A0)))
    EVT_CALL(SetActorVar, -127, 4, 0)
    EVT_CALL(SetActorVar, -127, 5, 0)
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

#define NAMESPACE b_area_mac_lee_kooper
#include "common/UnkBattleFunc1.inc.c"
#define NAMESPACE b_area_mac_lee

EvtScript N(idle_80220790) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, -127, 4, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetTargetOffset, -127, 1, -2, 38)
            EVT_CALL(func_8027D4C8, -127, 1, -3, -9)
            EVT_CALL(N(kooper_UnkBattleFunc1), -10, 25, 10, 25)
        EVT_CASE_EQ(1)
            EVT_CALL(SetTargetOffset, -127, 1, 5, 15)
            EVT_CALL(func_8027D4C8, -127, 1, 0, -6)
            EVT_CALL(N(kooper_UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_802208B0)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

EvtScript N(handleEvent_80220908) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_12)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_kooper_Palette_00_Anim_13)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_12)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_kooper_Palette_00_Anim_13)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_13)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(13)
            EVT_CALL(SetActorVar, -127, 4, 1)
            EVT_CALL(SetActorVar, -127, 5, 1)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_802205E4)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022058C)))
            EVT_CALL(SetTargetOffset, -127, 1, 5, 15)
            EVT_CALL(func_8027D4C8, -127, 1, 0, -6)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                EVT_WAIT_FRAMES(1)
            EVT_END_THREAD
            EVT_USE_BUF(EVT_ADDR(N(intTable_802208B0)))
            EVT_LOOP(22)
                EVT_BUF_READ1(LW(0))
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(0), 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_19)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LW(0), 0x00000001)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_4)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                    EVT_SET_CONST(LW(0), 0x00000001)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_19)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_19)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_4)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LW(0), 0x00000001)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_6)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                    EVT_SET_CONST(LW(0), 0x00000001)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_19)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                    EVT_IF_NOT_FLAG(LW(0), 0x35D000)
                        EVT_IF_FLAG(LW(0), 0x80000)
                            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                        EVT_ELSE
                            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                        EVT_END_IF
                    EVT_END_IF
                    EVT_SET_CONST(LW(0), 0x00000001)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_6)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LW(0), 0x00000001)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_19)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkActorPosFunc.inc.c"

EvtScript N(takeTurn_80221200) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, -127, 4, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetActorVar, -127, 5, LW(0))
        EVT_SUB(LW(0), 1)
        EVT_IF_GT(LW(0), 0)
            EVT_CALL(SetActorVar, -127, 5, LW(0))
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_WAIT_FRAMES(30)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
        EVT_ELSE
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_19)
            EVT_SET(LW(0), 0)
            EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
            EVT_THREAD
                EVT_LOOP(5)
                    EVT_ADD(LW(0), 15)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
            EVT_CALL(SetActorVar, -127, 4, 0)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_802205D8)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80220540)))
            EVT_CALL(SetTargetOffset, -127, 1, -2, 38)
            EVT_CALL(func_8027D4C8, -127, 1, -3, -9)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_E)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x200C)
    EVT_CALL(UseBattleCamPreset, 14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 75)
    EVT_CALL(func_8024ECF8, 1, 1, 1)
    EVT_CALL(GetActorVar, -127, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_SET(LW(0), 10)
        EVT_CASE_EQ(1)
            EVT_SET(LW(0), 20)
        EVT_CASE_EQ(2)
            EVT_SET(LW(0), 30)
    EVT_END_SWITCH
    EVT_SET(LW(9), 0)
    EVT_LOOP(LW(0))
        EVT_ADD(LW(9), 1)
        EVT_SWITCH(LW(9))
            EVT_CASE_LT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, 0x1D, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(40)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_B)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, 0x1D, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(50)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_C)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
            EVT_CASE_EQ(50)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, 0x1D, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(60)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_D)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CASE_EQ(60)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, 0x1D, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x200A)
    EVT_CALL(SetActorSounds, -127, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_CALL(N(UnkActorPosFunc))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_9)
            EVT_CALL(SetActorRotationOffset, -127, -8, 0, 0)
            EVT_SET(LW(0), 0)
            EVT_LOOP(2)
                EVT_ADD(LW(0), 30)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(5)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
            EVT_CALL(PlayEffect, 0x1D, 1, LW(4), LW(5), LW(6), 16, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_LOOP(5)
                EVT_ADD(LW(0), -12)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.5))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 2, 32)
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 3, 32)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 5, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 8)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 60)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.400390625))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.5))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_802221A0) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_kooper) = {
    { .actor = &N(kooper), .home = { .vec = &N(vector3D_8021E940) }}
};

s32 N(idleAnimations_80222290)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_bombette_Palette_00_Anim_4,
    STATUS_STONE,     NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_battle_bombette_Palette_00_Anim_4,
    STATUS_STOP,      NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_bombette_Palette_00_Anim_4,
    STATUS_PARALYZE,  NPC_ANIM_battle_bombette_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_bombette_Palette_00_Anim_1E,
    STATUS_FEAR,      NPC_ANIM_battle_bombette_Palette_00_Anim_1E,
    STATUS_END,
};

s32 N(defenseTable_802222DC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_802222E8)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80222394)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80222290),
        .defenseTable = N(defenseTable_802222DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -263,
    },
};

extern EvtScript N(init_LeeBombette);

ActorBlueprint N(bombette) = {
    .flags = 0,
    .type = ACTOR_TYPE_LEE_BOMBETTE,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_80222394)),
    .partsData = N(partsTable_80222394),
    .script = N(init_LeeBombette),
    .statusTable = N(statusTable_802222E8),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 30, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_802229C4);
extern EvtScript N(idle_80222458);
extern EvtScript N(handleEvent_80222468);
extern EvtScript N(nextTurn_80223298);

EvtScript N(init_LeeBombette) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802229C4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80222458)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80222468)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80223298)))
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80222458) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80222468) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_13)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bombette_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_13)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bombette_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_SET(LW(2), 15)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CASE_EQ(38)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_SET(LW(2), 15)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_8)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#define NAMESPACE b_area_mac_lee_bombette
#include "common/UnkActorPosFunc.inc.c"
#define NAMESPACE b_area_mac_lee

EvtScript N(takeTurn_802229C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
    EVT_CALL(RunToGoal, ACTOR_SELF, 30, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_F)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetActorSounds, -127, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2020)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -10, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_10)
            EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 15, 0)
                EVT_SET(LW(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LW(0), 72)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, -60, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
            EVT_THREAD
                EVT_CALL(N(bombette_UnkActorPosFunc))
            EVT_END_THREAD
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_SET(LW(10), LW(0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_10)
    EVT_CALL(RunToGoal, ACTOR_SELF, 4, FALSE)
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, 32)
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, 32)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 5, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.400390625))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_ADD(LW(0), 40)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_11)
            EVT_ADD(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_E)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_4)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bombette_Palette_00_Anim_8)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80223298) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bombette_Palette_00_Anim_12)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_bombette) = {
    { .actor = &N(bombette), .home = { .vec = &N(vector3D_8021E940) }}
};

s32 N(idleAnimations_80223388)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_FEAR,      NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(defenseTable_802233D4)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_802233E0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8022348C)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80223388),
        .defenseTable = N(defenseTable_802233D4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 240,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -3, -18 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_802233D4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 240,
    },
};

extern EvtScript N(init_Parakarry);

ActorBlueprint N(parakerry) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_PARAKARRY,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_8022348C)),
    .partsData = N(partsTable_8022348C),
    .script = N(init_Parakarry),
    .statusTable = N(statusTable_802233E0),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 38, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80224304);
extern EvtScript N(idle_80223574);
extern EvtScript N(handleEvent_80223584);
extern EvtScript N(nextTurn_80224320);

EvtScript N(init_Parakarry) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80224304)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80223574)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80223584)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80224320)))
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80223574) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80223584) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_F)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_parakarry_Palette_00_Anim_10)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_F)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_parakarry_Palette_00_Anim_10)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_10)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_D)
            EVT_SET(LW(2), 22)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, 0)
        EVT_CASE_EQ(38)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_D)
            EVT_SET(LW(2), 22)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_parakarry_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x35D000)
                EVT_IF_FLAG(LW(0), 0x80000)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80223B74) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_0)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(func_8024E664, 1)
    EVT_CALL(SetActorSounds, -127, 1, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2004)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_14)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 10, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_4)
    EVT_END_THREAD
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 15, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, -20, 6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2005)
    EVT_CALL(EnableActorBlur, -127, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_5)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_1)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 10, -20, 4)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(EnableActorBlur, -127, 0)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, -127, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_6)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, 32)
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, 32)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 5, 32)
    EVT_END_SWITCH
    EVT_CALL(PlaySound, SOUND_0)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.400390625))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_0)
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpWithBounce, -127, 10, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80224304) = {
    EVT_EXEC_WAIT(N(80223B74))
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80224320) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_parakerry) = {
    { .actor = &N(parakerry), .home = { .vec = &N(vector3D_8021E940) }}
};

s32 N(idleAnimations_80224410)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_bow_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_battle_bow_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_bow_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_bow_Palette_00_Anim_1A,
    STATUS_FEAR,      NPC_ANIM_battle_bow_Palette_00_Anim_1A,
    STATUS_END,
};

s32 N(defenseTable_8022445C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80224468)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80224514)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80224410),
        .defenseTable = N(defenseTable_8022445C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -26 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_8022445C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
};

extern EvtScript N(init_Bow);

ActorBlueprint N(bow) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_BOW,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_80224514)),
    .partsData = N(partsTable_80224514),
    .script = N(init_Bow),
    .statusTable = N(statusTable_80224468),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 36, 29 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80224CA0);
extern EvtScript N(idle_802245FC);
extern EvtScript N(handleEvent_8022460C);
extern EvtScript N(nextTurn_80225884);

EvtScript N(init_Bow) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80224CA0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_802245FC)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022460C)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80225884)))
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802245FC) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022460C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_18)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bow_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_18)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bow_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_SET(LW(2), 14)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_THREAD
                EVT_SET(LW(0), 200)
                EVT_LOOP(20)
                    EVT_SUB(LW(0), 10)
                    EVT_CALL(SetPartAlpha, -127, 1, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 60)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_SET(LW(0), 55)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetPartAlpha, -127, 1, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, -127, 1, 255)
        EVT_CASE_EQ(38)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_SET(LW(2), 14)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80224CA0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_WAIT_FRAMES(10)
    EVT_THREAD
        EVT_SET(LW(0), 200)
        EVT_LOOP(20)
            EVT_SUB(LW(0), 10)
            EVT_CALL(SetPartAlpha, -127, 1, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPreset, 1)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_3)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
        EVT_IF_FLAG(LW(10), 0x80000)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 4, -4, 0)
        EVT_ELSE
            EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -10, 0)
        EVT_END_IF
        EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseBattleCamPreset, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_SET(LW(0), 55)
    EVT_LOOP(20)
        EVT_ADD(LW(0), 10)
        EVT_CALL(SetPartAlpha, -127, 1, LW(0))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, -127, 1, 255)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.400390625), EVT_FLOAT(1.400390625), EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_7)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LW(0), 0)
            EVT_LOOP(20)
                EVT_ADD(LW(0), -45)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1A)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 3)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(YieldTurn)
            EVT_THREAD
                EVT_SET(LW(0), 200)
                EVT_LOOP(20)
                    EVT_SUB(LW(0), 10)
                    EVT_CALL(SetPartAlpha, -127, 1, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 60)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_SET(LW(0), 55)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetPartAlpha, -127, 1, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, -127, 1, 255)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_SET(LW(10), 0)
    EVT_CALL(GetActorVar, -127, 1, LW(8))
    EVT_SWITCH(LW(8))
        EVT_CASE_EQ(0)
            EVT_SET(LW(8), 4)
        EVT_CASE_EQ(1)
            EVT_SET(LW(8), 5)
        EVT_CASE_EQ(2)
            EVT_SET(LW(8), 6)
    EVT_END_SWITCH
    EVT_SET(LW(7), LW(8))
    EVT_LOOP(LW(7))
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2019)
        EVT_ADD(LW(10), 1)
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.400390625), EVT_FLOAT(1.400390625), EVT_FLOAT(1.0))
        EVT_IF_EQ(LF(0), 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_7)
            EVT_SET(LF(0), 1)
            EVT_IF_EQ(LW(10), LW(8))
                EVT_CALL(func_80269EAC, 12)
            EVT_ELSE
                EVT_CALL(func_80269EAC, 10)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_8)
            EVT_SET(LF(0), 0)
            EVT_IF_EQ(LW(10), LW(8))
                EVT_CALL(func_80269EAC, 13)
            EVT_ELSE
                EVT_CALL(func_80269EAC, 11)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.5))
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.2001953125))
        EVT_END_THREAD
        EVT_CALL(GetActorVar, -127, 1, LW(9))
        EVT_SWITCH(LW(9))
            EVT_CASE_EQ(0)
                EVT_WAIT_FRAMES(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, 16)
            EVT_CASE_EQ(1)
                EVT_WAIT_FRAMES(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, 16)
            EVT_CASE_EQ(2)
                EVT_WAIT_FRAMES(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, 16)
        EVT_END_SWITCH
        EVT_WAIT_FRAMES(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
        EVT_CALL(GetActorHP, 0, LW(1))
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(YieldTurn)
            EVT_THREAD
                EVT_SET(LW(0), 200)
                EVT_LOOP(20)
                    EVT_SUB(LW(0), 10)
                    EVT_CALL(SetPartAlpha, -127, 1, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_SET(LW(0), 55)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetPartAlpha, -127, 1, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, -127, 1, 255)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80225884) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_bow) = {
    { .actor = &N(bow), .home = { .vec = &N(vector3D_8021E940) }}
};

s32 N(idleAnimations_80225974)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_watt_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_battle_watt_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_watt_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_watt_Palette_00_Anim_F,
    STATUS_FEAR,      NPC_ANIM_battle_watt_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(defenseTable_802259C0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 99,
    ELEMENT_END,
};

s32 N(statusTable_802259D4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80225A80)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -1, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80225974),
        .defenseTable = N(defenseTable_802259C0),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .unk_1C = 248,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -1, -30 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_802259C0),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .unk_1C = 248,
    },
};

extern EvtScript N(init_Watt);

ActorBlueprint N(watt) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_WATT,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_80225A80)),
    .partsData = N(partsTable_80225A80),
    .script = N(init_Watt),
    .statusTable = N(statusTable_802259D4),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 34, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80226004);
extern EvtScript N(idle_80225B68);
extern EvtScript N(handleEvent_80225B90);
extern EvtScript N(nextTurn_80226880);

EvtScript N(init_Watt) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80226004)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80225B68)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80225B90)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80226880)))
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

ApiStatus func_80219188_465618(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_mac/actor/lee", func_80219188_465618);

ApiStatus func_80219604_465A94(Evt* script, s32 isInitialCall) {
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.actorID)->state.varTable[3];

    unkDuplighost->flags = 0;

    if (unkDuplighost->effect1 != NULL) {
        unkDuplighost->effect1->flags |= EFFECT_INSTANCE_FLAGS_10;
    }

    if (unkDuplighost->effect2 != NULL) {
        unkDuplighost->effect2->flags |= EFFECT_INSTANCE_FLAGS_10;
    }

    return ApiStatus_DONE2;
}

EvtScript N(idle_80225B68) = {
    EVT_SET_PRIORITY(99)
    EVT_CALL(func_80219188_465618)
    EVT_RETURN
    EVT_END
};

ApiStatus func_80219658_465AE8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[3];

    unkDuplighost->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802196A4_465B34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[3];

    unkDuplighost->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_802196F0_465B80(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    UnkDuplighost* unkDuplighost = (UnkDuplighost*)get_actor(script->owner1.enemyID)->state.varTable[3];

    unkDuplighost->unk_10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(handleEvent_80225B90) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_80219658_465AE8, 0)
    EVT_CALL(func_802196A4_465B34, 1)
    EVT_CALL(func_802196F0_465B80, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_watt_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_watt_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(func_80219658_465AE8, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

EvtScript N(takeTurn_80226004) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseBattleCamPreset, 19)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(MoveBattleCamOver, 80)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
    EVT_CALL(func_802196F0_465B80, 1)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 15, -10, 5)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
    EVT_CALL(func_802196F0_465B80, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(func_80219658_465AE8, 0)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 25, 20, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -20, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, 10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 10, -20, 4)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(func_802196A4_465B34, 1)
            EVT_CALL(func_80219658_465AE8, 1)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(func_802196A4_465B34, 0)
    EVT_SET(LW(10), 40)
    EVT_CALL(AddBattleCamZoom, -75)
    EVT_CALL(MoveBattleCamOver, LW(10))
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x289)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), 0x80000)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 4)
        EVT_CALL(PlayEffect, 0x33, 8, LW(0), LW(1), LW(2), EVT_FLOAT(0.5205078125), LW(10), 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 12)
        EVT_CALL(PlayEffect, 0x33, 8, LW(0), LW(1), LW(2), EVT_FLOAT(1.30078125), LW(10), 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_SET(LW(9), 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_6)
    EVT_LOOP(LW(10))
        EVT_ADD(LW(9), 3)
        EVT_IF_GT(LW(9), 200)
            EVT_SET(LW(9), 200)
        EVT_END_IF
        EVT_CALL(N(SetBackgroundAlpha), LW(9))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
    EVT_CALL(func_8026EA7C, -127, 1, 9)
    EVT_CALL(AddBattleCamZoom, 75)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_THREAD
        EVT_WAIT_FRAMES(2)
        EVT_CALL(N(SetBackgroundAlpha), 0)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), (DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_IGNORE_DEFENSE), 65535, 0, 3, 32)
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), (DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_IGNORE_DEFENSE), 65535, 0, 4, 32)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), (DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_IGNORE_DEFENSE), 65535, 0, 5, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(func_802196A4_465B34, 1)
            EVT_CALL(func_80219658_465AE8, 1)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 25, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -10, 10)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80226880) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_CALL(func_80219604_465A94)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_watt) = {
    { .actor = &N(watt), .home = { .vec = &N(vector3D_8021E940) }}
};

s32 N(idleAnimations_8022697C)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_sushie_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_battle_sushie_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_sushie_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_battle_sushie_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_battle_sushie_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_sushie_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_battle_sushie_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_sushie_Palette_00_Anim_10,
    STATUS_FEAR,      NPC_ANIM_battle_sushie_Palette_00_Anim_10,
    STATUS_END,
};

s32 N(defenseTable_802269C8)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_802269D4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80226A80)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022697C),
        .defenseTable = N(defenseTable_802269C8),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 244,
    },
};

extern EvtScript N(init_Sushie);

ActorBlueprint N(sushie) = {
    .flags = 0,
    .type = ACTOR_TYPE_LEE_SUSHIE,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_80226A80)),
    .partsData = N(partsTable_80226A80),
    .script = N(init_Sushie),
    .statusTable = N(statusTable_802269D4),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 37, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_802270BC);
extern EvtScript N(idle_80226B44);
extern EvtScript N(handleEvent_80226B54);
extern EvtScript N(nextTurn_8022831C);

EvtScript N(init_Sushie) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802270BC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80226B44)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80226B54)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_8022831C)))
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80226B44) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80226B54) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_sushie_Palette_00_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_sushie_Palette_00_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_F)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_SET(LW(2), 20)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CASE_EQ(38)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_SET(LW(2), 20)
            EVT_EXEC_WAIT(N(8021E5DC))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802270BC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_SUB(LW(3), LW(0))
    EVT_DIV(LW(3), EVT_FLOAT(3.0))
    EVT_SET(LW(10), LW(3))
    EVT_IF_LT(LW(10), 0)
        EVT_MUL(LW(10), -1)
    EVT_END_IF
    EVT_CALL(MoveBattleCamOver, LW(10))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_3)
    EVT_CALL(RunToGoal, ACTOR_SELF, LW(10), FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPreset, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(AddBattleCamZoom, -50)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_8024ECF8, 1, 1, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_4)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_8)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_5)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
                EVT_SET(LW(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LW(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 20)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(GetActorVar, -127, 1, LW(0))
                EVT_SWITCH(LW(0))
                    EVT_CASE_EQ(0)
                        EVT_WAIT_FRAMES(13)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                    EVT_CASE_EQ(1)
                        EVT_WAIT_FRAMES(13)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.05078125), EVT_FLOAT(1.05078125), EVT_FLOAT(1.05078125))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.150390625), EVT_FLOAT(1.150390625), EVT_FLOAT(1.150390625))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.25), EVT_FLOAT(1.25), EVT_FLOAT(1.25))
                    EVT_CASE_EQ(2)
                        EVT_WAIT_FRAMES(13)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.30078125), EVT_FLOAT(1.30078125), EVT_FLOAT(1.30078125))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.400390625), EVT_FLOAT(1.400390625), EVT_FLOAT(1.400390625))
                        EVT_WAIT_FRAMES(1)
                        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.5))
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_CALL(SetActorSounds, -127, 2, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2034)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_5)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_6)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_7)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(LandJump, -127)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x29A)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(AddGoalPos, ACTOR_SELF, -15, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x29A)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -10, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x29A)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_5)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(10)
            EVT_ADD(LW(0), 36)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 20)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorVar, -127, 1, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(0)
                EVT_WAIT_FRAMES(13)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375), EVT_FLOAT(1.1005859375))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.30078125), EVT_FLOAT(1.30078125), EVT_FLOAT(1.30078125))
            EVT_CASE_EQ(1)
                EVT_WAIT_FRAMES(13)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.150390625), EVT_FLOAT(1.150390625), EVT_FLOAT(1.150390625))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.3505859375), EVT_FLOAT(1.3505859375), EVT_FLOAT(1.3505859375))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.400390625), EVT_FLOAT(1.400390625), EVT_FLOAT(1.400390625))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.55078125), EVT_FLOAT(1.55078125), EVT_FLOAT(1.55078125))
            EVT_CASE_EQ(2)
                EVT_WAIT_FRAMES(13)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125), EVT_FLOAT(1.2001953125))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.30078125), EVT_FLOAT(1.30078125), EVT_FLOAT(1.30078125))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.5))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.6005859375), EVT_FLOAT(1.6005859375), EVT_FLOAT(1.6005859375))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.80078125), EVT_FLOAT(1.80078125), EVT_FLOAT(1.80078125))
        EVT_END_SWITCH
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, -127, 2, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2034)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_5)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_6)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_7)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(SetPartScale, -127, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(GetActorVar, -127, 1, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, 32)
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 4, 32)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 5, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_6)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 60)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.400390625))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x29A)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x29A)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x29A)
            EVT_ADD(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x29A)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_sushie_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8022831C) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_sushie_Palette_00_Anim_D)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_sushie) = {
    { .actor = &N(sushie), .home = { .vec = &N(vector3D_8021E940) }}
};

s32 N(idleAnimations_8022840C)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_lakilester_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_battle_lakilester_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_lakilester_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_battle_lakilester_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_battle_lakilester_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_lakilester_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_battle_lakilester_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_lakilester_Palette_00_Anim_8,
    STATUS_FEAR,      NPC_ANIM_battle_lakilester_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(idleAnimations_80228458)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_lakilester_Palette_00_Anim_14,
    STATUS_END,
};

s32 N(defenseTable_80228464)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80228470)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8022851C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 33 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022840C),
        .defenseTable = N(defenseTable_80228464),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -266,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80228458),
        .defenseTable = N(defenseTable_80228464),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

extern EvtScript N(init_Lakilester);

ActorBlueprint N(lakilester) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LEE_LAKILESTER,
    .level = 0,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(partsTable_8022851C)),
    .partsData = N(partsTable_8022851C),
    .script = N(init_Lakilester),
    .statusTable = N(statusTable_80228470),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 44, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_80228B78);
extern EvtScript N(idle_80228604);
extern EvtScript N(handleEvent_80228614);
extern EvtScript N(nextTurn_80229658);

EvtScript N(init_Lakilester) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80228B78)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80228604)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80228614)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80229658)))
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80228604) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80228614) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_C)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_lakilester_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_C)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_lakilester_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
        EVT_CASE_EQ(38)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(8021E0E0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80228B78) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 20, 30, LW(2))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), 0x80000)
        EVT_ADD(LW(0), -1)
        EVT_ADD(LW(1), 4)
        EVT_ADD(LW(2), 2)
        EVT_CALL(SetPartScale, -127, 3, EVT_FLOAT(0.400390625), EVT_FLOAT(0.400390625), EVT_FLOAT(0.400390625))
    EVT_ELSE
        EVT_ADD(LW(0), -3)
        EVT_ADD(LW(1), 10)
        EVT_ADD(LW(2), 5)
        EVT_CALL(SetPartScale, -127, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetPartFlagBits, -127, 3, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_battle_lakilester_Palette_00_Anim_14)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_F)
    EVT_LOOP(4)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
        EVT_IF_FLAG(LW(10), 0x80000)
            EVT_ADDF(LW(1), EVT_FLOAT(2.400390625))
        EVT_ELSE
            EVT_ADD(LW(1), 6)
        EVT_END_IF
        EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), 0x80000)
        EVT_ADD(LW(0), -3)
        EVT_ADD(LW(1), 16)
        EVT_ADD(LW(2), 2)
        EVT_SETF(LW(3), EVT_FLOAT(0.400390625))
    EVT_ELSE
        EVT_ADD(LW(0), -8)
        EVT_ADD(LW(1), 40)
        EVT_ADD(LW(2), 5)
        EVT_SETF(LW(3), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x6B, 0, LW(0), LW(1), LW(2), LW(3), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2C5)
    EVT_THREAD
        EVT_LOOP(15)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, 1, 0, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, -1, 0, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_10)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_11)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_12)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetPartSounds, -127, 3, 2, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x201B)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_battle_lakilester_Palette_00_Anim_15)
            EVT_CALL(SetPartJumpGravity, -127, 3, EVT_FLOAT(1.5))
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(RandInt, 100, LW(3))
            EVT_SUB(LW(3), 50)
            EVT_ADD(LW(0), LW(3))
            EVT_CALL(JumpPartTo, -127, 3, LW(0), 0, LW(2), 20, 1)
            EVT_THREAD
                EVT_ADD(LW(0), -50)
                EVT_CALL(JumpPartTo, -127, 3, LW(0), 0, LW(2), 15, 1)
                EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
            EVT_END_THREAD
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 60)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_battle_lakilester_Palette_00_Anim_15)
    EVT_CALL(SetPartJumpGravity, -127, 3, EVT_FLOAT(1.5))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpPartTo, -127, 3, LW(0), LW(1), LW(2), 20, 1)
    EVT_THREAD
        EVT_ADD(LW(0), -50)
        EVT_CALL(JumpPartTo, -127, 3, LW(0), 0, LW(2), 15, 1)
        EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, -127, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, 32)
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, 32)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, 32)
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_lakilester_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80229658) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_lakilester_Palette_00_Anim_A)
            EVT_EXEC_WAIT(N(8021E118))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Formation N(formation_lakilester) = {
    { .actor = &N(lakilester), .home = { .vec = &N(vector3D_8021E940) }}
};

ApiStatus func_802197B8_465C48(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

ApiStatus func_80219824_465CB4(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_mac/actor/lee", func_80219824_465CB4);

EvtScript N(copyPartner) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, 14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(ActorSpeak, 131111, -127, 1, 10747910, 10747907)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_lee_Palette_00_Anim_7)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), 0x80000)
        EVT_ADD(LW(1), 8)
        EVT_SETF(LW(3), EVT_FLOAT(0.400390625))
    EVT_ELSE
        EVT_ADD(LW(1), 20)
        EVT_SETF(LW(3), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x13, 1, LW(0), LW(1), LW(2), LW(3), 40, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 20, 0)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(SetBackgroundAlpha), LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_802197B8_465C48, LW(5), LW(6))
    EVT_CALL(func_80218100_464590)
    EVT_CALL(func_80219824_465CB4, LW(5))
    EVT_SWITCH(LW(5))
        EVT_CASE_EQ(1)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_goombario)), 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_kooper)), 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_bombette)), 0)
        EVT_CASE_EQ(4)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_parakerry)), 0)
        EVT_CASE_EQ(9)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_bow)), 0)
        EVT_CASE_EQ(6)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_watt)), 0)
        EVT_CASE_EQ(7)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_sushie)), 0)
        EVT_CASE_EQ(8)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_lakilester)), 0)
    EVT_END_SWITCH
    EVT_SET(LW(10), LW(0))
    EVT_CALL(CopyStatusEffects, -127, LW(10))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 3)
        EVT_ADD(LW(2), 5)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, 0x1, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(SetPartFlagBits, -127, 1, 131073, 1)
    EVT_CALL(SetPartFlagBits, -127, 1, 8388608, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, (ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY), 1)
    EVT_CALL(GetActorHP, -127, LW(0))
    EVT_CALL(SetEnemyHP, LW(10), LW(0))
    EVT_CALL(CopyBuffs, -127, LW(10))
    EVT_CALL(GetOwnerID, LW(0))
    EVT_CALL(SetActorVar, LW(10), 0, LW(0))
    EVT_CALL(SetActorVar, LW(10), 1, LW(6))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(MakeLerp, 200, 0, 20, 0)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetBackgroundAlpha), LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, LW(10), 2, 0, 0)
    EVT_SWITCH(LW(5))
        EVT_CASE_EQ(8)
            EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, LW(10), EVT_FLOAT(0.0107421875))
            EVT_CALL(SetGoalPos, LW(10), LW(0), 10, LW(2))
            EVT_CALL(JumpToGoal, LW(10), 10, FALSE, FALSE, FALSE)
            EVT_WAIT_FRAMES(10)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, LW(10), EVT_FLOAT(0.0107421875))
            EVT_CALL(SetGoalPos, LW(10), LW(0), 30, LW(2))
            EVT_CALL(JumpToGoal, LW(10), 20, FALSE, FALSE, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, LW(10), LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, LW(10))
    EVT_CALL(ResetActorSounds, LW(10), 2)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorPos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, -127, 8, 1)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80229F9C) = {
    EVT_CALL(GetActorVar, -127, 8, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(copyPartner))
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(flyingTackle))
        EVT_CASE_EQ(3)
            EVT_CALL(SetActorVar, -127, 8, 2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8022A038) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), 0x3F1000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorHP, -127, LW(0))
            EVT_CALL(GetEnemyMaxHP, -127, LW(1))
            EVT_DIV(LW(1), 2)
            EVT_IF_LE(LW(0), LW(1))
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(GetActorVar, -127, 8, LW(0))
                EVT_IF_EQ(LW(0), 1)
                    EVT_CALL(ActorSpeak, 131112, 513, 1, 10747910, 10747907)
                EVT_ELSE
                    EVT_CALL(ActorSpeak, 131112, -127, 1, 10747910, 10747907)
                EVT_END_IF
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LW(0))
            EVT_IF_LE(LW(0), 5)
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131113, -127, 1, 10747910, 10747907)
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
