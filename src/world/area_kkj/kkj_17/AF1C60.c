#include "kkj_17.h"

extern s32 D_8024092C_AF258C[5];

static char* N(exit_str_0) = "kkj_11";
static char* N(exit_str_1) = "";

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

INCLUDE_ASM(s32, "world/area_kkj/kkj_17/AF1C60", func_802402BC_AF1F1C);

ApiStatus func_80240500_AF2160(Evt* script, s32 isInitialCall) {
    s32* ptr = D_8024092C_AF258C;
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024092C_AF258C); i++) {
        s32 var = ptr[i];

        if (script->varTable[0] == var) {
            found = TRUE;
            break;
        }
    }

    if (found) {
        evt_set_variable(NULL, GSWF(494 + i), TRUE);
    }

    return ApiStatus_DONE2;
}

#include "world/common/GetItemEmptyCount.inc.c"
