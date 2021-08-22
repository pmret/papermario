#include "jan_05.h"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_802407F0_B4B260);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_802408A4_B4B314);

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80240AD4_B4B544);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80240ECC_B4B93C);

#include "world/common/UnkNpcAIFunc15.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241150_B4BBC0);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_80241494_B4BF04);

#include "world/common/UnkNpcAIFunc4.inc.c"

#include "world/common/UnkNpcAIFunc29.inc.c"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

#include "world/common/UnkNpcAIFunc27.inc.c"

#include "world/common/UnkNpcAIFunc28.inc.c"

#define NAMESPACE dup_jan_05
#include "world/common/foliage.inc.c"
#define NAMESPACE jan_05

ApiStatus func_8024268C_B4D0FC(Evt* script) {
    if (get_enemy_safe(0) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
