#include "common.h"

#ifdef SHIFT
BSS u8 WorldEntityHeapBottom[WORLD_ENTITY_HEAP_SIZE];
#endif
BSS u8 WorldEntityHeapBase[0x10];
BSS u8 heap_collisionHead[COLLISION_HEAP_SIZE];
