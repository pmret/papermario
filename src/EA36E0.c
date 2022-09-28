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
    if (gPartnerActionStatus.partnerActionState != 0) {
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
