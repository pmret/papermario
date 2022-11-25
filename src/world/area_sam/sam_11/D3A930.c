#include "sam_11.h"
#include "model.h"

extern s32 D_80243CC0_D3E290;
extern s32 D_80243CC4_D3E294;
extern s32 D_80243CC8_D3E298;

// needs data migration + some issues with the return values
#ifdef NON_EQUIVALENT
ApiStatus func_80240360_D3A930(Evt* script, s32 isInitialCall) {
    u8 r, g, b, a;
    u8 alpha;
    s32 temp_a2;

    if (isInitialCall) {
        func_8011B950(script->varTable[1], -1, 1, 1);
        script->functionTemp[0] = 0;
        get_background_color_blend(&r, &g, &b, &a);
        if ((script->varTable[0] != 0) || (a != 255)) {
            if (script->varTable[0] == 1 && a == 0) {
                return ApiStatus_DONE2;
            }
        } else {
            return ApiStatus_DONE2;
        }
    }

    script->functionTemp[0] += script->varTable[2];
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }
    if (script->varTable[0] == 0) {
        alpha = script->functionTemp[0];
    } else {
        alpha = ~script->functionTemp[0];
    }
    a = alpha;
    set_background_color_blend(0, 0, 0, a);
    temp_a2 = 255 - a;
    r = (D_80243CC0_D3E290 * temp_a2) / 255;
    g = (D_80243CC4_D3E294 * temp_a2) / 255;
    b = (D_80243CC8_D3E298 * temp_a2) / 255;
    gCameras[CAM_DEFAULT].bgColor[0] = r;
    gCameras[CAM_DEFAULT].bgColor[1] = g;
    gCameras[CAM_DEFAULT].bgColor[2] = b;
    if (script->functionTemp[0] >= 255) {
        if (script->varTable[0] == 1) {
            func_8011B950(script->varTable[1], -1, 0, 1);
        }

        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_sam/sam_11/D3A930", func_80240360_D3A930);
#endif

ApiStatus func_8024052C_D3AAFC(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 1;
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_sam_11
ApiStatus N(Set80151310_2)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 2;
    return ApiStatus_DONE2;
}

ApiStatus N(Set80151310_0)(Evt* script, s32 isInitialCall) {
    gEntityHideMode = 0;
    return ApiStatus_DONE2;
}
#define NAMESPACE sam_11

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

ApiStatus func_8024059C_D3AB6C(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 xComp, zComp;
    f32 x, y, z;
    f32 hitDepth;

    if (isInitialCall) {
        script->functionTemp[1] = 10;
    }
    playerStatus->targetYaw = 270.0f;
    script->functionTemp[1] += 4;
    xComp = (script->functionTemp[1] / 10) * sin_deg(playerStatus->targetYaw);
    zComp = (script->functionTemp[1] / 10) * -cos_deg(playerStatus->targetYaw);
    x = playerStatus->position.x + xComp;
    y = playerStatus->position.y + playerStatus->colliderHeight * 0.5f;
    z = playerStatus->position.z + zComp;
    hitDepth = 500.0f;

    if (npc_raycast_down_sides(0, &x, &y, &z, &hitDepth)) {
        if (hitDepth < 100.0f) {
            playerStatus->position.x = x;
            playerStatus->position.y = y;
            playerStatus->position.z = z;
            return ApiStatus_BLOCK;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8024072C_D3ACFC(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & (PS_FLAGS_INPUT_DISABLED | PS_FLAGS_NO_STATIC_COLLISION)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240754_D3AD24(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPosition.y == 385) {
        evt_set_variable(script, MapVar(7), 0);
    }
    if (playerStatus->lastGoodPosition.y == 150) {
        evt_set_variable(script, MapVar(7), 1);
    }
    return ApiStatus_BLOCK;
}
