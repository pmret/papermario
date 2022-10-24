#include "obk_04.h"

static char* N(exit_str_0) = "obk_03";

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240050_BC7EB0);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_802400D0_BC7F30);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240198_BC7FF8);

void func_8024022C_BC808C(void) {
    get_npc_unsafe(1)->unk_A2 = 0;
    get_npc_unsafe(2)->unk_A2 = 0;
    get_npc_unsafe(3)->unk_A2 = 0;
    get_npc_unsafe(4)->unk_A2 = 0;
    get_npc_unsafe(5)->unk_A2 = 0;
    get_npc_unsafe(6)->unk_A2 = 0;
    get_npc_unsafe(7)->unk_A2 = 0;
    get_npc_unsafe(8)->unk_A2 = 0;
}

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_802402A0_BC8100);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_802402F4_BC8154);

ApiStatus func_802405B4_BC8414(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    npc->blur.any = get_npc_unsafe(0); // TODO what is this?
    script->functionTemp[2] = script->owner2.npcID * 45;
    npc->flags |= NPC_FLAG_40000;
    script->functionTemp[1] = 0;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240624_BC8484);

ApiStatus func_80240910_BC8770(void) {
    if (gPlayerStatus.position.y < -50.0f) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240A58_BC88B8);

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240C10_BC8A70);

ApiStatus func_80240CA0_BC8B00(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(evt_get_variable(NULL, MapVar(5)));

    script->varTable[0] = npc->pos.x;
    script->varTable[1] = npc->pos.y;
    script->varTable[2] = npc->pos.z;
    return ApiStatus_DONE2;
}

ApiStatus func_80240D00_BC8B60(Evt* script, s32 isInitialCall) {
    gPlayerData.bootsLevel = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_obk/obk_04/BC7EB0", func_80240D14_BC8B74);

ApiStatus func_80240E58_BC8CB8(Evt* script, s32 isInitialCall) {
    if (get_npc_unsafe(1)->duration == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
