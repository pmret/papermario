#include "common.h"
#include "script_api/battle.h"
#include "battle/action_cmd/jump.h"
#include "sprite/player.h"

s32 N(D_802A10F0)[] = {
    9, 3, 9, 3, 9, 3, 8, 3,
    7, 3, 6, 2, 5, 2, 4, 2,
};

API_CALLABLE(N(CalcJumpReboundTime)) {
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

    if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED) {
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

EvtScript N(EVS_JumpSupport_CalcJumpTime) = {
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

EvtScript N(EVS_JumpSupport_CalcJumpTime_Alt1) = {
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

EvtScript N(EVS_JumpSupport_CalcJumpTime_Alt2) = {
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

EvtScript N(EVS_JumpSupport_Rebound) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(func_802693F0)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.3))
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(CalcJumpReboundTime))
    Call(PlayerHopToGoal, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(PlayerHopToGoal, 6, 0, 2)
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
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(func_802693F0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 50)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.8))
    Call(N(CalcJumpReboundTime))
    Call(PlayerHopToGoal, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    Call(PlayerHopToGoal, 6, 0, 2)
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
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_MISTAKE)
    Call(func_802693F0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(N(CalcJumpReboundTime))
    Call(PlayerHopToGoal, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(PlayerHopToGoal, 6, 0, 2)
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

EvtScript N(EVS_JumpSupport_UnusedRebound) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(func_802693F0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.8))
    Call(N(CalcJumpReboundTime))
    Call(PlayerHopToGoal, LVar0, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(1)
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(PlayerHopToGoal, 6, 0, 2)
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

EvtScript N(EVS_JumpSupport_BouncingRebound) = {
    Call(PlayerYieldTurn)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(EnablePlayerBlur, ACTOR_BLUR_RESET)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(func_802693F0)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Hurt, ANIM_Mario1_Hurt, ANIM_Mario1_Land)
    Call(N(CalcJumpReboundTime))
    Call(PlayerHopToGoal, LVar0, 0, 0)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.0))
    EndChildThread
    Call(AddGoalPos, ACTOR_PLAYER, -30, 0, 0)
    Call(PlayerHopToGoal, 8, 0, 2)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.0))
    EndChildThread
    Call(AddGoalPos, ACTOR_PLAYER, -20, 0, 0)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayerHopToGoal, 6, 0, 2)
    ChildThread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.0))
    EndChildThread
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(PlayerHopToGoal, 4, 0, 2)
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
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
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
EvtScript N(EVS_JumpSupport_ApproachAndJump) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(EVS_JumpSupport_Approach))
    ExecWait(N(EVS_JumpSupport_CalcJumpTime))
    Call(action_command_jump_start, LVarA, AC_DIFFICULTY_3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_JUMP_MIDAIR)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_MarioB1_Stomp)
    Call(PlayerBasicJumpToGoal, LVarA, PLAYER_BASIC_JUMP_0)
    Return
    End
};

EvtScript N(EVS_JumpSupport_UnusedSuper) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(EVS_JumpSupport_Approach))
    Call(InitTargetIterator)
    ExecWait(N(EVS_JumpSupport_CalcJumpTime_Alt1))
    Set(LVarB, LVarA)
    Add(LVarB, 14)
    Add(LVarB, -3)
    Call(action_command_jump_start, LVarB, AC_DIFFICULTY_3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_SUPER_JUMP_MIDAIR)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Sit, ANIM_Mario1_SpinJump)
    Call(PlayerSuperJumpToGoal, LVarA, PLAYER_SUPER_JUMP_0)
    Wait(7)
    Call(GetPlayerActionQuality, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(PlayerSuperJumpToGoal, 3, PLAYER_SUPER_JUMP_1)
        CaseDefault
            Call(PlayerSuperJumpToGoal, 5, PLAYER_SUPER_JUMP_1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_JumpSupport_UnusedUltra) = {
    Call(LoadActionCommand, ACTION_COMMAND_JUMP)
    Call(action_command_jump_init)
    ExecWait(N(EVS_JumpSupport_Approach))
    ExecWait(N(EVS_JumpSupport_CalcJumpTime_Alt2))
    Call(SetActionDifficultyTable, Ref(N(D_802A10F0)))
    Set(LVarB, LVarA)
    Sub(LVarB, 4)
    Add(LVarB, -3)
    Call(action_command_jump_start, LVarB, AC_DIFFICULTY_3)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ULTRA_JUMP_MIDAIR)
    Call(SetGoalToTarget, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_MarioW2_Carried, ANIM_MarioB1_Stomp)
    Call(PlayerUltraJumpToGoal, LVarA, PLAYER_ULTRA_JUMP_0)
    Call(InterruptActionCommand)
    Set(LVar9, 0)
    Call(GetPlayerActionQuality, LVar0)
    IfGt(LVar0, 0)
        Set(LVar9, 1)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Stomp)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
        Wait(2)
        Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        Call(LoadActionCommand, ACTION_COMMAND_JUMP)
        Call(action_command_jump_init)
        Call(action_command_jump_start, 13, AC_DIFFICULTY_3)
        Call(UseBattleCamPreset, BTL_CAM_PLAYER_UNUSED_ULTRA_JUMP)
        Call(PlayerUltraJumpToGoal, 15, PLAYER_ULTRA_JUMP_2)
        Goto(10)
    Else
        Call(LoadActionCommand, ACTION_COMMAND_JUMP)
        Call(action_command_jump_init)
        Call(action_command_jump_start, 2, AC_DIFFICULTY_3)
        Call(PlayerUltraJumpToGoal, 4, PLAYER_ULTRA_JUMP_1)
        Goto(10)
    EndIf
    Label(10)
    Return
    End
};
