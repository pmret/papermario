#include "common.h"
#include "effects.h"
#include "model.h"
#include "hud_element.h"
#include "script_api/battle.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/BattleMerlee.h"
#include "battle/action_cmd/flee.h"

extern HudScript HES_Happy;
extern HudScript HES_HPDrain;

extern EvtScript PlayerCelebrate;
extern EvtScript D_802988F0;
extern EvtScript D_80298724;
extern EvtScript D_80298948;
ApiStatus func_802749F8(Evt* script, s32 isInitialCall);

BSS s32 D_8029FB90;
BSS f32 D_8029FB94;
BSS EffectInstance* BattleMerleeOrbEffect;
BSS EffectInstance* BattleMerleeWaveEffect;
BSS s32 D_8029FBA0;
BSS s16 D_8029FBA4;
BSS s32 D_8029FBA8;
BSS s32 D_8029FBAC;
BSS s32 D_8029FBB0[3];

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

extern PlayerCelebrationAnimOptions D_80280FC0;

ApiStatus ChoosePlayerCelebrationAnim(Evt* script, s32 isInitialCall) {
    PlayerCelebrationAnimOptions* pcao = &D_80280FC0;
    PlayerData* playerData = &gPlayerData;
    s32 temp;
    s32 i;

    if (rand_int(pcao->randomChance + pcao->hpBasedChance) < pcao->randomChance) {
        temp = 0;
        for (i = 0; i < 8; i++) {
            temp += pcao->options[i * 2];
        }
        temp = rand_int(temp);
        for (i = 0; i < 8; i++) {
            temp -= pcao->options[i * 2];
            if (temp <= 0) {
                break;
            }
        }

        script->varTable[0] = pcao->options[i * 2 + 1];
    } else {
        s32* opts;
        f32 healthRatio = playerData->curHP / (f32) playerData->curMaxHP;

        if (healthRatio <= 0.25) {
            opts = &pcao->options[16];
        } else if (healthRatio <= 0.5) {
            opts = &pcao->options[32];
        } else if (healthRatio <= 0.75) {
            opts = &pcao->options[48];
        } else {
            opts = &pcao->options[64];
        }

        temp = 0;
        for (i = 0; i < 8; i++) {
            temp += opts[i * 2];
        }
        temp = rand_int(temp);
        for (i = 0; i < 8; i++) {
            temp -= opts[i * 2];
            if (temp <= 0) {
                break;
            }
        }
        script->varTable[0] = opts[i * 2 + 1];
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80260DB8(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_ENEMY_FLED;
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
        *gBgRenderTypePtr = BACKGROUND_RENDER_TYPE_1;
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
    gBattleSubState = D_800DC4D8;
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
        *gBgRenderTypePtr = BACKGROUND_RENDER_TYPE_1;
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

EvtScript D_80284A20 = {
    EVT_RETURN
    EVT_END
};

EvtScript D_80284A30 = {
    EVT_RETURN
    EVT_END
};

EvtScript MarioEnterStage = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_22)
    EVT_CALL(SetBattleCamTarget, -80, 35, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 100)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RandInt, 100, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(50)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario_Running)
            EVT_CALL(PlayerRunToGoal, 25)
            EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario_10002)
        EVT_CASE_GT(20)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_BeforeJump)
            EVT_CALL(func_80273444, 18, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_BeforeJump)
            EVT_WAIT(7)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
            EVT_CALL(PlayerRunToGoal, 20)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
            EVT_END_CHILD_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_162)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GetUp)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_DustOff)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript PeachEnterStage = {
    EVT_CALL(func_8026BF48, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_22)
    EVT_CALL(SetBattleCamTarget, -80, 35, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
    EVT_CHILD_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 100)
        EVT_ADD(LVar1, 50)
        EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, 0, ANIM_Twink_Angry)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 45, -10, 10)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 100)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Peach_A0003)
    EVT_CALL(PlayerRunToGoal, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Peach_A0002)
    EVT_WAIT(15)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};

EvtScript PlayerScriptDispatcher = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(ExecutePlayerAction)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(PlayerFirstStrike)
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(PlayerCelebrate)
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(RunAwayStart)
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(RunAwayFail)
        EVT_CASE_EQ(PHASE_RUN_AWAY_RESET)
            EVT_EXEC_WAIT(RunAwayReset)
        EVT_CASE_EQ(PHASE_USE_LIFE_SHROOM)
            EVT_EXEC_WAIT(UseLifeShroom)
        EVT_CASE_EQ(PHASE_USE_DEFEND)
            EVT_EXEC_WAIT(StartDefend)
        EVT_CASE_EQ(PHASE_MERLEE_ATTACK_BONUS)
            EVT_EXEC_WAIT(MerleeAttackBonus)
        EVT_CASE_EQ(PHASE_MERLEE_DEFENSE_BONUS)
            EVT_EXEC_WAIT(MerleeDefenseBonus)
        EVT_CASE_EQ(PHASE_MERLEE_EXP_BONUS)
            EVT_EXEC_WAIT(MerleeExpBonus)
        EVT_CASE_EQ(PHASE_PLAYER_HAPPY)
            EVT_EXEC_WAIT(PlayerHappy)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript PeachScriptDispatcher = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(ExecutePeachAction)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript ExecutePlayerAction = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(LoadMoveScript)
            EVT_EXEC_WAIT(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(LoadMoveScript)
            EVT_EXEC_WAIT(LVar0)
        EVT_CASE_EQ(2)
            EVT_CALL(LoadItemScript)
            EVT_EXEC_WAIT(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
    EVT_END_SWITCH
    EVT_CALL(EnablePlayerBlur, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript ExecutePeachAction = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript PlayerFirstStrike = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(LoadMoveScript)
            EVT_EXEC_WAIT(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(LoadMoveScript)
            EVT_EXEC_WAIT(LVar0)
    EVT_END_SWITCH
    EVT_CALL(EnablePlayerBlur, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript StartDefend = {
    EVT_CALL(activate_defend_command)
    EVT_RETURN
    EVT_END
};

EvtScript HandleEvent_Player = {
    EVT_CALL(GetLastEvent, ACTOR_PLAYER, LVarF)
    EVT_SWITCH(LVarF)
        EVT_CASE_NE(EVENT_32)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_END_SWITCH
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_100, 0)
    EVT_CALL(func_802693F0)
    EVT_CALL(func_802749F8)
    EVT_CALL(GetLastEvent, ACTOR_PLAYER, LVarF)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_OR_EQ(EVENT_SPIKE_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_30)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_HurtFoot, ANIM_Mario_HurtFoot, ANIM_Mario_HurtFoot)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 5, 0, 1)
            EVT_SET_CONST(LVar1, ANIM_Mario_HurtFoot)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(D_802988F0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 10, 0, 2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 7, 0, 2)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 4, 0, 2)
            EVT_IF_EQ(LVarF, 39)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_31)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_50003, ANIM_Mario_50003, ANIM_Mario_50003)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 5, 0, 1)
            EVT_CHILD_THREAD
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar5, LVar6, LVar7)
                EVT_ADD(LVar5, 5)
                EVT_ADD(LVar6, 4)
                EVT_ADD(LVar7, 5)
                EVT_CALL(PlayEffect, EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.5), 15, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar5, LVar6, LVar7)
                EVT_ADD(LVar5, -5)
                EVT_ADD(LVar6, 18)
                EVT_ADD(LVar7, 5)
                EVT_CALL(PlayEffect, EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.5), 15, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_CHILD_THREAD
            EVT_SET_CONST(LVar1, ANIM_Mario_50003)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(D_802988F0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 10, 0, 2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 7, 0, 2)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 4, 0, 2)
            EVT_IF_EQ(LVarF, 36)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_31)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_HurtFoot, ANIM_Mario_HurtFoot, ANIM_Mario_HurtFoot)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 5, 0, 1)
            EVT_CALL(ShowShockEffect, -127)
            EVT_SET_CONST(LVar1, ANIM_Mario_HurtFoot)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(D_802988F0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 10, 0, 2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 7, 0, 2)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 4, 0, 2)
            EVT_IF_EQ(LVarF, 38)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_LUCKY)
            EVT_CALL(func_80260B70)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30009)
                EVT_WAIT(30)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_ELSE
                EVT_WAIT(30)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 15, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
            EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
            EVT_CALL(PlayerRunToGoal, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
        EVT_CASE_EQ(EVENT_32)
            EVT_WAIT(10)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 15, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
            EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
            EVT_CALL(PlayerRunToGoal, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_Mario_FallBack)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(D_80298724)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208C)
            EVT_SET_CONST(LVar1, ANIM_Mario_10002)
            EVT_EXEC_WAIT(D_80298948)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Mario_Crouch)
            EVT_EXEC_WAIT(D_80298948)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_Mario_50003)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(D_802988F0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
        EVT_CASE_EQ(EVENT_FIRE_DEATH)
            EVT_SET_CONST(LVar1, ANIM_Mario_50003)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(D_802988F0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_Mario_FallBack)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(D_802988F0)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_PARTNER)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_BeforeJump)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
            EVT_CALL(func_80273444, 15, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_BeforeJump)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript PlayerCelebrate = {
    EVT_SET(LVar0, 0)
    EVT_LOOP(5)
        EVT_ADD(LVar0, 72)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ChoosePlayerCelebrationAnim)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, LVar0)
    EVT_WAIT(31)
    EVT_RETURN
    EVT_END
};

EvtScript D_80286228 = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_50000)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_15D)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 8, 0, 0)
    EVT_CALL(func_80260DD8)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(func_80260DB8)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_15E)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -240, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(16.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(5)
    EVT_ELSE
        EVT_CHILD_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_CHILD_THREAD
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30001)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_162)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -100, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(10.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_SET(LVar3, 6)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CHILD_THREAD
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
        EVT_END_CHILD_THREAD
        EVT_LOOP(10)
            EVT_SUB(LVar0, LVar3)
            EVT_SUB(LVar3, 1)
            EVT_IF_LT(LVar3, 1)
                EVT_SET(LVar3, 1)
            EVT_END_IF
            EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_DUST_OFF)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GetUp)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_DustOff)
        EVT_CHILD_THREAD
            EVT_WAIT(7)
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 8)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 5)
                EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
        EVT_END_CHILD_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript RunAwayStart = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(GetActionCommandMode, LVar2)
    EVT_IF_EQ(LVar2, ACTION_COMMAND_MODE_NOT_LEARNED)
        EVT_EXEC_WAIT(D_80286228)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowActionHud, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_FLEE)
    EVT_CALL(action_command_flee_init, LVar0)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(func_80260E38)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_50000)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_15D)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT(5)
    EVT_CALL(action_command_flee_start, 0, 60, 3)
    EVT_CALL(func_80260E5C)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, 0, 2, 0, 0)
    EVT_WAIT(15)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 8, 0, 0)
    EVT_CALL(GetActionSuccess, LVar0)
    EVT_CALL(func_80260DD8)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(func_80260DB8)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_15E)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -240, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(16.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(5)
    EVT_ELSE
        EVT_CHILD_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_CHILD_THREAD
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30001)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_162)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -100, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(10.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_SET(LVar3, 6)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CHILD_THREAD
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
        EVT_END_CHILD_THREAD
        EVT_LOOP(10)
            EVT_SUB(LVar0, LVar3)
            EVT_SUB(LVar3, 1)
            EVT_IF_LT(LVar3, 1)
                EVT_SET(LVar3, 1)
            EVT_END_IF
            EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_DUST_OFF)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GetUp)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_DustOff)
        EVT_CHILD_THREAD
            EVT_WAIT(7)
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 8)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 5)
                EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
        EVT_END_CHILD_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript RunAwayFail = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript RunAwayReset = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_30002)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_24)
    EVT_WAIT(15)
    EVT_CALL(EnablePlayerBlur, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_371)
    EVT_SET(LVar0, 0)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 60)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 36)
        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnablePlayerBlur, 0)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_3FB)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 1)
    EVT_LOOP(0)
        EVT_IF_EQ(LVar0, 90)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_ADD(LVar0, LVar1)
        EVT_ADD(LVar1, 2)
        EVT_IF_GT(LVar0, 90)
            EVT_SET(LVar0, 90)
        EVT_END_IF
        EVT_CALL(SetActorRotation, ACTOR_PLAYER, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 2)
    EVT_CALL(SetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 20)
    EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript D_80287404 = {
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208D)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_ADD(LVar1, 45)
        EVT_SET(LVar3, LVar1)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar3, 2)
        EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
        EVT_SET(LVarA, LVar0)
        EVT_CALL(base_GiveRefund)
        EVT_WAIT(LVar0)
        EVT_WAIT(15)
        EVT_CALL(base_GiveRefundCleanup)
        EVT_CALL(RemoveItemEntity, LVarA)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_208D)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_WAIT(4)
        EVT_ADD(LVar1, 45)
        EVT_SET(LVar3, LVar1)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar3, 2)
        EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
        EVT_SET(LVarA, LVar0)
        EVT_WAIT(15)
        EVT_CALL(RemoveItemEntity, LVarA)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript D_80287708 = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -85, 1, 0)
    EVT_CALL(SetBattleCamOffsetZ, 41)
    EVT_CALL(SetBattleCamZoom, 248)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 45)
    EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
    EVT_SET(LVarE, LVar0)
    EVT_CALL(base_GiveRefund)
    EVT_WAIT(LVar0)
    EVT_WAIT(15)
    EVT_CALL(base_GiveRefundCleanup)
    EVT_CALL(RemoveItemEntity, LVarE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80287834 = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript PlayEatFX = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2095)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Eat)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript PlayDrinkFX = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2095)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Drink)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript UseLifeShroom = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CHILD_THREAD
        EVT_CALL(func_80261388)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(DispatchEvent, ACTOR_PARTNER, EVENT_LIFE_SHROOM_PROC)
            EVT_CALL(SetActorFlagBits, ACTOR_PARTNER, ACTOR_FLAG_NO_SHADOW, 1)
            EVT_SET(LVar0, 255)
            EVT_LOOP(10)
                EVT_SUB(LVar0, 25)
                EVT_IF_LT(LVar0, 0)
                    EVT_SET(LVar0, 0)
                EVT_END_IF
                EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 0)
        EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CALL(func_802610CC)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(MakeItemEntity, ITEM_LIFE_SHROOM, LVar0, LVar1, LVar2, 1, 0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, 30)
    EVT_SET(LVar4, 16)
    EVT_LOOP(LVar3)
        EVT_ADD(LVar4, 8)
        EVT_IF_GT(LVar4, 255)
            EVT_SET(LVar4, 255)
        EVT_END_IF
        EVT_ADDF(LVar1, EVT_FLOAT(1.0))
        EVT_CALL(SetItemPos, LVarA, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar3, LVar0)
    EVT_SET(LVar4, LVar1)
    EVT_SET(LVar5, LVar2)
    EVT_CALL(func_802613A8)
    EVT_CALL(base_GiveRefund)
    EVT_IF_GT(LVar0, 0)
        EVT_WAIT(LVar0)
        EVT_WAIT(15)
        EVT_CALL(base_GiveRefundCleanup)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_372)
    EVT_ADD(LVar4, 15)
    EVT_CALL(PlayEffect, EFFECT_ENERGY_IN_OUT, 3, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_SET(LVar0, LVarF)
    EVT_LOOP(4)
        EVT_CALL(SetItemFlags, LVarA, 64, 1)
        EVT_WAIT(2)
        EVT_CALL(SetItemFlags, LVarA, 64, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2055)
    EVT_CALL(PlayEffect, EFFECT_STARS_SHIMMER, 1, LVar3, LVar4, LVar5, 70, 70, 10, 20, 0, 0, 0, 0, 0)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_373)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_STARS_SHIMMER, 2, LVar0, LVar1, LVar2, 50, 20, 32, 30, 0, 0, 0, 0, 0)
    EVT_WAIT(40)
    EVT_CALL(PlayEffect, EFFECT_STARS_SHIMMER, 2, LVar0, LVar1, LVar2, 30, 50, 32, 30, 0, 0, 0, 0, 0)
    EVT_CHILD_THREAD
        EVT_LOOP(3)
            EVT_CALL(SetActorDispOffset, ACTOR_PLAYER, 1, 0, 0)
            EVT_WAIT(4)
            EVT_CALL(SetActorDispOffset, ACTOR_PLAYER, -1, 0, 0)
            EVT_WAIT(4)
        EVT_END_LOOP
        EVT_LOOP(3)
            EVT_CALL(SetActorDispOffset, ACTOR_PLAYER, 1, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(SetActorDispOffset, ACTOR_PLAYER, -1, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
        EVT_LOOP(7)
            EVT_CALL(SetActorDispOffset, ACTOR_PLAYER, 1, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PLAYER, -1, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_WAIT(50)
    EVT_CHILD_THREAD
        EVT_CALL(func_80261164)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_374)
    EVT_CALL(SetActorRotation, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(ConsumeLifeShroom)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(PlayEffect, EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(FreezeBattleCam, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CHILD_THREAD
        EVT_CALL(func_80261388)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(SetActorFlagBits, ACTOR_PARTNER, ACTOR_FLAG_NO_SHADOW, 0)
            EVT_SET(LVar0, 0)
            EVT_LOOP(10)
                EVT_ADD(LVar0, 25)
                EVT_IF_GT(LVar0, 255)
                    EVT_SET(LVar0, 255)
                EVT_END_IF
                EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(DispatchEvent, ACTOR_PARTNER, EVENT_REVIVE)
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 255)
        EVT_END_IF
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_LOOP(5)
            EVT_WAIT(2)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(PlayEffect, EFFECT_MISC_PARTICLES, 2, LVar0, LVar1, LVar2, 20, 20, EVT_FLOAT(1.0), 10, 50, 0, 0, 0, 0)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_160)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(RestorePreDefeatState)
    EVT_RETURN
    EVT_END
};

EvtScript MerleeRunOut = {
    EVT_CALL(HasMerleeCastsLeft)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(ShowMessageBox, 3, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

EvtScript MerleeAttackBonus = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(BattleMerleeFadeStageToBlack)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 0, 80, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 246)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, -10, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_40000, TRUE)
    EVT_CALL(SetNpcRenderMode, -10, 34)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleMerleeUpdateFX)
    EVT_END_CHILD_THREAD
    EVT_CALL(BattleFadeInMerlee)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    EVT_CALL(func_802619B4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 4)
    EVT_CALL(BattleMerleeFadeStageFromBlack)
    EVT_WAIT(20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleFadeOutMerlee)
        EVT_CALL(DeleteNpc, -10)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2075)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 18, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario_10002)
    EVT_CALL(ShowMessageBox, 0, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(MerleeRunOut)
    EVT_RETURN
    EVT_END
};

EvtScript MerleeDefenseBonus = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(BattleMerleeFadeStageToBlack)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 0, 80, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 246)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, -10, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_40000, TRUE)
    EVT_CALL(SetNpcRenderMode, -10, 34)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleMerleeUpdateFX)
    EVT_END_CHILD_THREAD
    EVT_CALL(BattleFadeInMerlee)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    EVT_CALL(func_802619B4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 4)
    EVT_CALL(BattleMerleeFadeStageFromBlack)
    EVT_WAIT(20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleFadeOutMerlee)
        EVT_CALL(DeleteNpc, -10)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2075)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, 0x0035D000)
        EVT_WAIT(22)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 18, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario_10002)
    EVT_END_IF
    EVT_CALL(ShowMessageBox, 1, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(MerleeRunOut)
    EVT_RETURN
    EVT_END
};

EvtScript MerleeExpBonus = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(BattleMerleeFadeStageToBlack)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 0, 80, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 246)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, -10, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_40000, TRUE)
    EVT_CALL(SetNpcRenderMode, -10, 34)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleMerleeUpdateFX)
    EVT_END_CHILD_THREAD
    EVT_CALL(BattleFadeInMerlee)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    EVT_CALL(func_802619B4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 4)
    EVT_CALL(BattleMerleeFadeStageFromBlack)
    EVT_WAIT(20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleFadeOutMerlee)
        EVT_CALL(DeleteNpc, -10)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_2075)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 18, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10009)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario_10002)
    EVT_CALL(ShowMessageBox, 2, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(MerleeRunOut)
    EVT_RETURN
    EVT_END
};

EvtScript PlayerHappy = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(UseBattleCamPresetWait, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_ThumbsUp)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_802619E8, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 35)
    EVT_SET(LVar3, LVarA)
    EVT_ADD(LVar3, LVarB)
    EVT_IF_GT(LVar3, 0)
        EVT_CALL(FXRecoverHP, LVar0, LVar1, LVar2, LVar3)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 25)
    EVT_IF_GT(LVarC, 0)
        EVT_CALL(FXRecoverFP, LVar0, LVar1, LVar2, LVarC)
    EVT_END_IF
    EVT_SET(LVar3, LVarA)
    EVT_ADD(LVar3, LVarB)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
    EVT_WAIT(10)
    EVT_SET(LVar0, LVarA)
    EVT_IF_GT(LVar0, 0)
        EVT_LOOP(LVar0)
            EVT_CALL(IncrementPlayerHP)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_SET(LVar0, LVarB)
    EVT_IF_GT(LVar0, 0)
        EVT_LOOP(LVar0)
            EVT_CALL(IncrementPlayerHP)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_SET(LVar0, LVarC)
    EVT_IF_GT(LVar0, 0)
        EVT_LOOP(LVar0)
            EVT_CALL(IncrementPlayerFP)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario_10002)
    EVT_CALL(func_80261B40)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript DoDizzyAttack = {
    EVT_SET(LVar0, 0)
    EVT_LOOP(40)
        EVT_ADD(LVar0, 72)
        EVT_CALL(SetActorRotation, ACTOR_ENEMY0, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(func_80261D98)
    EVT_CALL(SetActorRotation, ACTOR_ENEMY0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};


EvtScript RegainAbility = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVarF, LVar1, LVar2)
    EVT_LOOP(LVar0)
        EVT_ADD(LVarF, 3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(func_80261DD4)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(2)
            EVT_SET(LVarE, 0)
            EVT_SET(LVarA, ITEM_ITEMS_ICON)
        EVT_CASE_EQ(1)
            EVT_SET(LVarE, 1)
            EVT_SWITCH(LVarC)
                EVT_CASE_EQ(0)
                    EVT_SET(LVarA, ITEM_HAMMER1_ICON)
                EVT_CASE_EQ(1)
                    EVT_SET(LVarA, ITEM_HAMMER2_ICON)
                EVT_CASE_EQ(2)
                    EVT_SET(LVarA, ITEM_HAMMER3_ICON)
            EVT_END_SWITCH
        EVT_CASE_EQ(0)
            EVT_SET(LVarE, 2)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(0)
                    EVT_SET(LVarA, ITEM_BOOTS1_ICON)
                EVT_CASE_EQ(1)
                    EVT_SET(LVarA, ITEM_BOOTS2_ICON)
                EVT_CASE_EQ(2)
                    EVT_SET(LVarA, ITEM_BOOTS3_ICON)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVarF, 24)
    EVT_ADD(LVar1, 150)
    EVT_CALL(MakeItemEntity, LVarA, LVarF, LVar1, LVar2, 1, 0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(func_80261DF4)
    EVT_CALL(func_802620F8)
    EVT_CALL(func_80261FB4)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlayEffect, EFFECT_STARS_SHIMMER, 0, LVar0, LVar1, LVar2, 30, 30, 10, 30, 0, 0, 0, 0, 0)
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_CALL(func_8026BF48, 0)
    EVT_RETURN
    EVT_END
};
