#include "flo_00.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_EPILOGUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 110, 60, -100, 0, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
