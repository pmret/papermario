#include "common.h"

s32 func_802BD100(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        Trigger* trigger = get_trigger_by_id(i);

        if (trigger != NULL && trigger->flags.flags & 0x100 && trigger->params2 == arg0) {
            return trigger->unk_2C;
        }
    }
    return 0;
}

void func_802BD174(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 20;
}

INCLUDE_ASM(s32, "code_317020", func_802BD188);

INCLUDE_ASM(s32, "code_317020", func_802BD1D0);

INCLUDE_ASM(s32, "code_317020", func_802BD564);

INCLUDE_ASM(s32, "code_317020", func_802BD5A8);

INCLUDE_ASM(s32, "code_317020", func_802BD5D8);

INCLUDE_ASM(s32, "code_317020", func_802BDB30);

ApiStatus func_802BDB84(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this?

    if (isInitialCall) {
        func_800EE994(unk);
    }

    return func_800EE9B8(unk) != 0;
}

// Something is up with D_8010EBB0 I think. It might be a struct or something
#ifdef NON_MATCHING
void func_802BDBBC(s32 arg0) {
    if (D_8010EBB0[0] != 0) {
        func_80027088(0);
        enable_player_input();
        CancelMessageAndBlock();
        clear_partner_move_history(arg0);
        D_8010EBB0[0] = 0;
        D_8010EBB0[3] = 0;
        disable_npc_blur(arg0);
    }
    D_8010EBB0[3] = 1;
}
#else
INCLUDE_ASM(s32, "code_317020", func_802BDBBC);
#endif
