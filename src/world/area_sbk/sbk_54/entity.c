#include "sbk_54.h"
#include "entity.h"

TweesterPath N(DefaultTweesterPath) = {
    -65, 0, 217,
    -262, 0, -64,
    57, 0, -286,
    327, 0, 8,
    TWEESTER_PATH_LOOP
};

TweesterPath* N(TweesterPaths)[] = {
    &N(DefaultTweesterPath),
    PTR_LIST_END
};

EvtScript N(EVS_GotoMap_sbk_45_4) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(GotoMap, Ref("sbk_45"), sbk_45_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Tweester), 327, 0, 8, 0, Ref(N(TweesterPaths)), MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_GotoMap_sbk_45_4)))
    Return
    End
};
