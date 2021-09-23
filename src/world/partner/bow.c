#include "common.h"
#include "../partners.h"

extern s32 D_802BE0C0;
extern s32 D_802BE0C4;
extern struct unkPartnerStruct* D_802BDFFC_32494C;

void func_802BD100_323A50(Npc* partner) {
    partner->collisionHeight = 26;
    partner->collisionRadius = 24;
    partner->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    D_802BE0C4 = 0;
    D_802BE0C0 = 0;
}

ApiStatus func_802BD130_323A80(Evt* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;
    if (isInitialCall) {
        partner_init_get_out(owner);
    }
    return partner_get_out(owner) != 0;
}

s32 func_802BD168_323AB8(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    Entity* entity;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_flying_enable(npc, 1);
        mem_clear(D_802BDFFC_32494C, sizeof(*D_802BDFFC_32494C));
        D_8010C954 = 0;
    }
    entity = D_8010C954;
    playerData->unk_2F4[9]++;
    if (entity == NULL) {
        partner_flying_update_player_tracking(npc);
        partner_flying_update_motion(npc);
        return 0;
    }

    switch (D_802BDFFC_32494C->unk_04){
        case 0:
            D_802BDFFC_32494C->unk_04 = 1;
            D_802BDFFC_32494C->unk_08 = npc->flags;
            D_802BDFFC_32494C->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BDFFC_32494C->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BDFFC_32494C->unk_14 = 6.0f;
            D_802BDFFC_32494C->unk_18 = 50.0f;
            D_802BDFFC_32494C->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BDFFC_32494C->unk_10 * TAU) / 360.0f, &sp10, &sp14);
            npc->pos.x = entity->position.x + (sp10 * D_802BDFFC_32494C->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BDFFC_32494C->unk_0C);
            D_802BDFFC_32494C->unk_10 = clamp_angle(D_802BDFFC_32494C->unk_10 - D_802BDFFC_32494C->unk_14);
            if (D_802BDFFC_32494C->unk_0C > 20.0f) {
                D_802BDFFC_32494C->unk_0C -= 1.0f;
            } else if (D_802BDFFC_32494C->unk_0C < 19.0f) {
                D_802BDFFC_32494C->unk_0C++;
            }

            tempY = sin_rad((D_802BDFFC_32494C->unk_18 * TAU) / 360.0f) * 3.0f;
            D_802BDFFC_32494C->unk_18 += 3.0f;
            if (D_802BDFFC_32494C->unk_18 > 150.0f) {
                D_802BDFFC_32494C->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;
            npc->renderYaw = clamp_angle(360.0f - D_802BDFFC_32494C->unk_10);
            D_802BDFFC_32494C->unk_14 += 0.8;
            if (D_802BDFFC_32494C->unk_14 > 40.0f) {
                D_802BDFFC_32494C->unk_14 = 40.0f;
            }
            if (--D_802BDFFC_32494C->unk_00 == 0) {
                D_802BDFFC_32494C->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BDFFC_32494C->unk_08;
            D_802BDFFC_32494C->unk_00 = 0x1E;
            D_802BDFFC_32494C->unk_04++;
            break;
        case 3:
            partner_flying_update_player_tracking(npc);
            partner_flying_update_motion(npc);
            if (--D_802BDFFC_32494C->unk_00 == 0) {
                D_802BDFFC_32494C->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

INCLUDE_ASM(s32, "world/partner/bow", func_802BD4FC_323E4C);

INCLUDE_ASM(s32, "world/partner/bow", func_802BD540_323E90);

INCLUDE_ASM(s32, "world/partner/bow", func_802BD694_323FE4);

INCLUDE_ASM(s32, "world/partner/bow", func_802BDDF0_324740);

INCLUDE_ASM(s32, "world/partner/bow", func_802BDF08_324858);

INCLUDE_ASM(s32, "world/partner/bow", func_802BDF64_3248B4);
