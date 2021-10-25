#include "dead.h"
#include "common.h"

#define NAMESPACE EED1E0

#define dead_gPartnerActionStatus dead_gPartnerActionStatus2

extern s32 D_80094900[11][4];

#include "world/common/SetOverrideFlags_40.inc.c"

#include "world/common/UnkFunc17.inc.c"

ApiStatus func_8024011C_EED21C(Evt* script, s32 isInitialCall) {
    func_802F3B00(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc18.inc.c"

INCLUDE_ASM(s32, "EED1E0", func_802402AC_EED3AC);

#include "world/common/SwitchToPartner.inc.c"

ApiStatus func_80240528_EED628(Evt* script, s32 isInitialCall) {
    set_message_msg(D_80094900[gPlayerData.currentPartner][0], 0);

    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc20.inc.c"

#include "world/common/UnkFunc39.inc.c"

#include "world/common/UnkFunc21.inc.c"

#include "world/common/UnkFunc22.inc.c"

INCLUDE_ASM(s32, "EED1E0", func_802406E0_EED7E0);

#include "world/common/UnkFunc23.inc.c"

#include "world/common/DeadUnkPartnerPosFuncs.inc.c"

#include "world/common/UnkFunc40.inc.c"

#include "world/common/UnkFunc44.inc.c"
