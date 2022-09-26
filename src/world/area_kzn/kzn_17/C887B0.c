#include "kzn_17.h"

#define UNK_FUNC_50_LVar1 -583.0
#define UNK_FUNC_50_LVar2 165.0

//func_80242D00_C887B0
ApiStatus N(SpinyTrompHit)(Evt* script, s32 isInitialCall) {
    subtract_hp(1);
    return ApiStatus_DONE2;
}

ApiStatus func_80242D20_C887D0(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) {
        script->varTable[0] = gPartnerActionStatus.actingPartner;
    } else {
        script->varTable[0] = -1;
    }
    return ApiStatus_DONE2;
}

#include "world/common/UnkFunc46.inc.c"

#include "world/common/UnkFunc47.inc.c"

#include "world/common/UnkFunc48.inc.c"

#include "world/common/UnkFunc49.inc.c"

#include "world/common/UnkFunc50.inc.c"

#include "world/common/UnkFunc51.inc.c"
