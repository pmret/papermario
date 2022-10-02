#include "tst_03.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 567, 60, 100, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenRedBlock), 623, 60, 100, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_InertYellowBlock), 300, 60, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 360, 80, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 420, 80, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 480, 80, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_TriggerBlock), 540, 80, -50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 600, 60, -50, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SuperBlock), 300, 60, 160, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 420, 60, 160, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 480, 60, 160, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PowBlock), 644, 60, 118, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1BlockTiny), 460, 0, 50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer1BlockTiny), 460, 25, 50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer2BlockTiny), 490, 0, 50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Hammer3BlockTiny), 520, 0, 50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PowBlock), 644, 60, 118, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 416, 0, 232, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), 336, 0, 232, 0, -1, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), 270, 0, 232, 0, ITEM_MUSHROOM, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), 270, 30, 232, 0, ITEM_MUSHROOM, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
