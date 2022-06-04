#include "sprite/npc/battle_parakarry.h"

extern EvtScript N(parakarry_init);
extern EvtScript N(parakarry_takeTurn);
extern EvtScript N(parakarry_idle);
extern EvtScript N(parakarry_handleEvent);

s32 N(parakarry_idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_POISON, NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_battle_parakarry_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_FEAR, NPC_ANIM_battle_parakarry_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(parakarry_defenseTable)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(parakarry_statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 80,
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

ActorPartBlueprint N(parakarry_parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 32 },
        .opacity = 255,
        .idleAnimations = N(parakarry_idleAnimations),
        .defenseTable = N(parakarry_defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -16,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -3, -18 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(parakarry_defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -16,
    },
};

ActorBlueprint N(parakarry) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_GHOST_PARAKARRY,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(parakarry_parts)),
    .partsData = N(parakarry_parts),
    .script = &N(parakarry_init),
    .statusTable = N(parakarry_statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .spookChance = 70,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 38, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(parakarry_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(parakarry_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(parakarry_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(parakarry_handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(parakarry_idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(parakarry_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LW(1))
            EVT_IF_FLAG(LW(1), DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
                EVT_EXEC_WAIT(N(OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_F)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_parakarry_Palette_00_Anim_10)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_F)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_parakarry_Palette_00_Anim_10)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_10)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(N(OnShockHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_D)
            EVT_SET(LW(2), 22)
            EVT_EXEC_WAIT(N(OnShockDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_parakarry_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
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

EvtScript N(parakarry_doTakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_0)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(UseBattleCamPresetImmediately, 1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2004)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2005)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_5)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_1)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 10, -20, 4)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_6)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(9))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_CALL(PlaySound, SOUND_0)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_0)
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_parakarry_Palette_00_Anim_3)
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpWithBounce, ACTOR_SELF, 10, EVT_FLOAT(4.0))
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

EvtScript N(parakarry_takeTurn) = {
    EVT_EXEC_WAIT(N(parakarry_doTakeTurn))
    EVT_RETURN
    EVT_END
};
