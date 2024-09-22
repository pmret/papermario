#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/ShyStackGuy.h"
#include "sprite/npc/ShyStackDamage.h"
#include "sprite/npc/ShyStackRock.h"
#include "sprite/npc/GeneralGuy.h"
#include "sprite/npc/ShyGuy.h"

#include "battle/area/omo2/actor/boss_common.h"

#define NAMESPACE b_area_omo2_3_shy_stack

extern s32 N(FourStackAnims)[];
extern s32 N(RockAnims)[];
extern s32 N(DamageAnims)[];
extern s32 N(ShyGuyAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_SpinSmashLaunch);
extern EvtScript N(EVS_ShootRock);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_SpinSmashDeath);
extern EvtScript N(EVS_SpinSmashHit);
extern EvtScript N(EVS_SpinSmashHit_Top);
extern EvtScript N(EVS_SpinSmashHit_Stack);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_STACK_1     = 2,
    PRT_STACK_2     = 3,
    PRT_STACK_3     = 4,
    PRT_STACK_4     = 5,
    PRT_ROCK_1      = 6,
    PRT_ROCK_2      = 7,
    PRT_ROCK_3      = 8,
    PRT_ROCK_4      = 9,
    PRT_KNOCKOFF    = 10,
    // used when forming the stack
    PRT_GUY_1       = 11,
    PRT_GUY_2       = 12,
    PRT_GUY_3       = 13,
    PRT_GUY_4       = 14,
};

enum N(ActorVars) {
    AVAR_IN_Order           = 0,
    AVAR_Anim_Still         = 1,
    AVAR_Anim_Idle          = 2,
    AVAR_Anim_Hurt          = 3,
    AVAR_Anim_BurnHurt      = 4,
    AVAR_Anim_BurnStill     = 5,
    AVAR_Anim_Attack        = 6,
    AVAR_ShotsToFire        = 7,
    AVAR_DefeatedCount      = 8,
};

enum N(ActorParams) {
    DMG_SHOOT_ONE       = 1,
    DMG_SHOOT_TWO       = 2,
    DMG_SHOOT_THREE     = 3,
    DMG_SHOOT_FOUR      = 4,
};

// doesn't actually do anything
API_CALLABLE(N(PrintDebugValue)) {
    Bytecode* args = script->ptrReadPos;
    char* name = (char*) *args++;
    s32 value = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              60,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               60,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(FourStackAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_STACK_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 67 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_STACK_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 50 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_STACK_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 33 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_STACK_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_ROCK_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_ROCK_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_ROCK_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_ROCK_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_KNOCKOFF,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(DamageAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_GUY_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(ShyGuyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_GUY_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(ShyGuyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_GUY_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(ShyGuyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_GUY_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(ShyGuyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SHY_STACK,
    .level = ACTOR_LEVEL_SHY_STACK,
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
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 75 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusTextOffset = { 10, 65 },
};

s32 N(FourStackAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyStackGuy_Anim04,
    STATUS_KEY_STONE,     ANIM_ShyStackGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShyStackGuy_Anim00,
    STATUS_KEY_POISON,    ANIM_ShyStackGuy_Anim04,
    STATUS_KEY_STOP,      ANIM_ShyStackGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShyStackGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0C,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0C,
    STATUS_KEY_FEAR,      ANIM_ShyStackGuy_Anim00,
    STATUS_END,
};

s32 N(ThreeStackAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyStackGuy_Anim05,
    STATUS_KEY_STONE,     ANIM_ShyStackGuy_Anim01,
    STATUS_KEY_SLEEP,     ANIM_ShyStackGuy_Anim01,
    STATUS_KEY_POISON,    ANIM_ShyStackGuy_Anim05,
    STATUS_KEY_STOP,      ANIM_ShyStackGuy_Anim01,
    STATUS_KEY_STATIC,    ANIM_ShyStackGuy_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim01,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0D,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0D,
    STATUS_KEY_FEAR,      ANIM_ShyStackGuy_Anim01,
    STATUS_END,
};

s32 N(TwoStackAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyStackGuy_Anim06,
    STATUS_KEY_STONE,     ANIM_ShyStackGuy_Anim02,
    STATUS_KEY_SLEEP,     ANIM_ShyStackGuy_Anim02,
    STATUS_KEY_POISON,    ANIM_ShyStackGuy_Anim06,
    STATUS_KEY_STOP,      ANIM_ShyStackGuy_Anim02,
    STATUS_KEY_STATIC,    ANIM_ShyStackGuy_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim02,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0E,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0E,
    STATUS_KEY_FEAR,      ANIM_ShyStackGuy_Anim02,
    STATUS_END,
};

s32 N(OneStackAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyStackGuy_Anim07,
    STATUS_KEY_STONE,     ANIM_ShyStackGuy_Anim03,
    STATUS_KEY_SLEEP,     ANIM_ShyStackGuy_Anim03,
    STATUS_KEY_POISON,    ANIM_ShyStackGuy_Anim07,
    STATUS_KEY_STOP,      ANIM_ShyStackGuy_Anim03,
    STATUS_KEY_STATIC,    ANIM_ShyStackGuy_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_ShyStackGuy_Anim03,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0F,
    STATUS_KEY_DIZZY,     ANIM_ShyStackGuy_Anim0F,
    STATUS_KEY_FEAR,      ANIM_ShyStackGuy_Anim03,
    STATUS_END,
};

s32 N(RockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyStackRock_Anim00,
    STATUS_END,
};

s32 N(DamageAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyStackDamage_Anim00,
    STATUS_END,
};

s32 N(ShyGuyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyGuy_Red_Anim01,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim00)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim04)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim08)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim10)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim14)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1B)
    Call(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 0)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_IN_Order, LVar0)
    IfEq(LVar0, 0)
        Set(LVar0, 10)
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_4, LVar0, 200, 0)
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_3, LVar0, 200, 0)
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_2, LVar0, 200, 0)
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_1, LVar0, 200, 0)
        Thread
            Wait(5)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_4, SOUND_FALL_QUICK)
        EndThread
        Thread
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim0A)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_4, Float(1.0))
            Call(SetPartSounds, ACTOR_SELF, PRT_GUY_4, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            Call(FallPartTo, ACTOR_SELF, PRT_GUY_4, LVar0, 0, 0, 36)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_4, SOUND_SHY_STACK_SQUISH)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim07)
        EndThread
        Thread
            Wait(36)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_3, SOUND_FALL_QUICK)
        EndThread
        Thread
            Wait(31)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim0A)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_3, Float(1.0))
            Call(SetPartSounds, ACTOR_SELF, PRT_GUY_3, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            Call(FallPartTo, ACTOR_SELF, PRT_GUY_3, LVar0, 18, 0, 32)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_3, SOUND_SHY_STACK_SQUISH)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim07)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -5, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
        EndThread
        Thread
            Wait(67)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_2, SOUND_FALL_QUICK)
        EndThread
        Thread
            Wait(62)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim0A)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_2, Float(1.0))
            Call(SetPartSounds, ACTOR_SELF, PRT_GUY_2, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            Call(FallPartTo, ACTOR_SELF, PRT_GUY_2, LVar0, 36, 0, 28)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_2, SOUND_SHY_STACK_SQUISH)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim07)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -4, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -6, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -4, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
        EndThread
        Thread
            Wait(98)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_1, SOUND_FALL_QUICK)
        EndThread
        Thread
            Wait(93)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim0A)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_1, Float(1.0))
            Call(SetPartSounds, ACTOR_SELF, PRT_GUY_1, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            Call(FallPartTo, ACTOR_SELF, PRT_GUY_1, LVar0, 54, 0, 24)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_1, SOUND_SHY_STACK_SQUISH)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim07)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -5, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, 0, 0)
            Wait(7)
            Call(GetPartOffset, ACTOR_SELF, PRT_GUY_4, LVar0, LVar1, LVar2)
            Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(HPBarToHome, ACTOR_SELF)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        EndThread
    Else
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_4, 200, 0, 47)
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_3, 200, 0, 47)
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_2, 200, 0, 47)
        Call(SetPartPos, ACTOR_SELF, PRT_GUY_1, 200, 0, 47)
        Thread
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim04)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_GUY_4, Float(4.0))
            Call(RunPartTo, ACTOR_SELF, PRT_GUY_4, 55, 0, 47, FALSE)
            Call(RunPartTo, ACTOR_SELF, PRT_GUY_4, 50, 0, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim07)
        EndThread
        Thread
            Wait(31)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim04)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_GUY_3, Float(4.0))
            Call(RunPartTo, ACTOR_SELF, PRT_GUY_3, 55, 0, 47, 36)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim09)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_3, Float(1.0))
            Call(JumpPartTo, ACTOR_SELF, PRT_GUY_3, 50, 18, 0, 20, TRUE)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_3, SOUND_SHY_STACK_SQUISH)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim07)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -5, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
        EndThread
        Thread
            Wait(77)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim0A)
        EndThread
        Thread
            Wait(62)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim04)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_GUY_2, Float(4.0))
            Call(RunPartTo, ACTOR_SELF, PRT_GUY_2, 55, 0, 47, 36)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim09)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_2, Float(1.0))
            Call(JumpPartTo, ACTOR_SELF, PRT_GUY_2, 50, 36, 0, 20, TRUE)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_2, SOUND_SHY_STACK_SQUISH)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim07)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -5, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
        EndThread
        Thread
            Wait(108)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim0A)
        EndThread
        Thread
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim04)
            Wait(143)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim09)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim0A)
        EndThread
        Thread
            Wait(133)
            Call(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
            Add(LVar1, -3)
            Call(SetPartPos, ACTOR_SELF, PRT_GUY_1, LVar0, LVar1, LVar2)
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Add(LVar0, -20)
            Add(LVar1, 18)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_1, Float(0.6))
            Call(JumpPartTo, ACTOR_SELF, PRT_GUY_1, LVar0, LVar1, LVar2, 20, TRUE)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_1, Float(0.3))
            Call(JumpPartTo, ACTOR_SELF, PRT_GUY_1, 50, 54, 0, 30, TRUE)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_1, SOUND_SHY_STACK_SQUISH)
            Call(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim07)
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim04)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.2), Float(0.8), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -5, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.1), Float(0.9), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            Wait(1)
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_4, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_3, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartScale, ACTOR_SELF, PRT_GUY_2, Float(1.0), Float(1.0), Float(1.0))
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, 0, 0)
            Wait(12)
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
            Call(GetPartOffset, ACTOR_SELF, PRT_GUY_4, LVar0, LVar1, LVar2)
            Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(HPBarToHome, ACTOR_SELF)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Call(SetActorVar, ACTOR_TANK, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Next)
        EndThread
    EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
                IfEq(LVarA, 3)
                    SetConst(LVar0, PRT_MAIN)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                    ExecWait(EVS_Enemy_Hit)
                Else
                    Call(GetDamageSource, LVar0)
                    Switch(LVar0)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_SpinSmashLaunch))
                        EndCaseGroup
                        CaseDefault
                            SetConst(LVar0, PRT_MAIN)
                            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                            ExecWait(EVS_Enemy_Hit)
                    EndSwitch
                EndIf
            EndIf
        CaseEq(EVENT_DEATH)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
            Else
                Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
                IfEq(LVarA, 3)
                    SetConst(LVar0, PRT_MAIN)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                    ExecWait(EVS_Enemy_Hit)
                    Wait(10)
                Else
                    Call(GetDamageSource, LVar0)
                    Switch(LVar0)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_SpinSmashLaunch))
                        EndCaseGroup
                        CaseDefault
                            SetConst(LVar0, PRT_MAIN)
                            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                            ExecWait(EVS_Enemy_Hit)
                            Wait(10)
                    EndSwitch
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, 1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfFlag(LVar5, STATUS_FLAG_SHRINK)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                IfEq(LVarA, 3)
                    ExecWait(EVS_Enemy_BurnHit)
                Else
                    Call(GetDamageSource, LVarA)
                    Switch(LVarA)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_SpinSmashLaunch))
                        EndCaseGroup
                        CaseDefault
                            ExecWait(EVS_Enemy_BurnHit)
                    EndSwitch
                EndIf
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, 1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfFlag(LVar5, STATUS_FLAG_SHRINK)
                ExecWait(EVS_Enemy_BurnHit)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            Else
                IfEq(LVarA, 3)
                    ExecWait(EVS_Enemy_BurnHit)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
                Else
                    Call(GetDamageSource, LVarA)
                    Switch(LVarA)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_SpinSmashLaunch))
                            SetConst(LVar1, -1)
                        EndCaseGroup
                        CaseDefault
                            ExecWait(EVS_Enemy_BurnHit)
                            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
                    EndSwitch
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfFlag(LVar5, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                ExecWait(N(EVS_SpinSmashHit))
            EndIf
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfFlag(LVar5, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                ExecWait(N(EVS_SpinSmashHit))
            EndIf
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_LAUNCH_HIT)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfFlag(LVar5, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                ExecWait(N(EVS_SpinSmashLaunch))
            EndIf
        CaseEq(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            IfFlag(LVar5, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                ExecWait(N(EVS_SpinSmashLaunch))
            EndIf
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(N(EVS_SpinSmashDeath))
            Return
        CaseEq(EVENT_SHOCK_HIT)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_SPIKE_TAUNT)
            Call(GetBattleFlags, LVar2)
            IfFlag(LVar2, BS_FLAGS1_PARTNER_ACTING)
                Call(GetMenuSelection, LVar0, LVar1, LVar2)
                IfEq(LVar2, MOVE_SPOOK)
                    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                    Return
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Idle, LVar1)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            Wait(1000)
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Idle, LVar1)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_END_FIRST_STRIKE)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Idle, LVar1)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar2)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar2)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_SpinAround) = {
    Set(LVar0, 0)
    Label(0)
        Sub(LVar0, 30)
        IfLt(LVar0, 0)
            Add(LVar0, 360)
        EndIf
        Call(SetActorYaw, ACTOR_SELF, LVar0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SpinSmashHit) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
    Switch(LVarA)
        CaseEq(0)
            ExecWait(N(EVS_SpinSmashHit_Stack))
        CaseEq(1)
            ExecWait(N(EVS_SpinSmashHit_Stack))
        CaseEq(2)
            ExecWait(N(EVS_SpinSmashHit_Stack))
        CaseEq(3)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(N(EVS_SpinSmashHit_Top))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_SpinSmashHit_Top) = {
    ExecGetTID(N(EVS_SpinAround), LVarE)
    Call(GetPartEventFlags, ACTOR_SELF, LVar0, LVarA)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(CreateCurrentPosTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_ALLOW_TARGET_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerID, LVar1)
        Call(GetOwnerTarget, LVar0, LVar9)
        IfNe(LVar1, LVar0)
            Call(ChooseNextTarget, ITER_NEXT, LVar0)
            Goto(0)
        EndIf
    Label(1)
        Add(LVarF, 1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfEq(LVar0, ITER_NO_MORE)
            Goto(10)
        EndIf
        Call(GetOwnerTarget, LVar0, LVar9)
        Call(GetActorFlags, LVar0, LVar1)
        IfFlag(LVar1, ACTOR_FLAG_TARGET_ONLY)
            Goto(1)
        EndIf
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
        Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
        Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        EndThread
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
        Goto(1)
    Label(10)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    Div(LVar3, 2)
    Set(LVar4, 70)
    Sub(LVar4, LVar3)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar5, LVar4)
    Sub(LVar5, LVar0)
    IfLt(LVar5, 6)
        Set(LVar5, 1)
    Else
        Set(LVar5, 0)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, LVar5, FALSE, TRUE, FALSE)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    Sub(LVar4, 18)
    IfLe(LVar4, LVar6)
        Set(LVar4, LVar6)
        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    Else
        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
        Call(SetGoalToHome, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar4, LVar7, LVar8)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EndIf
    KillThread(LVarE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Wait(10)
    Return
    End
};

EvtScript N(EVS_DetachMember) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
    Switch(LVarA)
        CaseEq(0)
            Call(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim01)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim05)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim09)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim11)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim15)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1C)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ThreeStackAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_1, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            Call(SetActorStatusOffsets, ACTOR_SELF, 0, -20, 0, -20)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 57, 30)
        CaseEq(1)
            Call(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim02)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim06)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim0A)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim12)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim16)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1D)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(TwoStackAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            Call(SetActorStatusOffsets, ACTOR_SELF, 0, -40, 0, -40)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 39, 30)
        CaseEq(2)
            Call(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim03)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim07)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim0B)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim13)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim17)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1E)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(OneStackAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_4, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_STACK_4, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            Call(SetActorStatusOffsets, ACTOR_SELF, 0, -60, 0, -60)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 21, 30)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_DropStack) = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 18)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar3, LVar1)
        Wait(2)
        Sub(LVar3, 1)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(3)
        Sub(LVar3, 2)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(2)
        Sub(LVar3, 3)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Sub(LVar3, 5)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Sub(LVar3, 7)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Add(LVar3, 2)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Add(LVar3, 3)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Add(LVar3, 3)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Sub(LVar3, 3)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Sub(LVar3, 3)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Wait(1)
        Sub(LVar3, 2)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_STACK_SQUISH)
    EndThread
    Return
    End
};

EvtScript N(EVS_SpinSmashHit_Stack) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(N(PrintDebugValue), Ref("X"), LVar0)
    Call(N(PrintDebugValue), Ref("Y"), LVar1)
    Call(N(PrintDebugValue), Ref("Z"), LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_KNOCKOFF, ANIM_ShyStackDamage_Anim00)
    Call(SetPartPos, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    Call(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, 0, 0, 0)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    ExecWait(N(EVS_DetachMember))
    SetConst(LVar0, PRT_MAIN)
    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    ExecWait(N(EVS_DropStack))
    Call(CreateCurrentPosTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_PRIMARY_ONLY | TARGET_FLAG_ALLOW_TARGET_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerID, LVar1)
        Call(GetOwnerTarget, LVar0, LVar9)
        IfNe(LVar1, LVar0)
            Call(ChooseNextTarget, ITER_NEXT, LVar0)
            Goto(0)
        EndIf
    Label(1)
        Add(LVarF, 1)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        Call(N(PrintDebugValue), Ref("T"), LVar0)
        IfEq(LVar0, ITER_NO_MORE)
            Goto(10)
        EndIf
        Call(GetOwnerTarget, LVar0, LVar9)
        Call(GetActorFlags, LVar0, LVar1)
        IfFlag(LVar1, ACTOR_FLAG_TARGET_ONLY)
            Goto(1)
        EndIf
        Call(GetOwnerID, LVar0)
        Call(N(PrintDebugValue), Ref("MYSELF ID"), LVar0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(N(PrintDebugValue), Ref("TARGET ID"), LVar0)
        Call(N(PrintDebugValue), Ref("TARGET PARTS ID"), LVar1)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, Float(0.1))
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, Float(7.0))
        Call(N(PrintDebugValue), Ref("TX"), LVar0)
        Call(N(PrintDebugValue), Ref("TY"), LVar1)
        Call(N(PrintDebugValue), Ref("TZ"), LVar2)
        Call(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2, 0, TRUE)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        EndThread
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
        Goto(1)
    Label(10)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, Float(0.1))
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, Float(6.0))
    Call(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    Div(LVar3, 2)
    Set(LVar4, 70)
    Sub(LVar4, LVar3)
    Call(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    Set(LVar5, LVar4)
    Sub(LVar5, LVar0)
    IfLt(LVar5, 6)
        Set(LVar5, 1)
    Else
        Set(LVar5, 0)
    EndIf
    Call(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar4, LVar1, LVar2, LVar5, TRUE)
    Sub(LVar4, 18)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, Float(1.5))
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, Float(3.0))
    Call(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar4, LVar1, LVar2, 12, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_KNOCKOFF, SOUND_ACTOR_DEATH)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Set(LVar0, 0)
    Loop(12)
        Call(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, LVar0, 0, 0)
        Add(LVar0, 8)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Return
    End
};

EvtScript N(EVS_SpinSmashLaunch) = {
    Call(GetDamageSource, LVar0)
    IfEq(LVar0, DMG_SRC_FIRE_SHELL)
        Call(SetAnimation, ACTOR_SELF, PRT_KNOCKOFF, ANIM_ShyStackDamage_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_KNOCKOFF, ANIM_ShyStackDamage_Anim00)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(N(PrintDebugValue), Ref("X"), LVar0)
    Call(N(PrintDebugValue), Ref("Y"), LVar1)
    Call(N(PrintDebugValue), Ref("Z"), LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    Call(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, 0, 0, 0)
    ExecWait(N(EVS_DetachMember))
    Call(GetLastEvent, ACTOR_SELF, LVar1)
    Switch(LVar1)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
        EndCaseGroup
        CaseDefault
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    ExecWait(N(EVS_DropStack))
    Thread
        Set(LVar0, 0)
        Loop(30)
            Add(LVar0, 24)
            Call(SetPartYaw, ACTOR_SELF, PRT_KNOCKOFF, LVar0)
            Wait(1)
        EndLoop
        Call(SetPartYaw, ACTOR_SELF, PRT_KNOCKOFF, LVar0)
    EndThread
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, Float(3.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, Float(0.5))
    Call(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    Div(LVar3, 2)
    Set(LVar4, 70)
    Sub(LVar4, LVar3)
    Call(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    Set(LVar5, LVar4)
    Sub(LVar5, LVar0)
    IfLt(LVar5, 6)
        Set(LVar5, 1)
    Else
        Set(LVar5, 0)
    EndIf
    Call(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar4, LVar1, LVar2, LVar5, TRUE)
    Set(LVar1, 0)
    Sub(LVar0, 10)
    Call(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2, 10, TRUE)
    Wait(20)
    Call(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_KNOCKOFF, SOUND_ACTOR_DEATH)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Set(LVar0, 0)
    Loop(12)
        Call(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, LVar0, 0, 0)
        Add(LVar0, 8)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            Div(LVar3, 2)
            Add(LVar1, LVar3)
            Add(LVar2, 5)
            DivF(LVar3, Float(10.0))
            PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        CaseDefault
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Attack, LVar0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Wait(20)
    Add(LVar0, 4)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_DRAW)
    Wait(5)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_FIRE)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVar5, 1)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 0)
        EndCaseGroup
        CaseDefault
            Set(LVar5, 0)
            Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 4)
                CaseEq(1)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 3)
                CaseEq(2)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 2)
                CaseEq(3)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 1)
                CaseDefault
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 1)
            EndSwitch
    EndSwitch
    Set(LVar1, LVar5)
    Call(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVar0)
    IfLe(LVar0, 0)
        Set(LVar0, 0)
        Exec(N(EVS_ShootRock))
    EndIf
    IfLe(LVar0, 1)
        Set(LVar0, 1)
        Exec(N(EVS_ShootRock))
    EndIf
    IfLe(LVar0, 2)
        Set(LVar0, 2)
        Exec(N(EVS_ShootRock))
    EndIf
    Set(LVar0, 3)
    Exec(N(EVS_ShootRock))
    Wait(10)
    Call(GetActorVar, ACTOR_SELF, AVAR_ShotsToFire, LVar0)
    Switch(LVar0)
        CaseEq(1)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_ONE, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(2)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_TWO, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(3)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_THREE, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(4)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_FOUR, BS_FLAGS1_TRIGGER_EVENTS)
        CaseDefault
            Switch(LVarF)
                CaseEq(HIT_RESULT_LUCKY)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                CaseDefault
            EndSwitch
    EndSwitch
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(15)
            Wait(15)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ShootRock) = {
    Call(GetStatusFlags, ACTOR_SELF, LVarF)
    IfFlag(LVarF, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_1, Float(0.4), Float(0.4), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_2, Float(0.4), Float(0.4), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_3, Float(0.4), Float(0.4), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_4, Float(0.4), Float(0.4), Float(1.0))
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Switch(LVar0)
            CaseEq(0)
                Add(LVar3, -4)
                Add(LVar4, 28)
                Set(LVar2, 9)
            CaseEq(1)
                Add(LVar3, -4)
                Add(LVar4, 21)
                Set(LVar2, 8)
            CaseEq(2)
                Add(LVar3, -4)
                Add(LVar4, 14)
                Set(LVar2, 7)
            CaseDefault
                Add(LVar3, -4)
                Add(LVar4, 7)
                Set(LVar2, 6)
        EndSwitch
    Else
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_1, Float(1.0), Float(1.0), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_2, Float(1.0), Float(1.0), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_3, Float(1.0), Float(1.0), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK_4, Float(1.0), Float(1.0), Float(1.0))
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Switch(LVar0)
            CaseEq(0)
                Add(LVar3, -10)
                Add(LVar4, 72)
                Set(LVar2, 9)
            CaseEq(1)
                Add(LVar3, -10)
                Add(LVar4, 54)
                Set(LVar2, 8)
            CaseEq(2)
                Add(LVar3, -10)
                Add(LVar4, 36)
                Set(LVar2, 7)
            CaseDefault
                Add(LVar3, -10)
                Add(LVar4, 18)
                Set(LVar2, 6)
        EndSwitch
    EndIf
    Call(SetPartSounds, ACTOR_SELF, LVar2, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(SetPartPos, ACTOR_SELF, LVar2, LVar3, LVar4, LVar5)
    Call(SetAnimation, ACTOR_SELF, LVar2, ANIM_ShyStackRock_Anim00)
    Call(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Wait(1)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    Call(SetPartMoveSpeed, ACTOR_SELF, LVar2, Float(12.0))
    Call(SetPartJumpGravity, ACTOR_SELF, LVar2, Float(1.0))
    Switch(LVar1)
        CaseEq(0)
            Call(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 9, TRUE)
            Sub(LVar6, 100)
            Call(RandInt, 40, LVar9)
            Sub(LVar6, LVar9)
            Add(LVar7, LVar9)
            Call(SetPartJumpGravity, ACTOR_SELF, LVar2, Float(0.8))
            Call(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 25, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        CaseEq(1)
            Switch(LVar0)
                CaseEq(0)
                    Call(SetPartJumpGravity, ACTOR_SELF, LVar2, Float(2.2))
                CaseEq(1)
                    Call(SetPartJumpGravity, ACTOR_SELF, LVar2, Float(1.8))
                CaseEq(2)
                    Call(SetPartJumpGravity, ACTOR_SELF, LVar2, Float(1.4))
                CaseDefault
                    Call(SetPartJumpGravity, ACTOR_SELF, LVar2, Float(1.0))
            EndSwitch
            Set(LVar7, 0)
            Call(RandInt, 35, LVar9)
            Add(LVar9, 30)
            Sub(LVar6, LVar9)
            Call(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 9, TRUE)
            Call(RandInt, 25, LVar9)
            Add(LVar9, 45)
            Sub(LVar6, LVar9)
            Call(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 8, TRUE)
            Sub(LVar6, 25)
            Call(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 4, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Death) = {
    ExecWait(EVS_Enemy_DeathWithoutRemove)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(GetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    IfGe(LVar0, AVAL_StackPhase_Defeated)
        Call(FreezeBattleState, TRUE)
    EndIf
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_SpinSmashDeath) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Set(LVar2, 0)
    Loop(24)
        Call(SetActorYaw, ACTOR_SELF, LVar2)
        Add(LVar2, 30)
        Wait(1)
    EndLoop
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Call(PlaySound, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Set(LVar3, 0)
    Loop(12)
        Call(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(GetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    IfGe(LVar0, AVAL_StackPhase_Defeated)
        Call(FreezeBattleState, TRUE)
    EndIf
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
