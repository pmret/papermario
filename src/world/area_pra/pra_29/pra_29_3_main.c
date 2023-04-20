#include "pra_29.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o859, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o861, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o772, MODEL_o859, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o768, MODEL_o861, -1 };

s32 N(NearRightDoorModelsL)[] = { MODEL_o995, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o997, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o1096, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o1094, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o995, MODEL_o1096, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o997, MODEL_o1094, -1 };

EvtScript N(EVS_ExitDoors_pra_20_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_29_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_20"), pra_20_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_34_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_29_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearRightDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_34"), pra_34_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_34_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_29_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(FarRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(FarRightDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_34"), pra_34_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_20_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_29_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_deilittnw)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_20"), pra_20_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_20_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_34_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_34_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_20_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_29_ENTRY_0)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_29_ENTRY_1)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearRightDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_29_ENTRY_2)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(FarRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(FarRightDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_29_ENTRY_3)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupBridge))
    EVT_SET(LVar0, MODEL_o945)
    EVT_SET(LVar1, MODEL_o945)
    EVT_SET(LVar2, TEX_PANNER_0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_EXTENDED_PALACE_BRIDGE)
        EVT_SET(LVar1, TRUE)
    EVT_ELSE
        EVT_SET(LVar1, FALSE)
    EVT_END_IF
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
