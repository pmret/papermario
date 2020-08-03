#include "common.h"

extern s32 D_80268000;
extern s32 D_802FB800;
extern s32 D_803DA800;

//s32 _heap_free(s32 addr, s32 size);

s32 general_heap_create(void) {
    return _heap_create(&D_802FB800, 0x54000);
}

s32 general_heap_malloc(s32 size) {
    return _heap_malloc(&D_802FB800, size);
}

s32 general_heap_malloc_tail(s32 size) {
    return _heap_malloc_tail(&D_802FB800, size);
}

s32 general_heap_free(s32 size) {
    return _heap_free(&D_802FB800, size);
}

INCLUDE_ASM(code_6000, battle_heap_create);
/*s32 battle_heap_create(void) {
    if (_heap_create(&D_803DA800, 0x25800) != -1) {
        return -1;
    } else {
        return 0;
    }
}*/

s32 func_8002ACDC(void) {
    return 0;
}

s32 heap_malloc(s32 size) {
    if ((*gGameStatusPtr)->unk_70 == 0) {
        return general_heap_malloc(size);
    } else {
        return _heap_malloc(&D_803DA800, size);
    }
}

s32 heap_free(s32 size) {
    if ((*gGameStatusPtr)->unk_70 != 0) {
        return _heap_free(&D_803DA800, size);
    } else {
        return general_heap_free(size);
    }
}

INCLUDE_ASM(code_6000, collision_heap_create);

INCLUDE_ASM(code_6000, collision_heap_malloc);

INCLUDE_ASM(code_6000, collision_heap_free);
/*s32 collision_heap_free(s32 size) {
    s32 unk_70 = (*gGameStatusPtr)->unk_70;
    
    return _heap_free((unk_70 == 0) ? (&D_80268000) : (&D_803DA800), size);
}*/