#include "kkj_12.h"

API_CALLABLE(N(DisableSpotlightSources)) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gSpriteShadingProfile->sources[i].flags = LIGHT_SOURCE_DISABLED;
    }

    return ApiStatus_DONE2;
}

#include "../common/SetAvailableDisguise.inc.c"

EvtScript N(EVS_ExitDoors_kkj_11_1) = EVT_EXIT_DOUBLE_DOOR(kkj_12_ENTRY_0, "kkj_11", kkj_11_ENTRY_1,
    COLLIDER_deilit1, MODEL_door1, MODEL_door2);
EvtScript N(EVS_ExitDoors_kkj_13_0) = EVT_EXIT_DOUBLE_DOOR(kkj_12_ENTRY_1, "kkj_13", kkj_13_ENTRY_0,
    COLLIDER_deilit2, MODEL_door4, MODEL_door3);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_11_1)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit1, 1, 0)
    IfEq(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        IfEq(GF_KKJ12_TrickedGuard, FALSE)
            Return
        EndIf
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilit2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kkj_12_ENTRY_0)
            Set(LVar2, MODEL_door1)
            Set(LVar3, MODEL_door2)
            ExecWait(EnterDoubleDoor)
        CaseEq(kkj_12_ENTRY_1)
            Set(LVar2, MODEL_door4)
            Set(LVar3, MODEL_door3)
            ExecWait(EnterDoubleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    Call(SetSpriteShading, SHADING_KKJ_12)
    EVT_SETUP_CAMERA_DEFAULT()
    IfEq(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        Call(N(SetAvailableDisguise), PEACH_DISGUISE_KOOPATROL)
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Else
        Call(EnableModel, MODEL_o694, FALSE)
        Call(EnableModel, MODEL_o695, FALSE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        Call(N(DisableSpotlightSources))
    EndIf
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Exec(N(EVS_BindExitTriggers))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
