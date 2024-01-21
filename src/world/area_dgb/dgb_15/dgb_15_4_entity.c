#include "dgb_15.h"
#include "entity.h"

#include "world/common/todo/GetEntityPosition.inc.c"
#include "world/common/todo/RemovePadlock.inc.c"

EvtScript N(EVS_UnlockPrompt_Door) = {
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
    Call(FindKeyItem, ITEM_TUBBA_CASTLE_KEY, LVar0)
    Call(RemoveKeyItemAt, LVar0)
    Call(CloseChoicePopup)
    Set(GF_DGB15_UnlockedUpperFoyer, TRUE)
    Call(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_PadlockEntityID)
    Call(N(RemovePadlock))
    ResumeGroup(EVT_GROUP_01)
    Unbind
    Return
    End
};

EvtScript N(EVS_OpenLockedDoor) = {
    BindTrigger(Ref(N(EVS_ExitDoors_dgb_17_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_DGB15_UnlockedUpperFoyer, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 130, 8, 175, -80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OpenLockedDoor)))
        Set(MV_PadlockEntityID, LVar0)
    EndIf
    Return
    End
};
