#include "mim_07.h"
#include "entity.h"

EvtScript N(EVS_ReadSign) = {
    Call(IsStartingConversation, LVar0)
    IfEq(LVar0, TRUE)
        Return
    EndIf
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(DisablePlayerInput, TRUE)
    Call(ShowMessageAtScreenPos, MSG_Menus_017F, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Signpost), 280, 0, 0, 90, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign)))
    Return
    End
};
