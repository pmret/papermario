#include "kkj_11.h"
#include "entity.h"

s32 N(PeachKeyList)[] = {
    ITEM_PEACH_KEY1,
    ITEM_NONE
};

#include "world/common/todo/RemovePadlock.inc.c"

EvtScript N(EVS_ItemPrompt_Lock) = {
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
    EVT_CALL(PlaySoundAt, SOUND_0269, SOUND_SPACE_DEFAULT, 0, 10, 490)
    EVT_SET(LVar0, MV_PadlockEntityIdx)
    EVT_CALL(N(RemovePadlock))
    EVT_WAIT(5)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_KKJ11_UnlockedKitchen, TRUE)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_10_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_IF_LE(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        EVT_IF_EQ(GF_KKJ11_UnlockedKitchen, FALSE)
            EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 0, 10, 490, 180, MAKE_ENTITY_END)
            EVT_SET(MV_PadlockEntityIdx, LVar0)
            EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_Lock)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(PeachKeyList)), 0, 1)
        EVT_ELSE
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kkj_10_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
