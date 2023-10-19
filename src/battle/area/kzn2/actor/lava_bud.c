#include "../area.h"
#include "sprite/npc/LavaBud.h"
#include "sprite/npc/PetitPiranha.h"
#include "ld_addrs.h"
#include "boss_common.h"

#define NAMESPACE A(lava_bud)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_PlayAnimForVine);
extern EvtScript N(EVS_ComboHit);
extern EvtScript N(EVS_Hit);
extern EvtScript N(EVS_BurnHit);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_Attack_SpitPetit);
extern EvtScript N(EVS_Move_SummonPetit);
extern EvtScript N(EVS_PlayIdleAnimation);

extern EvtScript A(lava_piranha_EVS_Ignite);

extern ActorBlueprint A(petit_piranha);
extern ActorBlueprint A(petit_piranha_bomb);

extern Formation N(LeftPetitFormation);
extern Formation N(RightPetitFormation);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_SummonDelayTurns   = 4,
};

enum N(ActorParams) {
    DMG_PETIT_SPIT      = 4,
};

static s32 N(unusedArray)[64];

MATCHING_BSS(0x8A0);

BSS u8 Vine3Base[0x2000];
BSS u8 Vine2Base[0x3000];
BSS u8 Vine1Base[0x3000];
BSS u8 Vine0Base[0x4000];

#define VINE_1_BASE (s32) Vine1Base
#define VINE_2_BASE (s32) Vine2Base

#define EVT_LOAD_BUD_ANIM(whichVine, anim) \
    EVT_IF_EQ(whichVine, VINE_1) \
        EVT_CALL(OverrideBattleDmaDest, VINE_1_BASE) \
    EVT_ELSE \
        EVT_CALL(OverrideBattleDmaDest, VINE_2_BASE) \
    EVT_END_IF \
    EVT_CALL(LoadBattleDmaData, anim)

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaBud_Anim03,
    STATUS_KEY_STOP,      ANIM_LavaBud_Anim02,
    STATUS_END,
};

s32 N(FieryAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaBud_Anim04,
    STATUS_KEY_STOP,      ANIM_LavaBud_Anim02,
    STATUS_END,
};

s32 N(StunnedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LavaBud_Anim0F,
    STATUS_KEY_STOP,      ANIM_LavaBud_Anim0F,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,    0,
    ELEMENT_ICE,      0,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
    ELEMENT_END,
};

s32 N(FieryDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,   -2,
    ELEMENT_ICE,     -2,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
    ELEMENT_END,
};

s32 N(StunnedDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,    0,
    ELEMENT_ICE,      0,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              75,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,               60,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
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
    .level = ACTOR_LEVEL_LAVA_BUD_PHASE_1,
    .maxHP = 8,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .healthBarOffset = { 10, -42 },
    .statusIconOffset = { -18, 10 },
    .statusTextOffset = { 0, 0 },
};

EvtScript N(EVS_Init) = {
    EVT_USE_ARRAY(N(unusedArray))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, PIRANHA_STATE_STUNNED)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_FlameEffect, NULL)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Bud_PetitCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SummonDelayTurns, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_StunTurnsLeft, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_NextTwitchTime, 0)
    EVT_CALL(RandInt, 20, LVar0)
    EVT_ADD(LVar0, 15)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_NextTwitchTime, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim1, ANIM_LavaBud_Anim03)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, ANIM_LavaBud_Anim09)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorHP, ACTOR_BOSS, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_GOTO(99)
        EVT_END_IF
        EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
        EVT_IF_FLAG(LVar0, ACTOR_FLAG_NO_DMG_APPLY)
            EVT_GOTO(99)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar0)
        EVT_IF_NE(LVar0, PIRANHA_STATE_DEAD)
            EVT_GOTO(99)
        EVT_END_IF
        EVT_LABEL(10)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_NextTwitchTime, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_NextTwitchTime, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_GOTO(99)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_NextTwitchMode, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_IF_GE(LVar0, 3)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_NextTwitchMode, LVar0)
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
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_NextTwitchTime, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_TWITCH)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
        EVT_LABEL(99)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayAnimForVine) = {
    EVT_IF_EQ(LVar0, VINE_1)
        EVT_CALL(PlayModelAnimation, LVar0, VINE_1_BASE)
    EVT_ELSE
        EVT_CALL(PlayModelAnimation, LVar0, VINE_2_BASE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(EVS_ComboHit))
        EVT_CASE_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(EVS_Hit))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(EVS_BurnHit))
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(EVS_Death))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(EVS_Hit))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(EVS_Death))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_IF_NOT_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(EVS_ComboHit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_IF_NOT_FLAG(LVarE, DAMAGE_TYPE_FIRE)
                EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(EVS_Death))
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
            EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 0)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STOP)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
        EVT_CALL(SetAnimatorFlags, LVar0, MODEL_ANIMATOR_FLAG_FREEZE_ANIMATION, 1)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BurnHit) = {
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_IsSecondPhase, LVar0)
        EVT_IF_FALSE(LVar0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar2)
        EVT_IF_EQ(LVar2, PIRANHA_STATE_FIERY)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
        EVT_IF_EQ(LVar0, VINE_1)
            EVT_SET(LVar0, ACTOR_BUD_1)
        EVT_ELSE
            EVT_SET(LVar0, ACTOR_BUD_2)
        EVT_END_IF
        EVT_EXEC_WAIT(A(lava_piranha_EVS_Ignite))
        EVT_LABEL(10)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_IsSecondPhase, LVar0)
    EVT_IF_TRUE(LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar0)
        EVT_IF_EQ(LVar0, PIRANHA_STATE_DEAD)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
            EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_RECOVER)
            EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim1, ANIM_LavaBud_Anim03)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, ANIM_LavaBud_Anim09)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(FieryAnims)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(FieryDefense)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_TARGET, EVT_PTR(N(FieryDefense)))
            EVT_THREAD
                EVT_WAIT(14)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_IDLE)
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_NO_DMG_APPLY)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_IsSecondPhase, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar0)
        EVT_IF_EQ(LVar0, PIRANHA_STATE_DEAD)
            EVT_RETURN
        EVT_END_IF
        EVT_EXEC_WAIT(N(EVS_Attack_SpitPetit))
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SummonDelayTurns, LVar1)
        EVT_IF_NE(LVar1, 0)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SummonDelayTurns, LVar1)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar0)
        EVT_IF_EQ(LVar0, PIRANHA_STATE_FIERY)
            EVT_IF_NE(LVar1, 0)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SummonDelayTurns, 1)
            EVT_EXEC_WAIT(N(EVS_Move_SummonPetit))
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_StunTurnsLeft, LVar0)
            EVT_SUB(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_StunTurnsLeft, LVar0)
            EVT_IF_LE(LVar0, 0)
                EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
                EVT_IF_EQ(LVar0, VINE_1)
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
                    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_TWITCH)
                    EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                    EVT_WAIT(4)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 15)
                EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim04)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
                EVT_IF_EQ(LVar0, VINE_1)
                    EVT_SET(LVar0, ACTOR_BUD_1)
                EVT_ELSE
                    EVT_SET(LVar0, ACTOR_BUD_2)
                EVT_END_IF
                EVT_CALL(PlaySoundAtActor, LVar0, SOUND_LAVA_BUD_RECOVER)
                EVT_EXEC_WAIT(A(lava_piranha_EVS_Ignite))
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_RECOVER)
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                EVT_WAIT(14)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_IDLE)
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
                EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_PlayIdleAnimation))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PlayIdleAnimation) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim1, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_IsSecondPhase, LVar3)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar3)
    EVT_IF_EQ(LVar3, PIRANHA_STATE_DEAD)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_TWITCH)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
    EVT_ELSE
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_IDLE)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_SummonPetit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar0)
    EVT_IF_EQ(LVar0, PIRANHA_STATE_DEAD)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_PetitCount, LVar0)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_ATTACK)
    EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim07)
        EVT_WAIT(34)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim08)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim04)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_IDLE)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
    EVT_END_THREAD
    EVT_WAIT(56)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SummonEnemy, EVT_PTR(N(LeftPetitFormation)), FALSE)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(RightPetitFormation)), FALSE)
    EVT_END_IF
    EVT_SET(LVar5, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_PetitCount, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Bud_PetitCount, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_IF_EQ(LVar0, VINE_1)
        EVT_CALL(SetActorVar, LVar5, AVAR_Petit_Parent, ACTOR_BUD_1)
    EVT_ELSE
        EVT_CALL(SetActorVar, LVar5, AVAR_Petit_Parent, ACTOR_BUD_2)
    EVT_END_IF
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_MAIN, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetActorPos, LVar5, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_SUB(LVar1, 15)
    EVT_CALL(PlaySoundAtActor, LVar5, SOUND_LAVA_BUD_SPIT_PETIT)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar9)
    EVT_IF_EQ(LVar9, VINE_1)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_IDLE)
    EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonPos) = { 260, 0, 0 };

Formation N(LeftPetitFormation) = {
    ACTOR_BY_POS(A(petit_piranha), N(SummonPos), 95, -12, 85),
};

Formation N(RightPetitFormation) = {
    ACTOR_BY_POS(A(petit_piranha), N(SummonPos), 94, 18, 38),
};

Formation N(PetitBombFormation) = {
    ACTOR_BY_POS(A(petit_piranha_bomb), N(SummonPos), 95),
};

EvtScript N(EVS_Death) = {
    EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_IsSecondPhase, LVar0)
    EVT_IF_TRUE(LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar0)
        EVT_IF_EQ(LVar0, PIRANHA_STATE_DEAD)
            EVT_EXEC_WAIT(N(EVS_Hit))
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, LVar0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_HEAVY_HIT)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_StunTurnsLeft, 2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_FlameEffect, LVar0)
        EVT_IF_NE(LVar0, NULL)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_FlameEffect, NULL)
        EVT_END_IF
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(StunnedAnims)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(StunnedDefense)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_TARGET, EVT_PTR(N(StunnedDefense)))
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim1, ANIM_LavaBud_Anim0F)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, ANIM_LavaBud_Anim09)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim0F)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FIREY, FALSE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_TARGET, ACTOR_EVENT_FLAG_FIREY, FALSE)
        EVT_WAIT(29)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LAVA_BUD_WITHER)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUN)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
        EVT_WAIT(14)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, PIRANHA_STATE_DEAD)
        EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_Dying, LVarF)
        EVT_IF_EQ(LVarF, 0)
            EVT_EXEC_WAIT(N(EVS_PlayIdleAnimation))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar0)
    EVT_IF_EQ(LVar0, PIRANHA_STATE_STUNNED)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_HEAVY_HIT)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(StunnedAnims)))
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim1, ANIM_LavaBud_Anim0F)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, ANIM_LavaBud_Anim09)
        EVT_WAIT(29)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LAVA_BUD_WITHER)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUN)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
        EVT_WAIT(14)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, PIRANHA_STATE_DEAD)
        EVT_EXEC_WAIT(N(EVS_PlayIdleAnimation))
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Hit))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ComboHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_IsSecondPhase, LVar1)
    EVT_IF_FALSE(LVar1)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar5)
        EVT_IF_NE(LVar5, PIRANHA_STATE_DEAD)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_LIGHT_HIT)
            EVT_ELSE
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_HEAVY_HIT)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
            EVT_WAIT(29)
        EVT_ELSE
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_LIGHT_HIT)
            EVT_ELSE
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_HEAVY_HIT)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
            EVT_WAIT(29)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar5)
        EVT_IF_EQ(LVar5, PIRANHA_STATE_FIERY)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_LIGHT_HIT)
            EVT_ELSE
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_HEAVY_HIT)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
            EVT_WAIT(29)
        EVT_ELSE
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_LIGHT_HIT)
            EVT_ELSE
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_HEAVY_HIT)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
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

EvtScript N(EVS_Hit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_IsSecondPhase, LVar5)
    EVT_IF_FALSE(LVar5)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar5)
        EVT_IF_EQ(LVar5, PIRANHA_STATE_STUNNED)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_LIGHT_HIT)
            EVT_ELSE
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_HEAVY_HIT)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
            EVT_WAIT(29)
        EVT_ELSE
            EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
            EVT_IF_LT(LVar5, 4)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_LIGHT_HIT)
            EVT_ELSE
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_HEAVY_HIT)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
            EVT_WAIT(29)
        EVT_END_IF
    EVT_ELSE
        EVT_IF_FLAG(LVarE, DAMAGE_TYPE_ICE | DAMAGE_TYPE_WATER)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar3)
            EVT_IF_EQ(LVar3, PIRANHA_STATE_DEAD)
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_LT(LVar5, 4)
                    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_LIGHT_HIT)
                EVT_ELSE
                    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_HEAVY_HIT)
                EVT_END_IF
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                EVT_WAIT(29)
            EVT_ELSE
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_HEAVY_HIT)
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_StunTurnsLeft, 2)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_FlameEffect, LVar0)
                EVT_IF_NE(LVar0, NULL)
                    EVT_CALL(RemoveEffect, LVar0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_FlameEffect, NULL)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_COLD_BREATH, 0, LVar0, LVar1, LVar2, EVT_FLOAT(2.0), 45, 0)
                EVT_END_IF
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(StunnedAnims)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(StunnedDefense)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_TARGET, EVT_PTR(N(StunnedDefense)))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim1, ANIM_LavaBud_Anim0F)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_UnkAnim2, ANIM_LavaBud_Anim09)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim0F)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FIREY, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_TARGET, ACTOR_EVENT_FLAG_FIREY, FALSE)
                EVT_WAIT(29)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LAVA_BUD_WITHER)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
                EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUN)
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                EVT_WAIT(14)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, PIRANHA_STATE_DEAD)
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Common_PiranhaState, LVar3)
            EVT_IF_EQ(LVar3, PIRANHA_STATE_DEAD)
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_EQ(LVar5, 0)
                    EVT_RETURN
                EVT_END_IF
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_LT(LVar5, 4)
                    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_LIGHT_HIT)
                EVT_ELSE
                    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_STUNNED_HEAVY_HIT)
                EVT_END_IF
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                EVT_WAIT(29)
            EVT_ELSE
                EVT_CALL(GetLastDamage, ACTOR_SELF, LVar5)
                EVT_IF_LT(LVar5, 4)
                    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_LIGHT_HIT)
                EVT_ELSE
                    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_HEAVY_HIT)
                EVT_END_IF
                EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_SUB(LVar2, 25)
                EVT_ADD(LVar3, 2)
                EVT_PLAY_EFFECT(EFFECT_EMBERS, 0, LVar1, LVar2, LVar3, 40, 50, EVT_FLOAT(1.2), 24, 42, EVT_FLOAT(0.8), EVT_FLOAT(0.6), 0)
                EVT_WAIT(29)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_BOSS, AVAR_Boss_Dying, LVarF)
    EVT_IF_EQ(LVarF, 0)
        EVT_EXEC_WAIT(N(EVS_PlayIdleAnimation))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SetPetitFlameSize)) {
    Bytecode* args = script->ptrReadPos;
    FlameFXData* data = ((EffectInstance*) evt_get_variable(script, *args++))->data.flame;
    f32 scale = evt_get_float_variable(script, *args++);

    data->scaleH = scale;
    data->scaleW = scale;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Attack_SpitPetit) = {
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
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bud_WhichVine, LVar0)
    EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_ATTACK)
    EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim05)
        EVT_WAIT(39)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim06)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LavaBud_Anim03)
        EVT_LOAD_BUD_ANIM(LVar0, VINE_ANIM_BUD_IDLE)
        EVT_EXEC_WAIT(N(EVS_PlayAnimForVine))
    EVT_END_THREAD
    EVT_WAIT(56)
    EVT_CALL(SummonEnemy, EVT_PTR(N(PetitBombFormation)), FALSE)
    EVT_SET(LVar5, LVar0)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_MAIN, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 15)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetActorPos, LVar5, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetAnimation, LVar5, 1, ANIM_PetitPiranha_Anim05)
    EVT_CALL(SetGoalPos, LVar5, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, LVar5, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LVar5, EVT_FLOAT(1.8))
    EVT_CALL(PlaySoundAtActor, LVar5, SOUND_PETIT_PIRANHA_DIVE)
    EVT_CALL(SetTargetActor, LVar5, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, LVar5)
    EVT_CALL(EnemyTestTarget, LVar5, LVar9, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar9, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, DMG_PETIT_SPIT, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetPartFlagBits, LVar5, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetGoalToTarget, LVar5)
            EVT_CALL(GetGoalPos, LVar5, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 10)
            EVT_ADD(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_FLAME, FX_FLAME_SMALL_BLUE, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), LVarA, 0)
            EVT_CALL(MakeLerp, 120, 10, 20, EASING_QUADRATIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_MULF(LVar0, EVT_FLOAT(0.01))
                EVT_CALL(N(SetPetitFlameSize), LVarA, LVar0)
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
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
