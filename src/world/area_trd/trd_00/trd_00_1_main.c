#include "trd_00.h"
#include "sprite/player.h"

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_nok_15_1) = EVT_EXIT_WALK(60, trd_00_ENTRY_0, "nok_15", nok_15_ENTRY_1);
EvtScript N(EVS_ExitDoors_trd_01_0) = EVT_EXIT_DOUBLE_DOOR(trd_00_ENTRY_1, "trd_01", trd_01_ENTRY_0, COLLIDER_tt2, MODEL_o62, MODEL_doa);
EvtScript N(EVS_ExitDoors_trd_05_1) = EVT_EXIT_DOUBLE_DOOR(trd_00_ENTRY_2, "trd_05", trd_05_ENTRY_1, COLLIDER_tt3, MODEL_o70, MODEL_o69);
EvtScript N(EVS_ExitWalk_trd_05_2) = EVT_EXIT_WALK(60, trd_00_ENTRY_3, "trd_05", trd_05_ENTRY_2);
EvtScript N(EVS_ExitWalk_nok_15_2) = EVT_EXIT_WALK(60, trd_00_ENTRY_4, "nok_15", nok_15_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_15_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_05_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_trd_05_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili5, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_nok_15_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilit, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240B34_99A7A4) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerPos,NPC_DISPOSE_LOCATION)
    EVT_CALL(SetNpcPos, NPC_PARTNER, NPC_DISPOSE_LOCATION)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -730, 0, 400)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 20, 0, 400)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, -1000)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, EVT_FLOAT(-20.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -480, 0, 400)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, -1300)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 18, EVT_FLOAT(-11.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_WAIT(5)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_WAIT(82)
    EVT_CALL(SetPlayerPos, -1041, 0, 204)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Walk)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -1041, 0, 204)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(PlayerMoveTo, -900, 200, 30)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, 1)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_00_ENTRY_0)
            EVT_IF_LT(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_FORTRESS)
                EVT_SET(GB_StoryProgress, STORY_CH1_ARRIVED_AT_KOOPA_FORTRESS)
                EVT_EXEC_WAIT(N(D_80240B34_99A7A4))
                EVT_EXEC(N(EVS_BindExitTriggers))
            EVT_ELSE
                EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
                EVT_EXEC(EnterWalk)
            EVT_END_IF
        EVT_CASE_EQ(trd_00_ENTRY_1)
            EVT_SET(LVar2, MODEL_o62)
            EVT_SET(LVar3, MODEL_doa)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_00_ENTRY_2)
            EVT_SET(LVar2, MODEL_o70)
            EVT_SET(LVar3, MODEL_o69)
            EVT_EXEC_WAIT(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(trd_00_ENTRY_3)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(trd_00_ENTRY_4)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(trd_00_ENTRY_5)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TexPan_WaterEdge) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_ue, TEX_PANNER_1)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_AUX, LVar1, 0)
        EVT_ADD(LVar0, 100)
        EVT_SUB(LVar1, 100)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_KOOPA_BROS_FORTRESS)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_SET(GF_MAP_KoopaBrosFortress, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(trd_00_ENTRY_0)
        EVT_CASE_OR_EQ(trd_00_ENTRY_1)
        EVT_CASE_OR_EQ(trd_00_ENTRY_4)
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_TexPan_WaterEdge))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_WAIT(1)
    EVT_IF_EQ(GF_TRD05_BombedWall, FALSE)
        EVT_CALL(SetGroupVisibility, MODEL_g21, MODEL_GROUP_HIDDEN)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt5, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetGroupVisibility, MODEL_ana, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, trd_00_ENTRY_5)
        EVT_WAIT(65)
    EVT_ELSE
        EVT_WAIT(1)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, MODEL_o125, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0,   90,  -60,  -70)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
