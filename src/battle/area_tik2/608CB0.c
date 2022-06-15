#include "common.h"

#define NAMESPACE b_area_tik2

#define NAMESPACE dup_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

INCLUDE_ASM(s32, "battle/area_tik2/608CB0", func_80218258_608D08);

#include "common/FadeBackgroundToBlack.inc.c"

#include "common/UnfadeBackgroundToBlack.inc.c"

INCLUDE_ASM(s32, "battle/area_tik2/608CB0", func_80218404_608EB4);

#define NAMESPACE dup_b_area_tik2
#include "common/UnkWaterFountainFunc.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup2_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

#ifdef NON_MATCHING // regalloc
ApiStatus func_802186D8_609188(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;

    evt_set_float_variable(script, arg0, evt_get_float_variable(script, *args++) * sin_rad(evt_get_float_variable(script, arg0) * TAU / 360.0f));

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/area_tik2/608CB0", func_802186D8_609188)
#endif

#define NAMESPACE dup_b_area_tik2
#include "common/FadeBackgroundToBlack.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup_b_area_tik2
#include "common/UnfadeBackgroundToBlack.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup2_b_area_tik2
#include "common/UnkWaterFountainFunc.inc.c"
#define NAMESPACE b_area_tik2

#define NAMESPACE dup3_b_area_tik2
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_tik2

#include "common/UnkBattleFunc2.inc.c"

#include "world/common/UnkFunc56.inc.c"
