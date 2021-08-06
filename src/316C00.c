#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

#define JAL   0x03
#define ADDIU 0x09
#define LUI   0x0F
#define LW    0x23
#define LOWER(x) ((x) & 0xFFFF)
#define UPPER(x) ((x) >> 16)
#define OPCODE(x) ((x) >> 26)
#define GET_RS(x) ((x >> 0x15) & 0x1F)
#define GET_RT(x) (UPPER(x) & 0x1F)

extern s32 D_7012BC11[];

void func_802AE000_316C00(void) {
    s32(*readFunc)(OSPiHandle*, u32, u32*);
    UNK_FUN_PTR(generalHeapCreate);
    u32 thisInsn;
    u32* it;
    u32 prevInsn;
    s32 seed;
    u32 blah;
    u32 hash;

    readFunc = osEPiReadIo;
    seed = 0x4BF15BF6; // 0x3C016C07 + 0xFEFEFEF;
    generalHeapCreate = D_7012BC11; // 0x8002AC00 - 0xFEFEFEF (the former address being that of general_heap_create)
    hash = 0;

    readFunc(nuPiCartHandle, 0xB0000574, &thisInsn);
    seed -= thisInsn; // thisInsn = 0x3C016C07 here

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

    generalHeapCreate += seed + 0x2499BF - hash;

    // If the function's address is 0x8XXXXXXX
    if (((u32)generalHeapCreate >> 0x1C) == 8) {
        // Call the function that ends up being generalHeapCreate
        (generalHeapCreate)();
    }
}
