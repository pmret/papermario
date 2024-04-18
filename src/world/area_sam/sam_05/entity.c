#include "sam_05.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_LETTER_TO_MERLOW, 100, 0, -100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_SAM05_Item_Letter06)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 490, 140, -75, 0, ITEM_STOP_WATCH, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SAM05_HiddenItem_StopWatch)
    Return
    End
};
