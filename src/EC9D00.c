#include "dead.h"
#include "common.h"

// Copy of flo_08 (CAED40.c)

#define NAMESPACE EC9D00

#define gPartnerActionStatus dead_gPartnerActionStatus2

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

ApiStatus func_8024003C_EC9D3C(Evt* script, s32 isInitialCall) {
    func_802F3B00(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc18.inc.c"

INCLUDE_ASM(s32, "EC9D00", func_802401CC_EC9ECC);

#include "world/common/SwitchToPartner.inc.c"

#include "world/common/UnkFunc19.inc.c"

#include "world/common/UnkFunc20.inc.c"

#include "world/common/UnkFunc39.inc.c"

#include "world/common/UnkFunc21.inc.c"

#include "world/common/UnkFunc22.inc.c"

INCLUDE_ASM(s32, "EC9D00", func_80240600_ECA300);

#include "world/common/UnkFunc23.inc.c"

#include "world/common/UnkPartnerPosFuncs.inc.c"

#include "world/common/UnkFunc40.inc.c"
