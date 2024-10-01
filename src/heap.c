#include "common.h"

extern HeapNode heap_generalHead;
extern HeapNode heap_collisionHead;

HeapNode* general_heap_create(void) {
    return _heap_create(&heap_generalHead, GENERAL_HEAP_SIZE);
}

void* general_heap_malloc(s32 size) {
    return _heap_malloc(&heap_generalHead, size);
}

void* general_heap_malloc_tail(s32 size) {
    return _heap_malloc_tail(&heap_generalHead, size);
}

s32 general_heap_free(void* data) {
    return _heap_free(&heap_generalHead, data);
}

s32 battle_heap_create(void) {
    if ((s32)_heap_create(&heap_battleHead, BATTLE_HEAP_SIZE) == -1) {
        return -1;
    } else {
        return 0;
    }
}

s32 func_8002ACDC(void) {
    return 0;
}

void* heap_malloc(s32 size) {
    if (gGameStatusPtr->context == CONTEXT_WORLD) {
        return general_heap_malloc(size);
    } else {
        return _heap_malloc(&heap_battleHead, size);
    }
}

s32 heap_free(void* data) {
    if (gGameStatusPtr->context != CONTEXT_WORLD) {
        return _heap_free(&heap_battleHead, data);
    } else {
        return general_heap_free(data);
    }
}

s32 collision_heap_create(void) {
    if ((s32)_heap_create(&heap_collisionHead, COLLISION_HEAP_SIZE) == -1) {
        return -1;
    }
    return 0;
}

void* collision_heap_malloc(s32 size) {
    if (gGameStatusPtr->context == CONTEXT_WORLD) {
        return _heap_malloc(&heap_collisionHead, size);
    } else {
        return _heap_malloc(&heap_battleHead, size);
    }
}

s32 collision_heap_free(void* data) {
    if (gGameStatusPtr->context != CONTEXT_WORLD) {
        return _heap_free(&heap_battleHead, data);
    } else {
        return _heap_free(&heap_collisionHead, data);
    }
}
