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
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GotoMap, Ref("sbk_14"), sbk_14_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Tweester), 327, 0, 8, 0, Ref(N(D_802403F4_93AB54)), MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(D_802403FC_93AB5C)))
    Return
    End
};
