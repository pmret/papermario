#include "jan_05.h"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_802407F0_B4B260);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_802408A4_B4B314);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80240AD4_B4B544);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80240ECC_B4B93C);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241070_B4BAE0);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241150_B4BBC0);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241494_B4BF04);

#include "world/common/UnkNpcAIFunc4.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241708_B4C178);

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241AD4_B4C544);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241C88_B4C6F8);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241EE8_B4C958);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_8024219C_B4CC0C);

#define MAP_NAME dup_jan_05
#include "world/common/SomeMatrixOperations.inc.c"
#define MAP_NAME jan_05

ApiStatus func_8024268C_B4D0FC(ScriptInstance* script) {
    if (get_enemy_safe(0) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
