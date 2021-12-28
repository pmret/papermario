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
void entity_interacts_with_current_partner(s32 arg0);

void func_802BD100_317E50(Npc* npc) {
    f32 sp20, sp24, sp28;
    f32 phi_f20 = 0.0f;
    
    while (phi_f20 < 360.0f) {
        sp20 = npc->pos.x;
        sp24 = npc->pos.y;
        sp28 = npc->pos.z;
        if (npc_test_move_taller_with_slipping(0x100000, &sp20, &sp24, &sp28, 30.0f, clamp_angle(npc->yaw + phi_f20),
                                               npc->collisionHeight, npc->collisionRadius) != 0) {
            break;
        } else {
            phi_f20 += 45.0f;
        }
    }

    if (phi_f20 >= 360.0f) {
        phi_f20 = 0.0f;

        while (phi_f20 < 360.0f) {
            sp20 = npc->pos.x;
            sp24 = npc->pos.y;
            sp28 = npc->pos.z;
            if (npc_test_move_taller_with_slipping(0x40000, &sp20, &sp24, &sp28, 30.0f, clamp_angle(npc->yaw + phi_f20),
                                                   npc->collisionHeight, npc->collisionRadius) != 0) {
                break;
            } else {
                phi_f20 += 45.0f;
            }
        }
        
        if (!(phi_f20 >= 360.0f)) {
            if (D_8010C978 >= 0 && (D_8010C978 & 0x4000) != 0) {
                entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
            }
        }
    } else {
        if (D_8010C978 >= 0 && (D_8010C978 & 0x4000) != 0) {
            entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
        }
    }
}

void world_bombette_init(Npc* bombette) {
    bombette->collisionHeight = 28;
    bombette->collisionRadius = 24;
    D_802BE928 = 0;
    D_802BE924 = 0;
}

ApiStatus func_802BD300_318050(Evt* script, s32 isInitialCall) {
    Npc* bombette = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(bombette);
    }

    return partner_get_out(bombette) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

ApiStatus func_802BD338_318088(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* bombette = script->owner2.npc;
    f32 sp10, sp14, tempY;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(bombette, 1);
        mem_clear(D_802BE89C_3195EC, sizeof(*D_802BE89C_3195EC));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[3]++;
    bombette->flags |= NPC_FLAG_DIRTY_SHADOW;
    entity = D_8010C954;

    if (entity == NULL) {
        partner_walking_update_player_tracking(bombette);
        partner_walking_update_motion(bombette);
        return ApiStatus_BLOCK;
    }

    switch (D_802BE89C_3195EC->unk_04) {
        case 0:
            D_802BE89C_3195EC->unk_04 = 1;
            D_802BE89C_3195EC->flags = bombette->flags;
            D_802BE89C_3195EC->unk_0C = fabsf(dist2D(bombette->pos.x, bombette->pos.z,
                                                     entity->position.x, entity->position.z));
            D_802BE89C_3195EC->unk_10 = atan2(entity->position.x, entity->position.z,
                                              bombette->pos.x, bombette->pos.z);
            D_802BE89C_3195EC->unk_14 = 6.0f;
            D_802BE89C_3195EC->unk_18 = 50.0f;
            D_802BE89C_3195EC->unk_00 = 120;
            bombette->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            bombette->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((D_802BE89C_3195EC->unk_10 * TAU) / 360.0f, &sp10, &sp14);
            bombette->pos.x = entity->position.x + (sp10 * D_802BE89C_3195EC->unk_0C);
            bombette->pos.z = entity->position.z - (sp14 * D_802BE89C_3195EC->unk_0C);
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

            bombette->pos.y += tempY;
            bombette->renderYaw = clamp_angle(360.0f - D_802BE89C_3195EC->unk_10);
            D_802BE89C_3195EC->unk_14 += 0.8;

            if (D_802BE89C_3195EC->unk_14 > 40.0f) {
                D_802BE89C_3195EC->unk_14 = 40.0f;
            }

            if (--D_802BE89C_3195EC->unk_00 == 0) {
                D_802BE89C_3195EC->unk_04++;
            }
            break;
        case 2:
            bombette->flags = D_802BE89C_3195EC->flags;
            D_802BE89C_3195EC->unk_00 = 0x1E;
            D_802BE89C_3195EC->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(bombette);
            partner_walking_update_motion(bombette);

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
        npc->flags = D_802BE89C_3195EC->flags;
        D_802BE89C_3195EC->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

s32 world_bombette_can_use_ability(void) {
    if (gPartnerActionStatus.actionState.b[0] != 0) {
        D_802BE934 = 1;
        return FALSE;
    }
    return TRUE;
}

s32 world_bombette_can_player_pause(void) {
    return gPartnerActionStatus.actionState.b[0] == 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD758_3184A8);

ApiStatus func_802BE4E8_319238(Evt* script, s32 isInitialCall) {
    Npc* bombette = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(bombette);
    }

    return partner_put_away(bombette) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

s32 world_bombette_test_first_strike(Npc* bombette, Npc* enemy) {
    f32 adjustedDistanceX, adjustedDistanceY, adjustedDistanceZ;
    f32 temp_f6, temp_f20, npcZPos, bombetteZPos, npcXPos, bombetteXPos;
    s32 slippingResult;
    f32 distance;
    s32 ret;
    f32 temp2;
    f32 height;

    if (D_802BE928 == 0) {
        return FALSE;
    }

    npcXPos = enemy->pos.x;
    bombetteXPos = bombette->pos.x;
    adjustedDistanceX = enemy->pos.x - bombette->pos.x;

    adjustedDistanceY = (enemy->pos.y + (f32)(enemy->collisionHeight * 0.5) - bombette->pos.y);

    npcZPos = enemy->pos.z;
    bombetteZPos = bombette->pos.z;
    adjustedDistanceZ = npcZPos - bombetteZPos;

    temp_f6 = enemy->collisionRadius * 0.55;
    height = 35.0f;
    temp2 = sqrtf(SQ(adjustedDistanceX) + SQ(adjustedDistanceY) + SQ(adjustedDistanceZ));
    ret = FALSE;

    if (temp2 < (temp_f6 + height)) {
        ret = TRUE;
    }

    temp_f20 = atan2(npcXPos, npcZPos, bombetteXPos, bombetteZPos);
    distance = dist2D(npcXPos, npcZPos, bombetteXPos, bombetteZPos);

    adjustedDistanceX = bombette->pos.x;
    adjustedDistanceY = bombette->pos.y;
    adjustedDistanceZ = bombette->pos.z;

    slippingResult = npc_test_move_taller_with_slipping(0, &adjustedDistanceX, &adjustedDistanceY, &adjustedDistanceZ,
                                                        distance, temp_f20, height, 2.0f);

    if (slippingResult) {
        return FALSE;
    }

    return ret;
}

void world_bombette_pre_battle(Npc* bombette) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* bombetteActionStatus = &gPartnerActionStatus;

    if (bombetteActionStatus->actionState.b[0] != 0) {
        if (D_802BE92C) {
            enable_player_input();
        }

        D_802BE928 = 0;
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_JUMPING;
        bombette->jumpVelocity = 0.0f;
        bombette->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;

        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(bombette);

        bombetteActionStatus->actionState.b[0] = 0;
        bombetteActionStatus->actionState.b[3] = 0;

        bombette->pos.x = playerStatus->position.x;
        bombette->pos.y = playerStatus->position.y;
        bombette->pos.z = playerStatus->position.z;

        if (D_802BE920 == 0) {
            add_vec2D_polar(&bombette->pos.x, &bombette->pos.z,
                            playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw + 90.0f));
        } else {
            add_vec2D_polar(&bombette->pos.x, &bombette->pos.z,
                            playerStatus->colliderDiameter / 4, clamp_angle(playerStatus->targetYaw - 90.0f));
        }

        bombette->jumpVelocity = 0.0f;
        bombette->pos.y = playerStatus->position.y;
        bombette->rotation.x = 0.0f;
        bombette->rotation.z = 0.0f;
        bombette->currentAnim.w = 0x30003;
        partner_clear_player_tracking(bombette);
        disable_npc_blur(bombette);

        if (D_802BE924) {
            D_802BE924 = 0;
            sfx_stop_sound(0x80000000);
        }
    }
}

EvtSource world_bombette_take_out = {
    EVT_CALL(func_802BD300_318050)
    EVT_RETURN
    EVT_END
};

unkPartnerStruct* D_802BE89C_3195EC = &D_802BE940;

EvtSource world_bombette_update = {
    EVT_CALL(func_802BD338_318088)
    EVT_RETURN
    EVT_END
};

EvtSource world_bombette_use_ability = {
    EVT_CALL(func_802BD758_3184A8)
    EVT_RETURN
    EVT_END
};

EvtSource world_bombette_put_away = {
    EVT_CALL(func_802BE4E8_319238)
    EVT_RETURN
    EVT_END
};
