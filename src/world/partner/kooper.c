#include "common.h"

extern s32 D_802BEC54;
extern unkPartnerStruct* D_802BEB60_31CB80;

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD100_31B120);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD144_31B164);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD17C_31B19C);

void func_802BD200_31B220(Npc* npc) {
    npc->collisionHeight = 37;
    npc->collisionRadius = 24;
    npc->unk_80 = 0x10000;
    D_802BEC54 = 0;
}

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD228_31B248);

s32 func_802BD260_31B280(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    f32 sp10;
    f32 sp14;
    f32 tempY;
    Entity* entity;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BEB60_31CB80, sizeof(*D_802BEB60_31CB80));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[2]++;
    entity = D_8010C954;
    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }

    switch (D_802BEB60_31CB80->unk_04) {
        case 0:
            D_802BEB60_31CB80->unk_04 = 1;
            D_802BEB60_31CB80->unk_08 = npc->flags;
            D_802BEB60_31CB80->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BEB60_31CB80->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BEB60_31CB80->unk_14 = 6.0f;
            D_802BEB60_31CB80->unk_18 = 50.0f;
            D_802BEB60_31CB80->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BEB60_31CB80->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BEB60_31CB80->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BEB60_31CB80->unk_0C);

            D_802BEB60_31CB80->unk_10 = clamp_angle(D_802BEB60_31CB80->unk_10 - D_802BEB60_31CB80->unk_14);
            if (D_802BEB60_31CB80->unk_0C > 20.0f) {
                D_802BEB60_31CB80->unk_0C--;
            } else if (D_802BEB60_31CB80->unk_0C < 19.0f) {
                D_802BEB60_31CB80->unk_0C++;
            }

            tempY = sin_rad((D_802BEB60_31CB80->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BEB60_31CB80->unk_18 += 3.0f;

            if (D_802BEB60_31CB80->unk_18 > 150.0f) {
                D_802BEB60_31CB80->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BEB60_31CB80->unk_10);
            D_802BEB60_31CB80->unk_14 += 0.8;
            if (D_802BEB60_31CB80->unk_14 > 40.0f) {
                D_802BEB60_31CB80->unk_14 = 40.0f;
            }

            if (--D_802BEB60_31CB80->unk_00 == 0) {
                D_802BEB60_31CB80->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BEB60_31CB80->unk_08;
            D_802BEB60_31CB80->unk_00 = 0x1E;
            D_802BEB60_31CB80->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--D_802BEB60_31CB80->unk_00 == 0) {
                D_802BEB60_31CB80->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD5F4_31B614);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BD638_31B658);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BE7E0_31C800);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BE818_31C838);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BEA24_31CA44);

INCLUDE_ASM(s32, "world/partner/kooper", func_802BEB10_31CB30);
