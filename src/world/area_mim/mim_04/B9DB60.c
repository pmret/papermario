#include "mim_04.h"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240200_B9DB60);

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240430_B9DD90);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240828_B9E188);

#include "world/common/UnkNpcAIFunc15.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240AAC_B9E40C);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80240DF0_B9E750);

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9DB60", func_80241014_B9E974);
/*
ApiStatus N(func_80241014_B9E974)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &D_80241C68_BE09F8;
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
        ptr = &D_80241C68_BE09F8;
        heap_free(*ptr);
        *ptr = NULL;
    }
    return 2;
}
*/

#include "world/common/GetItemName.inc.c"
