#include "arn_07.h"
#include "entity.h"

MAP_RODATA_PAD(1,entity);

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_UnlockDoor) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_MYSTICAL_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GB_StoryProgress, STORY_CH3_UNLOCKED_WINDY_MILL)
    EVT_CALL(N(GetEntityPosition), MV_Unk_00, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_Unk_00)
    EVT_CALL(N(RemovePadlock))
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindLockTrigger) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoor_arn_08_0)), TRIGGER_WALL_PRESS_A, COLLIDER_tt3, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH3_UNLOCKED_WINDY_MILL)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 10, 30, -155, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BindLockTrigger)))
        EVT_SET(MV_Unk_00, LVar0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
