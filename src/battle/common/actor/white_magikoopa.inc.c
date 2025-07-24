#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "sprite/npc/Magikoopa.h"

#define NAMESPACE A(white_magikoopa)

extern s32 N(IdleAnimations_80223D70)[];
extern s32 N(IdleAnimations_80223DBC)[];
extern s32 N(IdleAnimations_80223E08)[];
extern EvtScript N(EVS_Init_Ground);
extern EvtScript N(EVS_Init_Flying);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Flee);

enum N(ActorPartIDs) {
    PRT_GROUND      = 1,
    PRT_FLYING      = 2,
    PRT_BROOM       = 3,
};

enum N(ActorVars) {
    AVAR_ShouldKnockDown      = 0,
};

enum N(ActorParams) {
    DMG_MAGIC_BLAST     = 3,
    DMG_WAND_STRIKE     = 3,
    HEAL_AMT_ONE        = 5,
    HEAL_AMT_ALL        = 3,
};

s32 N(DefenseTable_80223B20)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DefenseTable_80223B2C)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable_Ground)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
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
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

s32 N(StatusTable_Flying)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             80,
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
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(GroundParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80223D70),
        .defenseTable = N(DefenseTable_80223B20),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

ActorPartBlueprint N(FlyingParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80223D70),
        .defenseTable = N(DefenseTable_80223B2C),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80223DBC),
        .defenseTable = N(DefenseTable_80223B2C),
        .eventFlags = ACTOR_EVENT_FLAG_RIDING_BROOMSTICK,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BROOM,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80223E08),
        .defenseTable = N(DefenseTable_80223B2C),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_WHITE_MAGIKOOPA,
    .level = ACTOR_LEVEL_WHITE_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(GroundParts)),
    .partsData = N(GroundParts),
    .initScript = &N(EVS_Init_Ground),
    .statusTable = N(StatusTable_Ground),
    .escapeChance = 40,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 32 },
};

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_WHITE_MAGIKOOPA,
    .level = ACTOR_LEVEL_FLYING_WHITE_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(FlyingParts)),
    .partsData = N(FlyingParts),
    .initScript = &N(EVS_Init_Flying),
    .statusTable = N(StatusTable_Flying),
    .escapeChance = 40,
    .airLiftChance = 95,
    .hurricaneChance = 75,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusTextOffset = { 1, 34 },
};

s32 N(IdleAnimations_80223D70)[] = {
    STATUS_KEY_NORMAL,    ANIM_Magikoopa_White_Anim01,
    STATUS_KEY_STONE,     ANIM_Magikoopa_White_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Magikoopa_White_Anim08,
    STATUS_KEY_POISON,    ANIM_Magikoopa_White_Anim01,
    STATUS_KEY_STOP,      ANIM_Magikoopa_White_Anim00,
    STATUS_KEY_STATIC,    ANIM_Magikoopa_White_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Magikoopa_White_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Magikoopa_White_Anim07,
    STATUS_KEY_FEAR,      ANIM_Magikoopa_White_Anim07,
    STATUS_END,
};

s32 N(IdleAnimations_80223DBC)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_White_Anim01,
    STATUS_KEY_STONE,     ANIM_FlyingMagikoopa_White_Anim00,
    STATUS_KEY_SLEEP,     ANIM_FlyingMagikoopa_White_Anim08,
    STATUS_KEY_POISON,    ANIM_FlyingMagikoopa_White_Anim01,
    STATUS_KEY_STOP,      ANIM_FlyingMagikoopa_White_Anim00,
    STATUS_KEY_STATIC,    ANIM_FlyingMagikoopa_White_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_FlyingMagikoopa_White_Anim00,
    STATUS_KEY_DIZZY,     ANIM_FlyingMagikoopa_White_Anim07,
    STATUS_KEY_FEAR,      ANIM_FlyingMagikoopa_White_Anim07,
    STATUS_END,
};

s32 N(IdleAnimations_80223E08)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_White_Anim0A,
    STATUS_END,
};

#include "common/ShrinkActor.inc.c"

#include "common/GetSelectedMoveID.inc.c"

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

#include "common/StartRumbleWithParams.inc.c"

#include "common/battle/CheckMagikoopaCastTarget.inc.c"

API_CALLABLE(N(GetBootsHammerLevel)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.bootsLevel);
    evt_set_variable(script, *args++, gPlayerData.hammerLevel);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetActorDefense)) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* part;
    s32 defense;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    part = get_actor_part(actor, partID);
    defense = lookup_defense(part->defenseTable, ELEMENT_NORMAL);

    evt_set_variable(script, *args++, defense);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent_Ground) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim05)
            SetConst(LVar2, ANIM_Magikoopa_White_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim05)
            SetConst(LVar2, ANIM_Magikoopa_White_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim06)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim04)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim02)
            ExecWait(N(EVS_Flee))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim02)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, 0, 2, 0)
                Else
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, -4, 5, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_GROUND)
            SetConst(LVar1, ANIM_Magikoopa_White_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_KnockDownCheck) = {
    Call(GetBattleFlags, LVar0)
    IfNotFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
        IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, true)
        EndIf
    Else
        Call(N(GetSelectedMoveID), LVar0)
        Switch(LVar0)
            CaseOrEq(MOVE_HEADBONK1)
            CaseOrEq(MOVE_HEADBONK2)
            CaseOrEq(MOVE_HEADBONK3)
            CaseOrEq(MOVE_MULTIBONK)
                Call(GetBattleFlags, LVar0)
                IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
                    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, true)
                EndIf
            EndCaseGroup
        EndSwitch
    EndIf
    Return
    End
};

EvtScript N(EVS_KnockDown) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, LVar0)
    IfEq(LVar0, 1)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim04)
        Goto(0)
    EndIf
    Call(GetLastElement, LVar0)
    IfFlag(LVar0, DAMAGE_TYPE_POW)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim04)
        Goto(0)
    EndIf
    Return
    Label(0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_BROOM, Float(0.4), Float(0.4), Float(0.4))
    EndIf
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 1)
    Call(SetPartPos, ACTOR_SELF, PRT_BROOM, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
    Call(N(StartRumbleWithParams), 150, 10)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.7))
    EndThread
    Call(GetLastEvent, ACTOR_SELF, LVar3)
    IfEq(LVar3, EVENT_15)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim04)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Add(LVar4, 10)
        Add(LVar5, 5)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, Float(1.0), 10, 0)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Loop(20)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, true)
        Wait(1)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, false)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim01)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, false)
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ground)))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_WHITE_MAGIKOOPA)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable_Ground)))
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 32)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, true)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(GetIndexFromPos, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HandleEvent_Flying) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Hit)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_FALL_TRIGGER)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_KnockDown))
        EndCaseGroup
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_15)
            ExecWait(N(EVS_KnockDownCheck))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim05)
            SetConst(LVar2, ANIM_FlyingMagikoopa_White_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_KnockDown))
        EndCaseGroup
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim05)
            SetConst(LVar2, ANIM_FlyingMagikoopa_White_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim06)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim01)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim01)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim04)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim02)
            ExecWait(N(EVS_Flee))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim02)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -3, 0, 0)
                Else
                    Call(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -15, 0, 0)
                EndIf
            EndIf
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_FlyingMagikoopa_White_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_MagicBlast) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 1)
    Else
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 10)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Sub(LVar0, 12)
        Add(LVar1, 14)
    Else
        Sub(LVar0, 30)
        Add(LVar1, 36)
    EndIf
    PlayEffect(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, Float(0.5), 30, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim02)
    Wait(30)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim03)
            Wait(5)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar9)
            IfFlag(LVar9, STATUS_FLAG_SHRINK)
                Sub(LVar0, 8)
                Add(LVar1, 8)
            Else
                Sub(LVar0, 20)
                Add(LVar1, 20)
            EndIf
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Sub(LVar3, 50)
            Set(LVar4, 0)
            Call(N(ShrinkActor), LVar0, LVar1, LVar5, LVar3, LVar4, LVar5, 25)
            Wait(50)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(14)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            Wait(30)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim03)
    Wait(5)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Sub(LVar0, 8)
        Add(LVar1, 8)
    Else
        Sub(LVar0, 20)
        Add(LVar1, 20)
    EndIf
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar3, 10)
    Call(N(ShrinkActor), LVar0, LVar1, LVar5, LVar3, LVar4, LVar5, 20)
    Wait(18)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MAGIC_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(19)
            Call(YieldTurn)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_WandStrike) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_VANISH)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim02)
        Set(LVar0, 200)
        Loop(20)
            Sub(LVar0, 10)
            Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, 5)
    Else
        Add(LVar0, 25)
    EndIf
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    Set(LVar0, 55)
    Loop(20)
        Add(LVar0, 10)
        Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
    Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim03)
    Wait(11)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_WAND_STRIKE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Set(LVar0, 200)
            Loop(20)
                Sub(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim01)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Set(LVar0, 55)
            Loop(20)
                Add(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_WAND_STRIKE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(10)
            Set(LVar0, 200)
            Loop(20)
                Sub(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim01)
            Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
            Set(LVar0, 55)
            Loop(20)
                Add(LVar0, 10)
                Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Flee) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(HideHealthBar, ACTOR_SELF)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    IfNe(LVar0, EVENT_SCARE_AWAY)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 15)
        Wait(15)
        Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Wait(10)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(YieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    ExecWait(EVS_ForceNextTarget)
    Call(HideHealthBar, ACTOR_SELF)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Init_Ground) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ground)))
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, false)
    Return
    End
};

EvtScript N(EVS_Init_Flying) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Flying)))
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, false)
    Return
    End
};

EvtScript N(EVS_Move_HealOne) = {
    #define LV_LowestActor  LVar8
    #define LV_LowestHP     LVar9
    // try to find a non-magikoopa actor in danger of being killed by the player
    Set(LV_LowestActor, 0)
    Set(LV_LowestHP, 9999)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorHP, LVar0, LVar2)
        Call(N(GetBootsHammerLevel), LVar3, LVar4)
        IfGt(LVar3, LVar4)
            Set(LVar3, LVar4)
        EndIf
        Call(N(GetActorDefense), LVar0, LVar1, LVar5)
        Call(GetActorDefenseBoost, LVar0, LVar6)
        Add(LVar5, LVar6)
        Sub(LVar3, LVar5)
        Sub(LVar2, LVar3)
        Call(N(CheckMagikoopaCastTarget), LVar0, LVarA)
        IfEq(LVarA, 0)
            Call(GetEnemyMaxHP, LVar0, LVarA)
            Call(GetActorHP, LVar0, LVarB)
            IfNe(LVarA, LVarB)
                IfLt(LVar2, LV_LowestHP)
                    Set(LV_LowestActor, LVar0)
                    Set(LV_LowestHP, LVar2)
                Else
                    IfEq(LVar2, LV_LowestHP)
                        IfLt(LVar0, LV_LowestActor)
                            Set(LV_LowestActor, LVar0)
                            Set(LV_LowestHP, LVar2)
                        EndIf
                    EndIf
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
        IfNe(LV_LowestActor, 0)
        Goto(100)
    EndIf
    // try to find any actor in danger of being killed by the player
    Set(LV_LowestActor, 0)
    Set(LV_LowestHP, 9999)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorHP, LVar0, LVar2)
        Call(N(GetBootsHammerLevel), LVar3, LVar4)
        IfGt(LVar3, LVar4)
            Set(LVar3, LVar4)
        EndIf
        Call(N(GetActorDefense), LVar0, LVar1, LVar5)
        Call(GetActorDefenseBoost, LVar0, LVar6)
        Add(LVar5, LVar6)
        Sub(LVar3, LVar5)
        Sub(LVar2, LVar4)
        Set(LFlag0, false)
        Call(GetOriginalActorType, LVar0, LVarA)
        IfEq(LVarA, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVarA)
            IfEq(LVarA, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        Call(GetOwnerID, LVarA)
        IfNe(LVarA, LVar0)
            IfEq(LFlag0, false)
                Call(GetEnemyMaxHP, LVar0, LVarA)
                Call(GetActorHP, LVar0, LVarB)
                IfNe(LVarA, LVarB)
                    IfLt(LVar2, LV_LowestHP)
                        Set(LV_LowestActor, LVar0)
                        Set(LV_LowestHP, LVar2)
                    Else
                        IfEq(LVar2, LV_LowestHP)
                            IfLt(LVar0, LV_LowestActor)
                                Set(LV_LowestActor, LVar0)
                                Set(LV_LowestHP, LVar2)
                            EndIf
                        EndIf
                    EndIf
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    IfNe(LV_LowestActor, 0)
        Goto(100)
    EndIf
    // try to find the actor with lowest HP%
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(2)
        Call(GetOwnerTarget, LVar0, LVar1)
        Set(LFlag0, false)
        Call(GetOriginalActorType, LVar0, LVarA)
        IfEq(LVarA, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVarA)
            IfEq(LVarA, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        Call(GetOwnerID, LVarA)
        IfNe(LVarA, LVar0)
            IfEq(LFlag0, false)
                Call(GetEnemyMaxHP, LVar0, LVarA)
                Call(GetActorHP, LVar0, LVarB)
                IfNe(LVarA, LVarB)
                    Set(LV_LowestActor, LVar0)
                    Goto(100)
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(2)
        EndIf
    Call(GetEnemyMaxHP, ACTOR_SELF, LVarA)
    Call(GetActorHP, ACTOR_SELF, LVarB)
    IfNe(LVarA, LVarB)
        Set(LV_LowestActor, ACTOR_SELF)
        Goto(100)
    EndIf
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(3)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOwnerID, LVarA)
        IfNe(LVarA, LVar0)
            Call(GetActorFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, ACTOR_FLAG_FLYING)
                ExecWait(N(EVS_Attack_MagicBlast))
            Else
                ExecWait(N(EVS_Attack_WandStrike))
            EndIf
            Return
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(3)
        EndIf
    ExecWait(N(EVS_Flee))
    Return
    Label(100)
    Call(RandInt, 1000, LVar0)
    IfGt(LVar0, 750)
        Call(GetActorFlags, ACTOR_SELF, LVar0)
        IfFlag(LVar0, ACTOR_FLAG_FLYING)
            ExecWait(N(EVS_Attack_MagicBlast))
        Else
            ExecWait(N(EVS_Attack_WandStrike))
        EndIf
        Return
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim02)
    EndIf
    Wait(5)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 6)
            Add(LVar1, 12)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 16)
            Add(LVar1, 31)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    EndIf
    Wait(30)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim01)
    EndIf
    Wait(5)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, LV_LowestActor, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, LV_LowestActor, SOUND_HEART_BOUNCE)
        Wait(30)
        Call(PlaySoundAtActor, LV_LowestActor, SOUND_STAR_BOUNCE_A)
    EndThread
    Thread
        Call(FreezeBattleState, true)
        Call(HealActor, LV_LowestActor, HEAL_AMT_ONE, false)
        Call(FreezeBattleState, false)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Move_HealAll) = {
    Call(RandInt, 1000, LVar0)
    IfGt(LVar0, 750)
        Call(GetActorFlags, ACTOR_SELF, LVar0)
        IfFlag(LVar0, ACTOR_FLAG_FLYING)
            ExecWait(N(EVS_Attack_MagicBlast))
        Else
            ExecWait(N(EVS_Attack_WandStrike))
        EndIf
        Return
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim02)
    EndIf
    Wait(5)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 6)
            Add(LVar1, 12)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 16)
            Add(LVar1, 31)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Sub(LVar0, 12)
            Add(LVar1, 14)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.12), 30, 0)
        Else
            Sub(LVar0, 30)
            Add(LVar1, 36)
            Sub(LVar2, 2)
            PlayEffect(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, Float(0.3), 30, 0)
        EndIf
    EndIf
    Wait(30)
    Call(GetActorFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, ACTOR_FLAG_FLYING)
        Call(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_White_Anim01)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_White_Anim01)
    EndIf
    Wait(5)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Set(LFlag0, false)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar1)
        IfEq(LVar1, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        IfEq(LFlag0, false)
            Thread
                Wait(5)
                Call(PlaySoundAtActor, LVar0, SOUND_RECOVER_HEART)
                Call(PlaySoundAtActor, LVar0, SOUND_HEART_BOUNCE)
                Wait(30)
                Call(PlaySoundAtActor, LVar0, SOUND_STAR_BOUNCE_A)
            EndThread
            Thread
                Call(FreezeBattleState, true)
                Call(HealActor, LVar0, HEAL_AMT_ALL, true)
                Call(FreezeBattleState, false)
            EndThread
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Call(WaitForBuffDone)
    Wait(1)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(10)
    Call(YieldTurn)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Flee))
        Return
    EndIf
    Set(LVarA, 0)
    Set(LVarB, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Set(LFlag0, false)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar1)
        IfEq(LVar1, ACTOR_TYPE_DRY_BONES)
            Call(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, true)
            EndIf
        EndIf
        IfEq(LFlag0, false)
            Call(GetActorHP, LVar0, LVar2)
            Call(GetEnemyMaxHP, LVar0, LVar3)
            IfNe(LVar2, LVar3)
                Add(LVarA, 1)
            EndIf
            Add(LVarB, 1)
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Mul(LVarA, 100)
    Div(LVarA, LVarB)
    Switch(LVarA)
        CaseGe(60)
            ExecWait(N(EVS_Move_HealAll))
        CaseEq(0)
            Call(GetActorFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, ACTOR_FLAG_FLYING)
                ExecWait(N(EVS_Attack_MagicBlast))
            Else
                ExecWait(N(EVS_Attack_WandStrike))
            EndIf
        CaseDefault
            ExecWait(N(EVS_Move_HealOne))
    EndSwitch
    Return
    End
};
