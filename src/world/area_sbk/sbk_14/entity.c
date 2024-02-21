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
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GotoMap, Ref("sbk_05"), sbk_05_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Tweester), 327, 0, 8, 0, Ref(N(D_80240474_936B54)), MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(D_8024047C_936B5C)))
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 0, 60, -100, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK14_MultiCoinBrick)
    Call(MakeEntity, Ref(Entity_YellowBlock), -240, 0, 215, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK14_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_YellowBlock), 220, 0, 150, 0, ITEM_HONEY_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_SBK14_ItemBlock_HoneySyrup)
    Return
    End
};
