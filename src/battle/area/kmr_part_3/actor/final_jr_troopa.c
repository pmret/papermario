#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/SpikedParaJrTroopa.h"
#include "sprite/npc/MageJrTroopa.h"

#define NAMESPACE A(final_jr_troopa)

// Invalid value used in some scripts here == -91,999,590
// The closest evt variable for this is MapFlag(-1999590), which is way out of range.
// Looks like it was supposed to be a value for EVT_FLOAT(), but its likewise out of range.
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
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_FLAG(LVar2, STATUS_FLAGS_IMMOBILIZED)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar2)
    EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar2, MOVE_SPOOK)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_Ready)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_EMOTE_QUESTION)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 30)
            EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 30, EMOTER_POS, LVar0, LVar1, LVar2, 5)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TransformFX) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 16)
    EVT_ELSE
        EVT_ADD(LVar1, 6)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(32)
            EVT_WAIT(1)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(32)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_NEW_POWER)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 40, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 4, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_FocusOnJrTroopa) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_07)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_ResetFocus) = {
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_FocusOnGoompa) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(BaseDefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

EvtScript N(EVS_JrTroopa_BaseDeath) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVar1)
    EVT_WAIT(10)
    EVT_CALL(GetDamageSource, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar2, 0)
            EVT_LOOP(24)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                EVT_ADD(LVar2, 30)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 10)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Collapse)
    EVT_WAIT(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, LVarA, EVT_PTR(N(BaseDefeatedAnims)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_UnusedBrag, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DialogueFlags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Form, AVAL_Form_Base)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealsLeft, 5)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_Form_Flying)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
                EVT_IF_FLAG(LVarA, STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_FLYING, -15, 28)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_FLYING, 4, -6)
                    EVT_CALL(N(SetAbsoluteStatusOffsets), -25, 27, -1, 27)
                EVT_ELSE
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_FLYING, -8, 33)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_FLYING, 0, -6)
                    EVT_CALL(N(SetAbsoluteStatusOffsets), -22, 30, 2, 28)
                EVT_END_IF
            EVT_CASE_DEFAULT
                EVT_CALL(N(SetAbsoluteStatusOffsets), -20, 35, 10, 25)
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_SetupFearReaction))
            EVT_EXEC_WAIT(N(EVS_TryFearReaction))
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar1, FORM_ANIM_BURN)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar1, FORM_ANIM_BURN)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET(LVar1, FORM_ANIM_IMMUNE)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET(LVar1, FORM_ANIM_IMMUNE)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_EXEC_WAIT(N(EVS_SetupFearReaction))
            EVT_EXEC_WAIT(N(EVS_TryFearReaction))
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_SWITCH(LVar3)
                EVT_CASE_FLAG(STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
                    EVT_ADD(LVar0, -13)
                    EVT_ADD(LVar1, 37)
                EVT_CASE_FLAG(STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar0, -1)
                    EVT_ADD(LVar1, 14)
                EVT_CASE_DEFAULT
                    EVT_ADD(LVar0, -4)
                    EVT_ADD(LVar1, 37)
            EVT_END_SWITCH
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_SET(LVar1, FORM_ANIM_FLAIL)
                EVT_EXEC_WAIT(N(EVS_GetFormAnims))
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_SET(LVar1, FORM_ANIM_IMMUNE)
                EVT_EXEC_WAIT(N(EVS_GetFormAnims))
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                EVT_WAIT(20)
                EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
                EVT_SET(LVar1, FORM_ANIM_TALK)
                EVT_EXEC_WAIT(N(EVS_GetFormAnims))
                EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
                EVT_CALL(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, LVar0, -1, -1)
                EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    EVT_IF_NE(LVar0, AVAL_Form_Mage)
        EVT_CALL(GetActorHP, ACTOR_SELF, LVar1)
        EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar2)
        EVT_MUL(LVar1, 100)
        EVT_DIV(LVar1, LVar2)
        EVT_IF_EQ(LVar0, AVAL_Form_Base)
            EVT_IF_LT(LVar1, 65)
                EVT_EXEC_WAIT(N(EVS_Transform_Flying))
            EVT_END_IF
        EVT_ELSE
            EVT_IF_LT(LVar1, 35)
                EVT_EXEC_WAIT(N(EVS_Transform_Mage))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LT(LVar0, 15)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, AVAL_Dialogue_LowHP)
            EVT_BITWISE_OR_CONST(LVar0, AVAL_Dialogue_LowHP)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Form_Flying)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Talk)
                EVT_CASE_EQ(AVAL_Form_Mage)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Talk)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Talk)
            EVT_END_SWITCH
            EVT_CALL(ActorSpeak, MSG_CH8_0060, ACTOR_SELF, PRT_BASE, -1, -1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Form_Flying)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 50)
                EVT_EXEC_WAIT(N(EVS_Attack_Swoop))
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Attack_SpikeDive))
            EVT_END_IF
        EVT_CASE_EQ(AVAL_Form_Mage)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_LT(60)
                    EVT_EXEC_WAIT(N(EVS_Attack_MagicSpell))
                EVT_CASE_LT(80)
                    EVT_EXEC_WAIT(N(EVS_Attack_LightningBolt))
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
                    EVT_IF_NE(LVar0, LVar1)
                        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealsLeft, LVar2)
                        EVT_IF_GT(LVar2, 0)
                            EVT_SUB(LVar2, 1)
                            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealsLeft, LVar2)
                            EVT_EXEC_WAIT(N(EVS_Move_HealSelf))
                        EVT_ELSE
                            EVT_EXEC_WAIT(N(EVS_Attack_MagicSpell))
                        EVT_END_IF
                    EVT_ELSE
                        EVT_EXEC_WAIT(N(EVS_Attack_MagicSpell))
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_Attack_Leap))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Transform_Flying) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(ActorSpeak, MSG_CH8_005E, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_TiredTalk, ANIM_JrTroopa_TiredTalk)
    EVT_EXEC_WAIT(N(EVS_TransformFX))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_WAIT(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 60, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Form, AVAL_Form_Flying)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(FlyingStatusTable)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Transform_Mage) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(ActorSpeak, MSG_CH8_005F, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Talk, ANIM_SpikedParaJrTroopa_Talk)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 120)
    EVT_EXEC_WAIT(N(EVS_TransformFX))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 20)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FallToGoal, ACTOR_SELF, 10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Form, AVAL_Form_Mage)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(MageStatusTable)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Leap) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 8, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Charge)
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_ChargeTripped)
            EVT_END_THREAD
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Trip)
            EVT_THREAD
                EVT_WAIT(3)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Defeated)
            EVT_END_THREAD
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 16, 0, EASING_CUBIC_OUT)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_ChargeArmsUp)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_BASE, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_BASE, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_JR_TOOPA_JUMP, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Jump)
            EVT_WAIT(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Midair)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 0)
            EVT_ADD(LVar2, 3)
            EVT_THREAD
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Fall)
            EVT_END_THREAD
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_PanicFast)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_JR_TOOPA_JUMP, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Jump)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Midair)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Fall)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
    EVT_WAIT(8)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Swoop) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(LVar0, 80)
            EVT_SET(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_BASE, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_BASE, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Dive)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SWOOP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_WAIT(10)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SpikeDive) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CLOSE_SHELL)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_EnterEgg)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_EggIdle)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 6, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 10)
                EVT_SET(LVar1, 12)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_END_THREAD
            EVT_SET(LVar0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_LOOP(20)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar0)
                EVT_SET(LVar1, LVar4)
                EVT_SET(LVar2, LVar5)
                EVT_SET(LVar3, LVar6)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_SUB(LVar1, 40)
                EVT_SET(LVar2, 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_LOOP(14)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                EVT_SET(LVar7, LVar0)
                EVT_ADD(LVar7, 180)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar7)
                EVT_SET(LVar1, LVar4)
                EVT_SET(LVar2, LVar5)
                EVT_SET(LVar3, LVar6)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_ExitEgg)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 12, 0)
    EVT_THREAD
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_SET(LVar0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_LOOP(20)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar0)
        EVT_SET(LVar1, LVar4)
        EVT_SET(LVar2, LVar5)
        EVT_SET(LVar3, LVar6)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_SPIKE_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_ADD(LVar1, 40)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_LOOP(14)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
        EVT_SET(LVar7, LVar0)
        EVT_ADD(LVar7, 180)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, LVar7)
        EVT_SET(LVar1, LVar4)
        EVT_SET(LVar2, LVar5)
        EVT_SET(LVar3, LVar6)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_ExitEgg)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_FlyFast)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/CalculateArcsinDeg.inc.c"

EvtScript N(EVS_Attack_MagicSpell) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 36)
        EVT_SETF(LVar5, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 14)
        EVT_SETF(LVar5, INVALID_VAR)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            EVT_SUB(LVar3, 120)
            EVT_ADD(LVar4, 20)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET(LVar6, -8)
                EVT_SET(LVar7, 20)
                EVT_SETF(LVar8, EVT_FLOAT(1.0))
            EVT_ELSE
                EVT_SET(LVar6, -3)
                EVT_SET(LVar7, 8)
                EVT_SETF(LVar8, INVALID_VAR)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, LVar6)
            EVT_ADD(LVar1, LVar7)
            EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 30, 0)
            EVT_WAIT(35)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 12)
                EVT_PLAY_EFFECT(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(3.0), 30, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_BurnStaff)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_WAIT(40)
                EVT_SUB(LVar0, 7)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 4)
                EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Idle)
            EVT_END_THREAD
            EVT_WAIT(20)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_WAIT(40)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 20)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_SET(LVar6, -8)
        EVT_SET(LVar7, 20)
        EVT_SETF(LVar8, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar6, -3)
        EVT_SET(LVar7, 8)
        EVT_SETF(LVar8, INVALID_VAR)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar6)
    EVT_ADD(LVar1, LVar7)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 15, 0)
    EVT_WAIT(15)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, DMG_SPELL, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/Dist3D.inc.c" // Not used?

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

EvtScript N(EVS_Attack_LightningBolt) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 36)
        EVT_SETF(LVar5, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 14)
        EVT_SETF(LVar5, INVALID_VAR)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 60, EASING_COS_IN_OUT)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetBackgroundAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(RandInt, 40, LVar1)
    EVT_ADD(LVar0, LVar1)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 200)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LIGHTNING_STRIKE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_WAIT(20)
            EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
            EVT_LABEL(2)
                EVT_CALL(UpdateLerp)
                EVT_CALL(N(SetBackgroundAlpha), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(RandInt, 40, LVar1)
            EVT_SUB(LVar0, LVar1)
            EVT_SET(LVar1, 200)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, 0, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 12)
                EVT_PLAY_EFFECT(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(3.0), 30, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_BurnStaff)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_WAIT(40)
                EVT_SUB(LVar0, 7)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 4)
                EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Idle)
            EVT_END_THREAD
            EVT_WAIT(20)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
            EVT_LABEL(2)
                EVT_CALL(UpdateLerp)
                EVT_CALL(N(SetBackgroundAlpha), LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
    EVT_WAIT(14)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT), 0, SUPPRESS_EVENT_FLAG_10000, DMG_LIGHTNING, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MakeLerp, 200, 0, 60, EASING_LINEAR)
    EVT_LABEL(2)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetBackgroundAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_WAIT(20)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_HealSelf) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 36)
        EVT_SETF(LVar5, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LVar3, 0)
        EVT_SET(LVar4, 14)
        EVT_SETF(LVar5, INVALID_VAR)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GATHER_SMALL)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_ADD(LVar2, 50)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar1, LVar2, LVar3, 10, 0)
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 2, LVar1, LVar2, LVar3, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Idle)
    EVT_WAIT(10)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
    EVT_MUL(LVar0, 17)
    EVT_DIV(LVar0, 100)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(HealActor, ACTOR_SELF, LVar0, FALSE)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, AVAL_Dialogue_Begin)
                EVT_BITWISE_OR_CONST(LVar0, AVAL_Dialogue_Begin)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DialogueFlags, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_CALL(ActorSpeak, MSG_CH8_005D, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTalk)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Idle)
            EVT_END_IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN) //@bug duplicate case, should be PHASE_PLAYER_END
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetFormAnims) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(FORM_ANIM_HURT)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Form_Flying)
                    EVT_SET(LVar1, ANIM_SpikedParaJrTroopa_Hurt)
                EVT_CASE_EQ(AVAL_Form_Mage)
                    EVT_SET(LVar1, ANIM_MageJrTroopa_Hurt)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_JrTroopa_Hurt)
            EVT_END_SWITCH
        EVT_CASE_EQ(FORM_ANIM_BURN)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Form_Flying)
                    EVT_SET(LVar1, ANIM_SpikedParaJrTroopa_BurnHurt)
                    EVT_SET(LVar2, ANIM_SpikedParaJrTroopa_BurnStill)
                EVT_CASE_EQ(AVAL_Form_Mage)
                    EVT_SET(LVar1, ANIM_MageJrTroopa_BurnHurt)
                    EVT_SET(LVar2, ANIM_MageJrTroopa_BurnStill)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_JrTroopa_BurnHurt)
                    EVT_SET(LVar2, ANIM_JrTroopa_BurnStill)
            EVT_END_SWITCH
        EVT_CASE_EQ(FORM_ANIM_FLAIL)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Form_Flying)
                    EVT_SET(LVar1, ANIM_SpikedParaJrTroopa_Flail)
                EVT_CASE_EQ(AVAL_Form_Mage)
                    EVT_SET(LVar1, ANIM_MageJrTroopa_Flail)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_JrTroopa_Flail)
            EVT_END_SWITCH
        EVT_CASE_EQ(FORM_ANIM_TALK)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Form_Flying)
                    EVT_SET(LVar1, ANIM_SpikedParaJrTroopa_Talk)
                EVT_CASE_EQ(AVAL_Form_Mage)
                    EVT_SET(LVar1, ANIM_MageJrTroopa_Talk)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_JrTroopa_Talk)
            EVT_END_SWITCH
        EVT_CASE_EQ(FORM_ANIM_RETURN)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Form_Flying)
                    EVT_SET(LVar1, ANIM_SpikedParaJrTroopa_FlyFast)
                EVT_CASE_EQ(AVAL_Form_Mage)
                    EVT_SET(LVar1, ANIM_MageJrTroopa_Run)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_JrTroopa_Run)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Form_Flying)
                    EVT_SET(LVar1, ANIM_SpikedParaJrTroopa_Idle)
                EVT_CASE_EQ(AVAL_Form_Mage)
                    EVT_SET(LVar1, ANIM_MageJrTroopa_Idle)
                EVT_CASE_DEFAULT
                    EVT_SET(LVar1, ANIM_JrTroopa_Idle)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JrTroopa_Death) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Form_Flying)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_IF_EQ(LVar1, 0)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
            EVT_CALL(HideHealthBar, ACTOR_SELF)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(FallToGoal, ACTOR_SELF, 10)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
            EVT_CALL(ShowHealthBar, ACTOR_SELF)
            EVT_LABEL(0)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_ADD(LVar2, 10)
                EVT_LOOP(3)
                    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                    EVT_WAIT(3)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_DefeatedBegin)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(15)
            EVT_CALL(PlaySound, SOUND_ACTOR_DEATH)
            EVT_CALL(DropStarPoints, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(SetBattleCamZoom, 260)
            EVT_CALL(SetBattleCamOffsetZ, 15)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Defeated)
            EVT_WAIT(60)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(AVAL_Form_Mage)
            EVT_CALL(HideHealthBar, ACTOR_SELF)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(GetDamageSource, LVar5)
            EVT_SWITCH(LVar5)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
                EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SET(LVar2, 0)
                    EVT_LOOP(24)
                        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                        EVT_ADD(LVar2, 30)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_SWITCH
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_ADD(LVar2, 10)
                EVT_LOOP(3)
                    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                    EVT_WAIT(3)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_DefeatedBegin)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(15)
            EVT_CALL(PlaySound, SOUND_ACTOR_DEATH)
            EVT_CALL(DropStarPoints, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(SetBattleCamZoom, 260)
            EVT_CALL(SetBattleCamOffsetZ, 15)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Defeated)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_BASE, EVT_PTR(N(DefeatedAnims)))
            EVT_WAIT(60)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, FORM_ANIM_HURT)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(N(EVS_JrTroopa_BaseDeath))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Form_Flying)
            EVT_SET(LVar1, FORM_ANIM_RETURN)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        EVT_CASE_EQ(AVAL_Form_Mage)
            EVT_SET(LVar1, FORM_ANIM_RETURN)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_DEFAULT
            EVT_SET(LVar1, FORM_ANIM_RETURN)
            EVT_EXEC_WAIT(N(EVS_GetFormAnims))
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryFearReaction) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
    EVT_IF_EQ(LVar0, AVAL_SpookReact_Ready)
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Form, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_Form_Flying)
                EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_FLYING, ANIM_SpikedParaJrTroopa_Talk, ANIM_SpikedParaJrTroopa_Idle)
            EVT_CASE_EQ(AVAL_Form_Mage)
                EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_MAGE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
            EVT_CASE_DEFAULT
                EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_BASE, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle)
        EVT_END_SWITCH
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_UnusedBrag, LVar0)
        EVT_IF_NE(LVar0, TRUE)
            EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
    EVT_RETURN
    EVT_END
};
