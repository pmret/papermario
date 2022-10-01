#include "isk_11.h"

ApiStatus func_802400B0_98AAC0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemID = evt_get_variable(script, *args++);
    
    evt_set_variable(script, *args++, gItemTable[itemID & 0xFFF0FFFF].nameMsg);
    return ApiStatus_DONE2;
}
