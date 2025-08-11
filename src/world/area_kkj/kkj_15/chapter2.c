#include "kkj_15.h"

EvtScript N(EVS_ExtiDoor_Chapter2) = {
    IfEq(AF_KKJ_06, false)
        Call(DisablePlayerInput, true)
        Call(DisablePartnerAI, 1)
        Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_006B)
        Call(EnablePartnerAI)
        Call(DisablePlayerInput, false)
    EndIf
    Set(LVar0, kkj_15_ENTRY_0)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_o2)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    IfEq(AF_KKJ_06, false)
        Call(GotoMap, Ref("kkj_11"), kkj_11_ENTRY_7)
    Else
        Call(GotoMap, Ref("kkj_11"), kkj_11_ENTRY_3)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_SetupChapter2) = {
    BindTrigger(Ref(N(EVS_ExtiDoor_Chapter2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};
