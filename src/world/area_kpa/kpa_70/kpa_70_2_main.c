#include "kpa_70.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_SetupChainDrive) = {
    EVT_CALL(LoadAnimatedModel, 0, EVT_PTR(N(ChainDriveSkeleton)))
    EVT_CALL(PlayModelAnimation, 0, EVT_PTR(N(AS_ChainDriveAnim)))
    EVT_CALL(SetAnimatedModelRootPosition, 0, 0, 0, 0)
    EVT_CALL(SetAnimatedModelRenderMode, 0, RENDER_MODE_SURFACE_OPA)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_kpa_62_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(3)
    EVT_SET(LVar0, kpa_70_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittw)
    EVT_SET(LVar2, MODEL_o1431)
    EVT_SET(LVar3, MODEL_o1432)
    EVT_EXEC(ExitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("kpa_62"), kpa_62_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitWalk_kpa_50_0) = EVT_EXIT_WALK(60, kpa_70_ENTRY_1, "kpa_50", kpa_50_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_kpa_50_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_Lava) = {
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( 1000,    0, 2000,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_o1558, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_o1825, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_m01, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_m02, TEX_PANNER_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Update_Gears) = {
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_CALL(RotateModel, MODEL_o1773, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_o1774, LVar0, 0, 0, -1)
        EVT_CALL(RotateModel, MODEL_o1777, LVar0, 0, 0, -1)
        EVT_ADD(LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(InitAnimatedModels)
    EVT_EXEC(N(EVS_SetupChainDrive))
    EVT_THREAD
        EVT_CALL(PlaySoundAt, SOUND_LOOP_KPA_CHAIN_DRIVE, SOUND_SPACE_DEFAULT, 800, 100, -200)
        EVT_WAIT(28)
        EVT_LOOP(0)
            EVT_CALL(PlaySoundAt, SOUND_KPA_DUMP_LAVA, SOUND_SPACE_DEFAULT, 800, 100, -200)
            EVT_WAIT(90)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_EXEC(N(EVS_Update_Gears))
    EVT_EXEC(N(EVS_TexPan_Lava))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_62_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittw, 1, 0)
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_70_ENTRY_0)
            EVT_THREAD
                EVT_SET(LVar2, MODEL_o1431)
                EVT_SET(LVar3, MODEL_o1432)
                EVT_EXEC_WAIT(EnterDoubleDoor)
                EVT_EXEC_WAIT(N(EVS_BindExitTriggers))
            EVT_END_THREAD
        EVT_CASE_EQ(kpa_70_ENTRY_1)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
