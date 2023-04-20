#include "pra_20.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

s32 N(NearSingleDoorModels)[] = { MODEL_o999, MODEL_o1000, -1 };
s32 N(FarSingleDoorModels)[]  = { MODEL_o997, MODEL_o998, -1 };

s32 N(NearRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, -1 };

s32 N(BackRightDoorModelsL)[] = { MODEL_o880, MODEL_o881, -1 };
s32 N(BackRightDoorModelsR)[] = { MODEL_o878, MODEL_o879, -1 };

s32 N(BothRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, MODEL_o880, MODEL_o881, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, MODEL_o878, MODEL_o879, -1 };

s32 N(ModelListNone)[] = { -1 };

EvtScript N(EVS_ExitWalk_pra_19_1) = EVT_EXIT_WALK(60, pra_20_ENTRY_0, "pra_19", pra_19_ENTRY_1);

EvtScript N(EVS_ExitDoor_pra_21_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_20_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittssw)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(NearSingleDoorModels)))
        EVT_SET(LVar3, EVT_PTR(N(FarSingleDoorModels)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearSingleDoorModels)))
        EVT_SET(LVar3, EVT_PTR(N(ModelListNone)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_21"), pra_21_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_29_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_20_ENTRY_2)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_29"), pra_29_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_29_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_20_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(BackRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BackRightDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_29"), pra_29_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoor_pra_22_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_20_ENTRY_4)
    EVT_SET(LVar1, COLLIDER_deilittnnw)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(NearSingleDoorModels)))
        EVT_SET(LVar3, EVT_PTR(N(FarSingleDoorModels)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(ModelListNone)))
        EVT_SET(LVar3, EVT_PTR(N(FarSingleDoorModels)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_22"), pra_22_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_pra_19_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_pra_21_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_29_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_29_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_pra_22_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnnw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_20_ENTRY_0)
            EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
            EVT_EXEC(EnterWalk)
        EVT_CASE_EQ(pra_20_ENTRY_1)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(NearSingleDoorModels)))
                EVT_SET(LVar3, EVT_PTR(N(FarSingleDoorModels)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearSingleDoorModels)))
                EVT_SET(LVar3, EVT_PTR(N(ModelListNone)))
            EVT_END_IF
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_20_ENTRY_2)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearRightDoorModelsR)))
            EVT_END_IF
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_20_ENTRY_3)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(BackRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BackRightDoorModelsR)))
            EVT_END_IF
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(pra_20_ENTRY_4)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(NearSingleDoorModels)))
                EVT_SET(LVar3, EVT_PTR(N(FarSingleDoorModels)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(FarSingleDoorModels)))
                EVT_SET(LVar3, EVT_PTR(N(ModelListNone)))
            EVT_END_IF
            EVT_EXEC_WAIT(BaseEnterDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnableModel, MODEL_o981, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1019, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(LVar0, MODEL_o945)
    EVT_SET(LVar1, MODEL_o947)
    EVT_SET(LVar2, TEX_PANNER_0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_SET(LVar0, REFLECTION_FLOOR_WALL)
    EVT_SET(LVar1, GF_PRA_BrokeIllusion)
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
