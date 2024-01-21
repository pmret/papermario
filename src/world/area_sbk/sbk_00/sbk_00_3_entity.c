#include "sbk_00.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -230, 0, 155, 0, ITEM_FRIGHT_JAR, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK00_ItemBlock_FrightJar)
    Call(MakeEntity, Ref(Entity_YellowBlock), 160, 0, 205, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK00_ItemBlock_Coin)
    Return
    End
};
