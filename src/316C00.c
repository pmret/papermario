#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "mips.h"

extern s32 D_7012BC11[];

void func_802AE000_316C00(void) {
    s32(*readFunc)(OSPiHandle*, u32, u32*) = osEPiReadIo;
    s32 seed = 0x3C016C07 + 0xFEFEFEF;
    HeapNode*(*generalHeapCreate)(void) = D_7012BC11; // general_heap_create - 0xFEFEFEF
    u32 hash = 0;
    u32 thisInsn;
    u32* it;
    u32 prevInsn;

    readFunc(nuPiCartHandle, 0xB0000574, &thisInsn);
    seed -= thisInsn; // thisInsn = 0x3C016C07 here, so seed becomes 0xFEFEFEF

    prevInsn = 0;

    for (it = _316A70_ROM_START; it < _316A70_ROM_END; it++) {
        readFunc(nuPiCartHandle, it, &thisInsn);
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
    generalHeapCreate += seed + 0x2499BF - hash;

    // If the function's address is 0x8XXXXXXX
    if (((u32)generalHeapCreate >> 0x1C) == 8) {
        // Call the function that ends up being general_heap_create
        (generalHeapCreate)();
    }
}
