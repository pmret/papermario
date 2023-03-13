#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/SpyGuy.h"

#define NAMESPACE b_area_omo_spy_guy

extern EvtScript N(init_802275D4);
extern EvtScript N(takeTurn_802293DC);
extern EvtScript N(idle_802276C4);
extern EvtScript N(handleEvent_80227ABC);

s32 N(IdleAnimations_80227400)[] = {
    STATUS_NORMAL,    ANIM_SpyGuy_Anim03,
    STATUS_STONE,     ANIM_SpyGuy_Anim01,
    STATUS_SLEEP,     ANIM_SpyGuy_Anim0F,
    STATUS_POISON,    ANIM_SpyGuy_Anim03,
    STATUS_STOP,      ANIM_SpyGuy_Anim01,
    STATUS_STATIC,    ANIM_SpyGuy_Anim03,
    STATUS_PARALYZE,  ANIM_SpyGuy_Anim01,
    STATUS_DIZZY,     ANIM_SpyGuy_Anim12,
    STATUS_FEAR,      ANIM_SpyGuy_Anim12,
    STATUS_END,
};

s32 N(IdleAnimations_8022744C)[] = {
    STATUS_NORMAL,    ANIM_SpyGuy_Anim02,
    STATUS_STONE,     ANIM_SpyGuy_Anim00,
    STATUS_SLEEP,     ANIM_SpyGuy_Anim0F,
    STATUS_POISON,    ANIM_SpyGuy_Anim02,
    STATUS_STOP,      ANIM_SpyGuy_Anim00,
    STATUS_STATIC,    ANIM_SpyGuy_Anim02,
    STATUS_PARALYZE,  ANIM_SpyGuy_Anim00,
    STATUS_DIZZY,     ANIM_SpyGuy_Anim12,
    STATUS_FEAR,      ANIM_SpyGuy_Anim12,
    STATUS_END,
};

s32 N(IdleAnimations_80227498)[] = {
    STATUS_NORMAL,    ANIM_SpyGuy_Anim10,
    STATUS_END,
};

s32 N(DefenseTable_802274A4)[] = {
    ELEMENT_NORMAL,     0,
    ELEMENT_SHOCK,      0,
    ELEMENT_END,
};

s32 N(StatusTable_802274B8)[] = {
    STATUS_NORMAL,      0,
    STATUS_DEFAULT,     0,
    STATUS_SLEEP,       70,
    STATUS_POISON,      50,
    STATUS_FROZEN,      0,
    STATUS_DIZZY,       80,
    STATUS_FEAR,        100,
    STATUS_STATIC,      0,
    STATUS_PARALYZE,    90,
    STATUS_SHRINK,      75,
    STATUS_STOP,        90,
    STATUS_DEFAULT_TURN_MOD,    0,
    STATUS_SLEEP_TURN_MOD,      0,
    STATUS_POISON_TURN_MOD,     0,
    STATUS_FROZEN_TURN_MOD,     0,
    STATUS_DIZZY_TURN_MOD,      0,
    STATUS_FEAR_TURN_MOD,       0,
    STATUS_STATIC_TURN_MOD,     0,
    STATUS_PARALYZE_TURN_MOD,   1,
    STATUS_SHRINK_TURN_MOD,     0,
    STATUS_STOP_TURN_MOD,       0,
    STATUS_END,
};

enum PartIDs {
    PT_MAIN     = 1,
    PT_2        = 2,
};

ActorPartBlueprint N(PartsTable_80227564)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80227400),
        .defenseTable = N(DefenseTable_802274A4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -13 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80227498),
        .defenseTable = N(DefenseTable_802274A4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPY_GUY,
    .level = 15,
    .maxHP = 7,
    .partCount = ARRAY_COUNT( N(PartsTable_80227564)),
    .partsData = N(PartsTable_80227564),
    .initScript = &N(init_802275D4),
    .statusTable = N(StatusTable_802274B8),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 60,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_802293DC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_802276C4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80227ABC)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(GetInstigatorValue, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PT_MAIN, EVT_PTR(N(IdleAnimations_8022744C)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim02)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802276C4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(802276D4) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim02)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim03)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_100)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PT_MAIN, EVT_PTR(N(IdleAnimations_80227400)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim17)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim19)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim03)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PT_MAIN, EVT_PTR(N(IdleAnimations_8022744C)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim18)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim1A)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim02)
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80227ABC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_SpyGuy_Anim0E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_SpyGuy_Anim0E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
            EVT_EXEC_WAIT(N(802276D4))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_END_IF
            EVT_SET_CONST(LVar2, ANIM_SpyGuy_Anim11)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
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
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E7)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim15)
    EVT_WAIT(12)
    EVT_WAIT(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim16)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, PT_2, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PT_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PT_2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E8)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PT_2, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetPartOffset, ACTOR_SELF, PT_2, LVar3, LVar4, LVar5)
                    EVT_IF_GT(LVar0, LVar3)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PT_2, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PT_2, EVT_FLOAT(0.002))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PT_2, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(15)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PT_2, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PT_2, EVT_FLOAT(0.002))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PT_2, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PT_2, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PT_2, EVT_FLOAT(0.7))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PT_2, LVar0, 0, LVar2, 30, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            EVT_SET(LVar2, 0)
            EVT_SUB(LVar3, 1)
            EVT_CALL(N(DisableRandomAbility), LVar4, LVar5)
            EVT_CALL(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_ADD(LVar1, 30)
            EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 20, EVT_FLOAT(1.0))
            EVT_ADD(LVar1, 20)
            EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 10, EVT_FLOAT(1.0))
            EVT_ADD(LVar1, 10)
            EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, EVT_FLOAT(1.0))
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(ShowMessageBox, LVar5, 60)
            EVT_SUB(LVar1, 150)
            EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 30, EVT_FLOAT(1.0))
            EVT_CALL(RemoveItemEntity, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 3)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_WAIT(1)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim07)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim07)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
    EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim03)
    EVT_WAIT(10)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_327)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim0A)
            EVT_WAIT(6)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim0A)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_SET(LocalFlag(0), 0)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(N(SpyGuyActionFunc), LVar0)
                EVT_IF_NE(LVar0, -1)
                    EVT_SET(LocalFlag(0), 1)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_LE(LVar0, 0)
                EVT_WAIT(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
            EVT_IF_FLAG(LVar1, STATUS_FLAG_SHRINK)
                EVT_WAIT(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar1)
            EVT_IF_FLAG(LVar1, STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
                EVT_WAIT(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_EXEC(N(80228778))
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim07)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 70)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim03)
                EVT_LABEL(0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                EVT_IF_NE(LVar0, 0)
                    EVT_WAIT(1)
                    EVT_GOTO(0)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim07)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
                EVT_CALL(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
                EVT_ADD(LVar1, 20)
                EVT_SUB(LVar3, 2)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_THREAD
                    EVT_WAIT(5)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20DC)
                    EVT_CALL(N(StartRumbleWithParams), 200, 10)
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim09)
                EVT_WAIT(5)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
                EVT_SUB(LVar1, 7)
                EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, LVar2, LVar3, EVT_FLOAT(1.0), 0, 0)
                EVT_WAIT(40)
            EVT_ELSE
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim07)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 70)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim03)
                EVT_WAIT(10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_PLAY_EFFECT(EFFECT_EMOTE, 2, 0, LVar0, LVar1, LVar2, 25, -45, 20, 0, 0)
                EVT_WAIT(20)
            EVT_END_IF
            EVT_LABEL(100)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802293DC) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PT_MAIN, EVT_PTR(N(IdleAnimations_8022744C)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_SpyGuy_Anim02)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(slingshotAttack))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(hammerAttack))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
