#include "machi.h"

#define VAR_RANGE_BYTE(s, firstVar, nextRange, nextVar) \
{ \
    .name = s, \
    .first = EVT_INDEX_OF_GAME_BYTE(firstVar), \
    .count = nextRange - firstVar, \
    .next = nextVar, \
}

GameVarRange N(GameByteTable)[] = {
    VAR_RANGE_BYTE("GSW EVT",   GB_StoryProgress,                 GB_KMR20_MarioReadDiaryFlags_00,  GB_Unused_EVT_02),
    VAR_RANGE_BYTE("GSW KMR",   GB_KMR20_MarioReadDiaryFlags_00,  GB_MAC01_Merlon_SpinJumpCount,    GB_Unused_KMR_05),
    VAR_RANGE_BYTE("GSW MAC",   GB_MAC01_Merlon_SpinJumpCount,    GB_TIK15_RipCheato_PurchaseCount, GB_Unused_MAC_13),
    VAR_RANGE_BYTE("GSW TIK",   GB_TIK15_RipCheato_PurchaseCount, GB_Unused_KGR_00,                 GB_Unused_TIK_01),
    VAR_RANGE_BYTE("GSW KGR",   GB_Unused_KGR_00,                 GB_Unused_KKJ_00,                 GB_Unused_KGR_00),
    VAR_RANGE_BYTE("GSW KKJ",   GB_Unused_KKJ_00,                 GB_Unused_HOS_00,                 GB_Unused_KKJ_03),
    VAR_RANGE_BYTE("GSW HOS",   GB_Unused_HOS_00,                 GB_Unused_NOK_00,                 GB_Unused_HOS_00),
    VAR_RANGE_BYTE("GSW NOK",   GB_Unused_NOK_00,                 GB_Unused_TRD_00,                 GB_Unused_NOK_02),
    VAR_RANGE_BYTE("GSW TRD",   GB_Unused_TRD_00,                 GB_IWA10_ReturnedLetterCount,     GB_Unused_TRD_00),
    VAR_RANGE_BYTE("GSW IWA",   GB_IWA10_ReturnedLetterCount,     GB_DRO02_SheekGiftCount,          GB_Unused_IWA_02),
    VAR_RANGE_BYTE("GSW DRO",   GB_DRO02_SheekGiftCount,          GB_Unused_SBK_00,                 GB_Unused_DRO_02),
    VAR_RANGE_BYTE("GSW SBK",   GB_Unused_SBK_00,                 GB_ISK11_ItemSocket1,             GB_Unused_SBK_00),
    VAR_RANGE_BYTE("GSW ISK",   GB_ISK11_ItemSocket1,             GB_MIM_CurrentMapID,              GB_Unused_ISK_05),
    VAR_RANGE_BYTE("GSW MIM",   GB_MIM_CurrentMapID,              GB_OBK07_SelectedRecord,          GB_Unused_MIM_01),
    VAR_RANGE_BYTE("GSW OBK",   GB_OBK07_SelectedRecord,          GB_Unused_ARN_00,                 GB_Unused_OBK_01),
    VAR_RANGE_BYTE("GSW ARN",   GB_Unused_ARN_00,                 GB_ARN_Tubba_MapID,               GB_Unused_ARN_00),
    VAR_RANGE_BYTE("GSW DGB",   GB_ARN_Tubba_MapID,               GB_Unused_OMO_00,                 GB_Unused_DGB_01),
    VAR_RANGE_BYTE("GSW OMO",   GB_Unused_OMO_00,                 GB_Unused_JAN_00,                 GB_Unused_OMO_05),
    VAR_RANGE_BYTE("GSW JAN",   GB_Unused_JAN_00,                 GB_Unused_KZN_00,                 GB_Unused_JAN_00),
    VAR_RANGE_BYTE("GSW KZN",   GB_Unused_KZN_00,                 GB_Unused_FLO_00,                 GB_Unused_KZN_00),
    VAR_RANGE_BYTE("GSW FLO",   GB_Unused_FLO_00,                 GB_SAM09_ItemSocket1_LowerByte,   GB_Unused_FLO_05),
    VAR_RANGE_BYTE("GSW SAM",   GB_SAM09_ItemSocket1_LowerByte,   GB_Unused_PRA_00,                 GB_Unused_SAM_08),
    VAR_RANGE_BYTE("GSW PRA",   GB_Unused_PRA_00,                 GB_KPA_WaterLevel,                GB_Unused_PRA_04),
    VAR_RANGE_BYTE("GSW KPA",   GB_KPA_WaterLevel,                GB_Unused_OSR_00,                 GB_Unused_KPA_08),
    VAR_RANGE_BYTE("GSW END",   GB_Unused_END_00,                 GB_Unused_BAT_00,                 GB_Unused_END_01),
    VAR_RANGE_BYTE("GSW OSR",   GB_Unused_OSR_00,                 GB_Unused_END_00,                 GB_Unused_OSR_00),
    VAR_RANGE_BYTE("GSW BAT",   GB_Unused_BAT_00,                 GB_KootFavor_State,               GB_Unused_BAT_00),
    VAR_RANGE_BYTE("GSW NPC",   GB_KootFavor_State,               GB_Tattles_00,                    GB_Unused_NPC_09),
    VAR_RANGE_BYTE("GSW BTL",   GB_Tattles_00,                    GB_Unused_FBTL_00,                GB_Unused_BTL_1E),
    VAR_RANGE_BYTE("GSW FBTL",  GB_Unused_FBTL_00,                GB_Unused_DOKAN_00,               GB_Unused_FBTL_00),
    VAR_RANGE_BYTE("GSW DOKAN", GB_Unused_DOKAN_00,               GB_WorldLocation,                 GB_Unused_DOKAN_00),
    VAR_RANGE_BYTE("GSW MAP",   GB_WorldLocation,                 GB_Unused_1B4,                    GB_Unused_MAP_01),
    {}
};

#define VAR_RANGE_FLAG(s, firstVar, nextRange, nextVar) \
{ \
    .name = s, \
    .first = EVT_INDEX_OF_GAME_FLAG(firstVar), \
    .count = nextRange - firstVar, \
    .next = nextVar, \
}

GameVarRange N(GameFlagTable)[] = {
    VAR_RANGE_FLAG("GSWF EVT",   GF_Unused_EVT_00,                GF_KMR04_Tree3_Dolly,            GF_Unused_EVT_0A),
    VAR_RANGE_FLAG("GSWF KMR",   GF_KMR04_Tree3_Dolly,            GF_Unused_MAC_00,                GF_Unused_KMR_51),
    VAR_RANGE_FLAG("GSWF MAC",   GF_Unused_MAC_00,                GF_Unused_TIK_00,                GF_Unused_MAC_EF),
    VAR_RANGE_FLAG("GSWF TIK",   GF_Unused_TIK_00,                GF_Unused_KGR_00,                GF_Unused_TIK_33),
    VAR_RANGE_FLAG("GSWF KGR",   GF_Unused_KGR_00,                GF_KKJ14_OpenedPassage,          GF_Unused_KGR_00),
    VAR_RANGE_FLAG("GSWF KKJ",   GF_KKJ14_OpenedPassage,          GF_Unused_HOS_00,                GF_Unused_KKJ_20),
    VAR_RANGE_FLAG("GSWF HOS",   GF_Unused_HOS_00,                GF_NOK01_RecoveredShellA,        GF_Unused_HOS_0F),
    VAR_RANGE_FLAG("GSWF NOK",   GF_NOK01_RecoveredShellA,        GF_TRD01_Item_SmashCharge,       GF_Unused_NOK_34),
    VAR_RANGE_FLAG("GSWF TRD",   GF_TRD01_Item_SmashCharge,       GF_IWA01_Item_QuakeHammer,       GF_Unused_TRD_1D),
    VAR_RANGE_FLAG("GSWF IWA",   GF_IWA01_Item_QuakeHammer,       GF_DRO02_Sheek_SpokeTo,          GF_Unused_IWA_25),
    VAR_RANGE_FLAG("GSWF DRO",   GF_DRO02_Sheek_SpokeTo,          GF_SBK30_Met_Kolorado,           GF_Unused_DRO_10),
    VAR_RANGE_FLAG("GSWF SBK",   GF_SBK30_Met_Kolorado,           GF_ISK02_UnlockedDoor,           GF_Unused_SBK_44),
    VAR_RANGE_FLAG("GSWF ISK",   GF_ISK02_UnlockedDoor,           GF_MIM_ChoosingPath,             GF_Unused_ISK_25),
    VAR_RANGE_FLAG("GSWF MIM",   GF_MIM_ChoosingPath,             GF_Unused_OBK_00,                GF_Unused_MIM_0C),
    VAR_RANGE_FLAG("GSWF OBK",   GF_Unused_OBK_00,                GF_Unused_ARN_00,                GF_Unused_OBK_1A),
    VAR_RANGE_FLAG("GSWF ARN",   GF_Unused_ARN_00,                GF_DGB01_UnlockedEastWing,       GF_Unused_ARN_14),
    VAR_RANGE_FLAG("GSWF DGB",   GF_DGB01_UnlockedEastWing,       GF_Unused_OMO_00,                GF_Unused_DGB_20),
    VAR_RANGE_FLAG("GSWF OMO",   GF_Unused_OMO_00,                GF_Unused_JAN_00,                GF_Unused_OMO_61),
    VAR_RANGE_FLAG("GSWF JAN",   GF_Unused_JAN_00,                GF_Unused_KZN_00,                GF_Unused_JAN_44),
    VAR_RANGE_FLAG("GSWF KZN",   GF_Unused_KZN_00,                GF_Unused_FLO_00,                GF_Unused_KZN_20),
    VAR_RANGE_FLAG("GSWF FLO",   GF_Unused_FLO_00,                GF_SAM04_PlacedScarf,            GF_Unused_FLO_33),
    VAR_RANGE_FLAG("GSWF SAM",   GF_SAM04_PlacedScarf,            GF_PRA_BrokeIllusion,            GF_Unused_SAM_27),
    VAR_RANGE_FLAG("GSWF PRA",   GF_PRA_BrokeIllusion,            GF_KPA01_ItemBlock_POWBlock,     GF_Unused_PRA_1F),
    VAR_RANGE_FLAG("GSWF KPA",   GF_KPA01_ItemBlock_POWBlock,     GF_Unused_END_00,                GF_Unused_KPA_2F),
    VAR_RANGE_FLAG("GSWF END",   GF_Unused_END_00,                GF_OSR02_HiddenItem_UltraShroom, GF_Unused_END_01),
    VAR_RANGE_FLAG("GSWF OSR",   GF_OSR02_HiddenItem_UltraShroom, GF_MAC01_RowfBadge_00,           GF_Unused_OSR_01),
    VAR_RANGE_FLAG("GSWF BAT",   GF_MAC01_RowfBadge_00,           GF_KootFavor_LeftKoopaVillage,   GF_Unused_BAT_15),
    VAR_RANGE_FLAG("GSWF NPC",   GF_KootFavor_LeftKoopaVillage,   GF_SpawnedItemDrop_00,           GF_Unused_NPC_5A),
    VAR_RANGE_FLAG("GSWF BTL",   GF_SpawnedItemDrop_00,           GF_FBTL_00,                      GF_Unused_BTL_07),
    VAR_RANGE_FLAG("GSWF FBTL",  GF_FBTL_00,                      GF_TIK01_WarpPipes,              GF_Unused_FBTL_4B),
    VAR_RANGE_FLAG("GSWF DOKAN", GF_TIK01_WarpPipes,              GF_MAP_ToadTown,                 GF_Unused_DOKAN_09),
    VAR_RANGE_FLAG("GSWF MAP",   GF_MAP_ToadTown,                 GF_Unused_7E0,                   GF_Unused_MAP_22),
    {}
};
