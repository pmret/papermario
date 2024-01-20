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
    Return
    End
};

EvtScript EVS_Peach_OnActorCreate = {
    Return
    End
};

EvtScript EVS_MarioEnterStage = {
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ENTRY)
    Call(SetBattleCamTarget, -80, 35, 8)
    Call(BattleCamTargetActor, ACTOR_PLAYER)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 100)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RandInt, 100, LVar0)
    Switch(LVar0)
        CaseGt(50)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Run)
            Call(PlayerRunToGoal, 25)
            Call(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
        CaseGt(20)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_BeforeJump)
            Call(func_80273444, 18, 0, 0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
            Wait(7)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        CaseDefault
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
            Call(PlayerRunToGoal, 20)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            ChildThread
                Call(ShakeCam, 1, 0, 5, Float(1.0))
            EndChildThread
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TRIP)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
            Wait(10)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
            Wait(10)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EndSwitch
    Return
    End
};

EvtScript EVS_PeachEnterStage = {
    Call(FreezeBattleState, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_PLAYER_ENTRY)
    Call(SetBattleCamTarget, -80, 35, 8)
    Call(BattleCamTargetActor, ACTOR_PLAYER)
    ChildThread
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Sub(LVar0, 100)
        Add(LVar1, 50)
        Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetAnimation, ACTOR_PARTNER, 0, ANIM_Twink_Angry)
        Call(FlyToGoal, ACTOR_PARTNER, 45, -10, 10)
    EndChildThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 100)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, 0, ANIM_Peach1_Run)
    Call(PlayerRunToGoal, 40)
    Call(SetAnimation, ACTOR_SELF, 0, ANIM_Peach1_Walk)
    Wait(15)
    Call(FreezeBattleState, FALSE)
    Return
    End
};

EvtScript EVS_Mario_HandlePhase = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(EVS_ExecuteMarioAction)
        CaseEq(PHASE_FIRST_STRIKE)
            ExecWait(EVS_PlayerFirstStrike)
        CaseEq(PHASE_CELEBRATE)
            ExecWait(EVS_Player_Celebrate)
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(EVS_RunAwayStart)
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(EVS_RunAwayFail)
        CaseEq(PHASE_DEATH)
            ExecWait(EVS_PlayerDies)
        CaseEq(PHASE_USE_LIFE_SHROOM)
            ExecWait(EVS_UseLifeShroom)
        CaseEq(PHASE_USE_DEFEND)
            ExecWait(EVS_StartDefend)
        CaseEq(PHASE_MERLEE_ATTACK_BONUS)
            ExecWait(EVS_MerleeAttackBonus)
        CaseEq(PHASE_MERLEE_DEFENSE_BONUS)
            ExecWait(EVS_MerleeDefenseBonus)
        CaseEq(PHASE_MERLEE_EXP_BONUS)
            ExecWait(EVS_MerleeExpBonus)
        CaseEq(PHASE_PLAYER_HAPPY)
            ExecWait(EVS_PlayerHappy)
    EndSwitch
    Return
    End
};

EvtScript EVS_Peach_HandlePhase = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(EVS_ExecutePeachAction)
    EndSwitch
    Return
    End
};

EvtScript EVS_ExecuteMarioAction = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_JUMP)
            Call(LoadMoveScript)
            ExecWait(LVar0)
        CaseEq(BTL_MENU_TYPE_SMASH)
            Call(LoadMoveScript)
            ExecWait(LVar0)
        CaseEq(BTL_MENU_TYPE_ITEMS)
            Call(LoadItemScript)
            ExecWait(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
    EndSwitch
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_ExecutePeachAction = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_PlayerFirstStrike = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(0)
            Call(LoadMoveScript)
            ExecWait(LVar0)
        CaseEq(1)
            Call(LoadMoveScript)
            ExecWait(LVar0)
    EndSwitch
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_StartDefend = {
    Call(ActivateDefend)
    Return
    End
};

EvtScript EVS_Player_HandleEvent = {
    Call(GetLastEvent, ACTOR_PLAYER, LVarF)
    Switch(LVarF)
        CaseNe(EVENT_32)
            Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EndSwitch
    Call(CloseActionCommandInfo)
    Call(SetBattleFlagBits, BS_FLAGS1_EXECUTING_MOVE, FALSE)
    Call(func_802693F0)
    Call(ForceDisablePlayerBlurImmediately)
    Call(GetLastEvent, ACTOR_PLAYER, LVarF)
    Switch(LVarF)
        CaseOrEq(EVENT_SPIKE_CONTACT)
        CaseOrEq(EVENT_SPIKE_DEATH)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(UseBattleCamPreset, BTL_CAM_PLAYER_HIT_SPIKE)
            Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 60)
            Add(LVar1, 40)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.1))
            Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 5, 0, 1)
            SetConst(LVar1, ANIM_Mario1_HurtFoot)
            Set(LVar2, 0)
            ExecWait(EVS_Player_SimpleHit)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToHome, ACTOR_PLAYER)
            Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.4))
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 10, 0, 2)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 7, 0, 2)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 4, 0, 2)
            IfEq(LVarF, 39)
                Return
            EndIf
        EndCaseGroup
        CaseOrEq(EVENT_BURN_CONTACT)
        CaseOrEq(EVENT_BURN_DEATH)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(UseBattleCamPreset, BTL_CAM_PLAYER_HIT_HAZARD)
            Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 60)
            Add(LVar1, 40)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.1))
            Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MarioB3_BurnHurt, ANIM_MarioB3_BurnHurt, ANIM_MarioB3_BurnHurt)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 5, 0, 1)
            ChildThread
                Call(GetActorPos, ACTOR_PLAYER, LVar5, LVar6, LVar7)
                Add(LVar5, 5)
                Add(LVar6, 4)
                Add(LVar7, 5)
                PlayEffect(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, Float(1.5), 15)
                Wait(2)
                Call(GetActorPos, ACTOR_PLAYER, LVar5, LVar6, LVar7)
                Add(LVar5, -5)
                Add(LVar6, 18)
                Add(LVar7, 5)
                PlayEffect(EFFECT_RING_BLAST, 0, LVar5, LVar6, LVar7, Float(1.5), 15)
            EndChildThread
            SetConst(LVar1, ANIM_MarioB3_BurnHurt)
            Set(LVar2, 0)
            ExecWait(EVS_Player_SimpleHit)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToHome, ACTOR_PLAYER)
            Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.4))
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 10, 0, 2)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 7, 0, 2)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 4, 0, 2)
            IfEq(LVarF, 36)
                Return
            EndIf
        EndCaseGroup
        CaseOrEq(EVENT_SHOCK_HIT)
        CaseOrEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(UseBattleCamPreset, BTL_CAM_PLAYER_HIT_HAZARD)
            Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 60)
            Add(LVar1, 40)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(0.1))
            Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot, ANIM_Mario1_HurtFoot)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 5, 0, 1)
            Call(ShowShockEffect, ACTOR_SELF)
            SetConst(LVar1, ANIM_Mario1_HurtFoot)
            Set(LVar2, 0)
            ExecWait(EVS_Player_SimpleHit)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToHome, ACTOR_PLAYER)
            Call(GetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.4))
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 10, 0, 2)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 7, 0, 2)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 4, 0, 2)
            IfEq(LVarF, 38)
                Return
            EndIf
        EndCaseGroup
        CaseEq(EVENT_LUCKY)
            Call(TryPlayerLucky)
            IfFalse(LVar0)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_AdjustCap)
                Wait(30)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            Else
                Wait(30)
            EndIf
        CaseEq(EVENT_RECOVER_STATUS)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
            Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 15, 0, 0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            Call(SetGoalToHome, ACTOR_PLAYER)
            Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
            Call(PlayerRunToGoal, 0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        CaseEq(EVENT_32)
            Wait(10)
            Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
            Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(func_80273444, 15, 0, 0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            Call(SetGoalToHome, ACTOR_PLAYER)
            Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
            Call(PlayerRunToGoal, 0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1, ANIM_Mario1_Hurt)
            Set(LVar2, 0)
            ExecWait(EVS_Player_ComplexHit)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_NO_DAMGE)
            SetConst(LVar1, ANIM_Mario1_Idle)
            ExecWait(EVS_Player_NoDamageHit)
        EndCaseGroup
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_NO_DAMGE)
            SetConst(LVar0, 1)
            SetConst(LVar1, ANIM_Mario1_Crouch)
            ExecWait(EVS_Player_NoDamageHit)
            Wait(10)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1, ANIM_MarioB3_BurnHurt)
            Set(LVar2, 0)
            ExecWait(EVS_Player_SimpleHit)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        CaseEq(EVENT_FIRE_DEATH)
            SetConst(LVar1, ANIM_MarioB3_BurnHurt)
            Set(LVar2, 0)
            ExecWait(EVS_Player_SimpleHit)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar1, ANIM_Mario1_Hurt)
            Set(LVar2, 0)
            ExecWait(EVS_Player_SimpleHit)
            Return
        CaseEq(EVENT_RECOVER_FROM_KO)
            Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
            Call(GetActorPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
            Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_BeforeJump)
            Call(SetGoalPos, ACTOR_PLAYER, LVar7, LVar8, LVar9)
            Call(func_80273444, 15, 0, 0)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_BeforeJump)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_Player_Celebrate = {
    Set(LVar0, 0)
    Loop(5)
        Add(LVar0, 72)
        Call(SetActorYaw, ACTOR_SELF, LVar0)
        Wait(1)
    EndLoop
    Call(ChoosePlayerCelebrationAnim)
    Call(SetAnimation, ACTOR_PLAYER, 0, LVar0)
    Wait(31)
    Return
    End
};

EvtScript EVS_RunAwayNoCommand = {
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hustled)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_IN_PLACE)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 180)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(15)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 8, 0, 0)
    Call(DetermineAutoRunAwaySuccess)
    IfEq(LVar0, 1)
        Call(SetFledBattleFlag)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_AWAY)
        Call(SetGoalPos, ACTOR_PLAYER, -240, 0, 10)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(16.0))
        Call(PlayerRunToGoal, 0)
        Wait(5)
    Else
        ChildThread
            Call(ShakeCam, 1, 0, 5, Float(1.0))
        EndChildThread
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Trip)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TRIP)
        Call(SetGoalPos, ACTOR_PLAYER, -100, 0, 10)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(10.0))
        Call(PlayerRunToGoal, 0)
        Set(LVar3, 6)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        ChildThread
            Loop(2)
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, Float(1.0))
                Wait(5)
            EndLoop
        EndChildThread
        Loop(10)
            Sub(LVar0, LVar3)
            Sub(LVar3, 1)
            IfLt(LVar3, 1)
                Set(LVar3, 1)
            EndIf
            Call(SetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_DUST_OFF)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
        Wait(20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
        ChildThread
            Wait(7)
            Loop(2)
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                Sub(LVar0, 8)
                Add(LVar1, 14)
                Add(LVar2, 5)
                PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, Float(1.0), Float(1.0))
                Wait(5)
            EndLoop
        EndChildThread
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Wait(10)
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_RunAwayStart = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(GetActionCommandMode, LVar2)
    IfEq(LVar2, ACTION_COMMAND_MODE_NOT_LEARNED)
        ExecWait(EVS_RunAwayNoCommand)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Return
    EndIf
    Call(ShowActionHud, 1)
    Call(GetActorVar, ACTOR_SELF, 0, LVar0)
    Call(LoadActionCommand, ACTION_COMMAND_FLEE)
    Call(action_command_flee_init, LVar0)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Call(func_80260E38)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB3_Hustled)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_IN_PLACE)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 180)
    Wait(5)
    Call(action_command_flee_start, 0, 60, 3)
    Call(func_80260E5C)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(2)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(5)
    Call(AddActorPos, ACTOR_PLAYER, 2, 0, 0)
    Wait(15)
    Wait(30)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 8, 0, 0)
    Call(GetActionSuccess, LVar0)
    Call(DetermineAutoRunAwaySuccess)
    IfEq(LVar0, 1)
        Call(SetFledBattleFlag)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_RUN_AWAY)
        Call(SetGoalPos, ACTOR_PLAYER, -240, 0, 10)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(16.0))
        Call(PlayerRunToGoal, 0)
        Wait(5)
    Else
        ChildThread
            Call(ShakeCam, 1, 0, 5, Float(1.0))
        EndChildThread
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Trip)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TRIP)
        Call(SetGoalPos, ACTOR_PLAYER, -100, 0, 10)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(10.0))
        Call(PlayerRunToGoal, 0)
        Set(LVar3, 6)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        ChildThread
            Loop(2)
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, Float(1.0))
                Wait(5)
            EndLoop
        EndChildThread
        Loop(10)
            Sub(LVar0, LVar3)
            Sub(LVar3, 1)
            IfLt(LVar3, 1)
                Set(LVar3, 1)
            EndIf
            Call(SetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_DUST_OFF)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_GetUp)
        Wait(20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_DustOff)
        ChildThread
            Wait(7)
            Loop(2)
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                Sub(LVar0, 8)
                Add(LVar1, 14)
                Add(LVar2, 5)
                PlayEffect(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, Float(1.0), Float(1.0))
                Wait(5)
            EndLoop
        EndChildThread
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Wait(10)
    EndIf
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_RunAwayFail = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(SetActorYaw, ACTOR_PLAYER, 0)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_PlayerDies = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Dying)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_24)
    Wait(15)
    Call(EnablePlayerBlur, ACTOR_BLUR_ENABLE)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_SPINNING)
    Set(LVar0, 0)
    Loop(30)
        Add(LVar0, 60)
        Call(SetActorYaw, ACTOR_PLAYER, LVar0)
        Wait(1)
    EndLoop
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 36)
        Call(SetActorYaw, ACTOR_PLAYER, LVar0)
        Wait(1)
    EndLoop
    Call(EnablePlayerBlur, ACTOR_BLUR_DISABLE)
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_COLLAPSE)
    Set(LVar0, 0)
    Set(LVar1, 1)
    Loop(0)
        IfEq(LVar0, 90)
            BreakLoop
        EndIf
        Add(LVar0, LVar1)
        Add(LVar1, 2)
        IfGt(LVar0, 90)
            Set(LVar0, 90)
        EndIf
        Call(SetActorRotation, ACTOR_PLAYER, LVar0, 0, 0)
        Wait(1)
    EndLoop
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 2)
    Call(SetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar2, 20)
    PlayEffect(EFFECT_WALKING_DUST, 1, LVar0, LVar1, LVar2, Float(1.0), Float(1.0))
    Wait(15)
    Return
    End
};

EvtScript D_80287404 = {
    IfEq(LVar1, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_69)
        Wait(10)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 18)
        Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlayerRunToGoal, 0)
        Add(LVar1, 45)
        Set(LVar3, LVar1)
        Add(LVar3, 10)
        Add(LVar3, 2)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, Float(1.0), 30)
        Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
        Set(LVarA, LVar0)
        Call(GiveRefund)
        Wait(LVar0)
        Wait(15)
        Call(GiveRefundCleanup)
        Call(RemoveItemEntity, LVarA)
    Else
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_USE_ITEM)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        Wait(4)
        Add(LVar1, 45)
        Set(LVar3, LVar1)
        Add(LVar3, 10)
        Add(LVar3, 2)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 1, LVar0, LVar3, LVar2, Float(1.0), 30)
        Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
        Set(LVarA, LVar0)
        Wait(15)
        Call(RemoveItemEntity, LVarA)
    EndIf
    Return
    End
};

EvtScript D_80287708 = {
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -85, 1, 0)
    Call(SetBattleCamOffsetZ, 41)
    Call(SetBattleCamZoom, 248)
    Call(MoveBattleCamOver, 30)
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 45)
    Call(MakeItemEntity, LVarA, LVar0, LVar1, LVar2, 1, 0)
    Set(LVarE, LVar0)
    Call(GiveRefund)
    Wait(LVar0)
    Wait(15)
    Call(GiveRefundCleanup)
    Call(RemoveItemEntity, LVarE)
    Return
    End
};

EvtScript D_80287834 = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(8.0))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
    Call(PlayerRunToGoal, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_PlayEatFX = {
    Thread
        Loop(4)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            Wait(10)
        EndLoop
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Eat)
    Wait(45)
    Return
    End
};

EvtScript EVS_PlayDrinkFX = {
    Thread
        Loop(4)
            Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_EAT_OR_DRINK)
            Wait(10)
        EndLoop
    EndThread
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Drink)
    Wait(45)
    Return
    End
};

EvtScript EVS_UseLifeShroom = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    ChildThread
        Call(func_80261388)
        IfEq(LVar0, 1)
            Call(DispatchEvent, ACTOR_PARTNER, EVENT_LIFE_SHROOM_PROC)
            Call(SetActorFlagBits, ACTOR_PARTNER, ACTOR_FLAG_NO_SHADOW, 1)
            Set(LVar0, 255)
            Loop(10)
                Sub(LVar0, 25)
                IfLt(LVar0, 0)
                    Set(LVar0, 0)
                EndIf
                Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
                Wait(1)
            EndLoop
            Call(SetPartAlpha, ACTOR_PARTNER, -1, 0)
        EndIf
    EndChildThread
    Call(LifeShroomShroudWorld)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(MakeItemEntity, ITEM_LIFE_SHROOM, LVar0, LVar1, LVar2, 1, 0)
    Set(LVarA, LVar0)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar3, 30)
    Set(LVar4, 16)
    Loop(LVar3)
        Add(LVar4, 8)
        IfGt(LVar4, 255)
            Set(LVar4, 255)
        EndIf
        AddF(LVar1, Float(1.0))
        Call(SetItemPos, LVarA, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Set(LVar3, LVar0)
    Set(LVar4, LVar1)
    Set(LVar5, LVar2)
    Call(SetItemAsLifeShroom)
    Call(GiveRefund)
    IfGt(LVar0, 0)
        Wait(LVar0)
        Wait(15)
        Call(GiveRefundCleanup)
    EndIf
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LIFE_SHROOM_CHIME)
    Add(LVar4, 15)
    PlayEffect(EFFECT_ENERGY_IN_OUT, 3, LVar3, LVar4, LVar5, Float(1.0))
    Set(LVar0, LVarF)
    Loop(4)
        Call(SetItemFlags, LVarA, 64, 1)
        Wait(2)
        Call(SetItemFlags, LVarA, 64, 0)
        Wait(8)
    EndLoop
    Call(RemoveEffect, LVar0)
    Call(RemoveItemEntity, LVarA)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_START_RECOVERY)
    PlayEffect(EFFECT_STARS_SHIMMER, 1, LVar3, LVar4, LVar5, 70, 70, 10, 20)
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_REVIVAL_MAGIC)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_STARS_SHIMMER, 2, LVar0, LVar1, LVar2, 50, 20, 32, 30)
    Wait(40)
    PlayEffect(EFFECT_STARS_SHIMMER, 2, LVar0, LVar1, LVar2, 30, 50, 32, 30)
    ChildThread
        Loop(3)
            Call(SetActorDispOffset, ACTOR_PLAYER, 1, 0, 0)
            Wait(4)
            Call(SetActorDispOffset, ACTOR_PLAYER, -1, 0, 0)
            Wait(4)
        EndLoop
        Loop(3)
            Call(SetActorDispOffset, ACTOR_PLAYER, 1, 0, 0)
            Wait(2)
            Call(SetActorDispOffset, ACTOR_PLAYER, -1, 0, 0)
            Wait(2)
        EndLoop
        Loop(7)
            Call(SetActorDispOffset, ACTOR_PLAYER, 1, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PLAYER, -1, 0, 0)
            Wait(1)
        EndLoop
    EndChildThread
    Wait(50)
    ChildThread
        Call(LifeShroomRevealWorld)
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_PLAYER_REVIVE)
    Call(SetActorRotation, ACTOR_PLAYER, 0, 0, 0)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(ConsumeLifeShroom)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    PlayEffect(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3)
    Call(FreezeBattleCam, 0)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    ChildThread
        Call(func_80261388)
        IfEq(LVar0, 1)
            Call(SetActorFlagBits, ACTOR_PARTNER, ACTOR_FLAG_NO_SHADOW, 0)
            Set(LVar0, 0)
            Loop(10)
                Add(LVar0, 25)
                IfGt(LVar0, 255)
                    Set(LVar0, 255)
                EndIf
                Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
                Wait(1)
            EndLoop
            Call(DispatchEvent, ACTOR_PARTNER, EVENT_REVIVE)
            Call(SetPartAlpha, ACTOR_PARTNER, -1, 255)
        EndIf
    EndChildThread
    ChildThread
        Loop(5)
            Wait(2)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_MISC_PARTICLES, 2, LVar0, LVar1, LVar2, 20, 20, Float(1.0), 10, 50)
        EndLoop
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_LONG_PLAYER_JUMP)
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.0))
    Call(SetActorSpeed, ACTOR_PLAYER, Float(1.0))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 20, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(4)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(10)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Call(RestorePreDefeatState)
    Return
    End
};

EvtScript EVS_MerleeRunOut = {
    Call(HasMerleeCastsLeft)
    IfEq(LVar0, 1)
        Return
    EndIf
    Wait(15)
    Call(ShowMessageBox, BTL_MSG_MERLEE_DONE, 60)
    Call(WaitForMessageBoxDone)
    Return
    End
};

EvtScript EVS_MerleeAttackBonus = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(BattleMerleeFadeStageToBlack)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, 0, 80, 0)
    Call(SetBattleCamOffsetZ, 0)
    Call(SetBattleCamZoom, 246)
    Call(MoveBattleCamOver, 20)
    Wait(10)
    Call(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    Call(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Call(SetNpcRenderMode, NPC_BTL_MERLEE, 34)
    Call(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    ChildThread
        Call(BattleMerleeUpdateFX)
    EndChildThread
    Call(BattleFadeInMerlee)
    Wait(30)
    Call(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    Call(func_802619B4)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 4)
    Call(BattleMerleeFadeStageFromBlack)
    Wait(20)
    ChildThread
        Call(BattleFadeOutMerlee)
        Call(DeleteNpc, NPC_BTL_MERLEE)
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MAGIC_DESCENDING)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    Call(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    Wait(15)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 18, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(4)
    Call(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    Call(ShowMessageBox, BTL_MSG_MERLEE_ATK_UP, 60)
    Call(WaitForMessageBoxDone)
    ExecWait(EVS_MerleeRunOut)
    Return
    End
};

EvtScript EVS_MerleeDefenseBonus = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(BattleMerleeFadeStageToBlack)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, 0, 80, 0)
    Call(SetBattleCamOffsetZ, 0)
    Call(SetBattleCamZoom, 246)
    Call(MoveBattleCamOver, 20)
    Wait(10)
    Call(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    Call(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Call(SetNpcRenderMode, NPC_BTL_MERLEE, 34)
    Call(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    ChildThread
        Call(BattleMerleeUpdateFX)
    EndChildThread
    Call(BattleFadeInMerlee)
    Wait(30)
    Call(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    Call(func_802619B4)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 4)
    Call(BattleMerleeFadeStageFromBlack)
    Wait(20)
    ChildThread
        Call(BattleFadeOutMerlee)
        Call(DeleteNpc, NPC_BTL_MERLEE)
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MAGIC_DESCENDING)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    Call(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    Wait(15)
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Wait(22)
    Else
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
        Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
        Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Call(func_80273444, 18, 0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
        Wait(4)
        Call(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    EndIf
    Call(ShowMessageBox, BTL_MSG_MERLEE_DEF_UP, 60)
    Call(WaitForMessageBoxDone)
    ExecWait(EVS_MerleeRunOut)
    Return
    End
};

EvtScript EVS_MerleeExpBonus = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(BattleMerleeFadeStageToBlack)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, 0, 80, 0)
    Call(SetBattleCamOffsetZ, 0)
    Call(SetBattleCamZoom, 246)
    Call(MoveBattleCamOver, 20)
    Wait(10)
    Call(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    Call(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Call(SetNpcRenderMode, NPC_BTL_MERLEE, 34)
    Call(SetNpcPos, NPC_BTL_MERLEE, 0, 65, 20)
    ChildThread
        Call(BattleMerleeUpdateFX)
    EndChildThread
    Call(BattleFadeInMerlee)
    Wait(30)
    Call(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    Call(func_802619B4)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 4)
    Call(BattleMerleeFadeStageFromBlack)
    Wait(20)
    ChildThread
        Call(BattleFadeOutMerlee)
        Call(DeleteNpc, NPC_BTL_MERLEE)
    EndChildThread
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_MAGIC_DESCENDING)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(PlayBattleMerleeGatherFX, LVar0, LVar1, LVar2)
    Call(PlayBattleMerleeOrbFX, LVar0, LVar1, LVar2)
    Wait(15)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(func_80273444, 18, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Land)
    Wait(4)
    Call(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    Call(ShowMessageBox, BTL_MSG_MERLEE_EXP_UP, 60)
    Call(WaitForMessageBoxDone)
    ExecWait(EVS_MerleeRunOut)
    Return
    End
};

EvtScript EVS_PlayerHappy = {
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(UseBattleCamPresetWait, BTL_CAM_DEFAULT)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SpawnTurnEndFX, LVar0, LVar1, LVar2)
    Add(LVar0, 0)
    Add(LVar1, 35)
    Set(LVar3, LVarA)
    Add(LVar3, LVarB)
    IfGt(LVar3, 0)
        Call(SpawnRecoverHeartFX, LVar0, LVar1, LVar2, LVar3)
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Add(LVar1, 25)
    IfGt(LVarC, 0)
        Call(SpawnRecoverFlowerFX, LVar0, LVar1, LVar2, LVarC)
    EndIf
    Set(LVar3, LVarA)
    Add(LVar3, LVarB)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVar3)
    Wait(10)
    Set(LVar0, LVarA)
    IfGt(LVar0, 0)
        Loop(LVar0)
            Call(IncrementPlayerHP)
            Wait(1)
        EndLoop
    EndIf
    Set(LVar0, LVarB)
    IfGt(LVar0, 0)
        Loop(LVar0)
            Call(IncrementPlayerHP)
            Wait(1)
        EndLoop
    EndIf
    Set(LVar0, LVarC)
    IfGt(LVar0, 0)
        Loop(LVar0)
            Call(IncrementPlayerFP)
            Wait(1)
        EndLoop
    EndIf
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, 0, ANIM_Mario1_Idle)
    Call(RemoveTurnEndFX)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Return
    End
};

EvtScript EVS_ApplyDizzyAttack = {
    Set(LVar0, 0)
    Loop(40)
        Add(LVar0, 72)
        Call(SetActorRotation, ACTOR_ENEMY0, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(InflictDizzyAttackStatus)
    Call(SetActorRotation, ACTOR_ENEMY0, 0, 0, 0)
    Return
    End
};

EvtScript EVS_PlayerRegainAbility = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(GetActorPos, ACTOR_PLAYER, LVarF, LVar1, LVar2)
    Loop(LVar0)
        Add(LVarF, 3)
        Wait(1)
    EndLoop
    Call(GetLostHammerAndBootsLevel)
    Switch(LVarA)
        CaseEq(BTL_MENU_TYPE_ITEMS)
            Set(LVarE, 0)
            Set(LVarA, ITEM_MENU_ITEMS)
        CaseEq(BTL_MENU_TYPE_SMASH)
            Set(LVarE, 1)
            Switch(LVarC)
                CaseEq(0)
                    Set(LVarA, ITEM_MENU_HAMMER1)
                CaseEq(1)
                    Set(LVarA, ITEM_MENU_HAMMER2)
                CaseEq(2)
                    Set(LVarA, ITEM_MENU_HAMMER3)
            EndSwitch
        CaseEq(BTL_MENU_TYPE_JUMP)
            Set(LVarE, 2)
            Switch(LVarB)
                CaseEq(0)
                    Set(LVarA, ITEM_MENU_BOOTS1)
                CaseEq(1)
                    Set(LVarA, ITEM_MENU_BOOTS2)
                CaseEq(2)
                    Set(LVarA, ITEM_MENU_BOOTS3)
            EndSwitch
    EndSwitch
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVarF, 24)
    Add(LVar1, 150)
    Call(MakeItemEntity, LVarA, LVarF, LVar1, LVar2, 1, 0)
    Set(LVarA, LVar0)
    Call(DropAbilityItem)
    Call(AbilityItemUnkDelay)
    Call(PlayerGatherAbilityItem)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_STARS_SHIMMER, 0, LVar0, LVar1, LVar2, 30, 30, 10, 30)
    Call(RemoveItemEntity, LVarA)
    Call(FreezeBattleState, FALSE)
    Return
    End
};
