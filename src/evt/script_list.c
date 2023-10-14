#include "common.h"
#include "hud_element.h"

s32 gStaticScriptCounter = 1;
s32 gIsUpdatingScripts = 0;
f32 gGlobalTimeSpace = 1.0f;

// script_list
BSS u32* gMapFlags;
BSS s32* gMapVars;
BSS s32 gNumScripts;
BSS s32 D_802DA48C; // unused?
BSS ScriptList gWorldScriptList;
BSS ScriptList gBattleScriptList;
BSS ScriptList* gCurrentScriptListPtr;
BSS s32 D_802DA894; // unused?
BSS s32 gScriptIndexList[MAX_SCRIPTS];
BSS s32 gScriptIdList[MAX_SCRIPTS];
BSS s32 gScriptListCount;
BSS s32 D_802DAC9C; // unused?

// evt
BSS char evtDebugPrintBuffer[0x100];

// map_api
BSS struct LavaReset* gLavaResetList;
BSS s32 LastSafeFloor;
BSS s32 D_802DADA8[2]; // unused?

// model_api
BSS AnimatedModelList gBattleMeshAnimationList;
BSS AnimatedModelList gWorldMeshAnimationList;
BSS AnimatedModelList* gCurrentMeshAnimationListPtr;
BSS s32 D_802DAE34[3]; // unused?

// npc_api
BSS s32 wExtraPartnerID;
BSS s32 wExtraPartnerNpcID;
BSS s32 D_802DAE4C[2]; // unused?

// msg_api
BSS s32 ShowMessageScreenOffsetX;
BSS s32 ShowMessageScreenOffsetY;
BSS s32 D_802DAE58[2]; // unused?
BSS char D_802DAE60[0x400]; // unused?
BSS MessagePrintState* gCurrentPrintContext;
BSS s32 D_802DB264;
BSS MessagePrintState* D_802DB268;
BSS s32 D_802DB26C; // unused?

// player_api
BSS Npc playerNpcData;
BSS u16 PlayerImgFXFlags;
BSS s32 D_802DB5B4[3]; // unused
BSS VirtualEntityList bBattleVirtualEntityList;
BSS VirtualEntityList wWorldVirtualEntityList;
BSS VirtualEntityList* gCurrentVirtualEntityListPtr;
BSS s32 D_802DB7C4[3]; // unused

// audio_api
BSS MusicEvent* MusicEventList;
BSS s32 D_802DB7D4; // unused?
BSS Evt* RunningMusicEvents[10];
BSS s32 RunningMusicEventIDs[10];
BSS s32 D_802DB828[2]; // unused?

// item_api
BSS PopupMenu D_802DB830;

#if VERSION_PAL
BSS s32 D_PAL_BSS_802E1E34[0x3]; // TODO: probably just alignment
#endif

// demo_api
BSS s32 gSpriteShadingHeader;
BSS s32 D_802DBB64; // unused?
BSS s32 gSpriteShadingData;
BSS s32 D_802DB8B6C; // unused?
BSS char D_802DBB70[0x100];

// why is this at the end? com section vs bss?
BSS u32 gWorldMapFlags[MAX_MAPFLAGS];
BSS s32 DoorModelsSwingCW[3];
BSS PushBlockGrid* wPushBlockGrids[8];
BSS u32 gWorldMapVars[MAX_MAPVARS];
BSS u32 gBattleMapVars[MAX_MAPVARS];
BSS s32 DoorModelsSwingCCW[3];
BSS u32 gBattleMapFlags[MAX_MAPFLAGS];

s32 evt_execute_next_command(Evt* script);

void sort_scripts(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 tempID;
    Evt* curScript;
    ScriptList** currentScriptListPtr;
    s32 i;
    s32 j;
    s32 x;
    s32 numValidScripts = 0;
    s32* scriptIndexList = gScriptIndexList;
    s32* scriptIdList = gScriptIdList;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        curScript = (*gCurrentScriptListPtr)[i];
        if (curScript != NULL) {
            if (curScript->stateFlags != 0) {
                scriptIndexList[numValidScripts] = i;
                scriptIdList[numValidScripts] = curScript->id;
                numValidScripts++;
            }
        }
    }

    gScriptListCount = numValidScripts;
    for (i = 0; i < (x = numValidScripts - 1); i++) {
        scriptIndexList = gScriptIndexList;
        currentScriptListPtr = &gCurrentScriptListPtr;
        scriptIdList = gScriptIdList;
        for (j = i + 1; j < numValidScripts; j++) {
            temp_a1 = scriptIndexList[i];
            temp_a0 = scriptIndexList[j];
            x = i;
            if ((**currentScriptListPtr)[temp_a1]->priority > (**currentScriptListPtr)[temp_a0]->priority) {
                scriptIndexList[i] = temp_a0;
                scriptIndexList[j] = temp_a1;
                tempID = scriptIdList[i];
                scriptIdList[i] = scriptIdList[j];
                scriptIdList[j] = tempID;
            }
        }
    }
}

void find_script_labels(Evt* script) {
    Bytecode* curLine;
    s32 type;
    s32 label;
    s32 numArgs;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(script->labelIndices); i++) {
        script->labelIndices[i] = -1;
        script->labelPositions[i] = 0;
    }

    j = 0;
    curLine = script->ptrNextLine;
    while (j < ARRAY_COUNT(script->labelIndices)) {
        type = *curLine++;
        numArgs = *curLine++;
        label = *curLine;
        curLine += numArgs;

        if (type == 1) {
            return;
        }

        if (type == 3) {
            script->labelIndices[j] = label;
            script->labelPositions[j] = curLine;
            j++;
        }
    }
    PANIC();
}

void clear_script_list(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentScriptListPtr = &gWorldScriptList;
        gMapVars = gWorldMapVars;
        gMapFlags = gWorldMapFlags;
    } else {
        gCurrentScriptListPtr = &gBattleScriptList;
        gMapVars = gBattleMapVars;
        gMapFlags = gBattleMapFlags;
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        (*gCurrentScriptListPtr)[i] = NULL;
    }

    gNumScripts = 0;
    gScriptListCount = 0;
    gIsUpdatingScripts = 0;

    for (i = 0; i < MAX_MAPVARS; i++) {
        gMapVars[i] = 0;
    }

    for (i = 0; i < MAX_MAPFLAGS; i++) {
        gMapFlags[i] = 0;
    }

    clear_virtual_entity_list();
    reset_model_animators();
}

void init_script_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentScriptListPtr = &gWorldScriptList;
        gMapVars = gWorldMapVars;
        gMapFlags = gWorldMapFlags;
    } else {
        gCurrentScriptListPtr = &gBattleScriptList;
        gMapVars = gBattleMapVars;
        gMapFlags = gBattleMapFlags;
    }

    gNumScripts = 0;
    gIsUpdatingScripts = 0;

    init_virtual_entity_list();
    init_model_animators();
}

void suspend_frozen_scripts(Evt* script) {
    s32 groupFlags;

    switch (timeFreezeMode) {
        default:
        case 0:
        case 4:
            return;
        case 1:
            groupFlags = EVT_GROUP_01;
            break;
        case 2:
        case 3:
            groupFlags = EVT_GROUP_02;
            break;
    }
    suspend_all_group(groupFlags);
}

Evt* start_script(EvtScript* source, s32 priority, s32 flags) {
    Evt* newScript;
    s32 curScriptIndex;
    s32 scriptListCount;
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if ((*gCurrentScriptListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < MAX_SCRIPTS);
    curScriptIndex = i;

    (*gCurrentScriptListPtr)[curScriptIndex] = newScript = heap_malloc(sizeof(*newScript));
    gNumScripts++;
    ASSERT(newScript != NULL);

    newScript->stateFlags = flags | EVT_FLAG_ACTIVE;
    newScript->curOpcode = EVT_OP_INTERNAL_FETCH;
    newScript->priority = priority;
    newScript->ptrNextLine = (Bytecode*)source;
    newScript->ptrFirstLine = (Bytecode*)source;
    newScript->ptrCurLine = (Bytecode*)source;
    newScript->userData = NULL;
    newScript->blockingParent = NULL;
    newScript->childScript = NULL;
    newScript->parentScript = NULL;
    newScript->id = gStaticScriptCounter++;
    newScript->owner1.actorID = -1;
    newScript->owner2.npcID = -1;
    newScript->loopDepth = -1;
    newScript->switchDepth = -1;
    newScript->groupFlags = ~EVT_GROUP_10;
    newScript->ptrSavedPos = NULL;
    newScript->frameCounter = 0.0f;
    newScript->unk_158 = 0;
    newScript->timeScale = gGlobalTimeSpace;

    scriptListCount = 0;

    for (i = 0; i < ARRAY_COUNT(newScript->varTable); i++) {
        newScript->varTable[i] = 0;
    }

    for (i = 0; i < ARRAY_COUNT(newScript->varFlags); i++) {
        newScript->varFlags[i] = 0;
    }

    find_script_labels(newScript);

    if (gIsUpdatingScripts && (newScript->stateFlags & EVT_FLAG_RUN_IMMEDIATELY)) {
        scriptListCount = gScriptListCount++;
        gScriptIndexList[scriptListCount] = curScriptIndex;
        gScriptIdList[scriptListCount] = newScript->id;
    }

    suspend_frozen_scripts(newScript);

    if (gStaticScriptCounter == 0) {
        gStaticScriptCounter = 1;
    }

    return newScript;
}

Evt* start_script_in_group(EvtScript* source, u8 priority, u8 flags, u8 groupFlags) {
    Evt* newScript;
    s32 scriptListCount;
    s32 i;
    s32 curScriptIndex;
    s32* tempCounter;
    s32* numScripts;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if ((*gCurrentScriptListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < MAX_SCRIPTS);
    curScriptIndex = i;

    (*gCurrentScriptListPtr)[curScriptIndex] = newScript = heap_malloc(sizeof(*newScript));
    numScripts = &gNumScripts;
    (*numScripts)++;
    ASSERT(newScript != NULL);

    // Some of this function is surely macros. I think we'll learn more as we do others in this file. -Ethan
    do {
        newScript->stateFlags = flags | EVT_FLAG_ACTIVE;
        newScript->curOpcode = EVT_OP_INTERNAL_FETCH;
        newScript->priority = priority;
        newScript->id = gStaticScriptCounter++;
        newScript->ptrNextLine = (Bytecode*)source;
        newScript->ptrFirstLine = (Bytecode*)source;
        newScript->ptrCurLine = (Bytecode*)source;
        newScript->userData = 0;
        newScript->blockingParent = 0;
        newScript->childScript = 0;
        newScript->parentScript = 0;
        newScript->owner1.actorID = -1;
        newScript->owner2.npcID = -1;
        newScript->loopDepth = -1;
        newScript->switchDepth = -1;
        newScript->groupFlags = groupFlags;
        newScript->ptrSavedPos = 0;
        newScript->frameCounter = 0.0f;
        newScript->unk_158 = 0;
        newScript->timeScale = gGlobalTimeSpace;
        scriptListCount = 0;

        for (i = 0; i < ARRAY_COUNT(newScript->varTable); i++) {
            newScript->varTable[i] = 0;
        }
        for (i = 0; i < ARRAY_COUNT(newScript->varFlags); i++) {
            newScript->varFlags[i] = 0;
        }

        find_script_labels(newScript);

        if (gIsUpdatingScripts && (newScript->stateFlags & EVT_FLAG_RUN_IMMEDIATELY)) {
            scriptListCount = gScriptListCount++;
            gScriptIndexList[scriptListCount] = curScriptIndex;
            gScriptIdList[scriptListCount] = newScript->id;
        }
    } while (0);

    suspend_frozen_scripts(newScript);

    tempCounter = &gStaticScriptCounter;
    if (*tempCounter == 0) {
        *tempCounter = 1;
    }

    return newScript;
}

Evt* start_child_script(Evt* parentScript, EvtScript* source, s32 flags) {
    s32 curScriptIndex;
    s32 scriptListCount;
    Evt* child;
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if ((*gCurrentScriptListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < MAX_SCRIPTS);
    curScriptIndex = i;

    (*gCurrentScriptListPtr)[curScriptIndex] = child = heap_malloc(sizeof(*child));
    gNumScripts++;
    ASSERT(child != NULL);

    parentScript->childScript = child;
    parentScript->stateFlags |= EVT_FLAG_BLOCKED_BY_CHILD;
    child->stateFlags = flags | EVT_FLAG_ACTIVE;
    child->ptrCurLine = child->ptrFirstLine = child->ptrNextLine = (Bytecode*)source;


    child->curOpcode = EVT_OP_INTERNAL_FETCH;
    child->userData = NULL;
    child->blockingParent = parentScript;
    child->childScript = NULL;
    child->parentScript = NULL;
    child->priority = parentScript->priority + 1;
    child->id = gStaticScriptCounter++;
    child->owner1 = parentScript->owner1;
    child->owner2 = parentScript->owner2;
    child->loopDepth = -1;
    child->switchDepth = -1;
    child->groupFlags = parentScript->groupFlags;
    child->ptrSavedPos = NULL;
    child->array = parentScript->array;
    child->flagArray = parentScript->flagArray;
    child->timeScale = gGlobalTimeSpace;
    child->frameCounter = 0.0f;
    child->unk_158 = 0;

    scriptListCount = 0;

    for (i = 0; i < ARRAY_COUNT(child->varTable); i++) {
        child->varTable[i] = parentScript->varTable[i];
    }

    for (i = 0; i < ARRAY_COUNT(child->varFlags); i++) {
        child->varFlags[i] = parentScript->varFlags[i];
    }

    find_script_labels(child);
    if (gIsUpdatingScripts) {
        scriptListCount = gScriptListCount++;
        gScriptIndexList[scriptListCount] = curScriptIndex;
        gScriptIdList[scriptListCount] = child->id;
    }

    suspend_frozen_scripts(child);

    if (gStaticScriptCounter == 0) {
        gStaticScriptCounter = 1;
    }

    return child;
}

Evt* func_802C39F8(Evt* parentScript, Bytecode* nextLine, s32 newState) {
    Evt* child;
    s32 curScriptIndex;
    s32 i;
    s32 scriptListCount;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if ((*gCurrentScriptListPtr)[i] == NULL) {
            break;
        }
    }

    ASSERT(i < MAX_SCRIPTS);
    curScriptIndex = i;

    (*gCurrentScriptListPtr)[curScriptIndex] = child = heap_malloc(sizeof(*child));
    gNumScripts++;
    ASSERT(child != NULL);

    child->stateFlags = newState | EVT_FLAG_ACTIVE;
    child->ptrNextLine = nextLine;
    child->ptrFirstLine = nextLine;
    child->ptrCurLine = nextLine;
    child->curOpcode = EVT_OP_INTERNAL_FETCH;
    child->userData = NULL;
    child->blockingParent = NULL;
    child->parentScript = parentScript;
    child->childScript = NULL;
    child->priority = parentScript->priority;
    child->id = gStaticScriptCounter++;
    child->owner1.actorID = parentScript->owner1.actorID;
    child->owner2.npcID = parentScript->owner2.npcID;
    child->loopDepth = -1;
    child->switchDepth = -1;
    child->groupFlags = parentScript->groupFlags;
    child->ptrSavedPos = NULL;
    child->array = parentScript->array;
    child->flagArray = parentScript->flagArray;
    child->timeScale = gGlobalTimeSpace;
    child->frameCounter = 0.0f;
    child->unk_158 = 0;

    scriptListCount = 0;

    for (i = 0; i < ARRAY_COUNT(child->varTable); i++) {
        child->varTable[i] = parentScript->varTable[i];
    }

    for (i = 0; i < ARRAY_COUNT(child->varFlags); i++) {
        child->varFlags[i] = parentScript->varFlags[i];
    }

    find_script_labels(child);
    if (gIsUpdatingScripts) {
        scriptListCount = gScriptListCount++;
        gScriptIndexList[scriptListCount] = curScriptIndex;
        gScriptIdList[scriptListCount] = child->id;
    }

    if (gStaticScriptCounter == 0) {
        gStaticScriptCounter = 1;
    }

    suspend_frozen_scripts(child);
    return child;
}

Evt* func_802C3C10(Evt* script, Bytecode* line, s32 arg2) {
    Evt* curScript;
    s32 i;

    script->ptrNextLine = line;
    script->ptrFirstLine = line;
    script->ptrCurLine = line;
    script->curOpcode = EVT_OP_INTERNAL_FETCH;
    script->frameCounter = 0;
    script->stateFlags |= arg2;
    script->timeScale = 1.0f;

    if (script->userData != NULL) {
        heap_free(script->userData);
        script->userData = NULL;
    }

    if (script->childScript != 0) {
        kill_script(script->childScript);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        curScript = (*gCurrentScriptListPtr)[i];
        if ((curScript != 0) && (curScript->parentScript == script)) {
            kill_script(curScript);
        }
    }
    script->loopDepth = -1;
    script->switchDepth = -1;
    script->blockingParent = NULL;
    script->parentScript = NULL;
    script->childScript = NULL;
    script->frameCounter = 0.0f;
    script->unk_158 = 0;
    script->timeScale = gGlobalTimeSpace;
    find_script_labels(script);
    suspend_frozen_scripts(script);

    return script;
}

Evt* restart_script(Evt* script) {
    Bytecode* ptrFirstLine = script->ptrFirstLine;

    // frameCounter gets set to 0 twice which makes me think a macro is being used here
    script->loopDepth = -1;
    script->switchDepth = -1;
    script->frameCounter = 0;
    script->curOpcode = EVT_OP_INTERNAL_FETCH;

    script->ptrNextLine = ptrFirstLine;
    script->ptrCurLine = ptrFirstLine;
    script->timeScale = 1.0f;
    script->frameCounter = 0;
    script->unk_158 = 0;

    script->timeScale = gGlobalTimeSpace;

    find_script_labels(script);
    suspend_frozen_scripts(script);

    return script;
}

void update_scripts(void) {
    s32 i;

    if (gGameStatusPtr->debugScripts == DEBUG_SCRIPTS_NO_UPDATE) {
        return;
    }

    gIsUpdatingScripts = TRUE;
    sort_scripts();

    for (i = 0; i < gScriptListCount; i++) {
        Evt* script = (*gCurrentScriptListPtr)[gScriptIndexList[i]];

        if (script != NULL &&
            script->id == gScriptIdList[i] &&
            script->stateFlags != 0 &&
            !(script->stateFlags & (EVT_FLAG_SUSPENDED | EVT_FLAG_BLOCKED_BY_CHILD | EVT_FLAG_SUSPENDED_IN_GROUP)))
        {
            s32 stop = FALSE;
            s32 status;

            script->frameCounter += script->timeScale;

            do {
                if (script->frameCounter < 1.0) {
                    // Continue to next script
                    do {} while (0); // TODO required to match
                    break;
                };

                script->frameCounter -= 1.0;
                status = evt_execute_next_command(script);
                if (status == EVT_CMD_RESULT_ERROR) {
                    stop = TRUE;
                    break;
                }
            } while (status != EVT_CMD_RESULT_YIELD);

            if (stop) {
                break;
            }
        }
    }
    gIsUpdatingScripts = FALSE;
}

// Does nothing, is cursed
void func_802C3EE4(void) {
    s32 temp;
    s32 i;

    for (i = 0; i < gScriptListCount; i++) {
        temp = (s32) (*gCurrentScriptListPtr)[gScriptIndexList[i]];
        temp = *((s32*) temp);
        if (temp == gScriptIdList[i]) {
            temp = 1;
        }
    }
}

void kill_script(Evt* instanceToKill) {
    Evt* childScript;
    Evt* blockingParent;
    s32 j;
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if ((*gCurrentScriptListPtr)[i] == instanceToKill) {
            break;
        }
    }

    if (i >= MAX_SCRIPTS) {
        return;
    }

    childScript = instanceToKill->childScript;
    if (childScript != NULL) {
        kill_script(childScript);
    }

    for (j = 0; j < MAX_SCRIPTS; j++) {
        Evt* tempScriptInstance = (*gCurrentScriptListPtr)[j];
        if (tempScriptInstance != NULL) {
            if (tempScriptInstance->parentScript == instanceToKill) {
                kill_script(tempScriptInstance);
            }
        }
    }

    blockingParent = instanceToKill->blockingParent;
    if (blockingParent != NULL) {
        blockingParent->childScript = NULL;
        blockingParent->stateFlags &= ~EVT_FLAG_BLOCKED_BY_CHILD;

        for (j = 0; j < ARRAY_COUNT(blockingParent->varTable); j++) {
            blockingParent->varTable[j] = instanceToKill->varTable[j];
        }

        for (j = 0; j < ARRAY_COUNT(blockingParent->varFlags); j++) {
            blockingParent->varFlags[j] = instanceToKill->varFlags[j];
        }
    }

    if (instanceToKill->userData != NULL) {
        heap_free(instanceToKill->userData);
        instanceToKill->userData = NULL;
    }

    heap_free((*gCurrentScriptListPtr)[i]);
    (*gCurrentScriptListPtr)[i] = NULL;
    gNumScripts--;
}

void kill_script_by_ID(s32 id) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            kill_script(scriptContextPtr);
        }
    }
}

void kill_all_scripts(void) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            kill_script(scriptContextPtr);
        }
    }
}

s32 does_script_exist(s32 id) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 does_script_exist_by_ref(Evt* script) {
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if (script == (*gCurrentScriptListPtr)[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

void set_script_priority(Evt* script, s32 priority) {
    script->priority = priority;
}

void set_script_timescale(Evt* script, f32 timescale) {
    script->timeScale = timescale * gGlobalTimeSpace;
}

void set_global_timespace(f32 timeScale) {
    gGlobalTimeSpace = timeScale;
}

f32 get_global_timespace(void) {
    return gGlobalTimeSpace;
}

void set_script_group(Evt* script, s32 groupFlags) {
    script->groupFlags = groupFlags;
}

Trigger* bind_trigger(EvtScript* script, s32 flags, s32 triggerFlagIndex, s32 triggerVar0, s32 triggerVar1,
                      s32 priority, s32 arg6) {
    Trigger* trigger;
    TriggerBlueprint bp;

    bp.flags = flags | TRIGGER_SCRIPT_BOUND;
    bp.colliderID = triggerFlagIndex;
    bp.tattleMsg = 0;
    bp.onActivateFunc = evt_trigger_on_activate_exec_script;
    bp.hasPlayerInteractPrompt = arg6;

    trigger = create_trigger(&bp);
    trigger->onTriggerEvt = script;
    trigger->runningScript = NULL;
    trigger->priority = priority;
    trigger->varTable[0] = triggerVar0;
    trigger->varTable[1] = triggerVar1;
    return trigger;
}

Trigger* bind_trigger_1(EvtScript* script, s32 flags, s32 triggerFlagIndex, s32 triggerVar0, s32 triggerVar1,
                        s32 priority) {
    return bind_trigger(script, flags, triggerFlagIndex, triggerVar0, triggerVar1, priority, 1);
}

void suspend_group_script(Evt* script, s32 groupFlags) {
    Evt* childScript = script->childScript;
    s32 i;

    if (childScript != NULL) {
        suspend_group_script(childScript, groupFlags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        Evt* scriptContextPtr = (*gCurrentScriptListPtr)[i];

        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }

    if ((script->groupFlags & groupFlags) != 0) {
        script->stateFlags |= EVT_FLAG_SUSPENDED_IN_GROUP;
    }
}

void resume_group_script(Evt* script, s32 groupFlags) {
    Evt* childScript = script->childScript;
    s32 i;

    if (childScript != NULL) {
        resume_group_script(childScript, groupFlags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        Evt* scriptContextPtr = (*gCurrentScriptListPtr)[i];

        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }

    if ((script->groupFlags & groupFlags) != 0) {
        script->stateFlags &= ~EVT_FLAG_SUSPENDED_IN_GROUP;
    }
}

s32 suspend_all_script(s32 id) {
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        Evt* scriptContextPtr = (*gCurrentScriptListPtr)[i];

        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            suspend_group_script(scriptContextPtr, 0xEF);
        }
    }
}

s32 resume_all_script(s32 id) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            resume_group_script(scriptContextPtr, 0xEF);
        }
    }
}

void suspend_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void suspend_all_group(s32 groupFlags) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

s32 resume_all_group(s32 groupFlags) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void suspend_group_others(Evt* script, s32 groupFlags) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr != script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_others(Evt* script, s32 groupFlags) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr != script) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

Evt* get_script_by_index(s32 index) {
    return (*gCurrentScriptListPtr)[index];
}

Evt* get_script_by_id(s32 id) {
    s32 i;
    Evt* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if ((*gCurrentScriptListPtr)[i] != NULL) {
            scriptContextPtr = (*gCurrentScriptListPtr)[i];
            if (scriptContextPtr->id == id) {
                return scriptContextPtr;
            }
        }
    }
    return 0;
}

void set_script_flags(Evt* script, s32 flags) {
    Evt* childScript = script->childScript;
    s32 i;

    script->stateFlags |= flags;
    if (childScript != NULL) {
        set_script_flags(childScript, flags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        Evt* scriptContextPtr = (*gCurrentScriptListPtr)[i];

        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            set_script_flags(script->parentScript, flags);
        }
    }
}

void clear_script_flags(Evt* script, s32 flags) {
    Evt* childScript = script->childScript;
    s32 i;

    script->stateFlags &= ~flags;
    if (childScript != NULL) {
        clear_script_flags(childScript, flags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        Evt* scriptContextPtr = (*gCurrentScriptListPtr)[i];

        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            clear_script_flags(scriptContextPtr, flags);
        }
    }
}
