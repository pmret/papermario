#include "common.h"

extern unkPartnerStruct* D_802BFE7C_3239CC;
extern f64 D_802BFEF0;

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD100_320C50);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD21C_320D6C);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD29C_320DEC);

s32 func_802BD2D4_320E24(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Entity* entity;
    Npc* npc;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_flying_enable(npc, 1);
        mem_clear(D_802BFE7C_3239CC, sizeof(*D_802BFE7C_3239CC));
        D_8010C954 = 0;
    }
    playerData->unk_2F4[8]++;
    npc->flags |= 0x10000;
    entity = D_8010C954;
    if (entity == NULL) {
        partner_flying_update_player_tracking(npc);
        partner_flying_update_motion(npc);
        return 0;
    }

    switch (D_802BFE7C_3239CC->unk_04) {
        case 0:
            D_802BFE7C_3239CC->unk_04 = 1;
            D_802BFE7C_3239CC->unk_08 = npc->flags;
            D_802BFE7C_3239CC->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BFE7C_3239CC->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BFE7C_3239CC->unk_14 = 6.0f;
            D_802BFE7C_3239CC->unk_18 = 50.0f;
            D_802BFE7C_3239CC->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BFE7C_3239CC->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BFE7C_3239CC->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BFE7C_3239CC->unk_0C);

            D_802BFE7C_3239CC->unk_10 = clamp_angle(D_802BFE7C_3239CC->unk_10 - D_802BFE7C_3239CC->unk_14);
            if (D_802BFE7C_3239CC->unk_0C > 20.0f) {
                D_802BFE7C_3239CC->unk_0C--;
            } else if (D_802BFE7C_3239CC->unk_0C < 19.0f) {
                D_802BFE7C_3239CC->unk_0C++;
            }

            tempY = sin_rad((D_802BFE7C_3239CC->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BFE7C_3239CC->unk_18 += 3.0f;

            if (D_802BFE7C_3239CC->unk_18 > 150.0f) {
                D_802BFE7C_3239CC->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BFE7C_3239CC->unk_10);
            D_802BFE7C_3239CC->unk_14 += D_802BFEF0;
            if (D_802BFE7C_3239CC->unk_14 > 40.0f) {
                D_802BFE7C_3239CC->unk_14 = 40.0f;
            }

            if (--D_802BFE7C_3239CC->unk_00 == 0) {
                D_802BFE7C_3239CC->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BFE7C_3239CC->unk_08;
            D_802BFE7C_3239CC->unk_00 = 0x1E;
            D_802BFE7C_3239CC->unk_04++;
            break;
        case 3:
            partner_flying_update_player_tracking(npc);
            partner_flying_update_motion(npc);

            if (--D_802BFE7C_3239CC->unk_00 == 0) {
                D_802BFE7C_3239CC->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD678_3211C8);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD6BC_32120C);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD7DC);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD99C_3214EC);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BDA90_3215E0);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BDDD8_321928);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BE6A0_3221F0);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BE724_322274);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BF4F0_323040);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFA00_323550);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFAA8_3235F8);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFB44_323694);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFBA0_3236F0);
