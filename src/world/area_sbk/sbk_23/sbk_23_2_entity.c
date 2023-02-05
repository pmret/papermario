#include "sbk_23.h"
#include "entity.h"

TweesterPath N(D_802403C0_93AB20) = {
    -65, 0, 217,
    -262, 0, -64,
    57, 0, -286,
    327, 0, 8,
    TWEESTER_PATH_LOOP
};

TweesterPath* N(D_802403F4_93AB54)[] = {
    &N(D_802403C0_93AB20),
    PTR_LIST_END
};

EvtScript N(D_802403FC_93AB5C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("sbk_14"), sbk_14_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Tweester), 327, 0, 8, 0, EVT_PTR(N(D_802403F4_93AB54)), MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_802403FC_93AB5C)))
    EVT_RETURN
    EVT_END
};
