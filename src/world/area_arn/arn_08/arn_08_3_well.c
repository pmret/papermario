#include "arn_08.h"
#include "sprite/player.h"

API_CALLABLE(N(AwaitPlayerFallDist)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 fallSpeed;
    s32 colliderID;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        suggest_player_anim_allow_backward(ANIM_Mario1_Jump);
    }

    fallSpeed = player_fall_distance();
    playerStatus->pos.y = player_check_collision_below(fallSpeed, &colliderID);
    script->functionTemp[0] += fabsf(fallSpeed);

    if (script->functionTemp[0] > 50) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(N(AwaitPlayerJumpDown)) {
    if (gPlayerStatus.pos.y < -10.0f) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_ExitWell) = {
    EVT_LOOP(0)
        EVT_IF_NE(GB_StoryProgress, STORY_CH3_HEART_ESCAPED_WELL)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(N(AwaitPlayerJumpDown))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(AwaitPlayerFallDist))
    EVT_SET(AF_ARN_01, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_WENT_DOWN_THE_WELL)
        EVT_SET(GB_StoryProgress, STORY_CH3_WENT_DOWN_THE_WELL)
    EVT_END_IF
    EVT_CALL(GotoMap, EVT_PTR("arn_09"), arn_09_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupHole) = {
    EVT_CALL(SetCamProperties, CAM_DEFAULT, EVT_FLOAT(90.0), 0, 0, 0, EVT_FLOAT(470.0), EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_EXEC(N(EVS_ExitWell))
    EVT_RETURN
    EVT_END
};
