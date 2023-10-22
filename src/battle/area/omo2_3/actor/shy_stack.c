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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim00)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim04)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim08)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim10)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim14)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1B)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_Order, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_SET(LVar0, 10)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_4, LVar0, 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_3, LVar0, 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_2, LVar0, 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_1, LVar0, 200, 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_4, SOUND_FALL_QUICK)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_GUY_4, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            EVT_CALL(FallPartTo, ACTOR_SELF, PRT_GUY_4, LVar0, 0, 0, 36)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_4, SOUND_SHY_STACK_SQUISH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim07)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(36)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_3, SOUND_FALL_QUICK)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(31)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_GUY_3, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            EVT_CALL(FallPartTo, ACTOR_SELF, PRT_GUY_3, LVar0, 18, 0, 32)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_3, SOUND_SHY_STACK_SQUISH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(67)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_2, SOUND_FALL_QUICK)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(62)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_GUY_2, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            EVT_CALL(FallPartTo, ACTOR_SELF, PRT_GUY_2, LVar0, 36, 0, 28)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_2, SOUND_SHY_STACK_SQUISH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(98)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_1, SOUND_FALL_QUICK)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(93)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_1, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_GUY_1, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            EVT_CALL(FallPartTo, ACTOR_SELF, PRT_GUY_1, LVar0, 54, 0, 24)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_1, SOUND_SHY_STACK_SQUISH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, 0, 0)
            EVT_WAIT(7)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_GUY_4, LVar0, LVar1, LVar2)
            EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_END_THREAD
    EVT_ELSE
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_4, 200, 0, 47)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_3, 200, 0, 47)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_2, 200, 0, 47)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_1, 200, 0, 47)
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, PRT_GUY_4, 55, 0, 47, FALSE)
            EVT_CALL(RunPartTo, ACTOR_SELF, PRT_GUY_4, 50, 0, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_4, ANIM_ShyGuy_Red_Anim07)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(31)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, PRT_GUY_3, 55, 0, 47, 36)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim09)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_GUY_3, 50, 18, 0, 20, TRUE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_3, SOUND_SHY_STACK_SQUISH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(77)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_3, ANIM_ShyGuy_Red_Anim0A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(62)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, PRT_GUY_2, 55, 0, 47, 36)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim09)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_GUY_2, 50, 36, 0, 20, TRUE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_2, SOUND_SHY_STACK_SQUISH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(108)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_2, ANIM_ShyGuy_Red_Anim0A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim04)
            EVT_WAIT(143)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim09)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim0A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(133)
            EVT_CALL(GetActorPos, ACTOR_GENERAL, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -3)
            EVT_CALL(SetPartPos, ACTOR_SELF, PRT_GUY_1, LVar0, LVar1, LVar2)
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim05)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_ADD(LVar0, -20)
            EVT_ADD(LVar1, 18)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_1, EVT_FLOAT(0.6))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_GUY_1, LVar0, LVar1, LVar2, 20, TRUE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_GUY_1, EVT_FLOAT(0.3))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_GUY_1, 50, 54, 0, 30, TRUE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_GUY_1, SOUND_SHY_STACK_SQUISH)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GUY_1, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim04)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, PRT_GUY_2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_3, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_2, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GUY_1, 0, 0, 0)
            EVT_WAIT(12)
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim03)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_GUY_4, LVar0, LVar1, LVar2)
            EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GUY_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_StiltPhase, AVAL_StiltPhase_Next)
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_SpinSmashLaunch))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, PRT_MAIN)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                            EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_WAIT(10)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_SpinSmashLaunch))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, PRT_MAIN)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                            EVT_EXEC_WAIT(EVS_Enemy_Hit)
                            EVT_WAIT(10)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_SpinSmashLaunch))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            EVT_ELSE
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(EVS_SpinSmashLaunch))
                            EVT_SET_CONST(LVar1, -1)
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_SpinSmashHit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_SpinSmashHit))
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_SpinSmashLaunch))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_SpinSmashLaunch))
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(N(EVS_SpinSmashDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetBattleFlags, LVar2)
            EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
                EVT_IF_EQ(LVar2, MOVE_SPOOK)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Idle, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Idle, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Idle, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar2)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar2)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinAround) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_SUB(LVar0, 30)
        EVT_IF_LT(LVar0, 0)
            EVT_ADD(LVar0, 360)
        EVT_END_IF
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinSmashHit) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_SpinSmashHit_Stack))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_SpinSmashHit_Stack))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_SpinSmashHit_Stack))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(N(EVS_SpinSmashHit_Top))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinSmashHit_Top) = {
    EVT_EXEC_GET_TID(N(EVS_SpinAround), LVarE)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, LVar0, LVarA)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(CreateCurrentPosTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_ALLOW_TARGET_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerID, LVar1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_IF_NE(LVar1, LVar0)
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_LABEL(1)
        EVT_ADD(LVarF, 1)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_EQ(LVar0, ITER_NO_MORE)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_CALL(GetActorFlags, LVar0, LVar1)
        EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
        EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    EVT_DIV(LVar3, 2)
    EVT_SET(LVar4, 70)
    EVT_SUB(LVar4, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar5, LVar4)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_LT(LVar5, 6)
        EVT_SET(LVar5, 1)
    EVT_ELSE
        EVT_SET(LVar5, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, LVar5, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    EVT_SUB(LVar4, 18)
    EVT_IF_LE(LVar4, LVar6)
        EVT_SET(LVar4, LVar6)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar7, LVar8)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_KILL_THREAD(LVarE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DetachMember) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim01)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim05)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim09)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim11)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim15)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1C)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ThreeStackAnims)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_1, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            EVT_CALL(SetActorStatusOffsets, ACTOR_SELF, 0, -20, 0, -20)
            EVT_CALL(SetPartSize, ACTOR_SELF, PRT_MAIN, 57, 30)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim02)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim06)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim0A)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim12)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim16)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1D)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(TwoStackAnims)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            EVT_CALL(SetActorStatusOffsets, ACTOR_SELF, 0, -40, 0, -40)
            EVT_CALL(SetPartSize, ACTOR_SELF, PRT_MAIN, 39, 30)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DefeatedCount, 3)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Still, ANIM_ShyStackGuy_Anim03)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Idle, ANIM_ShyStackGuy_Anim07)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_ShyStackGuy_Anim0B)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_ShyStackGuy_Anim13)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_ShyStackGuy_Anim17)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Attack, ANIM_ShyStackGuy_Anim1E)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(OneStackAnims)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_3, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_4, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STACK_4, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            EVT_CALL(SetActorStatusOffsets, ACTOR_SELF, 0, -60, 0, -60)
            EVT_CALL(SetPartSize, ACTOR_SELF, PRT_MAIN, 21, 30)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropStack) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 18)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar3, LVar1)
        EVT_WAIT(2)
        EVT_SUB(LVar3, 1)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(3)
        EVT_SUB(LVar3, 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(2)
        EVT_SUB(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 5)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 7)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar3, 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_STACK_SQUISH)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinSmashHit_Stack) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(N(PrintDebugValue), EVT_PTR("X"), LVar0)
    EVT_CALL(N(PrintDebugValue), EVT_PTR("Y"), LVar1)
    EVT_CALL(N(PrintDebugValue), EVT_PTR("Z"), LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_KNOCKOFF, ANIM_ShyStackDamage_Anim00)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, 0, 0, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_EXEC_WAIT(N(EVS_DetachMember))
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_EXEC_WAIT(N(EVS_DropStack))
    EVT_CALL(CreateCurrentPosTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_PRIMARY_ONLY | TARGET_FLAG_ALLOW_TARGET_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerID, LVar1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_IF_NE(LVar1, LVar0)
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_LABEL(1)
        EVT_ADD(LVarF, 1)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_CALL(N(PrintDebugValue), EVT_PTR("T"), LVar0)
        EVT_IF_EQ(LVar0, ITER_NO_MORE)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetOwnerTarget, LVar0, LVar9)
        EVT_CALL(GetActorFlags, LVar0, LVar1)
        EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetOwnerID, LVar0)
        EVT_CALL(N(PrintDebugValue), EVT_PTR("MYSELF ID"), LVar0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(N(PrintDebugValue), EVT_PTR("TARGET ID"), LVar0)
        EVT_CALL(N(PrintDebugValue), EVT_PTR("TARGET PARTS ID"), LVar1)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(0.1))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(7.0))
        EVT_CALL(N(PrintDebugValue), EVT_PTR("TX"), LVar0)
        EVT_CALL(N(PrintDebugValue), EVT_PTR("TY"), LVar1)
        EVT_CALL(N(PrintDebugValue), EVT_PTR("TZ"), LVar2)
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2, 0, TRUE)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
        EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    EVT_DIV(LVar3, 2)
    EVT_SET(LVar4, 70)
    EVT_SUB(LVar4, LVar3)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    EVT_SET(LVar5, LVar4)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_LT(LVar5, 6)
        EVT_SET(LVar5, 1)
    EVT_ELSE
        EVT_SET(LVar5, 0)
    EVT_END_IF
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar4, LVar1, LVar2, LVar5, TRUE)
    EVT_SUB(LVar4, 18)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(1.5))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(3.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar4, LVar1, LVar2, 12, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_KNOCKOFF, SOUND_ACTOR_DEATH)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, LVar0, 0, 0)
        EVT_ADD(LVar0, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinSmashLaunch) = {
    EVT_CALL(GetDamageSource, LVar0)
    EVT_IF_EQ(LVar0, DMG_SRC_FIRE_SHELL)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_KNOCKOFF, ANIM_ShyStackDamage_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_KNOCKOFF, ANIM_ShyStackDamage_Anim00)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(N(PrintDebugValue), EVT_PTR("X"), LVar0)
    EVT_CALL(N(PrintDebugValue), EVT_PTR("Y"), LVar1)
    EVT_CALL(N(PrintDebugValue), EVT_PTR("Z"), LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_DetachMember))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_EXEC_WAIT(N(EVS_DropStack))
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(30)
            EVT_ADD(LVar0, 24)
            EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_KNOCKOFF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_KNOCKOFF, LVar0)
    EVT_END_THREAD
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(3.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_KNOCKOFF, EVT_FLOAT(0.5))
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    EVT_DIV(LVar3, 2)
    EVT_SET(LVar4, 70)
    EVT_SUB(LVar4, LVar3)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    EVT_SET(LVar5, LVar4)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_LT(LVar5, 6)
        EVT_SET(LVar5, 1)
    EVT_ELSE
        EVT_SET(LVar5, 0)
    EVT_END_IF
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar4, LVar1, LVar2, LVar5, TRUE)
    EVT_SET(LVar1, 0)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2, 10, TRUE)
    EVT_WAIT(20)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_KNOCKOFF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_KNOCKOFF, SOUND_ACTOR_DEATH)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_KNOCKOFF, LVar0, 0, 0)
        EVT_ADD(LVar0, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_KNOCKOFF, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_DIV(LVar3, 2)
            EVT_ADD(LVar1, LVar3)
            EVT_ADD(LVar2, 5)
            EVT_DIVF(LVar3, EVT_FLOAT(10.0))
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Attack, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_WAIT(20)
    EVT_ADD(LVar0, 4)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_DRAW)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_FIRE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVar5, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar5, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 4)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 3)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 2)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShotsToFire, 1)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_SET(LVar1, LVar5)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefeatedCount, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_SET(LVar0, 0)
        EVT_EXEC(N(EVS_ShootRock))
    EVT_END_IF
    EVT_IF_LE(LVar0, 1)
        EVT_SET(LVar0, 1)
        EVT_EXEC(N(EVS_ShootRock))
    EVT_END_IF
    EVT_IF_LE(LVar0, 2)
        EVT_SET(LVar0, 2)
        EVT_EXEC(N(EVS_ShootRock))
    EVT_END_IF
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(EVS_ShootRock))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ShotsToFire, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_ONE, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_TWO, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(3)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_THREE, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(4)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT_FOUR, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_DEFAULT
            EVT_SWITCH(LVarF)
                EVT_CASE_EQ(HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(15)
            EVT_WAIT(15)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShootRock) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarF)
    EVT_IF_FLAG(LVarF, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 28)
                EVT_SET(LVar2, 9)
            EVT_CASE_EQ(1)
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 21)
                EVT_SET(LVar2, 8)
            EVT_CASE_EQ(2)
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 14)
                EVT_SET(LVar2, 7)
            EVT_CASE_DEFAULT
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 7)
                EVT_SET(LVar2, 6)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 72)
                EVT_SET(LVar2, 9)
            EVT_CASE_EQ(1)
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 54)
                EVT_SET(LVar2, 8)
            EVT_CASE_EQ(2)
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 36)
                EVT_SET(LVar2, 7)
            EVT_CASE_DEFAULT
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 18)
                EVT_SET(LVar2, 6)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVar2, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar2, ANIM_ShyStackRock_Anim00)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar2, EVT_FLOAT(12.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.0))
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 9, TRUE)
            EVT_SUB(LVar6, 100)
            EVT_CALL(RandInt, 40, LVar9)
            EVT_SUB(LVar6, LVar9)
            EVT_ADD(LVar7, LVar9)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(0.8))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 25, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CASE_EQ(1)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(2.2))
                EVT_CASE_EQ(1)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.8))
                EVT_CASE_EQ(2)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.4))
                EVT_CASE_DEFAULT
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.0))
            EVT_END_SWITCH
            EVT_SET(LVar7, 0)
            EVT_CALL(RandInt, 35, LVar9)
            EVT_ADD(LVar9, 30)
            EVT_SUB(LVar6, LVar9)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 9, TRUE)
            EVT_CALL(RandInt, 25, LVar9)
            EVT_ADD(LVar9, 45)
            EVT_SUB(LVar6, LVar9)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 8, TRUE)
            EVT_SUB(LVar6, 25)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 4, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_EXEC_WAIT(EVS_Enemy_DeathWithoutRemove)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    EVT_IF_GE(LVar0, AVAL_StackPhase_Defeated)
        EVT_CALL(FreezeBattleState, TRUE)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinSmashDeath) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVar2, 0)
    EVT_LOOP(24)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
        EVT_ADD(LVar2, 30)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_StackPhase, LVar0)
    EVT_IF_GE(LVar0, AVAL_StackPhase_Defeated)
        EVT_CALL(FreezeBattleState, TRUE)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
