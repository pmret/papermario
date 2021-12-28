#include "common.h"
#include "../src/world/partners.h"

extern s32 D_802BEBC0_31CBE0;

extern s32 D_802BEBB0;
extern s32 D_802BEBB4;
extern s32 D_802BEBB8;
extern s32 D_802BEBBC;
extern s32 D_802BEBC4;


void world_parakarry_init(Npc* parakarry) {
    parakarry->collisionHeight = 37;
    parakarry->collisionRadius = 40;
    D_802BEBB0 = 0;
    D_802BEBC0_31CBE0 = 0;
    D_802BEBB4 = 0;
    D_802BEBB8 = 0;
    D_802BEBBC = 0;
    D_802BEBC4 = 0;
}

ApiStatus func_802BD148_3196B8(Evt* script, s32 isInitialCall) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(parakarry);
    }

    return partner_get_out(parakarry) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtSource world_parakarry_take_out = {
    EVT_CALL(func_802BD148_3196B8)
    EVT_RETURN
    EVT_END
};

struct unkPartnerStruct* D_802BEAAC_31B01C = 0x802BEBC8;

ApiStatus func_802BD180_3196F0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Entity* entity;
    Npc* parakarry = script->owner2.npc;
    f32 sp10, sp14, tempY;

    if (isInitialCall) {
        partner_flying_enable(parakarry, 1);
        mem_clear(D_802BEAAC_31B01C, sizeof(*D_802BEAAC_31B01C));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[4]++;
    entity = D_8010C954;

    if (entity == NULL) {
        partner_flying_update_player_tracking(parakarry);
        partner_flying_update_motion(parakarry);
        return ApiStatus_BLOCK;
    }

    switch (D_802BEAAC_31B01C->unk_04) {
        case 0:
            D_802BEAAC_31B01C->unk_04 = 1;
            D_802BEAAC_31B01C->flags = parakarry->flags;
            D_802BEAAC_31B01C->unk_0C = fabsf(dist2D(parakarry->pos.x, parakarry->pos.z,
                                                     entity->position.x, entity->position.z));
            D_802BEAAC_31B01C->unk_10 = atan2(entity->position.x, entity->position.z,
                                              parakarry->pos.x, parakarry->pos.z);
            D_802BEAAC_31B01C->unk_14 = 6.0f;
            D_802BEAAC_31B01C->unk_18 = 50.0f;
            D_802BEAAC_31B01C->unk_00 = 120;
            parakarry->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            parakarry->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((D_802BEAAC_31B01C->unk_10 * TAU) / 360.0f, &sp10, &sp14);
            parakarry->pos.x = entity->position.x + (sp10 * D_802BEAAC_31B01C->unk_0C);
            parakarry->pos.z = entity->position.z - (sp14 * D_802BEAAC_31B01C->unk_0C);
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

            parakarry->pos.y += tempY;
            parakarry->renderYaw = clamp_angle(360.0f - D_802BEAAC_31B01C->unk_10);
            D_802BEAAC_31B01C->unk_14 += 0.8;

            if (D_802BEAAC_31B01C->unk_14 > 40.0f) {
                D_802BEAAC_31B01C->unk_14 = 40.0f;
            }

            if (--D_802BEAAC_31B01C->unk_00 == 0) {
                D_802BEAAC_31B01C->unk_04++;
            }
            break;
        case 2:
            parakarry->flags = D_802BEAAC_31B01C->flags;
            D_802BEAAC_31B01C->unk_00 = 30;
            D_802BEAAC_31B01C->unk_04++;
            break;
        case 3:
            partner_flying_update_player_tracking(parakarry);
            partner_flying_update_motion(parakarry);

            if (--D_802BEAAC_31B01C->unk_00 == 0) {
                D_802BEAAC_31B01C->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtSource world_parakarry_update = {
    EVT_CALL(func_802BD180_3196F0)
    EVT_RETURN
    EVT_END
};

void func_802BD514_319A84(Npc* parakarry) {
    if (D_8010C954) {
        D_8010C954 = 0;
        parakarry->flags = D_802BEAAC_31B01C->flags;
        D_802BEAAC_31B01C->unk_04 = 0;
        partner_clear_player_tracking (parakarry);
    }
}

s32 func_802BD558_319AC8(void) {
    f32 sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    f32 colliderBaseHeight = gPlayerStatus.colliderHeight;
    s32 raycastResult;

    sp28 = gPlayerStatus.position.x;
    sp2C = gPlayerStatus.position.y + (colliderBaseHeight * 0.5);
    sp30 = gPlayerStatus.position.z;
    sp34 = colliderBaseHeight * 0.5f;
    
    raycastResult = player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38,
                                                      &sp3C, &sp40, &sp44);

    if (((get_collider_type_by_id(raycastResult) & 0xFF) - 2) < 2U) {
        gPlayerStatus.unk_BF = 2;
        D_802BEBC0_31CBE0 = 0x15;
        gPlayerStatus.flags |= PLAYER_STATUS_FLAGS_800;
    }

    return raycastResult;
}

s32 func_802BD660_319BD0(void);
INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD660_319BD0);

EvtSource world_parakarry_use_ability = {
    EVT_CALL(func_802BD660_319BD0)
    EVT_RETURN
    EVT_END
};

ApiStatus func_802BE8D4_31AE44(Evt* script, s32 isInitialCall) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(parakarry);
    }

    return partner_put_away(parakarry) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtSource world_parakarry_put_away = {
    EVT_CALL(func_802BE8D4_31AE44)
    EVT_RETURN
    EVT_END
};

void world_parakarry_pre_battle(Npc* parakarry) {
    PartnerActionStatus* parakarryActionStatus = &gPartnerActionStatus;

    if (D_802BEBB0) {
        if (D_802BEBB8) {
            enable_player_static_collisions();
        }

        if (D_802BEBB4) {
            enable_player_input();
        }

        set_action_state(ACTION_STATE_IDLE);
        parakarryActionStatus->npc = *parakarry;
        parakarryActionStatus->actionState.b[1] = 1;
        partner_clear_player_tracking(parakarry);
    }

    parakarryActionStatus->actionState.b[3] = 4;
}

void world_parakarry_post_battle(Npc* parakarry) {
    PartnerActionStatus* parakarryActionStatus = &gPartnerActionStatus;

    if (parakarryActionStatus->actionState.b[1] != 0) {
        if (D_802BEBB8) {
            disable_player_static_collisions();
        }
        if (D_802BEBB4) {
            disable_player_input();
        }

        set_action_state(ACTION_STATE_RIDE);
        *parakarry = parakarryActionStatus->npc;
        parakarryActionStatus->actionState.b[3] = 0;
        parakarryActionStatus->actionState.b[0] = 0;
        partner_clear_player_tracking(parakarry);
        partner_use_ability();
    }
}
