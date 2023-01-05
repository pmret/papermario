#include "tik_18.h"
#include "entity.h"

API_CALLABLE(N(WakeSpikedGoomba)) {
    Enemy* enemy = get_enemy_safe(NPC_SpikedGloomba);

    if (enemy != NULL) {
        enemy->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnBreakBlock) = {
    EVT_CALL(N(WakeSpikedGoomba))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 200, 50, -75, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK18_HiddenItem_SuperShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_MulticoinBlock), 0, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_TIK18_MultiCoinBrick)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -100, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -50, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 50, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 100, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 250, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 150, 50, -75, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlock)))
    EVT_RETURN
    EVT_END
};
