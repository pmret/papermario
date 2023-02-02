#include "sbk_14.h"
#include "entity.h"

TweesterPath N(D_80240440_936B20) = {
    -65, 0, 217,
    -262, 0, -64,
    57, 0, -286,
    327, 0, 8,
    TWEESTER_PATH_LOOP
};

TweesterPath* N(D_80240474_936B54)[] = {
    &N(D_80240440_936B20),
    PTR_LIST_END
};

EvtScript N(D_8024047C_936B5C) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GotoMap, EVT_PTR("sbk_05"), sbk_05_ENTRY_4)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Tweester), 327, 0, 8, 0, EVT_PTR(N(D_80240474_936B54)), MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(D_8024047C_936B5C)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK14_MultiCoinBrick)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -240, 0, 215, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK14_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 220, 0, 150, 0, ITEM_HONEY_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_SBK14_ItemBlock_HoneySyrup)
    EVT_RETURN
    EVT_END
};
