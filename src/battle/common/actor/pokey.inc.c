#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Pokey.h"

#define NAMESPACE A(pokey)

// while these parts seem set up to manage Pokeys changing size, its actually all handled via animations
// and the PRT_BODY* are always invisible
enum N(ActorPartIDs) {
    PRT_MAIN            = 1, // top part of a 4-part Pokey
    PRT_BODY3           = 2, // bottom part of a 4-part Pokey
    PRT_BODY2           = 3,
    PRT_BODY1           = 4,
    PRT_SINGLE          = 5, // single-part Pokey
    PRT_PROJECTILE      = 6, // part which is thrown
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
    AVAR_Generation         = 10, // Pokeys from the initial formation are generation 0, their summons are generation 1, and so on. generation 2 cannot summon.

    AVAL_Generation_First   = 0,
    AVAL_Generation_Second  = 1,
    AVAL_Generation_Last    = 2,
};

enum N(ActorParams) {
    DMG_SMASH_LARGE        = 2,
    DMG_SMASH_MEDIUM       = 2,
    DMG_SMASH_SMALL        = 2,
    DMG_THROW_PART         = 2, // throw a body part at the player
    DMG_LEAP               = 2, // jump onto the player, used when no more parts can be thrown
};

extern s32 N(FourPartAnims)[];
extern s32 N(ThrownPartAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_FindValidSummonPosition);
extern EvtScript N(EVS_SummonBackup);
extern EvtScript N(EVS_Attack_SinglePartLeap);
extern EvtScript N(EVS_Pokey_SpinSmashHit);
extern EvtScript N(EVS_DecrementSize);
extern EvtScript N(EVS_KnockPartAway);
extern EvtScript N(EVS_Pokey_Hit);
extern EvtScript N(EVS_Pokey_ScareAway);

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              90,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
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
        .idleAnimations = NULL,
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
        .idleAnimations = NULL,
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
        .idleAnimations = NULL,
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
        .idleAnimations = NULL,
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
    .type = ACTOR_TYPE_POKEY,
    .level = ACTOR_LEVEL_POKEY,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 70,
    .airLiftChance = 90,
    .hurricaneChance = 85,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 24, 80 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusTextOffset = { 10, 65 },
};

s32 N(FourPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Idle4,
    STATUS_KEY_STONE,     ANIM_Pokey_Still4,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Sleep4,
    STATUS_KEY_STOP,      ANIM_Pokey_Still4,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Still4,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Dizzy4,
    STATUS_KEY_FEAR,      ANIM_Pokey_Dizzy4,
    STATUS_END,
};

s32 N(ThreePartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Idle3,
    STATUS_KEY_STONE,     ANIM_Pokey_Still3,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Sleep3,
    STATUS_KEY_STOP,      ANIM_Pokey_Still3,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Still3,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Dizzy3,
    STATUS_KEY_FEAR,      ANIM_Pokey_Dizzy3,
    STATUS_END,
};

s32 N(TwoPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Idle2,
    STATUS_KEY_STONE,     ANIM_Pokey_Still2,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Sleep2,
    STATUS_KEY_STOP,      ANIM_Pokey_Still2,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Still2,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Dizzy2,
    STATUS_KEY_FEAR,      ANIM_Pokey_Dizzy2,
    STATUS_END,
};

s32 N(OnePartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Idle1,
    STATUS_KEY_STONE,     ANIM_Pokey_Still1,
    STATUS_KEY_SLEEP,     ANIM_Pokey_Sleep1,
    STATUS_KEY_STOP,      ANIM_Pokey_Still1,
    STATUS_KEY_PARALYZE,  ANIM_Pokey_Still1,
    STATUS_KEY_DIZZY,     ANIM_Pokey_Dizzy1,
    STATUS_KEY_FEAR,      ANIM_Pokey_Dizzy1,
    STATUS_END,
};

s32 N(ThrownPartAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Pokey_Projectile,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, AVAL_Generation_First)
    // copy input var from Formation
    Call(GetActorVar, ACTOR_SELF, AVAR_IN_CantSummon, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_CantSummon, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Idle4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Run4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Hurt4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Windup3)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Throw3)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_BurnHurt4)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_BurnStill4)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
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
            Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Set(LVar0, 0)
                    Set(LVar1, 77)
                    SetConst(LVar2, ANIM_Pokey_Dizzy4)
                CaseEq(1)
                    Set(LVar0, 0)
                    Set(LVar1, 59)
                    SetConst(LVar2, ANIM_Pokey_Dizzy3)
                CaseEq(2)
                    Set(LVar0, 0)
                    Set(LVar1, 41)
                    SetConst(LVar2, ANIM_Pokey_Dizzy2)
                CaseEq(3)
                    Set(LVar0, 0)
                    Set(LVar1, 23)
                    SetConst(LVar2, ANIM_Pokey_Dizzy1)
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
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_GroundSmash) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                Call(AddGoalPos, ACTOR_SELF, 60, 0, 0)
            Else
                Call(AddGoalPos, ACTOR_SELF, 24, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run4)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle4)
        CaseEq(1)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                Call(AddGoalPos, ACTOR_SELF, 40, 0, 0)
            Else
                Call(AddGoalPos, ACTOR_SELF, 16, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run3)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle3)
        CaseEq(2)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                Call(AddGoalPos, ACTOR_SELF, 20, 0, 0)
            Else
                Call(AddGoalPos, ACTOR_SELF, 8, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle2)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_SWAY)
    Call(MakeLerp, 0, -40, 20, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    ChildThread
        Wait(3)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_SMASH)
    EndChildThread
    Call(MakeLerp, -40, 90, 5, EASING_QUADRATIC_IN)
    Label(3)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(3)
        EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(MakeLerp, 90, 0, 5, EASING_LINEAR)
            Label(4)
                Call(UpdateLerp)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(4)
                EndIf
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(YieldTurn)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run4)
                    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle4)
                CaseEq(1)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run3)
                    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle3)
                CaseEq(2)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run2)
                    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle2)
            EndSwitch
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    // damage *could* depend on size of the Pokey, but all DMG values are the same, so it doesn't
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Set(LVar1, DMG_SMASH_LARGE)
        CaseEq(1)
            Set(LVar1, DMG_SMASH_MEDIUM)
        CaseDefault
            Set(LVar1, DMG_SMASH_SMALL)
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 0), LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MakeLerp, 90, 0, 10, EASING_LINEAR)
            Label(5)
                Call(UpdateLerp)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(5)
                EndIf
            Call(YieldTurn)
            Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run4)
                    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle4)
                CaseEq(1)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run3)
                    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle3)
                CaseEq(2)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run2)
                    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle2)
            EndSwitch
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

// (out) LVar9 : number of Pokey actors that aren't disabled, haven't thrown parts, and aren't last-generation
EvtScript N(EVS_CountSummonerPokeys) = {
    Set(LVar9, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        Switch(LVar2)
            CaseEq(ACTOR_TYPE_POKEY)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_SHRINK)
                    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar3)
                    IfEq(LVar3, 0)
                        Call(GetActorVar, LVar0, AVAR_Generation, LVar3)
                        IfNe(LVar3, AVAL_Generation_Last)
                            Add(LVar9, 1)
                        EndIf
                    EndIf
                EndIf
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    #define LBL_NO_SUMMON 123
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    IfEq(LVarA, 3)
        ExecWait(N(EVS_Attack_SinglePartLeap))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_CantSummon, LVar0)
    IfEq(LVar0, 0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
        IfEq(LVar0, AVAL_Generation_Last)
            Goto(LBL_NO_SUMMON)
        EndIf
        ExecWait(N(EVS_FindValidSummonPosition))
        IfEq(LVarE, -1)
            Goto(LBL_NO_SUMMON)
        EndIf
        ExecWait(N(EVS_CountSummonerPokeys))
        Switch(LVar9)
            CaseEq(1)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 400)
                    ExecWait(N(EVS_SummonBackup))
                    Return
                EndIf
            CaseEq(2)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 200)
                    ExecWait(N(EVS_SummonBackup))
                    Return
                EndIf
            CaseEq(3)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 100)
                    ExecWait(N(EVS_SummonBackup))
                    Return
                EndIf
        EndSwitch
    EndIf
    // try other moves
    Label(LBL_NO_SUMMON)
    Call(RandInt, 1000, LVar0)
    IfLt(LVar0, 500)
        ExecWait(N(EVS_Attack_GroundSmash))
        Return
    EndIf
    // throw a body part
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
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
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartPos, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2)
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(2.2))
        Call(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Projectile)
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
                Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, TRUE)
            CaseEq(1)
                IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
                    Add(LVar1, 20)
                Else
                    Add(LVar1, 8)
                    Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(1.2))
                EndIf
                Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, TRUE)
            CaseEq(2)
                IfNotFlag(LVar5, STATUS_FLAG_SHRINK)
                    Add(LVar1, 8)
                Else
                    Add(LVar1, 3)
                    Call(SetPartJumpGravity, ACTOR_SELF, PRT_PROJECTILE, Float(1.2))
                EndIf
                Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 15, TRUE)
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
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_THROW_PART, BS_FLAGS1_TRIGGER_EVENTS)
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
            Call(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Projectile)
            Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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
    Call(SetAnimation, ACTOR_SELF, PRT_PROJECTILE, ANIM_Pokey_Projectile)
    Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, TRUE)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 0), DMG_THROW_PART, BS_FLAGS1_TRIGGER_EVENTS)
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
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_FindValidSummonPosition) = {
    Set(LVarE, -1)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar0)
    IfNe(LVar0, 0)
        Return
    EndIf
    // check if each column is occupied
    Set(LFlag1, FALSE)
    Set(LFlag2, FALSE)
    Set(LFlag3, FALSE)
    Set(LFlag4, FALSE)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar5)
        Call(GetIndexFromHome, LVar0, LVar5)
        Mod(LVar5, 4)
        Switch(LVar5)
            CaseEq(0)
                Set(LFlag1, TRUE)
            CaseEq(1)
                Set(LFlag2, TRUE)
            CaseEq(2)
                Set(LFlag3, TRUE)
            CaseEq(3)
                Set(LFlag4, TRUE)
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    // only summon if space in front of the Pokey is available, and never if Pokey is in front position
    Call(GetIndexFromHome, ACTOR_SELF, LVar1)
    Switch(LVar1)
        CaseEq(BTL_POS_GROUND_A)
            Return // can't summon if Pokey is in front
        CaseEq(BTL_POS_GROUND_B)
            IfEq(LFlag1, FALSE)
                Set(LVarE, BTL_POS_GROUND_A)
            EndIf
        CaseEq(BTL_POS_GROUND_C)
            IfEq(LFlag2, FALSE)
                Set(LVarE, BTL_POS_GROUND_B)
            EndIf
        CaseEq(BTL_POS_GROUND_D)
            IfEq(LFlag3, FALSE)
                Set(LVarE, BTL_POS_GROUND_C)
            EndIf
    EndSwitch
    Return
    End
};

Vec3i N(SummonPos) = { 400, -100, 0 };

Formation N(SummonFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 100),
};

EvtScript N(EVS_SummonBackup) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle4)
    // lean back slightly
    Call(MakeLerp, 0, -20, 20, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    ChildThread
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_LEAN_FORWARD)
    EndChildThread
    // lean forward
    Call(MakeLerp, -20, 30, 20, EASING_COS_IN_OUT)
    Label(1)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    ChildThread
        Wait(6)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_LEAN_BACK)
    EndChildThread
    // lean back
    Call(MakeLerp, 30, -40, 20, EASING_COS_IN_OUT)
    Label(2)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    ChildThread
        Wait(4)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_REACH_DOWN)
    EndChildThread
    // smash into ground
    Call(MakeLerp, -40, 90, 10, EASING_COS_IN_OUT)
    Label(3)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(3)
        EndIf
    Wait(20)
    // create new Pokey actor
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POKEY_EMERGE_FROM_GROUND)
    Call(StartRumble, BTL_RUMBLE_PLAYER_HEAVY)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(1.0))
    EndThread
    Call(SummonEnemy, Ref(N(SummonFormation)), FALSE)
    Set(LVarB, LVar0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Sub(LVar1, 80)
    Call(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    ChildThread
        PlayEffect(EFFECT_SHOCKWAVE, 2, LVar0, 0, LVar2, 0)
        Call(UseIdleAnimation, LVarB, FALSE)
        Call(SetAnimation, LVarB, 1, ANIM_Pokey_Hurt4)
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, LVarB, Float(1.2))
        Call(SetGoalPos, LVarB, LVar0, 0, LVar2)
        Call(JumpToGoal, LVarB, 20, FALSE, TRUE, FALSE)
        Wait(20)
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Call(SetAnimation, LVarB, 1, ANIM_Pokey_Idle4)
        Call(SetHomePos, LVarB, LVar0, LVar1, LVar2)
        Call(HPBarToHome, LVarB)
        Call(UseIdleAnimation, LVarB, TRUE)
    EndChildThread
    // set generation of child to parent generation + 1
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar1)
    Switch(LVar1)
        CaseEq(AVAL_Generation_First)
            Call(SetActorVar, LVarB, AVAR_Generation, AVAL_Generation_Second)
        CaseEq(AVAL_Generation_Second)
            Call(SetActorVar, LVarB, AVAR_Generation, AVAL_Generation_Last)
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Set(LVarA, LVar0)
    // pull back and overshoot
    Call(MakeLerp, 90, -30, 7, EASING_QUADRATIC_OUT)
    Label(4)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(4)
        EndIf
    Wait(20)
    // correct overshoot
    Call(MakeLerp, -30, 0, 10, EASING_COS_IN_OUT)
    Label(5)
        Call(UpdateLerp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(5)
        EndIf
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle4)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_SinglePartLeap) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_POKEY_STEP, SOUND_POKEY_STEP)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_POKEY_STEP, SOUND_NONE)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run1)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle1)
    Wait(4)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(4)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run1)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_LEAP, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            Call(JumpToGoal, ACTOR_SELF, 22, FALSE, TRUE, FALSE)
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
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run1)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            ExecWait(EVS_Enemy_HopToPos)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle1)
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
    Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 0), DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle1)
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
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Sub(LVar0, 10)
            Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle1)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Run1)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            ExecWait(EVS_Enemy_HopToPos)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Pokey_Idle1)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
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

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

// set actor vars for new size one unit smaller than previous
EvtScript N(EVS_DecrementSize) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVarA)
    Switch(LVarA)
        CaseEq(0)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Idle3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Run3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Hurt3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Windup2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Throw2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_BurnHurt3)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_BurnStill3)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ThreePartAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY3, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY3, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 1)
            Call(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 62, EVT_IGNORE_ARG)
            Call(N(SetAbsoluteStatusOffsets), -15, 55, 10, 45)
        CaseEq(1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Idle2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Run2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Hurt2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Windup, ANIM_Pokey_Windup1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Throw, ANIM_Pokey_Throw1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_BurnHurt2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_BurnStill2)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(TwoPartAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
            Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, 2)
            Call(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 44, EVT_IGNORE_ARG)
            Call(N(SetAbsoluteStatusOffsets), -15, 35, 10, 25)
        CaseEq(2)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Immune, ANIM_Pokey_Idle1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Run, ANIM_Pokey_Run1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hit, ANIM_Pokey_Hurt1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnHurt, ANIM_Pokey_BurnHurt1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_BurnStill, ANIM_Pokey_BurnStill1)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(OnePartAnims)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BODY1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SINGLE, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SINGLE, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
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
    Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
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
        Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 0, TRUE)
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
    Call(JumpPartTo, ACTOR_SELF, PRT_PROJECTILE, 296, 0, 0, 0, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_PROJECTILE, Float(6.0))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 30)
        Set(LVar1, 0)
        Call(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 10, 18, EASING_LINEAR)
        Add(LVar0, 20)
        Call(FlyPartTo, ACTOR_SELF, PRT_PROJECTILE, LVar0, LVar1, LVar2, 8, 10, EASING_LINEAR)
        Loop(20)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Wait(1)
        EndLoop
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_NO_TARGET, TRUE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_PROJECTILE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Wait(20)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(FallToGoal, ACTOR_SELF, 10)
    Wait(20)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Wait(5)
    Call(SetActorVar, ACTOR_SELF, AVAR_PartsThrown, LVar2)
    Switch(LVar2)
        CaseEq(0)
            Set(LVar2, 96)
            Set(LVar6, 4)
        CaseEq(1)
            Set(LVar2, 72)
            Set(LVar6, 3)
        CaseEq(2)
            Set(LVar2, 48)
            Set(LVar6, 2)
        CaseDefault
            Set(LVar2, 24)
            Set(LVar6, 1)
    EndSwitch
    ChildThread
        Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
        Loop(LVar6)
            PlayEffect(EFFECT_SHOCKWAVE, 2, LVarA, 0, LVarC, 0)
            Wait(10)
        EndLoop
    EndChildThread
    Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar4, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    Wait(8)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
