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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_FakeBowser_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_FakeBowser_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_FakeBowser_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_FakeBowser_HandlePhase)))
    UseArray(FakeBowserAnimState)
    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_None)
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, 0)
    Set(ArrayVar(0), ANIM_BEGIN_IDLE)
    Call(SetActorPos, ACTOR_SELF, 96, 0, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetPartTargetFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_TARGET_NO_DAMAGE, TRUE)
    Return
    End
};

// -------------------------------------------------------------------------
// FAKE BOWSER BATTLE

s32 N(IdleHeadAngles)[] = {
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(1.0),
    Float(0.0), Float(0.0), Float(2.0),
    Float(0.0), Float(0.0), Float(2.5),
    Float(0.0), Float(0.0), Float(3.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(3.5),
    Float(0.0), Float(0.0), Float(3.0),
    Float(0.0), Float(0.0), Float(2.5),
    Float(0.0), Float(0.0), Float(3.0),
    Float(0.0), Float(0.0), Float(2.0),
    Float(0.0), Float(0.0), Float(1.0),
    Float(0.0), Float(0.0), Float(0.5),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    255,            255,            255
};


EvtScript N(EVS_AnimBowser_IdleHead) = {
    UseArray(FakeBowserAnimState)
    UseFBuf(Ref(N(IdleHeadAngles)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_IDLE)
            Return
        EndIf
        FBufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseFBuf(Ref(N(IdleHeadAngles)))
            FBufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

s32 N(MoveHeadAngles)[] = {
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(2.0),
    Float(0.0), Float(0.0), Float(5.0),
    Float(0.0), Float(0.0), Float(8.0),
    Float(0.0), Float(0.0), Float(8.0),
    Float(0.0), Float(0.0), Float(8.0),
    Float(0.0), Float(0.0), Float(8.0),
    Float(0.0), Float(0.0), Float(7.0),
    Float(0.0), Float(0.0), Float(5.0),
    Float(0.0), Float(0.0), Float(4.0),
    Float(0.0), Float(0.0), Float(1.0),
    Float(0.0), Float(0.0), Float(0.0),
    255,            255,            255
};

EvtScript N(EVS_AnimBowser_MoveHead) = {
    UseArray(FakeBowserAnimState)
    UseFBuf(Ref(N(MoveHeadAngles)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_MOVE)
            Return
        EndIf
        FBufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseFBuf(Ref(N(MoveHeadAngles)))
            FBufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

s32 N(HurtHeadAngles)[] = {
    Float(0.0),  Float(10.0), Float(0.0),
    Float(20.0), Float(0.0),  Float(5.0),
    Float(0.0),  Float(0.0),  Float(0.0),
    Float(5.0),  Float(20.0), Float(0.0),
    Float(10.0), Float(0.0),  Float(0.0),
    Float(0.0),  Float(30.0), Float(0.0),
    Float(0.0),  Float(5.0),  Float(2.0),
    Float(30.0), Float(0.0),  Float(10.0),
    Float(30.0), Float(10.0), Float(0.0),
    Float(0.0),  Float(40.0), Float(2.0),
    Float(0.0),  Float(0.0),  Float(5.0),
    Float(5.0),  Float(0.0),  Float(8.0),
    Float(10.0), Float(0.0),  Float(0.0),
    Float(0.0),  Float(30.0), Float(0.0),
    Float(20.0), Float(0.0),  Float(5.0),
    Float(0.0),  Float(0.0),  Float(0.0),
    Float(0.0),  Float(5.0),  Float(0.0),
    Float(10.0), Float(0.0),  Float(8.0),
    Float(0.0),  Float(20.0), Float(0.0),
    Float(5.0),  Float(0.0),  Float(0.0),
    Float(0.0),  Float(5.0),  Float(5.0),
    Float(30.0), Float(0.0),  Float(0.0),
    Float(0.0),  Float(0.0),  Float(0.0),
    255,             255,             255
};

EvtScript N(EVS_AnimBowser_HurtHead) = {
    UseArray(FakeBowserAnimState)
    UseFBuf(Ref(N(HurtHeadAngles)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_HURT)
            Return
        EndIf
        FBufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseFBuf(Ref(N(HurtHeadAngles)))
            FBufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(RandInt, 100, LVarA)
        IfLt(LVarA, 50)
            SetF(LVarA, Float(0.0))
            SubF(LVarA, LVar0)
            SetF(LVar0, LVarA)
            SetF(LVarA, Float(0.0))
            SubF(LVarA, LVar1)
            SetF(LVar1, LVarA)
        EndIf
        Call(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathMain) = {
    UseArray(FakeBowserAnimState)
    Call(N(StartRumbleWithParams), 256, 30)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 20, Float(3.0))
    EndThread
    Call(SetPartFlagBits, ACTOR_SELF, PRT_HEAD, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_HEAD, 0, -60, 0)
    Set(LVar1, 60)
    Call(SetPartPos, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(60)
            Add(LVar0, 20)
            Call(SetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Sub(LVar0, 60)
    Set(LVar1, -200)
    Add(LVar2, 100)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_HEAD, Float(0.5))
    Call(JumpPartTo, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2, 60, TRUE)
    Wait(30)
    Call(PlaySoundAtModel, MODEL_k1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    EndThread
    Call(N(StartRumbleWithParams), 100, 20)
    Wait(20)
    Call(PlaySoundAtModel, MODEL_u1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.5))
    EndThread
    Call(N(StartRumbleWithParams), 150, 20)
    Wait(30)
    Call(PlaySoundAtModel, MODEL_p1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.0))
    EndThread
    Call(N(StartRumbleWithParams), 100, 20)
    Wait(30)
    Call(PlaySoundAtModel, MODEL_d1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.7))
    EndThread
    Call(N(StartRumbleWithParams), 70, 20)
    Wait(20)
    Call(PlaySoundAtModel, MODEL_s1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.0))
    EndThread
    Call(N(StartRumbleWithParams), 100, 20)
    Wait(20)
    Call(PlaySoundAtModel, MODEL_km1, SOUND_DISTANT_THUD, SOUND_SPACE_DEFAULT)
    Call(N(StartRumbleWithParams), 60, 20)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.6))
    EndThread
    Wait(20)
    Thread
        SetGroup(EVT_GROUP_00)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.3))
    EndThread
    Call(N(StartRumbleWithParams), 30, 20)
    Return
    End
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
    UseArray(FakeBowserAnimState)
    UseBuf(Ref(N(IdleBodyOffsets)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_IDLE)
            Return
        EndIf
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseBuf(Ref(N(IdleBodyOffsets)))
            BufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
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
    UseArray(FakeBowserAnimState)
    UseBuf(Ref(N(MoveBodyOffsets)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_MOVE)
            Return
        EndIf
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseBuf(Ref(N(MoveBodyOffsets)))
            BufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
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
    UseArray(FakeBowserAnimState)
    UseBuf(Ref(N(StrikeBodyOffsets)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        Switch(LVar0)
            CaseEq(ANIM_DOING_STRIKE)
            CaseEq(ANIM_DOING_BLOCKED)
            CaseDefault
                Return
        EndSwitch
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseBuf(Ref(N(StrikeBodyOffsets)))
            BufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
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
    UseArray(FakeBowserAnimState)
    UseBuf(Ref(N(HurtBodyOffsets)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_HURT)
            Return
        EndIf
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseBuf(Ref(N(HurtBodyOffsets)))
            BufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetActorDispOffset, ACTOR_SELF, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathBody) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_BODY, 0, -30, 0)
    Set(LVar1, 30)
    Call(SetPartPos, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(80)
            Add(LVar0, -20)
            Call(SetPartRotation, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Sub(LVar0, 150)
    Set(LVar1, -200)
    Sub(LVar2, 200)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_BODY, Float(0.3))
    Call(JumpPartTo, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2, 80, TRUE)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathShell) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SHELL, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_SHELL, 0, -24, 0)
    Set(LVar1, 24)
    Call(SetPartPos, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(60)
            Add(LVar0, 4)
            Add(LVar1, -1)
            Call(SetPartRotation, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Add(LVar0, 30)
    Set(LVar1, -200)
    Add(LVar2, 150)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_SHELL, Float(0.5))
    Call(JumpPartTo, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2, 60, TRUE)
    Return
    End
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
    UseArray(FakeBowserAnimState)
    UseBuf(Ref(N(IdleFeetOffsets)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_IDLE)
            Return
        EndIf
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseBuf(Ref(N(IdleFeetOffsets)))
            BufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
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
    UseArray(FakeBowserAnimState)
    UseBuf(Ref(N(StrikeFeetOffsets)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        Switch(LVar0)
            CaseEq(ANIM_DOING_STRIKE)
            CaseEq(ANIM_DOING_BLOCKED)
            CaseDefault
                Return
        EndSwitch
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseBuf(Ref(N(StrikeFeetOffsets)))
            BufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
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
    UseArray(FakeBowserAnimState)
    UseBuf(Ref(N(MoveFeetOffsets)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_MOVE)
            Return
        EndIf
        BufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseBuf(Ref(N(MoveFeetOffsets)))
            BufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathFeet) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FEET, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(80)
            Add(LVar0, -10)
            Call(SetPartRotation, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Sub(LVar0, 50)
    Set(LVar1, -200)
    Sub(LVar2, 200)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_FEET, Float(0.3))
    Call(JumpPartTo, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2, 80, TRUE)
    Return
    End
};

s32 N(StrikeArmAngles)[] = {
    Float(0.0), Float(0.0), Float(5.0),
    Float(0.0), Float(0.0), Float(10.0),
    Float(0.0), Float(0.0), Float(15.0),
    Float(0.0), Float(0.0), Float(20.0),
    Float(0.0), Float(0.0), Float(25.0),
    Float(0.0), Float(0.0), Float(30.0),
    Float(0.0), Float(0.0), Float(35.0),
    Float(0.0), Float(0.0), Float(40.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(48.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(48.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(48.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(48.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(48.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(48.0),
    Float(0.0), Float(0.0), Float(45.0),
    Float(0.0), Float(0.0), Float(35.0),
    Float(0.0), Float(0.0), Float(25.0),
    Float(0.0), Float(0.0), Float(15.0),
    Float(0.0), Float(0.0), Float(5.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    Float(0.0), Float(0.0), Float(0.0),
    255,            255,            255,
};

EvtScript N(EVS_AnimBowser_StrikeArm) = {
    UseArray(FakeBowserAnimState)
    UseFBuf(Ref(N(StrikeArmAngles)))
    Set(LVarF, 0)
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_STRIKE)
            Return
        EndIf
        IfEq(LVarF, 0)
            FBufRead3(LVar0, LVar1, LVar2)
            IfEq(LVar0, 255)
                Set(LVarF, 1)
                Set(LVar0, Float(0.0))
                Set(LVar1, Float(0.0))
                Set(LVar2, Float(0.0))
            EndIf
        EndIf
        MulF(LVar2, Float(-2.0))
        Call(SetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimBowser_BlockArm) = {
    Call(GetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar2, LVar3, LVar4)
    Call(MakeLerp, LVar4, 0, 20, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(SetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, Float(0.0), Float(0.0), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathLeftArm) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_LEFT_ARM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_LEFT_ARM, 0, -60, 0)
    Set(LVar1, 60)
    Call(SetPartPos, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(80)
            Add(LVar0, 8)
            Add(LVar1, 10)
            Call(SetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Sub(LVar0, 0)
    Set(LVar1, -200)
    Add(LVar2, 100)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_LEFT_ARM, Float(0.6))
    Call(JumpPartTo, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2, 80, TRUE)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathRightArm) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_RIGHT_ARM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_RIGHT_ARM, 0, -60, 0)
    Set(LVar1, 60)
    Call(SetPartPos, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
    Sub(LVar0, 0)
    Set(LVar1, -200)
    Sub(LVar2, 200)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_RIGHT_ARM, Float(0.4))
    Call(JumpPartTo, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2, 80, TRUE)
    Return
    End
};

s32 N(MoveWheelAngles)[] = {
    Float(0.0), Float(0.0), Float(20.0),
    Float(0.0), Float(0.0), Float(40.0),
    Float(0.0), Float(0.0), Float(60.0),
    Float(0.0), Float(0.0), Float(80.0),
    Float(0.0), Float(0.0), Float(100.0),
    Float(0.0), Float(0.0), Float(120.0),
    Float(0.0), Float(0.0), Float(140.0),
    Float(0.0), Float(0.0), Float(160.0),
    Float(0.0), Float(0.0), Float(180.0),
    Float(0.0), Float(0.0), Float(200.0),
    Float(0.0), Float(0.0), Float(220.0),
    Float(0.0), Float(0.0), Float(240.0),
    Float(0.0), Float(0.0), Float(260.0),
    Float(0.0), Float(0.0), Float(280.0),
    Float(0.0), Float(0.0), Float(300.0),
    Float(0.0), Float(0.0), Float(320.0),
    Float(0.0), Float(0.0), Float(340.0),
    Float(0.0), Float(0.0), Float(0.0),
    255,            255,            255
};

EvtScript N(EVS_AnimBowser_MoveWheels) = {
    UseArray(FakeBowserAnimState)
    UseFBuf(Ref(N(MoveWheelAngles)))
    Label(0)
        Set(LVar0, ArrayVar(0))
        IfNe(LVar0, ANIM_DOING_MOVE)
            Return
        EndIf
        FBufRead3(LVar0, LVar1, LVar2)
        IfEq(LVar0, 255)
            UseFBuf(Ref(N(MoveWheelAngles)))
            FBufRead3(LVar0, LVar1, LVar2)
        EndIf
        Call(SetPartRotation, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        Call(SetPartRotation, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathFrontWheels) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FRONT_WHEELS, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(80)
            Add(LVar0, 8)
            Call(SetPartRotation, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Sub(LVar0, 150)
    Set(LVar1, -200)
    Add(LVar2, 100)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_FRONT_WHEELS, Float(0.3))
    Call(JumpPartTo, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2, 80, TRUE)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathBackWheels) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BACK_WHEELS, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(80)
            Add(LVar0, 8)
            Call(SetPartRotation, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Sub(LVar0, 50)
    Set(LVar1, -200)
    Sub(LVar2, 100)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_BACK_WHEELS, Float(0.3))
    Call(JumpPartTo, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2, 80, TRUE)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_AnimBowser_DeathTail) = {
    UseArray(FakeBowserAnimState)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TAIL, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    Call(GetPartPos, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_TAIL, 0, -30, 0)
    Set(LVar1, 30)
    Call(SetPartPos, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LVar2, 0)
        Loop(80)
            Add(LVar0, 25)
            Add(LVar1, 1)
            Call(SetPartRotation, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Sub(LVar0, 0)
    Set(LVar1, -200)
    Add(LVar2, 200)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_TAIL, Float(0.3))
    Call(JumpPartTo, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2, 80, TRUE)
    Return
    End
};

EvtScript N(EVS_FakeBowser_Idle) = {
    UseArray(FakeBowserAnimState)
    Set(LVarA, 0)
    Label(0)
        // update animation state. ANIM_BEGIN states start new animations, ANIM_DOING states continue them.
        Set(LVar0, ArrayVar(0))
        Switch(LVar0)
            CaseEq(ANIM_BEGIN_IDLE)
                Set(ArrayVar(0), ANIM_DOING_IDLE)
                Exec(N(EVS_AnimBowser_IdleBody))
                Exec(N(EVS_AnimBowser_IdleFeet))
                Exec(N(EVS_AnimBowser_IdleHead))
            CaseEq(ANIM_DOING_IDLE)
            CaseEq(ANIM_BEGIN_HURT)
                Set(ArrayVar(0), ANIM_DOING_HURT)
                Exec(N(EVS_AnimBowser_HurtBody))
                Exec(N(EVS_AnimBowser_HurtHead))
            CaseEq(ANIM_DOING_HURT)
            CaseEq(ANIM_BEGIN_MOVE)
                Set(ArrayVar(0), ANIM_DOING_MOVE)
                Exec(N(EVS_AnimBowser_MoveBody))
                Exec(N(EVS_AnimBowser_MoveFeet))
                Exec(N(EVS_AnimBowser_MoveHead))
                Exec(N(EVS_AnimBowser_MoveWheels))
            CaseEq(ANIM_DOING_MOVE)
            CaseEq(ANIM_BEGIN_STRIKE)
                Set(ArrayVar(0), ANIM_DOING_STRIKE)
                Exec(N(EVS_AnimBowser_StrikeBody))
                Exec(N(EVS_AnimBowser_StrikeFeet))
                Exec(N(EVS_AnimBowser_StrikeArm))
            CaseEq(ANIM_DOING_STRIKE)
            CaseEq(ANIM_BEGIN_DEATH)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_BLAST)
                Set(ArrayVar(0), ANIM_DOING_DEATH)
                Exec(N(EVS_AnimBowser_DeathMain))
                Exec(N(EVS_AnimBowser_DeathBody))
                Exec(N(EVS_AnimBowser_DeathShell))
                Exec(N(EVS_AnimBowser_DeathLeftArm))
                Exec(N(EVS_AnimBowser_DeathRightArm))
                Exec(N(EVS_AnimBowser_DeathTail))
                Exec(N(EVS_AnimBowser_DeathFrontWheels))
                Exec(N(EVS_AnimBowser_DeathBackWheels))
                Exec(N(EVS_AnimBowser_DeathFeet))
                Exec(N(EVS_KoopaBrosEnter))
            CaseEq(ANIM_DOING_DEATH)
            CaseEq(ANIM_BEGIN_BLOCKED)
                Set(ArrayVar(0), ANIM_DOING_BLOCKED)
                Exec(N(EVS_AnimBowser_StrikeBody))
                Exec(N(EVS_AnimBowser_StrikeFeet))
                Exec(N(EVS_AnimBowser_BlockArm))
            CaseEq(ANIM_DOING_BLOCKED)
        EndSwitch
        // sync the positions of the models to corresponding actor parts
        Call(GetPartPos, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_atama, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_HEAD, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_atama, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_atama, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_atama, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_k1, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k2, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k3, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k4, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k5, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k6, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k7, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k8, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_k9, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(GetPartPos, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_dou, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_BODY, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_dou, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_dou, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_dou, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_d1, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_d2, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_d3, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(GetPartPos, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_koura, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_SHELL, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_koura, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_koura, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_koura, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_s1, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_s2, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_s3, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_s4, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_s5, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(GetPartPos, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_left_arm, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_LEFT_ARM, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_left_arm, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_left_arm, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_left_arm, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_u1, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_u2, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_u3, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(GetPartPos, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_shippo, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_TAIL, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_shippo, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_shippo, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_shippo, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_p1, MODEL_FLAG_IGNORE_FOG, TRUE)
        Set(LVar0, ArrayVar(0))
        IfEq(LVar0, ANIM_DOING_DEATH)
            Call(GetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        Else
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
        EndIf
        Call(SetPartPos, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_koma1, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_FRONT_WHEELS, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_koma1, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_koma1, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_koma1, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_km1, MODEL_FLAG_IGNORE_FOG, TRUE)
        Set(LVar0, ArrayVar(0))
        IfEq(LVar0, ANIM_DOING_DEATH)
            Call(GetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        Else
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
        EndIf
        Call(SetPartPos, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_koma2, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_BACK_WHEELS, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_koma2, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_koma2, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_koma2, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_km2, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(GetPartPos, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_right_arm, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_RIGHT_ARM, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_right_arm, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_right_arm, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_right_arm, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_o171, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_o172, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_o183, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(GetPartPos, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        Call(TranslateGroup, MODEL_ashi, LVar0, LVar1, LVar2)
        Call(GetPartRotation, ACTOR_SELF, PRT_FEET, LVar0, LVar1, LVar2)
        Call(RotateGroup, MODEL_ashi, LVar0, 1, 0, 0)
        Call(RotateGroup, MODEL_ashi, LVar1, 0, 1, 0)
        Call(RotateGroup, MODEL_ashi, LVar2, 0, 0, 1)
        Call(SetModelFlags, MODEL_o118, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_o120, MODEL_FLAG_IGNORE_FOG, TRUE)
        Call(SetModelFlags, MODEL_o165, MODEL_FLAG_IGNORE_FOG, TRUE)
        // spawn puffs of smoke if health is low enough
        // written to have different effects at every quintile, but every case in the final
        // version just executes the same script
        Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        IfNotFlag(LVar0, AFLAG_Boss_Dialogue_HaveATaste) // odd reuse/misuse of flag. always FALSE here.
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            Mul(LVar0, 100)
            Div(LVar0, LVar1)
            Switch(LVar0)
                CaseEq(0)
                CaseLt(20)
                    IfGt(LVarA, 20)
                        Exec(N(EVS_SpawnDamageFX))
                        Set(LVarA, 0)
                    EndIf
                CaseLt(40)
                    IfGt(LVarA, 40)
                        Exec(N(EVS_SpawnDamageFX))
                        Set(LVarA, 0)
                    EndIf
                CaseLt(60)
                    IfGt(LVarA, 60)
                        Exec(N(EVS_SpawnDamageFX))
                        Set(LVarA, 0)
                    EndIf
                CaseLt(80)
                    IfGt(LVarA, 80)
                        Exec(N(EVS_SpawnDamageFX))
                        Set(LVarA, 0)
                    EndIf
            EndSwitch
            Add(LVarA, 1)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

// (in) LVarA : remaining health percent
EvtScript N(EVS_SpawnDamageFX) = {
    Div(LVarA, 4)
    Add(LVarA, 1)
    Call(RandInt, LVarA, LVar3)
    Add(LVar3, 1)
    Wait(LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -8)
    PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, 98, 0, 0, 0, 0)
    Call(RandInt, LVarA, LVar3)
    Add(LVar3, 1)
    Wait(LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -12)
    PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, 23, 0, 0, 0, 0)
    Call(RandInt, LVarA, LVar3)
    Add(LVar3, 1)
    Wait(LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -47)
    PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, 70, 0, 0, 0, 0)
    Call(RandInt, LVarA, LVar3)
    Add(LVar3, 1)
    Wait(LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, 22, 0, 0, 0, 0)
    Call(RandInt, LVarA, LVar3)
    Add(LVar3, 1)
    Wait(LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, -19)
    PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, 59, 33, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_FakeBowser_HandleEvent) = {
    UseArray(FakeBowserAnimState)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            Set(ArrayVar(0), ANIM_BEGIN_HURT)
            Wait(20)
            Set(ArrayVar(0), ANIM_BEGIN_IDLE)
        CaseEq(EVENT_HIT)
            Set(ArrayVar(0), ANIM_BEGIN_HURT)
            Wait(20)
            Set(ArrayVar(0), ANIM_BEGIN_IDLE)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Set(ArrayVar(0), ANIM_BEGIN_HURT)
            Wait(20)
            Set(ArrayVar(0), ANIM_BEGIN_IDLE)
        EndCaseGroup
        CaseOrEq(EVENT_DEATH)
        CaseOrEq(EVENT_BURN_DEATH)
            Call(HideHealthBar, ACTOR_SELF)
            IfEq(LVar0, EVENT_BURN_DEATH)
                Call(N(SetModelTintMode), APPLY_TINT_MODELS, Ref(N(BowserModels)), ENV_TINT_REMAP)
                Call(N(SetModelTintParams), ENV_TINT_REMAP, 35, 35, 35, 0, 0, 0, 0, 0, 0)
            EndIf
            Set(ArrayVar(0), ANIM_BEGIN_HURT)
            Wait(20)
            IfEq(LVar0, EVENT_BURN_DEATH)
                Call(N(SetModelTintMode), APPLY_TINT_MODELS, Ref(N(BowserModels)), ENV_TINT_NONE)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
                DivF(LVar3, Float(2.0))
                AddF(LVar1, LVar3)
                AddF(LVar2, Float(5.0))
                DivF(LVar3, Float(10.0))
                PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
                Wait(5)
                PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            EndIf
            Call(ActorSpeak, MSG_CH1_0106, ACTOR_SELF, PRT_TARGET, -1, -1)
            Wait(30)
            Set(ArrayVar(0), ANIM_BEGIN_DEATH)
            Label(20)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                Wait(1)
                IfNotFlag(LVar0, AFLAG_Boss_KoopaBrosRevealed)
                    Goto(20)
                EndIf
            Wait(20)
            ExecWait(N(EVS_TryFormingTower))
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar0)
            Call(SetEnemyHP, ACTOR_SELF, LVar0)
            Return
        EndCaseGroup
        CaseOrEq(EVENT_BURN_CONTACT)
        CaseOrEq(EVENT_BURN_HIT)
            Call(N(SetModelTintMode), APPLY_TINT_MODELS, Ref(N(BowserModels)), ENV_TINT_REMAP)
            Call(N(SetModelTintParams), ENV_TINT_REMAP, 35, 35, 35, 0, 0, 0, 0, 0, 0)
            Set(ArrayVar(0), ANIM_BEGIN_HURT)
            Wait(20)
            Set(ArrayVar(0), ANIM_BEGIN_IDLE)
            Call(N(SetModelTintMode), APPLY_TINT_MODELS, Ref(N(BowserModels)), ENV_TINT_NONE)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            DivF(LVar3, Float(2.0))
            AddF(LVar1, LVar3)
            AddF(LVar2, Float(5.0))
            DivF(LVar3, Float(10.0))
            PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
            Wait(5)
            PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_FakeBowser_TakeTurn) = {
    UseArray(FakeBowserAnimState)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Thread
        Loop(4)
            Call(N(StartRumbleWithParams), 256, 3)
            Wait(5)
        EndLoop
    EndThread
    Set(ArrayVar(0), ANIM_BEGIN_MOVE)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Set(ArrayVar(0), ANIM_BEGIN_IDLE)
    Thread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_SWING)
        Wait(22)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_STRIKE)
    EndThread
    Set(ArrayVar(0), ANIM_BEGIN_STRIKE)
    Wait(24)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            IfEq(LVar0, HIT_RESULT_LUCKY)
                Thread
                    Wait(15)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndThread
            EndIf
            Wait(8)
            Thread
                Loop(4)
                    Call(N(StartRumbleWithParams), 256, 5)
                    Wait(8)
                EndLoop
            EndThread
            Set(ArrayVar(0), ANIM_BEGIN_MOVE)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Set(ArrayVar(0), ANIM_BEGIN_IDLE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, DMG_STRIKE, BS_FLAGS1_NICE_HIT)
    Call(GetBattleFlags, LVar0)
    IfFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
        Call(GetPlayerHP, LVar0)
        IfNe(LVar0, 0)
            Set(ArrayVar(0), ANIM_BEGIN_BLOCKED)
        EndIf
    EndIf
    Wait(18)
    Thread
        Loop(4)
            Call(N(StartRumbleWithParams), 256, 5)
            Wait(8)
        EndLoop
    EndThread
    Set(ArrayVar(0), ANIM_BEGIN_MOVE)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Set(ArrayVar(0), ANIM_BEGIN_IDLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(GetPlayerHP, LVar0)
    IfLe(LVar0, 0)
        Return
    EndIf
    Call(EnableBattleStatusBar, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, 28, 75, -101)
    Call(SetBattleCamOffsetY, 0)
    Call(SetBattleCamDist, 500)
    Call(MoveBattleCamOver, 20)
    Wait(15)
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(ActorSpeak, MSG_CH1_00FE, ACTOR_SELF, PRT_TARGET, -1, -1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 1)
        CaseEq(1)
            Call(ActorSpeak, MSG_CH1_00FF, ACTOR_SELF, PRT_TARGET, -1, -1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 2)
        CaseEq(2)
            Call(ActorSpeak, MSG_CH1_0100, ACTOR_SELF, PRT_TARGET, -1, -1)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamTarget, 85, 81, 0)
            Call(SetBattleCamOffsetY, 0)
            Call(SetBattleCamDist, 249)
            Call(MoveBattleCamOver, 10)
            Wait(10)
            Call(ActorSpeak, MSG_CH1_0101, ACTOR_SELF, PRT_TARGET, -1, -1)
            Wait(10)
            Call(ActorSpeak, MSG_CH1_0102, ACTOR_SELF, PRT_TARGET, -1, -1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 3)
        CaseEq(3)
            Call(ActorSpeak, MSG_CH1_0103, ACTOR_SELF, PRT_TARGET, -1, -1)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamTarget, 85, 81, 0)
            Call(SetBattleCamOffsetY, 0)
            Call(SetBattleCamDist, 249)
            Call(MoveBattleCamOver, 10)
            Wait(10)
            Call(ActorSpeak, MSG_CH1_0104, ACTOR_SELF, PRT_TARGET, -1, -1)
            Wait(10)
            Call(ActorSpeak, MSG_CH1_0105, ACTOR_SELF, PRT_TARGET, -1, -1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Boss_BowserTaunts, 1)
    EndSwitch
    Call(EnableBattleStatusBar, TRUE)
    Return
    End
};

EvtScript N(EVS_FakeBowser_HandlePhase) = {
    UseArray(FakeBowserAnimState)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfNotFlag(LVar0, AFLAG_Boss_Dialogue_BowserReveal)
                Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                Call(SetBattleCamTarget, -4, 46, -2)
                Call(SetBattleCamYaw, 24)
                Call(SetBattleCamOffsetY, 30)
                Call(SetBattleCamDist, 461)
                Call(MoveBattleCamOver, 30)
                Wait(30)
                Call(ActorSpeak, MSG_CH1_00FD, ACTOR_SELF, PRT_TARGET, -1, -1)
                Thread
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_SWING)
                    Wait(22)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FAKE_BOWSER_STRIKE)
                EndThread
                Set(ArrayVar(0), ANIM_BEGIN_STRIKE)
                Wait(30)
                Set(ArrayVar(0), ANIM_BEGIN_IDLE)
                Call(EndActorSpeech, ACTOR_SELF, PRT_TARGET, -1, -1)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_Dialogue_BowserReveal)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Wait(20)
            EndIf
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

// -------------------------------------------------------------------------
// KOOPA BROS BATTLE

API_CALLABLE(N(PlayKoopaBrosSong)) {
    bgm_set_battle_song(SONG_KOOPA_BROS_BATTLE, 0);
    bgm_push_battle_song();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_KoopaBrosEnter) = {
    Call(UseIdleAnimation, GREEN_ACTOR, FALSE)
    Call(EnableIdleScript, GREEN_ACTOR, IDLE_SCRIPT_DISABLE)
    Call(SetActorPos, GREEN_ACTOR, 100, 0, 10)
    Call(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_Launched)
    Thread
        Call(SetActorJumpGravity, GREEN_ACTOR, Float(0.4))
        Call(SetActorSounds, GREEN_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(SetGoalPos, GREEN_ACTOR, -300, 250, 0)
        Call(JumpToGoal, GREEN_ACTOR, 50, FALSE, TRUE, FALSE)
    EndThread
    Call(UseIdleAnimation, YELLOW_ACTOR, FALSE)
    Call(EnableIdleScript, YELLOW_ACTOR, IDLE_SCRIPT_DISABLE)
    Call(SetActorPos, YELLOW_ACTOR, 100, 0, 10)
    Call(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_Launched)
    Thread
        Call(SetActorJumpGravity, YELLOW_ACTOR, Float(0.4))
        Call(SetActorSounds, YELLOW_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(SetGoalPos, YELLOW_ACTOR, -200, 250, 0)
        Call(JumpToGoal, YELLOW_ACTOR, 50, FALSE, TRUE, FALSE)
    EndThread
    Call(UseIdleAnimation, BLACK_ACTOR, FALSE)
    Call(EnableIdleScript, BLACK_ACTOR, IDLE_SCRIPT_DISABLE)
    Call(SetActorPos, BLACK_ACTOR, 100, 0, 10)
    Call(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_Launched)
    Thread
        Call(SetActorJumpGravity, BLACK_ACTOR, Float(0.4))
        Call(SetActorSounds, BLACK_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(SetGoalPos, BLACK_ACTOR, 0, 250, 0)
        Call(JumpToGoal, BLACK_ACTOR, 50, FALSE, TRUE, FALSE)
    EndThread
    Call(UseIdleAnimation, RED_ACTOR, FALSE)
    Call(EnableIdleScript, RED_ACTOR, IDLE_SCRIPT_DISABLE)
    Call(SetActorPos, RED_ACTOR, 100, 0, 10)
    Call(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_Launched)
    Thread
        Call(SetActorJumpGravity, RED_ACTOR, Float(0.4))
        Call(SetActorSounds, RED_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(SetGoalPos, RED_ACTOR, 150, 250, 0)
        Call(JumpToGoal, RED_ACTOR, 50, FALSE, TRUE, FALSE)
    EndThread
    Wait(100)
    Wait(100)
    Call(EnableGroup, MODEL_atama, FALSE)
    Call(EnableGroup, MODEL_left_arm, FALSE)
    Call(EnableGroup, MODEL_shippo, FALSE)
    Call(EnableGroup, MODEL_dou, FALSE)
    Call(EnableGroup, MODEL_koura, FALSE)
    Call(EnableGroup, MODEL_koma1, FALSE)
    Call(EnableGroup, MODEL_koma2, FALSE)
    Call(EnableGroup, MODEL_right_arm, FALSE)
    Call(EnableGroup, MODEL_ashi, FALSE)
    Thread
        Wait(23)
        Call(PlaySoundAtActor, GREEN_ACTOR, SOUND_FALL_QUICK)
        Wait(5)
        Call(PlaySoundAtActor, YELLOW_ACTOR, SOUND_FALL_QUICK)
        Wait(5)
        Call(PlaySoundAtActor, BLACK_ACTOR, SOUND_FALL_QUICK)
        Wait(5)
        Call(PlaySoundAtActor, RED_ACTOR, SOUND_FALL_QUICK)
    EndThread
    Thread
        Call(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_Land)
        Call(SetActorPos, GREEN_ACTOR, 20, 250, 0)
        Call(SetGoalPos, GREEN_ACTOR, 20, 0, 0)
        Call(SetActorJumpGravity, GREEN_ACTOR, Float(1.5))
        Call(SetActorSounds, GREEN_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(FallToGoal, GREEN_ACTOR, 30)
        Call(PlaySoundAtActor, GREEN_ACTOR, SOUND_KOOPA_BROS_LAND)
        Call(ResetActorSounds, GREEN_ACTOR, ACTOR_SOUND_JUMP)
        Call(ForceHomePos, GREEN_ACTOR, 20, 0, 0)
        Call(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_IdleCrouch)
    EndThread
    Thread
        Wait(5)
        Call(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_Land)
        Call(SetActorPos, YELLOW_ACTOR, 60, 250, -5)
        Call(SetGoalPos, YELLOW_ACTOR, 60, 0, -5)
        Call(SetActorJumpGravity, YELLOW_ACTOR, Float(1.5))
        Call(SetActorSounds, YELLOW_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(FallToGoal, YELLOW_ACTOR, 30)
        Call(PlaySoundAtActor, YELLOW_ACTOR, SOUND_KOOPA_BROS_LAND)
        Call(ResetActorSounds, YELLOW_ACTOR, ACTOR_SOUND_JUMP)
        Call(ForceHomePos, YELLOW_ACTOR, 60, 0, -5)
        Call(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
    EndThread
    Thread
        Wait(10)
        Call(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_Land)
        Call(SetActorPos, BLACK_ACTOR, 100, 250, -10)
        Call(SetGoalPos, BLACK_ACTOR, 100, 0, -10)
        Call(SetActorJumpGravity, BLACK_ACTOR, Float(1.5))
        Call(SetActorSounds, BLACK_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(FallToGoal, BLACK_ACTOR, 30)
        Call(PlaySoundAtActor, BLACK_ACTOR, SOUND_KOOPA_BROS_LAND)
        Call(ResetActorSounds, BLACK_ACTOR, ACTOR_SOUND_JUMP)
        Call(ForceHomePos, BLACK_ACTOR, 100, 0, -10)
        Call(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_IdleCrouch)
    EndThread
    Thread
        Wait(15)
        Call(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_Land)
        Call(SetActorPos, RED_ACTOR, 140, 250, -15)
        Call(SetGoalPos, RED_ACTOR, 140, 0, -15)
        Call(SetActorJumpGravity, RED_ACTOR, Float(1.5))
        Call(SetActorSounds, RED_ACTOR, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(FallToGoal, RED_ACTOR, 30)
        Call(PlaySoundAtActor, RED_ACTOR, SOUND_KOOPA_BROS_LAND)
        Call(ResetActorSounds, RED_ACTOR, ACTOR_SOUND_JUMP)
        Call(ForceHomePos, RED_ACTOR, 140, 0, -15)
        Call(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_IdleCrouch)
    EndThread
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, 70, 46, 0)
    Call(SetBattleCamOffsetY, 0)
    Call(SetBattleCamDist, 292)
    Call(MoveBattleCamOver, 20)
    Wait(28)
    Call(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_ThumbsUp)
    Wait(5)
    Call(GetActorPos, GREEN_ACTOR, LVar0, LVar1, LVar2)
    Add(LVar0, 7)
    Add(LVar1, 28)
    Add(LVar2, 5)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(PlaySoundAtActor, GREEN_ACTOR, SOUND_SMALL_LENS_FLARE)
    Call(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_ThumbsUp)
    Wait(5)
    Call(GetActorPos, YELLOW_ACTOR, LVar0, LVar1, LVar2)
    Add(LVar0, 7)
    Add(LVar1, 28)
    Add(LVar2, 5)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(PlaySoundAtActor, YELLOW_ACTOR, SOUND_SMALL_LENS_FLARE)
    Call(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_ThumbsUp)
    Wait(5)
    Call(GetActorPos, BLACK_ACTOR, LVar0, LVar1, LVar2)
    Add(LVar0, 7)
    Add(LVar1, 28)
    Add(LVar2, 5)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(PlaySoundAtActor, BLACK_ACTOR, SOUND_SMALL_LENS_FLARE)
    Call(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_ThumbsUp)
    Wait(5)
    Call(GetActorPos, RED_ACTOR, LVar0, LVar1, LVar2)
    Add(LVar0, 7)
    Add(LVar1, 28)
    Add(LVar2, 5)
    PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(PlaySoundAtActor, RED_ACTOR, SOUND_SMALL_LENS_FLARE)
    Wait(30)
    Call(N(PlayKoopaBrosSong))
    Call(ActorSpeak, MSG_CH1_0107, YELLOW_ACTOR, 1, -1, -1)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_KoopaBros_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_KoopaBros_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_KoopaBros_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_KoopaBros_HandlePhase)))
    Call(SetActorFlagBits, GREEN_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    Call(SetPartFlagBits, GREEN_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Call(HPBarToHome, GREEN_ACTOR)
    Call(SetAnimation, GREEN_ACTOR, 1, ANIM_KoopaBros_Green_Idle)
    Call(SetActorFlagBits, YELLOW_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    Call(SetPartFlagBits, YELLOW_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Call(HPBarToHome, YELLOW_ACTOR)
    Call(SetAnimation, YELLOW_ACTOR, 1, ANIM_KoopaBros_Yellow_Idle)
    Call(SetActorFlagBits, BLACK_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    Call(SetPartFlagBits, BLACK_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Call(HPBarToHome, BLACK_ACTOR)
    Call(SetAnimation, BLACK_ACTOR, 1, ANIM_KoopaBros_Black_Idle)
    Call(SetActorFlagBits, RED_ACTOR, ACTOR_FLAG_NO_HEALTH_BAR, FALSE)
    Call(SetPartFlagBits, RED_ACTOR, 1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Call(HPBarToHome, RED_ACTOR)
    Call(SetAnimation, RED_ACTOR, 1, ANIM_KoopaBros_Red_Idle)
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Toppled) // prevents first-turn tower attack
    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    BitwiseOrConst(LVar0, AFLAG_Boss_KoopaBrosRevealed)
    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    Return
    End
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
    IfEq(LVar2, TOWER_TOP)
        Call(SetActorVar, ACTOR_SELF, AVAR_Boss_LeadKoopaID, LVar0)
    EndIf
    Set(LVarA, LVar0)
    Set(VAR_TOWER_HEIGHT, LVar1)
    Set(VAR_CUR_TOWER_IDX, LVar2)
    Call(UseIdleAnimation, LVarA, FALSE)
    Switch(LVar2)
        CaseEq(TOWER_TOP)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
            EndSwitch
            Call(SetActorYaw, LVarA, 0)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Sub(LVar0, 22)
            Add(LVar1, 19)
            Wait(10)
            Wait(30)
            Set(LVar0, VAR_TOWER_HEIGHT)
            Sub(LVar0, 1)
            Mul(LVar0, 16)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            Call(SetBattleCamTarget, LVar2, LVar3, LVar4)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamOffsetY, 50)
            Call(SetBattleCamDist, 400)
            Call(MoveBattleCamOver, LVar0)
            Wait(LVar0)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            Set(LVar4, 15)
            Call(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
            Call(AddGoalPos, LVarA, 0, 0, 0)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Run)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Run)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Run)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Run)
            EndSwitch
            Call(GetGoalPos, LVarA, LVar0, LVar1, LVar2)
            Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            IfLt(LVar0, LVar3)
                Call(SetActorYaw, LVarA, 0)
            Else
                Call(SetActorYaw, LVarA, 180)
            EndIf
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
            EndSwitch
            Wait(5)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            Set(LVar4, 15)
            Call(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
            Set(LVar0, VAR_TOWER_HEIGHT)
            Sub(LVar0, 1)
            Mul(LVar0, 18)
            Switch(VAR_TOWER_HEIGHT)
                CaseEq(4)
                    Call(AddGoalPos, LVarA, 0, LVar0, -10)
                CaseEq(3)
                    Call(AddGoalPos, LVarA, 0, LVar0, -7)
                CaseEq(2)
                    Call(AddGoalPos, LVarA, 0, LVar0, -4)
            EndSwitch
            Call(AddGoalPos, LVarA, 15, 0, 0)
            Thread
                Wait(10)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                EndSwitch
            EndThread
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
            EndSwitch
            Call(SetActorJumpGravity, LVarA, Float(1.6))
            Call(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            Call(N(PlayLandOnTowerFX), LVarA)
            Call(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
            Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            Sub(LVar3, 15)
            Call(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EndSwitch
            Wait(5)
            Call(SetActorYaw, LVarA, 0)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
            EndSwitch
            Call(PlaySoundAtActor, LVarA, SOUND_SMALL_LENS_FLARE)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Sub(LVar0, 22)
            Add(LVar1, 19)
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
            Wait(20)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfNotFlag(LVar0, AFLAG_Boss_Dialogue_HaveATaste)
                Call(ActorSpeak, MSG_CH1_010A, LVarA, 1, -1, -1)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_Dialogue_HaveATaste)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            Wait(10)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EndSwitch
            Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
            Call(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(HPBarToHome, LVarA)
            Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosA)
            Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
        CaseOrEq(TOWER_DOWN_1)
        CaseOrEq(TOWER_DOWN_2)
        CaseOrEq(TOWER_DOWN_3)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
            EndSwitch
            Wait(50)
            // handle (height - 1) position
            Set(LVar0, VAR_TOWER_HEIGHT)
            Sub(LVar0, TOWER_DOWN_1)
            IfEq(VAR_CUR_TOWER_IDX, LVar0)
                Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
                Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                Set(LVar4, 15)
                Call(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                Call(AddGoalPos, LVarA, 0, 0, 0)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Run)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Run)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Run)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Run)
                EndSwitch
                Call(RunToGoal, LVarA, 10, FALSE)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
                EndSwitch
                Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
                Call(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
                Call(HPBarToHome, LVarA)
                Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosB)
            EndIf
            // handle (height - 2) position
            Set(LVar0, VAR_TOWER_HEIGHT)
            Sub(LVar0, TOWER_DOWN_2)
            IfEq(VAR_CUR_TOWER_IDX, LVar0)
                Wait(10)
                Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
                Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                Set(LVar4, 15)
                Call(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                Call(AddGoalPos, LVarA, 0, 18, -4)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
                EndSwitch
                Wait(5)
                Call(AddGoalPos, LVarA, 15, 0, 0)
                Thread
                    Wait(10)
                    Switch(LVarA)
                        CaseEq(GREEN_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                        CaseEq(YELLOW_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                        CaseEq(BLACK_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                        CaseEq(RED_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                    EndSwitch
                EndThread
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
                EndSwitch
                Call(SetActorJumpGravity, LVarA, Float(1.6))
                Call(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
                Call(N(PlayLandOnTowerFX), LVarA)
                Call(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
                Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
                Sub(LVar3, 15)
                Call(SetActorPos, LVarA, LVar3, LVar4, LVar5)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
                EndSwitch
                Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
                Call(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
                Call(HPBarToHome, LVarA)
                Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosC)
            EndIf
            // handle (height - 3) position
            Set(LVar0, LVarB)
            Sub(LVar0, TOWER_DOWN_3)
            IfEq(VAR_CUR_TOWER_IDX, LVar0)
                Wait(30)
                Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
                Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
                Set(LVar4, 15)
                Call(SetGoalPos, LVarA, LVar2, LVar3, LVar4)
                Call(AddGoalPos, LVarA, 0, 36, -7)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
                EndSwitch
                Wait(5)
                Call(AddGoalPos, LVarA, 15, 0, 0)
                Thread
                    Wait(10)
                    Switch(LVarA)
                        CaseEq(GREEN_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                        CaseEq(YELLOW_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                        CaseEq(BLACK_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                        CaseEq(RED_ACTOR)
                            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                    EndSwitch
                EndThread
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
                EndSwitch
                Call(SetActorJumpGravity, LVarA, Float(1.6))
                Call(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
                Call(N(PlayLandOnTowerFX), LVarA)
                Call(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
                Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
                Sub(LVar3, 15)
                Call(SetActorPos, LVarA, LVar3, LVar4, LVar5)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
                EndSwitch
                Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
                Call(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
                Call(HPBarToHome, LVarA)
                Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosD)
            EndIf
        EndCaseGroup
    EndSwitch
    Return
    End
    #undef VAR_TOWER_HEIGHT
    #undef VAR_CUR_TOWER_IDX
};

// (in) Var0 : koopa bros actorID
// (in) Var1 : expected tower height
// (in) Var2 : add index (0, 1, ...), or (-1) to mean "demoting"
// (in) Var3 : orphan count
EvtScript N(EVS_UpdateTowerWithKoopa) = {
    IfEq(LVar2, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_Boss_LeadKoopaID, LVar0)
    EndIf
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Set(LVarD, LVar3)
    Call(UseIdleAnimation, LVarA, FALSE)
    Switch(LVarA)
        CaseEq(GREEN_ACTOR)
            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
        CaseEq(YELLOW_ACTOR)
            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
        CaseEq(BLACK_ACTOR)
            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
        CaseEq(RED_ACTOR)
            Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
    EndSwitch
    Wait(15)
    Switch(LVarC)
        CaseEq(-1)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
            EndSwitch
            Switch(LVarB)
                CaseEq(4)
                    Switch(LVarD)
                        CaseEq(2)
                            Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosC)
                        CaseEq(1)
                            Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosD)
                    EndSwitch
                CaseEq(3)
                    Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosC)
            EndSwitch
        CaseEq(0)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
            Call(GetHomePos, LVar1, LVar2, LVar3, LVar4)
            Call(SetBattleCamTarget, LVar2, LVar3, LVar4)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamOffsetY, 50)
            Call(SetBattleCamDist, 400)
            Call(MoveBattleCamOver, 30)
            IfEq(LVarD, 2)
                Wait(25)
            EndIf
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
            EndSwitch
            Wait(5)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
            Call(GetHomePos, LVar0, LVar1, LVar2, LVar3)
            Set(LVar3, 15)
            Call(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
            Switch(LVarB)
                CaseEq(4)
                    Call(AddGoalPos, LVarA, 0, 54, -10)
                CaseEq(3)
                    Call(AddGoalPos, LVarA, 0, 36, -7)
            EndSwitch
            Call(AddGoalPos, LVarA, 15, 0, 0)
            Thread
                Wait(10)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                EndSwitch
            EndThread
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
            EndSwitch
            Call(SetActorJumpGravity, LVarA, Float(1.6))
            Call(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            Call(N(PlayLandOnTowerFX), LVarA)
            Call(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
            Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            Sub(LVar3, 15)
            Call(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EndSwitch
            Wait(10)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_PointForward)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_PointForward)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_PointForward)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_PointForward)
            EndSwitch
            Call(PlaySoundAtActor, LVarA, SOUND_SMALL_LENS_FLARE)
            Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            Sub(LVar0, 22)
            Add(LVar1, 19)
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
            Wait(30)
            Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
            Call(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(HPBarToHome, LVarA)
            Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosA)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            BitwiseOrConst(LVar0, AFLAG_Boss_DoneTowerUpdate)
            Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        CaseEq(1)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Leap)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Leap)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Leap)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Leap)
            EndSwitch
            Wait(5)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
            Call(GetHomePos, LVar0, LVar1, LVar2, LVar3)
            Set(LVar3, 15)
            Call(SetGoalPos, LVarA, LVar1, LVar2, LVar3)
            Call(AddGoalPos, LVarA, 0, 36, -7)
            Call(AddGoalPos, LVarA, 15, 0, 0)
            Thread
                Wait(10)
                Switch(LVarA)
                    CaseEq(GREEN_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Land)
                    CaseEq(YELLOW_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Land)
                    CaseEq(BLACK_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Land)
                    CaseEq(RED_ACTOR)
                        Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Land)
                EndSwitch
            EndThread
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Midair)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Midair)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Midair)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Midair)
            EndSwitch
            Call(SetActorJumpGravity, LVarA, Float(1.6))
            Call(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
            Call(N(PlayLandOnTowerFX), LVarA)
            Call(PlaySoundAtActor, LVarA, SOUND_KOOPA_BROS_LAND)
            Call(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            Sub(LVar3, 15)
            Call(SetActorPos, LVarA, LVar3, LVar4, LVar5)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_Idle)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_Idle)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_Idle)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_Idle)
            EndSwitch
            Wait(10)
            Switch(LVarA)
                CaseEq(GREEN_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Green_IdleCrouch)
                CaseEq(YELLOW_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Yellow_IdleCrouch)
                CaseEq(BLACK_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Black_IdleCrouch)
                CaseEq(RED_ACTOR)
                    Call(SetAnimation, LVarA, 1, ANIM_KoopaBros_Red_IdleCrouch)
            EndSwitch
            Call(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_HEALTH_BAR, TRUE)
            Call(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(HPBarToHome, LVarA)
            Call(SetActorVar, LVarA, AVAR_Koopa_State, AVAL_Koopa_State_PosD)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TryFormingTower) = {
    // count the number of standing koopa bros
    #define VAR_STANDING_COUNT LVarA
    Set(VAR_STANDING_COUNT, 0)
    Call(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
        IfEq(LVar1, 0)
            Call(GetStatusFlags, LVar0, LVar1)
            IfEq(LVar1, 0)
                IfEq(VAR_STANDING_COUNT, 0)
                    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                EndIf
                Add(VAR_STANDING_COUNT, 1)
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    // check special cases for standing koopa count
    Switch(VAR_STANDING_COUNT)
        CaseEq(0)
            Return
        CaseEq(1)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            BitwiseOrConst(LVar0, AFLAG_Boss_DoingSoloAttack)
            Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            Return
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, VAR_STANDING_COUNT)
    Set(LFlag0, FALSE)
    // have each koopa join the tower from front to back
    // the index ranges from (height - 1) for the bottom koopa to 0 for the top
    #define VAR_CUR_KOOPA_IDX LVarB
    Set(VAR_CUR_KOOPA_IDX, VAR_STANDING_COUNT)
    Sub(VAR_CUR_KOOPA_IDX, 1)
    Call(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
        IfEq(LVar1, 0)
            Call(GetStatusFlags, LVar0, LVar1)
            IfEq(LVar1, 0)
                Set(LVar1, VAR_STANDING_COUNT)
                Set(LVar2, VAR_CUR_KOOPA_IDX)
                Exec(N(EVS_BuildTowerWithKoopa))
                Sub(VAR_CUR_KOOPA_IDX, 1)
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    // hide the status bar until the tower is formed
    Call(EnableBattleStatusBar, FALSE)
    Label(2)
        Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
        Wait(1)
        IfEq(LVar0, AVAL_Boss_TowerState_Toppled)
            Goto(2)
        EndIf
    Call(EnableBattleStatusBar, TRUE)
    // housekeeping for various actor states in the new tower configuration
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_POPUP, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Set(LVar0, VAR_STANDING_COUNT)
    Mul(LVar0, 18)
    Add(LVar0, 20)
    Call(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
    Call(SetActorSize, ACTOR_SELF, LVar0, 45)
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_BROS)
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
    Call(GetActorPos, LVar1, LVar2, LVar3, LVar4)
    Call(SetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    Set(LVarA, BOSS_CMD_STABLE)
    ExecWait(N(EVS_BroadcastToKoopaBros))
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
    Return
    End
    #undef VAR_STANDING_COUNT
    #undef VAR_CUR_KOOPA_IDX
};

// count the number of standing koopa bros
EvtScript N(EVS_TryJoiningTower) = {
    #define VAR_STANDING_COUNT LVarA
    Set(VAR_STANDING_COUNT, 0)
    Call(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
        IfEq(LVar1, 0)
            Call(GetStatusFlags, LVar0, LVar1)
            IfEq(LVar1, 0)
                Add(VAR_STANDING_COUNT, 1)
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    IfEq(VAR_STANDING_COUNT, 0)
        // no orphaned koopa bros found
        Return
    EndIf
    // add orphan count to tower size
    Set(LVar3, LVarA)
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVar0)
    Add(LVarA, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVarA)
    // reset 'joined' flag
    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AFLAG_Boss_DoneTowerUpdate)
    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    // demote the top koopa bros
    Set(LVar0, FIRST_KOOPA_ACTOR)
    Loop(4)
        Call(ActorExists, LVar0, LVar1)
        IfEq(LVar1, TRUE)
            Call(GetActorVar, LVar0, AVAR_Koopa_State, LVar2)
            IfEq(LVar2, AVAL_Koopa_State_PosA)
                Set(LVar1, LVarA)
                Set(LVar2, -1)
                Exec(N(EVS_UpdateTowerWithKoopa))
                BreakLoop
            EndIf
        EndIf
        Add(LVar0, 1)
    EndLoop
    // have each orphaned koopa join the tower from front to back
    Set(LVar2, 0)
    Call(CreateCurrentPosTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorVar, LVar0, AVAR_Koopa_State, LVar8)
        IfEq(LVar8, AVAL_Koopa_State_Ready)
            Set(LVar1, LVarA)
            Exec(N(EVS_UpdateTowerWithKoopa))
            Add(LVar2, 1)
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    // hide the status bar until the tower is formed
    Call(EnableBattleStatusBar, FALSE)
    Label(2)
        Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        IfNotFlag(LVar0, AFLAG_Boss_DoneTowerUpdate)
            Wait(1)
            Goto(2)
        EndIf
    Call(EnableBattleStatusBar, TRUE)
    // housekeeping for various actor states in the new tower configuration
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_POPUP, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Set(LVar0, LVarA)
    Mul(LVar0, 18)
    Add(LVar0, 20)
    Call(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
    Call(SetActorSize, ACTOR_SELF, LVar0, 45)
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_BROS)
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar1)
    Call(GetActorPos, LVar1, LVar2, LVar3, LVar4)
    Call(SetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    Set(LVarA, BOSS_CMD_STABLE)
    ExecWait(N(EVS_BroadcastToKoopaBros))
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
    Return
    End
    #undef VAR_STANDING_COUNT
};

EvtScript N(EVS_Broadcast_TowerUnstable) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    IfEq(LVar0, AVAL_Boss_TowerState_Unstable)
        Return
    EndIf
    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    BitwiseOrConst(LVar0, AFLAG_Boss_TowerUnstable)
    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Unstable)
    Set(LVarA, BOSS_CMD_UNSTABLE)
    ExecWait(N(EVS_BroadcastToKoopaBros))
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVarA)
    Set(LVar0, LVarA)
    Mul(LVar0, 18)
    Add(LVar0, 5)
    Call(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
    Call(SetActorSize, ACTOR_SELF, LVar0, 45)
    Return
    End
};

EvtScript N(EVS_Broadcast_ToppleHit) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Toppled)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    IfNe(LVar0, EVENT_BURN_HIT)
        Set(LVarA, BOSS_CMD_TOPPLE_HIT)
    Else
        Set(LVarA, BOSS_CMD_TOPPLE_BURN_HIT)
    EndIf
    ExecWait(N(EVS_BroadcastToKoopaBros))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TARGET, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_TOWER, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AFLAG_Boss_TowerUnstable)
    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    BitwiseAndConst(LVar0, ~AFLAG_Boss_Dialogue_WereGoingOver)
    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    Return
    End
};

// (in) LVarA : event
EvtScript N(EVS_BroadcastToKoopaBros) = {
    Call(ActorExists, GREEN_ACTOR, LVar0)
    IfEq(LVar0, TRUE)
        ExecGetTID(A(green_ninja_koopa_HandleCommand), LVar1)
    EndIf
    Call(ActorExists, YELLOW_ACTOR, LVar0)
    IfEq(LVar0, TRUE)
        ExecGetTID(A(yellow_ninja_koopa_HandleCommand), LVar1)
    EndIf
    Call(ActorExists, BLACK_ACTOR, LVar0)
    IfEq(LVar0, TRUE)
        ExecGetTID(A(black_ninja_koopa_HandleCommand), LVar1)
    EndIf
    Call(ActorExists, RED_ACTOR, LVar0)
    IfEq(LVar0, TRUE)
        ExecGetTID(A(red_ninja_koopa_HandleCommand), LVar1)
    EndIf
    // if any koopa bros are still alive, wait for their script to finish
    Label(0)
        IsThreadRunning(LVar1, LVar0)
        IfEq(LVar0, TRUE)
            Wait(1)
            Goto(0)
        EndIf
    Return
    End
};

// adds a random jitter to KoopaBros actors' X position while the tower is unstable
EvtScript N(EVS_KoopaBros_Idle) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
        IfNe(LVar0, AVAL_Boss_TowerState_Unstable)
            Wait(1)
            Goto(0)
        EndIf
        // get initial actor positions
        Call(ActorExists, GREEN_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorPos, GREEN_ACTOR, LVarA, LVarE, LVarF)
        EndIf
        Call(ActorExists, YELLOW_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorPos, YELLOW_ACTOR, LVarC, LVarE, LVarF)
        EndIf
        Call(ActorExists, BLACK_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorPos, BLACK_ACTOR, LVarD, LVarE, LVarF)
        EndIf
        Call(ActorExists, RED_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorPos, RED_ACTOR, LVarB, LVarE, LVarF)
        EndIf
        // while tower is unstable, add random X offsets to koopa bros
        Label(1)
            Call(ActorExists, GREEN_ACTOR, LVar0)
            IfNe(LVar0, FALSE)
                Call(GetActorVar, GREEN_ACTOR, AVAR_Koopa_State, LVar0)
                Switch(LVar0)
                    CaseOrEq(AVAL_Koopa_State_PosA)
                    CaseOrEq(AVAL_Koopa_State_PosD)
                    CaseOrEq(AVAL_Koopa_State_PosC)
                    CaseOrEq(AVAL_Koopa_State_PosB)
                        Call(RandInt, 2, LVar0)
                        Set(LVar1, 1)
                        Sub(LVar0, LVar1)
                        Add(LVar0, LVarA)
                        Call(GetActorPos, GREEN_ACTOR, LVar1, LVar2, LVar3)
                        Call(SetActorPos, GREEN_ACTOR, LVar0, LVar2, LVar3)
                    EndCaseGroup
                EndSwitch
            EndIf
            Call(ActorExists, YELLOW_ACTOR, LVar0)
            IfNe(LVar0, FALSE)
                Call(GetActorVar, YELLOW_ACTOR, AVAR_Koopa_State, LVar0)
                Switch(LVar0)
                    CaseOrEq(AVAL_Koopa_State_PosA)
                    CaseOrEq(AVAL_Koopa_State_PosD)
                    CaseOrEq(AVAL_Koopa_State_PosC)
                    CaseOrEq(AVAL_Koopa_State_PosB)
                        Call(RandInt, 2, LVar0)
                        Set(LVar1, 1)
                        Sub(LVar0, LVar1)
                        Add(LVar0, LVarC)
                        Call(GetActorPos, YELLOW_ACTOR, LVar1, LVar2, LVar3)
                        Call(SetActorPos, YELLOW_ACTOR, LVar0, LVar2, LVar3)
                    EndCaseGroup
                EndSwitch
            EndIf
            Call(ActorExists, BLACK_ACTOR, LVar0)
            IfNe(LVar0, FALSE)
                Call(GetActorVar, BLACK_ACTOR, AVAR_Koopa_State, LVar0)
                Switch(LVar0)
                    CaseOrEq(AVAL_Koopa_State_PosA)
                    CaseOrEq(AVAL_Koopa_State_PosD)
                    CaseOrEq(AVAL_Koopa_State_PosC)
                    CaseOrEq(AVAL_Koopa_State_PosB)
                        Call(RandInt, 2, LVar0)
                        Set(LVar1, 1)
                        Sub(LVar0, LVar1)
                        Add(LVar0, LVarD)
                        Call(GetActorPos, BLACK_ACTOR, LVar1, LVar2, LVar3)
                        Call(SetActorPos, BLACK_ACTOR, LVar0, LVar2, LVar3)
                    EndCaseGroup
                EndSwitch
            EndIf
            Call(ActorExists, RED_ACTOR, LVar0)
            IfNe(LVar0, FALSE)
                Call(GetActorVar, RED_ACTOR, AVAR_Koopa_State, LVar0)
                Switch(LVar0)
                    CaseOrEq(AVAL_Koopa_State_PosA)
                    CaseOrEq(AVAL_Koopa_State_PosD)
                    CaseOrEq(AVAL_Koopa_State_PosC)
                    CaseOrEq(AVAL_Koopa_State_PosB)
                        Call(RandInt, 2, LVar0)
                        Set(LVar1, 1)
                        Sub(LVar0, LVar1)
                        Add(LVar0, LVarB)
                        Call(GetActorPos, RED_ACTOR, LVar1, LVar2, LVar3)
                        Call(SetActorPos, RED_ACTOR, LVar0, LVar2, LVar3)
                    EndCaseGroup
                EndSwitch
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            IfEq(LVar0, AVAL_Boss_TowerState_Unstable)
                Wait(2)
                Goto(1)
            EndIf
        // once tower regains stability, reset X positions to initial values
        Call(ActorExists, GREEN_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorVar, GREEN_ACTOR, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Call(GetActorPos, GREEN_ACTOR, LVar1, LVar2, LVar3)
                    Call(SetActorPos, GREEN_ACTOR, LVarA, LVar2, LVar3)
                EndCaseGroup
            EndSwitch
        EndIf
        Call(ActorExists, YELLOW_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorVar, YELLOW_ACTOR, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Call(GetActorPos, YELLOW_ACTOR, LVar1, LVar2, LVar3)
                    Call(SetActorPos, YELLOW_ACTOR, LVarC, LVar2, LVar3)
                EndCaseGroup
            EndSwitch
        EndIf
        Call(ActorExists, BLACK_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorVar, BLACK_ACTOR, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Call(GetActorPos, BLACK_ACTOR, LVar1, LVar2, LVar3)
                    Call(SetActorPos, BLACK_ACTOR, LVarD, LVar2, LVar3)
                EndCaseGroup
            EndSwitch
        EndIf
        Call(ActorExists, RED_ACTOR, LVar0)
        IfNe(LVar0, FALSE)
            Call(GetActorVar, RED_ACTOR, AVAR_Koopa_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_Koopa_State_PosA)
                CaseOrEq(AVAL_Koopa_State_PosD)
                CaseOrEq(AVAL_Koopa_State_PosC)
                CaseOrEq(AVAL_Koopa_State_PosB)
                    Call(GetActorPos, RED_ACTOR, LVar1, LVar2, LVar3)
                    Call(SetActorPos, RED_ACTOR, LVarB, LVar2, LVar3)
                EndCaseGroup
            EndSwitch
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_KoopaBros_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            // set flags for player or partner hitting the koopa bros tower
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PartnerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            Else
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PlayerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            Set(LVarA, BOSS_CMD_HIT)
            ExecWait(N(EVS_BroadcastToKoopaBros))
            Wait(30)
            // if the attack was explosive, set both flags
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_BLAST)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PlayerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PartnerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            ExecWait(N(EVS_Broadcast_TowerUnstable))
        CaseEq(EVENT_HIT)
            // set flags for player or partner hitting the koopa bros tower
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PartnerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            Else
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PlayerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            // if the attack was explosive, set both flags
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_BLAST)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PlayerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PartnerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            // if this was the second hit, topple the tower
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfFlag(LVar0, AFLAG_Boss_PlayerHitTower)
                IfFlag(LVar0, AFLAG_Boss_PartnerHitTower)
                    ExecWait(N(EVS_Broadcast_ToppleHit))
                    Wait(20)
                    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                    Return
                EndIf
            EndIf
            // this was the first hit
            Set(LVarA, BOSS_CMD_HIT)
            ExecWait(N(EVS_BroadcastToKoopaBros))
            Wait(30)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            IfNe(LVar0, AVAL_Boss_TowerState_Unstable)
                ExecWait(N(EVS_Broadcast_TowerUnstable))
            EndIf
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfFlag(LVar0, AFLAG_Boss_TowerUnstable)
                IfNotFlag(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                    Call(ActorSpeak, MSG_CH1_0109, LVar0, 1, -1, -1)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    BitwiseOrConst(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    Wait(20)
                EndIf
            EndIf
        CaseEq(EVENT_BURN_HIT)
            // set flags for player or partner hitting the koopa bros tower
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PartnerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            Else
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PlayerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            // if the attack was explosive, set both flags
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_BLAST)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PlayerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PartnerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            // if this was the second hit, topple the tower
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfFlag(LVar0, AFLAG_Boss_PlayerHitTower)
                IfFlag(LVar0, AFLAG_Boss_PartnerHitTower)
                    ExecWait(N(EVS_Broadcast_ToppleHit))
                    Wait(20)
                    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                    Return
                EndIf
            EndIf
            // this was the first hit
            Set(LVarA, BOSS_CMD_BURN_HIT)
            ExecWait(N(EVS_BroadcastToKoopaBros))
            Wait(30)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            IfNe(LVar0, AVAL_Boss_TowerState_Unstable)
                ExecWait(N(EVS_Broadcast_TowerUnstable))
            EndIf
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfFlag(LVar0, AFLAG_Boss_TowerUnstable)
                IfNotFlag(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                    Call(ActorSpeak, MSG_CH1_0109, LVar0, 1, -1, -1)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    BitwiseOrConst(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    Wait(20)
                EndIf
            EndIf
        CaseEq(EVENT_ZERO_DAMAGE)
            Set(LVarA, BOSS_CMD_NO_DAMAGE_HIT)
            ExecWait(N(EVS_BroadcastToKoopaBros))
        CaseEq(EVENT_IMMUNE)
            // set both flags if the tower is already unstable
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
            IfEq(LVar0, AVAL_Boss_TowerState_Unstable)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PlayerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                BitwiseOrConst(LVar0, AFLAG_Boss_PartnerHitTower)
                Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            EndIf
            // if this was the second hit, topple the tower
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfFlag(LVar0, AFLAG_Boss_PlayerHitTower)
                IfFlag(LVar0, AFLAG_Boss_PartnerHitTower)
                    ExecWait(N(EVS_Broadcast_ToppleHit))
                    Wait(20)
                    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                    Return
                EndIf
            EndIf
            // this was the first hit
            Set(LVarA, BOSS_CMD_NO_DAMAGE_HIT)
            ExecWait(N(EVS_BroadcastToKoopaBros))
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfFlag(LVar0, AFLAG_Boss_TowerUnstable)
                IfNotFlag(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TopKoopaID, LVar0)
                    Call(ActorSpeak, MSG_CH1_0109, LVar0, 1, -1, -1)
                    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    BitwiseOrConst(LVar0, AFLAG_Boss_Dialogue_WereGoingOver)
                    Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
                    Wait(20)
                EndIf
            EndIf
        CaseOrEq(EVENT_DEATH)
        CaseOrEq(EVENT_BURN_DEATH)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_KoopaBros_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    // reform stable tower if tipping
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Boss_TowerState_None)
        CaseEq(AVAL_Boss_TowerState_Stable)
        CaseEq(AVAL_Boss_TowerState_Unstable)
            Wait(30)
            Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
            Set(LVarA, BOSS_CMD_STABLE)
            ExecWait(N(EVS_BroadcastToKoopaBros))
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AFLAG_Boss_TowerUnstable)
            Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AFLAG_Boss_Dialogue_WereGoingOver)
            Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerHeight, LVarA)
            Set(LVar0, LVarA)
            Mul(LVar0, 18)
            Add(LVar0, 20)
            Call(SetTargetOffset, ACTOR_SELF, PRT_TOWER, -4, LVar0)
            Call(SetActorSize, ACTOR_SELF, LVar0, 45)
        CaseEq(AVAL_Boss_TowerState_Toppled)
    EndSwitch
    // find if any koopa bros are toppled
    Set(LVar0, FIRST_KOOPA_ACTOR)
    Loop(4)
        Call(ActorExists, LVar0, LVar1)
        IfEq(LVar1, TRUE)
            Call(GetStatusFlags, LVar0, LVar1)
            IfEq(LVar1, 0)
                Call(GetActorVar, LVar0, AVAR_Koopa_State, LVar1)
                IfEq(LVar1, AVAL_Koopa_State_Toppled)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
            EndIf
        EndIf
        Add(LVar0, 1)
    EndLoop
    // zoom in to show the toppled koopa bros and have them try to get up
    IfEq(LFlag0, TRUE)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(SetBattleCamTarget, 90, 0, 0)
        Call(SetBattleCamDist, 350)
        Call(SetBattleCamOffsetY, 40)
        Call(MoveBattleCamOver, 15)
        Wait(15)
    EndIf
    Set(LVarA, BOSS_CMD_TRY_GET_UP)
    ExecWait(N(EVS_BroadcastToKoopaBros))
    // try tower operations
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Boss_TowerState_Stable)
            // try adding any orphaned koopa bros to the tower
            ExecWait(N(EVS_TryJoiningTower))
        CaseDefault
            // try forming a new tower
            ExecWait(N(EVS_TryFormingTower))
    EndSwitch
    // if only one koopa bro is alive, perform a solo attack
    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    IfFlag(LVar0, AFLAG_Boss_DoingSoloAttack)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 15)
        Set(LVarA, BOSS_CMD_SOLO_ATTACK)
        ExecWait(N(EVS_BroadcastToKoopaBros))
        Label(123)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            IfFlag(LVar0, AFLAG_Boss_DoingSoloAttack)
                Wait(1)
                Goto(123)
            EndIf
        Set(LVarA, BOSS_CMD_GET_READY)
        ExecWait(N(EVS_BroadcastToKoopaBros))
        Wait(5)
        Return
    EndIf
    Set(LVarA, BOSS_CMD_GET_READY)
    ExecWait(N(EVS_BroadcastToKoopaBros))
    Wait(5)
    Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
    IfEq(LVar0, AVAL_Boss_TowerState_Toppled)
        Return
    EndIf
    // execute spin attack
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    IfNotFlag(LVar0, AFLAG_Boss_Dialogue_SpinAttack)
        Call(GetActorVar, ACTOR_SELF, AVAR_Boss_LeadKoopaID, LVar0)
        Switch(LVar0)
            CaseEq(GREEN_ACTOR)
                Call(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Green_Talk, ANIM_KoopaBros_Green_Idle)
            CaseEq(YELLOW_ACTOR)
                Call(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Yellow_Talk, ANIM_KoopaBros_Yellow_Idle)
            CaseEq(BLACK_ACTOR)
                Call(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Black_Talk, ANIM_KoopaBros_Black_Idle)
            CaseEq(RED_ACTOR)
                Call(ActorSpeak, MSG_CH1_0108, LVar0, 1, ANIM_KoopaBros_Red_Talk, ANIM_KoopaBros_Red_Idle)
        EndSwitch
        Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        BitwiseOrConst(LVar0, AFLAG_Boss_Dialogue_SpinAttack)
        Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
    EndIf
    Set(LVarA, BOSS_CMD_SPIN_ATTACK)
    ExecWait(N(EVS_BroadcastToKoopaBros))
    Label(10)
        Call(GetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, LVar0)
        Wait(1)
        IfNe(LVar0, AVAL_Boss_TowerState_None)
            Goto(10)
        EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_Boss_TowerState, AVAL_Boss_TowerState_Stable)
    Return
    End
};

EvtScript N(EVS_KoopaBros_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    Call(SetEnemyHP, ACTOR_SELF, LVar0)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AFLAG_Boss_PlayerHitTower)
            Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            Call(GetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
            BitwiseAndConst(LVar0, ~AFLAG_Boss_PartnerHitTower)
            Call(SetActorVar, BOSS_ACTOR, AVAR_Boss_Flags, LVar0)
        CaseEq(PHASE_ENEMY_BEGIN)
        CaseEq(PHASE_ENEMY_END)
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
