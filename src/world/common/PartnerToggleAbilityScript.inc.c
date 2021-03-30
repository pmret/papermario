#include "common.h"
#include "../partners.h"
#include "map.h"

ApiStatus N(PartnerSuspendAbilityScript)(ScriptInstance* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == NO_PARTNER) {
        return ApiStatus_DONE2;
    }
    partner_suspend_ability_script();
    return ApiStatus_DONE2;
}

ApiStatus N(PartnerResumeAbilityScript)(ScriptInstance* script, s32 isInitialCall) {
    partner_resume_ability_script();
    return ApiStatus_DONE2;
}
