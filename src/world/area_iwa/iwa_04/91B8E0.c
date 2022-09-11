#include "iwa_04.h"

static char* N(exit_str_0) = "iwa_02";
static char* N(exit_str_1) = "sbk_99";

ApiStatus func_80240000_91B8E0(Evt* script, s32 isInitialCall) {
    s32 status = -1;
    
    if (gPlayerStatus.lastGoodPosition.y > -100.0) {
        status = 0;
    }
    if (gPlayerStatus.lastGoodPosition.y < -240.0) {
        status = 1;
    }
    if (status >= 0) {
        evt_set_variable(script, MapVar(9), status);
    }
    
    return ApiStatus_BLOCK;
}

#include "world/common/enemy/CleftAI.inc.c"

ApiStatus func_80241060_91C940(Evt* script, s32 isInitialCall) {
    gCameras[CAM_DEFAULT].unk_498 = 1.0f;
    return ApiStatus_BLOCK;
}

ApiStatus func_8024107C_91C95C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = resolve_npc(script, NPC_SELF);
    npc->renderYaw = (f32) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}
