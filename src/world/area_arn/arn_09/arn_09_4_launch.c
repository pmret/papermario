#include "arn_09.h"
#include "sprite/player.h"

EvtScript N(EVS_LaunchPlayer) = {
    EVT_IF_EQ(AF_ARN_01, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(AF_ARN_01, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_FALLING)
    EVT_CALL(func_802D2484)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.5))
    EVT_CALL(PlayerJump, 50, 0, 0, 16)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_SET(AF_ARN_01, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
