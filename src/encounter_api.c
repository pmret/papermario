#include "common.h"
#include "npc.h"
#include "effects.h"
#include "battle/battle.h"

API_CALLABLE(SetEncounterStatusFlags) {
    Bytecode* args = script->ptrReadPos;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 flagBits = *args++;

    if (evt_get_variable(script, *args++)) {
        currentEncounter->flags |= flagBits;
    } else {
        currentEncounter->flags &= ~flagBits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(IsStartingConversation) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, is_starting_conversation());
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80044238) {
    Bytecode* args = script->ptrReadPos;

    func_80072BCC(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

API_CALLABLE(LoadDemoBattle) {
    Bytecode* args = script->ptrReadPos;

    load_demo_battle(evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80044290) {
    return ApiStatus_DONE2;
}

API_CALLABLE(MakeNpcs) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            make_npcs(evt_get_variable(script, *args++), gGameStatusPtr->mapID, (s32*) evt_get_variable(script, *args++));
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (gEncounterState != ENCOUNTER_STATE_CREATE) {
                return ApiStatus_DONE2;
            }
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(RemoveNpc) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    ApiStatus ret = ApiStatus_DONE1;
    s32 id = evt_get_variable(script, *args++);
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i, j;

    if ((s32)enemy != NPC_SELF) {
        if (id == NPC_SELF) {
            id = enemy->npcID;
            ret = ApiStatus_FINISH;
        } else {
            if (enemy->npcID == id) {
                Evt* scriptTemp = script;

                while (TRUE) {
                    if (scriptTemp->blockingParent != NULL) {
                        scriptTemp = scriptTemp->blockingParent;
                    } else {
                        break;
                    }
                }

                if (scriptTemp == enemy->aiScript) {
                    ret = ApiStatus_FINISH;
                }
            } else {
                get_enemy(id);
            }
        }
    } else {
        get_enemy(id);
    }

    for (i = 0; i < currentEncounter->numEncounters; i++) {
        Encounter* encounter = currentEncounter->encounterList[i];

        if (encounter != NULL) {
            for (j = 0; j < encounter->count; j++) {
                enemy = encounter->enemy[j];
                if (enemy != NULL && enemy->npcID == id) {
                    kill_enemy(enemy);
                    return ret;
                }
            }
        }
    }

    return ret;
}

API_CALLABLE(RemoveEncounter) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 id = evt_get_variable(script, *args++);
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    ApiStatus ret = ApiStatus_DONE1;
    s32 i, j;

    if ((s32)enemy != NPC_SELF && (id == NPC_SELF || enemy->npcID == id)) {
        id = enemy->npcID;
        ret = ApiStatus_FINISH;
    } else {
        get_enemy(id);
    }

    for (i = 0; i < currentEncounter->numEncounters; i++) {
        Encounter* encounter = currentEncounter->encounterList[i];

        if (encounter != NULL) {
            for (j = 0; j < encounter->count; j++) {
                enemy = encounter->enemy[j];
                if (enemy != NULL && enemy->npcID == id) {
                    kill_encounter(enemy);
                    return ret;
                }
            }
        }
    }

    return ret;
}

API_CALLABLE(GetBattleOutcome) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCurrentEncounter.battleOutcome);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_800445A8) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, script->owner1.enemy->unk_C4);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_800445D4) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, script->owner1.enemy->unk_C8);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetOwnerEncounterTrigger) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, script->owner1.enemy->encountered);
    return ApiStatus_DONE2;
}

API_CALLABLE(DoNpcDefeat) {
    Enemy* owner = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(owner->npcID);
    Evt* newScript;

    kill_script(script);
    npc->curAnim = owner->animList[6];
    newScript = start_script(&EVS_NpcDefeat, EVT_PRIORITY_A, 0);
    owner->defeatScript = newScript;
    owner->defeatScriptID = newScript->id;
    newScript->owner1.enemy = owner;
    newScript->owner2.npcID = owner->npcID;
    newScript->groupFlags = owner->scriptGroup;

    return ApiStatus_FINISH;
}

void start_battle(Evt* script, s32 songID) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Enemy* enemy = script->owner1.enemy;
    Encounter* encounter;
    s32 i;

    resume_all_group(EVT_GROUP_01);

    currentEncounter->hitType = ENCOUNTER_TRIGGER_NONE;
    enemy->encountered = TRUE;
    currentEncounter->curEnemy = enemy;
    currentEncounter->curEncounter = currentEncounter->encounterList[enemy->encounterIndex];
    currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
    currentEncounter->allowFleeing = FALSE;
    currentEncounter->songID = songID;
    currentEncounter->unk_18 = -1;

    if (enemy->aiScript != NULL) {
        suspend_all_script(enemy->aiScriptID);
    }

    if (enemy->auxScript != NULL) {
        suspend_all_script(enemy->auxScriptID);
    }

    disable_player_input();
    partner_disable_input();

    encounter = currentEncounter->curEncounter;
    for (i = 0; i < encounter->count; i++) {
        enemy = encounter->enemy[i];
        if (enemy != NULL && (!(enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) || enemy == currentEncounter->curEnemy)) {
            if (enemy->hitBytecode != NULL) {
                Evt* hitEvtInstance;
                enemy->encountered = TRUE;

                hitEvtInstance = start_script(enemy->hitBytecode, EVT_PRIORITY_A, 0);

                enemy->hitScript = hitEvtInstance;
                enemy->hitScriptID = hitEvtInstance->id;

                hitEvtInstance = enemy->hitScript;
                hitEvtInstance->owner1.enemy = enemy;
                hitEvtInstance->owner2.npcID = enemy->npcID;
                hitEvtInstance->groupFlags = enemy->scriptGroup;
            }
        }
    }

    currentEncounter->fadeOutAmount = 0;
    currentEncounter->unk_94 = 0;
    currentEncounter->scriptedBattle = TRUE;
    gEncounterState = ENCOUNTER_STATE_PRE_BATTLE;
    D_8009A678 = 1;
    gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT;
}

API_CALLABLE(StartBattle) {
    start_battle(script, -1);
    return ApiStatus_DONE1;
}

API_CALLABLE(StartBattleWith) {
    Bytecode* args = script->ptrReadPos;

    start_battle(script, evt_get_variable(script, *args++));
    return ApiStatus_DONE1;
}

API_CALLABLE(StartBossBattle) {
    Bytecode* args = script->ptrReadPos;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Enemy* enemy = script->owner1.enemy;
    s32 songID = evt_get_variable(script, *args++);
    Encounter* encounter;
    s32 i;

    resume_all_group(EVT_GROUP_01);

    currentEncounter->hitType = ENCOUNTER_TRIGGER_NONE;
    enemy->encountered = TRUE;
    currentEncounter->curEnemy = enemy;
    currentEncounter->curEncounter = currentEncounter->encounterList[enemy->encounterIndex];
    currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
    currentEncounter->allowFleeing = TRUE;
    currentEncounter->songID = songID;
    currentEncounter->unk_18 = -1;

    if (enemy->aiScript != NULL) {
        suspend_all_script(enemy->aiScriptID);
    }

    if (enemy->auxScript != NULL) {
        suspend_all_script(enemy->auxScriptID);
    }

    disable_player_input();
    partner_disable_input();

    encounter = currentEncounter->curEncounter;
    for (i = 0; i < encounter->count; i++) {
        enemy = encounter->enemy[i];
        if ((enemy != NULL && (
            !(enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) || enemy == currentEncounter->curEnemy)
            ) && enemy->hitBytecode != NULL) {
            enemy->encountered = TRUE;

            script = start_script(enemy->hitBytecode, EVT_PRIORITY_A, 0);
            enemy->hitScript = script;
            enemy->hitScriptID = script->id;

            script = enemy->hitScript;
            script->owner1.enemy = enemy;
            script->owner2.npcID = enemy->npcID;
            script->groupFlags = enemy->scriptGroup;
        }
    }

    currentEncounter->fadeOutAmount = 0;
    currentEncounter->unk_94 = 0;
    currentEncounter->scriptedBattle = TRUE;
    gEncounterState = ENCOUNTER_STATE_PRE_BATTLE;
    D_8009A678 = 1;
    gEncounterSubState = ENCOUNTER_SUBSTATE_PRE_BATTLE_INIT;

    return ApiStatus_DONE1;
}

API_CALLABLE(SetBattleMusic) {
    Bytecode* args = script->ptrReadPos;
    Bytecode songID = evt_get_variable(script, *args++);
    EncounterStatus* currentEncounter = &gCurrentEncounter;

    currentEncounter->allowFleeing = TRUE;
    currentEncounter->songID = songID;
    currentEncounter->unk_18 = -1;
    return ApiStatus_DONE2;
}

API_CALLABLE(BindNpcAI) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 id = evt_get_variable(script, *args++);
    EvtScript* newScriptSource = (EvtScript*)evt_get_variable(script, *args++);
    Evt* scriptTemp = script;
    ApiStatus ret = ApiStatus_DONE2;
    Evt* aiScript;
    s32 groupFlags;

    if ((s32)enemy != NPC_SELF && (id == NPC_SELF || enemy->npcID == id)) {
        id = enemy->npcID;

        while (TRUE) {
            if (scriptTemp->blockingParent != NULL) {
                scriptTemp = scriptTemp->blockingParent;
            } else {
                break;
            }
        }

        aiScript = enemy->aiScript;
        if (scriptTemp == aiScript) {
            ret = ApiStatus_FINISH;
        }
    } else {
        enemy = get_enemy(id);
    }

    if (enemy->flags & ENEMY_FLAG_PASSIVE) {
        groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
    } else {
        groupFlags = EVT_GROUP_08 | EVT_GROUP_02 | EVT_GROUP_01;
    }

    if (enemy->aiScript != NULL) {
#if VERSION_JP
        groupFlags = enemy->aiScript->groupFlags;
#endif
        kill_script_by_ID(enemy->aiScriptID);
    }

    enemy->unk_C8 = 100;
    enemy->aiBytecode = newScriptSource;
    scriptTemp = start_script(newScriptSource, EVT_PRIORITY_A, 0);
    enemy->aiScript = scriptTemp;
    enemy->aiScriptID = scriptTemp->id;
    scriptTemp->owner1.enemy = enemy;
    scriptTemp->owner2.npcID = id;
    scriptTemp->groupFlags = groupFlags;
    return ret;
}

API_CALLABLE(BindNpcIdle) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    EvtScript* aiBytecode = (EvtScript*)evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = owner->npcID;
    }

    owner = get_enemy(npcID);
    owner->aiBytecode = aiBytecode;

    return ApiStatus_DONE2;
}

API_CALLABLE(RestartNpcAI) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    Evt* newScript;
    s32 groupFlags;

    if (npcID == NPC_SELF) {
        npcID = enemy->npcID;
    }

    enemy = get_enemy(npcID);

    if (enemy->flags & ENEMY_FLAG_PASSIVE) {
        groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
    } else {
        groupFlags = EVT_GROUP_08 | EVT_GROUP_02 | EVT_GROUP_01;
    }

    if (enemy->aiScript != NULL) {
#if VERSION_JP
        groupFlags = enemy->aiScript->groupFlags;
#endif
        kill_script_by_ID(enemy->aiScriptID);
    }

    enemy->unk_C8 = 100;
    newScript = start_script(enemy->aiBytecode, EVT_PRIORITY_A, 0);
    enemy->aiScript = newScript;
    enemy->aiScriptID = newScript->id;
    newScript->owner1.enemy = enemy;
    newScript->owner2.npc = script->owner2.npc;
    newScript->groupFlags = groupFlags;

    return ApiStatus_DONE2;
}

API_CALLABLE(EnableNpcAI) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);

    if (var2 != 0) {
        if (npc->aiScript != NULL) {
            resume_all_script(npc->aiScriptID);
        }
    } else if (npc->aiScript != NULL) {
        suspend_all_script(npc->aiScriptID);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcAux) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 id = evt_get_variable(script, *args++);
    EvtScript* newScriptSource = (EvtScript*)evt_get_variable(script, *args++);
    Evt* scriptTemp = script;
    ApiStatus ret = ApiStatus_DONE2;
    Evt* auxScript;

    if ((s32)enemy != NPC_SELF && (id == NPC_SELF || enemy->npcID == id)) {
        id = enemy->npcID;

        while (TRUE) {
            if (scriptTemp->blockingParent != NULL) {
                scriptTemp = scriptTemp->blockingParent;
            } else {
                break;
            }
        }

        auxScript = enemy->auxScript;
        if (scriptTemp == auxScript) {
            ret = ApiStatus_FINISH;
        }
    } else {
        enemy = get_enemy(id);
        auxScript = enemy->auxScript;
    }

    if (auxScript != NULL) {
        kill_script_by_ID(enemy->auxScriptID);
    }

    if (newScriptSource != NULL) {
        enemy->auxBytecode = newScriptSource;
        scriptTemp = start_script(newScriptSource, EVT_PRIORITY_A, 0);
        enemy->auxScript = scriptTemp;
        enemy->auxScriptID = scriptTemp->id;
        scriptTemp->owner1.enemy = enemy;
        scriptTemp->owner2.npcID = id;
        scriptTemp->groupFlags = script->groupFlags;
    }
    return ret;
}

API_CALLABLE(BindNpcAux) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    EvtScript* auxBytecode = (EvtScript*)evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);
    npc->auxBytecode = auxBytecode;

    return ApiStatus_DONE2;
}

API_CALLABLE(RestartNpcAux) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    Evt* newScript;
    s32 groupFlags;

    if (npcID == NPC_SELF) {
        npcID = enemy->npcID;
    }

    enemy = get_enemy(npcID);

    if (enemy->flags & ENEMY_FLAG_PASSIVE) {
        groupFlags = EVT_GROUP_08 | EVT_GROUP_02;
    } else {
        groupFlags = EVT_GROUP_08 | EVT_GROUP_02 | EVT_GROUP_01;
    }

    if (enemy->auxScript != NULL) {
#if VERSION_JP
        groupFlags = enemy->auxScript->groupFlags;
#endif
        kill_script_by_ID(enemy->auxScriptID);
    }

    newScript = start_script(enemy->auxBytecode, EVT_PRIORITY_A, 0);
    enemy->auxScript = newScript;
    enemy->auxScriptID = newScript->id;
    newScript->owner1.enemy = enemy;
    newScript->owner2.npcID = npcID;
    newScript->groupFlags = groupFlags;

    return ApiStatus_DONE2;
}

API_CALLABLE(EnableNpcAux) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);

    if (var2 != 0) {
        if (npc->auxScript != NULL) {
            resume_all_script(npc->auxScriptID);
        }
    } else if (npc->auxScript != NULL) {
        suspend_all_script(npc->auxScriptID);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(BindNpcInteract) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    EvtScript* interactBytecode = (EvtScript*)evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);

    if (npc->interactScript != NULL) {
        kill_script_by_ID(npc->interactScriptID);
    }
    npc->interactBytecode = interactBytecode;

    return ApiStatus_DONE2;
}

API_CALLABLE(BindNpcHit) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    EvtScript* hitBytecode = (EvtScript*)evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);

    if (npc->hitScript != NULL) {
        kill_script_by_ID(npc->hitScriptID);
    }
    npc->hitBytecode = hitBytecode;

    return ApiStatus_DONE2;
}

API_CALLABLE(BindNpcDefeat) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    EvtScript* defeatBytecode = (EvtScript*)evt_get_variable(script, *args++);

    if (npcID == -1) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);
    npc->defeatBytecode = defeatBytecode;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetSelfVar) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    s32 index = evt_get_variable(script, *args++);
    s32 value = evt_get_variable(script, *args++);

    owner->varTable[index] = value;
    return ApiStatus_DONE2;
}

API_CALLABLE(GetSelfVar) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var0 = *args++;

    evt_set_variable(script, var0, owner->varTable[var1]);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetNpcVar) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 varIdx = evt_get_variable(script, *args++);
    s32 val = evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);
    npc->varTable[varIdx] = val;

    return ApiStatus_DONE2;
}

API_CALLABLE(GetNpcVar) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 varIdx = evt_get_variable(script, *args++);
    s32 var3 = *args++;

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);
    evt_set_variable(script, var3, npc->varTable[varIdx]);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetSelfRotation) {
    Bytecode* args = script->ptrReadPos;
    Npc* self = get_npc_unsafe(script->owner2.npcID);
    s32 rotX = evt_get_variable(script, *args++);
    s32 rotY = evt_get_variable(script, *args++);
    s32 rotZ = evt_get_variable(script, *args++);

    self->rot.x = rotX;
    self->rot.y = rotY;
    self->rot.z = rotZ;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetSelfEnemyFlags) {
    Bytecode* args = script->ptrReadPos;
    script->owner1.enemy->flags = *args++;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetSelfEnemyFlagBits) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    s32 bits = *args++;
    s32 mode = evt_get_variable(script, *args++);

    if (mode) {
        owner->flags |= bits;
    } else {
        owner->flags &= ~bits;
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SelfEnemyOverrideSyncPos) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(script->owner2.npcID);

    owner->hitboxIsActive = evt_get_variable(script, *args++);
    owner->unk_10.x = npc->pos.x;
    owner->unk_10.y = npc->pos.y;
    owner->unk_10.z = npc->pos.z;

    return ApiStatus_DONE2;
}

API_CALLABLE(GetSelfNpcID) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, script->owner1.enemy->npcID);
    return ApiStatus_DONE2;
}

API_CALLABLE(ClearDefeatedEnemies) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(currentEncounter->defeatFlags); i++) {
        for (j = 0; j < ARRAY_COUNT(currentEncounter->defeatFlags[0]); j++) {
            currentEncounter->defeatFlags[i][j] = 0;
        }
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SetEnemyFlagBits) {
    Bytecode* args = script->ptrReadPos;
    Enemy* npc = script->owner1.enemy;
    s32 npcID = evt_get_variable(script, *args++);
    s32 bits = *args++;
    s32 mode = evt_get_variable(script, *args++);

    if (npcID == NPC_SELF) {
        npcID = npc->npcID;
    }

    npc = get_enemy(npcID);

    if (mode) {
        npc->flags |= bits;
    } else {
        npc->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_8004572C) {
    return ApiStatus_DONE2;
}

API_CALLABLE(GetSelfAnimationFromTable) {
    Bytecode* args = script->ptrReadPos;
    Enemy* owner = script->owner1.enemy;
    s32 animIdx = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, owner->animList[animIdx]);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80045798) {
    Bytecode* args = script->ptrReadPos;

    gPartnerStatus.unk_358 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetOwnerInstigatorValue) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;

    enemy->instigatorValue = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleAsScripted) {
    gCurrentEncounter.scriptedBattle = TRUE;
    return ApiStatus_DONE2;
}

API_CALLABLE(GetEncounterTriggerHitTier) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCurrentEncounter.hitTier);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80045838) {
    Bytecode* args = script->ptrReadPos;
    s32 npcID = evt_get_variable(script, *args++);
    s32 soundID = evt_get_variable(script, *args++);
    s32 upperSoundFLags = evt_get_variable(script, *args++);
    Npc* npc = resolve_npc(script, npcID);

    if (npc == NULL) {
        return ApiStatus_DONE2;
    }

    ai_enemy_play_sound(npc, soundID, upperSoundFLags);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_800458CC) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, script->owner1.enemy->npcSettings->actionFlags & AI_ACTION_08);
    return ApiStatus_DONE2;
}

API_CALLABLE(OnPlayerFled) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    s32 skipReaction = evt_get_variable(script, *args++);

    enemy->aiFlags |= ENEMY_AI_FLAG_SUSPEND;

    if (!skipReaction) {
        EffectInstance* emoteEffect;

        if (!(enemy->aiFlags & ENEMY_AI_FLAG_10)) {
            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        }

        if (!(enemy->aiFlags & ENEMY_AI_FLAG_8)) {
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 0.0f, -20.0f, 40, &emoteEffect);
        }

        if ((npc->flags & (NPC_FLAG_GRAVITY | NPC_FLAG_JUMPING | NPC_FLAG_FLYING)) == (NPC_FLAG_JUMPING | NPC_FLAG_FLYING)) {
            f32 x = npc->pos.x;
            f32 y = npc->pos.y + npc->collisionHeight;
            f32 z = npc->pos.z;
            f32 a = 100.0f;

            if (npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &a) != 0) {
                npc->pos.y = y;
            }
            npc->flags &= ~NPC_FLAG_JUMPING;
        }
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetTattleMessage) {
    Bytecode* args = script->ptrReadPos;
    s32 enemyId = evt_get_variable(script, *args++);
    u32 tattleMsg = evt_get_variable(script, *args++);
    Enemy* npc = get_enemy(enemyId);

    npc->tattleMsg = tattleMsg;
    return ApiStatus_DONE2;
}
