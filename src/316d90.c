#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "mips.h"

extern s32 D_7012ACA1[];

void func_802AE000(void) {
    s32(*readFunc)(OSPiHandle*, u32, u32*);
    UNK_FUN_PTR(aFunction);
    u32 thisInsn;
    u32* it;
    u32 prevInsn;
    s32 seed;
    u32 blah;
    u32 hash;

    readFunc = osEPiReadIo;
    seed = 0x33F50000;
    aFunction = D_7012ACA1;
    hash = 0;

    readFunc(nuPiCartHandle, 0xB0000800, &thisInsn);
    seed -= thisInsn;

    prevInsn = 0;

    for (it = _316C00_ROM_START; it < _316C00_ROM_END; it++) {
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

    aFunction += seed + 0x291993 - hash;

    // If the function's address is 0x8XXXXXXX
    if (((u32)aFunction >> 0x1C) == 8) {
        (aFunction)();
    } else {
        _heap_create(&D_803DA800, 0x10000);
    }
}
