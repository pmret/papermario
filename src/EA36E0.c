#include "dead.h"
#include "common.h"

#define NAMESPACE EA36E0

// Copy of kzn_17 (C887B0.c)

#define UNK_FUNC_50_LVar1 -583.0
#define UNK_FUNC_50_LVar2 165.0

ApiStatus N(SpinyTrompHit)(Evt* script, s32 isInitialCall) {
    subtract_hp(1);
    return ApiStatus_DONE2;
}

ApiStatus N(GetActingPartner)(Evt* script, s32 isInitialCall) {
    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) {
        script->varTable[0] = gPartnerActionStatus.actingPartner;
    } else {
        script->varTable[0] = -1;
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc46.inc.c"

#include "world/common/todo/SpinyTromp_CheckDist.inc.c"

#include "world/common/todo/UnkFunc48.inc.c"

#include "world/common/todo/UnkFunc49.inc.c"

#include "world/common/todo/UnkFunc50.inc.c"

#include "world/common/todo/UnkFunc51.inc.c"
