#include "pra_39.h"

s32 N(map_init)(void) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_MARIO_REFLECT_FLOOR;
    sprintf(wMapShapeName, "pra_10_shape");
    sprintf(wMapHitName, "pra_10_hit");
    return FALSE;
}

#include "../common/Reflection.inc.c"
#include "../common/Reflection.data.inc.c"

EvtScript N(EVS_ExitDoors_pra_04_1) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_39_ENTRY_0)
    EVT_SET(LVar1, COLLIDER_deilittsw)
    EVT_SET(LVar2, MODEL_o772)
    EVT_SET(LVar3, MODEL_o768)
    EVT_SET(LVar4, MODEL_o844)
    EVT_SET(LVar5, MODEL_o846)
    EVT_EXEC(ExitSplitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_04"), pra_04_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ExitDoors_pra_06_0) = {
    EVT_SET_GROUP(EVT_GROUP_1B)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(LVar0, pra_39_ENTRY_1)
    EVT_SET(LVar1, COLLIDER_deilittse)
    EVT_SET(LVar2, MODEL_o1019)
    EVT_SET(LVar3, MODEL_o1021)
    EVT_SET(LVar4, MODEL_o1020)
    EVT_SET(LVar5, MODEL_o1022)
    EVT_EXEC(ExitSplitDoubleDoor)
    EVT_WAIT(17)
    EVT_CALL(GotoMap, EVT_PTR("pra_06"), pra_06_ENTRY_0)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_04_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittsw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_06_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(pra_39_ENTRY_0)
            EVT_SET(LVar2, MODEL_o772)
            EVT_SET(LVar3, MODEL_o768)
            EVT_SET(LVar4, MODEL_o844)
            EVT_SET(LVar5, MODEL_o846)
            EVT_EXEC_WAIT(EnterSplitDoubleDoor)
        EVT_CASE_EQ(pra_39_ENTRY_1)
            EVT_SET(LVar2, MODEL_o1019)
            EVT_SET(LVar3, MODEL_o1021)
            EVT_SET(LVar4, MODEL_o1020)
            EVT_SET(LVar5, MODEL_o1022)
            EVT_EXEC_WAIT(EnterSplitDoubleDoor)
    EVT_END_SWITCH
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
    EVT_SET(LVar0, REFLECTION_FLOOR_ONLY)
    EVT_SET(LVar1, GF_PRA_BrokeIllusion)
    EVT_EXEC(N(EVS_SetupReflections))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
