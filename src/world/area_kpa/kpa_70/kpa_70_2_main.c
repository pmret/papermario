#include "kpa_70.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_SetupChainDrive) = {
    Call(LoadAnimatedModel, 0, Ref(N(ChainDriveSkeleton)))
    Call(PlayModelAnimation, 0, Ref(N(AS_ChainDriveAnim)))
    Call(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    Call(SetAnimatedModelRenderMode, 0, RENDER_MODE_SURFACE_OPA)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kpa_62_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Wait(3)
    Set(LVar0, kpa_70_ENTRY_0)
    Set(LVar1, COLLIDER_deilittw)
    Set(LVar2, MODEL_o1431)
    Set(LVar3, MODEL_o1432)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kpa_62"), kpa_62_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kpa_50_0) = EVT_EXIT_WALK(60, kpa_70_ENTRY_1, "kpa_50", kpa_50_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_50_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_Lava) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( 1000,    0, 2000,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o1558, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o1825, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_m01, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_m02, TEX_PANNER_1)
    Return
    End
};

EvtScript N(EVS_Update_Gears) = {
    Set(LVar0, 0)
    Loop(0)
        Call(RotateModel, MODEL_o1773, LVar0, 0, 0, 1)
        Call(RotateModel, MODEL_o1774, LVar0, 0, 0, -1)
        Call(RotateModel, MODEL_o1777, LVar0, 0, 0, -1)
        Add(LVar0, 1)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Call(InitAnimatedModels)
    Exec(N(EVS_SetupChainDrive))
    Thread
        Call(PlaySoundAt, SOUND_LOOP_KPA_CHAIN_DRIVE, SOUND_SPACE_DEFAULT, 800, 100, -200)
        Wait(28)
        Loop(0)
            Call(PlaySoundAt, SOUND_KPA_DUMP_LAVA, SOUND_SPACE_DEFAULT, 800, 100, -200)
            Wait(90)
        EndLoop
    EndThread
    Exec(N(EVS_Update_Gears))
    Exec(N(EVS_TexPan_Lava))
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_62_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_70_ENTRY_0)
            Thread
                Set(LVar2, MODEL_o1431)
                Set(LVar3, MODEL_o1432)
                ExecWait(EnterDoubleDoor)
                ExecWait(N(EVS_BindExitTriggers))
            EndThread
        CaseEq(kpa_70_ENTRY_1)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Exec(N(EVS_SetupMusic))
    Return
    End
};
