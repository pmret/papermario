#include "common.h"
#include "goompa.h"
#include "../src/world/partners.h"

extern unkPartnerStruct* D_802BD58C_324E9C;
ApiStatus func_802BD14C_324A5C(Evt* script, s32 isInitialCall);

void world_goompa_init(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionRadius = 20;
}

ApiStatus GoompaTakeOut(Evt* script, s32 isInitialCall) {
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

ApiStatus func_802BD14C_324A5C(Evt* evt, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    f32 sp10, sp14, tempY;
    Entity* entity;

    npc = evt->owner2.npc;
    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BD58C_324E9C, sizeof(*D_802BD58C_324E9C));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[5]++;
    entity = D_8010C954;
    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return ApiStatus_BLOCK;
    }

    switch (D_802BD58C_324E9C->unk_04) {
        case 0:
            D_802BD58C_324E9C->unk_04 = 1;
            D_802BD58C_324E9C->unk_08 = npc->flags;
            D_802BD58C_324E9C->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BD58C_324E9C->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BD58C_324E9C->unk_14 = 6.0f;
            D_802BD58C_324E9C->unk_18 = 50.0f;
            D_802BD58C_324E9C->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BD58C_324E9C->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BD58C_324E9C->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BD58C_324E9C->unk_0C);

            D_802BD58C_324E9C->unk_10 = clamp_angle(D_802BD58C_324E9C->unk_10 - D_802BD58C_324E9C->unk_14);
            if (D_802BD58C_324E9C->unk_0C > 20.0f) {
                D_802BD58C_324E9C->unk_0C--;
            } else if (D_802BD58C_324E9C->unk_0C < 19.0f) {
                D_802BD58C_324E9C->unk_0C++;
            }

            tempY = sin_rad((D_802BD58C_324E9C->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BD58C_324E9C->unk_18 += 3.0f;

            if (D_802BD58C_324E9C->unk_18 > 150.0f) {
                D_802BD58C_324E9C->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BD58C_324E9C->unk_10);
            D_802BD58C_324E9C->unk_14 += 0.8;
            if (D_802BD58C_324E9C->unk_14 > 40.0f) {
                D_802BD58C_324E9C->unk_14 = 40.0f;
            }

            if (--D_802BD58C_324E9C->unk_00 == 0) {
                D_802BD58C_324E9C->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BD58C_324E9C->unk_08;
            D_802BD58C_324E9C->unk_00 = 0x1E;
            D_802BD58C_324E9C->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--D_802BD58C_324E9C->unk_00 == 0) {
                D_802BD58C_324E9C->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

void func_802BD4E0_324DF0(Npc* npc) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        npc->flags = D_802BD58C_324E9C->unk_08;
        D_802BD58C_324E9C->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

ApiStatus GoompaUseAbility(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus GoompaPutAway(Evt* script, s32 isInitialCall) {
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

EvtSource world_goompa_take_out = {
    EVT_CALL(GoompaTakeOut)
    EVT_RETURN
    EVT_END
};

unkPartnerStruct* D_802BD58C_324E9C = (unkPartnerStruct*)0x802BD600;

EvtSource world_goompa_update = {
    EVT_CALL(func_802BD14C_324A5C)
    EVT_RETURN
    EVT_END
};

EvtSource world_goompa_use_ability = {
    EVT_CALL(GoompaUseAbility)
    EVT_RETURN
    EVT_END
};

EvtSource world_goompa_put_away = {
    EVT_CALL(GoompaPutAway)
    EVT_RETURN
    EVT_END
};
