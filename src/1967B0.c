#include "common.h"

INCLUDE_ASM(s32, "1967B0", LoadItemScript);

extern s32 D_80293B80;

typedef struct BattleItemTableEntry {
    /* 0x0 */ u8* romStart;
    /* 0x4 */ u8* romEnd;
    /* 0x8 */ u8* vramStart;
    /* 0xC */ u8* vramEnd;
} BattleItemTableEntry; // size = 0x10

extern BattleItemTableEntry gBattleItemTable[];

INCLUDE_ASM(s32, "1967B0", LoadFreeItemScript);
// ApiStatus LoadFreeItemScript(ScriptInstance* script, s32 isInitialCall) {
//     Actor* player = gBattleStatus.playerActor;
//     StaticItem* staticItem = &gItemTable[gBattleStatus.selectedItemID];
//     SelectableTarget* selectableTarget;

//     s32 i;
//     s32 temp_v0;
//     BattleItemTableEntry* battleItemTableEntry;
//     s32* temp_v1;
//     s32 phi_v0;
//     s32* phi_v1;
//     s32 phi_v0_2;
//     s32 i;
//     s32 i;

//     gBattleStatus.currentAttackElement = 0;
//     gBattleStatus.currentTargetListFlags = staticItem->targetFlags | 0x8000;

//     player_create_target_list(player);

//     selectableTarget = &player->targetData[player->targetIndexList[0]];
//     gBattleStatus.currentTargetID = selectableTarget->actorID;
//     gBattleStatus.currentTargetPart = selectableTarget->partID;

//     if (D_80293B80 != 0) {
//         phi_v0 = D_80293B80;
//         phi_v1 = &D_80293B80;
//         i = 0;
// loop_2:
//         temp_v1 = phi_v1 + 4;
//         phi_v0_2 = phi_v0;
//         if (phi_v0 != gBattleStatus.selectedItemID) {
//             temp_v0 = *temp_v1;
//             i++;
//             phi_v0 = temp_v0;
//             phi_v1 = temp_v1;
//             if (temp_v0 != 0) {
//                 goto loop_2;
//             }
//             phi_v0_2 = *temp_v1;
//         }
//         if (phi_v0_2 == 0) {
// block_6:
//             i = !(staticItem->typeFlags & 0x80);
//         }
//     } else {
//         goto block_6;
//     }

//     battleItemTableEntry = &gBattleItemTable[i];
//     dma_copy(battleItemTableEntry->romStart, battleItemTableEntry->romEnd, battleItemTableEntry->vramStart);
//     script->varTable[1] = 1;
//     script->varTable[0] = battleItemTableEntry->vramEnd;

//     return ApiStatus_DONE2;
// }

ApiStatus LoadMoveScript(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32* moveScript = gMoveScriptTable[battleStatus->selectedMoveID];

    dma_copy(moveScript[0], moveScript[1], moveScript[2]);
    script->varTable[0] = moveScript[3];

    deduct_current_move_fp();

    if (gBattleStatus.flags2 & 0x8000000) {
        enable_player_blur();
    }

    return ApiStatus_DONE2;
}
