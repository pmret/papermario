#include "pra_19.h"

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_19/D6E9D0", func_8024114C_D6FAFC);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

extern s32 D_802479F0[];

ApiStatus func_802411D8_D6FB88(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802479F0[i] = ptr[i];
        }
        D_802479F0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802479F0[i] = i + 16;
            D_802479F0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_80247BB8_pra_19[];

ApiStatus func_80241274_D6FC24(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80247BB8_pra_19[i] = ptr[i];
        }
        D_80247BB8_pra_19[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80247BB8_pra_19[i] = i + 128;
            D_80247BB8_pra_19[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/PlayBigSmokePuff.inc.c"

ApiStatus func_802413A4_D6FD54(Evt* script, s32 isInitialCall) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 var_s1 = evt_get_variable(script, *args++) == 0;
    Encounter* encounter;

    if (evt_get_variable(script, *args++) == 0) {
        var_s1 += 1;
    }
    if (evt_get_variable(script, *args++) == 0) {
        var_s1 += 1;
    }
    if (evt_get_variable(script, *args++) == 0) {
        var_s1 += 1;
    }

    switch (var_s1) {
        case 1:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2101;
            break;
        case 2:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2102;
            break;
        case 3:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2103;
            break;
        case 4:
            encounter = currentEncounter->encounterList[enemy->encounterIndex];
            encounter->battle = 0x2104;
            break;
    }
    return ApiStatus_DONE2;
}

void func_802415E0_D6FF90(void* data);
void func_80241530_D6FEE0(void);

ApiStatus func_802414F4_D6FEA4(Evt* script, s32 isInitialCall) {
    script->array[0] = create_generic_entity_world(0, func_80241530_D6FEE0);
    return ApiStatus_DONE2;
}

void func_80241530_D6FEE0(void) {
    RenderTask rt;
    RenderTask* rtPtr = &rt;
    Npc* npc = get_npc_safe(5);

    if (gPlayerStatusPtr->flags & PS_FLAGS_HAS_REFLECTION) {
        s32 x, y, z;

        get_screen_coords(gCurrentCamID, npc->pos.x, npc->pos.y, -npc->pos.z, &x, &y, &z);
        rtPtr->renderMode = npc->renderMode;
        rtPtr->distance = -z;
        rtPtr->appendGfxArg = npc;
        rtPtr->appendGfx = func_802415E0_D6FF90;
        queue_render_task(rtPtr);
    }
}

void func_802415E0_D6FF90(void* data) {
    Npc* npc = data;
    Matrix4f sp18, sp58, sp98;

    npc_get_render_yaw(npc);
    guRotateF(sp18, npc->renderYaw + gCameras[gCurrentCamID].currentYaw, 0.0f, 1.0f, 0.0f);
    guScaleF(sp98, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_F);
    guMtxCatF(sp18, sp98, sp18);
    guTranslateF(sp58, npc->pos.x, npc->pos.y, npc->pos.z);
    guMtxCatF(sp18, sp58, sp18);
    spr_update_player_sprite(2, npc->currentAnim, 1.0f);
    spr_draw_player_sprite(2, 0, 0, 0, sp18);
}

ApiStatus func_802416F8_D700A8(Evt* script, s32 isInitialCall) {
    gPlayerStatus.spriteFacingAngle = script->varTable[0];
    return ApiStatus_DONE2;
}

ApiStatus func_80241710_D700C0(Evt* script, s32 isInitialCall) {
    Npc* npc1 = resolve_npc(script, script->varTable[3]);
    Npc* npc2 = resolve_npc(script, script->varTable[4]);

    npc1->collisionRadius = npc2->collisionRadius;
    npc1->collisionHeight = npc2->collisionHeight;
    return ApiStatus_DONE2;
}


ApiStatus func_8024175C_D7010C(Evt* script, s32 isInitialCall) {
    Npc* npc0 = get_npc_unsafe(0);
    Npc* npc1 = get_npc_unsafe(1);
    Npc* npc2 = get_npc_unsafe(2);
    Npc* npc3 = get_npc_unsafe(3);
    Npc* npc4 = get_npc_unsafe(4);
    f32 playerX = gPlayerStatus.position.x;

    if (npc0->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc1->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc2->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc3->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    if (npc4->pos.x < playerX) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;;
}

ApiStatus func_80241838_D701E8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(evt_get_variable(script, *args++));

    if (isInitialCall) {
        script->varTable[10] = evt_get_variable(script, *args++);
        script->varTable[11] = 8;
        script->varTable[12] = evt_get_variable(script, *args++);
        if (npc->pos.x < script->varTable[10]) {
            script->varTable[13] = 0;
        } else {
            script->varTable[13] = 1;
        }
    }

    if (script->varTable[13] == 0) {
        if (npc->pos.x >= script->varTable[10]) {
            npc->pos.x = script->varTable[10];
            return ApiStatus_DONE2;
        }
        npc->pos.x += script->varTable[11];
    } else {
        if (npc->pos.x <= script->varTable[10]) {
            npc->pos.x = script->varTable[10];
            return ApiStatus_DONE2;
        }
        npc->pos.x -= script->varTable[11];
    }

    if (script->varTable[12] == 0) {
        script->varTable[11] += 2;
        if (script->varTable[11] >= 14) {
            script->varTable[11] = 14;
        }
    } else {
        script->varTable[11] -= 2;
        if (script->varTable[11] <= 8) {
            script->varTable[11] = 8;
        }
    }
    return ApiStatus_BLOCK;
}
