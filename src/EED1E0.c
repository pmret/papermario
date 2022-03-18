#include "dead.h"
#include "common.h"

// Copy of flo_16 (CD1F10.c)

#define NAMESPACE EED1E0

#define gPartnerActionStatus dead_gPartnerActionStatus2

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

ApiStatus func_8024011C_EED21C(Evt* script, s32 isInitialCall) {
    func_802F3B00(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc18.inc.c"

INCLUDE_ASM(s32, "EED1E0", func_802402AC_EED3AC);

#include "world/common/SwitchToPartner.inc.c"

#include "world/common/UnkFunc19.inc.c"

#include "world/common/UnkFunc20.inc.c"

#include "world/common/UnkFunc39.inc.c"

#include "world/common/UnkFunc21.inc.c"

#include "world/common/UnkFunc22.inc.c"

#include "world/common/UnkFunc60.inc.c"

#include "world/common/UnkFunc23.inc.c"

#include "world/common/UnkPartnerPosFuncs.inc.c"

#include "world/common/UnkFunc40.inc.c"

#include "world/common/UnkFunc44.inc.c"
