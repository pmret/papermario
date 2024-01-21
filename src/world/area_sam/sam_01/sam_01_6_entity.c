#include "sam_01.h"
#include "entity.h"

#define NAME_SUFFIX _Entity
#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_AttackFXE) = EVT_OPEN_CHEST_BADGE(ITEM_ATTACK_FX_E, GF_SAM01_Chest_AttackFXE);
#define NAME_SUFFIX

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 95, 0, -180, 270, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_SAM01_Chest_AttackFXE)
    Call(AssignScript, Ref(N(EVS_OpenChest_AttackFXE_Entity)))
    Call(SetEntityCullMode, 1)
    IfLt(GB_StoryProgress, STORY_CH7_MAYOR_MURDER_SOLVED)
        Call(MakeItemEntity, ITEM_PRESENT, -325, 0, -240, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_PresentItemID, LVar0)
    EndIf
    Call(MakeItemEntity, ITEM_SNOWMAN_BUCKET, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
    Set(MV_BucketItemID, LVar0)
    Call(MakeEntity, Ref(Entity_HiddenPanel), -110, 0, 0, 0, MODEL_o341, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_SAM01_HiddenPanel)
    Return
    End
};
