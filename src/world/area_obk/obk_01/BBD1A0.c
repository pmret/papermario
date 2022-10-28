#include "obk_01.h"

static char* N(exit_str_0) = "mim_11";
static char* N(exit_str_1) = "obk_02";
static char* N(exit_str_2) = "obk_05";
static char* N(exit_str_3) = "obk_07";
static char* N(exit_str_4) = "obk_08";
static char* N(exit_str_5) = "obk_09";

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

ApiStatus func_80240038_BBD1D8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gCameras[CAM_DEFAULT].vfov = (s32) evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD1A0", func_8024007C_BBD21C);

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD1A0", func_80240098_BBD238);

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD1A0", func_802406AC_BBD84C);

INCLUDE_ASM(s32, "world/area_obk/obk_01/BBD1A0", func_80240730_BBD8D0);

ApiStatus func_80240790_BBD930(Evt* script, s32 isInitialCall) {
    ItemEntity* item = get_item_entity(script->varTable[0]);

    set_item_entity_flags(script->varTable[0], 0x80000);
    item->alpha = -1;
    return ApiStatus_DONE2;
}
