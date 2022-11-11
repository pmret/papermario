#include "obk_04.h"

static char* N(exit_str_0) = "obk_03";

ApiStatus func_80240050_BC7EB0(Evt* script, s32 isInitialCall) {
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

void func_802400D0_BC7F30(Npc* npc) {
    if (npc->yaw > 340.0f || npc->yaw < 20.0f) {
        npc->renderMode = RENDER_MODE_ALPHATEST;
        npc->unk_A2 = 0;
        func_8003D624(npc, 0, 0, 0, 0, 0, npc->unk_A2);
    } else {
        npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
        func_8003D624(npc, 7, gPlayerStatusPtr->alpha1, 255, 0, 0, npc->unk_A2);
        npc->unk_9A = 255;
    }
}

void func_80240198_BC7FF8(void) {
    func_802400D0_BC7F30(get_npc_unsafe(1));
    func_802400D0_BC7F30(get_npc_unsafe(2));
    func_802400D0_BC7F30(get_npc_unsafe(3));
    func_802400D0_BC7F30(get_npc_unsafe(4));
    func_802400D0_BC7F30(get_npc_unsafe(5));
    func_802400D0_BC7F30(get_npc_unsafe(6));
    func_802400D0_BC7F30(get_npc_unsafe(7));
    func_802400D0_BC7F30(get_npc_unsafe(8));
}

void func_8024022C_BC808C(void) {
    get_npc_unsafe(1)->unk_A2 = 0;
    get_npc_unsafe(2)->unk_A2 = 0;
    get_npc_unsafe(3)->unk_A2 = 0;
    get_npc_unsafe(4)->unk_A2 = 0;
    get_npc_unsafe(5)->unk_A2 = 0;
    get_npc_unsafe(6)->unk_A2 = 0;
    get_npc_unsafe(7)->unk_A2 = 0;
    get_npc_unsafe(8)->unk_A2 = 0;
}

s32 func_802402A0_BC8100(s32 arg0) {
    s32 ret = 12;

    switch (arg0) {
        case 0:
            ret = 12;
            break;
        case 1:
            ret = 100;
            break;
        case 2:
            ret = 13;
            break;
        case 3:
            ret = 14;
            break;
    }
    return ret;
}

ApiStatus func_802402F4_BC8154(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    s32* temp_s3 = npc->blur.any;
    s32 temp_v0;

    switch (script->functionTemp[1]) {
        case 0:
            temp_v0 = evt_get_variable(script, MapVar(1));
            if (temp_v0 == 1) {
                *temp_s3 = temp_v0;
                script->functionTemp[1] = 10;
            }
            break;
        case 1:
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
                func_80240198_BC7FF8();
            }
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            npc->pos.y -= 0.5f;
            if (npc->pos.y <= -988.0f) {
                evt_set_variable(script, MapVar(2), 1);
                func_8024022C_BC808C();
                script->functionTemp[1] = 12;
            }
            break;
        case 12:
            script->functionTemp[1] = func_802402A0_BC8100(evt_get_variable(script, MapVar(3)));
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case 13:
            script->functionTemp[1] = func_802402A0_BC8100(evt_get_variable(script, MapVar(3)));
            npc->yaw = clamp_angle(npc->yaw - 2.0f);
            break;
        case 14:
            evt_set_variable(script, MapVar(3), 0);
            npc->duration++;
            if (npc->duration == 50) {
                script->functionTemp[1] = 15;
            }
            npc->planarFlyDist -= 2.0f;
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case 15:
            npc->duration--;
            if (npc->duration == 0) {
                script->functionTemp[1] = 12;
            }
            npc->planarFlyDist += 2.0f;
            npc->yaw = clamp_angle(npc->yaw + 2.0f);
            break;
        case 100:
            script->functionTemp[1] = func_802402A0_BC8100(evt_get_variable(script, MapVar(3)));
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802405B4_BC8414(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->blur.any = get_npc_unsafe(0); // TODO what is this?
    script->functionTemp[2] = script->owner2.npcID * 45;
    npc->flags |= NPC_FLAG_40000;
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

// float regalloc
#ifdef NON_MATCHING
ApiStatus func_80240624_BC8484(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);
    Npc* npc2 = npc->blur.any;
    f32 temp_f10;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f6;
    s32* temp_s2;
    f32 yaw;
    f32 new_var;
    f32 f1;


    temp_s2 = npc2->blur.any;
    switch (script->functionTemp[1]) {
        case 0:
            npc->yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            if (*temp_s2 == 1) {
                script->functionTemp[1] = 1;
                npc->duration = rand_int(20) + 10;
            }
            break;
        case 1:
            npc->yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            npc->duration--;
            if (npc->duration == 0) {
                sfx_play_sound_at_position(0xB000000F, 0, npc->pos.x, npc->pos.y, npc->pos.z);
                script->functionTemp[1] = 2;
                npc->duration = 0;
                npc->moveToPos.x = npc->pos.x;
                npc->moveToPos.y = npc->pos.y;
                npc->moveToPos.z = npc->pos.z;
            }
            break;
        case 2:
            npc->yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            new_var = npc->yaw;
            npc->pos.x = npc2->pos.x;
            npc->pos.z = npc2->pos.z;
            npc_move_heading(npc, npc2->planarFlyDist, new_var);
            temp_f4 = (40.0f - npc->duration) / 40.0f;
            temp_f12 = npc->pos.z;
            f1 = (npc->pos.x - npc->moveToPos.x) * (temp_f4 * temp_f4);
            temp_f6 = (npc->pos.z - npc->moveToPos.z) * (temp_f4 * temp_f4);
            temp_f2 = npc2->pos.y + 1000.0f;
            npc->pos.x -= f1;
            npc->pos.y = temp_f2;
            npc->pos.y -= (npc->pos.y - npc->moveToPos.y) * ((temp_f4 * temp_f4) * temp_f4);
            npc->pos.z = temp_f12 - temp_f6;
            npc->duration++;
            if (npc->duration == 40) {
                script->functionTemp[1] = 12;
            }
            break;
        case 12:
        case 13:
        case 14:
            yaw = clamp_angle(script->functionTemp[2] + npc2->yaw);
            npc->yaw = yaw;
            script->functionTemp[1] = func_802402A0_BC8100(evt_get_variable(script, MapVar(3)));
            npc->pos.x = npc2->pos.x;
            npc->pos.z = npc2->pos.z;
            npc_move_heading(npc, npc2->planarFlyDist, yaw);
            npc->pos.y = npc2->pos.y + 1000.0f;
            break;
        case 100:
            script->functionTemp[1] = func_802402A0_BC8100(evt_get_variable(script, MapVar(3)));
            break;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240624_BC8484);
#endif

ApiStatus func_80240910_BC8770(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.position.y < -50.0f) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

ApiStatus func_80240A58_BC88B8(Evt* script, s32 isInitialCall) {
    Npc* npc1 = get_npc_unsafe(1);
    Npc* npc2 = get_npc_unsafe(2);
    Npc* npc3 = get_npc_unsafe(3);
    Npc* npc4 = get_npc_unsafe(4);
    Npc* npc5 = get_npc_unsafe(5);
    Npc* npc6 = get_npc_unsafe(6);
    Npc* npc7 = get_npc_unsafe(7);
    Npc* npc8 = get_npc_unsafe(8);

    switch (script->varTable[0]) {
        case 0:
            script->varTable[0] = npc1->yaw;
            evt_set_variable(NULL, MapVar(5), 1);
            break;
        case 1:
            script->varTable[0] = npc2->yaw;
            evt_set_variable(NULL, MapVar(5), 2);
            break;
        case 2:
            script->varTable[0] = npc3->yaw;
            evt_set_variable(NULL, MapVar(5), 3);
            break;
        case 3:
            script->varTable[0] = npc4->yaw;
            evt_set_variable(NULL, MapVar(5), 4);
            break;
        case 4:
            script->varTable[0] = npc5->yaw;
            evt_set_variable(NULL, MapVar(5), 5);
            break;
        case 5:
            script->varTable[0] = npc6->yaw;
            evt_set_variable(NULL, MapVar(5), 6);
            break;
        case 6:
            script->varTable[0] = npc7->yaw;
            evt_set_variable(NULL, MapVar(5), 7);
            break;
        case 7:
            script->varTable[0] = npc8->yaw;
            evt_set_variable(NULL, MapVar(5), 8);
            break;
    }
    script->varTable[0] += script->varTable[1];
    return ApiStatus_DONE2;
}

ApiStatus func_80240C10_BC8A70(Evt* script, s32 isInitialCall) {
    Npc npc;

    npc.pos.x = 0;
    npc.pos.y = 0.0f;
    npc.pos.z = 0.0f;
    npc.planarFlyDist = 125.0f;
    npc_move_heading(&npc, 125.0f, script->varTable[0]);
    script->varTable[0] = npc.pos.x;
    script->varTable[1] = npc.pos.y + 10.0f;
    script->varTable[2] = npc.pos.z + 20.0f;
    return ApiStatus_DONE2;
}

ApiStatus func_80240CA0_BC8B00(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(evt_get_variable(NULL, MapVar(5)));

    script->varTable[0] = npc->pos.x;
    script->varTable[1] = npc->pos.y;
    script->varTable[2] = npc->pos.z;
    return ApiStatus_DONE2;
}

ApiStatus func_80240D00_BC8B60(Evt* script, s32 isInitialCall) {
    gPlayerData.bootsLevel = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_80240D14_BC8B74(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc npc;
    f32 dist = dist2D(playerStatus->position.x, playerStatus->position.z, 0.0f, 0.0f);
    f32 yaw;
    s32 gt, lt;

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
        yaw = atan2(playerStatus->position.x, playerStatus->position.z, 0.0f, 0.0f) + 180.0f;
        npc.pos.x = 0.0f;
        npc.pos.y = 0.0f;
        npc.pos.z = 0.0f;
        npc_move_heading(&npc, 80.0f, yaw);
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

ApiStatus func_80240E58_BC8CB8(Evt* script, s32 isInitialCall) {
    if (get_npc_unsafe(1)->duration == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
