#include "common.h"

extern Addr map_vram_end;

#define HEAP_COLLISION_HEAD_SIZE 0x18000

BSS u8 WorldEntityHeapBase[0x10];
BSS HeapNode heap_collisionHead;
BSS u8 heap_collison[HEAP_COLLISION_HEAD_SIZE - sizeof(heap_collisionHead)];
