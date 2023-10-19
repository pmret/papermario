#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/SpyGuy.h"

#define NAMESPACE A(spy_guy)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_STONE       = 2,
};

enum N(ActorVars) {
    AVAR_ItemState          = 0,
    AVAL_Item_None          = 0,
    AVAL_Item_Fumble        = 1,
    AVAL_Item_KnockAway     = 2,
    AVAL_Item_Gone          = 3,
    AVAR_Knockoff_ItemIdx   = 1,
    AVAR_Weapon             = 2,
    AVAL_Weapon_Slingshot   = 0,
    AVAL_Weapon_Mallet      = 1,
    AVAR_ShouldSwitchWeapon = 3,
};

enum N(ActorParams) {
    DMG_SHOOT       = 2,
    DMG_MALLET      = 2,
};

s32 N(MalletAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpyGuy_Anim03,
    STATUS_KEY_STONE,     ANIM_SpyGuy_Anim01,
    STATUS_KEY_SLEEP,     ANIM_SpyGuy_Anim0F,
    STATUS_KEY_POISON,    ANIM_SpyGuy_Anim03,
    STATUS_KEY_STOP,      ANIM_SpyGuy_Anim01,
    STATUS_KEY_STATIC,    ANIM_SpyGuy_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_SpyGuy_Anim01,
    STATUS_KEY_DIZZY,     ANIM_SpyGuy_Anim12,
    STATUS_KEY_FEAR,      ANIM_SpyGuy_Anim12,
    STATUS_END,
};

s32 N(SlingshotAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpyGuy_Anim02,
    STATUS_KEY_STONE,     ANIM_SpyGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_SpyGuy_Anim0F,
    STATUS_KEY_POISON,    ANIM_SpyGuy_Anim02,
    STATUS_KEY_STOP,      ANIM_SpyGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_SpyGuy_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_SpyGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_SpyGuy_Anim12,
    STATUS_KEY_FEAR,      ANIM_SpyGuy_Anim12,
    STATUS_END,
};

s32 N(StoneAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpyGuy_Anim10,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,              0,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(MalletAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -13 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_STONE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(StoneAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPY_GUY,
    .level = ACTOR_LEVEL_SPY_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 1,
    .size = { 32, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Mallet)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, FALSE)
    EVT_CALL(GetInstigatorValue, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Slingshot)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SlingshotAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrySwitchWeapon) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Weapon_Slingshot)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
        EVT_CASE_EQ(AVAL_Weapon_Mallet)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
    EVT_END_SWITCH
    EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_EXECUTING_MOVE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Weapon_Slingshot)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Mallet)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(MalletAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim17)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim19)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
        EVT_CASE_EQ(AVAL_Weapon_Mallet)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Slingshot)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SlingshotAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim18)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim1A)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, TRUE)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, TRUE)
            EVT_EXEC_WAIT(N(EVS_TrySwitchWeapon))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_SpyGuy_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, TRUE)
            EVT_EXEC_WAIT(N(EVS_TrySwitchWeapon))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_SpyGuy_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldSwitchWeapon, TRUE)
            EVT_EXEC_WAIT(N(EVS_TrySwitchWeapon))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            EVT_IF_EQ(LVar1, AVAL_Weapon_Slingshot)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            EVT_IF_EQ(LVar1, AVAL_Weapon_Slingshot)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_EXEC_WAIT(N(EVS_TrySwitchWeapon))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            EVT_IF_EQ(LVar1, AVAL_Weapon_Slingshot)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            EVT_IF_EQ(LVar1, AVAL_Weapon_Slingshot)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_END_IF
            EVT_SET_CONST(LVar2, ANIM_SpyGuy_Anim11)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            EVT_IF_EQ(LVar1, AVAL_Weapon_Slingshot)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar1)
            EVT_IF_EQ(LVar1, AVAL_Weapon_Slingshot)
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Slingshot) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_DRAW)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim15)
    EVT_WAIT(12)
    EVT_WAIT(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim16)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SLINGSHOT_FIRE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_STONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_STONE, LVar3, LVar4, LVar5)
                    EVT_IF_GT(LVar0, LVar3)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.002))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(15)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_STONE, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.002))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SHOOT, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_STONE, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_STONE, EVT_FLOAT(0.7))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_STONE, LVar0, 0, LVar2, 30, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_STONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/ItemEntityJumpToPos.inc.c"

#include "common/GetItemEntityPosition.inc.c"

#include "common/DisableRandomAbility.inc.c"

#include "common/battle/CheckPlayerCanLoseCommand.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_ManageItemMotion) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ItemState, LVarA)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(AVAL_Item_None)
                // do nothing
            EVT_CASE_EQ(AVAL_Item_Fumble)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
                EVT_SET(LVar2, 0)
                EVT_SUB(LVar3, 1)
                EVT_CALL(N(DisableRandomAbility), LVar4, LVar5)
                EVT_CALL(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Knockoff_ItemIdx, LVar0)
                EVT_ADD(LVar1, 30)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 20, EVT_FLOAT(1.0))
                EVT_ADD(LVar1, 20)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 10, EVT_FLOAT(1.0))
                EVT_ADD(LVar1, 10)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, EVT_FLOAT(1.0))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAR_ItemState)
            EVT_CASE_EQ(AVAL_Item_KnockAway)
                EVT_CALL(ShowMessageBox, LVar5, 60)
                EVT_SUB(LVar1, 150)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 30, EVT_FLOAT(1.0))
                EVT_CALL(RemoveItemEntity, LVar0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAL_Item_Gone)
                EVT_RETURN
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Mallet) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
    EVT_IF_NOT_FLAG(LVar1, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
    EVT_WAIT(10)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MALLET_SWING)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim0A)
            EVT_WAIT(6)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim0A)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MALLET, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(N(CheckPlayerCanLoseCommand), LVar0)
                EVT_IF_NE(LVar0, -1)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_LE(LVar0, 0)
                EVT_WAIT(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
            EVT_IF_FLAG(LVar1, STATUS_FLAG_SHRINK)
                EVT_WAIT(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar1)
            EVT_IF_FLAG(LVar1, STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
                EVT_WAIT(20)
                EVT_GOTO(100)
            EVT_END_IF
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAL_Item_Fumble)
                EVT_EXEC(N(EVS_ManageItemMotion))
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 70)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
                EVT_LABEL(0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ItemState, LVar0)
                    EVT_IF_NE(LVar0, AVAL_Item_None)
                        EVT_WAIT(1)
                        EVT_GOTO(0)
                    EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Knockoff_ItemIdx, LVar0)
                EVT_CALL(N(GetItemEntityPosition), LVar0, LVar1, LVar2, LVar3)
                EVT_ADD(LVar1, 20)
                EVT_SUB(LVar3, 2)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_THREAD
                    EVT_WAIT(5)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_COMMAND_LOSS)
                    EVT_CALL(N(StartRumbleWithParams), 200, 10)
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim09)
                EVT_WAIT(5)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ItemState, AVAL_Item_KnockAway)
                EVT_SUB(LVar1, 7)
                EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar1, LVar2, LVar3, EVT_FLOAT(1.0), 0, 0)
                EVT_WAIT(40)
            EVT_ELSE
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim07)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 70)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim03)
                EVT_WAIT(10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_PLAY_EFFECT(EFFECT_EMOTE, EMOTE_QUESTION, 0, LVar0, LVar1, LVar2, 25, -45, 20, 0, 0)
                EVT_WAIT(20)
            EVT_END_IF
            EVT_LABEL(100)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_SpyGuy_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Weapon, AVAL_Weapon_Slingshot)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SlingshotAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_SpyGuy_Anim02)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Weapon, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Weapon_Slingshot)
            EVT_EXEC_WAIT(N(EVS_Attack_Slingshot))
        EVT_CASE_EQ(AVAL_Weapon_Mallet)
            EVT_EXEC_WAIT(N(EVS_Attack_Mallet))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
