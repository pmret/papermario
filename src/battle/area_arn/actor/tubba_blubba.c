#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_tubba.h"

#define NAMESPACE b_area_arn_tubba_blubba

extern EvtScript N(init_80225D98);
extern EvtScript N(takeTurn_802264AC);
extern EvtScript N(idle_80225F58);
extern EvtScript N(handleEvent_802260D0);
extern EvtScript N(80225E08);
extern EvtScript N(80226558);
extern EvtScript N(80226B88);
extern EvtScript N(80227878);

s32 N(idleAnimations_80225C40)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_tubba_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_battle_tubba_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_tubba_Palette_00_Anim_18,
    STATUS_POISON,    NPC_ANIM_battle_tubba_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_battle_tubba_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_tubba_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_battle_tubba_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_battle_tubba_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_tubba_Palette_00_Anim_18,
    STATUS_FEAR,      NPC_ANIM_battle_tubba_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(defenseTable_80225C94)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80225CA0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 80,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 80,
    STATUS_SHRINK, 90,
    STATUS_STOP, 80,
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

ActorPartBlueprint N(partsTable_80225D4C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -15, 75 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80225C40),
        .defenseTable = N(defenseTable_80225C94),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUBBA_BLUBBA_INVINCIBLE,
    .level = 70,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(partsTable_80225D4C)),
    .partsData = N(partsTable_80225D4C),
    .script = N(init_80225D98),
    .statusTable = N(statusTable_80225CA0),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 110, 100 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -33, 78 },
    .statusMessageOffset = { 10, 75 },
};

EvtScript N(init_80225D98) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802264AC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80225F58)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802260D0)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_EXEC(N(80225E08))
    EVT_RETURN
    EVT_END
};

EvtScript N(80225E08) = {
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(ActorExists, ACTOR_SELF, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_IF_EQ(LW(0), NPC_ANIM_battle_tubba_Palette_00_Anim_6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_EQ(LW(0), NPC_ANIM_battle_tubba_Palette_00_Anim_7)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(1)
    EVT_CALL(StartRumble, 1)
    EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80225F58) = {
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80225F8C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80225FD4) = {
    EVT_SET(LW(1), 7012353)
    EVT_EXEC_WAIT(N(80225F8C))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_SET(LW(1), 7012358)
    EVT_EXEC_WAIT(N(80225F8C))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_SET(LW(1), 7012353)
    EVT_EXEC_WAIT(N(80225F8C))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802260D0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(80227878))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80225FD4))
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_EXEC_WAIT(N(80227878))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(80227878))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(80227878))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_tubba_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802264AC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(RandInt, 100, LW(0))
    EVT_IF_LT(LW(0), 60)
        EVT_EXEC_WAIT(N(80226558))
    EVT_ELSE
        EVT_EXEC_WAIT(N(80226B88))
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80226558) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_SET(LW(1), 7012358)
    EVT_EXEC_WAIT(N(80225F8C))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
    EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x35E)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_16)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_17)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_SET(LW(1), 0)
        EVT_CALL(PlayEffect, EFFECT_ID_06, 4, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_THREAD
            EVT_CALL(StartRumble, 1)
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(15.0))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EA)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_ID_25, 0, LW(0), 0, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(30)
            EVT_SET(LW(1), 7012353)
            EVT_EXEC_WAIT(N(80225F8C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(80225FD4))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
    EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(PlayEffect, EFFECT_ID_25, 1, LW(0), 0, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
        EVT_CALL(func_80269EAC, 23)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_WAIT_FRAMES(30)
            EVT_SET(LW(1), 7012353)
            EVT_EXEC_WAIT(N(80225F8C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(80225FD4))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80226B88) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_SET(LW(1), 7012358)
    EVT_EXEC_WAIT(N(80225F8C))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_A)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_B)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 999, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_WAIT_FRAMES(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_C)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 15)
            EVT_SET(LW(1), 0)
            EVT_ADD(LW(2), 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 23, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EA)
            EVT_CALL(PlayEffect, EFFECT_ID_25, 0, LW(0), 0, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_D)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(PlayEffect, EFFECT_ID_1D, 0, LW(0), LW(1), LW(2), 60, 8, 10, 20, 0, 0, 0, 0, 0)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_ADD(LW(2), 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(StartRumble, 1)
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_ID_1D, 0, LW(0), LW(1), LW(2), 60, 8, 10, 20, 0, 0, 0, 0, 0)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_E)
            EVT_WAIT_FRAMES(4)
            EVT_EXEC_WAIT(N(80225FD4))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_THREAD
                EVT_WAIT_FRAMES(9)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_C)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
    EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
        EVT_CALL(func_80269EAC, 24)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EA)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_NOT_FLAG(LW(0), BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_STONE)
                    EVT_CALL(LandJump, ACTOR_SELF)
                EVT_ELSE
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_ELSE
                EVT_GOTO(1)
            EVT_END_IF
            EVT_LABEL(0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_ID_25, 0, LW(0), 0, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_D)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(PlayEffect, EFFECT_ID_1D, 0, LW(0), LW(1), LW(2), 60, 8, 10, 20, 0, 0, 0, 0, 0)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_ADD(LW(2), 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(StartRumble, 1)
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_ID_1D, 0, LW(0), LW(1), LW(2), 60, 8, 10, 20, 0, 0, 0, 0, 0)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_WAIT_FRAMES(3)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(PlayEffect, EFFECT_ID_25, 1, LW(0), 0, LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_THREAD
                EVT_WAIT_FRAMES(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_E)
            EVT_END_THREAD
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_IF_NOT_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_CALL(StartRumble, 1)
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(PlayEffect, EFFECT_ID_1D, 0, LW(0), LW(1), LW(2), 60, 8, 10, 20, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(8)
            EVT_END_IF
            EVT_LABEL(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(80225FD4))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80227878) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_14)
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x0E, 0x00C9), ACTOR_SELF, 1, NPC_ANIM_battle_tubba_Palette_00_Anim_14, NPC_ANIM_battle_tubba_Palette_00_Anim_14)
    EVT_SET(LW(0), 1)
    EVT_SET(LW(1), 7012372)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};
