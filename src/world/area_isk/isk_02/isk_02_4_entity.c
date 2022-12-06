#include "isk_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_ISK02_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 272, 60, 486, 300, MAKE_ENTITY_END)
        EVT_SET(MV_EntityID_Padlock, LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
