#include "kmr_04.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    Set(GF_KMR04_Hammer1Block, TRUE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_KMR04_Hammer1Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer1Block), -80, 0, 400, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashBlock)))
    EndIf
    Call(MakeEntity, Ref(Entity_BrickBlock), -230, 60, -140, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -440, 60, 20, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 60, 0, 370, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 85, 0, 395, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 100, 0, -70, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KMR04_MultiCoinBrick)
    Call(MakeEntity, Ref(Entity_SavePoint), 0, 60, 0, 0, MAKE_ENTITY_END)
    Return
    End
};
