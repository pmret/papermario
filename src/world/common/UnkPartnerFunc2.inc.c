#include "common.h"

s32 N(UnkPartnerFunc2)(Evt* evt, s32 arg1) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    Entity* entity;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    npc = evt->owner2.npc;
    if (arg1 != 0) {

        #if IS_WALKING_PARTNER == 1
            partner_walking_enable(npc, 1);
        #else
            partner_flying_enable(npc, 1);
        #endif
        mem_clear(UNK_PARTNER_SYMBOL, sizeof(*UNK_PARTNER_SYMBOL));
        D_8010C954 = 0;
    }
    #ifdef IS_PLAYER_DATA_USED
    playerData->unk_2F4[IS_PLAYER_DATA_USED]++;
    #if IS_PLAYER_DATA_USED == 8 || IS_PLAYER_DATA_USED == 3    // Laki and Bombette have the following
    npc->flags |= 0x10000;
    #endif
    #endif
    entity = D_8010C954;
    if (entity == NULL) {
        #if IS_WALKING_PARTNER == 1
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);
        #else
            partner_flying_update_player_tracking(npc);
            partner_flying_update_motion(npc);
        #endif
        return 0;
    }

    switch (UNK_PARTNER_SYMBOL->unk_04) {
        case 0:
            UNK_PARTNER_SYMBOL->unk_04 = 1;
            UNK_PARTNER_SYMBOL->unk_08 = npc->flags;
            UNK_PARTNER_SYMBOL->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            UNK_PARTNER_SYMBOL->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            UNK_PARTNER_SYMBOL->unk_14 = 6.0f;
            UNK_PARTNER_SYMBOL->unk_18 = 50.0f;
            UNK_PARTNER_SYMBOL->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((UNK_PARTNER_SYMBOL->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * UNK_PARTNER_SYMBOL->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * UNK_PARTNER_SYMBOL->unk_0C);

            UNK_PARTNER_SYMBOL->unk_10 = clamp_angle(UNK_PARTNER_SYMBOL->unk_10 - UNK_PARTNER_SYMBOL->unk_14);
            if (UNK_PARTNER_SYMBOL->unk_0C > 20.0f) {
                UNK_PARTNER_SYMBOL->unk_0C--;
            } else if (UNK_PARTNER_SYMBOL->unk_0C < 19.0f) {
                UNK_PARTNER_SYMBOL->unk_0C++;
            }

            tempY = sin_rad((UNK_PARTNER_SYMBOL->unk_18 * TAU) / 360.0f) * 3.0f;

            UNK_PARTNER_SYMBOL->unk_18 += 3.0f;

            if (UNK_PARTNER_SYMBOL->unk_18 > 150.0f) {
                UNK_PARTNER_SYMBOL->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - UNK_PARTNER_SYMBOL->unk_10);
            UNK_PARTNER_SYMBOL->unk_14 += UNK_14_ADDITION;
            if (UNK_PARTNER_SYMBOL->unk_14 > 40.0f) {
                UNK_PARTNER_SYMBOL->unk_14 = 40.0f;
            }

            if (--UNK_PARTNER_SYMBOL->unk_00 == 0) {
                UNK_PARTNER_SYMBOL->unk_04++;
            }
            break;
        case 2:
            npc->flags = UNK_PARTNER_SYMBOL->unk_08;
            UNK_PARTNER_SYMBOL->unk_00 = 0x1E;
            UNK_PARTNER_SYMBOL->unk_04++;
            break;
        case 3:

        #if IS_WALKING_PARTNER == 1
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);
        #else
            partner_flying_update_player_tracking(npc);
            partner_flying_update_motion(npc);
        #endif

            if (--UNK_PARTNER_SYMBOL->unk_00 == 0) {
                UNK_PARTNER_SYMBOL->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return 0;
}
