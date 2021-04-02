#include "tik_12.h"

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_802405F0_8891C0);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80240960_889530);
/*
ApiStatus N(func_80240960_889530)(ScriptInstance* script, s32 isInitialCall) {
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

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/SetOverrideFlags_40.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80240C38_889808);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80240C58_889828);
/*
s) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80240C84_889854);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80240CF0_8898C0);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80240D3C_88990C);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80240DE8_8899B8);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80241038_889C08);
/*
s) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80241064_889C34);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_8024109C_889C6C);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_8024112C_889CFC);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80241160_889D30);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_802411C4_889D94);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_8024121C_889DEC);

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80241754_88A324);

#include "world/common/UnkPartnerPosFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_tik/tik_12/8891C0", func_80241924_88A4F4);
