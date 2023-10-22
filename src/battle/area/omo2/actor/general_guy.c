#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "animation_script.h"
#include "sprite/npc/GeneralGuy.h"
#include "sprite/npc/GeneralGuyBomb.h"

#include "battle/area/omo2/actor/boss_common.h"

#define NAMESPACE b_area_omo2_general_guy

extern ActorBlueprint b_area_omo2_1_shy_squad;
extern AnimScript AS_ToyTank_CloseHatch;
extern AnimScript AS_ToyTank_OpenHatch;

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Attack_ThrowBomb);
extern EvtScript N(EVS_Attack_ShootLightning);
extern s32 N(DefaultAnims)[];
extern s32 N(BombAnims)[];
extern Formation N(ShySquadFormation);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BOMB        = 2,
};

enum N(ActorParams) {
    DMG_BOMB_TOSS           = 4,
    DMG_LIGHTNING_PLAYER    = 5,
    DMG_LIGHTNING_PARTNER   = 2,
};

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
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
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_NO_STATUS_ANIMS,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_NO_STATUS_ANIMS,
        .index = PRT_BOMB,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BombAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_GENERAL_GUY,
    .level = ACTOR_LEVEL_GENERAL_GUY,
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
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 30, 30 },
    .healthBarOffset = { 20, -3 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GeneralGuy_Anim02,
    STATUS_KEY_STONE,     ANIM_GeneralGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_GeneralGuy_Anim00,
    STATUS_KEY_POISON,    ANIM_GeneralGuy_Anim02,
    STATUS_KEY_STOP,      ANIM_GeneralGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_GeneralGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_GeneralGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_GeneralGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_GeneralGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_GeneralGuy_Anim00,
    STATUS_KEY_FEAR,      ANIM_GeneralGuy_Anim00,
    STATUS_END,
};

s32 N(BombAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GeneralGuyBomb_Anim00,
    STATUS_END,
};

// unused
s32 N(PanicAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GeneralGuy_Anim0E,
    STATUS_KEY_POISON,    ANIM_GeneralGuy_Anim0E,
    STATUS_KEY_STOP,      ANIM_GeneralGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_GeneralGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_GeneralGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_GeneralGuy_Anim00,
    STATUS_KEY_FEAR,      ANIM_GeneralGuy_Anim00,
    STATUS_END,
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorPos, ACTOR_SELF, 200, 0, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 200, 0, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_General_DoingTankPhase, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_General_Flags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_General_WavesDefeated, 0)
    EVT_CALL(LoadBattleSection, BTL_AREA_OMO2_1)
    EVT_CALL(SummonEnemy, EVT_PTR(N(ShySquadFormation)), TRUE)
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
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_GeneralGuy_Anim08)
            EVT_SET(LVar2, ANIM_GeneralGuy_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_GeneralGuy_Anim08)
            EVT_SET(LVar2, ANIM_GeneralGuy_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GeneralGuy_Anim02)
            EVT_SET_CONST(LVar2, ANIM_GeneralGuy_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_General_DoingTankPhase, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_BULB, LVar0)
    EVT_IF_TRUE(LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_KO)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 60)
                EVT_EXEC_WAIT(N(EVS_Attack_ShootLightning))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Attack_ThrowBomb))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ThrowBomb) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 30)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_OPEN_HATCH)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0B)
    EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_OpenHatch))
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim0B)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 8)
    EVT_ADD(LVar1, 27)
    EVT_SUB(LVar2, 4)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BOMB, ANIM_GeneralGuyBomb_Anim00)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim0A)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_WAIT(6)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 8)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_BOMB, ANIM_GeneralGuyBomb_Anim01)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_BOMB, SOUND_TOSS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 120)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(0.1))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_BOMB, SOUND_TOSS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 65)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_BOMB, SOUND_TOSS)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_BOMB, SOUND_BOMB_BLAST)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_BOMB_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
                EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
                EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ShootLightning) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 30)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_OPEN_HATCH)
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0B)
    EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_OpenHatch))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
    EVT_IF_TRUE(LVar0)
        EVT_CALL(SetDarknessMode, BTL_DARKNESS_MODE_2)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    EVT_WAIT(20)
    EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundDarken))
    EVT_END_THREAD
    EVT_CALL(GetModelCenter, MODEL_kyu3)
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, LVar8, SOUND_ELECTRIC_BUZZ)
            EVT_CALL(RandInt, 3, LVar0)
            EVT_ADD(LVar0, 3)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 40, 0)
    EVT_WAIT(40)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(GetModelCenter, MODEL_kyu3)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_CALL(PlaySound, SOUND_TANK_BULB_FIRE)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_WAIT(12)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
            EVT_IF_NE(LVar0, HIT_RESULT_MISS)
                EVT_CALL(GetModelCenter, MODEL_kyu3)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                EVT_CALL(PlaySound, SOUND_TANK_BULB_FIRE)
                EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
                EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, FALSE)
                EVT_WAIT(12)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_LIGHTNING_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
            EVT_ELSE
                EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, FALSE)
                EVT_WAIT(20)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
            EVT_IF_TRUE(LVar0)
                EVT_CALL(SetDarknessMode, BTL_DARKNESS_MODE_3)
            EVT_END_IF
            EVT_CALL(N(FadeBackgroundLighten))
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(GetModelCenter, MODEL_kyu3)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_CALL(PlaySound, SOUND_TANK_BULB_FIRE)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_WAIT(12)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(GetModelCenter, MODEL_kyu3)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            EVT_CALL(PlaySound, SOUND_TANK_BULB_FIRE)
            EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
            EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, FALSE)
            EVT_WAIT(12)
            EVT_CALL(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
            EVT_IF_TRUE(LVar0)
                EVT_CALL(SetDarknessMode, BTL_DARKNESS_MODE_3)
            EVT_END_IF
            EVT_CALL(N(FadeBackgroundLighten))
            EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
            EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetModelCenter, MODEL_kyu3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(PlaySound, SOUND_TANK_BULB_FIRE)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
    EVT_WAIT(12)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_LIGHTNING_PLAYER, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, FALSE)
                EVT_WAIT(30)
                EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
                EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
                EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    EVT_CALL(GetModelCenter, MODEL_kyu3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(PlaySound, SOUND_TANK_BULB_FIRE)
    EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 18, 0)
    EVT_CALL(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, FALSE)
    EVT_WAIT(12)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_LIGHTNING_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
    EVT_IF_TRUE(LVar0)
        EVT_CALL(SetDarknessMode, BTL_DARKNESS_MODE_3)
    EVT_END_IF
    EVT_CALL(N(FadeBackgroundLighten))
    EVT_CALL(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    EVT_CALL(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(AS_ToyTank_CloseHatch))
    EVT_CALL(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonPos) = { 240, 0, 0 };

Formation N(ShySquadFormation) = {
    ACTOR_BY_POS(b_area_omo2_1_shy_squad, N(SummonPos), 100)
};
