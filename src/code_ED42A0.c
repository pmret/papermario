#include "common.h"

INCLUDE_ASM(s32, "code_ED42A0", func_80240080_ED42A0);
/*
s32 N(func_80240080_ED42A0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "code_ED42A0", func_80240134_ED4354);

INCLUDE_ASM(s32, "code_ED42A0", func_80240198_ED43B8);

INCLUDE_ASM(s32, "code_ED42A0", func_802402BC_ED44DC);