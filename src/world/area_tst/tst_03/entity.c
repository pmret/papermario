#include "tst_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_RedBlock), 567, 60, 100, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenRedBlock), 623, 60, 100, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_InertYellowBlock), 300, 60, -50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 360, 80, -50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 420, 80, -50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_YellowBlock), 480, 80, -50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_TriggerBlock), 540, 80, -50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 600, 60, -50, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SuperBlock), 300, 60, 160, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HeartBlock), 420, 60, 160, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_SavePoint), 480, 60, 160, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_PowBlock), 644, 60, 118, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_Hammer1BlockTiny), 460, 0, 50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_Hammer1BlockTiny), 460, 25, 50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_Hammer2BlockTiny), 490, 0, 50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_Hammer3BlockTiny), 520, 0, 50, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_PowBlock), 644, 60, 118, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BoardedFloor), 416, 0, 232, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 336, 0, 232, 0, -1, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 270, 0, 232, 0, ITEM_MUSHROOM, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 270, 30, 232, 0, ITEM_MUSHROOM, 0, MAKE_ENTITY_END)
    Return
    End
};
