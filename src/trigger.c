#include "common.h"

void default_trigger_on_activate(Trigger* self) {
    self->flags.flags |= TRIGGER_ACTIVATED;
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

Trigger* create_trigger(TriggerBlueprint* bp) {
    Trigger* trigger;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        Trigger* listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(*gCurrentTriggerListPtr));

    (*gCurrentTriggerListPtr)[i] = trigger = heap_malloc(sizeof(*trigger));
    gTriggerCount++;

    ASSERT(trigger != NULL);

    trigger->flags.flags = bp->flags | TRIGGER_ACTIVE;
    trigger->params1 = bp->colliderIndex;
    trigger->params2 = bp->flagIndex;
    trigger->itemList = bp->itemList;
    trigger->unk_tr_2C = bp->unk_tr_2C;
    trigger->hasPlayerInteractPrompt = bp->hasPlayerInteractPrompt;

    trigger->onActivateFunc = bp->onActivateFunc;
    if (trigger->onActivateFunc == NULL) {
        trigger->onActivateFunc = default_trigger_on_activate;
    }

    return trigger;
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

        if (!(listTrigger->flags.flags & TRIGGER_ACTIVE)) {
            continue;
        }

        if (listTrigger->flags.flags & TRIGGER_FORCE_ACTIVATE) {
            listTrigger->flags.flags |= TRIGGER_ACTIVATED;
            continue;
        }

        if (listTrigger->flags.flags & TRIGGER_WALL_PUSH) {
            if (listTrigger->params2 == collisionStatus->currentWall) {
                func_800E06C0(1);
            }
            if (listTrigger->params2 == collisionStatus->pushingAgainstWall) {
                func_800E06C0(0);
            } else {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_FLOOR_TOUCH) {
            if (listTrigger->params2 != collisionStatus->currentFloor) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_FLOOR_ABOVE) {
            if (listTrigger->params2 != collisionStatus->floorBelow) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_WALL_PRESS_A) {
            if (listTrigger->params2 == collisionStatus->currentWall) {
                collisionStatus->touchingWallTrigger = 1;
            }
            if ((listTrigger->params2 != collisionStatus->unk_0A) || !phys_can_player_interact()) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_WALL_TOUCH) {
            if (listTrigger->params2 != collisionStatus->currentWall) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_FLOOR_JUMP) {
            if (listTrigger->params2 != collisionStatus->lastTouchedFloor) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_FLOOR_PRESS_A) {
            if ((listTrigger->params2 != collisionStatus->currentFloor) ||
                !(gGameStatusPtr->pressedButtons & BUTTON_A) || (gPlayerStatus.flags & PLAYER_STATUS_FLAGS_INPUT_DISABLED)) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_WALL_HAMMER) {
            if (listTrigger->params2 != collisionStatus->lastWallHammered) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_CEILING_TOUCH) {
            if (listTrigger->params2 != collisionStatus->currentCeiling) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_FLAGS_2000) {
            if (listTrigger->params2 != collisionStatus->unk_0C) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_FLAGS_4000) {
            if (listTrigger->params2 != collisionStatus->unk_0E) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_FLAGS_8000) {
            if (listTrigger->params2 != collisionStatus->unk_10) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_POINT_BOMB) {
            f32* triggerPos;
            f32 dist;

            if (collisionStatus->bombetteExploded < 0) {
                continue;
            }

            triggerPos = (f32*)listTrigger->params2;
            dist = dist3D(triggerPos[0], triggerPos[1], triggerPos[2],
                                collisionStatus->bombetteExplosionPos.x, collisionStatus->bombetteExplosionPos.y,
                                collisionStatus->bombetteExplosionPos.z);

            if ((triggerPos[3] * 0.5f) + 50.0f < dist) {
                continue;
            }
        }

        if (listTrigger->flags.flags & TRIGGER_GAME_FLAG_SET && get_global_flag(listTrigger->params1) == 0) {
            continue;
        }

        if (listTrigger->flags.flags & TRIGGER_AREA_FLAG_SET && get_area_flag(listTrigger->params1) == 0) {
            continue;
        }

        listTrigger->flags.flags |= TRIGGER_ACTIVATED;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL) {
            continue;
        }

        if (listTrigger->flags.flags & TRIGGER_ACTIVE) {
            if (listTrigger->flags.flags & TRIGGER_ACTIVATED) {
                if (listTrigger->onActivateFunc(listTrigger) == 0) {
                    listTrigger->flags.flags &= ~TRIGGER_ACTIVATED;
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

s32 is_another_trigger_bound(Trigger* trigger, EvtScript* script) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        Trigger* listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL || listTrigger == trigger) {
            continue;
        }

        if (listTrigger->flags.flags & TRIGGER_ACTIVE) {
            if (listTrigger->flags.flags & TRIGGER_ACTIVATED) {
                if (listTrigger->onTriggerEvt == script) {
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
            trigger->hasPlayerInteractPrompt != 0 &&
            trigger->params2 == colliderID &&
            trigger->flags.flags & TRIGGER_WALL_PRESS_A) {
            return TRUE;
        }
    }
    return FALSE;
}
