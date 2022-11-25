#include "flo_13.h"
#include "entity.h"

EvtScript N(EVS_OnBlast_Rock) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeItemEntity, ITEM_MEGA_SMASH, -61, 60, -85, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO13_Item_MegaSmash)
    EVT_CALL(MakeItemEntity, ITEM_SHOOTING_STAR, 128, 0, 157, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO13_Item_ShootingStar)
    EVT_IF_EQ(GF_FLO13_Item_MegaSmash, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BombableRock), -160, 160, -90, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBlast_Rock)))
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
