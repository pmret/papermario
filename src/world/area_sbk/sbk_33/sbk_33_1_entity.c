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
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("sbk_24"), sbk_24_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 0, 0, 225, 0, MODEL_stage, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_SBK33_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Tweester), 327, 0, 8, 0, EVT_PTR(N(TweesterPaths)), MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_802400FC_945ACC)))
    EVT_RETURN
    EVT_END
};
