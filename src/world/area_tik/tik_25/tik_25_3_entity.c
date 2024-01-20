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
    IfEq(GF_TIK25_GiantChest, FALSE)
        Label(10)
        IfEq(GF_TIK25_GiantChest, FALSE)
            Wait(1)
            Goto(10)
        EndIf
        Wait(60)
        Exec(N(EVS_PlayUpgradeSong))
        Call(ShowMessageAtScreenPos, MSG_Menus_0187, 160, 40)
        Call(N(DismissGotItem))
    EndIf
    Return
    End
};

EvtScript N(EVS_OnBreakBlock_SpringR) = {
    IfEq(GF_TIK25_SpringBrickA, TRUE)
        Return
    EndIf
    Set(GF_TIK25_SpringBrickA, TRUE)
    Call(DisablePlayerInput, TRUE)
    Set(LVar5, 210)
    Call(MakeLerp, -50, -20, 8, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_EntityID_SpringR, LVar5, LVar0, 0)
        Wait(1)
        Sub(LVar5, 2)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, LVar0, -135, 22, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_EntityID_SpringR, LVar5, LVar0, 0)
        Wait(1)
        Sub(LVar5, 2)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    Call(PlaySoundAt, SOUND_SPRING, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    Call(N(PlaySpringReboundAnimation), MV_EntityID_SpringR)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OnBreakBlock_SpringL) = {
    IfEq(GF_TIK25_SpringBrickB, TRUE)
        Return
    EndIf
    Set(GF_TIK25_SpringBrickB, TRUE)
    Call(DisablePlayerInput, TRUE)
    Set(LVar5, -120)
    Call(MakeLerp, -20, 10, 8, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_EntityID_SpringL, LVar5, LVar0, 0)
        Wait(1)
        Add(LVar5, 2)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(MakeLerp, LVar0, -135, 22, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_EntityID_SpringL, LVar5, LVar0, 0)
        Wait(1)
        Add(LVar5, 2)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    Call(PlaySoundAt, SOUND_SPRING, SOUND_SPACE_DEFAULT, LVar5, LVar0, 0)
    Call(N(PlaySpringReboundAnimation), MV_EntityID_SpringL)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_GiantChest), -270, -90, 0, 90, ITEM_ULTRA_BOOTS, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_TIK25_GiantChest)
    Exec(N(EVS_SetupGiantChest_UltraBoots))
    Call(MakeEntity, Ref(Entity_BrickBlock), 210, -75, -20, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_OnBreakBlock_SpringR)))
    IfEq(GF_TIK25_SpringBrickA, FALSE)
        Call(MakeEntity, Ref(Entity_SimpleSpring), 210, -50, -20, 0, 100, MAKE_ENTITY_END)
        Set(MV_EntityID_SpringR, LVar0)
    Else
        Call(MakeEntity, Ref(Entity_SimpleSpring), 150, -135, -20, 0, 100, MAKE_ENTITY_END)
    EndIf
    Call(MakeEntity, Ref(Entity_BrickBlock), -120, -45, -20, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_OnBreakBlock_SpringL)))
    IfEq(GF_TIK25_SpringBrickB, FALSE)
        Call(MakeEntity, Ref(Entity_SimpleSpring), -120, -20, -20, 0, 100, MAKE_ENTITY_END)
        Set(MV_EntityID_SpringL, LVar0)
    Else
        Call(MakeEntity, Ref(Entity_SimpleSpring), -60, -135, -20, 0, 100, MAKE_ENTITY_END)
    EndIf
    Return
    End
};
