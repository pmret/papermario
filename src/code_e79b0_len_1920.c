#include "common.h"

INCLUDE_ASM(code_e79b0_len_1920, sort_scripts);

INCLUDE_ASM(code_e79b0_len_1920, find_script_labels);

INCLUDE_ASM(code_e79b0_len_1920, clear_script_list);

INCLUDE_ASM(code_e79b0_len_1920, init_script_list);

INCLUDE_ASM(code_e79b0_len_1920, func_802C3390);

INCLUDE_ASM(code_e79b0_len_1920, start_script);

INCLUDE_ASM(code_e79b0_len_1920, start_script_in_group);

INCLUDE_ASM(code_e79b0_len_1920, start_child_script);

INCLUDE_ASM(code_e79b0_len_1920, func_802C39F8);

INCLUDE_ASM(code_e79b0_len_1920, restart_script);
// TODO: Find out why things break when script->timeScale = 1 goes after the previous lines
/*
script_context* restart_script(script_context* script) {
    script->loopDepth = -1;
    script->switchDepth = -1;
    script->currentOpcode = 0;
    script->frameCounter = 0;
    script->frameCounter = 0;
    script->unk_158 = 0;

    //script->timeScale = 1;
    script->ptrNextLine = script->ptrFirstLine;
    script->ptrCurrentLine = script->ptrFirstLine;
    script->timeScale = 1.0f;


    script->timeScale = gGlobalTimeSpace;
    find_script_labels();
    func_802C3390(script);
    return script;
}
*/

INCLUDE_ASM(code_e79b0_len_1920, update_scripts);

INCLUDE_ASM(code_e79b0_len_1920, func_802C3EE4);

INCLUDE_ASM(code_e79b0_len_1920, kill_script);

void* kill_script_by_ID(s32 id) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            kill_script(scriptContextPtr);
        }
    }
}

s32 kill_all_scripts(void) {
    s32 i;
    script_context* scriptContextPtr;

    for(i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            kill_script(scriptContextPtr);
        }
    }
    return;
}

s32 does_script_exist(s32 id) {
    s32 i;
    script_context* scriptContextPtr;

    for(i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            return 1;
        }
    }
    return 0;
}

s32 does_script_exist_by_ref(script_context* script) {
    s32 i;

    for(i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        if(script == (*gCurrentScriptListPtr)[i]) {
            return 1;
        }
    }
    return 0;
}

void set_script_priority(script_context* script, s8 priority) {
    script->priority = priority;
}

void set_script_timescale(script_context* script, f32 timeScale) {
    script->timeScale = timeScale * gGlobalTimeSpace;
}

INCLUDE_ASM(code_e79b0_len_1920, set_global_timespace);
/*
// TODO: figure out why compiler/assembler isn't putting SWC1 in delay slot
void set_global_timespace(f32 timeScale) {
    //gGlobalTimeSpace = timeScale;
}
*/


INCLUDE_ASM(code_e79b0_len_1920, get_global_timespace);
/*
// TODO: figure out why compiler/assembler isn't putting LWC1 in delay slot
f32 get_global_timespace(void) {
    //return gGlobalTimeSpace;
}
*/

void set_script_group(script_context* script, s8 groupFlags) {
    script->groupFlags = groupFlags;
}

INCLUDE_ASM(code_e79b0_len_1920, bind_trigger);

INCLUDE_ASM(code_e79b0_len_1920, bind_trigger_1);

void suspend_group_script(script_context* script, s32 groupFlags) {
    int i;
    script_context* scriptContextPtr;
    script_context* childScript = script->childScript;

    if (childScript != NULL) {
        suspend_group_script(childScript, groupFlags);
    }

    for(i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }

    if ((script->groupFlags & groupFlags) != 0) {
        script->state |= 0x2;
    }
}

void resume_group_script(script_context* script, s32 groupFlags) {
    int i;
    script_context* scriptContextPtr;
    script_context* childScript = script->childScript;

    if (childScript != NULL) {
        resume_group_script(childScript, groupFlags);
    }

    for(i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
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
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            suspend_group_script(scriptContextPtr, 0xEF);
        }
    }
}

s32 resume_all_script(s32 id) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            resume_group_script(scriptContextPtr, 0xEF);
        }
    }
}

void suspend_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_script_index(s32 id, s32 groupFlags) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

s32 suspend_all_group(s32 groupFlags) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

s32 resume_all_group(s32 groupFlags) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}


void suspend_group_others(s32 script, s32 groupFlags) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr != script) {
            suspend_group_script(scriptContextPtr, groupFlags);
        }
    }
}

void resume_group_others(s32 script, s32 groupFlags) {
    s32 i;
    script_context* scriptContextPtr;

    for (i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr != script) {
            resume_group_script(scriptContextPtr, groupFlags);
        }
    }
}

script_context* get_script_by_index(s32 index) {
    return (*gCurrentScriptListPtr)[index];
}

script_context* get_script_by_id(s32 id) {
    s32 i;
    script_context* scriptContextPtr;

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

void set_script_flags(script_context* script, s32 flags) {
    int i;
    script_context* scriptContextPtr;
    script_context* childScript = script->childScript;

    script->state |= flags;
    if (childScript != NULL) {
        set_script_flags(childScript, flags);
    }

    for(i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            set_script_flags(script->parentScript, flags);
        }
    }
}

INCLUDE_ASM(code_e79b0_len_1920, clear_script_flags);
/*
// TODO: Really close but some weirdness is going on
void clear_script_flags(script_context* script, s32 flags) {
    int i;
    script_context* scriptContextPtr;
    script_context* childScript = script->childScript;

    script->state &= ~flags;
    if (childScript != NULL) {
        clear_script_flags(childScript, flags);
    }

    for(i = 0; i < ARRAY_COUNT(gCurrentScriptListPtr); i++) {
        scriptContextPtr = (*gCurrentScriptListPtr)[i];
        if (scriptContextPtr != NULL && scriptContextPtr->parentScript == script) {
            clear_script_flags(script->parentScript, flags);
        }
    }
}
*/
