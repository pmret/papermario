#include "common.h"

void default_trigger_delegate(Trigger* self) {
    self->flags.flags |= 2;
}

void clear_trigger_data(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentTriggerListPtr = &wTriggerList;
    } else {
        gCurrentTriggerListPtr = &bTriggerList;
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
    collisionStatus->bombetteExplosionPos.x = 0.0f;
    collisionStatus->bombetteExplosionPos.y = 0.0f;
    collisionStatus->bombetteExplosionPos.z = 0.0f;
}

void init_trigger_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentTriggerListPtr = &wTriggerList;
    } else {
        gCurrentTriggerListPtr = &bTriggerList;
    }

    gTriggerCount = 0;
}

Trigger* create_trigger(TriggerDefinition* def) {
    Trigger* ret;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        Trigger* listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(*gCurrentTriggerListPtr));

    (*gCurrentTriggerListPtr)[i] = ret = heap_malloc(sizeof(*ret));
    gTriggerCount++;

    ASSERT(ret != NULL);

    ret->flags.flags = def->flags | TRIGGER_DEFINITION_FLAGS_1;
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

void update_triggers(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Trigger* listTrigger;
    s32 i;

    collisionStatus->touchingWallTrigger = 0;

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL) {
            continue;
        }

        if (!(listTrigger->flags.flags & 1)) {
            continue;
        }

        if (listTrigger->flags.flags & 0x10) {
            listTrigger->flags.flags |= 2;
            continue;
        }

        if (listTrigger->flags.flags & 0x40) {
            if (listTrigger->params2 == collisionStatus->currentWall) {
                func_800E06C0(1);
            }
            if (listTrigger->params2 == collisionStatus->pushingAgainstWall) {
                func_800E06C0(0);
            } else {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x80) {
            if (listTrigger->params2 != collisionStatus->currentFloor) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x80000) {
            if (listTrigger->params2 != collisionStatus->floorBelow) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x100) {
            if (listTrigger->params2 == collisionStatus->currentWall) {
                collisionStatus->touchingWallTrigger = 1;
            }
            if ((listTrigger->params2 != collisionStatus->unk_0A) || !phys_can_player_interact()) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x400) {
            if (listTrigger->params2 != collisionStatus->currentWall) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x200) {
            if (listTrigger->params2 != collisionStatus->lastTouchedFloor) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x800) {
            if ((listTrigger->params2 != collisionStatus->currentFloor) ||
                !(gGameStatusPtr->pressedButtons & 0x8000) || (gPlayerStatus.flags & 0x2000)) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x1000) {
            if (listTrigger->params2 != collisionStatus->lastWallHammered) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x40000) {
            if (listTrigger->params2 != collisionStatus->currentCeiling) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x2000) {
            if (listTrigger->params2 != collisionStatus->unk_0C) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x4000) {
            if (listTrigger->params2 != collisionStatus->unk_0E) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x8000) {
            if (listTrigger->params2 != collisionStatus->unk_10) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x100000) {
            f32* floats;
            f32 dist;

            if (collisionStatus->bombetteExploded < 0) {
                continue;
            }

            floats = (f32*)listTrigger->params2;
            dist = dist3D(floats[0], floats[1], floats[2],
                                collisionStatus->bombetteExplosionPos.x, collisionStatus->bombetteExplosionPos.y,
                                collisionStatus->bombetteExplosionPos.z);

            if ((floats[3] * 0.5f) + 50.0f < dist) {
                continue;
            }
        }

        if (listTrigger->flags.flags & 0x10000 && get_global_flag(listTrigger->params1) == 0) {
            continue;
        }

        if (listTrigger->flags.flags & 0x20000 && get_area_flag(listTrigger->params1) == 0) {
            continue;
        }

        listTrigger->flags.flags |= 2;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL) {
            continue;
        }

        if (listTrigger->flags.flags & 1) {
            if (listTrigger->flags.flags & 2) {
                if (listTrigger->functionHandler(listTrigger) == 0) {
                    listTrigger->flags.flags &= ~2;
                }
            }
        }
    }
}

void delete_trigger(Trigger* toDelete) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        if ((*gCurrentTriggerListPtr)[i] == toDelete) {
            break;
        }
    }

    if (i < ARRAY_COUNT(*gCurrentTriggerListPtr)) {
        heap_free((*gCurrentTriggerListPtr)[i]);
        (*gCurrentTriggerListPtr)[i] = NULL;
    }
}

s32 is_trigger_bound(Trigger* trigger, EvtSource* script) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
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

    if (!phys_can_player_interact()) {
        return FALSE;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        Trigger* trigger = (*gCurrentTriggerListPtr)[i];

        if (trigger != NULL &&
            trigger->unk_30 != 0 &&
            trigger->params2 == colliderID &&
            trigger->flags.flags & 0x100) {
            return TRUE;
        }
    }
    return FALSE;
}
