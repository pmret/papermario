#include "trd_05.h"
#include "entity.h"

extern EvtScript N(EVS_OnHitTrapTrigger);

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_MARIO_ACTIVATED_TRAP)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_TriggerBlock), -70, 300, -15, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnHitTrapTrigger)))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
