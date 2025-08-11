#include "omo_09.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_Dictionary) = {
    Set(LVarA, ITEM_DICTIONARY)
    Set(LVarB, ITEM_TYPE_KEY)
    Set(GF_OMO09_Chest_Dictionary, true)
    ExecWait(N(EVS_Chest_GetItem))
    Set(GF_MAC00_DictionaryStolen, true)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeItemEntity, ITEM_COIN, -760, 10, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinA)
    Call(MakeItemEntity, ITEM_COIN, -700, 10, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinB)
    Call(MakeItemEntity, ITEM_COIN, -640, 10, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinC)
    Call(MakeItemEntity, ITEM_COIN, -440, 10, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinD)
    Call(MakeItemEntity, ITEM_COIN, -380, 10, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinE)
    Call(MakeItemEntity, ITEM_COIN, -320, 10, 100, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinF)
    Call(MakeItemEntity, ITEM_STAR_PIECE, 1800, 25, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_StarPiece)
    Call(MakeItemEntity, ITEM_COIN, 1775, 25, -50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinG)
    Call(MakeItemEntity, ITEM_COIN, 1825, 25, -50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinH)
    Call(MakeItemEntity, ITEM_COIN, 1750, 25, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinI)
    Call(MakeItemEntity, ITEM_COIN, 1850, 25, 0, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinJ)
    Call(MakeItemEntity, ITEM_COIN, 1775, 25, 50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinK)
    Call(MakeItemEntity, ITEM_COIN, 1825, 25, 50, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_CoinL)
    Call(MakeEntity, Ref(Entity_MulticoinBlock), 1285, 230, -50, 0, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO09_MultiCoinBrick)
    Call(UseDynamicShadow, true)
    Call(MakeEntity, Ref(Entity_Chest), 1950, 150, -31, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OMO09_Chest_Dictionary)
    Call(AssignScript, Ref(N(EVS_OpenChest_Dictionary)))
    IfEq(GF_OMO09_Defeated_MysteryNoteThief, true)
        IfEq(GF_OMO09_Item_MysteryNote, false)
            Call(MakeItemEntity, ITEM_MYSTERY_NOTE, 142, 10, -96, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OMO09_Item_MysteryNote)
        EndIf
    EndIf
    Return
    End
};
