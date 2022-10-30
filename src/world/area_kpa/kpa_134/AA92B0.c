#include "kpa_134.h"

ApiStatus func_80240310_AA92B0(Evt* script, s32 isInitialCall) {
    create_shadow_type(0, 50.0f, 115.0f, -34.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_8024033C_AA92DC(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState != ACTION_STATE_FALLING) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->position.x - 50.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->position.y - 150.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->position.z - -34.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    playerStatus->position.x = 50.0f;
    playerStatus->position.y = 150.0f;
    playerStatus->position.z = -34.0f;
    playerStatus->currentSpeed = 0.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80240408_AA93A8(Evt* script, s32 isInitialCall) {
    create_shadow_type(0, 680.0f, 240.0f, -35.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240434_AA93D4(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->actionState != ACTION_STATE_FALLING) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->position.x - 680.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->position.y - 275.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    if (fabs(playerStatus->position.z - -35.0f) > 14.0) {
        return ApiStatus_BLOCK;
    }

    playerStatus->position.x = 680.0f;
    playerStatus->position.y = 275.0f;
    playerStatus->position.z = -35.0f;
    playerStatus->currentSpeed = 0.0f;
    return ApiStatus_DONE2;
}
