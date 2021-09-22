#include "common.h"

extern struct unkPartnerStruct* D_802BEAAC_31B01C;

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD100_319670);

ApiStatus func_802BD148_3196B8(Evt* script, s32 isInitialCall) {
    Npc* unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_get_out(unk);
    }
    return partner_get_out(unk) != 0;
}

s32 func_802BD180_3196F0(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Entity* temp_s2;
    Npc* npc;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_flying_enable(npc, 1);
        mem_clear(D_802BEAAC_31B01C, sizeof(*D_802BEAAC_31B01C));
        D_8010C954 = 0;
    }
    playerData->unk_2F4[4]++;
    temp_s2 = D_8010C954;
    if (temp_s2 == NULL) {
        partner_flying_update_player_tracking(npc);
        partner_flying_update_motion(npc);
        return 0;
    }

    switch (D_802BEAAC_31B01C->unk_04) {
        case 0:
            D_802BEAAC_31B01C->unk_04 = 1;
            D_802BEAAC_31B01C->unk_08 = npc->flags;
            D_802BEAAC_31B01C->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, temp_s2->position.x, temp_s2->position.z));
            D_802BEAAC_31B01C->unk_10 = atan2(temp_s2->position.x, temp_s2->position.z, npc->pos.x, npc->pos.z);
            D_802BEAAC_31B01C->unk_14 = 6.0f;
            D_802BEAAC_31B01C->unk_18 = 50.0f;
            D_802BEAAC_31B01C->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BEAAC_31B01C->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = temp_s2->position.x + (sp10 * D_802BEAAC_31B01C->unk_0C);
            npc->pos.z = temp_s2->position.z - (sp14 * D_802BEAAC_31B01C->unk_0C);

            D_802BEAAC_31B01C->unk_10 = clamp_angle(D_802BEAAC_31B01C->unk_10 - D_802BEAAC_31B01C->unk_14);
            if (D_802BEAAC_31B01C->unk_0C > 20.0f) {
                D_802BEAAC_31B01C->unk_0C--;
            } else if (D_802BEAAC_31B01C->unk_0C < 19.0f) {
                D_802BEAAC_31B01C->unk_0C++;
            }

            tempY = sin_rad((D_802BEAAC_31B01C->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BEAAC_31B01C->unk_18 += 3.0f;

            if (D_802BEAAC_31B01C->unk_18 > 150.0f) {
                D_802BEAAC_31B01C->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BEAAC_31B01C->unk_10);
            D_802BEAAC_31B01C->unk_14 += 0.8;
            if (D_802BEAAC_31B01C->unk_14 > 40.0f) {
                D_802BEAAC_31B01C->unk_14 = 40.0f;
            }

            if (--D_802BEAAC_31B01C->unk_00 == 0) {
                D_802BEAAC_31B01C->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BEAAC_31B01C->unk_08;
            D_802BEAAC_31B01C->unk_00 = 0x1E;
            D_802BEAAC_31B01C->unk_04++;
            break;
        case 3:
            partner_flying_update_player_tracking(npc);
            partner_flying_update_motion(npc);

            if (--D_802BEAAC_31B01C->unk_00 == 0) {
                D_802BEAAC_31B01C->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD514_319A84);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD558_319AC8);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD660_319BD0);

ApiStatus func_802BE8D4_31AE44(Evt* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_put_away(unk);
    }
    return partner_put_away(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BE90C_31AE7C);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BE9D0_31AF40);
