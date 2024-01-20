#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/SpikedParaJrTroopa.h"
#include "sprite/npc/MageJrTroopa.h"

#define NAMESPACE A(final_jr_troopa)

// Invalid value used in some scripts here == -91,999,590
// The closest evt variable for this is MapFlag(-1999590), which is way out of range.
// Looks like it was supposed to be a value for Float(), but its likewise out of range.
#define INVALID_VAR 0xFA84329A

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

extern EvtScript N(EVS_GetFormAnims);
extern EvtScript N(EVS_TryFearReaction);
extern EvtScript N(EVS_JrTroopa_Death);
extern EvtScript N(EVS_ReturnHome);

extern EvtScript N(EVS_Transform_Flying);
extern EvtScript N(EVS_Transform_Mage);
extern EvtScript N(EVS_Attack_Leap);
extern EvtScript N(EVS_Attack_Swoop);
extern EvtScript N(EVS_Attack_SpikeDive);
extern EvtScript N(EVS_Attack_MagicSpell);
extern EvtScript N(EVS_Attack_LightningBolt);
extern EvtScript N(EVS_Move_HealSelf);

API_CALLABLE(N(CalculateArcsinDeg));

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

enum N(ActorPartIDs) {
    PRT_BASE        = 1,
    PRT_FLYING      = 2,
    PRT_MAGE        = 3,
};

enum N(ActorVars) {
    AVAR_UnusedBrag         = 0,
    AVAR_SpookReact         = 1,
    AVAL_SpookReact_None    = 0,
    AVAL_SpookReact_Ready   = 1,
    AVAR_DialogueFlags      = 2,
    AVAL_Dialogue_Begin     = 1,
    AVAL_Dialogue_LowHP     = 2,
    AVAR_Form               = 3,
    AVAL_Form_Base          = 1,
    AVAL_Form_Flying        = 2,
    AVAL_Form_Mage          = 3,
    AVAR_HealsLeft          = 4,
};

enum N(ActorParams) {
    DMG_LEAP        = 8,
    DMG_SWOOP       = 8,
    DMG_SPIKE_DIVE  = 9,
    DMG_SPELL       = 8,
    DMG_LIGHTNING   = 9,
};

// keys for getting form-specific anim sets
enum {
    FORM_ANIM_HURT      = 0,
    FORM_ANIM_BURN      = 1,
    FORM_ANIM_FLAIL     = 2,
    FORM_ANIM_TALK      = 3,
    FORM_ANIM_RETURN    = 4,
    FORM_ANIM_IMMUNE    = 5,
};

s32 N(BaseAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpikedParaJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_SpikedParaJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_SpikedParaJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_SpikedParaJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(MageAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MageJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_MageJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_MageJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_MageJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(BaseDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_END,
};

s32 N(FlyingDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_END,
};

s32 N(MageDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_END,
};

s32 N(BaseStatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               60,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -2,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
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

s32 N(MageStatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              40,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -2,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_BASE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 26 },
        .opacity = 255,
        .idleAnimations = N(BaseAnims),
        .defenseTable = N(BaseDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -6 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 32 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -11 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAGE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 28 },
        .opacity = 255,
        .idleAnimations = N(MageAnims),
        .defenseTable = N(MageDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA_6,
    .level = ACTOR_LEVEL_JR_TROOPA_6,
    .maxHP = 60,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(BaseStatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 35 },
    .statusTextOffset = { 10, 25 },
};

EvtScript N(EVS_SetupFearReaction) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar2)
    IfFlag(LVar2, STATUS_FLAGS_IMMOBILIZED)
        Return
    EndIf
    Call(GetBattleFlags, LVar2)
    IfFlag(LVar2, BS_FLAGS1_PARTNER_ACTING)
        Call(GetMenuSelection, LVar0, LVar1, LVar2)
        IfEq(LVar2, MOVE_SPOOK)
            Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_Ready)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_EMOTE_QUESTION)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 30)
            Call(ShowEmote, 0, EMOTE_QUESTION, -45, 30, EMOTER_POS, LVar0, LVar1, LVar2, 5)
            Wait(30)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_TransformFX) = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 16)
    Else
        Add(LVar1, 6)
    EndIf
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
    Thread
        Set(LVar0, 0)
        Loop(32)
            Wait(1)
            Add(LVar0, 45)
            Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EndLoop
    EndThread
    Wait(32)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_NEW_POWER)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 40, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 4, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 4, 0)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnJrTroopa) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_07)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamOffsetZ, 38)
    Call(SetBattleCamZoom, 256)
    Call(MoveBattleCamOver, 15)
    Return
    End
};

EvtScript N(EVS_Cam_ResetFocus) = {
    Call(EnableBattleStatusBar, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 12)
    Return
    End
};

EvtScript N(EVS_Cam_FocusOnGoompa) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_55)
    Call(MoveBattleCamOver, 30)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Return
    End
};

s32 N(BaseDefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

EvtScript N(EVS_JrTroopa_BaseDeath) = {
    Set(LVarA, LVar0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetAnimation, ACTOR_SELF, LVarA, LVar1)
    Wait(10)
    Call(GetDamageSource, LVar5)
    Switch(LVar5)
        CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_SPIN_SMASH)
        EndCaseGroup
        CaseDefault
            Set(LVar2, 0)
            Loop(24)
                Call(SetActorYaw, ACTOR_SELF, LVar2)
                Add(LVar2, 30)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_SELF, 0)
    EndSwitch
    Label(0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Add(LVar2, 10)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Call(PlaySound, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(SetBattleCamZoom, 260)
    Call(SetBattleCamOffsetZ, 15)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    Call(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Collapse)
    Wait(12)
    Call(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Defeated)
    Call(SetIdleAnimations, ACTOR_SELF, LVarA, Ref(N(BaseDefeatedAnims)))
    Wait(60)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_UnusedBrag, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_DialogueFlags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
    Call(SetActorVar, ACTOR_SELF, AVAR_Form, AVAL_Form_Base)
    Call(SetActorVar, ACTOR_SELF, AVAR_HealsLeft, 5)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_Form_Flying)
                Call(GetStatusFlags, ACTOR_SELF, LVarA)
                IfFlag(LVarA, STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
                    Call(SetTargetOffset, ACTOR_SELF, PRT_FLYING, -15, 28)
                    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_FLYING, 4, -6)
                    Call(N(SetAbsoluteStatusOffsets), -25, 27, -1, 27)
                Else
                    Call(SetTargetOffset, ACTOR_SELF, PRT_FLYING, -8, 33)
                    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_FLYING, 0, -6)
                    Call(N(SetAbsoluteStatusOffsets), -22, 30, 2, 28)
                EndIf
            CaseDefault
                Call(N(SetAbsoluteStatusOffsets), -20, 35, 10, 25)
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVarA)
    Switch(LVarA)
        CaseEq(EVENT_HIT_COMBO)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_SetupFearReaction))
            ExecWait(N(EVS_TryFearReaction))
        CaseEq(EVENT_DEATH)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar1, FORM_ANIM_BURN)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar1, FORM_ANIM_BURN)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            Call(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_ShockHit)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            Call(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_ShockHit)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_JrTroopa_Death))
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            Set(LVar1, FORM_ANIM_IMMUNE)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            Set(LVar1, FORM_ANIM_IMMUNE)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_NoDamageHit)
            ExecWait(N(EVS_SetupFearReaction))
            ExecWait(N(EVS_TryFearReaction))
        CaseEq(EVENT_SPIKE_TAUNT)
            Wait(10)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            Switch(LVar3)
                CaseFlag(STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
                    Add(LVar0, -13)
                    Add(LVar1, 37)
                CaseFlag(STATUS_FLAG_SHRINK)
                    Add(LVar0, -1)
                    Add(LVar1, 14)
                CaseDefault
                    Add(LVar0, -4)
                    Add(LVar1, 37)
            EndSwitch
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            Wait(20)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Set(LVar1, FORM_ANIM_FLAIL)
                ExecWait(N(EVS_GetFormAnims))
                Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                Wait(1000)
            EndIf
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Set(LVar1, FORM_ANIM_IMMUNE)
                ExecWait(N(EVS_GetFormAnims))
                Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                Wait(20)
                ExecWait(N(EVS_Cam_FocusOnJrTroopa))
                Set(LVar1, FORM_ANIM_TALK)
                ExecWait(N(EVS_GetFormAnims))
                Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                Call(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, LVar0, -1, -1)
                ExecWait(N(EVS_Cam_ResetFocus))
            EndIf
        CaseEq(EVENT_SPIKE_CONTACT)
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_BASE)
            SetConst(LVar1, ANIM_JrTroopa_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    IfNe(LVar0, AVAL_Form_Mage)
        Call(GetActorHP, ACTOR_SELF, LVar1)
        Call(GetEnemyMaxHP, ACTOR_SELF, LVar2)
        Mul(LVar1, 100)
        Div(LVar1, LVar2)
        IfEq(LVar0, AVAL_Form_Base)
            IfLt(LVar1, 65)
                ExecWait(N(EVS_Transform_Flying))
            EndIf
        Else
            IfLt(LVar1, 35)
                ExecWait(N(EVS_Transform_Mage))
            EndIf
        EndIf
    EndIf
    Call(GetActorHP, ACTOR_SELF, LVar0)
    IfLt(LVar0, 15)
        Call(GetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
        IfNotFlag(LVar0, AVAL_Dialogue_LowHP)
            BitwiseOrConst(LVar0, AVAL_Dialogue_LowHP)
            Call(SetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(MoveBattleCamOver, 20)
            Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Form_Flying)
                    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Talk)
                CaseEq(AVAL_Form_Mage)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Talk)
                CaseDefault
                    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Talk)
            EndSwitch
            Call(ActorSpeak, MSG_CH8_0060, ACTOR_SELF, PRT_BASE, -1, -1)
        EndIf
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Form_Flying)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 50)
                ExecWait(N(EVS_Attack_Swoop))
            Else
                ExecWait(N(EVS_Attack_SpikeDive))
            EndIf
        CaseEq(AVAL_Form_Mage)
            Call(RandInt, 100, LVar0)
            Switch(LVar0)
                CaseLt(60)
                    ExecWait(N(EVS_Attack_MagicSpell))
                CaseLt(80)
                    ExecWait(N(EVS_Attack_LightningBolt))
                CaseDefault
                    Call(GetActorHP, ACTOR_SELF, LVar0)
                    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
                    IfNe(LVar0, LVar1)
                        Call(GetActorVar, ACTOR_SELF, AVAR_HealsLeft, LVar2)
                        IfGt(LVar2, 0)
                            Sub(LVar2, 1)
                            Call(SetActorVar, ACTOR_SELF, AVAR_HealsLeft, LVar2)
                            ExecWait(N(EVS_Move_HealSelf))
                        Else
                            ExecWait(N(EVS_Attack_MagicSpell))
                        EndIf
                    Else
                        ExecWait(N(EVS_Attack_MagicSpell))
                    EndIf
            EndSwitch
        CaseDefault
            ExecWait(N(EVS_Attack_Leap))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Transform_Flying) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(ActorSpeak, MSG_CH8_005E, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_TiredTalk)
    ExecWait(N(EVS_TransformFX))
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    Wait(10)
    Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 20, 60, 0)
    Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_LINEAR)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetActorVar, ACTOR_SELF, AVAR_Form, AVAL_Form_Flying)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(FlyingStatusTable)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
    Return
    End
};

EvtScript N(EVS_Transform_Mage) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(ActorSpeak, MSG_CH8_005F, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Talk, ANIM_SpikedParaJrTroopa_Talk)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 120)
    ExecWait(N(EVS_TransformFX))
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 20)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FallToGoal, ACTOR_SELF, 10)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetActorVar, ACTOR_SELF, AVAR_Form, AVAL_Form_Mage)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(MageStatusTable)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    Return
    End
};

EvtScript N(EVS_Attack_Leap) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 8, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseEq(HIT_RESULT_LUCKY)
            Thread
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Charge)
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_ChargeTripped)
            EndThread
            Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Trip)
            Thread
                Wait(3)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Defeated)
            EndThread
            Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(FlyToGoal, ACTOR_SELF, 16, 0, EASING_CUBIC_OUT)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_ChargeArmsUp)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_BASE, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_BASE, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseEq(HIT_RESULT_MISS)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 50)
            Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_JR_TOOPA_JUMP, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Jump)
            Wait(2)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Midair)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Set(LVar1, 0)
            Add(LVar2, 3)
            Thread
                Wait(8)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Fall)
            EndThread
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_PanicFast)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
            Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_JR_TOOPA_JUMP, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Jump)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Midair)
    Thread
        Wait(8)
        Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Fall)
    EndThread
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
    Wait(8)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Swoop) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Sub(LVar0, 80)
            Set(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Dive)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_BASE, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_BASE, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Dive)
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SWOOP, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    Wait(10)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(YieldTurn)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_SpikeDive) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLOSE_SHELL)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_EnterEgg)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_EggIdle)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Thread
                Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
                Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Sub(LVar0, 10)
                Set(LVar1, 12)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EndThread
            Set(LVar0, 0)
            Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            Loop(20)
                Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar0)
                Set(LVar1, LVar4)
                Set(LVar2, LVar5)
                Set(LVar3, LVar6)
                Wait(1)
            EndLoop
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                Sub(LVar1, 40)
                Set(LVar2, 10)
                Call(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                Call(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            EndThread
            Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            Loop(14)
                Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                Set(LVar7, LVar0)
                Add(LVar7, 180)
                Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar7)
                Set(LVar1, LVar4)
                Set(LVar2, LVar5)
                Set(LVar3, LVar6)
                Wait(1)
            EndLoop
            Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            Call(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_ExitEgg)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 12, 0)
    Thread
        Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EndThread
    Set(LVar0, 0)
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Loop(20)
        Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
        Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar0)
        Set(LVar1, LVar4)
        Set(LVar2, LVar5)
        Set(LVar3, LVar6)
        Wait(1)
    EndLoop
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_SPIKE_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Add(LVar1, 40)
        Call(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Loop(14)
        Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
        Set(LVar7, LVar0)
        Add(LVar7, 180)
        Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar7)
        Set(LVar1, LVar4)
        Set(LVar2, LVar5)
        Set(LVar3, LVar6)
        Wait(1)
    EndLoop
    Call(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
    Call(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_ExitEgg)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/CalculateArcsinDeg.inc.c"

EvtScript N(EVS_Attack_MagicSpell) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_RaiseStaff)
    Wait(8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Set(LVar3, 0)
        Set(LVar4, 36)
        SetF(LVar5, Float(1.0))
    Else
        Set(LVar3, 0)
        Set(LVar4, 14)
        SetF(LVar5, INVALID_VAR)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_SwingStaff)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseEq(HIT_RESULT_MISS)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            Sub(LVar3, 120)
            Add(LVar4, 20)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                Set(LVar6, -8)
                Set(LVar7, 20)
                SetF(LVar8, Float(1.0))
            Else
                Set(LVar6, -3)
                Set(LVar7, 8)
                SetF(LVar8, INVALID_VAR)
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, LVar6)
            Add(LVar1, LVar7)
            PlayEffect(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 30, 0)
            Wait(35)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseEq(HIT_RESULT_LUCKY)
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 12)
                PlayEffect(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, Float(3.0), 30, 0)
                Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_BurnStaff)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Wait(40)
                Sub(LVar0, 7)
                Add(LVar1, 14)
                Add(LVar2, 4)
                PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                Wait(20)
                Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Idle)
            EndThread
            Wait(20)
            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            Wait(40)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Add(LVar4, 20)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Set(LVar6, -8)
        Set(LVar7, 20)
        SetF(LVar8, Float(1.0))
    Else
        Set(LVar6, -3)
        Set(LVar7, 8)
        SetF(LVar8, INVALID_VAR)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, LVar6)
    Add(LVar1, LVar7)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 15, 0)
    Wait(15)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, DMG_SPELL, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/Dist3D.inc.c" // Not used?

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

EvtScript N(EVS_Attack_LightningBolt) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_RaiseStaff)
    Wait(8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Set(LVar3, 0)
        Set(LVar4, 36)
        SetF(LVar5, Float(1.0))
    Else
        Set(LVar3, 0)
        Set(LVar4, 14)
        SetF(LVar5, INVALID_VAR)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 60)
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_SwingStaff)
    Call(N(UnkBackgroundFunc3))
    Call(MakeLerp, 0, 200, 60, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Call(N(SetBackgroundAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(RandInt, 40, LVar1)
    Add(LVar0, LVar1)
    Add(LVar0, 50)
    Set(LVar1, 200)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LIGHTNING_STRIKE)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseEq(HIT_RESULT_MISS)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
            Wait(20)
            Call(MakeLerp, 200, 0, 60, EASING_LINEAR)
            Label(2)
                Call(UpdateLerp)
                Call(N(SetBackgroundAlpha), LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(2)
                EndIf
            Wait(20)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseEq(HIT_RESULT_LUCKY)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(RandInt, 40, LVar1)
            Sub(LVar0, LVar1)
            Set(LVar1, 200)
            Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, 0, LVar5, Float(1.0), 18, 0)
            Thread
                Wait(10)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 12)
                PlayEffect(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, Float(3.0), 30, 0)
                Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_BurnStaff)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Wait(40)
                Sub(LVar0, 7)
                Add(LVar1, 14)
                Add(LVar2, 4)
                PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                Wait(20)
                Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Idle)
            EndThread
            Wait(20)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(MakeLerp, 200, 0, 60, EASING_LINEAR)
            Label(2)
                Call(UpdateLerp)
                Call(N(SetBackgroundAlpha), LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(2)
                EndIf
            Wait(20)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
    PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
    Wait(14)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT), 0, SUPPRESS_EVENT_FLAG_10000, DMG_LIGHTNING, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MakeLerp, 200, 0, 60, EASING_LINEAR)
    Label(2)
        Call(UpdateLerp)
        Call(N(SetBackgroundAlpha), LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(2)
        EndIf
    Wait(20)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_HealSelf) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_RaiseStaff)
    Wait(8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Set(LVar3, 0)
        Set(LVar4, 36)
        SetF(LVar5, Float(1.0))
    Else
        Set(LVar3, 0)
        Set(LVar4, 14)
        SetF(LVar5, INVALID_VAR)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, LVar3)
    Add(LVar1, LVar4)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GATHER_SMALL)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Add(LVar2, 50)
    PlayEffect(EFFECT_SPARKLES, 1, LVar1, LVar2, LVar3, 10, 0)
    PlayEffect(EFFECT_RECOVER, 2, LVar1, LVar2, LVar3, 0, 0)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Idle)
    Wait(10)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    Mul(LVar0, 17)
    Div(LVar0, 100)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        Wait(30)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EndThread
    Thread
        Call(FreezeBattleState, TRUE)
        Call(HealActor, ACTOR_SELF, LVar0, FALSE)
        Call(FreezeBattleState, FALSE)
    EndThread
    Wait(30)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
            IfNotFlag(LVar0, AVAL_Dialogue_Begin)
                BitwiseOrConst(LVar0, AVAL_Dialogue_Begin)
                Call(SetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(MoveBattleCamOver, 20)
                Call(ActorSpeak, MSG_CH8_005D, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTalk)
                Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
        CaseEq(PHASE_ENEMY_END)
        CaseEq(PHASE_PLAYER_BEGIN) //@bug duplicate case, should be PHASE_PLAYER_END
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_GetFormAnims) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    Switch(LVar1)
        CaseEq(FORM_ANIM_HURT)
            Switch(LVar0)
                CaseEq(AVAL_Form_Flying)
                    Set(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
                CaseEq(AVAL_Form_Mage)
                    Set(LVar1, ANIM_MageJrTroopa_Hurt)
                CaseDefault
                    Set(LVar1, ANIM_JrTroopa_Hurt)
            EndSwitch
        CaseEq(FORM_ANIM_BURN)
            Switch(LVar0)
                CaseEq(AVAL_Form_Flying)
                    Set(LVar1, ANIM_SpikedParaJrTroopa_BurnHurt)
                    Set(LVar2, ANIM_SpikedParaJrTroopa_BurnStill)
                CaseEq(AVAL_Form_Mage)
                    Set(LVar1, ANIM_MageJrTroopa_BurnHurt)
                    Set(LVar2, ANIM_MageJrTroopa_BurnStill)
                CaseDefault
                    Set(LVar1, ANIM_JrTroopa_BurnHurt)
                    Set(LVar2, ANIM_JrTroopa_BurnStill)
            EndSwitch
        CaseEq(FORM_ANIM_FLAIL)
            Switch(LVar0)
                CaseEq(AVAL_Form_Flying)
                    Set(LVar1, ANIM_SpikedParaJrTroopa_Flail)
                CaseEq(AVAL_Form_Mage)
                    Set(LVar1, ANIM_MageJrTroopa_Flail)
                CaseDefault
                    Set(LVar1, ANIM_JrTroopa_Flail)
            EndSwitch
        CaseEq(FORM_ANIM_TALK)
            Switch(LVar0)
                CaseEq(AVAL_Form_Flying)
                    Set(LVar1, ANIM_SpikedParaJrTroopa_Talk)
                CaseEq(AVAL_Form_Mage)
                    Set(LVar1, ANIM_MageJrTroopa_Talk)
                CaseDefault
                    Set(LVar1, ANIM_JrTroopa_Talk)
            EndSwitch
        CaseEq(FORM_ANIM_RETURN)
            Switch(LVar0)
                CaseEq(AVAL_Form_Flying)
                    Set(LVar1, ANIM_SpikedParaJrTroopa_FlyFast)
                CaseEq(AVAL_Form_Mage)
                    Set(LVar1, ANIM_MageJrTroopa_Run)
                CaseDefault
                    Set(LVar1, ANIM_JrTroopa_Run)
            EndSwitch
        CaseDefault
            Switch(LVar0)
                CaseEq(AVAL_Form_Flying)
                    Set(LVar1, ANIM_SpikedParaJrTroopa_Idle)
                CaseEq(AVAL_Form_Mage)
                    Set(LVar1, ANIM_MageJrTroopa_Idle)
                CaseDefault
                    Set(LVar1, ANIM_JrTroopa_Idle)
            EndSwitch
    EndSwitch
    Return
    End
};

EvtScript N(EVS_JrTroopa_Death) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Form_Flying)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            IfEq(LVar1, 0)
                Goto(0)
            EndIf
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
            Call(HideHealthBar, ACTOR_SELF)
            Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Call(FallToGoal, ACTOR_SELF, 10)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Call(HPBarToCurrent, ACTOR_SELF)
            Call(ShowHealthBar, ACTOR_SELF)
            Label(0)
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 10)
                Add(LVar2, 10)
                Loop(3)
                    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                    Wait(3)
                EndLoop
            EndThread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_DefeatedBegin)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 5)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Wait(15)
            Call(PlaySound, SOUND_ACTOR_DEATH)
            Call(DropStarPoints, ACTOR_SELF)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
            Call(SetBattleCamZoom, 260)
            Call(SetBattleCamOffsetZ, 15)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(MoveBattleCamOver, 30)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Defeated)
            Wait(60)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            Return
        CaseEq(AVAL_Form_Mage)
            Call(HideHealthBar, ACTOR_SELF)
            Call(UseIdleAnimation, ACTOR_SELF, FALSE)
            Call(GetDamageSource, LVar5)
            Switch(LVar5)
                CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
                CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
                CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
                CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
                CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
                CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
                CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
                CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
                CaseOrEq(DMG_SRC_SPIN_SMASH)
                EndCaseGroup
                CaseDefault
                    Set(LVar2, 0)
                    Loop(24)
                        Call(SetActorYaw, ACTOR_SELF, LVar2)
                        Add(LVar2, 30)
                        Wait(1)
                    EndLoop
                    Call(SetActorYaw, ACTOR_SELF, 0)
            EndSwitch
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 10)
                Add(LVar2, 10)
                Loop(3)
                    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                    Wait(3)
                EndLoop
            EndThread
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_DefeatedBegin)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 5)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Wait(15)
            Call(PlaySound, SOUND_ACTOR_DEATH)
            Call(DropStarPoints, ACTOR_SELF)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
            Call(SetBattleCamZoom, 260)
            Call(SetBattleCamOffsetZ, 15)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(MoveBattleCamOver, 30)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
            Call(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Defeated)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_BASE, Ref(N(DefeatedAnims)))
            Wait(60)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            Return
        CaseDefault
            Set(LVar1, FORM_ANIM_HURT)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(N(EVS_JrTroopa_BaseDeath))
            Return
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Form_Flying)
            Set(LVar1, FORM_ANIM_RETURN)
            ExecWait(N(EVS_GetFormAnims))
            Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        CaseEq(AVAL_Form_Mage)
            Set(LVar1, FORM_ANIM_RETURN)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_ReturnHome)
        CaseDefault
            Set(LVar1, FORM_ANIM_RETURN)
            ExecWait(N(EVS_GetFormAnims))
            ExecWait(EVS_Enemy_ReturnHome)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TryFearReaction) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
    IfEq(LVar0, AVAL_SpookReact_Ready)
        Wait(10)
        ExecWait(N(EVS_Cam_FocusOnJrTroopa))
        Call(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_Form_Flying)
                Call(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Talk, ANIM_SpikedParaJrTroopa_Idle)
            CaseEq(AVAL_Form_Mage)
                Call(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
            CaseDefault
                Call(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle)
        EndSwitch
        Call(GetActorVar, ACTOR_SELF, AVAR_UnusedBrag, LVar0)
        IfNe(LVar0, TRUE)
            ExecWait(N(EVS_Cam_ResetFocus))
        EndIf
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
    Return
    End
};
