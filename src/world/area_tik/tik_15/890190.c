#include "tik_15.h"

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_802405F0_890190);

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240960_890500);
/*
s32 N(func_80240960_890500)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240A78_890618);

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240AA4_890644);

INCLUDE_ASM(s32, "world/area_tik/tik_15/890190", func_80240AD0_890670);