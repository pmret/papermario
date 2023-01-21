#include "nok_11.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 30, 60, -85, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 110, 60, -85, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_NOK11_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 330, 60, -85, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 380, 60, -85, 0, ITEM_DIZZY_ATTACK, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_NOK11_BadgeBlock_DizzyAttack)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 650, 60, -85, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 700, 60, -85, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 750, 60, -85, 0, ITEM_FRIGHT_JAR, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_NOK11_ItemBlock_FrightJar)
    EVT_RETURN
    EVT_END
};
