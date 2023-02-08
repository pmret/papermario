#include "nok_14.h"
#include "entity.h"

EvtScript N(EVS_ReadSign_NoEntry) = {
    EVT_CALL(IsStartingConversation, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0179, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakBlock_ThunderBolt) = {
    EVT_IF_EQ(GF_NOK14_Item_ThunderBolt, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_LOOP(25)
            EVT_WAIT(1)
            EVT_CALL(GetNpcPos, NPC_KoopaTroopa_02, LVar0, LVar1, LVar2)
            EVT_CALL(SetItemPos, MV_Item_ThunderBolt, LVar0, LVar1, LVar2)
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_KoopaTroopa_02, NPC_DISPOSE_LOCATION)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_KoopaTroopa_02, -345, 75, -117)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_KoopaTroopa_02, EVT_FLOAT(1.5))
    EVT_IF_LE(LVar0, -345)
        EVT_CALL(NpcJump0, NPC_KoopaTroopa_02, -280, 0, -112, 20)
    EVT_ELSE
        EVT_CALL(NpcJump0, NPC_KoopaTroopa_02, -410, 0, -112, 20)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Signpost), -150, 0, -175, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_ReadSign_NoEntry)))
    EVT_SET(LVar0, 1)
    EVT_IF_LT(GB_StoryProgress, STORY_CH1_MADE_SECOND_BRIDGE)
        EVT_SET(LVar0, 0)
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BlueSwitch), 100, 0, -185, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignSwitchFlag, EVT_INDEX_OF_AREA_FLAG(AF_NOK14_HitSwitch))
    EVT_END_IF
    EVT_CALL(MakeItemEntity, ITEM_COIN, -655, 75, -35, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -640, 75, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinB)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -640, 75, -50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinC)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -670, 75, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinD)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -670, 75, -50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_CoinE)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), -345, 77, -117, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_BreakBlock_ThunderBolt)))
    EVT_CALL(MakeItemEntity, ITEM_THUNDER_BOLT, -345, 102, -117, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_NOK14_Item_ThunderBolt)
    EVT_SET(MV_Item_ThunderBolt, LVar0)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 200, 60, -160, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 250, 60, -160, 0, ITEM_FIRE_FLOWER, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_NOK14_HiddenItem_FireFlower)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_BrickBlock), 300, 60, -160, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -650, 75, -50, 0, MODEL_o251, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_NOK14_HiddenPanel)
    EVT_RETURN
    EVT_END
};
