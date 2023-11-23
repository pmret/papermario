#include "common.h"
#include "effects.h"
#include "model.h"
#include "hud_element.h"
#include "script_api/battle.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/BattleMerlee.h"
#include "battle/action_cmd/flee.h"
#include "battle/battle.h"
#include "sprite/player.h"

extern HudScript HES_Happy;
extern HudScript HES_HPDrain;

extern EvtScript EVS_Player_Celebrate;
extern EvtScript EVS_Player_SimpleHit;
extern EvtScript EVS_Player_ComplexHit;
extern EvtScript EVS_Player_NoDamageHit;

extern PlayerCelebrationAnimOptions bPlayerCelebrations;

BSS s32 D_8029FB90;
BSS f32 D_8029FB94;
BSS EffectInstance* BattleMerleeOrbEffect;
BSS EffectInstance* BattleMerleeWaveEffect;
BSS s32 RefundHudElem;
BSS s16 D_8029FBA4;
BSS s32 D_8029FBA8;
BSS s32 D_8029FBAC;
BSS s32 D_8029FBB0[3];

API_CALLABLE(ForceDisablePlayerBlurImmediately);

void btl_set_player_idle_anims(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorPart* actorPart = &battleStatus->playerActor->partsTable[0];

    if (battleStatus->flags2 & BS_FLAGS2_PEACH_BATTLE) {
        actorPart->idleAnimations = bPeachIdleAnims;
        set_actor_anim(0, 0, ANIM_Peach1_Walk);
    } else if (!battleStatus->outtaSightActive) {
        actorPart->idleAnimations = bMarioIdleAnims;
    }
}

API_CALLABLE(IsPartnerImmobile) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    s32 isImmobile = playerActor->debuff == STATUS_KEY_FEAR
                     || playerActor->debuff == STATUS_KEY_DIZZY
                     || playerActor->debuff == STATUS_KEY_PARALYZE
                     || playerActor->debuff == STATUS_KEY_SLEEP
                     || playerActor->debuff == STATUS_KEY_FROZEN
                     || playerActor->debuff == STATUS_KEY_STOP;

    if (playerActor->stoneStatus == STATUS_KEY_STONE) {
        isImmobile = TRUE;
    }

    script->varTable[0] = isImmobile;
    return ApiStatus_DONE2;
}

API_CALLABLE(ActivateDefend) {
    ActorPart* actorPart = &gBattleStatus.playerActor->partsTable[0];

    deduct_current_move_fp();
    gBattleStatus.flags1 |= BS_FLAGS1_PLAYER_DEFENDING;
    actorPart->idleAnimations = bMarioDefendAnims;
    set_actor_anim(0, 0, ANIM_Mario1_Crouch);
    return ApiStatus_DONE2;
}

// (out) LVar0: skip playing lucky animation
API_CALLABLE(TryPlayerLucky) {
    Actor* player = gBattleStatus.playerActor;

    show_action_rating(ACTION_RATING_LUCKY, player, player->curPos.x, player->curPos.y + 20.0f, player->curPos.z);
    sfx_play_sound(SOUND_LUCKY);
    
    script->varTable[0] = FALSE;
    if (player->debuff == STATUS_KEY_FEAR
        || player->debuff == STATUS_KEY_DIZZY
        || player->debuff == STATUS_KEY_PARALYZE
        || player->debuff == STATUS_KEY_SLEEP
        || player->debuff == STATUS_KEY_FROZEN
        || player->debuff == STATUS_KEY_STOP
    ) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(ChoosePlayerCelebrationAnim) {
    PlayerCelebrationAnimOptions* pcao = &bPlayerCelebrations;
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

API_CALLABLE(SetFledBattleFlag) {
    gBattleStatus.flags1 |= BS_FLAGS1_BATTLE_FLED;
    return ApiStatus_DONE2;
}

API_CALLABLE(DetermineAutoRunAwaySuccess) {
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

API_CALLABLE(func_80260E38) {
    btl_show_battle_message(BTL_MSG_ACTION_TIP_MASH_BUTTON, 60);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80260E5C) {
    gBattleStatus.flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    gBattleStatus.flags1 &= ~BS_FLAGS1_2000;
    gBattleStatus.flags1 &= ~BS_FLAGS1_4000;
    return ApiStatus_DONE2;
}

// out LVar0: time caller should wait for coin spawns
API_CALLABLE(GiveRefund) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 sellValue = gItemTable[battleStatus->moveArgument].sellValue;
    f32 angle = 0.0f;
    s32 delayTime = 0;
    f32 posX, posY, posZ;
    posY = player->curPos.y + player->size.y;

    if (player_team_is_ability_active(player, ABILITY_REFUND) && sellValue > 0) {
        s32 i;
        s32 iconPosX, iconPosY, iconPosZ;

        // 75% of the item's sell value, rounded up
        sellValue = (sellValue * 75 + 99) / 100;

        for (i = 0; i < sellValue; i++) {
            posX = player->curPos.x;
            posZ = player->curPos.z;

            make_item_entity(ITEM_COIN, posX, posY, posZ, ITEM_SPAWN_MODE_TOSS_FADE1, (i * 3) + 1, angle, 0);
            add_coins(1);
            angle += 30.0f;
        }

        delayTime = (i * 3) + 30;

        posX = player->curPos.x;
        posY = player->curPos.y;
        posZ = player->curPos.z;
        get_screen_coords(gCurrentCameraID, posX, posY, posZ, &iconPosX, &iconPosY, &iconPosZ);
        RefundHudElem = hud_element_create(&HES_Refund);
        hud_element_set_render_pos(RefundHudElem, iconPosX + 36, iconPosY - 63);
    }

    script->varTable[0] = delayTime;

    return ApiStatus_DONE2;
}

API_CALLABLE(GiveRefundCleanup) {
    s32 sellValue = gItemTable[gBattleStatus.moveArgument].sellValue;

    if (player_team_is_ability_active(gBattleStatus.playerActor, ABILITY_REFUND) && sellValue > 0) {
        hud_element_free(RefundHudElem);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(LifeShroomShroudWorld) {
    if (isInitialCall) {
        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        script->functionTemp[0] = 20;
    }

    mdl_set_shroud_tint_params(0, 0, 0, ((20 - script->functionTemp[0]) * 12) & 0xFC);

    script->functionTemp[0] -= 1;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    }
    
    return ApiStatus_BLOCK;
}

API_CALLABLE(LifeShroomRevealWorld) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
        btl_cam_unfreeze();
    }

    mdl_set_shroud_tint_params(0, 0, 0, (script->functionTemp[0] * 12) & 0xFC);

    script->functionTemp[0] -= 1;
    if (script->functionTemp[0] == 0) {
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }
    
    return ApiStatus_BLOCK;
}

API_CALLABLE(ConsumeLifeShroom) {
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

API_CALLABLE(RestorePreDefeatState) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;

    gBattleState = gDefeatedBattleState;
    gBattleSubState = gDefeatedBattleSubstate;
    battleStatus->flags1 |= BS_FLAGS1_SHOW_PLAYER_DECORATIONS;

    // clear rush flags to initialize
    battleStatus->rushFlags = RUSH_FLAG_NONE;
    battleStatus->flags2 &= ~BS_FLAGS2_HAS_RUSH;

    // set rush flags based on danger/peril status
    if (!(battleStatus->flags2 & BS_FLAGS2_PEACH_BATTLE)) {
        if (playerData->curHP <= PERIL_THRESHOLD && is_ability_active(ABILITY_MEGA_RUSH)) {
            gBattleStatus.flags2 |= BS_FLAGS2_HAS_RUSH;
            battleStatus->rushFlags |= RUSH_FLAG_MEGA;
        }

        if (playerData->curHP <= DANGER_THRESHOLD && is_ability_active(ABILITY_POWER_RUSH)) {
            if (!(battleStatus->rushFlags & RUSH_FLAG_MEGA)) {
                gBattleStatus.flags2 |= BS_FLAGS2_HAS_RUSH;
                battleStatus->rushFlags |= RUSH_FLAG_POWER;
            }
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80261388) {
    s32 partnerActorExists = gBattleStatus.partnerActor != NULL;

    script->varTable[0] = FALSE;
    if (partnerActorExists) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SetItemAsLifeShroom) {
    gBattleStatus.moveArgument = ITEM_LIFE_SHROOM;
    return ApiStatus_DONE2;
}

API_CALLABLE(PlayBattleMerleeGatherFX) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_energy_in_out(6, var1, var2 + 15, var3, 1.2f, 30);
    return ApiStatus_DONE2;
}

API_CALLABLE(PlayBattleMerleeOrbFX) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_energy_orb_wave(9, var1, var2 + 15, var3, 5.0f, 15);
    return ApiStatus_DONE2;
}

API_CALLABLE(BattleMerleeFadeStageToBlack) {
    if (isInitialCall) {
        mdl_set_all_tint_type(ENV_TINT_SHROUD);
        *gBackgroundTintModePtr = ENV_TINT_SHROUD;
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        script->functionTemp[0] = 25;
    }

    mdl_set_shroud_tint_params(0, 0, 0, ((25 - script->functionTemp[0]) * 10) & 254);
    script->functionTemp[0]--;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(BattleMerleeFadeStageFromBlack) {
    if (isInitialCall) {
        script->functionTemp[0] = 25;
    }

    mdl_set_shroud_tint_params(0, 0, 0, (script->functionTemp[0] * 10) & 0xFF);

    script->functionTemp[0] -= 5;
    if (script->functionTemp[0] == 0) {
        mdl_set_shroud_tint_params(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleFadeInMerlee) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);

    if (isInitialCall) {
        sfx_play_sound(SOUND_MERLEE_APPEAR);
        merlee->alpha = 0;
    }

    merlee->alpha += 17;
    if (merlee->alpha >= 255) {
        merlee->alpha = 255;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleFadeOutMerlee) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);

    merlee->alpha -= 17;
    if (merlee->alpha == 0) {
        merlee->alpha = 0;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(BattleMerleeUpdateFX) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);
    EnergyOrbWaveFXData* data;

    if (isInitialCall) {
        script->functionTemp[1] = 0;
        D_8029FB94 = merlee->pos.y;
        BattleMerleeOrbEffect = fx_energy_orb_wave(0, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.4f, 0);
        BattleMerleeWaveEffect = fx_energy_orb_wave(3, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.00001f, 0);
        D_8029FBA4 = 0;
        D_8029FB90 = 12;
        sfx_play_sound(SOUND_MAGIC_ASCENDING);
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
        BattleMerleeOrbEffect->flags |= FX_INSTANCE_FLAG_DISMISS;
        BattleMerleeWaveEffect->flags |= FX_INSTANCE_FLAG_DISMISS;
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

API_CALLABLE(func_802619B4) {
    D_8029FBA4 = 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(HasMerleeCastsLeft) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = FALSE;
    if (playerData->merleeCastsLeft > 0) {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SpawnTurnEndFX) {
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

API_CALLABLE(RemoveTurnEndFX) {
    if (script->varTable[10] > 0) {
        hud_element_free(D_8029FBAC);
    }
    if (script->varTable[11] > 0 || script->varTable[12] > 0) {
        hud_element_free(D_8029FBA8);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SpawnRecoverHeartFX) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_recover(0, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

API_CALLABLE(SpawnRecoverFlowerFX) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_recover(1, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

API_CALLABLE(IncrementPlayerHP) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP++;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(IncrementPlayerFP) {
    PlayerData* playerData = &gPlayerData;

    playerData->curFP++;
    if (playerData->curFP > playerData->curMaxFP) {
        playerData->curFP = playerData->curMaxFP;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(InflictDizzyAttackStatus) {
    inflict_status_set_duration(get_actor(script->owner1.actorID), STATUS_KEY_DIZZY, 0, 1);
    btl_update_ko_status();
    return ApiStatus_DONE2;
}

API_CALLABLE(GetLostHammerAndBootsLevel) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[11] = playerData->bootsLevel;
    script->varTable[12] = playerData->hammerLevel;
    return ApiStatus_DONE2;
}

API_CALLABLE(DropAbilityItem) {
    ItemEntity* item = get_item_entity(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 0;
    }

    switch (script->functionTemp[1]) {
        case 0:
            script->functionTemp[0]--;
            item->pos.y += script->functionTemp[0];
            if (item->pos.y < 0.0f) {
                item->pos.y = 0.0f;
                script->functionTemp[0] = 8;
                script->functionTemp[1] = 1;
            }
            break;
        case 1:
            script->functionTemp[0]--;
            item->pos.y += script->functionTemp[0];
            item->pos.x += 1.5;
            if (item->pos.y < 0.0f) {
                item->pos.y = 0.0f;
                script->functionTemp[0] = 4;
                script->functionTemp[1] = 2;
            }
            break;
        case 2:
            script->functionTemp[0]--;
            item->pos.y += script->functionTemp[0];
            item->pos.x += 1.2;
            if (item->pos.y < 0.0f) {
                item->pos.y = 0.0f;
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

API_CALLABLE(PlayerGatherAbilityItem) {
    ItemEntity* item = get_item_entity(script->varTable[10]);
    Actor* player = gBattleStatus.playerActor;
    s32 interpAmt;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 10;
    }

    switch (script->functionTemp[0]) {
        case 0:
            interpAmt = script->functionTemp[1];
            deltaX = player->curPos.x - item->pos.x;
            deltaY = player->curPos.y + 12.0f - item->pos.y;
            deltaZ = player->curPos.z - 5.0f - item->pos.z;

            item->pos.x += deltaX / interpAmt;
            item->pos.y += deltaY / interpAmt;
            item->pos.z += deltaZ / interpAmt;

            item->pos.y += dist2D(item->pos.x, item->pos.y, player->curPos.x,
                                       player->curPos.y + 12.0f) / 5.0f;

            if (script->functionTemp[1] == 1) {
                script->functionTemp[0] = 1;
            }

            script->functionTemp[1]--;
            break;
        case 1:
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(AbilityItemUnkDelay) {
    s32* delayCounter = &D_8029FBB0[script->varTable[14]];

    if (*delayCounter != 0) {
        (*delayCounter)--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

EvtScript EVS_Mario_OnActorCreate = {
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Peach_OnActorCreate = {
    EVT_RETURN
    EVT_END
};

EvtScript EVS_MarioEnterStage = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ENTRY)
    EVT_CALL(SetBattleCamTarget, -80, 35, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 100)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RandInt, 100, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(50)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Run)
            EVT_CALL(PlayerRunToGoal, 25)
            EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
        EVT_CASE_GT(20)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_BeforeJump)
            EVT_CALL(func_80273444, 18, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
            EVT_WAIT(7)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
            EVT_CALL(PlayerRunToGoal, 20)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_CHILD_THREAD
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
            EVT_END_CHILD_THREAD
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TRIP)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PeachEnterStage = {
    EVT_CALL(FreezeBattleState, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_ENTRY)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Peach1_Run)
    EVT_CALL(PlayerRunToGoal, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Peach1_Walk)
    EVT_WAIT(15)
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Mario_HandlePhase = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(EVS_ExecuteMarioAction)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(EVS_PlayerFirstStrike)
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(EVS_Player_Celebrate)
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(EVS_RunAwayStart)
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(EVS_RunAwayFail)
        EVT_CASE_EQ(PHASE_DEATH)
            EVT_EXEC_WAIT(EVS_PlayerDies)
        EVT_CASE_EQ(PHASE_USE_LIFE_SHROOM)
            EVT_EXEC_WAIT(EVS_UseLifeShroom)
        EVT_CASE_EQ(PHASE_USE_DEFEND)
            EVT_EXEC_WAIT(EVS_StartDefend)
        EVT_CASE_EQ(PHASE_MERLEE_ATTACK_BONUS)
            EVT_EXEC_WAIT(EVS_MerleeAttackBonus)
        EVT_CASE_EQ(PHASE_MERLEE_DEFENSE_BONUS)
            EVT_EXEC_WAIT(EVS_MerleeDefenseBonus)
        EVT_CASE_EQ(PHASE_MERLEE_EXP_BONUS)
            EVT_EXEC_WAIT(EVS_MerleeExpBonus)
        EVT_CASE_EQ(PHASE_PLAYER_HAPPY)
            EVT_EXEC_WAIT(EVS_PlayerHappy)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Peach_HandlePhase = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(EVS_ExecutePeachAction)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ExecuteMarioAction = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(BTL_MENU_TYPE_JUMP)
            EVT_CALL(LoadMoveScript)
            EVT_EXEC_WAIT(LVar0)
        EVT_CASE_EQ(BTL_MENU_TYPE_SMASH)
            EVT_CALL(LoadMoveScript)
            EVT_EXEC_WAIT(LVar0)
        EVT_CASE_EQ(BTL_MENU_TYPE_ITEMS)
            EVT_CALL(LoadItemScript)
            EVT_EXEC_WAIT(LVar0)
        EVT_CASE_EQ(BTL_MENU_TYPE_STAR_POWERS)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
    EVT_END_SWITCH
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ExecutePeachAction = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(BTL_MENU_TYPE_STAR_POWERS)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayerFirstStrike = {
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
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_StartDefend = {
    EVT_CALL(ActivateDefend)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Player_HandleEvent = {
    EVT_CALL(GetLastEvent, ACTOR_PLAYER, LVarF)
    EVT_SWITCH(LVarF)
        EVT_CASE_NE(EVENT_32)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_END_SWITCH
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    EVT_CALL(func_802693F0)
    EVT_CALL(ForceDisablePlayerBlurImmediately)
    EVT_CALL(GetLastEvent, ACTOR_PLAYER, LVarF)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_OR_EQ(EVENT_SPIKE_DEATH)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HIT_SPIKE)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 5, 0, 1)
            EVT_SET_CONST(LVar1, ANIM_Mario1_HurtFoot)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(EVS_Player_SimpleHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HIT_HAZARD)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_BurnHurt, ANIM_MarioB3_BurnHurt, ANIM_MarioB3_BurnHurt)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 5, 0, 1)
            EVT_CHILD_THREAD
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar5, LVar6, LVar7)
                EVT_ADD(LVar5, 5)
                EVT_ADD(LVar6, 4)
                EVT_ADD(LVar7, 5)
                EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.5), 15)
                EVT_WAIT(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar5, LVar6, LVar7)
                EVT_ADD(LVar5, -5)
                EVT_ADD(LVar6, 18)
                EVT_ADD(LVar7, 5)
                EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, EVT_FLOAT(1.5), 15)
            EVT_END_CHILD_THREAD
            EVT_SET_CONST(LVar1, ANIM_MarioB3_BurnHurt)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(EVS_Player_SimpleHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PLAYER_HIT_HAZARD)
            EVT_CALL(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_ADD(LVar1, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.1))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 5, 0, 1)
            EVT_CALL(ShowShockEffect, ACTOR_SELF)
            EVT_SET_CONST(LVar1, ANIM_Mario1_HurtFoot)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(EVS_Player_SimpleHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
            EVT_CALL(TryPlayerLucky)
            EVT_IF_FALSE(LVar0)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_AdjustCap)
                EVT_WAIT(30)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_ELSE
                EVT_WAIT(30)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 15, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
            EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
            EVT_CALL(PlayerRunToGoal, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CASE_EQ(EVENT_32)
            EVT_WAIT(10)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(func_80273444, 15, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
            EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
            EVT_CALL(PlayerRunToGoal, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_Mario1_Hurt)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(EVS_Player_ComplexHit)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_NO_DAMGE)
            EVT_SET_CONST(LVar1, ANIM_Mario1_Idle)
            EVT_EXEC_WAIT(EVS_Player_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_NO_DAMGE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Mario1_Crouch)
            EVT_EXEC_WAIT(EVS_Player_NoDamageHit)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_MarioB3_BurnHurt)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(EVS_Player_SimpleHit)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CASE_EQ(EVENT_FIRE_DEATH)
            EVT_SET_CONST(LVar1, ANIM_MarioB3_BurnHurt)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(EVS_Player_SimpleHit)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_Mario1_Hurt)
            EVT_SET(LVar2, 0)
            EVT_EXEC_WAIT(EVS_Player_SimpleHit)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
            EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_BeforeJump)
            EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
            EVT_CALL(func_80273444, 15, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_Player_Celebrate = {
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

EvtScript EVS_RunAwayNoCommand = {
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hustled)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_IN_PLACE)
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
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 8, 0, 0)
    EVT_CALL(DetermineAutoRunAwaySuccess)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetFledBattleFlag)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_AWAY)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -240, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(16.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(5)
    EVT_ELSE
        EVT_CHILD_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_CHILD_THREAD
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Trip)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TRIP)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -100, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(10.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_SET(LVar3, 6)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CHILD_THREAD
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0))
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
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
        EVT_CHILD_THREAD
            EVT_WAIT(7)
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 8)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 5)
                EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(5)
            EVT_END_LOOP
        EVT_END_CHILD_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_RunAwayStart = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(GetActionCommandMode, LVar2)
    EVT_IF_EQ(LVar2, ACTION_COMMAND_MODE_NOT_LEARNED)
        EVT_EXEC_WAIT(EVS_RunAwayNoCommand)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowActionHud, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_FLEE)
    EVT_CALL(action_command_flee_init, LVar0)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(func_80260E38)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hustled)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_IN_PLACE)
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
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(5)
    EVT_CALL(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    EVT_WAIT(15)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 8, 0, 0)
    EVT_CALL(GetActionSuccess, LVar0)
    EVT_CALL(DetermineAutoRunAwaySuccess)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetFledBattleFlag)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_AWAY)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -240, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(16.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(5)
    EVT_ELSE
        EVT_CHILD_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_CHILD_THREAD
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Trip)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TRIP)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, -100, 0, 10)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(10.0))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_SET(LVar3, 6)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CHILD_THREAD
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0))
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
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
        EVT_CHILD_THREAD
            EVT_WAIT(7)
            EVT_LOOP(2)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 8)
                EVT_ADD(LVar1, 14)
                EVT_ADD(LVar2, 5)
                EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(5)
            EVT_END_LOOP
        EVT_END_CHILD_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_RunAwayFail = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayerDies = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Dying)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_24)
    EVT_WAIT(15)
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_SPINNING)
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
    EVT_CALL(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_COLLAPSE)
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
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript D_80287404 = {
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_ADD(LVar1, 45)
        EVT_SET(LVar3, LVar1)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar3, 2)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 30)
        EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
        EVT_SET(LVarA, LVar0)
        EVT_CALL(GiveRefund)
        EVT_WAIT(LVar0)
        EVT_WAIT(15)
        EVT_CALL(GiveRefundCleanup)
        EVT_CALL(RemoveItemEntity, LVarA)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_WAIT(4)
        EVT_ADD(LVar1, 45)
        EVT_SET(LVar3, LVar1)
        EVT_ADD(LVar3, 10)
        EVT_ADD(LVar3, 2)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, EVT_FLOAT(1.0), 30)
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
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 45)
    EVT_CALL(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
    EVT_SET(LVarE, LVar0)
    EVT_CALL(GiveRefund)
    EVT_WAIT(LVar0)
    EVT_WAIT(15)
    EVT_CALL(GiveRefundCleanup)
    EVT_CALL(RemoveItemEntity, LVarE)
    EVT_RETURN
    EVT_END
};

EvtScript D_80287834 = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayEatFX = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Eat)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayDrinkFX = {
    EVT_THREAD
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Drink)
    EVT_WAIT(45)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_UseLifeShroom = {
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
    EVT_CALL(LifeShroomShroudWorld)
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
    EVT_CALL(SetItemAsLifeShroom)
    EVT_CALL(GiveRefund)
    EVT_IF_GT(LVar0, 0)
        EVT_WAIT(LVar0)
        EVT_WAIT(15)
        EVT_CALL(GiveRefundCleanup)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LIFE_SHROOM_CHIME)
    EVT_ADD(LVar4, 15)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 3, LVar3, LVar4, LVar5, EVT_FLOAT(1.0))
    EVT_SET(LVar0, LVarF)
    EVT_LOOP(4)
        EVT_CALL(SetItemFlags, LVarA, 64, 1)
        EVT_WAIT(2)
        EVT_CALL(SetItemFlags, LVarA, 64, 0)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_CALL(RemoveEffect, LVar0)
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_START_RECOVERY)
    EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 1, LVar3, LVar4, LVar5, 70, 70, 10, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_REVIVAL_MAGIC)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 2, LVar0, LVar1, LVar2, 50, 20, 32, 30)
    EVT_WAIT(40)
    EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 2, LVar0, LVar1, LVar2, 30, 50, 32, 30)
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
        EVT_CALL(LifeShroomRevealWorld)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_REVIVE)
    EVT_CALL(SetActorRotation, ACTOR_PLAYER, 0, 0, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(ConsumeLifeShroom)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(FreezeBattleCam, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
            EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 2, LVar0, LVar1, LVar2, 20, 20, EVT_FLOAT(1.0), 10, 50)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(RestorePreDefeatState)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_MerleeRunOut = {
    EVT_CALL(HasMerleeCastsLeft)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(ShowMessageBox, BTL_MSG_MERLEE_DONE, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_MerleeAttackBonus = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(BattleMerleeFadeStageToBlack)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 0, 80, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 246)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CALL(SetNpcRenderMode, NPC_BTL_MERLEE, 34)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleMerleeUpdateFX)
    EVT_END_CHILD_THREAD
    EVT_CALL(BattleFadeInMerlee)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    EVT_CALL(func_802619B4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 4)
    EVT_CALL(BattleMerleeFadeStageFromBlack)
    EVT_WAIT(20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleFadeOutMerlee)
        EVT_CALL(DeleteNpc, NPC_BTL_MERLEE)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MAGIC_DESCENDING)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 18, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    EVT_CALL(ShowMessageBox, BTL_MSG_MERLEE_ATK_UP, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(EVS_MerleeRunOut)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_MerleeDefenseBonus = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(BattleMerleeFadeStageToBlack)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 0, 80, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 246)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CALL(SetNpcRenderMode, NPC_BTL_MERLEE, 34)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleMerleeUpdateFX)
    EVT_END_CHILD_THREAD
    EVT_CALL(BattleFadeInMerlee)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    EVT_CALL(func_802619B4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 4)
    EVT_CALL(BattleMerleeFadeStageFromBlack)
    EVT_WAIT(20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleFadeOutMerlee)
        EVT_CALL(DeleteNpc, NPC_BTL_MERLEE)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MAGIC_DESCENDING)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_WAIT(22)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 18, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    EVT_END_IF
    EVT_CALL(ShowMessageBox, BTL_MSG_MERLEE_DEF_UP, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(EVS_MerleeRunOut)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_MerleeExpBonus = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(BattleMerleeFadeStageToBlack)
    EVT_WAIT(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 0, 80, 0)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(SetBattleCamZoom, 246)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CALL(SetNpcRenderMode, NPC_BTL_MERLEE, 34)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleMerleeUpdateFX)
    EVT_END_CHILD_THREAD
    EVT_CALL(BattleFadeInMerlee)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    EVT_CALL(func_802619B4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 4)
    EVT_CALL(BattleMerleeFadeStageFromBlack)
    EVT_WAIT(20)
    EVT_CHILD_THREAD
        EVT_CALL(BattleFadeOutMerlee)
        EVT_CALL(DeleteNpc, NPC_BTL_MERLEE)
    EVT_END_CHILD_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MAGIC_DESCENDING)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    EVT_CALL(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(func_80273444, 18, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    EVT_WAIT(4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    EVT_CALL(ShowMessageBox, BTL_MSG_MERLEE_EXP_UP, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(EVS_MerleeRunOut)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayerHappy = {
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(UseBattleCamPresetWait, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SpawnTurnEndFX, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 35)
    EVT_SET(LVar3, LVarA)
    EVT_ADD(LVar3, LVarB)
    EVT_IF_GT(LVar3, 0)
        EVT_CALL(SpawnRecoverHeartFX, LVar0, LVar1, LVar2, LVar3)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 25)
    EVT_IF_GT(LVarC, 0)
        EVT_CALL(SpawnRecoverFlowerFX, LVar0, LVar1, LVar2, LVarC)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    EVT_CALL(RemoveTurnEndFX)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_ApplyDizzyAttack = {
    EVT_SET(LVar0, 0)
    EVT_LOOP(40)
        EVT_ADD(LVar0, 72)
        EVT_CALL(SetActorRotation, ACTOR_ENEMY0, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(InflictDizzyAttackStatus)
    EVT_CALL(SetActorRotation, ACTOR_ENEMY0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayerRegainAbility = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVarF, LVar1, LVar2)
    EVT_LOOP(LVar0)
        EVT_ADD(LVarF, 3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetLostHammerAndBootsLevel)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(BTL_MENU_TYPE_ITEMS)
            EVT_SET(LVarE, 0)
            EVT_SET(LVarA, ITEM_MENU_ITEMS)
        EVT_CASE_EQ(BTL_MENU_TYPE_SMASH)
            EVT_SET(LVarE, 1)
            EVT_SWITCH(LVarC)
                EVT_CASE_EQ(0)
                    EVT_SET(LVarA, ITEM_MENU_HAMMER1)
                EVT_CASE_EQ(1)
                    EVT_SET(LVarA, ITEM_MENU_HAMMER2)
                EVT_CASE_EQ(2)
                    EVT_SET(LVarA, ITEM_MENU_HAMMER3)
            EVT_END_SWITCH
        EVT_CASE_EQ(BTL_MENU_TYPE_JUMP)
            EVT_SET(LVarE, 2)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(0)
                    EVT_SET(LVarA, ITEM_MENU_BOOTS1)
                EVT_CASE_EQ(1)
                    EVT_SET(LVarA, ITEM_MENU_BOOTS2)
                EVT_CASE_EQ(2)
                    EVT_SET(LVarA, ITEM_MENU_BOOTS3)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVarF, 24)
    EVT_ADD(LVar1, 150)
    EVT_CALL(MakeItemEntity, LVarA, LVarF, LVar1, LVar2, 1, 0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(DropAbilityItem)
    EVT_CALL(AbilityItemUnkDelay)
    EVT_CALL(PlayerGatherAbilityItem)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_STARS_SHIMMER, 0, LVar0, LVar1, LVar2, 30, 30, 10, 30)
    EVT_CALL(RemoveItemEntity, LVarA)
    EVT_CALL(FreezeBattleState, FALSE)
    EVT_RETURN
    EVT_END
};
