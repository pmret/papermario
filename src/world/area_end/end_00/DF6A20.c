#include "end_00.h"

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240020_DF6A20);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240270_DF6C70);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240540_DF6F40);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_8024081C_DF721C);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240AE8_DF74E8);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240EB0_DF78B0);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80240FEC_DF79EC);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802411CC_DF7BCC);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80241294_DF7C94);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802414CC_DF7ECC);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80241768_DF8168);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802419F8_DF83F8);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80241B34_DF8534);

static char* N(exit_str_0) = "end_01";

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_802421D8_DF8BD8);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242358_DF8D58);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242500_DF8F00);

ApiStatus func_80242558_DF8F58(ScriptInstance* script, s32 isInitialCall) {
    func_80242500_DF8F00();
    load_font(1);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242580_DF8F80);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242680_DF9080);

ApiStatus func_80242744_DF9144(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 a1 = *args++;

    set_variable(script, a1, _heap_malloc(&gSpriteHeapPtr, var1));
    return ApiStatus_DONE2;
}

ApiStatus func_802427A4_DF91A4(ScriptInstance* script, s32 isInitialCall) {
    _heap_free(&gSpriteHeapPtr, get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802427D8_DF91D8(ScriptInstance* script, s32 isInitialCall) {
    Camera* camera = &gCameras[gCurrentCameraID];

    camera->unk_506 = 1;
    camera->movePos.x += 0.6666667f;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242830_DF9230);

INCLUDE_ASM(s32, "world/area_end/end_00/DF6A20", func_80242898_DF9298);
