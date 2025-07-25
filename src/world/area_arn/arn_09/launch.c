#include "arn_09.h"
#include "sprite/player.h"

EvtScript N(EVS_LaunchPlayer) = {
    IfEq(AF_ARN_01, false)
        Return
    EndIf
    Set(AF_ARN_01, true)
    Call(DisablePlayerInput, true)
    Call(SetPlayerActionState, ACTION_STATE_FALLING)
    Call(func_802D2484)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Call(SetPlayerJumpscale, Float(1.5))
    Call(PlayerJump, 50, 0, 0, 16)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Set(AF_ARN_01, false)
    Call(DisablePlayerInput, false)
    Return
    End
};
