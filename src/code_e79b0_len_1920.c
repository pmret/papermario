#include "common.h"

INCLUDE_ASM("code_e79b0_len_1920", sort_scripts);

INCLUDE_ASM("code_e79b0_len_1920", find_script_labels);

INCLUDE_ASM("code_e79b0_len_1920", clear_script_list);

INCLUDE_ASM("code_e79b0_len_1920", init_script_list);

INCLUDE_ASM("code_e79b0_len_1920", func_802C3390);

INCLUDE_ASM("code_e79b0_len_1920", start_script);

INCLUDE_ASM("code_e79b0_len_1920", start_script_in_group);

INCLUDE_ASM("code_e79b0_len_1920", start_child_script);

INCLUDE_ASM("code_e79b0_len_1920", func_802C39F8);

#ifdef NON_MATCHING
ScriptInstance* restart_script(ScriptInstance* script) {
    script->loopDepth = -1;
    script->switchDepth = -1;
    script->currentOpcode = 0;
    script->frameCounter = 0; // TODO: force compiler to not optimise away this
    script->frameCounter = 0;
    script->unk_158 = 0;

    script->ptrNextLine = script->ptrFirstLine;
    script->ptrCurrentLine = script->ptrFirstLine;

    script->timeScale = 1.0f;
    script->timeScale = gGlobalTimeSpace;

    find_script_labels();
    func_802C3390(script);

    return script;
}
#else
INCLUDE_ASM("code_e79b0_len_1920", restart_script);
#endif

INCLUDE_ASM("code_e79b0_len_1920", update_scripts);

INCLUDE_ASM("code_e79b0_len_1920", func_802C3EE4);

INCLUDE_ASM("code_e79b0_len_1920", kill_script);

void kill_script_by_ID(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            kill_script(scriptContextPtr);
        }
    }
}

void kill_all_scripts(void) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            kill_script(scriptContextPtr);
        }
    }
}

s32 does_script_exist(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            return 1;
        }
    }
    return 0;
}

s32 does_script_exist_by_ref(ScriptInstance* script) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        if (script == (*gCurrentScriptListPtr)[i]) {
            return 1;
        }
    }
    return 0;
}

void set_script_priority(ScriptInstance* script, s8 priority) {
    script->priority = priority;
}

void set_script_timescale(ScriptInstance* script, f32 timescale) {
    script->timeScale = timescale * gGlobalTimeSpace;
}

#ifdef NON_MATCHING
// TODO: figure out why compiler/assembler isn't putting SWC1 in delay slot
void set_global_timespace(f32 timeScale) {
    //gGlobalTimeSpace = timeScale;
}
#else
INCLUDE_ASM("code_e79b0_len_1920", set_global_timespace);
#endif

#ifdef NON_MATCHING
// TODO: figure out why compiler/assembler isn't putting LWC1 in delay slot
f32 get_global_timespace(void) {
    //return gGlobalTimeSpace;
}
#else
INCLUDE_ASM("code_e79b0_len_1920", get_global_timespace);
#endif

void set_script_group(ScriptInstance* script, s8 groupFlags) {
    script->groupFlags = groupFlags;
}

INCLUDE_ASM("code_e79b0_len_1920", bind_trigger);

INCLUDE_ASM("code_e79b0_len_1920", bind_trigger_1);

void suspend_group_script(ScriptInstance* script, s32 groupFlags) {
    int i;
    ScriptInstance* scriptContextPtr;
    ScriptInstance* childScript = script->childScript;

    if (childScript != NULL) {
        suspend_group_script(childScript, groupFlags);
    }

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
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

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }

    if ((script->groupFlags & groupFlags) != 0) {
        script->state &= 0xFD;
    }
}

s32 suspend_all_script(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            suspend_group_script(scriptContextPtr, 0xEF);
        }
    }
}

s32 resume_all_script(s32 id) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            resume_group_script(scriptContextPtr, 0xEF);
        }
    }
}

void suspend_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

s32 suspend_all_group(s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

s32 resume_all_group(s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void suspend_group_others(ScriptInstance* script, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr != script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_others(ScriptInstance* script, s32 groupFlags) {
    s32 i;
    ScriptInstance* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
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

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        if ((*gCurrentScriptListPtr)[i] != NULL) {
            scriptContextPtr = (*gCurrentScriptListPtr)[i];
            if (scriptContextPtr->uniqueID == id) {
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

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            set_script_flags(script->parentScript, flags);
        }
    }
}

#ifdef NON_MATCHING
// TODO: Really close but some weirdness is going on
void clear_script_flags(ScriptInstance* script, s32 flags) {
    int i;
    ScriptInstance* scriptContextPtr;
    ScriptInstance* childScript = script->childScript;

    script->state &= ~flags;
    if (childScript != NULL) {
        clear_script_flags(childScript, flags);
    }

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            clear_script_flags(script->parentScript, flags);
        }
    }
}
#else
INCLUDE_ASM("code_e79b0_len_1920", clear_script_flags);
#endif
