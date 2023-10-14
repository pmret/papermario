#include "kpa_113.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(KeyList_BowsersCastle)[] = {
    ITEM_BOWSER_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_ExitDoors_kpa_82_0) = EVT_EXIT_DOUBLE_DOOR(kpa_113_ENTRY_1, "kpa_82", kpa_82_ENTRY_0, COLLIDER_deiliett, MODEL_o136, MODEL_o137);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_UnlockPrompt_LockedDoor) = {
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
    EVT_CALL(PlaySound, SOUND_USE_KEY)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_KPA113_UnlockedDoor, TRUE)
    EVT_SET(LVar0, MV_PadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_82_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliett, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KPA113_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 418, 10, 100, 280, MAKE_ENTITY_END)
        EVT_SET(MV_PadlockEntityID, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_LockedDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList_BowsersCastle)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_82_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deiliett, 1, 0)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 375, 60, 50, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
