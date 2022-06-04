#include "sprite/npc/battle_bow.h"

extern EvtScript N(bow_takeTurn);
extern EvtScript N(bow_idle);
extern EvtScript N(bow_handleEvent);
extern EvtScript N(bow_init);

s32 N(bow_idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_battle_bow_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_POISON, NPC_ANIM_battle_bow_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_battle_bow_Palette_00_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_battle_bow_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_battle_bow_Palette_00_Anim_1A,
    STATUS_FEAR, NPC_ANIM_battle_bow_Palette_00_Anim_1A,
    STATUS_END,
};

s32 N(bow_defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(bow_statusTable)[] = {
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

ActorPartBlueprint N(bow_parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(bow_idleAnimations),
        .defenseTable = N(bow_defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -26 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(bow_defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
};

ActorBlueprint N(bow) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_GHOST_BOW,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(bow_parts)),
    .partsData = N(bow_parts),
    .script = &N(bow_init),
    .statusTable = N(bow_statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .spookChance = 70,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 36, 29 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(bow_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(bow_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(bow_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(bow_handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(bow_idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(bow_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LW(1))
            EVT_IF_FLAG(LW(1), DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
                EVT_EXEC_WAIT(N(OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_18)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bow_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_18)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bow_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(N(OnShockHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_SET(LW(2), 14)
            EVT_EXEC_WAIT(N(OnShockDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bow_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
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

EvtScript N(bow_takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR)
    EVT_THREAD
        EVT_SET(LW(0), 200)
        EVT_LOOP(20)
            EVT_SUB(LW(0), 10)
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_3)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
        EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 4, -4, 0)
        EVT_ELSE
            EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -10, 0)
        EVT_END_IF
        EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH)
    EVT_SET(LW(0), 55)
    EVT_LOOP(20)
        EVT_ADD(LW(0), 10)
        EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_7)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LW(0), 0)
            EVT_LOOP(20)
                EVT_ADD(LW(0), -45)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1A)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 3)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR)
            EVT_THREAD
                EVT_SET(LW(0), 200)
                EVT_LOOP(20)
                    EVT_SUB(LW(0), 10)
                    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH)
            EVT_CALL(YieldTurn)
            EVT_SET(LW(0), 55)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_SET(LW(10), 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(8))
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
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2019)
        EVT_ADD(LW(10), 1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
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
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.5))
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.2))
        EVT_END_THREAD
        EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(9))
        EVT_SWITCH(LW(9))
            EVT_CASE_EQ(0)
                EVT_WAIT_FRAMES(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, BS_FLAGS1_10)
            EVT_CASE_EQ(1)
                EVT_WAIT_FRAMES(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, BS_FLAGS1_10)
            EVT_CASE_EQ(2)
                EVT_WAIT_FRAMES(2)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, BS_FLAGS1_10)
        EVT_END_SWITCH
        EVT_WAIT_FRAMES(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
        EVT_CALL(GetActorHP, ACTOR_PLAYER, LW(1))
        EVT_IF_EQ(LW(1), 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_APPEAR)
            EVT_THREAD
                EVT_SET(LW(0), 200)
                EVT_LOOP(20)
                    EVT_SUB(LW(0), 10)
                    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bow_Palette_00_Anim_1)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOO_VANISH)
            EVT_CALL(YieldTurn)
            EVT_SET(LW(0), 55)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 10)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
