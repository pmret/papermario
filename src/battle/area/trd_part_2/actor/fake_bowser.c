#include "../area.h"
#include "sprite/npc/KoopaBros.h"
#include "mapfs/trd_bt00_shape.h"

#define NAMESPACE A(fake_bowser)

#include "boss.h"

extern EvtScript N(EVS_Init);
// first part of the battle
extern EvtScript N(EVS_FakeBowser_Idle);
extern EvtScript N(EVS_FakeBowser_HandleEvent);
extern EvtScript N(EVS_FakeBowser_HandlePhase);
extern EvtScript N(EVS_FakeBowser_TakeTurn);
// second part of the battle
extern EvtScript N(EVS_KoopaBros_Idle);
extern EvtScript N(EVS_KoopaBros_HandleEvent);
extern EvtScript N(EVS_KoopaBros_HandlePhase);
extern EvtScript N(EVS_KoopaBros_TakeTurn);

extern EvtScript A(green_ninja_koopa_HandleCommand);
extern EvtScript A(red_ninja_koopa_HandleCommand);
extern EvtScript A(black_ninja_koopa_HandleCommand);
extern EvtScript A(yellow_ninja_koopa_HandleCommand);

extern EvtScript N(EVS_SpawnDamageFX);
extern EvtScript N(EVS_KoopaBrosEnter);
extern EvtScript N(EVS_TryFormingTower);
extern EvtScript N(EVS_BroadcastToKoopaBros);

// only the first element is actually used
BSS s32 FakeBowserAnimState[31];

enum N(ActorPartIDs) {
    // the targetable bowser in part 1
    PRT_TARGET          = 1,
    // the targetable koopa bros tower in part 2
    PRT_TOWER           = 2,
    // non-targetable parts of the bowser robot use to animate breaking apart
    PRT_BODY            = 3,
    PRT_SHELL           = 4,
    PRT_HEAD            = 5,
    PRT_LEFT_ARM        = 6,
    PRT_TAIL            = 7,
    PRT_FRONT_WHEELS    = 8,
    PRT_BACK_WHEELS     = 9,
    PRT_FEET            = 10,
    PRT_RIGHT_ARM       = 11,
};

enum N(ActorParams) {
    DMG_STRIKE          = 1,
};

enum N(AnimState) {
    ANIM_BEGIN_IDLE     = 0,
    ANIM_DOING_IDLE     = 1,
    ANIM_BEGIN_HURT     = 2,
    ANIM_DOING_HURT     = 3,
    ANIM_BEGIN_MOVE     = 4,
    ANIM_DOING_MOVE     = 5,
    ANIM_BEGIN_STRIKE   = 6,
    ANIM_DOING_STRIKE   = 7,
    ANIM_BEGIN_DEATH    = 8,
    ANIM_DOING_DEATH    = 9,
    ANIM_BEGIN_BLOCKED  = 10,
    ANIM_DOING_BLOCKED  = 11,
};

#include "common/StartRumbleWithParams.inc.c"

#include "world/common/atomic/ApplyTint.inc.c"

s32 N(BowserDefense)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_BLAST,    1,
    ELEMENT_END,
};

s32 N(TowerDefense)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,            -1,
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

s32 N(PlaceholderAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaBros_Black_Idle,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, 15 },
        .targetOffset = { -46, 110 },
        .opacity = 255,
        .idleAnimations = N(PlaceholderAnims),
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_TOWER,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(TowerDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_HEAD,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BODY,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_SHELL,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_LEFT_ARM,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_TAIL,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_FRONT_WHEELS,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_BACK_WHEELS,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_FEET,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_RIGHT_ARM,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 10 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(BowserDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW,
    .type = ACTOR_TYPE_FAKE_BOWSER,
    .level = ACTOR_LEVEL_FAKE_BOWSER,
    .maxHP = 10,
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
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { -71, 125 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(BowserModels)[] = {
    MODEL_p1, // tail
    MODEL_u1, MODEL_u2, MODEL_u3, // near arm
    MODEL_k1, MODEL_k2, MODEL_k3, MODEL_k4, MODEL_k5, MODEL_k6, // head
    MODEL_s1, MODEL_s2, MODEL_s3, MODEL_s4, MODEL_s5, // shell
    MODEL_d1, MODEL_d2, MODEL_d3, // body
    MODEL_o171, MODEL_o172, MODEL_o183, // far arm
    MODEL_o118, MODEL_o120, MODEL_o165, // feet
    MODEL_km1, // front wheels
    MODEL_km2, // rear wheels
    0xFFFF,
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_FakeBowser_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_FakeBowser_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_FakeBowser_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_FakeBowser_HandlePhase)))
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_None)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, 0)
    EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
    EVT_CALL(SetActorPos, ACTOR_SELF, 96, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_TARGET_NO_DAMAGE, TRUE)
    EVT_RETURN
    EVT_END
};

// -------------------------------------------------------------------------
// FAKE BOWSER BATTLE

s32 N(IdleHeadAngles)[] = {
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(2.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(2.5),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(3.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(3.5),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(3.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(2.5),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(3.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(2.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.5),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    255,            255,            255
};


EvtScript N(EVS_AnimBowser_IdleHead) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_FBUF(EVT_PTR(N(IdleHeadAngles)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_IDLE)
            EVT_RETURN
        EVT_END_IF
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_FBUF(EVT_PTR(N(IdleHeadAngles)))
            EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(MoveHeadAngles)[] = {
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(2.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(5.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(8.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(8.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(8.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(8.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(7.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(5.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(4.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(1.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    255,            255,            255
};

EvtScript N(EVS_AnimBowser_MoveHead) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_FBUF(EVT_PTR(N(MoveHeadAngles)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_MOVE)
            EVT_RETURN
        EVT_END_IF
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_FBUF(EVT_PTR(N(MoveHeadAngles)))
            EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(HurtHeadAngles)[] = {
    EVT_FLOAT(0.0),  EVT_FLOAT(10.0), EVT_FLOAT(0.0),
    EVT_FLOAT(20.0), EVT_FLOAT(0.0),  EVT_FLOAT(5.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(0.0),  EVT_FLOAT(0.0),
    EVT_FLOAT(5.0),  EVT_FLOAT(20.0), EVT_FLOAT(0.0),
    EVT_FLOAT(10.0), EVT_FLOAT(0.0),  EVT_FLOAT(0.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(30.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(5.0),  EVT_FLOAT(2.0),
    EVT_FLOAT(30.0), EVT_FLOAT(0.0),  EVT_FLOAT(10.0),
    EVT_FLOAT(30.0), EVT_FLOAT(10.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(40.0), EVT_FLOAT(2.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(0.0),  EVT_FLOAT(5.0),
    EVT_FLOAT(5.0),  EVT_FLOAT(0.0),  EVT_FLOAT(8.0),
    EVT_FLOAT(10.0), EVT_FLOAT(0.0),  EVT_FLOAT(0.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(30.0), EVT_FLOAT(0.0),
    EVT_FLOAT(20.0), EVT_FLOAT(0.0),  EVT_FLOAT(5.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(0.0),  EVT_FLOAT(0.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(5.0),  EVT_FLOAT(0.0),
    EVT_FLOAT(10.0), EVT_FLOAT(0.0),  EVT_FLOAT(8.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(20.0), EVT_FLOAT(0.0),
    EVT_FLOAT(5.0),  EVT_FLOAT(0.0),  EVT_FLOAT(0.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(5.0),  EVT_FLOAT(5.0),
    EVT_FLOAT(30.0), EVT_FLOAT(0.0),  EVT_FLOAT(0.0),
    EVT_FLOAT(0.0),  EVT_FLOAT(0.0),  EVT_FLOAT(0.0),
    255,             255,             255
};

EvtScript N(EVS_AnimBowser_HurtHead) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_FBUF(EVT_PTR(N(HurtHeadAngles)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_HURT)
            EVT_RETURN
        EVT_END_IF
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_FBUF(EVT_PTR(N(HurtHeadAngles)))
            EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(RandInt, 100, LVarA)
        EVT_IF_LT(LVarA, 50)
            EVT_SETF(LVarA, EVT_FLOAT(0.0))
            EVT_SUBF(LVarA, LVar0)
            EVT_SETF(LVar0, LVarA)
            EVT_SETF(LVarA, EVT_FLOAT(0.0))
            EVT_SUBF(LVarA, LVar1)
            EVT_SETF(LVar1, LVarA)
        EVT_END_IF
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathMain) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(N(StartRumbleWithParams), 256, 30)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 20, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_HEAD, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_HEAD, 0, -60, 0)
    EVT_SET(LVar1, 60)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(60)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_HEAD, EVT_FLOAT(0.5))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2, 60, TRUE)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtModel, MODEL_k1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtModel, MODEL_u1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 150, 20)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtModel, MODEL_p1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtModel, MODEL_d1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 70, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtModel, MODEL_s1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 100, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtModel, MODEL_km1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    EVT_CALL(N(StartRumbleWithParams), 60, 20)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.6))
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_THREAD
        EVT_SET_GROUP(EVT_GROUP_00)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(N(StartRumbleWithParams), 30, 20)
    EVT_RETURN
    EVT_END
};

s32 N(IdleBodyOffsets)[] = {
    0,   0,   0,
    0,   1,   0,
    0,   2,   0,
    0,   3,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   3,   0,
    0,   3,   0,
    0,   2,   0,
    0,   1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(EVS_AnimBowser_IdleBody) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_BUF(EVT_PTR(N(IdleBodyOffsets)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_IDLE)
            EVT_RETURN
        EVT_END_IF
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_BUF(EVT_PTR(N(IdleBodyOffsets)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(MoveBodyOffsets)[] = {
    0,   2,   0,
    0,   7,   0,
    0,   9,   0,
    0,   9,   0,
    0,   7,   0,
    0,   5,   0,
    0,   1,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(EVS_AnimBowser_MoveBody) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_BUF(EVT_PTR(N(MoveBodyOffsets)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_MOVE)
            EVT_RETURN
        EVT_END_IF
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_BUF(EVT_PTR(N(MoveBodyOffsets)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(StrikeBodyOffsets)[] = {
    0,   0,   0,
    0,   1,   0,
    0,   2,   0,
    0,   3,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   4,   0,
    0,   3,   0,
    0,   3,   0,
    0,   2,   0,
    0,   1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(EVS_AnimBowser_StrikeBody) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_BUF(EVT_PTR(N(StrikeBodyOffsets)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(ANIM_DOING_STRIKE)
            EVT_CASE_EQ(ANIM_DOING_BLOCKED)
            EVT_CASE_DEFAULT
                EVT_RETURN
        EVT_END_SWITCH
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_BUF(EVT_PTR(N(StrikeBodyOffsets)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(HurtBodyOffsets)[] = {
    0,   1,   0,
    0,   4,   0,
    0,   16,  0,
    0,   8,   0,
    0,   20,  0,
    0,   8,   0,
    0,   12,  0,
    0,   6,   0,
    0,   0,   0,
    0,   6,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    0,   2,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(EVS_AnimBowser_HurtBody) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_BUF(EVT_PTR(N(HurtBodyOffsets)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_HURT)
            EVT_RETURN
        EVT_END_IF
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_BUF(EVT_PTR(N(HurtBodyOffsets)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathBody) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BODY, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_BODY, 0, -30, 0)
    EVT_SET(LVar1, 30)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, -20)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 150)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BODY, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2, 80, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathShell) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SHELL, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_SHELL, 0, -24, 0)
    EVT_SET(LVar1, 24)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(60)
            EVT_ADD(LVar0, 4)
            EVT_ADD(LVar1, -1)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 150)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_SHELL, EVT_FLOAT(0.5))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2, 60, TRUE)
    EVT_RETURN
    EVT_END
};

// opposite of IdleBodyOffsets
s32 N(IdleFeetOffsets)[] = {
    0,   0,   0,
    0,   0,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(EVS_AnimBowser_IdleFeet) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_BUF(EVT_PTR(N(IdleFeetOffsets)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_IDLE)
            EVT_RETURN
        EVT_END_IF
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_BUF(EVT_PTR(N(IdleFeetOffsets)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

// opposite of StrikeBodyOffsets
s32 N(StrikeFeetOffsets)[] = {
    0,   0,   0,
    0,   0,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -2,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,  -1,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    0,   0,   0,
    255, 255, 255,
};

EvtScript N(EVS_AnimBowser_StrikeFeet) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_BUF(EVT_PTR(N(StrikeFeetOffsets)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(ANIM_DOING_STRIKE)
            EVT_CASE_EQ(ANIM_DOING_BLOCKED)
            EVT_CASE_DEFAULT
                EVT_RETURN
        EVT_END_SWITCH
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_BUF(EVT_PTR(N(StrikeFeetOffsets)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

// opposite of MoveBodyOffsets
s32 N(MoveFeetOffsets)[] = {
    0,   0, 0,
    0,  -2, 0,
    0,  -4, 0,
    0,  -4, 0,
    0,  -4, 0,
    0,  -3, 0,
    0,  -1, 0,
    0,   0, 0,
    0,   0, 0,
    0,   0, 0,
    0,   0, 0,
    0,   0, 0,
    255, 255, 255,
};

EvtScript N(EVS_AnimBowser_MoveFeet) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_BUF(EVT_PTR(N(MoveFeetOffsets)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_MOVE)
            EVT_RETURN
        EVT_END_IF
        EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_BUF(EVT_PTR(N(MoveFeetOffsets)))
            EVT_BUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathFeet) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FEET, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, -10)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 50)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FEET, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2, 80, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(StrikeArmAngles)[] = {
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(5.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(10.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(15.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(20.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(25.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(30.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(35.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(40.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(48.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(48.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(48.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(48.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(48.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(48.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(45.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(35.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(25.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(15.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(5.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    255,            255,            255,
};

EvtScript N(EVS_AnimBowser_StrikeArm) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_FBUF(EVT_PTR(N(StrikeArmAngles)))
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_STRIKE)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_EQ(LVarF, 0)
            EVT_FBUF_READ3(LVar0, LVar1, LVar2)
            EVT_IF_EQ(LVar0, 255)
                EVT_SET(LVarF, 1)
                EVT_SET(LVar0, EVT_FLOAT(0.0))
                EVT_SET(LVar1, EVT_FLOAT(0.0))
                EVT_SET(LVar2, EVT_FLOAT(0.0))
            EVT_END_IF
        EVT_END_IF
        EVT_MULF(LVar2, EVT_FLOAT(-2.0))
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_BlockArm) = {
    EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar2, LVar3, LVar4)
    EVT_CALL(MakeLerp, LVar4, 0, 20, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, EVT_FLOAT(0.0), EVT_FLOAT(0.0), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathLeftArm) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_LEFT_ARM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_LEFT_ARM, 0, -60, 0)
    EVT_SET(LVar1, 60)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 8)
            EVT_ADD(LVar1, 10)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 0)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_LEFT_ARM, EVT_FLOAT(0.6))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2, 80, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathRightArm) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_RIGHT_ARM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_RIGHT_ARM, 0, -60, 0)
    EVT_SET(LVar1, 60)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 0)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_RIGHT_ARM, EVT_FLOAT(0.4))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2, 80, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(MoveWheelAngles)[] = {
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(20.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(40.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(60.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(80.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(100.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(120.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(140.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(160.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(180.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(200.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(220.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(240.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(260.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(280.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(300.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(320.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(340.0),
    EVT_FLOAT(0.0), EVT_FLOAT(0.0), EVT_FLOAT(0.0),
    255,            255,            255
};

EvtScript N(EVS_AnimBowser_MoveWheels) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_USE_FBUF(EVT_PTR(N(MoveWheelAngles)))
    EVT_LABEL(0)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_NE(LVar0, ANIM_DOING_MOVE)
            EVT_RETURN
        EVT_END_IF
        EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar0, 255)
            EVT_USE_FBUF(EVT_PTR(N(MoveWheelAngles)))
            EVT_FBUF_READ3(LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathFrontWheels) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FRONT_WHEELS, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 8)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 150)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_FRONT_WHEELS, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2, 80, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathBackWheels) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BACK_WHEELS, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 8)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 50)
    EVT_SET(LVar1, -200)
    EVT_SUB(LVar2, 100)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BACK_WHEELS, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2, 80, TRUE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimBowser_DeathTail) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TAIL, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(GetPartPos, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_TAIL, 0, -30, 0)
    EVT_SET(LVar1, 30)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(80)
            EVT_ADD(LVar0, 25)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SUB(LVar0, 0)
    EVT_SET(LVar1, -200)
    EVT_ADD(LVar2, 200)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_TAIL, EVT_FLOAT(0.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2, 80, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FakeBowser_Idle) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_SET(LVarA, 0)
    EVT_LABEL(0)
        // update animation state. ANIM_BEGIN states start new animations, ANIM_DOING states continue them.
        EVT_SET(LVar0, ArrayVar(0))
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(ANIM_BEGIN_IDLE)
                EVT_SET(ArrayVar(0), ANIM_DOING_IDLE)
                EVT_EXEC(N(EVS_AnimBowser_IdleBody))
                EVT_EXEC(N(EVS_AnimBowser_IdleFeet))
                EVT_EXEC(N(EVS_AnimBowser_IdleHead))
            EVT_CASE_EQ(ANIM_DOING_IDLE)
            EVT_CASE_EQ(ANIM_BEGIN_HURT)
                EVT_SET(ArrayVar(0), ANIM_DOING_HURT)
                EVT_EXEC(N(EVS_AnimBowser_HurtBody))
                EVT_EXEC(N(EVS_AnimBowser_HurtHead))
            EVT_CASE_EQ(ANIM_DOING_HURT)
            EVT_CASE_EQ(ANIM_BEGIN_MOVE)
                EVT_SET(ArrayVar(0), ANIM_DOING_MOVE)
                EVT_EXEC(N(EVS_AnimBowser_MoveBody))
                EVT_EXEC(N(EVS_AnimBowser_MoveFeet))
                EVT_EXEC(N(EVS_AnimBowser_MoveHead))
                EVT_EXEC(N(EVS_AnimBowser_MoveWheels))
            EVT_CASE_EQ(ANIM_DOING_MOVE)
            EVT_CASE_EQ(ANIM_BEGIN_STRIKE)
                EVT_SET(ArrayVar(0), ANIM_DOING_STRIKE)
                EVT_EXEC(N(EVS_AnimBowser_StrikeBody))
                EVT_EXEC(N(EVS_AnimBowser_StrikeFeet))
                EVT_EXEC(N(EVS_AnimBowser_StrikeArm))
            EVT_CASE_EQ(ANIM_DOING_STRIKE)
            EVT_CASE_EQ(ANIM_BEGIN_DEATH)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_BLAST)
                EVT_SET(ArrayVar(0), ANIM_DOING_DEATH)
                EVT_EXEC(N(EVS_AnimBowser_DeathMain))
                EVT_EXEC(N(EVS_AnimBowser_DeathBody))
                EVT_EXEC(N(EVS_AnimBowser_DeathShell))
                EVT_EXEC(N(EVS_AnimBowser_DeathLeftArm))
                EVT_EXEC(N(EVS_AnimBowser_DeathRightArm))
                EVT_EXEC(N(EVS_AnimBowser_DeathTail))
                EVT_EXEC(N(EVS_AnimBowser_DeathFrontWheels))
                EVT_EXEC(N(EVS_AnimBowser_DeathBackWheels))
                EVT_EXEC(N(EVS_AnimBowser_DeathFeet))
                EVT_EXEC(N(EVS_KoopaBrosEnter))
            EVT_CASE_EQ(ANIM_DOING_DEATH)
            EVT_CASE_EQ(ANIM_BEGIN_BLOCKED)
                EVT_SET(ArrayVar(0), ANIM_DOING_BLOCKED)
                EVT_EXEC(N(EVS_AnimBowser_StrikeBody))
                EVT_EXEC(N(EVS_AnimBowser_StrikeFeet))
                EVT_EXEC(N(EVS_AnimBowser_BlockArm))
            EVT_CASE_EQ(ANIM_DOING_BLOCKED)
        EVT_END_SWITCH
        // sync the positions of the models to corresponding actor parts
        EVT_CALL(GetPartPos, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_atama, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_atama, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_atama, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_atama, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_k1, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k2, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k3, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k4, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k5, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k6, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k7, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k8, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_k9, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(GetPartPos, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_dou, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_dou, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_dou, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_dou, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_d1, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_d2, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_d3, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(GetPartPos, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_koura, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_koura, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_koura, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_koura, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_s1, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_s2, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_s3, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_s4, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_s5, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(GetPartPos, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_left_arm, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_left_arm, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_left_arm, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_left_arm, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_u1, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_u2, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_u3, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(GetPartPos, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_shippo, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_shippo, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_shippo, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_shippo, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_p1, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_EQ(LVar0, ANIM_DOING_DEATH)
            EVT_CALL(GetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        EVT_ELSE
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
        EVT_END_IF
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_koma1, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_koma1, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_koma1, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_koma1, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_km1, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_SET(LVar0, ArrayVar(0))
        EVT_IF_EQ(LVar0, ANIM_DOING_DEATH)
            EVT_CALL(GetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        EVT_ELSE
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
        EVT_END_IF
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_koma2, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_koma2, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_koma2, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_koma2, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_km2, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(GetPartPos, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_right_arm, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_right_arm, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_right_arm, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_right_arm, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_o171, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_o172, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_o183, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(GetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        EVT_CALL(TranslateGroup, MODEL_ashi, LVar0, LVar1, LVar2)
        EVT_CALL(GetPartRotation, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        EVT_CALL(RotateGroup, MODEL_ashi, LVar0, 1, 0, 0)
        EVT_CALL(RotateGroup, MODEL_ashi, LVar1, 0, 1, 0)
        EVT_CALL(RotateGroup, MODEL_ashi, LVar2, 0, 0, 1)
        EVT_CALL(SetModelFlags, MODEL_o118, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_o120, MODEL_FLAG_IGNORE_FOG, TRUE)
        EVT_CALL(SetModelFlags, MODEL_o165, MODEL_FLAG_IGNORE_FOG, TRUE)
        // spawn puffs of smoke if health is low enough
        // written to have different effects at every quintile, but every case in the final
        // version just executes the same script
        EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_Dialogue_HaveATaste) // odd reuse/misuse of flag. always FALSE here.
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            EVT_MUL(LVar0, 100)
            EVT_DIV(LVar0, LVar1)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                EVT_CASE_LT(20)
                    EVT_IF_GT(LVarA, 20)
                        EVT_EXEC(N(EVS_SpawnDamageFX))
                        EVT_SET(LVarA, 0)
                    EVT_END_IF
                EVT_CASE_LT(40)
                    EVT_IF_GT(LVarA, 40)
                        EVT_EXEC(N(EVS_SpawnDamageFX))
                        EVT_SET(LVarA, 0)
                    EVT_END_IF
                EVT_CASE_LT(60)
                    EVT_IF_GT(LVarA, 60)
                        EVT_EXEC(N(EVS_SpawnDamageFX))
                        EVT_SET(LVarA, 0)
                    EVT_END_IF
                EVT_CASE_LT(80)
                    EVT_IF_GT(LVarA, 80)
                        EVT_EXEC(N(EVS_SpawnDamageFX))
                        EVT_SET(LVarA, 0)
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_ADD(LVarA, 1)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

// (in) LVarA : remaining health percent
EvtScript N(EVS_SpawnDamageFX) = {
    EVT_DIV(LVarA, 4)
    EVT_ADD(LVarA, 1)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -8)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, 98, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -12)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, 23, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -47)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, 70, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, 22, 0, 0, 0, 0)
    EVT_CALL(RandInt, LVarA, LVar3)
    EVT_ADD(LVar3, 1)
    EVT_WAIT(LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -19)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, 59, 33, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FakeBowser_HandleEvent) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_HURT)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_HURT)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_HURT)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(HideHealthBar, ACTOR_SELF)
            EVT_IF_EQ(LVar0, EVENT_BURN_DEATH)
                EVT_CALL(N(SetModelTintMode), APPLY_TINT_MODELS, EVT_PTR(N(BowserModels)), ENV_TINT_REMAP)
                EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 35, 35, 35, 0, 0, 0, 0, 0, 0)
            EVT_END_IF
            EVT_SET(ArrayVar(0), ANIM_BEGIN_HURT)
            EVT_WAIT(20)
            EVT_IF_EQ(LVar0, EVENT_BURN_DEATH)
                EVT_CALL(N(SetModelTintMode), APPLY_TINT_MODELS, EVT_PTR(N(BowserModels)), ENV_TINT_NONE)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                EVT_DIVF(LVar3, EVT_FLOAT(2.0))
                EVT_ADDF(LVar1, LVar3)
                EVT_ADDF(LVar2, EVT_FLOAT(5.0))
                EVT_DIVF(LVar3, EVT_FLOAT(10.0))
                EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
                EVT_WAIT(5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            EVT_END_IF
            EVT_CALL(ActorSpeak, MSG_CH1_0106, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_WAIT(30)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_DEATH)
            EVT_LABEL(20)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_WAIT(1)
                EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_KoopaBrosRevealed)
                    EVT_GOTO(20)
                EVT_END_IF
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(EVS_TryFormingTower))
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
            EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
            EVT_CALL(N(SetModelTintMode), APPLY_TINT_MODELS, EVT_PTR(N(BowserModels)), ENV_TINT_REMAP)
            EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 35, 35, 35, 0, 0, 0, 0, 0, 0)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_HURT)
            EVT_WAIT(20)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
            EVT_CALL(N(SetModelTintMode), APPLY_TINT_MODELS, EVT_PTR(N(BowserModels)), ENV_TINT_NONE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_DIVF(LVar3, EVT_FLOAT(2.0))
            EVT_ADDF(LVar1, LVar3)
            EVT_ADDF(LVar2, EVT_FLOAT(5.0))
            EVT_DIVF(LVar3, EVT_FLOAT(10.0))
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            EVT_WAIT(5)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FakeBowser_TakeTurn) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(N(StartRumbleWithParams), 256, 3)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(ArrayVar(0), ANIM_BEGIN_MOVE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_SWING)
        EVT_WAIT(22)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_STRIKE)
    EVT_END_THREAD
    EVT_SET(ArrayVar(0), ANIM_BEGIN_STRIKE)
    EVT_WAIT(24)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_THREAD
            EVT_END_IF
            EVT_WAIT(8)
            EVT_THREAD
                EVT_LOOP(4)
                    EVT_CALL(N(StartRumbleWithParams), 256, 5)
                    EVT_WAIT(8)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SET(ArrayVar(0), ANIM_BEGIN_MOVE)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, DMG_STRIKE, BS_FLAGS1_NICE_HIT)
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
        EVT_CALL(GetPlayerHP, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_SET(ArrayVar(0), ANIM_BEGIN_BLOCKED)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(18)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(N(StartRumbleWithParams), 256, 5)
            EVT_WAIT(8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(ArrayVar(0), ANIM_BEGIN_MOVE)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetPlayerHP, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 28, 75, -101)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 500)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(15)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(ActorSpeak, MSG_CH1_00FE, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(ActorSpeak, MSG_CH1_00FF, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 2)
        EVT_CASE_EQ(2)
            EVT_CALL(ActorSpeak, MSG_CH1_0100, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 85, 81, 0)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(SetBattleCamZoom, 249)
            EVT_CALL(MoveBattleCamOver, 10)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0101, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0102, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 3)
        EVT_CASE_EQ(3)
            EVT_CALL(ActorSpeak, MSG_CH1_0103, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, 85, 81, 0)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(SetBattleCamZoom, 249)
            EVT_CALL(MoveBattleCamOver, 10)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0104, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_CH1_0105, ACTOR_SELF, PRT_TARGET, -1, -1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 1)
    EVT_END_SWITCH
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FakeBowser_HandlePhase) = {
    EVT_USE_ARRAY(FakeBowserAnimState)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_Dialogue_BowserReveal)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                EVT_CALL(SetBattleCamTarget, -4, 46, -2)
                EVT_CALL(SetBattleCamYaw, 24)
                EVT_CALL(SetBattleCamOffsetZ, 30)
                EVT_CALL(SetBattleCamZoom, 461)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(30)
                EVT_CALL(ActorSpeak, MSG_CH1_00FD, ACTOR_SELF, PRT_TARGET, -1, -1)
                EVT_THREAD
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_SWING)
                    EVT_WAIT(22)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_STRIKE)
                EVT_END_THREAD
                EVT_SET(ArrayVar(0), ANIM_BEGIN_STRIKE)
                EVT_WAIT(30)
                EVT_SET(ArrayVar(0), ANIM_BEGIN_IDLE)
                EVT_CALL(EndActorSpeech, ACTOR_SELF, PRT_TARGET, -1, -1)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_Dialogue_BowserReveal)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_WAIT(20)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// -------------------------------------------------------------------------
// KOOPA BROS BATTLE

API_CALLABLE(N(PlayKoopaBrosSong)) {
    bgm_set_battle_song(SONG_KOOPA_BROS_BATTLE, 0);
    bgm_push_battle_song();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_KoopaBrosEnter) = {
    EVT_CALL(UseIdleAnimation, GREEN_ACTOR, FALSE)
    EVT_CALL(EnableIdleScript, GREEN_ACTOR, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorPos, GREEN_ACTOR, 100, 0, 10)
    EVT_CALL(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_Launched)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, GREEN_ACTOR, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, GREEN_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(SetGoalPos, GREEN_ACTOR, -300, 250, 0)
        EVT_CALL(JumpToGoal, GREEN_ACTOR, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, YELLOW_ACTOR, FALSE)
    EVT_CALL(EnableIdleScript, YELLOW_ACTOR, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorPos, YELLOW_ACTOR, 100, 0, 10)
    EVT_CALL(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_Launched)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, YELLOW_ACTOR, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, YELLOW_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(SetGoalPos, YELLOW_ACTOR, -200, 250, 0)
        EVT_CALL(JumpToGoal, YELLOW_ACTOR, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, BLACK_ACTOR, FALSE)
    EVT_CALL(EnableIdleScript, BLACK_ACTOR, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorPos, BLACK_ACTOR, 100, 0, 10)
    EVT_CALL(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_Launched)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, BLACK_ACTOR, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, BLACK_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(SetGoalPos, BLACK_ACTOR, 0, 250, 0)
        EVT_CALL(JumpToGoal, BLACK_ACTOR, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, RED_ACTOR, FALSE)
    EVT_CALL(EnableIdleScript, RED_ACTOR, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorPos, RED_ACTOR, 100, 0, 10)
    EVT_CALL(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_Launched)
    EVT_THREAD
        EVT_CALL(SetActorJumpGravity, RED_ACTOR, EVT_FLOAT(0.4))
        EVT_CALL(SetActorSounds, RED_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(SetGoalPos, RED_ACTOR, 150, 250, 0)
        EVT_CALL(JumpToGoal, RED_ACTOR, 50, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_WAIT(100)
    EVT_WAIT(100)
    EVT_CALL(EnableGroup, MODEL_atama, FALSE)
    EVT_CALL(EnableGroup, MODEL_left_arm, FALSE)
    EVT_CALL(EnableGroup, MODEL_shippo, FALSE)
    EVT_CALL(EnableGroup, MODEL_dou, FALSE)
    EVT_CALL(EnableGroup, MODEL_koura, FALSE)
    EVT_CALL(EnableGroup, MODEL_koma1, FALSE)
    EVT_CALL(EnableGroup, MODEL_koma2, FALSE)
    EVT_CALL(EnableGroup, MODEL_right_arm, FALSE)
    EVT_CALL(EnableGroup, MODEL_ashi, FALSE)
    EVT_THREAD
        EVT_WAIT(23)
        EVT_CALL(PlaySoundAtActor, GREEN_ACTOR, SOUND_FALL_QUICK)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, YELLOW_ACTOR, SOUND_FALL_QUICK)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, BLACK_ACTOR, SOUND_FALL_QUICK)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, RED_ACTOR, SOUND_FALL_QUICK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_Land)
        EVT_CALL(SetActorPos, GREEN_ACTOR, 20, 250, 0)
        EVT_CALL(SetGoalPos, GREEN_ACTOR, 20, 0, 0)
        EVT_CALL(SetActorJumpGravity, GREEN_ACTOR, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, GREEN_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(FallToGoal, GREEN_ACTOR, 30)
        EVT_CALL(PlaySoundAtActor, GREEN_ACTOR, SOUND_KOOPA_BROS_LAND)
        EVT_CALL(ResetActorSounds, GREEN_ACTOR, ACTOR_SOUND_JUMP)
        EVT_CALL(ForceHomePos, GREEN_ACTOR, 20, 0, 0)
        EVT_CALL(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_IdleCrouch)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_Land)
        EVT_CALL(SetActorPos, YELLOW_ACTOR, 60, 250, -5)
        EVT_CALL(SetGoalPos, YELLOW_ACTOR, 60, 0, -5)
        EVT_CALL(SetActorJumpGravity, YELLOW_ACTOR, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, YELLOW_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(FallToGoal, YELLOW_ACTOR, 30)
        EVT_CALL(PlaySoundAtActor, YELLOW_ACTOR, SOUND_KOOPA_BROS_LAND)
        EVT_CALL(ResetActorSounds, YELLOW_ACTOR, ACTOR_SOUND_JUMP)
        EVT_CALL(ForceHomePos, YELLOW_ACTOR, 60, 0, -5)
        EVT_CALL(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_Land)
        EVT_CALL(SetActorPos, BLACK_ACTOR, 100, 250, -10)
        EVT_CALL(SetGoalPos, BLACK_ACTOR, 100, 0, -10)
        EVT_CALL(SetActorJumpGravity, BLACK_ACTOR, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, BLACK_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(FallToGoal, BLACK_ACTOR, 30)
        EVT_CALL(PlaySoundAtActor, BLACK_ACTOR, SOUND_KOOPA_BROS_LAND)
        EVT_CALL(ResetActorSounds, BLACK_ACTOR, ACTOR_SOUND_JUMP)
        EVT_CALL(ForceHomePos, BLACK_ACTOR, 100, 0, -10)
        EVT_CALL(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_IdleCrouch)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_Land)
        EVT_CALL(SetActorPos, RED_ACTOR, 140, 250, -15)
        EVT_CALL(SetGoalPos, RED_ACTOR, 140, 0, -15)
        EVT_CALL(SetActorJumpGravity, RED_ACTOR, EVT_FLOAT(1.5))
        EVT_CALL(SetActorSounds, RED_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(FallToGoal, RED_ACTOR, 30)
        EVT_CALL(PlaySoundAtActor, RED_ACTOR, SOUND_KOOPA_BROS_LAND)
        EVT_CALL(ResetActorSounds, RED_ACTOR, ACTOR_SOUND_JUMP)
        EVT_CALL(ForceHomePos, RED_ACTOR, 140, 0, -15)
        EVT_CALL(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_IdleCrouch)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 70, 46, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 292)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(28)
    EVT_CALL(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_ThumbsUp)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, GREEN_ACTOR, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(PlaySoundAtActor, GREEN_ACTOR, SOUND_SMALL_LENS_FLARE)
    EVT_CALL(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_ThumbsUp)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, YELLOW_ACTOR, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(PlaySoundAtActor, YELLOW_ACTOR, SOUND_SMALL_LENS_FLARE)
    EVT_CALL(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_ThumbsUp)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, BLACK_ACTOR, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(PlaySoundAtActor, BLACK_ACTOR, SOUND_SMALL_LENS_FLARE)
    EVT_CALL(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_ThumbsUp)
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, RED_ACTOR, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 7)
    EVT_ADD(LVar1, 28)
    EVT_ADD(LVar2, 5)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(PlaySoundAtActor, RED_ACTOR, SOUND_SMALL_LENS_FLARE)
    EVT_WAIT(30)
    EVT_CALL(N(PlayKoopaBrosSong))
    EVT_CALL(ActorSpeak, MSG_CH1_0107, YELLOW_ACTOR, 1, -1, -1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_KoopaBros_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_KoopaBros_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_KoopaBros_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_KoopaBros_HandlePhase)))
    EVT_CALL(SetActorFlagBits, GREEN_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    EVT_CALL(SetPartFlagBits, GREEN_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(HPBarToHome, GREEN_ACTOR)
    EVT_CALL(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_Idle)
    EVT_CALL(SetActorFlagBits, YELLOW_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    EVT_CALL(SetPartFlagBits, YELLOW_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(HPBarToHome, YELLOW_ACTOR)
    EVT_CALL(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_Idle)
    EVT_CALL(SetActorFlagBits, BLACK_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    EVT_CALL(SetPartFlagBits, BLACK_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(HPBarToHome, BLACK_ACTOR)
    EVT_CALL(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_Idle)
    EVT_CALL(SetActorFlagBits, RED_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    EVT_CALL(SetPartFlagBits, RED_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(HPBarToHome, RED_ACTOR)
    EVT_CALL(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_Idle)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Toppled) // prevents first-turn tower attack
    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_KoopaBrosRevealed)
    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(PlayLandOnTowerFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor = get_actor(actorID);

    play_movement_dust_effects(2, actor->state.goalPos.x - 15.0f, actor->state.goalPos.y, actor->state.goalPos.z, actor->state.angle);
    return ApiStatus_DONE2;
}

// (in) Var0 : koopa bros actorID
// (in) Var1 : expected tower height
// (in) Var2 : tower index (height - 1, height - 2, ..., 0)
EvtScript N(EVS_BuildTowerWithKoopa) = {
    #define VAR_TOWER_HEIGHT LVarB
    #define VAR_CUR_TOWER_IDX LVarC
    EVT_IF_EQ(LVar2, TOWER_TOP)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_LeadKoopaID, LVar0)
    EVT_END_IF
    EVT_SET(LVarA, LVar0)
    EVT_SET(VAR_TOWER_HEIGHT, LVar1)
    EVT_SET(VAR_CUR_TOWER_IDX, LVar2)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(TOWER_TOP)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
            EVT_END_SWITCH
            EVT_CALL(SetActorYaw, LVarA, 0)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 22)
            EVT_ADD(LVar1, 19)
            EVT_WAIT(10)
            EVT_WAIT(30)
            EVT_SET(LVar0, VAR_TOWER_HEIGHT)
            EVT_SUB(LVar0, 1)
            EVT_MUL(LVar0, 16)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_CALL(SetBattleCamTarget, LVar2, LVar3, LVar4)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamOffsetZ, 50)
            EVT_CALL(SetBattleCamZoom, 400)
            EVT_CALL(MoveBattleCamOver, LVar0)
            EVT_WAIT(LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_SET(LVar4, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
            EVT_CALL(AddGoalPos, LVarA, 0, 0, 0)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Run)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Run)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Run)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Run)
            EVT_END_SWITCH
            EVT_CALL(GetGoalPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_IF_LT(LVar0, LVar3)
                EVT_CALL(SetActorYaw, LVarA, 0)
            EVT_ELSE
                EVT_CALL(SetActorYaw, LVarA, 180)
            EVT_END_IF
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_SET(LVar4, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
            EVT_SET(LVar0, VAR_TOWER_HEIGHT)
            EVT_SUB(LVar0, 1)
            EVT_MUL(LVar0, 18)
            EVT_SWITCH(VAR_TOWER_HEIGHT)
                EVT_CASE_EQ(4)
                    EVT_CALL(AddGoalPos, LVarA, 0, LVar0, -10)
                EVT_CASE_EQ(3)
                    EVT_CALL(AddGoalPos, LVarA, 0, LVar0, -7)
                EVT_CASE_EQ(2)
                    EVT_CALL(AddGoalPos, LVarA, 0, LVar0, -4)
            EVT_END_SWITCH
            EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
            EVT_END_SWITCH
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            EVT_CALL(N(PlayLandOnTowerFX), LVarA)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 15)
            EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(SetActorYaw, LVarA, 0)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
            EVT_END_SWITCH
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SMALL_LENS_FLARE)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 22)
            EVT_ADD(LVar1, 19)
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
            EVT_WAIT(20)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_Dialogue_HaveATaste)
                EVT_CALL(ActorSpeak, MSG_CH1_010A, LVarA, 1, -1, -1)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_Dialogue_HaveATaste)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EVT_END_SWITCH
            EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
            EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(HPBarToHome, LVarA)
            EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosA)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
        EVT_CASE_OR_EQ(TOWER_DOWN_1)
        EVT_CASE_OR_EQ(TOWER_DOWN_2)
        EVT_CASE_OR_EQ(TOWER_DOWN_3)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
            EVT_END_SWITCH
            EVT_WAIT(50)
            // handle (height - 1) position
            EVT_SET(LVar0, VAR_TOWER_HEIGHT)
            EVT_SUB(LVar0, TOWER_DOWN_1)
            EVT_IF_EQ(VAR_CUR_TOWER_IDX, LVar0)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
                EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                EVT_SET(LVar4, 15)
                EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                EVT_CALL(AddGoalPos, LVarA, 0, 0, 0)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Run)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Run)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Run)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Run)
                EVT_END_SWITCH
                EVT_CALL(RunToGoal, LVarA, 10, FALSE)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
                EVT_END_SWITCH
                EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
                EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
                EVT_CALL(HPBarToHome, LVarA)
                EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosB)
            EVT_END_IF
            // handle (height - 2) position
            EVT_SET(LVar0, VAR_TOWER_HEIGHT)
            EVT_SUB(LVar0, TOWER_DOWN_2)
            EVT_IF_EQ(VAR_CUR_TOWER_IDX, LVar0)
                EVT_WAIT(10)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
                EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                EVT_SET(LVar4, 15)
                EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                EVT_CALL(AddGoalPos, LVarA, 0, 18, -4)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
                EVT_END_SWITCH
                EVT_WAIT(5)
                EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
                EVT_THREAD
                    EVT_WAIT(10)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_EQ(GREEN_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                        EVT_CASE_EQ(YELLOW_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                        EVT_CASE_EQ(BLACK_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                        EVT_CASE_EQ(RED_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                    EVT_END_SWITCH
                EVT_END_THREAD
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
                EVT_END_SWITCH
                EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
                EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
                EVT_CALL(N(PlayLandOnTowerFX), LVarA)
                EVT_CALL(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
                EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SUB(LVar3, 15)
                EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
                EVT_END_SWITCH
                EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
                EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
                EVT_CALL(HPBarToHome, LVarA)
                EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosC)
            EVT_END_IF
            // handle (height - 3) position
            EVT_SET(LVar0, LVarB)
            EVT_SUB(LVar0, TOWER_DOWN_3)
            EVT_IF_EQ(VAR_CUR_TOWER_IDX, LVar0)
                EVT_WAIT(30)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
                EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                EVT_SET(LVar4, 15)
                EVT_CALL(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                EVT_CALL(AddGoalPos, LVarA, 0, 36, -7)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
                EVT_END_SWITCH
                EVT_WAIT(5)
                EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
                EVT_THREAD
                    EVT_WAIT(10)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_EQ(GREEN_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                        EVT_CASE_EQ(YELLOW_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                        EVT_CASE_EQ(BLACK_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                        EVT_CASE_EQ(RED_ACTOR)
                            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                    EVT_END_SWITCH
                EVT_END_THREAD
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
                EVT_END_SWITCH
                EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
                EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
                EVT_CALL(N(PlayLandOnTowerFX), LVarA)
                EVT_CALL(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
                EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SUB(LVar3, 15)
                EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
                EVT_END_SWITCH
                EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
                EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
                EVT_CALL(HPBarToHome, LVarA)
                EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosD)
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
    #undef VAR_TOWER_HEIGHT
    #undef VAR_CUR_TOWER_IDX
};

// (in) Var0 : koopa bros actorID
// (in) Var1 : expected tower height
// (in) Var2 : add index (0, 1, ...), or (-1) to mean "demoting"
// (in) Var3 : orphan count
EvtScript N(EVS_UpdateTowerWithKoopa) = {
    EVT_IF_EQ(LVar2, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_LeadKoopaID, LVar0)
    EVT_END_IF
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_SET(LVarD, LVar3)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(GREEN_ACTOR)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
        EVT_CASE_EQ(YELLOW_ACTOR)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
        EVT_CASE_EQ(BLACK_ACTOR)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
        EVT_CASE_EQ(RED_ACTOR)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
    EVT_END_SWITCH
    EVT_WAIT(15)
    EVT_SWITCH(LVarC)
        EVT_CASE_EQ(-1)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
            EVT_END_SWITCH
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(4)
                    EVT_SWITCH(LVarD)
                        EVT_CASE_EQ(2)
                            EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosC)
                        EVT_CASE_EQ(1)
                            EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosD)
                    EVT_END_SWITCH
                EVT_CASE_EQ(3)
                    EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosC)
            EVT_END_SWITCH
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            EVT_CALL(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            EVT_CALL(SetBattleCamTarget, LVar2, LVar3, LVar4)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamOffsetZ, 50)
            EVT_CALL(SetBattleCamZoom, 400)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_IF_EQ(LVarD, 2)
                EVT_WAIT(25)
            EVT_END_IF
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
            EVT_CALL(GetHomePos, LVar0, LVar1, LVar2, LVar3)
            EVT_SET(LVar3, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(4)
                    EVT_CALL(AddGoalPos, LVarA, 0, 54, -10)
                EVT_CASE_EQ(3)
                    EVT_CALL(AddGoalPos, LVarA, 0, 36, -7)
            EVT_END_SWITCH
            EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
            EVT_END_SWITCH
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            EVT_CALL(N(PlayLandOnTowerFX), LVarA)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 15)
            EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EVT_END_SWITCH
            EVT_WAIT(10)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
            EVT_END_SWITCH
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SMALL_LENS_FLARE)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 22)
            EVT_ADD(LVar1, 19)
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
            EVT_WAIT(30)
            EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
            EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(HPBarToHome, LVarA)
            EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosA)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_DoneTowerUpdate)
            EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        EVT_CASE_EQ(1)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
            EVT_END_SWITCH
            EVT_WAIT(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
            EVT_CALL(GetHomePos, LVar0, LVar1, LVar2, LVar3)
            EVT_SET(LVar3, 15)
            EVT_CALL(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
            EVT_CALL(AddGoalPos, LVarA, 0, 36, -7)
            EVT_CALL(AddGoalPos, LVarA, 15, 0, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_SWITCH(LVarA)
                    EVT_CASE_EQ(GREEN_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                    EVT_CASE_EQ(YELLOW_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                    EVT_CASE_EQ(BLACK_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                    EVT_CASE_EQ(RED_ACTOR)
                        EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                EVT_END_SWITCH
            EVT_END_THREAD
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
            EVT_END_SWITCH
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            EVT_CALL(N(PlayLandOnTowerFX), LVarA)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 15)
            EVT_CALL(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EVT_END_SWITCH
            EVT_WAIT(10)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(GREEN_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                EVT_CASE_EQ(YELLOW_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                EVT_CASE_EQ(BLACK_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                EVT_CASE_EQ(RED_ACTOR)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
            EVT_END_SWITCH
            EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
            EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(HPBarToHome, LVarA)
            EVT_CALL(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosD)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryFormingTower) = {
    // count the number of standing koopa bros
    #define VAR_STANDING_COUNT LVarA
    EVT_SET(VAR_STANDING_COUNT, 0)
    EVT_CALL(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(GetStatusFlags, LVar0, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_IF_EQ(VAR_STANDING_COUNT, 0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                EVT_END_IF
                EVT_ADD(VAR_STANDING_COUNT, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    // check special cases for standing koopa count
    EVT_SWITCH(VAR_STANDING_COUNT)
        EVT_CASE_EQ(0)
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_DoingSoloAttack)
            EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, VAR_STANDING_COUNT)
    EVT_SET(LFlag0, FALSE)
    // have each koopa join the tower from front to back
    // the index ranges from (height - 1) for the bottom koopa to 0 for the top
    #define VAR_CUR_KOOPA_IDX LVarB
    EVT_SET(VAR_CUR_KOOPA_IDX, VAR_STANDING_COUNT)
    EVT_SUB(VAR_CUR_KOOPA_IDX, 1)
    EVT_CALL(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(GetStatusFlags, LVar0, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET(LVar1, VAR_STANDING_COUNT)
                EVT_SET(LVar2, VAR_CUR_KOOPA_IDX)
                EVT_EXEC(N(EVS_BuildTowerWithKoopa))
                EVT_SUB(VAR_CUR_KOOPA_IDX, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(1)
        EVT_END_IF
    // hide the status bar until the tower is formed
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_LABEL(2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, AVAL_Boss_TowerState_Toppled)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(EnableBattleStatusBar, TRUE)
    // housekeeping for various actor states in the new tower configuration
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_POPUP, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_SET(LVar0, VAR_STANDING_COUNT)
    EVT_MUL(LVar0, 18)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
    EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_BROS)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
    EVT_CALL(GetActorPos, LVar1, LVar2, LVar3, LVar4)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_SET(LVarA, BOSS_CMD_STABLE)
    EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
    EVT_RETURN
    EVT_END
    #undef VAR_STANDING_COUNT
    #undef VAR_CUR_KOOPA_IDX 
};

// count the number of standing koopa bros
EvtScript N(EVS_TryJoiningTower) = {
    #define VAR_STANDING_COUNT LVarA
    EVT_SET(VAR_STANDING_COUNT, 0)
    EVT_CALL(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(GetStatusFlags, LVar0, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_ADD(VAR_STANDING_COUNT, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_IF_EQ(VAR_STANDING_COUNT, 0)
        // no orphaned koopa bros found
        EVT_RETURN
    EVT_END_IF
    // add orphan count to tower size
    EVT_SET(LVar3, LVarA)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVar0)
    EVT_ADD(LVarA, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVarA)
    // reset 'joined' flag
    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_DoneTowerUpdate)
    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    // demote the top koopa bros
    EVT_SET(LVar0, FIRST_KOOPA_ACTOR)
    EVT_LOOP(4)
        EVT_CALL(ActorExists, LVar0, LVar1)
        EVT_IF_EQ(LVar1, TRUE)
            EVT_CALL(GetActorVar, LVar0, AVAR_Koopa_State, LVar2)
            EVT_IF_EQ(LVar2, AVAL_Koopa_State_PosA)
                EVT_SET(LVar1, LVarA)
                EVT_SET(LVar2, -1)
                EVT_EXEC(N(EVS_UpdateTowerWithKoopa))
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // have each orphaned koopa join the tower from front to back
    EVT_SET(LVar2, 0)
    EVT_CALL(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetActorVar, LVar0, AVAR_Koopa_State, LVar8)
        EVT_IF_EQ(LVar8, AVAL_Koopa_State_Ready)
            EVT_SET(LVar1, LVarA)
            EVT_EXEC(N(EVS_UpdateTowerWithKoopa))
            EVT_ADD(LVar2, 1)
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(1)
        EVT_END_IF
    // hide the status bar until the tower is formed
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_LABEL(2)
        EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_DoneTowerUpdate)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_CALL(EnableBattleStatusBar, TRUE)
    // housekeeping for various actor states in the new tower configuration
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_POPUP, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_SET(LVar0, LVarA)
    EVT_MUL(LVar0, 18)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
    EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_BROS)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
    EVT_CALL(GetActorPos, LVar1, LVar2, LVar3, LVar4)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_SET(LVarA, BOSS_CMD_STABLE)
    EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
    EVT_RETURN
    EVT_END
    #undef VAR_STANDING_COUNT
};

EvtScript N(EVS_Broadcast_TowerUnstable) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    EVT_IF_EQ(LVar0, AVAL_Boss_TowerState_Unstable)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_TowerUnstable)
    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Unstable)
    EVT_SET(LVarA, BOSS_CMD_UNSTABLE)
    EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVarA)
    EVT_SET(LVar0, LVarA)
    EVT_MUL(LVar0, 18)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
    EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Broadcast_ToppleHit) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Toppled)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, EVENT_BURN_HIT)
        EVT_SET(LVarA, BOSS_CMD_TOPPLE_HIT)
    EVT_ELSE
        EVT_SET(LVarA, BOSS_CMD_TOPPLE_BURN_HIT)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_TowerUnstable)
    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_Dialogue_WereGoingOver)
    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_RETURN
    EVT_END
};

// (in) LVarA : event
EvtScript N(EVS_BroadcastToKoopaBros) = {
    EVT_CALL(ActorExists, GREEN_ACTOR, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(A(green_ninja_koopa_HandleCommand), LVar1)
    EVT_END_IF
    EVT_CALL(ActorExists, YELLOW_ACTOR, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(A(yellow_ninja_koopa_HandleCommand), LVar1)
    EVT_END_IF
    EVT_CALL(ActorExists, BLACK_ACTOR, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(A(black_ninja_koopa_HandleCommand), LVar1)
    EVT_END_IF
    EVT_CALL(ActorExists, RED_ACTOR, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_EXEC_GET_TID(A(red_ninja_koopa_HandleCommand), LVar1)
    EVT_END_IF
    // if any koopa bros are still alive, wait for their script to finish
    EVT_LABEL(0)
        EVT_IS_THREAD_RUNNING(LVar1, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

// adds a random jitter to KoopaBros actors' X position while the tower is unstable
EvtScript N(EVS_KoopaBros_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
        EVT_IF_NE(LVar0, AVAL_Boss_TowerState_Unstable)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        // get initial actor positions
        EVT_CALL(ActorExists, GREEN_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorPos, GREEN_ACTOR, LVarA, LVarE, LVarF)
        EVT_END_IF
        EVT_CALL(ActorExists, YELLOW_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorPos, YELLOW_ACTOR, LVarC, LVarE, LVarF)
        EVT_END_IF
        EVT_CALL(ActorExists, BLACK_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorPos, BLACK_ACTOR, LVarD, LVarE, LVarF)
        EVT_END_IF
        EVT_CALL(ActorExists, RED_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorPos, RED_ACTOR, LVarB, LVarE, LVarF)
        EVT_END_IF
        // while tower is unstable, add random X offsets to koopa bros
        EVT_LABEL(1)
            EVT_CALL(ActorExists, GREEN_ACTOR, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_CALL(GetActorVar, GREEN_ACTOR, AVAR_Koopa_State, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                        EVT_CALL(RandInt, 2, LVar0)
                        EVT_SET(LVar1, 1)
                        EVT_SUB(LVar0, LVar1)
                        EVT_ADD(LVar0, LVarA)
                        EVT_CALL(GetActorPos, GREEN_ACTOR, LVar1, LVar2, LVar3)
                        EVT_CALL(SetActorPos, GREEN_ACTOR, LVar0, LVar2, LVar3)
                    EVT_END_CASE_GROUP
                EVT_END_SWITCH
            EVT_END_IF
            EVT_CALL(ActorExists, YELLOW_ACTOR, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_CALL(GetActorVar, YELLOW_ACTOR, AVAR_Koopa_State, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                        EVT_CALL(RandInt, 2, LVar0)
                        EVT_SET(LVar1, 1)
                        EVT_SUB(LVar0, LVar1)
                        EVT_ADD(LVar0, LVarC)
                        EVT_CALL(GetActorPos, YELLOW_ACTOR, LVar1, LVar2, LVar3)
                        EVT_CALL(SetActorPos, YELLOW_ACTOR, LVar0, LVar2, LVar3)
                    EVT_END_CASE_GROUP
                EVT_END_SWITCH
            EVT_END_IF
            EVT_CALL(ActorExists, BLACK_ACTOR, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_CALL(GetActorVar, BLACK_ACTOR, AVAR_Koopa_State, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                        EVT_CALL(RandInt, 2, LVar0)
                        EVT_SET(LVar1, 1)
                        EVT_SUB(LVar0, LVar1)
                        EVT_ADD(LVar0, LVarD)
                        EVT_CALL(GetActorPos, BLACK_ACTOR, LVar1, LVar2, LVar3)
                        EVT_CALL(SetActorPos, BLACK_ACTOR, LVar0, LVar2, LVar3)
                    EVT_END_CASE_GROUP
                EVT_END_SWITCH
            EVT_END_IF
            EVT_CALL(ActorExists, RED_ACTOR, LVar0)
            EVT_IF_NE(LVar0, FALSE)
                EVT_CALL(GetActorVar, RED_ACTOR, AVAR_Koopa_State, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                    EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                        EVT_CALL(RandInt, 2, LVar0)
                        EVT_SET(LVar1, 1)
                        EVT_SUB(LVar0, LVar1)
                        EVT_ADD(LVar0, LVarB)
                        EVT_CALL(GetActorPos, RED_ACTOR, LVar1, LVar2, LVar3)
                        EVT_CALL(SetActorPos, RED_ACTOR, LVar0, LVar2, LVar3)
                    EVT_END_CASE_GROUP
                EVT_END_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_Boss_TowerState_Unstable)
                EVT_WAIT(2)
                EVT_GOTO(1)
            EVT_END_IF
        // once tower regains stability, reset X positions to initial values
        EVT_CALL(ActorExists, GREEN_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorVar, GREEN_ACTOR, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_CALL(GetActorPos, GREEN_ACTOR, LVar1, LVar2, LVar3)
                    EVT_CALL(SetActorPos, GREEN_ACTOR, LVarA, LVar2, LVar3)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_END_IF
        EVT_CALL(ActorExists, YELLOW_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorVar, YELLOW_ACTOR, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_CALL(GetActorPos, YELLOW_ACTOR, LVar1, LVar2, LVar3)
                    EVT_CALL(SetActorPos, YELLOW_ACTOR, LVarC, LVar2, LVar3)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_END_IF
        EVT_CALL(ActorExists, BLACK_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorVar, BLACK_ACTOR, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_CALL(GetActorPos, BLACK_ACTOR, LVar1, LVar2, LVar3)
                    EVT_CALL(SetActorPos, BLACK_ACTOR, LVarD, LVar2, LVar3)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_END_IF
        EVT_CALL(ActorExists, RED_ACTOR, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_CALL(GetActorVar, RED_ACTOR, AVAR_Koopa_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosA)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosD)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosC)
                EVT_CASE_OR_EQ(AVAL_Koopa_State_PosB)
                    EVT_CALL(GetActorPos, RED_ACTOR, LVar1, LVar2, LVar3)
                    EVT_CALL(SetActorPos, RED_ACTOR, LVarB, LVar2, LVar3)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            // set flags for player or partner hitting the koopa bros tower
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PartnerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_ELSE
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            EVT_SET(LVarA, BOSS_CMD_HIT)
            EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
            EVT_WAIT(30)
            // if the attack was explosive, set both flags
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_BLAST)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PartnerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            EVT_EXEC_WAIT(N(EVS_Broadcast_TowerUnstable))
        EVT_CASE_EQ(EVENT_HIT)
            // set flags for player or partner hitting the koopa bros tower
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PartnerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_ELSE
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            // if the attack was explosive, set both flags
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_BLAST)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PartnerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            // if this was the second hit, topple the tower
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_IF_FLAG(LVar0, AFLAG_Boss_PartnerHitTower)
                    EVT_EXEC_WAIT(N(EVS_Broadcast_ToppleHit))
                    EVT_WAIT(20)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            // this was the first hit
            EVT_SET(LVarA, BOSS_CMD_HIT)
            EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            EVT_IF_NE(LVar0, AVAL_Boss_TowerState_Unstable)
                EVT_EXEC_WAIT(N(EVS_Broadcast_TowerUnstable))
            EVT_END_IF
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AFLAG_Boss_TowerUnstable)
                EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                    EVT_CALL(ActorSpeak, MSG_CH1_0109, LVar0, 1, -1, -1)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            // set flags for player or partner hitting the koopa bros tower
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PartnerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_ELSE
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            // if the attack was explosive, set both flags
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_BLAST)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PartnerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            // if this was the second hit, topple the tower
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_IF_FLAG(LVar0, AFLAG_Boss_PartnerHitTower)
                    EVT_EXEC_WAIT(N(EVS_Broadcast_ToppleHit))
                    EVT_WAIT(20)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            // this was the first hit
            EVT_SET(LVarA, BOSS_CMD_BURN_HIT)
            EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            EVT_IF_NE(LVar0, AVAL_Boss_TowerState_Unstable)
                EVT_EXEC_WAIT(N(EVS_Broadcast_TowerUnstable))
            EVT_END_IF
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AFLAG_Boss_TowerUnstable)
                EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                    EVT_CALL(ActorSpeak, MSG_CH1_0109, LVar0, 1, -1, -1)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET(LVarA, BOSS_CMD_NO_DAMAGE_HIT)
            EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
        EVT_CASE_EQ(EVENT_IMMUNE)
            // set both flags if the tower is already unstable
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_Boss_TowerState_Unstable)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_PartnerHitTower)
                EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_END_IF
            // if this was the second hit, topple the tower
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AFLAG_Boss_PlayerHitTower)
                EVT_IF_FLAG(LVar0, AFLAG_Boss_PartnerHitTower)
                    EVT_EXEC_WAIT(N(EVS_Broadcast_ToppleHit))
                    EVT_WAIT(20)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            // this was the first hit
            EVT_SET(LVarA, BOSS_CMD_NO_DAMAGE_HIT)
            EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AFLAG_Boss_TowerUnstable)
                EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                    EVT_CALL(ActorSpeak, MSG_CH1_0109, LVar0, 1, -1, -1)
                    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    // reform stable tower if tipping
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Boss_TowerState_None)
        EVT_CASE_EQ(AVAL_Boss_TowerState_Stable)
        EVT_CASE_EQ(AVAL_Boss_TowerState_Unstable)
            EVT_WAIT(30)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
            EVT_SET(LVarA, BOSS_CMD_STABLE)
            EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_TowerUnstable)
            EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_Dialogue_WereGoingOver)
            EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVarA)
            EVT_SET(LVar0, LVarA)
            EVT_MUL(LVar0, 18)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
            EVT_CALL(SetActorSize, ACTOR_SELF, LVar0, 45)
        EVT_CASE_EQ(AVAL_Boss_TowerState_Toppled)
    EVT_END_SWITCH
    // find if any koopa bros are toppled
    EVT_SET(LVar0, FIRST_KOOPA_ACTOR)
    EVT_LOOP(4)
        EVT_CALL(ActorExists, LVar0, LVar1)
        EVT_IF_EQ(LVar1, TRUE)
            EVT_CALL(GetStatusFlags, LVar0, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
                EVT_IF_EQ(LVar1, AVAL_Koopa_State_Toppled)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    // zoom in to show the toppled koopa bros and have them try to get up
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, 90, 0, 0)
        EVT_CALL(SetBattleCamZoom, 350)
        EVT_CALL(SetBattleCamOffsetZ, 40)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
    EVT_END_IF
    EVT_SET(LVarA, BOSS_CMD_TRY_GET_UP)
    EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
    // try tower operations
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Boss_TowerState_Stable)
            // try adding any orphaned koopa bros to the tower
            EVT_EXEC_WAIT(N(EVS_TryJoiningTower))
        EVT_CASE_DEFAULT
            // try forming a new tower
            EVT_EXEC_WAIT(N(EVS_TryFormingTower))
    EVT_END_SWITCH
    // if only one koopa bro is alive, perform a solo attack
    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_IF_FLAG(LVar0, AFLAG_Boss_DoingSoloAttack)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_SET(LVarA, BOSS_CMD_SOLO_ATTACK)
        EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
        EVT_LABEL(123)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_IF_FLAG(LVar0, AFLAG_Boss_DoingSoloAttack)
                EVT_WAIT(1)
                EVT_GOTO(123)
            EVT_END_IF
        EVT_SET(LVarA, BOSS_CMD_GET_READY)
        EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
        EVT_WAIT(5)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, BOSS_CMD_GET_READY)
    EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
    EVT_WAIT(5)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    EVT_IF_EQ(LVar0, AVAL_Boss_TowerState_Toppled)
        EVT_RETURN
    EVT_END_IF
    // execute spin attack
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, AFLAG_Boss_Dialogue_SpinAttack)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_LeadKoopaID, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(GREEN_ACTOR)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Green_Talk, ANIM_KoopaBros_Green_Idle)
            EVT_CASE_EQ(YELLOW_ACTOR)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle)
            EVT_CASE_EQ(BLACK_ACTOR)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Black_Talk, ANIM_KoopaBros_Black_Idle)
            EVT_CASE_EQ(RED_ACTOR)
                EVT_CALL(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle)
        EVT_END_SWITCH
        EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        EVT_BITWISE_OR_CONST(LVar0, AFLAG_Boss_Dialogue_SpinAttack)
        EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EVT_END_IF
    EVT_SET(LVarA, BOSS_CMD_SPIN_ATTACK)
    EVT_EXEC_WAIT(N(EVS_BroadcastToKoopaBros))
    EVT_LABEL(10)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar0, AVAL_Boss_TowerState_None)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KoopaBros_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_PlayerHitTower)
            EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_CALL(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EVT_BITWISE_AND_CONST(LVar0, ~AFLAG_Boss_PartnerHitTower)
            EVT_CALL(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
