#include "pra_13.h"

#include "../common/Reflection.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);
#include "world/common/todo/ItemChoice_WaitForSelection.inc.c"

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

BSS s32 D_80243720[114];
BSS s32 pra_13_802438E8[92];

ApiStatus func_802411D8_D657B8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80243720[i] = ptr[i];
        }
        D_80243720[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80243720[i] = i + 16;
            D_80243720[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80241274_D65854(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            pra_13_802438E8[i] = ptr[i];
        }
        pra_13_802438E8[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            pra_13_802438E8[i] = i + 128;
            pra_13_802438E8[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/PlayBigSmokePuff.inc.c"

ApiStatus func_802413A4_D65984(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    get_npc_safe(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

void func_8024140C_D659EC(void);
void func_802414BC_D65A9C(void* npc);

ApiStatus func_802413D0_D659B0(Evt* script, s32 isInitialCall) {
    script->array[0] = create_worker_world(0, func_8024140C_D659EC);
    return ApiStatus_DONE2;
}

void func_8024140C_D659EC(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    Npc* npc = get_npc_safe(0);

    if (gPlayerStatusPtr->flags & PS_FLAG_HAS_REFLECTION) {
        s32 x, y, z;

        get_screen_coords(gCurrentCamID, npc->pos.x, npc->pos.y, -npc->pos.z, &x, &y, &z);
        rtPtr->renderMode = npc->renderMode;
        rtPtr->distance = -z;
        rtPtr->appendGfxArg = npc;
        rtPtr->appendGfx = func_802414BC_D65A9C;
        queue_render_task(rtPtr);
    }
}

void func_802414BC_D65A9C(void* data) {
    Npc* npc = data;
    Matrix4f sp18, sp58, sp98, spD8;

    npc_get_render_yaw(npc);
    guRotateF(sp18, npc->renderYaw + gCameras[gCurrentCamID].currentYaw, 0.0f, 1.0f, 0.0f);
    guScaleF(spD8, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
    guMtxCatF(sp18, spD8, sp18);
    guTranslateF(sp58, npc->pos.x, npc->pos.y, npc->pos.z);
    guMtxCatF(sp18, sp58, sp18);
    spr_update_player_sprite(PLAYER_SPRITE_AUX2, npc->currentAnim, 1.0f);
    spr_draw_player_sprite(PLAYER_SPRITE_AUX2, 0, 0, 0, sp18);
}
