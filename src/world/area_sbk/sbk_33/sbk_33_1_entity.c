#include "sbk_33.h"
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

EvtScript N(D_802400FC_945ACC) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GotoMap, Ref("sbk_24"), sbk_24_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), 0, 0, 225, 0, MODEL_stage, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_SBK33_HiddenPanel)
    Call(MakeEntity, Ref(Entity_Tweester), 327, 0, 8, 0, Ref(N(TweesterPaths)), MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(D_802400FC_945ACC)))
    Return
    End
};
