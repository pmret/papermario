#include "common.h"

extern s32 D_80108AAC;
extern s32 D_80108AD4;

extern s32 D_8029FB90;
extern f32 D_8029FB94;
extern EffectInstance* D_8029FB98;
extern EffectInstance* D_8029FB9C;
extern HudElement* D_8029FBA0;
extern s16 D_8029FBA4;
extern s32 D_8029FBA8;
extern s32 D_8029FBAC;
extern s32 D_8029FBB0[];

void func_80260A60(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorPart* actorPart = &battleStatus->playerActor->partsTable[0];

    if (battleStatus->flags2 & 0x40) {
        actorPart->idleAnimations = &bPeachIdleAnims;
        set_animation(0, 0, 0xA0002);
    } else if (!battleStatus->outtaSightActive) {
        actorPart->idleAnimations = &bMarioIdleAnims;
    }
}

ApiStatus IsPartnerImmobile(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus activate_defend_command(ScriptInstance* script, s32 isInitialCall) {
    ActorPart* actorPart = &gBattleStatus.playerActor->partsTable[0];

    deduct_current_move_fp();
    gBattleStatus.flags1 |= 0x400000;
    actorPart->idleAnimations = &bMarioDefendAnims;
    set_animation(0, 0, 0x10014);
    return ApiStatus_DONE2;
}

ApiStatus func_80260B70(ScriptInstance* script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;

    func_802667F0(2, player, player->currentPos.x, player->currentPos.y + 20.0f, player->currentPos.z);
    sfx_play_sound(0x3FC);
    script->varTable[0] = FALSE;
    if (player->debuff == STATUS_FEAR || player->debuff == STATUS_DIZZY || player->debuff == STATUS_PARALYZE ||
        player->debuff == STATUS_SLEEP ||player->debuff == STATUS_FROZEN || player->debuff == STATUS_STOP) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", func_80260BF4);

ApiStatus func_80260DB8(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x40000;
    return ApiStatus_DONE2;
}

ApiStatus func_80260DD8(ScriptInstance* script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;
    s32 var;

    if (gPlayerData.hasActionCommands) {
        return ApiStatus_DONE2;
    }

    var = player->varTable[0];
    if (var >= rand_int(100)) {
        script->varTable[0] = TRUE;
    } else {
        script->varTable[0] = FALSE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80260E38(ScriptInstance* script, s32 isInitialCall) {
    btl_show_battle_message(0x31, 60);
    return ApiStatus_DONE2;
}

ApiStatus func_80260E5C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 &= ~0x8000;
    gBattleStatus.flags1 &= ~0x2000;
    gBattleStatus.flags1 &= ~0x4000;
    return ApiStatus_DONE2;
}

#define NAMESPACE base
ApiStatus N(GiveRefund)(ScriptInstance* script, s32 isInitialCall) {
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
        D_8029FBA0 = create_hud_element(&D_80108A64);
        set_hud_element_render_pos(D_8029FBA0, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus N(GiveRefundCleanup)(ScriptInstance* script, s32 isInitialCall) {
    s32 sellValue = gItemTable[gBattleStatus.selectedItemID].sellValue;

    if (player_team_is_ability_active(gBattleStatus.playerActor, ABILITY_REFUND) && sellValue > 0) {
        free_hud_element(D_8029FBA0);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802610CC(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 20;
    }

    set_background_color_blend(0, 0, 0, ((20 - script->functionTemp[0].s) * 12) & 0xFC);

    script->functionTemp[0].s -= 1;
    do {} while(0); // TODO required to match
    return (script->functionTemp[0].s == 0) * ApiStatus_DONE2;
}

ApiStatus func_80261164(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 20;
        btl_cam_unfreeze();
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0].s * 12) & 0xFC);

    script->functionTemp[0].s -= 1;
    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus ConsumeLifeShroom(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    StaticItem* item = &gItemTable[0x95];

    playerData->curHP += item->potencyA;
    if (playerData->curMaxHP < playerData->curHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    playerData->invItems[find_item(0x95)] = ITEM_NONE;
    sort_items();
    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

// TODO something wrong with the struct breakdown for BattleStatus
#ifdef NON_MATCHING
ApiStatus RestorePreDefeatState(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->dangerFlags = 0;
    gBattleState = battleStatus->unk_474;
    battleStatus->battleState = battleStatus->unk_468;
    battleStatus->flags1 |= 8;
    battleStatus->flags2 &= ~0x8000000;

    if (!(battleStatus->flags2 & 0x40)) {
        if (playerData->curHP <= 1 && is_ability_active(ABILITY_MEGA_RUSH)) {
            battleStatus->flags2 |= 0x8000000;
            gBattleStatus.dangerFlags |= 1;
        }
        if (playerData->curHP <= 5 && is_ability_active(ABILITY_POWER_RUSH) && !(battleStatus->dangerFlags & 1)) {
            battleStatus->flags2 |= 0x8000000;
            gBattleStatus.dangerFlags |= 2;
        }
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "18F340", RestorePreDefeatState);
#endif

ApiStatus func_80261388(ScriptInstance* script, s32 isInitialCall) {
    s32 partnerActorExists = gBattleStatus.partnerActor != NULL;

    script->varTable[0] = FALSE;
    if (partnerActorExists) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802613A8(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.selectedItemID = ITEM_LIFE_SHROOM;
    return ApiStatus_DONE2;
}

ApiStatus func_802613BC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    playFX_6B(6, var1, var2 + 15, var3, 1.2f, 30);
    return ApiStatus_DONE2;
}

ApiStatus func_80261478(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    playFX_52(9, var1, var2 + 15, var3, 5.0f, 15);
    return ApiStatus_DONE2;
}

ApiStatus func_80261530(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 25;
    }

    set_background_color_blend(0, 0, 0, ((25 - script->functionTemp[0].s) * 10) & 0xFE);

    script->functionTemp[0].s--;
    do {} while(0); // TODO required to match
    return (script->functionTemp[0].s == 0) * ApiStatus_DONE2;
}

ApiStatus func_802615C8(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 25;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0].s * 10) & 0xFF);

    script->functionTemp[0].s -= 5;
    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80261648(ScriptInstance* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);

    if (isInitialCall) {
        sfx_play_sound(0x24B);
        merlee->alpha = 0;
    }

    merlee->alpha += 17;
    if (merlee->alpha >= 0xFF) {
        merlee->alpha = 0xFF;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802616B4(ScriptInstance* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);

    merlee->alpha -= 17;
    if (merlee->alpha == 0) {
        merlee->alpha = 0;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802616F4(ScriptInstance* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);
    EffectInstanceData* effectInstanceData;

    if (isInitialCall) {
        script->functionTemp[1].s = 0;
        D_8029FB94 = merlee->pos.y;
        D_8029FB98 = playFX_52(0, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.4f, 0);
        D_8029FB9C = playFX_52(3, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.00001f, 0);
        D_8029FBA4 = 0;
        D_8029FB90 = 12;
        sfx_play_sound(0x2074);
    }
    merlee->pos.y = D_8029FB94 + (sin_rad((script->functionTemp[1].s * TAU) / 360.0f) * 3.0f);

    script->functionTemp[1].s += 10;
    script->functionTemp[1].s = clamp_angle(script->functionTemp[1].s);

    effectInstanceData = D_8029FB98->data;
    effectInstanceData->pos.x = merlee->pos.x;
    effectInstanceData->pos.y = merlee->pos.y + 16.0f;
    effectInstanceData->pos.z = merlee->pos.z;

    effectInstanceData = D_8029FB9C->data;
    effectInstanceData->pos.x = merlee->pos.x;
    effectInstanceData->pos.y = merlee->pos.y + 16.0f;
    effectInstanceData->pos.z = merlee->pos.z + 5.0f;

    if (D_8029FBA4 == 2) {
        D_8029FB98->data->unk_30 = 0.00001f;
        D_8029FB9C->data->unk_30 = 0.00001f;
        D_8029FB98->flags |= 0x10;
        D_8029FB9C->flags |= 0x10;
        return ApiStatus_DONE1;
    }

    if (D_8029FBA4 == 1) {
        effectInstanceData = D_8029FB98->data;
        effectInstanceData->unk_30 += 0.35;
        if (effectInstanceData->unk_30 > 3.5) {
            effectInstanceData->unk_30 = 3.5f;
        }

        if (D_8029FB90 != 0) {
            D_8029FB90--;
        } else {
            effectInstanceData = D_8029FB9C->data;
            effectInstanceData->unk_30 += 0.5;
            if (effectInstanceData->unk_30 > 5.0) {
                D_8029FBA4 = 2;
            }
        }
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802619B4(ScriptInstance* script, s32 isInitialCall) {
    D_8029FBA4 = 1;
    return ApiStatus_DONE2;
}

ApiStatus HasMerleeCastsLeft(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = FALSE;
    if (playerData->merleeCastsLeft > 0) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802619E8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);
    s32 screenX;
    s32 screenY;
    s32 screenZ;

    get_screen_coords(gCurrentCameraID, x, y, z, &screenX, &screenY, &screenZ);

    screenX += 30;
    screenY -= 19;

    if (script->varTable[10] > 0) {
        D_8029FBAC = create_hud_element(&D_80108AD4);
        set_hud_element_render_pos(D_8029FBAC, screenX, screenY);
        screenY += 9;
    }

    if (script->varTable[11] > 0 || script->varTable[12] > 0) {
        D_8029FBA8 = create_hud_element(&D_80108AAC);
        set_hud_element_render_pos(D_8029FBA8, screenX, screenY);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80261B40(ScriptInstance* script, s32 isInitialCall) {
    if (script->varTable[10] > 0) {
        free_hud_element(D_8029FBAC);
    }
    if (script->varTable[11] > 0 || script->varTable[12] > 0) {
        free_hud_element(D_8029FBA8);
    }
    return ApiStatus_DONE2;
}

ApiStatus FXRecoverHP(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);

    playFX_40(0, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus FXRecoverFP(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32 var4 = get_variable(script, *args++);

    playFX_40(1, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus IncrementPlayerHP(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP++;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

ApiStatus IncrementPlayerFP(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curFP++;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80261D98(ScriptInstance* script, s32 isInitialCall) {
    inflict_status_set_duration(get_actor(script->owner1.actorID), 4, 0, 1);
    btl_update_ko_status();
    return ApiStatus_DONE2;
}

ApiStatus func_80261DD4(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[11] = playerData->bootsLevel;
    script->varTable[12] = playerData->hammerLevel;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", func_80261DF4);

ApiStatus func_80261FB4(ScriptInstance* script, s32 isInitialCall) {
    ItemEntity* item = get_item_entity(script->varTable[10]);
    Actor* player = gBattleStatus.playerActor;
    s32 ft1;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 10;
    }

    switch (script->functionTemp[0].s) {
        case 0:
            ft1 = script->functionTemp[1].s;
            deltaX = player->currentPos.x - item->position.x;
            deltaY = player->currentPos.y + 12.0f - item->position.y;
            deltaZ = player->currentPos.z - 5.0f - item->position.z;

            item->position.x += deltaX / ft1;
            item->position.y += deltaY / ft1;
            item->position.z += deltaZ / ft1;

            item->position.y += dist2D(item->position.x, item->position.y, player->currentPos.x,
                                       player->currentPos.y + 12.0f) / 5.0f;

            if (script->functionTemp[1].s == 1) {
                script->functionTemp[0].s = script->functionTemp[1].s;
            }

            script->functionTemp[1].s--;
            break;
        case 1:
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_802620F8(ScriptInstance* script, s32 isInitialCall) {
    // TODO get type correct
    s32* temp_v1 = &D_8029FBB0[script->varTable[14]];

    if (*temp_v1 != 0) {
        (*temp_v1)--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}
