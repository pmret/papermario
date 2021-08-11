#include "common.h"

// TODO: move to src/battle/action_cmd.c

enum ActionCommand {
    ACTION_COMMAND_JUMP = 1,
    ACTION_COMMAND_SMASH,
    ACTION_COMMAND_FLEE,
    ACTION_COMMAND_BREAK_FREE,
    ACTION_COMMAND_WHIRLWIND,
    ACTION_COMMAND_STOP_LEECH,
    ACTION_COMMAND_07,
    ACTION_COMMAND_DIZZY_SHELL,
    ACTION_COMMAND_FIRE_SHELL,
    ACTION_COMMAND_0A,
    ACTION_COMMAND_BOMB,
    ACTION_COMMAND_BODY_SLAM,
    ACTION_COMMAND_AIR_LIFT,
    ACTION_COMMAND_AIR_RAID,
    ACTION_COMMAND_SQUIRT,
    ACTION_COMMAND_POWER_SHOCK,
    ACTION_COMMAND_MEGA_SHOCK,
    ACTION_COMMAND_SMACK,
    ACTION_COMMAND_SPINY_SURGE,
    ACTION_COMMAND_HURRICANE,
    ACTION_COMMAND_SPOOK,
    ACTION_COMMAND_WATER_BLOCK,
    ACTION_COMMAND_TIDAL_WAVE,
};

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

void func_80268858(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    actionCommandStatus->autoSucceed = FALSE;
    actionCommandStatus->unk_6A = FALSE;

    if (!(gBattleStatus.flags1 & 0x80000)) {
        if (is_ability_active(ABILITY_RIGHT_ON)) {
            actionCommandStatus->autoSucceed = TRUE;
        }

        if (!(gBattleStatus.flags1 & 0x80000) && is_ability_active(ABILITY_BERSERKER)) {
            actionCommandStatus->unk_61 = FALSE;
            actionCommandStatus->unk_6A = TRUE;

            if (rand_int(100) < 25) {
                actionCommandStatus->autoSucceed = TRUE;
            }
        }
    }

    if (gGameStatusPtr->demoFlags & 1) {
        actionCommandStatus->autoSucceed = TRUE;
    }

    if (gBattleStatus.flags1 & 0x1000) {
        actionCommandStatus->autoSucceed = TRUE;
        actionCommandStatus->unk_61 = FALSE;
    }
}

// action_cmd_current_main - calls current action command's main func
#ifdef NON_MATCHING
void func_80268938(void) {
    enum ActionCommand ac;

    if (gBattleStatus.flags1 & 0x8000) {
        func_80268C9C();
    }

    ac = gActionCommandStatus.unk_4A;

    switch (ac) {
        case ACTION_COMMAND_JUMP:
            func_802A9234_421C24();
            return;
        case ACTION_COMMAND_SMASH:
            func_802A936C_42236C();
            return;
        case ACTION_COMMAND_FLEE:
            func_802A9378_422E48();
            return;
        case ACTION_COMMAND_BREAK_FREE:
            func_802A92DC_4236CC();
            return;
        case ACTION_COMMAND_WHIRLWIND:
            func_802A92F0_423F60();
            return;
        case ACTION_COMMAND_STOP_LEECH:
            func_802A91F8_425788();
            return;
        case ACTION_COMMAND_07:
            func_802A9228_425D78();
            return;
        case ACTION_COMMAND_DIZZY_SHELL:
            func_802A928C_4263FC();
            return;
        case ACTION_COMMAND_FIRE_SHELL:
            func_802A9294_426C64();
            return;
        case ACTION_COMMAND_0A:
            func_802A928C_4263FC();
            return;
        case ACTION_COMMAND_BOMB:
            func_802A928C_4263FC();
            return;
        case ACTION_COMMAND_BODY_SLAM:
            func_802A92D4_4285B4();
            return;
        case ACTION_COMMAND_AIR_LIFT:
            func_802A9278_428CE8();
            return;
        case ACTION_COMMAND_AIR_RAID:
            func_802A9294_426C64();
            return;
        case ACTION_COMMAND_SQUIRT:
            func_802A9208_429F28();
            return;
        case ACTION_COMMAND_POWER_SHOCK:
            func_802A9310_42D220();
            return;
        case ACTION_COMMAND_MEGA_SHOCK:
            func_802A92A0_422D70();
            return;
        case ACTION_COMMAND_SMACK:
            func_802A9298_42E638();
            return;
        case ACTION_COMMAND_SPINY_SURGE:
            func_802A9254_42F074();
            return;
        case ACTION_COMMAND_HURRICANE:
            func_802A92A0_422D70();
            return;
        case ACTION_COMMAND_SPOOK:
            func_802A9298_42E638();
            return;
        case ACTION_COMMAND_WATER_BLOCK:
            func_802A948C_42A97C();
            return;
        case ACTION_COMMAND_TIDAL_WAVE:
            func_802A9228_425D78();
            return;
    }
}
#else
INCLUDE_ASM(s32, "196AA0", func_80268938);
#endif

INCLUDE_ASM(s32, "196AA0", func_80268AF8);

INCLUDE_ASM(s32, "196AA0", func_80268C9C);

INCLUDE_ASM(s32, "196AA0", func_80268E88);

s32 check_block_input(s32 buttonMask) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
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

    if (!battleStatus->unk_83 || (gGameStatusPtr->demoFlags & 1)) {
        return FALSE;
    }

    if (playerData->hitsTaken < 9999) {
        playerData->hitsTaken += 1;
        actionCommandStatus->hitsTakenIsMax = FALSE;
    } else {
        actionCommandStatus->hitsTakenIsMax = TRUE;
    }

    block = FALSE;
    blockWindow = 3;
    mashWindow = 10;

    if (!(gBattleStatus.flags1 & 0x80000) && is_ability_active(ABILITY_DODGE_MASTER)) {
        blockWindow = 5;
    }

    // Pre-window mashing check
    bufferPos = battleStatus->inputBufferPos;
    bufferPos -= mashWindow + blockWindow;

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
    bufferPos = battleStatus->inputBufferPos;
    bufferPos -= blockWindow;
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
    if (block == TRUE) {
        bufferPos = battleStatus->inputBufferPos;
        bufferPos -= mashWindow + blockWindow;
        if (bufferPos < 0) {
            bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
        }

        for (i = 0; i < mashWindow + blockWindow; i++) {
            if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
            }
            battleStatus->pushInputBuffer[bufferPos] = 0;
            bufferPos++;
        }
    }
    if (block && !actionCommandStatus->hitsTakenIsMax) {
        playerData->hitsBlocked += 1;
    }

    return block;
}

INCLUDE_ASM(s32, "196AA0", func_80269118);

INCLUDE_ASM(s32, "196AA0", func_80269160);

ApiStatus func_8026919C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_434 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetupMashMeter(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    gActionCommandStatus.mashMeterIntervals = get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[0] = get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[1] = get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[2] = get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[3] = get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[4] = get_variable(script, *args++);
    gActionCommandStatus.unk_74 = gActionCommandStatus.mashMeterCutoffs[0] / 2;
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
