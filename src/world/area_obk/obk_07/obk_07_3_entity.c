#include "obk_07.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_BooWeight) = {
    EVT_SET(LVarA, ITEM_BOO_WEIGHT)
    EVT_SET(LVarB, ITEM_TYPE_KEY)
    EVT_SET(GB_StoryProgress, STORY_CH3_GOT_WEIGHT)
    EVT_SET(GF_OBK07_Chest_Weight, TRUE)
    EVT_EXEC_WAIT(N(EVS_Chest_GetItem))
    EVT_EXEC_WAIT(N(EVS_Scene_PlayerGotChestItem))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 170, 0, -160, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OBK07_Chest_Weight)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_BooWeight)))
    EVT_RETURN
    EVT_END
};
