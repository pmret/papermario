
#include "kpa_52.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(KeyList_CastleDoor)[] = {
    ITEM_BOWSER_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_Door) = {
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        Return
    EndIf
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_KPA52_UnlockedDoor, true)
    Call(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_PadlockEntityID)
    Call(N(RemovePadlock))
    Set(LVar1, 0)
    Wait(5)
    Call(CloseChoicePopup)
    Unbind
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_40_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte1, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_KPA52_UnlockedDoor, false)
        Call(MakeEntity, Ref(Entity_Padlock), 352, 10, -25, 270, MAKE_ENTITY_END)
        Set(MV_PadlockEntityID, LVar0)
        BindPadlock(Ref(N(EVS_UnlockPrompt_Door)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList_CastleDoor)), 0, 1)
    Else
        BindTrigger(Ref(N(EVS_ExitDoors_kpa_40_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tte1, 1, 0)
    EndIf
    Return
    End
};
