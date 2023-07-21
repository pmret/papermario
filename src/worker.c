#include "common.h"

SHIFT_BSS WorkerList gWorldWorkerList;
SHIFT_BSS WorkerList gBattleWorkerList;
SHIFT_BSS WorkerList* gCurrentWorkerListPtr;

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

    worker->flags = WORKER_FLAG_1 | WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE;
    worker->update = updateFunc;
    if (updateFunc == NULL) {
        worker->update = worker_delegate_do_nothing;
    }
    worker->draw = drawFunc;
    if (drawFunc == NULL) {
        worker->draw = worker_delegate_do_nothing;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_BIT;
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

    worker->flags = WORKER_FLAG_1 | WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE | WORKER_FLAG_FRONT_UI;
    worker->update = updateFunc;
    if (updateFunc == NULL) {
        worker->update = worker_delegate_do_nothing;
    }
    worker->draw = drawFunc;
    if (drawFunc == NULL) {
        worker->draw = worker_delegate_do_nothing;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_BIT;
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

    worker->flags = WORKER_FLAG_1 | WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE | WORKER_FLAG_BACK_UI;
    worker->update = updateFunc;
    if (updateFunc == NULL) {
        worker->update = &worker_delegate_do_nothing;
    }
    worker->draw = drawFunc;
    if (drawFunc == NULL) {
        worker->draw = &worker_delegate_do_nothing;
    }

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_ENTITY_ID_BIT;
    }
    return i;
}

void update_workers(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL) {
            worker->flags &= ~WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE;
            worker->update();
        }
    }
}

void render_workers_world(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL && !(worker->flags & WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE)) {
            if (!(worker->flags & WORKER_FLAG_FRONT_UI)) {
                worker->draw();
            }
        }
    }
}

void render_workers_frontUI(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL && !(worker->flags & WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE)) {
            if (worker->flags & WORKER_FLAG_FRONT_UI) {
                worker->draw();
            }
        }
    }
}

void render_workers_backUI(void) {
    s32 i;

    for (i = 0; i < MAX_WORKERS; i++) {
        Worker* worker = (*gCurrentWorkerListPtr)[i];
        if (worker != NULL && !(worker->flags & WORKER_FLAG_SKIP_DRAW_UNTIL_UPDATE)) {
            if (worker->flags & WORKER_FLAG_BACK_UI) {
                worker->draw();
            }
        }
    }
}

void free_worker(s32 idx) {
    if (!gGameStatusPtr->isBattle || (idx & BATTLE_ENTITY_ID_BIT)) {
        idx &= ~BATTLE_ENTITY_ID_BIT;
        if ((*gCurrentWorkerListPtr)[idx] != NULL) {
            heap_free((*gCurrentWorkerListPtr)[idx]);
            (*gCurrentWorkerListPtr)[idx] = NULL;
        }
    }
}

Worker* get_worker(s32 idx) {
    return (*gCurrentWorkerListPtr)[idx & ~BATTLE_ENTITY_ID_BIT];
}
