#include "common.h"

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD100_319670);

ApiStatus func_802BD148(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        func_800EECC4(unk);
    }
    return func_800EECE8(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD180);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD514);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD558);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD660);

ApiStatus func_802BE8D4(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        func_800EE994(unk);
    }
    return func_800EE9B8(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BE90C);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BE9D0);
