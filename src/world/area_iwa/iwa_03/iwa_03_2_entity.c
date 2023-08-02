#include "iwa_03.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

MAP_RODATA_PAD(1,entity);

API_CALLABLE(N(MonitorPlayerAltitude)) {
    s32 result = -1;

    if (gPlayerStatus.lastGoodPos.y > 200.0) {
        result = 0;
    }
    if (gPlayerStatus.lastGoodPos.y < 40.0) {
        result = 1;
    }
    if (result >= 0) {
        evt_set_variable(script, MV_PlayerCliffLevel, result);
    }
    return ApiStatus_BLOCK;
}

EvtScript N(EVS_TetherCameraToPlayer) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSpring) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAUNCH)
    EVT_WAIT(1)
    EVT_EXEC_GET_TID(N(EVS_TetherCameraToPlayer), LVarA)
    EVT_IF_EQ(MV_PlayerCliffLevel, 0)
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.4))
        EVT_CALL(PlayerJump, -1582, 23, 60, 15)
    EVT_ELSE
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(0.7))
        EVT_CALL(PlayerJump, -1582, 408, -60, 40)
    EVT_END_IF
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_IDLE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenChest) = EVT_OPEN_CHEST_BADGE(ITEM_DAMAGE_DODGE_B, GF_IWA03_Chest_DamageDodgeB);

EvtScript N(EVS_MakeEntities) = {
    EVT_THREAD
        EVT_CALL(N(MonitorPlayerAltitude))
    EVT_END_THREAD
    EVT_CALL(MakeEntity, EVT_PTR(Entity_ScriptSpring), -1580, 23, 20, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_UseSpring)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -1775, 408, -120, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_IWA03_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -620, -15, -69, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_IWA03_ItemBlock_Mushroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -1090, 408, -130, 0, ITEM_HONEY_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_IWA03_ItemBlock_HoneySyrup)
    EVT_CALL(MakeItemEntity, ITEM_LETTER_TO_KOLORADO, -20, 95, -85, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_LettertoKolorado)
    EVT_CALL(MakeItemEntity, ITEM_STAR_PIECE, -1865, 23, 20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_StarPiece)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1815, 23, 20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinC)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1915, 23, 20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinD)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1840, 23, 63, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinE)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1890, 23, 63, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinF)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1840, 23, -23, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinG)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1890, 23, -23, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinH)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1707, -60, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinA)
    EVT_CALL(MakeItemEntity, ITEM_COIN, -1707, -60, 60, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinB)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), -1717, 93, -127, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_IWA03_Chest_DamageDodgeB)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest)))
    EVT_RETURN
    EVT_END
};
