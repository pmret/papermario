#include "trd_03.h"
#include "effects.h"

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_GreenKoopaBros);
extern EvtScript N(EVS_InitializePlatforms);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(GetHiddenDoorPushDirection)) {
    Bytecode* args = script->ptrReadPos;
    s32 pushDir = 0;

    if ((gCollisionStatus.pushingAgainstWall == COLLIDER_o84) && (gGameStatusPtr->stickX[0] < 0)) {
        pushDir = 1;
    }
    if ((gCollisionStatus.pushingAgainstWall == COLLIDER_o85) && (gGameStatusPtr->stickX[0] > 0)) {
        pushDir = 2;
    }

    evt_set_variable(script, *args++, pushDir);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetFrameCounter)) {
    evt_set_variable(script, *script->ptrReadPos, gGameStatusPtr->frameCounter);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoors_trd_02_1) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_0, "trd_02", trd_02_ENTRY_1, COLLIDER_ttw, MODEL_d1, MODEL_d2);
EvtScript N(EVS_ExitDoors_trd_04_0) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_1, "trd_04", trd_04_ENTRY_0, COLLIDER_tte, MODEL_d3, MODEL_d4);
EvtScript N(EVS_ExitDoors_trd_02_3) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_2, "trd_02", trd_02_ENTRY_3, COLLIDER_ttwo, MODEL_o33, MODEL_o34);
EvtScript N(EVS_ExitDoors_trd_04_2) = EVT_EXIT_DOUBLE_DOOR(trd_03_ENTRY_3, "trd_04", trd_04_ENTRY_2, COLLIDER_tteo, MODEL_o31, MODEL_o32);
EvtScript N(EVS_ExitDoors_trd_02_4) = EVT_EXIT_WALK(40, trd_03_ENTRY_4, "trd_02", trd_02_ENTRY_4);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_trd_02_1)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_04_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttwo, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_04_2)), TRIGGER_WALL_PRESS_A, COLLIDER_tteo, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_trd_02_4)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(trd_03_ENTRY_0)
            Set(LVar2, MODEL_d1)
            Set(LVar3, MODEL_d2)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_03_ENTRY_1)
            Set(LVar2, MODEL_d3)
            Set(LVar3, MODEL_d4)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_03_ENTRY_2)
            Set(LVar2, MODEL_o33)
            Set(LVar3, MODEL_o34)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_03_ENTRY_3)
            Set(LVar2, MODEL_o31)
            Set(LVar3, MODEL_o32)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(trd_03_ENTRY_4)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

BombTrigger N(BombPos_MiddleCell) = {
    .pos = { -160.0f, 0.0f, -10.0f },
    .radius = 0.0f
};

BombTrigger N(BombPos_RightCell) = {
    .pos = { 360.0f, 0.0f, -10.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BombWall_MiddleCell) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 40, 10, 1, 10, 30)
    Call(EnableModel, MODEL_nk2, TRUE)
    Loop(10)
        Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_VISIBLE)
        Wait(1)
        Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit2, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_TRD03_BombedCenterCell, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_BombWall_RightCell) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 43, 10, 1, 10, 30)
    Call(EnableModel, MODEL_nk3, TRUE)
    Loop(10)
        Call(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_VISIBLE)
        Wait(1)
        Call(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_TRD03_BombedRightCell, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_HiddenDoor) = {
    Set(LVarB, 0)
    SetF(LVarC, Float(0.0))
    Set(LVarD, 0)
    Set(LVarE, 0)
    Call(CloneModel, MODEL_rou2, CLONED_MODEL(0))
    Call(EnableModel, CLONED_MODEL(0), FALSE)
    Call(ParentColliderToModel, COLLIDER_o84, CLONED_MODEL(0))
    Call(CloneModel, MODEL_rou2, CLONED_MODEL(1))
    Call(EnableModel, CLONED_MODEL(1), FALSE)
    Call(ParentColliderToModel, COLLIDER_o85, CLONED_MODEL(1))
    Label(0)
        IfEq(LVarD, 0)
            Call(N(GetHiddenDoorPushDirection), LVar0)
            Switch(LVar0)
                // pushing left on COLLIDER_o84
                CaseEq(1)
                    Call(N(GetFrameCounter), LVar1)
                    Sub(LVar1, LVarA)
                    IfEq(LVar1, 1)
                        Add(LVarB, 1)
                        SubF(LVarC, Float(0.1))
                    Else
                        Set(LVarB, 0)
                    EndIf
                    IfGt(LVarB, 15)
                        Set(LVarB, 0)
                        Set(LVarD, 8)
                    EndIf
                    IfLt(LVarC, -3)
                        Set(LVarD, 8)
                    EndIf
                // pushing right on COLLIDER_o85
                CaseEq(2)
                    Set(LVarD, -8)
                // not pushing
                CaseDefault
                    Set(LVarB, 0)
                    IfLt(LVarC, 0)
                        AddF(LVarC, Float(0.2))
                        IfGt(LVarC, 0)
                            SetF(LVarC, Float(0.0))
                        EndIf
                    Else
                        SubF(LVarC, Float(0.2))
                        IfLt(LVarC, 0)
                            SetF(LVarC, Float(0.0))
                        EndIf
                    EndIf
            EndSwitch
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o84, 0x7FFFFFFF)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o85, 0x7FFFFFFF)
            Call(TranslateModel, CLONED_MODEL(0), LVarC, 0, 0)
            Call(TranslateModel, CLONED_MODEL(1), LVarC, 0, 0)
            Call(UpdateColliderTransform, COLLIDER_o84)
            Call(UpdateColliderTransform, COLLIDER_o85)
        Else
            SetF(LVarC, Float(0.0))
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o84, 0x7FFFFFFF)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o85, 0x7FFFFFFF)
            IfGt(LVarD, 0)
                Sub(LVarD, 1)
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                SetF(LVar3, LVarD)
                MulF(LVar3, Float(1.8))
                SubF(LVar0, LVar3)
                Call(SetPlayerPos, LVar0, LVar1, LVar2)
            Else
                Add(LVarD, 1)
            EndIf
        EndIf
        Call(N(GetFrameCounter), LVarA)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    IfLt(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        Exec(N(EVS_Scene_GreenKoopaBros))
    Else
        Exec(N(EVS_EnterMap))
    EndIf
    IfEq(GF_TRD02_BombedWall, FALSE)
        Call(EnableModel, MODEL_nk1, FALSE)
    Else
        Call(SetGroupVisibility, MODEL_ana1, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit1, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_TRD03_BombedCenterCell, FALSE)
        Call(EnableModel, MODEL_nk2, FALSE)
        BindTrigger(Ref(N(EVS_BombWall_MiddleCell)), TRIGGER_POINT_BOMB, Ref(N(BombPos_MiddleCell)), 1, 0)
    Else
        Call(SetGroupVisibility, MODEL_ana2, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt2, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_TRD03_BombedRightCell, FALSE)
        Call(EnableModel, MODEL_nk3, FALSE)
        BindTrigger(Ref(N(EVS_BombWall_RightCell)), TRIGGER_POINT_BOMB, Ref(N(BombPos_RightCell)), 1, 0)
    Else
        Call(SetGroupVisibility, MODEL_ana3, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilit3, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt3, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetupMusic))
    IfLt(GB_StoryProgress, STORY_CH1_KOOPA_BROS_HID_KEY)
        Call(TranslateModel, MODEL_0ri, 0, 100, -1)
    EndIf
    ExecWait(N(EVS_InitializePlatforms))
    Exec(N(EVS_HiddenDoor))
    Return
    End
};
