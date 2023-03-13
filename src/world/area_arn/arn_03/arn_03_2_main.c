#include "arn_03.h"

EvtScript N(EVS_ExitWalk_arn_07_1) = EVT_EXIT_WALK(60, arn_03_ENTRY_0, "arn_07", arn_07_ENTRY_1);
EvtScript N(EVS_ExitWalk_arn_05_0) = EVT_EXIT_WALK(60, arn_03_ENTRY_1, "arn_05", arn_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_arn_07_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_arn_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetLoadType, LVar1)
    EVT_IF_EQ(LVar1, LOAD_FROM_FILE_SELECT)
        EVT_EXEC(EnterSavePoint)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_ARRIVED_AT_GHOST_TOWN)
        EVT_CALL(SetPlayerPos, -175, 165, 160)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -175, 165, 160)
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
#if VERSION_PAL
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(4 / DT))
#else
        EVT_CALL(SetPlayerSpeed, 4)
#endif
        EVT_CALL(PlayerMoveTo, -55, 160, 0)
        EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
    EVT_EXEC(EnterWalk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GUSTY_GULCH)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_SET(AF_ARN_03, FALSE)
    EVT_SET(AF_ARN_04, FALSE)
    EVT_SET(AF_ARN_05, FALSE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(BeforeNPCs)))
    EVT_ELSE
        EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(AfterNPCs)))
    EVT_END_IF
    EVT_IF_EQ(GF_ARN03_WaitingForPackage, TRUE)
        EVT_SET(MV_Unk_00, 450)
        EVT_SET(MV_Unk_01, 450)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
