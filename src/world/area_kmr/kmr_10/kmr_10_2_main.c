#include "kmr_10.h"

EvtScript N(EVS_ExitWalk_kmr_11_1) = EVT_EXIT_WALK(60, kmr_10_ENTRY_0, "kmr_11", kmr_11_ENTRY_1);
EvtScript N(EVS_ExitWalk_mac_00_0) = EVT_EXIT_WALK(60, kmr_10_ENTRY_1, "mac_00", mac_00_ENTRY_0);
EvtScript N(EVS_ExitWalk_mac_00_2) = EVT_EXIT_WALK(60, kmr_10_ENTRY_2, "mac_00", mac_00_ENTRY_2);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_11_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mac_00_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mac_00_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili3, 1, 0)
    Return
    End
};

EvtScript N(D_80240828_8D8CF8) = {
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Call(ClearDefeatedEnemies)
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    ExecWait(N(EVS_SetupFoliage))
    IfEq(GB_StoryProgress, STORY_CH0_KAMMY_RETURNED_TO_BOWSER)
        IfEq(AF_KMR_0D, FALSE)
            Wait(50)
            Set(AF_KMR_0D, TRUE)
        EndIf
    EndIf
    Exec(N(D_80240828_8D8CF8))
    Wait(1)
    Set(GF_MAC01_RowfBadgesChosen, FALSE)
    Return
    End
};
