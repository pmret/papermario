#include "trd_03.h"
#include "entity.h"

extern EvtScript N(EVS_TogglePlatforms_LeftSwitch);
extern EvtScript N(EVS_TogglePlatforms_RightSwitch);

EvtScript N(EVS_MakeEntities) = {
    EVT_SET(MV_PlatformsExtended, FALSE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), -315, 120, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_TogglePlatforms_LeftSwitch)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedSwitch), 210, 120, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_TogglePlatforms_RightSwitch)))
    EVT_CALL(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, -580, 0, -60, ITEM_SPAWN_MODE_KEY, GF_TRD03_Item_FortressKeyA)
    EVT_CALL(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, 470, 0, -60, ITEM_SPAWN_MODE_KEY, GF_TRD03_Item_FortressKeyB)
    EVT_CALL(MakeItemEntity, ITEM_POWER_BOUNCE, -50, 0, -60, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_TRD03_Item_PowerBounce)
    EVT_RETURN
    EVT_END
};
