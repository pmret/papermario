#include "common.h"
#include "../src/world/partners.h"

extern s32 D_802BE934;
extern s32 D_802BE92C;
extern s32 D_802BE928;
extern s32 D_802BE924;
extern s32 D_802BE920;
extern unkPartnerStruct* D_802BE89C_3195EC;

ApiStatus func_802BD338_318088(Evt* evt, s32 arg1);
ApiStatus func_802BD758_3184A8(Evt* evt, s32 isInitialCall);
ApiStatus func_802BE4E8_319238(Evt* script, s32 isInitialCall);
ApiStatus func_802BD300_318050(Evt* script, s32 isInitialCall);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD100_317E50);

void func_802BD2D8_318028(Npc* npc) {
    npc->collisionHeight = 28;
    npc->collisionRadius = 24;
    D_802BE928 = 0;
    D_802BE924 = 0;
}

ApiStatus func_802BD300_318050(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(npc);
    }
    return partner_get_out(npc) != 0;
}

ApiStatus func_802BD338_318088(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc = script->owner2.npc;
    f32 sp10, sp14, tempY;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BE89C_3195EC, sizeof(*D_802BE89C_3195EC));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[3]++;
    npc->flags |= 0x10000;
    entity = D_8010C954;

    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return ApiStatus_BLOCK;
    }

    switch (D_802BE89C_3195EC->unk_04) {
        case 0:
            D_802BE89C_3195EC->unk_04 = 1;
            D_802BE89C_3195EC->unk_08 = npc->flags;
            D_802BE89C_3195EC->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            D_802BE89C_3195EC->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            D_802BE89C_3195EC->unk_14 = 6.0f;
            D_802BE89C_3195EC->unk_18 = 50.0f;
            D_802BE89C_3195EC->unk_00 = 0x78;
            npc->flags |= 0x40148;
            npc->flags &= ~0x200;
        case 1:
            sin_cos_rad((D_802BE89C_3195EC->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            npc->pos.x = entity->position.x + (sp10 * D_802BE89C_3195EC->unk_0C);
            npc->pos.z = entity->position.z - (sp14 * D_802BE89C_3195EC->unk_0C);

            D_802BE89C_3195EC->unk_10 = clamp_angle(D_802BE89C_3195EC->unk_10 - D_802BE89C_3195EC->unk_14);
            if (D_802BE89C_3195EC->unk_0C > 20.0f) {
                D_802BE89C_3195EC->unk_0C--;
            } else if (D_802BE89C_3195EC->unk_0C < 19.0f) {
                D_802BE89C_3195EC->unk_0C++;
            }

            tempY = sin_rad((D_802BE89C_3195EC->unk_18 * TAU) / 360.0f) * 3.0f;

            D_802BE89C_3195EC->unk_18 += 3.0f;

            if (D_802BE89C_3195EC->unk_18 > 150.0f) {
                D_802BE89C_3195EC->unk_18 = 150.0f;
            }
            npc->pos.y += tempY;

            npc->renderYaw = clamp_angle(360.0f - D_802BE89C_3195EC->unk_10);
            D_802BE89C_3195EC->unk_14 += 0.8;
            if (D_802BE89C_3195EC->unk_14 > 40.0f) {
                D_802BE89C_3195EC->unk_14 = 40.0f;
            }

            if (--D_802BE89C_3195EC->unk_00 == 0) {
                D_802BE89C_3195EC->unk_04++;
            }
            break;
        case 2:
            npc->flags = D_802BE89C_3195EC->unk_08;
            D_802BE89C_3195EC->unk_00 = 0x1E;
            D_802BE89C_3195EC->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--D_802BE89C_3195EC->unk_00 == 0) {
                D_802BE89C_3195EC->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

void func_802BD6DC_31842C(Npc* npc) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        npc->flags = D_802BE89C_3195EC->unk_08;
        D_802BE89C_3195EC->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

s32 func_802BD720_318470(void) {
    if (gPartnerActionStatus.actionState.b[0] != 0) {
        D_802BE934 = 1;
        return FALSE;
    }
    return TRUE;
}

s32 func_802BD748(void) {
    return gPartnerActionStatus.actionState.b[0] == 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD758_3184A8);

ApiStatus func_802BE4E8_319238(Evt* script, s32 isInitialCall) {
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

s32 func_802BE520_319270(Npc* npc1, Npc* npc2) {
    f32 sp20, sp24, sp28;
    f32 temp_f6, temp_f20, temp_f22, temp_f24, temp_f26, temp_f28;
    s32 slippingResult;
    f32 distance;
    s32 ret;
    f32 temp2;
    f32 height;

    if (D_802BE928 == 0) {
        return FALSE;
    }

    temp_f26 = npc2->pos.x;
    temp_f28 = npc1->pos.x;

    sp20 = npc2->pos.x - npc1->pos.x;
    sp24 = (npc2->pos.y + (f32)(npc2->collisionHeight * 0.5) - npc1->pos.y);
    temp_f22 = npc2->pos.z;
    temp_f24 = npc1->pos.z;
    sp28 = temp_f22 - temp_f24;
    temp_f6 = npc2->collisionRadius * 0.55;
    height = 35.0f;

    temp2 = sqrtf(SQ(sp20) + SQ(sp24) + SQ(sp28));
    ret = FALSE;

    if (temp2 < (temp_f6 + height)) {
        ret = TRUE;
    }

    temp_f20 = atan2(temp_f26, temp_f22, temp_f28, temp_f24);
    distance = dist2D(temp_f26, temp_f22, temp_f28, temp_f24);

    sp20 = npc1->pos.x;
    sp24 = npc1->pos.y;
    sp28 = npc1->pos.z;

    slippingResult = npc_test_move_taller_with_slipping(0, &sp20, &sp24, &sp28, distance, temp_f20, height, 2.0f);

    if (slippingResult) {
        return FALSE;
    }

    return ret;
}

void func_802BE6E8_319438(Npc* npc) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    f32 phi_f12;
    f32* new_var0;
    f32* new_var1;

    if (partnerActionStatus->actionState.b[0] != 0) {
        if (D_802BE92C) {
            enable_player_input();
        }

        D_802BE928 = 0;
        playerStatus->flags &= -3;
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~0x800;

        set_action_state(0);
        partner_clear_player_tracking(npc);

        partnerActionStatus->actionState.b[0] = 0;
        partnerActionStatus->actionState.b[3] = 0;

        npc->pos.x = playerStatus->position.x;
        npc->pos.y = playerStatus->position.y;
        npc->pos.z = playerStatus->position.z;

        if (D_802BE920 == 0) {
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw + 90.0f));
        } else {
            add_vec2D_polar(&npc->pos.x, &npc->pos.z, playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw - 90.0f));
        }

        npc->jumpVelocity = 0.0f;
        npc->pos.y = playerStatus->position.y;
        npc->rotation.x = 0.0f;
        npc->rotation.z = 0.0f;
        npc->currentAnim.w = 0x30003;
        partner_clear_player_tracking(npc);
        disable_npc_blur(npc);

        if (D_802BE924) {
            D_802BE924 = 0;
            sfx_stop_sound(0x80000000);
        }
    }
}

EvtSource D_802BE880_3195D0 = {
    EVT_CALL(func_802BD300_318050)
    EVT_RETURN
    EVT_END
};

unkPartnerStruct* D_802BE89C_3195EC = (unkPartnerStruct*)0x802BE940;

EvtSource D_802BE89C_3195F0 = {
    EVT_CALL(func_802BD338_318088)
    EVT_RETURN
    EVT_END
};

EvtSource nextScript = {
    EVT_CALL(func_802BD758_3184A8)
    EVT_RETURN
    EVT_END
};

EvtSource nextScript2 = {
    EVT_CALL(func_802BE4E8_319238)
    EVT_RETURN
    EVT_END
};



