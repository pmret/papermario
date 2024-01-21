#include "dgb_05.h"

EvtScript N(EVS_ExitDoor_dgb_03_2) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Set(LVar0, dgb_05_ENTRY_0)
    Set(LVar1, COLLIDER_deilittn)
    Set(LVar2, MODEL_o158)
    Set(LVar3, DOOR_SWING_IN)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("dgb_03"), dgb_03_ENTRY_2)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(UseDoorSounds, DOOR_SOUNDS_BASIC)
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(dgb_05_ENTRY_0)
            Set(LVar2, MODEL_o158)
            Set(LVar3, DOOR_SWING_IN)
            ExecWait(EnterSingleDoor)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TUBBAS_MANOR)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    IfLt(GB_StoryProgress, STORY_CH3_STAR_SPIRIT_RESCUED)
        Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupHole))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitts, COLLIDER_FLAGS_UPPER_MASK)
    Call(EnableModel, MODEL_o297, FALSE)
    BindTrigger(Ref(N(EVS_ExitDoor_dgb_03_2)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittn, 1, 0)
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Return
    End
};
