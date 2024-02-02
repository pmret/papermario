#include "kkj_23.h"

#include "../common/RestoreFromPeachState.inc.c"
#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_EndPeachChapter6) = {
    Set(LVar0, GB_KKJ_LastPartner)
    Call(N(RestoreFromPeachState))
    Call(PlaySound, SOUND_SLIDE_WHISTLE_OUT)
    Call(GotoMapSpecial, Ref("flo_00"), flo_00_ENTRY_A, TRANSITION_END_PEACH_INTERLUDE)
    Wait(100)
}; //@bug script not properly terminated

EvtScript N(EVS_ExitDoors_kkj_22_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, kkj_23_ENTRY_0)
    Set(LVar1, COLLIDER_tte)
    Set(LVar2, MODEL_o5)
    Set(LVar3, MODEL_o4)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_22"), kkj_22_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoors_kkj_24_0) = EVT_EXIT_DOUBLE_DOOR(kkj_23_ENTRY_1, "kkj_24", kkj_24_ENTRY_0, COLLIDER_ttw, MODEL_o9, MODEL_o10);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_23_ENTRY_0)
            Set(LVar2, MODEL_o5)
            Set(LVar3, MODEL_o4)
            ExecWait(EnterDoubleDoor)
            IfEq(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
                Exec(N(EVS_Scene_KammyUnmasksPeach))
            Else
                Exec(N(EVS_BowserTauntMario))
            EndIf
        CaseEq(kkj_23_ENTRY_1)
            Set(LVar2, MODEL_o9)
            Set(LVar3, MODEL_o10)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_23)
    EVT_SETUP_CAMERA_DEFAULT()
    IfEq(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        Call(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
        Call(MakeNpcs, FALSE, Ref(N(PeachNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(FinaleNPCs)))
    EndIf
    Exec(N(EVS_SetupMusic))
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_24_0)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_22_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Exec(N(EVS_EnterMap))
    Return
    End
};
