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

Trigger* create_trigger(TriggerDefinition* def) {
    Trigger* ret;
    s32 i;

    for (i = 0; i < MAX_TRIGGERS; i++) {
        Trigger* listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL) {
            break;
        }
    }

    ASSERT(i < MAX_TRIGGERS);

    (*gCurrentTriggerListPtr)[i] = ret = heap_malloc(sizeof(*ret));
    gTriggerCount++;

    ASSERT(ret != NULL);

    ret->flags.flags = def->flags | 1;
    ret->params1 = def->colliderIndex;
    ret->params2 = def->flagIndex;
    ret->unk_28 = def->unk_1C;
    ret->unk_2C = def->unk_14;
    ret->unk_30 = def->inputArg3;

    ret->functionHandler = def->function;
    if (ret->functionHandler == NULL) {
        ret->functionHandler = default_trigger_delegate;
    }

    return ret;
}

INCLUDE_ASM(s32, "dbd70_len_700", update_triggers);

void delete_trigger(Trigger* toDelete) {
    s32 i;

    for (i = 0; i < MAX_TRIGGERS; i++) {
        if ((*gCurrentTriggerListPtr)[i] == toDelete) {
            break;
        }
    }

    if (i < MAX_TRIGGERS) {
        heap_free((*gCurrentTriggerListPtr)[i]);
        (*gCurrentTriggerListPtr)[i] = NULL;
    }
}

s32 is_trigger_bound(Trigger* trigger, EvtSource* script) {
    s32 i;

    for (i = 0; i < MAX_TRIGGERS; i++) {
        Trigger* listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL || listTrigger == trigger) {
            continue;
        }

        if (listTrigger->flags.flags & 1) {
            if (listTrigger->flags.flags & 2) {
                if (listTrigger->scriptSource == script) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

Trigger* get_trigger_by_id(s32 triggerID) {
    return (*gCurrentTriggerListPtr)[triggerID];
}

/// @returns TRUE if colliderID is bound to an interaction trigger (press A) and the player can use it.
s32 should_collider_allow_interact(s32 colliderID) {
    s32 i;

    if (phys_can_player_interact() == 0) {
        return FALSE;
    }

    for (i = 0; i < MAX_TRIGGERS; i++) {
        Trigger* trigger = (*gCurrentTriggerListPtr)[i];

        if ((trigger != NULL) &&
            (trigger->unk_30 != 0) &&
            (trigger->params2 == colliderID) &&
            (trigger->flags.flags & 0x100)) {
            return TRUE;
        }
    }
    return FALSE;
}
