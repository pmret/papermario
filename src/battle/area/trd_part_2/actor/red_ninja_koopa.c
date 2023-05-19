#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/KoopaBros.h"

#define NAMESPACE b_area_trd_part_2_red_ninja_koopa

extern s32 N(IdleAnimations_80228610)[];
extern EvtScript N(init_8022AC8C);
extern EvtScript N(idle_8022AD80);
extern EvtScript N(handleEvent_8022ADE8);
extern EvtScript N(nextTurn_8022B484);
extern EvtScript N(takeTurn_8022B474);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

s32 N(DefenseTable_80228500)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(DefenseTable_8022850C)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable_80228518)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              60,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           60,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,               75,
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

ActorPartBlueprint N(ActorParts_802285C4)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 36 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80228610),
        .defenseTable = N(DefenseTable_80228500),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_RED_NINJAKOOPA,
    .level = 17,
    .maxHP = 5,
    .partCount = ARRAY_COUNT( N(ActorParts_802285C4)),
    .partsData = N(ActorParts_802285C4),
    .initScript = &N(init_8022AC8C),
    .statusTable = N(StatusTable_80228518),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 0,
    .size = { 38, 42 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(IdleAnimations_80228610)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaBros_Red_Anim04,
    STATUS_KEY_STONE,     ANIM_KoopaBros_Red_Anim00,
    STATUS_KEY_SLEEP,     ANIM_KoopaBros_Red_Anim15,
    STATUS_KEY_POISON,    ANIM_KoopaBros_Red_Anim00,
    STATUS_KEY_STOP,      ANIM_KoopaBros_Red_Anim00,
    STATUS_KEY_STATIC,    ANIM_KoopaBros_Red_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim00,
    STATUS_KEY_DIZZY,     ANIM_KoopaBros_Red_Anim18,
    STATUS_KEY_DIZZY,     ANIM_KoopaBros_Red_Anim18,
    STATUS_END,
};

s32 N(IdleAnimations_80228664)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaBros_Red_Anim05,
    STATUS_KEY_STONE,     ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_POISON,    ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_STOP,      ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_STATIC,    ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim01,
    STATUS_END,
};

s32 N(IdleAnimations_802286A0)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaBros_Red_Anim0D,
    STATUS_KEY_STONE,     ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_POISON,    ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_STOP,      ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_STATIC,    ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim01,
    STATUS_END,
};

s32 N(IdleAnimations_802286DC)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaBros_Red_Anim0C,
    STATUS_KEY_STONE,     ANIM_KoopaBros_Red_Anim17,
    STATUS_KEY_SLEEP,     ANIM_KoopaBros_Red_Anim17,
    STATUS_KEY_POISON,    ANIM_KoopaBros_Red_Anim17,
    STATUS_KEY_STOP,      ANIM_KoopaBros_Red_Anim17,
    STATUS_KEY_STATIC,    ANIM_KoopaBros_Red_Anim17,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim17,
    STATUS_KEY_PARALYZE,  ANIM_KoopaBros_Red_Anim17,
    STATUS_KEY_DIZZY,     ANIM_KoopaBros_Red_Anim22,
    STATUS_KEY_DIZZY,     ANIM_KoopaBros_Red_Anim22,
    STATUS_END,
};

s32 N(IdleAnimations_80228730)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaBros_Red_Anim0A,
    STATUS_END,
};

s32 N(IdleAnimations_8022873C)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaBros_Red_Anim0C,
    STATUS_END,
};

#include "common/StartRumbleWithParams.inc.c"

#include "common/UnkWhirlwindEffectFunc.inc.c"

#include "common/UnkEnemyFunc.inc.c"

#include "common/UnkEnemyPosFunc.inc.c"

#include "common/GetLastActorEventType.inc.c"

EvtScript N(80228748) = {
    EVT_CALL(SetOwnerID, ACTOR_ENEMY3)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_80228610)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim04)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_80228664)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim05)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_WAIT(5)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_802286A0)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0D)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, 192)
                    EVT_IF_NE(LVar0, 192)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_802286A0)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0D)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_80228730)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0A)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(3)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(N(GetLastActorEventType), 14)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0E)
                    EVT_SET_CONST(LVar2, -1)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, 192)
                    EVT_IF_NE(LVar0, 192)
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_802286A0)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0D)
                    EVT_ELSE
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_80228730)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0A)
                    EVT_END_IF
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(4)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim08)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim09)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim1F)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim20)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_WAIT(15)
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET(LocalFlag(0), 0)
                    EVT_IF_EQ(LVar0, 3)
                        EVT_SET(LocalFlag(0), 1)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
                    EVT_CALL(N(UnkEnemyPosFunc), LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0A)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_80228730)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LocalFlag(0), 1)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.8))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0C)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_8022873C)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_802286DC)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable_8022850C)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(6)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(3)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_SET(LocalFlag(0), 0)
                    EVT_IF_EQ(LVar0, 3)
                        EVT_SET(LocalFlag(0), 1)
                    EVT_END_IF
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
                    EVT_CALL(N(UnkEnemyPosFunc), LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0E)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_80228730)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
                    EVT_IF_EQ(LocalFlag(0), 1)
                        EVT_CALL(N(StartRumbleWithParams), 256, 5)
                        EVT_THREAD
                            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.8))
                        EVT_END_THREAD
                    EVT_END_IF
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                    EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                    EVT_ADDF(LVar1, LVar3)
                    EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                    EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                    EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0C)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_8022873C)))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(HPBarToHome, ACTOR_SELF)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_802286DC)))
                    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable_8022850C)))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(9)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
                    EVT_SUB(LVar0, 1)
                    EVT_IF_GT(LVar0, 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                        EVT_WAIT(20)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                    EVT_ELSE
                        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                        EVT_WAIT(12)
                        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                        EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_0, 0)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
                        EVT_THREAD
                            EVT_SET(LVar0, 0)
                            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 18, 0)
                            EVT_LOOP(4)
                                EVT_ADD(LVar0, 22)
                                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                                EVT_WAIT(1)
                            EVT_END_LOOP
                        EVT_END_THREAD
                        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
                        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
                        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 36)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
                        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable_80228500)))
                        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_80228610)))
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim04)
                        EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
                    EVT_END_IF
                EVT_CASE_DEFAULT
                    EVT_WAIT(20)
            EVT_END_SWITCH
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(7)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim08)
                    EVT_WAIT(10)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_356)
                        EVT_CASE_EQ(3)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_355)
                        EVT_CASE_EQ(2)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_354)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim07)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 60)
                    EVT_WAIT(60)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_10)
                        EVT_SWITCH(LVar0)
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVarA)
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        EVT_IF_GT(LVar0, LVar3)
                            EVT_WAIT(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar1)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, LVar1, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37C)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(13.0))
                        EVT_CASE_EQ(3)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                    EVT_END_SWITCH
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                    EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                    EVT_SET(LVar4, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVarB)
                    EVT_SET(LVar0, LVarB)
                    EVT_SUB(LVar0, 1)
                    EVT_MUL(LVar0, 18)
                    EVT_SWITCH(LVarB)
                        EVT_CASE_EQ(4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -10)
                        EVT_CASE_EQ(3)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -7)
                        EVT_CASE_EQ(2)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, LVar0, -4)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 3, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 60)
                            EVT_WAIT(60)
                        EVT_CASE_EQ(3)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 50)
                            EVT_WAIT(50)
                        EVT_CASE_EQ(2)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 40)
                            EVT_WAIT(40)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim09)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F3)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim1B)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 22)
                    EVT_ADD(LVar1, 19)
                    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim04)
                    EVT_WAIT(20)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 1, 0)
                EVT_CASE_OR_EQ(4)
                EVT_CASE_OR_EQ(5)
                EVT_CASE_OR_EQ(6)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim1F)
                    EVT_WAIT(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim07)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 60)
                    EVT_WAIT(60)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
                        EVT_CASE_EQ(5)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
                        EVT_CASE_EQ(6)
                            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_END_SWITCH
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 36, -7)
                        EVT_CASE_EQ(5)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 18, -4)
                        EVT_CASE_EQ(6)
                            EVT_CALL(GetActorVar, ACTOR_ENEMY4, 4, LVar1)
                            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                            EVT_SET(LVar4, 15)
                            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
                            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
                    EVT_END_SWITCH
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(4)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 50)
                            EVT_WAIT(50)
                        EVT_CASE_EQ(5)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 40)
                            EVT_WAIT(40)
                        EVT_CASE_EQ(6)
                            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                            EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 30)
                            EVT_WAIT(30)
                    EVT_END_SWITCH
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim20)
                    EVT_WAIT(10)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim05)
                    EVT_WAIT(30)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(8)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SET(LVar2, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim03)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim1F)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_353)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim07)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 30)
                    EVT_WAIT(30)
                    EVT_THREAD
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, BS_FLAGS1_10)
                        EVT_SWITCH(LVar0)
                            EVT_CASE_EQ(HIT_RESULT_LUCKY)
                                EVT_WAIT(20)
                                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                                EVT_RETURN
                            EVT_CASE_EQ(HIT_RESULT_MISS)
                                EVT_RETURN
                        EVT_END_SWITCH
                        EVT_LABEL(0)
                        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
                        EVT_IF_GT(LVar0, LVar3)
                            EVT_WAIT(1)
                            EVT_GOTO(0)
                        EVT_END_IF
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_END_THREAD
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37C)
                    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -160, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK)
                    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
                    EVT_THREAD
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 15, 0)
                        EVT_SET(LVar0, 0)
                        EVT_LOOP(40)
                            EVT_SUB(LVar0, 45)
                            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, LVar0)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
                    EVT_END_THREAD
                    EVT_CALL(GetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SET(LVar2, 15)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 40, FALSE, TRUE, FALSE)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(N(UnkWhirlwindEffectFunc), LVar0, LVar1, LVar2, 30)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim09)
                    EVT_WAIT(10)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F3)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim1B)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 22)
                    EVT_ADD(LVar1, 19)
                    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
                    EVT_WAIT(30)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim03)
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
                    EVT_CALL(GetActorVar, ACTOR_ENEMY4, 0, LVar0)
                    EVT_BITWISE_AND_CONST(LVar0, -513)
                    EVT_CALL(SetActorVar, ACTOR_ENEMY4, 0, LVar0)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8022AC8C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022B474)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022AD80)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022ADE8)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_8022B484)))
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022AD80) = {
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8022AD90)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

EvtScript N(handleEvent_8022ADE8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0E)
            EVT_SET_CONST(LVar2, ANIM_KoopaBros_Red_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0E)
            EVT_SET_CONST(LVar2, ANIM_KoopaBros_Red_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 2)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(IdleAnimations_802286DC)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable_8022850C)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 18)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0B)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_THREAD
                    EVT_WAIT(4)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                    EVT_WAIT(1)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                    EVT_WAIT(1)
                EVT_END_THREAD
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim0C)
            EVT_END_IF
            EVT_USE_BUF(EVT_PTR(N(intTable_8022AD90)))
            EVT_LOOP(22)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaBros_Red_Anim09)
                    EVT_WAIT(10)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0C)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaBros_Red_Anim04)
                EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022B474) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8022B484) = {
    EVT_RETURN
    EVT_END
};
