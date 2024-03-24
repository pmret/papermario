#include "obk_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), 675, -420, 415, 180, MODEL_o317, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OBK01_HiddenPanel)
    Return
    End
};
