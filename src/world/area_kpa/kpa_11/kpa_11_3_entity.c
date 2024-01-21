#include "kpa_11.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_SavePoint), 1400, 90, -875, 0, MAKE_ENTITY_END)
    IfEq(GF_KPA11_Defeated_Guard, TRUE)
        Call(MakeItemEntity, ITEM_BOWSER_CASTLE_KEY, 550, 30, -145, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA11_Item_CastleKey2)
    EndIf
    Call(MakeEntity, Ref(Entity_YellowBlock), 1400, 90, -375, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA10_ItemBlock_LifeShroom)
    Return
    End
};
