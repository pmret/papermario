#include "common.h"

// TODO: move to src/battle/action_cmd.c

// action command state
extern struct D_8029FBE0 {
    /* 0x00 */ char unk_00[0x6D];
    /* 0x6E */ s16 hitsTakenIsMax;
    /* 0x70 */ char unk_70[2];
    /* 0x72 */ char unk_72[2];
    /* 0x74 */ s16 unk_74;
    /* 0x76 */ s16 unk_76;
    /* 0x78 */ s16 unk_78;
    /* 0x7A */ s16 unk_7A;
    /* 0x7C */ s16 unk_7C;
    /* 0x7E */ s16 unk_7E;
    /* 0x80 */ s8 unk_80;
} D_8029FBE0; // size unknown

extern void* actionCommandDmaTable[23];
extern s32 D_8029FBC0;

ApiStatus LoadActionCommand(ScriptInstance* script, s32 isInitialCall) {
    s32 cmd = get_variable(script, *script->ptrReadPos);

    dma_copy(actionCommandDmaTable[cmd * 3], actionCommandDmaTable[cmd * 3 + 1], actionCommandDmaTable[cmd * 3 + 2]);
    return ApiStatus_DONE2;
}

s32 func_80268224(s32 arg0) {
    if (!(gBattleStatus.flags1 & 0x80000)) {
        arg0 -= is_ability_active(ABILITY_DODGE_MASTER) * 3;
    }

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 7) {
        arg0 = 7;
    }

    return arg0;
}

INCLUDE_ASM(s32, "196AA0", func_80268284);

void func_80268770(s32 arg0, s32 arg1, s32 arg2) {
    D_8029FBC0 = 2;
    func_80268284(arg0, arg1, arg2, 0);
}

void func_80268798(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8029FBC0 = arg3;
    func_80268284(arg0, arg1, arg2, 0);
}

void func_802687BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8029FBC0 = 2;
    func_80268284(arg0, arg1, arg2, arg3);
}

void func_802687E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_8029FBC0 = arg3;
    func_80268284(arg0, arg1, arg2, arg4);
}

void func_8026880C(s32 arg0, s32 arg1, s32 arg2) {
    D_8029FBC0 = 2;
    func_80268284(arg0, arg1, arg2, -1);
}

void func_80268834(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8029FBC0 = arg3;
    func_80268284(arg0, arg1, arg2, -1);
}

INCLUDE_ASM(s32, "196AA0", func_80268858);

INCLUDE_ASM(s32, "196AA0", func_80268938);

INCLUDE_ASM(s32, "196AA0", func_80268AF8);

INCLUDE_ASM(s32, "196AA0", func_80268C9C);

INCLUDE_ASM(s32, "196AA0", func_80268E88);

// regalloc + some logical difference, instructions are correct
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
    s32 ignoreWindow;

    battleStatus->blockResult = 0; // Fail

    if (battleStatus->unk_83 == -1 && (battleStatus->flags1 & 0x2000000)) {
        battleStatus->blockResult = 1;
        return TRUE;
    }

    block = FALSE;

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
        bufferPos = battleStatus->inputBufferPos - (mashWindow + blockWindow);

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
            bufferPos++;
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
            bufferPos++;
        }

        if (mash) {
            battleStatus->blockResult = -1; // Mash
            block = FALSE;
        }

        // Ignore inputs until another mash window has passed, so check_block_input() can be called in quick succession
        ignoreWindow = mashWindow + blockWindow;
        if (block == TRUE) {
            bufferPos = battleStatus->inputBufferPos - ignoreWindow;
            if (bufferPos < 0) {
                bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
            }
            for (i = 0; i < ignoreWindow; i++) {
                //block = FALSE; // this should be a different var
                if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                    bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                battleStatus->pushInputBuffer[bufferPos] = 0;
                bufferPos++;
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

ApiStatus SetupMashMeter(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    D_8029FBE0.unk_80 = get_variable(script, *args++);
    D_8029FBE0.unk_76 = get_variable(script, *args++);
    D_8029FBE0.unk_78 = get_variable(script, *args++);
    D_8029FBE0.unk_7A = get_variable(script, *args++);
    D_8029FBE0.unk_7C = get_variable(script, *args++);
    D_8029FBE0.unk_7E = get_variable(script, *args++);
    D_8029FBE0.unk_74 = D_8029FBE0.unk_76 / 2;
    return ApiStatus_DONE2;
}

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
