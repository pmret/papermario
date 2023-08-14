#include "tik_25.h"
#include "entity.h"

API_CALLABLE(N(DismissGotItem)) {
    Entity* bigChest = get_entity_by_index(script->varTable[0]);
    bigChest->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"
#include "world/common/util/PlaySpringReboundAnimation.inc.c"

EvtScript N(EVS_SetupGiantChest_UltraBoots) = {
    EVT_IF_EQ(GF_TIK25_GiantChest, FALSE)
        EVT_LABEL(10)
        EVT_IF_EQ(GF_TIK25_GiantChest, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_WAIT(60)
        EVT_EXEC(N(EVS_PlayUpgradeSong))
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0187, 160, 40)
        EVT_CALL(N(DismissGotItem))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlock_SpringR) = {
    EVT_IF_EQ(GF_TIK25_SpringBrickA, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_TIK25_SpringBrickA, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar5, 210)
    EVT_CALL(MakeLerp, -50, -20, 8, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_EntityID_SpringR, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_SUB(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, LVar0, -135, 22, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_EntityID_SpringR, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_SUB(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    EVT_CALL(PlaySoundAt, SOUND_SPRING, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    EVT_CALL(N(PlaySpringReboundAnimation), MV_EntityID_SpringR)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnBreakBlock_SpringL) = {
    EVT_IF_EQ(GF_TIK25_SpringBrickB, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(GF_TIK25_SpringBrickB, TRUE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar5, -120)
    EVT_CALL(MakeLerp, -20, 10, 8, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_EntityID_SpringL, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_ADD(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(MakeLerp, LVar0, -135, 22, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetEntityPosition), MV_EntityID_SpringL, LVar5, LVar0, 0)
        EVT_WAIT(1)
        EVT_ADD(LVar5, 2)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    EVT_CALL(PlaySoundAt, SOUND_SPRING, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    EVT_CALL(N(PlaySpringReboundAnimation), MV_EntityID_SpringL)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_GiantChest), -270, -90, 0, 90, ITEM_ULTRA_BOOTS, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_TIK25_GiantChest)
    EVT_EXEC(N(EVS_SetupGiantChest_UltraBoots))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 210, -75, -20, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlock_SpringR)))
    EVT_IF_EQ(GF_TIK25_SpringBrickA, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 210, -50, -20, 0, 100, MAKE_ENTITY_END)
        EVT_SET(MV_EntityID_SpringR, LVar0)
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), 150, -135, -20, 0, 100, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -120, -45, -20, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnBreakBlock_SpringL)))
    EVT_IF_EQ(GF_TIK25_SpringBrickB, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), -120, -20, -20, 0, 100, MAKE_ENTITY_END)
        EVT_SET(MV_EntityID_SpringL, LVar0)
    EVT_ELSE
        EVT_CALL(MakeEntity, EVT_PTR(Entity_SimpleSpring), -60, -135, -20, 0, 100, MAKE_ENTITY_END)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
