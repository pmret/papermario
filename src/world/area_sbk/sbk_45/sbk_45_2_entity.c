
#include "sbk_45.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_BrickBlock), -255, 55, -145, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -375, 80, -145, 0, MAKE_ENTITY_END)
    Call(MakeItemEntity, ITEM_STOP_WATCH, -375, 105, -145, ITEM_SPAWN_MODE_FALL_NEVER_VANISH, GF_SBK45_Item_StopWatch)
    Call(MakeItemEntity, ITEM_SPIN_ATTACK, 193, 79, -345, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SBK45_Item_SpinAttack)
    Return
    End
};
