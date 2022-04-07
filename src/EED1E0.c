#include "dead.h"
#include "common.h"

// Copy of flo_16 (CD1F10.c)

#define NAMESPACE EED1E0

#define gPartnerActionStatus dead_gPartnerActionStatus2

#include "world/common/SuperBlock_SetOverride40.inc.c"

#include "world/common/SuperBlock_ClearOverride40.inc.c"

ApiStatus func_8024011C_EED21C(Evt* script, s32 isInitialCall) {
    func_802F3B00(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "world/common/SuperBlock_GetPartnerRank.inc.c"

INCLUDE_ASM(s32, "EED1E0", func_802402AC_EED3AC);

#include "world/common/SuperBlock_SwitchToPartner.inc.c"

#include "world/common/SuperBlock_LoadCurrentPartnerName.inc.c"

#include "world/common/SuperBlock_StartGlowEffect.inc.c"

#include "world/common/SuperBlock_EndGlowEffect.inc.c"

#include "world/common/SuperBlock_GatherEnergyFX.inc.c"

#include "world/common/SuperBlock_RadiateFaintEnergyFX.inc.c"

#include "world/common/SuperBlock_AnimateEnergyOrbs.inc.c"

#include "world/common/SuperBlock_WhiteScreenFlash.inc.c"

#include "world/common/UnkPartnerPosFuncs.inc.c"

#include "world/common/SuperBlock_WaitForPlayerToLand.inc.c"

#include "world/common/UnkFunc44.inc.c"
