#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "npc.h"
#include "effects.h"
#include "hud_element.h"
#include "world/partners.h"
#include "sprite.h"
#include "sprite/npc/BattleMerlee.h"

ApiStatus ShowMerleeCoinMessage(Evt* script, s32 isInitialCall);
ApiStatus ShowMerleeRanOutMessage(Evt* script, s32 isInitialCall);
ApiStatus FadeInMerlee(Evt* script, s32 isInitialCall);
ApiStatus FadeOutMerlee(Evt* script, s32 isInitialCall);
ApiStatus MerleeUpdateFX(Evt* script, s32 isInitialCall);
ApiStatus MerleeStopFX(Evt* script, s32 isInitialCall);
ApiStatus PlayMerleeGatherFX(Evt* script, s32 isInitialCall);
ApiStatus PlayMerleeOrbFX(Evt* script, s32 isInitialCall);

s32 D_80077C40 = 0;

EvtScript D_80077C44 = {
    EVT_WAIT(10)
    EVT_CALL(FadeBackgroundToBlack)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_100, TRUE)
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

EvtScript SCRIPT_NpcDefeat = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(OnDefeatEnemy)
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript D_80077E9C = {
    EVT_CALL(OnFleeBattleDrops)
    EVT_RETURN
    EVT_END
};

EnemyDrops D_80077EB8 = {
    .dropFlags = NPC_DROP_FLAGS_80,
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
            EVT_CALL(SetEnemyFlagBits, -1, ENEMY_FLAGS_10, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

extern s8 D_8009A654;
extern s16 D_8009A668;
extern s32 D_800A0BA0;
extern f32 D_800A0BA4;
extern EffectInstance* WorldMerleeOrbEffect;
extern EffectInstance* WorldMerleeWaveEffect;

void set_battle_formation(Battle*);

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
        mdl_set_all_fog_mode(1);
        *gBgRenderTypePtr = BACKGROUND_RENDER_TYPE_1;
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
        WorldMerleeOrbEffect->flags |= EFFECT_INSTANCE_FLAGS_10;
        WorldMerleeWaveEffect->flags |= EFFECT_INSTANCE_FLAGS_10;
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
        npc->flags &= ~NPC_FLAG_2;
    } else {
        npc->flags |= NPC_FLAG_2;
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
        npc->flags |= NPC_FLAG_2;
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
                make_item_entity_delayed(ITEM_COIN, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight,
                                         playerStatus->position.z, 3, 0, 0);
            }
        }
        script->functionTemp[2] = 0;
    }

    return --script->functionTemp[1] == 0;
}

/// Default/neutral state during world gameplay; checks for player-enemy collisions and initiates battles when they occur.
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

    s32 cond;
    s32 cond2;
    s32 firstStrikeType;
    s32 aiPaused;

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
    currentEncounter->dropWhackaBump = 0;
    currentEncounter->flags &= ~ENCOUNTER_STATUS_FLAGS_1;
    currentEncounter->flags &= ~ENCOUNTER_STATUS_FLAGS_2;
    currentEncounter->flags &= ~ENCOUNTER_STATUS_FLAGS_4;

    playerX = playerStatus->position.x;
    playerY = playerStatus->position.y;
    playerZ = playerStatus->position.z;
    playerYaw = playerStatus->spriteFacingAngle;

    if (playerYaw < 180.0f) {
        playerYaw = clamp_angle(camera->currentYaw - 90.0f);
    } else {
        playerYaw = clamp_angle(camera->currentYaw + 90.0f);
    }

    if (currentEncounter->battleTriggerCooldown != 0) {
        if (!(gOverrideFlags & GLOBAL_OVERRIDES_40)) {
            currentEncounter->battleTriggerCooldown--;
        }
        if (playerStatus->blinkTimer != 0) {
            if (!(playerStatus->flags & PS_FLAGS_INPUT_DISABLED)) {
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
            if (enemy == NULL || (enemy->flags & ENEMY_FLAGS_20)) {
                continue;
            }
            npc = get_npc_unsafe(enemy->npcID);
            if (enemy->aiPaused != 0) {
                if (!(gOverrideFlags & GLOBAL_OVERRIDES_40)) {
                    enemy->aiPaused--;
                    aiPaused = enemy->aiPaused;
                } else {
                    aiPaused = 0;
                }

                if (aiPaused & 1) {
                    npc->flags |= NPC_FLAG_80000000;
                    enemy->flags |= ENEMY_FLAGS_80000000;
                } else {
                    npc->flags &= ~NPC_FLAG_80000000;
                    enemy->flags &= ~ENEMY_FLAGS_80000000;
                }
                script = get_script_by_id(enemy->auxScriptID);
                if (script != NULL) {
                    set_script_flags(script, EVT_FLAG_80);
                }
                script = get_script_by_id(enemy->aiScriptID);
                if (script != NULL) {
                    set_script_flags(script, EVT_FLAG_80);
                }
                if (enemy->flags & 0x80000) {
                    script = get_script_by_id(enemy->auxScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_80);
                    }
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_80);
                    }
                }
            } else if (!(enemy->flags & ENEMY_FLAGS_200000)) {
                get_screen_coords(gCurrentCameraID, npc->pos.x, npc->pos.y, npc->pos.z, &screenX, &screenY, &screenZ);
                if ((screenX < -160 || screenX > 480 || screenY < -120 || screenY > 360 || screenZ < 0) && !(enemy->flags & ENEMY_FLAGS_1)) {
                    npc->flags |= NPC_FLAG_80000000;
                    enemy->flags |= ENEMY_FLAGS_80000000;
                    script = get_script_by_id(enemy->auxScriptID);
                    if (script != NULL) {
                        set_script_flags(script, EVT_FLAG_80);
                    }
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        set_script_flags(script, EVT_FLAG_80);
                    }
                } else {
                    npc->flags &= ~NPC_FLAG_80000000;
                    enemy->flags &= ~ENEMY_FLAGS_80000000;
                    script = get_script_by_id(enemy->auxScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_80);
                    }
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_80);
                    }
                }
            } else {
                npc->flags &= ~NPC_FLAG_80000000;
                enemy->flags &= ~ENEMY_FLAGS_80000000;
                script = get_script_by_id(enemy->auxScriptID);
                if (script != NULL) {
                    clear_script_flags(script, EVT_FLAG_80);
                }
                script = get_script_by_id(enemy->aiScriptID);
                if (script != NULL) {
                    clear_script_flags(script, EVT_FLAG_80);
                }
            }

            if (enemy->flags & ENEMY_FLAGS_80000000) {
                continue;
            }
            if (enemy->flags & ENEMY_FLAGS_1) {
                if (!(enemy->flags & ENEMY_FLAGS_400000)) {
                    if (npc == playerStatus->encounteredNPC) {
                        enemy->unk_E0 = npc->yaw;
                        npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                        script = get_script_by_id(enemy->aiScriptID);
                        if (script != NULL) {
                            set_script_flags(script, EVT_FLAG_80);
                        }
                    } else {
                        if (enemy->unk_E0 != 12345) {
                            npc->yaw = enemy->unk_E0;
                            enemy->unk_E0 = 12345;
                        }
                        script = get_script_by_id(enemy->aiScriptID);
                        if (script != NULL) {
                            clear_script_flags(script, EVT_FLAG_80);
                        }
                    }
                } else {
                    script = get_script_by_id(enemy->aiScriptID);
                    if (script != NULL) {
                        clear_script_flags(script, EVT_FLAG_80);
                    }
                }
            }

            if (currentEncounter->battleTriggerCooldown != 0 ||
                gGameStatusPtr->debugEnemyContact == 1 ||
                (playerStatus->flags & PS_FLAGS_80000) ||
                (gOverrideFlags & GLOBAL_OVERRIDES_40) ||
                gPartnerActionStatus.actingPartner == PARTNER_BOW ||
                (enemy->flags & ENEMY_FLAGS_1) ||
                (gOverrideFlags & (GLOBAL_OVERRIDES_DISABLE_BATTLES | GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_800)) ||
                is_picking_up_item()) {
                continue;
            }
            do {
                if (!(enemy->flags & ENEMY_FLAGS_10000000) && partner_test_enemy_collision(npc) != 0) {
                    currentEncounter->hitType = ENCOUNTER_TRIGGER_PARTNER;
                    enemy->encountered = ENCOUNTER_TRIGGER_PARTNER;
                    currentEncounter->currentEncounter = encounter;
                    currentEncounter->currentEnemy = enemy;
                    currentEncounter->firstStrikeType = FIRST_STRIKE_PLAYER;
                    goto START_BATTLE;
                }
            } while (0);

            npcX = npc->pos.x;
            npcY = npc->pos.y;
            npcZ = npc->pos.z;
            npcYaw = npc->yaw;
            colHeight = npc->collisionHeight;
            colRadius = npc->collisionRadius / 2;

            if (enemy->unk_DC != 0) {
                npcYaw = npc->yawCamOffset;
                if (npcYaw < 180.0f) {
                    npcYaw = clamp_angle(camera->currentYaw - 90.0f);
                } else {
                    npcYaw = clamp_angle(camera->currentYaw + 90.0f);
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
                        hammerDir = clamp_angle(camera->currentYaw - 90.0f);
                        if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                            hammerDir = clamp_angle(hammerDir + 30.0f);
                        }
                    } else {
                        hammerDir = clamp_angle(camera->currentYaw + 90.0f);
                        if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                            hammerDir = clamp_angle(hammerDir - 30.0f);
                        }
                    }
                    add_vec2D_polar(&x, &z, 24.0f, hammerDir);
                    dx = npcX - x;
                    dz = npcZ - z;
                    distance = sqrtf(SQ(dx) + SQ(dz));
                    if (enemy->flags & ENEMY_FLAGS_IGNORE_HAMMER) {
                        break;
                    }
                    if (!(playerStatus->flags & PS_FLAGS_1000000)) {
                        break;
                    }
                    if (distance >= playerColRadius + colRadius || y > npcY + colHeight || npcY > y + playerColHeight) {
                        break;
                    }

                    testX = npcX;
                    testY = npcY;
                    testZ = npcZ;

                    if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(npcX, npcZ, playerX, playerZ), colHeight, colRadius * 2.0f) != 0) {
                        testX = playerX;
                        testY = playerY;
                        testZ = playerZ;
                        if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(playerX, playerZ, npcX, npcZ), colHeight, colRadius * 2.0f) != 0) {
                            break;
                        }
                    }
                    if (enemy->unk_07 != 0) {
                        npcX = enemy->unk_10.x;
                        npcY = enemy->unk_10.y;
                        npcZ = enemy->unk_10.z;
                    }

                    angle1 = fabsf(get_clamped_angle_diff(atan2(playerX, playerZ, npcX, npcZ), playerYaw));
                    angle2 = fabsf(get_clamped_angle_diff(atan2(npcX, npcZ, playerX, playerZ), npcYaw));
                    cond = FALSE;
                    if (angle1 >= 90.0f && angle2 >= 90.0f) {
                        cond = FALSE;
                    }
                    if (angle1 < 90.0f && angle2 >= 90.0f) {
                        cond = TRUE;
                    }
                    if (angle1 >= 90.0f && angle2 < 90.0f) {
                        cond = FALSE;
                    }
                    if (angle1 < 90.0f && angle2 < 90.0f) {
                        cond = TRUE;
                    }
                    if (cond) {
                        sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, 0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
                        currentEncounter->hitType = ENCOUNTER_TRIGGER_HAMMER;
                        currentEncounter->hitTier = gPlayerData.hammerLevel;
                        enemy->encountered = ENCOUNTER_TRIGGER_HAMMER;
                        currentEncounter->currentEncounter = encounter;
                        currentEncounter->currentEnemy = enemy;
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
                    if (!(enemy->flags & ENEMY_FLAGS_IGNORE_JUMP)) {
                        if (distance >= playerColRadius + colRadius) {
                            continue;
                        }
                        if (playerY > npcY + colHeight || npcY > playerY + playerJumpColHeight) {
                            continue;
                        }

                        testX = npcX;
                        testY = npcY;
                        testZ = npcZ;
                        if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(npcX, npcZ, playerX, playerZ), colHeight, colRadius * 2.0f) != 0) {
                            testX = playerX;
                            testY = playerY;
                            testZ = playerZ;
                            if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(playerX, playerZ, npcX, npcZ), colHeight, colRadius * 2.0f) != 0) {
                                break;
                            }
                        }
                        cond = FALSE;
                        if (npcY + colHeight < playerY + playerJumpColHeight * 0.5f) {
                            if (playerStatus->actionState == ACTION_STATE_FALLING ||
                                playerStatus->actionState == ACTION_STATE_STEP_DOWN ||
                                playerStatus->actionState == ACTION_STATE_LAND ||
                                playerStatus->actionState == ACTION_STATE_STEP_DOWN_LAND ||
                                playerStatus->actionState == ACTION_STATE_SPIN_JUMP ||
                                playerStatus->actionState == ACTION_STATE_SPIN_POUND ||
                                playerStatus->actionState == ACTION_STATE_TORNADO_JUMP ||
                                playerStatus->actionState == ACTION_STATE_TORNADO_POUND) {
                                cond = TRUE;
                            }
                        }
                        if (playerY + playerJumpColHeight < npcY + colHeight * 0.5f) {
                            cond = FALSE;
                        }
                        if (cond) {
                            if (gPlayerData.bootsLevel < 0) {
                                currentEncounter->hitType = ENCOUNTER_TRIGGER_NONE;
                                enemy->encountered = ENCOUNTER_TRIGGER_NONE;
                                currentEncounter->currentEncounter = encounter;
                                currentEncounter->currentEnemy = enemy;
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
                            sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, 0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
                            enemy->encountered = 2;
                            currentEncounter->currentEncounter = encounter;
                            currentEncounter->currentEnemy = enemy;
                            currentEncounter->firstStrikeType = FIRST_STRIKE_PLAYER;
                            goto START_BATTLE;
                        }
                    }
                    break;
            }

            if (enemy->flags & ENEMY_FLAGS_IGNORE_TOUCH) {
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
            if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(npcX, npcZ, playerX, playerZ), colHeight, colRadius * 2.0f) != 0) {
                testX = playerX;
                testY = playerY;
                testZ = playerZ;
                if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_10000, &testX, &testY, &testZ, distance, atan2(playerX, playerZ, npcX, npcZ), colHeight, colRadius * 2.0f) != 0) {
                    continue;
                }
            }
            cond = FALSE;
            if (is_ability_active(ABILITY_SPIN_ATTACK) && gPlayerData.level >= enemy->npcSettings->level) {
                cond = currentEncounter->unk_12 == 0;
            }
            if (is_ability_active(ABILITY_DIZZY_ATTACK)) {
                cond = TRUE;
            }
            if ((playerStatus->animFlags & PA_FLAGS_SPINNING) && !(enemy->flags & ENEMY_FLAGS_20000000) && cond) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, 0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
                testX = playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                testY = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                testZ = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                currentEncounter->hitType = ENCOUNTER_TRIGGER_SPIN;
                playerStatus->animFlags |= PA_FLAGS_20000;
                enemy->encountered = ENCOUNTER_TRIGGER_SPIN;
                currentEncounter->currentEncounter = encounter;
                currentEncounter->currentEnemy = enemy;
                currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
            } else {
                currentEncounter->hitType = ENCOUNTER_TRIGGER_NONE;
                playerStatus->animFlags &= ~PA_FLAGS_20000;
                enemy->encountered = ENCOUNTER_TRIGGER_NONE;
                currentEncounter->currentEncounter = encounter;
                currentEncounter->currentEnemy = enemy;
                testX = playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                testY = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                testZ = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                firstStrikeType = FIRST_STRIKE_NONE;
                if (enemy->unk_07 != 0) {
                    if (is_ability_active(ABILITY_CHILL_OUT)) {
                        firstStrikeType = FIRST_STRIKE_NONE;
                    } else {
                        firstStrikeType = FIRST_STRIKE_ENEMY;
                    }
                }
                if (!is_ability_active(ABILITY_BUMP_ATTACK) || gPlayerData.level < enemy->npcSettings->level || (enemy->flags & ENEMY_FLAGS_40)) {
                    currentEncounter->firstStrikeType = firstStrikeType;
                } else {
                    if (currentEncounter->unk_12 == 0) {
                        firstStrikeType = FIRST_STRIKE_NONE;
                    }
                    currentEncounter->firstStrikeType = firstStrikeType;
                }
            }
            goto START_BATTLE;
        }
    }

START_BATTLE:
    switch (currentEncounter->hitType) {
        case 0:
            break;
        case ENCOUNTER_TRIGGER_NONE:
            currentEnemy = enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAGS_8) && enemy != currentEncounter->currentEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAGS_20) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAGS_40) && enemy != currentEncounter->currentEnemy) {
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
                playerStatus->flags |= PS_FLAGS_40000;
            }
            if (!is_ability_active(ABILITY_CHILL_OUT) && currentEncounter->firstStrikeType == FIRST_STRIKE_ENEMY) {
                set_action_state(ACTION_STATE_ENEMY_FIRST_STRIKE);
                npc = get_npc_unsafe(enemy->npcID);
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, 0, npc->pos.x, npc->pos.y, npc->pos.z);
            }
            currentEncounter->unk_12 = 0;
            gGameState = 3;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case ENCOUNTER_TRIGGER_SPIN:
            currentEnemy = enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAGS_8) && enemy != currentEncounter->currentEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAGS_20) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAGS_40) && enemy != currentEncounter->currentEnemy) {
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
            currentEncounter->unk_12 = 0;
            gGameState = 3;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            playerStatus->flags |= PS_FLAGS_40000;
            break;
        case ENCOUNTER_TRIGGER_JUMP:
            currentEnemy = enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;

            cond2 = FALSE;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAGS_8) && enemy != currentEncounter->currentEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAGS_20) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAGS_40) && enemy != currentEncounter->currentEnemy) {
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
                    testX =  playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                    testY = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                } else if (!(enemy->flags & ENEMY_FLAGS_1)) {
                    npc = get_npc_unsafe(enemy->npcID);
                    cond2 = TRUE;
                    testX =  playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                    testY = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                }
            }
            disable_player_input();
            partner_disable_input();
            playerStatus->flags |= PS_FLAGS_40000;
            if (cond2) {
                start_bounce_a();
            }
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            currentEncounter->unk_12 = 0;
            sfx_play_sound(0);
            gGameState = 3;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case ENCOUNTER_TRIGGER_HAMMER:
            currentEnemy = enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAGS_8) && enemy != currentEncounter->currentEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAGS_20) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAGS_40) && enemy != currentEncounter->currentEnemy) {
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
                    testX =  playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                    testY = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                    fx_damage_stars(3, testX, testY, testZ, 0.0f, -1.0f, 0.0f, 3);
                } else if (!(enemy->flags & ENEMY_FLAGS_1)) {
                    npc = get_npc_unsafe(enemy->npcID);
                    testX =  playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                    testY = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                    testZ = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                    fx_damage_stars(3, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 0.0f, -1.0f, 0.0f, 3);
                }
            }
            disable_player_input();
            partner_disable_input();
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            currentEncounter->unk_12 = 0;
            playerStatus->flags |= PS_FLAGS_40000;
            sfx_play_sound(0);
            gGameState = 3;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case ENCOUNTER_TRIGGER_CONVERSATION:
            suspend_all_group(1);
            enemy = currentEncounter->currentEnemy;
            if (enemy != NULL && enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            enemy = currentEncounter->currentEnemy;
            if (enemy->interactBytecode != NULL) {
                enemy->encountered = 5;
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
            gGameState = 4;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case ENCOUNTER_TRIGGER_PARTNER:
            currentEnemy = enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;

            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy == NULL) {
                    continue;
                }
                if ((enemy->flags & ENEMY_FLAGS_8) && enemy != currentEncounter->currentEnemy) {
                    continue;
                }
                if (enemy->flags & ENEMY_FLAGS_20) {
                    continue;
                }
                if ((currentEnemy->flags & ENEMY_FLAGS_40) && enemy != currentEncounter->currentEnemy) {
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
                } else if (!(enemy->flags & ENEMY_FLAGS_1)) {
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
            currentEncounter->unk_12 = 0;
            playerStatus->flags |= PS_FLAGS_40000;
            sfx_play_sound(0);
            gGameState = 3;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
    }
}

static const f32 padding = 0;

void draw_encounters_neutral(void) {
}

void update_encounters_pre_battle(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerData* playerData = &gPlayerData;
    Encounter* encounter;
    Enemy* enemy;
    s32 i;
    s32 j;

    switch (D_8009A5D0) {
        case 0:
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 1;
            currentEncounter->fadeOutAccel = 1;
            currentEncounter->unk_08 = -1;
            D_8009A654 = 0;
            D_80077C40 = 0;
            suspend_all_group(0x10);

            for (i = 0; i < currentEncounter->numEncounters; i++) {
                encounter = currentEncounter->encounterList[i];

                if (encounter != NULL) {
                    for (j = 0; j < encounter->count; j++) {
                        enemy = encounter->enemy[j];
                        if (enemy != NULL && !(enemy->flags & NPC_FLAG_NO_AI)) {
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

            enemy = currentEncounter->currentEnemy;
            if ((enemy->flags & NPC_FLAG_MOTION_BLUR) && currentEncounter->unk_12 == 0) {
                currentEncounter->unk_94 = 0;
                currentEncounter->battleStartCountdown = 0;
                partner_handle_before_battle();
                D_8009A5D0 = 3;
                return;
            }

            if (gGameStatusPtr->debugEnemyContact == 2) {
                currentEncounter->unk_94 = 0;
                currentEncounter->battleStartCountdown = 10;
                partner_handle_before_battle();
                D_8009A5D0 = 2;
                return;
            }

            enemy = currentEncounter->currentEnemy;
            if (currentEncounter->hitType != 1 &&
                currentEncounter->hitType != 3 &&
                is_ability_active(ABILITY_FIRST_ATTACK) &&
                (playerData->level >= enemy->npcSettings->level) &&
                !(enemy->flags & ENEMY_FLAGS_40) &&
                currentEncounter->unk_12 == 0)
            {
                currentEncounter->unk_94 = 0;
                currentEncounter->battleStartCountdown = 0xA;
                D_80077C40 = 1;
                D_8009A5D0 = 2;
                return;
            }

            enemy = currentEncounter->currentEnemy;
            if ((
                    (is_ability_active(ABILITY_BUMP_ATTACK)) &&
                    (playerData->level >= enemy->npcSettings->level) &&
                    (!(enemy->flags & ENEMY_FLAGS_40) &&
                    (currentEncounter->unk_12 == 0))
                ) || (
                    (enemy = currentEncounter->currentEnemy,
                    (currentEncounter->hitType == 3)) &&
                    (is_ability_active(ABILITY_SPIN_ATTACK)) &&
                    playerData->level >= enemy->npcSettings->level &&
                    !(enemy->flags & ENEMY_FLAGS_40) &&
                    currentEncounter->unk_12 == 0
                ))
            {
                currentEncounter->battleStartCountdown = 10;
                D_80077C40 = 1;
                currentEncounter->unk_94 = 0;
                D_8009A5D0 = 2;
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
            D_8009A654 = 1;
            currentEncounter->battleStartCountdown = 10;
            D_8009A5D0 = 1;
        case 1:
            if (currentEncounter->fadeOutAmount == 255) {
                if (currentEncounter->battleStartCountdown != 0) {
                    currentEncounter->battleStartCountdown--;
                    break;
                }

                encounter = currentEncounter->currentEncounter;
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    if (enemy != NULL &&
                        ((!(enemy->flags & NPC_FLAG_ENABLE_HIT_SCRIPT) || enemy == currentEncounter->currentEnemy)) &&
                        !(enemy->flags & NPC_FLAG_NO_AI) &&
                        enemy->hitScript != NULL)
                    {
                        kill_script_by_ID(enemy->hitScriptID);
                        enemy->hitScript = NULL;
                    }
                }

                partner_handle_before_battle();
                currentEncounter->dizzyAttackStatus = 0;
                currentEncounter->dizzyAttackDuration = 0;

                enemy = currentEncounter->currentEnemy;
                currentEncounter->unk_10 = enemy->unk_B5;

                if (is_ability_active(ABILITY_DIZZY_ATTACK) && currentEncounter->hitType == 3) {
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
                currentEncounter->merleeCoinBonus = 0;
                currentEncounter->damageTaken = 0;
                currentEncounter->coinsEarned = 0;
                currentEncounter->fadeOutAccel = 0;
                currentEncounter->fadeOutAmount = 255;
                set_screen_overlay_params_front(0, 255.0f);
                gGameState = 5;
                D_8009A678 = 1;
                D_8009A5D0 = 0;
            }
            break;
        case 2:
            if (currentEncounter->battleStartCountdown != 0) {
                currentEncounter->battleStartCountdown--;
                break;
            }

            encounter = currentEncounter->currentEncounter;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy != NULL &&
                    (!(enemy->flags & NPC_FLAG_ENABLE_HIT_SCRIPT) || enemy == currentEncounter->currentEnemy) &&
                    !(enemy->flags & NPC_FLAG_NO_AI) &&
                    (enemy->hitScript != 0))
                {
                    kill_script_by_ID(enemy->hitScriptID);
                    enemy->hitScript = NULL;
                }
            }

            currentEncounter->unk_08 = 1;
            currentEncounter->unk_07 = 1;
            currentEncounter->battleOutcome = 0;
            currentEncounter->merleeCoinBonus = 0;
            currentEncounter->damageTaken = 0;
            gGameState = 5;
            currentEncounter->coinsEarned = 0;
            currentEncounter->fadeOutAccel = 0;
            currentEncounter->fadeOutAmount = 0;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case 3:
            currentEncounter->battleOutcome = 4;
            currentEncounter->unk_08 = 1;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->fadeOutAccel = 0;
            gGameState = 5;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
    }
}

void draw_encounters_pre_battle(void) {
    EncounterStatus* encounter = &gCurrentEncounter;
    Npc* npc = get_npc_unsafe(encounter->currentEnemy->npcID);
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

            playerX = playerStatus->position.x;
            playerY = playerStatus->position.y;
            playerZ = playerStatus->position.z;

            otherX = npc->pos.x;
            otherY = npc->pos.y;
            otherZ = npc->pos.z;
            if (otherY < -990.0f) {
                otherX = playerX;
                otherY = playerY;
                otherZ = playerZ;
            }

            if (gGameStatusPtr->demoState == 2) {
                set_screen_overlay_params_back(10, encounter->fadeOutAmount);
                set_screen_overlay_alpha(1, 255.0f);
                set_screen_overlay_color(1, 0, 0, 0);
                get_screen_coords(gCurrentCameraID, playerX, playerY + 20.0f, playerZ, &pScreenX, &pScreenY, &pScreenZ);
                get_screen_coords(gCurrentCameraID, otherX, otherY + 15.0f, otherZ, &oScreenX, &oScreenY, &oScreenZ);
                set_screen_overlay_center(1, 0, (pScreenX - oScreenX) / 2 + oScreenX,
                                              (pScreenY - oScreenY) / 2 + oScreenY);
            } else {
                set_screen_overlay_params_front(10, encounter->fadeOutAmount);
                set_screen_overlay_alpha(0, 255.0f);
                set_screen_overlay_color(0, 0, 0, 0);
                get_screen_coords(gCurrentCameraID, playerX, playerY + 20.0f, playerZ, &pScreenX, &pScreenY, &pScreenZ);
                get_screen_coords(gCurrentCameraID, otherX, otherY + 15.0f, otherZ, &oScreenX, &oScreenY, &oScreenZ);
                set_screen_overlay_center(0, 0, (pScreenX - oScreenX) / 2 + oScreenX,
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
        D_8009A668 = -200;
        return;
    }

    D_8009A668 += 40;
    xOffset = D_8009A668;
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
                    width = get_msg_width(0x1D00AC, 0) + 24;
                    posX = (xOffset + screenWidthHalf) - (width / 2);
                    draw_box(0, 0x14, posX, 69, 0, width, 28, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                    draw_msg(0x1D00AC, posX + 11, 75, 0xFF, 0xA, 0);
                    break;
                case 6:
                    width = get_msg_width(0x1D00AD, 0) + 24;
                    posX = (xOffset + screenWidthHalf) - (width / 2);
                    draw_box(0, 0x14, posX, 69, 0, width, 28, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                    draw_msg(0x1D00AD, posX + 11, 75, 0xFF, 0xA, 0);
                    break;
            }
            break;
        case FIRST_STRIKE_ENEMY:
            if (!is_ability_active(ABILITY_CHILL_OUT)) {
                width = get_msg_width(0x1D00AE, 0) + 24;
                posX = (xOffset + screenWidthHalf) - (width / 2);
                draw_box(0, 4, posX, 69, 0, width, 28, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, 0, NULL,
                         SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
                draw_msg(0x1D00AE, posX + 11, 75, 0xFF, 0xA, 0);
            }
            break;
    }
}

INCLUDE_ASM(s32, "1a1f0_len_5390", update_encounters_post_battle);

void draw_encounters_post_battle(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 ret = currentEncounter->fadeOutAccel;

    if (ret != 0) {
        set_screen_overlay_params_front(0, currentEncounter->fadeOutAmount);
        set_screen_overlay_color(0, 0, 0, 0);
    }
}

void update_encounters_conversation(void) {
    EncounterStatus* encounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Enemy* currentEnemy;
    s32 flag;

    switch (D_8009A5D0) {
        case 0:
            currentEnemy = encounter->currentEnemy;
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
                D_8009A5D0 = 1;
            }
            break;
        case 1:
            resume_all_group(1);

            currentEnemy = encounter->currentEnemy;
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
            resume_all_group(16);
            gGameState = 2;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
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
    playerStatus->flags &= ~PS_FLAGS_HAS_CONVERSATION_NPC;
    playerColliderHeight = playerStatus->colliderHeight;
    playerColliderRadius = playerStatus->colliderDiameter / 2;
    playerX = playerStatus->position.x;
    playerY = playerStatus->position.y;
    playerZ = playerStatus->position.z;

    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) {
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

            if (encounterEnemy->flags & (ENEMY_FLAGS_80000000 | ENEMY_FLAGS_20)) {
                continue;
            }

            if (!(encounterEnemy->flags & ENEMY_FLAGS_1)) {
                continue;
            }

            if ((encounterEnemy->flags & ENEMY_FLAGS_8000000) || encounterEnemy->interactBytecode == NULL) {
                continue;
            }

            encounterNpc = get_npc_unsafe(encounterEnemy->npcID);

            npcX = encounterNpc->pos.x;
            npcY = encounterNpc->pos.y;
            npcZ = encounterNpc->pos.z;
            deltaX = npcX - playerX;
            deltaZ = npcZ - playerZ;
            npcCollisionHeight = encounterNpc->collisionHeight;
            npcCollisionRadius = encounterNpc->collisionRadius;
            length = sqrtf(SQ(deltaX) + SQ(deltaZ));

            if ((playerColliderRadius + npcCollisionRadius <= length) ||
                (npcY + npcCollisionHeight < playerY) ||
                (playerY + playerColliderHeight < npcY)) {
                continue;
            }

            if (clamp_angle(playerStatus->spriteFacingAngle) < 180.0f) {
                angle = clamp_angle(camera->currentYaw - 120.0f);
                if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                    angle = clamp_angle(angle + 60.0f);
                }
            } else {
                angle = clamp_angle(camera->currentYaw + 120.0f);
                if (playerStatus->trueAnimation & SPRITE_ID_BACK_FACING) {
                    angle = clamp_angle(angle - 60.0f);
                }
            }

            if (fabsf(get_clamped_angle_diff(angle, atan2(playerX, playerZ, npcX, npcZ))) > 90.0f) {
                continue;
            }

            if (!(encounterEnemy->flags & ENEMY_FLAGS_10000) && encounterNpc->flags & NPC_FLAG_20000000) {
                xTemp = npcX;
                yTemp = npcY;
                zTemp = npcZ;

                if (npc_test_move_taller_with_slipping(0, &xTemp, &yTemp, &zTemp, length,
                                                        atan2(npcX, npcZ, playerX, playerZ),
                                                        npcCollisionHeight,
                                                        2.0f * npcCollisionRadius) != 0) {
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

    if (!(playerStatus->animFlags & PA_FLAGS_8BIT_MARIO) && npc != NULL && !is_picking_up_item()) {
        playerStatus->encounteredNPC = npc;
        playerStatus->flags |= PS_FLAGS_HAS_CONVERSATION_NPC;
        if (playerStatus->pressedButtons & BUTTON_A) {
            close_status_menu();
            gCurrentEncounter.hitType = ENCOUNTER_TRIGGER_CONVERSATION;
            enemy->encountered = ENCOUNTER_TRIGGER_CONVERSATION;
            encounterStatus->currentEncounter = encounter;
            encounterStatus->currentEnemy = enemy;
            encounterStatus->firstStrikeType = FIRST_STRIKE_PLAYER;
            return TRUE;
        }
    }
    return FALSE;
}

INCLUDE_ASM(s32, "1a1f0_len_5390", create_encounters);

void init_encounters_ui(void) {
}

s32 is_starting_conversation(void) {
    s32 ret = gGameState == 3;

    if (gCurrentEncounter.hitType == 5) {
        ret = 1;
    }
    return ret;
}
