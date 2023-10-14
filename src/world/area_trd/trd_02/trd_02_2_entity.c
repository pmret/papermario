#include "trd_02.h"
#include "entity.h"

extern EvtScript N(EVS_ExitDoors_trd_01_2);

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(D_80242890_9A3870) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_SUSPEND_GROUP(EVT_GROUP_01)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RESUME_GROUP(EVT_GROUP_01)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_TRD02_UnlockedDoor, TRUE)
    EVT_CALL(N(GetEntityPosition), MV_Padlock_EntityIndex, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_Padlock_EntityIndex)
    EVT_CALL(N(RemovePadlock))
    EVT_RESUME_GROUP(EVT_GROUP_01)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BindLockTrigger) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_trd_01_2)), TRIGGER_WALL_PRESS_A, COLLIDER_ttw2, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_EQ(GF_TRD02_UnlockedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), -265, 195, -55, 80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_BindLockTrigger)))
        EVT_SET(MV_Padlock_EntityIndex, LVar0)
    EVT_END_IF
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_LOWERED_SECOND_STAIRS)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 10, 187, 100, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_TRD02_LowerStairs))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
