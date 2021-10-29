#include "common.h"
#include "npc.h"

extern s16 D_802809F8;

ApiStatus N(Set80218630_Var0)(Evt* script, s32 isInitialCall) {
    D_802809F8 = script->varTable[0];
    return ApiStatus_DONE2;
}
