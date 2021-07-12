#include "common.h"

void default_trigger_delegate(s32* arg0) {
    arg0[0] |= 2;
}

void clear_trigger_data(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentTriggerListPtr = &gTriggerList1;
    } else {
        gCurrentTriggerListPtr = &gTriggerList2;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        (*gCurrentTriggerListPtr)[i] = NULL;
    }

    gTriggerCount = 0;
    collisionStatus->pushingAgainstWall = -1;
    collisionStatus->currentFloor = -1;
    collisionStatus->lastTouchedFloor = -1;
    collisionStatus->currentCeiling = -1;
    collisionStatus->unk_0A = -1;
    collisionStatus->unk_0C = -1;
    collisionStatus->unk_0E = -1;
    collisionStatus->unk_10 = -1;
    collisionStatus->currentWall = -1;
    collisionStatus->lastWallHammered = -1;
    collisionStatus->touchingWallTrigger = 0;
    collisionStatus->bombetteExploded = -1;
    collisionStatus->bombetteExplositionPos[0] = 0.0f;
    collisionStatus->bombetteExplositionPos[1] = 0.0f;
    collisionStatus->bombetteExplositionPos[2] = 0.0f;
}

void init_trigger_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentTriggerListPtr = &gTriggerList1;
    } else {
        gCurrentTriggerListPtr = &gTriggerList2;
    }

    gTriggerCount = 0;
}

INCLUDE_ASM(Trigger*, "dbd70_len_700", create_trigger, TriggerDefinition* def);

INCLUDE_ASM(s32, "dbd70_len_700", update_triggers);

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

INCLUDE_ASM(s32, "dbd70_len_700", is_trigger_bound, Trigger* trigger, Bytecode* script);

Trigger* get_trigger_by_id(s32 triggerID) {
    return (*gCurrentTriggerListPtr)[triggerID];
}

/// @returns TRUE if colliderID is bound to an interaction trigger (press A) and the player can use it.
s32 should_collider_allow_interact(s32 colliderID) {
    s32 i;

    if (phys_can_player_interact() == 0) {
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
