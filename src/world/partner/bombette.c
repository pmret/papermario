#include "common.h"

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD100_317E50);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD2D8_318028);

ApiStatus func_802BD300_318050(ScriptInstance* script, s32 isInitialCall) {
    Npc* unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        func_800EECC4(unk);
    }
    return func_800EECE8(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD338_318088);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD6DC_31842C);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD720_318470);

s32 func_802BD748(void) {
    return D_8010EBB0[0] == 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD758_3184A8);

ApiStatus func_802BE4E8_319238(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        func_800EE994(unk);
    }
    return func_800EE9B8(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BE520_319270);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BE6E8_319438);
