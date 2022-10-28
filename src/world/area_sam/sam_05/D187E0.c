#include "sam_05.h"

static char* N(exit_str_0) = "sam_04";
static char* N(exit_str_1) = "sam_06";

#include "world/common/enemy/ai/PiranhaPlantAI.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_05/D187E0", func_802419A4_D1A184);

ApiStatus func_80241D20_D1A500(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
