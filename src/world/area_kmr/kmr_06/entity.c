#include "kmr_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HeartBlock), 800, 60, 0, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_RedBlock), 220, 60, 10, 0, ITEM_CLOSE_CALL, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KMR06_BadgeBlock_CloseCall)
    Return
    End
};
