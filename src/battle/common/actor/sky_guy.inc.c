#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/SkyGuy.h"

#define NAMESPACE A(sky_guy)

extern s32 N(GroundAnims)[];

extern EvtScript N(EVS_Flying_Init);
extern EvtScript N(EVS_Flying_Idle);
extern EvtScript N(EVS_Flying_TakeTurn);
extern EvtScript N(EVS_Flying_HandleEvent);

extern EvtScript N(EVS_Ground_Idle);
extern EvtScript N(EVS_Ground_TakeTurn);
extern EvtScript N(EVS_Ground_HandleEvent);

enum N(ActorPartIDs) {
    PRT_GROUND          = 1,
    PRT_FLYING          = 2,
    PRT_YELLOW_BALLOON  = 3,
    PRT_RED_BALLOON     = 4,
    PRT_BLUE_BALLOON    = 5,
    PRT_STONE           = 6,
};

enum N(ActorVars) {
    AVAR_BalloonState       = 8,
    AVAL_Balloons_Intact    = 0,
    AVAL_Balloons_Popping   = 1,
    AVAL_Balloons_Popped    = 2,
};

enum N(ActorParams) {
    DMG_SLINGSHOT   = 3,
    DMG_TACKLE      = 2,
    DMG_VAULT       = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SkyGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_SkyGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_SkyGuy_Anim04,
    STATUS_KEY_POISON,    ANIM_SkyGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_SkyGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_SkyGuy_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_SkyGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_SkyGuy_Anim05,
    STATUS_KEY_FEAR,      ANIM_SkyGuy_Anim05,
    STATUS_END,
};

s32 N(YellowBalloonAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SkyGuy_Anim10,
    STATUS_KEY_STONE,     ANIM_SkyGuy_Anim0D,
    STATUS_KEY_SLEEP,     ANIM_SkyGuy_Anim19,
    STATUS_KEY_POISON,    ANIM_SkyGuy_Anim10,
    STATUS_KEY_STOP,      ANIM_SkyGuy_Anim0D,
    STATUS_KEY_STATIC,    ANIM_SkyGuy_Anim10,
    STATUS_KEY_PARALYZE,  ANIM_SkyGuy_Anim0D,
    STATUS_KEY_DIZZY,     ANIM_SkyGuy_Anim10,
    STATUS_KEY_FEAR,      ANIM_SkyGuy_Anim10,
    STATUS_END,
};

s32 N(RedBalloonAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SkyGuy_Anim0F,
    STATUS_KEY_STONE,     ANIM_SkyGuy_Anim0C,
    STATUS_KEY_SLEEP,     ANIM_SkyGuy_Anim18,
    STATUS_KEY_POISON,    ANIM_SkyGuy_Anim0F,
    STATUS_KEY_STOP,      ANIM_SkyGuy_Anim0C,
    STATUS_KEY_STATIC,    ANIM_SkyGuy_Anim0F,
    STATUS_KEY_PARALYZE,  ANIM_SkyGuy_Anim0C,
    STATUS_KEY_DIZZY,     ANIM_SkyGuy_Anim0F,
    STATUS_KEY_FEAR,      ANIM_SkyGuy_Anim0F,
    STATUS_END,
};

s32 N(BlueBalloonAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SkyGuy_Anim11,
    STATUS_KEY_STONE,     ANIM_SkyGuy_Anim0E,
    STATUS_KEY_SLEEP,     ANIM_SkyGuy_Anim1A,
    STATUS_KEY_POISON,    ANIM_SkyGuy_Anim11,
    STATUS_KEY_STOP,      ANIM_SkyGuy_Anim0E,
    STATUS_KEY_STATIC,    ANIM_SkyGuy_Anim11,
    STATUS_KEY_PARALYZE,  ANIM_SkyGuy_Anim0E,
    STATUS_KEY_DIZZY,     ANIM_SkyGuy_Anim11,
    STATUS_KEY_FEAR,      ANIM_SkyGuy_Anim11,
    STATUS_END,
};

s32 N(StoneAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SkyGuy_Anim0B,
    STATUS_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(GroundDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(StatusTable_802296D0)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(GroundDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_YELLOW_BALLOON,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 50 },
        .opacity = 255,
        .idleAnimations = N(YellowBalloonAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
        .overrideNameMsg = MSG_EnemyName_Balloon,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_RED_BALLOON,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(RedBalloonAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_BLUE_BALLOON,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(BlueBalloonAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_STONE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(StoneAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_SKY_GUY,
    .level = ACTOR_LEVEL_SKY_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Flying_Init),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 50,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 28, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Flying_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Flying_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Flying_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Flying_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Intact)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_YELLOW_BALLOON, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_RED_BALLOON, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BLUE_BALLOON, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 5)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_TARGET_NO_DAMAGE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KillActor) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_BalloonState, LVar2)
    EVT_IF_NE(LVar2, AVAL_Balloons_Intact)
        EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Popping)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        EVT_ADD(LVar8, 20)
        EVT_PLAY_EFFECT(EFFECT_BALLOON, 2, LVar7, LVar8, LVar9, EVT_FLOAT(1.0), 150, 0)
        EVT_SUB(LVar7, 14)
        EVT_SUB(LVar8, 4)
        EVT_PLAY_EFFECT(EFFECT_BALLOON, 0, LVar7, LVar8, LVar9, EVT_FLOAT(1.0), 150, 0)
        EVT_ADD(LVar7, 28)
        EVT_PLAY_EFFECT(EFFECT_BALLOON, 1, LVar7, LVar8, LVar9, EVT_FLOAT(1.0), 150, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Popped)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ResetAnimations) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_YELLOW_BALLOON, ANIM_SkyGuy_Anim13)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_RED_BALLOON, ANIM_SkyGuy_Anim12)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BLUE_BALLOON, ANIM_SkyGuy_Anim14)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StretchBalloons) = {
    EVT_CALL(MakeLerp, 100, 80, 7, EASING_CUBIC_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(100.0))
        EVT_SETF(LVar2, EVT_FLOAT(2.0))
        EVT_SUBF(LVar2, LVar0)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_YELLOW_BALLOON, LVar2, LVar0, EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_RED_BALLOON, LVar2, LVar0, EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_BLUE_BALLOON, LVar2, LVar0, EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(MakeLerp, 80, 100, 7, EASING_COS_FAST_OVERSHOOT)
    EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_DIVF(LVar0, EVT_FLOAT(100.0))
        EVT_SETF(LVar2, EVT_FLOAT(2.0))
        EVT_SUBF(LVar2, LVar0)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_YELLOW_BALLOON, LVar2, LVar0, EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_RED_BALLOON, LVar2, LVar0, EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_BLUE_BALLOON, LVar2, LVar0, EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_YELLOW_BALLOON, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_RED_BALLOON, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_BLUE_BALLOON, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_PopBalloons) = {
    EVT_CALL(GetLastElement, LVar0)
    EVT_SET(LVar0, DAMAGE_TYPE_SPINY_SURGE)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_4000 | DAMAGE_TYPE_SPINY_SURGE)
        EVT_CALL(HideHealthBar, ACTOR_SELF)
        EVT_THREAD
            EVT_WAIT(20)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SKY_GUY_BALLOON_POP)
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_YELLOW_BALLOON, ANIM_SkyGuy_Anim2E)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_RED_BALLOON, ANIM_SkyGuy_Anim2D)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BLUE_BALLOON, ANIM_SkyGuy_Anim2F)
        EVT_WAIT(30)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Popped)
        EVT_WAIT(15)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim00)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_EMOTE_QUESTION)
        EVT_PLAY_EFFECT(EFFECT_EMOTE, EMOTE_QUESTION, 0, LVar0, LVar1, LVar2, 24, 0, 25, 0, 0)
        EVT_WAIT(25)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim06)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim06)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 120, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
        EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
        EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
        EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim12)
        EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0, 0)
        EVT_WAIT(40)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Ground_TakeTurn)))
        EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Ground_Idle)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Ground_HandleEvent)))
        EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
        EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_StretchBalloons))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, PRT_YELLOW_BALLOON)
                EVT_EXEC_WAIT(N(EVS_StretchBalloons))
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_FLYING)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, PRT_YELLOW_BALLOON)
                EVT_EXEC_WAIT(N(EVS_StretchBalloons))
                EVT_EXEC_WAIT(N(EVS_PopBalloons))
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_FLYING)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_SkyGuy_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_SkyGuy_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim0A)
            EVT_EXEC_WAIT(N(EVS_KillActor))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, PRT_YELLOW_BALLOON)
                EVT_EXEC_WAIT(N(EVS_StretchBalloons))
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_FLYING)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim01)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(func_8026E914, LVar0, LVar1)
            EVT_IF_GE(LVar1, PRT_YELLOW_BALLOON)
                EVT_EXEC_WAIT(N(EVS_StretchBalloons))
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_FLYING)
                EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim01)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim06)
            EVT_EXEC_WAIT(N(EVS_KillActor))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim03)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim01)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_YELLOW_BALLOON, ANIM_SkyGuy_Anim1F)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_RED_BALLOON, ANIM_SkyGuy_Anim1E)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BLUE_BALLOON, ANIM_SkyGuy_Anim20)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim03)
            EVT_SET_CONST(LVar2, ANIM_SkyGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_SkyGuy_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_ResetAnimations))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_DRAW)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim08)
    EVT_WAIT(12)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_STONE, ANIM_SkyGuy_Anim0B)
    EVT_WAIT(12)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_FIRE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_STONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 120)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.1))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_EXEC_WAIT(N(EVS_ResetAnimations))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim07)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 65)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_EXEC_WAIT(N(EVS_ResetAnimations))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SLINGSHOT, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 55)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(4.0))
            EVT_SUB(LVar0, 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_ResetAnimations))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(GroundAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STONE,     ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShyGuy_Red_Anim12,
    STATUS_KEY_POISON,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STOP,      ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShyGuy_Red_Anim13,
    STATUS_KEY_FEAR,      ANIM_ShyGuy_Red_Anim13,
    STATUS_END,
};

// unused
EvtScript N(EVS_Ground_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Ground_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Ground_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Ground_HandleEvent)))
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Ground_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_GROUND, -4, 14)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, 0, 0)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 13, 10, 13)
        EVT_ELSE
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_GROUND, 0, 24)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, -1, -10)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Ground_ReturnHome) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LVar0, PRT_GROUND)
    EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Ground_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(EVS_Ground_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim14)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Tackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HOP, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim05)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_EXEC_WAIT(N(EVS_Ground_ReturnHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Vault) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_TIMING_BAR_GO)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_SUB(LVar0, 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim0A)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
    EVT_THREAD
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim0A)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_VAULT, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LVar3, 0)
                EVT_LOOP(20)
                    EVT_SUB(LVar3, 30)
                    EVT_IF_LT(LVar3, 0)
                        EVT_ADD(LVar3, 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim07)
            EVT_WAIT(15)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim10)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DISAPPOINTED)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 50)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim11)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim13)
            EVT_END_IF
            EVT_WAIT(25)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_LABEL(2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Ground_TakeTurn) = {
    EVT_CALL(RandInt, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_Vault))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
