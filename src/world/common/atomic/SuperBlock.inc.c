#include "common.h"
#include "npc.h"
#include "effects.h"

extern s32 gPartnerPopupProperties[11][4];

extern s32 N(SuperBlock_CantUpgradeMessages)[2];
extern s16 N(SuperBlock_PartnerIDs)[8];
extern s32 N(SuperBlock_UpgradeDescMessages)[8][2];
extern f32 N(SuperBlock_UpgradeOrbAngles)[3];

extern s32 wPartnerHudScripts[];
extern s32 wDisabledPartnerHudScripts[];

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

ApiStatus N(SwitchToPartner)(Evt* script, s32 isInitialCall) {
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

typedef struct {
    s32 unk_00;
    s32 unk_04;
    EffectGraphics* unk_08[3]; // TODO this is wrong
    f32 unk_14[3];
    f32 unk_20[3];
    f32 unk_2C[3];
    f32 unk_38[3];
    f32 unk_44[3];
    f32 unk_50[3];
    Entity* unk_5C;
    s32 unk_60;
    s32 unk_64;
} N(UserData);

ApiStatus N(SuperBlock_AnimateEnergyOrbs)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* partner = get_npc_safe(NPC_PARTNER);
    N(UserData)* userData;
    f32 sinTheta, cosTheta;
    f32 x;
    f32 t1;
    s32 i;

    sin_cos_deg(gCameras[gCurrentCameraID].currentYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (N(UserData)*)general_heap_malloc(0x68);
        userData = (N(UserData)*)script->userData;

        userData->unk_5C = get_entity_by_index(evt_get_variable(script, *args++));

        for (i = 0; i < ARRAY_COUNT(userData->unk_08); i++) {
            userData->unk_08[i] = (EffectGraphics*) fx_motion_blur_flame(0, userData->unk_5C->position.x,
                                                          userData->unk_5C->position.y + 12.5f,
                                                          userData->unk_5C->position.z, 1.0f, -1);
            t1 = 0.0f;
            userData->unk_2C[i] = t1;
            userData->unk_20[i] = t1;
            userData->unk_14[i] = t1;
            userData->unk_50[i] = t1;
            userData->unk_44[i] = t1;
            userData->unk_38[i] = t1;
        }

        userData->unk_00 = 0;
        userData->unk_04 = 0;
        userData->unk_60 = 0;
        userData->unk_64 = 0;

        t1 = 50.0f;
        for (i = 0; i < ARRAY_COUNT(userData->unk_38); i++) {
            x = 0.0f;
            add_vec2D_polar(&x, &userData->unk_44[i], t1, N(SuperBlock_UpgradeOrbAngles)[i]);
            userData->unk_38[i] = cosTheta * x;
            userData->unk_50[i] = sinTheta * x;
            userData->unk_38[i] = partner->pos.x - (userData->unk_5C->position.x + userData->unk_38[i]);
            userData->unk_44[i] = partner->pos.y - (userData->unk_5C->position.y + userData->unk_44[i]);
            userData->unk_50[i] = partner->pos.z - (userData->unk_5C->position.z + userData->unk_50[i]);
        }
    }

    userData = (N(UserData)*)script->userData;
    switch (userData->unk_00) {
        case 0:
            t1 = update_lerp(5, 0.0f, 50.0f, userData->unk_60, 20);
            for (i = 0; i < ARRAY_COUNT(userData->unk_20); i++) {
                x = userData->unk_20[i] = 0.0f;
                add_vec2D_polar(&x, &userData->unk_20[i], t1, N(SuperBlock_UpgradeOrbAngles)[i]);
                userData->unk_14[i] = cosTheta * x;
                userData->unk_2C[i] = sinTheta * x;
            }

            userData->unk_60++;
            if (userData->unk_60 >= 21) {
                userData->unk_00 = 1;
                userData->unk_60 = 0;
            }
            break;
        case 1:
            t1 = 50.0f;
            for (i = 0; i < ARRAY_COUNT(userData->unk_20); i++) {
                x = userData->unk_20[i] = 0.0f;
                add_vec2D_polar(&x, &userData->unk_20[i], t1, N(SuperBlock_UpgradeOrbAngles)[i]);
                userData->unk_14[i] = cosTheta * x;
                userData->unk_2C[i] = sinTheta * x;
            }

            userData->unk_60++;
            if (userData->unk_60 > 15) {
                userData->unk_60 = 15;
                userData->unk_00 = 2;
            }
            break;
        case 2:
            userData->unk_60++;
            if (userData->unk_60 > 30) {
                for (i = 0; i < ARRAY_COUNT(userData->unk_08); i++) {
                    userData->unk_08[i]->flags |= 0x10;
                }
                return ApiStatus_DONE2;
            }
            break;
    }

    switch (userData->unk_04) {
        case 0:
            userData->unk_64++;
            if (userData->unk_64 > 15) {
                userData->unk_04 = 1;
                userData->unk_64 = 0;
            }
            break;
        case 1:
            for (i = 0; i < ARRAY_COUNT(userData->unk_14); i++) {
                userData->unk_14[i] += update_lerp(1, 0.0f, userData->unk_38[i], userData->unk_64, 20);
                userData->unk_20[i] += update_lerp(1, 0.0f, userData->unk_44[i], userData->unk_64, 20);
                userData->unk_2C[i] += update_lerp(1, 0.0f, userData->unk_50[i], userData->unk_64, 20);
            }

            userData->unk_64++;
            if (userData->unk_64 > 20) {
                userData->unk_04 = 2;
                userData->unk_64 = 0;
            }
            break;
    }

    for (i = 0; i < ARRAY_COUNT(userData->unk_08); i++) {
        ((EffectInstanceData*)userData->unk_08[i]->freeDelay)->rotation.x = userData->unk_14[i];
        ((EffectInstanceData*)userData->unk_08[i]->freeDelay)->rotation.y = userData->unk_20[i];
        ((EffectInstanceData*)userData->unk_08[i]->freeDelay)->rotation.z = userData->unk_2C[i];
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
    if ((gPartnerActionStatus.actionState.b[0] != 0) && (gPartnerActionStatus.actionState.b[3]  == 3)) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

