#include "common.h"
#include "battle/action_cmd/jump.h"
#include "battle/action_cmd/hammer.h"
#include "battle/action_cmd/flee.h"
#include "battle/action_cmd/break_free.h"
#include "battle/action_cmd/whirlwind.h"
#include "battle/action_cmd/stop_leech.h"
#include "battle/action_cmd/07.h"
#include "battle/action_cmd/dizzy_shell.h"
#include "battle/action_cmd/fire_shell.h"
#include "battle/action_cmd/0A.h"
#include "battle/action_cmd/bomb.h"
#include "battle/action_cmd/body_slam.h"
#include "battle/action_cmd/air_lift.h"
#include "battle/action_cmd/air_raid.h"
#include "battle/action_cmd/squirt.h"
#include "battle/action_cmd/power_shock.h"
#include "battle/action_cmd/mega_shock.h"
#include "battle/action_cmd/smack.h"
#include "battle/action_cmd/spiny_surge.h"
#include "battle/action_cmd/hurricane.h"
#include "battle/action_cmd/spook.h"
#include "battle/action_cmd/water_block.h"
#include "battle/action_cmd/tidal_wave.h"

// TODO: move to src/battle/action_cmd.c

extern void* actionCommandDmaTable[23];
extern s32 D_8029FBC0;
extern s16 D_8029FC4C;

ApiStatus LoadActionCommand(Evt* script, s32 isInitialCall) {
    s32 cmd = evt_get_variable(script, *script->ptrReadPos);

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

void func_80268938(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (gBattleStatus.flags1 & BS_FLAGS1_8000) {
        func_80268C9C();
    }

    switch (actionCommandStatus->actionCommandID) {
        case ACTION_COMMAND_NONE:
            break;
        case ACTION_COMMAND_JUMP:
            action_command_jump_update();
            break;
        case ACTION_COMMAND_SMASH:
            func_802A936C_42236C();
            break;
        case ACTION_COMMAND_FLEE:
            func_802A9378_422E48();
            break;
        case ACTION_COMMAND_BREAK_FREE:
            func_802A92DC_4236CC();
            break;
        case ACTION_COMMAND_WHIRLWIND:
            func_802A92F0_423F60();
            break;
        case ACTION_COMMAND_STOP_LEECH:
            func_802A91F8_425788();
            break;
        case ACTION_COMMAND_07:
            func_802A9228_425D78();
            break;
        case ACTION_COMMAND_DIZZY_SHELL:
            func_802A928C_4263FC();
            break;
        case ACTION_COMMAND_FIRE_SHELL:
            func_802A9294_426C64();
            break;
        case ACTION_COMMAND_0A:
            func_802A928C_42763C();
            break;
        case ACTION_COMMAND_BOMB:
            func_802A928C_427CFC();
            break;
        case ACTION_COMMAND_BODY_SLAM:
            func_802A92D4_4285B4();
            break;
        case ACTION_COMMAND_AIR_LIFT:
            func_802A9278_428CE8();
            break;
        case ACTION_COMMAND_AIR_RAID:
            func_802A9294_4295B4();
            break;
        case ACTION_COMMAND_SQUIRT:
            func_802A9208_429F28();
            break;
        case ACTION_COMMAND_POWER_SHOCK:
            func_802A9310_42D220();
            break;
        case ACTION_COMMAND_MEGA_SHOCK:
            func_802A92A0_42DCB0();
            break;
        case ACTION_COMMAND_SMACK:
            func_802A9298_42E638();
            break;
        case ACTION_COMMAND_SPINY_SURGE:
            func_802A9254_42F074();
            break;
        case ACTION_COMMAND_HURRICANE:
            func_802A92A0_42F980();
            break;
        case ACTION_COMMAND_SPOOK:
            func_802A9298_4302B8();
            break;
        case ACTION_COMMAND_WATER_BLOCK:
            func_802A948C_42A97C();
            break;
        case ACTION_COMMAND_TIDAL_WAVE:
            action_command_tidal_wave_update();
            break;
        default:
            break;
    }
}

void func_80268AF8(void);
INCLUDE_ASM(s32, "196AA0", func_80268AF8);

INCLUDE_ASM(s32, "196AA0", func_80268C9C);

void func_80268E88(void) {
    ActionCommandStatus *actionCmdStatus = &gActionCommandStatus;
    actionCmdStatus->unk_00 = create_generic_entity_frontUI(func_80268938, func_80268AF8);
    actionCmdStatus->actionCommandID = 0;
}

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

void func_80269118(void) {
    PlayerData* playerData = &gPlayerData;
    ActionCommandStatus *actionCommandStatus = &gActionCommandStatus;

    if (!actionCommandStatus->autoSucceed) {
        if (playerData->otherHitsTaken < 9999) {
            playerData->otherHitsTaken++;
            actionCommandStatus->hitsTakenIsMax = FALSE;
        } else {
            actionCommandStatus->hitsTakenIsMax = TRUE;
        }
    }
}

void func_80269160(void) {
    PlayerData* playerData = &gPlayerData;

    if (!gActionCommandStatus.autoSucceed && gActionCommandStatus.hitsTakenIsMax) {
        playerData->unk_296++;
    }
}

ApiStatus func_8026919C(Evt* script, s32 isInitialCall) {
    gBattleStatus.unk_434 = (s32*) evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetupMashMeter(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    gActionCommandStatus.mashMeterIntervals = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[1] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[2] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[3] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[4] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[5] = evt_get_variable(script, *args++);
    gActionCommandStatus.mashMeterCutoffs[0] = gActionCommandStatus.mashMeterCutoffs[1] / 2;
    return ApiStatus_DONE2;
}

ApiStatus GetActionSuccess(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

ApiStatus SetActionSuccess(Evt* script, s32 isInitialCall) {
    gBattleStatus.actionSuccess = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetActionCommandMode(Evt* script, s32 isInitialCall) {
    gBattleStatus.unk_83 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus GetActionCommandMode(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.unk_83);
    return ApiStatus_DONE2;
}

ApiStatus func_80269344(Evt* script, s32 isInitialCall) {
    D_8029FC4C = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus GetCommandAutoSuccess(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gActionCommandStatus.autoSucceed);
    return ApiStatus_DONE2;
}

ApiStatus SetCommandAutoSuccess(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (evt_get_variable(script, *script->ptrReadPos) != 0) {
        actionCommandStatus->autoSucceed = TRUE;
    } else {
        actionCommandStatus->autoSucceed = FALSE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802693F0(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 &= ~0x4000;
    return ApiStatus_DONE2;
}

ApiStatus CloseActionCommandInfo(Evt* script, s32 isInitialCall) {
    ActionCommandStatus *actionCommandStatus = &gActionCommandStatus;

    if (isInitialCall) {
        switch (actionCommandStatus->actionCommandID) {
            case ACTION_COMMAND_WHIRLWIND:
            case ACTION_COMMAND_STOP_LEECH:
                return ApiStatus_DONE2;
            default:
                func_80268C9C();
                return ApiStatus_BLOCK;
        }
    }

    sfx_stop_sound(0x80000041);
    close_action_command_instruction_popup();

    return ApiStatus_DONE2;
}

ApiStatus func_80269470(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        func_80268C9C();
        return ApiStatus_BLOCK;
    }

    close_action_command_instruction_popup();
    return ApiStatus_DONE2;
}

ApiStatus func_802694A4(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (evt_get_variable(script, *script->ptrReadPos) == 0) {
        actionCommandStatus->unk_61 = FALSE;
    } else {
        actionCommandStatus->unk_61 = TRUE;
    }
    return ApiStatus_DONE2;
}

ApiStatus GetActionSuccessCopy(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

ApiStatus func_80269524(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.unk_86);
    return ApiStatus_DONE2;
}

ApiStatus func_80269550(Evt* script, s32 isInitialCall) {
    gBattleStatus.unk_86 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus GetBlockResult(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.blockResult);
    return ApiStatus_DONE2;
}

ApiStatus GetActionResult(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.unk_84);
    return ApiStatus_DONE2;
}

ApiStatus SetActionResult(Evt* script, s32 isInitialCall) {
    gBattleStatus.unk_84 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_80269600(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.unk_85);
    return ApiStatus_DONE2;
}

ApiStatus func_8026962C(Evt* script, s32 isInitialCall) {
    gBattleStatus.unk_85 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
