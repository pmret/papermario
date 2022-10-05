
#include "sbk_45.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -255, 55, -145, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -375, 80, -145, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeItemEntity, ITEM_STOP_WATCH, -375, 105, -145, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_SBK45_Item_StopWatch)
    EVT_CALL(MakeItemEntity, ITEM_SPIN_ATTACK, 193, 79, -345, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SBK45_Item_SpinAttack)
    EVT_RETURN
    EVT_END
};
