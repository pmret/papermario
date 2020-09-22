#include "common.h"

void default_trigger_function_handler(s32* arg0) {
    arg0[0] |= 2;
}

INCLUDE_ASM("code_dbd70_len_700", clear_trigger_data);

void init_trigger_list(void) {
    if ((*gGameStatusPtr)->isBattle == 0) {
        *gCurrentTriggerListPtr = gTriggerList1;
    } else {
        *gCurrentTriggerListPtr = gTriggerList2;
    }

    gTriggerCount = 0;
}

INCLUDE_ASM_T(Trigger*, "code_dbd70_len_700", create_trigger, TriggerDefinition* def);

INCLUDE_ASM("code_dbd70_len_700", update_triggers);

void delete_trigger(Trigger* toDelete) {
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

INCLUDE_ASM("code_dbd70_len_700", is_trigger_bound);

Trigger* get_trigger_by_id(s32 triggerID) {
    return (*gCurrentTriggerListPtr)[triggerID];
}

#ifdef NON_MATCHING
s32 func_80145CE8(s32 arg0) {
    s32 i;
    s32 ret;

    if (func_800E52F8() == 0) {
        return 0;
    }

    for (i = 0; i < ARRAY_COUNT(gCurrentTriggerListPtr); i++) {
        if (((*gCurrentTriggerListPtr)[i] == NULL) ||
            ((*gCurrentTriggerListPtr)[i]->unk_30 == 0) ||
            ((*gCurrentTriggerListPtr)[i]->colliderID != arg0) ||
            ((*gCurrentTriggerListPtr)[i]->genericFlagIndex & 0x100) == 0) {
            ret = 1;
        }
    }

    return ret;
}
#else
INCLUDE_ASM("code_dbd70_len_700", func_80145CE8);
#endif
