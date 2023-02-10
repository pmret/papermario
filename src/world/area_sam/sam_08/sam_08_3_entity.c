#include "sam_08.h"
#include "entity.h"

#define SUPER_BLOCK_MAPVAR MV_SuperBlock
#define SUPER_BLOCK_GAMEFLAG GF_SAM08_SuperBlock
#include "world/common/entity/SuperBlock.inc.c"

EvtScript N(EVS_MakeEntities) = {
    EVT_MAKE_SUPER_BLOCK(-800, 210, -130, 0)
    EVT_CALL(MakeItemEntity, ITEM_PEBBLE, -770, -240, 30, ITEM_SPAWN_MODE_FIXED_SPAWN_ALWAYS_NEVER_VANISH, 0)
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_DEFEATED_FIRST_DUPLIGHOST)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), -960, -120, -37, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_SAM_06))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
