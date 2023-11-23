#include "dro_02.h"

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_ExitWalk_dro_01_1) = EVT_EXIT_WALK(60, dro_02_ENTRY_0, "dro_01", dro_01_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_dro_01_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnReadPoster) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_017C, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterScene) = {
    EVT_CALL(PlaySound, SOUND_LOOP_SBK_RUINS_RISING_DISTANT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 190, 0, -37)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 190, 0, -37)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(200.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(13.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_BG, NULL, ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_GROUPS, -1, ENV_TINT_REMAP)
    EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 44, 32, 177, 0, 0, 0, 0, 0, 0)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 300, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(GetEntryID, LVar0)
        EVT_IF_EQ(LVar0, dro_02_ENTRY_2)
            EVT_CALL(GotoMap, EVT_PTR("sbk_02"), sbk_02_ENTRY_6)
        EVT_ELSE
            EVT_CALL(GotoMap, EVT_PTR("sbk_02"), sbk_02_ENTRY_7)
        EVT_END_IF
        EVT_WAIT(100)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_DRY_DRY_OUTPOST)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_CALL(InitVirtualEntityList)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC_WAIT(N(EVS_SetupRooms))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(dro_02_ENTRY_2)
        EVT_CASE_OR_EQ(dro_02_ENTRY_3)
            EVT_EXEC_WAIT(N(EVS_EnterScene))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_THREAD
        EVT_CALL(SetTexPanner, MODEL_kemuri, 1)
        EVT_SET(LVar0, 0)
        EVT_LABEL(123)
            EVT_ADD(LVar0, 420)
            EVT_IF_GT(LVar0, 0x10000)
                EVT_ADD(LVar0, -0x10000)
            EVT_END_IF
            EVT_CALL(SetTexPanOffset, 1, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_GOTO(123)
    EVT_END_THREAD
    EVT_SET(MF_Unk_00, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnReadPoster)), TRIGGER_WALL_PRESS_A, COLLIDER_poster, 1, 0)
    EVT_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar2, -200)
                EVT_CALL(EnableGroup, MODEL_mazinai, TRUE)
            EVT_ELSE
                EVT_CALL(EnableGroup, MODEL_mazinai, FALSE)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.334))
    EVT_RETURN
    EVT_END
};
