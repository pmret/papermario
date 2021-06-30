#include "common.h"
#include "battle/battle.h"

extern s32 D_800DC060;
extern Stage* D_800DC064;

INCLUDE_ASM(s32, "4DF30", reset_battle_status);

void ALT_reset_battle_status(void) {
    reset_battle_status();
}

void func_80072BCC(s32 arg0) {
    gBattleStatus.unk_488 = arg0;
}

//weird stuff with loading gBattleStatus
#ifdef NON_MATCHING
void load_battle_section(void) {
    BattleArea* battleArea;
    s32 temp_a0;

    battleArea = &gBattleAreas[gBattleStatus.currentBattleSection];
    dma_copy(battleArea->dmaStart, battleArea->dmaEnd, battleArea->dmaDest);

    gBattleStatus.unk_48C = &(*battleArea->battles)[gBattleStatus.unk_47B];

    if (gBattleStatus.unk_47C >= 0) {
        D_800DC064 = NULL;
    } else {
        D_800DC064 = &(*battleArea->stages)[gBattleStatus.unk_47C];
    }

    btl_set_state(1);
    gBattleStatus.unk_460 = 0;
}
#else
INCLUDE_ASM(s32, "4DF30", load_battle_section);
#endif

INCLUDE_ASM(s32, "4DF30", load_battle);

void set_battle_stage(s32 arg0) {
    gBattleStatus.unk_47C = arg0;
}

void set_battle_formation(s32 arg0) {
    gBattleStatus.unk_484 = arg0;
}

void func_80072CEC(f32 arg0, f32 arg1, f32 arg2) {
}

void func_80072CF4(void) {
    func_80072CEC(1.0f, 1.1f, 1.2f);
}

INCLUDE_ASM(s32, "4DF30", setup_demo_player);

INCLUDE_ASM(s32, "4DF30", load_demo_battle);
