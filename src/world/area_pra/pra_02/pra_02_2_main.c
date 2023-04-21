#include "pra_02.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"
#include "../common/GlassShimmer.inc.c"

EvtScript N(EVS_UpdateShiftingWallPos) = {
    EVT_CALL(TranslateGroup, MODEL_g293, 0, 250, 0)
    EVT_CALL(TranslateGroup, MODEL_g291, 0, MV_WallPosOffset, 0)
    EVT_RETURN
    EVT_END
};

s32 N(NearLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, -1 };
s32 N(FarLeftDoorModelsL)[] = { MODEL_o859, -1 };
s32 N(FarLeftDoorModelsR)[] = { MODEL_o861, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o772, MODEL_o844, MODEL_o859, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o768, MODEL_o846, MODEL_o861, -1 };

s32 N(FarBlueDoorModelsL)[] = { MODEL_o1162, -1 };
s32 N(FarBlueDoorModelsR)[] = { MODEL_o1160, -1 };
s32 N(FarRedDoorModelsL)[] = { MODEL_o952, -1 };
s32 N(FarRedDoorModelsR)[] = { MODEL_o950, -1 };

s32 N(NearBlueDoorModelsL)[] = { MODEL_o1156, -1 };
s32 N(NearBlueDoorModelsR)[] = { MODEL_o1158, -1 };
s32 N(NearRedDoorModelsL)[] = { MODEL_o946, -1 };
s32 N(NearRedDoorModelsR)[] = { MODEL_o948, -1 };

s32 N(BothBlueDoorModelsL)[] = { MODEL_o1156, MODEL_o1162, -1 };
s32 N(BothBlueDoorModelsR)[] = { MODEL_o1158, MODEL_o1160, -1 };
s32 N(BothRedDoorModelsL)[] = { MODEL_o946, MODEL_o952, -1 };
s32 N(BothRedDoorModelsR)[] = { MODEL_o948, MODEL_o950, -1 };

s32 N(NearCenterDoorModels)[] = { MODEL_o847, -1 };
s32 N(FarCenterDoorModels)[] = { MODEL_o774, -1 };
s32 N(EmptyModelList)[] = { -1 };

EvtScript N(EVS_ExitDoors_pra_01_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, pra_02_ENTRY_0)
    EVT_SET(LVar1, 24)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_01"), pra_01_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_03_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, pra_02_ENTRY_1)
    EVT_SET(LVar1, 56)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(NearCenterDoorModels)))
        EVT_SET(LVar3, EVT_PTR(N(FarCenterDoorModels)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearCenterDoorModels)))
        EVT_SET(LVar3, EVT_PTR(N(EmptyModelList)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_03"), pra_03_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_16_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, pra_02_ENTRY_2)
    EVT_SET(LVar1, 36)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothRedDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothRedDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearRedDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearRedDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_16"), pra_16_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_13_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, pra_02_ENTRY_2)
    EVT_SET(LVar1, 36)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothBlueDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothBlueDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(NearBlueDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(NearBlueDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_13"), pra_13_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_16_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, pra_02_ENTRY_3)
    EVT_SET(LVar1, 32)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothRedDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothRedDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(FarRedDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(FarRedDoorModelsR)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_16"), pra_16_ENTRY_3)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_13_3) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
    EVT_SET(LVar0, pra_02_ENTRY_3)
    EVT_SET(LVar1, 32)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(BothBlueDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(BothBlueDoorModelsR)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(FarBlueDoorModelsL)))
        EVT_SET(LVar3, EVT_PTR(N(FarBlueDoorModelsR)))
    EVT_END_IF
EVT_END_IF
EVT_EXEC(BaseExitDoor)
EVT_WAIT(17)
EVT_CALL(GotoMap, EVT_PTR("pra_13"), pra_13_ENTRY_3)
EVT_WAIT(100)
EVT_RETURN
EVT_END
};

EvtScript N(EVS_ExitDoors_pra_04_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, pra_02_ENTRY_4)
    EVT_SET(LVar1, 51)
    EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
        EVT_SET(LVar2, EVT_PTR(N(NearCenterDoorModels)))
        EVT_SET(LVar3, EVT_PTR(N(FarCenterDoorModels)))
    EVT_ELSE
        EVT_SET(LVar2, EVT_PTR(N(EmptyModelList)))
        EVT_SET(LVar3, EVT_PTR(N(FarCenterDoorModels)))
    EVT_END_IF
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_04"), pra_04_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_01_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
    EVT_SET(LVar0, pra_02_ENTRY_5)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_01"), pra_01_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_01_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_03_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittssw, 1, 0)
    EVT_IF_EQ(GF_PRA02_DoorColorToggle, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne2, COLLIDER_FLAGS_UPPER_MASK)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_PRA02_UnlockedRedDoor, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_16_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_16_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_END_IF
    EVT_IF_EQ(GF_PRA02_UnlockedBlueDoor, TRUE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse2, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_13_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne2, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_04_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnnw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_02_ENTRY_0)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_IF_EQ(GF_PRA02_Visited, FALSE)
                EVT_SET(GF_PRA02_Visited, TRUE)
                EVT_SET(GB_StoryProgress, STORY_CH7_ARRIVED_AT_CRYSTAL_PALACE)
            EVT_END_IF
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_02_ENTRY_1)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(NearCenterDoorModels)))
                EVT_SET(LVar3, EVT_PTR(N(FarCenterDoorModels)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearCenterDoorModels)))
                EVT_SET(LVar3, EVT_PTR(N(EmptyModelList)))
            EVT_END_IF
        EVT_CASE_EQ(pra_02_ENTRY_2)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_IF_EQ(GF_PRA02_DoorColorToggle, FALSE)
                EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                    EVT_SET(LVar2, EVT_PTR(N(BothRedDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(BothRedDoorModelsR)))
                EVT_ELSE
                    EVT_SET(LVar2, EVT_PTR(N(NearRedDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(NearRedDoorModelsR)))
                EVT_END_IF
            EVT_ELSE
                EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                    EVT_SET(LVar2, EVT_PTR(N(BothBlueDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(BothBlueDoorModelsR)))
                EVT_ELSE
                    EVT_SET(LVar2, EVT_PTR(N(NearBlueDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(NearBlueDoorModelsR)))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(pra_02_ENTRY_3)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_CREAKY)
            EVT_IF_EQ(GF_PRA02_DoorColorToggle, FALSE)
                EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                    EVT_SET(LVar2, EVT_PTR(N(BothRedDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(BothRedDoorModelsR)))
                EVT_ELSE
                    EVT_SET(LVar2, EVT_PTR(N(FarRedDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(FarRedDoorModelsR)))
                EVT_END_IF
            EVT_ELSE
                EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                    EVT_SET(LVar2, EVT_PTR(N(BothBlueDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(BothBlueDoorModelsR)))
                EVT_ELSE
                    EVT_SET(LVar2, EVT_PTR(N(FarBlueDoorModelsL)))
                    EVT_SET(LVar3, EVT_PTR(N(FarBlueDoorModelsR)))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(pra_02_ENTRY_4)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(NearCenterDoorModels)))
                EVT_SET(LVar3, EVT_PTR(N(FarCenterDoorModels)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(EmptyModelList)))
                EVT_SET(LVar3, EVT_PTR(N(FarCenterDoorModels)))
            EVT_END_IF
        EVT_CASE_EQ(pra_02_ENTRY_5)
            EVT_CALL(UseDoorSounds, DOOR_SOUNDS_BASIC)
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
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_IF_EQ(GF_PRA02_DoorColorToggle, FALSE)
        EVT_SET(MV_WallPosOffset, 0)
        EVT_CALL(SetGroupVisibility, MODEL_g308, MODEL_GROUP_HIDDEN)
    EVT_ELSE
        EVT_SET(MV_WallPosOffset, -250)
        EVT_CALL(SetGroupVisibility, MODEL_g307, MODEL_GROUP_HIDDEN)
    EVT_END_IF
    EVT_EXEC(N(EVS_UpdateShiftingWallPos))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ManagePoundableSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o1342, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ManagePoundableSwitch)), TRIGGER_FLOOR_TOUCH, COLLIDER_o1344, 1, 0)
    EVT_SET(LVar0, MODEL_o549)
    EVT_SET(LVar1, MODEL_o549)
    EVT_SET(LVar2, TEX_PANNER_0)
    EVT_EXEC(N(EVS_GlassShimmer))
    EVT_SET(LVar0, REFLECTION_WALL_ONLY)
    EVT_SET(LVar1, GF_PRA_BrokeIllusion)
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
