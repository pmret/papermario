#include "jan_04.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_VolcanoVase) = EVT_OPEN_CHEST_KEY(ITEM_VOLCANO_VASE, GF_JAN04_Chest_VolcanoVase);

EvtScript N(EVS_MakeEntities) = {
    Switch(GB_StoryProgress)
        CaseRange(STORY_CH5_BEGAN_PEACH_MISSION, STORY_CH8_REACHED_PEACHS_CASTLE)
            Call(MakeEntity, Ref(Entity_Chest), 0, 0, 0, 0, 0, MAKE_ENTITY_END)
            Call(AssignChestFlag, GF_JAN04_Chest_VolcanoVase)
            Call(AssignScript, Ref(N(EVS_OpenChest_VolcanoVase)))
    EndSwitch
    Call(MakeItemEntity, ITEM_STAR_PIECE, 300, 0, -225, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_JAN04_Item_StarPiece)
    Return
    End
};
