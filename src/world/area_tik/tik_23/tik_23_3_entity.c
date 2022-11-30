#include "tik_23.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    EVT_SET(GF_TIK23_Hammer2Block, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o102, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TIK23_Hammer2Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2Block), -280, -20, -20, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashBlock)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o102, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -75, 40, -120, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK23_HiddenItem_MapleSyrup)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 175, 40, 0, 0, ITEM_STOP_WATCH, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK23_HiddenItem_StopWatch)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -250, 40, -100, 0, ITEM_VOLT_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK23_HiddenItem_VoltShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -200, 40, -100, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK23_ItemBlock_Coin)
    EVT_RETURN
    EVT_END
};
