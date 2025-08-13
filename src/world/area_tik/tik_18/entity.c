#include "tik_18.h"
#include "entity.h"

API_CALLABLE(N(WakeSpikedGoomba)) {
    Enemy* enemy = get_enemy_safe(NPC_SpikedGloomba);

    if (enemy != nullptr) {
        enemy->varTable[0] = true;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnBreakBlock) = {
    Call(N(WakeSpikedGoomba))
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 200, 50, -75, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK18_HiddenItem_SuperShroom)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 0, 50, -75, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_TIK18_MultiCoinBrick)
    Call(MakeEntity, Ref(Entity_BrickBlock), -100, 50, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), -50, 50, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 50, 50, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 100, 50, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 250, 50, -75, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_BrickBlock), 150, 50, -75, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_OnBreakBlock)))
    Return
    End
};
