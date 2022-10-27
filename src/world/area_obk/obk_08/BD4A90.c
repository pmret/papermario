#include "obk_08.h"

ApiStatus func_80241220_BD4A90(Evt* script, s32 isInitialCall) {
    Npc* npc1 = get_npc_unsafe(0xB);
    Npc* npc2 = get_npc_unsafe(0);

    npc1->pos.x = npc2->pos.x;
    npc1->pos.z = npc2->pos.z;
    npc_move_heading(npc1, npc2->planarFlyDist, script->varTable[0]);
    npc1->pos.y = npc2->pos.y + 1000.0f + 25.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_802412BC_BD4B2C(Evt* script, s32 isInitialCall) {
    script->varTable[0] = clamp_angle(script->varTable[0] - 2);
    return ApiStatus_DONE2;
}

ApiStatus func_80241300_BD4B70(Evt* script, s32 isInitialCall) {
    Npc* npc1 = get_npc_unsafe(1);
    Npc* npc2 = get_npc_unsafe(2);
    Npc* npc3 = get_npc_unsafe(3);
    Npc* npc4 = get_npc_unsafe(4);
    Npc* npc5 = get_npc_unsafe(5);
    Npc* npc6 = get_npc_unsafe(6);
    Npc* npc7 = get_npc_unsafe(7);
    Npc* npc8 = get_npc_unsafe(8);
    s32 outVal = 0;

    script->varTable[1] = FALSE;

    evt_set_variable(script, MapVar(3), 0);
    if (npc1->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc1->yaw) {
        script->varTable[1] = TRUE;
        outVal = 1;
    }
    if (npc2->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc2->yaw) {
        script->varTable[1] = TRUE;
        outVal = 2;
    }
    if (npc3->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc3->yaw) {
        script->varTable[1] = TRUE;
        outVal = 3;
    }
    if (npc4->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc4->yaw) {
        script->varTable[1] = TRUE;
        outVal = 4;
    }
    if (npc5->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc5->yaw) {
        script->varTable[1] = TRUE;
        outVal = 5;
    }
    if (npc6->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc6->yaw) {
        script->varTable[1] = TRUE;
        outVal = 6;
    }
    if (npc7->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc7->yaw) {
        script->varTable[1] = TRUE;
        outVal = 7;
    }
    if (npc8->yaw <= script->varTable[0] - 23 && script->varTable[0] - 27 <= npc8->yaw) {
        script->varTable[1] = TRUE;
        outVal = 8;
    }
    evt_set_variable(script, MapVar(3), outVal);
    return ApiStatus_DONE2;
}

ApiStatus func_80241658_BD4EC8(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 dist = dist2D(playerStatus->position.x, playerStatus->position.z, 0.0f, 0.0f);
    Npc npc;
    f32 temp_a2;
    s32 gt;
    s32 lt;

    if (!(dist > 90.0f)) {
        gt = FALSE;
    } else {
        gt = TRUE;
    }

    if (!(dist < 150.0f)) {
        lt = FALSE;
    } else {
        lt = TRUE;
    }

    if ((gt | lt) != 0) {
        temp_a2 = atan2(playerStatus->position.x, playerStatus->position.z, 0.0f, 0.0f) + 180.0f;
        npc.pos.x = 0.0f;
        npc.pos.y = 0.0f;
        npc.pos.z = 0.0f;
        npc_move_heading(&npc, 80.0f, temp_a2);
        script->varTable[0] = npc.pos.x;
        script->varTable[1] = npc.pos.y;
        script->varTable[2] = npc.pos.z;
        script->varTable[3] = 1;
    } else {
        script->varTable[0] = playerStatus->position.x;
        script->varTable[1] = playerStatus->position.y;
        script->varTable[2] = playerStatus->position.z;
        script->varTable[3] = 0;
    }
    return ApiStatus_DONE2;
}
