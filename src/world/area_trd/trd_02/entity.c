#include "trd_02.h"
#include "entity.h"

extern EvtScript N(EVS_ExitDoors_trd_01_2);

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(D_80242890_9A3870) = {
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
    Set(GF_TRD02_UnlockedDoor, true)
    Call(N(GetEntityPosition), MV_Padlock_EntityIndex, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_Padlock_EntityIndex)
    Call(N(RemovePadlock))
    ResumeGroup(EVT_GROUP_FLAG_INTERACT)
    Unbind
    Return
    End
};

EvtScript N(EVS_BindLockTrigger) = {
    BindTrigger(Ref(N(EVS_ExitDoors_trd_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_TRD02_UnlockedDoor, false)
        Call(MakeEntity, Ref(Entity_Padlock), -265, 195, -55, 80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_BindLockTrigger)))
        Set(MV_Padlock_EntityIndex, LVar0)
    EndIf
    IfLt(GB_StoryProgress, STORY_CH1_LOWERED_SECOND_STAIRS)
        Call(MakeEntity, Ref(Entity_BlueSwitch), 10, 187, 100, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TRD02_LowerStairs))
    EndIf
    Return
    End
};
