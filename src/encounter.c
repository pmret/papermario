#include "battle/battle.h"
#include "script_api/battle.h"
#include "npc.h"
#include "effects.h"
#include "hud_element.h"
#include "world/partners.h"
#include "sprite.h"
#include "sprite/npc/BattleMerlee.h"
#include "sprite/player.h"
#include "model.h"

ApiStatus ShowMerleeCoinMessage(Evt* script, s32 isInitialCall);
ApiStatus ShowMerleeRanOutMessage(Evt* script, s32 isInitialCall);
ApiStatus FadeInMerlee(Evt* script, s32 isInitialCall);
ApiStatus FadeOutMerlee(Evt* script, s32 isInitialCall);
ApiStatus MerleeUpdateFX(Evt* script, s32 isInitialCall);
ApiStatus MerleeStopFX(Evt* script, s32 isInitialCall);
ApiStatus PlayMerleeGatherFX(Evt* script, s32 isInitialCall);
ApiStatus PlayMerleeOrbFX(Evt* script, s32 isInitialCall);

s32 D_80077C40 = 0;

EvtScript EVS_MerleeDropCoins = {
    EVT_WAIT(10)
    EVT_CALL(FadeBackgroundToBlack)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcYaw, NPC_BTL_MERLEE, 0)
    EVT_CALL(GetCamLookAtObjVector)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(MerleeUpdateFX)
    EVT_END_THREAD
    EVT_CALL(FadeInMerlee)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_BTL_MERLEE, ANIM_BattleMerlee_Release)
    EVT_CALL(MerleeStopFX)
    EVT_CALL(UnfadeBackgroundFromBlack)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(FadeOutMerlee)
        EVT_CALL(DeleteNpc, NPC_BTL_MERLEE)
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_2075)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(PlayMerleeGatherFX, LVar0, LVar1, LVar2)
    EVT_CALL(PlayMerleeOrbFX, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(ShowMerleeCoinMessage)
    EVT_WAIT(15)
    EVT_CALL(HasMerleeCasts)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowMerleeRanOutMessage)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_NpcDefeat = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(OnDefeatEnemy)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EVS_FleeBattleDrops = {
    EVT_CALL(OnFleeBattleDrops)
    EVT_RETURN
    EVT_END
};

EnemyDrops DefaultEnemyDrops = {
    .dropFlags = NPC_DROP_FLAG_80,
    .itemDropChance = 10,
    .itemDrops = {
        {
            .item = ITEM_MUSHROOM,
            .weight = 50,
            .unk_04 = -1,
        },
    },
    .heartDrops = {
        {
            .cutoff = F16(75),
            .generalChance = F16(100),
            .attempts = 0,
            .chancePerAttempt = 1,
        },
        {
            .cutoff = F16(50),
            .generalChance = F16(75),
            .attempts = 0,
            .chancePerAttempt = 2,
        },
        {
            .cutoff = F16(25),
            .generalChance = F16(50),
            .attempts = 0,
            .chancePerAttempt = 3,
        },
        {
            .cutoff = F16(0),
            .generalChance = F16(25),
            .attempts = 0,
            .chancePerAttempt = 4,
        },
    },
    .flowerDrops = {
        {
            .cutoff = 1,
            .generalChance = 3,
            .attempts = 0,
            .chancePerAttempt = 0,
        },
    },
    .minCoinBonus = 0,
    .maxCoinBonus = 0,
};

EvtScript EnemyNpcHit = {
    EVT_CALL(GetOwnerEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_NONE)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(GetSelfAnimationFromTable, ENEMY_ANIM_INDEX_HIT, LVar0)
            EVT_EXEC_WAIT(EVS_NpcHitRecoil)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_SPIN)
            EVT_THREAD
                EVT_CALL(func_800458CC, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_LOOP(30)
                        EVT_ADD(LVarA, 40)
                        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVarA, 0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript EnemyNpcDefeat = {
    EVT_CALL(SetNpcRotation, NPC_SELF, 0, 0, 0)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(OnPlayerFled, 0)
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, -1, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

SHIFT_BSS s32 gEncounterState;
SHIFT_BSS s32 gEncounterSubState;
SHIFT_BSS EncounterStatus gCurrentEncounter;
SHIFT_BSS s8 D_8009A63C;
SHIFT_BSS s8 D_8009A654;
SHIFT_BSS s16 gFirstStrikeMessagePos;
SHIFT_BSS s8 D_8009A670;
SHIFT_BSS s32 D_8009A678;
SHIFT_BSS s32 D_800A0BA0;
SHIFT_BSS f32 D_800A0BA4;
SHIFT_BSS Evt* D_800A0BB0;
SHIFT_BSS s32 D_800A0BB4;
SHIFT_BSS s16 D_800A0BB8;
SHIFT_BSS EffectInstance* WorldMerleeOrbEffect;
SHIFT_BSS EffectInstance* WorldMerleeWaveEffect;

void set_battle_formation(Battle*);
void func_800E97E4(void);
void partner_handle_after_battle(void);
s32 get_coin_drop_amount(Enemy* enemy);

s32 get_defeated(s32 mapID, s32 encounterID) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift = encounterID % 32;

    return currentEncounter->defeatFlags[mapID][encounterIdx] & (1 << encounterShift);
}

void set_defeated(s32 mapID, s32 encounterID) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift;
    s32 flag;

    flag = encounterID % 32;
    encounterShift = flag;
    flag = currentEncounter->defeatFlags[mapID][encounterIdx];
    currentEncounter->defeatFlags[mapID][encounterIdx] = flag | (1 << encounterShift);

    // TODO: The below should work but has regalloc issues:
    /*EncounterStatus *currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift = encounterID % 32;

    currentEncounter->defeatFlags[mapID][encounterIdx] |= (1 << encounterShift);*/
}

ApiStatus ShowMerleeCoinMessage(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        show_merlee_message(0, 60);
    }

    if (is_merlee_message_done()) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

ApiStatus ShowMerleeRanOutMessage(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        show_merlee_message(1, 60);
    }

    if (is_merlee_message_done()) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

ApiStatus FadeBackgroundToBlack(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(FOG_MODE_1);
        *gBackgroundFogModePtr = FOG_MODE_1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 25;
    }

    set_background_color_blend(0, 0, 0, ((25 - script->functionTemp[0]) * 10) & 254);
    script->functionTemp[0]--;

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus UnfadeBackgroundFromBlack(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 25;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 10) & 0xFE);
    script->functionTemp[0] -= 5;

    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus FadeInMerlee(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_BTL_MERLEE);

    if (isInitialCall) {
        sfx_play_sound(SOUND_24B);
        npc->alpha = 0;
    }

    npc->alpha += 17;

    if ((u32)(npc->alpha & 0xFF) >= 0xFF) {
        npc->alpha = 0xFF;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus FadeOutMerlee(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_BTL_MERLEE);

    npc->alpha -= 17;
    if (npc->alpha == 0) {
        npc->alpha = 0;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

// same as BattleMerleeUpdateFX aside from syms
ApiStatus MerleeUpdateFX(Evt* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);
    EnergyOrbWaveFXData* effectData;

    if (isInitialCall) {
        script->functionTemp[1] = 0;
        D_800A0BA4 = merlee->pos.y;
        WorldMerleeOrbEffect = fx_energy_orb_wave(0, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.4f, 0);
        WorldMerleeWaveEffect = fx_energy_orb_wave(3, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.00001f, 0);
        D_800A0BB8 = 0;
        D_800A0BA0 = 12;
        sfx_play_sound(SOUND_2074);
    }

    merlee->pos.y = D_800A0BA4 + sin_rad(DEG_TO_RAD(script->functionTemp[1])) * 3.0f;

    script->functionTemp[1] += 10;
    script->functionTemp[1] = clamp_angle(script->functionTemp[1]);

    effectData = WorldMerleeOrbEffect->data.energyOrbWave;
    effectData->pos.x = merlee->pos.x;
    effectData->pos.y = merlee->pos.y + 16.0f;
    effectData->pos.z = merlee->pos.z;

    effectData = WorldMerleeWaveEffect->data.energyOrbWave;
    effectData->pos.x = merlee->pos.x;
    effectData->pos.y = merlee->pos.y + 16.0f;
    effectData->pos.z = merlee->pos.z + 5.0f;

    if (D_800A0BB8 == 2) {
        WorldMerleeOrbEffect->data.energyOrbWave->scale = 0.00001f;
        WorldMerleeWaveEffect->data.energyOrbWave->scale = 0.00001f;
        WorldMerleeOrbEffect->flags |= FX_INSTANCE_FLAG_DISMISS;
        WorldMerleeWaveEffect->flags |= FX_INSTANCE_FLAG_DISMISS;
        return ApiStatus_DONE1;
    }

    if (D_800A0BB8 == 1) {
        effectData = WorldMerleeOrbEffect->data.energyOrbWave;
        effectData->scale += 0.35;
        if (effectData->scale > 3.5) {
            effectData->scale = 3.5f;
        }

        if (D_800A0BA0 != 0) {
            D_800A0BA0--;
        } else {
            effectData = WorldMerleeWaveEffect->data.energyOrbWave;
            effectData->scale += 0.5;
            if (effectData->scale > 5.0) {
                D_800A0BB8 = 2;
            }
        }
    }
    return ApiStatus_BLOCK;
}

ApiStatus MerleeStopFX(Evt* script, s32 isInitialCall) {
    D_800A0BB8 = 1;
    return ApiStatus_DONE2;
}

ApiStatus GetCamLookAtObjVector(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gCameras[gCurrentCameraID].lookAt_obj.x;
    script->varTable[1] = gCameras[gCurrentCameraID].lookAt_obj.y;
    script->varTable[2] = gCameras[gCurrentCameraID].lookAt_obj.z;

    return ApiStatus_DONE2;
}

ApiStatus HasMerleeCasts(Evt* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;
    if (gPlayerData.merleeCastsLeft > 0) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

ApiStatus PlayMerleeGatherFX(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    fx_energy_in_out(6, var0, var1, var2, 1.2f, 30);
    return ApiStatus_DONE2;
}

ApiStatus PlayMerleeOrbFX(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    fx_energy_orb_wave(9, var0, var1, var2, 5.0f, 15);
    return ApiStatus_DONE2;
}

ApiStatus OnDefeatEnemy(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp1;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 20;
    }

    if (script->functionTemp[1] & 1) {
        npc->flags &= ~NPC_FLAG_INVISIBLE;
    } else {
        npc->flags |= NPC_FLAG_INVISIBLE;
    }

    if (script->functionTemp[1] == 15) {
        sfx_play_sound(SOUND_DEATH);
        fx_damage_stars(1, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z, 0, -1.0f, 0, 10);
    }

    temp1 = script->functionTemp[1];
    if (script->functionTemp[1] == 10) {
        fx_big_smoke_puff(npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 10.0f);
        if (script->functionTemp[1] == temp1) { // what? (never can be false, seemingly)
            spawn_drops(enemy);
        }
    }

    script->functionTemp[1]--;
    if (script->functionTemp[1] == 0) {
        npc->flags |= NPC_FLAG_INVISIBLE;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus OnFleeBattleDrops(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 40;
        script->functionTemp[2] = 0;
    }

    script->functionTemp[2]++;
    if (script->functionTemp[2] >= 5) {
        if (rand_int(100) < 50) {
            if (playerData->coins != 0) {
                playerData->coins--;
                make_item_entity_delayed(ITEM_COIN, playerStatus->pos.x,
                    playerStatus->pos.y + playerStatus->colliderHeight, playerStatus->pos.z,
                    ITEM_SPAWN_MODE_TOSS_SPAWN_ALWAYS, 0, 0);
            }
        }
        script->functionTemp[2] = 0;
    }

    return --script->functionTemp[1] == 0;
}

void update_encounters_neutral(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 screenX, screenY, screenZ;
    f32 npcX, npcY, npcZ;
    f32 npcYaw;
    f32 testX, testY, testZ;
    f32 x, y, z;
    s32 e;
    f32 playerX, playerY, playerZ;
    f32 playerYaw;
    Encounter* encounter;
    Evt* script;
    Npc* npc;
    f32 distance;
    f32 colHeight;
    f32 colRadius;
    f32 hammerDir;

    s32 triggeredBattle;
    s32 cond2;
    s32 firstStrikeType;
    s32 suspendTime;

    Enemy* enemy;
    Enemy* currentEnemy;
    s32 i;

    f32 playerJumpColHeight = 37.0f;
    f32 playerColRadius = 14.0f;
    f32 playerColHeight = 18.0f;

    f32 dx, dz;
    f32 angle1, angle2;

    do {
        if (currentEncounter->hitType == ENCOUNTER_TRIGGER_CONVERSATION) {
            goto START_BATTLE;
        }
    } while (0);

    currentEncounter->songID = -1;
    currentEncounter->unk_18 = -1;
    currentEncounter->hitType = 0;
    currentEncounter->allowFleeing = FALSE;
    currentEncounter->dropWhackaBump = FALSE;
    currentEncounter->flags &= ~ENCOUNTER_STATUS_FLAG_1;
    currentEncounter->flags &= ~ENCOUNTER_STATUS_FLAG_2;
    currentEncounter->flags &= ~ENCOUNTER_STATUS_FLAG_4;

    playerX = playerStatus->pos.x;
    playerY = playerStatus->pos.y;
    playerZ = playerStatus->pos.z;
    playerYaw = playerStatus->spriteFacingAngle;

    if (playerYaw < 180.0f) {
        playerYaw = clamp_angle(camera->curYaw - 90.0f);
    } else {
        playerYaw = clamp_angle(camera->curYaw + 90.0f);
    }

    if (currentEncounter->battleTriggerCooldown != 0) {
        if (!(gOverrideFlags & GLOBAL_OVERRIDES_40)) {
            currentEncounter->battleTriggerCooldown--;
        }
        if (playerStatus->blinkTimer != 0) {
            if (!(playerStatus->flags & PS_FLAG_INPUT_DISABLED)) {
                playerStatus->blinkTimer = currentEncounter->battleTriggerCooldown;
            } else {
                playerStatus->blinkTimer = 1;
            }
        }
    }

    for (e = 0; e < currentEncounter->numEncounters; e++) {
        encounter = currentEncounter->encounterList[e];
        if (encounter == NULL) {
            continue;
        }
        for (i = 0; i < encounter->count; i++) {
            enemy = encounter->enemy[i];
            if (enemy == NULL || (enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                continue;
            }
            npc = get_npc_unsafe(enemy->npcID);
            if (enemy->aiSuspendTime != 0) {
                if (!(gOverrideFlags & GLOBAL_OVERRIDES_40)) {
                    enemy->aiSuspendTime--;
                    suspendTime = enemy->aiSuspendTime;
                } else {
                    suspendTime = 0;
                }

                if (suspendTime & 1) {
                    npc->flags |= NPC_FLAG_SUSPENDED;
                    enemy->flags |= ENEMY_FLAG_SUSPENDED;
                } else {
                    npc->flags &= ~NPC_FLAG_SUSPENDED;
                    enemy->flags &= ~ENEMY_FLAG_SUSPENDED;
                }
                script = get_script_by_id(enemy->auxScriptID);
                if (script != NULL) {
                    set_script_flags(script, EVT_FLAG_SUSPENDED);
                }
                script = get_script_by_id(enemy->aiScriptID);
                if (script != NULL) {
                    set_script_flags(script, EVT_FLAG_SUSPENDED);
                }
                if (enemy->flags & ENEMY_FLAG_80000) {
                    script = get_script_by_id(enemy->auxScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_SUSPENDED);
                    }
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_SUSPENDED);
                    }
                }
            } else if (!(enemy->flags & ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN)) {
                get_screen_coords(gCurrentCameraID, npc->pos.x, npc->pos.y, npc->pos.z, &screenX, &screenY, &screenZ);
                if ((screenX < -160 || screenX > 480 || screenY < -120 || screenY > 360 || screenZ < 0) && !(enemy->flags & ENEMY_FLAG_PASSIVE)) {
                    npc->flags |= NPC_FLAG_SUSPENDED;
                    enemy->flags |= ENEMY_FLAG_SUSPENDED;
                    script = get_script_by_id(enemy->auxScriptID);
                    if (script != NULL) {
                        set_script_flags(script, EVT_FLAG_SUSPENDED);
                    }
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        set_script_flags(script, EVT_FLAG_SUSPENDED);
                    }
                } else {
                    npc->flags &= ~NPC_FLAG_SUSPENDED;
                    enemy->flags &= ~ENEMY_FLAG_SUSPENDED;
                    script = get_script_by_id(enemy->auxScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_SUSPENDED);
                    }
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_SUSPENDED);
                    }
                }
            } else {
                npc->flags &= ~NPC_FLAG_SUSPENDED;
                enemy->flags &= ~ENEMY_FLAG_SUSPENDED;
                script = get_script_by_id(enemy->auxScriptID);
                if (script != NULL) {
                    clear_script_flags(script, EVT_FLAG_SUSPENDED);
                }
                script = get_script_by_id(enemy->aiScriptID);
                if (script != NULL) {
                    clear_script_flags(script, EVT_FLAG_SUSPENDED);
                }
            }

            if (enemy->flags & ENEMY_FLAG_SUSPENDED) {
                continue;
            }
            if (enemy->flags & ENEMY_FLAG_PASSIVE) {
                if (!(enemy->flags & ENEMY_FLAG_400000)) {
                    if (npc == playerStatus->encounteredNPC) {
                        enemy->savedNpcYaw = npc->yaw;
                        npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
                        script = get_script_by_id(enemy->aiScriptID);
                        if (script != NULL) {
                            set_script_flags(script, EVT_FLAG_SUSPENDED);
                        }
                    } else {
                        if (enemy->savedNpcYaw != 12345) {
                            npc->yaw = enemy->savedNpcYaw;
                            enemy->savedNpcYaw = 12345;
                        }
                        script = get_script_by_id(enemy->aiScriptID);
                        if (script != NULL) {
                            clear_script_flags(script, EVT_FLAG_SUSPENDED);
                        }
                    }
                } else {
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_SUSPENDED);
                    }
                }
            }

            if (currentEncounter->battleTriggerCooldown != 0 ||
                gGameStatusPtr->debugEnemyContact == DEBUG_CONTACT_CANT_TOUCH ||
                (playerStatus->flags & PS_FLAG_ARMS_RAISED) ||
                (gOverrideFlags & GLOBAL_OVERRIDES_40) ||
                gPartnerStatus.actingPartner == PARTNER_BOW ||
                (enemy->flags & ENEMY_FLAG_PASSIVE) ||
                (gOverrideFlags & (GLOBAL_OVERRIDES_DISABLE_BATTLES | GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_800)) ||
                is_picking_up_item()) {
                continue;
            }
            do {
                if (!(enemy->flags & ENEMY_FLAG_IGNORE_PARTNER) && partner_test_enemy_collision(npc)) {
                    currentEncounter->hitType = ENCOUNTER_TRIGGER_PARTNER;
                    enemy->encountered = ENCOUNTER_TRIGGER_PARTNER;
                    currentEncounter->curEncounter = encounter;
                    currentEncounter->curEnemy = enemy;
                    currentEncounter->firstStrikeType = FIRST_STRIKE_PLAYER;
                    goto START_BATTLE;
                }
            } while (0);

            npcX = npc->pos.x;
            npcY = npc->pos.y;
            npcZ = npc->pos.z;
            npcYaw = npc->yaw;
            colHeight = npc->collisionHeight;
            colRadius = npc->collisionDiameter / 2;

            if (enemy->unk_DC != 0) {
                npcYaw = npc->yawCamOffset;
                if (npcYaw < 180.0f) {
                    npcYaw = clamp_angle(camera->curYaw - 90.0f);
                } else {
                    npcYaw = clamp_angle(camera->curYaw + 90.0f);
                }

                add_vec2D_polar(&npcX, &npcZ, enemy->unk_DC, npcYaw);
            }

            dx = npcX - playerX;
            dz = npcZ - playerZ;
            distance = sqrtf(SQ(dx) + SQ(dz));

            switch (playerStatus->actionState) {
                case ACTION_STATE_HAMMER:
                    x = playerX;
                    y = playerY;
                    z = playerZ;
                    if (clamp_angle(playerStatus->spriteFacingAngle) < 180.0f) {
                        hammerDir = clamp_angle(camera->curYaw - 90.0f);
                        if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                            hammerDir = clamp_angle(hammerDir + 30.0f);
                        }
                    } else {
                        hammerDir = clamp_angle(camera->curYaw + 90.0f);
                        if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                            hammerDir = clamp_angle(hammerDir - 30.0f);
                        }
                    }
                    add_vec2D_polar(&x, &z, 24.0f, hammerDir);
                    dx = npcX - x;
                    dz = npcZ - z;
                    distance = sqrtf(SQ(dx) + SQ(dz));
                    if (enemy->flags & ENEMY_FLAG_IGNORE_HAMMER) {
                        break;
                    }
                    if (!(playerStatus->flags & PS_FLAG_HAMMER_CHECK)) {
                        break;
                    }
                    if (distance >= playerColRadius + colRadius || y > npcY + colHeight || npcY > y + playerColHeight) {
                        break;
                    }

                    testX = npcX;
                    testY = npcY;
                    testZ = npcZ;

                    if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(npcX, npcZ, playerX, playerZ), colHeight, colRadius * 2.0f)) {
                        testX = playerX;
                        testY = playerY;
                        testZ = playerZ;
                        if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(playerX, playerZ, npcX, npcZ), colHeight, colRadius * 2.0f)) {
                            break;
                        }
                    }
                    if (enemy->hitboxIsActive) {
                        npcX = enemy->unk_10.x;
                        npcY = enemy->unk_10.y;
                        npcZ = enemy->unk_10.z;
                    }

                    angle1 = fabsf(get_clamped_angle_diff(atan2(playerX, playerZ, npcX, npcZ), playerYaw));
                    angle2 = fabsf(get_clamped_angle_diff(atan2(npcX, npcZ, playerX, playerZ), npcYaw));
                    triggeredBattle = FALSE;
                    if (angle1 >= 90.0f && angle2 >= 90.0f) {
                        triggeredBattle = FALSE;
                    }
                    if (angle1 < 90.0f && angle2 >= 90.0f) {
                        triggeredBattle = TRUE;
                    }
                    if (angle1 >= 90.0f && angle2 < 90.0f) {
                        triggeredBattle = FALSE;
                    }
                    if (angle1 < 90.0f && angle2 < 90.0f) {
                        triggeredBattle = TRUE;
                    }
                    if (triggeredBattle) {
                        sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_MODE_0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
                        currentEncounter->hitType = ENCOUNTER_TRIGGER_HAMMER;
                        currentEncounter->hitTier = gPlayerData.hammerLevel;
                        enemy->encountered = ENCOUNTER_TRIGGER_HAMMER;
                        currentEncounter->curEncounter = encounter;
                        currentEncounter->curEnemy = enemy;
                        currentEncounter->firstStrikeType = FIRST_STRIKE_PLAYER;
                        goto START_BATTLE;
                    }
                    break;
                case ACTION_STATE_JUMP:
                case ACTION_STATE_BOUNCE:
                case ACTION_STATE_FALLING:
                case ACTION_STATE_STEP_DOWN:
                case ACTION_STATE_LAND:
                case ACTION_STATE_STEP_DOWN_LAND:
                case ACTION_STATE_SPIN_JUMP:
                case ACTION_STATE_SPIN_POUND:
                case ACTION_STATE_TORNADO_JUMP:
                case ACTION_STATE_TORNADO_POUND:
                    x = playerX;
                    z = playerZ;
                    if (!(enemy->flags & ENEMY_FLAG_IGNORE_JUMP)) {
                        if (distance >= playerColRadius + colRadius) {
                            continue;
                        }
                        if (playerY > npcY + colHeight || npcY > playerY + playerJumpColHeight) {
                            continue;
                        }

                        testX = npcX;
                        testY = npcY;
                        testZ = npcZ;
                        if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(npcX, npcZ, playerX, playerZ), colHeight, colRadius * 2.0f)) {
                            testX = playerX;
                            testY = playerY;
                            testZ = playerZ;
                            if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(playerX, playerZ, npcX, npcZ), colHeight, colRadius * 2.0f)) {
                                break;
                            }
                        }
                        triggeredBattle = FALSE;
                        if (npcY + colHeight < playerY + playerJumpColHeight * 0.5f) {
                            if (playerStatus->actionState == ACTION_STATE_FALLING ||
                                playerStatus->actionState == ACTION_STATE_STEP_DOWN ||
                                playerStatus->actionState == ACTION_STATE_LAND ||
                                playerStatus->actionState == ACTION_STATE_STEP_DOWN_LAND ||
                                playerStatus->actionState == ACTION_STATE_SPIN_JUMP ||
                                playerStatus->actionState == ACTION_STATE_SPIN_POUND ||
                                playerStatus->actionState == ACTION_STATE_TORNADO_JUMP ||
                                playerStatus->actionState == ACTION_STATE_TORNADO_POUND) {
                                triggeredBattle = TRUE;
                            }
                        }
                        if (playerY + playerJumpColHeight < npcY + colHeight * 0.5f) {
                            triggeredBattle = FALSE;
                        }
                        if (triggeredBattle) {
                            if (gPlayerData.bootsLevel < 0) {
                                currentEncounter->hitType = ENCOUNTER_TRIGGER_NONE;
                                enemy->encountered = ENCOUNTER_TRIGGER_NONE;
                                currentEncounter->curEncounter = encounter;
                                currentEncounter->curEnemy = enemy;
                                currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
                                currentEncounter->hitTier = 0;
                                goto START_BATTLE;
                            }
                            currentEncounter->hitType = ENCOUNTER_TRIGGER_JUMP;
                            switch (playerStatus->actionState) {
                                case ACTION_STATE_JUMP:
                                case ACTION_STATE_BOUNCE:
                                case ACTION_STATE_FALLING:
                                case ACTION_STATE_STEP_DOWN:
                                case ACTION_STATE_LAND:
                                case ACTION_STATE_STEP_DOWN_LAND:
                                    currentEncounter->hitTier = 0;
                                    break;
                                case ACTION_STATE_SPIN_JUMP:
                                case ACTION_STATE_SPIN_POUND:
                                    currentEncounter->hitTier = 1;
                                    break;
                                case ACTION_STATE_TORNADO_JUMP:
                                case ACTION_STATE_TORNADO_POUND:
                                    currentEncounter->hitTier = 2;
                                    break;
                            }
                            sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_MODE_0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
                            enemy->encountered = ENCOUNTER_STATE_NEUTRAL;
                            currentEncounter->curEncounter = encounter;
                            currentEncounter->curEnemy = enemy;
                            currentEncounter->firstStrikeType = FIRST_STRIKE_PLAYER;
                            goto START_BATTLE;
                        }
                    }
                    break;
            }

            if (enemy->flags & ENEMY_FLAG_IGNORE_TOUCH) {
                continue;
            }

            dx = npcX - playerX;
            dz = npcZ - playerZ;
            distance = sqrtf(SQ(dx) + SQ(dz));

            if (distance >= (playerColRadius + colRadius) * 0.8) {
                continue;
            }
            if (npcY + colHeight < playerY) {
                continue;
            }
            if (playerY + playerJumpColHeight < npcY) {
                continue;
            }

            testX = npcX;
            testY = npcY;
            testZ = npcZ;
            if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(npcX, npcZ, playerX, playerZ), colHeight, colRadius * 2.0f)) {
                testX = playerX;
                testY = playerY;
                testZ = playerZ;
                if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(playerX, playerZ, npcX, npcZ), colHeight, colRadius * 2.0f)) {
                    continue;
                }
            }
            triggeredBattle = FALSE;
            if (is_ability_active(ABILITY_SPIN_ATTACK) && gPlayerData.level >= enemy->npcSettings->level) {
                triggeredBattle = !currentEncounter->scriptedBattle;
            }
            if (is_ability_active(ABILITY_DIZZY_ATTACK)) {
                triggeredBattle = TRUE;
            }
            if ((playerStatus->animFlags & PA_FLAG_SPINNING) && !(enemy->flags & ENEMY_FLAG_IGNORE_SPIN) && triggeredBattle) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_MODE_0, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
                testX = playerStatus->pos.x + ((npc->pos.x - playerStatus->pos.x) * 0.5f);
                testY = playerStatus->pos.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->pos.y + playerStatus->colliderHeight)) * 0.5f);
                testZ = playerStatus->pos.z + ((npc->pos.z - playerStatus->pos.z) * 0.5f);
                fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                currentEncounter->hitType = ENCOUNTER_TRIGGER_SPIN;
                playerStatus->animFlags |= PA_FLAG_DIZZY_ATTACK_ENCOUNTER;
                enemy->encountered = ENCOUNTER_TRIGGER_SPIN;
                currentEncounter->curEncounter = encounter;
                currentEncounter->curEnemy = enemy;
                currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
            } else {
                currentEncounter->hitType = ENCOUNTER_TRIGGER_NONE;
                playerStatus->animFlags &= ~PA_FLAG_DIZZY_ATTACK_ENCOUNTER;
                enemy->encountered = ENCOUNTER_TRIGGER_NONE;
                currentEncounter->curEncounter = encounter;
                currentEncounter->curEnemy = enemy;
                testX = playerStatus->pos.x + ((npc->pos.x - playerStatus->pos.x) * 0.5f);
                testY = playerStatus->pos.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->pos.y + playerStatus->colliderHeight)) * 0.5f);
                testZ = playerStatus->pos.z + ((npc->pos.z - playerStatus->pos.z) * 0.5f);
                fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                // if the hitbox is active, trigger a first strike
                firstStrikeType = FIRST_STRIKE_NONE;
                if (enemy->hitboxIsActive) {
                    if (is_ability_active(ABILITY_CHILL_OUT)) {
                        firstStrikeType = FIRST_STRIKE_NONE;
                    } else {
                        firstStrikeType = FIRST_STRIKE_ENEMY;
                    }
                }
                // cancel the first strike if bump attack is applicable
                if ((is_ability_active(ABILITY_BUMP_ATTACK)
                        && (gPlayerData.level >= enemy->npcSettings->level)
                        && !(enemy->flags & ENEMY_FLAG_PROJECTILE))
                    && !currentEncounter->scriptedBattle
                ) {
                    firstStrikeType = FIRST_STRIKE_NONE;
                }
                currentEncounter->firstStrikeType = firstStrikeType;
            }
            goto START_BATTLE;
        }
    }

START_BATTLE:
    switch (currentEncounter->hitType) {
        case 0:
            break;
        case ENCOUNTER_TRIGGER_NONE:
            currentEnemy = enemy = currentEncounter->curEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAG_PROJECTILE) && enemy != currentEncounter->curEnemy) {
                    continue;
                }

                if (enemy->hitBytecode != NULL) {
                    enemy->encountered = ENCOUNTER_TRIGGER_NONE;
                    script = start_script(enemy->hitBytecode, EVT_PRIORITY_A, 0);
                    enemy->hitScript = script;
                    enemy->hitScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                }
            }
            disable_player_input();
            partner_disable_input();
            if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP &&
                playerStatus->actionState != ACTION_STATE_TORNADO_POUND &&
                playerStatus->actionState != ACTION_STATE_SPIN_JUMP &&
                playerStatus->actionState != ACTION_STATE_SPIN_POUND) {
                playerStatus->flags |= PS_FLAG_ENTERING_BATTLE;
            }
            if (!is_ability_active(ABILITY_CHILL_OUT) && currentEncounter->firstStrikeType == FIRST_STRIKE_ENEMY) {
                set_action_state(ACTION_STATE_ENEMY_FIRST_STRIKE);
                npc = get_npc_unsafe(enemy->npcID);
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_MODE_0, npc->pos.x, npc->pos.y, npc->pos.z);
            }
            currentEncounter->scriptedBattle = FALSE;
            gEncounterState = ENCOUNTER_STATE_PRE_BATTLE;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT;
            break;
        case ENCOUNTER_TRIGGER_SPIN:
            currentEnemy = enemy = currentEncounter->curEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAG_PROJECTILE) && enemy != currentEncounter->curEnemy) {
                    continue;
                }

                if (enemy->hitBytecode != NULL) {
                    enemy->encountered = ENCOUNTER_TRIGGER_SPIN;
                    script = start_script(enemy->hitBytecode, EVT_PRIORITY_A, 0);
                    enemy->hitScript = script;
                    enemy->hitScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                }
            }
            disable_player_input();
            partner_disable_input();
            currentEncounter->scriptedBattle = FALSE;
            gEncounterState = ENCOUNTER_STATE_PRE_BATTLE;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT;
            playerStatus->flags |= PS_FLAG_ENTERING_BATTLE;
            break;
        case ENCOUNTER_TRIGGER_JUMP:
            currentEnemy = enemy = currentEncounter->curEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->curEncounter;

            cond2 = FALSE;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAG_PROJECTILE) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->hitBytecode != NULL) {
                    enemy->encountered = ENCOUNTER_TRIGGER_JUMP;
                    script = start_script(enemy->hitBytecode, EVT_PRIORITY_A, 0);
                    enemy->hitScript = script;
                    enemy->hitScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                    npc = get_npc_unsafe(enemy->npcID);
                    cond2 = TRUE;
                    testX =  playerStatus->pos.x + ((npc->pos.x - playerStatus->pos.x) * 0.5f);
                    testY = playerStatus->pos.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->pos.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->pos.z + ((npc->pos.z - playerStatus->pos.z) * 0.5f);
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                } else if (!(enemy->flags & ENEMY_FLAG_PASSIVE)) {
                    npc = get_npc_unsafe(enemy->npcID);
                    cond2 = TRUE;
                    testX =  playerStatus->pos.x + ((npc->pos.x - playerStatus->pos.x) * 0.5f);
                    testY = playerStatus->pos.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->pos.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->pos.z + ((npc->pos.z - playerStatus->pos.z) * 0.5f);
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                }
            }
            disable_player_input();
            partner_disable_input();
            playerStatus->flags |= PS_FLAG_ENTERING_BATTLE;
            if (cond2) {
                start_bounce_a();
            }
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            currentEncounter->scriptedBattle = FALSE;
            sfx_play_sound(0);
            gEncounterState = ENCOUNTER_STATE_PRE_BATTLE;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT;
            break;
        case ENCOUNTER_TRIGGER_HAMMER:
            currentEnemy = enemy = currentEncounter->curEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAG_PROJECTILE) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->hitBytecode != NULL) {
                    enemy->encountered = ENCOUNTER_TRIGGER_HAMMER;
                    script = start_script(enemy->hitBytecode, EVT_PRIORITY_A, 0);
                    enemy->hitScript = script;
                    enemy->hitScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                    npc = get_npc_unsafe(enemy->npcID);
                    testX =  playerStatus->pos.x + ((npc->pos.x - playerStatus->pos.x) * 0.5f);
                    testY = playerStatus->pos.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->pos.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->pos.z + ((npc->pos.z - playerStatus->pos.z) * 0.5f);
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                } else if (!(enemy->flags & ENEMY_FLAG_PASSIVE)) {
                    npc = get_npc_unsafe(enemy->npcID);
                    testX =  playerStatus->pos.x + ((npc->pos.x - playerStatus->pos.x) * 0.5f);
                    testY = playerStatus->pos.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->pos.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->pos.z + ((npc->pos.z - playerStatus->pos.z) * 0.5f);
                    fx_damage_stars(3, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 0.0f, -1.0f, 0.0f, 3);
                }
            }
            disable_player_input();
            partner_disable_input();
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            currentEncounter->scriptedBattle = FALSE;
            playerStatus->flags |= PS_FLAG_ENTERING_BATTLE;
            sfx_play_sound(0);
            gEncounterState = ENCOUNTER_STATE_PRE_BATTLE;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT;
            break;
        case ENCOUNTER_TRIGGER_CONVERSATION:
            suspend_all_group(EVT_GROUP_01);
            enemy = currentEncounter->curEnemy;
            if (enemy != NULL && enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            enemy = currentEncounter->curEnemy;
            if (enemy->interactBytecode != NULL) {
                enemy->encountered = ENCOUNTER_TRIGGER_CONVERSATION;
                script = start_script(enemy->interactBytecode, EVT_PRIORITY_A, 0);
                enemy->interactScript = script;
                enemy->interactScriptID = script->id;
                script->owner1.enemy = enemy;
                script->owner2.npcID = enemy->npcID;
                script->groupFlags = enemy->scriptGroup;
            }
            disable_player_input();
            partner_disable_input();
            set_action_state(ACTION_STATE_TALK);
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            func_800EF3D4(1);
            gEncounterState = ENCOUNTER_STATE_CONVERSATION;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_CONVERSATION_INIT;
            break;
        case ENCOUNTER_TRIGGER_PARTNER:
            currentEnemy = enemy = currentEncounter->curEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->curEncounter;

            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAG_PROJECTILE) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->hitBytecode != NULL) {
                    enemy->encountered = ENCOUNTER_TRIGGER_PARTNER;
                    script = start_script(enemy->hitBytecode, EVT_PRIORITY_A, 0);
                    enemy->hitScript = script;
                    enemy->hitScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                    npc = get_npc_unsafe(enemy->npcID);
                    testX = npc->pos.x;
                    testY = npc->pos.y + npc->collisionHeight;
                    testZ = npc->pos.z;
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                } else if (!(enemy->flags & ENEMY_FLAG_PASSIVE)) {
                    npc = get_npc_unsafe(enemy->npcID);
                    testX = npc->pos.x;
                    testY = npc->pos.y + npc->collisionHeight;
                    testZ = npc->pos.z;
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                }
            }
            disable_player_input();
            partner_disable_input();
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            currentEncounter->scriptedBattle = FALSE;
            playerStatus->flags |= PS_FLAG_ENTERING_BATTLE;
            sfx_play_sound(0);
            gEncounterState = ENCOUNTER_STATE_PRE_BATTLE;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT;
            break;
    }
}

void draw_encounters_neutral(void) {
}

void update_encounters_pre_battle(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerData* playerData = &gPlayerData;
    Encounter* encounter;
    Enemy* enemy;
    s32 i;
    s32 j;

    switch (gEncounterSubState) {
        case ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT:
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 1;
            currentEncounter->fadeOutAccel = 1;
            currentEncounter->unk_08 = -1;
            D_8009A654 = FALSE;
            D_80077C40 = 0;
            suspend_all_group(EVT_GROUP_10);

            for (i = 0; i < currentEncounter->numEncounters; i++) {
                encounter = currentEncounter->encounterList[i];

                if (encounter != NULL) {
                    for (j = 0; j < encounter->count; j++) {
                        enemy = encounter->enemy[j];
                        if (enemy != NULL && !(enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                            if (enemy->aiScript != NULL) {
                                suspend_all_script(enemy->aiScriptID);
                            }
                            if (enemy->auxScript != NULL) {
                                suspend_all_script(enemy->auxScriptID);
                            }
                        }
                    }
                }
            }

            enemy = currentEncounter->curEnemy;
            if ((enemy->flags & ENEMY_FLAG_100000) && !currentEncounter->scriptedBattle) {
                currentEncounter->unk_94 = 0;
                currentEncounter->battleStartCountdown = 0;
                partner_handle_before_battle();
                gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_3;
                return;
            }

            if (gGameStatusPtr->debugEnemyContact == DEBUG_CONTACT_DIE_ON_TOUCH) {
                currentEncounter->unk_94 = 0;
                currentEncounter->battleStartCountdown = 10;
                partner_handle_before_battle();
                gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_AUTO_WIN;
                return;
            }

            enemy = currentEncounter->curEnemy;
            if (currentEncounter->hitType != ENCOUNTER_TRIGGER_NONE
                && currentEncounter->hitType != ENCOUNTER_TRIGGER_SPIN
                && is_ability_active(ABILITY_FIRST_ATTACK)
                && (playerData->level >= enemy->npcSettings->level)
                && !(enemy->flags & ENEMY_FLAG_PROJECTILE)
                && !currentEncounter->scriptedBattle
            ) {
                currentEncounter->unk_94 = 0;
                currentEncounter->battleStartCountdown = 10;
                D_80077C40 = 1;
                gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_AUTO_WIN;
                return;
            }

            enemy = currentEncounter->curEnemy;
            if ((
                    (is_ability_active(ABILITY_BUMP_ATTACK)) &&
                    (playerData->level >= enemy->npcSettings->level) &&
                    (!(enemy->flags & ENEMY_FLAG_PROJECTILE) &&
                    !(currentEncounter->scriptedBattle))
                ) || (
                    (enemy = currentEncounter->curEnemy,
                    (currentEncounter->hitType == ENCOUNTER_TRIGGER_SPIN)) &&
                    (is_ability_active(ABILITY_SPIN_ATTACK)) &&
                    playerData->level >= enemy->npcSettings->level &&
                    !(enemy->flags & ENEMY_FLAG_PROJECTILE) &&
                    !currentEncounter->scriptedBattle
                ))
            {
                currentEncounter->battleStartCountdown = 10;
                D_80077C40 = 1;
                currentEncounter->unk_94 = 0;
                gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_AUTO_WIN;
                return;
            }

            if (currentEncounter->songID < 0) {
                switch (currentEncounter->firstStrikeType) {
                    case 0:
                        bgm_set_battle_song(SONG_NORMAL_BATTLE, FIRST_STRIKE_NONE);
                        break;
                    case 1:
                        bgm_set_battle_song(SONG_NORMAL_BATTLE, FIRST_STRIKE_PLAYER);
                        break;
                    case 2:
                        bgm_set_battle_song(SONG_NORMAL_BATTLE, FIRST_STRIKE_ENEMY);
                        break;
                }
            } else {
                bgm_set_battle_song(currentEncounter->songID, FIRST_STRIKE_NONE);
            }
            bgm_push_battle_song();
            D_8009A654 = TRUE;
            currentEncounter->battleStartCountdown = 10;
            gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_LOAD_BATTLE;
        case ENCOUNTER_SUBSTATE_PRE_BATTLE_LOAD_BATTLE:
            if (currentEncounter->fadeOutAmount == 255) {
                if (currentEncounter->battleStartCountdown != 0) {
                    currentEncounter->battleStartCountdown--;
                    break;
                }

                encounter = currentEncounter->curEncounter;
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    if (enemy != NULL &&
                        ((!(enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) || enemy == currentEncounter->curEnemy)) &&
                        !(enemy->flags & ENEMY_FLAG_DISABLE_AI) &&
                        enemy->hitScript != NULL)
                    {
                        kill_script_by_ID(enemy->hitScriptID);
                        enemy->hitScript = NULL;
                    }
                }

                partner_handle_before_battle();
                currentEncounter->dizzyAttackStatus = 0;
                currentEncounter->dizzyAttackDuration = 0;

                enemy = currentEncounter->curEnemy;
                currentEncounter->instigatorValue = enemy->instigatorValue;

                if (is_ability_active(ABILITY_DIZZY_ATTACK) && currentEncounter->hitType == ENCOUNTER_TRIGGER_SPIN) {
                    currentEncounter->dizzyAttackStatus = 4;
                    currentEncounter->dizzyAttackDuration = 3;
                }

                sfx_stop_sound(SOUND_2111);
                sfx_stop_sound(SOUND_2112);
                sfx_stop_sound(SOUND_2113);
                sfx_stop_sound(SOUND_2114);
                set_battle_formation(NULL);
                set_battle_stage(encounter->stage);
                load_battle(encounter->battle);
                currentEncounter->unk_07 = 1;
                currentEncounter->unk_08 = 0;
                currentEncounter->hasMerleeCoinBonus = FALSE;
                currentEncounter->damageTaken = 0;
                currentEncounter->coinsEarned = 0;
                currentEncounter->fadeOutAccel = 0;
                currentEncounter->fadeOutAmount = 255;
                set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, 255.0f);
                gEncounterState = ENCOUNTER_STATE_POST_BATTLE;
                D_8009A678 = 1;
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_INIT;
            }
            break;
        case ENCOUNTER_SUBSTATE_PRE_BATTLE_AUTO_WIN:
            if (currentEncounter->battleStartCountdown != 0) {
                currentEncounter->battleStartCountdown--;
                break;
            }

            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy != NULL &&
                    (!(enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) || enemy == currentEncounter->curEnemy) &&
                    !(enemy->flags & ENEMY_FLAG_DISABLE_AI) &&
                    (enemy->hitScript != 0))
                {
                    kill_script_by_ID(enemy->hitScriptID);
                    enemy->hitScript = NULL;
                }
            }

            currentEncounter->unk_08 = 1;
            currentEncounter->unk_07 = 1;
            currentEncounter->battleOutcome = OUTCOME_PLAYER_WON;
            currentEncounter->hasMerleeCoinBonus = FALSE;
            currentEncounter->damageTaken = 0;
            gEncounterState = ENCOUNTER_STATE_POST_BATTLE;
            currentEncounter->coinsEarned = 0;
            currentEncounter->fadeOutAccel = 0;
            currentEncounter->fadeOutAmount = 0;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_INIT;
            break;
        case ENCOUNTER_SUBSTATE_PRE_BATTLE_3:
            currentEncounter->battleOutcome = OUTCOME_4;
            currentEncounter->unk_08 = 1;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->fadeOutAccel = 0;
            gEncounterState = ENCOUNTER_STATE_POST_BATTLE;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_INIT;
            break;
    }
}

void draw_encounters_pre_battle(void) {
    EncounterStatus* encounter = &gCurrentEncounter;
    Npc* npc = get_npc_unsafe(encounter->curEnemy->npcID);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (encounter->unk_94 != 0) {
        f32 playerX, playerY, playerZ;
        f32 otherX, otherY, otherZ;
        s32 pScreenX, pScreenY, pScreenZ;
        s32 oScreenX, oScreenY, oScreenZ;

        if (encounter->fadeOutAmount != 255) {
            encounter->fadeOutAccel++;
            if (encounter->fadeOutAccel > 10) {
                encounter->fadeOutAccel = 10;
            }

            encounter->fadeOutAmount += encounter->fadeOutAccel;
            if (encounter->fadeOutAmount > 255) {
                encounter->fadeOutAmount = 255;
            }

            playerX = playerStatus->pos.x;
            playerY = playerStatus->pos.y;
            playerZ = playerStatus->pos.z;

            otherX = npc->pos.x;
            otherY = npc->pos.y;
            otherZ = npc->pos.z;
            if (otherY < -990.0f) {
                otherX = playerX;
                otherY = playerY;
                otherZ = playerZ;
            }

            if (gGameStatusPtr->demoState == DEMO_STATE_CHANGE_MAP) {
                set_screen_overlay_params_back(OVERLAY_START_BATTLE, encounter->fadeOutAmount);
                set_screen_overlay_alpha(SCREEN_LAYER_BACK, 255.0f);
                set_screen_overlay_color(SCREEN_LAYER_BACK, 0, 0, 0);
                get_screen_coords(gCurrentCameraID, playerX, playerY + 20.0f, playerZ, &pScreenX, &pScreenY, &pScreenZ);
                get_screen_coords(gCurrentCameraID, otherX, otherY + 15.0f, otherZ, &oScreenX, &oScreenY, &oScreenZ);
                set_screen_overlay_center(SCREEN_LAYER_BACK, 0, (pScreenX - oScreenX) / 2 + oScreenX,
                                              (pScreenY - oScreenY) / 2 + oScreenY);
            } else {
                set_screen_overlay_params_front(OVERLAY_START_BATTLE, encounter->fadeOutAmount);
                set_screen_overlay_alpha(SCREEN_LAYER_FRONT, 255.0f);
                set_screen_overlay_color(SCREEN_LAYER_FRONT, 0, 0, 0);
                get_screen_coords(gCurrentCameraID, playerX, playerY + 20.0f, playerZ, &pScreenX, &pScreenY, &pScreenZ);
                get_screen_coords(gCurrentCameraID, otherX, otherY + 15.0f, otherZ, &oScreenX, &oScreenY, &oScreenZ);
                set_screen_overlay_center(SCREEN_LAYER_FRONT, 0, (pScreenX - oScreenX) / 2 + oScreenX,
                                              (pScreenY - oScreenY) / 2 + oScreenY);
            }
        }
    }
}

void show_first_strike_message(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 posX;
    s32 width;
    s32 xOffset;
    s32 screenWidthHalf;

    if (currentEncounter->unk_94 == 0) {
        gFirstStrikeMessagePos = -200;
        return;
    }

    gFirstStrikeMessagePos += 40;
    xOffset = gFirstStrikeMessagePos;
    if (xOffset > 0) {
        if (xOffset < 1600) {
            xOffset = 0;
        } else {
            xOffset -= 1600;
        }
    }

    screenWidthHalf = SCREEN_WIDTH / 2;

    switch (currentEncounter->firstStrikeType) {
        case FIRST_STRIKE_PLAYER:
            switch (currentEncounter->hitType) {
                case 2:
                case 4:
                    width = get_msg_width(MSG_Menus_PlayerFirstStrike, 0) + 24;
                    posX = (xOffset + screenWidthHalf) - (width / 2);
                    draw_box(0, WINDOW_STYLE_20, posX, 69, 0, width, 28, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                    draw_msg(MSG_Menus_PlayerFirstStrike, posX + 11, 75, 0xFF, MSG_PAL_STANDARD, 0);
                    break;
                case 6:
                    width = get_msg_width(MSG_Menus_PartnerFirstStrike, 0) + 24;
                    posX = (xOffset + screenWidthHalf) - (width / 2);
                    draw_box(0, WINDOW_STYLE_20, posX, 69, 0, width, 28, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                    draw_msg(MSG_Menus_PartnerFirstStrike, posX + 11, 75, 0xFF, MSG_PAL_STANDARD, 0);
                    break;
            }
            break;
        case FIRST_STRIKE_ENEMY:
            if (!is_ability_active(ABILITY_CHILL_OUT)) {
                width = get_msg_width(MSG_Menus_EnemyFirstStrike, 0) + 24;
                posX = (xOffset + screenWidthHalf) - (width / 2);
                draw_box(0, WINDOW_STYLE_4, posX, 69, 0, width, 28, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                         SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                draw_msg(MSG_Menus_EnemyFirstStrike, posX + 11, 75, 0xFF, MSG_PAL_STANDARD, 0);
            }
            break;
    }
}

void update_encounters_post_battle(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    Encounter* encounter;
    Evt* script;
    Enemy* enemy;
    s32 i, j;
    s32 hasDefeatScript;
    Npc* npc;

    switch (gEncounterSubState) {
        case ENCOUNTER_SUBSTATE_POST_BATTLE_INIT:
            if (currentEncounter->unk_08 == 0) {
                return;
            }

            currentEncounter->unk_08 = 0;
            gPlayerStatus.blinkTimer = 0;
            currentEncounter->scriptedBattle = FALSE;
            func_800E97E4();
            currentEncounter->dizzyAttackStatus = 0;
            currentEncounter->unk_A4 = 0;
            currentEncounter->unk_A8 = 0;
            currentEncounter->unk_AC = 0;
            currentEncounter->dizzyAttackDuration = 0;
            currentEncounter->unk_A6 = 0;
            currentEncounter->unk_AA = 0;
            currentEncounter->unk_AE = 0;
            if (D_8009A654 == TRUE) {
                bgm_pop_battle_song();
            }
            currentEncounter->fadeOutAccel = 1;
            currentEncounter->battleStartCountdown = 0;
            D_8009A670 = FALSE;
            gPlayerStatus.flags &= ~PS_FLAG_ENTERING_BATTLE;
            if (currentEncounter->hitType == ENCOUNTER_TRIGGER_SPIN) {
                D_8009A670 = TRUE;
            }
            currentEncounter->hitType = 0;
            if (D_80077C40 == 0) {
                partner_handle_after_battle();
            }
            D_8009A63C = FALSE;
            if (partnerStatus->shouldResumeAbility) {
                D_8009A63C = TRUE;
            } else if (D_8009A670 == 0 &&
                       !(gPlayerStatus.flags & (PS_FLAG_JUMPING | PS_FLAG_FALLING)) &&
                       gPlayerStatus.actionState != ACTION_STATE_RIDE &&
                       gPlayerStatus.actionState != ACTION_STATE_USE_SPINNING_FLOWER) {
                set_action_state(ACTION_STATE_IDLE);
            }
            switch (currentEncounter->battleOutcome) {
                case OUTCOME_PLAYER_WON:
                    gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_WON_CHECK_MERLEE_BONUS;
                    break;
                case OUTCOME_PLAYER_LOST:
                    gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_INIT;
                    break;
                case OUTCOME_PLAYER_FLED:
                    gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_FLED_INIT;
                    break;
                case OUTCOME_4:
                    gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_300;
                    break;
                case OUTCOME_ENEMY_FLED:
                    gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_INIT;
                    break;
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_WON_CHECK_MERLEE_BONUS:
            if (currentEncounter->hasMerleeCoinBonus) {
                if (get_coin_drop_amount(currentEncounter->curEnemy) != 0) {
                    D_800A0BB0 = start_script(&EVS_MerleeDropCoins, EVT_PRIORITY_A, 0);
                    D_800A0BB0->groupFlags = 0;
                    D_800A0BB4 = D_800A0BB0->id;
                } else {
                    playerData->merleeTurnCount = 0;
                    playerData->merleeCastsLeft++;
                }
            }
            gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_PLAY_NPC_DEFEAT;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_PLAY_NPC_DEFEAT:
            if (currentEncounter->hasMerleeCoinBonus && (get_coin_drop_amount(currentEncounter->curEnemy) != 0)) {
                currentEncounter->fadeOutAccel += 4;
                currentEncounter->fadeOutAmount -= currentEncounter->fadeOutAccel;
                if (currentEncounter->fadeOutAmount < 0) {
                    currentEncounter->fadeOutAmount = 0;
                }
                if (does_script_exist(D_800A0BB4)) {
                    break;
                }
            }
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }
                if (enemy->defeatBytecode != NULL) {
                    script = start_script_in_group(enemy->defeatBytecode, EVT_PRIORITY_A, 0, 0);
                    enemy->defeatScript = script;
                    enemy->defeatScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = 0;
                    currentEncounter->battleStartCountdown = 1;
                } else {
                    script = start_script_in_group(&EVS_NpcDefeat, EVT_PRIORITY_A, 0, 0);
                    enemy->defeatScript = script;
                    enemy->defeatScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = 0;
                }
            }
            if (!(currentEncounter->flags & ENCOUNTER_STATUS_FLAG_1) && !D_8009A63C && currentEncounter->battleStartCountdown == 0 && D_8009A670 == 0) {
                suggest_player_anim_allow_backward(0x10032);
            }
            gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_WON_WAIT;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_WON_WAIT:
            if (currentEncounter->fadeOutAmount == 0) {
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_WON_KILL;
            } else {
                currentEncounter->fadeOutAccel += 4;
                currentEncounter->fadeOutAmount -= currentEncounter->fadeOutAccel;
                if (currentEncounter->fadeOutAmount < 0) {
                    currentEncounter->fadeOutAmount = 0;
                }
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_WON_KILL:
            hasDefeatScript = FALSE;
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }
                if (does_script_exist(enemy->defeatScriptID)) {
                    hasDefeatScript = TRUE;
                } else {
                    enemy->defeatScript = NULL;
                }
            }
            if (!hasDefeatScript) {
                if (!(currentEncounter->flags & ENCOUNTER_STATUS_FLAG_1) && !D_8009A63C && currentEncounter->battleStartCountdown == 1) {
                    suggest_player_anim_allow_backward(ANIM_Mario1_ThumbsUp);
                }
                encounter = currentEncounter->curEncounter;
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    enemy = encounter->enemy[i];
                    if (enemy == NULL) {
                        continue;
                    }
                    if (enemy->flags & ENEMY_FLAG_4) {
                        continue;
                    }
                    if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                        continue;
                    }
                    if (!(enemy->flags & ENEMY_FLAG_PASSIVE)) {
                        if (!(enemy->flags & ENEMY_FLAG_FLED)) {
                            set_defeated(currentEncounter->mapID, encounter->encounterID + i);
                        }
                    }
                    kill_enemy(enemy);
                }

                currentEncounter->unk_94 = 0;
                if (!(currentEncounter->flags & ENCOUNTER_STATUS_FLAG_1) && !D_8009A63C && currentEncounter->battleStartCountdown == 1) {
                    currentEncounter->unk_94 = 30;
                }
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_WON_TO_NEUTRAL;
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_WON_TO_NEUTRAL:
            if (!(currentEncounter->flags & ENCOUNTER_STATUS_FLAG_2) && (gGameStatusPtr->stickX[0] != 0 || gGameStatusPtr->stickY[0] != 0)) {
                currentEncounter->unk_94 = 0;
            }
            if (currentEncounter->unk_94 != 0) {
                currentEncounter->unk_94--;
                break;
            }

            for (i = 0; i < currentEncounter->numEncounters; i++) {
                encounter = currentEncounter->encounterList[i];
                if (encounter == NULL) {
                    continue;
                }
                for (j = 0; j < encounter->count; j++) {
                    enemy = encounter->enemy[j];
                    if (enemy == NULL || (enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                        continue;
                    }
                    if (enemy->aiScript != NULL) {
                        resume_all_script(enemy->aiScriptID);
                    }
                    if (enemy->auxScript != NULL) {
                        resume_all_script(enemy->auxScriptID);
                    }
                }
            }

            currentEncounter->battleTriggerCooldown = 15;
            enable_player_input();
            partner_enable_input();
            if (!D_8009A63C) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            }
            set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
            resume_all_group(EVT_GROUP_10);
            gEncounterState = ENCOUNTER_STATE_NEUTRAL;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_NEUTRAL;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_FLED_INIT:
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }

                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }

                if (enemy->defeatBytecode != NULL) {
                    script = start_script(enemy->defeatBytecode, EVT_PRIORITY_A, 0);
                    enemy->defeatScript = script;
                    enemy->defeatScriptID = script->id;
                    enemy->aiFlags |= 1;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                }
            }
            gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_FLED_WAIT;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_FLED_WAIT:
            if (currentEncounter->fadeOutAmount == 0) {
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_102;
            } else {
                currentEncounter->fadeOutAccel += 4;
                currentEncounter->fadeOutAmount -= currentEncounter->fadeOutAccel;
                if (currentEncounter->fadeOutAmount < 0) {
                    currentEncounter->fadeOutAmount = 0;
                }
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_102:
            encounter = currentEncounter->curEncounter;
            hasDefeatScript = FALSE;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if (!(enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                    if (does_script_exist(enemy->defeatScriptID)) {
                        hasDefeatScript = TRUE;
                    } else {
                        enemy->defeatScript = NULL;
                    }
                }
            }
            if (!hasDefeatScript) {
                for (i = 0; i < currentEncounter->numEncounters; i++) {
                    encounter = currentEncounter->encounterList[i];
                    if (encounter == NULL) {
                        continue;
                    }
                    for (j = 0; j < encounter->count; j++) {
                        enemy = encounter->enemy[j];
                        if (enemy == NULL || (enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                            continue;
                        }
                        if (enemy->aiScript != NULL) {
                            resume_all_script(enemy->aiScriptID);
                        }
                        if (enemy->auxScript != NULL) {
                            resume_all_script(enemy->auxScriptID);
                        }
                    }
                }

                enemy = currentEncounter->curEnemy;
                encounter = currentEncounter->curEncounter;
                if (!(enemy->flags & ENEMY_FLAG_40000)) {
                    enemy->aiSuspendTime = 45;
                    playerStatus->blinkTimer = 45;
                    for (j = 0; j < encounter->count; j++) {
                        enemy = encounter->enemy[j];
                        if (enemy == NULL) {
                            continue;
                        }
                        if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                            continue;
                        }
                        if (enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) {
                            continue;
                        }
                        enemy->aiSuspendTime = 45;
                        playerStatus->blinkTimer = 45;
                    }
                }

                enemy = currentEncounter->curEnemy;
                if (!(currentEncounter->flags & ENCOUNTER_STATUS_FLAG_4)) {
                    script = start_script(&EVS_FleeBattleDrops, EVT_PRIORITY_A, 0);
                    enemy->defeatScript = script;
                    enemy->defeatScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                }

                currentEncounter->battleTriggerCooldown = 45;
                playerStatus->blinkTimer = 45;
                enable_player_input();
                partner_enable_input();
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                if (!D_8009A63C) {
                    currentEncounter->unk_94 = 15;
                } else {
                    currentEncounter->unk_94 = 0;
                }
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_103;
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_103:
            if (currentEncounter->unk_94 != 0) {
                currentEncounter->unk_94--;
                if (gGameStatusPtr->curButtons[0] == 0 && gGameStatusPtr->stickX[0] == 0 && gGameStatusPtr->stickY[0] == 0) {
                    break;
                }
            }
            if (!D_8009A63C && playerStatus->anim == ANIM_MarioB3_Hustled) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
            }
            resume_all_group(EVT_GROUP_10);
            gEncounterState = ENCOUNTER_STATE_NEUTRAL;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_NEUTRAL;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_INIT:
            suggest_player_anim_allow_backward(ANIM_MarioW2_LayingDown);
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }

                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }

                if (enemy->defeatBytecode != NULL) {
                    script = start_script(enemy->defeatBytecode, EVT_PRIORITY_A, 0);
                    enemy->defeatScript = script;
                    enemy->defeatScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                }
            }
            gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_WAIT;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_WAIT:
            if (currentEncounter->fadeOutAmount == 0) {
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_202;
            } else {
                currentEncounter->fadeOutAccel += 4;
                currentEncounter->fadeOutAmount -= currentEncounter->fadeOutAccel;
                if (currentEncounter->fadeOutAmount < 0) {
                    currentEncounter->fadeOutAmount = 0;
                }
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_202:
            hasDefeatScript = FALSE;
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if (!(enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                    if (does_script_exist(enemy->defeatScriptID)) {
                        hasDefeatScript = TRUE;
                    } else {
                        enemy->defeatScript = NULL;
                    }
                }
            }
            if (!hasDefeatScript) {
                for (i = 0; i < currentEncounter->numEncounters; i++) {
                    encounter = currentEncounter->encounterList[i];
                    if (encounter == NULL) {
                        continue;
                    }
                    for (j = 0; j < encounter->count; j++) {
                        enemy = encounter->enemy[j];
                        if (enemy == NULL || (enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                            continue;
                        }
                        if (enemy->aiScript != NULL) {
                            resume_all_script(enemy->aiScriptID);
                        }
                        if (enemy->auxScript != NULL) {
                            resume_all_script(enemy->auxScriptID);
                        }
                    }
                }
                enable_player_input();
                partner_enable_input();
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                currentEncounter->unk_94 = 15;
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_TO_NEUTRAL;
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_LOST_TO_NEUTRAL:
            if (currentEncounter->unk_94 != 0) {
                currentEncounter->unk_94--;
                if (gGameStatusPtr->curButtons[0] == 0 && gGameStatusPtr->stickX[0] == 0 && gGameStatusPtr->stickY[0] == 0) {
                    break;
                }
            }
            resume_all_group(EVT_GROUP_10);
            gEncounterState = ENCOUNTER_STATE_NEUTRAL;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_NEUTRAL;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_300:
            for (i = 0; i < currentEncounter->numEncounters; i++) {
                encounter = currentEncounter->encounterList[i];
                if (encounter == NULL) {
                    continue;
                }
                for (j = 0; j < encounter->count; j++) {
                    enemy = encounter->enemy[j];
                    if (enemy == NULL || (enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                        continue;
                    }
                    if (enemy->aiScript != NULL) {
                        resume_all_script(enemy->aiScriptID);
                    }
                    if (enemy->auxScript != NULL) {
                        resume_all_script(enemy->auxScriptID);
                    }
                }
            }
            enable_player_input();
            partner_enable_input();
            set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
            resume_all_group(EVT_GROUP_10);
            gEncounterState = ENCOUNTER_STATE_NEUTRAL;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_NEUTRAL;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_INIT:
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) && enemy != currentEncounter->curEnemy) {
                    continue;
                }

                if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                    continue;
                }

                if (enemy->defeatBytecode != NULL) {
                    script = start_script(enemy->defeatBytecode, EVT_PRIORITY_A, 0);
                    enemy->defeatScript = script;
                    enemy->defeatScriptID = script->id;
                    script->owner1.enemy = enemy;
                    script->owner2.npcID = enemy->npcID;
                    script->groupFlags = enemy->scriptGroup;
                }
            }
            gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_WAIT;
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_WAIT:
            if (currentEncounter->fadeOutAmount == 0) {
                gEncounterSubState = ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_TO_NEUTRAL;
            } else {
                currentEncounter->fadeOutAccel += 4;
                currentEncounter->fadeOutAmount -= currentEncounter->fadeOutAccel;
                if (currentEncounter->fadeOutAmount < 0) {
                    currentEncounter->fadeOutAmount = 0;
                }
            }
            break;
        case ENCOUNTER_SUBSTATE_POST_BATTLE_ENEMY_FLED_TO_NEUTRAL:
            hasDefeatScript = FALSE;
            encounter = currentEncounter->curEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if (!(enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                    if (does_script_exist(enemy->defeatScriptID)) {
                        hasDefeatScript = TRUE;
                    } else {
                        enemy->defeatScript = NULL;
                    }
                }
            }
            if (!hasDefeatScript) {
                for (i = 0; i < currentEncounter->numEncounters; i++) {
                    encounter = currentEncounter->encounterList[i];
                    if (encounter == NULL) {
                        continue;
                    }
                    for (j = 0; j < encounter->count; j++) {
                        enemy = encounter->enemy[j];
                        if (enemy == NULL || (enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                            continue;
                        }
                        if (enemy->aiScript != NULL) {
                            resume_all_script(enemy->aiScriptID);
                        }
                        if (enemy->auxScript != NULL) {
                            resume_all_script(enemy->auxScriptID);
                        }
                    }
                }

                enemy = currentEncounter->curEnemy;
                if (!(enemy->flags & ENEMY_FLAG_4)) {
                    encounter = currentEncounter->curEncounter;
                    enemy->aiSuspendTime = 45;
                    playerStatus->blinkTimer = 45;
                    for (j = 0; j < encounter->count; j++) {
                        enemy = encounter->enemy[j];
                        if (enemy == NULL) {
                            continue;
                        }
                        if (enemy->flags & ENEMY_FLAG_DISABLE_AI) {
                            continue;
                        }
                        if (enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) {
                            continue;
                        }
                        enemy->aiSuspendTime = 45;
                        playerStatus->blinkTimer = 45;
                    }
                }

                currentEncounter->battleTriggerCooldown = 45;
                enable_player_input();
                partner_enable_input();
                set_screen_overlay_params_front(OVERLAY_NONE, -1.0f);
                resume_all_group(EVT_GROUP_10);
                gEncounterState = ENCOUNTER_STATE_NEUTRAL;
                D_8009A678 = 1;
                gEncounterSubState = ENCOUNTER_SUBSTATE_NEUTRAL;
            }
            break;
    }

    for (i = 0; i < currentEncounter->numEncounters; i++) {
        encounter = currentEncounter->encounterList[i];
        if (encounter == NULL) {
            continue;
        }
        for (j = 0; j < encounter->count; j++) {
            enemy = encounter->enemy[j];
            if (enemy == NULL || (enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                continue;
            }

            npc = get_npc_unsafe(enemy->npcID);
            if (enemy->aiSuspendTime != 0) {
                if (enemy->aiSuspendTime & 1) {
                    npc->flags |= NPC_FLAG_SUSPENDED;
                    enemy->flags |= ENEMY_FLAG_SUSPENDED;
                } else {
                    npc->flags &= ~NPC_FLAG_SUSPENDED;
                    enemy->flags &= ~ENEMY_FLAG_SUSPENDED;
                }
            }
        }
    }
}

void draw_encounters_post_battle(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 ret = currentEncounter->fadeOutAccel;

    if (ret != 0) {
        set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, currentEncounter->fadeOutAmount);
        set_screen_overlay_color(SCREEN_LAYER_FRONT, 0, 0, 0);
    }
}

void update_encounters_conversation(void) {
    EncounterStatus* encounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Enemy* currentEnemy;
    s32 flag;

    switch (gEncounterSubState) {
        case ENCOUNTER_SUBSTATE_CONVERSATION_INIT:
            currentEnemy = encounter->curEnemy;
            flag = FALSE;

            if (currentEnemy->interactScript != NULL) {
                if (does_script_exist(currentEnemy->interactScriptID)) {
                    flag = TRUE;
                } else {
                    currentEnemy->interactScript = NULL;
                }
            }

            if (currentEnemy->hitScript != NULL) {
                if (does_script_exist(currentEnemy->hitScriptID)) {
                    flag = TRUE;
                } else {
                    currentEnemy->hitScript = NULL;
                }
            }

            if (!flag) {
                gEncounterSubState = ENCOUNTER_SUBSTATE_CONVERSATION_END;
            }
            break;
        case ENCOUNTER_SUBSTATE_CONVERSATION_END:
            resume_all_group(EVT_GROUP_01);

            currentEnemy = encounter->curEnemy;
            if (currentEnemy != NULL && currentEnemy->aiScript != NULL) {
                resume_all_script(currentEnemy->aiScriptID);
            }

            enable_player_input();
            partner_enable_input();

            if (playerStatus->actionState == ACTION_STATE_TALK) {
                set_action_state(ACTION_STATE_IDLE);
            }

            func_800EF3D4(0);
            encounter->hitType = 0;
            resume_all_group(EVT_GROUP_10);
            gEncounterState = ENCOUNTER_STATE_NEUTRAL;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_NEUTRAL;
            break;
    }
}

void draw_encounters_conversation(void) {
}

s32 check_conversation_trigger(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    f32 npcX, npcY, npcZ;
    f32 angle;
    f32 deltaX, deltaZ;
    Encounter* encounter;
    f32 playerX, playerY, playerZ;
    f32 playerColliderHeight;
    f32 playerColliderRadius;
    f32 length;
    f32 npcCollisionHeight;
    f32 npcCollisionRadius;
    Encounter* encounterTemp;
    Npc* npc;
    Npc* encounterNpc;
    Enemy* enemy;
    Enemy* encounterEnemy;
    f32 minLength;
    f32 xTemp, yTemp, zTemp;
    s32 i, j;

    playerStatus->encounteredNPC = NULL;
    playerStatus->flags &= ~PS_FLAG_HAS_CONVERSATION_NPC;
    playerColliderHeight = playerStatus->colliderHeight;
    playerColliderRadius = playerStatus->colliderDiameter / 2;
    playerX = playerStatus->pos.x;
    playerY = playerStatus->pos.y;
    playerZ = playerStatus->pos.z;

    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        return FALSE;
    }

    encounter = NULL;
    npc = NULL;
    enemy = NULL;
    minLength = 65535.0f;

    for (i = 0; i < encounterStatus->numEncounters; i++) {
        encounterTemp = encounterStatus->encounterList[i];

        if (encounterTemp == NULL) {
            continue;
        }

        for (j = 0; j < encounterTemp->count; j++) {
            encounterEnemy = encounterTemp->enemy[j];

            if (encounterEnemy == NULL) {
                continue;
            }

            if (encounterEnemy->flags & (ENEMY_FLAG_SUSPENDED | ENEMY_FLAG_DISABLE_AI)) {
                continue;
            }

            if (!(encounterEnemy->flags & ENEMY_FLAG_PASSIVE)) {
                continue;
            }

            if ((encounterEnemy->flags & ENEMY_FLAG_CANT_INTERACT) || encounterEnemy->interactBytecode == NULL) {
                continue;
            }

            encounterNpc = get_npc_unsafe(encounterEnemy->npcID);

            npcX = encounterNpc->pos.x;
            npcY = encounterNpc->pos.y;
            npcZ = encounterNpc->pos.z;
            deltaX = npcX - playerX;
            deltaZ = npcZ - playerZ;
            npcCollisionHeight = encounterNpc->collisionHeight;
            npcCollisionRadius = encounterNpc->collisionDiameter;
            length = sqrtf(SQ(deltaX) + SQ(deltaZ));

            if ((playerColliderRadius + npcCollisionRadius <= length) ||
                (npcY + npcCollisionHeight < playerY) ||
                (playerY + playerColliderHeight < npcY)) {
                continue;
            }

            if (clamp_angle(playerStatus->spriteFacingAngle) < 180.0f) {
                angle = clamp_angle(camera->curYaw - 120.0f);
                if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                    angle = clamp_angle(angle + 60.0f);
                }
            } else {
                angle = clamp_angle(camera->curYaw + 120.0f);
                if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                    angle = clamp_angle(angle - 60.0f);
                }
            }

            if (fabsf(get_clamped_angle_diff(angle, atan2(playerX, playerZ, npcX, npcZ))) > 90.0f) {
                continue;
            }

            if (!(encounterEnemy->flags & ENEMY_FLAG_10000) && encounterNpc->flags & NPC_FLAG_20000000) {
                xTemp = npcX;
                yTemp = npcY;
                zTemp = npcZ;

                if (npc_test_move_taller_with_slipping(0, &xTemp, &yTemp, &zTemp, length,
                                                        atan2(npcX, npcZ, playerX, playerZ),
                                                        npcCollisionHeight,
                                                        2.0f * npcCollisionRadius)) {
                    continue;
                }
            }

            if (length < minLength) {
                minLength = length;
                encounter = encounterTemp;
                npc = encounterNpc;
                enemy = encounterEnemy;
            }
        }
    }

    if (!(playerStatus->animFlags & PA_FLAG_8BIT_MARIO) && npc != NULL && !is_picking_up_item()) {
        playerStatus->encounteredNPC = npc;
        playerStatus->flags |= PS_FLAG_HAS_CONVERSATION_NPC;
        if (playerStatus->pressedButtons & BUTTON_A) {
            close_status_bar();
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_CONVERSATION;
            enemy->encountered = ENCOUNTER_TRIGGER_CONVERSATION;
            encounterStatus->curEncounter = encounter;
            encounterStatus->curEnemy = enemy;
            encounterStatus->firstStrikeType = FIRST_STRIKE_PLAYER;
            return TRUE;
        }
    }
    return FALSE;
}

void create_encounters(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    NpcBlueprint sp10;
    NpcBlueprint* bp = &sp10;
    NpcGroup* groupList = (NpcGroup*)(currentEncounter->npcGroupList);
    s32 groupNpcCount;
    s32 mapID = currentEncounter->mapID;

    Npc* newNpc;
    s32 newNpcIndex;
    s32 npcCount;

    NpcSettings* npcSettings;
    NpcData* npcData;
    Enemy* enemy;
    Encounter* encounter;
    Evt* script;

    s32 totalNpcCount;

    s32 cond1;
    s32 cond2;
    s32 i;
    s32 k;
    s32 e;

    switch (gEncounterSubState) {
        case ENCOUNTER_SUBSTATE_CREATE_INIT:
            if (currentEncounter->resetMapEncounterFlags != 1) {
                // check for current map among most recently visited
                for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps); i++) {
                    if (currentEncounter->recentMaps[i] == mapID) {
                        break;
                    }
                }
                // current map not found in recent: reset all defeat flags
                if (i >= ARRAY_COUNT(currentEncounter->recentMaps)) {
                    for (k = 0; k < ARRAY_COUNT(currentEncounter->defeatFlags[mapID]); k++) {
                        currentEncounter->defeatFlags[mapID][k] = FALSE;
                    }
                }
                // add current map to recent maps, pushing out the least recent
                for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps) - 1; i++) {
                    currentEncounter->recentMaps[i] = currentEncounter->recentMaps[i + 1];
                }
                currentEncounter->recentMaps[i] = mapID;
            }

            e = 0;
            totalNpcCount = 0;
            while (TRUE) {
                if (groupList->npcCount == 0) {
                    break;
                }

                npcData = groupList->npcs;
                groupNpcCount = groupList->npcCount;

                encounter = heap_malloc(sizeof(*encounter));

                currentEncounter->encounterList[e] = encounter;
                ASSERT(encounter != NULL);
                encounter->count = groupNpcCount;
                encounter->battle = groupList->battle;
                encounter->stage = groupList->stage - 1;
                encounter->encounterID = totalNpcCount;
                for (i = 0; i < groupNpcCount; i++) {
                    if (get_defeated(mapID, encounter->encounterID + i)) {
                        npcData++;
                        encounter->enemy[i] = NULL;
                        continue;
                    }

                    enemy = encounter->enemy[i] = heap_malloc(sizeof(*enemy));
                    ASSERT (enemy != NULL);

                    for (k = 0; k < ARRAY_COUNT(enemy->varTable); k++) {
                        enemy->varTable[k] = 0;
                    }
                    enemy->encounterIndex = e;
                    enemy->npcID = npcData->id;
                    npcSettings = enemy->npcSettings = npcData->settings;
                    enemy->drops = &npcData->drops;
                    if ((*(s16*)(&npcData->drops) & 0xFF00) != 0x8000) { //TODO s16?
                        enemy->drops = &DefaultEnemyDrops;
                    }
                    enemy->encountered = 0;
                    if ((s32) npcData->init < EVT_LIMIT) {
                        enemy->initBytecode = npcData->init;
                    } else {
                        enemy->initBytecode = NULL;
                    }
                    enemy->interactBytecode = npcSettings->onInteract;
                    enemy->aiBytecode = npcSettings->ai;
                    enemy->hitBytecode = npcSettings->onHit;
                    enemy->auxBytecode = npcSettings->aux;
                    enemy->defeatBytecode = npcSettings->onDefeat;
                    enemy->initScript = NULL;
                    enemy->interactScript = NULL;
                    enemy->aiScript = NULL;
                    enemy->hitScript = NULL;
                    enemy->auxScript = NULL;
                    enemy->defeatScript = NULL;
                    enemy->interactScriptID = 0;
                    enemy->aiScriptID = 0;
                    enemy->hitScriptID = 0;
                    enemy->auxScriptID = 0;
                    enemy->defeatScriptID = 0;
                    enemy->hitboxIsActive = FALSE;
                    enemy->instigatorValue = 0;
                    enemy->aiDetectFlags = npcData->aiDetectFlags;


                    enemy->aiFlags = npcData->aiFlags;
                    enemy->unk_DC = 0;
                    enemy->aiSuspendTime = 0;
                    enemy->unk_B8 = (EvtScript*)npcSettings->unk_24; // ??
                    enemy->unk_BC = NULL;
                    enemy->unk_C0 = 0;
                    enemy->unk_C4 = 0;

                    enemy->animList = (s32*)&npcData->animations;
                    enemy->territory = &npcData->territory;

                    enemy->flags = npcSettings->flags;
                    enemy->flags |= npcData->flags;
                    enemy->unk_64 = NULL;
                    enemy->tattleMsg = npcData->tattle;
                    if (npcData->initVarCount != 0) {
                        if (npcData->initVarCount == 1) {
                            enemy->varTable[0] = npcData->initVar.value;
                        } else {
                            s32* initialVars = npcData->initVar.array;
                            for (k = 0; k < npcData->initVarCount; k++) {
                                enemy->varTable[k] = *initialVars++;
                            }
                        }
                    }

                    // create the new NPC
                    bp->flags = 0;
                    if (npcSettings->defaultAnim == 0) {
                        bp->initialAnim = enemy->animList[0];
                    } else {
                        bp->initialAnim = npcSettings->defaultAnim;
                    }
                    bp->onUpdate = NULL;
                    bp->onRender = NULL;
                    if (!(enemy->flags & ENEMY_FLAG_USE_PLAYER_SPRITE)) {
                        newNpcIndex = create_standard_npc(bp, npcData->extraAnimations);
                    } else {
                        newNpcIndex = create_peach_npc(bp);
                    }

                    newNpc = get_npc_by_index(newNpcIndex);
                    newNpc->npcID = npcData->id;
                    newNpc->collisionDiameter = npcSettings->radius;
                    newNpc->collisionHeight = npcSettings->height;
                    enemy->spawnPos[0] = newNpc->pos.x = npcData->pos.x;
                    enemy->spawnPos[1] = newNpc->pos.y = npcData->pos.y;
                    enemy->spawnPos[2] = newNpc->pos.z = npcData->pos.z;
                    newNpc->unk_96 = 0;
                    newNpc->planarFlyDist = 0.0f;
                    newNpc->homePos.x = newNpc->pos.x;
                    newNpc->homePos.y = newNpc->pos.y;
                    newNpc->homePos.z = newNpc->pos.z;
                    set_npc_yaw(newNpc, npcData->yaw);
                    enemy->savedNpcYaw = 12345;
                    if (newNpc->collisionDiameter >= 24.0) {
                        newNpc->shadowScale = newNpc->collisionDiameter / 24.0;
                    } else {
                        newNpc->shadowScale = 1.0f;
                    }
                    if (enemy->flags & ENEMY_FLAG_IGNORE_WORLD_COLLISION) {
                        newNpc->flags |= NPC_FLAG_IGNORE_WORLD_COLLISION;
                    }
                    if (enemy->flags & ENEMY_FLAG_IGNORE_PLAYER_COLLISION) {
                        newNpc->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
                    }
                    if (enemy->flags & ENEMY_FLAG_IGNORE_ENTITY_COLLISION) {
                        newNpc->flags |= NPC_FLAG_IGNORE_ENTITY_COLLISION;
                    }
                    if (enemy->flags & ENEMY_FLAG_800) {
                        newNpc->flags |= NPC_FLAG_8;
                    }
                    if (enemy->flags & ENEMY_FLAG_GRAVITY) {
                        newNpc->flags |= NPC_FLAG_GRAVITY;
                    }
                    if (!(enemy->flags & ENEMY_FLAG_PASSIVE)) {
                        newNpc->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
                    }
                    if (enemy->flags & ENEMY_FLAG_HAS_NO_SPRITE) {
                        newNpc->flags |= NPC_FLAG_HAS_NO_SPRITE;
                    }
                    if (enemy->flags & ENEMY_FLAG_NO_SHADOW_RAYCAST) {
                        newNpc->flags |= NPC_FLAG_NO_SHADOW_RAYCAST;
                    }
                    if (enemy->flags & ENEMY_FLAG_8000) {
                        newNpc->flags |= NPC_FLAG_10000000;
                    }
                    if (enemy->flags & ENEMY_FLAG_10000) {
                        newNpc->flags |= NPC_FLAG_20000000;
                    }
                    if (enemy->flags & ENEMY_FLAG_DONT_UPDATE_SHADOW_Y) {
                        newNpc->flags |= NPC_FLAG_DONT_UPDATE_SHADOW_Y;
                    }
                    enemy->scriptGroup = EVT_GROUP_0B;
                    if (enemy->flags & ENEMY_FLAG_PASSIVE) {
                        enemy->scriptGroup = EVT_GROUP_0A;
                    }
                    if (npcSettings->otherAI != NULL) {
                        script = start_script(npcSettings->otherAI, EVT_PRIORITY_A, 0);
                        enemy->aiScript = script;
                        enemy->aiScriptID = script->id;
                        script->owner1.enemy = enemy;
                        script->owner2.npcID = enemy->npcID;
                        script->groupFlags = enemy->scriptGroup;
                    }

                    npcData++;
                }
                groupList++;
                e++;
                totalNpcCount += groupNpcCount;
            }
            currentEncounter->numEncounters = e;
            gEncounterSubState = ENCOUNTER_SUBSTATE_CREATE_RUN_INIT_SCRIPT;
            break;

        case ENCOUNTER_SUBSTATE_CREATE_RUN_INIT_SCRIPT:
            cond2 = FALSE;
            for (e = 0; e < currentEncounter->numEncounters; e++) {
                encounter = currentEncounter->encounterList[e];
                if (encounter == NULL) {
                    continue;
                }
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    if (enemy == NULL) {
                        continue;
                    }
                    if (enemy->aiScript != NULL) {
                        if (does_script_exist(enemy->aiScriptID)) {
                            cond2 = TRUE;
                        }
                    }
                }
            }
            if (!cond2) {
                for (e = 0; e < currentEncounter->numEncounters; e++) {
                    encounter = currentEncounter->encounterList[e];
                    if (encounter == NULL) {
                        continue;
                    }
                    for (i = 0; i < encounter->count; i++) {
                        enemy = encounter->enemy[i];
                        if (enemy == NULL) {
                            continue;
                        }
                        if (enemy->initBytecode != NULL) {
                            script = start_script(enemy->initBytecode, EVT_PRIORITY_A, 0);
                            enemy->initScript = script;
                            enemy->initScriptID = script->id;
                            script->owner1.enemy = enemy;
                            script->owner2.npcID = enemy->npcID;
                            script->groupFlags = enemy->scriptGroup;
                        }
                    }
                }
                gEncounterSubState = ENCOUNTER_SUBSTATE_CREATE_RUN_AI;
            }
            break;

        case ENCOUNTER_SUBSTATE_CREATE_RUN_AI:
            cond1 = FALSE;

            for (e = 0; e < currentEncounter->numEncounters; e++) {
                encounter = currentEncounter->encounterList[e];
                if (encounter == NULL) {
                    continue;
                }
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    if (enemy == NULL) {
                        continue;
                    }
                    if (enemy->initScript != NULL) {
                        if (does_script_exist(enemy->initScriptID)) {
                            cond1 = TRUE;
                        } else {
                            enemy->initScript = NULL;
                        }
                    }
                }
            }

            if (cond1) {
                break;
            }

            for (e = 0; e < currentEncounter->numEncounters; e++) {
                encounter = currentEncounter->encounterList[e];
                if (encounter == NULL) {
                    continue;
                }
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    if (enemy == NULL) {
                        continue;
                    }
                    if (!(enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                        if (enemy->aiBytecode != NULL) {
                            script = start_script(enemy->aiBytecode, EVT_PRIORITY_A, 0);
                            enemy->aiScript = script;
                            enemy->aiScriptID = script->id;
                            enemy->unk_C8 = 100;
                            script->owner1.enemy = enemy;
                            script->owner2.npcID = enemy->npcID;
                            script->groupFlags = enemy->scriptGroup;
                        }
                    }
                }
            }

            for (e = 0; e < currentEncounter->numEncounters; e++) {
                encounter = currentEncounter->encounterList[e];
                if (encounter == NULL) {
                    continue;
                }
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    if (enemy == NULL) {
                        continue;
                    }
                    if (!(enemy->flags & ENEMY_FLAG_DISABLE_AI)) {
                        if (enemy->auxBytecode != NULL) {
                            script = start_script(enemy->auxBytecode, EVT_PRIORITY_A, 0);
                            enemy->auxScript = script;
                            enemy->auxScriptID = script->id;
                            script->owner1.enemy = enemy;
                            script->owner2.npcID = enemy->npcID;
                            script->groupFlags = enemy->scriptGroup;
                        }
                    }
                }
            }
            resume_all_group(EVT_GROUP_10);
            gEncounterState = ENCOUNTER_STATE_NEUTRAL;
            D_8009A678 = 1;
            gEncounterSubState = ENCOUNTER_SUBSTATE_NEUTRAL;
            break;
    }
}

void init_encounters_ui(void) {
}

s32 is_starting_conversation(void) {
    s32 ret = gEncounterState == ENCOUNTER_STATE_PRE_BATTLE;

    if (gCurrentEncounter.hitType == ENCOUNTER_TRIGGER_CONVERSATION) {
        ret = TRUE;
    }
    return ret;
}
