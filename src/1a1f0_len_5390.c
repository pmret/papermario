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

void spawn_drops(Enemy* enemy);

s32 D_80077C40 = 0;

extern EvtScript D_800936DC;

EvtScript D_80077C44 = {
    EVT_WAIT(10)
    EVT_CALL(FadeBackgroundToBlack)
    EVT_WAIT(10)
    EVT_CALL(CreateNpc, NPC_BTL_MERLEE, ANIM_BattleMerlee_Gather)
    EVT_CALL(SetNpcFlagBits, NPC_BTL_MERLEE, NPC_FLAG_100, TRUE)
    EVT_CALL(SetNpcYaw, NPC_BTL_MERLEE, 0)
    EVT_CALL(GetCamLookAtObjVector)
    EVT_CALL(SetNpcPos, NPC_BTL_MERLEE, LocalVar(0), LocalVar(1), LocalVar(2))
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
    EVT_CALL(GetPlayerPos, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(PlayMerleeGatherFX, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(PlayMerleeOrbFX, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(15)
    EVT_CALL(ShowMerleeCoinMessage)
    EVT_WAIT(15)
    EVT_CALL(HasMerleeCasts)
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ShowMerleeRanOutMessage)
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};

EvtScript SCRIPT_NpcDefeat = {
    EVT_CALL(GetBattleOutcome, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
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
    .dropFlags = 0x80,
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
    EVT_CALL(GetOwnerEncounterTrigger, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(1)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(GetSelfAnimationFromTable, 7, LocalVar(0))
            EVT_EXEC_WAIT(D_800936DC)
        EVT_CASE_EQ(3)
            EVT_THREAD
                EVT_CALL(func_800458CC, LocalVar(0))
                EVT_IF_EQ(LocalVar(0), 0)
                    EVT_SET(LocalVar(10), 0)
                    EVT_LOOP(30)
                        EVT_ADD(LocalVar(10), 40)
                        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LocalVar(10), 0)
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
    EVT_CALL(GetBattleOutcome, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(2)
            EVT_CALL(func_80045900, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetEnemyFlagBits, -1, 16, 1)
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
        *D_801512F0 = 1;
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
INCLUDE_ASM(s32, "1a1f0_len_5390", update_encounters_neutral);
/*
void update_encounters_neutral(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[gCurrentCameraID];
    s32 sp20;
    s32 sp24;
    s32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp44;
    s32 e;
    f32 sp50;
    f32 sp54;
    f32 sp58;
    f32 sp5C;
    s32 sp60;
    f32* sp64;
    Encounter* encounter;
    Evt* script;
    s16 colliderHeight;
    Npc* npc;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f10;
    f32 temp_f10_2;
    f32 temp_f10_3;
    f32 temp_f10_4;
    f32 temp_f10_5;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_4;
    f32 temp_f30;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f4_5;
    f32 temp_f4_6;
    f32 temp_f6;
    f32 temp_f6_2;
    f32 temp_f6_3;
    f32 temp_f8;
    f32 temp_f8_2;
    f32 temp_f8_3;
    f32 temp_f8_4;
    f32 temp_f8_5;
    f32 var_a1;
    f32 var_a2;
    f32 var_a3;
    f32 var_f0;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f24;
    f32 var_f26;
    f32 var_f2;
    f32 var_f6;
    s32 (*temp_v0_25)[0];
    s32 cond;
    s32 var_v0_4;
    s32 firstStrikeType;
    s32 var_v0_3;

    Enemy* enemy;
    s32 i;


    if (currentEncounter->hitType != 5) {
        currentEncounter->songID = -1;
        currentEncounter->unk_18 = -1;
        currentEncounter->hitType = 0;
        currentEncounter->allowFleeing = 0;
        currentEncounter->dropWhackaBump = 0;
        currentEncounter->flags &= ~1;
        currentEncounter->flags &= ~2;
        currentEncounter->flags &= ~4;
        sp50 = playerStatus->position.x;
        sp54 = playerStatus->position.y;
        sp58 = playerStatus->position.z;

        if (playerStatus->spriteFacingAngle < 180.0f) {
            sp5C = clamp_angle(camera->currentYaw - 90.0f);
        } else {
            sp5C = clamp_angle(camera->currentYaw + 90.0f);
        }

        if (currentEncounter->battleTriggerCooldown != 0) {
            if (!(gOverrideFlags & 0x40)) {
                currentEncounter->battleTriggerCooldown--;
            }
            if (playerStatus->blinkTimer != 0) {
                if (playerStatus->flags & 0x2000) {
                    playerStatus->blinkTimer = 1;
                } else {
                    playerStatus->blinkTimer = currentEncounter->battleTriggerCooldown;
                }
            }
        }

        sp60 = 0x7FFFFFFF;
        sp64 = &sp3C;
        for (e = 0; e < currentEncounter->numEncounters; e++) {
            encounter = currentEncounter->encounterList[e];

            if (encounter != NULL) {
                for (i = 0; i < encounter->count; i++) {
                    enemy = encounter->enemy[i];
                    if (enemy != NULL && !(enemy->flags & 0x20)) {
                        npc = get_npc_unsafe(enemy->npcID);
                        if (!enemy->aiPaused) {
                            if (!(enemy->flags & 0x200000) && ((get_screen_coords(gCurrentCameraID, npc->pos.x, npc->pos.y, npc->pos.z, &sp20, &sp24, &sp28), (((u32) (sp20 + 0xA0) < 0x281U) == 0)) || (sp24 < -120) || (sp24 > 360) || (sp28 < 0)) && !(enemy->flags & 1)) {
                                npc->flags |= 0x80000000;
                                enemy->flags |= 0x80000000;
                                script = get_script_by_id(enemy->auxScriptID);
                                if (script != NULL) {
                                    set_script_flags(script, 0x80);
                                }
                                script = get_script_by_id(enemy->aiScriptID);
                                if (script != NULL) {
                                    set_script_flags(script, 0x80);
                                }
                            } else {
                                npc->flags &= sp60;
                                enemy->flags &= sp60;
                                script = get_script_by_id(enemy->auxScriptID);
                                if (script != NULL) {
                                    clear_script_flags(script, 0x80);
                                }
                                script = get_script_by_id(enemy->aiScriptID);
                                if (script != NULL) {
                                    clear_script_flags(script, 0x80);
                                }
                            }
                        } else {
                            if (gOverrideFlags & 0x40) {
                                var_v0_3 = 0;
                            } else {
                                enemy->aiPaused--;
                                var_v0_3 = enemy->aiPaused;
                            }

                            if (var_v0_3 & 1) {
                                npc->flags |= 0x80000000;
                                enemy->flags |= 0x80000000;
                            } else {
                                npc->flags &= sp60;
                                enemy->flags &= sp60;
                            }

                            script = get_script_by_id(enemy->auxScriptID);
                            if (script != NULL) {
                                set_script_flags(script, 0x80);
                            }
                            script = get_script_by_id(enemy->aiScriptID);
                            if (script != NULL) {
                                set_script_flags(script, 0x80);
                            }

                            if (enemy->flags & 0x80000) {
                                script = get_script_by_id(enemy->auxScriptID);
                                if (script != NULL) {
                                    clear_script_flags(script, 0x80);
                                }
                                script = get_script_by_id(enemy->aiScriptID);
                                if (script != NULL) {
                                    clear_script_flags(script, 0x80);
                                }
                            }
                        }

                        if (!(enemy->flags & 0x80000000)) {
                            if (enemy->flags & 1) {
                                if (!(enemy->flags & 0x400000)) {
                                    if (npc == playerStatus->encounteredNPC) {
                                        enemy->unk_E0 = (s16) npc->yaw;
                                        npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                                        script = get_script_by_id(enemy->aiScriptID);
                                        if (script != NULL) {
                                            set_script_flags(script, 0x80);
                                        }
                                    } else {
                                        if (enemy->unk_E0 != 0x3039) {
                                            npc->yaw = enemy->unk_E0;
                                            enemy->unk_E0 = 0x3039;
                                        }
                                        script = get_script_by_id(enemy->aiScriptID);
                                        if (script != NULL) {
                                            clear_script_flags(script, 0x80);
                                        }
                                    }
                                } else {
                                    script = get_script_by_id(enemy->aiScriptID);
                                    if (script != NULL) {
                                        clear_script_flags(script, 0x80);
                                    }
                                }
                            }

                            if ((currentEncounter->battleTriggerCooldown == 0) && (gGameStatusPtr->debugEnemyContact != 1) && !(playerStatus->flags & 0x80000) && (((gOverrideFlags & 0x40) == 0)) && (gPartnerActionStatus.actingPartner != 9) && !(enemy->flags & 1) && !(gOverrideFlags & 0xF00) && (is_picking_up_item() == 0)) {
                                if (!(enemy->flags & 0x10000000)) {
                                    if (partner_test_enemy_collision(npc) != 0) {
                                        currentEncounter->hitType = 6;
                                        enemy->encountered = 6;
                                        currentEncounter->currentEncounter = encounter;
                                        currentEncounter->currentEnemy = enemy;
                                        currentEncounter->firstStrikeType = 1;
                                        break;
                                    }
                                }
                                var_f26 = npc->pos.y;
                                var_f24 = npc->yaw;
                                sp2C = npc->pos.x;
                                sp30 = npc->pos.z;
                                temp_f28 = npc->collisionHeight;
                                temp_f30 = npc->collisionRadius / 2;
                                if (enemy->unk_DC != 0) {
                                    if (npc->yawCamOffset < 180.0f) {
                                        var_f12_2 = camera->currentYaw - 90.0f;
                                    } else {
                                        var_f12_2 = camera->currentYaw + 90.0f;
                                    }
                                    var_f24 = clamp_angle(var_f12_2);
                                    add_vec2D_polar(&sp2C, &sp30, enemy->unk_DC, var_f24);
                                }
                                temp_f0 = sp2C - sp50;
                                temp_f0_2 = sp30 - sp58;
                                temp_f22 = sqrtf(SQ(temp_f0) + SQ(temp_f0_2));
                                switch (playerStatus->actionState) {
                                    case 18:
                                        sp34 = sp50;
                                        sp38 = sp58;
                                        if (clamp_angle(playerStatus->spriteFacingAngle) < 180.0f) {
                                            var_f0 = clamp_angle(camera->currentYaw - 90.0f);
                                            if (playerStatus->trueAnimation & 0x01000000) {
                                                var_f0 = clamp_angle(var_f0 + 30.0f);
                                            }
                                        } else {
                                            var_f0 = clamp_angle(camera->currentYaw + 90.0f);
                                            if (playerStatus->trueAnimation & 0x01000000) {
                                                var_f0 = clamp_angle(var_f0 - 30.0f);
                                            }
                                        }
                                        add_vec2D_polar(&sp34, &sp38, 24.0f, var_f0);
                                        temp_f0_3 = sp2C - sp34;
                                        temp_f0_4 = sp30 - sp38;
                                        temp_f22_2 = sqrtf(SQ(temp_f0_3) + SQ(temp_f0_4));
                                        if (!(enemy->flags & 0x04000000) && (playerStatus->flags & 0x01000000) && !((14.0f + temp_f30) <= temp_f22_2) && !((var_f26 + temp_f28) < sp54) && !((sp54 + 18.0f) < var_f26) && ((sp40 = var_f26, sp3C = sp2C, sp44 = sp30, temp_f20 = 2.0f * temp_f30, (npc_test_move_taller_with_slipping(0x10000, sp64, &sp40, &sp44, temp_f22_2, atan2(sp2C, sp30, sp50, sp58), temp_f28, temp_f20) == 0)) || (sp3C = sp50, sp40 = sp54, sp44 = sp58, (npc_test_move_taller_with_slipping(0x10000, sp64, &sp40, &sp44, temp_f22_2, atan2(sp50, sp58, sp2C, sp30), temp_f28, temp_f20) == 0)))) {
                                            if (enemy->unk_07 != 0) {
                                                var_f26 = enemy->unk_10.y;
                                                sp2C = enemy->unk_10.x;
                                                sp30 = enemy->unk_10.z;
                                            }
                                            cond = FALSE;
                                            temp_f20_2 = fabsf(get_clamped_angle_diff(atan2(sp50, sp58, sp2C, sp30), sp5C));
                                            temp_f0_5 = fabsf(get_clamped_angle_diff(atan2(sp2C, sp30, sp50, sp58), var_f24));
                                            if (temp_f20_2 < 90.0f) {
                                                if (temp_f0_5 >= 90.0f) {
                                                    cond = TRUE;
                                                }
                                            }
                                            if (temp_f20_2 >= 90.0f && temp_f0_5 < 90.0f) {
                                                cond = FALSE;
                                            }
                                            if (temp_f20_2 < 90.0f && temp_f0_5 < 90.0f) {
                                                cond = TRUE;
                                            }
                                            if (cond) {
                                                sfx_play_sound_at_position(0xE1, 0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
                                                currentEncounter->hitType = 4;
                                                currentEncounter->hitTier = gPlayerData.hammerLevel;
                                                enemy->encountered = 4;
                                                currentEncounter->currentEncounter = encounter;
                                                currentEncounter->currentEnemy = enemy;
                                                currentEncounter->firstStrikeType = 1;
                                                break;
                                            } else {
                                                goto block_135;
                                            }
                                        }
                                        break;
                                    case 3:
                                    case 4:
                                    case 8:
                                    case 9:
                                    case 10:
                                    case 11:
                                    case 13:
                                    case 14:
                                    case 15:
                                    case 16:
                                        sp34 = sp50;
                                        sp38 = sp58;
                                        if (!(enemy->flags & 0x02000000)) {
                                            if (!((14.0f + temp_f30) <= temp_f22) && (temp_f24 = var_f26 + temp_f28, !(temp_f24 < sp54)) && !((sp54 + 37.0f) < var_f26)) {
                                                sp40 = var_f26;
                                                sp3C = sp2C;
                                                sp44 = sp30;
                                                temp_f20_4 = 2.0f * temp_f30;
                                                if ((npc_test_move_taller_with_slipping(0x10000, sp64, &sp40, &sp44, temp_f22, atan2(sp2C, sp30, sp50, sp58), temp_f28, temp_f20_4) == 0) || (sp3C = sp50, sp40 = sp54, sp44 = sp58, (npc_test_move_taller_with_slipping(0x10000, sp64, &sp40, &sp44, temp_f22, atan2(sp50, sp58, sp2C, sp30), temp_f28, temp_f20_4) == 0))) {
                                                    cond = FALSE;
                                                    if (temp_f24 < (sp54 + (37.0f * 0.5f))) {
                                                        if ((u32) (playerStatus->actionState - 8) < 4U) {
                                                            cond = TRUE;
                                                        } else if ((playerStatus->actionState == 0xD) || (playerStatus->actionState == 0xE) || (playerStatus->actionState == 0xF) || (playerStatus->actionState == 0x10)) {
                                                            cond = TRUE;
                                                        }
                                                    }
                                                    if ((sp54 + 37.0f) < (var_f26 + (temp_f28 * 0.5f))) {
                                                        cond = FALSE;
                                                    }
                                                    if (cond) {
                                                        if (gPlayerData.bootsLevel >= 0) {
                                                            currentEncounter->hitType = 2;
                                                            switch (playerStatus->actionState) {
                                                                case 3:
                                                                case 4:
                                                                case 8:
                                                                case 9:
                                                                case 10:
                                                                case 11:
                                                                    currentEncounter->hitTier = 0;
                                                                    break;
                                                                case 13:
                                                                case 14:
                                                                    currentEncounter->hitTier = 1;
                                                                    break;
                                                                case 15:
                                                                case 16:
                                                                    currentEncounter->hitTier = 2;
                                                                    break;
                                                            }
                                                            sfx_play_sound_at_position(0xE1, 0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
                                                            enemy->encountered = 2;
                                                            currentEncounter->currentEncounter = encounter;
                                                            currentEncounter->currentEnemy = enemy;
                                                            currentEncounter->firstStrikeType = 1;
                                                            break;
                                                        }
                                                        currentEncounter->hitType = 1;
                                                        enemy->encountered = 1;
                                                        currentEncounter->currentEncounter = encounter;
                                                        currentEncounter->currentEnemy = enemy;
                                                        currentEncounter->firstStrikeType = 0;
                                                        currentEncounter->hitTier = 0;
                                                    } else {
                                                        goto block_135;
                                                    }
                                                } else {
                                                    goto block_135;
                                                }
                                            }
                                        } else {
                                            goto block_135;
                                        }
                                        break;
                                    default:
    block_135:
                                            if (!(enemy->flags & 0x01000000) && (temp_f0_6 = sp2C - sp50, temp_f0_7 = sp30 - sp58, temp_f4 = sqrtf((temp_f0_6 * temp_f0_6) + (temp_f0_7 * temp_f0_7)), !(((f64) (14.0f + temp_f30) * 0.8) <= (f64) temp_f4)) && !((var_f26 + temp_f28) < sp54) && !((sp54 + 37.0f) < var_f26) && ((sp40 = var_f26, sp3C = sp2C, sp44 = sp30, temp_f20_3 = 2.0f * temp_f30, cond = FALSE, (npc_test_move_taller_with_slipping(0x10000, sp64, &sp40, &sp44, temp_f4, atan2(sp2C, sp30, sp50, sp58), temp_f28, temp_f20_3) == 0)) || (sp3C = sp50, sp40 = sp54, sp44 = sp58, (npc_test_move_taller_with_slipping(0x10000, sp64, &sp40, &sp44, temp_f4, atan2(sp50, sp58, sp2C, sp30), temp_f28, temp_f20_3) == 0)))) {
                                                if (is_ability_active(0x28) && (gPlayerData.level >= enemy->npcSettings->level)) {
                                                    cond = currentEncounter->unk_12 == 0;
                                                }
                                                if (is_ability_active(0x2D)) {
                                                    cond = TRUE;
                                                }
                                                if (playerStatus->animFlags & 0x10000) {
                                                    if (!(enemy->flags & 0x20000000)) {
                                                        if (cond) {
                                                            sfx_play_sound_at_position(0xE1, 0, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
                                                            temp_f12 = playerStatus->position.x;
                                                            temp_f6 = playerStatus->position.y;
                                                            temp_f4_2 = playerStatus->position.z;
                                                            temp_f12_2 = temp_f12 + ((npc->pos.x - temp_f12) * 0.5f);
                                                            temp_f6_2 = temp_f6 + (((npc->pos.y + npc->collisionHeight) - (temp_f6 + playerStatus->colliderHeight)) * 0.5f);
                                                            temp_f4_3 = temp_f4_2 + ((npc->pos.z - temp_f4_2) * 0.5f);
                                                            sp3C = temp_f12_2;
                                                            sp40 = temp_f6_2;
                                                            sp44 = temp_f4_3;
                                                            fx_damage_stars(3, temp_f12_2, temp_f6_2, temp_f4_3, 0.0f, -1.0f, 0.0f, 3);
                                                            currentEncounter->hitType = 3;
                                                            playerStatus->animFlags |= 0x20000;
                                                            enemy->encountered = 3;
                                                            currentEncounter->currentEncounter = encounter;
                                                            currentEncounter->currentEnemy = enemy;
                                                            currentEncounter->firstStrikeType = 0;
                                                        }
                                                    }
                                                }
                                                currentEncounter->hitType = 1;
                                                playerStatus->animFlags &= 0xFFFDFFFF;
                                                enemy->encountered = 1;
                                                currentEncounter->currentEncounter = encounter;
                                                currentEncounter->currentEnemy = enemy;
                                                temp_f10 = playerStatus->position.x;
                                                temp_f8 = playerStatus->position.y;
                                                temp_f2 = playerStatus->position.z;
                                                temp_f10_2 = temp_f10 + ((npc->pos.x - temp_f10) * 0.5f);
                                                temp_f8_2 = temp_f8 + (((npc->pos.y + npc->collisionHeight) - (temp_f8 + playerStatus->colliderHeight)) * 0.5f);
                                                temp_f2_2 = temp_f2 + ((npc->pos.z - temp_f2) * 0.5f);
                                                sp3C = temp_f10_2;
                                                sp40 = temp_f8_2;
                                                sp44 = temp_f2_2;
                                                fx_damage_stars(3, temp_f10_2, temp_f8_2, temp_f2_2, 0.0f, -1.0f, 0.0f, 3);
                                                firstStrikeType = 0;
                                                if (enemy->unk_07 != 0) {
                                                    firstStrikeType = !is_ability_active(0x11) * 2;
                                                }
                                                if (!is_ability_active(0x2A)) {
                                                    currentEncounter->firstStrikeType = firstStrikeType;
                                                } else if (gPlayerData.level < enemy->npcSettings->level) {
                                                    currentEncounter->firstStrikeType = firstStrikeType;
                                                } else if (enemy->flags & 0x40) {
                                                    currentEncounter->firstStrikeType = firstStrikeType;
                                                } else {
                                                    if (currentEncounter->unk_12 == 0) {
                                                        firstStrikeType = 0;
                                                    }
                                                    currentEncounter->firstStrikeType = firstStrikeType;
                                                }
                                            } else {
                                                continue;
                                            }
                                        }
                                        break;

                            }
                        }
                    }
                }
            }
        }
    }

    switch ((u32) currentEncounter->hitType) {
        case 1:
            enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;
            i = 0;
            if (encounter->count > 0) {
                do {
                    enemy = encounter->enemy[i];
                    if ((enemy != NULL) && ((((enemy->flags & 8) == 0)) || ((enemy == currentEncounter->currentEnemy))) && !(enemy->flags & 0x20) && (!(enemy->flags & 0x40) || (enemy == currentEncounter->currentEnemy))) {
                        if (enemy->hitBytecode != NULL) {
                            enemy->encountered = 1;
                            script = start_script(enemy->hitBytecode, 0xA, 0);
                            enemy->hitScript = script;
                            enemy->hitScriptID = script->id;
                            script->owner1.enemyID = enemy;
                            script->owner2.npcID = enemy->npcID;
                            script->groupFlags = enemy->scriptGroup;
                        }
                    }
                    i += 1;
                } while (i < encounter->count);
            }
            disable_player_input();
            partner_disable_input();
            if (!((u32) (playerStatus->actionState - 0xF) < 2U) && (playerStatus->actionState != 0xD) && (playerStatus->actionState != 0xE)) {
                playerStatus->flags |= 0x40000;
            }
            if (!is_ability_active(0x11) && (currentEncounter->firstStrikeType == 2)) {
                set_action_state(0x1B);
                npc = get_npc_unsafe(enemy->npcID);
                sfx_play_sound_at_position(0xE1, 0, npc->pos.x, npc->pos.y, npc->pos.z);
            }
            currentEncounter->unk_12 = 0;
            gGameState = 3;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case 3:
            enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;
            i = 0;
            if (encounter->count > 0) {
                do {
                    enemy = encounter->enemy[i];
                    if ((enemy != NULL) && ((((enemy->flags & 8) == 0)) || ((enemy == currentEncounter->currentEnemy))) && !(enemy->flags & 0x20) && (!(enemy->flags & 0x40) || (enemy == currentEncounter->currentEnemy))) {
                        if (enemy->hitBytecode != NULL) {
                            enemy->encountered = 3;
                            script = start_script(enemy->hitBytecode, 0xA, 0);
                            enemy->hitScript = script;
                            enemy->hitScriptID = script->id;
                            script->owner1.enemyID = enemy;
                            script->owner2.npcID = enemy->npcID;
                            script->groupFlags = enemy->scriptGroup;
                        }
                    }
                    i += 1;
                } while (i < encounter->count);
            }
            disable_player_input();
            partner_disable_input();
            currentEncounter->unk_12 = 0;
            gGameState = 3;
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            playerStatus->flags |= 0x40000;
            break;
        case 2:
            enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;

            cond = FALSE;
            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if ((enemy != NULL) && ((((enemy->flags & 8) == 0)) || ((enemy == currentEncounter->currentEnemy))) && !(enemy->flags & 0x20) && (!(enemy->flags & 0x40) || (enemy == currentEncounter->currentEnemy))) {
                    if (enemy->hitBytecode != NULL) {
                        enemy->encountered = 2;
                        script = start_script(enemy->hitBytecode, 0xA, 0);
                        enemy->hitScript = script;
                        enemy->hitScriptID = script->id;
                        script->owner1.enemyID = enemy;
                        script->owner2.npcID = enemy->npcID;
                        script->groupFlags = enemy->scriptGroup;
                        npc = get_npc_unsafe(enemy->npcID);
                        var_f6 = (npc->pos.x - playerStatus->position.x) * 0.5f;
                        var_f2 = npc->pos.y + npc->collisionHeight;
                        temp_f8_3 = playerStatus->position.y;
                        temp_f4_4 = playerStatus->position.z;
                        temp_f10_3 = playerStatus->position.x + var_f6;
                        temp_f8_4 = temp_f8_3 + ((var_f2 - (temp_f8_3 + playerStatus->colliderHeight)) * 0.5f);
                        cond = TRUE;
                        temp_f4_5 = temp_f4_4 + ((npc->pos.z - temp_f4_4) * 0.5f);
                        sp3C = temp_f10_3;
                        sp40 = temp_f8_4;
                        sp44 = temp_f4_5;
                        fx_damage_stars(3, temp_f10_3, temp_f8_4, temp_f4_5, 0.0f, -1.0f, 0.0f, 3);
                    }
                    if (!(enemy->flags & 1)) {
                        npc = get_npc_unsafe(enemy->npcID);
                        var_f6 = (npc->pos.x - playerStatus->position.x) * 0.5f;
                        var_f2 = npc->pos.y + npc->collisionHeight;
                        temp_f8_3 = playerStatus->position.y;
                        temp_f4_4 = playerStatus->position.z;
                        temp_f10_3 = playerStatus->position.x + var_f6;
                        temp_f8_4 = temp_f8_3 + ((var_f2 - (temp_f8_3 + playerStatus->colliderHeight)) * 0.5f);
                        cond = TRUE;
                        temp_f4_5 = temp_f4_4 + ((npc->pos.z - temp_f4_4) * 0.5f);
                        sp3C = temp_f10_3;
                        sp40 = temp_f8_4;
                        sp44 = temp_f4_5;
                        fx_damage_stars(3, temp_f10_3, temp_f8_4, temp_f4_5, 0.0f, -1.0f, 0.0f, 3);
                    }
                }
            }
            disable_player_input();
            partner_disable_input();
            playerStatus->flags |= 0x40000;
            if (cond) {
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
        case 4:
            enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;
            i = 0;
            if (encounter->count > 0) {
                do {
                    enemy = encounter->enemy[i];
                    if ((enemy != NULL) && ((((enemy->flags & 8) == 0)) || ((enemy == currentEncounter->currentEnemy))) && !(enemy->flags & 0x20) && (!(enemy->flags & 0x40) || (enemy == currentEncounter->currentEnemy))) {
                        if (enemy->hitBytecode != NULL) {
                            enemy->encountered = 4;
                            script = start_script(enemy->hitBytecode, 0xA, 0);
                            enemy->hitScript = script;
                            enemy->hitScriptID = script->id;
                            script->owner1.enemyID = enemy;
                            script->owner2.npcID = enemy->npcID;
                            script->groupFlags = enemy->scriptGroup;
                            npc = get_npc_unsafe(enemy->npcID);
                            var_a1 = playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                            var_a2 = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                            var_a3 = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                            sp3C = var_a1;
                            sp40 = var_a2;
                            sp44 = var_a3;
                            goto block_246;
                        }
                        if (!(enemy->flags & 1)) {
                            npc = get_npc_unsafe(enemy->npcID);
                            var_a2 = npc->pos.y + npc->collisionHeight;
                            sp3C = playerStatus->position.x + ((npc->pos.x - playerStatus->position.x) * 0.5f);
                            sp44 = playerStatus->position.z + ((npc->pos.z - playerStatus->position.z) * 0.5f);
                            sp40 = playerStatus->position.y + (((npc->pos.y + npc->collisionHeight) - (playerStatus->position.y + playerStatus->colliderHeight)) * 0.5f);
                            var_a1 = npc->pos.x;
                            var_a3 = npc->pos.z;
block_246:
                            fx_damage_stars(3, var_a1, var_a2, var_a3, 0, 0, 0, 0); // TODO zeros
                        }
                    }
                    i += 1;
                } while (i < encounter->count);
            }
            disable_player_input();
            partner_disable_input();
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            currentEncounter->unk_12 = 0;
            playerStatus->flags |= 0x40000;
            sfx_play_sound(0);
            gGameState = 3;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case 5:
            suspend_all_group(1);
            enemy = currentEncounter->currentEnemy;
            if (enemy != NULL && enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            temp_v0_25 = currentEncounter->currentEnemy->interactBytecode;
            if (temp_v0_25 != NULL) {
                currentEncounter->currentEnemy->encountered = 5;
                script = start_script(temp_v0_25, 0xA, 0);
                currentEncounter->currentEnemy->interactScript = script;
                currentEncounter->currentEnemy->interactScriptID = script->id;
                script->owner1.enemyID = currentEncounter->currentEnemy;
                script->owner2.npcID = currentEncounter->currentEnemy->npcID;
                script->groupFlags = currentEncounter->currentEnemy->scriptGroup;
            }
            disable_player_input();
            partner_disable_input();
            set_action_state(0xC);
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            func_800EF3D4(1);
            gGameState = 4;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
        case 6:
            enemy = currentEncounter->currentEnemy;
            if (enemy->aiScript != NULL) {
                suspend_all_script(enemy->aiScriptID);
            }
            if (enemy->auxScript != NULL) {
                suspend_all_script(enemy->auxScriptID);
            }
            encounter = currentEncounter->currentEncounter;

            for (i = 0; i < encounter->count; i++) {
                enemy = encounter->enemy[i];
                if (enemy != NULL && ((((enemy->flags & 8) == 0)) || ((enemy == currentEncounter->currentEnemy))) && !(enemy->flags & 0x20) && (!(enemy->flags & 0x40) || (enemy == currentEncounter->currentEnemy))) {
                    if (enemy->hitBytecode != NULL) {
                        enemy->encountered = 6;
                        script = start_script(enemy->hitBytecode, 0xA, 0);
                        enemy->hitScript = script;
                        enemy->hitScriptID = script->id;
                        script->owner1.enemyID = enemy;
                        script->owner2.npcID = enemy->npcID;
                        script->groupFlags = enemy->scriptGroup;
                        goto block_270;
                    }
                    if (!(enemy->flags & 1)) {
block_270:
                        npc = get_npc_unsafe(enemy->npcID);
                        temp_f2_4 = npc->pos.z;
                        temp_f4_6 = npc->pos.y + npc->collisionHeight;
                        temp_f0_8 = npc->pos.x;
                        sp44 = temp_f2_4;
                        sp3C = temp_f0_8;
                        sp40 = temp_f4_6;
                        fx_damage_stars(3, temp_f0_8, temp_f4_6, temp_f2_4, 0.0f, -1.0f, 0.0f, 3);
                    }
                }
            }
            disable_player_input();
            partner_disable_input();
            currentEncounter->fadeOutAmount = 0;
            currentEncounter->unk_94 = 0;
            currentEncounter->unk_12 = 0;
            playerStatus->flags |= 0x40000;
            sfx_play_sound(0);
            gGameState = 3;
            D_8009A678 = 1;
            D_8009A5D0 = 0;
            break;
    }
}
*/

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
