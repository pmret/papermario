#include "hos_10.h"

EvtScript N(EVS_Main) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_10_ENTRY_1)
        Wait(75)
    EndIf
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_10_ENTRY_1)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_Descent)))
        CaseEq(hos_10_ENTRY_2)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup_FlyAway)))
        CaseDefault
    EndSwitch
    IfNe(GB_StoryProgress, STORY_INTRO)
        Call(EnableModel, MODEL_mario_o, FALSE)
    EndIf
    Exec(N(EVS_SetupMusic))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_10_ENTRY_1)
            Wait(50)
            Exec(N(EVS_Scene_CastleDescending))
        CaseEq(hos_10_ENTRY_2)
            Exec(N(EVS_Scene_SpiritsFlyingAway))
        CaseEq(hos_10_ENTRY_3)
            ExecWait(N(EVS_Scene_RisingAboveClouds))
        CaseEq(hos_10_ENTRY_4)
            ExecWait(N(EVS_Scene_UnusedWhiteScreen))
        CaseEq(hos_10_ENTRY_5)
            Wait(30)
            Exec(N(EVS_Scene_PreTitle))
    EndSwitch
    Return
    End
};
