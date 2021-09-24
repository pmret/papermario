#include "dead.h"
#include "common.h"

#define NAMESPACE EA8AE0

extern s32 D_80248388[];

#include "world/common/DeadUnkTexturePanFunc.inc.c"

#include "world/common/DeadUnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "EA8AE0", func_8024030C_EA8DEC);

INCLUDE_ASM(s32, "EA8AE0", func_80240358_EA8E38);

INCLUDE_ASM(s32, "EA8AE0", func_802404B8_EA8F98);

static char* N(exit_str_0) = "kmr_23";
static char* N(exit_str_1) = "kzn_18";
static char* N(exit_str_2) = "kzn_20";

INCLUDE_ASM(s32, "EA8AE0", func_802408C8_EA93A8);

INCLUDE_ASM(s32, "EA8AE0", func_80240908_EA93E8);

INCLUDE_ASM(s32, "EA8AE0", func_80240A14_EA94F4);

INCLUDE_ASM(s32, "EA8AE0", func_80240B00_EA95E0);

INCLUDE_ASM(s32, "EA8AE0", func_80240BD4_EA96B4);

INCLUDE_ASM(s32, "EA8AE0", func_80240CD8_EA97B8);

INCLUDE_ASM(s32, "EA8AE0", func_80240DA4_EA9884);

INCLUDE_ASM(s32, "EA8AE0", func_80240E2C_EA990C);

INCLUDE_ASM(s32, "EA8AE0", func_802413C0_EA9EA0);

INCLUDE_ASM(s32, "EA8AE0", func_802413FC_EA9EDC);

INCLUDE_ASM(s32, "EA8AE0", func_8024140C_EA9EEC);

INCLUDE_ASM(s32, "EA8AE0", func_80241468_EA9F48);

#include "world/common/DeadGetItemName.inc.c"

INCLUDE_ASM(s32, "EA8AE0", func_80241580_EAA060);

INCLUDE_ASM(s32, "EA8AE0", func_802415DC_EAA0BC);

INCLUDE_ASM(s32, "EA8AE0", func_802417AC_EAA28C);

INCLUDE_ASM(s32, "EA8AE0", func_80241800_EAA2E0);

ApiStatus func_80241838_EAA318(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80248388[i] = ptr[i];
        }
        D_80248388[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80248388[i] = i + 16;
            D_80248388[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "EA8AE0", func_802418D4_EAA3B4);

//INCLUDE_ASM(s32, "EA8AE0", func_802419C4_EAA4A4);
#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "EA8AE0", func_80241B50_EAA630);

INCLUDE_ASM(s32, "EA8AE0", func_80241B94_EAA674);

INCLUDE_ASM(s32, "EA8AE0", func_80241BC0_EAA6A0);
