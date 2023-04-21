#include "pra_16.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

// doors on right wall
s32 N(NearRightDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o859, MODEL_o860, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o861, MODEL_o862, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o772, MODEL_o844, MODEL_o859, MODEL_o860, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o768, MODEL_o846, MODEL_o861, MODEL_o862, -1 };

// doors on left wall
s32 N(NearLeftDoorModelsL)[] = { MODEL_o874, MODEL_o875, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o876, MODEL_o877, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o880, MODEL_o881, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o878, MODEL_o879, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o874, MODEL_o875, MODEL_o880, MODEL_o881, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o876, MODEL_o877, MODEL_o878, MODEL_o879, -1 };

EvtScript N(EVS_ExitDoors_pra_02_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, pra_16_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearRightDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_02"), pra_02_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_18_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, pra_16_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_18"), pra_18_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_18_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, pra_16_ENTRY_2)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_18"), pra_18_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_02_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, pra_16_ENTRY_3)
    EVT_SET(LVar1, COLLIDER_deilittnw)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(FarRightDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(FarRightDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_02"), pra_02_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_02_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_18_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_18_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_02_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_16_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearRightDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_16_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_16_ENTRY_2)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(FarLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(FarLeftDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_16_ENTRY_3)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(FarRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(FarRightDoorModelsR)))
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
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC(N(EVS_SetupMusic))
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
