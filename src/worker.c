#include "common.h"

void worker_delegate_do_nothing(void) {
}

void clear_worker_list(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentWorkerListPtr = &gWorldWorkerList;
    } else {
        gCurrentWorkerListPtr = &gBattleWorkerList;
    }

    for (i = 0; i < MAX_WORKERS; i++) {
        (*gCurrentWorkerListPtr)[i] = NULL;
    }
}

void init_worker_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentWorkerListPtr = &gWorldWorkerList;
    } else {
        gCurrentWorkerListPtr = &gBattleWorkerList;
    }
}

s32 create_worker_world(void (*updateFunc)(void), void (*drawFunc)(void)) {
    Worker* worker;
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* lastWorker = (*gCurrentWorkerListPtr)[i];
        if (lastWorker == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_WORKERS);

    (*gCurrentWorkerListPtr)[i] = worker = heap_malloc(sizeof(*worker));
    ASSERT(worker != NULL);

    worker->flags = ENTITY_FLAGS_HIDDEN | ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE1;
    worker->update = updateFunc;
    if (updateFunc == NULL) {
        worker->update = worker_delegate_do_nothing;
    }
    worker->draw = drawFunc;
    if (drawFunc == NULL) {
        worker->draw = worker_delegate_do_nothing;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_MASK;
    }
    return i;
}

s32 create_worker_frontUI(void (*updateFunc)(void), void (*drawFunc)(void)) {
    Worker* worker;
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* lastWorker = (*gCurrentWorkerListPtr)[i];
        if (lastWorker == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_WORKERS);

    (*gCurrentWorkerListPtr)[i] = worker = heap_malloc(sizeof(*worker));
    ASSERT(worker != NULL);

    worker->flags = ENTITY_FLAGS_HIDDEN | ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE1 | ENTITY_FLAGS_HAS_DYNAMIC_SHADOW;
    worker->update = updateFunc;
    if (updateFunc == NULL) {
        worker->update = worker_delegate_do_nothing;
    }
    worker->draw = drawFunc;
    if (drawFunc == NULL) {
        worker->draw = worker_delegate_do_nothing;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_MASK;
    }
    return i;
}

s32 create_worker_backUI(void (*updateFunc)(void), void (*drawFunc)(void)) {
    Worker* worker;
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* lastWorker = (*gCurrentWorkerListPtr)[i];
        if (lastWorker == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_WORKERS);

    (*gCurrentWorkerListPtr)[i] = worker = heap_malloc(sizeof(*worker));
    ASSERT(worker != NULL);

    worker->flags = ENTITY_FLAGS_HIDDEN | ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE1 | ENTITY_FLAGS_HAS_ANIMATED_MODEL;
    worker->update = updateFunc;
    if (updateFunc == NULL) {
        worker->update = &worker_delegate_do_nothing;
    }
    worker->draw = drawFunc;
    if (drawFunc == NULL) {
        worker->draw = &worker_delegate_do_nothing;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_MASK;
    }
    return i;
}

void update_workers(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL) {
            worker->flags &= ~ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE1;
            worker->update();
        }
    }
}

void render_workers_world(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL && !(worker->flags & ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE1)) {
            if (!(worker->flags & ENTITY_FLAGS_HAS_DYNAMIC_SHADOW)) {
                worker->draw();
            }
        }
    }
}

void render_workers_frontUI(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL && !(worker->flags & ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE1)) {
            if (worker->flags & ENTITY_FLAGS_HAS_DYNAMIC_SHADOW) {
                worker->draw();
            }
        }
    }
}

void render_workers_backUI(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL && !(worker->flags & ENTITY_FLAGS_DRAW_IF_CLOSE_HIDE_MODE1)) {
            if (worker->flags & ENTITY_FLAGS_HAS_ANIMATED_MODEL) {
                worker->draw();
            }
        }
    }
}

void free_worker(s32 idx) {
    if (!gGameStatusPtr->isBattle || (idx & BATTLE_ENTITY_ID_MASK)) {
        idx &= ~BATTLE_ENTITY_ID_MASK;
        if ((*gCurrentWorkerListPtr)[idx] != NULL) {
            heap_free((*gCurrentWorkerListPtr)[idx]);
            (*gCurrentWorkerListPtr)[idx] = NULL;
        }
    }
}

Worker* get_worker(s32 idx) {
    return (*gCurrentWorkerListPtr)[idx & ~BATTLE_ENTITY_ID_MASK];
}
