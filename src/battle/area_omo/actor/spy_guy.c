#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/spy_guy.h"

#define NAMESPACE b_area_omo_spy_guy

extern EvtScript N(init_802275D4);
extern EvtScript N(takeTurn_802293DC);
extern EvtScript N(idle_802276C4);
extern EvtScript N(handleEvent_80227ABC);

s32 N(idleAnimations_80227400)[] = {
    STATUS_NORMAL,    NPC_ANIM_spy_guy_Palette_00_Anim_3,
    STATUS_STONE,     NPC_ANIM_spy_guy_Palette_00_Anim_1,
    STATUS_SLEEP,     NPC_ANIM_spy_guy_Palette_00_Anim_F,
    STATUS_POISON,    NPC_ANIM_spy_guy_Palette_00_Anim_3,
    STATUS_STOP,      NPC_ANIM_spy_guy_Palette_00_Anim_1,
    STATUS_STATIC,    NPC_ANIM_spy_guy_Palette_00_Anim_3,
    STATUS_PARALYZE,  NPC_ANIM_spy_guy_Palette_00_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_spy_guy_Palette_00_Anim_12,
    STATUS_FEAR,      NPC_ANIM_spy_guy_Palette_00_Anim_12,
    STATUS_END,
};

s32 N(idleAnimations_8022744C)[] = {
    STATUS_NORMAL,    NPC_ANIM_spy_guy_Palette_00_Anim_2,
    STATUS_STONE,     NPC_ANIM_spy_guy_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_spy_guy_Palette_00_Anim_F,
    STATUS_POISON,    NPC_ANIM_spy_guy_Palette_00_Anim_2,
    STATUS_STOP,      NPC_ANIM_spy_guy_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_spy_guy_Palette_00_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_spy_guy_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_spy_guy_Palette_00_Anim_12,
    STATUS_FEAR,      NPC_ANIM_spy_guy_Palette_00_Anim_12,
    STATUS_END,
};

s32 N(idleAnimations_80227498)[] = {
    STATUS_NORMAL,    NPC_ANIM_spy_guy_Palette_00_Anim_10,
    STATUS_END,
};

s32 N(defenseTable_802274A4)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(statusTable_802274B8)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 80,
    STATUS_FEAR, 100,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80227564)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80227400),
        .defenseTable = N(defenseTable_802274A4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -13,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80227498),
        .defenseTable = N(defenseTable_802274A4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = -10,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPY_GUY,
    .level = 15,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(partsTable_80227564)),
    .partsData = N(partsTable_80227564),
    .script = N(init_802275D4),
    .statusTable = N(statusTable_802274B8),
    .escapeChance = 50,
    .airLiftChance = 85,
    .spookChance = 80,
    .baseStatusChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 1,
    .size = { 32, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_802275D4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802293DC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_802276C4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80227ABC)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(func_8027D75C, ACTOR_SELF, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022744C)))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802276C4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(802276D4) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetLastDamage, ACTOR_SELF, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_2)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_3)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_CALL(GetBattleFlags, LW(0))
    EVT_IF_FLAG(LW(0), BS_FLAGS1_100)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80227400)))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_17)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_19)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_3)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022744C)))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_18)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_1A)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_2)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80227ABC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_spy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_spy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_IF_EQ(LW(1), 0)
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_2)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_3)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_IF_EQ(LW(1), 0)
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_2)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_3)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_IF_EQ(LW(1), 0)
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_2)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_3)
            EVT_END_IF
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_IF_EQ(LW(1), 0)
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_6)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_7)
            EVT_END_IF
            EVT_SET_CONST(LW(2), NPC_ANIM_spy_guy_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_IF_EQ(LW(1), 0)
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_6)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_7)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_IF_EQ(LW(1), 0)
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_6)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_7)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(slingshotAttack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E7)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(12)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_16)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 10)
    EVT_ADD(LW(1), 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E8)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 2, 2, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
                    EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LW(3), LW(4), LW(5))
                    EVT_IF_GT(LW(0), LW(3))
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.001953125))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.001953125))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.7))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LW(0), 0, LW(2), 30, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/ItemEntityJumpToPos.inc.c"

#include "common/GetItemEntityPosition.inc.c"

#include "common/DisableRandomAbility.inc.c"

#include "common/SpyGuyActionFunc.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(80228778) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(1), LW(2), LW(3))
            EVT_SET(LW(2), 0)
            EVT_SUB(LW(3), 1)
            EVT_CALL(N(DisableRandomAbility), LW(4), LW(5))
            EVT_CALL(MakeItemEntity, LW(4), LW(1), LW(2), LW(3), 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_ADD(LW(1), 30)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 20, EVT_FLOAT(1.0))
            EVT_ADD(LW(1), 20)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 10, EVT_FLOAT(1.0))
            EVT_ADD(LW(1), 10)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 5, EVT_FLOAT(1.0))
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(ShowMessageBox, LW(5), 60)
            EVT_SUB(LW(1), 150)
            EVT_CALL(N(ItemEntityJumpToPos), LW(0), LW(1), LW(2), LW(3), 30, EVT_FLOAT(1.0))
            EVT_CALL(RemoveItemEntity, LW(0))
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(hammerAttack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_7)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_7)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
    EVT_IF_NOT_FLAG(LW(1), STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_3)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x327)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_A)
            EVT_WAIT_FRAMES(6)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_A)
    EVT_WAIT_FRAMES(5)
    EVT_WAIT_FRAMES(2)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_SET(LF(0), 0)
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_NOT_FLAG(LW(0), BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(N(SpyGuyActionFunc), LW(0))
                EVT_IF_NE(LW(0), -1)
                    EVT_SET(LF(0), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LW(0))
            EVT_IF_LE(LW(0), 0)
                EVT_WAIT_FRAMES(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
            EVT_IF_FLAG(LW(1), STATUS_FLAG_SHRINK)
                EVT_WAIT_FRAMES(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(1))
            EVT_IF_FLAG(LW(1), STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
                EVT_WAIT_FRAMES(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_IF_EQ(LF(0), 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_EXEC(N(80228778))
                EVT_WAIT_FRAMES(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_7)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), 70)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_3)
                EVT_LABEL(0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
                EVT_IF_NE(LW(0), 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_GOTO(0)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_7)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
                EVT_CALL(N(GetItemEntityPosition), LW(0), LW(1), LW(2), LW(3))
                EVT_ADD(LW(1), 20)
                EVT_SUB(LW(3), 2)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), LW(2), LW(3))
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_THREAD
                    EVT_WAIT_FRAMES(5)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DC)
                    EVT_CALL(N(StartRumbleWithParams), 200, 10)
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_9)
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
                EVT_SUB(LW(1), 7)
                EVT_CALL(PlayEffect, EFFECT_ID_43, 0, LW(1), LW(2), LW(3), EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(40)
            EVT_ELSE
                EVT_WAIT_FRAMES(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_7)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(0), 70)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_3)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 10)
                EVT_CALL(PlayEffect, EFFECT_ID_10, 2, 0, LW(0), LW(1), LW(2), 25, -45, 20, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(20)
            EVT_END_IF
            EVT_LABEL(100)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_spy_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802293DC) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022744C)))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spy_guy_Palette_00_Anim_2)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(slingshotAttack))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(hammerAttack))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
