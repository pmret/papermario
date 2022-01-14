#include "common.h"
#include "npc.h"

extern s32 gPartnerPopupProperties[11][4];

ApiStatus N(UnkFunc19)(Evt* script, s32 isInitialCall) {
    set_message_msg(gPartnerPopupProperties[gPlayerData.currentPartner][0], 0);

    return ApiStatus_DONE2;
}
