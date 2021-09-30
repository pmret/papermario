#include "common.h"

extern s32 D_80268000;
extern s32 D_802FB800;

HeapNode* general_heap_create(void) {
    return _heap_create(&D_802FB800, 0x54000);
}

void* general_heap_malloc(s32 size) {
    return _heap_malloc(&D_802FB800, size);
}

s32 general_heap_malloc_tail(s32 size) {
    return _heap_malloc_tail(&D_802FB800, size);
}

s32 general_heap_free(s32* size) {
    return _heap_free(&D_802FB800, size);
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
    if (gGameStatusPtr->isBattle == 0) {
        return general_heap_malloc(size);
    } else {
        return _heap_malloc(&D_803DA800, size);
    }
}

s32 heap_free(void* ptr) {
    if (gGameStatusPtr->isBattle != 0) {
        return _heap_free(&D_803DA800, ptr);
    } else {
        return general_heap_free(ptr);
    }
}

s32 collision_heap_create(void) {
    if ((s32)_heap_create(&D_80268000, 0x18000) == -1) {
        return -1;
    }
    return 0;
}

void* collision_heap_malloc(s32 size) {
    if (!gGameStatusPtr->isBattle) {
        return _heap_malloc(&D_80268000, size);
    } else {
        return _heap_malloc(&D_803DA800, size);
    }
}

s32 collision_heap_free(void* data) {
    if (gGameStatusPtr->isBattle) {
        return _heap_free(&D_803DA800, data);
    } else {
        return _heap_free(&D_80268000, data);
    }
}
