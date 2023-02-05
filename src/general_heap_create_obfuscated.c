#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "mips.h"

extern u8 obfuscated_general_heap_create[];

#ifdef SHIFT
void general_heap_create_obfuscated(void) {
    general_heap_create();
}
#else
void general_heap_create_obfuscated(void) {
    s32(*readFunc)(OSPiHandle*, u32, u32*) = osEPiReadIo;
    s32 seed = 0x3C016C07 + 0xFEFEFEF;
    HeapNode*(*general_heap_create)(void) = (HeapNode* (*)(void)) obfuscated_general_heap_create; // general_heap_create - 0xFEFEFEF
    u32 hash = 0;
    u32 thisInsn;
    u32* it;
    u32 prevInsn;

    readFunc(nuPiCartHandle, 0xB0000574, &thisInsn);
    seed -= thisInsn; // thisInsn = 0x3C016C07 here, so seed becomes 0xFEFEFEF

    prevInsn = 0;

    for (it = (u32*) load_engine_data_obfuscated_ROM_START; it < (u32*) load_engine_data_obfuscated_ROM_END; it++) {
        readFunc(nuPiCartHandle, (u32) it, &thisInsn);
        hash += LOWER(thisInsn) + UPPER(thisInsn);

        if (OPCODE(prevInsn) == LUI && (OPCODE(thisInsn) == ADDIU || OPCODE(thisInsn) == LW)) {
            if (GET_RS(thisInsn) == GET_RT(prevInsn) && GET_RS(thisInsn) == GET_RT(thisInsn)) {
                hash -= LOWER(thisInsn);
                hash -= LOWER(prevInsn);
            }
        }

        if (OPCODE(thisInsn) == JAL) {
            hash -= LOWER(thisInsn) + (UPPER(thisInsn) & 0xFC00);
        }

        prevInsn = thisInsn;
    }

    // 0x2499BF - hash == 0, so we add back 0xFEFEFEF (seed) and we end up with the address of general_heap_create!
    general_heap_create += seed + 0x2499BF - hash;

    // If the function's address is 0x8XXXXXXX
    if (((u32)general_heap_create >> 0x1C) == 8) {
        // Call the function that ends up being general_heap_create
        general_heap_create();
    }
}
#endif
