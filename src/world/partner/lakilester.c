#include "common.h"
#include "../partners.h"

extern unkPartnerStruct* D_802BFE7C_3239CC;

extern f64 D_802BFEF0;
extern s32 D_802BFF00;
extern s32 D_802BFF04;
extern s32 D_802BFF08;
extern s32 D_802BFF0C;

s32 func_802BD7DC(void);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD100_320C50);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD21C_320D6C);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD29C_320DEC);

ApiStatus func_802BD2D4_320E24(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Entity* entity;
    Npc* npc = script->owner2.npc;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    if (isInitialCall) {
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
        return ApiStatus_BLOCK;
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
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD678_3211C8);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD6BC_32120C);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD7DC);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BD99C_3214EC);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BDA90_3215E0);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BDDD8_321928);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BE6A0_3221F0);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BE724_322274);

ApiStatus func_802BF4F0_323040(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Camera* cam = &gCameras;
    Npc* partner = script->owner2.npc;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 yaw;
    s32 phi_v1;

    if (isInitialCall) {
        if (D_802BFF0C == 0) {
            phi_v1 = 3;
        } else {
            phi_v1 = 0;
        }
        D_802BFF00 = phi_v1;
        partner_init_put_away(partner);
        func_802BD7DC();
        playerStatus->animFlags &= ~0x400000;
        playerStatus->flags |= 0x100;
    }

    switch (D_802BFF00) {
        case 0:
            func_802BD7DC();
            yaw = cam->currentYaw;
            if ((playerStatus->spriteFacingAngle >= 90.0f) && (playerStatus->spriteFacingAngle < 270.0f)) {
                partner->yaw = (yaw + 180.0f) - 90.0f;
            } else {
                partner->yaw = (yaw + 0.0f) - 90.0f;
            }

            sp2C = dist2D(playerStatus->position.x, playerStatus->position.z,
                          partner->moveToPos.x, partner->moveToPos.z);
            partner->duration = 14;

            if (partner->moveToPos.y > partner->pos.y ) {
                partner->jumpVelocity = (partner->moveToPos.y - partner->pos.y) / 14.0f + 6.0f;
            } else {
                partner->jumpVelocity = 6.0f;
            }
            partner->jumpScale = 1.2f;
            partner->moveSpeed = sp2C / partner->duration;
            partner->yaw = atan2(playerStatus->position.x, playerStatus->position.z,
                                 partner->moveToPos.x, partner->moveToPos.z);
            suggest_player_anim_clearUnkFlag(0x10006);
            D_802BFF00++;
            break;
        case 1:
            suggest_player_anim_clearUnkFlag(0x10007);
            D_802BFF00++;
        case 2:
            playerStatus->position.y += partner->jumpVelocity;
            partner->jumpVelocity -= partner->jumpScale;
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z,
                            partner->moveSpeed, partner->yaw);
            func_800E4AD8(0);
            if (partner->jumpVelocity <= 0.0f) {
                playerStatus->flags |= 4;
                if (partner->jumpVelocity < -10.0) {
                    partner->jumpVelocity = -10.0f;
                }
            }
            sp20 = playerStatus->position.x;
            sp24 = playerStatus->position.y + playerStatus->colliderHeight;
            sp28 = playerStatus->position.z;
            sp2C = playerStatus->colliderHeight;
            if (npc_raycast_down_ahead(0, &sp20, &sp24, &sp28, &sp2C,
                                       partner->yaw, partner->collisionRadius)) {

                D_802BFF00 = 3;
                playerStatus->position.y = sp24;
            }
            break;
    }

    gCameras->targetPos.x = playerStatus->position.x;
    gCameras->targetPos.y = playerStatus->position.y;
    gCameras->targetPos.z = playerStatus->position.z;

    switch (D_802BFF00) {
        case 3:
            partner->flags &= ~0x48;
            if (D_802BFF08) {
                D_802BFF08 = FALSE;
                enable_player_static_collisions();
            }
            enable_player_shadow();
            if (playerStatus->flags & 0x800) {
                partnerActionStatus->actionState.b[3] = 0;
                partnerActionStatus->actionState.b[0] = 0;
                if (D_802BFF04) {
                    D_802BFF04 = FALSE;
                    enable_player_input();
                }
                gGameStatusPtr->unk_7D = 0;
                D_802BFF0C = 0;
                partner_clear_player_tracking(partner);
                set_action_state(ACTION_STATE_HIT_FIRE);
                return ApiStatus_DONE1;
            }
            if (D_802BFF0C == 0) {
                phys_main_collision_below();
            } else {
                set_action_state(ACTION_STATE_FALLING);
                gravity_use_fall_parms();
            }
            D_802BFF00++;
            break;
        case 4:
            partnerActionStatus->actionState.b[3] = 0;
            partnerActionStatus->actionState.b[0] = 0;
            playerStatus->flags &= -0x101;
            if (D_802BFF04) {
                D_802BFF04 = FALSE;
                enable_player_input();
            }
            gGameStatusPtr->unk_7D = 0;
            D_802BFF0C = 0;
            partner_clear_player_tracking(partner);
            D_802BFF00++;
            break;
        case 5:
            if (partner_put_away(partner) == FALSE) {
                break;
            }
            return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFA00_323550);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFAA8_3235F8);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFB44_323694);

INCLUDE_ASM(s32, "world/partner/lakilester", func_802BFBA0_3236F0);
