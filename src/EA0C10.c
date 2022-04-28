#include "dead.h"
#include "common.h"
#include "dead_structs.h"

// Copy of kzn_17 (C85DC0.c)

#define NAMESPACE EA0C10

const char ascii_EA6D70[] = "kzn_11";
const char ascii_EA6D78[] = "kzn_18";
extern s32 D_802466D0[];

void func_8004D8E0(DeadEnemy*);
void func_80240DC4_EA16C4(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory);

#include "world/common/enemy/WanderMeleeAI.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_00.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_01.inc.c"

// sqrtf issue - Would be PiranhaPlantAI_10
INCLUDE_ASM(s32, "EA0C10", func_80240DC4_EA16C4);

#include "world/common/enemy/state/PiranhaPlantAI_11.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_12.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_13.inc.c"

#include "world/common/enemy/state/PiranhaPlantAI_14.inc.c"

#include "world/common/enemy/Dead_PiranhaPlantAI_Main.inc.c"

#include "world/common/enemy/TackleAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_802429C0_EA32C0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        D_802441B8_EA4AB8 = FALSE;
    }

    if (D_802441B8_EA4AB8) {
        D_802441B8_EA4AB8 = FALSE;
        evt_set_variable(script, *args++, D_802441BC_EA4ABC);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EA0C10", func_802429C0_EA32C0);
#endif

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_80242A14_EA3314(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_802441BC_EA4ABC = dead_evt_get_variable(script, *args++);
    D_802441B8_EA4AB8 = TRUE;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EA0C10", func_80242A14_EA3314);
#endif

ApiStatus func_80242A4C_EA334C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802466D0[i] = ptr[i];
        }
        D_802466D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802466D0[i] = i + 16;
            D_802466D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/LetterDelivery.inc.c"
