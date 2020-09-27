#include "common.h"

typedef struct {
/* 0x00 */ s32 unk_00;
/* 0x04 */ s32 unk_04;
/* 0x08 */ s16 unk_08;
/* 0x0A */ s16 unk_0A;
/* 0x0C */ f32 unk_0C;
/* 0x10 */ f32 unk_10;
/* 0x14 */ f32 unk_14;
/* 0x18 */ f32 unk_18;
/* 0x1C */ f32 unk_1C;
/* 0x20 */ f32 unk_20;
/* 0x24 */ f32 unk_24;
/* 0x28 */ f32 unk_28;
/* 0x2C */ s32* unk_2C;
/* 0x30 */ s32* unk_30;
/* 0x34 */ s32 unk_34;
/* 0x38 */ s32* unk_38;
/* 0x3C */ s32 unk_3C;
} DoorStuff;

ApiStatus func_80281C20(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* thisPos = script->ptrReadPos;

    func_800EF414(get_variable(script, *thisPos++), get_variable(script, *thisPos++));
    func_800EF394(0.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80281C84(ScriptInstance* script, s32 isInitialCall) {
    func_800EF3E4();
    func_800EF3A4();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_7E2AA0", MakeDoorAdvanced);

INCLUDE_ASM(s32, "code_7E2AA0", func_802822A8);

ApiStatus func_80282314(ScriptInstance* script, s32 isInitialCall) {
    script->functionTemp[1] = script->varTable[1];
    return ApiStatus_DONE2;
}

ApiStatus func_80282324(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = *(UNK_TYPE*)script->functionTemp[1];
    return ApiStatus_DONE2;
}

ApiStatus func_80282338(ScriptInstance* script, s32 isInitialCall) {
    UNK_TYPE* temp_s0 = script->functionTemp[1];

    *temp_s0 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_7E2AA0", func_8028236C);

INCLUDE_ASM(s32, "code_7E2AA0", func_802823B0);

INCLUDE_ASM(s32, "code_7E2AA0", func_80282414);

#ifdef NON_MATCHING
ApiStatus func_80282594(ScriptInstance* script, s32 isInitialCall) {
    Camera* camera;
    Camera* camera2;
    f32 temp_f0;

    temp_f0 = get_float_variable(script, *script->ptrReadPos);
    camera = &gCameras[0];
    camera2 = &gCameras[0];

    if (temp_f0 >= 0.0f) {
        D_80286540 = camera->moveSpeed;
        camera2->moveSpeed = temp_f0;
    } else {
        camera2->moveSpeed = D_80286540;
    }
    
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_7E2AA0", func_80282594);
#endif

ApiStatus func_802825FC(ScriptInstance* script, s32 isInitialCall) {
    D_80151310 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_80282610(ScriptInstance* script, s32 isInitialCall) {
    D_80151310 = 2;
    return ApiStatus_DONE2;
}

ApiStatus func_80282624(ScriptInstance* script, s32 isInitialCall) {
    D_80151310 = 0;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_7E2AA0", func_80282634);

INCLUDE_ASM(s32, "code_7E2AA0", func_80282700);

INCLUDE_ASM(s32, "code_7E2AA0", func_80282774);

INCLUDE_ASM(s32, "code_7E2AA0", func_802827A8);
/*ApiStatus func_802827A8(ScriptInstance* script, s32 isInitialCall) {
    func_80134230(script->functionTemp[1]->unkA);
    return ApiStatus_DONE2;
}*/

ApiStatus func_802827CC(ScriptInstance* script, s32 isInitialCall) {
    DoorStuff* temp = script->functionTemp[1];

    script->varTable[2] = temp->unk_04;
    script->varTable[3] = temp->unk_0C;
    script->varTable[4] = temp->unk_10;
    script->varTable[5] = temp->unk_14;
    script->varTable[6] = temp->unk_18;
    script->varTable[7] = temp->unk_1C;
    script->varTable[8] = temp->unk_20;
    script->varTable[9] = temp->unk_24;
    script->varTable[10] = temp->unk_28;
    script->varTable[11] = temp->unk_2C;
    script->varTable[12] = temp->unk_30;
    script->varTable[13] = temp->unk_34;
    script->varTable[14] = temp->unk_38;
    script->varTable[15] = temp->unk_3C;
    return ApiStatus_DONE2;
}

ApiStatus func_80282868(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[1] = script->functionTemp[1];
    return ApiStatus_DONE2;
}
