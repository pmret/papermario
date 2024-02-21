#include "pra_13.h"
#include "effects.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };

s32 N(FarLeftDoorModelsL)[] = { MODEL_o859, MODEL_o860, -1 };
s32 N(FarLeftDoorModelsR)[] = { MODEL_o861, MODEL_o862, -1 };

s32 N(BothLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, MODEL_o859, MODEL_o860, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, MODEL_o861, MODEL_o862, -1 };

EvtScript N(EVS_ExitDoors_pra_02_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, 0)
    Set(LVar1, 20)
    IfEq(GF_PRA_BrokeIllusion, FALSE)
        Set(LVar2, Ref(N(BothLeftDoorModelsL)))
        Set(LVar3, Ref(N(BothLeftDoorModelsR)))
    Else
        Set(LVar2, Ref(N(NearLeftDoorModelsL)))
        Set(LVar3, Ref(N(NearLeftDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_pra_14_0) = EVT_EXIT_WALK(60, pra_13_ENTRY_1, "pra_14", pra_14_ENTRY_0);

EvtScript N(EVS_Unused_1) = {
    Return
    End
};

EvtScript N(EVS_ExitWalk_pra_14_1) = EVT_EXIT_WALK(60, pra_13_ENTRY_2, "pra_14", pra_14_ENTRY_1);

EvtScript N(EVS_Unused_2) = {
    Return
    End
};

EvtScript N(EVS_ExitDoors_pra_02_3) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    Set(LVar0, 3)
    Set(LVar1, 24)
    IfEq(GF_PRA_BrokeIllusion, FALSE)
        Set(LVar2, Ref(N(BothLeftDoorModelsL)))
        Set(LVar3, Ref(N(BothLeftDoorModelsR)))
    Else
        Set(LVar2, Ref(N(FarLeftDoorModelsL)))
        Set(LVar3, Ref(N(FarLeftDoorModelsR)))
    EndIf
    Exec(BaseExitDoor)
    Wait(17)
    Call(GotoMap, Ref("pra_02"), pra_02_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_pra_02_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_pra_14_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(pra_13_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            IfEq(GF_PRA_BrokeIllusion, FALSE)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(NearLeftDoorModelsL)))
                Set(LVar3, Ref(N(NearLeftDoorModelsR)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(pra_13_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(pra_13_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(pra_13_ENTRY_3)
            Call(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            IfEq(GF_PRA_BrokeIllusion, FALSE)
                Set(LVar2, Ref(N(BothLeftDoorModelsL)))
                Set(LVar3, Ref(N(BothLeftDoorModelsR)))
            Else
                Set(LVar2, Ref(N(FarLeftDoorModelsL)))
                Set(LVar3, Ref(N(FarLeftDoorModelsR)))
            EndIf
            ExecWait(BaseEnterDoor)
            Exec(N(EVS_BindExitTriggers))
    EndSwitch
    Return
    End
};

BombTrigger N(BombPos_NearWall) = {
    .pos = { 487.0f, 0.0f, 80.0f },
    .radius = 0.0f
};

BombTrigger N(BombPos_FarWall) = {
    .pos = { 487.0f, 0.0f, -80.0f },
    .radius = 0.0f
};

EvtScript N(EVS_BlastWall_Near) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 50, 34, 1, 10, 30)
    Call(EnableModel, MODEL_g260, FALSE)
    Call(EnableModel, MODEL_g265, FALSE)
    Call(EnableModel, MODEL_o952, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_PRA13_BombedWallA, TRUE)
    Set(GF_PRA_BrokeIllusion, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_BlastWall_Far) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 65, 34, 1, 10, 30)
    Call(EnableModel, MODEL_g289, FALSE)
    Call(EnableModel, MODEL_g290, FALSE)
    Call(EnableModel, MODEL_o1009, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_PRA13_BombedWallB, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    Call(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(SetCamEnabled, CAM_DEFAULT, TRUE)
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Set(LVar0, MODEL_o945)
    Set(LVar1, MODEL_o947)
    Set(LVar2, 0)
    Exec(N(EVS_GlassShimmer))
    Set(LVar0, REFLECTION_FLOOR_WALL)
    Set(LVar1, GF_PRA_BrokeIllusion)
    Exec(N(EVS_SetupReflections))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Exec(N(EVS_SetupMusic))
    IfEq(GF_PRA13_BombedWallA, FALSE)
        BindTrigger(Ref(N(EVS_BlastWall_Near)), TRIGGER_POINT_BOMB, Ref(N(BombPos_NearWall)), 1, 0)
        Call(EnableModel, MODEL_o952, FALSE)
    Else
        Call(EnableModel, MODEL_g260, FALSE)
        Call(EnableModel, MODEL_g265, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_PRA13_BombedWallB, FALSE)
        BindTrigger(Ref(N(EVS_BlastWall_Far)), TRIGGER_POINT_BOMB, Ref(N(BombPos_FarWall)), 1, 0)
        Call(EnableModel, MODEL_o1009, FALSE)
    Else
        Call(EnableModel, MODEL_g289, FALSE)
        Call(EnableModel, MODEL_g290, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
