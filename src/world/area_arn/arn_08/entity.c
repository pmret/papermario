#include "arn_08.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfLt(GB_StoryProgress, STORY_CH3_WENT_DOWN_THE_WELL)
        Call(MakeEntity, Ref(Entity_BoardedFloor), 0, 30, 0, 0, MAKE_ENTITY_END)
    EndIf
    Return
    End
};
