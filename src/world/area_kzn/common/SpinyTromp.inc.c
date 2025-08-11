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
    Call(DisablePlayerInput, true)
    Label(10)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, 0)
        Call(InterruptUsePartner)
    EndIf
    Label(0)
    Wait(1)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, 0)
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_BOW)
            Goto(2)
        Else
            Goto(10)
        EndIf
    EndIf
    Call(GetPlayerActionState, LVar0)
    IfNe(LVar0, ACTION_STATE_IDLE)
        Goto(0)
    EndIf
    Call(GetPlayerTargetYaw, LVar0)
    IfLt(LVar0, 180)
        Call(InterpPlayerYaw, 90, 1)
        Wait(1)
        Call(N(UnkFunc48), 20)
    Else
        Call(InterpPlayerYaw, 270, 1)
        Wait(1)
        Call(N(UnkFunc48), -20)
    EndIf
    Call(SetPlayerAnimation, ANIM_Mario1_Fallen)
    Wait(1)
    Call(N(SpinyTrompHit))
    Call(UpdatePlayerImgFX, ANIM_Mario1_Fallen, IMGFX_SET_WAVY, Float(3.0), Float(3.0), 0, 0)
    Label(1)
        Wait(1)
        IfEq(AF_KZN_TrompRollingDone, false)
            Goto(1)
        EndIf
    Wait(30)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Fallen, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerAnimation, ANIM_Mario1_GetUp)
    Call(N(UnkFunc48), 0)
    Label(2)
    Call(DisablePlayerInput, false)
    Return
    End
};
