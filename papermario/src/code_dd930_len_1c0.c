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

INCLUDE_ASM(code_dd930_len_1c0, UpdateMusicPlayers);

INCLUDE_ASM(code_dd930_len_1c0, play_ambient_sounds);