#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "mips.h"

extern s32 D_7012ACA1[];

void func_802AE000(void) {
    s32(*readFunc)(OSPiHandle*, u32, u32*) = osEPiReadIo;
    s32 seed = 0x33F50000;
    UNK_FUN_PTR(battle_heap_create) = D_7012ACA1;
    u32 hash = 0;
    u32 thisInsn;
    u32* it;
    u32 prevInsn;

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

    battle_heap_create += seed + 0x291993 - hash;

    // If the function's address is 0x8XXXXXXX
    if (((u32)battle_heap_create >> 0x1C) == 8) {
        (battle_heap_create)();
    } else {
        _heap_create(&D_803DA800, 0x10000);
    }
}
