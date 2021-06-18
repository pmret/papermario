#include "common.h"
#include "map.h"

extern s32 D_800A0BA0;
extern f32 D_800A0BA4;
extern EffectInstance* D_800A0BA8;
extern EffectInstance* D_800A0BAC;

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

ApiStatus ShowMerleeCoinMessage(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_80045D00(0, 60);
    }
    return (is_merlee_message_done() == 0) * ApiStatus_DONE2;
}

ApiStatus ShowMerleeRanOutMessage(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_80045D00(1, 60);
    }
    return (is_merlee_message_done() == 0) * ApiStatus_DONE2;
}

ApiStatus FadeBackgroundToBlack(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_8011D82C(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0].s = 25;
    }

    set_background_color_blend(0, 0, 0, ((25 - script->functionTemp[0].s) * 10) & 254);
    script->functionTemp[0].s--;
    do {} while (0);
    return (script->functionTemp[0].s == 0) * ApiStatus_DONE2;
}

ApiStatus UnfadeBackgroundFromBlack(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0].s = 25;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0].s * 10) & 0xFE);
    script->functionTemp[0].s -= 5;

    if (script->functionTemp[0].s == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus FadeInMerlee(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_BTL_MERLEE);

    if (isInitialCall) {
        sfx_play_sound(0x24B);
        npc->alpha = 0;
    }

    npc->alpha += 17;

    if ((u32)(npc->alpha & 0xFF) >= 0xFF) {
        npc->alpha = 0xFF;
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus FadeOutMerlee(ScriptInstance* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_BTL_MERLEE);

    npc->alpha -= 17;
    if (npc->alpha == 0) {
        npc->alpha = 0;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

// same as func_802616F4 aside from syms
ApiStatus MerleeUpdateFX(ScriptInstance* script, s32 isInitialCall) {
    Npc* merlee = get_npc_unsafe(NPC_BTL_MERLEE);
    EffectInstanceData* effectInstanceData;

    if (isInitialCall) {
        script->functionTemp[1].s = 0;
        D_800A0BA4 = merlee->pos.y;
        D_800A0BA8 = func_80071750(0, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.4f, 0);
        D_800A0BAC = func_80071750(3, merlee->pos.x, merlee->pos.y, merlee->pos.z, 0.00001f, 0);
        D_800A0BB8 = 0;
        D_800A0BA0 = 12;
        sfx_play_sound(0x2074);
    }

    merlee->pos.y = D_800A0BA4 + (sin_rad((script->functionTemp[1].s * TAU) / 360.0f) * 3.0f);

    script->functionTemp[1].s += 10;
    script->functionTemp[1].s = clamp_angle(script->functionTemp[1].s);

    effectInstanceData = D_800A0BA8->data;
    effectInstanceData->pos.x = merlee->pos.x;
    effectInstanceData->pos.y = merlee->pos.y + 16.0f;
    effectInstanceData->pos.z = merlee->pos.z;

    effectInstanceData = D_800A0BAC->data;
    effectInstanceData->pos.x = merlee->pos.x;
    effectInstanceData->pos.y = merlee->pos.y + 16.0f;
    effectInstanceData->pos.z = merlee->pos.z + 5.0f;

    if (D_800A0BB8 == 2) {
        D_800A0BA8->data->unk_30 = 0.00001f;
        D_800A0BAC->data->unk_30 = 0.00001f;
        D_800A0BA8->flags |= 0x10;
        D_800A0BAC->flags |= 0x10;
        return ApiStatus_DONE1;
    }

    if (D_800A0BB8 == 1) {
        effectInstanceData = D_800A0BA8->data;
        effectInstanceData->unk_30 += 0.35;
        if (effectInstanceData->unk_30 > 3.5) {
            effectInstanceData->unk_30 = 3.5f;
        }

        if (D_800A0BA0 != 0) {
            D_800A0BA0--;
        } else {
            effectInstanceData = D_800A0BAC->data;
            effectInstanceData->unk_30 += 0.5;
            if (effectInstanceData->unk_30 > 5.0) {
                D_800A0BB8 = 2;
            }
        }
    }
    return ApiStatus_BLOCK;
}

ApiStatus MerleeStopFX(ScriptInstance* script, s32 isInitialCall) {
    D_800A0BB8 = 1;
    return ApiStatus_DONE2;
}

ApiStatus GetCamLookAtObjVector(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = gCameras[gCurrentCameraID].lookAt_obj.x;
    script->varTable[1] = gCameras[gCurrentCameraID].lookAt_obj.y;
    script->varTable[2] = gCameras[gCurrentCameraID].lookAt_obj.z;

    return ApiStatus_DONE2;
}

ApiStatus HasMerleeCasts(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = FALSE;
    if (gPlayerData.merleeCastsLeft > 0) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}

ApiStatus PlayMerleeGatherFX(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    func_800720B0(6, var0, var1, var2, 1.2f, 30);
    return ApiStatus_DONE2;
}

ApiStatus PlayMerleeOrbFX(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    func_80071750(9, var0, var1, var2, 5.0f, 15);
    return ApiStatus_DONE2;
}

ApiStatus OnDefeatEnemy(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp1;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 20;
    }

    if (script->functionTemp[1].s & 1) {
        npc->flags &= ~2;
    } else {
        npc->flags |= 2;
    }

    if (script->functionTemp[1].s == 15) {
        sfx_play_sound(SOUND_DEATH);
        func_80070190(1, npc->pos.x, npc->pos.y + (npc->collisionHeight / 2), npc->pos.z, 0, -1.0f, 0, 10);
    }

    temp1 = script->functionTemp[1].s;
    if (script->functionTemp[1].s == 10) {
        func_8006F8F0(npc->pos.x, npc->pos.y + 10.0f, npc->pos.z + 10.0f);
        if (script->functionTemp[1].s == temp1) { // what? (never can be false, seemingly)
            spawn_drops(enemy);
        }
    }

    script->functionTemp[1].s -= 1;

    if (script->functionTemp[1].s == 0) {
        npc->flags |= 2;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus OnFleeBattleDrops(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        script->functionTemp[1].s = 40;
        script->functionTemp[2].s = 0;
    }

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= 5) {
        if (rand_int(100) < 50) {
            if (playerData->coins != 0) {
                playerData->coins--;
                make_item_entity_delayed(ITEM_COIN, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight,
                                         playerStatus->position.z, 3, 0, 0);
            }
        }
        script->functionTemp[2].s = 0;
    }

    return --script->functionTemp[1].s == 0;
}

/// Default/neutral state during world gameplay; checks for player-enemy collisions and initiates battles when they occur.
INCLUDE_ASM(s32, "1a1f0_len_5390", update_encounters_neutral);

void draw_encounters_neutral() {
}

INCLUDE_ASM(s32, "1a1f0_len_5390", update_encounters_pre_battle);

void draw_encounters_pre_battle(void) {
    EncounterStatus* encounter = &gCurrentEncounter;
    Npc* npc = get_npc_unsafe(encounter->currentEnemy->npcID);
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (encounter->unk_94 != 0) {
        f32 px, py, pz;
        f32 ox, oy, oz;
        s32 psx, psy, psz;
        s32 osx, osy, osz;

        if (encounter->fadeOutAmount != 255) {
            encounter->fadeOutAccel++;
            if (encounter->fadeOutAccel > 10) {
                encounter->fadeOutAccel = 10;
            }

            encounter->fadeOutAmount += encounter->fadeOutAccel;
            if (encounter->fadeOutAmount > 255) {
                encounter->fadeOutAmount = 255;
            }

            px = playerStatus->position.x;
            py = playerStatus->position.y;
            pz = playerStatus->position.z;

            ox = npc->pos.x;
            oy = npc->pos.y;
            oz = npc->pos.z;
            if (oy < -990.0f) {
                ox = px;
                oy = py;
                oz = pz;
            }

            if (gGameStatusPtr->demoState == 2) {
                set_transition_stencil_zoom_1(10, encounter->fadeOutAmount);
                set_transition_stencil_alpha(1, 255.0f);
                set_transition_stencil_color(1, 0, 0, 0);
                get_screen_coords(gCurrentCameraID, px, py + 20.0f, pz, &psx, &psy, &psz);
                get_screen_coords(gCurrentCameraID, ox, oy + 15.0f, oz, &osx, &osy, &osz);
                set_transition_stencil_center(1, 0, (psx - osx) / 2 + osx, (psy - osy) / 2 + osy);
            } else {
                set_transition_stencil_zoom_0(10, encounter->fadeOutAmount);
                set_transition_stencil_alpha(0, 255.0f);
                set_transition_stencil_color(0, 0, 0, 0);
                get_screen_coords(gCurrentCameraID, px, py + 20.0f, pz, &psx, &psy, &psz);
                get_screen_coords(gCurrentCameraID, ox, oy + 15.0f, oz, &osx, &osy, &osz);
                set_transition_stencil_center(0, 0, (psx - osx) / 2 + osx, (psy - osy) / 2 + osy);
            }
        }
    }
}

extern s16 D_8009A668;

INCLUDE_ASM(s32, "1a1f0_len_5390", show_first_strike_message);

INCLUDE_ASM(s32, "1a1f0_len_5390", update_encounters_post_battle);

s32 draw_encounters_post_battle(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 ret = currentEncounter->fadeOutAccel;

    if (ret != 0) {
        set_transition_stencil_zoom_0(0, currentEncounter->fadeOutAmount);
        ret = set_transition_stencil_color(0, 0, 0, 0);
    }

    return ret;
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
            func_800EF600();

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

void draw_encounters_conversation() {
}

INCLUDE_ASM(s32, "1a1f0_len_5390", check_conversation_trigger);

INCLUDE_ASM(s32, "1a1f0_len_5390", create_encounters);

void init_encounters_ui() {
}

s32 is_starting_conversation(void) {
    s32 ret = gGameState == 3;

    if (gCurrentEncounter.hitType == 5) {
        ret = 1;
    }
    return ret;
}
