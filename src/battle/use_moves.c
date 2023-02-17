#include "common.h"
#include "ld_addrs.h"

extern EvtScript battle_move_hammer_attack_EVS_UseMove0;
extern EvtScript battle_move_hammer_attack_EVS_UseMove1;
extern EvtScript battle_move_hammer_attack_EVS_UseMove2;
extern EvtScript battle_move_spin_smash_EVS_UseMove;
extern EvtScript battle_move_quake_hammer_EVS_UseMove0;
extern EvtScript battle_move_d_down_pound_EVS_UseMove;
extern EvtScript battle_move_hammer_charge_0_EVS_UseMove0;
extern EvtScript battle_move_hammer_charge_0_EVS_UseMove1;
extern EvtScript battle_move_hammer_throw_EVS_UseMove;
extern EvtScript battle_move_mega_quake_EVS_UseMove;
extern EvtScript battle_move_hammer_charge_1_EVS_UseMove0;
extern EvtScript battle_move_hammer_charge_1_EVS_UseMove1;
extern EvtScript battle_move_hammer_charge_2_EVS_UseMove0;
extern EvtScript battle_move_hammer_charge_2_EVS_UseMove1;
extern EvtScript battle_move_auto_smash_main;
extern EvtScript battle_move_power_quake_EVS_UseMove;
extern EvtScript battle_move_power_smash_EVS_UseMove;
extern EvtScript battle_move_super_smash_EVS_UseMove;
extern EvtScript battle_move_mega_smash_EVS_UseMove;
extern EvtScript battle_move_shrink_smash_EVS_UseMove;
extern EvtScript battle_move_shell_crack_EVS_UseMove;
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

typedef struct BattleTableEntry {
    /* 0x00 */ u8* romStart;
    /* 0x04 */ u8* romEnd;
    /* 0x08 */ u8* vramStart;
    /* 0x0C */ EvtScript* mainScript;
} BattleTableEntry; // size = 0x10

// Some moves have multiple entry point methods, in which case the _SCR macro is used
#define BTL_MOVE_AUTO(name) \
{ \
    .romStart   = battle_move_##name##_ROM_START, \
    .romEnd     = battle_move_##name##_ROM_END, \
    .vramStart  = battle_move_##name##_VRAM, \
    .mainScript = &battle_move_##name##_main \
}

#define BTL_MOVE(name, script) \
{ \
    .romStart   = battle_move_##name##_ROM_START, \
    .romEnd     = battle_move_##name##_ROM_END, \
    .vramStart  = battle_move_##name##_VRAM, \
    .mainScript = &battle_move_##name##_##script \
}

BattleTableEntry gMoveScriptTable[] = {
    {},
    {},
    {},
    BTL_MOVE(hammer_attack, EVS_UseMove0),
    BTL_MOVE(hammer_attack, EVS_UseMove0),
    BTL_MOVE(hammer_attack, EVS_UseMove0),
    BTL_MOVE(hammer_attack, EVS_UseMove1),
    BTL_MOVE(hammer_attack, EVS_UseMove2),
    BTL_MOVE(spin_smash, EVS_UseMove),
    BTL_MOVE(quake_hammer, EVS_UseMove0),
    BTL_MOVE(d_down_pound, EVS_UseMove),
    BTL_MOVE(hammer_charge_0, EVS_UseMove0),
    BTL_MOVE(hammer_charge_0, EVS_UseMove1),
    BTL_MOVE(hammer_throw, EVS_UseMove),
    BTL_MOVE(mega_quake, EVS_UseMove),
    BTL_MOVE(hammer_charge_1, EVS_UseMove0),
    BTL_MOVE(hammer_charge_1, EVS_UseMove1),
    BTL_MOVE(hammer_charge_2, EVS_UseMove0),
    BTL_MOVE(hammer_charge_2, EVS_UseMove1),
    BTL_MOVE(auto_smash, UseMove),
    BTL_MOVE(power_quake, EVS_UseMove),
    BTL_MOVE(power_smash, EVS_UseMove),
    BTL_MOVE(super_smash, EVS_UseMove),
    BTL_MOVE(mega_smash,  EVS_UseMove),
    BTL_MOVE(shrink_smash, EVS_UseMove),
    BTL_MOVE(shell_crack, EVS_UseMove),
    BTL_MOVE(jump, 802A2650),
    BTL_MOVE(jump, 802A2650),
    BTL_MOVE(jump, 802A2650),
    BTL_MOVE(jump, 802A30F4),
    BTL_MOVE(jump, 802A3644),
    BTL_MOVE_AUTO(multibounce),
    BTL_MOVE_AUTO(power_bounce),
    BTL_MOVE_AUTO(sleep_stomp),
    BTL_MOVE_AUTO(dizzy_stomp),
    BTL_MOVE(jump_charge_0, 802A2800),
    BTL_MOVE(jump_charge_0, 802A27F0),
    BTL_MOVE(jump_charge_1, 802A2880),
    BTL_MOVE(jump_charge_1, 802A2870),
    BTL_MOVE(jump_charge_2, 802A2880),
    BTL_MOVE(jump_charge_2, 802A2870),
    BTL_MOVE_AUTO(auto_jump),
    BTL_MOVE_AUTO(auto_multibounce),
    BTL_MOVE_AUTO(power_jump),
    BTL_MOVE_AUTO(super_jump),
    BTL_MOVE_AUTO(mega_jump),
    BTL_MOVE_AUTO(d_down_jump),
    BTL_MOVE_AUTO(shrink_stomp),
    BTL_MOVE_AUTO(earthquake_jump),
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
