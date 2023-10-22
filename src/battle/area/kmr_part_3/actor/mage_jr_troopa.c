#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/MageJrTroopa.h"

#define NAMESPACE A(mage_jr_troopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TryFearReaction);
extern EvtScript N(EVS_JrTroopa_Death);

enum N(ActorPartIDs) {
    PRT_BASE        = 1,
    PRT_MAGE        = 2,
};

enum N(ActorVars) {
    // 'you wont like this!' brag before attacking
    AVAR_MagicBrag_State        = 0,
    AVAL_MagicBrag_None         = 0,
    AVAL_MagicBrag_Ready        = 1,
    AVAL_MagicBrag_Done         = 2,
    // 'that felt fantastic!' brag after dealing damage
    AVAR_DamageBrag_State       = 1,
    AVAL_DamageBrag_None        = 0,
    AVAL_DamageBrag_Ready       = 1,
    AVAL_DamageBrag_Done        = 2,
    AVAR_Unused                 = 2,
    AVAR_SpookReact             = 3,
    AVAL_SpookReact_None        = 0,
    AVAL_SpookReact_Ready       = 1,
};

enum N(ActorParams) {
    DMG_SPELL       = 8,
};

s32 N(MageAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MageJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_MageJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_MageJrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_MageJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(UnusedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MageJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_STONE,     ANIM_MageJrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_MageJrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_MageJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_MageJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_MageJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(BaseAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              35,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              45,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           45,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               60,
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

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_BASE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 28 },
        .opacity = 255,
        .idleAnimations = N(MageAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAGE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(BaseAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA_5,
    .level = ACTOR_LEVEL_JR_TROOPA_5,
    .maxHP = 50,
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
    .powerBounceChance = 75,
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

EvtScript N(EVS_Transform) = {
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

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, AVAL_MagicBrag_None)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, AVAL_DamageBrag_None)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
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
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_SetupFearReaction))
            EVT_EXEC_WAIT(N(EVS_TryFearReaction))
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Still)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, PRT_BASE)
            EVT_SET(LVar1, ANIM_MageJrTroopa_BurnHurt)
            EVT_SET(LVar2, ANIM_MageJrTroopa_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, PRT_BASE)
            EVT_SET(LVar1, ANIM_MageJrTroopa_BurnHurt)
            EVT_SET(LVar2, ANIM_MageJrTroopa_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_BurnStill)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Still)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_EXEC_WAIT(N(EVS_SetupFearReaction))
            EVT_EXEC_WAIT(N(EVS_TryFearReaction))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Flail)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Flail)
                EVT_WAIT(20)
                EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
                EVT_CALL(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_BASE)
            EVT_SET_CONST(LVar1, ANIM_MageJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_RaiseStaff)
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
        EVT_SETF(LVar5, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar3)
    EVT_ADD(LVar1, LVar4)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, LVar5, 30, 0)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
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
                EVT_SETF(LVar8, EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, LVar6)
            EVT_ADD(LVar1, LVar7)
            EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 30, 0)
            EVT_WAIT(35)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
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
        EVT_SETF(LVar8, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, LVar6)
    EVT_ADD(LVar1, LVar7)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 15, 0)
    EVT_WAIT(15)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, DMG_SPELL, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_DamageBrag_None)
                EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar1)
                EVT_IF_NE(LVar1, 0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, AVAL_DamageBrag_Ready)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
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
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            // trying showing the scene where Jr Troopa brags about his new skills
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_MagicBrag_Ready)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_IF_NOT_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, AVAL_MagicBrag_Done)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
                    EVT_IF_EQ(LVar0, AVAL_SpookReact_None)
                        EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
                        EVT_WAIT(20)
                    EVT_END_IF
                    EVT_CALL(ActorSpeak, MSG_CH7_00DD, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                    EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_ELSE
                EVT_WAIT(20)
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
            EVT_RETURN
        EVT_CASE_EQ(PHASE_ENEMY_END)
            // trying showing the scene where Jr Troopa brgas about dealing damage
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_DamageBrag_Ready)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DamageBrag_State, AVAL_DamageBrag_Done)
                EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH7_00DE, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
                EVT_WAIT(10)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            // trying showing the scene where Jr Troopa transforms
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_MagicBrag_None)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, AVAL_MagicBrag_Ready)
                EVT_WAIT(15)
                EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, MSG_CH7_00DB, ACTOR_SELF, PRT_MAGE, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot)
                EVT_WAIT(8)
                EVT_EXEC_WAIT(N(EVS_Transform))
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                EVT_WAIT(15)
                EVT_CALL(ActorSpeak, MSG_CH7_00DC, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JrTroopa_Death) = {
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
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BASE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAGE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_JrTroopa_DefeatedBegin)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAGE, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAGE, EVT_PTR(N(DefeatedAnims)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryFearReaction) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
    EVT_IF_EQ(LVar0, AVAL_SpookReact_Ready)
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
        EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Talk, ANIM_MageJrTroopa_PointIdle)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BASE, ANIM_MageJrTroopa_Idle)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_MagicBrag_State, LVar0)
        EVT_IF_NE(LVar0, AVAL_MagicBrag_Ready)
            EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
