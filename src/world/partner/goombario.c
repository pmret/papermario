#include "common.h"
#include "sprite/npc/world_goombario.h"
#include "goombario.h"
#include "../src/world/partners.h"

ApiStatus func_802BD188_3170A8(Evt* script, s32 isInitialCall);
ApiStatus func_802BD1D0_3170F0(Evt* script, s32 isInitialCall);
ApiStatus func_802BD5D8_3174F8(Evt* script, s32 isInitialCall);
ApiStatus func_802BDB30_317A50(Evt* script, s32 isInitialCall);
extern s32 D_802BDF60;

extern unkPartnerStruct* D_802BDD88_317CA8;

s32 func_802BD100_317020(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        Trigger* trigger = get_trigger_by_id(i);

        if (trigger != NULL && trigger->flags.flags & TRIGGER_WALL_PRESS_A && trigger->params2 == arg0) {
            return trigger->unk_2C;
        }
    }
    return 0;
}

void world_goombario_init(Npc* goombario) {
    goombario->collisionHeight = 24;
    goombario->collisionRadius = 20;
}

ApiStatus func_802BD188_3170A8(Evt* script, s32 isInitialCall) {
    Npc* goombario = script->owner2.npc;
    D_802BDF60 = -1;

    if (isInitialCall) {
        partner_init_get_out(goombario);
    }

    return partner_get_out(goombario) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

s32 func_802BD1D0_3170F0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc = script->owner2.npc;
    Entity* entity;
    f32 sp10, sp14, tempY;

    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BDD88_317CA8, sizeof(*D_802BDD88_317CA8));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[1]++;
    entity = D_8010C954;

    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }

    switch (D_802BDD88_317CA8->unk_04) {
        case 0:
            D_802BDD88_317CA8->unk_04 = 1;
            D_802BDD88_317CA8->flags = npc->flags;
            D_802BDD88_317CA8->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BDD88_317CA8->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BDD88_317CA8->unk_14 = 6.0f;
            D_802BDD88_317CA8->unk_18 = 50.0f;
            D_802BDD88_317CA8->unk_00 = 120;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100 | NPC_FLAG_40000;
            npc->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((D_802BDD88_317CA8->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BDD88_317CA8->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BDD88_317CA8->unk_0C);
            D_802BDD88_317CA8->unk_10 = clamp_angle(D_802BDD88_317CA8->unk_10 - D_802BDD88_317CA8->unk_14);

            if (D_802BDD88_317CA8->unk_0C > 20.0f) {
                D_802BDD88_317CA8->unk_0C--;
            } else if (D_802BDD88_317CA8->unk_0C < 19.0f) {
                D_802BDD88_317CA8->unk_0C++;
            }

            tempY = sin_rad((D_802BDD88_317CA8->unk_18 * TAU) / 360.0f) * 3.0f;
            D_802BDD88_317CA8->unk_18 += 3.0f;

            if (D_802BDD88_317CA8->unk_18 > 150.0f) {
                D_802BDD88_317CA8->unk_18 = 150.0f;
            }

            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BDD88_317CA8->unk_10);
            D_802BDD88_317CA8->unk_14 += 0.8;

            if (D_802BDD88_317CA8->unk_14 > 40.0f) {
                D_802BDD88_317CA8->unk_14 = 40.0f;
            }

            if (--D_802BDD88_317CA8->unk_00 == 0) {
                D_802BDD88_317CA8->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BDD88_317CA8->flags;
            D_802BDD88_317CA8->unk_00 = 30;
            D_802BDD88_317CA8->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--D_802BDD88_317CA8->unk_00 == 0) {
                D_802BDD88_317CA8->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

void func_802BD564_317484(Npc* goombario) {
    if (D_8010C954) {
        D_8010C954 = 0;
        goombario->flags = D_802BDD88_317CA8->flags;
        D_802BDD88_317CA8->unk_04 = 0;
        partner_clear_player_tracking (goombario);
    }
}

s32 world_goombario_can_pause(Npc* goombario) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;
    s32 new_var;

    if (goombarioActionStatus->actionState.b[0] != 0) {
        return FALSE;
    }

    if ((goombario->flags & (NPC_FLAG_1000 | NPC_FLAG_NO_Y_MOVEMENT)) != NPC_FLAG_1000) {
        return new_var = 0;
        do { } while (new_var); // why though
    }

    return TRUE;
}

// get message for tattle routine
// has big jumptable at rodata 802BDE88
INCLUDE_ASM(ApiStatus, "world/partner/goombario", func_802BD5D8_3174F8, Evt* script, s32 isInitialCall);

#ifdef NON_EQUIVALENT //something with the symbol is broken
ApiStatus func_802BDB30_317A50(Evt* script, s32 isInitialCall) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;

    set_time_freeze_mode(0);

    if (D_802BDF64_3248B4 != 0) {
        D_802BDF64_3248B4 = 0;
        enable_player_input();
    }

    goombarioActionStatus->actionState.b[0] = 0;
    goombarioActionStatus->actionState.b[3] = 0;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(ApiStatus, "world/partner/goombario", func_802BDB30_317A50, Evt* script, s32 isInitialCall);
#endif

ApiStatus func_802BDB84(Evt* script, s32 isInitialCall) {
    Npc* goombario = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goombario);
    }

    return partner_put_away(goombario) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

void world_goombario_pre_battle(Npc* goombario) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;

    if (goombarioActionStatus->actionState.b[0] != 0) {
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        enable_player_input();
        CancelMessageAndBlock();
        partner_clear_player_tracking(goombario);
        goombarioActionStatus->actionState.b[0] = 0;
        goombarioActionStatus->actionState.b[3] = 0;
        disable_npc_blur(goombario);
    }

    goombarioActionStatus->actionState.b[3] = 1;
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

EvtSource world_goombario_take_out = {
    EVT_CALL(func_802BD188_3170A8)
    EVT_RETURN
    EVT_END
};

unkPartnerStruct* D_802BDD88_317CA8 = &D_802BDF40;

EvtSource world_goombario_update = {
    EVT_CALL(func_802BD1D0_3170F0)
    EVT_RETURN
    EVT_END
};

EvtSource world_goombario_use_ability = {
    EVT_CALL(func_802BD5D8_3174F8)
    EVT_IF_EQ(EVT_VAR(0), -1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(func_802BDB30_317A50)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(EVT_VAR(1), 0)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, NPC_ANIM_world_goombario_normal_talk,
                 NPC_ANIM_world_goombario_normal_idle, 0, EVT_VAR(0))
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_CALL(func_802BDB30_317A50)
    EVT_RETURN
    EVT_END
};

EvtSource world_goombario_put_away = {
    EVT_CALL(func_802BDB84)
    EVT_RETURN
    EVT_END
};
