#ifndef _WORLD_AREA_KMR_KMR_H_
#define _WORLD_AREA_KMR_KMR_H_

#include "si.h"

#define KMR20_MarioReadLetterFlags_00 SI_SAVE_VAR(0x00E)
#define KMR20_MarioReadLetterFlags_01 SI_SAVE_VAR(0x00F)

#define KMR04_Tree3_Dolly SI_SAVE_FLAG(0x01E)
#define KMR02_KeptDolly SI_SAVE_FLAG(0x01F)
#define KMR02_Met_Goompapa SI_SAVE_FLAG(0x020)
#define KMR02_Goompapa_SaidFarewell SI_SAVE_FLAG(0x021)
#define KMR02_Met_Goomama SI_SAVE_FLAG(0x022)
#define KMR02_Goomama_SaidFarewell SI_SAVE_FLAG(0x023)
#define KMR02_Met_Goombario SI_SAVE_FLAG(0x024)
#define KMR02_Goombario_SwapDialogue SI_SAVE_FLAG(0x025)
#define KMR02_Met_Gooma SI_SAVE_FLAG(0x026)
#define KMR02_Gooma_HealthAdvice SI_SAVE_FLAG(0x027)
#define KMR02_Met_Goompa SI_SAVE_FLAG(0x028)
#define KMR02_Goompa_SwapDialogue SI_SAVE_FLAG(0x029)
#define KMR02_ToadHouse_Intro SI_SAVE_FLAG(0x02A)
#define KMR02_ReturnedWithGoompa SI_SAVE_FLAG(0x02B)
#define KMR11_GoombaBrosFledToCastle SI_SAVE_FLAG(0x02D)
#define KMR02_Item_ShootingStar SI_SAVE_FLAG(0x02E)
#define KMR02_Bush2_Coin SI_SAVE_FLAG(0x02F)
#define KMR02_Tree1_Goomnut SI_SAVE_FLAG(0x030)
#define KMR02_Item_FireFlower SI_SAVE_FLAG(0x031)
#define KMR03_ItemBlock_Coin SI_SAVE_FLAG(0x032)
#define KMR03_HiddenItem_RepelGel SI_SAVE_FLAG(0x034)
#define KMR03_Tree1_Mushroom SI_SAVE_FLAG(0x035)
#define KMR03_Hammer1Block SI_SAVE_FLAG(0x036)
#define KMR03_Item_CoinA SI_SAVE_FLAG(0x038)
#define KMR03_Item_CoinB SI_SAVE_FLAG(0x039)
#define KMR03_Item_CoinC SI_SAVE_FLAG(0x03A)
#define KMR03_Item_CoinD SI_SAVE_FLAG(0x03B)
#define KMR04_Tree1_Coin SI_SAVE_FLAG(0x03C)
#define KMR04_Tree2_Coin SI_SAVE_FLAG(0x03D)
#define KMR04_Bush1_Coin SI_SAVE_FLAG(0x03E)
#define KMR04_Bush2_Coin SI_SAVE_FLAG(0x03F)
#define KMR04_Bush3_CoinA SI_SAVE_FLAG(0x040)
#define KMR04_Bush3_CoinB SI_SAVE_FLAG(0x041)
#define KMR04_Bush4_Coin SI_SAVE_FLAG(0x042)
#define KMR04_Bush5_Coin SI_SAVE_FLAG(0x043)
#define KMR04_MultiCoinBrick SI_SAVE_FLAG(0x046)
#define KMR04_Hammer1Block SI_SAVE_FLAG(0x047)
#define KMR05_EnemyWarning SI_SAVE_FLAG(0x048)
#define KMR05_Tree1_Coin SI_SAVE_FLAG(0x049)
#define KMR05_Item_StarPiece SI_SAVE_FLAG(0x04A)
#define KMR09_ItemBlock_CoinA SI_SAVE_FLAG(0x04D)
#define KMR09_ItemBlock_CoinB SI_SAVE_FLAG(0x04E)
#define KMR06_Item_Mushroom SI_SAVE_FLAG(0x04F)
#define KMR06_BadgeBlock_CloseCall SI_SAVE_FLAG(0x050)
#define KMR11_ItemBlock_SuperShroom SI_SAVE_FLAG(0x051)
#define KMR11_Tree1_StarPiece SI_SAVE_FLAG(0x052)
#define KMR11_Tree2_Coin SI_SAVE_FLAG(0x053)
#define KMR10_Chest_HammerThrow SI_SAVE_FLAG(0x054)
#define KMR10_ItemBlock_SleepySheep SI_SAVE_FLAG(0x055)
#define KMR00_HiddenPanel SI_SAVE_FLAG(0x056)
#define KMR03_HiddenPanel SI_SAVE_FLAG(0x058)
#define KMR11_HiddenPanel SI_SAVE_FLAG(0x05A)
#define KMR10_UnreadFlagForSpring SI_SAVE_FLAG(0x05B)
#define Tutorial_Badges SI_SAVE_FLAG(0x05E)
#define Tutorial_SaveBlock SI_SAVE_FLAG(0x05F)
#define Tutorial_HeartBlock SI_SAVE_FLAG(0x060)
#define Tutorial_GotItem SI_SAVE_FLAG(0x061)
#define KMR20_ReunitedWithLuigi SI_SAVE_FLAG(0x062) ///< And saw him whistling
#define KMR20_Gift_LuigisAutograph SI_SAVE_FLAG(0x063)
#define KMR02_Gift_TheTape SI_SAVE_FLAG(0x064)
#define Tutorial_GotStarPiece SI_SAVE_FLAG(0x065)
#define FoughtTheMaster SI_SAVE_FLAG(0x066)
#define KMR20_ReadThankYouLetterFromKoopaVillage SI_SAVE_FLAG(0x067)
#define KMR02_Goombario_RelayedMessage SI_SAVE_FLAG(0x068)
#define KMR20_CaughtLuigiInBasement SI_SAVE_FLAG(0x069)
#define KMR20_CaughtLuigiReadingLetter SI_SAVE_FLAG(0x06A)
#define KMR20_FoundLuigisDiary SI_SAVE_FLAG(0x06B)
#define KMR20_CheckedDeskForMail SI_SAVE_FLAG(0x06C)
#define KMR20_ChasedOffShyGuy SI_SAVE_FLAG(0x06D)
#define KMR10_KnockedSpringOutOfTree SI_SAVE_FLAG(0x06E)

MapConfig kmr_00_config;
MapConfig kmr_02_config;
MapConfig kmr_03_config;
MapConfig kmr_04_config;
MapConfig kmr_05_config;
MapConfig kmr_06_config;
MapConfig kmr_07_config;
MapConfig kmr_09_config;
MapConfig kmr_10_config;
MapConfig kmr_11_config;
MapConfig kmr_12_config;
MapConfig kmr_20_config;
MapConfig kmr_21_config;
MapConfig kmr_22_config;
MapConfig kmr_23_config;
MapConfig kmr_24_config;
MapConfig kmr_30_config;

#endif
