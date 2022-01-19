#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/putrid_piranha.h"

extern EvtScript N(init_8021B1F8);
extern EvtScript N(takeTurn_8021B8A8);
extern EvtScript N(idle_8021B244);
extern EvtScript N(handleEvent_8021B3D0);
extern EvtScript N(bite);
extern EvtScript N(breath);

s32 N(idleAnimations_8021B0A0)[] = {
    STATUS_NORMAL,    NPC_ANIM_putrid_piranha_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_putrid_piranha_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_putrid_piranha_Palette_00_Anim_0,
    STATUS_POISON,    NPC_ANIM_putrid_piranha_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_putrid_piranha_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_putrid_piranha_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_putrid_piranha_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_putrid_piranha_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_putrid_piranha_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(defenseTable_8021B0EC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021B100)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 95,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 85,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 1,
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

ActorPartBlueprint N(partsTable_8021B1AC)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -15, 50 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B0A0),
        .defenseTable = N(defenseTable_8021B0EC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 1010,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_PUTRID_PIRANHA,
    .level = 17,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(partsTable_8021B1AC)),
    .partsData = N(partsTable_8021B1AC),
    .script = N(init_8021B1F8),
    .statusTable = N(statusTable_8021B100),
    .escapeChance = 60,
    .airLiftChance = 20,
    .spookChance = 20,
    .baseStatusChance = 30,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 60, 52 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -22, 32 },
    .statusMessageOffset = { 1, 44 },
};

EvtScript N(init_8021B1F8) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021B8A8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021B244)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021B3D0)))
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_8021B244) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_DIZZY)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -27, 33)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 5, -11)
        EVT_CALL(N(UnkBattleFunc1), -37, 9, -7, 31)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -15, 50)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 3, -14)
        EVT_CALL(N(UnkBattleFunc1), -22, 32, 1, 44)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B354) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021B3D0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_10)
            EVT_SET_CONST(LW(2), NPC_ANIM_putrid_piranha_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_10)
            EVT_SET_CONST(LW(2), NPC_ANIM_putrid_piranha_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8021B354))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_putrid_piranha_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021B8A8) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(bite))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 100, LW(0))
    EVT_IF_LT(LW(0), 70)
        EVT_EXEC_WAIT(N(breath))
    EVT_ELSE
        EVT_EXEC_WAIT(N(bite))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(bite) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_18)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 27)
        EVT_SET(LW(1), 0)
        EVT_SET(LW(3), LW(0))
        EVT_SET(LW(4), LW(1))
        EVT_SET(LW(5), LW(2))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(6), LW(7), LW(8))
        EVT_ADD(LW(3), LW(6))
        EVT_ADD(LW(4), LW(7))
        EVT_ADD(LW(5), LW(8))
        EVT_DIV(LW(3), 2)
        EVT_DIV(LW(4), 2)
        EVT_DIV(LW(5), 2)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, LW(3), LW(4), LW(5))
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 40)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_17)
        EVT_WAIT_FRAMES(8)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
        EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
            EVT_ADD(LW(0), 10)
        EVT_ELSE
            EVT_ADD(LW(0), 27)
        EVT_END_IF
        EVT_SET(LW(1), 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_1)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT_FRAMES(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DE)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_5)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_6)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_7)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(14)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(YieldTurn)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_18)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_17)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
            EVT_ELSE
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
                EVT_EXEC_WAIT(N(8021B354))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_6)
    EVT_WAIT_FRAMES(1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_7)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_18)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_17)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
            EVT_ELSE
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(8021B354))
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkEffect6FFunc.inc.c"

EvtScript N(breath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(0), 16)
    EVT_ELSE
        EVT_ADD(LW(0), 40)
    EVT_END_IF
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_8)
    EVT_WAIT_FRAMES(11)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3AB)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(0), 12)
        EVT_SET(LW(1), 5)
        EVT_SETF(LW(3), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LW(0), 32)
        EVT_SET(LW(1), 13)
        EVT_SETF(LW(3), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(N(UnkEffect6FFunc), LW(2), LW(0), LW(1), LW(2), LW(3), 30, 120, 0, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_9)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_A)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(14)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(8021B354))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, STATUS_FLAG_4 | STATUS_FLAG_20 | STATUS_FLAG_40 | STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_putrid_piranha_Palette_00_Anim_A)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(8021B354))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
