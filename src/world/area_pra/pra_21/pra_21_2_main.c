#include "pra_21.h"

s32 N(D_802401C0_D780E0)[] = {
    MODEL_o977,
    -1 
};

s32 N(D_802401C8_D780E8)[] = {
    MODEL_o976,
    -1 
};

EvtScript N(D_802401D0_D780F0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_21_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittnnw)
    EVT_SET(LVar2, MODEL_o774)
    EVT_SET(LVar3, DOOR_SWING_IN)
    EVT_EXEC(ExitSingleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_20"), pra_20_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240274_D78194) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, 1)
    EVT_SET(LVar1, 32)
    EVT_SET(LVar2, EVT_PTR(N(D_802401C0_D780E0)))
    EVT_SET(LVar3, EVT_PTR(N(D_802401C8_D780E8)))
    EVT_EXEC(BaseExitDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_36"), pra_36_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240318_D78238) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_802401D0_D780F0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnnw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80240274_D78194)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnne, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80240360_D78280) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_21_ENTRY_0)
            EVT_SET(LVar2, MODEL_o774)
            EVT_SET(LVar3, DOOR_SWING_IN)
            EVT_EXEC_WAIT(EnterSingleDoor)
        EVT_CASE_EQ(pra_21_ENTRY_1)
            EVT_SET(LVar2, EVT_PTR(N(D_802401C0_D780E0)))
            EVT_SET(LVar3, EVT_PTR(N(D_802401C8_D780E8)))
            EVT_EXEC_WAIT(BaseEnterDoor)
    EVT_END_SWITCH
    EVT_EXEC(N(D_80240318_D78238))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_CRYSTAL_PALACE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 24, 24, 40)
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_IF_LT(GB_StoryProgress, STORY_CH7_FOUND_HIDDEN_ROOM_UNDER_STATUE)
        EVT_SET(LVar0, 0)
    EVT_ELSE
        EVT_SWITCH(GB_PRA_TwinStatueState)
            EVT_CASE_EQ(0)
                EVT_SET(LVar0, -50)
            EVT_CASE_EQ(1)
                EVT_SET(LVar0, -50)
            EVT_CASE_EQ(2)
                EVT_SET(LVar0, 50)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ParentColliderToModel, COLLIDER_o1063, MODEL_o980)
    EVT_CALL(TranslateModel, MODEL_o980, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o981, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o982, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o983, LVar0, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o984, LVar0, 0, 0)
    EVT_CALL(UpdateColliderTransform, COLLIDER_o1063)
    EVT_EXEC(N(D_80240360_D78280))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
