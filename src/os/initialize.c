#include "ultra64.h"
#include "include_asm.h"

INCLUDE_ASM(s32, "os/initialize", __createSpeedParam)

INCLUDE_ASM(void, "os/initialize", __osInitialize_common, void);

void __osInitialize_autodetect(void) {
}
