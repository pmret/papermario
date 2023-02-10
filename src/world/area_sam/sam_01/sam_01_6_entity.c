#include "sam_01.h"
#include "entity.h"

#define NAME_SUFFIX _Entity
#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_AttackFXE) = EVT_OPEN_CHEST_BADGE(ITEM_ATTACK_FX_E, GF_SAM01_Chest_AttackFXE);
#define NAME_SUFFIX

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 95, 0, -180, 270, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_SAM01_Chest_AttackFXE)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_AttackFXE_Entity)))
    EVT_CALL(SetEntityCullMode, 1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        EVT_CALL(MakeItemEntity, ITEM_PRESENT, -325, 0, -240, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_PresentItemID, LVar0)
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_SNOWMAN_BUCKET, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_SET(MV_BucketItemID, LVar0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -110, 0, 0, 0, MODEL_o341, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_SAM01_HiddenPanel)
    EVT_RETURN
    EVT_END
};
