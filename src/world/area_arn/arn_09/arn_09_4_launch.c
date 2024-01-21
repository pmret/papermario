#include "arn_09.h"
#include "sprite/player.h"

EvtScript N(EVS_LaunchPlayer) = {
    IfEq(AF_ARN_01, FALSE)
        Return
    EndIf
    Set(AF_ARN_01, TRUE)
    Call(DisablePlayerInput, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_FALLING)
    Call(func_802D2484)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Call(SetPlayerJumpscale, Float(1.5))
    Call(PlayerJump, 50, 0, 0, 16)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Set(AF_ARN_01, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
