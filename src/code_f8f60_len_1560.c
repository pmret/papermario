#include "common.h"

s32 MakeLerp(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;

    script->varTable[0xC] = get_variable(script, *ptrReadPos++); // start
    script->varTable[0xD] = get_variable(script, *ptrReadPos++); // end
    script->varTable[0xF] = get_variable(script, *ptrReadPos++); // duration
    script->varTable[0xB] = get_variable(script, *ptrReadPos++); // easing type
    script->varTable[0xE] = 0; // elapsed

    return 2;
}

s32 UpdateLerp(script_context* script, s32 initialCall) {
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

    return 2;
}

s32 RandInt(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    s32 max = get_variable(script, *ptrReadPos++);
    bytecode outVar = *ptrReadPos++;

    set_variable(script, outVar, rand_int(max));

    return 2;
}

s32 GetAngleBetweenNPCs(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    NPC aID = get_variable(script, *ptrReadPos++);
    NPC bID = get_variable(script, *ptrReadPos++);
    bytecode outVar = *ptrReadPos++;

    npc* a = resolve_npc(script, aID);
    npc* b = resolve_npc(script, bID);
    set_variable(script, outVar, atan2(a->pos.x, a->pos.z, b->pos.x, b->pos.z));

    return 2;
}

s32 GetAngleToNPC(script_context* script, s32 initialCall) {
    player_status* playerStatus = &gPlayerStatus;
    bytecode* ptrReadPos = script->ptrReadPos;

    NPC npcID = get_variable(script, *ptrReadPos++);
    bytecode outVar = *ptrReadPos++;

    npc* npc = resolve_npc(script, npcID);
    set_variable(script, outVar, atan2(playerStatus->position.x, playerStatus->position.z, npc->pos.x, npc->pos.z));

    return 2;
}

s32 GetAngleToPlayer(script_context* script, s32 initialCall) {
    player_status* playerStatus = &gPlayerStatus;
    bytecode* ptrReadPos = script->ptrReadPos;

    NPC npcID = get_variable(script, *ptrReadPos++);
    bytecode outVar = *ptrReadPos++;

    npc* npc = resolve_npc(script, npcID);
    set_variable(script, outVar, atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z));

    return 2;
}

s32 AwaitPlayerApproach(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;
    player_status* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;

    if (initialCall) {
        *targetX = get_variable(script, *ptrReadPos++);
        *targetZ = get_variable(script, *ptrReadPos++);
        *distanceRequired = get_variable(script, *ptrReadPos++);
    }

    distance = dist2D(
        playerStatus->position.x, playerStatus->position.z,
        *targetX, *targetZ
    );

    if (distance < *distanceRequired) {
        return 2;
    } else {
        return 0;
    }
}

s32 IsPlayerWithin(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;
    player_status* playerStatus = &gPlayerStatus;

    /* Function temporaries are redundant, stack should be used instead */
    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;
    bytecode outVar = SI_VAR_0; /* Redundant */

    if (initialCall) { /* Redundant condition, function always returns DONE */
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

    return 2;
}

s32 AwaitPlayerLeave(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;
    player_status* playerStatus = &gPlayerStatus;

    s32* targetX = &script->functionTemp[0];
    s32* targetZ = &script->functionTemp[1];
    s32* distanceRequired = &script->functionTemp[2];

    f32 distance;

    if (initialCall) {
        *targetX = get_variable(script, *ptrReadPos++);
        *targetZ = get_variable(script, *ptrReadPos++);
        *distanceRequired = get_variable(script, *ptrReadPos++);
    }

    distance = dist2D(
        playerStatus->position.x, playerStatus->position.z,
        *targetX, *targetZ
    );

    if (distance > *distanceRequired) {
        return 2;
    } else {
        return 0;
    }
}

s32 AddVectorPolar(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    bytecode xVar = *ptrReadPos++;
    f32 x = get_float_variable(script, xVar);

    bytecode yVar = *ptrReadPos++;
    f32 y = get_float_variable(script, yVar);

    f32 r = get_float_variable(script, *ptrReadPos++);

    add_vec2D_polar(&x, &y, r, get_float_variable(script, *ptrReadPos++));

    set_float_variable(script, xVar, x);
    set_float_variable(script, yVar, y);

    return 2;
}

INCLUDE_ASM(code_f8f60_len_1560, func_802D4BDC);
/*
s32 func_802D4BDC(script_context* script, s32 initialCall) {
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
            return 2;
        }
    }

    return 0;
}
*/

// Very similar to func_802D4BDC
INCLUDE_ASM(code_f8f60_len_1560, func_802D4C4C);

INCLUDE_ASM(code_f8f60_len_1560, func_802D4CC4);
/*
s32 func_802D4CC4(script_context* script, s32 initialCall) {
    s32 value = get_variable(script, *script->ptrReadPos);
    if (value < 0) {
        func_80137DA4(0xFF, D_BF800000);
    } else {
        func_80137DA4(0xA, value);
    }

    return 2;
}
*/

s32 func_802D4D18(script_context* script, s32 initialCall) {
    s32 value = get_float_variable(script, *script->ptrReadPos);

    func_80137E4C(0, 0, 0xC, 0x14);
    func_80137E4C(0, 1, 0x134, 0xDC);
    func_80137D88(0xC, value);

    return 2;
}

s32 func_802D4D88(script_context* script, s32 initialCall) {
    func_80137D88(0xC, 0);
    return 2;
}

INCLUDE_ASM(code_f8f60_len_1560, setup_path_data);

INCLUDE_ASM(code_f8f60_len_1560, func_802D5270);

INCLUDE_ASM(code_f8f60_len_1560, LoadPath);

INCLUDE_ASM(code_f8f60_len_1560, GetNextPathPos);

s32 GetDist2D(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    bytecode outVar = *ptrReadPos++;
    set_float_variable(script, outVar, dist2D(
        get_float_variable(script, *ptrReadPos++),
        get_float_variable(script, *ptrReadPos++),
        get_float_variable(script, *ptrReadPos++),
        get_float_variable(script, *ptrReadPos++)
    ));

    return 2;
}

s32 func_802D5830(script_context* script, s32 initialCall) {
    func_80027088(get_variable(script, *script->ptrReadPos));
    return 2;
}

s32 func_802D585C(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;
    s32 setMode = get_variable(script,  *ptrReadPos++);
    s32 flags = get_variable(script, *ptrReadPos++);

    if (setMode) {
        // Set flag
        D_8009A650[0] |= flags;
    } else {
        // Unset flag
        D_8009A650[0] &= ~flags;
    }

    return 2;
}

s32 SetValueByRef(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    s32 dest = get_variable(script, *ptrReadPos++); /* Reference */
    s32 src = get_variable(script, *ptrReadPos++);
    set_variable(script, dest, src);

    return 2;
}

s32 GetValueByRef(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    s32 src = get_variable(script, *ptrReadPos++); /* Reference */
    bytecode dest = *ptrReadPos++;

    set_variable(script, dest, get_variable(script, src));

    return 2;
}

s32 EnableStatusMenu(script_context* script, s32 initialCall) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        decrement_status_menu_disabled();
    } else {
        increment_status_menu_disabled();
    }

    return 2;
}

s32 ShowStatusMenu(script_context* script, s32 initialCall) {
    if (get_variable(script, *script->ptrReadPos) != 0) {
        status_menu_enable_ignore_changes();
        func_800E97B8();
    } else {
        status_menu_disable_ignore_changes();
    }

    return 2;
}

s32 SetGameMode(script_context* script, s32 initialCall) {
    set_game_mode(
        // Clear upper half
        (get_variable(script, *script->ptrReadPos) << 0x10) >> 0x10
    );
    return 2;
}

s32 ClampAngleInt(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    set_variable(script, *ptrReadPos, clamp_angle(get_variable(script, *ptrReadPos)));

    return 2;
}

s32 ClampAngleFloat(script_context* script, s32 initialCall) {
    bytecode* ptrReadPos = script->ptrReadPos;

    set_float_variable(script, *ptrReadPos, clamp_angle(get_float_variable(script, *ptrReadPos)));

    return 2;
}