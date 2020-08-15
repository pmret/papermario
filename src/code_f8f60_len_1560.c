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

    s32 maxVar = get_variable(script, *ptrReadPos++);
    bytecode outVar = *ptrReadPos++;

    set_variable(script, outVar, rand_int(maxVar));

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

INCLUDE_ASM(code_f8f60_len_1560, GetAngleToNPC);

INCLUDE_ASM(code_f8f60_len_1560, GetAngleToPlayer);

INCLUDE_ASM(code_f8f60_len_1560, AwaitPlayerApproach);

INCLUDE_ASM(code_f8f60_len_1560, IsPlayerWithin);

INCLUDE_ASM(code_f8f60_len_1560, AwaitPlayerLeave);

INCLUDE_ASM(code_f8f60_len_1560, AddVectorPolar);

INCLUDE_ASM(code_f8f60_len_1560, setup_path_data);

INCLUDE_ASM(code_f8f60_len_1560, func_802D5270);

INCLUDE_ASM(code_f8f60_len_1560, LoadPath);

INCLUDE_ASM(code_f8f60_len_1560, GetNextPathPos);

INCLUDE_ASM(code_f8f60_len_1560, GetDist2D);

INCLUDE_ASM(code_f8f60_len_1560, SetValueByRef);

INCLUDE_ASM(code_f8f60_len_1560, GetValueByRef);

INCLUDE_ASM(code_f8f60_len_1560, EnableStatusMenu);

INCLUDE_ASM(code_f8f60_len_1560, ShowStatusMenu);

INCLUDE_ASM(code_f8f60_len_1560, SetGameMode);

INCLUDE_ASM(code_f8f60_len_1560, ClampAngleInt);

INCLUDE_ASM(code_f8f60_len_1560, ClampAngleFloat);
