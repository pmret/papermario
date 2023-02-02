#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "mips.h"

extern s32 obfuscated_battle_heap_create[];

#ifdef SHIFT
void battle_heap_create_obfuscated(void) {
    battle_heap_create();
}
#else
void battle_heap_create_obfuscated(void) {
    s32(*readFunc)(OSPiHandle*, u32, u32*) = osEPiReadIo;
    s32 seed = 0x33F50000;
    s32 (*battle_heap_create)(void) = (s32 (*) (void)) obfuscated_battle_heap_create;
    u32 hash = 0;
    u32 thisInsn;
    u32* it;
    u32 prevInsn;

    readFunc(nuPiCartHandle, 0xB0000800, &thisInsn);
    seed -= thisInsn;

    prevInsn = 0;

    for (it = (u32*) general_heap_create_obfuscated_ROM_START; it < (u32*) general_heap_create_obfuscated_ROM_END; it++) {
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

    battle_heap_create += seed + 0x291993 - hash;

    // If the function's address is 0x8XXXXXXX
    if (((u32)battle_heap_create >> 0x1C) == 8) {
        battle_heap_create();
    } else {
        _heap_create(&heap_battleHead, 0x10000);
    }
}
#endif
