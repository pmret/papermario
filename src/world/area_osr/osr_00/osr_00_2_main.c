#include "osr_00.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(CreateSunshine)) {
    fx_sun(FX_SUN_FROM_RIGHT, 0.0f, 0.0f, 0.0f, 0.0f, 0);
    return ApiStatus_DONE2;
}

#include "world/common/todo/SpawnSunEffect.inc.c"

EvtScript N(EVS_ExitWalk_mac_01_2) = EVT_EXIT_WALK(60, osr_00_ENTRY_0, "mac_01", mac_01_ENTRY_2);
EvtScript N(EVS_ExitDoors_kkj_00_6) = EVT_EXIT_DOUBLE_DOOR(osr_00_ENTRY_2, "kkj_00", kkj_00_ENTRY_6, COLLIDER_deilitn, MODEL_d2, MODEL_d1);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mac_01_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_00_6)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitn, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(osr_00_ENTRY_2)
            Set(LVar2, MODEL_d2)
            Set(LVar3, MODEL_d1)
            ExecWait(EnterDoubleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(osr_00_ENTRY_3)
            Exec(N(EVS_Scene_ShowInvitation))
        CaseEq(osr_00_ENTRY_4)
            Exec(N(EVS_Scene_ApproachParty))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TexPan_Fountain) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_fw1, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_w2, TEX_PANNER_2)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(    0, -200,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(    0,    0,    0,  300)
        TEX_PAN_PARAMS_FREQ(    0,    0,    0,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACH_CASTLE_GROUNDS)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Switch(GB_StoryProgress)
        CaseEq(STORY_INTRO)
            Call(N(CreateSunshine))
            Call(MakeNpcs, FALSE, Ref(N(IntroNPCs)))
        CaseGe(STORY_EPILOGUE)
            Call(N(SpawnSunEffect))
            Call(MakeNpcs, FALSE, Ref(N(EpilogueNPCs)))
    EndSwitch
    Call(GetEntryID, LVar0)
    IfNe(LVar0, osr_00_ENTRY_3)
        Exec(N(EVS_SetupMusic))
    EndIf
    Call(GetEntryID, LVar0)
    IfNe(LVar0, osr_00_ENTRY_3)
        Exec(N(EVS_TexPan_Fountain))
        Call(PlaySoundAtF, SOUND_LOOP_OSR_FOUNTAIN_INTACT, SOUND_SPACE_WITH_DEPTH, 300, 0, 400)
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
