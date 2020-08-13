#include "common.h"


void default_trigger_function_handler(s32* arg0) {
    arg0[0] |= 2;
}

INCLUDE_ASM(code_dbd70_len_700, clear_trigger_data);

//INCLUDE_ASM(code_dbd70_len_700, init_trigger_list);
void init_trigger_list(void) {
    if ((*gGameStatusPtr)->unk_70 == 0) {
        *gCurrentTriggerListPtr = gTriggerList1;
    } else {
        *gCurrentTriggerListPtr = gTriggerList2;
    }

    gTriggerCount = 0;
}

INCLUDE_ASM(code_dbd70_len_700, create_trigger);

INCLUDE_ASM(code_dbd70_len_700, update_triggers);


void delete_trigger(trigger* toDelete) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCurrentTriggerListPtr); i++) {
        if ((*gCurrentTriggerListPtr)[i] == toDelete) {
            break;
        }
    }

    if (i < ARRAY_COUNT(gCurrentTriggerListPtr)) {
        heap_free((*gCurrentTriggerListPtr)[i]);
        (*gCurrentTriggerListPtr)[i] = NULL;
    }
}

INCLUDE_ASM(code_dbd70_len_700, is_trigger_bound);

//INCLUDE_ASM(code_dbd70_len_700, get_trigger_by_id);
trigger* get_trigger_by_id(s32 triggerID) {
    return (*gCurrentTriggerListPtr)[triggerID];
}

INCLUDE_ASM(code_dbd70_len_700, func_80145CE8);
