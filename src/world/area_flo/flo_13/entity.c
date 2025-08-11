#include "flo_13.h"
#include "entity.h"

EvtScript N(EVS_OnBlast_Rock) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_MEGA_SMASH, -61, 60, -85, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO13_Item_MegaSmash)
    Call(MakeItemEntity, ITEM_SHOOTING_STAR, 128, 0, 157, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_FLO13_Item_ShootingStar)
    IfEq(GF_FLO13_Item_MegaSmash, false)
        Call(MakeEntity, Ref(Entity_BombableRock), -160, 160, -90, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnBlast_Rock)))
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
