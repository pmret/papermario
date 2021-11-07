#include "common.h"

extern HeapNode* heapCollisionHead; //D_80268000;
extern HeapNode* heapGeneralHead; //D_802FB800;

HeapNode* general_heap_create(void) {
    return _heap_create(&heapGeneralHead, 0x54000);
}

void* general_heap_malloc(s32 size) {
    return _heap_malloc(&heapGeneralHead, size);
}

s32 general_heap_malloc_tail(s32 size) {
    return _heap_malloc_tail(&heapGeneralHead, size);
}

s32 general_heap_free(s32* data) {
    return _heap_free(&heapGeneralHead, data);
}

s32 battle_heap_create(void) {
    if ((s32)_heap_create(&D_803DA800, 0x25800) == -1) {
        return -1;
    } else {
        return 0;
    }
}

s32 func_8002ACDC(void) {
    return 0;
}

void* heap_malloc(s32 size) {
    if (!gGameStatusPtr->isBattle) {
        return general_heap_malloc(size);
    } else {
        return _heap_malloc(&D_803DA800, size);
    }
}

s32 heap_free(void* data) {
    if (gGameStatusPtr->isBattle) {
        return _heap_free(&D_803DA800, data);
    } else {
        return general_heap_free(data);
    }
}

s32 collision_heap_create(void) {
    if ((s32)_heap_create(&heapCollisionHead, 0x18000) == -1) {
        return -1;
    }
    return 0;
}

void* collision_heap_malloc(s32 size) {
    if (!gGameStatusPtr->isBattle) {
        return _heap_malloc(&heapCollisionHead, size);
    } else {
        return _heap_malloc(&D_803DA800, size);
    }
}

s32 collision_heap_free(void* data) {
    if (gGameStatusPtr->isBattle) {
        return _heap_free(&D_803DA800, data);
    } else {
        return _heap_free(&heapCollisionHead, data);
    }
}
