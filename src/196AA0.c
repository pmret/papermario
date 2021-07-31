#include "common.h"

// playerData status?
extern struct D_8029FBE0 {
    /* 0x00 */ char unk_00[0x6D];
    /* 0x6E */ s16 hitsTakenIsMax;
} D_8029FBE0; // size unknown

extern void* actionCommandDmaTable[23];

ApiStatus LoadActionCommand(ScriptInstance* script, s32 isInitialCall) {
    s32 cmd = get_variable(script, *script->ptrReadPos);

    dma_copy(actionCommandDmaTable[cmd * 3], actionCommandDmaTable[cmd * 3 + 1], actionCommandDmaTable[cmd * 3 + 2]);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "196AA0", func_80268224);

INCLUDE_ASM(s32, "196AA0", func_80268284);

INCLUDE_ASM(s32, "196AA0", func_80268770);

INCLUDE_ASM(s32, "196AA0", func_80268798);

INCLUDE_ASM(s32, "196AA0", func_802687BC);

INCLUDE_ASM(s32, "196AA0", func_802687E4);

INCLUDE_ASM(s32, "196AA0", func_8026880C);

INCLUDE_ASM(s32, "196AA0", func_80268834);

INCLUDE_ASM(s32, "196AA0", func_80268858);

INCLUDE_ASM(s32, "196AA0", func_80268938);

INCLUDE_ASM(s32, "196AA0", func_80268AF8);

INCLUDE_ASM(s32, "196AA0", func_80268C9C);

INCLUDE_ASM(s32, "196AA0", func_80268E88);

// ARRAY_COUNT possibly placed in a temp var
#ifdef NON_MATCHING
s32 check_block_input(s32 buttonMask) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    struct D_8029FBE0* d8029FBE0 = &D_8029FBE0;
    s32 mashWindow;
    s32 blockWindow;
    s32 block;
    s32 mash = FALSE;
    s32 bufferPos;
    s32 i;

    battleStatus->blockResult = 0; // Fail

    if (battleStatus->unk_83 == -1 && (battleStatus->flags1 & 0x2000000)) {
        battleStatus->blockResult = 1;
        return TRUE;
    }

    if (battleStatus->unk_83 && !(gGameStatusPtr->demoFlags & 1)) {
        if (playerData->hitsTaken < 9999) {
            playerData->hitsTaken += 1;
            d8029FBE0->hitsTakenIsMax = FALSE;
        } else {
            d8029FBE0->hitsTakenIsMax = TRUE;
        }

        block = FALSE;
        blockWindow = 3;
        mashWindow = 10;

        if (!(gBattleStatus.flags1 & 0x80000) && is_ability_active(ABILITY_DODGE_MASTER)) {
            blockWindow = 5;
        }

        // Pre-window mashing check
        bufferPos = battleStatus->inputBufferPos - (blockWindow + mashWindow);

        if (bufferPos < 0) {
            bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
        }
        for (i = 0; i < mashWindow; i++) {
            if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
            }

            if (battleStatus->pushInputBuffer[bufferPos] & buttonMask) {
                mash = TRUE;
                break;
            }
        }

        // Block check
        bufferPos = battleStatus->inputBufferPos - blockWindow;
        if (bufferPos < 0) {
            bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
        }
        for (i = 0; i < blockWindow; i++) {
            if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
            }

            if (battleStatus->pushInputBuffer[bufferPos] & buttonMask) {
                battleStatus->blockResult = 1; // Block
                block = TRUE;
                break;
            }
        }

        if (mash) {
            battleStatus->blockResult = -1; // Mash
        }

        // Ignore inputs until another mash window has passed, so check_block_input() can be called in quick succession
        if (block == TRUE) {
            bufferPos = battleStatus->inputBufferPos - (blockWindow + mashWindow);
            if (bufferPos < 0) {
                bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
            }
            for (i = 0; i < mashWindow; i++) {
                if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                    bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                battleStatus->pushInputBuffer[bufferPos] = 0;
            }
        }

        if (block && !d8029FBE0->hitsTakenIsMax) {
            playerData->hitsBlocked += 1;
        }
    }

    return block;
}
#else
INCLUDE_ASM(s32, "196AA0", check_block_input);
#endif

INCLUDE_ASM(s32, "196AA0", func_80269118);

INCLUDE_ASM(s32, "196AA0", func_80269160);

ApiStatus func_8026919C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_434 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "196AA0", SetupMashMeter);

ApiStatus GetActionSuccess(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

ApiStatus SetActionSuccess(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.actionSuccess = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetActionCommandMode(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_83 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus GetActionCommandMode(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_83);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "196AA0", func_80269344);

INCLUDE_ASM(s32, "196AA0", SetCommandAutoSuccess);

INCLUDE_ASM(s32, "196AA0", GetCommandAutoSuccess);

ApiStatus func_802693F0(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 &= ~0x4000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "196AA0", CloseActionCommandInfo);

INCLUDE_ASM(s32, "196AA0", func_80269470);

INCLUDE_ASM(s32, "196AA0", func_802694A4);

ApiStatus GetActionSuccessCopy(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

ApiStatus func_80269524(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_86);
    return ApiStatus_DONE2;
}

ApiStatus func_80269550(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_86 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus GetBlockResult(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.blockResult);
    return ApiStatus_DONE2;
}

ApiStatus GetActionResult(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_84);
    return ApiStatus_DONE2;
}

ApiStatus SetActionResult(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_84 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_80269600(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_85);
    return ApiStatus_DONE2;
}

ApiStatus func_8026962C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_85 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
