#include "dead.h"
#include "common.h"

#define NAMESPACE EC9D00

extern s32 D_80094900[11][4];

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

ApiStatus func_8024003C_EC9D3C(Evt* script, s32 isInitialCall) {
    func_802F3B00(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc18.inc.c"

INCLUDE_ASM(s32, "EC9D00", func_802401CC_EC9ECC);

#include "world/common/SwitchToPartner.inc.c"

ApiStatus func_80240448_ECA148(Evt* script, s32 isInitialCall) {
    set_message_msg(D_80094900[gPlayerData.currentPartner][0], 0);

    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc20.inc.c"

#include "world/common/UnkFunc39.inc.c"

#include "world/common/UnkFunc21.inc.c"

#include "world/common/UnkFunc22.inc.c"

INCLUDE_ASM(s32, "EC9D00", func_80240600_ECA300);

#include "world/common/UnkFunc23.inc.c"

#include "world/common/DeadUnkPartnerPosFuncs.inc.c"

// Cannot common include this due to duplicate dead symbols both referencing gPlayerActionStatus
// dead.h would simply create a misdefine if we were to use the include, so we have to copy-paste for now
ApiStatus N(UnkFunc40)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if (dead_gPartnerActionStatus2.actionState.b[0] != 0 && dead_gPartnerActionStatus2.actionState.b[3] == 3) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
