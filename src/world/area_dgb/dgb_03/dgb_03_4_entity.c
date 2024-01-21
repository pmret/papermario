#include "dgb_03.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_UnlockPrompt_UpperDoor) = {
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
    Set(GF_DGB03_UnlockedThirdFloor, TRUE)
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
    BindTrigger(Ref(N(EVS_ExitDoors_dgb_14_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittnw, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfEq(GF_DGB03_UnlockedThirdFloor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), -355, 218, 75, 80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OpenLockedDoor)))
        Set(MV_PadlockEntityID, LVar0)
    EndIf
    Call(MakeItemEntity, ITEM_STAR_PIECE, 0, 75, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_DGB03_Item_StarPiece)
    Return
    End
};
