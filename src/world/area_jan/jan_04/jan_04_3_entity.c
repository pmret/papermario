#include "jan_04.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_VolcanoVase) = EVT_OPEN_CHEST_KEY(ITEM_VOLCANO_VASE, GF_JAN04_Chest_VolcanoVase);

EvtScript N(EVS_MakeEntities) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_RANGE(STORY_CH5_BEGAN_PEACH_MISSION, STORY_CH8_REACHED_PEACHS_CASTLE)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 0, 0, 0, 0, 0, MAKE_ENTITY_END)
            EVT_CALL(AssignChestFlag, GF_JAN04_Chest_VolcanoVase)
            EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_VolcanoVase)))
    EVT_END_SWITCH
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, 300, 0, -225, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN04_Item_StarPiece)
    EVT_RETURN
    EVT_END
};
