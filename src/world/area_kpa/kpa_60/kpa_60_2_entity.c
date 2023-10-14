#include "kpa_60.h"
#include "entity.h"

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

s32 N(KeyList_FrontDoor)[] = {
    ITEM_BOWSER_CASTLE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_FrontDoor) = {
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
    EVT_SET(GF_KPA62_UnlockedFrontDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_PadLockEntityID, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_PadLockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kpa_70_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittn, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_KPA62_UnlockedFrontDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), -200, 10, -207, 0, MAKE_ENTITY_END)
        EVT_SET(MV_PadLockEntityID, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_FrontDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(KeyList_FrontDoor)), 0, 1)
    EVT_ELSE
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_kpa_70_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittn, 1, 0)
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), -532, 145, -59, 0, ITEM_DEEP_FOCUS3, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KPA62_BadgeBlock_DeepFocus3)
    EVT_RETURN
    EVT_END
};
