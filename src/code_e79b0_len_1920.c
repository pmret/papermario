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

INCLUDE_ASM(code_e79b0_len_1920, update_scripts);

INCLUDE_ASM(code_e79b0_len_1920, func_802C3EE4);

INCLUDE_ASM(code_e79b0_len_1920, kill_script);

void* kill_script_by_ID(s32 id) {
    s32 i;
    script_context* scriptContextPtr;

    for (i=0; i < MAX_SCRIPT_LIST_LENGTH; i++) {
        scriptContextPtr = gCurrentScriptListPtr[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            kill_script(scriptContextPtr);
        }
    }
}

s32 kill_all_scripts(void) {
    s32 i;
    script_context* scriptContextPtr;

    for(i=0; i < MAX_SCRIPT_LIST_LENGTH; i++) {
        scriptContextPtr = gCurrentScriptListPtr[i];
        if (scriptContextPtr != NULL) {
            kill_script(scriptContextPtr);
        }
    }
    return;
}

s32 does_script_exist(s32 id) {
    s32 i;
    script_context* scriptContextPtr;

    for(i=0; i < MAX_SCRIPT_LIST_LENGTH; i++) {
        scriptContextPtr = gCurrentScriptListPtr[i];
        if (scriptContextPtr != NULL && scriptContextPtr->uniqueID == id) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM(code_e79b0_len_1920, does_script_exist_by_ref);

INCLUDE_ASM(code_e79b0_len_1920, set_script_priority);

INCLUDE_ASM(code_e79b0_len_1920, set_script_timescale);

INCLUDE_ASM(code_e79b0_len_1920, set_global_timespace);

INCLUDE_ASM(code_e79b0_len_1920, get_global_timespace);

INCLUDE_ASM(code_e79b0_len_1920, set_script_group);

INCLUDE_ASM(code_e79b0_len_1920, bind_trigger);

INCLUDE_ASM(code_e79b0_len_1920, bind_trigger_1);

INCLUDE_ASM(code_e79b0_len_1920, suspend_group_script);

INCLUDE_ASM(code_e79b0_len_1920, resume_group_script);

INCLUDE_ASM(code_e79b0_len_1920, suspend_all_script);

INCLUDE_ASM(code_e79b0_len_1920, resume_all_script);

INCLUDE_ASM(code_e79b0_len_1920, suspend_group_script_index);

INCLUDE_ASM(code_e79b0_len_1920, resume_group_script_index);

INCLUDE_ASM(code_e79b0_len_1920, suspend_all_group);

INCLUDE_ASM(code_e79b0_len_1920, resume_all_group);

INCLUDE_ASM(code_e79b0_len_1920, suspend_group_others);

INCLUDE_ASM(code_e79b0_len_1920, resume_group_others);

script_context* get_script_by_index(s32 index) {
    return gCurrentScriptListPtr[index];
}

script_context* get_script_by_id(s32 id) {
    s32 i;
    script_context* scriptContextPtr;

    for (i=0; i < MAX_SCRIPT_LIST_LENGTH; i++) {
        if (gCurrentScriptListPtr[i] != NULL) {
            scriptContextPtr = gCurrentScriptListPtr[i];
            if (scriptContextPtr->uniqueID == id) {
                return scriptContextPtr;
            }
        }
    }
    return 0;
}


INCLUDE_ASM(code_e79b0_len_1920, set_script_flags);

INCLUDE_ASM(code_e79b0_len_1920, clear_script_flags);
