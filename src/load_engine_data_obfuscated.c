#include "common.h"
#include "ld_addrs.h"
#include "mips.h"

extern u8 obfuscated_load_engine_data[];

#ifdef SHIFT
void load_engine_data(void);
void load_engine_data_obfuscated(void) {
    load_engine_data();
}
#else
void load_engine_data_obfuscated(void) {
    s32 seed = 0x3C01A775;
    u32 thisInsn = 0xB0018FFC;
    HeapNode*(*load_engine_data)(void) = (HeapNode* (*)(void)) obfuscated_load_engine_data; // load_engine_data - ????????
    s32 hash = 0;
    u32 prevInsn;
    u32* it;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY));
    seed -= IO_READ(thisInsn + 0xFFFE7508);

    prevInsn = 0;

    for (it = (u32*) create_audio_system_obfuscated_ROM_START; it < (u32*) create_audio_system_obfuscated_ROM_END; it++) {
        while (IO_READ(PI_STATUS_REG) & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY));
        thisInsn = IO_READ(it + 0x4000000); // ???

        hash += LOWER(thisInsn) + UPPER(thisInsn);

        if (OPCODE(prevInsn) == LUI &&
            OPCODE(thisInsn) == ADDIU &&
            GET_RS(thisInsn) == GET_RT(prevInsn) &&
            GET_RS(thisInsn) == GET_RT(thisInsn))
        {
            hash -= LOWER(thisInsn);
            hash -= LOWER(prevInsn);
        }

        if (OPCODE(thisInsn) == JAL) {
            hash -= LOWER(thisInsn) + (UPPER(thisInsn) & 0xFC00);
        }

        prevInsn = thisInsn;
    }

    load_engine_data += seed + 0xDDD20 - hash;
    load_engine_data();
}
#endif
