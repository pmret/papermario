#include "trd_03.h"
#include "entity.h"

extern EvtScript N(EVS_TogglePlatforms_LeftSwitch);
extern EvtScript N(EVS_TogglePlatforms_RightSwitch);

EvtScript N(EVS_MakeEntities) = {
    Set(MV_PlatformsExtended, FALSE)
    Call(MakeEntity, Ref(Entity_RedSwitch), -315, 120, -100, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_TogglePlatforms_LeftSwitch)))
    Call(MakeEntity, Ref(Entity_RedSwitch), 210, 120, -100, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_TogglePlatforms_RightSwitch)))
    Call(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, -580, 0, -60, ITEM_SPAWN_MODE_KEY, GF_TRD03_Item_FortressKeyA)
    Call(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, 470, 0, -60, ITEM_SPAWN_MODE_KEY, GF_TRD03_Item_FortressKeyB)
    Call(MakeItemEntity, ITEM_POWER_BOUNCE, -50, 0, -60, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_TRD03_Item_PowerBounce)
    Return
    End
};
