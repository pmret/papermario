#include "common.h"

extern void(*D_8004AA85)(void);

void func_80200000(void) {
    u32 t0 = 0xAC29007B;
    u32 t1 = 0xB00006A8;
    void(*create_audio_subsystem)(void) = &D_8004AA85;

    while (IO_READ(PI_STATUS_REG) & 3);

    t0 -= IO_READ(t1 - 0x1C8);
    create_audio_subsystem += t0;
    create_audio_subsystem();
}
