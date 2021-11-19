#include "common.h"
#include "effects.h"
#include "../src/world/partners.h"
#include "npc.h"

void force_player_anim(s32 arg0);
void func_802BE070_31DBE0(void);
void partner_kill_ability_script(void);
s32 partner_use_ability(void);
void func_802BD1AC_31CD1C(s32 arg0);
extern s32 D_802BE278_31DDE8;
extern f64 D_802BE2F0_31DE60;
extern s32 D_802BE250_31DDC0;

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

typedef struct unk_802BE274_31DDE4 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} unk_802BE274_31DDE4; //size = 0x1C

extern s32 D_802BE300;
extern s32 D_802BE304;
extern s32 D_802BE308;
extern s32 D_802BE30C;
extern unk_802BE310* D_802BE310;
extern unk_802BE274_31DDE4* D_802BE274_31DDE4;

void func_802BD100_31CC70(Npc* npc) {
    if (!(npc->flags & 2)) {
        if (D_802BE310 == NULL) {
            D_802BE310 = (unk_802BE310*)playFX_73(0, npc->pos.x, npc->pos.y + 13.0f, npc->pos.z, 0.9f, 5, 0);
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

INCLUDE_ASM(s32, "world/partner/watt", func_802BD1AC_31CD1C);

void func_802BD23C_31CDAC(Npc* npc) {
    npc->collisionHeight = 24;
    npc->collisionRadius = 24;
    D_802BE308 = 0;
    D_802BE300 = 0;
    D_802BE30C = 0;
    D_802BE304 = 20;
    D_802BE310 = NULL;
}

ApiStatus func_802BD27C_31CDEC(Evt* script, s32 isInitialCall) {
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(npc);
    }

    if (partner_get_out(npc) != 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus func_802BD2B4_31CE24(Evt *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Entity* entity;
    f32 sp10, sp14;
    f32 new_var;
    f32 temp_f0;
    Npc* npc = script->owner2.npc;
    
    if (gPartnerActionStatus.actionState.b[1] == 0) {
        if (isInitialCall) {
            partner_flying_enable(npc, 1);
            mem_clear(D_802BE274_31DDE4, sizeof(unk_802BE274_31DDE4));
            D_8010C954 = NULL;
        }

        entity = D_8010C954;
        playerData->unk_2F4[6]++;

        if (entity == NULL) {
            func_802BD100_31CC70(npc);
            partner_flying_update_player_tracking(npc);
            partner_flying_update_motion(npc);
            if (npc->moveSpeed != 0.0f) {
                if (D_802BE278_31DDE8 == 0) {
                    D_802BE278_31DDE8 = 1;
                    func_802BD1AC_31CD1C(1);
                    npc->currentAnim.w = 0x60003;
                }
            } else if (D_802BE278_31DDE8 != 0) {
                D_802BE278_31DDE8 = 0;
                func_802BD1AC_31CD1C(0);
                npc->currentAnim.w = 0x60001;
            }

            if (D_802BE310 != 0) {
                D_802BE310->unk_0C->unk_04 = npc->pos.x;
                D_802BE310->unk_0C->unk_08 = npc->pos.y + 13.0f;
                D_802BE310->unk_0C->unk_0C = npc->pos.z;
            }

            return 0;
        }
        
        switch (D_802BE274_31DDE4->unk_04) {
            case 0:
                D_802BE274_31DDE4->unk_04 = 1;
                D_802BE274_31DDE4->unk_08 = npc->flags;
                D_802BE274_31DDE4->unk_0C = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
                D_802BE274_31DDE4->unk_10 = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
                D_802BE274_31DDE4->unk_14 = 6.0f;
                D_802BE274_31DDE4->unk_18 = 50.0f;
                D_802BE274_31DDE4->unk_00 = 0x78;
                npc->flags |= 0x40148;
                npc->flags &= ~0x200;
            case 1:
                sin_cos_rad((D_802BE274_31DDE4->unk_10 * TAU) / 360.0f, &sp10, &sp14);
                npc->pos.x = (entity->position.x + (sp10 * D_802BE274_31DDE4->unk_0C));
                npc->pos.z = (entity->position.z - (sp14 * D_802BE274_31DDE4->unk_0C));
                D_802BE274_31DDE4->unk_10 = clamp_angle(D_802BE274_31DDE4->unk_10 - D_802BE274_31DDE4->unk_14);

                if (D_802BE274_31DDE4->unk_0C > 20.0f) {
                    D_802BE274_31DDE4->unk_0C--;
                } else if (D_802BE274_31DDE4->unk_0C < 19.0f) {
                    D_802BE274_31DDE4->unk_0C++;
                }

                temp_f0 = sin_rad((D_802BE274_31DDE4->unk_18 * TAU) / 360.0f);
                D_802BE274_31DDE4->unk_18 += 3.0f;

                new_var = temp_f0 * 3.0f;

                if (D_802BE274_31DDE4->unk_18 > 150.0f) {
                    D_802BE274_31DDE4->unk_18 = 150.0f;
                }
                
                npc->pos.y += new_var;
                npc->renderYaw = clamp_angle(360.0f - D_802BE274_31DDE4->unk_10);
                D_802BE274_31DDE4->unk_14 += D_802BE2F0_31DE60;

                if (D_802BE274_31DDE4->unk_14 > 40.0f) {
                    D_802BE274_31DDE4->unk_14 = 40.0f;
                }

                if (--D_802BE274_31DDE4->unk_00 == 0) {
                    D_802BE274_31DDE4->unk_04++;
                }
                break;
            case 2:
                npc->flags = D_802BE274_31DDE4->unk_08;
                D_802BE274_31DDE4->unk_00 = 0x1E;
                D_802BE274_31DDE4->unk_04++;
                break;
            case 3:
                partner_flying_update_player_tracking(npc);
                partner_flying_update_motion(npc);
                if (--D_802BE274_31DDE4->unk_00 == 0) {
                    D_802BE274_31DDE4->unk_04 = 0;
                    D_8010C954 = NULL;
                }
                break;
        }

        if (D_802BE310 != 0) {
            D_802BE310->unk_0C->unk_04 = npc->pos.x;
            D_802BE310->unk_0C->unk_08 = npc->pos.y + 13.0f;
            D_802BE310->unk_0C->unk_0C = npc->pos.z;
        }
    }
    return 0;
}

void func_802BD710_31D280(Npc* npc) {
    if (D_8010C954 != NULL) {
        D_8010C954 = NULL;
        npc->flags = D_802BE274_31DDE4->unk_08;
        D_802BE274_31DDE4->unk_04 = 0;
        partner_clear_player_tracking(npc);
    }
}

INCLUDE_ASM(s32, "world/partner/watt", func_802BD754_31D2C4);

s32 func_802BDD0C_31D87C(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    Npc* npc = script->owner2.npc;

    if (isInitialCall) {
        func_802BD180_31CCF0();
        partner_init_put_away(npc);
        force_player_anim(0x10002);
        partnerActionStatus->actionState.b[3] = 0;
        partnerActionStatus->actionState.b[0] = 0;
        playerStatus->animFlags = playerStatus->animFlags & ~3;
        gGameStatusPtr->unk_7D = 0;
    }

    if (partner_put_away(npc) != 0) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

void func_802BDD9C_31D90C(Npc* npc) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (D_802BE30C != 0) {
        partnerActionStatus->npc = *npc;
        partnerActionStatus->actionState.b[1] = 1;
        partner_clear_player_tracking(npc);
    }

    func_802BD180_31CCF0();
}

void func_802BDE10_31D980(Npc* npc) {
    if (gPartnerActionStatus.actionState.b[1]) {
        *npc = gPartnerActionStatus.npc;
        partner_use_ability();
        func_802BD100_31CC70(npc);
    }
}

ApiStatus func_802BDE88_31D9F8(Evt* script, s32 isInitialCall) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(NPC_PARTNER);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            if (script->varTable[12] == 0) {
                partner_kill_ability_script();
                func_802BD180_31CCF0();
            } else {
                func_802BD100_31CC70(npc);
            }

            script->functionTemp[1] = script->varTable[4];
            playerStatus->targetYaw = atan2(playerStatus->position.x, playerStatus->position.z, script->varTable[1], script->varTable[3]);
            playerStatus->heading = playerStatus->targetYaw;
            move_player(script->functionTemp[1], playerStatus->heading, *((f32*) &script->varTable[5]));
            func_802BE070_31DBE0();
            npc->flags &= ~0x200;
            npc->flags |= 0x100;
            playerStatus->animFlags |= 3;
            gGameStatusPtr->unk_7D = 1;
            partnerActionStatus->actionState.b[0] = 1;
            partnerActionStatus->actionState.b[3] = 6;
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
    f32 temp;
    f32 temp_f20;
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

        temp_f20 = ((((camera->currentYaw + 270.0f) - gPlayerStatusPtr->spriteFacingAngle) + phi_v1) * TAU) / 360.0f;

        playerStatus = gPlayerStatusPtr;
        partnerNPC = wPartnerNpc;
        partnerNPC->pos.x = playerStatus->position.x + ((sin_rad(temp_f20) * gPlayerStatusPtr->colliderDiameter) * temp);

        new_var2 = wPartnerNpc;
        playerStatus = gPlayerStatusPtr;
        partnerNPC = new_var2;
        partnerNPC->pos.z = playerStatus->position.z - ((cos_rad(temp_f20) * gPlayerStatusPtr->colliderDiameter) * temp);
        
        wPartnerNpc->yaw = gPlayerStatusPtr->targetYaw;
        wPartnerNpc->pos.y = gPlayerStatusPtr->position.y + 5.0f;
    }
}
