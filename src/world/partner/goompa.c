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
    Npc* goompa = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(goompa);
    }

    return partner_get_out(goompa) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

ApiStatus func_802BD14C_324A5C(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* goompa = script->owner2.npc;
    f32 sp10, sp14, tempY;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(goompa, 1);
        mem_clear(D_802BD58C_324E9C, sizeof(*D_802BD58C_324E9C));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[5]++;
    entity = D_8010C954;

    if (entity == NULL) {
        partner_walking_update_player_tracking(goompa);
        partner_walking_update_motion(goompa);
        return ApiStatus_BLOCK;
    }

    switch (D_802BD58C_324E9C->unk_04) {
        case 0:
            D_802BD58C_324E9C->unk_04 = 1;
            D_802BD58C_324E9C->flags = goompa->flags;
            D_802BD58C_324E9C->unk_0C = fabsf(dist2D(goompa->pos.x, goompa->pos.z,
                                                    entity->position.x, entity->position.z));
            D_802BD58C_324E9C->unk_10 = atan2(entity->position.x, entity->position.z, goompa->pos.x, goompa->pos.z);
            D_802BD58C_324E9C->unk_14 = 6.0f;
            D_802BD58C_324E9C->unk_18 = 50.0f;
            D_802BD58C_324E9C->unk_00 = 120;
            goompa->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100 | NPC_FLAG_40000;
            goompa->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((D_802BD58C_324E9C->unk_10 * TAU) / 360.0f, &sp10, &sp14);
            goompa->pos.x = entity->position.x + (sp10 * D_802BD58C_324E9C->unk_0C);
            goompa->pos.z = entity->position.z - (sp14 * D_802BD58C_324E9C->unk_0C);
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

            goompa->pos.y += tempY;
            goompa->renderYaw = clamp_angle(360.0f - D_802BD58C_324E9C->unk_10);
            D_802BD58C_324E9C->unk_14 += 0.8;

            if (D_802BD58C_324E9C->unk_14 > 40.0f) {
                D_802BD58C_324E9C->unk_14 = 40.0f;
            }

            if (--D_802BD58C_324E9C->unk_00 == 0) {
                D_802BD58C_324E9C->unk_04++;
            }
            break;
        case 2:
            goompa->flags = D_802BD58C_324E9C->flags;
            D_802BD58C_324E9C->unk_00 = 30;
            D_802BD58C_324E9C->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(goompa);
            partner_walking_update_motion(goompa);

            if (--D_802BD58C_324E9C->unk_00 == 0) {
                D_802BD58C_324E9C->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

void func_802BD4E0_324DF0(Npc* goompa) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        goompa->flags = D_802BD58C_324E9C->flags;
        D_802BD58C_324E9C->unk_04 = 0;
        partner_clear_player_tracking(goompa);
    }
}

ApiStatus GoompaUseAbility(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus GoompaPutAway(Evt* script, s32 isInitialCall) {
    Npc* goompa = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goompa);
    }

    return partner_put_away(goompa) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
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
