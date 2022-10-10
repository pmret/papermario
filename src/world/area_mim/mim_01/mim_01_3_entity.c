
#include "mim_01.h"
#include "entity.h"

EvtScript N(EVS_ReadSign) = {
    EVT_CALL(IsStartingConversation, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_017E, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), -300, 0, 0, 270, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign)))
    EVT_RETURN
    EVT_END
};
