#include "obk_08.h"

ApiStatus func_80240840_BD40B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    start_rumble(0x64, evt_get_variable(script, *args++) & 0xFFFF);
    return ApiStatus_DONE2;
}

ApiStatus func_80240870_BD40E0(Evt* script, s32 isInitialCall) {
    set_item_entity_flags(script->varTable[0], 0x80000);
    return ApiStatus_DONE2;
}

