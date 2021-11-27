#include "common.h"
#include "../src/world/partners.h"

extern unkPartnerStruct* D_802BEB60_31CB80;
s32 entity_interacts_with_current_partner(s32);
s32 test_item_entity_position(f32, f32, f32, f32);
s32 partner_use_ability(void);
s32 npc_raycast_up_corner(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);
extern s32 D_802BEC68;
extern s32 D_802BEC6C;
extern s32 D_802BEC54;
extern s32 D_802BEB40_31CB60;
extern s32 D_802BEC64;
extern s32 D_802BEC58;
extern f32 D_802BEC70;
extern f32 D_802BEC74;
extern f32 D_802BEC78;
extern s32 D_802BEC50;
extern s32 D_802BEC60;
extern s32 D_802BEC5C;
extern s16 D_8010C97A;
void playFX_18(s32, f32, f32, f32, f32, f32, f32, s32);

s32 func_802BD100_31B120(void) {
    if (D_8010C978 < 0) {
        return 0;
    }
    
    if (!(D_8010C978 & 0x4000)) {
        return 0;
    }
    
    return entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
}

void func_802BD144_31B164(void) {
    if (D_8010C978 >= 0 && D_8010C978 & 0x4000) {
        entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
    }
}

s32 func_802BD17C_31B19C(Npc* npc) {
    D_802BEC68 = test_item_entity_position(npc->pos.x, npc->pos.y, npc->pos.z, npc->collisionRadius);
    
    if (D_802BEC68 < 0) {
        return 0;
    } else {
        D_802BEC6C = 1;
        gOverrideFlags |= 0x40;
        set_item_entity_flags(D_802BEC68, ENTITY_FLAGS_200000);
        return 1;
    }
}

void func_802BD200_31B220(Npc* npc) {
    npc->collisionHeight = 37;
    npc->collisionRadius = 24;
    npc->unk_80 = 0x00010000;
    D_802BEC54 = 0;
}

ApiStatus func_802BD228_31B248(Evt* script, s32 isInitialCall) {
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

ApiStatus func_802BD260_31B280(Evt* evt, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc;
    f32 sp10, sp14, tempY;
    Entity* entity;

    npc = evt->owner2.npc;
    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(D_802BEB60_31CB80, sizeof(*D_802BEB60_31CB80));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[2]++;
    entity = D_8010C954;
    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return ApiStatus_BLOCK;
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
    return ApiStatus_BLOCK;
}

void func_802BD5F4_31B614(Npc* npc) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        npc->flags = D_802BEB60_31CB80->unk_08;
        D_802BEB60_31CB80->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

#ifdef NON_EQUIVALENT
ApiStatus func_802BD638_31B658(Evt* script, s32 isInitialCall) {
    Camera* cam;
    ItemEntity* itemGrabbed;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = script->owner2.npc;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 sp20, sp24, sp28, sp2C;
    s32 phi_v0_4 = 0;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 phi_f0;
    f32 phi_f0_3;
    s32 tempVar;
    f32 clamp;
    f32 colheight;
    
    if (currentEncounter->unk_08 == 0) {
        if (isInitialCall) {
            func_802BD5F4_31B614(npc);
            if (playerStatus->animFlags & 0x100000) {
                return ApiStatus_DONE2;
            }

            if (D_802BEC54 == 0) {
                tempVar = playerStatus->actionState;
                if (tempVar < 3U) {
                    script->functionTemp[0] = 20;
                } else {
                    return ApiStatus_DONE2;
                }
                
            }

            else if (partnerActionStatus->actionState.b[0] == 0) {
                partnerActionStatus->actionState.b[0] = 1;
                partnerActionStatus->actionState.b[3] = 2;
                script->functionTemp[0] = 5;
                npc->currentAnim.w = 0x20009;
                D_802BEC50 = 30;
            }
        }
        
        switch (script->functionTemp[0]) {
        case 20:
            if (playerStatus->statusMenuCounterinputEnabledCounter == 0) {
                if (playerStatus->decorationList == 0) {
                    if (npc->flags & 0x1000) {
                        disable_player_input();
                        script->functionTemp[2] = playerStatus->statusMenuCounterinputEnabledCounter;
                        D_802BEC64 = 1;
                        D_802BEB40_31CB60 = 0;
                        D_802BEC6C = 0;
                        npc->flags &= ~0xA08;
                        npc->flags |= 0x140;
                        partnerActionStatus->actionState.b[3] = 2;
                        partnerActionStatus->actionState.b[0] = 1;
                        D_802BEC58 = func_800EF4E0();
                        enable_npc_blur(npc);
                        npc->duration = 4;
                        npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                        script->functionTemp[0]++;
                    } else {
                        return ApiStatus_DONE2;
                    }
                } else {
                    return ApiStatus_DONE2;
                }
            } else {
                return ApiStatus_DONE2;
            }
            break;

        case 21:
            if ((((u8)playerStatus->actionState - 0x15) < 3U) || (playerStatus->decorationList != 0)) {
                suggest_player_anim_clearUnkFlag(0x10002);
                script->functionTemp[0] = 0;
                break;
            } else {
                suggest_player_anim_clearUnkFlag(0x10006);
                
                D_802BEC70 = playerStatus->position.x;
                npc->moveToPos.x = D_802BEC70;
                D_802BEC74 = playerStatus->position.y;
                npc->moveToPos.y = D_802BEC74;
                D_802BEC78 = playerStatus->position.z;
                npc->moveToPos.z = D_802BEC78;
                
                npc->currentAnim.w = 0x20005;
                

                add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, playerStatus->colliderDiameter / 3, playerStatus->targetYaw);
                
                clamp = clamp_angle(playerStatus->targetYaw + ((D_802BEC58 != 0) ? 90.0f : -90.0f));

                add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, playerStatus->colliderDiameter / 4, clamp);
                
                npc->pos.x = (npc->pos.x + ((npc->moveToPos.x - npc->pos.x) / npc->duration));
                npc->pos.y = (npc->pos.y + ((npc->moveToPos.y - npc->pos.y) / npc->duration));
                npc->pos.z = (npc->pos.z + ((npc->moveToPos.z - npc->pos.z) / npc->duration));
                npc->duration -= 1;

                if (npc->duration << 0x10) {
                    break;
                }
                disable_npc_blur(npc);
                if (script->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
                    if (!(playerStatus->animFlags & 0x100000)) {
                        suggest_player_anim_clearUnkFlag(0x10002);
                    } else {
                        suggest_player_anim_clearUnkFlag(0x10005);
                    }
                    script->functionTemp[0] = 0;
                    break;
                } else {
                    npc->yaw = playerStatus->targetYaw;
                    npc->jumpVelocity = 18.0f;
                    npc->jumpScale = 3.0f;

                    npc->currentAnim.w = 0x2000A;
                    npc->collisionHeight = 12;
                    
                    npc->moveToPos.y = playerStatus->position.y;
                    npc->moveToPos.z = playerStatus->position.y + (playerStatus->colliderHeight / 3);

                    playerStatus->flags |= 2;
                    gCameras->moveFlags |= 1;
                    
                    
                    suggest_player_anim_clearUnkFlag(0x10007);
                    D_802BEC60 = 0;
                    sfx_play_sound_at_npc(0x2081, 0, -4);
                    script->functionTemp[0] = 2;
                }
            }
        
        case 2:
            if (((u8)playerStatus->actionState - 0x15) >= 3U) {
                npc->jumpVelocity -= npc->jumpScale;
                playerStatus->position.y += npc->jumpVelocity;
                if (npc->jumpVelocity < 0.0f) {
                    if (D_802BEC60 == 0) {
                        D_802BEC60 = 1;
                        suggest_player_anim_clearUnkFlag(0x10008);
                    }
                }

                colheight = playerStatus->colliderHeight / 2;
                
                sp20 = playerStatus->position.x;
                sp24 = playerStatus->position.y;
                sp28 = playerStatus->position.z;

                sp24 += colheight - npc->jumpVelocity;
                sp24 -= npc->jumpVelocity;

                sp2C = playerStatus->colliderHeight / 2;

                if ((npc_raycast_up(0x10000, &sp20, &sp24, &sp28, &sp2C) != 0) && (sp2C < colheight)) {
                    collisionStatus->currentCeiling = D_8010C97A;
                    playerStatus->position.y = sp24 - playerStatus->colliderHeight;
                    func_802BD144_31B164();
                }

                if (!(npc->jumpVelocity > 0.0f) && (playerStatus->position.y < npc->moveToPos.z)) {
                    D_802BEC5C = 0;
                    npc->flags &= ~0x100;
                    partnerActionStatus->actionState.b[3] = 2;
                    partnerActionStatus->actionState.b[0] = 2;
                    npc->rotation.z = 0.0f;
                    npc->planarFlyDist = 0.0f;
                    npc->moveSpeed = 8.0f;
                    npc->currentAnim.w = 0x20009;
                    D_802BEB40_31CB60 = 1;
                    temp_f20_2 = sin_deg(playerStatus->targetYaw);
                    playFX_18(3, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, temp_f20_2, -1.0f, -cos_deg(playerStatus->targetYaw), 3);
                    start_bounce_b();

                    if (D_802BEC64 != 0) {
                        enable_player_input();
                        D_802BEC64 = 0;
                    }

                    script->functionTemp[0] = 3;
                    D_802BEC60 = 0;
                    gCameras->moveFlags |= 1;
                    sfx_play_sound_at_npc(0x283, 0, -4);
                    sfx_play_sound_at_npc(0x284, 0, -4);
                }
            } else {
                script->functionTemp[0] = 0;
            }
            break;
        case 3:
            if (((u8)playerStatus->actionState - 0x15) > 1U) {
                sp20 = npc->pos.x;
                sp24 = npc->pos.y;
                sp28 = npc->pos.z;

                if (npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, npc->moveSpeed, npc->yaw - 20.0f, npc->collisionHeight, (npc->collisionRadius / 2)) != 0) {
                    if (func_802BD100_31B120() == 0) {
                        sfx_play_sound_at_npc(0x10C, 0, -4);
                    }

                    temp_f20_3 = sin_deg(npc->yaw);
                    playFX_18(3, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, temp_f20_3, -1.0f, -cos_deg(npc->yaw), 1);
                    sfx_play_sound_at_npc(0, 0, -4);
                    script->functionTemp[0] = 7;
                    break;
                }

                sp20 = npc->pos.x;
                sp24 = npc->pos.y;
                sp28 = npc->pos.z;

                if ((npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, npc->moveSpeed, npc->yaw + 20.0f, npc->collisionHeight, npc->collisionRadius / 2) == 0) && (sp20 = npc->pos.x, sp24 = npc->pos.y, sp28 = npc->pos.z, (npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, npc->moveSpeed, npc->yaw, npc->collisionHeight, npc->collisionRadius / 2) == 0))) {
                    npc->pos.x = sp20;
                    npc->pos.y = sp24;
                    npc->pos.z = sp28;
                    npc->planarFlyDist += npc->moveSpeed;
                    func_8003D660(npc, 1);
                    npc->moveSpeed += 2.0;

                    if (npc->moveSpeed > 14.0) {
                        npc->moveSpeed = 14.0f;
                    }

                    if ((func_800397E8(npc, 6.0f) == 0) && ((playerStatus->flags & 6) == 0)) {
                        npc->pos.y = (npc->pos.y + ((playerStatus->position.y - npc->pos.y) / 10.0f));
                    }

                    npc_do_other_npc_collision(npc);

                    if ((npc->flags & 0x2000000) == 0) {
                        if (func_802BD17C_31B19C(npc) != 0) {
                            sfx_play_sound_at_npc(0x286, 0, -4);
                            temp_f20_4 = sin_deg(npc->yaw);
                            playFX_18(3, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, temp_f20_4, -1.0f, -cos_deg(npc->yaw), 1);
                            sfx_play_sound_at_npc(0, 0, -4);
                            script->functionTemp[0] = 4;
                            D_802BEC50 = 8;
                            npc->moveSpeed -= 4.0;
                            if (npc->moveSpeed < 0.01) {
                                npc->moveSpeed = 0.01f;
                                npc->planarFlyDist += 1.0;
                            }
                        }
                        else if (D_802BEB40_31CB60 == 2) {
                            sfx_play_sound_at_npc(0, 0, -4);
                            script->functionTemp[0] = 5;
                            D_802BEC50 = 30;
                            npc->moveSpeed = 0.0f;
                        } else {
                            if (npc->planarFlyDist > 140.0f) {
                                label2:
                                script->functionTemp[0] = 7;
                                npc->moveSpeed = 0.0f;
                                sfx_play_sound_at_npc(0, 0, -4);
                            }
                            
                            else if (npc->planarFlyDist > 105.0f) {
                                npc->moveSpeed -= 4.0;
                                if (npc->moveSpeed < 0.01) {
                                    npc->moveSpeed = 0.01f;
                                    npc->planarFlyDist += 1.0;
                                }
                            }
                            break;
                        }
                    } else {
                        goto label2;
                    }
                } else {
                    if (func_802BD100_31B120() == 0) {
                        sfx_play_sound_at_npc(0x10C, 0, -4);
                    }

                    temp_f20_3 = sin_deg(npc->yaw);
                    playFX_18(3, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, temp_f20_3, -1.0f, -cos_deg(npc->yaw), 1);
                    sfx_play_sound_at_npc(0, 0, -4);
                    script->functionTemp[0] = 7;
                }
            } else {
                script->functionTemp[0] = 0;
            }
            break;
        case 4:
            sp20 = npc->pos.x;
            sp24 = npc->pos.y;
            sp28 = npc->pos.z;

            npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, npc->moveSpeed, npc->yaw, npc->collisionHeight, ( npc->collisionRadius / 2));
            npc->pos.x = sp20;
            npc->pos.y = sp24;
            npc->pos.z = sp28;

            npc->planarFlyDist += npc->moveSpeed;
            func_8003D660(npc, 1);
            npc->moveSpeed -= 6.0;

            if (npc->moveSpeed < 0.01) {
                npc->moveSpeed = 0.01f;
                npc->planarFlyDist += 1.0;
            }

            if (D_802BEC50 == 0) {
                script->functionTemp[0] = 7;
            }
            D_802BEC50--;
            break;
            
        case 5:
            if (D_802BEC50 != 0) {
                D_802BEC50--;
            } else {
                script->functionTemp[0] = 7;
            }
            break;
        }

        if (script->functionTemp[0] == 7) {
            npc->flags |= 0x100;
            if (((u8)playerStatus->actionState - 0x15) < 2U) {
                script->functionTemp[0] = 0;
            } else {
                temp_f20_5 = atan2(D_802BEC70, D_802BEC78, npc->pos.x, npc->pos.z);
                npc->yaw = temp_f20_5 + (get_clamped_angle_diff(npc->yaw, temp_f20_5) * 0.125f);
                npc_move_heading(npc, -npc->moveSpeed, npc->yaw);
                npc->planarFlyDist -= npc->moveSpeed;
                func_8003D660(npc, 1);
                npc->moveSpeed += 1.3333333333333333;

                if (npc->moveSpeed > 14.0) {
                    npc->moveSpeed = 14.0f;
                }

                if (func_800397E8(npc, 6.0f) == 0) {
                    npc->pos.y = (npc->pos.y + ((playerStatus->position.y - npc->pos.y) / 10.0f));
                }

                sp20 = npc->pos.x;
                sp24 = npc->pos.y;
                sp28 = npc->pos.z;

                if (npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, npc->moveSpeed, clamp_angle(npc->yaw + 180.0f), npc->collisionHeight, npc->collisionRadius) != 0) {
                    npc->pos.x = sp20;
                    npc->pos.y = sp24;
                    npc->pos.z = sp28;
                    sfx_play_sound_at_npc(0x10C, 0, -4);
                    temp_f20_6 = sin_deg(npc->yaw + 180.0f);
                    playFX_18(3, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, temp_f20_6, -1.0f, -cos_deg(npc->yaw + 180.0f), 1);
                    script->functionTemp[0] = 0;
                } else {
                    if (D_802BEC6C != 0) {
                        itemGrabbed = get_item_entity(D_802BEC68);
                        sp20 = npc->pos.x;
                        sp24 = npc->pos.y + 8.0f;
                        sp28 = npc->pos.z;

                        clamp = clamp_angle(playerStatus->targetYaw - ((D_802BEC58) ? 90.0f : -90.0f));

                        add_vec2D_polar(&sp20, &sp28, 4.0f, clamp);
                        itemGrabbed->position.x = sp20;
                        itemGrabbed->position.y = sp24;
                        itemGrabbed->position.z = sp28;
                    }

                    if (npc->planarFlyDist + 15.0f < npc->moveSpeed) {
                        script->functionTemp[0] = 0;
                    } else if (npc->planarFlyDist + 15.0f < 35.0f) {
                        npc->moveSpeed -= 4.0;
                        if (npc->moveSpeed < 4.0) {
                            npc->moveSpeed = 4.0;
                        }
                    }
                }
            }
        }

        if (script->functionTemp[0] == 0) {
            if (D_802BEC64 != 0) {
                enable_player_input();
                D_802BEC64 = 0;
            }

            D_802BEB40_31CB60 = 0;
            npc->flags |= 0x100;
            npc->flags &= ~0x840;
            partnerActionStatus->actionState.b[3] = 0;
            partnerActionStatus->actionState.b[0] = 0;
            npc->jumpVelocity = 0.0f;
            npc->collisionHeight = 24;
            npc->currentAnim.w = 0x20000 | 4;
            sfx_stop_sound(0x284);
            disable_npc_blur(npc);

            if (D_802BEC6C != 0) {
                func_801341B0(D_802BEC68);
                D_802BEC6C = 0;
            }

            D_802BEC54 = 0;
            partner_clear_player_tracking(npc);
            return ApiStatus_DONE2;
        }
        /* Duplicate return node #104. Try simplifying control flow for better match */
        return ApiStatus_BLOCK;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/partner/kooper", func_802BD638_31B658);
#endif

ApiStatus func_802BE7E0_31C800(Evt* script, s32 isInitialCall) {
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

#ifdef NON_EQUIVALENT
s32 func_802BE818_31C838(Npc* npcKooper, Npc* npc2) {
    f32 npcKooperXTemp, npcKooperYTemp, npcKooperZTemp;
    f32 npcX, npcY, npcZ;
    f32 npcKooperX, npcKooperY, npcKooperZ;
    f32 npcCollisionHeight, kooperCollisionHeight;
    f32 npcCollisionRadius, kooperCollisionRadius;
    f32 temp_f0, temp_f20;
    f32 npcDistanceToKooperX;
    f32 new_var2;

    if (D_802BEB40_31CB60) {
        npcX = npc2->pos.x;
        npcY = npc2->pos.y;
        npcZ = npc2->pos.z;

        npcDistanceToKooperX = npcKooper->pos.x;
        npcKooperX = npcDistanceToKooperX;
        npcKooperY = npcKooper->pos.y;
        npcKooperZ = npcKooper->pos.z;
        
        npcCollisionHeight = npc2->collisionHeight;
        npcCollisionRadius = npc2->collisionRadius * 0.8;
        kooperCollisionHeight = npcKooper->collisionHeight;
        kooperCollisionRadius = npcKooper->collisionRadius * 0.55;

        temp_f20 = atan2(npcX, npcZ, npcKooperX, npcKooperZ);
        temp_f0 = dist2D(npcX, npcZ, npcKooperX, npcKooperZ);

        npcKooperX = npcDistanceToKooperX;
        npcKooperXTemp = npcKooper->pos.x;
        npcKooperYTemp = npcKooper->pos.y;
        npcKooperZTemp = npcKooper->pos.z;

        if (npc_test_move_taller_with_slipping(0, &npcKooperXTemp, &npcKooperYTemp, &npcKooperZTemp, temp_f0, temp_f20, kooperCollisionHeight, kooperCollisionRadius + npcCollisionRadius) == 0) {
            if (!((npcKooperY) > npcCollisionHeight + npcY)) {
                if (!((kooperCollisionHeight + npcCollisionHeight) < npcY)) {
                    npcDistanceToKooperX = npcX - npcKooperX;
                    new_var2 = SQ(npcDistanceToKooperX);
                    npcKooperX = (SQ(kooperCollisionRadius)) + (SQ(npcCollisionRadius));
                    npcKooperZ = npcZ - npcKooperZ;
                    if (!(npcKooperX <= (new_var2 + (SQ(npcKooperZ))))) {
                        D_802BEB40_31CB60 = 2;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}
#else
INCLUDE_ASM(s32, "world/partner/kooper", func_802BE818_31C838);
#endif

void func_802BEA24_31CA44(Npc* npc) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    D_802BEC54 = 0;

    if (gPartnerActionStatus.actionState.b[0] != 0) {
        if (gPartnerActionStatus.actionState.b[0] == 2) {
            D_802BEC54 = 1;
        }

        if (D_802BEC64) {
            enable_player_input();
            D_802BEC64 = 0;
        }

        D_802BEB40_31CB60 = 0;
        playerStatus->flags &= -3;
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~0x800;
        npc->flags &= ~0x40;
        sfx_stop_sound(0x284);
        set_action_state(0);
        partner_clear_player_tracking(npc);
        disable_npc_blur(npc);
        partnerActionStatus->actionState.b[3] = 0;
        partnerActionStatus->actionState.b[0] = 0;
    }
}

void func_802BEB10_31CB30(Npc* npc) {
    if (D_802BEC54) {
        partner_clear_player_tracking(npc);
        partner_use_ability();
    }
}
