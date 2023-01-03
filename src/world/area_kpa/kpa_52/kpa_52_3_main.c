
#include "kpa_52.h"

EvtScript N(EVS_ExitDoors_kpa_33_2) = EVT_EXIT_DOUBLE_DOOR(kpa_52_ENTRY_0, "kpa_33", kpa_33_ENTRY_2, COLLIDER_ttw, MODEL_o407, MODEL_o408);
EvtScript N(EVS_ExitDoors_kpa_40_0) = EVT_EXIT_DOUBLE_DOOR(kpa_52_ENTRY_1, "kpa_40", kpa_40_ENTRY_0, COLLIDER_tte1, MODEL_o410, MODEL_o409);
EvtScript N(EVS_ExitDoors_kpa_08_0) = EVT_EXIT_DOUBLE_DOOR(kpa_52_ENTRY_2, "kpa_08", kpa_08_ENTRY_0, COLLIDER_tte2, MODEL_o412, MODEL_o411);

MAP_RODATA_PAD(1, strings);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_33_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(kpa_52_ENTRY_0)
            EVT_SET(LVar0, kpa_52_ENTRY_0)
            EVT_SET(LVar2, MODEL_o407)
            EVT_SET(LVar3, MODEL_o408)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_52_ENTRY_1)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar2, MODEL_o410)
            EVT_SET(LVar3, MODEL_o409)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
        EVT_CASE_EQ(kpa_52_ENTRY_2)
            EVT_SET(LVar0, 2)
            EVT_SET(LVar2, MODEL_o412)
            EVT_SET(LVar3, MODEL_o411)
            EVT_EXEC(EnterDoubleDoor)
            EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_RETURN
    EVT_END
};
