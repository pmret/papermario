#include "common.h"
#include "../src/world/partners.h"
#include "npc.h"

extern unkPartnerStruct* D_802BFDF8_320B68;
extern s32 D_802BFEEC;
extern f32 D_802BFEE0;
extern void func_802BD368_31E0D8(s32, f32, f32, f32, f32, f32);
extern void playFX_23(s32, f32, f32, f32, s32);
extern s32 partner_use_ability(void);
extern void partner_kill_ability_script(void);
extern s32 D_802BFEE4;
extern s32 D_802BFEE8;
extern s32 D_802BFEF0;
extern s32 D_802BFEF4;
extern f32 D_802BFDB0_320B20;
extern f32 D_802BFDB4_320B24;
extern s16 D_8010C97A;


void func_802BD100_31DE70(void) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam =  gCameras;
    s32 phi_v1;

    playerStatus->position.x = partnerNPC->pos.x;
    playerStatus->position.y = partnerNPC->pos.y + 16.0f;
    playerStatus->position.z = partnerNPC->pos.z;
    playerStatus->targetYaw = partnerNPC->yaw;

    if (playerStatus->spriteFacingAngle < 90.0f || playerStatus->spriteFacingAngle > 270.0f) {
        phi_v1 = -8;
    } else {
        phi_v1 = 8;
    }

    playerStatus->position.z -= cos_rad(((((cam->currentYaw + playerStatus->spriteFacingAngle) - 90.0f) + phi_v1) * TAU) / 360.0f) * -4.0f;
}

void func_802BD20C_31DF7C(f32* arg0, f32* arg1) {
    f32 temp_f22;
    f32 phi_f20;
    f32 temp_f2 = gPartnerActionStatus.stickY;
    f32 temp_f0 = gPartnerActionStatus.stickX;
    
    D_802BFDB0_320B20 = temp_f0;
    D_802BFDB4_320B24 = temp_f2;
    temp_f22 = clamp_angle(atan2(0.0f, 0.0f, temp_f0, -temp_f2) + gCameras->currentYaw);
    phi_f20 = 0.0f;

    if (dist2D(0.0f, 0.0f, D_802BFDB0_320B20, -D_802BFDB4_320B24) >= 1.0) {
        if (SQ(D_802BFDB0_320B20) + SQ(D_802BFDB4_320B24) > 3025.0f) {
            if (D_802BFEE4) {
                phi_f20 = 2.0f;
            } else {
                phi_f20 = 4.0f;
            }
        } else {
            phi_f20 = 2.0f;
        }
    }

    *arg0 = temp_f22;
    *arg1 = phi_f20;
}

void func_802BD368_31E0D8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 sp20;

    arg2 += 100.0f;
    sp20 = 200.0f;
    
    if (npc_raycast_down_ahead(arg0, &arg1, &arg2, &arg3, &sp20, arg4, arg5) == 0) {
        collisionStatus->currentFloor = -1;
        return;
    }

    collisionStatus->currentFloor = D_8010C97A;
    D_802BFEE0 = arg2;
}

INCLUDE_ASM(s32, "world/partner/sushie", func_802BD414_31E184);

s32 func_802BE280_31EFF0(s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32 arg4, f32 arg5, f32* arg6) {
    f32 sp38, sp3C, sp40, sp44, sp48, sp4C, sp50, sp54, sp58;
    s32 colliderRayResult;

    sin_cos_rad((*arg6 * TAU) / 360.0f, &sp38, &sp3C);
    sp3C = -sp3C;
    sp4C = arg5 + arg4;
    colliderRayResult = test_ray_colliders(0x10000, *arg1, *arg2, *arg3, sp38, 0.0f, sp3C, &sp40, &sp44, &sp48, &sp4C, &sp50, &sp54, &sp58);

    if (colliderRayResult >= 0) {
        *arg6 = atan2(0.0f, 0.0f, sp50, sp58);
    }

    return colliderRayResult;
}

INCLUDE_ASM(s32, "world/partner/sushie", func_802BE3A4_31F114);

void func_802BF520_320290(Npc* npc) {
    npc->collisionHeight = 0x18;
    npc->collisionRadius = 0x24;
    npc->unk_80 = 0x10000;
    D_802BFEEC = 0;
    D_802BFEE4 = 0;
    D_802BFEE8 = 0;
    D_802BFEF0 = 0;
    D_802BFEF4 = 0;
}

s32 func_802BF568_3202D8(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;
 
    if (isInitialCall != 0) {
        partner_init_get_out(npc);
    }

    if (partner_get_out(npc)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_802BF5A0_320310(Evt* evt, s32 isInitialCall) {
    Npc* npc = evt->owner2.npc;
    Entity* entity;
    f32 sp10;
    f32 sp14;
    f32 tempY;

    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BFDF8_320B68, sizeof(*D_802BFDF8_320B68));
        D_8010C954 = 0;
    }

    entity = D_8010C954;
    
    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return ApiStatus_BLOCK;
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

    return ApiStatus_BLOCK;
}

void func_802BF920_320690(Npc* npc) {
    if (D_8010C954 != 0) {
        D_8010C954 = NULL;
        npc->flags = D_802BFDF8_320B68->unk_08;
        D_802BFDF8_320B68->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

s32 func_802BF964_3206D4(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;

    if (isInitialCall != 0) {
        partner_init_put_away(npc);
        gPlayerStatusPtr->animFlags &= 0xFFBFFFFF;
    }

    if (partner_put_away(npc)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }

}

void func_802BF9B8_320728(Npc* npc) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (D_802BFEEC != 0) {
        partnerActionStatus->npc = *npc;
        partnerActionStatus->actionState.b[1] = 1;
        enable_player_static_collisions();
        enable_player_input();
        set_action_state(0);
        partner_clear_player_tracking(npc);
    }

    partnerActionStatus->actionState.b[3] = 7;
}

void func_802BFA58_3207C8(Npc* npc) {
    if (gPartnerActionStatus.actionState.b[1] != 0) {
        *npc = gPartnerActionStatus.npc;
        partner_use_ability();
    }
}

s32 func_802BFAB8_320828(Evt* script, s32 isInitialCall) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_f0;
    s32 funcTemp0;

    if (isInitialCall != 0) {
        script->functionTemp[0] = 0;
        D_802BFEE0 = playerStatus->position.y;
    }
    
    funcTemp0 = script->functionTemp[0];

    switch (funcTemp0) {
        case 0:
            gGameStatusPtr->unk_7D = 1;
            disable_player_static_collisions();
            disable_player_input();
            partnerNPC->pos.x = playerStatus->position.x;
            partnerNPC->pos.z = playerStatus->position.z;
            partnerNPC->pos.y = playerStatus->position.y;
            func_802BD368_31E0D8(partnerNPC->unk_80, partnerNPC->pos.x, partnerNPC->pos.y, partnerNPC->pos.z, partnerNPC->yaw, partnerNPC->collisionRadius * 0.5f);
            partnerNPC->pos.y = D_802BFEE0 - (partnerNPC->collisionHeight * 0.5f);
            temp_f0 = atan2(partnerNPC->pos.x, partnerNPC->pos.z, script->varTable[1], script->varTable[3]);
            partnerNPC->currentAnim.w = 0x7000A;
            partnerNPC->yaw = temp_f0;
            partnerNPC->jumpScale = 0.0f;
            partnerNPC->moveSpeed = 3.0f;
            partnerNPC->moveToPos.x = partnerNPC->pos.x;
            partnerNPC->moveToPos.y = partnerNPC->pos.y;
            partnerNPC->moveToPos.z = partnerNPC->pos.z;
            partnerNPC->flags = (partnerNPC->flags | 0x108) & ~0x200;
            disable_npc_shadow(partnerNPC);
            disable_player_shadow();

            if (script->varTable[0xC] == 0) {
                partner_kill_ability_script();
            } else {
                suggest_player_anim_setUnkFlag(0x8000F);
                if ((partnerNPC->yaw >= 0.0f) && (partnerNPC->yaw <= 180.0f)) {
                    partnerNPC->yawCamOffset = partnerNPC->yaw;
                    partnerNPC->isFacingAway = 1;
                }
            }

            script->functionTemp[1] = 0x19;
            script->functionTemp[0] = 1;
            break;
        case 1:
            npc_move_heading(partnerNPC, partnerNPC->moveSpeed, partnerNPC->yaw);
            func_802BD100_31DE70();
            if (!(script->functionTemp[1] & 3)) {
                playFX_23(0, partnerNPC->pos.x, partnerNPC->moveToPos.y + (partnerNPC->collisionHeight * 0.5f), partnerNPC->pos.z, 0);
            }

            script->functionTemp[1]--;
            if (script->functionTemp[1] == 0) {
                if (script->varTable[0xC] == funcTemp0) {
                    set_action_state(0x21);
                    partner_use_ability();
                    return ApiStatus_DONE2;
                }

                enable_player_static_collisions();
                enable_player_input();
                return ApiStatus_DONE2;
            }

            break;
    }

    return ApiStatus_BLOCK;
}
