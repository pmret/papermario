#include "common.h"

API_CALLABLE(N(ItemEntityJumpToPos)) {
    struct {
        /* 0x00 */ Vec3f pos;
        /* 0x0C */ f32 moveAngle;
        /* 0x10 */ f32 jumpAccel;
        /* 0x14 */ f32 moveSpeed;
        /* 0x18 */ f32 jumpVel;
        /* 0x1C */ s32 moveTime;
        /* 0x20 */ s32 itemEntityIndex;
    }* jumpState;
    Bytecode* args = script->ptrReadPos;
    ItemEntity* item;
    f32 moveDist;
    f32 temp_f2;

    if (isInitialCall) {
        jumpState = heap_malloc(sizeof(*jumpState));
        script->functionTemp[0] = (s32) jumpState;
        jumpState->itemEntityIndex = evt_get_variable(script, *args++);
        jumpState->pos.x = evt_get_float_variable(script, *args++);
        jumpState->pos.y = evt_get_float_variable(script, *args++);
        jumpState->pos.z = evt_get_float_variable(script, *args++);
        jumpState->moveTime = evt_get_variable(script, *args++);
        jumpState->jumpAccel = evt_get_float_variable(script, *args++);
        item = get_item_entity(jumpState->itemEntityIndex);
        moveDist = dist2D(item->pos.x, item->pos.z, jumpState->pos.x, jumpState->pos.z);
        jumpState->moveAngle = atan2(item->pos.x, item->pos.z, jumpState->pos.x, jumpState->pos.z);

        temp_f2 = item->pos.y;
        jumpState->jumpVel = (jumpState->jumpAccel * jumpState->moveTime * 0.5f)
             + ((jumpState->pos.y - temp_f2) / jumpState->moveTime);

        temp_f2 = jumpState->moveTime;
        jumpState->moveSpeed = moveDist / temp_f2;
    }

    jumpState = (void*) script->functionTemp[0];
    item = get_item_entity(jumpState->itemEntityIndex);
    if (!item) {
        heap_free((void*) script->functionTemp[0]);
        return ApiStatus_DONE2;
    }

    item->pos.x += (jumpState->moveSpeed * sin_deg(jumpState->moveAngle));
    item->pos.z -= (jumpState->moveSpeed * cos_deg(jumpState->moveAngle));
    item->pos.y +=  jumpState->jumpVel;
    jumpState->moveTime--;
    jumpState->jumpVel = (jumpState->jumpVel - jumpState->jumpAccel);
    if (jumpState->moveTime < 0) {
        item->pos.x = jumpState->pos.x;
        item->pos.y = jumpState->pos.y;
        item->pos.z = jumpState->pos.z;
        jumpState->jumpVel = 0.0f;
        heap_free((void*) script->functionTemp[0]);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}
