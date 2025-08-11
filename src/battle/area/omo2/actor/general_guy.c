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
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(SetActorPos, ACTOR_SELF, 200, 0, 0)
    Call(ForceHomePos, ACTOR_SELF, 200, 0, 0)
    Call(HPBarToHome, ACTOR_SELF)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Call(SetActorVar, ACTOR_SELF, AVAR_General_DoingTankPhase, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_General_Flags, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_General_WavesDefeated, 0)
    Call(LoadBattleSection, BTL_AREA_OMO2_1)
    Call(SummonEnemy, Ref(N(ShySquadFormation)), true)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, 1)
            Set(LVar1, ANIM_GeneralGuy_Anim08)
            Set(LVar2, ANIM_GeneralGuy_Anim09)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, 1)
            Set(LVar1, ANIM_GeneralGuy_Anim08)
            Set(LVar2, ANIM_GeneralGuy_Anim09)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim09)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim0E)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim02)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim0E)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim02)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_GeneralGuy_Anim02)
            SetConst(LVar2, ANIM_GeneralGuy_Anim05)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_General_DoingTankPhase, LVar0)
    IfFalse(LVar0)
        Return
    EndIf
    Call(ActorExists, ACTOR_BULB, LVar0)
    IfTrue(LVar0)
        Call(GetStatusFlags, ACTOR_PARTNER, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_KO)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 60)
                ExecWait(N(EVS_Attack_ShootLightning))
                Return
            EndIf
        EndIf
    EndIf
    ExecWait(N(EVS_Attack_ThrowBomb))
    Return
    End
};

EvtScript N(EVS_Attack_ThrowBomb) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_FAR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Thread
        Wait(35)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 30)
    EndThread
    Wait(5)
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_OPEN_HATCH)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0B)
    Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_OpenHatch))
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim0B)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 8)
    Add(LVar1, 27)
    Sub(LVar2, 4)
    Call(SetPartPos, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_BOMB, ANIM_GeneralGuyBomb_Anim00)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, false)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim0A)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, true)
    Wait(6)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 8)
    Add(LVar1, 20)
    Call(SetPartPos, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_BOMB, ANIM_GeneralGuyBomb_Anim01)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseEq(HIT_RESULT_MISS)
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_BOMB, SOUND_TOSS)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 120)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, Float(12.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, Float(0.1))
            Call(JumpPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, true)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        CaseEq(HIT_RESULT_LUCKY)
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_BOMB, SOUND_TOSS)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Set(LVar1, -5)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, Float(14.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 65)
            Set(LVar1, -5)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, Float(6.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
    EndSwitch
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_BOMB, SOUND_TOSS)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BOMB, Float(14.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_BOMB, Float(0.1))
    Call(FlyPartTo, ACTOR_SELF, PRT_BOMB, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_BOMB, SOUND_BOMB_BLAST)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BOMB, ACTOR_PART_FLAG_INVISIBLE, true)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_BOMB_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Wait(30)
            IfEq(LVarF, HIT_RESULT_10)
                Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
                Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
                Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
                Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_ShootLightning) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 320)
    Call(SetBattleCamOffsetY, 30)
    Call(MoveBattleCamOver, 40)
    Wait(40)
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_OPEN_HATCH)
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim0B)
    Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_OpenHatch))
    Wait(10)
    Call(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
    IfTrue(LVar0)
        Call(SetDarknessMode, BTL_DARKNESS_MODE_2)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim03)
    Wait(20)
    Call(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, true)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Thread
        Call(N(FadeBackgroundDarken))
    EndThread
    Call(GetModelCenter, MODEL_kyu3)
    Thread
        Loop(4)
            Call(PlaySoundAtActor, LVar8, SOUND_ELECTRIC_BUZZ)
            Call(RandInt, 3, LVar0)
            Add(LVar0, 3)
            Wait(LVar0)
        EndLoop
    EndThread
    PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, Float(1.0), 40, 0)
    Wait(40)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseEq(HIT_RESULT_MISS)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(GetModelCenter, MODEL_kyu3)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            Call(PlaySound, SOUND_TANK_BULB_FIRE)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
            Wait(12)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
            IfNe(LVar0, HIT_RESULT_MISS)
                Call(GetModelCenter, MODEL_kyu3)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                Call(PlaySound, SOUND_TANK_BULB_FIRE)
                PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
                Call(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, false)
                Wait(12)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_LIGHTNING_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
            Else
                Call(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, false)
                Wait(20)
            EndIf
            Call(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
            IfTrue(LVar0)
                Call(SetDarknessMode, BTL_DARKNESS_MODE_3)
            EndIf
            Call(N(FadeBackgroundLighten))
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        CaseEq(HIT_RESULT_LUCKY)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(GetModelCenter, MODEL_kyu3)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            Call(PlaySound, SOUND_TANK_BULB_FIRE)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
            Wait(12)
            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            Call(GetModelCenter, MODEL_kyu3)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar3, 0, LVar5)
            Call(PlaySound, SOUND_TANK_BULB_FIRE)
            PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
            Call(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, false)
            Wait(12)
            Call(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
            IfTrue(LVar0)
                Call(SetDarknessMode, BTL_DARKNESS_MODE_3)
            EndIf
            Call(N(FadeBackgroundLighten))
            Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
            Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
            Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
    EndSwitch
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetModelCenter, MODEL_kyu3)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(PlaySound, SOUND_TANK_BULB_FIRE)
    PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
    Wait(12)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_LIGHTNING_PLAYER, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GeneralGuy_Anim02)
            IfEq(LVarF, HIT_RESULT_10)
                Call(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, false)
                Wait(30)
                Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
                Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
                Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
                Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    Call(GetModelCenter, MODEL_kyu3)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(PlaySound, SOUND_TANK_BULB_FIRE)
    PlayEffect(EFFECT_LIGHTNING_BOLT, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0), 18, 0)
    Call(SetActorVar, ACTOR_TANK, AVAR_Tank_UsingBulbAttack, false)
    Wait(12)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_LIGHTNING_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
    Call(GetActorVar, ACTOR_TANK, AVAR_Tank_ModulateDarkness, LVar0)
    IfTrue(LVar0)
        Call(SetDarknessMode, BTL_DARKNESS_MODE_3)
    EndIf
    Call(N(FadeBackgroundLighten))
    Call(SetAnimation, ACTOR_GENERAL, PRT_MAIN, ANIM_GeneralGuy_Anim02)
    Call(SetPartFlagBits, ACTOR_GENERAL, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
    Call(PlaySoundAtPart, ACTOR_GENERAL, PRT_MAIN, SOUND_TOY_TANK_CLOSE_HATCH)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

Vec3i N(SummonPos) = { 240, 0, 0 };

Formation N(ShySquadFormation) = {
    ACTOR_BY_POS(b_area_omo2_1_shy_squad, N(SummonPos), 100)
};
