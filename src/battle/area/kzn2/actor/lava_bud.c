#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/LavaBud.h"
#include "sprite/npc/PetitPiranha.h"
#include "effects.h"
#include "ld_addrs.h"

#define NAMESPACE b_area_kzn2_lava_bud

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(playModelAnimation);
extern EvtScript N(onHitCombo);
extern EvtScript N(onHit);
extern EvtScript N(onBurnHit);
extern EvtScript N(onDeath);
extern EvtScript N(attackPetitSpit);
extern EvtScript N(summonPetitPiranha);
extern EvtScript N(8022630C);

API_CALLABLE(SetAnimatorFlags);

extern EvtScript b_area_kzn2_lava_piranha_ignite;

extern ActorBlueprint b_area_kzn2_petit_piranha;
extern ActorBlueprint b_area_kzn2_petit_piranha_bomb;

extern Formation N(formation_petit_piranha_1);
extern Formation N(formation_petit_piranha_2);

static s32 N(unusedArray)[64];

MATCHING_BSS(0x8A0);

BSS u8 Vine3Base[0x2000];
BSS u8 Vine2Base[0x3000];
BSS u8 Vine1Base[0x3000];
BSS u8 Vine0Base[0x4000];

enum {
    VINE_1      = 1,
    VINE_2      = 2,
};

#define VINE_1_BASE (s32) Vine1Base
#define VINE_2_BASE (s32) Vine2Base

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_LavaBud_Anim03,
    STATUS_STOP, ANIM_LavaBud_Anim02,
    STATUS_END,
};

s32 N(IdleAnimations_fiery)[] = {
    STATUS_NORMAL, ANIM_LavaBud_Anim04,
    STATUS_STOP, ANIM_LavaBud_Anim02,
    STATUS_END,
};

s32 N(IdleAnimations_wet)[] = {
    STATUS_NORMAL, ANIM_LavaBud_Anim0F,
    STATUS_STOP, ANIM_LavaBud_Anim0F,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_WATER, 0,
    ELEMENT_ICE, 0,
    ELEMENT_FIRE, 99,
    ELEMENT_BLAST, 0,
    ELEMENT_END,
};

s32 N(DefenseTable_fiery)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_WATER, -2,
    ELEMENT_ICE, -2,
    ELEMENT_FIRE, 99,
    ELEMENT_BLAST, 0,
    ELEMENT_END,
};

s32 N(DefenseTable_wet)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_WATER, 0,
    ELEMENT_ICE, 0,
    ELEMENT_FIRE, 99,
    ELEMENT_BLAST, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 75,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 0,
    STATUS_STOP, 60,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_LAVA_BUD_PHASE_1,
    .level = 0,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .hpBarOffset = { 10, -42 },
    .statusIconOffset = { -18, 10 },
    .statusMessageOffset = { 0, 0 },
};

EvtScript N(init) = {
    EVT_USE_ARRAY(N(unusedArray))
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, 0)
    EVT_CALL(RandInt, 20, LVar0)
    EVT_ADD(LVar0, 15)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaBud_Anim03)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaBud_Anim09)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorHP, ACTOR_ENEMY0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_NO_DMG_APPLY)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_NE(LVar0, 2)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 12, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_IF_GE(LVar0, 3)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 12, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(RandInt, 50, LVar0)
            EVT_ADD(LVar0, 25)
        EVT_CASE_EQ(1)
            EVT_CALL(RandInt, 40, LVar0)
            EVT_ADD(LVar0, 20)
        EVT_CASE_DEFAULT
            EVT_CALL(RandInt, 3, LVar0)
            EVT_ADD(LVar0, 3)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
    EVT_ELSE
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
    EVT_END_IF
    EVT_CALL(LoadBattleDmaData, 30)
    EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_LABEL(99)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(playModelAnimation) = {
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(PlayModelAnimation, LVar0, VINE_1_BASE)
    EVT_ELSE
        EVT_CALL(PlayModelAnimation, LVar0, VINE_2_BASE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(onHitCombo))
        EVT_CASE_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(onBurnHit))
            EVT_ELSE
                EVT_EXEC_WAIT(N(onHit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar1)
            EVT_EXEC_WAIT(DoShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(DoShockHit)
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_IF_NOT_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(onHitCombo))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_IF_NOT_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(onHit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STOP)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 1)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onBurnHit) = {
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar2)
        EVT_IF_EQ(LVar2, 1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_SET(LVar0, ACTOR_ENEMY1)
        EVT_ELSE
            EVT_SET(LVar0, ACTOR_ENEMY2)
        EVT_END_IF
        EVT_EXEC_WAIT(b_area_kzn2_lava_piranha_ignite)
        EVT_LABEL(10)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
            EVT_ELSE
                EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
            EVT_END_IF
            EVT_CALL(LoadBattleDmaData, 29)
            EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaBud_Anim03)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaBud_Anim09)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_fiery)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 2, EVT_PTR(N(DefenseTable_fiery)))
            EVT_THREAD
                EVT_WAIT(14)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 31)
                EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_NO_DMG_APPLY)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_RETURN
        EVT_END_IF
        EVT_EXEC_WAIT(N(attackPetitSpit))
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
        EVT_IF_NE(LVar1, 0)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, LVar1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_IF_NE(LVar1, 0)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 1)
            EVT_EXEC_WAIT(N(summonPetitPiranha))
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, 11, LVar0)
            EVT_SUB(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 11, LVar0)
            EVT_IF_LE(LVar0, 0)
                EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, 40, 30, 0)
                    EVT_CALL(SetBattleCamZoom, 270)
                    EVT_CALL(SetBattleCamOffsetZ, 20)
                    EVT_CALL(MoveBattleCamOver, 30)
                EVT_ELSE
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, 110, 35, 0)
                    EVT_CALL(SetBattleCamZoom, 300)
                    EVT_CALL(SetBattleCamOffsetZ, 20)
                    EVT_CALL(MoveBattleCamOver, 30)
                EVT_END_IF
                EVT_WAIT(30)
                EVT_LOOP(10)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                    EVT_ELSE
                        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                    EVT_END_IF
                    EVT_CALL(LoadBattleDmaData, 30)
                    EVT_EXEC_WAIT(N(playModelAnimation))
                    EVT_WAIT(4)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 15)
                EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim04)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_SET(LVar0, ACTOR_ENEMY1)
                EVT_ELSE
                    EVT_SET(LVar0, ACTOR_ENEMY2)
                EVT_END_IF
                EVT_CALL(PlaySoundAtActor, LVar0, SOUND_20BF)
                EVT_EXEC_WAIT(b_area_kzn2_lava_piranha_ignite)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 29)
                EVT_EXEC_WAIT(N(playModelAnimation))
                EVT_WAIT(14)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 31)
                EVT_EXEC_WAIT(N(playModelAnimation))
                EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
                EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(8022630C))
    EVT_RETURN
    EVT_END
};

EvtScript N(8022630C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar3)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar3)
    EVT_IF_EQ(LVar3, 2)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 30)
        EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_ELSE
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 31)
        EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(summonPetitPiranha) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(8)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 30)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(45)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
    EVT_ELSE
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
    EVT_END_IF
    EVT_CALL(LoadBattleDmaData, 18)
    EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim07)
        EVT_WAIT(34)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim08)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim04)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 31)
        EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_END_THREAD
    EVT_WAIT(56)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SummonEnemy, EVT_PTR(N(formation_petit_piranha_1)), 0)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(formation_petit_piranha_2)), 0)
    EVT_END_IF
    EVT_SET(LVar5, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetActorVar, LVar5, 0, ACTOR_ENEMY1)
    EVT_ELSE
        EVT_CALL(SetActorVar, LVar5, 0, ACTOR_ENEMY2)
    EVT_END_IF
    EVT_CALL(GetPartOffset, ACTOR_SELF, 1, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetActorPos, LVar5, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_SUB(LVar1, 15)
    EVT_CALL(PlaySoundAtActor, LVar5, SOUND_3C9)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar9)
    EVT_IF_EQ(LVar9, 1)
        EVT_CALL(GetActorPos, LVar5, LVar0, LVar1, LVar2)
        EVT_SET(LVar0, -12)
        EVT_SET(LVar1, 80)
        EVT_CALL(SetGoalPos, LVar5, LVar0, LVar1, LVar2)
        EVT_CALL(SetHomePos, LVar5, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, LVar5, EVT_FLOAT(4.0))
        EVT_CALL(SetActorJumpGravity, LVar5, EVT_FLOAT(1.0))
        EVT_CALL(FlyToGoal, LVar5, 24, -42, EASING_QUARTIC_OUT)
    EVT_ELSE
        EVT_CALL(GetActorPos, LVar5, LVar0, LVar1, LVar2)
        EVT_SET(LVar0, 18)
        EVT_SET(LVar1, 28)
        EVT_CALL(SetGoalPos, LVar5, LVar0, LVar1, LVar2)
        EVT_CALL(SetHomePos, LVar5, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, LVar5, EVT_FLOAT(5.0))
        EVT_CALL(SetActorJumpGravity, LVar5, EVT_FLOAT(1.2))
        EVT_CALL(FlyToGoal, LVar5, 16, -15, EASING_CUBIC_OUT)
    EVT_END_IF
    EVT_CALL(HPBarToHome, LVar5)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
    EVT_ELSE
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
    EVT_END_IF
    EVT_CALL(LoadBattleDmaData, 31)
    EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(petit_piranha_pos) = { 260, 0, 0 };

Formation N(formation_petit_piranha_1) = {
    { .actor = &b_area_kzn2_petit_piranha, .home = { .vec = &N(petit_piranha_pos) }, .priority = 95, .var0 = -12, .var1 = 85, },
};

Formation N(formation_petit_piranha_2) = {
    { .actor = &b_area_kzn2_petit_piranha, .home = { .vec = &N(petit_piranha_pos) }, .priority = 94, .var0 = 18, .var1 = 38, },
};

Formation N(formation_petit_piranha_bomb) = {
    { .actor = &b_area_kzn2_petit_piranha_bomb, .home = { .vec = &N(petit_piranha_pos) }, .priority = 95, },
};

EvtScript N(onDeath) = {
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_EQ(LVar0, 2)
            EVT_EXEC_WAIT(N(onHit))
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 21)
        EVT_EXEC_WAIT(N(playModelAnimation))
        EVT_CALL(SetActorVar, ACTOR_SELF, 11, 2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
        EVT_END_IF
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_wet)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_wet)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, 2, EVT_PTR(N(DefenseTable_wet)))
        EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaBud_Anim0F)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaBud_Anim09)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim0F)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FIREY, FALSE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_FIREY, FALSE)
        EVT_WAIT(29)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C7)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 27)
        EVT_EXEC_WAIT(N(playModelAnimation))
        EVT_WAIT(14)
        EVT_CALL(SetActorVar, ACTOR_SELF, 5, 2)
        EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LVarF)
        EVT_IF_EQ(LVarF, 0)
            EVT_EXEC_WAIT(N(8022630C))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 21)
        EVT_EXEC_WAIT(N(playModelAnimation))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_wet)))
        EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaBud_Anim0F)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaBud_Anim09)
        EVT_WAIT(29)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C7)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 27)
        EVT_EXEC_WAIT(N(playModelAnimation))
        EVT_WAIT(14)
        EVT_CALL(SetActorVar, ACTOR_SELF, 5, 2)
        EVT_EXEC_WAIT(N(8022630C))
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HIDE_HP_BAR, TRUE)
    EVT_ELSE
        EVT_EXEC_WAIT(N(onHit))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(onHitCombo) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar5)
        EVT_IF_NE(LVar5, 2)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 22)
            EVT_ELSE
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 21)
            EVT_END_IF
            EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_WAIT(29)
        EVT_ELSE
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 20)
            EVT_ELSE
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 19)
            EVT_END_IF
            EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_WAIT(29)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar5)
        EVT_IF_EQ(LVar5, 1)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 22)
            EVT_ELSE
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 21)
            EVT_END_IF
            EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_WAIT(29)
        EVT_ELSE
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 20)
            EVT_ELSE
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 19)
            EVT_END_IF
            EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_SUB(LVar2, 25)
            EVT_ADD(LVar3, 2)
            EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, LVar1, LVar2, LVar3, 40, 50, EVT_FLOAT(1.2), 24, 42, EVT_FLOAT(0.8), EVT_FLOAT(0.6), 0)
            EVT_WAIT(29)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 0, LVar5)
    EVT_IF_EQ(LVar5, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar5)
        EVT_IF_EQ(LVar5, 0)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 22)
            EVT_ELSE
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 21)
            EVT_END_IF
            EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_WAIT(29)
        EVT_ELSE
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 20)
            EVT_ELSE
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 19)
            EVT_END_IF
            EVT_EXEC_WAIT(N(playModelAnimation))
            EVT_WAIT(29)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_FLAG(LVarE, DAMAGE_TYPE_ICE | DAMAGE_TYPE_WATER)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar3)
            EVT_IF_EQ(LVar3, 2)
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_LT(LVar5, 4)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                    EVT_ELSE
                        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                    EVT_END_IF
                    EVT_CALL(LoadBattleDmaData, 20)
                EVT_ELSE
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                    EVT_ELSE
                        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                    EVT_END_IF
                    EVT_CALL(LoadBattleDmaData, 19)
                EVT_END_IF
                EVT_EXEC_WAIT(N(playModelAnimation))
                EVT_WAIT(29)
            EVT_ELSE
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 21)
                EVT_EXEC_WAIT(N(playModelAnimation))
                EVT_CALL(SetActorVar, ACTOR_SELF, 11, 2)
                EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
                EVT_IF_NE(LVar0, 0)
                    EVT_CALL(RemoveEffect, LVar0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_COLD_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 45, 0)
                EVT_END_IF
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_wet)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_wet)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, 2, EVT_PTR(N(DefenseTable_wet)))
                EVT_CALL(SetActorVar, ACTOR_SELF, 7, ANIM_LavaBud_Anim0F)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, ANIM_LavaBud_Anim09)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim0F)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FIREY, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_FIREY, FALSE)
                EVT_WAIT(29)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3C7)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                EVT_ELSE
                    EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                EVT_END_IF
                EVT_CALL(LoadBattleDmaData, 27)
                EVT_EXEC_WAIT(N(playModelAnimation))
                EVT_WAIT(14)
                EVT_CALL(SetActorVar, ACTOR_SELF, 5, 2)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar3)
            EVT_IF_EQ(LVar3, 2)
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_EQ(LVar5, 0)
                    EVT_RETURN
                EVT_END_IF
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_LT(LVar5, 4)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                    EVT_ELSE
                        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                    EVT_END_IF
                    EVT_CALL(LoadBattleDmaData, 20)
                EVT_ELSE
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                    EVT_ELSE
                        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                    EVT_END_IF
                    EVT_CALL(LoadBattleDmaData, 19)
                EVT_END_IF
                EVT_EXEC_WAIT(N(playModelAnimation))
                EVT_WAIT(29)
            EVT_ELSE
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_LT(LVar5, 4)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                    EVT_ELSE
                        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                    EVT_END_IF
                    EVT_CALL(LoadBattleDmaData, 22)
                EVT_ELSE
                    EVT_IF_EQ(LVar0, 1)
                        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
                    EVT_ELSE
                        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
                    EVT_END_IF
                    EVT_CALL(LoadBattleDmaData, 21)
                EVT_END_IF
                EVT_EXEC_WAIT(N(playModelAnimation))
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_SUB(LVar2, 25)
                EVT_ADD(LVar3, 2)
                EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, LVar1, LVar2, LVar3, 40, 50, EVT_FLOAT(1.2), 24, 42, EVT_FLOAT(0.8), EVT_FLOAT(0.6), 0)
                EVT_WAIT(29)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 1, LVarF)
    EVT_IF_EQ(LVarF, 0)
        EVT_EXEC_WAIT(N(8022630C))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(func_80218DF0_59F4D0) {
    Bytecode* args = script->ptrReadPos;
    FlameFXData* data = ((EffectInstance*) evt_get_variable(script, *args++))->data.flame;
    f32 temp_f0 = evt_get_float_variable(script, *args++);

    data->unk_2C = temp_f0;
    data->unk_30 = temp_f0;
    return ApiStatus_DONE2;
}

EvtScript N(attackPetitSpit) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 25)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 350)
        EVT_CALL(SetBattleCamOffsetZ, 30)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(45)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
    EVT_ELSE
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
    EVT_END_IF
    EVT_CALL(LoadBattleDmaData, 18)
    EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim05)
        EVT_WAIT(39)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim06)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LavaBud_Anim03)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE)
        EVT_ELSE
            EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE)
        EVT_END_IF
        EVT_CALL(LoadBattleDmaData, 31)
        EVT_EXEC_WAIT(N(playModelAnimation))
    EVT_END_THREAD
    EVT_WAIT(56)
    EVT_CALL(SummonEnemy, EVT_PTR(N(formation_petit_piranha_bomb)), 0)
    EVT_SET(LVar5, LVar0)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 1, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetActorPos, LVar5, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetAnimation, LVar5, 1, ANIM_PetitPiranha_Anim05)
    EVT_CALL(SetGoalPos, LVar5, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, LVar5, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LVar5, EVT_FLOAT(1.8))
    EVT_CALL(PlaySoundAtActor, LVar5, SOUND_3CB)
    EVT_CALL(SetTargetActor, LVar5, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, LVar5)
    EVT_CALL(EnemyTestTarget, LVar5, LVar9, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetGoalToTarget, LVar5)
            EVT_CALL(GetGoalPos, LVar5, LVar0, LVar1, LVar2)
            EVT_SET(LVar0, -180)
            EVT_CALL(SetGoalPos, LVar5, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, LVar5, EVT_FLOAT(13.0))
            EVT_CALL(SetActorJumpGravity, LVar5, EVT_FLOAT(1.8))
            EVT_CALL(FlyToGoal, LVar5, 0, 0, EASING_LINEAR)
            EVT_IF_EQ(LVar9, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, LVar5, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(RemoveActor, LVar5)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, LVar5, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, LVar5)
    EVT_CALL(SetActorSpeed, LVar5, EVT_FLOAT(13.0))
    EVT_CALL(SetActorJumpGravity, LVar5, EVT_FLOAT(1.8))
    EVT_CALL(FlyToGoal, LVar5, 0, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, LVar5)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar9, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetPartFlagBits, LVar5, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetGoalToTarget, LVar5)
            EVT_CALL(GetGoalPos, LVar5, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 10)
            EVT_ADD(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_FLAME, 2, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), LVarA, 0)
            EVT_CALL(MakeLerp, 120, 10, 20, EASING_QUADRATIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_MULF(LVar0, EVT_FLOAT(0.01))
                EVT_CALL(func_80218DF0_59F4D0, LVarA, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_WAIT(1)
            EVT_CALL(RemoveEffect, LVarA)
            EVT_CALL(RemoveActor, LVar5)
            EVT_WAIT(15)
            EVT_IF_EQ(LVar9, 10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
