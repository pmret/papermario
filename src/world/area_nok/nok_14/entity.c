#include "nok_14.h"
#include "entity.h"

EvtScript N(EVS_ReadSign_NoEntry) = {
    Call(IsStartingConversation, LVar0)
    IfEq(LVar0, true)
        Return
    EndIf
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(DisablePlayerInput, true)
    Call(ShowMessageAtScreenPos, MSG_Menus_0179, 160, 40)
    Call(DisablePlayerInput, false)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Return
    End
};

EvtScript N(EVS_BreakBlock_ThunderBolt) = {
    IfEq(GF_NOK14_Item_ThunderBolt, true)
        Return
    EndIf
    Thread
        Call(DisablePlayerInput, true)
        Loop(25)
            Wait(1)
            Call(GetNpcPos, NPC_KoopaTroopa_02, LVar0, LVar1, LVar2)
            Call(SetItemPos, MV_Item_ThunderBolt, LVar0, LVar1, LVar2)
        EndLoop
        Call(SetNpcPos, NPC_KoopaTroopa_02, NPC_DISPOSE_LOCATION)
        Call(DisablePlayerInput, false)
    EndThread
    Call(SetNpcPos, NPC_KoopaTroopa_02, -345, 75, -117)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_KoopaTroopa_02, Float(1.5))
    IfLe(LVar0, -345)
        Call(NpcJump0, NPC_KoopaTroopa_02, -280, 0, -112, 20)
    Else
        Call(NpcJump0, NPC_KoopaTroopa_02, -410, 0, -112, 20)
    EndIf
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Signpost), -150, 0, -175, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_ReadSign_NoEntry)))
    Set(LVar0, 1)
    IfLt(GB_StoryProgress, STORY_CH1_MADE_SECOND_BRIDGE)
        Set(LVar0, 0)
    EndIf
    IfEq(LVar0, 0)
        Call(MakeEntity, Ref(Entity_BlueSwitch), 100, 0, -185, 0, MAKE_ENTITY_END)
        Call(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_NOK14_HitSwitch))
    EndIf
    Call(MakeItemEntity, ITEM_COIN, -655, 75, -35, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, -640, 75, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinB)
    Call(MakeItemEntity, ITEM_COIN, -640, 75, -50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinC)
    Call(MakeItemEntity, ITEM_COIN, -670, 75, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinD)
    Call(MakeItemEntity, ITEM_COIN, -670, 75, -50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinE)
    Call(MakeEntity, Ref(Entity_BrickBlock), -345, 77, -117, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_BreakBlock_ThunderBolt)))
    Call(MakeItemEntity, ITEM_THUNDER_BOLT, -345, 102, -117, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_ThunderBolt)
    Set(MV_Item_ThunderBolt, LVar0)
    Call(MakeEntity, Ref(Entity_BrickBlock), 200, 60, -160, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 250, 60, -160, 0, ITEM_FIRE_FLOWER, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_NOK14_HiddenItem_FireFlower)
    Call(MakeEntity, Ref(Entity_BrickBlock), 300, 60, -160, 0, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenPanel), -650, 75, -50, 0, MODEL_o251, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_NOK14_HiddenPanel)
    Return
    End
};
