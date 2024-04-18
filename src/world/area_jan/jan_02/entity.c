#include "jan_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), 25, 15, -60, 0, MODEL_o222, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_JAN02_HiddenPanel)
    Return
    End
};
