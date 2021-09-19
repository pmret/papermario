#include "common.h"

extern unkPartnerStruct* D_802BFDF8_320B68;

INCLUDE_ASM(s32, "world/partner/sushie", func_802BD100_31DE70);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BD20C_31DF7C);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BD368_31E0D8);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BD414_31E184);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BE280_31EFF0);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BE3A4_31F114);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BF520_320290);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BF568_3202D8);

s32 func_802BF5A0_320310(Evt* evt, s32 arg1) {
    Npc* npc;
    Entity* entity;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    npc = evt->owner2.npc;
    if (arg1 != 0) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BFDF8_320B68, sizeof(*D_802BFDF8_320B68));
        D_8010C954 = 0;
    }

    entity = D_8010C954;
    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }
    switch (D_802BFDF8_320B68->unk_04) {
        case 0:
            D_802BFDF8_320B68->unk_04 = 1;
            D_802BFDF8_320B68->unk_08 = npc->flags;
            D_802BFDF8_320B68->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BFDF8_320B68->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BFDF8_320B68->unk_14 = 6.0f;
            D_802BFDF8_320B68->unk_18 = 50.0f;
            D_802BFDF8_320B68->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BFDF8_320B68->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BFDF8_320B68->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BFDF8_320B68->unk_0C);

            D_802BFDF8_320B68->unk_10 = clamp_angle(D_802BFDF8_320B68->unk_10 - D_802BFDF8_320B68->unk_14);
            if (D_802BFDF8_320B68->unk_0C > 20.0f) {
                D_802BFDF8_320B68->unk_0C--;
            } else if (D_802BFDF8_320B68->unk_0C < 19.0f) {
                D_802BFDF8_320B68->unk_0C++;
            }

            tempY = sin_rad((D_802BFDF8_320B68->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BFDF8_320B68->unk_18 += 3.0f;

            if (D_802BFDF8_320B68->unk_18 > 150.0f) {
                D_802BFDF8_320B68->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BFDF8_320B68->unk_10);
            D_802BFDF8_320B68->unk_14 += 0.8;
            if (D_802BFDF8_320B68->unk_14 > 40.0f) {
                D_802BFDF8_320B68->unk_14 = 40.0f;
            }

            if (--D_802BFDF8_320B68->unk_00 == 0) {
                D_802BFDF8_320B68->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BFDF8_320B68->unk_08;
            D_802BFDF8_320B68->unk_00 = 0x1E;
            D_802BFDF8_320B68->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--D_802BFDF8_320B68->unk_00 == 0) {
                D_802BFDF8_320B68->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}

INCLUDE_ASM(s32, "world/partner/sushie", func_802BF920_320690);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BF964_3206D4);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BF9B8_320728);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BFA58_3207C8);

INCLUDE_ASM(s32, "world/partner/sushie", func_802BFAB8_320828);
