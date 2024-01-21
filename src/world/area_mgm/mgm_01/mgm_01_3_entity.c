#include "mgm_01.h"
#include "entity.h"

EvtScript N(EVS_ReadSign_HowToPlay) = {
    Call(DisablePlayerInput, TRUE)
    Call(N(SetMsgImgs_Panels))
    Call(ShowMessageAtScreenPos, MSG_MGM_003B, 160, 40)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Signpost), -55, -2, -80, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign_HowToPlay)))
    Return
    End
};
