#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBombette.h"
#include "battle/action_cmd/bomb.h"
#include "battle/action_cmd/body_slam.h"

#define NAMESPACE battle_partner_bombette

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Attack_FirstStrike);
extern EvtScript N(EVS_FirstStrike);
extern EvtScript N(EVS_RunAway);
extern EvtScript N(EVS_RunAwayFail);
extern EvtScript N(EVS_Attack_BodySlam);
extern EvtScript N(EVS_Attack_Bomb);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Unk_0      = 0,
};

enum {
    LF_MashEnded    = LFlag0,
    LF_MashStarted  = LFlag2,
};

API_CALLABLE(N(PlayExplosionFX)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s16 selectedMoveID;
    s32 soundID;

    fx_smoke_ring(0, x, y, z);
    selectedMoveID = battleStatus->selectedMoveID;

    switch (selectedMoveID) {
        case MOVE_BOMB:
            if (script->varTable[10] > 0) {
                fx_explosion(1, x, y + 20, z);
            } else {
                fx_explosion(0, x, y + 20, z);
            }
            sfx_play_sound(SOUND_BOMBETTE_BLAST_LV1);
            break;
        case MOVE_POWER_BOMB:
            if (script->varTable[10] > 0) {
                fx_explosion(1, x, y + 20, z);
            } else {
                fx_explosion(0, x, y + 20, z);
            }
            sfx_play_sound(SOUND_BOMBETTE_BLAST_LV2);
            break;
        case MOVE_MEGA_BOMB:
            if (script->varTable[10] > 0) {
                fx_explosion(2, x, y + 20, z);
            } else {
                fx_explosion(1, x, y + 20, z);
            }
            sfx_play_sound(SOUND_BOMBETTE_BLAST_LV2);
            break;
        default:
            fx_explosion(0, x, y + 20, z);
            sfx_play_sound(SOUND_BOMBETTE_BLAST_LV1);
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SlowDown)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorState* partnerActorMovement = &partnerActor->state;

    if (isInitialCall) {
        partnerActor->state.curPos.x = partnerActor->curPos.x;
        partnerActor->state.curPos.y = partnerActor->curPos.y;
        partnerActor->state.curPos.z = partnerActor->curPos.z;
    }

    add_xz_vec3f(&partnerActorMovement->curPos, partnerActor->state.speed, partnerActor->state.angle);

    if (partnerActor->state.speed < 4.0f) {
        play_movement_dust_effects(0, partnerActor->state.curPos.x, partnerActor->state.curPos.y,
                                   partnerActor->state.curPos.z, partnerActor->state.angle);
    } else {
        play_movement_dust_effects(1, partnerActor->state.curPos.x, partnerActor->state.curPos.y,
                                   partnerActor->state.curPos.z, partnerActor->state.angle);
    }

    partnerActorMovement->speed /= 1.5;

    partnerActor->curPos.x = partnerActorMovement->curPos.x;
    partnerActor->curPos.y = partnerActorMovement->curPos.y;
    partnerActor->curPos.z = partnerActorMovement->curPos.z;

    if (partnerActorMovement->speed < 1.0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(GetBombDamage)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 mashResult = evt_get_variable(script, *args++);
    s32 damage = 0;

    switch (partnerActor->actorBlueprint->level) {
        case PARTNER_RANK_NORMAL:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 2;
            } else if (mashResult <= 80) {
                damage = 3;
            } else if (mashResult <= 99) {
                damage = 4;
            } else {
                damage = 5;
            }
            break;
        case PARTNER_RANK_SUPER:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 4;
            } else if (mashResult <= 99) {
                damage = 5;
            } else {
                damage = 6;
            }
            break;
        case PARTNER_RANK_ULTRA:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 5;
            } else if (mashResult <= 99) {
                damage = 6;
            } else {
                damage = 7;
            }
            break;
    }

    if (mashResult > 99) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    script->varTable[15] = damage;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetPowerBombDamage)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 mashResult = evt_get_variable(script, *args++);
    s32 damage = 0;

    switch (partnerActor->actorBlueprint->level) {
        case PARTNER_RANK_SUPER:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 4;
            } else if (mashResult <= 99) {
                damage = 5;
            } else {
                damage = 6;
            }
            break;
        case PARTNER_RANK_ULTRA:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 5;
            } else if (mashResult <= 99) {
                damage = 6;
            } else {
                damage = 7;
            }
            break;
    }

    if (mashResult > 99) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    script->varTable[15] = damage;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetMegaBombDamage)) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 mashResult = evt_get_variable(script, *args++);
    s32 damage = 0;

    switch (partnerActor->actorBlueprint->level) {
        case PARTNER_RANK_ULTRA:
            if (mashResult <= 35) {
                damage = 1;
            } else if (mashResult <= 60) {
                damage = 3;
            } else if (mashResult <= 80) {
                damage = 5;
            } else if (mashResult <= 99) {
                damage = 6;
            } else {
                damage = 7;
            }
            break;
    }

    if (mashResult > 99) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }

    script->varTable[15] = damage;

    return ApiStatus_DONE2;
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBombette_Walk,
    STATUS_KEY_STONE,     ANIM_BattleBombette_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBombette_Sleep,
    STATUS_KEY_POISON,    ANIM_BattleBombette_Still,
    STATUS_KEY_STOP,      ANIM_BattleBombette_Still,
    STATUS_KEY_DAZE,      ANIM_BattleBombette_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleBombette_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
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
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 9, 20 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOMBETTE,
    .level = ACTOR_LEVEL_BOMBETTE,
    .maxHP = 99,
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
    .size = { 30, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_PARTNER, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_PARTNER, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_PARTNER, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_PARTNER, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(CloseActionCommandInfo)
    Call(StopSound, SOUND_LRAW_BOMBETTE_FUSE)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            SetConst(LVar2, ANIM_BattleBombette_Backfire2)
            ExecWait(EVS_Partner_Hit)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Partner_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            Set(LVar2, 15)
            SetConst(LVar3, ANIM_BattleBombette_Injured)
            ExecWait(EVS_Partner_BombetteSpikeContact)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1, ANIM_BattleBombette_BurnHurt)
            SetConst(LVar2, ANIM_BattleBombette_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Set(LVarA, 0)
            Call(N(PlayExplosionFX), LVar0, LVar1, LVar2)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(3.0))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(1.5))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.8))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.3))
                Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.1))
            EndThread
            Thread
                Set(LVar0, 0)
                Loop(80)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Add(LVar0, 33)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar1, 200)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            Wait(50)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar1, 200)
            Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.6))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_61)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Sub(LVar0, 60)
            Add(LVar1, 40)
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.1))
            Call(SetJumpAnimations, ACTOR_PARTNER, 0, ANIM_BattleBombette_BurnHurt, ANIM_BattleBombette_BurnHurt, ANIM_BattleBombette_BurnHurt)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BurnHurt)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            SetConst(LVar1, ANIM_BattleBombette_BurnHurt)
            SetConst(LVar2, ANIM_BattleBombette_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Set(LVarA, 0)
            Call(N(PlayExplosionFX), LVar0, LVar1, LVar2)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(3.0))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(1.5))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.8))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.3))
                Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.1))
            EndThread
            Thread
                Set(LVar0, 0)
                Loop(80)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Add(LVar0, 33)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar1, 200)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            Wait(50)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar1, 200)
            Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.6))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            Set(LVar2, 15)
            SetConst(LVar3, ANIM_BattleBombette_Injured)
            Set(LVarA, LVar1)
            Set(LVarB, LVar2)
            Set(LVarC, LVar3)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_62)
            Call(SetAnimation, ACTOR_PARTNER, -1, LVarA)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Sub(LVar0, 60)
            Add(LVar1, 40)
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.1))
            Call(SetJumpAnimations, ACTOR_PARTNER, 0, LVarA, LVarA, LVarA)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, FALSE, FALSE)
            Call(ShowShockEffect, ACTOR_SELF)
            Set(LVar1, LVarA)
            Set(LVar2, 0)
            ExecWait(EVS_Partner_Hit)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Fall)
            Wait(8)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Set(LVarA, 0)
            Call(N(PlayExplosionFX), LVar0, LVar1, LVar2)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 10, Float(3.0))
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.0))
                Call(ShakeCam, CAM_BATTLE, 0, 3, Float(1.5))
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.8))
                Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.3))
                Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.1))
            EndThread
            Thread
                Set(LVar0, 0)
                Loop(80)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Add(LVar0, 33)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar1, 200)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            Wait(50)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar1, 200)
            Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.6))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_PARTNER, 5, FALSE, TRUE, FALSE)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_33)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Idle)
            SetConst(LVar2, ANIM_BattleBombette_Run)
            Set(LVar3, 0)
            ExecWait(EVS_Partner_Recover)
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Block)
            ExecWait(EVS_Partner_NoDamageHit)
            Wait(10)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_FIRST_STRIKE)
            ExecWait(N(EVS_FirstStrike))
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(N(EVS_ExecuteAction))
        CaseEq(PHASE_CELEBRATE)
            ExecWait(N(EVS_Celebrate))
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(N(EVS_RunAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(EVS_RunAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleBombette_CelebrateLoop)
    SetConst(LVar2, ANIM_BattleBombette_Celebrate)
    SetConst(LVar3, ANIM_BattleBombette_Idle)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(ShowActionHud, TRUE)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BODY_SLAM1)
            ExecWait(N(EVS_Attack_BodySlam))
        CaseEq(MOVE_BODY_SLAM2)
            ExecWait(N(EVS_Attack_BodySlam))
        CaseEq(MOVE_BODY_SLAM3)
            ExecWait(N(EVS_Attack_BodySlam))
        CaseEq(MOVE_BOMB)
            ExecWait(N(EVS_Attack_Bomb))
        CaseEq(MOVE_POWER_BOMB)
            ExecWait(N(EVS_Attack_Bomb))
        CaseEq(MOVE_MEGA_BOMB)
            ExecWait(N(EVS_Attack_Bomb))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_FirstStrike) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BODY_SLAM1)
            ExecWait(N(EVS_Attack_FirstStrike))
        CaseEq(MOVE_BODY_SLAM2)
            ExecWait(N(EVS_Attack_FirstStrike))
        CaseEq(MOVE_BODY_SLAM3)
            ExecWait(N(EVS_Attack_FirstStrike))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_RunAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleBombette_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(EVS_RunAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(returnHome2) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
    Call(MoveBattleCamOver, 10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 25, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Sub(LVar0, 30)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Sub(LVar0, 10)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    Wait(8)
    Call(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(5.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 15, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Sub(LVar0, 30)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire2)
    Sub(LVar0, 10)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Backfire1)
    Wait(1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    Wait(8)
    Call(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(5.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    Return
    End
};

EvtScript N(runToTarget) = {
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
    Call(RunToGoal, ACTOR_PARTNER, 35)
    Return
    End
};

EvtScript N(animBrace) = {
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Brace)
    Loop(15)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(0.5), 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(-0.5), 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(animHold) = {
    Loop(15)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(0.5), 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(-0.5), 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Attack_BodySlam) = {
    Call(LoadActionCommand, ACTION_COMMAND_BODY_SLAM)
    Call(action_command_body_slam_init)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_48)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
    Set(LF_MashStarted, 0)
    Loop(60)
        Call(CheckButtonDown, BUTTON_A, LVar0)
        IfNe(LVar0, FALSE)
            Set(LF_MashStarted, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(MoveBattleCamOver, 65)
    IfEq(LF_MashStarted, 1)
        Call(action_command_body_slam_start, 0, 92, 3, 0)
        Set(LF_MashEnded, 0)
        ExecGetTID(N(runToTarget), LVarA)
        Loop(35)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfEq(LVar0, FALSE)
                Set(LF_MashEnded, 1)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LF_MashEnded, 1)
            KillThread(LVarA)
            Goto(10)
        EndIf
        Set(LF_MashEnded, 0)
        ExecGetTID(N(animBrace), LVarA)
        Loop(30)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfEq(LVar0, FALSE)
                Set(LF_MashEnded, 1)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LF_MashEnded, 1)
            KillThread(LVarA)
            Goto(10)
        EndIf
        IfEq(LF_MashEnded, 0)
            ExecGetTID(N(animHold), LVarA)
            Loop(30)
                Call(CheckButtonDown, BUTTON_A, LVar0)
                IfEq(LVar0, FALSE)
                    Set(LF_MashEnded, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LF_MashEnded, 1)
                KillThread(LVarA)
                Goto(10)
            EndIf
        EndIf
    Else
        Set(LF_MashEnded, 0)
        ExecGetTID(N(runToTarget), LVarA)
        Loop(35)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfNe(LVar0, FALSE)
                IfEq(LF_MashStarted, 0)
                    Call(action_command_body_slam_start, 0, 92, 3, 0)
                    Set(LF_MashStarted, 1)
                EndIf
            EndIf
            IfEq(LF_MashStarted, 1)
                IfEq(LVar0, FALSE)
                    Set(LF_MashEnded, 1)
                    BreakLoop
                EndIf
            EndIf
            Wait(1)
        EndLoop
        IfEq(LF_MashEnded, 1)
            KillThread(LVarA)
            Goto(10)
        EndIf
        Set(LF_MashEnded, 0)
        ExecGetTID(N(animBrace), LVarA)
        Loop(30)
            Call(CheckButtonDown, BUTTON_A, LVar0)
            IfNe(LVar0, FALSE)
                IfEq(LF_MashStarted, 0)
                    Call(action_command_body_slam_start, 0, 92, 3, 0)
                    Set(LF_MashStarted, 1)
                EndIf
            EndIf
            IfEq(LF_MashStarted, 1)
                IfEq(LVar0, FALSE)
                    Set(LF_MashEnded, 1)
                    BreakLoop
                EndIf
            EndIf
            Wait(1)
        EndLoop
        IfEq(LF_MashEnded, 1)
            KillThread(LVarA)
            Goto(10)
        EndIf
        IfEq(LF_MashEnded, 0)
            ExecGetTID(N(animHold), LVarA)
            Loop(30)
                Call(CheckButtonDown, BUTTON_A, LVar0)
                IfEq(LVar0, FALSE)
                    Set(LF_MashEnded, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LF_MashEnded, 1)
                KillThread(LVarA)
                Goto(10)
            EndIf
        EndIf
    EndIf
    Label(10)
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    Wait(2)
    Call(CloseActionCommandInfo)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOMBETTE_BODY_SLAM)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BodySlam)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
        Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
        Thread
            Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 15, 0)
            Set(LVar0, 0)
            Loop(10)
                Add(LVar0, -72)
                Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
                Wait(1)
            EndLoop
            Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        EndThread
        Call(AddGoalPos, ACTOR_PARTNER, 60, 0, 0)
        Call(RunToGoal, ACTOR_PARTNER, 10)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        Thread
            Call(N(SlowDown))
        EndThread
        Wait(20)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(5.0))
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Run)
        Call(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        Return
    EndIf
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BODY_SLAM1)
            Set(LVarE, 1)
            Set(LVarF, 2)
        CaseEq(MOVE_BODY_SLAM2)
            Set(LVarE, 2)
            Set(LVarF, 3)
        CaseEq(MOVE_BODY_SLAM3)
            Set(LVarE, 3)
            Set(LVarF, 5)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOMBETTE_BODY_SLAM)
    Call(GetPartnerActionSuccess, LVar0)
    IfGt(LVar0, 0)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BodySlam)
        Call(RunToGoal, ACTOR_PARTNER, 3)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    Else
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(AddGoalPos, ACTOR_PARTNER, -10, 0, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_BodySlam)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
    EndIf
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP, 0, LVarF, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP, 0, LVarE, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(returnHome2))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_Bomb) = {
    Call(LoadActionCommand, ACTION_COMMAND_BOMB)
    Call(action_command_bomb_init)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BOMB)
            Call(GetActorLevel, ACTOR_PARTNER, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                CaseEq(1)
                    Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                CaseEq(2)
                    Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EndSwitch
        CaseEq(MOVE_POWER_BOMB)
            Call(GetActorLevel, ACTOR_PARTNER, LVar0)
            Switch(LVar0)
                CaseEq(1)
                    Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
                CaseEq(2)
                    Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EndSwitch
        CaseEq(MOVE_MEGA_BOMB)
            Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    EndSwitch
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_48)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BOMB)
            Call(InitTargetIterator)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
        CaseEq(MOVE_POWER_BOMB)
            Call(InitTargetIterator)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
        CaseEq(MOVE_MEGA_BOMB)
            Call(InitTargetIterator)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(AddGoalPos, ACTOR_PARTNER, -40, 0, 0)
    EndSwitch
    Call(MoveBattleCamOver, 60 * DT)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BOMB)
            Call(action_command_bomb_start, 0, 57 * DT, 3, 0)
        CaseEq(MOVE_POWER_BOMB)
            Call(action_command_bomb_start, 0, 73 * DT - 1, 3, 1)
        CaseEq(MOVE_MEGA_BOMB)
            Call(action_command_bomb_start, 0, 87 * DT, 3, 2)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LRAW_BOMBETTE_FUSE)
    ChildThread
        Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 1)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_RunLit)
        Call(GetMenuSelection, LVar0, LVar1, LVar2)
        Switch(LVar2)
            CaseEq(MOVE_BOMB)
                Set(LVar0, 45 * DT)
            CaseEq(MOVE_POWER_BOMB)
                Set(LVar0, 50 * DT)
            CaseEq(MOVE_MEGA_BOMB)
                Set(LVar0, 50 * DT)
        EndSwitch
        Call(RunToGoal, ACTOR_PARTNER, 45 * DT)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_AboutToExplode)
        Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    EndChildThread
    Switch(LVar2)
        CaseEq(MOVE_BOMB)
            Set(LVar0, 45 * DT)
        CaseEq(MOVE_POWER_BOMB)
            Set(LVar0, 50 * DT)
        CaseEq(MOVE_MEGA_BOMB)
            Set(LVar0, 50 * DT)
    EndSwitch
    Wait(LVar0)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BOMB)
            Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Call(StopSound, SOUND_LRAW_BOMBETTE_FUSE)
    Switch(LVar2)
        CaseEq(MOVE_BOMB)
            Set(LVar0, 6 * DT + 1)
        CaseEq(MOVE_POWER_BOMB)
            Set(LVar0, 12 * DT)
        CaseEq(MOVE_MEGA_BOMB)
            Set(LVar0, 20 * DT)
    EndSwitch
    Loop(LVar0)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(0.5), 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(-0.5), 0, 0)
        Wait(1)
    EndLoop
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 8)
    Call(GetActionSuccessCopy, LVar0)
    Call(N(GetBombDamage), LVar0)
    Set(LVarA, LVar0)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(N(PlayExplosionFX), LVar0, LVar1, LVar2)
    Thread
        Call(GetMenuSelection, LVar0, LVar1, LVar2)
        Switch(LVar2)
            CaseEq(MOVE_BOMB)
                IfGt(LVarA, 0)
                    Call(StartRumble, BTL_RUMBLE_HIT_HEAVY)
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.75))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 10, Float(4.5))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 10, Float(6.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 3, Float(2.25))
                    Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.2))
                    Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.45))
                    Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.15))
                Else
                    Call(StartRumble, BTL_RUMBLE_HIT_HEAVY)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.4))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.4))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.2))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(1.2))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.64))
                    Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.24))
                    Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.08))
                EndIf
            CaseEq(MOVE_POWER_BOMB)
                IfGt(LVarA, 0)
                    Call(StartRumble, BTL_RUMBLE_HIT_EXTREME)
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.75))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 10, Float(4.5))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 10, Float(6.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 3, Float(2.25))
                    Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.2))
                    Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.45))
                    Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.15))
                Else
                    Call(StartRumble, BTL_RUMBLE_HIT_EXTREME)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.4))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(2.4))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.2))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(1.2))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.64))
                    Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.24))
                    Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.08))
                EndIf
            CaseEq(MOVE_MEGA_BOMB)
                IfGt(LVarA, 0)
                    Call(StartRumble, BTL_RUMBLE_HIT_MAX)
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(4.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 10, Float(6.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(4.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 10, Float(8.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(4.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 3, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.6))
                    Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.2))
                Else
                    Call(StartRumble, BTL_RUMBLE_HIT_MAX)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(4.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(1.5))
                    Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.8))
                    Call(ShakeCam, CAM_BATTLE, 0, 3, Float(0.3))
                    Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.1))
                EndIf
        EndSwitch
    EndThread
    Thread
        Call(GetMenuSelection, LVar0, LVar1, LVar2)
        Switch(LVar2)
            CaseEq(MOVE_BOMB)
            CaseEq(MOVE_POWER_BOMB)
                Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
                Wait(8)
                IfGt(LVarA, 0)
                    PlayEffect(EFFECT_RED_IMPACT, 0, LVar0, 0, LVar2, 1, 0, 0)
                Else
                    PlayEffect(EFFECT_RED_IMPACT, 1, LVar0, 0, LVar2, 1, 0, 0)
                EndIf
            CaseEq(MOVE_MEGA_BOMB)
                Set(LVarA, 0)
                Wait(10)
                Call(N(PlayExplosionFX), 88, 33, 5)
                Wait(10)
                Call(N(PlayExplosionFX), 18, 73, 5)
                Wait(10)
                Call(N(PlayExplosionFX), 120, 19, 5)
                Wait(10)
        EndSwitch
    EndThread
    Set(LF_MashEnded, 0)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BOMB)
            Call(SetGoalToTarget, ACTOR_PARTNER)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOMBETTE_BLAST_LV1)
            Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            IfEq(LVar0, 6)
                BreakSwitch
            EndIf
            Call(GetActionSuccessCopy, LVar0)
            Call(N(GetBombDamage), LVar0)
            Switch(LVar0)
                CaseGt(0)
                    Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarF, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                    Set(LF_MashEnded, 1)
                CaseDefault
                    Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
            EndSwitch
        CaseEq(MOVE_POWER_BOMB)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOMBETTE_BLAST_LV1)
            Label(5)
                Call(SetGoalToTarget, ACTOR_PARTNER)
                Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
                IfEq(LVar0, 6)
                    Goto(6)
                EndIf
                Call(GetActionSuccessCopy, LVar0)
                Call(N(GetPowerBombDamage), LVar0)
                Switch(LVar0)
                    CaseGt(0)
                        Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                        Set(LF_MashEnded, 1)
                    CaseDefault
                        Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                EndSwitch
                Label(6)
                Call(ChooseNextTarget, ITER_NEXT, LVar0)
                IfNe(LVar0, ITER_NO_MORE)
                    Goto(5)
                EndIf
        CaseEq(MOVE_MEGA_BOMB)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOMBETTE_BLAST_LV3)
            Label(10)
                Call(SetGoalToTarget, ACTOR_PARTNER)
                Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
                IfEq(LVar0, 6)
                    Goto(11)
                EndIf
                Call(GetActionSuccessCopy, LVar0)
                Call(N(GetMegaBombDamage), LVar0)
                Switch(LVar0)
                    CaseGt(0)
                        Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                        Set(LF_MashEnded, 1)
                    CaseDefault
                        Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                EndSwitch
                Label(11)
                Wait(5)
                Call(ChooseNextTarget, ITER_NEXT, LVar0)
                IfNe(LVar0, ITER_NO_MORE)
                    Goto(10)
                EndIf
    EndSwitch
    IfGt(LF_MashEnded, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
        Call(MoveBattleCamOver, 10)
    Else
        Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EndIf
    Set(LVar0, 0)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(1)
        CaseOrEq(3)
            Thread
                Set(LVar0, 0)
                Loop(80)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Add(LVar0, 33)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Add(LVar1, 200)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            Wait(50)
            Call(PartnerYieldTurn)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar0, 25)
            Add(LVar1, 200)
            Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.6))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_FirstStrike) = {
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(AddGoalPos, ACTOR_PARTNER, -20, 0, 0)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_LRAW_BOMBETTE_FUSE)
    Call(UseBattleCamPresetImmediately, BTL_CAM_PRESET_11)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_AboutToExplode)
    Wait(5)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Wait(10)
    Call(StopSound, SOUND_LRAW_BOMBETTE_FUSE)
    Loop(7)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(0.5), 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(-0.5), 0, 0)
        Wait(1)
    EndLoop
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    Set(LVarA, 0)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(N(PlayExplosionFX), LVar0, LVar1, LVar2)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 8)
    Thread
        Call(StartRumble, BTL_RUMBLE_HIT_HEAVY)
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.75))
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(4.5))
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(6.0))
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 3, Float(2.25))
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.2))
        Call(ShakeCam, CAM_BATTLE, 0, 6, Float(0.45))
        Call(ShakeCam, CAM_BATTLE, 0, 8, Float(0.15))
    EndThread
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOMBETTE_BLAST_LV1)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(10)
    EndIf
    Set(LVarF, 1)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_BODY_SLAM1)
            Set(LVarF, 5)
        CaseEq(MOVE_BODY_SLAM2)
            Set(LVarF, 6)
        CaseEq(MOVE_BODY_SLAM3)
            Set(LVarF, 7)
    EndSwitch
    Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    Label(10)
    Set(LVar0, 0)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(1)
        CaseOrEq(3)
            Thread
                Set(LVar0, 0)
                Loop(80)
                    Wait(1)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Add(LVar0, 33)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Add(LVar1, 200)
            Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_LINEAR)
            Wait(50)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Add(LVar0, 25)
            Add(LVar1, 200)
            Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
            Call(SetGoalToHome, ACTOR_PARTNER)
            Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
            Call(SetActorJumpGravity, ACTOR_PARTNER, Float(0.6))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Aftermath)
            Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBombette_Idle)
        EndCaseGroup
    EndSwitch
    Return
    End
};
