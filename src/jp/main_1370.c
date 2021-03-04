#include "common.h"

extern s32* D_80073DE0;

INCLUDE_ASM(s32, "main_1370", func_80025F70);

INCLUDE_ASM(s32, "main_1370", func_80026148);

void gfxPreNMI_Callback(void) {
    D_80073DE0 = 1;
    nuContRmbForceStop();
}
