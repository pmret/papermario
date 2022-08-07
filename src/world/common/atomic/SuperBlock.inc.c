#include "common.h"
#include "npc.h"
#include "effects.h"
#include "SuperBlock.inc.h"
#include "hud_element.h"

ApiStatus N(SuperBlock_SetOverride40)(Evt* script, s32 isInitialCall) {
    gOverrideFlags |= GLOBAL_OVERRIDES_40;
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_ClearOverride40)(Evt* script, s32 isInitialCall) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_HideBlockContent)(Evt* script, s32 isInitialCall) {
    entity_upgrade_block_hide_content(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_GetPartnerRank)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 partnerIdx = evt_get_variable(script, *args++);
    s32 evt_var = *args++;

    playerData->partners[partnerIdx].level++;
    evt_set_variable(script, evt_var, playerData->partners[partnerIdx].level);

    return ApiStatus_DONE2;
}

s32 N(SuperBlock_get_partner_rank)(s32 idx, s16 maxLevel) {
    if (!gPlayerData.partners[idx].enabled) {
        return -1;
    }

    if (gPlayerData.partners[idx].level <= maxLevel) {
        return gPlayerData.partners[idx].level;
    }

    return -1;
}

ApiStatus N(SuperBlock_CountEligiblePartners)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s16 var = script->varTable[12] >= 0;
    s32 i;

    script->varTable[0] = -1;

    for (i = 1; i < ARRAY_COUNT(playerData->partners); i++) {
        if (playerData->partners[i].enabled && N(SuperBlock_get_partner_rank)(i, var) != -1) {
            script->varTable[0] = 1;
            break;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_ShowSelectPartnerMenu)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PopupMenu* popupMenu;
    s32 partnerID;
    s32 canUpgradePartner;
    s32 hasUltraStone;
    s32 entryIndex;
    s32 i;

    // create the 'partner upgrade' popup menu
    if (isInitialCall) {
        popupMenu = heap_malloc(sizeof(PopupMenu));
        script->functionTempPtr[2] = popupMenu;
        hasUltraStone = script->varTable[12] >= 0;

        // build the popup menu entries from unlocked partners
        entryIndex = 0;
        for (i = 0; i < ARRAY_COUNT(N(SuperBlock_PartnerIDs)); i++) {
            partnerID = N(SuperBlock_PartnerIDs)[i];
            if (playerData->partners[partnerID].enabled) {
                popupMenu->userIndex[entryIndex] = partnerID;
                popupMenu->nameMsg[entryIndex] = gPartnerPopupProperties[partnerID][0];
                canUpgradePartner = N(SuperBlock_get_partner_rank)(partnerID, hasUltraStone);
                if (canUpgradePartner >= 0) {
                    popupMenu->ptrIcon[entryIndex] = wPartnerHudScripts[partnerID];
                    popupMenu->enabled[entryIndex] = TRUE;
                    popupMenu->descMsg[entryIndex] = N(SuperBlock_UpgradeDescMessages)[i][canUpgradePartner];
                } else {
                    popupMenu->ptrIcon[entryIndex] = wDisabledPartnerHudScripts[partnerID];
                    popupMenu->enabled[entryIndex] = FALSE;
                    popupMenu->descMsg[entryIndex] = N(SuperBlock_CantUpgradeMessages)[hasUltraStone];
                }
                popupMenu->value[entryIndex] = playerData->partners[partnerID].level;
                entryIndex++;
            }
        }

        popupMenu->popupType = POPUP_MENU_UPGRADE_PARTNER;
        popupMenu->numEntries = entryIndex;
        popupMenu->initialPos = 0;
        create_popup_menu(popupMenu);
        script->functionTemp[0] = 0;
    }

    // wait for player to close popup
    popupMenu = script->functionTempPtr[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = popupMenu->result;
        if (script->functionTemp[1] == 0) {
            return ApiStatus_BLOCK;
        }
        hide_popup_menu();
    }

    // wait for popup to hide
    script->functionTemp[0]++;
    if (script->functionTemp[0] < 15) {
        return ApiStatus_BLOCK;
    }
    destroy_popup_menu();

    if (script->functionTemp[1] != 255) {
        script->varTable[0] = gPartnerPopupProperties[popupMenu->userIndex[script->functionTemp[1] - 1]][0];
        script->varTable[1] = popupMenu->userIndex[script->functionTemp[1] - 1];
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTempPtr[2]);
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_SwitchToPartner)(Evt* script, s32 isInitialCall) {
    switch_to_partner(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_LoadCurrentPartnerName)(Evt* script, s32 isInitialCall) {
    set_message_msg(gPartnerPopupProperties[gPlayerData.currentPartner][0], 0);
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_StartGlowEffect)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIdx = evt_get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIdx);
    s32 effectPtrOutVar = *args++;
    EffectInstance* effectInst = fx_energy_orb_wave(0, entity->position.x, entity->position.y + 12.5f, entity->position.z, 0.7f, 0);

    evt_set_variable(script, effectPtrOutVar, (s32) effectInst);
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_EndGlowEffect)(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *script->ptrReadPos);

    effect->flags |= EFFECT_INSTANCE_FLAGS_10;
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_GatherEnergyFX)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(evt_get_variable(script, *script->ptrReadPos));

    fx_radial_shimmer(4, entity->position.x, entity->position.y + 12.5f, entity->position.z, 1.0f, 75);
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_RadiateFaintEnergyFX)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(NPC_PARTNER);

    fx_radial_shimmer(9, npc->pos.x, npc->pos.y + 12.5f, npc->pos.z, 1.0f, 30);
    return ApiStatus_DONE2;
}

typedef struct EnergyOrbSet {
    s32 scatterState;
    s32 gatherState;
    EffectInstance* orbEffects[SUPER_BLOCK_NUM_ORBS];
    f32 posX[SUPER_BLOCK_NUM_ORBS];
    f32 posY[SUPER_BLOCK_NUM_ORBS];
    f32 posZ[SUPER_BLOCK_NUM_ORBS];
    f32 partnerPosX[SUPER_BLOCK_NUM_ORBS];
    f32 partnerPosY[SUPER_BLOCK_NUM_ORBS];
    f32 partnerPosZ[SUPER_BLOCK_NUM_ORBS];
    Entity* superBlock;
    s32 scatterStateTime;
    s32 gatherStateTime;
} EnergyOrbSet;

ApiStatus N(SuperBlock_AnimateEnergyOrbs)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* partner = get_npc_safe(NPC_PARTNER);
    EnergyOrbSet* userData;
    f32 sinTheta, cosTheta;
    f32 x;
    f32 t1;
    s32 i;

    sin_cos_deg(gCameras[gCurrentCameraID].currentYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (EnergyOrbSet*)general_heap_malloc(sizeof(EnergyOrbSet));
        userData = (EnergyOrbSet*)script->userData;

        userData->superBlock = get_entity_by_index(evt_get_variable(script, *args++));

        for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
            userData->orbEffects[i] = (EffectInstance*)fx_motion_blur_flame(0, userData->superBlock->position.x,
                userData->superBlock->position.y + 12.5f, userData->superBlock->position.z, 1.0f, -1);
            t1 = 0.0f;
            userData->posZ[i] = t1;
            userData->posY[i] = t1;
            userData->posX[i] = t1;
            userData->partnerPosZ[i] = t1;
            userData->partnerPosY[i] = t1;
            userData->partnerPosX[i] = t1;
        }

        userData->scatterState = 0;
        userData->gatherState = 0;
        userData->scatterStateTime = 0;
        userData->gatherStateTime = 0;

        t1 = 50.0f;
        for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
            x = 0.0f;
            add_vec2D_polar(&x, &userData->partnerPosY[i], t1, N(SuperBlock_UpgradeOrbAngles)[i]);
            userData->partnerPosX[i] = cosTheta * x;
            userData->partnerPosZ[i] = sinTheta * x;
            userData->partnerPosX[i] = partner->pos.x - (userData->superBlock->position.x + userData->partnerPosX[i]);
            userData->partnerPosY[i] = partner->pos.y - (userData->superBlock->position.y + userData->partnerPosY[i]);
            userData->partnerPosZ[i] = partner->pos.z - (userData->superBlock->position.z + userData->partnerPosZ[i]);
        }
    }

    userData = (EnergyOrbSet*)script->userData;
    switch (userData->scatterState) {
        case 0:
            t1 = update_lerp(EASING_CUBIC_OUT, 0.0f, 50.0f, userData->scatterStateTime, 20);
            for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
                x = userData->posY[i] = 0.0f;
                add_vec2D_polar(&x, &userData->posY[i], t1, N(SuperBlock_UpgradeOrbAngles)[i]);
                userData->posX[i] = cosTheta * x;
                userData->posZ[i] = sinTheta * x;
            }

            userData->scatterStateTime++;
            if (userData->scatterStateTime >= 21) {
                userData->scatterState = 1;
                userData->scatterStateTime = 0;
            }
            break;
        case 1:
            t1 = 50.0f;
            for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
                x = userData->posY[i] = 0.0f;
                add_vec2D_polar(&x, &userData->posY[i], t1, N(SuperBlock_UpgradeOrbAngles)[i]);
                userData->posX[i] = cosTheta * x;
                userData->posZ[i] = sinTheta * x;
            }

            userData->scatterStateTime++;
            if (userData->scatterStateTime > 15) {
                userData->scatterStateTime = 15;
                userData->scatterState = 2;
            }
            break;
        case 2:
            userData->scatterStateTime++;
            if (userData->scatterStateTime > 30) {
                for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
                    userData->orbEffects[i]->flags |= EFFECT_INSTANCE_FLAGS_10;
                }
                return ApiStatus_DONE2;
            }
            break;
    }

    switch (userData->gatherState) {
        case 0:
            userData->gatherStateTime++;
            if (userData->gatherStateTime > 15) {
                userData->gatherState = 1;
                userData->gatherStateTime = 0;
            }
            break;
        case 1:
            for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
                userData->posX[i] += update_lerp(EASING_QUADRATIC_IN, 0.0f, userData->partnerPosX[i], userData->gatherStateTime, 20);
                userData->posY[i] += update_lerp(EASING_QUADRATIC_IN, 0.0f, userData->partnerPosY[i], userData->gatherStateTime, 20);
                userData->posZ[i] += update_lerp(EASING_QUADRATIC_IN, 0.0f, userData->partnerPosZ[i], userData->gatherStateTime, 20);
            }

            userData->gatherStateTime++;
            if (userData->gatherStateTime > 20) {
                userData->gatherState = 2;
                userData->gatherStateTime = 0;
            }
            break;
    }

    for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
        userData->orbEffects[i]->data.motionBlurFlame->position.x = userData->posX[i];
        userData->orbEffects[i]->data.motionBlurFlame->position.y = userData->posY[i];
        userData->orbEffects[i]->data.motionBlurFlame->position.z = userData->posZ[i];
    }

    return ApiStatus_BLOCK;
}

s32 N(SuperBlock_WhiteScreenFlash)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 ret = 0;

    if (isInitialCall) {
        script->varTable[0] = evt_get_variable(script, *args++);
        script->varTable[1] = evt_get_variable(script, *args++);
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
        set_screen_overlay_color(0, 208, 208, 208);
    }

    switch (script->functionTemp[0]) {
        case 0:
            if (script->functionTemp[1] == 255) {
                script->functionTemp[0] = 1;
                script->functionTemp[2] = 0;
            }
            script->functionTemp[1] += script->varTable[0];
            if (script->functionTemp[1] > 255) {
                script->functionTemp[1] = 255;
            }
            break;

        case 1:
            script->functionTemp[2]++;
            if (script->functionTemp[2] >= 2) {
                script->functionTemp[0] = 2;
            }
            break;

        case 2:
            if (script->functionTemp[1] == 0) {
                ret = 1;
            }
            script->functionTemp[1] -= script->varTable[1];
            if (script->functionTemp[1] < 0) {
                script->functionTemp[1] = 0;
            }
            break;
    }

    set_screen_overlay_params_front(1, script->functionTemp[1]);

    return ret;
}

ApiStatus N(SuperBlock_PartnerSparkles2)(Evt* script, s32 isInitialCall) {
    Npc* partner = get_npc_safe(NPC_PARTNER);
    fx_sparkles(2, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_PartnerSparkles4)(Evt* script, s32 isInitialCall) {
    Npc* partner = get_npc_safe(NPC_PARTNER);
    fx_sparkles(4, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_WaitForPlayerToLand)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;
    if ((gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) && (gPartnerActionStatus.actingPartner == PARTNER_BOMBETTE)) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

