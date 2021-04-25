#include "common.h"
#include "sprite/npc/world_goombario.h"
#include "goombario.h"

s32 func_802BD100_317020(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        Trigger* trigger = get_trigger_by_id(i);

        if (trigger != NULL && trigger->flags.flags & 0x100 && trigger->params2 == arg0) {
            return trigger->unk_2C;
        }
    }
    return 0;
}

void world_goombario_init(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionRadius = 20;
}

INCLUDE_ASM(ApiStatus, "world/partner/goombario", func_802BD188_3170A8, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/partner/goombario", func_802BD1D0_3170F0, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "world/partner/goombario", func_802BD564_317484);

s32 world_goombario_can_pause(Npc* partner) {
    s32 new_var;

    if (D_8010EBB0.unk_00) {
        return FALSE;
    }

    if ((partner->flags & 0x1800) != 0x1000) {
        return new_var = 0;
        do { } while(new_var); // why though
    }

    return TRUE;
}

// get message for tattle routine
// has big jumptable at rodata 802BDE88
INCLUDE_ASM(ApiStatus, "world/partner/goombario", func_802BD5D8_3174F8, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/partner/goombario", func_802BDB30_317A50, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802BDB84(ScriptInstance* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this?

    if (isInitialCall) {
        func_800EE994(unk);
    }

    return func_800EE9B8(unk) != 0;
}

void world_goombario_pre_battle(Npc* partner) {
    Temp8010EBB0* temp = &D_8010EBB0;

    if (temp->unk_00 != 0) {
        set_time_freeze_mode(0);
        enable_player_input();
        CancelMessageAndBlock();
        clear_partner_move_history(partner);
        temp->unk_00 = 0;
        temp->unk_03 = 0;
        disable_npc_blur(partner);
    }
    temp->unk_03 = 1;
}

s32 D_802BDC40_317B60[] = {
    0x00000015, 0x001B0000, 0x00000018, 0x001B0000, 0x00000016, 0x001B0001, 0x00000019, 0x001B0001,
    0x00000017, 0x001B0003, 0x0000001A, 0x001B0003, 0x0000000D, 0x001B0005, 0x0000000E, 0x001B0005,
    0x0000000F, 0x001B0006, 0x00000010, 0x001B0006, 0x0000000B, 0x001B0007, 0x0000000C, 0x001B0008,
    0x00000014, 0x001B0009, 0x0000002E, 0x001B000A, 0x0000002F, 0x001B000A, 0x00000007, 0x001B000B,
    0x00000008, 0x001B000B, 0x00000009, 0x001B000C, 0x0000000A, 0x001B000E, 0x0000002B, 0x001B0010,
    0x00000003, 0x001B0011, 0x00000004, 0x001B0011, 0x00000005, 0x001B0011, 0x00000006, 0x001B0011,
    0x00000033, 0x001B0012, 0x00000034, 0x001B0013, 0x00000026, 0x001B0014, 0x00000032, 0x001B0015,
    0x00000024, 0x001B0017, 0x00000025, 0x001B001A, 0x00000031, 0x001B001D, 0x00000035, 0x001B001F,
    0x00000036, 0x001B0020, 0x00000038, 0x001B0021, 0x00000037, 0x001B0022, 0x0000003A, 0x001B0023,
    0x00000039, 0x001B0024, 0xFFFFFFFF
};

Script world_goombario_take_out = SCRIPT({
    func_802BD188_3170A8();
});

s32 D_802BDD88_317CA8 = 0x802BDF40;

Script world_goombario_update = SCRIPT({
    func_802BD1D0_3170F0();
});

Script world_goombario_use_ability = SCRIPT({
    func_802BD5D8_3174F8(); // returns tattle message id on SI_VAR(0), and something else on SI_VAR(1)

    if (SI_VAR(0) == -1) {
        return;
    }

    if (SI_VAR(0) == 0) {
        func_802BDB30_317A50();
        return;
    }

    if (SI_VAR(1) == 0) {
        SpeakToPlayer(NPC_PARTNER, NPC_ANIM(world_goombario, normal, talk), NPC_ANIM(world_goombario, normal, idle), 0,
                      SI_VAR(0));
    }

    sleep 1;

    func_802BDB30_317A50();
});

Script world_goombario_put_away = SCRIPT({
    func_802BDB84();
});
