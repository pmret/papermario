#include "mac_00.h"

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

static char* N(exit_str_0) = "mac_01";

#define NAMESPACE dup_mac_00
#include "world/common/todo/StashVars.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/todo/GetItemName.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/todo/GetNpcCollisionHeight.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/todo/AddPlayerHandsOffset.inc.c"
#define NAMESPACE mac_00

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243744_7EE454);

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243798_7EE4A8);

extern s32 D_80255EE0[];

ApiStatus func_802437D0_7EE4E0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80255EE0[i] = ptr[i];
        }
        D_80255EE0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80255EE0[i] = i + 16;
            D_80255EE0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_mac_00
extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"
#define NAMESPACE mac_00
