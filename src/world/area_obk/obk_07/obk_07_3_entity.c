#include "obk_07.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_BooWeight) = {
    Set(LVarA, ITEM_BOO_WEIGHT)
    Set(LVarB, ITEM_TYPE_KEY)
    Set(GB_StoryProgress, STORY_CH3_GOT_WEIGHT)
    Set(GF_OBK07_Chest_Weight, TRUE)
    ExecWait(N(EVS_Chest_GetItem))
    ExecWait(N(EVS_Scene_PlayerGotChestItem))
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 170, 0, -160, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OBK07_Chest_Weight)
    Call(AssignScript, Ref(N(EVS_OpenChest_BooWeight)))
    Return
    End
};
