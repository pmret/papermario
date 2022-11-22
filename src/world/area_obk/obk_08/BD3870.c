#include "obk_08.h"

#include "world/common/todo/UnkFoldFunc.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD3870", func_802403DC_BD3C4C);

ApiStatus func_802404F0_BD3D60(Evt* script, s32 isInitialCall) {
    UnkEntityStruct* temp_v0 = (UnkEntityStruct*) evt_get_variable(NULL, MapVar(10));

    func_8013A854(temp_v0->foldID);
    free_worker(temp_v0->entityID);
    heap_free(temp_v0);
    evt_set_variable(script, MapVar(10), NULL);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD3870", func_8024055C_BD3DCC);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD3870", func_8024061C_BD3E8C);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD3870", func_802406DC_BD3F4C);

INCLUDE_ASM(s32, "world/area_obk/obk_08/BD3870", func_8024079C_BD400C);

ApiStatus func_80240808_BD4078(Evt* script, s32 isInitialCall) {
    if (gPlayerData.curHP < 2) {
        return ApiStatus_DONE2;
    }
    gPlayerData.curHP--;
    return ApiStatus_DONE2;
}
