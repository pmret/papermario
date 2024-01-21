#include "sbk_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    IfGe(GB_StoryProgress, STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
        Call(MakeEntity, Ref(Entity_HeartBlock), -240, 60, -200, 0, 6, MAKE_ENTITY_END)
    EndIf
    Return
    End
};
