#include "common.h"

s32 gStaticScriptCounter = 1;
s32 gIsUpdatingScripts = 0;
f32 gGlobalTimeSpace = 1.0f;

void sort_scripts(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 tempID;
    ScriptInstance* curScript;
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
            if (curScript->state != 0) {
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

void find_script_labels(ScriptInstance* script) {
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

    if (gGameStatusPtr->isBattle == 0) {
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

    func_802D4488();
    func_802CD4B4();
}

void init_script_list(void) {
    if (gGameStatusPtr->isBattle == 0) {
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

    func_802D4560();
    func_802CD57C();
}

void func_802C3390(ScriptInstance* script) {
    s32 arg;

    switch (D_8009A5D8) {
        default:
        case 0:
        case 4:
            return;
        case 1:
            arg = 1;
            break;
        case 2:
        case 3:
            arg = 2;
            break;
    }
    suspend_all_group(arg);
}

#ifdef NON_MATCHING
ScriptInstance* start_script(Bytecode* initialLine, s32 priority, s32 initialState) {
    ScriptInstance* newScript;
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

    SCRIPT_ALLOC(newScript, curScriptIndex);

    newScript->state = initialState | 1;
    newScript->currentOpcode = 0;
    newScript->priority = priority;
    newScript->ptrNextLine = initialLine;
    newScript->ptrFirstLine = initialLine;
    newScript->ptrCurrentLine = initialLine;
    newScript->userData = NULL;
    newScript->blockingParent = NULL;
    newScript->childScript = NULL;
    newScript->parentScript = NULL;
    newScript->id = gStaticScriptCounter++;
    newScript->owner1.actorID = -1;
    newScript->owner2.npcID = -1;
    newScript->loopDepth = -1;
    newScript->switchDepth = -1;
    newScript->groupFlags = ~0x10;
    newScript->ptrSavedPosition = NULL;
    newScript->frameCounter = 0.0f;
    newScript->unk_158 = 0;
    newScript->timeScale = gGlobalTimeSpace;

    scriptListCount = 0;

    for (i = 0; i < 16; i++) {
        newScript->varTable[i] = 0;
    }

    for (i = 0; i < 3; i++) {
        newScript->varFlags[i] = 0;
    }

    find_script_labels(newScript);

    if (gIsUpdatingScripts && (newScript->state & 0x20)) {
        scriptListCount = gScriptListCount++;
        gScriptIndexList[scriptListCount] = curScriptIndex;
        gScriptIdList[scriptListCount] = newScript->id;
    }
    func_802C3390(newScript);
    {
        s32* tempCounter = &gStaticScriptCounter;
        if (*tempCounter == 0) {
            *tempCounter = 1;
        }
    }
    return newScript;
}
#else
INCLUDE_ASM(ScriptInstance*, "code_e79b0_len_1920", start_script, Bytecode* initialLine, s32 priority,
            s32 initialState);
#endif

ScriptInstance* start_script_in_group(Bytecode* initialLine, u8 priority, u8 initialState, u8 groupFlags) {
    ScriptInstance* newScript;
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

    (*gCurrentScriptListPtr)[curScriptIndex] = newScript = heap_malloc(sizeof(ScriptInstance));
    numScripts = &gNumScripts;
    (*numScripts)++;
    ASSERT(newScript != NULL);

    // Some of this function is surely macros. I think we'll learn more as we do others in this file. -Ethan
    do {
        newScript->state = initialState | 1;
        newScript->currentOpcode = 0;
        newScript->priority = priority;
        newScript->id = gStaticScriptCounter++;
        newScript->ptrNextLine = initialLine;
        newScript->ptrFirstLine = initialLine;
        newScript->ptrCurrentLine = initialLine;
        newScript->userData = 0;
        newScript->blockingParent = 0;
        newScript->childScript = 0;
        newScript->parentScript = 0;
        newScript->owner1.actorID = -1;
        newScript->owner2.npcID = -1;
        newScript->loopDepth = -1;
        newScript->switchDepth = -1;
        newScript->groupFlags = groupFlags;
        newScript->ptrSavedPosition = 0;
        newScript->frameCounter = 0.0f;
        newScript->unk_158 = 0;
        newScript->timeScale = gGlobalTimeSpace;
        scriptListCount = 0;

        for (i = 0; i < ((s32)((sizeof(newScript->varTable)) / (sizeof(newScript->varTable[0])))); i++) {
            newScript->varTable[i] = 0;
        }
        for (i = 0; i < ((s32)((sizeof(newScript->varFlags)) / (sizeof(newScript->varFlags[0])))); i++) {
            newScript->varFlags[i] = 0;
        }

        find_script_labels(newScript);

        if (gIsUpdatingScripts && (newScript->state & 0x20)) {
            scriptListCount = gScriptListCount++;
            gScriptIndexList[scriptListCount] = curScriptIndex;
            gScriptIdList[scriptListCount] = newScript->id;
        }
    } while (0);

    func_802C3390(newScript);

    tempCounter = &gStaticScriptCounter;
    if (*tempCounter == 0) {
        *tempCounter = 1;
    }

    return newScript;
}

INCLUDE_ASM(s32, "code_e79b0_len_1920", start_child_script);

#ifdef NON_MATCHING
// appears to be functionally equivalent, some ordering and regalloc issues
ScriptInstance* func_802C39F8(ScriptInstance* parentScript, Bytecode* nextLine, s32 newState) {
    ScriptInstance* child;
    s32* temp6;
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
    SCRIPT_ALLOC(child, curScriptIndex);

    child->state = newState | 1;
    child->ptrNextLine = nextLine;
    child->ptrFirstLine = nextLine;
    child->ptrCurrentLine = nextLine;
    child->currentOpcode = 0;
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
    child->ptrSavedPosition = NULL;
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

    temp6 = &gStaticScriptCounter;
    if (*temp6 == 0) {
        *temp6 = 1;
    }
    func_802C3390(child);
    return child;
}
#else
INCLUDE_ASM(ScriptInstance*, "code_e79b0_len_1920", func_802C39F8, ScriptInstance* parentScript, Bytecode* nextLine,
            s32 newState);
#endif

ScriptInstance* func_802C3C10(ScriptInstance* script, Bytecode* line, s32 arg2) {
    ScriptInstance* curScript;
    s32 i;

    script->ptrNextLine = line;
    script->ptrFirstLine = line;
    script->ptrCurrentLine = line;
    script->currentOpcode = 0;
    script->frameCounter = 0;
    script->state |= arg2;
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
    func_802C3390(script);

    return script;
}

ScriptInstance* restart_script(ScriptInstance* script) {
    Bytecode* ptrFirstLine = script->ptrFirstLine;

    // frameCounter gets set to 0 twice which makes me think a macro is being used here
    script->loopDepth = -1;
    script->switchDepth = -1;
    script->frameCounter = 0;
    script->currentOpcode = 0;

    script->ptrNextLine = ptrFirstLine;
    script->ptrCurrentLine = ptrFirstLine;
    script->timeScale = 1.0f;
    script->frameCounter = 0;
    script->unk_158 = 0;

    script->timeScale = gGlobalTimeSpace;

    find_script_labels(script);
    func_802C3390(script);

    return script;
}

INCLUDE_ASM(s32, "code_e79b0_len_1920", update_scripts);

// this function is evil.
INCLUDE_ASM(s32, "code_e79b0_len_1920", func_802C3EE4);

void kill_script(ScriptInstance* instanceToKill) {
    ScriptInstance* childScript;
    ScriptInstance* blockingParent;
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
        ScriptInstance* tempScriptInstance = (*gCurrentScriptListPtr)[j];
        if (tempScriptInstance != NULL) {
            if (tempScriptInstance->parentScript == instanceToKill) {
                kill_script(tempScriptInstance);
            }
        }
    }

    blockingParent = instanceToKill->blockingParent;
    if (blockingParent != NULL) {
        blockingParent->childScript = NULL;
        blockingParent->state &= ~0x10;

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

    SCRIPT_FREE(i);
}

void kill_script_by_ID(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            kill_script(scriptContextPtr);
        }
    }
}

void kill_all_scripts(void) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            kill_script(scriptContextPtr);
        }
    }
}

s32 does_script_exist(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 does_script_exist_by_ref(ScriptInstance* script) {
    s32 i;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        if (script == (*gCurrentScriptListPtr)[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

void set_script_priority(ScriptInstance* script, s8 priority) {
    script->priority = priority;
}

void set_script_timescale(ScriptInstance* script, f32 timescale) {
    script->timeScale = timescale * gGlobalTimeSpace;
}

void set_global_timespace(f32 timeScale) {
    gGlobalTimeSpace = timeScale;
}

f32 get_global_timespace(void) {
    return gGlobalTimeSpace;
}

void set_script_group(ScriptInstance* script, s8 groupFlags) {
    script->groupFlags = groupFlags;
}

Trigger* bind_trigger(Bytecode* script, s32 flags, s32 triggerFlagIndex, s32 triggerVar0, s32 triggerVar1,
                      s32 priority, s32 arg6) {
    Trigger* trigger;
    TriggerDefinition def;

    def.flags = flags | 0x1000000;
    def.flagIndex = triggerFlagIndex;
    def.unk_14 = 0;
    def.function = _bound_script_trigger_handler;
    def.inputArg3 = arg6;

    trigger = create_trigger(&def);
    trigger->scriptStart = script;
    trigger->runningScript = NULL;
    trigger->priority = priority;
    trigger->scriptVars[0] = triggerVar0;
    trigger->scriptVars[1] = triggerVar1;
    return trigger;
}

Trigger* bind_trigger_1(Bytecode* script, s32 flags, s32 triggerFlagIndex, s32 triggerVar0, s32 triggerVar1,
                        s32 priority) {
    return bind_trigger(script, flags, triggerFlagIndex, triggerVar0, triggerVar1, priority, 1);
}

void suspend_group_script(ScriptInstance* script, s32 groupFlags) {
    int i;
    ScriptInstance* scriptContextPtr;
    ScriptInstance* childScript = script->childScript;

    if (childScript != NULL) {
        suspend_group_script(childScript, groupFlags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }

    if ((script->groupFlags & groupFlags) != 0) {
        script->state |= 0x2;
    }
}

void resume_group_script(ScriptInstance* script, s32 groupFlags) {
    int i;
    ScriptInstance* scriptContextPtr;
    ScriptInstance* childScript = script->childScript;

    if (childScript != NULL) {
        resume_group_script(childScript, groupFlags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }

    if ((script->groupFlags & groupFlags) != 0) {
        script->state &= ~0x2;
    }
}

s32 suspend_all_script(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            suspend_group_script(scriptContextPtr, 0xEF);
        }
    }
}

s32 resume_all_script(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            resume_group_script(scriptContextPtr, 0xEF);
        }
    }
}

void suspend_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->id == id) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void suspend_all_group(s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

s32 resume_all_group(s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void suspend_group_others(ScriptInstance* script, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr != script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_others(ScriptInstance* script, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr != script) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

ScriptInstance* get_script_by_index(s32 index) {
    return (*gCurrentScriptListPtr)[index];
}

ScriptInstance* get_script_by_id(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

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

void set_script_flags(ScriptInstance* script, s32 flags) {
    int i;
    ScriptInstance* scriptContextPtr;
    ScriptInstance* childScript = script->childScript;

    script->state |= flags;
    if (childScript != NULL) {
        set_script_flags(childScript, flags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            set_script_flags(script->parentScript, flags);
        }
    }
}

void clear_script_flags(ScriptInstance* script, s32 flags) {
    int i;
    ScriptInstance* scriptContextPtr;
    ScriptInstance* childScript = script->childScript;

    script->state &= ~flags;
    if (childScript != NULL) {
        clear_script_flags(childScript, flags);
    }

    for (i = 0; i < MAX_SCRIPTS; i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            clear_script_flags(scriptContextPtr, flags);
        }
    }
}
