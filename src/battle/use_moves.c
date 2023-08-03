#include "common.h"
#include "ld_addrs.h"
#include "battle.h"

extern EvtScript battle_move_hammer_attack_EVS_UseMove0;
extern EvtScript battle_move_hammer_attack_EVS_UseMove1;
extern EvtScript battle_move_hammer_attack_EVS_UseMove2;
extern EvtScript battle_move_hammer_charge_0_EVS_UseMove0;
extern EvtScript battle_move_hammer_charge_0_EVS_UseMove1;
extern EvtScript battle_move_hammer_charge_1_EVS_UseMove0;
extern EvtScript battle_move_hammer_charge_1_EVS_UseMove1;
extern EvtScript battle_move_hammer_charge_2_EVS_UseMove0;
extern EvtScript battle_move_hammer_charge_2_EVS_UseMove1;
extern EvtScript battle_move_auto_smash_EVS_UseMove;
extern EvtScript battle_move_power_smash_EVS_UseMove;
extern EvtScript battle_move_super_smash_EVS_UseMove;
extern EvtScript battle_move_mega_smash_EVS_UseMove;
extern EvtScript battle_move_quake_hammer_EVS_UseMove0;
extern EvtScript battle_move_power_quake_EVS_UseMove;
extern EvtScript battle_move_mega_quake_EVS_UseMove;
extern EvtScript battle_move_hammer_throw_EVS_UseMove;
extern EvtScript battle_move_d_down_pound_EVS_UseMove;
extern EvtScript battle_move_shrink_smash_EVS_UseMove;
extern EvtScript battle_move_spin_smash_EVS_UseMove;
extern EvtScript battle_move_shell_crack_EVS_UseMove;

extern EvtScript battle_move_jump_attack_EVS_UseMove0;
extern EvtScript battle_move_jump_attack_EVS_UseMove1;
extern EvtScript battle_move_jump_attack_EVS_UseMove2;
extern EvtScript battle_move_jump_charge_0_EVS_UseMove0;
extern EvtScript battle_move_jump_charge_0_EVS_UseMove1;
extern EvtScript battle_move_jump_charge_1_EVS_UseMove0;
extern EvtScript battle_move_jump_charge_1_EVS_UseMove1;
extern EvtScript battle_move_jump_charge_2_EVS_UseMove0;
extern EvtScript battle_move_jump_charge_2_EVS_UseMove1;
extern EvtScript battle_move_auto_jump_EVS_UseMove;
extern EvtScript battle_move_power_jump_EVS_UseMove;
extern EvtScript battle_move_super_jump_EVS_UseMove;
extern EvtScript battle_move_mega_jump_EVS_UseMove;
extern EvtScript battle_move_auto_multibounce_EVS_UseMove;
extern EvtScript battle_move_multibounce_EVS_UseMove;
extern EvtScript battle_move_power_bounce_EVS_UseMove;
extern EvtScript battle_move_d_down_jump_EVS_UseMove;
extern EvtScript battle_move_sleep_stomp_EVS_UseMove;
extern EvtScript battle_move_dizzy_stomp_EVS_UseMove;
extern EvtScript battle_move_shrink_stomp_EVS_UseMove;
extern EvtScript battle_move_earthquake_jump_EVS_UseMove;

BattleMoveEntry gMoveScriptTable[] = {
    [MOVE_NONE]                 {},
    [MOVE_UNUSED_01]            {},
    [MOVE_UNUSED_02]            {},
    [MOVE_HAMMER1]              BTL_MOVE(hammer_attack, EVS_UseMove0),
    [MOVE_HAMMER2]              BTL_MOVE(hammer_attack, EVS_UseMove0),
    [MOVE_HAMMER3]              BTL_MOVE(hammer_attack, EVS_UseMove0),
    [MOVE_FIRST_STRIKE_HAMMER]  BTL_MOVE(hammer_attack, EVS_UseMove1),
    [MOVE_BERSERKER_HAMMER]     BTL_MOVE(hammer_attack, EVS_UseMove2),
    [MOVE_SPIN_SMASH]           BTL_MOVE(spin_smash, EVS_UseMove),
    [MOVE_QUAKE_HAMMER]         BTL_MOVE(quake_hammer, EVS_UseMove0),
    [MOVE_D_DOWN_POUND]         BTL_MOVE(d_down_pound, EVS_UseMove),
    [MOVE_SMASH_CHARGE0]        BTL_MOVE(hammer_charge_0, EVS_UseMove0),
    [MOVE_UNUSED_HAMMER_0C]     BTL_MOVE(hammer_charge_0, EVS_UseMove1),
    [MOVE_HAMMER_THROW]         BTL_MOVE(hammer_throw, EVS_UseMove),
    [MOVE_MEGA_QUAKE]           BTL_MOVE(mega_quake, EVS_UseMove),
    [MOVE_SMASH_CHARGE]         BTL_MOVE(hammer_charge_1, EVS_UseMove0),
    [MOVE_UNUSED_HAMMER_10]     BTL_MOVE(hammer_charge_1, EVS_UseMove1),
    [MOVE_SUPER_SMASH_CHARGE]   BTL_MOVE(hammer_charge_2, EVS_UseMove0),
    [MOVE_UNUSED_HAMMER_12]     BTL_MOVE(hammer_charge_2, EVS_UseMove1),
    [MOVE_AUTO_SMASH]           BTL_MOVE(auto_smash,  EVS_UseMove),
    [MOVE_POWER_QUAKE]          BTL_MOVE(power_quake, EVS_UseMove),
    [MOVE_POWER_SMASH]          BTL_MOVE(power_smash, EVS_UseMove),
    [MOVE_SUPER_SMASH]          BTL_MOVE(super_smash, EVS_UseMove),
    [MOVE_MEGA_SMASH]           BTL_MOVE(mega_smash,  EVS_UseMove),
    [MOVE_SHRINK_SMASH]         BTL_MOVE(shrink_smash, EVS_UseMove),
    [MOVE_SHELL_CRACK]          BTL_MOVE(shell_crack, EVS_UseMove),
    [MOVE_JUMP1]                BTL_MOVE(jump_attack, EVS_UseMove0),
    [MOVE_JUMP2]                BTL_MOVE(jump_attack, EVS_UseMove0),
    [MOVE_JUMP3]                BTL_MOVE(jump_attack, EVS_UseMove0),
    [MOVE_FIRST_STRIKE_JUMP]    BTL_MOVE(jump_attack, EVS_UseMove1),
    [MOVE_BERSERKER_JUMP]       BTL_MOVE(jump_attack, EVS_UseMove2),
    [MOVE_MULTIBOUNCE]          BTL_MOVE(multibounce, EVS_UseMove),
    [MOVE_POWER_BOUNCE]         BTL_MOVE(power_bounce, EVS_UseMove),
    [MOVE_SLEEP_STOMP]          BTL_MOVE(sleep_stomp, EVS_UseMove),
    [MOVE_DIZZY_STOMP]          BTL_MOVE(dizzy_stomp, EVS_UseMove),
    [MOVE_JUMP_CHARGE0]         BTL_MOVE(jump_charge_0, EVS_UseMove0),
    [MOVE_UNUSED_24]            BTL_MOVE(jump_charge_0, EVS_UseMove1),
    [MOVE_JUMP_CHARGE]          BTL_MOVE(jump_charge_1, EVS_UseMove0),
    [MOVE_UNUSED_26]            BTL_MOVE(jump_charge_1, EVS_UseMove1),
    [MOVE_SUPER_JUMP_CHARGE]    BTL_MOVE(jump_charge_2, EVS_UseMove0),
    [MOVE_UNUSED_28]            BTL_MOVE(jump_charge_2, EVS_UseMove1),
    [MOVE_AUTO_JUMP]            BTL_MOVE(auto_jump, EVS_UseMove),
    [MOVE_AUTO_MULTIBOUNCE]     BTL_MOVE(auto_multibounce, EVS_UseMove),
    [MOVE_POWER_JUMP]           BTL_MOVE(power_jump, EVS_UseMove),
    [MOVE_SUPER_JUMP]           BTL_MOVE(super_jump, EVS_UseMove),
    [MOVE_MEGA_JUMP]            BTL_MOVE(mega_jump,  EVS_UseMove),
    [MOVE_D_DOWN_JUMP]          BTL_MOVE(d_down_jump, EVS_UseMove),
    [MOVE_SHRINK_STOMP]         BTL_MOVE(shrink_stomp, EVS_UseMove),
    [MOVE_EARTHQUAKE_JUMP]      BTL_MOVE(earthquake_jump, EVS_UseMove),
};

ApiStatus LoadMoveScript(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleMoveEntry* moveTableEntry = &gMoveScriptTable[battleStatus->selectedMoveID];

    dma_copy(moveTableEntry->romStart, moveTableEntry->romEnd, moveTableEntry->vramStart);
    script->varTablePtr[0] = moveTableEntry->mainScript;

    deduct_current_move_fp();

    if (gBattleStatus.flags2 & BS_FLAGS2_HAS_RUSH) {
        enable_player_blur();
    }

    return ApiStatus_DONE2;
}
