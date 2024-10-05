#include "trd_04.h"
#include "entity.h"

extern EvtScript N(EVS_ExitDoors_trd_05_0);
extern EvtScript N(EVS_ExitDoors_trd_03_3);

#include "world/common/todo/RemovePadlock.inc.c"

#include "world/common/todo/SetEntityPosition.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(missing_80244D70_4D70)[] = {
    0x00000000, 0x00010101, 0x01010101, 0x01010101,
    0x01000000, 0x00000000, 0x00000101, 0x01010101,
    0x01010101, 0x01010000, 0x00000000, 0x00000001,
    0x01010101, 0x01010101, 0x01010100, 0x00000000,
    0x00000000, 0x01010101, 0x01010101, 0x01010101,
    0x00000000, 0x00000000, 0x00010101, 0x01010101,
    0x01010101, 0x01000000, 0x00000000, 0x00000101,
    0x01010101, 0x01010101, 0x01010000, 0x00000000,
    0x00000001, 0x01010101, 0x01010101, 0x01010100,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x01010101, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00010101, 0x01000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000101, 0x01010000,
    0x00000000, 0x00000000,
};

EvtScript N(EVS_UnlockUpperLeftDoors) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    SuspendGroup(EVT_GROUP_FLAG_INTERACT)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    Call(RemoveKeyItemAt, LVar1)
    Call(CloseChoicePopup)
    Set(GF_TRD04_UnlockedUpperDoor, TRUE)
    Call(N(GetEntityPosition), MV_Unk_00, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_Unk_00)
    Call(N(RemovePadlock))
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Unbind
    Return
    End
};

EvtScript N(EVS_UnlockLowerRightDoors) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    SuspendGroup(EVT_GROUP_FLAG_INTERACT)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_FLAG_INTERACT)
        Return
    EndIf
    Call(RemoveKeyItemAt, LVar1)
    Call(CloseChoicePopup)
    Set(GF_TRD04_UnlockedLowerDoor, TRUE)
    Call(N(GetEntityPosition), MV_Unk_01, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_Unk_01)
    Call(N(RemovePadlock))
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Unbind
    Return
    End
};

EvtScript N(EVS_Padlock_LowerDoors) = {
    BindTrigger(Ref(N(EVS_ExitDoors_trd_05_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte2, 1, 0)
    Return
    End
};

EvtScript N(EVS_Padlock_UpperDoors) = {
    BindTrigger(Ref(N(EVS_ExitDoors_trd_03_3)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw3, 1, 0)
    Return
    End
};

EvtScript N(EVS_DropSwitch) = {
    Call(DisablePlayerInput, TRUE)
    Wait(40 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, -188, 0, -43)
    Call(SetPanTarget, CAM_DEFAULT, -188, 0, -43)
    Call(SetCamDistance, CAM_DEFAULT, Float(510.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(3 * DT)
    Call(PlaySoundAt, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT, -180, 175, -35)
    Call(MakeLerp, 175, 0, 20 * DT, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(N(SetEntityPosition), MV_EntityID_Switch, -180, LVar0, -35)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(PlaySoundAt, SOUND_OBJECT_LAND, SOUND_SPACE_DEFAULT, -180, 0, -35)
    Call(ShakeCam, CAM_DEFAULT, 0, 5, Float(1.0))
    Wait(20 * DT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, Float(400.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(2)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TRD04_UnlockedLowerDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 265, 8, 90, -80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_Padlock_LowerDoors)))
        Set(MV_Unk_01, LVar0)
    EndIf
    IfEq(GF_TRD04_UnlockedUpperDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), -265, 195, -55, 80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_Padlock_UpperDoors)))
        Set(MV_Unk_00, LVar0)
    EndIf
    IfLe(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
        Call(MakeEntity, Ref(Entity_BlueSwitch), NPC_DISPOSE_LOCATION, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TRD04_LowerStairs))
        Set(MV_EntityID_Switch, LVar0)
        IfEq(GB_StoryProgress, STORY_CH1_DEFEATED_BASEMENT_GUARD)
            Call(N(SetEntityPosition), MV_EntityID_Switch, -180, 0, -35)
        EndIf
    EndIf
    Return
    End
};
