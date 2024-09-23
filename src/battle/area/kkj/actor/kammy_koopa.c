#include "../area.h"
#include "entity.h"
#include "sprite/npc/BattleKammy.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/BattleParakarry.h"

#define NAMESPACE A(kammy_koopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_CommentOnHit);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BROOM       = 2,
};

enum N(ActorVars) {
    AVAR_PlayerTurnCount    = 0,
    AVAR_Speaking           = 1,
};

enum N(ActorParams) {
    DMG_BLOCK_DROP  = 4,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleKammy_Anim05,
    STATUS_END,
};

s32 N(BroomAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleKammy_Anim0C,
    STATUS_END,
};

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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_BROOM,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BroomAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_KAMMY_KOOPA,
    .level = ACTOR_LEVEL_KAMMY_KOOPA,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetBattleFlagBits2, BS_FLAGS2_DONT_STOP_MUSIC, TRUE)
    Call(SetActorVar, ACTOR_SELF, AVAR_PlayerTurnCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Speaking, FALSE)
    Return
    End
};

s32 N(BobPhase) = 0;

API_CALLABLE(N(AddFlightBobbing)) {
    Actor* actor = get_actor(script->owner1.actorID);

    N(BobPhase) += 9;
    N(BobPhase) = clamp_angle(N(BobPhase));
    actor->verticalRenderOffset = sin_rad(DEG_TO_RAD(N(BobPhase))) * 3.0f;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    Loop(0)
        Call(N(AddFlightBobbing))
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKammy_Anim0D)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_CommentOnHit))
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKammy_Anim05)
            ExecWait(EVS_Enemy_NoDamageHit)
            ExecWait(N(EVS_CommentOnHit))
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKammy_Anim0D)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            ExecWait(N(EVS_Death))
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "world/common/todo/SetEntityPositionF.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

API_CALLABLE(N(BlockAppear)) {
    Entity* entity = get_entity_by_index(script->varTable[9]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rot.y = (1.0f - cos_rad(entity->scale.y * PI)) * 1080.0f * 0.5f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(FadeInScreenBlur)) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
        set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
        set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
        set_screen_overlay_params_back(OVERLAY_BLUR, 150);
    }
    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
    set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
    set_screen_overlay_params_back(OVERLAY_NONE, -1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(FadeOutScreenBlur)) {
    if (isInitialCall) {
        script->functionTemp[0] = 30;
        set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
        set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
        set_screen_overlay_params_back(OVERLAY_BLUR, 150);
    }
    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    set_screen_overlay_center(SCREEN_LAYER_BACK, 0, 0, 0);
    set_screen_overlay_center(SCREEN_LAYER_BACK, 1, 320, 240);
    set_screen_overlay_params_back(OVERLAY_NONE, -1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DropBlock)) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 entityIndex = script->varTable[9];
    Entity* entity = get_entity_by_index(entityIndex);

    entity->collisionTimer = 0;
    collisionStatus->lastWallHammered = entityIndex | COLLISION_WITH_ENTITY_BIT;
    playerStatus->flags |= PS_FLAG_HAMMER_CHECK;
    entity->collisionFlags = ENTITY_COLLISION_PLAYER_HAMMER;
    playerStatus->actionState = ACTION_STATE_HAMMER;
    entity->blueprint->fpHandleCollision(entity);
    entity->collisionTimer = 10;
    entity->flags |= ENTITY_FLAG_DETECTED_COLLISION;
    collisionStatus->lastWallHammered = -1;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim07)
    Wait(5)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KAMMY_SUMMON_MAGIC)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 25)
    Add(LVar1, 40)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 100, 0)
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, 80, 95, 15)
    Call(SetBattleCamDist, 340)
    Call(MoveBattleCamOver, 60)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KAMMY_SUMMON_BLOCK)
    Sub(LVar0, 15)
    Add(LVar1, 30)
    Set(LVar3, LVar1)
    Add(LVar3, 20)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, Float(1.0), 60, 0)
    Wait(20)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, Float(1.0), 60, 0)
    Wait(10)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, Float(1.0), 60, 0)
    Wait(5)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, Float(1.0), 60, 0)
    Wait(3)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar3, LVar2, Float(1.0), 60, 0)
    Call(MakeEntity, Ref(Entity_Hammer1Block), LVar0, LVar1, LVar2, 0, MAKE_ENTITY_END)
    Set(LVar9, LVar0)
    Call(N(BlockAppear))
    Thread
        Call(N(FadeInScreenBlur))
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KAMMY_RAISE_OBJECT)
    Call(N(GetEntityPosition), LVar9, LVar2, LVar3, LVar4)
    Call(MakeLerp, LVar3, 300, 20, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPositionF), LVar9, LVar2, LVar0, LVar4)
        Wait(1)
        IfNe(LVar1, 1)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim08)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, -80, 37, 5)
    Call(SetBattleCamDist, 256)
    Call(MoveBattleCamOver, 1)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    ChildThread
        Wait(10)
        Call(AddBattleCamDist, 100)
        Call(MoveBattleCamOver, 10)
        Wait(5)
        Call(N(FadeOutScreenBlur))
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KAMMY_LOWER_OBJECT)
    Set(LVar5, LVar1)
    Add(LVar5, 200)
    Call(N(SetEntityPositionF), LVar9, LVar0, LVar5, LVar2)
    Call(N(GetEntityPosition), LVar9, LVar2, LVar3, LVar4)
    Call(MakeLerp, LVar5, LVar1, 20, EASING_CUBIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPositionF), LVar9, LVar2, LVar0, LVar4)
        Wait(1)
        IfNe(LVar1, 1)
            BreakLoop
        EndIf
    EndLoop
    Call(N(DropBlock))
    ChildThread
        Call(StartRumble, BTL_RUMBLE_HIT_EXTREME)
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(6.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(5.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(4.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
    EndChildThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim05)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_BLOCK_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(19)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EndCaseGroup
    EndSwitch
    Call(GetLastDamage, ACTOR_PARTNER, LVar0)
    IfEq(LVar0, 0)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(SetBattleCamTarget, 69, 14, -18)
        Call(SetBattleCamDist, 340)
        Call(SetBattleCamOffsetY, 62)
        Call(MoveBattleCamOver, 20)
        Call(FreezeBattleCam, TRUE)
        Wait(20)
        Thread
            Call(SetGoalToHome, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 10, 5, 0)
            Call(FlyToGoal, ACTOR_SELF, 6, 0, EASING_LINEAR)
        EndThread
        Call(ActorSpeak, MSG_CH8_009A, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim05)
        Wait(10)
        Call(FreezeBattleCam, FALSE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EndIf
    Wait(10)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_PlayerTurnCount, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                    Call(SetBattleCamTarget, 69, 14, -18)
                    Call(SetBattleCamDist, 340)
                    Call(SetBattleCamOffsetY, 62)
                    Call(MoveBattleCamOver, 20)
                    Wait(20)
                    Call(ActorSpeak, MSG_CH8_0093, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim05)
                    Wait(10)
                    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                    Call(SetBattleCamTarget, -56, -9, -18)
                    Call(SetBattleCamDist, 340)
                    Call(SetBattleCamOffsetY, 62)
                    Call(MoveBattleCamOver, 1)
                    Wait(10)
                    Call(ActorSpeak, MSG_CH8_0094, ACTOR_PARTNER, 1, ANIM_Twink_ShoutAngry, ANIM_Twink_Angry)
                    Wait(10)
                    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                    Call(SetBattleCamTarget, -66, -9, -18)
                    Call(SetBattleCamDist, 340)
                    Call(SetBattleCamOffsetY, 62)
                    Call(MoveBattleCamOver, 10)
                    Wait(10)
                    Call(ActorSpeak, MSG_CH8_0095, ACTOR_PLAYER, 1, ANIM_BattleParakarry_EnterShell, ANIM_BattleParakarry_ShellFly)
                    Wait(10)
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(AddActorVar, ACTOR_SELF, AVAR_PlayerTurnCount, 1)
            EndSwitch
        CaseEq(PHASE_ENEMY_BEGIN)
            // do nothing
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_CommentOnHit) = {
    Call(FreezeBattleState, TRUE)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Speaking, TRUE)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(10)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamTarget, 69, 14, -18)
            Call(SetBattleCamDist, 340)
            Call(SetBattleCamOffsetY, 62)
            Call(MoveBattleCamOver, 20)
            Call(FreezeBattleCam, TRUE)
            Wait(20)
            Call(ActorSpeak, MSG_CH8_0097, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim09, ANIM_BattleKammy_Anim05)
            Wait(10)
            Call(FreezeBattleCam, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        CaseOrEq(9)
        CaseOrEq(8)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamTarget, 69, 14, -18)
            Call(SetBattleCamDist, 340)
            Call(SetBattleCamOffsetY, 62)
            Call(MoveBattleCamOver, 20)
            Call(FreezeBattleCam, TRUE)
            Wait(20)
            Call(ActorSpeak, MSG_CH8_0098, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim0A, ANIM_BattleKammy_Anim05)
            Wait(10)
            Call(FreezeBattleCam, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EndCaseGroup
        CaseOrEq(7)
        CaseOrEq(6)
        CaseOrEq(5)
        CaseOrEq(4)
        CaseOrEq(3)
        CaseOrEq(2)
        CaseOrEq(1)
            Call(GetActorVar, ACTOR_SELF, AVAR_PlayerTurnCount, LVar0)
            IfEq(LVar0, 2)
                BreakSwitch
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamTarget, 69, 14, -18)
            Call(SetBattleCamDist, 340)
            Call(SetBattleCamOffsetY, 62)
            Call(MoveBattleCamOver, 20)
            Call(FreezeBattleCam, TRUE)
            Wait(20)
            Call(ActorSpeak, MSG_CH8_0099, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim06, ANIM_BattleKammy_Anim05)
            Wait(10)
            Call(FreezeBattleCam, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorVar, ACTOR_SELF, AVAR_PlayerTurnCount, 1)
        EndCaseGroup
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_Speaking, FALSE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Call(FreezeBattleState, FALSE)
    Return
    End
};

EvtScript N(EVS_Death) = {
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 60)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim02)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 1)
    Call(SetPartPos, ACTOR_SELF, PRT_BROOM, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BROOM, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
    Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SEEING_STARS)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim03)
    Wait(50)
    Call(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, TRUE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    Call(ActorSpeak, MSG_CH8_009B, ACTOR_SELF, PRT_MAIN, ANIM_BattleKammy_Anim03, ANIM_BattleKammy_Anim03)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 60)
    Wait(40)
    Call(SetBattleFlagBits, BS_FLAGS1_PLAYER_IN_BACK, FALSE)
    Return
    End
};
