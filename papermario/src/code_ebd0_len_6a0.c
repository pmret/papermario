#include "common.h"

void func_800337D0(s16 new_fade_status) {
    game_status* gameStatus = *gGameStatusPtr;
    gameStatus->fade_status = new_fade_status;
    return;
}

void func_800337E0(s16 arg0) {
    game_status* gameStatus = *gGameStatusPtr;
    gameStatus->boot_logos_unk3 = arg0;
    gameStatus->boot_logos_unk2 = arg0;
    gameStatus->boot_logos_unk1 = arg0;
}

s16 func_800337F8(subtract_val) {
    game_status* gameStatus = *gGameStatusPtr;
    if (gameStatus->fade_status != 0){
        gameStatus->fade_status -= subtract_val;
        if (gameStatus->fade_status << 0x10 < 0){
            gameStatus->fade_status = 0;
        }
    }
    else {
        return 1;
    }
    return 0;
}

s16 func_80033830(add_val) {
    game_status* gameStatus = *gGameStatusPtr;
    if (gameStatus->fade_status != 0xFF){
        gameStatus->fade_status += add_val;
        if ((gameStatus->fade_status >= 0x100)){
            gameStatus->fade_status = 0xFF;
        }
    }
    else {
        return 1;
    }
    return 0;
}

void func_80137D88(s32, f32);
void func_80137E10(s32, u8, u8, u8);

void func_80033874(void) {
    
    func_80137D88(0, (f32) (*gGameStatusPtr)->fade_status);
    func_80137E10(0, (*gGameStatusPtr)->boot_logos_unk1, (*gGameStatusPtr)->boot_logos_unk2, (*gGameStatusPtr)->boot_logos_unk3);
    return 0;
}

s8 start_battle_countdown(void) {
    D_800A0900 = 5;
}


INCLUDE_ASM(code_ebd0_len_6a0, step_battle);
