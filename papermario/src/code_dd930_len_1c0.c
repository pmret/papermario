#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} struct_80147230;

extern struct_80147230 D_8014F140;
extern struct_80147230 D_8015C7C0;

void func_80147230(void) {
    D_8015C7C0 = D_8014F140;
}

void __attribute__((naked)) UpdateMusicPlayers(void) {
    __asm__(
    ".include \"asm/code_dd930_len_1c0/UpdateMusicPlayers.s\"\n"
    );
}

void __attribute__((naked)) play_ambient_sounds(void) {
    __asm__(
    ".include \"asm/code_dd930_len_1c0/play_ambient_sounds.s\"\n"
    );
}
