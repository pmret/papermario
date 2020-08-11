#include "common.h"


void func_80035DF0(s16 arg0) {
    s16* tempPtr = &D_800A0942;
    *tempPtr = arg0;
}

INCLUDE_ASM(code_111f0_len_860, func_80035E00);

INCLUDE_ASM(code_111f0_len_860, func_80035E24);

INCLUDE_ASM(code_111f0_len_860, func_80035E54);

INCLUDE_ASM(code_111f0_len_860, func_80035EEC);

void func_800360FC(void) {
    game_status* gameStatus = *gGameStatusPtr;

    if (gameStatus->unk_AC == 2) {
        func_800E973C();
    }
}

void func_80036130(void) {
    game_status* gameStatus = *gGameStatusPtr;

    D_800A0940 = 0x00;
    D_800A0942 = 0x14;
    D_800A0944 = 0x00;

    if (gameStatus->unk_88 != gameStatus->unk_86) {
        gameStatus->unk_8A = 0x01;
        gameStatus->unk_88 = gameStatus->unk_86;
    }
    else {
        gameStatus->unk_8A = 0;
    }
}

INCLUDE_ASM(code_111f0_len_860, func_8003617C);

s32 func_800363FC(void) {
    s32 phi_return;

    if ((D_800A0944 == 4) || (phi_return = 4, (D_800A0944 == 0))) {
        phi_return = func_800E973C();
    }
    return phi_return;
}

s32 func_80036430(void) {
    player_status* pPlayerStatus = &gPlayerStatus;

    D_800A0940 = 0xFF;
    D_800A0942 = 0x14;
    D_800A0944 = 0x01;
    
    pPlayerStatus->flags |= 0x1000;

    return pPlayerStatus->flags;
}

INCLUDE_ASM(code_111f0_len_860, func_8003646C);

void func_80036640(void) {
}

