#include "common.h"

static ApiStatus PartnerSuspendAbilityScript(ScriptInstance* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PartnerId_NONE) {
        return ApiStatus_DONE2;
    }
    partner_suspend_ability_script();
    return ApiStatus_DONE2;
}

static ApiStatus PartnerResumeAbilityScript(ScriptInstance* script, s32 isInitialCall) {
    partner_resume_ability_script();
    return ApiStatus_DONE2;
}
