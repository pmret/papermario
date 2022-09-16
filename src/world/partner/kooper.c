#include "common.h"
#include "../src/world/partners.h"

extern s16 D_8010C97A;

s32 entity_interacts_with_current_partner(s32);
s32 test_item_entity_position(f32, f32, f32, f32);
s32 npc_raycast_up_corner(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);
s32 npc_raycast_up(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);
void fx_damage_stars(s32, f32, f32, f32, f32, f32, f32, s32);
void func_801341B0(s32);

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

    if (!(D_8010C978 & COLLISION_WITH_ENTITY_BIT)) {
        return 0;
    }

    return entity_interacts_with_current_partner(D_8010C978 & ~COLLISION_WITH_ENTITY_BIT);
}

void func_802BD144_31B164(Npc* kooper) {
    if (D_8010C978 >= 0 && D_8010C978 & COLLISION_WITH_ENTITY_BIT) {
        entity_interacts_with_current_partner(D_8010C978 & ~COLLISION_WITH_ENTITY_BIT);
    }
}

s32 func_802BD17C_31B19C(Npc* kooper) {
    D_802BEC68 = test_item_entity_position(kooper->pos.x, kooper->pos.y, kooper->pos.z, kooper->collisionRadius);

    if (D_802BEC68 < 0) {
        return 0;
    } else {
        D_802BEC6C = 1;
        gOverrideFlags |= GLOBAL_OVERRIDES_40;
        set_item_entity_flags(D_802BEC68, ITEM_ENTITY_FLAGS_200000);
        return 1;
    }
}

void world_kooper_init(Npc* kooper) {
    kooper->collisionHeight = 37;
    kooper->collisionRadius = 24;
    kooper->collisionChannel = 0x00010000;
    D_802BEC54 = 0;
}

ApiStatus KooperTakeOut(Evt* script, s32 isInitialCall) {
    Npc* kooper = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(kooper);
    }

    return partner_get_out(kooper) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_kooper_take_out = {
    EVT_CALL(KooperTakeOut)
    EVT_RETURN
    EVT_END
};

BSS TweesterPhysics KooperTweesterPhysics;

TweesterPhysics* KooperTweesterPhysicsPtr = &KooperTweesterPhysics;

ApiStatus KooperUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* kooper = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(kooper, 1);
        mem_clear(KooperTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_KOOPER]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(kooper);
        partner_walking_update_motion(kooper);
        return ApiStatus_BLOCK;
    }

    switch (KooperTweesterPhysicsPtr->state) {
        case 0:
            KooperTweesterPhysicsPtr->state = 1;
            KooperTweesterPhysicsPtr->prevFlags = kooper->flags;
            KooperTweesterPhysicsPtr->radius = fabsf(dist2D(kooper->pos.x, kooper->pos.z,
                                                     entity->position.x, entity->position.z));
            KooperTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, kooper->pos.x, kooper->pos.z);
            KooperTweesterPhysicsPtr->angularVelocity = 6.0f;
            KooperTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            KooperTweesterPhysicsPtr->countdown = 120;
            kooper->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            kooper->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(KooperTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);

            kooper->pos.x = entity->position.x + (sinAngle * KooperTweesterPhysicsPtr->radius);
            kooper->pos.z = entity->position.z - (cosAngle * KooperTweesterPhysicsPtr->radius);

            KooperTweesterPhysicsPtr->angle = clamp_angle(KooperTweesterPhysicsPtr->angle - KooperTweesterPhysicsPtr->angularVelocity);
            if (KooperTweesterPhysicsPtr->radius > 20.0f) {
                KooperTweesterPhysicsPtr->radius--;
            } else if (KooperTweesterPhysicsPtr->radius < 19.0f) {
                KooperTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(KooperTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;

            KooperTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (KooperTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                KooperTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }
            kooper->pos.y += liftoffVelocity;

            kooper->renderYaw = clamp_angle(360.0f - KooperTweesterPhysicsPtr->angle);
            KooperTweesterPhysicsPtr->angularVelocity += 0.8;
            if (KooperTweesterPhysicsPtr->angularVelocity > 40.0f) {
                KooperTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--KooperTweesterPhysicsPtr->countdown == 0) {
                KooperTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            kooper->flags = KooperTweesterPhysicsPtr->prevFlags;
            KooperTweesterPhysicsPtr->countdown = 30;
            KooperTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(kooper);
            partner_walking_update_motion(kooper);

            if (--KooperTweesterPhysicsPtr->countdown == 0) {
                KooperTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_kooper_update = {
    EVT_CALL(KooperUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BD5F4_31B614(Npc* kooper) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        kooper->flags = KooperTweesterPhysicsPtr->prevFlags;
        KooperTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(kooper);
    }
}

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
    f32 temp_f20_3;
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
                if (tempVar == ACTION_STATE_IDLE || tempVar == ACTION_STATE_WALK || tempVar == ACTION_STATE_RUN) {
                    script->functionTemp[0] = 20;
                } else {
                    return ApiStatus_DONE2;
                }
            } else if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE) {
                partnerActionStatus->partnerActionState = PARTNER_ACTION_KOOPER_1;
                partnerActionStatus->actingPartner = PARTNER_KOOPER;
                script->functionTemp[0] = 5;
                kooper->currentAnim = 0x20009;
                D_802BEC50 = 30;
            }
        }

        switch (script->functionTemp[0]) {
            case 20:
                if (playerStatus->inputEnabledCounter == 0) {
                    if (playerStatus->timeInAir == 0) {
                        if (kooper->flags & 0x1000) {
                            disable_player_input();
                            script->functionTemp[2] = playerStatus->inputEnabledCounter;
                            D_802BEC64 = 1;
                            D_802BEB40_31CB60 = 0;
                            D_802BEC6C = 0;
                            kooper->flags &= ~0xA08;
                            kooper->flags |= 0x140;
                            partnerActionStatus->actingPartner = PARTNER_KOOPER;
                            partnerActionStatus->partnerActionState = PARTNER_ACTION_KOOPER_1;
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
                if ((((u8)playerStatus->actionState - 0x15) < 3U) || (playerStatus->timeInAir != 0)) {
                    suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                    script->functionTemp[0] = 0;
                    break;
                } else {
                    suggest_player_anim_clearUnkFlag(ANIM_Mario_BeforeJump);
                    kooper->moveToPos.x = D_802BEC70 = playerStatus->position.x;
                    kooper->moveToPos.y = D_802BEC74 = playerStatus->position.y;
                    kooper->moveToPos.z = D_802BEC78 = playerStatus->position.z;
                    kooper->currentAnim = 0x20005;
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
                    if (script->functionTemp[2] < playerStatus->inputEnabledCounter) {
                        if (!(playerStatus->animFlags & PA_FLAGS_100000)) {
                            suggest_player_anim_clearUnkFlag(ANIM_Mario_10002);
                        } else {
                            suggest_player_anim_clearUnkFlag(ANIM_Mario_Running);
                        }
                        script->functionTemp[0] = 0;
                        break;
                    } else {
                        kooper->yaw = playerStatus->targetYaw;
                        kooper->jumpVelocity = 18.0f;
                        kooper->jumpScale = 3.0f;
                        kooper->currentAnim = 0x2000A;
                        kooper->collisionHeight = 12;

                        kooper->moveToPos.y = playerStatus->position.y;
                        kooper->moveToPos.z = playerStatus->position.y + playerStatus->colliderHeight / 3;
                        playerStatus->flags |= PS_FLAGS_JUMPING;
                        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_FLAGS_1;

                        suggest_player_anim_clearUnkFlag(ANIM_Mario_AnimMidairStill);
                        D_802BEC60 = 0;
                        sfx_play_sound_at_npc(SOUND_JUMP_2081, 0, -4);
                        script->functionTemp[0] = 2;
                    }
                }

            case 2:
                if ((u8)playerStatus->actionState == ACTION_STATE_HIT_FIRE ||
                    (u8)playerStatus->actionState == ACTION_STATE_KNOCKBACK ||
                    (u8)playerStatus->actionState == ACTION_STATE_HIT_LAVA) {
                    script->functionTemp[0] = 0;
                } else {
                    kooper->jumpVelocity -= kooper->jumpScale;
                    playerStatus->position.y += kooper->jumpVelocity;
                    if (kooper->jumpVelocity < 0.0f) {
                        if (D_802BEC60 == 0) {
                            D_802BEC60 = 1;
                            suggest_player_anim_clearUnkFlag(ANIM_Mario_AnimMidair);
                        }
                    }

                    sp20 = playerStatus->position.x;
                    sp24 = (playerStatus->position.y + playerStatus->colliderHeight / 2) - kooper->jumpVelocity;
                    sp28 = playerStatus->position.z;
                    sp2C = playerStatus->colliderHeight / 2;
                    temp_f20_3 = sp2C;

                    if ((npc_raycast_up(0x10000, &sp20, &sp24, &sp28, &sp2C) != 0) && (sp2C < temp_f20_3)) {
                        collisionStatus->currentCeiling = D_8010C97A;
                        playerStatus->position.y = sp24 - playerStatus->colliderHeight;
                        func_802BD144_31B164(kooper);
                    }

                    if (!(kooper->jumpVelocity > 0.0f) && (playerStatus->position.y < kooper->moveToPos.z)) {
                        D_802BEC5C = 0;
                        kooper->flags &= ~ACTOR_FLAG_100;
                        partnerActionStatus->actingPartner = PARTNER_KOOPER;
                        partnerActionStatus->partnerActionState = PARTNER_ACTION_KOOPER_2;
                        kooper->rotation.z = 0.0f;
                        kooper->planarFlyDist = 0.0f;
                        kooper->moveSpeed = 8.0f;
                        kooper->currentAnim = 0x20009;
                        D_802BEB40_31CB60 = 1;
                        fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                                sin_deg(playerStatus->targetYaw), -1.0f, -cos_deg(playerStatus->targetYaw), 3);
                        start_bounce_b();

                        if (D_802BEC64 != 0) {
                            enable_player_input();
                            D_802BEC64 = 0;
                        }

                        script->functionTemp[0] = 3;
                        D_802BEC60 = 0;
                        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_FLAGS_1;
                        sfx_play_sound_at_npc(SOUND_283, 0, -4);
                        sfx_play_sound_at_npc(SOUND_284, 0, -4);
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
                            sfx_play_sound_at_npc(SOUND_IMMUNE, 0, -4);
                        }

                        temp_f20_3 = sin_deg(kooper->yaw);
                        fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
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
                                sfx_play_sound_at_npc(SOUND_286, 0, -4);
                                temp_f20_3 = sin_deg(kooper->yaw);
                                fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                                          temp_f20_3, -1.0f, -cos_deg(kooper->yaw), 1);
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
                            sfx_play_sound_at_npc(SOUND_IMMUNE, 0, -4);
                        }

                        temp_f20_3 = sin_deg(kooper->yaw);
                        fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
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
                temp2 = atan2(D_802BEC70, D_802BEC78, kooper->pos.x, kooper->pos.z);
                kooper->yaw = temp2 + (get_clamped_angle_diff(kooper->yaw, temp2) * 0.125f);
                npc_move_heading(kooper, -kooper->moveSpeed, kooper->yaw);
                kooper->planarFlyDist -= kooper->moveSpeed;
                func_8003D660(kooper, 1);
                kooper->moveSpeed += 4.0/3.0;

                if (kooper->moveSpeed > 14.0) {
                    kooper->moveSpeed = 14.0f;
                }

                if (func_800397E8(kooper, 6.0f) == 0) {
                    kooper->pos.y += (playerStatus->position.y - kooper->pos.y) / 10.0f;
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
                    sfx_play_sound_at_npc(SOUND_IMMUNE, 0, -4);
                    temp_f20_3 = sin_deg(kooper->yaw + 180.0f);
                    fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                            temp_f20_3, -1.0f, -cos_deg(kooper->yaw + 180.0f), 1);
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
            kooper->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_40);
            partnerActionStatus->actingPartner = PARTNER_NONE;
            partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
            kooper->jumpVelocity = 0.0f;
            kooper->collisionHeight = 24;
            kooper->currentAnim = 0x20000 | 4;
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

EvtScript world_kooper_use_ability = {
    EVT_CALL(func_802BD638_31B658)
    EVT_RETURN
    EVT_END
};

ApiStatus KooperPutAway(Evt* script, s32 isInitialCall) {
    Npc* kooper = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(kooper);
    }

    return partner_put_away(kooper) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_kooper_put_away = {
    EVT_CALL(KooperPutAway)
    EVT_RETURN
    EVT_END
};

s32 world_kooper_test_first_strike(Npc* kooper, Npc* enemy) {
    f32 xTemp, yTemp, zTemp;
    f32 enemyX, enemyY, enemyZ;
    f32 kooperX;
    f32 kooperZ;
    f32 enemyCollHeight;
    f32 kooperY;
    f32 kooperCollHeight;
    f32 enemyCollRadius;
    f32 kooperCollRadius;
    f32 arctan;
    f32 dist;

    if (D_802BEB40_31CB60 != 0) {
        enemyX = enemy->pos.x;
        enemyY = enemy->pos.y;
        enemyZ = enemy->pos.z;

        kooperX = kooper->pos.x;
        kooperY = kooper->pos.y;
        kooperZ = kooper->pos.z;

        enemyCollHeight = enemy->collisionHeight;
        enemyCollRadius = enemy->collisionRadius * 0.55;

        kooperCollHeight = kooper->collisionHeight;
        kooperCollRadius = kooper->collisionRadius * 0.8;

        arctan = atan2(enemyX, enemyZ, kooperX, kooperZ);
        dist = dist2D(enemyX, enemyZ, kooperX, kooperZ);

        xTemp = kooper->pos.x;
        yTemp = kooper->pos.y;
        zTemp = kooper->pos.z;

        if (npc_test_move_taller_with_slipping(0, &xTemp, &yTemp, &zTemp, dist, arctan, kooperCollHeight,
                                                 kooperCollRadius + enemyCollRadius))
        {
            return FALSE;
        }

        if (kooperY > enemyY + enemyCollHeight) {
            return FALSE;
        }

        if (enemyY > kooperY + kooperCollHeight) {
            return FALSE;
        }

        kooperX = enemyX - kooperX;
        kooperZ = enemyZ - kooperZ;
        dist = SQ(kooperX) + SQ(kooperZ);

        if (!(SQ(kooperCollRadius) + SQ(enemyCollRadius) <= dist)) {
            D_802BEB40_31CB60 = 2;
            return TRUE;
        }
    }
    return FALSE;
}

void world_kooper_pre_battle(Npc* kooper) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* kooperActionStatus = &gPartnerActionStatus;
    D_802BEC54 = 0;

    if (kooperActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
        if (kooperActionStatus->partnerActionState == PARTNER_ACTION_KOOPER_2) {
            D_802BEC54 = 1;
        }

        if (D_802BEC64) {
            enable_player_input();
            D_802BEC64 = 0;
        }

        D_802BEB40_31CB60 = 0;
        playerStatus->flags &= ~PS_FLAGS_JUMPING;

        kooper->jumpVelocity = 0.0f;
        kooper->flags &= ~NPC_FLAG_JUMPING;
        kooper->flags &= ~NPC_FLAG_40;

        sfx_stop_sound(0x284);
        set_action_state(0);
        partner_clear_player_tracking(kooper);
        disable_npc_blur(kooper);

        kooperActionStatus->actingPartner = PARTNER_NONE;
        kooperActionStatus->partnerActionState = PARTNER_ACTION_NONE;
    }
}

void world_kooper_post_battle(Npc* npc) {
    if (D_802BEC54) {
        partner_clear_player_tracking(npc);
        partner_use_ability();
    }
}
