#include "common.h"
#include "../src/world/partners.h"

extern s16 D_8010C97A;

s32 entity_interacts_with_current_partner(s32);
s32 test_item_entity_position(f32, f32, f32, f32);
s32 npc_raycast_up_corner(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);
s32 npc_raycast_up(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);
void start_bounce_b(void);
void playFX_18(s32, f32, f32, f32, f32, f32, f32, s32);
void func_801341B0(Npc* npc);

BSS s32 D_802BEC50;
BSS s32 D_802BEC54;
BSS s32 D_802BEC58;
BSS s32 D_802BEC5C;
BSS s32 D_802BEC60;
BSS s32 D_802BEC64;
BSS s32 D_802BEC68;
BSS s32 D_802BEC6C;
BSS f32 D_802BEC70;
BSS f32 D_802BEC74;
BSS f32 D_802BEC78;
BSS s32 D_802BEC7C;

s32 D_802BEB40_31CB60 = 0;

s32 func_802BD100_31B120(Npc* npc) {
    if (D_8010C978 < 0) {
        return 0;
    }

    if (!(D_8010C978 & 0x4000)) {
        return 0;
    }

    return entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
}

void func_802BD144_31B164(Npc* kooper) {
    if (D_8010C978 >= 0 && D_8010C978 & 0x4000) {
        entity_interacts_with_current_partner(D_8010C978 & ~0x4000);
    }
}

s32 func_802BD17C_31B19C(Npc* kooper) {
    D_802BEC68 = test_item_entity_position(kooper->pos.x, kooper->pos.y, kooper->pos.z, kooper->collisionRadius);

    if (D_802BEC68 < 0) {
        return 0;
    } else {
        D_802BEC6C = 1;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        set_item_entity_flags(D_802BEC68, ENTITY_FLAGS_200000);
        return 1;
    }
}

void world_kooper_init(Npc* kooper) {
    kooper->collisionHeight = 37;
    kooper->collisionRadius = 24;
    kooper->unk_80 = 0x00010000;
    D_802BEC54 = 0;
}

ApiStatus func_802BD228_31B248(Evt* script, s32 isInitialCall) {
    Npc* kooper = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(kooper);
    }

    return partner_get_out(kooper) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtSource world_kooper_take_out = {
    EVT_CALL(func_802BD228_31B248)
    EVT_RETURN
    EVT_END
};

BSS unkPartnerStruct D_802BEC80;

unkPartnerStruct* D_802BEB60_31CB80 = &D_802BEC80;

ApiStatus func_802BD260_31B280(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Entity* entity;
    Npc* kooper = script->owner2.npc;
    f32 sp10, sp14, tempY;

    if (isInitialCall) {
        partner_walking_enable(kooper, 1);
        mem_clear(D_802BEB60_31CB80, sizeof(*D_802BEB60_31CB80));
        D_8010C954 = 0;
    }

    playerData->unk_2F4[2]++;
    entity = D_8010C954;

    if (entity == NULL) {
        partner_walking_update_player_tracking(kooper);
        partner_walking_update_motion(kooper);
        return ApiStatus_BLOCK;
    }

    switch (D_802BEB60_31CB80->unk_04) {
        case 0:
            D_802BEB60_31CB80->unk_04 = 1;
            D_802BEB60_31CB80->flags = kooper->flags;
            D_802BEB60_31CB80->unk_0C = fabsf(dist2D(kooper->pos.x, kooper->pos.z,
                                                     entity->position.x, entity->position.z));
            D_802BEB60_31CB80->unk_10 = atan2(entity->position.x, entity->position.z, kooper->pos.x, kooper->pos.z);
            D_802BEB60_31CB80->unk_14 = 6.0f;
            D_802BEB60_31CB80->unk_18 = 50.0f;
            D_802BEB60_31CB80->unk_00 = 120;
            kooper->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            kooper->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((D_802BEB60_31CB80->unk_10 * TAU) / 360.0f, &sp10, &sp14);

            kooper->pos.x = entity->position.x + (sp10 * D_802BEB60_31CB80->unk_0C);
            kooper->pos.z = entity->position.z - (sp14 * D_802BEB60_31CB80->unk_0C);

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
            kooper->pos.y += tempY;

            kooper->renderYaw = clamp_angle(360.0f - D_802BEB60_31CB80->unk_10);
            D_802BEB60_31CB80->unk_14 += 0.8;
            if (D_802BEB60_31CB80->unk_14 > 40.0f) {
                D_802BEB60_31CB80->unk_14 = 40.0f;
            }

            if (--D_802BEB60_31CB80->unk_00 == 0) {
                D_802BEB60_31CB80->unk_04++;
            }
            break;
        case 2:
            kooper->flags = D_802BEB60_31CB80->flags;
            D_802BEB60_31CB80->unk_00 = 30;
            D_802BEB60_31CB80->unk_04++;
            break;
        case 3:
            partner_walking_update_player_tracking(kooper);
            partner_walking_update_motion(kooper);

            if (--D_802BEB60_31CB80->unk_00 == 0) {
                D_802BEB60_31CB80->unk_04 = 0;
                D_8010C954 = 0;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtSource world_kooper_update = {
    EVT_CALL(func_802BD260_31B280)
    EVT_RETURN
    EVT_END
};

void func_802BD5F4_31B614(Npc* kooper) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        kooper->flags = D_802BEB60_31CB80->flags;
        D_802BEB60_31CB80->unk_04 = 0;
        partner_clear_player_tracking(kooper);
    }
}

ApiStatus func_802BD638_31B658(Evt*, s32);
#ifdef NON_MATCHING
ApiStatus func_802BD638_31B658(Evt* script, s32 isInitialCall) {
    Camera* cam;
    ItemEntity* itemGrabbed;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* kooper = script->owner2.npc;
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
    f32 temp2;

    if (currentEncounter->unk_08 == 0) {
        if (isInitialCall) {
            func_802BD5F4_31B614(kooper);
            if (playerStatus->animFlags & 0x100000) {
                return ApiStatus_DONE2;
            }

            if (D_802BEC54 == 0) {
                tempVar = playerStatus->actionState;
                if (tempVar == 0 || tempVar == 1 || tempVar == 2) {
                    script->functionTemp[0] = 20;
                } else {
                    return ApiStatus_DONE2;
                }

            }

            else if (partnerActionStatus->actionState.b[0] == 0) {
                partnerActionStatus->actionState.b[0] = 1;
                partnerActionStatus->actionState.b[3] = 2;
                script->functionTemp[0] = 5;
                kooper->currentAnim.w = 0x20009;
                D_802BEC50 = 30;
            }
        }

        switch (script->functionTemp[0]) {
            case 20:
                if (playerStatus->statusMenuCounterinputEnabledCounter == 0) {
                    if (playerStatus->decorationList == 0) {
                        if (kooper->flags & 0x1000) {
                            disable_player_input();
                            script->functionTemp[2] = playerStatus->statusMenuCounterinputEnabledCounter;
                            D_802BEC64 = 1;
                            D_802BEB40_31CB60 = 0;
                            D_802BEC6C = 0;
                            kooper->flags &= ~0xA08;
                            kooper->flags |= 0x140;
                            partnerActionStatus->actionState.b[3] = 2;
                            partnerActionStatus->actionState.b[0] = 1;
                            D_802BEC58 = func_800EF4E0();
                            enable_npc_blur(kooper);
                            kooper->duration = 4;
                            kooper->yaw = atan2(kooper->pos.x, kooper->pos.z,
                                                playerStatus->position.x, playerStatus->position.z);
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
                //TODO: make if statement less bad
                if ((((u8)playerStatus->actionState - 0x15) < 3U) || (playerStatus->decorationList != 0)) {
                    suggest_player_anim_clearUnkFlag(0x10002);
                    script->functionTemp[0] = 0;
                    break;
                } else {
                    suggest_player_anim_clearUnkFlag(0x10006);
                    kooper->moveToPos.x = D_802BEC70 = playerStatus->position.x;
                    kooper->moveToPos.y = D_802BEC74 = playerStatus->position.y;
                    kooper->moveToPos.z = D_802BEC78 = playerStatus->position.z;
                    kooper->currentAnim.w = 0x20005;
                    add_vec2D_polar(&kooper->moveToPos.x, &kooper->moveToPos.z,
                                    playerStatus->colliderDiameter / 3, playerStatus->targetYaw);
                    clamp = clamp_angle(playerStatus->targetYaw + ((D_802BEC58 != 0) ? 90.0f : -90.0f));
                    add_vec2D_polar(&kooper->moveToPos.x, &kooper->moveToPos.z,
                                    playerStatus->colliderDiameter / 4, clamp);
                    kooper->pos.x = (kooper->pos.x + ((kooper->moveToPos.x - kooper->pos.x) / kooper->duration));
                    kooper->pos.y = (kooper->pos.y + ((kooper->moveToPos.y - kooper->pos.y) / kooper->duration));
                    kooper->pos.z = (kooper->pos.z + ((kooper->moveToPos.z - kooper->pos.z) / kooper->duration));
                    kooper->duration -= 1;

                    if (kooper->duration << 0x10) {
                        break;
                    }
                    disable_npc_blur(kooper);
                    if (script->functionTemp[2] < playerStatus->statusMenuCounterinputEnabledCounter) {
                        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_100000)) {
                            suggest_player_anim_clearUnkFlag(0x10002);
                        } else {
                            suggest_player_anim_clearUnkFlag(0x10005);
                        }
                        script->functionTemp[0] = 0;
                        break;
                    } else {
                        kooper->yaw = playerStatus->targetYaw;
                        kooper->jumpVelocity = 18.0f;
                        kooper->jumpScale = 3.0f;
                        kooper->currentAnim.w = 0x2000A;
                        kooper->collisionHeight = 12;

                        kooper->moveToPos.y = playerStatus->position.y;
                        //npc->moveToPos.z = playerStatus->position.y + (playerStatus->colliderHeight / 3);
                        //maybe better than above line, maybe not
                        temp2 = playerStatus->colliderHeight / 3;
                        kooper->moveToPos.z = playerStatus->position.y + temp2;
                        playerStatus->flags |= PLAYER_STATUS_FLAGS_JUMPING;
                        gCameras->moveFlags |= CAMERA_FLAGS_1;

                        suggest_player_anim_clearUnkFlag(0x10007);
                        D_802BEC60 = 0;
                        sfx_play_sound_at_npc(0x2081, 0, -4);
                        script->functionTemp[0] = 2;
                    }
                }

            case 2:
                if ((u8)playerStatus->actionState == 0x15 ||
                    (u8)playerStatus->actionState == 0x16 ||
                    (u8)playerStatus->actionState == 0x17) {
                    script->functionTemp[0] = 0;
                } else {
                    kooper->jumpVelocity -= kooper->jumpScale;
                    playerStatus->position.y += kooper->jumpVelocity;
                    if (kooper->jumpVelocity < 0.0f) {
                        if (D_802BEC60 == 0) {
                            D_802BEC60 = 1;
                            suggest_player_anim_clearUnkFlag(0x10008);
                        }
                    }

                    sp20 = playerStatus->position.x;
                    sp2C = playerStatus->colliderHeight / 2;
                    temp2 = sp2C;
                    sp24 = (playerStatus->position.y + playerStatus->colliderHeight / 2) - kooper->jumpVelocity;
                    sp28 = playerStatus->position.z;

                    if ((npc_raycast_up(0x10000, &sp20, &sp24, &sp28, &sp2C) != 0) && (sp2C < temp2)) {
                        collisionStatus->currentCeiling = D_8010C97A;
                        playerStatus->position.y = sp24 - playerStatus->colliderHeight;
                        func_802BD144_31B164(kooper);
                    }

                    if (!(kooper->jumpVelocity > 0.0f) && (playerStatus->position.y < kooper->moveToPos.z)) {
                        D_802BEC5C = 0;
                        kooper->flags &= ~PLAYER_STATUS_ANIM_FLAGS_100000;
                        partnerActionStatus->actionState.b[3] = 2;
                        partnerActionStatus->actionState.b[0] = 2;
                        kooper->rotation.z = 0.0f;
                        kooper->planarFlyDist = 0.0f;
                        kooper->moveSpeed = 8.0f;
                        kooper->currentAnim.w = 0x20009;
                        D_802BEB40_31CB60 = 1;
                        temp_f20_2 = sin_deg(playerStatus->targetYaw);
                        playFX_18(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                                temp_f20_2, -1.0f, -cos_deg(playerStatus->targetYaw), 3);
                        start_bounce_b();

                        if (D_802BEC64 != 0) {
                            enable_player_input();
                            D_802BEC64 = 0;
                        }

                        script->functionTemp[0] = 3;
                        D_802BEC60 = 0;
                        gCameras->moveFlags |= CAMERA_FLAGS_1;
                        sfx_play_sound_at_npc(0x283, 0, -4);
                        sfx_play_sound_at_npc(0x284, 0, -4);
                    }
                }
                break;

            case 3:
                //TODO: make if statement less bad
                if (((u8)playerStatus->actionState - 0x15) > 1U) {
                    sp20 = kooper->pos.x;
                    sp24 = kooper->pos.y;
                    sp28 = kooper->pos.z;

                    if (npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, kooper->moveSpeed,
                                                           kooper->yaw - 20.0f, kooper->collisionHeight,
                                                           (kooper->collisionRadius / 2)) != 0) {
                        if (func_802BD100_31B120(kooper) == 0) {
                            sfx_play_sound_at_npc(0x10C, 0, -4);
                        }

                        temp_f20_3 = sin_deg(kooper->yaw);
                        playFX_18(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                                temp_f20_3, -1.0f, -cos_deg(kooper->yaw), 1);
                        sfx_play_sound_at_npc(0, 0, -4);
                        script->functionTemp[0] = 7;
                        break;
                    }

                    sp20 = kooper->pos.x;
                    sp24 = kooper->pos.y;
                    sp28 = kooper->pos.z;

                    if ((npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, kooper->moveSpeed,
                                                            kooper->yaw + 20.0f, kooper->collisionHeight,
                                                            kooper->collisionRadius / 2) == 0) &&
                                                            (sp20 = kooper->pos.x, sp24 = kooper->pos.y,
                                                            sp28 = kooper->pos.z,
                                                            (npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24,
                                                            &sp28, kooper->moveSpeed, kooper->yaw,
                                                            kooper->collisionHeight,
                                                            kooper->collisionRadius / 2)== 0))) {
                        kooper->pos.x = sp20;
                        kooper->pos.y = sp24;
                        kooper->pos.z = sp28;
                        kooper->planarFlyDist += kooper->moveSpeed;
                        func_8003D660(kooper, 1);
                        kooper->moveSpeed += 2.0;

                        if (kooper->moveSpeed > 14.0) {
                            kooper->moveSpeed = 14.0f;
                        }

                        if ((func_800397E8(kooper, 6.0f) == 0) && ((playerStatus->flags & 6) == 0)) {
                            kooper->pos.y = (kooper->pos.y + ((playerStatus->position.y - kooper->pos.y) / 10.0f));
                        }

                        npc_do_other_npc_collision(kooper);

                        if ((kooper->flags & 0x2000000) == 0) {
                            if (func_802BD17C_31B19C(kooper) != 0) {
                                sfx_play_sound_at_npc(0x286, 0, -4);
                                temp_f20_4 = sin_deg(kooper->yaw);
                                playFX_18(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                                          temp_f20_4, -1.0f, -cos_deg(kooper->yaw), 1);
                                sfx_play_sound_at_npc(0, 0, -4);
                                script->functionTemp[0] = 4;
                                D_802BEC50 = 8;
                                kooper->moveSpeed -= 4.0;
                                if (kooper->moveSpeed < 0.01) {
                                    kooper->moveSpeed = 0.01f;
                                    kooper->planarFlyDist += 1.0;
                                }
                            }
                            else if (D_802BEB40_31CB60 == 2) {
                                sfx_play_sound_at_npc(0, 0, -4);
                                script->functionTemp[0] = 5;
                                D_802BEC50 = 30;
                                kooper->moveSpeed = 0.0f;
                            } else {
                                if (kooper->planarFlyDist > 140.0f) {
                                    label2:
                                    script->functionTemp[0] = 7;
                                    kooper->moveSpeed = 0.0f;
                                    sfx_play_sound_at_npc(0, 0, -4);
                                }

                                else if (kooper->planarFlyDist > 105.0f) {
                                    kooper->moveSpeed -= 4.0;
                                    if (kooper->moveSpeed < 0.01) {
                                        kooper->moveSpeed = 0.01f;
                                        kooper->planarFlyDist += 1.0;
                                    }
                                }
                                break;
                            }
                        } else {
                            goto label2;
                        }
                    } else {
                        if (func_802BD100_31B120(kooper) == 0) {
                            sfx_play_sound_at_npc(0x10C, 0, -4);
                        }

                        temp_f20_3 = sin_deg(kooper->yaw);
                        playFX_18(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                                temp_f20_3, -1.0f, -cos_deg(kooper->yaw), 1);
                        sfx_play_sound_at_npc(0, 0, -4);
                        script->functionTemp[0] = 7;
                    }
                } else {
                    script->functionTemp[0] = 0;
                }
                break;
            case 4:
                sp20 = kooper->pos.x;
                sp24 = kooper->pos.y;
                sp28 = kooper->pos.z;

                npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, kooper->moveSpeed, kooper->yaw,
                                                   kooper->collisionHeight, ( kooper->collisionRadius / 2));
                kooper->pos.x = sp20;
                kooper->pos.y = sp24;
                kooper->pos.z = sp28;

                kooper->planarFlyDist += kooper->moveSpeed;
                func_8003D660(kooper, 1);
                kooper->moveSpeed -= 6.0;

                if (kooper->moveSpeed < 0.01) {
                    kooper->moveSpeed = 0.01f;
                    kooper->planarFlyDist += 1.0;
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
            kooper->flags |= NPC_FLAG_100;
            //TODO: make if statement less bad
            if (((u8)playerStatus->actionState - 0x15) < 2U) {
                script->functionTemp[0] = 0;
            } else {
                temp_f20_5 = atan2(D_802BEC70, D_802BEC78, kooper->pos.x, kooper->pos.z);
                kooper->yaw = temp_f20_5 + (get_clamped_angle_diff(kooper->yaw, temp_f20_5) * 0.125f);
                npc_move_heading(kooper, -kooper->moveSpeed, kooper->yaw);
                kooper->planarFlyDist -= kooper->moveSpeed;
                func_8003D660(kooper, 1);
                kooper->moveSpeed += 1.3333333333333333;

                if (kooper->moveSpeed > 14.0) {
                    kooper->moveSpeed = 14.0f;
                }

                if (func_800397E8(kooper, 6.0f) == 0) {
                    kooper->pos.y = (kooper->pos.y + ((playerStatus->position.y - kooper->pos.y) / 10.0f));
                }

                sp20 = kooper->pos.x;
                sp24 = kooper->pos.y;
                sp28 = kooper->pos.z;

                if (npc_test_move_taller_with_slipping(0x8000, &sp20, &sp24, &sp28, kooper->moveSpeed,
                                                       clamp_angle(kooper->yaw + 180.0f), kooper->collisionHeight,
                                                       kooper->collisionRadius) != 0) {
                    kooper->pos.x = sp20;
                    kooper->pos.y = sp24;
                    kooper->pos.z = sp28;
                    sfx_play_sound_at_npc(0x10C, 0, -4);
                    temp_f20_6 = sin_deg(kooper->yaw + 180.0f);
                    playFX_18(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                            temp_f20_6, -1.0f, -cos_deg(kooper->yaw + 180.0f), 1);
                    script->functionTemp[0] = 0;
                } else {
                    if (D_802BEC6C != 0) {
                        itemGrabbed = get_item_entity(D_802BEC68);
                        sp20 = kooper->pos.x;
                        sp24 = kooper->pos.y + 8.0f;
                        sp28 = kooper->pos.z;

                        clamp = clamp_angle(playerStatus->targetYaw - ((D_802BEC58) ? 90.0f : -90.0f));

                        add_vec2D_polar(&sp20, &sp28, 4.0f, clamp);
                        itemGrabbed->position.x = sp20;
                        itemGrabbed->position.y = sp24;
                        itemGrabbed->position.z = sp28;
                    }

                    if (kooper->planarFlyDist + 15.0f < kooper->moveSpeed) {
                        script->functionTemp[0] = 0;
                    } else if (kooper->planarFlyDist + 15.0f < 35.0f) {
                        kooper->moveSpeed -= 4.0;
                        if (kooper->moveSpeed < 4.0) {
                            kooper->moveSpeed = 4.0;
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
            kooper->flags |= NPC_FLAG_100;
            kooper->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
            kooper->flags &= ~NPC_FLAG_40;
            partnerActionStatus->actionState.b[3] = 0;
            partnerActionStatus->actionState.b[0] = 0;
            kooper->jumpVelocity = 0.0f;
            kooper->collisionHeight = 24;
            kooper->currentAnim.w = 0x20000 | 4;
            sfx_stop_sound(0x284);
            disable_npc_blur(kooper);

            if (D_802BEC6C != 0) {
                func_801341B0(D_802BEC68);
                D_802BEC6C = 0;
            }

            D_802BEC54 = 0;
            partner_clear_player_tracking(kooper);
            return ApiStatus_DONE2;
        }
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/partner/kooper", func_802BD638_31B658);
#endif

EvtSource world_kooper_use_ability = {
    EVT_CALL(func_802BD638_31B658)
    EVT_RETURN
    EVT_END
};

ApiStatus func_802BE7E0_31C800(Evt* script, s32 isInitialCall) {
    Npc* kooper = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(kooper);
    }

    return partner_put_away(kooper) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtSource world_kooper_put_away = {
    EVT_CALL(func_802BE7E0_31C800)
    EVT_RETURN
    EVT_END
};

#ifdef NON_EQUIVALENT
s32 world_kooper_test_first_strike(Npc* npcKooper, Npc* npc2) {
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

        if (npc_test_move_taller_with_slipping(0, &npcKooperXTemp, &npcKooperYTemp, &npcKooperZTemp, temp_f0, temp_f20,
                                               kooperCollisionHeight, kooperCollisionRadius + npcCollisionRadius) == 0) {
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
INCLUDE_ASM(s32, "world/partner/kooper", world_kooper_test_first_strike);
#endif

void world_kooper_pre_battle(Npc* kooper) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* kooperActionStatus = &gPartnerActionStatus;
    D_802BEC54 = 0;

    if (kooperActionStatus->actionState.b[0] != 0) {
        if (kooperActionStatus->actionState.b[0] == 2) {
            D_802BEC54 = 1;
        }

        if (D_802BEC64) {
            enable_player_input();
            D_802BEC64 = 0;
        }

        D_802BEB40_31CB60 = 0;
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_JUMPING;

        kooper->jumpVelocity = 0.0f;
        kooper->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        kooper->flags &= ~NPC_FLAG_40;

        sfx_stop_sound(0x284);
        set_action_state(0);
        partner_clear_player_tracking(kooper);
        disable_npc_blur(kooper);

        kooperActionStatus->actionState.b[3] = 0;
        kooperActionStatus->actionState.b[0] = 0;
    }
}

void world_kooper_post_battle(Npc* npc) {
    if (D_802BEC54) {
        partner_clear_player_tracking(npc);
        partner_use_ability();
    }
}
