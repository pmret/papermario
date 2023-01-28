#include "common.h"

extern u8 obfuscated_create_audio_system[];

#ifdef SHIFT
void func_80200000(void) {
    create_audio_system();
}
#else
void func_80200000(void) {
    u32 t0 = 0xAC29007B;
    u32 t1 = 0xB00006A8;
    void (*create_audio_system)(void) = (void (*)(void)) obfuscated_create_audio_system;

    while (IO_READ(PI_STATUS_REG) & 3);

    t0 -= IO_READ(t1 - 0x1C8);
    create_audio_system += t0;
    create_audio_system();
}
#endif
