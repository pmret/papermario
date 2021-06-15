#include "common.h"

extern s32 D_8029FB90;
extern f32 D_8029FB94;
extern Effect* D_8029FB98;
extern Effect* D_8029FB9C;
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

    script->varTable[0].s = isImmobile;
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
    script->varTable[0].s = 0;
    if (player->debuff == 3 || player->debuff == 4 || player->debuff == 5 || player->debuff == 6 ||
        player->debuff == 7 || player->debuff == 8) {
        script->varTable[0].s = 1;
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
        script->varTable[0].s = TRUE;
    } else {
        script->varTable[0].s = FALSE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80260E38(ScriptInstance* script, s32 isInitialCall) {
    show_battle_message(0x31, 60);
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

    if (heroes_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
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
        D_8029FBA0 = create_icon(&D_80108A64);
        set_icon_render_pos(D_8029FBA0, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0].s = sleepTime;

    return ApiStatus_DONE2;
}

ApiStatus func_80261064(ScriptInstance* script, s32 isInitialCall) {
    s32 sellValue = gItemTable[gBattleStatus.selectedItemID].sellValue;

    if (heroes_is_ability_active(gBattleStatus.playerActor, ABILITY_REFUND) && sellValue > 0) {
        free_icon(D_8029FBA0);
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", func_802610CC);

ApiStatus func_80261164(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 20;
        unfreeze_cam();
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0].s * 12) & 0xFC);

    script->functionTemp[0].s -= 1;
    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802611E8(ScriptInstance *script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    StaticItem* item = &gItemTable[0x95];

    playerData->curHP += item->potencyA;
    if (playerData->curMaxHP < playerData->curHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    playerData->invItems[find_item(0x95)] = ITEM_NONE;
    sort_items();
    script->varTable[3].s = item->potencyA;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", func_8026127C);

ApiStatus func_80261388(ScriptInstance* script, s32 isInitialCall) {
    s32 partnerActorExists = gBattleStatus.partnerActor != NULL;

    script->varTable[0].s = FALSE;
    if (partnerActorExists) {
        script->varTable[0].s = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802613A8(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.selectedItemID = ITEM_LIFE_SHROOM;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", func_802613BC);

INCLUDE_ASM(s32, "18F340", func_80261478);

INCLUDE_ASM(s32, "18F340", func_80261530);

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
        D_8029FB98 = func_80071750(0, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.4f, 0);
        D_8029FB9C = func_80071750(3, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.00001f, 0);
        D_8029FBA4 = 0;
        D_8029FB90 = 12;
        sfx_play_sound(0x2074);
    }
    merlee->pos.y = D_8029FB94 + (sin_rad((script->functionTemp[1].s * TAU) / 360.0f) * 3.0f);

    script->functionTemp[1].s += 10;
    script->functionTemp[1].s = clamp_angle(script->functionTemp[1].s);

    effectInstanceData = D_8029FB98->instanceData;
    effectInstanceData->pos.x = merlee->pos.x;
    effectInstanceData->pos.y = merlee->pos.y + 16.0f;
    effectInstanceData->pos.z = merlee->pos.z;

    effectInstanceData = D_8029FB9C->instanceData;
    effectInstanceData->pos.x = merlee->pos.x;
    effectInstanceData->pos.y = merlee->pos.y + 16.0f;
    effectInstanceData->pos.z = merlee->pos.z + 5.0f;

    if (D_8029FBA4 == 2) {
        D_8029FB98->instanceData->unk_30 = 0.00001f;
        D_8029FB9C->instanceData->unk_30 = 0.00001f;
        D_8029FB98->flags |= 0x10;
        D_8029FB9C->flags |= 0x10;
        return ApiStatus_DONE1;
    }

    if (D_8029FBA4 == 1) {
        effectInstanceData = D_8029FB98->instanceData;
        effectInstanceData->unk_30 += 0.35;
        if (effectInstanceData->unk_30 > 3.5) {
            effectInstanceData->unk_30 = 3.5f;
        }

        if (D_8029FB90 != 0) {
            D_8029FB90--;
        } else {
            effectInstanceData = D_8029FB9C->instanceData;
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

    script->varTable[0].s = FALSE;
    if (playerData->merleeCastsLeft > 0) {
        script->varTable[0].s = TRUE;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", func_802619E8);

ApiStatus func_80261B40(ScriptInstance* script, s32 isInitialCall) {
    if (script->varTable[10].s > 0) {
        free_icon(D_8029FBAC);
    }
    if (script->varTable[11].s > 0 || script->varTable[12].s > 0) {
        free_icon(D_8029FBA8);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", FXRecoverHP);

INCLUDE_ASM(s32, "18F340", FXRecoverFP);

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
    func_8026777C();
    return ApiStatus_DONE2;
}

ApiStatus func_80261DD4(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[11].s = playerData->bootsLevel;
    script->varTable[12].s = playerData->hammerLevel;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "18F340", func_80261DF4);

INCLUDE_ASM(s32, "18F340", func_80261FB4);

ApiStatus func_802620F8(ScriptInstance* script, s32 isInitialCall) {
    // TODO get type correct
    s32* temp_v1 = &D_8029FBB0[script->varTable[14].s];

    if (*temp_v1 != 0) {
        (*temp_v1)--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}
