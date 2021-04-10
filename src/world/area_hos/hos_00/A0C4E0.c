#include "hos_00.h"

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_802407F0_A0C4E0);
/*
ApiStatus N(func_802407F0_A0C4E0)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240908_A0C5F8);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_8024091C_A0C60C);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240994_A0C684);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240A54_A0C744);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240B20_A0C810);

INCLUDE_ASM(s32, "world/area_hos/hos_00/A0C4E0", func_80240B3C_A0C82C);
