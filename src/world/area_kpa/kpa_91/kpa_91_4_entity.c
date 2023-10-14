#include "kpa_91.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(KeyList_PrisonCell)[] = {
    ITEM_PRISON_KEY1,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_PrisonCell) = {
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
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_KPA91_UnlockedDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_PadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(CloseChoicePopup)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OpenCellDoor)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittn, 1, 0)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KPA91_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), -5, 10, 13, 0, MAKE_ENTITY_END)
        EVT_SET(MV_PadlockEntityID, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_PrisonCell)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList_PrisonCell)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OpenCellDoor)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittn, 1, 0)
    EVT_END_IF
    EVT_IF_EQ(GF_KPA91_Defeated_Guard, TRUE)
        EVT_CALL(MakeItemEntity, ITEM_PRISON_KEY1, 60, 0, 55, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA91_Item_PrisonKey1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
