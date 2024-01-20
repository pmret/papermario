#include "tik_23.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    Set(GF_TIK23_Hammer2Block, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o102, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TIK23_Hammer2Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer2Block), -280, -20, -20, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashBlock)))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o102, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -75, 40, -120, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK23_HiddenItem_MapleSyrup)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 175, 40, 0, 0, ITEM_STOP_WATCH, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK23_HiddenItem_StopWatch)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -250, 40, -100, 0, ITEM_VOLT_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK23_HiddenItem_VoltShroom)
    Call(MakeEntity, Ref(Entity_YellowBlock), -200, 40, -100, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK23_ItemBlock_Coin)
    Return
    End
};
