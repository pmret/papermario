#include "common.h"

SHIFT_BSS s16 gTriggerCount;
SHIFT_BSS TriggerList wTriggerList;
SHIFT_BSS TriggerList bTriggerList;
SHIFT_BSS TriggerList* gCurrentTriggerListPtr;

void default_trigger_on_activate(Trigger* self) {
    self->flags |= TRIGGER_ACTIVATED;
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
    collisionStatus->pushingAgainstWall = NO_COLLIDER;
    collisionStatus->curFloor = NO_COLLIDER;
    collisionStatus->lastTouchedFloor = NO_COLLIDER;
    collisionStatus->curCeiling = NO_COLLIDER;
    collisionStatus->curInspect = NO_COLLIDER;
    collisionStatus->unk_0C = -1;
    collisionStatus->unk_0E = -1;
    collisionStatus->unk_10 = -1;
    collisionStatus->curWall = NO_COLLIDER;
    collisionStatus->lastWallHammered = NO_COLLIDER;
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

    trigger->flags = bp->flags | TRIGGER_ACTIVE;
    trigger->varIndex = bp->varIndex;
    trigger->location.colliderID = bp->colliderID;
    trigger->itemList = bp->itemList;
    trigger->tattleMsg = bp->tattleMsg;
    trigger->hasPlayerInteractPrompt = bp->hasPlayerInteractPrompt;

    trigger->onActivateFunc = bp->onActivateFunc;
    if (trigger->onActivateFunc == NULL) {
        trigger->onActivateFunc = (s32 (*) (Trigger*)) default_trigger_on_activate;
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

        if (!(listTrigger->flags & TRIGGER_ACTIVE)) {
            continue;
        }

        if (listTrigger->flags & TRIGGER_FORCE_ACTIVATE) {
            listTrigger->flags |= TRIGGER_ACTIVATED;
            continue;
        }

        if (listTrigger->flags & TRIGGER_WALL_PUSH) {
            if (listTrigger->location.colliderID == collisionStatus->curWall) {
                func_800E06C0(1);
            }
            if (listTrigger->location.colliderID == collisionStatus->pushingAgainstWall) {
                func_800E06C0(0);
            } else {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_FLOOR_TOUCH) {
            if (listTrigger->location.colliderID != collisionStatus->curFloor) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_FLOOR_ABOVE) {
            if (listTrigger->location.colliderID != collisionStatus->floorBelow) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_WALL_PRESS_A) {
            if (listTrigger->location.colliderID == collisionStatus->curWall) {
                collisionStatus->touchingWallTrigger = 1;
            }
            if ((listTrigger->location.colliderID != collisionStatus->curInspect) || !phys_can_player_interact()) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_WALL_TOUCH) {
            if (listTrigger->location.colliderID != collisionStatus->curWall) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_FLOOR_JUMP) {
            if (listTrigger->location.colliderID != collisionStatus->lastTouchedFloor) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_FLOOR_PRESS_A) {
            if ((listTrigger->location.colliderID != collisionStatus->curFloor) ||
                !(gGameStatusPtr->pressedButtons[0] & BUTTON_A) || (gPlayerStatus.flags & PS_FLAG_INPUT_DISABLED)) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_WALL_HAMMER) {
            if (listTrigger->location.colliderID != collisionStatus->lastWallHammered) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_CEILING_TOUCH) {
            if (listTrigger->location.colliderID != collisionStatus->curCeiling) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_FLAG_2000) {
            if (listTrigger->location.colliderID != collisionStatus->unk_0C) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_FLAG_4000) {
            if (listTrigger->location.colliderID != collisionStatus->unk_0E) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_FLAG_8000) {
            if (listTrigger->location.colliderID != collisionStatus->unk_10) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_POINT_BOMB) {
            Vec4f* triggerPos;
            f32 dist;

            if (collisionStatus->bombetteExploded < 0) {
                continue;
            }

            triggerPos = listTrigger->location.pos;
            dist = dist3D(triggerPos->x, triggerPos->y, triggerPos->z,
                                collisionStatus->bombetteExplosionPos.x, collisionStatus->bombetteExplosionPos.y,
                                collisionStatus->bombetteExplosionPos.z);

            if ((triggerPos->yaw * 0.5f) + 50.0f < dist) {
                continue;
            }
        }

        if (listTrigger->flags & TRIGGER_GAME_FLAG_SET && get_global_flag(listTrigger->varIndex) == 0) {
            continue;
        }

        if (listTrigger->flags & TRIGGER_AREA_FLAG_SET && get_area_flag(listTrigger->varIndex) == 0) {
            continue;
        }

        listTrigger->flags |= TRIGGER_ACTIVATED;
    }

    for (i = 0; i < ARRAY_COUNT(*gCurrentTriggerListPtr); i++) {
        listTrigger = (*gCurrentTriggerListPtr)[i];

        if (listTrigger == NULL) {
            continue;
        }

        if (listTrigger->flags & TRIGGER_ACTIVE) {
            if (listTrigger->flags & TRIGGER_ACTIVATED) {
                if (listTrigger->onActivateFunc(listTrigger) == 0) {
                    listTrigger->flags &= ~TRIGGER_ACTIVATED;
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

        if (listTrigger->flags & TRIGGER_ACTIVE) {
            if (listTrigger->flags & TRIGGER_ACTIVATED) {
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

        if (trigger != NULL
            && trigger->hasPlayerInteractPrompt != 0
            && trigger->location.colliderID == colliderID
            && trigger->flags & TRIGGER_WALL_PRESS_A
        ) {
            return TRUE;
        }
    }
    return FALSE;
}
