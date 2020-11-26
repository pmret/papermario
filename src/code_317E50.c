#include "common.h"

INCLUDE_ASM(s32, "code_317E50", func_802BD100_317E50);

INCLUDE_ASM(s32, "code_317E50", func_802BD2D8);

ApiStatus func_802BD300(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        func_800EECC4(unk);
    }
    return func_800EECE8(unk) != 0;
}

INCLUDE_ASM(s32, "code_317E50", func_802BD338);

INCLUDE_ASM(s32, "code_317E50", func_802BD6DC);

INCLUDE_ASM(s32, "code_317E50", func_802BD720);

s32 func_802BD748(void) {
    return D_8010EBB0[0] == 0;
}

INCLUDE_ASM(s32, "code_317E50", func_802BD758);

ApiStatus func_802BE4E8(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        func_800EE994(unk);
    }
    return func_800EE9B8(unk) != 0;
}

INCLUDE_ASM(s32, "code_317E50", func_802BE520);

INCLUDE_ASM(s32, "code_317E50", func_802BE6E8);
