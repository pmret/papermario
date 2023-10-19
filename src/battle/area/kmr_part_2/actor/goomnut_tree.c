#include "../area.h"
#include "sprite/npc/SpikyGoomnut.h"
#include "mapfs/kmr_bt06_shape.h"
#include "goomba_king_common.h"

#define NAMESPACE A(goomnut_tree)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_TriggerTreeShake);
extern EvtScript N(EVS_DropNutOnGoombas);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BIG_NUT     = 2,
    // more parts listed in goomba_king_common.h
};

enum N(ActorVars) {
    AVAR_Unused_0       = 0,
    AVAR_Unused_1       = 1,
    AVAR_Unused_2       = 2,
    AVAR_Unused_3       = 3,
    AVAR_Unused_4       = 4,
    AVAR_BigNutDropped  = 5,
    // another var listed in goomba_king_common.h
};

enum N(ActorParams) {
    DMG_TO_KING         = 3,
    DMG_TO_RED_GOOMBA   = 3,
    DMG_TO_BLUE_GOOMBA  = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpikyGoomnut_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SMASH,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_BIG_NUT,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_TREE_NUT_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_TREE_NUT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_TREE_NUT_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_POPUP,
    .type = ACTOR_TYPE_GOOMNUT_TREE,
    .level = ACTOR_LEVEL_GOOMNUT_TREE,
    .maxHP = 255,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 0,
    .coinReward = 0,
    .size = { 0, 0 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { 0, 0 },
    .statusTextOffset = { 0, 0 },
};

EvtScript N(EVS_UnusedStub) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BigNutDropped, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TREE_DELAY, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BIG_NUT, 10, 140, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TREE_NUT_1, -95, 140, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TREE_NUT_2, -115, 130, 0)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TREE_NUT_3, -65, 118, 5)
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_TREE_NUT_1, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_TREE_NUT_2, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_TREE_NUT_3, EVT_FLOAT(0.5), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_TARGET_NO_DAMAGE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_TriggerTreeShake))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_EXEC_WAIT(N(EVS_TriggerTreeShake))
            EVT_EXEC_WAIT(N(EVS_DropNutOnGoombas))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(EVS_TriggerTreeShake))
            EVT_EXEC_WAIT(N(EVS_DropNutOnGoombas))
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(EVS_TriggerTreeShake))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(EVS_TriggerTreeShake))
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// unclear what values LVar0 could have here
EvtScript N(EVS_TakeTurn) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(6)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(10)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
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
    EVT_CALL(PlaySound, SOUND_SMACK_TREE)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    EVT_THREAD
        EVT_SET(LFlag0, FALSE)
        EVT_IF_NE(LVar1, 0)
            EVT_WAIT(1)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_SET(LFlag0, TRUE)
                        EVT_CALL(PlaySoundAtModel, LVar3, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
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
        EVT_SET(LFlag0, FALSE)
        EVT_IF_NE(LVar2, 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_LOOP(LVar3)
                    EVT_BUF_READ1(LVar4)
                    EVT_CALL(N(TransformFoliage), LVar4, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_SET(LFlag0, TRUE)
                        EVT_CALL(PlaySoundAtModel, LVar4, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
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

FoliageModelList N(TreeLeaves) = FOLIAGE_MODEL_LIST(MODEL_ha3, MODEL_o306);
FoliageModelList N(TreeTrunk) = FOLIAGE_MODEL_LIST(MODEL_o307, MODEL_o308, MODEL_o309);

FoliageVectorList N(EffectPositions) = {
    .count = 2,
    .vectors = {
        { -10, 140, 0 },
        { 100, 140, 0 },
    },
};

ShakeTreeConfig N(Tree) = {
    .leaves = &N(TreeLeaves),
    .trunk = &N(TreeTrunk),
    .vectors = &N(EffectPositions),
};

EvtScript N(EVS_TriggerTreeShake) = {
    EVT_SET(LVar0, EVT_PTR(N(Tree)))
    EVT_EXEC_WAIT(N(EVS_ShakeTree))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropNutOnGoombas) = {
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -25, 120, 0, 90, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_BigNutDropped, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_KING)
    EVT_WAIT(20)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BigNutDropped, TRUE)
    EVT_CALL(ActorExists, ACTOR_KING, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, 10, 0, 10)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_BIG_NUT, SOUND_FALL_QUICK)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(0.8))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(4.0))
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_BIG_NUT, 10, 20, 10, 20)
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, 30, 20, 10, 10, TRUE)
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, 40, 20, 10, 5, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_BIG_NUT, SOUND_FALL_QUICK)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(0.8))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(4.0))
    EVT_CALL(GetStatusFlags, ACTOR_KING, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_BIG_NUT, 10, 80, 10, 10)
    EVT_ELSE
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_BIG_NUT, 10, 32, 10, 10)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetOwnerTarget, ACTOR_KING, PRT_BIG_NUT)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, DMG_TO_KING, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(ActorExists, ACTOR_RED_GOOMBA, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 65)
        EVT_SET(LVar1, 20)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(0.7))
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, TRUE)
        EVT_ADD(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 8, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_RED_GOOMBA, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_RED_GOOMBA, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 50)
    EVT_ELSE
        EVT_ADD(LVar1, 20)
    EVT_END_IF
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_CALL(SetOwnerTarget, ACTOR_RED_GOOMBA, PRT_MAIN)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, DMG_TO_RED_GOOMBA, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(ActorExists, ACTOR_BLUE_GOOMBA, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 35)
        EVT_SET(LVar1, 20)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(0.7))
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, TRUE)
        EVT_ADD(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 8, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_BLUE_GOOMBA, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_BLUE_GOOMBA, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 50)
    EVT_ELSE
        EVT_ADD(LVar1, 20)
    EVT_END_IF
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_CALL(SetOwnerTarget, ACTOR_BLUE_GOOMBA, PRT_MAIN)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, ((DAMAGE_TYPE_IGNORE_DEFENSE)), 0, 0, DMG_TO_BLUE_GOOMBA, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_SET(LVar1, 20)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BIG_NUT, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_ADD(LVar0, 12)
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BIG_NUT, LVar0, LVar1, LVar2, 8, TRUE)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BIG_NUT, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
