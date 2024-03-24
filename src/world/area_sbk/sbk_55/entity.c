#include "sbk_55.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK55_MultiCoinBrick)
    Call(MakeItemEntity, ITEM_TASTY_TONIC, 420, 0, 168, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SBK55_Item_TastyTonic)
    Return
    End
};
