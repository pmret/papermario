#include "dead.h"
#include "common.h"

#define NAMESPACE EDC020

extern s32 D_802429E0[];

#import "world/common/DeadFoliage.inc.c"

INCLUDE_ASM(s32, "EDC020", func_8024027C_EDC25C);

#include "world/common/DeadGetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

INCLUDE_ASM(s32, "EDC020", func_802403F0_EDC3D0);

INCLUDE_ASM(s32, "EDC020", func_802405C0_EDC5A0);

INCLUDE_ASM(s32, "EDC020", func_80240614_EDC5F4);

ApiStatus func_8024064C_EDC62C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802429E0[i] = ptr[i];
        }
        D_802429E0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802429E0[i] = i + 16;
            D_802429E0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
