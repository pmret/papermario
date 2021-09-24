#include "dead.h"
#include "common.h"

#define NAMESPACE ECAA80

extern s32 D_802462F0[];

INCLUDE_ASM(s32, "ECAA80", func_80240D80_ECAA80);

INCLUDE_ASM(s32, "ECAA80", func_80241364_ECB064);

INCLUDE_ASM(s32, "ECAA80", func_802414C8_ECB1C8);

INCLUDE_ASM(s32, "ECAA80", func_8024150C_ECB20C);

INCLUDE_ASM(s32, "ECAA80", func_80241770_ECB470);

INCLUDE_ASM(s32, "ECAA80", func_802417CC_ECB4CC);

INCLUDE_ASM(s32, "ECAA80", func_8024199C_ECB69C);

INCLUDE_ASM(s32, "ECAA80", func_802419F0_ECB6F0);

ApiStatus func_80241A28_ECB728(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802462F0[i] = ptr[i];
        }
        D_802462F0[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_802462F0[i] = i + 128;
            D_802462F0[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "ECAA80", func_80241AC4_ECB7C4);

INCLUDE_ASM(s32, "ECAA80", func_80241B88_ECB888);

INCLUDE_ASM(s32, "ECAA80", func_80241BF8_ECB8F8);
