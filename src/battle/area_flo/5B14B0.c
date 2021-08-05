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

    Bytecode* args = script->ptrReadPos;
    prevX = get_variable(script, *args++);
    prevZ = get_variable(script, *args++);
    length = get_variable(script, *args++);
    angle = get_variable(script, *args++);

    outX = prevX + (length * cos_deg(angle));
    outZ = prevZ - (length * sin_deg(angle));

    set_float_variable(script, *args++, outX);
    set_float_variable(script, *args++, outZ);
    return 2;
}