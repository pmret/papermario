#include "jan_22.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_THREAD
        EVT_LABEL(0)
            EVT_IF_LT(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
                EVT_WAIT(1)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 1075, 150, -50, 0, MAKE_ENTITY_END)
    EVT_END_THREAD
    EVT_CALL(MakeItemEntity, ITEM_JAMMIN_JELLY, 340, 0, -75, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN22_Item_JamminJelly)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), -107, 0, -97, -15, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
