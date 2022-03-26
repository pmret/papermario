#include "common.h"
#include "effects.h"
#include "../src/world/partners.h"
#include "npc.h"

void force_player_anim(s32 arg0);
void func_802BE070_31DBE0(void);
void partner_kill_ability_script(void);

typedef struct unk_802BE310_C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ char unk_2C[0x0C];
} unk_802BE310_C; // size = 0x38

typedef struct unk_802BE310 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ unk_802BE310_C* unk_0C;
} unk_802BE310; //size = 0x10

BSS s32 D_802BE300;
BSS s32 D_802BE304;
BSS s32 D_802BE308;
BSS s32 D_802BE30C;
BSS unk_802BE310* D_802BE310;
BSS s32 D_802BE314;
BSS TweesterPhysics WattTweesterPhysics;

s32 D_802BE250_31DDC0 = 0x18;

s32 D_802BE254_31DDC4 = 6;

void func_802BD100_31CC70(Npc* npc) {
    if (!(npc->flags & NPC_FLAG_2)) {
        if (D_802BE310 == NULL) {
            D_802BE310 = (unk_802BE310*)fx_static_status(0, npc->pos.x, npc->pos.y + 13.0f, npc->pos.z, 0.9f, 5, 0);
        }
    }
}

s32 func_802BD180_31CCF0(void) {
    if (D_802BE310 != NULL) {
        D_802BE310->unk_0C->unk_28 = 1;
        D_802BE310 = NULL;
        return 1;
    }
}

void func_802BD1AC_31CD1C(s32 arg0);
INCLUDE_ASM(s32, "world/partner/watt", func_802BD1AC_31CD1C);

void world_watt_init(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 24;
    D_802BE308 = 0;
    D_802BE300 = 0;
    D_802BE30C = 0;
    D_802BE304 = 20;
    D_802BE310 = NULL;
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
    
    if (gPartnerActionStatus.actionState.b[1] == 0) {
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
                    watt->currentAnim.w = 0x60003;
                }
            } else if (D_802BE278_31DDE8 != 0) {
                D_802BE278_31DDE8 = 0;
                func_802BD1AC_31CD1C(0);
                watt->currentAnim.w = 0x60001;
            }

            if (D_802BE310 != NULL) {
                D_802BE310->unk_0C->unk_04 = watt->pos.x;
                D_802BE310->unk_0C->unk_08 = watt->pos.y + 13.0f;
                D_802BE310->unk_0C->unk_0C = watt->pos.z;
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
                sin_cos_rad((WattTweesterPhysicsPtr->angle * TAU) / 360.0f, &sinAngle, &cosAngle);
                watt->pos.x = (entity->position.x + (sinAngle * WattTweesterPhysicsPtr->radius));
                watt->pos.z = (entity->position.z - (cosAngle * WattTweesterPhysicsPtr->radius));
                WattTweesterPhysicsPtr->angle = clamp_angle(WattTweesterPhysicsPtr->angle - WattTweesterPhysicsPtr->angularVelocity);

                if (WattTweesterPhysicsPtr->radius > 20.0f) {
                    WattTweesterPhysicsPtr->radius--;
                } else if (WattTweesterPhysicsPtr->radius < 19.0f) {
                    WattTweesterPhysicsPtr->radius++;
                }

                liftoffVelocity = sin_rad(WattTweesterPhysicsPtr->liftoffVelocityPhase * TAU / 360.0f) * 3.0f;
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

        if (D_802BE310 != 0) {
            D_802BE310->unk_0C->unk_04 = watt->pos.x;
            D_802BE310->unk_0C->unk_08 = watt->pos.y + 13.0f;
            D_802BE310->unk_0C->unk_0C = watt->pos.z;
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

s32 func_802BD754_31D2C4(void);
INCLUDE_ASM(s32, "world/partner/watt", func_802BD754_31D2C4);

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
        func_802BD180_31CCF0();
        partner_init_put_away(watt);
        force_player_anim(0x10002);
        wattActionStatus->actionState.b[3] = 0;
        wattActionStatus->actionState.b[0] = 0;
        playerStatus->animFlags &= ~(PLAYER_STATUS_ANIM_FLAGS_2 | PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT);
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
        wattActionStatus->actionState.b[1] = 1;
        partner_clear_player_tracking(watt);
    }

    func_802BD180_31CCF0();
}

void world_watt_post_battle(Npc* watt) {
    PartnerActionStatus* wattActionStatus = &gPartnerActionStatus;

    if (wattActionStatus->actionState.b[1]) {
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
                func_802BD180_31CCF0();
            } else {
                func_802BD100_31CC70(watt);
            }

            script->functionTemp[1] = script->varTable[4];
            playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z,
                                            script->varTable[1], script->varTable[3]);
            playerStatus->heading = playerStatus->targetYaw;
            move_player(script->functionTemp[1], playerStatus->heading, *((f32*) &script->varTable[5]));
            func_802BE070_31DBE0();
            watt->flags &= ~NPC_FLAG_GRAVITY;
            watt->flags |= NPC_FLAG_100;
            playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_2 | PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT;
            gGameStatusPtr->keepUsingPartnerOnMapChange = 1;
            wattActionStatus->actionState.b[0] = 1;
            wattActionStatus->actionState.b[3] = 6;
            D_802BE308 = 0;
            script->functionTemp[0] += 1;
            break;
        case 1:
            func_802BE070_31DBE0();
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
    s32 animationID;

    if (playerStatus->runSpeed <= currentSpeed) {
        animationID = 0x60002;
    } else if (playerStatus->walkSpeed <= currentSpeed) {
        animationID = 0x60000;
    } else {
        animationID = 0x60007;
    }
    suggest_player_anim_clearUnkFlag(animationID);
}

void func_802BE070_31DBE0(void) {
    Npc* partnerNPC;
    Npc* new_var2;
    Camera* camera = gCameras;
    PlayerStatus* playerStatus;
    f32 temp, angle;
    f32 spriteFacingAngle;
    s32 phi_v1;
    
    if (gPartnerActionStatus.actionState.b[0] != 0) {
        spriteFacingAngle = gPlayerStatusPtr->spriteFacingAngle;
        if ((spriteFacingAngle < 90.0f) || (spriteFacingAngle > 270.0f)) {
            if (!(gPlayerStatusPtr->trueAnimation & NPC_FLAG_1000000)) {
                phi_v1 = -5;
                temp = 0.6f;
            } else {
                phi_v1 = 5;
                temp = 0.6f;
            }
        } else {
            if (!(gPlayerStatusPtr->trueAnimation & NPC_FLAG_1000000)) {
                phi_v1 = 5;
                temp = 0.6f;
            } else {
                phi_v1 = -5;
                temp = 0.6f;
            }
        }

        angle = (camera->currentYaw + 270.0f - gPlayerStatusPtr->spriteFacingAngle + phi_v1) * TAU / 360.0f;

        playerStatus = gPlayerStatusPtr;
        partnerNPC = wPartnerNpc;
        partnerNPC->pos.x = playerStatus->position.x + (sin_rad(angle) * gPlayerStatusPtr->colliderDiameter * temp);

        new_var2 = wPartnerNpc;
        playerStatus = gPlayerStatusPtr;
        partnerNPC = new_var2;
        partnerNPC->pos.z = playerStatus->position.z - (cos_rad(angle) * gPlayerStatusPtr->colliderDiameter * temp);
        
        wPartnerNpc->yaw = gPlayerStatusPtr->targetYaw;
        wPartnerNpc->pos.y = gPlayerStatusPtr->position.y + 5.0f;
    }
}

EvtScript world_watt_while_riding = {
    EVT_CALL(func_802BDE88_31D9F8)
    EVT_RETURN
    EVT_END
};
