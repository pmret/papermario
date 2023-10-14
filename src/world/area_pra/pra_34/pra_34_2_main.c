#include "pra_34.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearLeftDoorModelsL)[] = { MODEL_o1012, MODEL_o1013, -1 };
s32 N(NearLeftDoorModelsR)[] = { MODEL_o1014, MODEL_o1015, -1 };
s32 N(FarLeftDoorModelsL)[]  = { MODEL_o1010, MODEL_o1011, -1 };
s32 N(FarLeftDoorModelsR)[]  = { MODEL_o1008, MODEL_o1009, -1 };
s32 N(BothLeftDoorModelsL)[] = { MODEL_o1012, MODEL_o1013, MODEL_o1010, MODEL_o1011, -1 };
s32 N(BothLeftDoorModelsR)[] = { MODEL_o1014, MODEL_o1015, MODEL_o1008, MODEL_o1009, -1 };

s32 N(NearRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o880, MODEL_o881, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o878, MODEL_o879, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o874, MODEL_o875, MODEL_o880, MODEL_o881, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o876, MODEL_o877, MODEL_o878, MODEL_o879, -1 };

EvtScript N(EVS_ExitDoors_pra_29_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_34_ENTRY_0)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_29"), pra_29_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_31_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_34_ENTRY_1)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_31"), pra_31_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_31_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_34_ENTRY_2)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_31"), pra_31_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_29_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_34_ENTRY_3)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_29"), pra_29_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(PalaceKeyList)[] = {
    ITEM_CRYSTAL_PALACE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_Doors) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_PRA34_UnlockedDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_FarPadlockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetEntityPosition), MV_NearPadlockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_FarPadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar0, MV_NearPadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_29_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_29_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_IF_EQ(GF_PRA34_UnlockedDoor, FALSE)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_Doors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(PalaceKeyList)), 0, 1)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_Doors)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(1), EVT_PTR(N(PalaceKeyList)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_31_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_31_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_34_ENTRY_0)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothLeftDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearLeftDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearLeftDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_34_ENTRY_1)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearRightDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_34_ENTRY_2)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(FarRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(FarRightDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_34_ENTRY_3)
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
