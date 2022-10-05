#include "sbk_00.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -230, 0, 155, 0, ITEM_FRIGHT_JAR, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK00_ItemBlock_FrightJar)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 160, 0, 205, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK00_ItemBlock_Coin)
    EVT_RETURN
    EVT_END
};
