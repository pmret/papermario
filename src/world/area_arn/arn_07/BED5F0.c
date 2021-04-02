#include "arn_07.h"

s32 N(func_80240800_BED5F0)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *shape) {
    f32 temp_f0 = get_float_variable(script, 0xFE363C80);

    if (temp_f0 >= 360.0) {
        temp_f0 -= 360.0;
    }
    set_float_variable(script, 0xFE363C80, temp_f0);
    return ApiStatus_DONE2;
}
