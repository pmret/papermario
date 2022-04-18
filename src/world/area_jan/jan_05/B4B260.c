#include "jan_05.h"

INCLUDE_ASM(s32, "world/area_jan/jan_05/B4B260", func_802407F0_B4B260);

#include "world/common/atomic/enemy/UnkAI_2.inc.c"

#include "world/common/atomic/enemy/SpearGuy.inc.c"

#define NAMESPACE dup_jan_05
#include "common/foliage.inc.c"
#define NAMESPACE jan_05

ApiStatus func_8024268C_B4D0FC(Evt* script) {
    if (get_enemy_safe(0) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
