#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Spiny.h"
#include "sprite/npc/Lakitu.h"

#define NAMESPACE A(spiny)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BALL        = 2,
};

enum N(ActorVars) {
    AVAR_Toppled        = 0,
    AVAR_ToppleTurns    = 1,
};

enum N(ActorParams) {
    DMG_ROLL        = 4,
};

s32 N(UprightAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Spiny_Anim01,
    STATUS_KEY_STONE,     ANIM_Spiny_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Spiny_Anim10,
    STATUS_KEY_POISON,    ANIM_Spiny_Anim01,
    STATUS_KEY_STOP,      ANIM_Spiny_Anim00,
    STATUS_KEY_STATIC,    ANIM_Spiny_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Spiny_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Spiny_Anim12,
    STATUS_KEY_FEAR,      ANIM_Spiny_Anim12,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Spiny_Anim02,
    STATUS_KEY_STONE,     ANIM_Spiny_Anim15,
    STATUS_KEY_SLEEP,     ANIM_Spiny_Anim11,
    STATUS_KEY_POISON,    ANIM_Spiny_Anim02,
    STATUS_KEY_STOP,      ANIM_Spiny_Anim15,
    STATUS_KEY_STATIC,    ANIM_Spiny_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_Spiny_Anim15,
    STATUS_KEY_DIZZY,     ANIM_Spiny_Anim13,
    STATUS_KEY_FEAR,      ANIM_Spiny_Anim13,
    STATUS_END,
};

s32 N(SpinyBallAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lakitu_Anim0B,
    STATUS_END,
};

s32 N(UprightDefense)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_END,
};

s32 N(ToppledDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
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
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(UprightAnims),
        .defenseTable = N(UprightDefense),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -4 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BALL,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpinyBallAnims),
        .defenseTable = N(UprightDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPINY,
    .level = ACTOR_LEVEL_SPINY,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 75,
    .hurricaneChance = 75,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 24, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BALL, ANIM_Lakitu_Anim0C)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim1A)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CheckToppleAnim) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar3)
    EVT_IF_EQ(LVar3, 1)
        EVT_SET(LVar1, LVar2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(FlipPosOffsets)[] = { 7, 13, 17, 21, 23, 24, 23, 21, 17, 13, 7, 0, 4, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Spiny_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0A)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_NE(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Spiny_Anim0B)
                EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0C)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Spiny_Anim0D)
                EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0E)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_NE(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Spiny_Anim0B)
                EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0C)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Spiny_Anim0C)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Spiny_Anim0D)
                EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0E)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Spiny_Anim0E)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Spiny_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0A)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Spiny_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0A)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Spiny_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0A)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim0A)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim16)
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Toppled, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefense)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ALT_SPIKY, FALSE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_USE_BUF(N(FlipPosOffsets))
            EVT_LOOP(19)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(20)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim06)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim07)
                    EVT_WAIT(10)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim02)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVarA)
                EVT_IF_EQ(LVarA, 0)
                    EVT_ADD(LVar0, 0)
                EVT_END_IF
                EVT_ADD(LVar1, 8)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVarA)
                EVT_IF_EQ(LVarA, 0)
                    EVT_ADD(LVar0, -1)
                EVT_END_IF
                EVT_ADD(LVar1, 22)
            EVT_END_IF
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Spiny_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0A)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Spiny_Anim09)
            EVT_SET_CONST(LVar2, ANIM_Spiny_Anim0A)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim01)
                    EVT_EXEC_WAIT(EVS_Enemy_Recover)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim02)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim04)
                    EVT_SET_CONST(LVar2, ANIM_Spiny_Anim09)
                    EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
                    EVT_RETURN
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim02)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim04)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim02)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim04)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Spiny_Anim02)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim14)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
        EVT_ELSE
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim14)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Spiny_Anim02)
            EVT_SET_CONST(LVar2, ANIM_Spiny_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_FlipBackUp)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightDefense)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ALT_SPIKY, TRUE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim19)
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Spiny_Anim18)
        EVT_WAIT(10)
    EVT_ELSE
        EVT_WAIT(20)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EVT_END_THREAD
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BALL, ANIM_Lakitu_Anim0C)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_BALL, SOUND_SPINY_SPIN_UP)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_BALL, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    EVT_IF_GT(LVar0, LVar3)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_ROLL, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BALL, ANIM_Lakitu_Anim0B)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
