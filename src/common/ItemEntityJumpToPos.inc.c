#include "common.h"

ApiStatus N(ItemEntityJumpToPos)(Evt* script, s32 isInitialCall) {
    struct JumpState {
     /* 0x00 */ Vec3f pos;
     /* 0x0C */ f32 moveAngle;
     /* 0x10 */ f32 jumpAccel;
     /* 0x14 */ f32 moveSpeed;
     /* 0x18 */ f32 jumpVelocity;
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
        moveDist = dist2D(item->position.x, item->position.z, jumpState->pos.x, jumpState->pos.z);
        jumpState->moveAngle = atan2(item->position.x, item->position.z, jumpState->pos.x, jumpState->pos.z);

        temp_f2 = item->position.y;
        jumpState->jumpVelocity = (jumpState->jumpAccel * jumpState->moveTime * 0.5f)
             + ((jumpState->pos.y - temp_f2) / jumpState->moveTime);

        temp_f2 = jumpState->moveTime;
        jumpState->moveSpeed = moveDist / temp_f2;
    }

    jumpState = script->functionTemp[0];
    item = get_item_entity(jumpState->itemEntityIndex);
    if (!item) {
        heap_free((void*) script->functionTemp[0]);
        return ApiStatus_DONE2;
    }

    item->position.x += (jumpState->moveSpeed * sin_deg(jumpState->moveAngle));
    item->position.z -= (jumpState->moveSpeed * cos_deg(jumpState->moveAngle));
    item->position.y +=  jumpState->jumpVelocity;
    jumpState->moveTime--;
    jumpState->jumpVelocity = (jumpState->jumpVelocity - jumpState->jumpAccel);
    if (jumpState->moveTime < 0) {
        item->position.x = jumpState->pos.x;
        item->position.y = jumpState->pos.y;
        item->position.z = jumpState->pos.z;
        jumpState->jumpVelocity = 0.0f;
        heap_free((void*) script->functionTemp[0]);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}
