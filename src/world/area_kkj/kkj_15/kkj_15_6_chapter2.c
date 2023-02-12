#include "kkj_15.h"

EvtScript N(EVS_ExtiDoor_Chapter2) = {
    EVT_IF_EQ(AF_KKJ_06, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(DisablePartnerAI, 1)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_006B)
        EVT_CALL(EnablePartnerAI)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_SET(LVar0, kkj_15_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_tte)
    EVT_SET(LVar2, MODEL_o2)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_IF_EQ(AF_KKJ_06, FALSE)
        EVT_CALL(GotoMap, EVT_PTR("kkj_11"), kkj_11_ENTRY_7)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("kkj_11"), kkj_11_ENTRY_3)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupChapter2) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExtiDoor_Chapter2)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    EVT_RETURN
    EVT_END
};
