#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/spiky_goomnut.h"

#define NAMESPACE b_area_kmr_part_2_goomnut_tree

s32 N(idleAnimations_802232D0)[] = {
    STATUS_NORMAL,    NPC_ANIM_spiky_goomnut_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(defenseTable_802232DC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_HAMMER, 0,
    ELEMENT_END,
};

s32 N(statusTable_802232F0)[] = {
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

extern EvtScript N(init_80223488);
extern EvtScript N(takeTurn_80223804);
extern EvtScript N(idle_80223678);
extern EvtScript N(handleEvent_80223688);
extern EvtScript N(shake_goomnut_tree);
extern EvtScript N(80223DBC);

ActorPartBlueprint N(partsTable_8022339C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802232D0),
        .defenseTable = N(defenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802232D0),
        .defenseTable = N(defenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802232D0),
        .defenseTable = N(defenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802232D0),
        .defenseTable = N(defenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_POPUP,
    .type = ACTOR_TYPE_GOOMNUT_TREE,
    .level = 1,
    .maxHP = 255,
    .partCount = ARRAY_COUNT(N(partsTable_8022339C)),
    .partsData = N(partsTable_8022339C),
    .script = N(init_80223488),
    .statusTable = N(statusTable_802232F0),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 0, 0 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { 0, 0 },
    .statusMessageOffset = { 0, 0 },
};

// Perhaps a status table
s32 N(unk_missing_80223478)[] = {
    2, 0,
    1, 0,
};

EvtScript N(init_80223488) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80223804)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80223678)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80223688)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 0)
    EVT_CALL(SetActorVar, -127, 4, 0)
    EVT_CALL(SetActorVar, -127, 5, 0)
    EVT_CALL(SetActorVar, -127, 6, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, 10, 140, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, -95, 140, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, -115, 130, 0)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, -65, 118, 5)
    EVT_CALL(SetPartScale, -127, 3, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, -127, 4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, -127, 5, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartTargetFlagBits, -127, 1, 4, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80223678) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80223688) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastElement, LW(14))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(23)
            EVT_EXEC_WAIT(N(shake_goomnut_tree))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(25)
            EVT_EXEC_WAIT(N(shake_goomnut_tree))
            EVT_EXEC_WAIT(N(80223DBC))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(11)
            EVT_EXEC_WAIT(N(shake_goomnut_tree))
            EVT_EXEC_WAIT(N(80223DBC))
        EVT_CASE_EQ(32)
            EVT_EXEC_WAIT(N(shake_goomnut_tree))
        EVT_CASE_EQ(33)
            EVT_EXEC_WAIT(N(shake_goomnut_tree))
        EVT_CASE_EQ(42)
        EVT_CASE_EQ(47)
        EVT_CASE_EQ(53)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80223804) = {
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(6)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(10)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/FoliageTransform.inc.c"

EvtScript N(shakeTree) = {
    EVT_SET_TIMESCALE(EVT_FLOAT(2.0))
    EVT_USE_BUF(LW(0))
    EVT_BUF_READ4(LW(1), LW(2), LW(3), LW(4))
    EVT_BUF_READ1(LW(5))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(6), LW(15), LW(8))
    EVT_CALL(PlaySound, SOUND_SMASH_GOOMNUT_TREE)
    EVT_CALL(PlaySound, 0x166)
    EVT_THREAD
        EVT_SET(LF(0), 0)
        EVT_IF_NE(LW(1), 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(5)
                EVT_USE_BUF(LW(1))
                EVT_BUF_READ1(LW(2))
                EVT_LOOP(LW(2))
                    EVT_BUF_READ1(LW(3))
                    EVT_CALL(N(TransformFoliage), LW(3), EVT_FLOAT(0.1005859375), EVT_FLOAT(0.2001953125), LW(15), 0)
                    EVT_IF_EQ(LF(0), 0)
                        EVT_SET(LF(0), 1)
                        EVT_CALL(PlaySoundAtModel, LW(3), 358, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(LW(1))
                EVT_BUF_READ1(LW(2))
                EVT_LOOP(LW(2))
                    EVT_BUF_READ1(LW(3))
                    EVT_CALL(N(TransformFoliage), LW(3), EVT_FLOAT(0.1005859375), EVT_FLOAT(-0.19921875), LW(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(LW(1))
            EVT_BUF_READ1(LW(2))
            EVT_LOOP(LW(2))
                EVT_BUF_READ1(LW(3))
                EVT_CALL(TranslateModel, LW(3), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LF(0), 0)
        EVT_IF_NE(LW(2), 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LW(2))
                EVT_BUF_READ1(LW(3))
                EVT_LOOP(LW(3))
                    EVT_BUF_READ1(LW(4))
                    EVT_CALL(N(TransformFoliage), LW(4), EVT_FLOAT(0.1005859375), EVT_FLOAT(0.2001953125), LW(15), 0)
                    EVT_IF_EQ(LF(0), 0)
                        EVT_SET(LF(0), 1)
                        EVT_CALL(PlaySoundAtModel, LW(4), 357, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(LW(2))
                EVT_BUF_READ1(LW(3))
                EVT_LOOP(LW(3))
                    EVT_BUF_READ1(LW(4))
                    EVT_CALL(N(TransformFoliage), LW(4), EVT_FLOAT(0.1005859375), EVT_FLOAT(-0.19921875), LW(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(LW(2))
            EVT_BUF_READ1(LW(3))
            EVT_LOOP(LW(3))
                EVT_BUF_READ1(LW(4))
                EVT_CALL(TranslateModel, LW(4), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LW(4), 0)
            EVT_USE_BUF(LW(4))
            EVT_BUF_READ1(LW(5))
            EVT_LOOP(LW(5))
                EVT_BUF_READ3(LW(6), LW(7), LW(8))
                EVT_CALL(PlayEffect, 0x14, 0, LW(6), LW(7), LW(8), 100, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(tree_leaves) = {
    .count = 2,
    .models = { 33, 36 }
};

FoliageModelList N(tree_trunk) = {
    .count = 3,
    .models = { 38, 39, 40 }
};

FoliageVectorList N(D_80223D60_41D7F0) = {
    .count = 2,
    .vectors = {
        { -10, 140, 0 },
        { 100, 140, 0 },
    },
};

ShakeTreeConfig N(tree) = {
    .leaves = &N(tree_leaves),
    .trunk = &N(tree_trunk),
    .vectors = &N(D_80223D60_41D7F0),
};

EvtScript N(shake_goomnut_tree) = {
    EVT_SET(LW(0), EVT_ADDR(N(tree)))
    EVT_EXEC_WAIT(N(shakeTree))
    EVT_RETURN
    EVT_END
};

EvtScript N(80223DBC) = {
    EVT_CALL(PlayEffect, 0x14, 0, -25, 120, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(GetActorVar, -127, 5, LW(0))
    EVT_IF_NE(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorVar, -127, 5, 1)
    EVT_CALL(ActorExists, 512, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, 10, 0, 10)
        EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
        EVT_CALL(PlaySoundAtPart, -127, 2, 769)
        EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.80078125))
        EVT_CALL(SetPartMoveSpeed, -127, 2, EVT_FLOAT(4.0))
        EVT_CALL(FallPartTo, -127, 2, 10, 20, 10, 20)
        EVT_CALL(JumpPartTo, -127, 2, 30, 20, 10, 10, 1)
        EVT_CALL(JumpPartTo, -127, 2, 40, 20, 10, 5, 1)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtPart, -127, 2, 769)
    EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.80078125))
    EVT_CALL(SetPartMoveSpeed, -127, 2, EVT_FLOAT(4.0))
    EVT_CALL(GetStatusFlags, ACTOR_ENEMY0, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_CALL(FallPartTo, -127, 2, 10, 80, 10, 10)
    EVT_ELSE
        EVT_CALL(FallPartTo, -127, 2, 10, 32, 10, 10)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetOwnerTarget, 512, 2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, 3, 32)
    EVT_CALL(ActorExists, 513, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(GetPartOffset, -127, 2, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 65)
        EVT_SET(LW(1), 20)
        EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.7001953125))
        EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 20, 1)
        EVT_ADD(LW(0), 12)
        EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 8, 1)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_ENEMY1, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_ENEMY1, LW(3))
    EVT_IF_NOT_FLAG(LW(3), 0x80000)
        EVT_ADD(LW(1), 50)
    EVT_ELSE
        EVT_ADD(LW(1), 20)
    EVT_END_IF
    EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.7001953125))
    EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 20, 1)
    EVT_CALL(SetOwnerTarget, 513, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, 3, 32)
    EVT_CALL(ActorExists, 514, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(GetPartOffset, -127, 2, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 35)
        EVT_SET(LW(1), 20)
        EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.7001953125))
        EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 20, 1)
        EVT_ADD(LW(0), 12)
        EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 8, 1)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_ENEMY2, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_ENEMY2, LW(3))
    EVT_IF_NOT_FLAG(LW(3), 0x80000)
        EVT_ADD(LW(1), 50)
    EVT_ELSE
        EVT_ADD(LW(1), 20)
    EVT_END_IF
    EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.7001953125))
    EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 20, 1)
    EVT_CALL(SetOwnerTarget, 514, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, 3, 32)
    EVT_CALL(GetPartOffset, -127, 2, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 20)
    EVT_SET(LW(1), 20)
    EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.7001953125))
    EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 20, 1)
    EVT_ADD(LW(0), 12)
    EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 8, 1)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
