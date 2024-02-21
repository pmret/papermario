#include "kkj_11.h"
#include "entity.h"

s32 N(PeachKeyList)[] = {
    ITEM_PEACH_KEY1,
    ITEM_NONE
};

#include "world/common/todo/RemovePadlock.inc.c"

EvtScript N(EVS_ItemPrompt_Lock) = {
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
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, 0, 10, 490)
    Set(LVar0, MV_PadlockEntityIdx)
    Call(N(RemovePadlock))
    Wait(5)
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_KKJ11_UnlockedKitchen, TRUE)
    Call(CloseChoicePopup)
    Unbind
    BindTrigger(Ref(N(EVS_ExitDoors_kkj_10_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfLe(GB_StoryProgress, STORY_CH4_BEGAN_PEACH_MISSION)
        IfEq(GF_KKJ11_UnlockedKitchen, FALSE)
            Call(MakeEntity, Ref(Entity_Padlock), 0, 10, 490, 180, MAKE_ENTITY_END)
            Set(MV_PadlockEntityIdx, LVar0)
            BindPadlock(Ref(N(EVS_ItemPrompt_Lock)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(PeachKeyList)), 0, 1)
        Else
            BindTrigger(Ref(N(EVS_ExitDoors_kkj_10_1)), TRIGGER_WALL_PRESS_A, COLLIDER_tts, 1, 0)
        EndIf
    EndIf
    Return
    End
};
