#include "common.h"

s32 MakeLerp(script_context* script, s32 initialCall) {
    s32* ptrReadPos = script->ptrReadPos;
    s32* ptrNextPos = *ptrReadPos++;
    s32* ptrNextPos2;
    s32* ptrNextPos3;
    s32* ptrNextPos4;

    script->varTable[12] = get_variable(script, ptrNextPos);
    ptrNextPos2 = *ptrReadPos++;
    script->varTable[13] = get_variable(script, ptrNextPos2);
    ptrNextPos3 = *ptrReadPos++;
    script->varTable[15] = get_variable(script, ptrNextPos3);
    ptrNextPos4 = *ptrReadPos++;
    script->varTable[11] = get_variable(script, ptrNextPos4);
    script->varTable[14] = 0;
    return 2;
}

INCLUDE_ASM(code_f8f60_len_1560, UpdateLerp);

INCLUDE_ASM(code_f8f60_len_1560, RandInt);

INCLUDE_ASM(code_f8f60_len_1560, GetAngleBetweenNPCs);

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
