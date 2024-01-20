#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/player.h"

s32 N(D_802A10F0)[] = {
    9, 3, 9, 3, 9, 3, 8, 3,
    7, 3, 6, 2, 5, 2, 4, 2,
};

API_CALLABLE(N(UnkMoveFunc1)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 posX = playerActor->curPos.x;
    f32 posY = playerActor->curPos.y;
    f32 posZ = playerActor->curPos.z;
    f32 goalX = playerActor->state.goalPos.x;
    f32 goalY = playerActor->state.goalPos.y;
    f32 goalZ = playerActor->state.goalPos.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] > 20) {
        script->varTable[0] = 20;
    }

    if (battleStatus->actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED) {
        if (script->varTable[0] < 6) {
            script->varTable[0] = 6;
        }
    } else if (script->varTable[0] < 12) {
        script->varTable[0] = 12;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_CheckForAPress) = {
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    Loop(5)
        Call(CheckButtonPress, BUTTON_A, LVar0)
        IfEq(LVar0, TRUE)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_JumpSupport_Approach) = {
    Call(SetGoalToFirstTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Sub(LVar3, Float(70.0))
    IfLt(LVar0, LVar3)
        Set(LVar3, LVar0)
    EndIf
    Call(SetGoalPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ATTACK_APPROACH)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(5.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(CancelablePlayerRunToGoal, 0, LVar0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    ExecWait(N(EVS_CheckForAPress))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
    Return
    End
};

EvtScript N(EVS_JumpSupport_B) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
    Call(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
    IfGt(LVar6, LVar7)
        Sub(LVar6, LVar7)
    Else
        Sub(LVar7, LVar6)
        Set(LVar6, LVar7)
    EndIf
    Sub(LVar6, 20)
    DivF(LVar6, Float(10.588))
    AddF(LVar6, 15)
    Set(LVarA, LVar6)
    Return
    End
};

EvtScript N(EVS_JumpSupport_C) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
    Call(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
    IfGt(LVar6, LVar7)
        Sub(LVar6, LVar7)
    Else
        Sub(LVar7, LVar6)
        Set(LVar6, LVar7)
    EndIf
    Sub(LVar6, 20)
    DivF(LVar6, Float(22.5))
    AddF(LVar6, 15)
    Set(LVarA, LVar6)
    Return
    End
};

EvtScript N(EVS_JumpSupport_D) = {
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
    Call(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
    IfGt(LVar6, LVar7)
        Sub(LVar6, LVar7)
    Else
        Sub(LVar7, LVar6)
        Set(LVar6, LVar7)
    EndIf
    Sub(LVar6, 20)
    DivF(LVar6, Float(18.0))
    AddF(LVar6, 22)
    Set(LVarA, LVar6)
    Return
    End
};

EvtScript N(EVS_JumpSupport_E) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(func_802693F0)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.3))
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(UnkMoveFunc1))
    Call(func_80273444, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(func_80273444, 6, 0, 2)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(5)
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_JumpSupport_F) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(func_802693F0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 50)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.8))
    Call(N(UnkMoveFunc1))
    Call(func_80273444, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    Call(func_80273444, 6, 0, 2)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(2)
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_JumpSupport_G) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_29)
    Call(func_802693F0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(N(UnkMoveFunc1))
    Call(func_80273444, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(func_80273444, 6, 0, 2)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(2)
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_JumpSupport_H) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(func_802693F0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.8))
    Call(N(UnkMoveFunc1))
    Call(func_80273444, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(func_80273444, 6, 0, 2)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(2)
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_JumpSupport_I) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(func_802693F0)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Hurt, ANIM_Mario1_Hurt, ANIM_Mario1_Land)
    Call(N(UnkMoveFunc1))
    Call(func_80273444, LVar0, 0, 0)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.0))
    EndChildThread
    Call(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    Call(func_80273444, 8, 0, 2)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.0))
    EndChildThread
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 6, 0, 2)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.0))
    EndChildThread
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(func_80273444, 4, 0, 2)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};

EvtScript N(EVS_JumpSupport_Miss) = {
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, 0, 0, ANIM_Mario1_SpinFall)
    Call(PlayerLandJump)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_SpinFall)
    Wait(2)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TRIP)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
    Wait(20)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(func_802693F0)
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Call(PlayerYieldTurn)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};

// load the action command
EvtScript N(EVS_JumpSupport_InitCommand) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(EVS_JumpSupport_Approach))
    ExecWait(N(EVS_JumpSupport_B))
    Call(action_command_jump_start, LVarA, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_34)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    Call(func_80274A18, LVarA, 0)
    Return
    End
};

EvtScript N(EVS_JumpSupport_L) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(EVS_JumpSupport_Approach))
    Call(InitTargetIterator)
    ExecWait(N(EVS_JumpSupport_C))
    Set(LVarB, LVarA)
    Add(LVarB, 14)
    Add(LVarB, -3)
    Call(action_command_jump_start, LVarB, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_37)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    Call(func_802752AC, LVarA, 0)
    Wait(7)
    Call(GetPlayerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(func_802752AC, 3, 1)
        CaseDefault
            Call(func_802752AC, 5, 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_JumpSupport_M) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(EVS_JumpSupport_Approach))
    ExecWait(N(EVS_JumpSupport_D))
    Call(SetActionDifficultyTable, Ref(N(D_802A10F0)))
    Set(LVarB, LVarA)
    Sub(LVarB, 4)
    Add(LVarB, -3)
    Call(action_command_jump_start, LVarB, 3)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_38)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioW2_Carried, ANIM_MarioB1_Stomp)
    Call(func_80275F00, LVarA, 0)
    Call(CloseActionCommandInfo)
    Set(LVar9, 0)
    Call(GetPlayerActionSuccess, LVar0)
    IfGt(LVar0, 0)
        Set(LVar9, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Stomp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
        Wait(2)
        Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        Call(LoadActionCommand, ACTION_COMMAND_JUMP)
        Call(action_command_jump_init)
        Call(action_command_jump_start, 13, 3)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_39)
        Call(func_80275F00, 15, 2)
        Goto(10)
    Else
        Call(LoadActionCommand, ACTION_COMMAND_JUMP)
        Call(action_command_jump_init)
        Call(action_command_jump_start, 2, 3)
        Call(func_80275F00, 4, 1)
        Goto(10)
    EndIf
    Label(10)
    Return
    End
};
