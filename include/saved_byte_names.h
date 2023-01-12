#include "script_api/macros.h"

enum GameBytes {
    GB_StoryProgress                        = GameByte(0x000), 
    GB_Unused_EVT_01                        = GameByte(0x001), ///< copied from GameStatus->unk_A9 by Function_80035E54 during save file load
    GB_Unused_EVT_02                        = GameByte(0x002), 
    GB_Unused_EVT_03                        = GameByte(0x003), 
    GB_Unused_EVT_04                        = GameByte(0x004), 
    GB_Unused_EVT_05                        = GameByte(0x005), 
    GB_Unused_EVT_06                        = GameByte(0x006), 
    GB_Unused_EVT_07                        = GameByte(0x007), 
    GB_Unused_EVT_08                        = GameByte(0x008), 
    GB_Unused_EVT_09                        = GameByte(0x009), 
    GB_Unused_EVT_0A                        = GameByte(0x00A), 
    GB_Unused_EVT_0B                        = GameByte(0x00B), 
    GB_KMR20_MarioReadDiaryFlags_00         = GameByte(0x00C), 
    GB_KMR20_MarioReadDiaryFlags_01         = GameByte(0x00D), 
    GB_KMR20_MarioReadLetterFlags_00        = GameByte(0x00E), 
    GB_KMR20_MarioReadLetterFlags_01        = GameByte(0x00F), 
    GB_Unused_KMR_04                        = GameByte(0x010), 
    GB_Unused_KMR_05                        = GameByte(0x011), 
    GB_Unused_KMR_06                        = GameByte(0x012), 
    GB_Unused_KMR_07                        = GameByte(0x013), 
    GB_Unused_KMR_08                        = GameByte(0x014), 
    GB_Unused_KMR_09                        = GameByte(0x015), 
    GB_Unused_KMR_0A                        = GameByte(0x016), 
    GB_Unused_KMR_0B                        = GameByte(0x017), 
    GB_Unused_KMR_0C                        = GameByte(0x018), 
    GB_Unused_KMR_0D                        = GameByte(0x019), 
    GB_Unused_KMR_0E                        = GameByte(0x01A), 
    GB_MAC01_Merlon_SpinJumpCount           = GameByte(0x01B), 
    GB_MAC00_DojoRank                       = GameByte(0x01C), 
    GB_MAC03_LilOinkCount                   = GameByte(0x01D), ///< 0  = none. 1  = ready, 2  = broken
    GB_MAC03_LilOink_00                     = GameByte(0x01E), 
    GB_MAC03_LilOink_01                     = GameByte(0x01F), 
    GB_MAC03_LilOink_02                     = GameByte(0x020), 
    GB_MAC03_LilOink_03                     = GameByte(0x021), 
    GB_MAC03_LilOink_04                     = GameByte(0x022), 
    GB_MAC03_LilOink_05                     = GameByte(0x023), 
    GB_MAC03_LilOink_06                     = GameByte(0x024), 
    GB_MAC03_LilOink_07                     = GameByte(0x025), 
    GB_MAC03_LilOink_08                     = GameByte(0x026), 
    GB_MAC03_LilOink_09                     = GameByte(0x027), 
    GB_MAC03_LilOink_0A                     = GameByte(0x028), 
    GB_MAC01_Rowf_Badge0                    = GameByte(0x029), 
    GB_MAC01_Rowf_Badge1                    = GameByte(0x02A), 
    GB_MAC01_Rowf_Badge2                    = GameByte(0x02B), 
    GB_MAC01_Rowf_NumBadges                 = GameByte(0x02C), 
    GB_MAC03_LilOinkCapsuleState            = GameByte(0x02D), 
    GB_Unused_MAC_13                        = GameByte(0x02E), 
    GB_Unused_MAC_14                        = GameByte(0x02F), 
    GB_Unused_MAC_15                        = GameByte(0x030), 
    GB_Unused_MAC_16                        = GameByte(0x031), 
    GB_Unused_MAC_17                        = GameByte(0x032), 
    GB_Unused_MAC_18                        = GameByte(0x033), 
    GB_Unused_MAC_19                        = GameByte(0x034), 
    GB_Unused_MAC_1A                        = GameByte(0x035), 
    GB_Unused_MAC_1B                        = GameByte(0x036), 
    GB_Unused_MAC_1C                        = GameByte(0x037), 
    GB_TIK15_RipCheato_PurchaseCount        = GameByte(0x038), 
    GB_Unused_TIK_01                        = GameByte(0x039), 
    GB_Unused_TIK_02                        = GameByte(0x03A), 
    GB_Unused_TIK_03                        = GameByte(0x03B), 
    GB_Unused_TIK_04                        = GameByte(0x03C), 
    GB_Unused_TIK_05                        = GameByte(0x03D), 
    GB_Unused_TIK_06                        = GameByte(0x03E), 
    GB_Unused_TIK_07                        = GameByte(0x03F), 
    GB_Unused_TIK_08                        = GameByte(0x040), 
    GB_Unused_TIK_09                        = GameByte(0x041), 
    GB_Unused_TIK_0A                        = GameByte(0x042), 
    GB_Unused_KGR_00                        = GameByte(0x043), 
    GB_Unused_KGR_01                        = GameByte(0x044), 
    GB_Unused_KGR_02                        = GameByte(0x045), 
    GB_Unused_KGR_03                        = GameByte(0x046), 
    GB_Unused_KGR_04                        = GameByte(0x047), 
    GB_Unused_KGR_05                        = GameByte(0x048), 
    GB_Unused_KGR_06                        = GameByte(0x049), 
    GB_Unused_KGR_07                        = GameByte(0x04A), 
    GB_Unused_KGR_08                        = GameByte(0x04B), 
    GB_Unused_KGR_09                        = GameByte(0x04C), 
    GB_Unused_KKJ_00                        = GameByte(0x04D), 
    GB_KKJ_LastPartner                      = GameByte(0x04E), ///< peach missions need to remember Mario's last partner
    GB_KKJ_CaughtCount                      = GameByte(0x04F), ///< how many times peach is caught for each mission
    GB_Unused_KKJ_03                        = GameByte(0x050), 
    GB_Unused_KKJ_04                        = GameByte(0x051), 
    GB_Unused_KKJ_05                        = GameByte(0x052), 
    GB_Unused_KKJ_06                        = GameByte(0x053), 
    GB_Unused_KKJ_07                        = GameByte(0x054), 
    GB_Unused_KKJ_08                        = GameByte(0x055), 
    GB_Unused_KKJ_09                        = GameByte(0x056), 
    GB_Unused_KKJ_0A                        = GameByte(0x057), 
    GB_Unused_KKJ_0B                        = GameByte(0x058), 
    GB_Unused_KKJ_0C                        = GameByte(0x059), 
    GB_Unused_HOS_00                        = GameByte(0x05A), 
    GB_Unused_HOS_01                        = GameByte(0x05B), 
    GB_Unused_HOS_02                        = GameByte(0x05C), 
    GB_Unused_HOS_03                        = GameByte(0x05D), 
    GB_Unused_HOS_04                        = GameByte(0x05E), 
    GB_Unused_HOS_05                        = GameByte(0x05F), 
    GB_Unused_HOS_06                        = GameByte(0x060), 
    GB_Unused_HOS_07                        = GameByte(0x061), 
    GB_Unused_HOS_08                        = GameByte(0x062), 
    GB_Unused_HOS_09                        = GameByte(0x063), 
    GB_Unused_NOK_00                        = GameByte(0x064), 
    GB_Unused_NOK_01                        = GameByte(0x065), 
    GB_Unused_NOK_02                        = GameByte(0x066), 
    GB_Unused_NOK_03                        = GameByte(0x067), 
    GB_Unused_NOK_04                        = GameByte(0x068), 
    GB_Unused_NOK_05                        = GameByte(0x069), 
    GB_Unused_NOK_06                        = GameByte(0x06A), 
    GB_Unused_NOK_07                        = GameByte(0x06B), 
    GB_Unused_NOK_08                        = GameByte(0x06C), 
    GB_Unused_NOK_09                        = GameByte(0x06D), 
    GB_Unused_NOK_0A                        = GameByte(0x06E), 
    GB_Unused_NOK_0B                        = GameByte(0x06F), 
    GB_Unused_TRD_00                        = GameByte(0x070), 
    GB_Unused_TRD_01                        = GameByte(0x071), 
    GB_Unused_TRD_02                        = GameByte(0x072), 
    GB_Unused_TRD_03                        = GameByte(0x073), 
    GB_Unused_TRD_04                        = GameByte(0x074), 
    GB_Unused_TRD_05                        = GameByte(0x075), 
    GB_Unused_TRD_06                        = GameByte(0x076), 
    GB_Unused_TRD_07                        = GameByte(0x077), 
    GB_Unused_TRD_08                        = GameByte(0x078), 
    GB_Unused_TRD_09                        = GameByte(0x079), 
    GB_IWA10_ReturnedLetterCount            = GameByte(0x07A), 
    GB_IWA00_Whacka_HitCount                = GameByte(0x07B), 
    GB_Unused_IWA_02                        = GameByte(0x07C), 
    GB_Unused_IWA_03                        = GameByte(0x07D), 
    GB_Unused_IWA_04                        = GameByte(0x07E), 
    GB_Unused_IWA_05                        = GameByte(0x07F), 
    GB_Unused_IWA_06                        = GameByte(0x080), 
    GB_Unused_IWA_07                        = GameByte(0x081), 
    GB_Unused_IWA_08                        = GameByte(0x082), 
    GB_Unused_IWA_09                        = GameByte(0x083), 
    GB_Unused_IWA_0A                        = GameByte(0x084), 
    GB_Unused_IWA_0B                        = GameByte(0x085), 
    GB_DRO02_SheekGiftCount                 = GameByte(0x086), 
    GB_DRO02_SheekLemonGiftCount            = GameByte(0x087), 
    GB_Unused_DRO_02                        = GameByte(0x088), 
    GB_Unused_DRO_03                        = GameByte(0x089), 
    GB_Unused_DRO_04                        = GameByte(0x08A), 
    GB_Unused_DRO_05                        = GameByte(0x08B), 
    GB_Unused_DRO_06                        = GameByte(0x08C), 
    GB_Unused_DRO_07                        = GameByte(0x08D), 
    GB_Unused_DRO_08                        = GameByte(0x08E), 
    GB_Unused_DRO_09                        = GameByte(0x08F), 
    GB_Unused_DRO_0A                        = GameByte(0x090), 
    GB_Unused_DRO_0B                        = GameByte(0x091), 
    GB_Unused_SBK_00                        = GameByte(0x092), 
    GB_Unused_SBK_01                        = GameByte(0x093), 
    GB_Unused_SBK_02                        = GameByte(0x094), 
    GB_Unused_SBK_03                        = GameByte(0x095), 
    GB_Unused_SBK_04                        = GameByte(0x096), 
    GB_Unused_SBK_05                        = GameByte(0x097), 
    GB_Unused_SBK_06                        = GameByte(0x098), 
    GB_Unused_SBK_07                        = GameByte(0x099), 
    GB_Unused_SBK_08                        = GameByte(0x09A), 
    GB_Unused_SBK_09                        = GameByte(0x09B), 
    GB_ISK11_ItemSocket1                    = GameByte(0x09C), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_ISK11_ItemSocket2                    = GameByte(0x09D), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_ISK11_ItemSocket3                    = GameByte(0x09E), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_ISK11_ItemSocket4                    = GameByte(0x09F), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_ISK11_ItemSocket5                    = GameByte(0x0A0), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_Unused_ISK_05                        = GameByte(0x0A1), 
    GB_Unused_ISK_06                        = GameByte(0x0A2), 
    GB_Unused_ISK_07                        = GameByte(0x0A3), 
    GB_Unused_ISK_08                        = GameByte(0x0A4), 
    GB_Unused_ISK_09                        = GameByte(0x0A5), 
    GB_Unused_ISK_0A                        = GameByte(0x0A6), 
    GB_Unused_ISK_0B                        = GameByte(0x0A7), 
    GB_Unused_ISK_0C                        = GameByte(0x0A8), 
    GB_Unused_ISK_0D                        = GameByte(0x0A9), 
    GB_Unused_ISK_0E                        = GameByte(0x0AA), 
    GB_MIM_CurrentMapID                     = GameByte(0x0AB), 
    GB_Unused_MIM_01                        = GameByte(0x0AC), 
    GB_Unused_MIM_02                        = GameByte(0x0AD), 
    GB_Unused_MIM_03                        = GameByte(0x0AE), 
    GB_Unused_MIM_04                        = GameByte(0x0AF), 
    GB_Unused_MIM_05                        = GameByte(0x0B0), 
    GB_Unused_MIM_06                        = GameByte(0x0B1), 
    GB_Unused_MIM_07                        = GameByte(0x0B2), 
    GB_Unused_MIM_08                        = GameByte(0x0B3), 
    GB_Unused_MIM_09                        = GameByte(0x0B4), 
    GB_Unused_MIM_0A                        = GameByte(0x0B5), 
    GB_OBK07_SelectedRecord                 = GameByte(0x0B6), ///< seems there were more than one at some point
    GB_Unused_OBK_01                        = GameByte(0x0B7), 
    GB_Unused_OBK_02                        = GameByte(0x0B8), 
    GB_Unused_OBK_03                        = GameByte(0x0B9), 
    GB_Unused_OBK_04                        = GameByte(0x0BA), 
    GB_Unused_OBK_05                        = GameByte(0x0BB), 
    GB_Unused_OBK_06                        = GameByte(0x0BC), 
    GB_Unused_OBK_07                        = GameByte(0x0BD), 
    GB_Unused_OBK_08                        = GameByte(0x0BE), 
    GB_Unused_OBK_09                        = GameByte(0x0BF), 
    GB_Unused_OBK_0A                        = GameByte(0x0C0), 
    GB_Unused_ARN_00                        = GameByte(0x0C1), 
    GB_Unused_ARN_01                        = GameByte(0x0C2), 
    GB_Unused_ARN_02                        = GameByte(0x0C3), 
    GB_Unused_ARN_03                        = GameByte(0x0C4), 
    GB_Unused_ARN_04                        = GameByte(0x0C5), 
    GB_Unused_ARN_05                        = GameByte(0x0C6), 
    GB_Unused_ARN_06                        = GameByte(0x0C7), 
    GB_Unused_ARN_07                        = GameByte(0x0C8), 
    GB_Unused_ARN_08                        = GameByte(0x0C9), 
    GB_Unused_ARN_09                        = GameByte(0x0CA), 
    GB_ARN_Tubba_MapID                      = GameByte(0x0CB), ///< current map ID for Tubba's location in his manor
    GB_Unused_DGB_01                        = GameByte(0x0CC), 
    GB_Unused_DGB_02                        = GameByte(0x0CD), 
    GB_Unused_DGB_03                        = GameByte(0x0CE), 
    GB_Unused_DGB_04                        = GameByte(0x0CF), 
    GB_Unused_DGB_05                        = GameByte(0x0D0), 
    GB_Unused_DGB_06                        = GameByte(0x0D1), 
    GB_Unused_DGB_07                        = GameByte(0x0D2), 
    GB_Unused_DGB_08                        = GameByte(0x0D3), 
    GB_Unused_DGB_09                        = GameByte(0x0D4), 
    GB_Unused_DGB_0A                        = GameByte(0x0D5), 
    GB_Unused_OMO_00                        = GameByte(0x0D6), 
    GB_OMO_TrainDestination                 = GameByte(0x0D7), 
    GB_OMO_PeachChoice1                     = GameByte(0x0D8), 
    GB_OMO_PeachChoice2                     = GameByte(0x0D9), 
    GB_OMO_PeachChoice3                     = GameByte(0x0DA), 
    GB_Unused_OMO_05                        = GameByte(0x0DB), 
    GB_Unused_OMO_06                        = GameByte(0x0DC), 
    GB_Unused_OMO_07                        = GameByte(0x0DD), 
    GB_Unused_OMO_08                        = GameByte(0x0DE), 
    GB_Unused_OMO_09                        = GameByte(0x0DF), 
    GB_Unused_OMO_0A                        = GameByte(0x0E0), 
    GB_Unused_OMO_0B                        = GameByte(0x0E1), 
    GB_Unused_OMO_0C                        = GameByte(0x0E2), 
    GB_Unused_OMO_0D                        = GameByte(0x0E3), 
    GB_Unused_OMO_0E                        = GameByte(0x0E4), 
    GB_Unused_JAN_00                        = GameByte(0x0E5), 
    GB_Unused_JAN_01                        = GameByte(0x0E6), 
    GB_Unused_JAN_02                        = GameByte(0x0E7), 
    GB_Unused_JAN_03                        = GameByte(0x0E8), 
    GB_Unused_JAN_04                        = GameByte(0x0E9), 
    GB_Unused_JAN_05                        = GameByte(0x0EA), 
    GB_Unused_JAN_06                        = GameByte(0x0EB), 
    GB_Unused_JAN_07                        = GameByte(0x0EC), 
    GB_Unused_JAN_08                        = GameByte(0x0ED), 
    GB_Unused_JAN_09                        = GameByte(0x0EE), 
    GB_Unused_KZN_00                        = GameByte(0x0EF), 
    GB_Unused_KZN_01                        = GameByte(0x0F0), 
    GB_Unused_KZN_02                        = GameByte(0x0F1), 
    GB_Unused_KZN_03                        = GameByte(0x0F2), 
    GB_Unused_KZN_04                        = GameByte(0x0F3), 
    GB_Unused_KZN_05                        = GameByte(0x0F4), 
    GB_Unused_KZN_06                        = GameByte(0x0F5), 
    GB_Unused_KZN_07                        = GameByte(0x0F6), 
    GB_Unused_KZN_08                        = GameByte(0x0F7), 
    GB_Unused_KZN_09                        = GameByte(0x0F8), 
    GB_Unused_FLO_00                        = GameByte(0x0F9), 
    GB_Unused_FLO_01                        = GameByte(0x0FA), 
    GB_Unused_FLO_02                        = GameByte(0x0FB), 
    GB_FLO18_MachineDamage_Left             = GameByte(0x0FC), 
    GB_FLO18_MachineDamage_Right            = GameByte(0x0FD), 
    GB_Unused_FLO_05                        = GameByte(0x0FE), 
    GB_Unused_FLO_06                        = GameByte(0x0FF), 
    GB_Unused_FLO_07                        = GameByte(0x100), 
    GB_Unused_FLO_08                        = GameByte(0x101), 
    GB_Unused_FLO_09                        = GameByte(0x102), 
    GB_Unused_FLO_0A                        = GameByte(0x103), 
    GB_Unused_FLO_0B                        = GameByte(0x104), 
    GB_Unused_FLO_0C                        = GameByte(0x105), 
    GB_Unused_FLO_0D                        = GameByte(0x106), 
    GB_Unused_FLO_0E                        = GameByte(0x107), 
    GB_SAM09_ItemSocket1_LowerByte          = GameByte(0x108), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_SAM09_ItemSocket1_UpperByte          = GameByte(0x109), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_SAM09_ItemSocket2_LowerByte          = GameByte(0x10A), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_SAM09_ItemSocket2_UpperByte          = GameByte(0x10B), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_SAM09_ItemSocket3_LowerByte          = GameByte(0x10C), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_SAM09_ItemSocket3_UpperByte          = GameByte(0x10D), ///< currently stored itemID (invalid for itemIDs > 0xFF)
    GB_SAM11_FrozenPondDamage               = GameByte(0x10E), 
    GB_Unused_SAM_07                        = GameByte(0x10F), 
    GB_Unused_SAM_08                        = GameByte(0x110), 
    GB_Unused_SAM_09                        = GameByte(0x111), 
    GB_Unused_SAM_0A                        = GameByte(0x112), 
    GB_Unused_SAM_0B                        = GameByte(0x113), 
    GB_Unused_SAM_0C                        = GameByte(0x114), 
    GB_Unused_SAM_0D                        = GameByte(0x115), 
    GB_Unused_SAM_0E                        = GameByte(0x116), 
    GB_Unused_SAM_0F                        = GameByte(0x117), 
    GB_Unused_SAM_10                        = GameByte(0x118), 
    GB_Unused_SAM_11                        = GameByte(0x119), 
    GB_Unused_SAM_12                        = GameByte(0x11A), 
    GB_Unused_PRA_00                        = GameByte(0x11B), 
    GB_PRA18_ClubbasDefeated                = GameByte(0x11C), 
    GB_PRA19_TutorialState                  = GameByte(0x11D), ///< 0/1/2 for the action performed by the reflection
    GB_PRA_TwinStatueState                  = GameByte(0x11E), ///< 0/1/2
    GB_Unused_PRA_04                        = GameByte(0x11F), 
    GB_Unused_PRA_05                        = GameByte(0x120), 
    GB_Unused_PRA_06                        = GameByte(0x121), 
    GB_Unused_PRA_07                        = GameByte(0x122), 
    GB_Unused_PRA_08                        = GameByte(0x123), 
    GB_Unused_PRA_09                        = GameByte(0x124), 
    GB_Unused_PRA_0A                        = GameByte(0x125), 
    GB_Unused_PRA_0B                        = GameByte(0x126), 
    GB_Unused_PRA_0C                        = GameByte(0x127), 
    GB_Unused_PRA_0D                        = GameByte(0x128), 
    GB_KPA_WaterLevel                       = GameByte(0x129), 
    GB_KPA81_BowserDoorState                = GameByte(0x12A), ///< 0/1/2
    GB_KPA82_BowserDoorState                = GameByte(0x12B), ///< 0/1
    GB_KPA83_BowserDoorState                = GameByte(0x12C), ///< 0/1
    GB_KPA111_StatuePosition                = GameByte(0x12D), 
    GB_KPA113_StatuePosition                = GameByte(0x12E), 
    GB_KPA115_StatuePosition                = GameByte(0x12F), 
    GB_KPA04_StatuePosition                 = GameByte(0x130), 
    GB_Unused_KPA_08                        = GameByte(0x131), 
    GB_Unused_KPA_09                        = GameByte(0x132), 
    GB_Unused_KPA_0A                        = GameByte(0x133), 
    GB_Unused_KPA_0B                        = GameByte(0x134), 
    GB_Unused_KPA_0C                        = GameByte(0x135), 
    GB_Unused_KPA_0D                        = GameByte(0x136), 
    GB_Unused_KPA_0E                        = GameByte(0x137), 
    GB_Unused_KPA_0F                        = GameByte(0x138), 
    GB_Unused_KPA_10                        = GameByte(0x139), 
    GB_Unused_KPA_11                        = GameByte(0x13A), 
    GB_Unused_OSR_00                        = GameByte(0x13B), 
    GB_Unused_OSR_01                        = GameByte(0x13C), 
    GB_Unused_OSR_02                        = GameByte(0x13D), 
    GB_Unused_OSR_03                        = GameByte(0x13E), 
    GB_Unused_OSR_04                        = GameByte(0x13F), 
    GB_Unused_OSR_05                        = GameByte(0x140), 
    GB_Unused_OSR_06                        = GameByte(0x141), 
    GB_Unused_OSR_07                        = GameByte(0x142), 
    GB_Unused_OSR_08                        = GameByte(0x143), 
    GB_Unused_OSR_09                        = GameByte(0x144), 
    GB_Unused_END_00                        = GameByte(0x145), 
    GB_Unused_END_01                        = GameByte(0x146), 
    GB_Unused_END_02                        = GameByte(0x147), 
    GB_Unused_END_03                        = GameByte(0x148), 
    GB_Unused_END_04                        = GameByte(0x149), 
    GB_Unused_END_05                        = GameByte(0x14A), 
    GB_Unused_END_06                        = GameByte(0x14B), 
    GB_Unused_END_07                        = GameByte(0x14C), 
    GB_Unused_END_08                        = GameByte(0x14D), 
    GB_Unused_END_09                        = GameByte(0x14E), 
    GB_Unused_END_0A                        = GameByte(0x14F), 
    GB_Unused_BAT_00                        = GameByte(0x150), 
    GB_Unused_BAT_01                        = GameByte(0x151), 
    GB_Unused_BAT_02                        = GameByte(0x152), 
    GB_Unused_BAT_03                        = GameByte(0x153), 
    GB_Unused_BAT_04                        = GameByte(0x154), 
    GB_Unused_BAT_05                        = GameByte(0x155), 
    GB_Unused_BAT_06                        = GameByte(0x156), 
    GB_Unused_BAT_07                        = GameByte(0x157), 
    GB_Unused_BAT_08                        = GameByte(0x158), 
    GB_Unused_BAT_09                        = GameByte(0x159), 
    GB_KootFavor_State                      = GameByte(0x15A), ///< 0  = none, 1  = rejected, 2  = accepted
    GB_KootFavor_Completed                  = GameByte(0x15B), 
    GB_KootFavor_Current                    = GameByte(0x15C), ///< 0 if none active
    GB_MAC02_CurrentBulletin                = GameByte(0x15D), 
    GB_ChuckQuizmo_Town                     = GameByte(0x15E), ///< 0-6, doesnt correspond to areaID
    GB_ChuckQuizmo_Map                      = GameByte(0x15F), ///< doesnt correspond to mapID
    GB_CompletedQuizzes                     = GameByte(0x160), 
    GB_HOS06_Merlow_PurchaseCount           = GameByte(0x161), 
    GB_TradingEvent_Count                   = GameByte(0x162), 
    GB_Unused_NPC_09                        = GameByte(0x163), 
    GB_Unused_NPC_0A                        = GameByte(0x164), 
    GB_Unused_NPC_0B                        = GameByte(0x165), 
    GB_Unused_NPC_0C                        = GameByte(0x166), 
    GB_Unused_NPC_0D                        = GameByte(0x167), 
    GB_Unused_NPC_0E                        = GameByte(0x168), 
    GB_Unused_NPC_0F                        = GameByte(0x169), 
    GB_Unused_NPC_10                        = GameByte(0x16A), 
    GB_Unused_NPC_11                        = GameByte(0x16B), 
    GB_Unused_NPC_12                        = GameByte(0x16C), 
    GB_Tattles_00                           = GameByte(0x16D), 
    GB_Tattles_01                           = GameByte(0x16E), 
    GB_Tattles_02                           = GameByte(0x16F), 
    GB_Tattles_03                           = GameByte(0x170), 
    GB_Tattles_04                           = GameByte(0x171), 
    GB_Tattles_05                           = GameByte(0x172), 
    GB_Tattles_06                           = GameByte(0x173), 
    GB_Tattles_07                           = GameByte(0x174), 
    GB_Tattles_08                           = GameByte(0x175), 
    GB_Tattles_09                           = GameByte(0x176), 
    GB_Tattles_0A                           = GameByte(0x177), 
    GB_Tattles_0B                           = GameByte(0x178), 
    GB_Tattles_0C                           = GameByte(0x179), 
    GB_Tattles_0D                           = GameByte(0x17A), 
    GB_Tattles_0E                           = GameByte(0x17B), 
    GB_Tattles_0F                           = GameByte(0x17C), 
    GB_Tattles_10                           = GameByte(0x17D), 
    GB_Tattles_11                           = GameByte(0x17E), 
    GB_Tattles_12                           = GameByte(0x17F), 
    GB_Tattles_13                           = GameByte(0x180), 
    GB_Tattles_14                           = GameByte(0x181), 
    GB_Tattles_15                           = GameByte(0x182), 
    GB_Tattles_16                           = GameByte(0x183), 
    GB_Tattles_17                           = GameByte(0x184), 
    GB_Tattles_18                           = GameByte(0x185), 
    GB_Tattles_19                           = GameByte(0x186), 
    GB_Tattles_1A                           = GameByte(0x187), 
    GB_Tattles_1B                           = GameByte(0x188), 
    GB_Tattles_1C                           = GameByte(0x189), 
    GB_FinalBowserHP                        = GameByte(0x18A), ///< Used by final bowser to remember HP between first and second phase
    GB_Unused_BTL_1E                        = GameByte(0x18B), 
    GB_Unused_BTL_1F                        = GameByte(0x18C), 
    GB_Unused_BTL_20                        = GameByte(0x18D), 
    GB_Unused_BTL_21                        = GameByte(0x18E), 
    GB_Unused_BTL_22                        = GameByte(0x18F), 
    GB_Unused_BTL_23                        = GameByte(0x190), 
    GB_Unused_BTL_24                        = GameByte(0x191), 
    GB_Unused_BTL_25                        = GameByte(0x192), 
    GB_Unused_BTL_26                        = GameByte(0x193), 
    GB_Unused_BTL_27                        = GameByte(0x194), 
    GB_Unused_FBTL_00                       = GameByte(0x195), 
    GB_Unused_FBTL_01                       = GameByte(0x196), 
    GB_Unused_FBTL_02                       = GameByte(0x197), 
    GB_Unused_FBTL_03                       = GameByte(0x198), 
    GB_Unused_FBTL_04                       = GameByte(0x199), 
    GB_Unused_FBTL_05                       = GameByte(0x19A), 
    GB_Unused_FBTL_06                       = GameByte(0x19B), 
    GB_Unused_FBTL_07                       = GameByte(0x19C), 
    GB_Unused_FBTL_08                       = GameByte(0x19D), 
    GB_Unused_FBTL_09                       = GameByte(0x19E), 
    GB_Unused_DOKAN_00                      = GameByte(0x19F), 
    GB_Unused_DOKAN_01                      = GameByte(0x1A0), 
    GB_Unused_DOKAN_02                      = GameByte(0x1A1), 
    GB_Unused_DOKAN_03                      = GameByte(0x1A2), 
    GB_Unused_DOKAN_04                      = GameByte(0x1A3), 
    GB_Unused_DOKAN_05                      = GameByte(0x1A4), 
    GB_Unused_DOKAN_06                      = GameByte(0x1A5), 
    GB_Unused_DOKAN_07                      = GameByte(0x1A6), 
    GB_Unused_DOKAN_08                      = GameByte(0x1A7), 
    GB_Unused_DOKAN_09                      = GameByte(0x1A8), 
    GB_WorldLocation                        = GameByte(0x1A9), 
    GB_Unused_MAP_01                        = GameByte(0x1AA), 
    GB_Unused_MAP_02                        = GameByte(0x1AB), 
    GB_Unused_MAP_03                        = GameByte(0x1AC), 
    GB_Unused_MAP_04                        = GameByte(0x1AD), 
    GB_Unused_MAP_05                        = GameByte(0x1AE), 
    GB_Unused_MAP_06                        = GameByte(0x1AF), 
    GB_Unused_MAP_07                        = GameByte(0x1B0), 
    GB_Unused_MAP_08                        = GameByte(0x1B1), 
    GB_Unused_MAP_09                        = GameByte(0x1B2), 
    GB_Unused_MAP_0A                        = GameByte(0x1B3), 
    GB_Unused_1B4                           = GameByte(0x1B4), 
    GB_Unused_1B5                           = GameByte(0x1B5), 
    GB_Unused_1B6                           = GameByte(0x1B6), 
    GB_Unused_1B7                           = GameByte(0x1B7), 
    GB_Unused_1B8                           = GameByte(0x1B8), 
    GB_Unused_1B9                           = GameByte(0x1B9), 
    GB_Unused_1BA                           = GameByte(0x1BA), 
    GB_Unused_1BB                           = GameByte(0x1BB), 
    GB_Unused_1BC                           = GameByte(0x1BC), 
    GB_Unused_1BD                           = GameByte(0x1BD), 
    GB_Unused_1BE                           = GameByte(0x1BE), 
    GB_Unused_1BF                           = GameByte(0x1BF), 
    GB_Unused_1C0                           = GameByte(0x1C0), 
    GB_Unused_1C1                           = GameByte(0x1C1), 
    GB_Unused_1C2                           = GameByte(0x1C2), 
    GB_Unused_1C3                           = GameByte(0x1C3), 
    GB_Unused_1C4                           = GameByte(0x1C4), 
    GB_Unused_1C5                           = GameByte(0x1C5), 
    GB_Unused_1C6                           = GameByte(0x1C6), 
    GB_Unused_1C7                           = GameByte(0x1C7), 
    GB_Unused_1C8                           = GameByte(0x1C8), 
    GB_Unused_1C9                           = GameByte(0x1C9), 
    GB_Unused_1CA                           = GameByte(0x1CA), 
    GB_Unused_1CB                           = GameByte(0x1CB), 
    GB_Unused_1CC                           = GameByte(0x1CC), 
    GB_Unused_1CD                           = GameByte(0x1CD), 
    GB_Unused_1CE                           = GameByte(0x1CE), 
    GB_Unused_1CF                           = GameByte(0x1CF), 
    GB_Unused_1D0                           = GameByte(0x1D0), 
    GB_Unused_1D1                           = GameByte(0x1D1), 
    GB_Unused_1D2                           = GameByte(0x1D2), 
    GB_Unused_1D3                           = GameByte(0x1D3), 
    GB_Unused_1D4                           = GameByte(0x1D4), 
    GB_Unused_1D5                           = GameByte(0x1D5), 
    GB_Unused_1D6                           = GameByte(0x1D6), 
    GB_Unused_1D7                           = GameByte(0x1D7), 
    GB_Unused_1D8                           = GameByte(0x1D8), 
    GB_Unused_1D9                           = GameByte(0x1D9), 
    GB_Unused_1DA                           = GameByte(0x1DA), 
    GB_Unused_1DB                           = GameByte(0x1DB), 
    GB_Unused_1DC                           = GameByte(0x1DC), 
    GB_Unused_1DD                           = GameByte(0x1DD), 
    GB_Unused_1DE                           = GameByte(0x1DE), 
    GB_Unused_1DF                           = GameByte(0x1DF), 
    GB_Unused_1E0                           = GameByte(0x1E0), 
    GB_Unused_1E1                           = GameByte(0x1E1), 
    GB_Unused_1E2                           = GameByte(0x1E2), 
    GB_Unused_1E3                           = GameByte(0x1E3), 
    GB_Unused_1E4                           = GameByte(0x1E4), 
    GB_Unused_1E5                           = GameByte(0x1E5), 
    GB_Unused_1E6                           = GameByte(0x1E6), 
    GB_Unused_1E7                           = GameByte(0x1E7), 
    GB_Unused_1E8                           = GameByte(0x1E8), 
    GB_Unused_1E9                           = GameByte(0x1E9), 
    GB_Unused_1EA                           = GameByte(0x1EA), 
    GB_Unused_1EB                           = GameByte(0x1EB), 
    GB_Unused_1EC                           = GameByte(0x1EC), 
    GB_Unused_1ED                           = GameByte(0x1ED), 
    GB_Unused_1EE                           = GameByte(0x1EE), 
    GB_Unused_1EF                           = GameByte(0x1EF), 
    GB_Unused_1F0                           = GameByte(0x1F0), 
    GB_Unused_1F1                           = GameByte(0x1F1), 
    GB_Unused_1F2                           = GameByte(0x1F2), 
    GB_Unused_1F3                           = GameByte(0x1F3), 
    GB_Unused_1F4                           = GameByte(0x1F4), 
    GB_Unused_1F5                           = GameByte(0x1F5), 
    GB_Unused_1F6                           = GameByte(0x1F6), 
    GB_Unused_1F7                           = GameByte(0x1F7), 
    GB_Unused_1F8                           = GameByte(0x1F8), 
    GB_Unused_1F9                           = GameByte(0x1F9), 
    GB_Unused_1FA                           = GameByte(0x1FA), 
    GB_Unused_1FB                           = GameByte(0x1FB), 
    GB_Unused_1FC                           = GameByte(0x1FC), 
    GB_Unused_1FD                           = GameByte(0x1FD), 
    GB_Unused_1FE                           = GameByte(0x1FE), 
    GB_Unused_1FF                           = GameByte(0x1FF),
};
