#include "jan_05.h"

#include "world/common/HeartPlant_SpawnHeart.inc.c"

#include "world/common/enemy/FuzzyAI.inc.c"

#include "world/common/enemy/SpearGuyAI.inc.c"

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
