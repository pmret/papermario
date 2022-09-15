#include "common.h"
#include "effects.h"
#include "../src/world/partners.h"
#include "npc.h"

void force_player_anim(AnimID);
void func_802BE014_31DB84(void);

s32 D_802BE250_31DDC0[] = {24, 6};

BSS s32 D_802BE300;
BSS s32 D_802BE304;
BSS s32 D_802BE308;
BSS s32 D_802BE30C;
BSS EffectInstance* WattStaticEffect;
BSS s32 D_802BE314;
BSS TweesterPhysics WattTweesterPhysics;

void func_802BD100_31CC70(Npc* npc) {
    if (!(npc->flags & NPC_FLAG_2)) {
        if (WattStaticEffect == NULL) {
            WattStaticEffect = fx_static_status(0, npc->pos.x, npc->pos.y + 13.0f, npc->pos.z, 0.9f, 5, 0);
        }
    }
}

s32 world_watt_dispose_static_effect(void) {
    if (WattStaticEffect != NULL) {
        WattStaticEffect->data.staticStatus->unk_28 = 1;
        WattStaticEffect = NULL;
        return 1;
    }
}

void func_802BD1AC_31CD1C(s32 arg0) {
    EffectInstance* effect = WattStaticEffect;
    StaticStatusFXData* data = effect->data.staticStatus;
    f32 tmp;
    s32 parts;
    s32 i;

    data->unk_00 = arg0;
    tmp = D_802BE250_31DDC0[arg0] * 0.5f;
    parts = effect->numParts - 1;

    data++;
    for (i = 1; i < parts; i++, data++) {
        data->unk_20 = -1.0f - (tmp * (i & 1));
    }
}

void world_watt_init(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 24;
    D_802BE308 = 0;
    D_802BE300 = 0;
    D_802BE30C = 0;
    D_802BE304 = 20;
    WattStaticEffect = NULL;
}

ApiStatus func_802BD27C_31CDEC(Evt* script, s32 isInitialCall) {
    Npc* watt = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(watt);
    }

    if (partner_get_out(watt)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript world_watt_take_out = {
    EVT_CALL(func_802BD27C_31CDEC)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* WattTweesterPhysicsPtr = &WattTweesterPhysics;

s32 D_802BE278_31DDE8 = 0;

ApiStatus WattUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* watt = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (gPartnerActionStatus.partnerAction_unk_1 == 0) {
        if (isInitialCall) {
            partner_flying_enable(watt, 1);
            mem_clear(WattTweesterPhysicsPtr, sizeof(TweesterPhysics));
            TweesterTouchingPartner = NULL;
        }

        entity = TweesterTouchingPartner;
        playerData->partnerUsedTime[PARTNER_WATT]++;

        if (entity == NULL) {
            func_802BD100_31CC70(watt);
            partner_flying_update_player_tracking(watt);
            partner_flying_update_motion(watt);
            if (watt->moveSpeed != 0.0f) {
                if (D_802BE278_31DDE8 == 0) {
                    D_802BE278_31DDE8 = 1;
                    func_802BD1AC_31CD1C(1);
                    watt->currentAnim = 0x60003;
                }
            } else if (D_802BE278_31DDE8 != 0) {
                D_802BE278_31DDE8 = 0;
                func_802BD1AC_31CD1C(0);
                watt->currentAnim = 0x60001;
            }

            if (WattStaticEffect != NULL) {
                WattStaticEffect->data.staticStatus->unk_04 = watt->pos.x;
                WattStaticEffect->data.staticStatus->unk_08 = watt->pos.y + 13.0f;
                WattStaticEffect->data.staticStatus->unk_0C = watt->pos.z;
            }

            return 0;
        }

        switch (WattTweesterPhysicsPtr->state) {
            case 0:
                WattTweesterPhysicsPtr->state = 1;
                WattTweesterPhysicsPtr->prevFlags = watt->flags;
                WattTweesterPhysicsPtr->radius = fabsf(dist2D(watt->pos.x, watt->pos.z,
                                                         entity->position.x, entity->position.z));
                WattTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, watt->pos.x, watt->pos.z);
                WattTweesterPhysicsPtr->angularVelocity = 6.0f;
                WattTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
                WattTweesterPhysicsPtr->countdown = 120;
                watt->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
                watt->flags &= ~NPC_FLAG_GRAVITY;
            case 1:
                sin_cos_rad(DEG_TO_RAD(WattTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
                watt->pos.x = (entity->position.x + (sinAngle * WattTweesterPhysicsPtr->radius));
                watt->pos.z = (entity->position.z - (cosAngle * WattTweesterPhysicsPtr->radius));
                WattTweesterPhysicsPtr->angle = clamp_angle(WattTweesterPhysicsPtr->angle - WattTweesterPhysicsPtr->angularVelocity);

                if (WattTweesterPhysicsPtr->radius > 20.0f) {
                    WattTweesterPhysicsPtr->radius--;
                } else if (WattTweesterPhysicsPtr->radius < 19.0f) {
                    WattTweesterPhysicsPtr->radius++;
                }

                liftoffVelocity = sin_rad(DEG_TO_RAD(WattTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
                WattTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

                if (WattTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                    WattTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
                }

                watt->pos.y += liftoffVelocity;
                watt->renderYaw = clamp_angle(360.0f - WattTweesterPhysicsPtr->angle);
                WattTweesterPhysicsPtr->angularVelocity += 0.8;

                if (WattTweesterPhysicsPtr->angularVelocity > 40.0f) {
                    WattTweesterPhysicsPtr->angularVelocity = 40.0f;
                }

                if (--WattTweesterPhysicsPtr->countdown == 0) {
                    WattTweesterPhysicsPtr->state++;
                }
                break;
            case 2:
                watt->flags = WattTweesterPhysicsPtr->prevFlags;
                WattTweesterPhysicsPtr->countdown = 30;
                WattTweesterPhysicsPtr->state++;
                break;
            case 3:
                partner_flying_update_player_tracking(watt);
                partner_flying_update_motion(watt);
                if (--WattTweesterPhysicsPtr->countdown == 0) {
                    WattTweesterPhysicsPtr->state = 0;
                    TweesterTouchingPartner = NULL;
                }
                break;
        }

        if (WattStaticEffect != 0) {
            WattStaticEffect->data.staticStatus->unk_04 = watt->pos.x;
            WattStaticEffect->data.staticStatus->unk_08 = watt->pos.y + 13.0f;
            WattStaticEffect->data.staticStatus->unk_0C = watt->pos.z;
        }
    }
    return 0;
}

EvtScript world_watt_update = {
    EVT_CALL(WattUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BD710_31D280(Npc* watt) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        watt->flags = WattTweesterPhysicsPtr->prevFlags;
        WattTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(watt);
    }
}

ApiStatus func_802BD754_31D2C4(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        func_802BD710_31D280(npc);
        if (!(playerStatus->animFlags & PA_FLAGS_100000)) {
            if (partnerActionStatus->partnerAction_unk_1 == 0) {
                if ((partnerActionStatus->partnerActionState != ACTION_STATE_IDLE) ||
                    (func_800EA52C(6) && !is_starting_conversation()))
                {
                    if (gGameStatusPtr->keepUsingPartnerOnMapChange) {
                        if (playerStatus->animFlags & (PA_FLAGS_HOLDING_WATT | PA_FLAGS_2)) {
                            D_802BE304 = 20;
                        } else {
                            D_802BE304 = 40;
                        }
                    } else if (playerStatus->animFlags & PA_FLAGS_HOLDING_WATT) {
                        D_802BE304 = 2;
                    } else {
                        D_802BE304 = 40;
                    }
                } else {
                    return ApiStatus_DONE2;
                }
            } else {
                partnerActionStatus->partnerAction_unk_1 = 0;
                playerStatus->animFlags |= (PA_FLAGS_HOLDING_WATT | PA_FLAGS_2);
                func_802BE014_31DB84();
                npc->currentAnim = 0x60001;
                D_802BE304 = 1;
                script->functionTemp[1] = 2;
            }
        } else {
            return ApiStatus_DONE2;
        }
    }

    switch (D_802BE304) {
        case 40:
            if (playerStatus->inputEnabledCounter != 0) {
                return ApiStatus_DONE2;
            }
            script->functionTemp[1] = 3;
            D_802BE304 = 41;
            script->functionTemp[2] = playerStatus->inputEnabledCounter;
            break;
        case 41:
            if (script->functionTemp[1] == 0) {
                if (script->functionTemp[2] >= playerStatus->inputEnabledCounter) {
                    if (!(playerStatus->animFlags & PA_FLAGS_100000)) {
                        if (func_800EA52C(6)) {
                            if (!is_starting_conversation()) {
                                D_802BE304 = 20;
                                break;
                            }
                        }
                    }
                }
                return ApiStatus_DONE2;
            }
            script->functionTemp[1]--;
            break;
    }

    switch (D_802BE304) {
        case 20:
            if (gGameStatusPtr->keepUsingPartnerOnMapChange) {
                playerStatus->animFlags |= PA_FLAGS_HOLDING_WATT;
                D_802BE30C = 1;
                npc->flags |= NPC_FLAG_100 | NPC_FLAG_ENABLE_HIT_SCRIPT;
                npc->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
                gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_USE;
                partnerActionStatus->actingPartner = PARTNER_WATT;
                npc->moveToPos.x = playerStatus->position.x;
                npc->moveToPos.y = playerStatus->position.y + 5.0f;
                npc->moveToPos.z = playerStatus->position.z;
                npc->currentAnim = 0x60002;
                add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, 15.0f, playerStatus->targetYaw);
                npc->yaw = playerStatus->targetYaw;
                npc->currentAnim = 0x60001;
                playerStatus->animFlags |= PA_FLAGS_2;
                func_802BE014_31DB84();
                npc_set_palswap_mode_A(npc, 1);
                script->functionTemp[1] = 2;
                D_802BE304 = 1;
            } else {
                playerStatus->animFlags |= PA_FLAGS_HOLDING_WATT;
                D_802BE30C = 1;
                npc->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_GRAVITY);
                gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
                partnerActionStatus->partnerActionState = PARTNER_ACTION_USE;
                partnerActionStatus->actingPartner = PARTNER_WATT;
                func_800EF4E0();
                npc->moveToPos.x = playerStatus->position.x;
                npc->moveToPos.y = playerStatus->position.y + 5.0f;
                npc->moveToPos.z = playerStatus->position.z;
                npc->currentAnim = 0x60002;
                add_vec2D_polar(&npc->moveToPos.x, &npc->moveToPos.z, 15.0f, playerStatus->targetYaw);
                npc->duration = 8;
                npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                D_802BE304++;
            }
            break;
        case 21:
            npc->pos.x += (npc->moveToPos.x - npc->pos.x) / npc->duration;
            npc->pos.y += (npc->moveToPos.y - npc->pos.y) / npc->duration;
            npc->pos.z += (npc->moveToPos.z - npc->pos.z) / npc->duration;
            npc->duration--;
            if (npc->duration == 0) {
                npc->yaw = playerStatus->targetYaw;
                npc->currentAnim = 0x60001;
                partnerActionStatus->actingPartner = PARTNER_WATT;
                playerStatus->animFlags |= PA_FLAGS_2;
                func_802BE014_31DB84();
                script->functionTemp[1] = 2;
                D_802BE304 = 1;
            }
            break;
        case 1:
            world_watt_sync_held_position();
            if ((playerStatus->flags & PS_FLAGS_800)) {
                D_802BE304 = 2;
            } else {
                s32 actionState = playerStatus->actionState;

                if (actionState != ACTION_STATE_USE_SPINNING_FLOWER) {
                    if (script->functionTemp[1] != 0) {
                        script->functionTemp[1]--;
                    } else if (
                        actionState == ACTION_STATE_IDLE ||
                        actionState == ACTION_STATE_WALK ||
                        actionState == ACTION_STATE_RUN ||
                        actionState == ACTION_STATE_LAND)
                    {
                        if (partnerActionStatus->pressedButtons & B_BUTTON) {
                            D_802BE304 = 2;
                        }
                    }
                }
            }
            break;
    }

    if (D_802BE304 == 2) {
        playerStatus->animFlags &= ~(PA_FLAGS_2 | PA_FLAGS_HOLDING_WATT);
        npc->currentAnim = 0x60001;
        partner_clear_player_tracking(npc);
        D_802BE30C = 0;
        partnerActionStatus->actingPartner = PARTNER_NONE;
        partnerActionStatus->partnerActionState = PARTNER_ACTION_NONE;
        gGameStatusPtr->keepUsingPartnerOnMapChange = FALSE;
        D_802BE304 = 20;
        npc_set_palswap_mode_A(npc, 0);
        if (!(playerStatus->flags & 0x800)) {
            set_action_state(0);
        }
        return ApiStatus_DONE1;
    }

    if (WattStaticEffect != NULL) {
        WattStaticEffect->data.staticStatus->unk_04 = npc->pos.x;
        WattStaticEffect->data.staticStatus->unk_08 = npc->pos.y + 13.0f;
        WattStaticEffect->data.staticStatus->unk_0C = npc->pos.z;
    }

    return ApiStatus_BLOCK;
}

EvtScript world_watt_use_ability = {
    EVT_CALL(func_802BD754_31D2C4)
    EVT_RETURN
    EVT_END
};

s32 WattPutAway(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* wattActionStatus = &gPartnerActionStatus;
    Npc* watt = script->owner2.npc;

    if (isInitialCall) {
        world_watt_dispose_static_effect();
        partner_init_put_away(watt);
        force_player_anim(ANIM_Mario_10002);
        wattActionStatus->actingPartner = PARTNER_NONE;
        wattActionStatus->partnerActionState = PARTNER_ACTION_NONE;
        playerStatus->animFlags &= ~(PA_FLAGS_2 | PA_FLAGS_HOLDING_WATT);
        gGameStatusPtr->keepUsingPartnerOnMapChange = 0;
    }

    if (partner_put_away(watt)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript world_watt_put_away = {
    EVT_CALL(WattPutAway)
    EVT_RETURN
    EVT_END
};

void world_watt_pre_battle(Npc* watt) {
    PartnerActionStatus* wattActionStatus = &gPartnerActionStatus;

    if (D_802BE30C != 0) {
        wattActionStatus->npc = *watt;
        wattActionStatus->partnerAction_unk_1 = 1;
        partner_clear_player_tracking(watt);
    }

    world_watt_dispose_static_effect();
}

void world_watt_post_battle(Npc* watt) {
    PartnerActionStatus* wattActionStatus = &gPartnerActionStatus;

    if (wattActionStatus->partnerAction_unk_1) {
        *watt = wattActionStatus->npc;
        partner_use_ability();
        func_802BD100_31CC70(watt);
    }
}

ApiStatus func_802BDE88_31D9F8(Evt* script, s32 isInitialCall) {
    PartnerActionStatus* wattActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* watt = get_npc_unsafe(NPC_PARTNER);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            if (script->varTable[12] == 0) {
                partner_kill_ability_script();
                world_watt_dispose_static_effect();
            } else {
                func_802BD100_31CC70(watt);
            }

            script->functionTemp[1] = script->varTable[4];
            playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z,
                                            script->varTable[1], script->varTable[3]);
            playerStatus->heading = playerStatus->targetYaw;
            move_player(script->functionTemp[1], playerStatus->heading, script->varTableF[5]);
            world_watt_sync_held_position();
            watt->flags &= ~NPC_FLAG_GRAVITY;
            watt->flags |= NPC_FLAG_100;
            playerStatus->animFlags |= (PA_FLAGS_2 | PA_FLAGS_HOLDING_WATT);
            gGameStatusPtr->keepUsingPartnerOnMapChange = 1;
            wattActionStatus->partnerActionState = PARTNER_ACTION_WATT_SHINE;
            wattActionStatus->actingPartner = PARTNER_WATT;
            D_802BE308 = 0;
            script->functionTemp[0] += 1;
            break;
        case 1:
            world_watt_sync_held_position();
            script->functionTemp[1]--;
            if (script->functionTemp[1] == 0) {
                if (script->varTable[12]) {
                    partner_use_ability();
                }
                return ApiStatus_DONE2;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

void func_802BE014_31DB84(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 currentSpeed = playerStatus->currentSpeed;
    AnimID anim;

    if (playerStatus->runSpeed <= currentSpeed) {
        anim = ANIM_Mario_60002;
    } else if (playerStatus->walkSpeed <= currentSpeed) {
        anim = ANIM_Mario_60000;
    } else {
        anim = ANIM_Mario_60007;
    }
    suggest_player_anim_clearUnkFlag(anim);
}

void world_watt_sync_held_position(void) {
    Npc* partnerNPC;
    Npc* new_var2;
    Camera* camera = gCameras;
    PlayerStatus* playerStatus;
    f32 offsetScale, angle;
    f32 spriteFacingAngle;
    s32 angleOffset;

    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) {
        spriteFacingAngle = gPlayerStatusPtr->spriteFacingAngle;
        if ((spriteFacingAngle < 90.0f) || (spriteFacingAngle > 270.0f)) {
            if (!(gPlayerStatusPtr->trueAnimation & NPC_FLAG_1000000)) {
                angleOffset = -5;
                offsetScale = 0.6f;
            } else {
                angleOffset = 5;
                offsetScale = 0.6f;
            }
        } else {
            if (!(gPlayerStatusPtr->trueAnimation & NPC_FLAG_1000000)) {
                angleOffset = 5;
                offsetScale = 0.6f;
            } else {
                angleOffset = -5;
                offsetScale = 0.6f;
            }
        }

        angle = DEG_TO_RAD(camera->currentYaw + 270.0f - gPlayerStatusPtr->spriteFacingAngle + angleOffset);

        playerStatus = gPlayerStatusPtr;
        partnerNPC = wPartnerNpc;
        partnerNPC->pos.x = playerStatus->position.x + (sin_rad(angle) * gPlayerStatusPtr->colliderDiameter * offsetScale);

        new_var2 = wPartnerNpc;
        playerStatus = gPlayerStatusPtr;
        partnerNPC = new_var2;
        partnerNPC->pos.z = playerStatus->position.z - (cos_rad(angle) * gPlayerStatusPtr->colliderDiameter * offsetScale);

        wPartnerNpc->yaw = gPlayerStatusPtr->targetYaw;
        wPartnerNpc->pos.y = gPlayerStatusPtr->position.y + 5.0f;
    }
}

EvtScript world_watt_while_riding = {
    EVT_CALL(func_802BDE88_31D9F8)
    EVT_RETURN
    EVT_END
};
