#include "kmr_00.h"

EvtScript N(EVS_ExitWalk_kmr_02_1) = EVT_EXIT_WALK(60, kmr_00_ENTRY_0, "kmr_02", kmr_02_ENTRY_1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kmr_02_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GOOMBA_VILLAGE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(GF_MAP_GoombaVillage, TRUE)
    IfLt(GB_StoryProgress, STORY_CH0_MET_INNKEEPER)
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        Call(ClearDefeatedEnemies)
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_Scene_MarioRevived))
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(EnableModel, MODEL_ji_3, FALSE)
            Exec(N(EVS_BindExitTriggers))
        CaseGe(STORY_CH0_WAKE_UP)
            Call(EnableModel, MODEL_ji_1, FALSE)
            Call(EnableModel, MODEL_ji_2, FALSE)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Wait(1)
    Return
    End
};
