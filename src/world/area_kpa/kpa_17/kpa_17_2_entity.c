#include "kpa_17.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HeartBlock), 1000, 90, -575, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 820, 60, -565, 0, -1, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 820, 30, -565, 0, ITEM_TASTY_TONIC, MAKE_ENTITY_END)
    Call(AssignCrateFlag, GF_KPA17_Crate_TastyTonic)
    Call(MakeEntity, Ref(Entity_WoodenCrate), 855, 30, -565, 0, ITEM_LIFE_SHROOM, MAKE_ENTITY_END)
    Call(AssignCrateFlag, GF_KPA17_Crate_LifeShroom)
    Return
    End
};
