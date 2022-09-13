#include "kkj_00.h"

static char* N(exit_str_0) = "kkj_01";
static char* N(exit_str_1) = "kkj_19";

extern f32 D_8024160C_ABC89C;
extern f32 D_8024162C_ABC8BC;

ApiStatus func_80240000_ABB290(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(NULL, GB_StoryProgress) >= 96) {
        gGameStatusPtr->playerSpriteSet = 2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80240040_ABB2D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    PlayerStatus* status = &gPlayerStatus;

    if (evt_get_variable(script, *args++) == 0) {
        status->slideParams = &D_8024160C_ABC89C;
    } else {
        status->slideParams = &D_8024162C_ABC8BC;
    }

    status->flags |= PS_FLAGS_10;
    return ApiStatus_DONE2;
}
