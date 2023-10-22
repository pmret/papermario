#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "effects.h"

#define NAMESPACE A(magikoopa)

extern s32 N(GroundAnims)[];
extern s32 N(FlyingAnims)[];
extern s32 N(BroomAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Flying_Init);
extern EvtScript N(EVS_Flying_HandleEvent);

enum N(ActorPartIDs) {
    PRT_GROUND      = 1,
    PRT_FLYING      = 2,
    PRT_BROOM       = 3,
};

enum N(ActorVars) {
    AVAR_HitTypeFlags           = 0,
    AVAL_HitType_Combo          = 1,
    AVAR_IsClone                = 1,
    AVAR_ShouldKnockDown        = 2,
    AVAR_HealAllCount           = 3,
    AVAR_HealOneCount           = 4,
    AVAR_AttackBoostCount       = 5,
    AVAR_DefenseBoostCount      = 6,
    AVAR_ElectrifyCount         = 7,
    AVAR_TransparifyCount       = 8,
    AVAR_CloneActorID           = 9,
    AVAR_MadeCloneLastTurn      = 10,
    AVAR_LastMove               = 11,
    AVAL_LastMove_None          = -1,
    AVAL_LastMove_HealOne       = 0,
    AVAL_LastMove_HealAll       = 1,
    AVAL_LastMove_MagicBlast    = 2,
    AVAL_LastMove_MakeClone     = 3,
    AVAL_LastMove_BoostAttack   = 4,
    AVAL_LastMove_BoostDefense  = 5,
    AVAL_LastMove_Electrify     = 6,
    AVAL_LastMove_Transparify   = 7,
};

enum N(ActorParams) {
    DMG_MAGIC_BLAST     = 6,
    HEAL_AMT_ONE        = 5,
    HEAL_AMT_ALL        = 3,
    ATTACK_BOOST_AMT    = 1,
    DEFENSE_BOOST_AMT   = 1,
    ELECTRIFY_TURNS     = 3,
    TRANSPARIFY_TURNS   = 2,
    MAX_HEAL_ONE        = 2,
    MAX_HEAL_ALL        = 2,
    MAX_ATTACK_BOOST    = 3,
    MAX_DEFENSE_BOOST   = 3,
    MAX_ELECTRIFY       = 3,
    MAX_TRANSPARIFY     = 3,
    HEAL_THRESHOLD_1    = 25,
    HEAL_THRESHOLD_2    = 20,
    HEAL_THRESHOLD_3    = 15,
    HEAL_CHANCE_1       = 75,
    HEAL_CHANCE_2       = 80,
    HEAL_CHANCE_3       = 100,
    HEAL_ONE_CHANCE     = 500,
    HEAL_ALL_CHANCE     = 500,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
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

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
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
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingDefense),
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
        .idleAnimations = N(BroomAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_MAGIKOOPA,
    .level = ACTOR_LEVEL_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
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
    .type = ACTOR_TYPE_FLYING_MAGIKOOPA,
    .level = ACTOR_LEVEL_FLYING_MAGIKOOPA,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(FlyingParts)),
    .partsData = N(FlyingParts),
    .initScript = &N(EVS_Flying_Init),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 40,
    .airLiftChance = 85,
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

s32 N(GroundAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_Magikoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Magikoopa_Anim08,
    STATUS_KEY_POISON,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_Magikoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Magikoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Magikoopa_Anim07,
    STATUS_KEY_FEAR,      ANIM_Magikoopa_Anim07,
    STATUS_END,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_FlyingMagikoopa_Anim08,
    STATUS_KEY_POISON,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_FlyingMagikoopa_Anim07,
    STATUS_KEY_FEAR,      ANIM_FlyingMagikoopa_Anim07,
    STATUS_END,
};

s32 N(BroomAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Anim0A,
    STATUS_END,
};

#include "common/ShrinkActor.inc.c"
#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_Idle) = {
    EVT_SET(LVarF, 0)
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
        EVT_CALL(ActorExists, LVar0, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(254.0), EVT_FLOAT(100.0), 20, 0, 0)
            EVT_ADD(LVarF, 1)
            EVT_CALL(GetActorFlags, ACTOR_SELF, LVar2)
            EVT_IF_FLAG(LVar2, ACTOR_FLAG_FLYING)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_FLYING, LVar1)
                EVT_CALL(SetPartAlpha, LVar0, 1, LVar1)
            EVT_ELSE
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, LVar1)
                EVT_CALL(SetPartAlpha, LVar0, 1, LVar1)
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVarF, 0)
            EVT_CALL(GetActorFlags, ACTOR_SELF, LVar2)
            EVT_IF_FLAG(LVar2, ACTOR_FLAG_FLYING)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_FLYING, 255)
            EVT_ELSE
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

#include "common/GetSelectedMoveID.inc.c"

EvtScript N(EVS_KnockDownCheck) = {
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, TRUE)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(MOVE_HEADBONK1)
            EVT_CASE_OR_EQ(MOVE_HEADBONK2)
            EVT_CASE_OR_EQ(MOVE_HEADBONK3)
            EVT_CASE_OR_EQ(MOVE_MULTIBONK)
                EVT_CALL(GetBattleFlags, LVar0)
                EVT_IF_FLAG(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, TRUE)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"
#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_KnockDown) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetLastElement, LVar0)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_POW)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_BROOM, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BROOM, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 150, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, EVENT_15)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_ADD(LVar4, 10)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 10, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_MAGIKOOPA)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 32)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flee) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, EVENT_SCARE_AWAY)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, ~AVAL_HitType_Combo)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsClone, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealAllCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealOneCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ElectrifyCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TransparifyCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_None)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Flying_HandleEvent)))
    EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsClone, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldKnockDown, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealAllCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HealOneCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ElectrifyCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TransparifyCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_None)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RemoveClone) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsClone, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(GetLastElement, LVarA)
    EVT_IF_FLAG(LVarA, DAMAGE_TYPE_MULTIPLE_POPUPS)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVarA)
        EVT_IF_FLAG(LVarA, BS_FLAGS1_EXECUTING_MOVE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, -1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, ACTOR_FLAG_FLYING)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_GROUND, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    EVT_END_IF
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(RemoveActor, LVar0)
    EVT_THREAD
        EVT_ADD(LVar3, 2)
        EVT_LOOP(2)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_GROUND, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AVAL_HitType_Combo)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_UP_AND_AWAY)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            EVT_IF_FLAG(LVar0, AVAL_HitType_Combo)
                EVT_EXEC_WAIT(N(EVS_RemoveClone))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
            EVT_EXEC_WAIT(N(EVS_Flee))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, 0, 2, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_GROUND, -4, 5, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_FLYING, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, AVAL_HitType_Combo)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            EVT_EXEC_WAIT(N(EVS_KnockDownCheck))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_FALL_TRIGGER)
            EVT_EXEC_WAIT(N(EVS_KnockDownCheck))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_EXEC_WAIT(N(EVS_KnockDown))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_15)
            EVT_EXEC_WAIT(N(EVS_KnockDownCheck))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_EXEC_WAIT(N(EVS_KnockDown))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitTypeFlags, LVar0)
            EVT_IF_FLAG(LVar0, AVAL_HitType_Combo)
                EVT_EXEC_WAIT(N(EVS_RemoveClone))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
            EVT_EXEC_WAIT(N(EVS_Flee))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -3, 0, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, -15, 0, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_RemoveClone))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// (in) LVarB: actorID to heal
EvtScript N(EVS_Move_HealOne) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_HealOne)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_HealOneCount, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_RECOVER_HEART)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_HEART_BOUNCE)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_STAR_BOUNCE_A)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(HealActor, LVarB, HEAL_AMT_ONE, FALSE)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_HealAll) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_HealAll)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_HealAllCount, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_SET(LFlag0, FALSE)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar1)
        EVT_IF_EQ(LVar1, ACTOR_TYPE_DRY_BONES)
            EVT_CALL(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(PlaySoundAtActor, LVar0, SOUND_RECOVER_HEART)
                EVT_CALL(PlaySoundAtActor, LVar0, SOUND_HEART_BOUNCE)
                EVT_WAIT(30)
                EVT_CALL(PlaySoundAtActor, LVar0, SOUND_STAR_BOUNCE_A)
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(FreezeBattleState, TRUE)
                EVT_CALL(HealActor, LVar0, HEAL_AMT_ALL, TRUE)
                EVT_CALL(FreezeBattleState, FALSE)
            EVT_END_THREAD
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(WaitForBuffDone)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_MagicBlast) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_MagicBlast)
    EVT_SET(LFlag0, FALSE)
    EVT_SET(LFlag1, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LFlag0, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVarA)
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_SET(LFlag1, TRUE)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 17)
            EVT_ADD(LVar1, 33)
            EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 13)
        EVT_ELSE
            EVT_SUB(LVar0, 17)
            EVT_ADD(LVar1, 33)
        EVT_END_IF
        EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
    EVT_ELSE
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
        EVT_END_IF
        EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar9, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_IF_EQ(LFlag1, FALSE)
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim03)
            EVT_ELSE
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim03)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            EVT_SUB(LVar4, 50)
            EVT_SET(LVar5, 0)
            EVT_IF_EQ(LFlag1, FALSE)
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                    EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_SUB(LVar0, 8)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            EVT_ELSE
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                    EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_SUB(LVar0, 8)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            EVT_END_IF
            EVT_WAIT(50)
            EVT_IF_EQ(LVar9, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, LVarA, TRUE)
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim03)
    EVT_ELSE
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim03)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
            EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 8)
            EVT_ADD(LVar1, 8)
        EVT_ELSE
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    EVT_ELSE
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
            EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 8)
            EVT_ADD(LVar1, 8)
        EVT_ELSE
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    EVT_END_IF
    EVT_WAIT(18)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MAGIC_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_ELSE
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_MAGIC_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(UseIdleAnimation, LVarA, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetAvailableColumn) = {
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetIndexFromHome, LVar0, LVar1)
        EVT_MOD(LVar1, 4)
        EVT_SWITCH(LVar1)
            EVT_CASE_EQ(0)
                EVT_SET(LFlagB, TRUE)
            EVT_CASE_EQ(1)
                EVT_SET(LFlagC, TRUE)
            EVT_CASE_EQ(2)
                EVT_SET(LFlagD, TRUE)
            EVT_CASE_EQ(3)
                EVT_SET(LFlagE, TRUE)
        EVT_END_SWITCH
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_SET(LVar0, -1)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar1)
    EVT_MOD(LVar1, 4)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(LFlagC, FALSE)
                EVT_SET(LVar0, 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LFlagB, FALSE)
                EVT_SET(LVar0, 0)
            EVT_END_IF
            EVT_IF_EQ(LFlagD, FALSE)
                EVT_SET(LVar0, 2)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LFlagC, FALSE)
                EVT_SET(LVar0, 1)
            EVT_END_IF
            EVT_IF_EQ(LFlagE, FALSE)
                EVT_SET(LVar0, 3)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LFlagD, FALSE)
                EVT_SET(LVar0, 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(GetActorFlags, ACTOR_SELF, LVar1)
        EVT_IF_FLAG(LVar1, ACTOR_FLAG_FLYING)
            EVT_ADD(LVar0, 4)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Clone_HandleEvent) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Clone_Init) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Clone_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsClone, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlyingClone_Init) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Clone_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsClone, TRUE)
    EVT_RETURN
    EVT_END
};

s32 N(CloneDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingCloneDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(CloneStatusTable)[] = {
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

s32 N(FlyingCloneStatusTable)[] = {
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

ActorPartBlueprint N(CloneParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(GroundAnims),
        .defenseTable = N(CloneDefense),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

ActorPartBlueprint N(FlyingCloneParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingCloneDefense),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint N(clone) = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_MAGICLONE,
    .level = ACTOR_LEVEL_MAGICLONE,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(CloneParts)),
    .partsData = N(CloneParts),
    .initScript = &N(EVS_Clone_Init),
    .statusTable = N(CloneStatusTable),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 32 },
};

ActorBlueprint N(clone_flying) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_FLYING_MAGICLONE,
    .level = ACTOR_LEVEL_FLYING_MAGICLONE,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(FlyingCloneParts)),
    .partsData = N(FlyingCloneParts),
    .initScript = &N(EVS_FlyingClone_Init),
    .statusTable = N(FlyingCloneStatusTable),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusTextOffset = { 1, 34 },
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(CloneFormation) = {
    ACTOR_BY_POS(N(clone), N(SummonPos), 0),
};

Formation N(FlyingCloneFormation) = {
    ACTOR_BY_POS(N(clone_flying), N(SummonPos), 0),
};

EvtScript N(EVS_Move_MakeClone) = {
    EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flee))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_MakeClone)
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SummonEnemy, EVT_PTR(N(CloneFormation)), FALSE)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(FlyingCloneFormation)), FALSE)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CloneActorID, LVar0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(EnableIdleScript, LVarA, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST3)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 23)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 23)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(EnableIdleScript, LVar9, IDLE_SCRIPT_ENABLE)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, -3)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_SET(LVar9, LVarA)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST4)
    EVT_CALL(PlaySoundAtActor, LVar9, SOUND_SPELL_CAST4)
    EVT_CALL(SetPartFlagBits, LVar9, 1, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
        EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    EVT_ELSE
        EVT_CALL(SetActorSpeed, LVar9, EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
        EVT_CALL(SetGoalToIndex, LVar9, LVar0)
        EVT_CALL(FlyToGoal, LVar9, 0, 0, EASING_LINEAR)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, LVar9, 1, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, LVar9, LVar0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorPos, LVar9, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVar9, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVar9)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_GROUND, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
        EVT_CALL(SetAnimation, LVar9, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
        EVT_CALL(SetAnimation, LVar9, 1, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseIdleAnimation, LVar9, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/battle/CheckMagikoopaCastTarget.inc.c"

EvtScript N(EVS_Move_TryBoostAttack) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
        EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
        EVT_CALL(InitTargetIterator)
        EVT_LABEL(0)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(GetIndexFromHome, LVar0, LVar1)
            EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar2)
            EVT_IF_GT(LVar1, LVar2)
                EVT_CALL(N(CheckMagikoopaCastTarget), LVar0, LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_CALL(GetActorAttackBoost, LVar0, LVar4)
                    EVT_IF_LT(LVar4, MAX_ATTACK_BOOST)
                        EVT_SET(LVar8, LVar0)
                        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar1)
                        EVT_GOTO(100)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_IF_NE(LVar0, ITER_NO_MORE)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_SET(LFlag0, TRUE)
            EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flee))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Attack_MagicBlast))
    EVT_RETURN
    // found target
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_BoostAttack)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_AttackBoostCount, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_POWER_UP)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(BoostAttack, LVar8, ATTACK_BOOST_AMT)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_TryBoostDefense) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
        EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
        EVT_CALL(InitTargetIterator)
        EVT_LABEL(0)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(GetIndexFromHome, LVar0, LVar1)
            EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar2)
            EVT_IF_GT(LVar1, LVar2)
                EVT_CALL(N(CheckMagikoopaCastTarget), LVar0, LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_CALL(GetActorDefenseBoost, LVar0, LVar4)
                    EVT_IF_LT(LVar4, MAX_DEFENSE_BOOST)
                        EVT_SET(LVar8, LVar0)
                        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar1)
                        EVT_GOTO(100)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_IF_NE(LVar0, ITER_NO_MORE)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_SET(LFlag0, TRUE)
            EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flee))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Attack_MagicBlast))
    EVT_RETURN
    // found target
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_BoostDefense)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_POWER_UP)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(BoostDefense, LVar8, DEFENSE_BOOST_AMT)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_TryElectrify) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
        EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
        EVT_CALL(InitTargetIterator)
        EVT_LABEL(0)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(GetIndexFromHome, LVar0, LVar1)
            EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar2)
            EVT_IF_GT(LVar1, LVar2)
                EVT_CALL(N(CheckMagikoopaCastTarget), LVar0, LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_CALL(GetStatusFlags, LVar0, LVar4)
                    EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_STATIC | STATUS_FLAG_TRANSPARENT)
                        EVT_SET(LVar8, LVar0)
                        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar1)
                        EVT_GOTO(100)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_IF_NE(LVar0, ITER_NO_MORE)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_SET(LFlag0, TRUE)
            EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flee))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Attack_MagicBlast))
    EVT_RETURN
    // found target
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_Electrify)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_ElectrifyCount, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_ELECTRIFY)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, LVar8, SOUND_ELECTRIC_BUZZ)
            EVT_CALL(RandInt, 3, LVar0)
            EVT_ADD(LVar0, 3)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(ElectrifyActor, LVar8, ELECTRIFY_TURNS)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Move_TryTransparent) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
        EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
        EVT_CALL(InitTargetIterator)
        EVT_LABEL(0)
            EVT_CALL(GetOwnerTarget, LVar0, LVar1)
            EVT_CALL(GetIndexFromHome, LVar0, LVar1)
            EVT_CALL(GetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar2)
            EVT_IF_GT(LVar1, LVar2)
                EVT_CALL(N(CheckMagikoopaCastTarget), LVar0, LVar3)
                EVT_IF_EQ(LVar3, 0)
                    EVT_CALL(GetStatusFlags, LVar0, LVar4)
                    EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_STATIC | STATUS_FLAG_TRANSPARENT)
                        EVT_SET(LVar8, LVar0)
                        EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, LVar1)
                        EVT_GOTO(100)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
            EVT_IF_NE(LVar0, ITER_NO_MORE)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_IF_EQ(LFlag0, FALSE)
            EVT_SET(LFlag0, TRUE)
            EVT_CALL(SetBattleVar, BTL_VAR_Magikoopa_LastIndexBoosted, -1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flee))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Attack_MagicBlast))
    EVT_RETURN
    // found target
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_LastMove, AVAL_LastMove_Transparify)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TransparifyCount, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_MAGIKOOPA_VANISH)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(VanishActor, LVar8, TRANSPARIFY_TURNS)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    #define LBL_LOOP_COUNT_INJURED_1    0
    #define LBL_LOOP_COUNT_INJURED_2    1
    #define LBL_LOOP_COUNT_INJURED_3    2
    #define LBL_TRY_HEALING             10
    #define LBL_LOOP_CHOOSE_BEST_HEAL   11
    #define LBL_TRY_MOVES               20
    #define LBL_CHOOSE_MOVE             123
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(EVS_Attack_MagicBlast))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(LBL_TRY_MOVES)
    EVT_END_IF
    // first heal check: count ~75% of actors with less than 25% HP
    EVT_SET(LVarA, 0)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(LBL_LOOP_COUNT_INJURED_1)
        EVT_SET(LFlag0, FALSE)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar1)
        EVT_IF_EQ(LVar1, ACTOR_TYPE_DRY_BONES)
            EVT_CALL(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(GetActorHP, LVar0, LVar2)
        EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
        EVT_MULF(LVar2, EVT_FLOAT(100.0))
        EVT_DIVF(LVar2, LVar3)
        EVT_IF_EQ(LFlag0, FALSE) // collapsed dry bones check
            EVT_IF_LE(LVar2, HEAL_THRESHOLD_1) // HP% check
                EVT_CALL(RandInt, 99, LVar4)
                EVT_ADD(LVar4, 1)
                EVT_IF_LT(LVar4, HEAL_CHANCE_1) // chance to ignore actor
                    EVT_ADD(LVarA, 1)
                    EVT_SET(LVarB, LVar0)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(LBL_LOOP_COUNT_INJURED_1)
        EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(LBL_TRY_HEALING)
    EVT_END_IF
    // second heal check: count ~80% of actors with less than 20% HP
    EVT_SET(LVarA, 0)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(LBL_LOOP_COUNT_INJURED_2)
        EVT_SET(LFlag0, FALSE)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar1)
        EVT_IF_EQ(LVar1, ACTOR_TYPE_DRY_BONES)
            EVT_CALL(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(GetActorHP, LVar0, LVar2)
        EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
        EVT_MULF(LVar2, EVT_FLOAT(100.0))
        EVT_DIVF(LVar2, LVar3)
        EVT_IF_EQ(LFlag0, FALSE) // collapsed dry bones check
            EVT_IF_LE(LVar2, HEAL_THRESHOLD_2) // HP% check
                EVT_CALL(RandInt, 99, LVar4)
                EVT_ADD(LVar4, 1)
                EVT_IF_LT(LVar4, HEAL_CHANCE_2) // chance to ignore actor
                    EVT_ADD(LVarA, 1)
                    EVT_SET(LVarB, LVar0)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(LBL_LOOP_COUNT_INJURED_2)
        EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(LBL_TRY_HEALING)
    EVT_END_IF
    // third heal check: count ~99% of actors with less than 15% HP
    EVT_SET(LVarA, 0)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(LBL_LOOP_COUNT_INJURED_3)
        EVT_SET(LFlag0, FALSE)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar1)
        EVT_IF_EQ(LVar1, ACTOR_TYPE_DRY_BONES)
            EVT_CALL(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(GetActorHP, LVar0, LVar2)
        EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
        EVT_MULF(LVar2, EVT_FLOAT(100.0))
        EVT_DIVF(LVar2, LVar3)
        EVT_IF_EQ(LFlag0, FALSE) // collapsed dry bones check
            EVT_IF_LE(LVar2, HEAL_THRESHOLD_3) // HP% check
                EVT_CALL(RandInt, 99, LVar4)
                EVT_ADD(LVar4, 1)
                EVT_IF_LT(LVar4, HEAL_CHANCE_3) // chance to ignore actor
                    EVT_ADD(LVarA, 1)
                    EVT_SET(LVarB, LVar0)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(LBL_LOOP_COUNT_INJURED_3)
        EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(LBL_TRY_HEALING)
    EVT_END_IF
    EVT_GOTO(LBL_TRY_MOVES)
    // try healing spells
    EVT_LABEL(LBL_TRY_HEALING)
    EVT_CALL(CountTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flee))
        EVT_RETURN
    EVT_END_IF
    // single healing target available
    EVT_IF_EQ(LVarA, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealOneCount, LVar0)
        EVT_IF_LT(LVar0, MAX_HEAL_ONE)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, HEAL_ONE_CHANCE)
                EVT_EXEC_WAIT(N(EVS_Move_HealOne))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealAllCount, LVar0)
            EVT_IF_LT(LVar0, MAX_HEAL_ALL)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, HEAL_ALL_CHANCE)
                    EVT_EXEC_WAIT(N(EVS_Move_HealAll))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
    // multiple injured actors were found
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealAllCount, LVar0)
        EVT_IF_LT(LVar0, MAX_HEAL_ALL)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, HEAL_ALL_CHANCE)
                EVT_EXEC_WAIT(N(EVS_Move_HealAll))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            // choose actor with least HP%
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HealOneCount, LVar0)
            EVT_IF_LT(LVar0, MAX_HEAL_ONE)
                EVT_SETF(LVar9, EVT_FLOAT(100.0))
                EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
                EVT_CALL(InitTargetIterator)
                EVT_LABEL(LBL_LOOP_CHOOSE_BEST_HEAL)
                    EVT_SET(LFlag0, FALSE)
                    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
                    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
                    EVT_IF_EQ(LVar1, ACTOR_TYPE_DRY_BONES)
                        EVT_CALL(GetActorVar, LVar0, AVAR_DryBones_Collapsed, LVar1)
                        EVT_IF_EQ(LVar1, 1)
                            EVT_SET(LFlag0, TRUE)
                        EVT_END_IF
                    EVT_END_IF
                    EVT_CALL(GetActorHP, LVar0, LVar2)
                    EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
                    EVT_MULF(LVar2, EVT_FLOAT(100.0))
                    EVT_DIVF(LVar2, LVar3)
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_IF_LE(LVar2, LVar9)
                            EVT_SETF(LVar9, LVar2)
                            EVT_SET(LVarB, LVar0)
                        EVT_END_IF
                    EVT_END_IF
                    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
                    EVT_IF_NE(LVar0, ITER_NO_MORE)
                        EVT_GOTO(LBL_LOOP_CHOOSE_BEST_HEAL)
                    EVT_END_IF
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, HEAL_ONE_CHANCE)
                    EVT_EXEC_WAIT(N(EVS_Move_HealOne))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    // check various buffs and attacks
    EVT_LABEL(LBL_TRY_MOVES)
    EVT_SET(LVarA, 10)
    EVT_SET(LVarB, 10)
    EVT_SET(LVarC, 10)
    EVT_SET(LVarD, 10)
    EVT_SET(LVarE, 10)
    EVT_SET(LVarF, 10)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_MadeCloneLastTurn, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LVarA, 100) // only magic blast
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_SET(LVarD, 0)
        EVT_SET(LVarE, 0)
        EVT_SET(LVarF, 0)
        EVT_GOTO(LBL_CHOOSE_MOVE)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
        EVT_IF_EQ(LVar0, -1)
            EVT_SET(LVarB, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_LastMove, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_LastMove_BoostAttack)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, LVar1)
            EVT_IF_LT(LVar1, MAX_ATTACK_BOOST)
                EVT_CALL(RandInt, 99, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_IF_LE(LVar0, 50)
                    EVT_SET(LVarA, 0)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 100) // only boost attack
                    EVT_SET(LVarD, 0)
                    EVT_SET(LVarE, 0)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(AVAL_LastMove_BoostDefense)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, LVar1)
            EVT_IF_LT(LVar1, MAX_DEFENSE_BOOST)
                EVT_CALL(RandInt, 99, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_IF_LE(LVar0, 50)
                    EVT_SET(LVarA, 0)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 0)
                    EVT_SET(LVarD, 100) // only boost defense
                    EVT_SET(LVarE, 0)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    // set weights to zero for anything we cant cast anymore
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AttackBoostCount, LVar0)
    EVT_IF_GE(LVar0, MAX_ATTACK_BOOST)
        EVT_SET(LVarC, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DefenseBoostCount, LVar0)
    EVT_IF_GE(LVar0, MAX_DEFENSE_BOOST)
        EVT_SET(LVarD, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ElectrifyCount, LVar0)
    EVT_IF_GE(LVar0, MAX_ELECTRIFY)
        EVT_SET(LVarE, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TransparifyCount, LVar0)
    EVT_IF_GE(LVar0, MAX_TRANSPARIFY)
        EVT_SET(LVarF, 0)
    EVT_END_IF
    // make a weighted choice
    EVT_LABEL(LBL_CHOOSE_MOVE)
    EVT_SET(LVar9, 0)
    EVT_ADD(LVar9, LVarA)
    EVT_ADD(LVar9, LVarB)
    EVT_ADD(LVar9, LVarC)
    EVT_ADD(LVar9, LVarD)
    EVT_ADD(LVar9, LVarE)
    EVT_ADD(LVar9, LVarF)
    EVT_SUB(LVar9, 1)
    EVT_CALL(RandInt, LVar9, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(EVS_Attack_MagicBlast))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarB)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(EVS_Move_MakeClone))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarC)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(EVS_Move_TryBoostAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarD)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(EVS_Move_TryBoostDefense))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarE)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(EVS_Move_TryElectrify))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Move_TryTransparent))
    EVT_RETURN
    EVT_END
};
