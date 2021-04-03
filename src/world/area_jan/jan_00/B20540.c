#include "jan_00.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_8024030C_B2084C);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240340_B20880);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_802403F4_B20934);
/*
ApiStatus N(func_802403F4_B20934)(ScriptInstance* script, s32 isInitialCall) {
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

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240738_B20C78);
/*
ApiStatus N(func_80240738_B20C78)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return 2;
    }

    return 0;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_8024078C_B20CCC);
/*
ApiStatus N(func_8024078C_B20CCC)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_802407C4_B20D04);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240ADC_B2101C);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240B20_B21060);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240B4C_B2108C);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240CF8_B21238);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240F14_B21454);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80241134_B21674);
