#include "ultra64.h"
#include "macros.h"
#include "PR/os_reg.h"

#if VERSION_IQUE
INCLUDE_ASM(u32, "os/_getcount", osGetCount, void);
#endif
