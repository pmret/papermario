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
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(SetCamTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_UseSpring) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAUNCH)
    Wait(1)
    ExecGetTID(N(EVS_TetherCameraToPlayer), LVarA)
    IfEq(MV_PlayerCliffLevel, 0)
        Call(SetPlayerJumpscale, Float(1.4))
        Call(PlayerJump, -1582, 23, 60, 15)
    Else
        Call(SetPlayerJumpscale, Float(0.7))
        Call(PlayerJump, -1582, 408, -60, 40)
    EndIf
    KillThread(LVarA)
    Call(SetPlayerActionState, ACTION_STATE_IDLE)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_OpenChest) = EVT_OPEN_CHEST_BADGE(ITEM_DAMAGE_DODGE_B, GF_IWA03_Chest_DamageDodgeB);

EvtScript N(EVS_MakeEntities) = {
    Thread
        Call(N(MonitorPlayerAltitude))
    EndThread
    Call(MakeEntity, Ref(Entity_ScriptSpring), -1580, 23, 20, 0, MAKE_ENTITY_END)
    Call(AssignScript, Ref(N(EVS_UseSpring)))
    Call(MakeEntity, Ref(Entity_YellowBlock), -1775, 408, -120, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_IWA03_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_YellowBlock), -620, -15, -69, 0, ITEM_MUSHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_IWA03_ItemBlock_Mushroom)
    Call(MakeEntity, Ref(Entity_YellowBlock), -1090, 408, -130, 0, ITEM_HONEY_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_IWA03_ItemBlock_HoneySyrup)
    Call(MakeItemEntity, ITEM_LETTER_TO_KOLORADO, -20, 95, -85, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_LettertoKolorado)
    Call(MakeItemEntity, ITEM_STAR_PIECE, -1865, 23, 20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_StarPiece)
    Call(MakeItemEntity, ITEM_COIN, -1815, 23, 20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinC)
    Call(MakeItemEntity, ITEM_COIN, -1915, 23, 20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinD)
    Call(MakeItemEntity, ITEM_COIN, -1840, 23, 63, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinE)
    Call(MakeItemEntity, ITEM_COIN, -1890, 23, 63, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinF)
    Call(MakeItemEntity, ITEM_COIN, -1840, 23, -23, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinG)
    Call(MakeItemEntity, ITEM_COIN, -1890, 23, -23, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinH)
    Call(MakeItemEntity, ITEM_COIN, -1707, -60, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, -1707, -60, 60, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_IWA03_Item_CoinB)
    Call(MakeEntity, Ref(Entity_Chest), -1717, 93, -127, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_IWA03_Chest_DamageDodgeB)
    Call(AssignScript, Ref(N(EVS_OpenChest)))
    Return
    End
};
