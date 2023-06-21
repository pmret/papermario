#include "common.h"
#include "world/area_kzn/kzn.h"
#include "sprite/player.h"

API_CALLABLE(N(SpinyTrompHit)) {
    subtract_hp(1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpinyTromp_GetActingPartner)) {
    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        script->varTable[0] = gPartnerStatus.actingPartner;
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

EvtScript N(D_80240D10_C7EE90) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(10)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(InterruptUsePartner)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(GetCurrentPartnerID, LVar0)
        EVT_IF_EQ(LVar0, PARTNER_BOW)
            EVT_GOTO(2)
        EVT_ELSE
            EVT_GOTO(10)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_IF_NE(LVar0, ACTION_STATE_IDLE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetPlayerTargetYaw, LVar0)
    EVT_IF_LT(LVar0, 180)
        EVT_CALL(InterpPlayerYaw, 90, 1)
        EVT_WAIT(1)
        EVT_CALL(N(UnkFunc48), 20)
    EVT_ELSE
        EVT_CALL(InterpPlayerYaw, 270, 1)
        EVT_WAIT(1)
        EVT_CALL(N(UnkFunc48), -20)
    EVT_END_IF
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Fallen)
    EVT_WAIT(1)
    EVT_CALL(N(SpinyTrompHit))
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Fallen, IMGFX_SET_WAVY, EVT_FLOAT(3.0), EVT_FLOAT(3.0), 0, 0)
    EVT_LABEL(1)
        EVT_WAIT(1)
        EVT_IF_EQ(AF_KZN_TrompRollingDone, FALSE)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Fallen, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_GetUp)
    EVT_CALL(N(UnkFunc48), 0)
    EVT_LABEL(2)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
