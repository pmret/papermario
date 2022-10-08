#include "nok_02.h"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_802438D0_9DA8F0);

#define NAMESPACE dup2_nok_02
#include "world/common/GetNpcCollisionHeight.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup2_nok_02
#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE nok_02

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243BEC_9DAC0C);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243C40_9DAC60);

extern s32 nok_02_D_80254BA0[];

ApiStatus func_80243C78_9DAC98(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            nok_02_D_80254BA0[i] = ptr[i];
        }
        nok_02_D_80254BA0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            nok_02_D_80254BA0[i] = i + 16;
            nok_02_D_80254BA0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 nok_02_D_80254D68[];

ApiStatus func_80243D14_9DAD34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            nok_02_D_80254D68[i] = ptr[i];
        }
        nok_02_D_80254D68[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            nok_02_D_80254D68[i] = i + 128;
            nok_02_D_80254D68[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#define NAMESPACE dup2_nok_02
#include "world/common/StashVars.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup2_nok_02
#include "world/common/GetItemName.inc.c"
#define NAMESPACE nok_02

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243EC8_9DAEE8);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243F10_9DAF30);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244078_9DB098);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244224_9DB244);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244288_9DB2A8);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_802442E0_9DB300);
