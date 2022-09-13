#include "common.h"
#include "effects.h"
#include "hud_element.h"

extern HudScript HES_Happy;
extern HudScript HES_HPDrain;

extern s32 D_8029FB90;
extern f32 D_8029FB94;
extern EffectInstance* BattleMerleeOrbEffect;
extern EffectInstance* BattleMerleeWaveEffect;
extern s32 D_8029FBA0;
extern s16 D_8029FBA4;
extern s32 D_8029FBA8;
extern s32 D_8029FBAC;
extern s32 D_8029FBB0[];

void func_80260A60(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorPart* actorPart = &battleStatus->playerActor->partsTable[0];

    if (battleStatus->flags2 & BS_FLAGS2_40) {
        actorPart->idleAnimations = bPeachIdleAnims;
        set_animation(0, 0, 0xA0002);
    } else if (!battleStatus->outtaSightActive) {
        actorPart->idleAnimations = bMarioIdleAnims;
    }
}

ApiStatus IsPartnerImmobile(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    s32 isImmobile = playerActor->debuff == STATUS_FEAR
                     || playerActor->debuff == STATUS_DIZZY
                     || playerActor->debuff == STATUS_PARALYZE
                     || playerActor->debuff == STATUS_SLEEP
                     || playerActor->debuff == STATUS_FROZEN
                     || playerActor->debuff == STATUS_STOP;

    if (playerActor->stoneStatus == 12) {
        isImmobile = TRUE;
    }

    script->varTable[0] = isImmobile;
    return ApiStatus_DONE2;
}

ApiStatus activate_defend_command(Evt* script, s32 isInitialCall) {
    ActorPart* actorPart = &gBattleStatus.playerActor->partsTable[0];

    deduct_current_move_fp();
    gBattleStatus.flags1 |= BS_FLAGS1_PLAYER_DEFENDING;
    actorPart->idleAnimations = bMarioDefendAnims;
    set_animation(0, 0, 0x10014);
    return ApiStatus_DONE2;
}

ApiStatus func_80260B70(Evt* script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;

    func_802667F0(2, player, player->currentPos.x, player->currentPos.y + 20.0f, player->currentPos.z);
    sfx_play_sound(SOUND_3FC);
    script->varTable[0] = FALSE;
    if (player->debuff == STATUS_FEAR || player->debuff == STATUS_DIZZY || player->debuff == STATUS_PARALYZE ||
        player->debuff == STATUS_SLEEP ||player->debuff == STATUS_FROZEN || player->debuff == STATUS_STOP) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80260BF4(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "18F340", func_80260BF4);

ApiStatus func_80260DB8(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_40000;
    return ApiStatus_DONE2;
}

ApiStatus func_80260DD8(Evt* script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;
    s32 var;

    if (gPlayerData.hasActionCommands) {
        return ApiStatus_DONE2;
    }

    var = player->state.varTable[0];
    if (var >= rand_int(100)) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80260E38(Evt* script, s32 isInitialCall) {
    btl_show_battle_message(0x31, 60);
    return ApiStatus_DONE2;
}

ApiStatus func_80260E5C(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 &= ~BS_FLAGS1_8000;
    gBattleStatus.flags1 &= ~BS_FLAGS1_2000;
    gBattleStatus.flags1 &= ~BS_FLAGS1_4000;
    return ApiStatus_DONE2;
}

#define NAMESPACE base
ApiStatus N(GiveRefund)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->selectedItemID].sellValue;
    f32 facingAngleSign = 0.0f;
    s32 sleepTime = 0;
    f32 posX, posY, posZ;
    posY = player->currentPos.y + player->size.y;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        s32 i;
        s32 iconPosX, iconPosY, iconPosZ;

        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->currentPos.x;
            posZ = player->currentPos.z;

            make_item_entity(ITEM_COIN, posX, posY, posZ, 0x17, (i * 3) + 1, facingAngleSign, 0);
            add_coins(1);
            facingAngleSign += 30.0f;
        }

        sleepTime = (i * 3) + 30;

        posX = player->currentPos.x;
        posY = player->currentPos.y;
        posZ = player->currentPos.z;
        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconPosX, &iconPosY, &iconPosZ);
        D_8029FBA0 = hud_element_create(&HES_Refund);
        hud_element_set_render_pos(D_8029FBA0, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(Evt* script, s32 isInitialCall) {
    s32 sellValue = gItemTable[gBattleStatus.selectedItemID].sellValue;

    if (player_team_is_ability_active(gBattleStatus.playerActor, ABILITY_REFUND) && sellValue > 0) {
        hud_element_free(D_8029FBA0);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802610CC(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 20;
    }

    set_background_color_blend(0, 0, 0, ((20 - script->functionTemp[0]) * 12) & 0xFC);

    script->functionTemp[0] -= 1;
    do {} while(0); // TODO required to match
    return (script->functionTemp[0] == 0) * ApiStatus_DONE2;
}

ApiStatus func_80261164(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
        btl_cam_unfreeze();
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 12) & 0xFC);

    script->functionTemp[0] -= 1;
    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus ConsumeLifeShroom(Evt *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    ItemData* item = &gItemTable[ITEM_LIFE_SHROOM];

    playerData->curHP += item->potencyA;
    if (playerData->curMaxHP < playerData->curHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    playerData->invItems[find_item(ITEM_LIFE_SHROOM)] = ITEM_NONE;
    sort_items();
    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

ApiStatus RestorePreDefeatState(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->rushFlags = RUSH_FLAG_NONE;
    gBattleState = D_800DC4E4;
    gBattleState2 = D_800DC4D8;
    battleStatus->flags1 |= BS_FLAGS1_8;
    battleStatus->flags2 &= ~BS_FLAGS2_8000000;

    if (!(battleStatus->flags2 & BS_FLAGS2_40)) {
        if (playerData->curHP <= 1 && is_ability_active(ABILITY_MEGA_RUSH)) {
            gBattleStatus.flags2 |= BS_FLAGS2_8000000;
            battleStatus->rushFlags |= RUSH_FLAG_MEGA;
        }

        if (playerData->curHP <= 5 && is_ability_active(ABILITY_POWER_RUSH) &&
            !(battleStatus->rushFlags & RUSH_FLAG_MEGA)) {
            gBattleStatus.flags2 |= BS_FLAGS2_8000000;
            battleStatus->rushFlags |= RUSH_FLAG_POWER;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80261388(Evt* script, s32 isInitialCall) {
    s32 partnerActorExists = gBattleStatus.partnerActor != NULL;

    script->varTable[0] = FALSE;
    if (partnerActorExists) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802613A8(Evt* script, s32 isInitialCall) {
    gBattleStatus.selectedItemID = ITEM_LIFE_SHROOM;
    return ApiStatus_DONE2;
}

ApiStatus PlayBattleMerleeGatherFX(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_energy_in_out(6, var1, var2 + 15, var3, 1.2f, 30);
    return ApiStatus_DONE2;
}

ApiStatus PlayBattleMerleeOrbFX(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_energy_orb_wave(9, var1, var2 + 15, var3, 5.0f, 15);
    return ApiStatus_DONE2;
}

ApiStatus BattleMerleeFadeStageToBlack(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 25;
    }

    set_background_color_blend(0, 0, 0, ((25 - script->functionTemp[0]) * 10) & 0xFE);
    script->functionTemp[0]--;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus BattleMerleeFadeStageFromBlack(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 25;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 10) & 0xFF);

    script->functionTemp[0] -= 5;
    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus BattleFadeInMerlee(Evt* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);

    if (isInitialCall) {
        sfx_play_sound(SOUND_24B);
        merlee->alpha = 0;
    }

    merlee->alpha += 17;
    if (merlee->alpha >= 255) {
        merlee->alpha = 255;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus BattleFadeOutMerlee(Evt* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);

    merlee->alpha -= 17;
    if (merlee->alpha == 0) {
        merlee->alpha = 0;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus BattleMerleeUpdateFX(Evt* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);
    EnergyOrbWaveFXData* data;

    if (isInitialCall) {
        script->functionTemp[1] = 0;
        D_8029FB94 = merlee->pos.y;
        BattleMerleeOrbEffect = fx_energy_orb_wave(0, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.4f, 0);
        BattleMerleeWaveEffect = fx_energy_orb_wave(3, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.00001f, 0);
        D_8029FBA4 = 0;
        D_8029FB90 = 12;
        sfx_play_sound(SOUND_2074);
    }
    merlee->pos.y = D_8029FB94 + (sin_rad(DEG_TO_RAD(script->functionTemp[1])) * 3.0f);

    script->functionTemp[1] += 10;
    script->functionTemp[1] = clamp_angle(script->functionTemp[1]);

    data = BattleMerleeOrbEffect->data.energyOrbWave;
    data->pos.x = merlee->pos.x;
    data->pos.y = merlee->pos.y + 16.0f;
    data->pos.z = merlee->pos.z;

    data = BattleMerleeWaveEffect->data.energyOrbWave;
    data->pos.x = merlee->pos.x;
    data->pos.y = merlee->pos.y + 16.0f;
    data->pos.z = merlee->pos.z + 5.0f;

    if (D_8029FBA4 == 2) {
        BattleMerleeOrbEffect->data.energyOrbWave->scale = 0.00001f;
        BattleMerleeWaveEffect->data.energyOrbWave->scale = 0.00001f;
        BattleMerleeOrbEffect->flags |= 0x10;
        BattleMerleeWaveEffect->flags |= 0x10;
        return ApiStatus_DONE1;
    }

    if (D_8029FBA4 == 1) {
        data = BattleMerleeOrbEffect->data.energyOrbWave;
        data->scale += 0.35;
        if (data->scale > 3.5) {
            data->scale = 3.5f;
        }

        if (D_8029FB90 != 0) {
            D_8029FB90--;
        } else {
            data = BattleMerleeWaveEffect->data.energyOrbWave;
            data->scale += 0.5;
            if (data->scale > 5.0) {
                D_8029FBA4 = 2;
            }
        }
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802619B4(Evt* script, s32 isInitialCall) {
    D_8029FBA4 = 1;
    return ApiStatus_DONE2;
}

ApiStatus HasMerleeCastsLeft(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = FALSE;
    if (playerData->merleeCastsLeft > 0) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802619E8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    screenX += 30;
    screenY -= 19;

    if (script->varTable[10] > 0) {
        D_8029FBAC = hud_element_create(&HES_HPDrain);
        hud_element_set_render_pos(D_8029FBAC, screenX, screenY);
        screenY += 9;
    }

    if (script->varTable[11] > 0 || script->varTable[12] > 0) {
        D_8029FBA8 = hud_element_create(&HES_Happy);
        hud_element_set_render_pos(D_8029FBA8, screenX, screenY);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80261B40(Evt* script, s32 isInitialCall) {
    if (script->varTable[10] > 0) {
        hud_element_free(D_8029FBAC);
    }
    if (script->varTable[11] > 0 || script->varTable[12] > 0) {
        hud_element_free(D_8029FBA8);
    }
    return ApiStatus_DONE2;
}

ApiStatus FXRecoverHP(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_recover(0, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus FXRecoverFP(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_recover(1, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus IncrementPlayerHP(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP++;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

ApiStatus IncrementPlayerFP(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curFP++;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80261D98(Evt* script, s32 isInitialCall) {
    inflict_status_set_duration(get_actor(script->owner1.actorID), 4, 0, 1);
    btl_update_ko_status();
    return ApiStatus_DONE2;
}

ApiStatus func_80261DD4(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[11] = playerData->bootsLevel;
    script->varTable[12] = playerData->hammerLevel;
    return ApiStatus_DONE2;
}

ApiStatus func_80261DF4(Evt* script, s32 isInitialCall) {
    ItemEntity* item = get_item_entity(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
    }

    switch (script->functionTemp[1]) {
        case 0:
            script->functionTemp[0]--;
            item->position.y += script->functionTemp[0];
            if (item->position.y < 0.0f) {
                item->position.y = 0.0f;
                script->functionTemp[0] = 8;
                script->functionTemp[1] = 1;
            }
            break;
        case 1:
            script->functionTemp[0]--;
            item->position.y += script->functionTemp[0];
            item->position.x += 1.5;
            if (item->position.y < 0.0f) {
                item->position.y = 0.0f;
                script->functionTemp[0] = 4;
                script->functionTemp[1] = 2;
            }
            break;
        case 2:
            script->functionTemp[0]--;
            item->position.y += script->functionTemp[0];
            item->position.x += 1.2;
            if (item->position.y < 0.0f) {
                item->position.y = 0.0f;
                script->functionTemp[1] = 3;
            }
            break;
        case 3:
            D_8029FBB0[0] = 20;
            D_8029FBB0[1] = 20;
            D_8029FBB0[2] = 20;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80261FB4(Evt* script, s32 isInitialCall) {
    ItemEntity* item = get_item_entity(script->varTable[10]);
    Actor* player = gBattleStatus.playerActor;
    s32 ft1;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 10;
    }

    switch (script->functionTemp[0]) {
        case 0:
            ft1 = script->functionTemp[1];
            deltaX = player->currentPos.x - item->position.x;
            deltaY = player->currentPos.y + 12.0f - item->position.y;
            deltaZ = player->currentPos.z - 5.0f - item->position.z;

            item->position.x += deltaX / ft1;
            item->position.y += deltaY / ft1;
            item->position.z += deltaZ / ft1;

            item->position.y += dist2D(item->position.x, item->position.y, player->currentPos.x,
                                       player->currentPos.y + 12.0f) / 5.0f;

            if (script->functionTemp[1] == 1) {
                script->functionTemp[0] = script->functionTemp[1];
            }

            script->functionTemp[1]--;
            break;
        case 1:
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802620F8(Evt* script, s32 isInitialCall) {
    // TODO get type correct
    s32* temp_v1 = &D_8029FBB0[script->varTable[14]];

    if (*temp_v1 != 0) {
        (*temp_v1)--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}
