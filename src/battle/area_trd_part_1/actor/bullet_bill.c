#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/bullet_bill.h"

#define NAMESPACE b_area_trd_part_1_bullet_bill

s32 N(defenseTable_80218F60)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80218F6C)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 100,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

extern s32 N(idleAnimations_80219064)[];
extern EvtScript N(init_80219088);

ActorPartBlueprint N(partsTable_80219018)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219064),
        .defenseTable = N(defenseTable_80218F60),
        .eventFlags = ACTOR_EVENT_FLAG_400,
        .elementImmunityFlags = 0,
        .unk_1D = 250,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BULLET_BILL,
    .level = 5,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(partsTable_80219018)),
    .partsData = N(partsTable_80219018),
    .script = &N(init_80219088),
    .statusTable = N(statusTable_80218F6C),
    .escapeChance = 50,
    .airLiftChance = 100,
    .spookChance = 100,
    .baseStatusChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 0,
    .size = { 28, 22 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_80219064)[] = {
    STATUS_NORMAL,    NPC_ANIM_bullet_bill_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_bullet_bill_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_bullet_bill_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_bullet_bill_Palette_00_Anim_0,
    STATUS_END,
};

extern EvtScript N(takeTurn_802197C0);
extern EvtScript N(idle_80219380);
extern EvtScript N(handleEvent_802193E8);

EvtScript N(init_80219088) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802197C0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80219380)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802193E8)))
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 16)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
        EVT_CALL(GetActorPos, LW(0), LW(1), LW(2), LW(3))
        EVT_CALL(GetStatusFlags, LW(0), LW(4))
        EVT_IF_FLAG(LW(4), STATUS_FLAG_SHRINK)
            EVT_SET(LW(5), -13)
            EVT_SET(LW(6), 4)
        EVT_ELSE
            EVT_SET(LW(5), -33)
            EVT_SET(LW(6), 11)
        EVT_END_IF
        EVT_ADD(LW(1), LW(5))
        EVT_ADD(LW(2), LW(6))
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
        EVT_CALL(CopyStatusEffects, LW(0), ACTOR_SELF)
        EVT_CALL(CopyBuffs, LW(0), ACTOR_SELF)
        EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
        EVT_CALL(GetActorPos, LW(0), LW(1), LW(11), LW(12))
        EVT_SUB(LW(1), 90)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bullet_bill_Palette_00_Anim_3)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), LW(2), LW(3))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bullet_bill_Palette_00_Anim_1)
        EVT_CALL(ForceHomePos, ACTOR_SELF, LW(1), LW(2), LW(3))
        EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80219380) = {
    EVT_RETURN
    EVT_END
};

extern EvtScript N(80219BE0);

EvtScript N(80219390) = {
    EVT_EXEC_WAIT(N(80219BE0))
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_7)
    EVT_SET(LW(2), -12345)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802193E8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_EXPLODE_TRIGGER)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(80219390))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802197C0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bullet_bill_Palette_00_Anim_4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_19)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SET(LW(3), LW(1))
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_SET(LW(1), LW(3))
            EVT_SUB(LW(0), 90)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(3), LW(1))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), LW(3))
    EVT_ADD(LW(0), 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(N(80219BE0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(YieldTurn)
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_bullet_bill_Palette_00_Anim_7)
    EVT_SET(LW(2), -12345)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(80219BE0) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(2), 2)
    EVT_CALL(PlayEffect, EFFECT_SMOKE_RING, 0, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ADD(LW(1), 16)
    EVT_ADD(LW(2), 2)
    EVT_CALL(PlayEffect, EFFECT_BLAST, 0, LW(0), LW(1), LW(2), EVT_FLOAT(3.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2078)
    EVT_CALL(StartRumble, 11)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
