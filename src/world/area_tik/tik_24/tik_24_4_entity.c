#include "tik_24.h"
#include "entity.h"

EvtScript N(EVS_OnSmashBlock) = {
    Set(GF_TIK24_Hammer3Block, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o44, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TIK24_Hammer3Block, FALSE)
        Call(MakeEntity, Ref(Entity_Hammer3Block), -240, -10, 0, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmashBlock)))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o44, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o45, COLLIDER_FLAGS_UPPER_MASK)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 50, 80, -75, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK24_HiddenItem_LifeShroom)
    Call(MakeEntity, Ref(Entity_YellowBlock), -50, 80, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK24_ItemBlock_CoinA)
    Call(MakeEntity, Ref(Entity_YellowBlock), 150, 80, -75, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK24_ItemBlock_CoinB)
    Call(MakeEntity, Ref(Entity_BrickBlock), -100, 80, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 0, 80, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 100, 80, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 200, 80, -75, 0, MAKE_ENTITY_END)
    Return
    End
};
