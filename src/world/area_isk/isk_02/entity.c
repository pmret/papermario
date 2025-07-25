#include "isk_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_ISK02_UnlockedDoor, false)
        Call(MakeEntity, Ref(Entity_Padlock), 272, 60, 486, 300, MAKE_ENTITY_END)
        Set(MV_EntityID_Padlock, LVar0)
    EndIf
    Return
    End
};
