#include "trd_05.h"
#include "entity.h"

extern EvtScript N(EVS_OnHitTrapTrigger);

EvtScript N(EVS_MakeEntities) = {
    IfLt(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
        Call(MakeEntity, Ref(Entity_TriggerBlock), -70, 300, -15, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnHitTrapTrigger)))
    EndIf
    Return
    End
};
