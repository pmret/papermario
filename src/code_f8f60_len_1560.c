#include "common.h"

ApiStatus MakeLerp(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    script->varTable[0xC] = get_variable(script, *ptrReadPos++); // start
    script->varTable[0xD] = get_variable(script, *ptrReadPos++); // end
    script->varTable[0xF] = get_variable(script, *ptrReadPos++); // duration
    script->varTable[0xB] = get_variable(script, *ptrReadPos++); // easing type
    script->varTable[0xE] = 0; // elapsed

    return ApiStatus_DONE2;
}

ApiStatus UpdateLerp(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0x0] = (s32) update_lerp(
        script->varTable[0xB],
        script->varTable[0xC],
        script->varTable[0xD],
        script->varTable[0xE],
        script->varTable[0xF]
    );

    if (script->varTable[0xE] >= script->varTable[0xF]) {
        script->varTable[0x1] = 0; // finished
    } else {
        script->varTable[0x1] = 1; // lerping
    }
    script->varTable[0xE]++;

    return ApiStatus_DONE2;
}

ApiStatus RandInt(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    s32 max = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;

    set_variable(script, outVar, rand_int(max));

    return ApiStatus_DONE2;
}

ApiStatus GetAngleBetweenNPCs(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    NpcId aID = get_variable(script, *ptrReadPos++);
    NpcId bID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;

    Npc* a = resolve_npc(script, aID);
    Npc* b = resolve_npc(script, bID);
    set_variable(script, outVar, atan2(a->pos.x, a->pos.z, b->pos.x, b->pos.z));

    return ApiStatus_DONE2;
}

ApiStatus GetAngleToNPC(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* ptrReadPos = script->ptrReadPos;

    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;

    Npc* npc = resolve_npc(script, npcID);
    set_variable(script, outVar, atan2(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z));

    return ApiStatus_DONE2;
}

ApiStatus GetAngleToPlayer(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* ptrReadPos = script->ptrReadPos;

    NpcId npcID = get_variable(script, *ptrReadPos++);
    Bytecode outVar = *ptrReadPos++;

    Npc* npc = resolve_npc(script, npcID);
    set_variable(script, outVar, atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z));

    return ApiStatus_DONE2;
}

ApiStatus AwaitPlayerApproach(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;

    if (isInitialCall) {
        *targetX = get_variable(script, *ptrReadPos++);
        *targetZ = get_variable(script, *ptrReadPos++);
        *distanceRequired = get_variable(script, *ptrReadPos++);
    }

    distance = dist2D(
        playerStatus->position.x, playerStatus->position.z,
        *targetX, *targetZ
    );

    if (distance < *distanceRequired) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus IsPlayerWithin(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;
    Bytecode outVar = SI_VAR_0;

    if (isInitialCall) {
        *targetX = get_variable(script, *ptrReadPos++);
        *targetZ = get_variable(script, *ptrReadPos++);
        *distanceRequired = get_variable(script, *ptrReadPos++);
        outVar = *ptrReadPos++;
    }

    distance = dist2D(
        playerStatus->position.x, playerStatus->position.z,
        *targetX, *targetZ
    );

    set_variable(script, outVar, 0);
    if (distance < *distanceRequired) {
        set_variable(script, outVar, 1);
    }

    return ApiStatus_DONE2;
}

ApiStatus AwaitPlayerLeave(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    PlayerStatus* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;

    if (isInitialCall) {
        *targetX = get_variable(script, *ptrReadPos++);
        *targetZ = get_variable(script, *ptrReadPos++);
        *distanceRequired = get_variable(script, *ptrReadPos++);
    }

    distance = dist2D(
        playerStatus->position.x, playerStatus->position.z,
        *targetX, *targetZ
    );

    if (distance > *distanceRequired) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus AddVectorPolar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    Bytecode xVar = *ptrReadPos++;
    f32 x = get_float_variable(script, xVar);

    Bytecode yVar = *ptrReadPos++;
    f32 y = get_float_variable(script, yVar);

    f32 r = get_float_variable(script, *ptrReadPos++);

    add_vec2D_polar(&x, &y, r, get_float_variable(script, *ptrReadPos++));

    set_float_variable(script, xVar, x);
    set_float_variable(script, yVar, y);

    return ApiStatus_DONE2;
}

INCLUDE_API_ASM(code_f8f60_len_1560, func_802D4BDC);
/*
ApiStatus func_802D4BDC(ScriptInstance* script, s32 initialCall) {
    s32* t0 = &script->functionTemp[0];
    s32* t1 = &script->functionTemp[1];
    s32 t1v;

    if (initialCall) {
        *t0 = 0;
        *t1 = 0;
    }

    if (*t0 == 0) {
        t1v = *t1;
        if (t1v != 0xFF) {
            t1v += 0xA;
            *t1 = t1v;
            if (t1v < 0x100) {
                // Void, debug stuff was probably here
            }
            t1v = 0xFF;
            func_80137DA4(0xA, (f32) *t1);
        } else {
            return ApiStatus_DONE2;
        }
    }

    return 0;
}
*/

// Very similar to func_802D4BDC
INCLUDE_API_ASM(code_f8f60_len_1560, func_802D4C4C);

INCLUDE_API_ASM(code_f8f60_len_1560, func_802D4CC4);
/*
ApiStatus func_802D4CC4(ScriptInstance* script, s32 initialCall) {
    s32 value = get_variable(script, *script->ptrReadPos);
    if (value < 0) {
        func_80137DA4(0xFF, -1.0f);
    } else {
        func_80137DA4(0xA, value);
    }

    return ApiStatus_DONE2;
}
*/

ApiStatus func_802D4D18(ScriptInstance* script, s32 initialCall) {
    s32 value = get_float_variable(script, *script->ptrReadPos);

    func_80137E4C(0, 0, 0xC, 0x14);
    func_80137E4C(0, 1, 0x134, 0xDC);
    func_80137D88(0xC, value);

    return ApiStatus_DONE2;
}

ApiStatus func_802D4D88(ScriptInstance* script, s32 initialCall) {
    func_80137D88(0xC, 0);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(code_f8f60_len_1560, setup_path_data);

INCLUDE_ASM(code_f8f60_len_1560, func_802D5270);

INCLUDE_API_ASM(code_f8f60_len_1560, LoadPath);

INCLUDE_API_ASM(code_f8f60_len_1560, GetNextPathPos);

ApiStatus GetDist2D(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    Bytecode outVar = *ptrReadPos++;
    set_float_variable(script, outVar, dist2D(
        get_float_variable(script, *ptrReadPos++),
        get_float_variable(script, *ptrReadPos++),
        get_float_variable(script, *ptrReadPos++),
        get_float_variable(script, *ptrReadPos++)
    ));

    return ApiStatus_DONE2;
}

ApiStatus func_802D5830(ScriptInstance* script, s32 initialCall) {
    func_80027088(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_802D585C(ScriptInstance* script, s32 initialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;
    s32 setMode = get_variable(script,  *ptrReadPos++);
    s32 flags = get_variable(script, *ptrReadPos++);

    if (setMode) {
        // Set flag
        D_8009A650[0] |= flags;
    } else {
        // Unset flag
        D_8009A650[0] &= ~flags;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetValueByRef(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    s32 dest = get_variable(script, *ptrReadPos++); /* Reference */
    s32 src = get_variable(script, *ptrReadPos++);
    set_variable(script, dest, src);

    return ApiStatus_DONE2;
}

ApiStatus GetValueByRef(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    s32 src = get_variable(script, *ptrReadPos++); /* Reference */
    Bytecode dest = *ptrReadPos++;

    set_variable(script, dest, get_variable(script, src));

    return ApiStatus_DONE2;
}

ApiStatus EnableStatusMenu(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        decrement_status_menu_disabled();
    } else {
        increment_status_menu_disabled();
    }

    return ApiStatus_DONE2;
}

ApiStatus ShowStatusMenu(ScriptInstance* script, s32 isInitialCall) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        status_menu_enable_ignore_changes();
        func_800E97B8();
    } else {
        status_menu_disable_ignore_changes();
    }

    return ApiStatus_DONE2;
}

ApiStatus SetGameMode(ScriptInstance* script, s32 isInitialCall) {
    set_game_mode(
        // Clear upper half
        (get_variable(script, *script->ptrReadPos) << 0x10) >> 0x10
    );
    return ApiStatus_DONE2;
}

ApiStatus ClampAngleInt(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    set_variable(script, *ptrReadPos, clamp_angle(get_variable(script, *ptrReadPos)));

    return ApiStatus_DONE2;
}

ApiStatus ClampAngleFloat(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* ptrReadPos = script->ptrReadPos;

    set_float_variable(script, *ptrReadPos, clamp_angle(get_float_variable(script, *ptrReadPos)));

    return ApiStatus_DONE2;
}
