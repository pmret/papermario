#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/SpikyGoomnut.h"

#define NAMESPACE b_area_kmr_part_2_goomnut_tree

s32 N(IdleAnimations_802232D0)[] = {
    STATUS_NORMAL,    ANIM_SpikyGoomnut_Still,
    STATUS_END,
};

s32 N(DefenseTable_802232DC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SMASH, 0,
    ELEMENT_END,
};

s32 N(StatusTable_802232F0)[] = {
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

ActorPartBlueprint N(PartsTable_8022339C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802232D0),
        .defenseTable = N(DefenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802232D0),
        .defenseTable = N(DefenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802232D0),
        .defenseTable = N(DefenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802232D0),
        .defenseTable = N(DefenseTable_802232DC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_POPUP,
    .type = ACTOR_TYPE_GOOMNUT_TREE,
    .level = 1,
    .maxHP = 255,
    .partCount = ARRAY_COUNT( N(PartsTable_8022339C)),
    .partsData = N(PartsTable_8022339C),
    .initScript = &N(init_80223488),
    .statusTable = N(StatusTable_802232F0),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80223804)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80223678)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80223688)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, 10, 140, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, -95, 140, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, -115, 130, 0)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, -65, 118, 5)
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 1, ACTOR_PART_TARGET_FLAG_4, TRUE)
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
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
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
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(6)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(10)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/FoliageTransform.inc.c"

EvtScript N(EVS_ShakeTree) = {
    EVT_SET_TIMESCALE(EVT_FLOAT(2.0))
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
    EVT_BUF_READ1(LVar5)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar6, LVarF, LVar8)
    EVT_CALL(PlaySound, SOUND_SMASH_GOOMNUT_TREE)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE)
    EVT_THREAD
        EVT_SET(LocalFlag(0), 0)
        EVT_IF_NE(LVar1, 0)
            EVT_WAIT(1)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                    EVT_IF_EQ(LocalFlag(0), 0)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_CALL(PlaySoundAtModel, LVar3, SOUND_SHAKE_TREE, SOUND_SPACE_MODE_0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), EVT_FLOAT(-0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar1)
            EVT_BUF_READ1(LVar2)
            EVT_LOOP(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_CALL(TranslateModel, LVar3, 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalFlag(0), 0)
        EVT_IF_NE(LVar2, 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_LOOP(LVar3)
                    EVT_BUF_READ1(LVar4)
                    EVT_CALL(N(TransformFoliage), LVar4, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                    EVT_IF_EQ(LocalFlag(0), 0)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_CALL(PlaySoundAtModel, LVar4, SOUND_SMASH_GOOMNUT_TREE, SOUND_SPACE_MODE_0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_LOOP(LVar3)
                    EVT_BUF_READ1(LVar4)
                    EVT_CALL(N(TransformFoliage), LVar4, EVT_FLOAT(0.1), EVT_FLOAT(-0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar2)
            EVT_BUF_READ1(LVar3)
            EVT_LOOP(LVar3)
                EVT_BUF_READ1(LVar4)
                EVT_CALL(TranslateModel, LVar4, 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar4, 0)
            EVT_USE_BUF(LVar4)
            EVT_BUF_READ1(LVar5)
            EVT_LOOP(LVar5)
                EVT_BUF_READ3(LVar6, LVar7, LVar8)
                EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, LVar6, LVar7, LVar8, 100, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

FoliageModelList N(tree_leaves) = FOLIAGE_MODEL_LIST(33, 36 );
FoliageModelList N(tree_trunk) = FOLIAGE_MODEL_LIST(38, 39, 40 );

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
    EVT_SET(LVar0, EVT_PTR(N(tree)))
    EVT_EXEC_WAIT(N(EVS_ShakeTree))
    EVT_RETURN
    EVT_END
};

EvtScript N(80223DBC) = {
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -25, 120, 0, 90, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
    EVT_WAIT(20)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 1)
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, 10, 0, 10)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, FALSE)
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_301)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.8))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(4.0))
        EVT_CALL(FallPartTo, ACTOR_SELF, 2, 10, 20, 10, 20)
        EVT_CALL(JumpPartTo, ACTOR_SELF, 2, 30, 20, 10, 10, TRUE)
        EVT_CALL(JumpPartTo, ACTOR_SELF, 2, 40, 20, 10, 5, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_301)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.8))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(4.0))
    EVT_CALL(GetStatusFlags, ACTOR_ENEMY0, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_CALL(FallPartTo, ACTOR_SELF, 2, 10, 80, 10, 10)
    EVT_ELSE
        EVT_CALL(FallPartTo, ACTOR_SELF, 2, 10, 32, 10, 10)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetOwnerTarget, ACTOR_ENEMY0, 2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 65)
        EVT_SET(LVar1, 20)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.7))
        EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 20, TRUE)
        EVT_ADD(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 8, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_ENEMY1, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_ENEMY1, LVar3)
    EVT_IF_NOT_FLAG(LVar3, 0x80000)
        EVT_ADD(LVar1, 50)
    EVT_ELSE
        EVT_ADD(LVar1, 20)
    EVT_END_IF
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_CALL(SetOwnerTarget, ACTOR_ENEMY1, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 35)
        EVT_SET(LVar1, 20)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.7))
        EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 20, TRUE)
        EVT_ADD(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 8, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_ENEMY2, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_ENEMY2, LVar3)
    EVT_IF_NOT_FLAG(LVar3, 0x80000)
        EVT_ADD(LVar1, 50)
    EVT_ELSE
        EVT_ADD(LVar1, 20)
    EVT_END_IF
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_CALL(SetOwnerTarget, ACTOR_ENEMY2, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_SET(LVar1, 20)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_ADD(LVar0, 12)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 8, TRUE)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, FALSE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, TRUE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
