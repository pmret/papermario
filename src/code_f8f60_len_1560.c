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

INCLUDE_ASM(code_f8f60_len_1560, AddVectorPolar);

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

INCLUDE_ASM(code_f8f60_len_1560, func_802D5830);

INCLUDE_ASM(code_f8f60_len_1560, func_802D585C);

INCLUDE_ASM(code_f8f60_len_1560, SetValueByRef);

INCLUDE_ASM(code_f8f60_len_1560, GetValueByRef);

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

INCLUDE_ASM(code_f8f60_len_1560, SetGameMode);

INCLUDE_ASM(code_f8f60_len_1560, ClampAngleInt);

INCLUDE_ASM(code_f8f60_len_1560, ClampAngleFloat);
