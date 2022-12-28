#include "tik_24.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    EVT_SET(GF_TIK24_Hammer3Block, TRUE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o44, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TIK24_Hammer3Block, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3Block), -240, -10, 0, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmashBlock)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o44, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o45, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 50, 80, -75, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK24_HiddenItem_LifeShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -50, 80, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK24_ItemBlock_CoinA)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 150, 80, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK24_ItemBlock_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -100, 80, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 0, 80, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 100, 80, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 200, 80, -75, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
