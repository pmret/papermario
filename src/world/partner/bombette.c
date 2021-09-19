#include "common.h"

extern s32 D_802BE934;
extern f64 D_802BE900_319650;

extern struct unkPartnerStruct* D_802BE89C_3195EC;

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD100_317E50);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD2D8_318028);

ApiStatus func_802BD300_318050(Evt* script, s32 isInitialCall) {
    Npc* unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_get_out(unk);
    }
    return partner_get_out(unk) != 0;
}

s32 func_802BD338_318088(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    f32 sp10;
    f32 sp14;
    f32 tempY;
    Entity* entity;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BE89C_3195EC, sizeof(*D_802BE89C_3195EC));
        D_8010C954 = 0;
    }
    playerData->unk_2F4[3]++;
    npc->flags |= 0x10000;
    entity = D_8010C954;
    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }
    switch (D_802BE89C_3195EC->unk_04) {
        case 0:
            D_802BE89C_3195EC->unk_04 = 1;
            D_802BE89C_3195EC->unk_08 = npc->flags;
            D_802BE89C_3195EC->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BE89C_3195EC->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BE89C_3195EC->unk_14 = 6.0f;
            D_802BE89C_3195EC->unk_18 = 50.0f;
            D_802BE89C_3195EC->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BE89C_3195EC->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BE89C_3195EC->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BE89C_3195EC->unk_0C);

            D_802BE89C_3195EC->unk_10 = clamp_angle(D_802BE89C_3195EC->unk_10 - D_802BE89C_3195EC->unk_14);
            if (D_802BE89C_3195EC->unk_0C > 20.0f) {
                D_802BE89C_3195EC->unk_0C--;
            } else if (D_802BE89C_3195EC->unk_0C < 19.0f) {
                D_802BE89C_3195EC->unk_0C++;
            }

            tempY = sin_rad((D_802BE89C_3195EC->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BE89C_3195EC->unk_18 += 3.0f;

            if (D_802BE89C_3195EC->unk_18 > 150.0f) {
                D_802BE89C_3195EC->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BE89C_3195EC->unk_10);
            D_802BE89C_3195EC->unk_14 += D_802BE900_319650;
            if (D_802BE89C_3195EC->unk_14 > 40.0f) {
                D_802BE89C_3195EC->unk_14 = 40.0f;
            }

            if (--D_802BE89C_3195EC->unk_00 == 0) {
                D_802BE89C_3195EC->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BE89C_3195EC->unk_08;
            D_802BE89C_3195EC->unk_00 = 0x1E;
            D_802BE89C_3195EC->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--D_802BE89C_3195EC->unk_00 == 0) {
                D_802BE89C_3195EC->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD6DC_31842C);

s32 func_802BD720_318470(void) {
    if (gPartnerActionStatus.actionState.b[0] != 0) {
        D_802BE934 = 1;
        return FALSE;
    }
    return TRUE;
}

s32 func_802BD748(void) {
    return gPartnerActionStatus.actionState.b[0] == 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD758_3184A8);

ApiStatus func_802BE4E8_319238(Evt* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_put_away(unk);
    }
    return partner_put_away(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BE520_319270);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BE6E8_319438);
