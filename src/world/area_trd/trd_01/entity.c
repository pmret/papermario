#include "trd_01.h"
#include "entity.h"

extern EvtScript N(EVS_ExitDoors_trd_02_0);

EvtScript N(EVS_FocusCamOnLock) = {
    Label(0)
        IfEq(GF_TRD01_Item_FortressKey, TRUE)
            Call(AwaitPlayerApproach, 320, 0, 40)
            Call(UseSettingsFrom, CAM_DEFAULT, 220, 0, 0)
            Call(SetPanTarget, CAM_DEFAULT, 300, 0, 0)
            Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
            Call(GetCamPosA, CAM_DEFAULT, LVar0, LVar1)
            Call(SetCamPosA, CAM_DEFAULT, Float(-64.0), LVar1)
            Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
            Call(PanToTarget, CAM_DEFAULT, 0, 1)
            Call(AwaitPlayerLeave, 320, 0, 60)
            Call(PanToTarget, CAM_DEFAULT, 0, 0)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_UnlockDoors) = {
    SetGroup(EVT_GROUP_00)
    SuspendGroup(EVT_GROUP_01)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_01)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        ResumeGroup(EVT_GROUP_01)
        Return
    EndIf
    Call(FindKeyItem, ITEM_KOOPA_FORTRESS_KEY, LVar0)
    Call(RemoveKeyItemAt, LVar0)
    Call(CloseChoicePopup)
    Set(GF_TRD01_UnlockedDoor, TRUE)
    Call(N(GetEntityPosition), MV_Padlock_EntityIndex, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_Padlock_EntityIndex)
    Call(N(RemovePadlock))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    ResumeGroup(EVT_GROUP_01)
    Unbind
    Return
    End
};

EvtScript N(EVS_BindLockTrigger) = {
    BindTrigger(Ref(N(EVS_ExitDoors_trd_02_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TRD01_UnlockedDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 315, 8, 0, -80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BindLockTrigger)))
        Set(MV_Padlock_EntityIndex, LVar0)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH1_RAISED_SUBMERGED_STAIRS)
        Call(MakeEntity, Ref(Entity_BlueSwitch), 0, 220, 255, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TRD01_RaiseStairs))
    EndIf
    Call(MakeItemEntity, ITEM_SMASH_CHARGE, -268, 656, -40, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_TRD01_Item_SmashCharge)
    IfEq(GF_TRD01_Defeated_KoopaGuard, TRUE)
        IfEq(GF_TRD01_Item_FortressKey, FALSE)
            Call(MakeItemEntity, ITEM_KOOPA_FORTRESS_KEY, 254, 0, 30, ITEM_SPAWN_MODE_KEY, GF_TRD01_Item_FortressKey)
        EndIf
    EndIf
    Return
    End
};
