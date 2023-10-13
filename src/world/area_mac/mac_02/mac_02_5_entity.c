#include "mac_02.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_OddKey)[] = {
    ITEM_ODD_KEY,
    ITEM_NONE
};

EvtScript N(EVS_ChooseItem_OddKey) = {
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, -470, 30, -155)
    EVT_SET(LVar0, MV_BlueHouseLockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_WAIT(5)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_MAC02_UnlockedHouse, TRUE)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReadSign) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_016B, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnInspect_StreetSign) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0171, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_02_ENTRY_5)
        EVT_IF_EQ(GF_MAC02_UnlockedHouse, FALSE)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), -470, 30, -155, 180, MAKE_ENTITY_END)
            EVT_SET(MV_BlueHouseLockEntityID, LVar0)
            EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ChooseItem_OddKey)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(ItemList_OddKey)), 0, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_ODD_KEY, -412, 20, -320, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_MAC02_Item_OddKey)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 400, 0, 100, 0, MODEL_o236, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_MAC02_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), -375, 0, 190, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnInspect_StreetSign)), TRIGGER_WALL_PRESS_A, COLLIDER_sign, 1, 0)
    EVT_RETURN
    EVT_END
};
