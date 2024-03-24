#include "osr_02.h"
#include "effects.h"

API_CALLABLE(N(SetAvailableDisguise)) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitDoor_kpa_121_1) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_METAL)
    Set(LVar0, osr_02_ENTRY_0)
    Set(LVar1, COLLIDER_tt1)
    Set(LVar2, MODEL_o570)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kpa_121"), kpa_121_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitDoor_kkj_10_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
    Set(LVar0, osr_02_ENTRY_1)
    Set(LVar1, COLLIDER_tt2)
    Set(LVar2, MODEL_d2)
    Set(LVar3, MODEL_d1)
    Exec(ExitDoubleDoor)
    Wait(17)
    Call(GotoMap, Ref("kkj_10"), kkj_10_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_KeepPeachFromBowsersCastle) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePartnerAI, 1)
    Call(SpeakToPlayer, NPC_PARTNER, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_Peach_0180)
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    IfEq(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        BindTrigger(Ref(N(EVS_KeepPeachFromBowsersCastle)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    Else
        BindTrigger(Ref(N(EVS_ExitDoor_kpa_121_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tt1, 1, 0)
    EndIf
    BindTrigger(Ref(N(EVS_ExitDoor_kkj_10_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt2, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(osr_02_ENTRY_0)
            Call(UseDoorSounds, DOOR_SOUNDS_METAL)
            Set(LVar2, MODEL_o570)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
        CaseEq(osr_02_ENTRY_1)
            Call(UseDoorSounds, DOOR_SOUNDS_LARGE)
            Set(LVar2, MODEL_d2)
            Set(LVar3, MODEL_d1)
            ExecWait(EnterDoubleDoor)
        CaseEq(osr_02_ENTRY_2)
            Exec(N(EVS_Scene_ReturnStarRod))
    EndSwitch
    Exec(N(EVS_BindExitTriggers))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_PEACHS_CASTLE)
    IfGt(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        Set(GF_MAP_PeachsCastle, TRUE)
    EndIf
    Call(SetSpriteShading, SHADING_OSR_02)
    SetUP_CAMERA_NO_LEAD()
    IfEq(GB_StoryProgress, STORY_CH6_BEGAN_PEACH_MISSION)
        Call(N(SetAvailableDisguise), PEACH_DISGUISE_CLUBBA)
        Call(MakeNpcs, FALSE, Ref(N(PeachNPCs)))
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(osr_02_ENTRY_2)
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_KKJ25_Defeated_Bowser, FALSE)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(-269.16895), Float(50.0), Float(100.22), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(-2.6025392), Float(50.0), Float(161.583), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(182.146), Float(50.0), Float(158.033), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(346.938), Float(50.0), Float(31.861), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(291.045), Float(86.206), Float(-191.08205), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(-105.39165), Float(70.0), Float(-203.115235), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(-52.5), Float(70.0), Float(-233.73735), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(52.5), Float(70.0), Float(-233.73735), 1, LVar0)
        PlayEffect(EFFECT_FLAME, FX_FLAME_PINK, Float(108.229), Float(70.0), Float(-200.6), 1, LVar0)
    Else
        Call(EnableGroup, MODEL_g116, FALSE)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        Call(FadeOutMusic, 0, 500)
    EndIf
    Exec(N(EVS_EnterMap))
    Wait(1)
    IfEq(GB_StoryProgress, STORY_CH8_REACHED_BOWSERS_CASTLE)
        Set(GB_StoryProgress, STORY_CH8_REACHED_PEACHS_CASTLE)
    EndIf
    Return
    End
};
