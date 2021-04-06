#include "nok_01.h"

#define UNK_ALPHA_FUNC_NPC 15

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240000_9C53E0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802400B4_9C5494);

#include "world/common/NpcJumpFunc3.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13_2.inc.c"

#include "world/common/UnkNpcAIFunc11.inc.c"

#include "world/common/UnkNpcAIFunc10.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240540_9C5920);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802405EC_9C59CC);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802407F4_9C5BD4);

#include "world/common/Call800E9894.inc.c"

#include "world/common/Call800E98C4SyncStatusMenu.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240AB4_9C5E94);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240B30_9C5F10);

#include "world/common/AwaitScriptComplete.inc.c"

#include "world/common/PartnerToggleAbilityScript.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240C2C_9C600C);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240C80_9C6060);

#include "world/common/GetPartnerCall800EB168.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240D60_9C6140);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240D68_9C6148);
/*
ApiStatus N(func_80240D68_9C6148)(ScriptInstance* script, s32 isInitialCall) {
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
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/Set80151310.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80240EA4_9C6284);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802410C8_9C64A8);

#include "world/common/GetNpcUnsafeOwner2.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241134_9C6514);

#include "world/common/UnkAlphaFunc.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802412E0_9C66C0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241454_9C6834);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802414D8_9C68B8);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802416F0_9C6AD0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802417A4_9C6B84);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802417D8_9C6BB8);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241858_9C6C38);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241870_9C6C50);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024188C_9C6C6C);

#include "world/common/GetGameStatus75.inc.c"

#include "world/common/SetCamVfov.inc.c"

#include "world/common/GetCamVfov.inc.c"

#include "world/common/UnkCameraFunc.inc.c"

#include "world/common/UnkRotatePlayer.inc.c"

#include "world/common/UnkPartnerFuncs.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241D60_9C7140);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80241DCC_9C71AC);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242028_9C7408);
/*
ApiStatus N(func_80242028_9C7408)(ScriptInstance* script, s32 isInitialCall) {
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
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024207C_9C745C);
/*
ApiStatus N(func_8024207C_9C745C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802420B4_9C7494);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802423CC_9C77AC);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242410_9C77F0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_8024243C_9C781C);

#include "common/UnkFloatFunc.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802426A4_9C7A84);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242760_9C7B40);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242790_9C7B70);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802427C0_9C7BA0);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242804_9C7BE4);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242858_9C7C38);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242898_9C7C78);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802428B8_9C7C98);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_802428D8_9C7CB8);

INCLUDE_ASM(s32, "world/area_nok/nok_01/9C53E0", func_80242910_9C7CF0);