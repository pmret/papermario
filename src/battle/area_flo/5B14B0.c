#include "common.h"

#define NAMESPACE b_area_flo

#include "common/UnkBattleFunc1.inc.c"

ApiStatus func_802180CC_5B157C(ScriptInstance* script, s32 isInitialCall) {
    s32 angle;
    f32 outX;
    f32 outZ;
    s32 length;
    s32 prevX;
    s32 prevZ;

    s32* ptrReadPos = script->ptrReadPos;
    prevX = get_variable(script, *ptrReadPos++);
    prevZ = get_variable(script, *ptrReadPos++);
    length = get_variable(script, *ptrReadPos++);
    angle = get_variable(script, *ptrReadPos++);

    outX = prevX + (length * cos_deg(angle));
    outZ = prevZ - (length * sin_deg(angle));

    set_float_variable(script, *ptrReadPos++, outX);
    set_float_variable(script, *ptrReadPos++, outZ);
    return 2;
}