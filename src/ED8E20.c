#include "dead.h"
#include "common.h"

extern s16 D_80169B12;
extern GameStatus* D_80079430;
extern f32 D_800B8DEC;

typedef struct DokanModelInfo {
    /* 0x00 */ s32 no;
    /* 0x04 */ Vec3f position;
} DokanModelInfo;

ApiStatus func_80240000_ED8E20(Evt* script, s32 isInitialCall) {
    PlayerStatus* status;

    status = gPlayerStatusPtr;
    status->animFlags |= 0x100000;
    return ApiStatus_DONE2;
}

ApiStatus func_80240020_ED8E40(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s32)D_80169B12;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "ED8E20", func_80240034_ED8E54);

INCLUDE_ASM(s32, "ED8E20", func_802400F0_ED8F10);

// Something off with the pointers? Not sure if functionally equivalent.
/*
ApiStatus func_802400F0_ED8F10(Evt* script, s32 isInitialCall) {
    s32 temp_s1;
    Model* temp_s2;

    temp_s2 = func_8005F128();
    temp_s1 = evt_get_variable(script, EVT_VAR(0)) * 0x10;
    evt_set_variable(script, EVT_VAR(1), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->no);
    evt_set_variable(script, EVT_VAR(2), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->position.x);
    evt_set_variable(script, EVT_VAR(3), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->position.y);
    evt_set_variable(script, EVT_VAR(4), (s32) ((DokanModelInfo*)temp_s2->extData + temp_s1)->position.z);
    osSyncPrintf("[%d] dokan get pos  (no=%d)  pos=%d, %d, %d,  dir=%d\n\0\0\0flo_23\0\0flo_12\0\0flo_11", D_80079430->frameCounter, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4]);
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "ED8E20", func_80240208_ED9028);

// Bad constant? Not sure if functionally equivalent.
/*
ApiStatus func_80240208_ED9028(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s32) clamp_angle(*(&D_800B8DEC + (gCurrentCameraID * 0x558)) + 180.0f);
    return ApiStatus_DONE2;
}
*/

ApiStatus func_80240274_ED9094(Evt* script, s32 isInitialCall) {
    f32 sp14;
    f32 sp10;
    f32* temp_a0;
    f32 temp_f20;
    f32 temp_a2;

    temp_a0 = &sp10;
    temp_a2 = evt_get_float_variable(script, *script->ptrReadPos);
    sp10 = gPlayerStatus.position.x;
    sp14 = gPlayerStatus.position.z;
    temp_f20 = gPlayerStatus.position.y;
    add_vec2D_polar(temp_a0, &sp14, temp_a2, gPlayerStatus.targetYaw);
    evt_set_float_variable(script, 0xFE363C80, sp10);
    evt_set_float_variable(script, 0xFE363C81, temp_f20);
    evt_set_float_variable(script, 0xFE363C82, sp14);
    return ApiStatus_DONE2;
}

ApiStatus func_80240318_ED9138(Evt* script, s32 isInitialCall) {
    func_80077BD0(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
