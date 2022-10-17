#include "mgm_01.h"
#include "entity.h"

EvtScript N(EVS_ReadSign_HowToPlay) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(SetMsgImgs_Panels))
    EVT_CALL(ShowMessageAtScreenPos, MSG_MGM_003B, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), -55, -2, -80, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign_HowToPlay)))
    EVT_RETURN
    EVT_END
};
