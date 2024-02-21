#include "sbk_54.h"
#include "entity.h"

TweesterPath N(TweesterPath1) = {
    -65, 0, 217,
    -262, 0, -64,
    57, 0, -286,
    327, 0, 8,
    TWEESTER_PATH_LOOP
};

TweesterPath* N(TweesterPaths)[] = {
    &N(TweesterPath1),
    PTR_LIST_END
};

EvtScript N(EVS_RideTweester) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GotoMap, Ref("sbk_45"), sbk_45_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Tweester), 327, 0, 8, 0, Ref(N(TweesterPaths)), MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_RideTweester)))
    Return
    End
};
