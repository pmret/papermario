#ifndef _WORLD_AREA_KMR_KMR_H_
#define _WORLD_AREA_KMR_KMR_H_

#include "evt.h"

#define KMR20_MarioReadLetterFlags_00 EVT_SAVE_VAR(0x00E)
#define KMR20_MarioReadLetterFlags_01 EVT_SAVE_VAR(0x00F)

#define KMR04_Tree3_Dolly EVT_SAVE_FLAG(0x01E)
#define KMR02_KeptDolly EVT_SAVE_FLAG(0x01F)
#define KMR02_Met_Goompapa EVT_SAVE_FLAG(0x020)
#define KMR02_Goompapa_SaidFarewell EVT_SAVE_FLAG(0x021)
#define KMR02_Met_Goomama EVT_SAVE_FLAG(0x022)
#define KMR02_Goomama_SaidFarewell EVT_SAVE_FLAG(0x023)
#define KMR02_Met_Goombario EVT_SAVE_FLAG(0x024)
#define KMR02_Goombario_SwapDialogue EVT_SAVE_FLAG(0x025)
#define KMR02_Met_Gooma EVT_SAVE_FLAG(0x026)
#define KMR02_Gooma_HealthAdvice EVT_SAVE_FLAG(0x027)
#define KMR02_Met_Goompa EVT_SAVE_FLAG(0x028)
#define KMR02_Goompa_SwapDialogue EVT_SAVE_FLAG(0x029)
#define KMR02_ToadHouse_Intro EVT_SAVE_FLAG(0x02A)
#define KMR02_ReturnedWithGoompa EVT_SAVE_FLAG(0x02B)
#define KMR11_GoombaBrosFledToCastle EVT_SAVE_FLAG(0x02D)
#define KMR02_Item_ShootingStar EVT_SAVE_FLAG(0x02E)
#define KMR02_Bush2_Coin EVT_SAVE_FLAG(0x02F)
#define KMR02_Tree1_Goomnut EVT_SAVE_FLAG(0x030)
#define KMR02_Item_FireFlower EVT_SAVE_FLAG(0x031)
#define KMR03_ItemBlock_Coin EVT_SAVE_FLAG(0x032)
#define KMR03_HiddenItem_RepelGel EVT_SAVE_FLAG(0x034)
#define KMR03_Tree1_Mushroom EVT_SAVE_FLAG(0x035)
#define KMR03_Hammer1Block EVT_SAVE_FLAG(0x036)
#define KMR03_Item_CoinA EVT_SAVE_FLAG(0x038)
#define KMR03_Item_CoinB EVT_SAVE_FLAG(0x039)
#define KMR03_Item_CoinC EVT_SAVE_FLAG(0x03A)
#define KMR03_Item_CoinD EVT_SAVE_FLAG(0x03B)
#define KMR04_Tree1_Coin EVT_SAVE_FLAG(0x03C)
#define KMR04_Tree2_Coin EVT_SAVE_FLAG(0x03D)
#define KMR04_Bush1_Coin EVT_SAVE_FLAG(0x03E)
#define KMR04_Bush2_Coin EVT_SAVE_FLAG(0x03F)
#define KMR04_Bush3_CoinA EVT_SAVE_FLAG(0x040)
#define KMR04_Bush3_CoinB EVT_SAVE_FLAG(0x041)
#define KMR04_Bush4_Coin EVT_SAVE_FLAG(0x042)
#define KMR04_Bush5_Coin EVT_SAVE_FLAG(0x043)
#define KMR04_MultiCoinBrick EVT_SAVE_FLAG(0x046)
#define KMR04_Hammer1Block EVT_SAVE_FLAG(0x047)
#define KMR05_EnemyWarning EVT_SAVE_FLAG(0x048)
#define KMR05_Tree1_Coin EVT_SAVE_FLAG(0x049)
#define KMR05_Item_StarPiece EVT_SAVE_FLAG(0x04A)
#define KMR09_ItemBlock_CoinA EVT_SAVE_FLAG(0x04D)
#define KMR09_ItemBlock_CoinB EVT_SAVE_FLAG(0x04E)
#define KMR06_Item_Mushroom EVT_SAVE_FLAG(0x04F)
#define KMR06_BadgeBlock_CloseCall EVT_SAVE_FLAG(0x050)
#define KMR11_ItemBlock_SuperShroom EVT_SAVE_FLAG(0x051)
#define KMR11_Tree1_StarPiece EVT_SAVE_FLAG(0x052)
#define KMR11_Tree2_Coin EVT_SAVE_FLAG(0x053)
#define KMR10_Chest_HammerThrow EVT_SAVE_FLAG(0x054)
#define KMR10_ItemBlock_SleepySheep EVT_SAVE_FLAG(0x055)
#define KMR00_HiddenPanel EVT_SAVE_FLAG(0x056)
#define KMR03_HiddenPanel EVT_SAVE_FLAG(0x058)
#define KMR11_HiddenPanel EVT_SAVE_FLAG(0x05A)
#define KMR10_UnreadFlagForSpring EVT_SAVE_FLAG(0x05B)
#define Tutorial_Badges EVT_SAVE_FLAG(0x05E)
#define Tutorial_SaveBlock EVT_SAVE_FLAG(0x05F)
#define Tutorial_HeartBlock EVT_SAVE_FLAG(0x060)
#define Tutorial_GotItem EVT_SAVE_FLAG(0x061)
#define KMR20_ReunitedWithLuigi EVT_SAVE_FLAG(0x062) ///< And saw him whistling
#define KMR20_Gift_LuigisAutograph EVT_SAVE_FLAG(0x063)
#define KMR02_Gift_TheTape EVT_SAVE_FLAG(0x064)
#define Tutorial_GotStarPiece EVT_SAVE_FLAG(0x065)
#define FoughtTheMaster EVT_SAVE_FLAG(0x066)
#define KMR20_ReadThankYouLetterFromKoopaVillage EVT_SAVE_FLAG(0x067)
#define KMR02_Goombario_RelayedMessage EVT_SAVE_FLAG(0x068)
#define KMR20_CaughtLuigiInBasement EVT_SAVE_FLAG(0x069)
#define KMR20_CaughtLuigiReadingLetter EVT_SAVE_FLAG(0x06A)
#define KMR20_FoundLuigisDiary EVT_SAVE_FLAG(0x06B)
#define KMR20_CheckedDeskForMail EVT_SAVE_FLAG(0x06C)
#define KMR20_ChasedOffShyGuy EVT_SAVE_FLAG(0x06D)
#define KMR10_KnockedSpringOutOfTree EVT_SAVE_FLAG(0x06E)

extern MapConfig kmr_00_config;
extern MapConfig kmr_02_config;
extern MapConfig kmr_03_config;
extern MapConfig kmr_04_config;
extern MapConfig kmr_05_config;
extern MapConfig kmr_06_config;
extern MapConfig kmr_07_config;
extern MapConfig kmr_09_config;
extern MapConfig kmr_10_config;
extern MapConfig kmr_11_config;
extern MapConfig kmr_12_config;
extern MapConfig kmr_20_config;
extern MapConfig kmr_21_config;
extern MapConfig kmr_22_config;
extern MapConfig kmr_23_config;
extern MapConfig kmr_24_config;
extern MapConfig kmr_30_config;

#endif
