#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PR/rcp.h"
#include "PR/viint.h"

extern u32 __osBbIsBb;

void osViSetMode(OSViMode* modep) {
    register u32 saveMask;

    saveMask = __osDisableInt();

#ifdef BBPLAYER
    if (__osBbIsBb) {
        modep->comRegs.ctrl &= ~VI_CTRL_PIXEL_ADV_2;
    }
#endif

    __osViNext->modep = modep;
    __osViNext->state = VI_STATE_MODE_UPDATED;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    __osRestoreInt(saveMask);
}
