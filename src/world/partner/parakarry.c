#include "common.h"
#include "../src/world/partners.h"

extern struct unkPartnerStruct* D_802BEAAC_31B01C;
extern s32 D_802BEBC0_31CBE0;

extern s32 D_802BEBB0;
extern s32 D_802BEBB4;
extern s32 D_802BEBB8;
extern s32 D_802BEBBC;
extern s32 D_802BEBC4;


void func_802BD100_319670(Npc* npc) {
    npc->collisionHeight = 37;
    npc->collisionRadius = 40;
    D_802BEBB0 = 0;
    D_802BEBC0_31CBE0 = 0;
    D_802BEBB4 = 0;
    D_802BEBB8 = 0;
    D_802BEBBC = 0;
    D_802BEBC4 = 0;
}

ApiStatus func_802BD148_3196B8(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(npc);
    }

    if (partner_get_out(npc)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

s32 func_802BD180_3196F0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Entity* temp_s2;
    Npc* npc;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    npc = script->owner2.npc;

    if (isInitialCall) {
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

void func_802BD514_319A84(Npc* parakarry) {
    if (D_8010C954) {
        D_8010C954 = 0;
        parakarry->flags = D_802BEAAC_31B01C->unk_08;
        D_802BEAAC_31B01C->unk_04 = 0;
        partner_clear_player_tracking (parakarry);
    }
}

s32 func_802BD558_319AC8(void) {
    f32 sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    f32 colliderBaseHeight;
    s32 temp_s1;

    colliderBaseHeight = gPlayerStatus.colliderHeight;
    sp28 = gPlayerStatus.position.x;
    sp2C = gPlayerStatus.position.y + (colliderBaseHeight * 0.5);
    sp30 = gPlayerStatus.position.z;
    sp34 = colliderBaseHeight * 0.5f;
    
    temp_s1 = player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C, &sp40, &sp44);

    if (((get_collider_type_by_id(temp_s1) & 0xFF) - 2) < 2U) {
        gPlayerStatus.unk_BF = 2;
        D_802BEBC0_31CBE0 = 0x15;
        gPlayerStatus.flags |= 0x800;
    }

    return temp_s1;
}

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD660_319BD0);

ApiStatus func_802BE8D4_31AE44(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(npc);
    }

    if (partner_put_away(npc)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

void func_802BE90C_31AE7C(Npc* npc) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (D_802BEBB0) {
        if (D_802BEBB8) {
            enable_player_static_collisions();
        }

        if (D_802BEBB4) {
            enable_player_input();
        }

        set_action_state(0);
        partnerActionStatus->npc = *npc;
        partnerActionStatus->actionState.b[1] = 1;
        partner_clear_player_tracking(npc);
    }

    partnerActionStatus->actionState.b[3] = 4;
}

void func_802BE9D0_31AF40(Npc* npc) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (partnerActionStatus->actionState.b[1] != 0) {
        if (D_802BEBB8) {
            disable_player_static_collisions();
        }
        if (D_802BEBB4) {
            disable_player_input();
        }

        set_action_state(0x21);
        *npc = partnerActionStatus->npc;
        partnerActionStatus->actionState.b[3] = 0;
        partnerActionStatus->actionState.b[0] = 0;
        partner_clear_player_tracking(npc);
        partner_use_ability();
    }
}
