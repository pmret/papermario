#include "common.h"

INCLUDE_ASM(s32, "code_EC7590", func_802403E0_EC7590);

INCLUDE_ASM(s32, "code_EC7590", func_80240450_EC7600);

INCLUDE_ASM(s32, "code_EC7590", func_8024061C_EC77CC);
/*
s32 N(func_8024061C_EC77CC)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
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

INCLUDE_ASM(s32, "code_EC7590", func_802406D0_EC7880);