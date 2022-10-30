#include "obk_08.h"

static char* N(exit_str_0) = "obk_01";

ApiStatus func_802408A0_BD4110(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* ptr = heap_malloc(4); // todo what is this

    npc->blur.any = ptr;
    *ptr = NULL;
    npc->planarFlyDist = 125.0f;
    npc->yaw = 0.0f;
    npc->pos.x = 0.0f;
    npc->pos.y = -875.0f;
    npc->pos.z = 0.0f;
    npc->duration = 60;
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

void func_80240920_BD4190(Npc* npc) {
    if (npc->yaw > 340.0f || npc->yaw < 20.0f) {
        npc->renderMode = RENDER_MODE_ALPHATEST;
        npc->unk_A2 = 0;
        func_8003D624(npc, 0, 0, 0, 0, 0, npc->unk_A2);
    } else {
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        func_8003D624(npc, 7, gPlayerStatusPtr->alpha1, 0, 0, 0, npc->unk_A2);
        npc->unk_9A = 255;
    }
}

void func_802409E8_BD4258(void) {
    func_80240920_BD4190(get_npc_unsafe(1));
    func_80240920_BD4190(get_npc_unsafe(2));
    func_80240920_BD4190(get_npc_unsafe(3));
    func_80240920_BD4190(get_npc_unsafe(4));
    func_80240920_BD4190(get_npc_unsafe(5));
    func_80240920_BD4190(get_npc_unsafe(6));
    func_80240920_BD4190(get_npc_unsafe(7));
    func_80240920_BD4190(get_npc_unsafe(8));
}

void func_80240A7C_BD42EC(void) {
    get_npc_unsafe(1)->unk_A2 = 0;
    get_npc_unsafe(2)->unk_A2 = 0;
    get_npc_unsafe(3)->unk_A2 = 0;
    get_npc_unsafe(4)->unk_A2 = 0;
    get_npc_unsafe(5)->unk_A2 = 0;
    get_npc_unsafe(6)->unk_A2 = 0;
    get_npc_unsafe(7)->unk_A2 = 0;
    get_npc_unsafe(8)->unk_A2 = 0;
}

ApiStatus func_80240AF0_BD4360(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* temp_s2 = npc->blur.any;
    s32 temp_v0;

    switch (script->functionTemp[1]) {
        case 0:
            temp_v0 = evt_get_variable(script, AreaFlag(8));
            if (temp_v0 == 1) {
                *temp_s2 = temp_v0;
                script->functionTemp[1] = 10;
            }
            break;
        case 10:
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = 11;
            }
            break;
        case 11:
            if (npc->pos.y <= -920.0f) {
                func_802409E8_BD4258();
            }
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->pos.y -= 0.5f;
            if (npc->pos.y <= -988.0f) {
                evt_set_variable(script, MapVar(1), 1);
                func_80240A7C_BD42EC();
                script->functionTemp[1] = 12;
            }
            break;
        case 12:
            if (evt_get_variable(script, MapVar(2)) == 1) {
                script->functionTemp[1] = 13;
            }
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case 13:
            if (evt_get_variable(script, MapVar(2)) == 0) {
                script->functionTemp[1] = 12;
            }
            break;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240CA0_BD4510(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->blur.any = get_npc_unsafe(0);
    script->functionTemp[2] = script->owner2.npcID * 45;
    npc->flags |= NPC_FLAG_40000;
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD4110", func_80240D10_BD4580);

ApiStatus func_80240FD8_BD4848(Evt* script, s32 isInitialCall) {
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80240FE4_BD4854(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(script->owner2.npcID);

    switch (script->functionTemp[1]) {
        case 0:
            npc->duration = rand_int(180) + 30;
            npc->pos.z = -430.0f;
            npc->pos.y = rand_int(50) + 40.0f;
            npc->moveSpeed = (2.0f * rand_float()) + 2.0f;
            if (rand_int(100) < 50) {
                npc->pos.x = 270.0f;
                npc->yaw = 270.0f;
            } else {
                npc->pos.x = -270.0f;
                npc->yaw = 90.0f;
            }
            script->functionTemp[1] = 1;
            break;
        case 1:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = 2;
            }
            break;
        case 2:
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (npc->pos.x < -280.0f || npc->pos.x > 280.0f) {
                script->functionTemp[1] = 0;
            }
            break;
    }
    return ApiStatus_DONE2;
}

extern s16 D_80244FEC_BD885C[];

ApiStatus func_8024116C_BD49DC(Evt* script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var1 = script->varTable[1];
    s32 temp;

    if (var1 == 0) {
        script->functionTemp[2] = D_80244FEC_BD885C[rand_int(3)];
        var1 = rand_int(50) + 30;
    }
    var1--;

    temp = script->functionTemp[2];
    if (var0 < temp) {
        var0 += 10;
        if (temp < var0) {
            var0 = temp;
        }
    }
    if (temp < var0) {
        var0 -= 10;
        if (var0 < temp) {
            var0 = temp;
        }
    }

    script->varTable[0] = var0;
    script->varTable[1] = var1;
    return ApiStatus_DONE2;
}
