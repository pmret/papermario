#include "pra_18.h"

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

#include "../common/GlassShimmer.inc.c"

s32 N(NearRightDoorModelsL)[] = { MODEL_o772, -1 };
s32 N(NearRightDoorModelsR)[] = { MODEL_o768, -1 };
s32 N(FarRightDoorModelsL)[]  = { MODEL_o859, -1 };
s32 N(FarRightDoorModelsR)[]  = { MODEL_o861, -1 };
s32 N(BothRightDoorModelsL)[] = { MODEL_o772, MODEL_o859, -1 };
s32 N(BothRightDoorModelsR)[] = { MODEL_o768, MODEL_o861, -1 };

s32 N(LeftDoorModelsL)[] = { MODEL_o995, MODEL_o996, -1 };
s32 N(LeftDoorModelsR)[] = { MODEL_o997, MODEL_o998, -1 };

EvtScript N(EVS_ExitDoors_pra_16_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_18_ENTRY_0)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_16"), pra_16_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_33_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_18_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittne)
    EVT_SET(LVar2, EVT_PTR(N(LeftDoorModelsL)))
    EVT_SET(LVar3, EVT_PTR(N(LeftDoorModelsR)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_33"), pra_33_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_16_2) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_18_ENTRY_2)
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
    EVT_CALL(GotoMap, EVT_PTR("pra_16"), pra_16_ENTRY_2)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_16_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_33_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_16_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_18_ENTRY_0)
            EVT_IF_EQ(GF_PRA_BrokeIllusion, FALSE)
                EVT_SET(LVar2, EVT_PTR(N(BothRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(BothRightDoorModelsR)))
            EVT_ELSE
                EVT_SET(LVar2, EVT_PTR(N(NearRightDoorModelsL)))
                EVT_SET(LVar3, EVT_PTR(N(NearRightDoorModelsR)))
            EVT_END_IF
        EVT_CASE_EQ(pra_18_ENTRY_1)
            EVT_SET(LVar2, EVT_PTR(N(LeftDoorModelsL)))
            EVT_SET(LVar3, EVT_PTR(N(LeftDoorModelsR)))
        EVT_CASE_EQ(pra_18_ENTRY_2)
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
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_GE(GB_StoryProgress, STORY_CH7_DEFEATED_CLUBBAS)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1174, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetGroupVisibility, MODEL_g298, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1175, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetGroupVisibility, MODEL_g296, MODEL_GROUP_HIDDEN)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
    EVT_ELSE
        EVT_SWITCH(GB_PRA18_ClubbasDefeated)
            EVT_CASE_EQ(1)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
            EVT_CASE_EQ(2)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1175, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(SetGroupVisibility, MODEL_g296, MODEL_GROUP_HIDDEN)
                EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1176, COLLIDER_FLAGS_UPPER_MASK)
                EVT_CALL(SetGroupVisibility, MODEL_g297, MODEL_GROUP_HIDDEN)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
