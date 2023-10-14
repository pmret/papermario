
#include "kpa_14.h"
#include "entity.h"

// similar to Chest.inc.c, except a script is missing...
#include "world/common/todo/StashVars.inc.c"
#include "world/common/todo/GetItemName.inc.c"
#include "world/common/todo/SomeItemEntityFunc.inc.c"
#include "world/common/todo/IsItemBadge.inc.c"

s32** N(varStash) = NULL;

EvtScript N(EVS_Chest_ShowGotItem) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_FULL)
    EVT_WAIT(40)
    EVT_CALL(ShowGotItem, LVar0, FALSE, 0)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(KeyList_BowsersCastle)[] = {
    ITEM_BOWSER_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_Door) = {
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
    EVT_SET(GF_KPA14_UnlockedDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_PadlockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_PadlockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kpa_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KPA14_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 1995, 40, -162, 270, MAKE_ENTITY_END)
        EVT_SET(MV_PadlockEntityID, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_Door)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList_BowsersCastle)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kpa_01_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilitte, 1, 0)
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_MYSTERY, 350, 30, -150, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA14_Item_Mystery)
    EVT_CALL(MakeItemEntity, ITEM_THUNDER_RAGE, 800, 30, -150, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA14_Item_ThunderRage)
    EVT_RETURN
    EVT_END
};
