#include "dead.h"
#include "common.h"
#include "EB1920.c"

#define NAMESPACE EB1170

void func_80059AC8(s32, s32); // extern
s32 *func_8002BFD4(s32); // extern
void func_8002C01C(s32*); // extern

extern s32 D_80244494;
extern s16 D_80169B12;

extern Camera D_800B8DEC[];

typedef struct arg80240310_EB1170 {
    /* 0x00 */ char unk_00[0x84];
    /* 0x84 */ s32 unk_84[0x10];
} arg80240310_EB1170;

ApiStatus func_80240310_EB1170(arg80240310_EB1170* arg0) {
    int i;

    if (D_80241780_EB25E0 == NULL) {
        s32* dest = func_8002BFD4(0x40);
        D_80241780_EB25E0 = dest;

        for (i = 0; i < 0x10; ++i) {
            dest[i] = arg0->unk_84[i];
        }
    } else {
        s32* source = D_80241780_EB25E0;
        for (i = 0; i < 0x10; ++i) {
            arg0->unk_84[i] = source[i];
        }

        func_8002C01C(D_80241780_EB25E0);
        D_80241780_EB25E0 = NULL;
    }

    return ApiStatus_DONE2;
}

#include "world/common/DeadGetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

ApiStatus func_80240484_EB12E4(Evt* event) {
    f32 angle;
    f32 distance3;
    f32 distance2;
    f32 distance1;
    Bytecode var1;
    Bytecode var2;
    Bytecode var3;

    Bytecode* readPos = event->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    var1 = *readPos++;
    distance1 = (f32) evt_get_variable(event, var1);

    var2 = *readPos++;
    distance2 = (f32) evt_get_variable(event, var2);

    var3 = *readPos++;
    distance3 = (f32) evt_get_variable(event, var3);

    angle = gCameras[gCurrentCameraID].currentYaw;

    if (playerStatus->spriteFacingAngle == 0.0f) {
        angle = angle - 100.0f;
    } else {
        angle = angle + 100.0f;
    }

    angle = clamp_angle(angle);
    distance1 = distance1 + (sin_deg(angle) * 15.0f);
    distance2 = distance2 + playerStatus->colliderHeight * 0.5f;
    distance3 = distance3 - (cos_deg(angle) * 15.0f);

    evt_set_variable(event, var1, (s32) distance1);
    evt_set_variable(event, var2, (s32) distance2);
    evt_set_variable(event, var3, (s32) distance3);

    return ApiStatus_DONE2;
}


ApiStatus func_80240654_EB14B4(Evt* event, s32 arg1) {
    Bytecode* readPos = event->ptrReadPos;

    if (arg1 != 0) {
        D_802417E4_EB2644 = 0;
    }

    if (D_802417E4_EB2644 != 0) {
        D_802417E4_EB2644 = 0;
        evt_set_variable(event, *readPos, D_802417E8_EB2648);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}


ApiStatus func_802406A8_EB1508(Evt* event) {
    D_802417E8_EB2648 = evt_get_variable(event, *event->ptrReadPos);
    D_802417E4_EB2644 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802406E0_EB1540(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802442D0[i] = ptr[i];
        }
        D_802442D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802442D0[i] = i + 16;
            D_802442D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8024077C_EB15DC(Evt *event) {
    s32 *readPos;

    readPos = event->ptrReadPos;
    event->varTable[2] = evt_get_variable(event, *readPos++);
    event->varTable[3] = evt_get_variable(event, *readPos++);
    event->varTable[4] = evt_get_variable(event, *readPos++);
    event->varTable[5] = evt_get_variable(event, *readPos++);
    event->varTable[6] = evt_get_variable(event, *readPos++);
    event->varTable[7] = evt_get_variable(event, *readPos++);
    event->varTable[8] = evt_get_variable(event, *readPos++);
    event->varTable[9] = evt_get_variable(event, *readPos++);
    event->varTable[10] = evt_get_variable(event, *readPos++);
    event->varTable[11] = evt_get_variable(event, *readPos++);
    return ApiStatus_DONE2;
}



//INCLUDE_ASM(s32, "EB1170", func_8024086C_EB16CC);
#include "world/common/UnkYawFunc.inc.c"


ApiStatus func_802409F8_EB1858(ActorPart* actor) {
    Npc *npc;

    npc = get_npc_unsafe(actor->unk_8C);
    D_80244494 = npc->currentAnim.w;
    npc->currentAnim.w = actor->idleAnimations;
    return ApiStatus_DONE2;
}

ApiStatus func_80240A3C_EB189C(ActorPart* actor) {
    get_npc_unsafe(actor->unk_8C)->currentAnim.w = D_80244494;
    return ApiStatus_DONE2;
}

ApiStatus func_80240A68_EB18C8(void) {
    func_80059AC8(0, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_80240A8C_EB18EC(Evt* event) {
    evt_set_variable(event, *event->ptrReadPos, (s32) D_80169B12);
    return ApiStatus_DONE2;
}
