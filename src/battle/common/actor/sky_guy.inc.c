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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Flying_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Flying_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Flying_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Intact)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_YELLOW_BALLOON, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_RED_BALLOON, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_BLUE_BALLOON, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 5)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetPartTargetFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_TARGET_NO_DAMAGE, true)
    Return
    End
};

EvtScript N(EVS_Flying_Idle) = {
    Return
    End
};

EvtScript N(EVS_KillActor) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_BalloonState, LVar2)
    IfNe(LVar2, AVAL_Balloons_Intact)
        ExecWait(EVS_Enemy_Death)
    Else
        Call(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Popping)
        Call(GetActorPos, ACTOR_SELF, LVar7, LVar8, LVar9)
        Add(LVar8, 20)
        PlayEffect(EFFECT_BALLOON, 2, LVar7, LVar8, LVar9, Float(1.0), 150, 0)
        Sub(LVar7, 14)
        Sub(LVar8, 4)
        PlayEffect(EFFECT_BALLOON, 0, LVar7, LVar8, LVar9, Float(1.0), 150, 0)
        Add(LVar7, 28)
        PlayEffect(EFFECT_BALLOON, 1, LVar7, LVar8, LVar9, Float(1.0), 150, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Popped)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
        ExecWait(EVS_Enemy_Death)
    EndIf
    Return
    End
};

EvtScript N(EVS_ResetAnimations) = {
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim02)
    Call(SetAnimation, ACTOR_SELF, PRT_YELLOW_BALLOON, ANIM_SkyGuy_Anim13)
    Call(SetAnimation, ACTOR_SELF, PRT_RED_BALLOON, ANIM_SkyGuy_Anim12)
    Call(SetAnimation, ACTOR_SELF, PRT_BLUE_BALLOON, ANIM_SkyGuy_Anim14)
    Return
    End
};

EvtScript N(EVS_StretchBalloons) = {
    Call(MakeLerp, 100, 80, 7, EASING_CUBIC_OUT)
    Label(0)
        Call(UpdateLerp)
        DivF(LVar0, Float(100.0))
        SetF(LVar2, Float(2.0))
        SubF(LVar2, LVar0)
        Call(SetPartScale, ACTOR_SELF, PRT_YELLOW_BALLOON, LVar2, LVar0, Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_RED_BALLOON, LVar2, LVar0, Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_BLUE_BALLOON, LVar2, LVar0, Float(1.0))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(MakeLerp, 80, 100, 7, EASING_COS_FAST_OVERSHOOT)
    Label(1)
        Call(UpdateLerp)
        DivF(LVar0, Float(100.0))
        SetF(LVar2, Float(2.0))
        SubF(LVar2, LVar0)
        Call(SetPartScale, ACTOR_SELF, PRT_YELLOW_BALLOON, LVar2, LVar0, Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_RED_BALLOON, LVar2, LVar0, Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_BLUE_BALLOON, LVar2, LVar0, Float(1.0))
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(SetPartScale, ACTOR_SELF, PRT_YELLOW_BALLOON, Float(1.0), Float(1.0), Float(1.0))
    Call(SetPartScale, ACTOR_SELF, PRT_RED_BALLOON, Float(1.0), Float(1.0), Float(1.0))
    Call(SetPartScale, ACTOR_SELF, PRT_BLUE_BALLOON, Float(1.0), Float(1.0), Float(1.0))
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_PopBalloons) = {
    Call(GetLastElement, LVar0)
    Set(LVar0, DAMAGE_TYPE_SPINY_SURGE)
    IfFlag(LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_4000 | DAMAGE_TYPE_SPINY_SURGE)
        Call(HideHealthBar, ACTOR_SELF)
        Thread
            Wait(20)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SKY_GUY_BALLOON_POP)
        EndThread
        Call(SetAnimation, ACTOR_SELF, PRT_YELLOW_BALLOON, ANIM_SkyGuy_Anim2E)
        Call(SetAnimation, ACTOR_SELF, PRT_RED_BALLOON, ANIM_SkyGuy_Anim2D)
        Call(SetAnimation, ACTOR_SELF, PRT_BLUE_BALLOON, ANIM_SkyGuy_Anim2F)
        Wait(30)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
        Call(SetActorVar, ACTOR_SELF, AVAR_BalloonState, AVAL_Balloons_Popped)
        Wait(15)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim00)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMOTE_QUESTION)
        PlayEffect(EFFECT_EMOTE, EMOTE_QUESTION, 0, LVar0, LVar1, LVar2, 24, 0, 25, 0, 0)
        Wait(25)
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim06)
        Wait(30)
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim06)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
        Call(N(StartRumbleWithParams), 120, 10)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.5))
        EndThread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
        Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
        Call(SetPartFlags, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
        Call(SetPartFlags, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim12)
        PlayEffect(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0, 0)
        Wait(40)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, false)
        Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Ground_TakeTurn)))
        Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Ground_Idle)))
        Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Ground_HandleEvent)))
        Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, true)
        Call(HPBarToHome, ACTOR_SELF)
        Call(ResetAllActorSounds, ACTOR_SELF)
    Else
        ExecWait(N(EVS_StretchBalloons))
    EndIf
    Return
    End
};

EvtScript N(EVS_Flying_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            Call(func_8026E914, LVar0, LVar1)
            IfGe(LVar1, PRT_YELLOW_BALLOON)
                ExecWait(N(EVS_StretchBalloons))
            Else
                SetConst(LVar0, PRT_FLYING)
                SetConst(LVar1, ANIM_SkyGuy_Anim06)
                ExecWait(EVS_Enemy_Hit)
            EndIf
        CaseEq(EVENT_HIT)
            Call(func_8026E914, LVar0, LVar1)
            IfGe(LVar1, PRT_YELLOW_BALLOON)
                ExecWait(N(EVS_StretchBalloons))
                ExecWait(N(EVS_PopBalloons))
            Else
                SetConst(LVar0, PRT_FLYING)
                SetConst(LVar1, ANIM_SkyGuy_Anim06)
                ExecWait(EVS_Enemy_Hit)
            EndIf
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim09)
            SetConst(LVar2, ANIM_SkyGuy_Anim0A)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim09)
            SetConst(LVar2, ANIM_SkyGuy_Anim0A)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim0A)
            ExecWait(N(EVS_KillActor))
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(func_8026E914, LVar0, LVar1)
            IfGe(LVar1, PRT_YELLOW_BALLOON)
                ExecWait(N(EVS_StretchBalloons))
            Else
                SetConst(LVar0, PRT_FLYING)
                SetConst(LVar1, ANIM_SkyGuy_Anim01)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(func_8026E914, LVar0, LVar1)
            IfGe(LVar1, PRT_YELLOW_BALLOON)
                ExecWait(N(EVS_StretchBalloons))
            Else
                SetConst(LVar0, PRT_FLYING)
                SetConst(LVar1, ANIM_SkyGuy_Anim01)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim06)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim06)
            ExecWait(N(EVS_KillActor))
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim03)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim01)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_YELLOW_BALLOON, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_RED_BALLOON, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BLUE_BALLOON, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, false)
            Call(SetAnimation, ACTOR_SELF, PRT_YELLOW_BALLOON, ANIM_SkyGuy_Anim1F)
            Call(SetAnimation, ACTOR_SELF, PRT_RED_BALLOON, ANIM_SkyGuy_Anim1E)
            Call(SetAnimation, ACTOR_SELF, PRT_BLUE_BALLOON, ANIM_SkyGuy_Anim20)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim03)
            SetConst(LVar2, ANIM_SkyGuy_Anim06)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim03)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_SkyGuy_Anim07)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    ExecWait(N(EVS_ResetAnimations))
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Flying_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 1)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_DRAW)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim08)
    Wait(12)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Add(LVar2, 2)
    Call(SetPartPos, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_STONE, ANIM_SkyGuy_Anim0B)
    Wait(12)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_FIRE)
    Call(SetPartSounds, ACTOR_SELF, PRT_STONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseEq(HIT_RESULT_MISS)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 120)
            Set(LVar1, 0)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(12.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.1))
            Call(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, true)
            ExecWait(N(EVS_ResetAnimations))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        CaseEq(HIT_RESULT_LUCKY)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Set(LVar1, -5)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(14.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SkyGuy_Anim07)
            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 65)
            Set(LVar1, -5)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(6.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, true)
            ExecWait(N(EVS_ResetAnimations))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
    EndSwitch
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(14.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.1))
    Call(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SLINGSHOT, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 55)
            Set(LVar1, 0)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(6.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, Float(4.0))
            Sub(LVar0, 20)
            Call(FlyPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, true)
        EndCaseGroup
    EndSwitch
    ExecWait(N(EVS_ResetAnimations))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Ground_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Ground_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Ground_HandleEvent)))
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Ground_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfFlag(LVar0, STATUS_FLAG_SLEEP)
            Call(SetTargetOffset, ACTOR_SELF, PRT_GROUND, -4, 14)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, 0, 0)
            Call(N(SetAbsoluteStatusOffsets), -10, 13, 10, 13)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_GROUND, 0, 24)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, -1, -10)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Ground_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    SetConst(LVar0, PRT_GROUND)
    SetConst(LVar1, ANIM_ShyGuy_Red_Anim03)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
    Return
    End
};

EvtScript N(EVS_Ground_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_Ground_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim03)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim14)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_Tackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HOP, 0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim04)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Wait(3)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    EndThread
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim04)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim05)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
    Wait(8)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    ExecWait(N(EVS_Ground_ReturnHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_Vault) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TIMING_BAR_GO)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 80)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim04)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Sub(LVar0, 40)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
            Thread
                Wait(12)
                Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim0A)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 24, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
    Thread
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim0A)
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 18, false, true, false)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_VAULT, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Set(LVar3, 0)
                Loop(20)
                    Sub(LVar3, 30)
                    IfLt(LVar3, 0)
                        Add(LVar3, 360)
                    EndIf
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    Wait(1)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Goto(1)
            EndIf
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfEq(LVar0, 0)
                Goto(1)
            EndIf
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING | SOUND_ID_TRIGGER_CHANGE_SOUND)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim09)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim07)
            Wait(15)
            Goto(2)
            Label(1)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim10)
            Wait(10)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISAPPOINTED)
            Call(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 50)
                Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim11)
            Else
                Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim13)
            EndIf
            Wait(25)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Label(2)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ShyGuy_Red_Anim01)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Ground_TakeTurn) = {
    Call(RandInt, 1, LVar0)
    IfEq(LVar0, 0)
        ExecWait(N(EVS_Attack_Tackle))
    Else
        ExecWait(N(EVS_Attack_Vault))
    EndIf
    Return
    End
};
