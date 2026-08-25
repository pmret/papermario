#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Pokey.h"

#define NAMESPACE A(pokey_mummy)

extern s32 N(FourPartAnims)[];
extern s32 N(ThrownPartAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_KnockPartAway);
extern EvtScript N(EVS_Attack_SinglePartLeap);
extern EvtScript N(EVS_Pokey_SpinSmashHit);
extern EvtScript N(EVS_DecrementSize);
extern EvtScript N(EVS_Pokey_Hit);
extern EvtScript N(EVS_Pokey_ScareAway);

// while these parts seem set up to manage Pokeys changing size, its actually all handled via animations
// and the PRT_BODY* are always invisible
enum N(ActorPartIDs) {
    PRT_MAIN        = 1, // top part of a 4-part Pokey
    PRT_BODY3       = 2, // bottom part of a 4-part Pokey
    PRT_BODY2       = 3,
    PRT_BODY1       = 4,
    PRT_SINGLE      = 5, // single-part Pokey
    PRT_PROJECTILE  = 6, // part which is thrown
};

enum N(ActorVars) {
    AVAR_IN_CantSummon      = 1,
    AVAR_PartsThrown        = 0,
    AVAR_Anim_Immune        = 1,
    AVAR_Anim_Run           = 2,
    AVAR_Anim_Hit           = 3,
    AVAR_Anim_Windup        = 4,
    AVAR_Anim_Throw         = 5,
    AVAR_Anim_BurnHurt      = 6,
    AVAR_Anim_BurnStill     = 7,
    AVAR_CantSummon         = 9,
    AVAR_Generation         = 10,

    AVAL_Generation_First   = 0,
    AVAL_Generation_Second  = 1,
    AVAL_Generation_Last    = 2,
};

enum N(ActorParams) {
    DMG_THROW_PART         = 2, // throw a body part at the player
    DMG_LEAP               = 2, // jump onto the player, used when no more parts can be thrown
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_UNUSED,         0,
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
        .idleAnimations = N(FourPartAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_BODY3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 72 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BODY2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 54 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_BODY1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 36 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_SINGLE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_PROJECTILE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(ThrownPartAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_ALT_SPIKY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_POKEY_MUMMY,
    .level = ACTOR_LEVEL_POKEY_MUMMY,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 90,
    .hurricaneChance = 85,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 24, 80 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusTextOffset = { 10, 65 },
};

s32 N(FourPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle4,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still4,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep4,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still4,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still4,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy4,
    STATUS_KEY_UNUSED,    ANIM_Pokey_Mummy_Dizzy4,
    STATUS_END,
};

s32 N(ThreePartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle3,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still3,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep3,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still3,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still3,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy3,
    STATUS_KEY_UNUSED,    ANIM_Pokey_Mummy_Dizzy3,
    STATUS_END,
};

s32 N(TwoPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle2,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still2,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep2,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still2,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still2,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy2,
    STATUS_KEY_UNUSED,    ANIM_Pokey_Mummy_Dizzy2,
    STATUS_END,
};

s32 N(OnePartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Idle1,
    STATUS_KEY_STONE,     ANIM_Pokey_Mummy_Still1,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Mummy_Sleep1,
    STATUS_KEY_STOP,      ANIM_Pokey_Mummy_Still1,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Mummy_Still1,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Mummy_Dizzy1,
    STATUS_KEY_UNUSED,    ANIM_Pokey_Mummy_Dizzy1,
    STATUS_END,
};

s32 N(ThrownPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Mummy_Projectile,
    STATUS_END,
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, AVAL_Generation_First)
    // copy input var from Formation
    Call(GetActorVar, ACTOR_SELF, AVAR_IN_CantSummon, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_CantSummon, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Mummy_Windup3)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Mummy_Throw3)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill4)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                IfEq(LVarA, 3)
                    SetConst(LVar0, PRT_MAIN)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                    ExecWait(EVS_Enemy_Hit)
                Else
                    Call(GetDamageSource, LVar0)
                    Switch(LVar0)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_Pokey_Hit))
                        EndCaseGroup
                        CaseDefault
                            SetConst(LVar0, PRT_MAIN)
                            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                            ExecWait(EVS_Enemy_Hit)
                    EndSwitch
                EndIf
            EndIf
        CaseEq(EVENT_DEATH)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
            Else
                Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                IfEq(LVarA, 3)
                    SetConst(LVar0, PRT_MAIN)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                    ExecWait(EVS_Enemy_Hit)
                    Wait(10)
                Else
                    Call(GetDamageSource, LVar0)
                    Switch(LVar0)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_Pokey_Hit))
                        EndCaseGroup
                        CaseDefault
                            SetConst(LVar0, PRT_MAIN)
                            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                            ExecWait(EVS_Enemy_Hit)
                            Wait(10)
                    EndSwitch
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            SetConst(LVar0, PRT_MAIN)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                IfEq(LVarA, 3)
                    ExecWait(EVS_Enemy_BurnHit)
                Else
                    Call(GetDamageSource, LVarA)
                    Switch(LVarA)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_Pokey_Hit))
                        EndCaseGroup
                        CaseDefault
                            ExecWait(EVS_Enemy_BurnHit)
                    EndSwitch
                EndIf
            EndIf
        CaseOrEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar2)
            SetConst(LVar0, PRT_MAIN)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
                IfEq(LVarA, 3)
                    ExecWait(EVS_Enemy_BurnHit)
                Else
                    Call(GetDamageSource, LVarA)
                    Switch(LVarA)
                        CaseOrEq(DMG_SRC_SHELL_TOSS)
                        CaseOrEq(DMG_SRC_POWER_SHELL)
                        CaseOrEq(DMG_SRC_FIRE_SHELL)
                            ExecWait(N(EVS_Pokey_Hit))
                        EndCaseGroup
                        CaseDefault
                            ExecWait(EVS_Enemy_BurnHit)
                    EndSwitch
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_Pokey_SpinSmashHit))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(N(EVS_Pokey_SpinSmashHit))
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_LAUNCH_HIT)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                ExecWait(N(EVS_Pokey_Hit))
            EndIf
        CaseEq(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                ExecWait(N(EVS_Pokey_Hit))
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, -1)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            ExecWait(EVS_Enemy_ShockHit)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Run, LVar1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            ExecWait(EVS_Enemy_HopToPos)
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Immune, LVar1)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
            Call(GetBattleFlags, LVar0)
            IfNotFlag(LVar0, BS_FLAGS1_PARTNER_ACTING)
                Call(AfflictActor, ACTOR_PLAYER, STATUS_KEY_POISON, 3)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Set(LVar0, 0)
                    Set(LVar1, 77)
                    SetConst(LVar2, ANIM_Pokey_Mummy_Dizzy4)
                CaseEq(1)
                    Set(LVar0, 0)
                    Set(LVar1, 59)
                    SetConst(LVar2, ANIM_Pokey_Mummy_Dizzy3)
                CaseEq(2)
                    Set(LVar0, 0)
                    Set(LVar1, 41)
                    SetConst(LVar2, ANIM_Pokey_Mummy_Dizzy2)
                CaseEq(3)
                    Set(LVar0, 0)
                    Set(LVar1, 23)
                    SetConst(LVar2, ANIM_Pokey_Mummy_Dizzy1)
            EndSwitch
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfNotFlag(LVar3, STATUS_FLAG_SLEEP)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar2)
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            Call(GetStatusFlags, ACTOR_SELF, LVar6)
            IfFlag(LVar6, STATUS_FLAG_SHRINK)
                MulF(LVar0, Float(0.4))
                MulF(LVar1, Float(0.4))
            EndIf
            AddF(LVar3, LVar0)
            AddF(LVar4, LVar1)
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar3, LVar4, LVar5, 20, 0)
            Wait(30)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Immune, LVar1)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            ExecWait(N(EVS_Pokey_ScareAway))
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    IfEq(LVarA, 3)
        ExecWait(N(EVS_Attack_SinglePartLeap))
        Return
    EndIf
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 1)
    EndIf
    Call(SetPartSounds, ACTOR_SELF, PRT_PROJECTILE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, Float(1.0), Float(1.0), Float(1.0))
    Else
        Call(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, Float(0.4), Float(0.4), Float(1.0))
    EndIf
    ChildThread
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, false)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartPos, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2)
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(2.2))
        Call(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Mummy_Projectile)
        Call(GetStatusFlags, ACTOR_SELF, LVar5)
        Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
        Switch(LVarA)
            CaseEq(0)
                IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
                    Add(LVar1, 38)
                Else
                    Add(LVar1, 15)
                    Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(1.2))
                EndIf
                Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, true)
            CaseEq(1)
                IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
                    Add(LVar1, 20)
                Else
                    Add(LVar1, 8)
                    Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(1.2))
                EndIf
                Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, true)
            CaseEq(2)
                IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
                    Add(LVar1, 8)
                Else
                    Add(LVar1, 3)
                    Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(1.2))
                EndIf
                Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, true)
            CaseEq(3)
        EndSwitch
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_SWAY)
    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Windup, LVar1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    Wait(12)
    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Throw, LVar1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    Wait(1)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_THROW)
    Wait(3)
    ExecWait(N(EVS_DecrementSize))
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            IfEq(LVar0, HIT_RESULT_LUCKY)
                ChildThread
                    Wait(5)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndChildThread
            EndIf
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 80)
            Sub(LVar1, 5)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(20.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(0.1))
            Call(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Mummy_Projectile)
            Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Run, LVar1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(20.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(0.1))
    Call(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Mummy_Projectile)
    Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, true)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 40), DMG_THROW_PART, BS_FLAGS1_TRIGGER_EVENTS)
    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Run, LVar1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 55)
            Set(LVar1, 0)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(6.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(4.0))
            Sub(LVar0, 24)
            Call(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(3.0))
            Sub(LVar0, 20)
            Call(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, 20, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, true)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_SinglePartLeap) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_POKEY_STEP, SOUND_POKEY_STEP)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_POKEY_STEP, SOUND_NONE)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
    Wait(4)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(4)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 5)
            Set(LVar1, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.1))
            ChildThread
                Wait(2)
                Set(LVar0, 0)
                Loop(5)
                    Add(LVar0, 30)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndChildThread
            Call(JumpToGoal, ACTOR_SELF, 22, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
            ChildThread
                Wait(2)
                Set(LVar0, 180)
                Loop(6)
                    Add(LVar0, 30)
                    IfEq(LVar0, 360)
                        Set(LVar0, 0)
                    EndIf
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EndChildThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            ExecWait(EVS_Enemy_HopToPos)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.1))
    ChildThread
        Wait(2)
        Set(LVar0, 0)
        Loop(5)
            Add(LVar0, 30)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndChildThread
    Call(JumpToGoal, ACTOR_SELF, 18, false, true, false)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Sub(LVar0, 10)
            Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Run1)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            ExecWait(EVS_Enemy_HopToPos)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Mummy_Idle1)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Pokey_SpinSmashHit) = {
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        SetConst(LVar0, PRT_MAIN)
        Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
        ExecWait(EVS_Enemy_SpinSmashHit)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    Switch(LVarA)
        CaseEq(0)
            ExecWait(N(EVS_KnockPartAway))
        CaseEq(1)
            ExecWait(N(EVS_KnockPartAway))
        CaseEq(2)
            ExecWait(N(EVS_KnockPartAway))
        CaseEq(3)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
            ExecWait(EVS_Enemy_SpinSmashHit)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_DecrementSize) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    Switch(LVarA)
        CaseEq(0)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Mummy_Windup2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Mummy_Throw2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill3)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ThreePartAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY3, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY3, ACTOR_PART_FLAG_NO_TARGET, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_NO_TARGET, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
            Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 1)
            Call(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 62, EVT_IGNORE_ARG)
            Call(N(SetAbsoluteStatusOffsets), -15, 55, 10, 45)
        CaseEq(1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Mummy_Windup1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Mummy_Throw1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill2)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(TwoPartAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_NO_TARGET, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_NO_TARGET, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
            Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 2)
            Call(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 44, EVT_IGNORE_ARG)
            Call(N(SetAbsoluteStatusOffsets), -15, 35, 10, 25)
        CaseEq(2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Mummy_Idle1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Mummy_Run1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Mummy_Hurt1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_Mummy_BurnHurt1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_Mummy_BurnStill1)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(OnePartAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_NO_TARGET, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SINGLE, ACTOR_PART_FLAG_NO_TARGET, false)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SINGLE, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
            Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 3)
            Call(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 26, EVT_IGNORE_ARG)
            Call(N(SetAbsoluteStatusOffsets), -15, 15, 10, 5)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HitReactionBounce) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 18)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
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
    Return
    End
};

EvtScript N(EVS_KnockPartAway) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, Float(1.0), Float(1.0), Float(1.0))
    Else
        Call(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, Float(0.4), Float(0.4), Float(1.0))
    EndIf
    ExecWait(N(EVS_DecrementSize))
    SetConst(LVar0, PRT_MAIN)
    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    ChildThread
        Wait(4)
        ExecWait(N(EVS_HitReactionBounce))
    EndChildThread
    Call(CreateHomeTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_PRIMARY_ONLY | TARGET_FLAG_ALLOW_TARGET_ONLY)
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
        Call(GetOwnerID, LVar0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(0.1))
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(7.0))
        Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, true)
        ChildThread
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        EndChildThread
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
        Goto(1)
    Label(10)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(0.1))
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(6.0))
    Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, 296, 0, 0, 0, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_NO_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, true)
    Return
    End
};

EvtScript N(EVS_Pokey_Hit) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, Float(1.0), Float(1.0), Float(1.0))
    Else
        Call(SetPartScale, ACTOR_SELF, PRT_PROJECTILE, Float(0.4), Float(0.4), Float(1.0))
    EndIf
    ExecWait(N(EVS_DecrementSize))
    SetConst(LVar0, PRT_MAIN)
    Call(GetLastEvent, ACTOR_SELF, LVar1)
    Switch(LVar1)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_BURN_DEATH)
            Call(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_BurnedProjectile)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, LVar1)
        EndCaseGroup
        CaseDefault
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    ChildThread
        Wait(4)
        ExecWait(N(EVS_HitReactionBounce))
    EndChildThread
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    IfNe(LVarA, 3)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartPos, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, false)
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(6.0))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 30)
        Set(LVar1, 0)
        Call(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 10, 18, EASING_LINEAR)
        Add(LVar0, 20)
        Call(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 8, 10, EASING_LINEAR)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, true)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, false)
            Wait(1)
        EndLoop
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_NO_TARGET, true)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, true)
    Else
        Wait(30)
    EndIf
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            Div(LVar3, 2)
            Add(LVar1, LVar3)
            Add(LVar2, 5)
            DivF(LVar3, Float(10.0))
            PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, LVar1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            Wait(10)
        CaseDefault
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Pokey_ScareAway) = {
    SetConst(LVar0, PRT_MAIN)
    Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hit, LVar1)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(GetActorFlags, ACTOR_SELF, LVar9)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.05))
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Set(LVarD, LVarB)
    Add(LVarD, 40)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarD, LVarC)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Wait(20)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(FallToGoal, ACTOR_SELF, 10)
    Wait(20)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Wait(5)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalPos, ACTOR_SELF, 200, 0, 0)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Wait(8)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
