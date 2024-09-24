#include "effects.h"
#include "sprite/player.h"

EvtScript N(EVS_UnkJP00) = {
    Call(N(StashVars))
    Call(SetPlayerAnimation, ANIM_Mario1_GetItem)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    Call(GetPlayerPos, LVar5, LVar6, LVar7)
    Add(LVar6, 50)
    Call(MakeItemEntity, LVarA, LVar5, LVar6, LVar7, 1, 0)
    Set(LVarD, LVar0)
    Call(GetPlayerPos, LVar5, LVar6, LVar7)
    Add(LVar5, -15)
    Add(LVar6, 40)
    Call(MakeItemEntity, LVarB, LVar5, LVar6, LVar7, 1, 0)
    Set(LVarE, LVar0)
    Call(GetPlayerPos, LVar5, LVar6, LVar7)
    Add(LVar5, 15)
    Add(LVar6, 40)
    Call(MakeItemEntity, LVarC, LVar5, LVar6, LVar7, 1, 0)
    Set(LVarF, LVar0)
    Thread
        Wait(4)
        Call(GetPlayerPos, LVar3, LVar4, LVar5)
        Add(LVar4, 50)
        Add(LVar5, 2)
        Add(LVar3, 8)
        PlayEffect(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
        Add(LVar3, -16)
        PlayEffect(EFFECT_SPARKLES, 3, LVar3, LVar4, LVar5, 20)
    EndThread
    Call(PlaySound, SOUND_JINGLE_GOT_KEY)
    Call(N(GetItemName), LVarA)
    Call(SetMessageText, LVarA, 0)
    Call(N(GetItemName), LVarB)
    Call(SetMessageText, LVarB, 1)
    Call(N(GetItemName), LVarC)
    Call(SetMessageText, LVarC, 2)
    Call(ShowMessageAtScreenPos, MSG_Menus_JP_0009, 160, 40)
    Call(RemoveItemEntity, LVarD)
    Call(RemoveItemEntity, LVarE)
    Call(RemoveItemEntity, LVarF)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(N(StashVars))
    Return
    End
};

EvtScript N(EVS_Chest_ShowGotItem) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_FULL)
    Wait(40)
    Call(ShowGotItem, LVar0, FALSE, 0)
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Return
    Return
    End
};
