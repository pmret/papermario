#include "common.h"
#include "goombario.h"

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

void world_goombario_init(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 20;
}

INCLUDE_ASM(s32, "world/partner/goombario", func_802BD188);

INCLUDE_ASM(s32, "world/partner/goombario", func_802BD1D0);

INCLUDE_ASM(s32, "world/partner/goombario", func_802BD564);

// Compiler is generating more efficient code than the original asm, using xori and sltiu instead of beq
#ifdef NON_MATCHING
s32 world_goombario_can_pause(Npc* partner) {
    if (D_8010EBB0[0]) {
        return FALSE;
    }

    if ((partner->flags & 0x1800) != 0x1000) {
        return FALSE;
    }

    return TRUE;
}
#else
INCLUDE_ASM(s32, "world/partner/goombario", world_goombario_can_pause, Npc* partner);
#endif


INCLUDE_ASM(s32, "world/partner/goombario", func_802BD5D8);

INCLUDE_ASM(s32, "world/partner/goombario", func_802BDB30);

ApiStatus func_802BDB84(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this?

    if (isInitialCall) {
        func_800EE994(unk);
    }

    return func_800EE9B8(unk) != 0;
}

// Something is up with D_8010EBB0 I think. It might be a struct or something
#ifdef NON_MATCHING
void world_goombario_pre_battle(s32 arg0) {
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
INCLUDE_ASM(void, "world/partner/goombario", world_goombario_pre_battle, s32 arg0);
#endif
