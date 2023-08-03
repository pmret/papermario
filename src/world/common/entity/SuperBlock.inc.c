#include "common.h"
#include "npc.h"
#include "effects.h"
#include "hud_element.h"

// ----------------------------------------------------------------
// Requirements

// GameFlag for super block availability
#ifndef SUPER_BLOCK_GAMEFLAG
    #error SUPER_BLOCK_GAMEFLAG is not defined!
#endif

// MapVar for super block entity ID
#ifndef SUPER_BLOCK_MAPVAR
    #error SUPER_BLOCK_MAPVAR  is not defined!
#endif

// ----------------------------------------------------------------
// User macros

// use this in an EvtScript calling MakeEntity for this super block
// expects SUPER_BLOCK_GAMEFLAG and SUPER_BLOCK_MAPVAR to be valid
#define EVT_MAKE_SUPER_BLOCK(x, y, z, angle) \
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), x, y, z, angle, MAKE_ENTITY_END)\
    EVT_SET(SUPER_BLOCK_MAPVAR, LVar0)\
    EVT_CALL(AssignBlockFlag, SUPER_BLOCK_GAMEFLAG)\
    EVT_CALL(AssignScript, EVT_PTR(N(SuperBlock_OnHit)))

// ----------------------------------------------------------------
// Implementation

#define SUPER_BLOCK_NUM_ORBS 3

s32 N(SuperBlock_CantUpgradeMessages)[2] = {
    MSG_Menus_00F0, MSG_Menus_00F1
};

s16 N(SuperBlock_PartnerIDs)[8] = {
    PARTNER_GOOMBARIO,
    PARTNER_KOOPER,
    PARTNER_BOMBETTE,
    PARTNER_PARAKARRY,
    PARTNER_BOW,
    PARTNER_WATT,
    PARTNER_SUSHIE,
    PARTNER_LAKILESTER
};

s32 N(SuperBlock_UpgradeDescMessages)[8][2] = {
    { MSG_Menus_00E0, MSG_Menus_00E1 },
    { MSG_Menus_00E2, MSG_Menus_00E3 },
    { MSG_Menus_00E4, MSG_Menus_00E5 },
    { MSG_Menus_00E6, MSG_Menus_00E7 },
    { MSG_Menus_00E8, MSG_Menus_00E9 },
    { MSG_Menus_00EA, MSG_Menus_00EB },
    { MSG_Menus_00EC, MSG_Menus_00ED },
    { MSG_Menus_00EE, MSG_Menus_00EF }
};

f32 N(SuperBlock_UpgradeOrbAngles)[SUPER_BLOCK_NUM_ORBS] = {
    140.0f, 180.0f, 220.0f
};

API_CALLABLE(N(SuperBlock_SetOverride40)) {
    gOverrideFlags |= GLOBAL_OVERRIDES_40;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_ClearOverride40)) {
    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_HideBlockContent)) {
    entity_upgrade_block_hide_content(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_GetPartnerRank)) {
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

API_CALLABLE(N(SuperBlock_CountEligiblePartners)) {
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

API_CALLABLE(N(SuperBlock_ShowSelectPartnerMenu)) {
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
                popupMenu->nameMsg[entryIndex] = gPartnerPopupProperties[partnerID].nameMsg;
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
        create_standard_popup_menu(popupMenu);
        script->functionTemp[0] = 0;
    }

    // wait for player to close popup
    popupMenu = script->functionTempPtr[2];
    if (script->functionTemp[0] == 0) {
        script->functionTemp[1] = popupMenu->result;
        if (script->functionTemp[1] == POPUP_RESULT_CHOOSING) {
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

    if (script->functionTemp[1] != POPUP_RESULT_CANCEL) {
        script->varTable[0] = gPartnerPopupProperties[popupMenu->userIndex[script->functionTemp[1] - 1]].nameMsg;
        script->varTable[1] = popupMenu->userIndex[script->functionTemp[1] - 1];
    } else {
        script->varTable[0] = -1;
    }

    heap_free(script->functionTempPtr[2]);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_SwitchToPartner)) {
    switch_to_partner(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_LoadCurrentPartnerName)) {
    set_message_msg(gPartnerPopupProperties[gPlayerData.curPartner].nameMsg, 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_StartGlowEffect)) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIdx = evt_get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIdx);
    s32 effectPtrOutVar = *args++;
    EffectInstance* effectInst = fx_energy_orb_wave(0, entity->pos.x, entity->pos.y + 12.5f, entity->pos.z, 0.7f, 0);

    evt_set_variable(script, effectPtrOutVar, (s32) effectInst);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_EndGlowEffect)) {
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *script->ptrReadPos);

    effect->flags |= FX_INSTANCE_FLAG_DISMISS;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_GatherEnergyFX)) {
    Entity* entity = get_entity_by_index(evt_get_variable(script, *script->ptrReadPos));

    fx_radial_shimmer(4, entity->pos.x, entity->pos.y + 12.5f, entity->pos.z, 1.0f, 75);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_RadiateFaintEnergyFX)) {
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

API_CALLABLE(N(SuperBlock_AnimateEnergyOrbs)) {
    Bytecode* args = script->ptrReadPos;
    Npc* partner = get_npc_safe(NPC_PARTNER);
    EnergyOrbSet* userData;
    f32 sinTheta, cosTheta;
    f32 x;
    f32 t1;
    s32 i;

    sin_cos_deg(gCameras[gCurrentCameraID].curYaw, &sinTheta, &cosTheta);

    if (isInitialCall) {
        script->userData = (EnergyOrbSet*)general_heap_malloc(sizeof(EnergyOrbSet));
        userData = (EnergyOrbSet*)script->userData;

        userData->superBlock = get_entity_by_index(evt_get_variable(script, *args++));

        for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
            userData->orbEffects[i] = (EffectInstance*)fx_motion_blur_flame(0, userData->superBlock->pos.x,
                userData->superBlock->pos.y + 12.5f, userData->superBlock->pos.z, 1.0f, -1);
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
            userData->partnerPosX[i] = partner->pos.x - (userData->superBlock->pos.x + userData->partnerPosX[i]);
            userData->partnerPosY[i] = partner->pos.y - (userData->superBlock->pos.y + userData->partnerPosY[i]);
            userData->partnerPosZ[i] = partner->pos.z - (userData->superBlock->pos.z + userData->partnerPosZ[i]);
        }
    }

    userData = (EnergyOrbSet*)script->userData;
    switch (userData->scatterState) {
        case 0:
            t1 = update_lerp(EASING_CUBIC_OUT, 0.0f, 50.0f, userData->scatterStateTime, 20 * DT);
            for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
                x = userData->posY[i] = 0.0f;
                add_vec2D_polar(&x, &userData->posY[i], t1, N(SuperBlock_UpgradeOrbAngles)[i]);
                userData->posX[i] = cosTheta * x;
                userData->posZ[i] = sinTheta * x;
            }

            userData->scatterStateTime++;
            if (userData->scatterStateTime >= (s32)(21 * DT)) {
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
            if (userData->scatterStateTime > (s32)(15 * DT)) {
                userData->scatterStateTime = 15 * DT;
                userData->scatterState = 2;
            }
            break;
        case 2:
            userData->scatterStateTime++;
            if (userData->scatterStateTime > (s32)(30 * DT)) {
                for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
                    userData->orbEffects[i]->flags |= FX_INSTANCE_FLAG_DISMISS;
                }
                return ApiStatus_DONE2;
            }
            break;
    }

    switch (userData->gatherState) {
        case 0:
            userData->gatherStateTime++;
            if (userData->gatherStateTime > (s32)(15 * DT)) {
                userData->gatherState = 1;
                userData->gatherStateTime = 0;
            }
            break;
        case 1:
            for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
                userData->posX[i] += update_lerp(EASING_QUADRATIC_IN, 0.0f, userData->partnerPosX[i], userData->gatherStateTime, 20 * DT);
                userData->posY[i] += update_lerp(EASING_QUADRATIC_IN, 0.0f, userData->partnerPosY[i], userData->gatherStateTime, 20 * DT);
                userData->posZ[i] += update_lerp(EASING_QUADRATIC_IN, 0.0f, userData->partnerPosZ[i], userData->gatherStateTime, 20 * DT);
            }

            userData->gatherStateTime++;
            if (userData->gatherStateTime > (s32)(20 * DT)) {
                userData->gatherState = 2;
                userData->gatherStateTime = 0;
            }
            break;
    }

    for (i = 0; i < SUPER_BLOCK_NUM_ORBS; i++) {
        userData->orbEffects[i]->data.motionBlurFlame->pos.x = userData->posX[i];
        userData->orbEffects[i]->data.motionBlurFlame->pos.y = userData->posY[i];
        userData->orbEffects[i]->data.motionBlurFlame->pos.z = userData->posZ[i];
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SuperBlock_WhiteScreenFlash)) {
    Bytecode* args = script->ptrReadPos;
    s32 ret = ApiStatus_BLOCK;

    if (isInitialCall) {
        script->varTable[0] = evt_get_variable(script, *args++);
        script->varTable[1] = evt_get_variable(script, *args++);
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
        set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 208, 208);
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
                ret = ApiStatus_DONE1;
            }
            script->functionTemp[1] -= script->varTable[1];
            if (script->functionTemp[1] < 0) {
                script->functionTemp[1] = 0;
            }
            break;
    }

    set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);

    return ret;
}

API_CALLABLE(N(SuperBlock_PartnerSparkles2)) {
    Npc* partner = get_npc_safe(NPC_PARTNER);
    fx_sparkles(FX_SPARKLES_2, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_PartnerSparkles4)) {
    Npc* partner = get_npc_safe(NPC_PARTNER);
    fx_sparkles(FX_SPARKLES_4, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_WaitForPlayerToLand)) {
    script->varTable[0] = FALSE;
    if ((gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) && (gPartnerStatus.actingPartner == PARTNER_BOMBETTE)) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(SuperBlock_ShowUpgradeEffects) = {
    EVT_WAIT(10 * DT)
    EVT_CALL(PlaySound, SOUND_212D)
    EVT_CALL(N(SuperBlock_GatherEnergyFX), SUPER_BLOCK_MAPVAR)
    EVT_WAIT(85 * DT)
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_212E)
        EVT_CALL(N(SuperBlock_WhiteScreenFlash), 70, 70)
        EVT_WAIT(27 * DT)
        EVT_CALL(PlaySound, SOUND_208E)
        EVT_CALL(N(SuperBlock_WhiteScreenFlash), 50, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(N(SuperBlock_HideBlockContent), SUPER_BLOCK_MAPVAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(47 * DT)
        EVT_CALL(N(SuperBlock_RadiateFaintEnergyFX))
        EVT_CALL(N(SuperBlock_PartnerSparkles2))
        EVT_WAIT(5 * DT)
        EVT_CALL(N(SuperBlock_PartnerSparkles4))
        EVT_WAIT(5 * DT)
        EVT_CALL(N(SuperBlock_PartnerSparkles2))
    EVT_END_THREAD
    EVT_WAIT(3)
    EVT_CALL(N(SuperBlock_AnimateEnergyOrbs), SUPER_BLOCK_MAPVAR)
    EVT_WAIT(30 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(SuperBlock_OnHit) = {
    EVT_IF_EQ(SUPER_BLOCK_GAMEFLAG, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(IsStartingConversation, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(N(SuperBlock_WaitForPlayerToLand))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ModifyGlobalOverrideFlags, 1, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    EVT_CALL(N(SuperBlock_SetOverride40))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(N(SuperBlock_StartGlowEffect), SUPER_BLOCK_MAPVAR, LVar9)
    EVT_CALL(FindKeyItem, ITEM_ULTRA_STONE, LVarC)
    EVT_CALL(N(SuperBlock_CountEligiblePartners))
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DC, 160, 40)
        EVT_WAIT(10)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(GF_Tutorial_SuperBlock, 0)
        EVT_SET(GF_Tutorial_SuperBlock, 1)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DA, 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DB, 160, 40)
    EVT_END_IF
    EVT_CALL(N(SuperBlock_ShowSelectPartnerMenu))
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_NE(LVar0, LVarB)
        EVT_CALL(N(SuperBlock_SwitchToPartner), LVarB)
    EVT_ELSE
        EVT_CALL(func_802CF56C, 2)
    EVT_END_IF
    EVT_WAIT(10 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DF, 160, 40)
    EVT_CALL(ShowChoice, MSG_Choice_000D)
    EVT_CALL(CloseMessage)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
        EVT_CALL(N(SuperBlock_ClearOverride40))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(SuperBlock_ShowUpgradeEffects))
    EVT_CALL(N(SuperBlock_GetPartnerRank), LVarB, LVarD)
    EVT_SET(SUPER_BLOCK_GAMEFLAG, 1)
    EVT_CALL(N(SuperBlock_EndGlowEffect), LVar9)
    EVT_CALL(N(SuperBlock_LoadCurrentPartnerName))
    EVT_IF_EQ(LVarD, 1)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DD, 160, 40)
    EVT_ELSE
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00DE, 160, 40)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ModifyGlobalOverrideFlags, 0, GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS)
    EVT_CALL(N(SuperBlock_ClearOverride40))
    EVT_RETURN
    EVT_END
};
