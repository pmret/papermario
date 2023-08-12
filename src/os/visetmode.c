#include "PR/viint.h"
#include "macros.h"

#if VERSION_IQUE
INCLUDE_ASM(void, "os/visetmode", osViSetMode, OSViMode *modep);
#else
void osViSetMode(OSViMode *modep) {
    register u32 saveMask = __osDisableInt();

    __osViNext->modep = modep;
    __osViNext->state = VI_STATE_MODE_UPDATED;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    __osRestoreInt(saveMask);
}
#endif
