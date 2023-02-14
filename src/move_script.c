#include "common.h"
#include "ld_addrs.h"

typedef struct BattleTableEntry {
    /* 0x00 */ u8* romStart;
    /* 0x04 */ u8* romEnd;
    /* 0x08 */ u8* vramStart;
    /* 0x0C */ EvtScript* mainScript;
} BattleTableEntry; // size = 0x10

extern EvtScript battle_move_hammer_802A3044;
extern EvtScript battle_move_hammer_802A369C;
extern EvtScript battle_move_hammer_802A3B28;
extern EvtScript battle_move_spin_smash_main;
extern EvtScript battle_move_quake_hammer_main;
extern EvtScript battle_move_d_down_pound_main;
extern EvtScript battle_move_hammer_charge_0_802A38C4;
extern EvtScript battle_move_hammer_charge_0_802A3234;
extern EvtScript battle_move_hammer_throw_main;
extern EvtScript battle_move_mega_quake_main;
extern EvtScript battle_move_hammer_charge_1_802A3944;
extern EvtScript battle_move_hammer_charge_1_802A32B4;
extern EvtScript battle_move_hammer_charge_2_802A3944;
extern EvtScript battle_move_hammer_charge_2_802A32B4;
extern EvtScript battle_move_auto_smash_main;
extern EvtScript battle_move_power_quake_main;
extern EvtScript battle_move_power_smash_main;
extern EvtScript battle_move_super_smash_main;
extern EvtScript battle_move_mega_smash_main;
extern EvtScript battle_move_shrink_smash_main;
extern EvtScript battle_move_shell_crack_main;
extern EvtScript battle_move_jump_802A2650;
extern EvtScript battle_move_jump_802A30F4;
extern EvtScript battle_move_jump_802A3644;
extern EvtScript battle_move_multibounce_main;
extern EvtScript battle_move_power_bounce_main;
extern EvtScript battle_move_sleep_stomp_main;
extern EvtScript battle_move_dizzy_stomp_main;
extern EvtScript battle_move_jump_charge_0_802A2800;
extern EvtScript battle_move_jump_charge_0_802A27F0;
extern EvtScript battle_move_jump_charge_1_802A2880;
extern EvtScript battle_move_jump_charge_1_802A2870;
extern EvtScript battle_move_jump_charge_2_802A2880;
extern EvtScript battle_move_jump_charge_2_802A2870;
extern EvtScript battle_move_auto_jump_main;
extern EvtScript battle_move_auto_multibounce_main;
extern EvtScript battle_move_power_jump_main;
extern EvtScript battle_move_super_jump_main;
extern EvtScript battle_move_mega_jump_main;
extern EvtScript battle_move_d_down_jump_main;
extern EvtScript battle_move_shrink_stomp_main;
extern EvtScript battle_move_earthquake_jump_main;
extern EvtScript battle_move_auto_smash_UseMove;

// Some moves seem to have multiple entry point methods, in which case the _SCR macro is used
#define BTL_MOVE_TABLE_ENTRY(name) { battle_move_##name##_ROM_START, battle_move_##name##_ROM_END, battle_move_##name##_VRAM, &battle_move_##name##_main }
#define BTL_MOVE_TABLE_ENTRY_SCR(name, script) { battle_move_##name##_ROM_START, battle_move_##name##_ROM_END, battle_move_##name##_VRAM, &script }

BattleTableEntry gMoveScriptTable[] = {
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    BTL_MOVE_TABLE_ENTRY_SCR(hammer, battle_move_hammer_802A3044),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer, battle_move_hammer_802A3044),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer, battle_move_hammer_802A3044),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer, battle_move_hammer_802A369C),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer, battle_move_hammer_802A3B28),
    BTL_MOVE_TABLE_ENTRY(spin_smash),
    BTL_MOVE_TABLE_ENTRY(quake_hammer),
    BTL_MOVE_TABLE_ENTRY(d_down_pound),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer_charge_0, battle_move_hammer_charge_0_802A38C4),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer_charge_0, battle_move_hammer_charge_0_802A3234),
    BTL_MOVE_TABLE_ENTRY(hammer_throw),
    BTL_MOVE_TABLE_ENTRY(mega_quake),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer_charge_1, battle_move_hammer_charge_1_802A3944),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer_charge_1, battle_move_hammer_charge_1_802A32B4),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer_charge_2, battle_move_hammer_charge_2_802A3944),
    BTL_MOVE_TABLE_ENTRY_SCR(hammer_charge_2, battle_move_hammer_charge_2_802A32B4),
    BTL_MOVE_TABLE_ENTRY_SCR(auto_smash, battle_move_auto_smash_UseMove),
    BTL_MOVE_TABLE_ENTRY(power_quake),
    BTL_MOVE_TABLE_ENTRY(power_smash),
    BTL_MOVE_TABLE_ENTRY(super_smash),
    BTL_MOVE_TABLE_ENTRY(mega_smash),
    BTL_MOVE_TABLE_ENTRY(shrink_smash),
    BTL_MOVE_TABLE_ENTRY(shell_crack),
    BTL_MOVE_TABLE_ENTRY_SCR(jump, battle_move_jump_802A2650),
    BTL_MOVE_TABLE_ENTRY_SCR(jump, battle_move_jump_802A2650),
    BTL_MOVE_TABLE_ENTRY_SCR(jump, battle_move_jump_802A2650),
    BTL_MOVE_TABLE_ENTRY_SCR(jump, battle_move_jump_802A30F4),
    BTL_MOVE_TABLE_ENTRY_SCR(jump, battle_move_jump_802A3644),
    BTL_MOVE_TABLE_ENTRY(multibounce),
    BTL_MOVE_TABLE_ENTRY(power_bounce),
    BTL_MOVE_TABLE_ENTRY(sleep_stomp),
    BTL_MOVE_TABLE_ENTRY(dizzy_stomp),
    BTL_MOVE_TABLE_ENTRY_SCR(jump_charge_0, battle_move_jump_charge_0_802A2800),
    BTL_MOVE_TABLE_ENTRY_SCR(jump_charge_0, battle_move_jump_charge_0_802A27F0),
    BTL_MOVE_TABLE_ENTRY_SCR(jump_charge_1, battle_move_jump_charge_1_802A2880),
    BTL_MOVE_TABLE_ENTRY_SCR(jump_charge_1, battle_move_jump_charge_1_802A2870),
    BTL_MOVE_TABLE_ENTRY_SCR(jump_charge_2, battle_move_jump_charge_2_802A2880),
    BTL_MOVE_TABLE_ENTRY_SCR(jump_charge_2, battle_move_jump_charge_2_802A2870),
    BTL_MOVE_TABLE_ENTRY(auto_jump),
    BTL_MOVE_TABLE_ENTRY(auto_multibounce),
    BTL_MOVE_TABLE_ENTRY(power_jump),
    BTL_MOVE_TABLE_ENTRY(super_jump),
    BTL_MOVE_TABLE_ENTRY(mega_jump),
    BTL_MOVE_TABLE_ENTRY(d_down_jump),
    BTL_MOVE_TABLE_ENTRY(shrink_stomp),
    BTL_MOVE_TABLE_ENTRY(earthquake_jump),
};

ApiStatus LoadMoveScript(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleTableEntry* moveTableEntry = &gMoveScriptTable[battleStatus->selectedMoveID];

    dma_copy(moveTableEntry->romStart, moveTableEntry->romEnd, moveTableEntry->vramStart);
    script->varTablePtr[0] = moveTableEntry->mainScript;

    deduct_current_move_fp();

    if (gBattleStatus.flags2 & BS_FLAGS2_HAS_RUSH) {
        enable_player_blur();
    }

    return ApiStatus_DONE2;
}
