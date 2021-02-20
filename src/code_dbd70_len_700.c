#include "common.h"

void default_trigger_delegate(s32* arg0) {
    arg0[0] |= 2;
}

INCLUDE_ASM(s32, "code_dbd70_len_700", clear_trigger_data);

void init_trigger_list(void) {
    if (!(*gGameStatusPtr)->isBattle) {
        gCurrentTriggerListPtr = &gTriggerList1;
    } else {
        gCurrentTriggerListPtr = &gTriggerList2;
    }

    gTriggerCount = 0;
}

INCLUDE_ASM(Trigger*, "code_dbd70_len_700", create_trigger, TriggerDefinition* def);

INCLUDE_ASM(s32, "code_dbd70_len_700", update_triggers);

void delete_trigger(Trigger* toDelete) {
    s32 i;
    TriggerList** currentTriggerListPtr = &gCurrentTriggerListPtr;

    for (i = 0; i < MAX_TRIGGERS; i++) {
        if ((**currentTriggerListPtr)[i] == toDelete) {
            break;
        }
    }

    if (i < MAX_TRIGGERS) {
        heap_free((**currentTriggerListPtr)[i]);
        (**currentTriggerListPtr)[i] = NULL;
    }
}

INCLUDE_ASM(s32, "code_dbd70_len_700", is_trigger_bound, Trigger* trigger, Bytecode* script);

Trigger* get_trigger_by_id(s32 triggerID) {
    return (*gCurrentTriggerListPtr)[triggerID];
}

/// @returns TRUE if colliderID is bound to an interaction trigger (press A) and the player can use it.
s32 should_collider_allow_interact(s32 colliderID) {
    s32 i;

    if (can_player_interact() == 0) {
        return 0;
    }

    for (i = 0; i < MAX_TRIGGERS; i++) {
        Trigger* trigger = (*gCurrentTriggerListPtr)[i];

        if ((trigger != NULL) &&
            (trigger->unk_30 != 0) &&
            (trigger->params2 == colliderID) &&
            (trigger->flags.flags & 0x100)) {
            return 1;
        }
    }
    return 0;
}
