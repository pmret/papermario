.include "macro.inc"

.section .data

dlabel D_80241EE0_CB0C20
.word 0xC4598000, 0x00000000, 0x00000000, 0x42B40000, 0x440E8000, 0x00000000, 0x00000000, 0x43870000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80242A6C_CB17AC, D_80241EE0_CB0C20, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x00190117

dlabel D_80241F40_CB0C80
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x00000035, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000030, 0x00000000, 0x00000008, 0x0000001C, 0x00000000, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000031, 0x00000000, 0x00000008, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241FB0_CB0CF0
.word 0x001D00F0, 0x001D00F1

dlabel D_80241FB8_CB0CF8
.word 0x00010002, 0x00030004, 0x00090006, 0x00070008

dlabel D_80241FC8_CB0D08
.word 0x001D00E0, 0x001D00E1, 0x001D00E2, 0x001D00E3, 0x001D00E4, 0x001D00E5, 0x001D00E6, 0x001D00E7, 0x001D00E8, 0x001D00E9, 0x001D00EA, 0x001D00EB, 0x001D00EC, 0x001D00ED, 0x001D00EE, 0x001D00EF

dlabel D_80242008_CB0D48
.word 0x430C0000, 0x43340000, 0x435C0000

dlabel D_80242014_CB0D54
.word 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, PlaySound, 0x0000212D, 0x00000043, 0x00000002, flo_08_UnkFunc21, 0xFD050F80, 0x00000008, 0x00000001, 0x00000055, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x0000212E, 0x00000043, 0x00000003, flo_08_UnkFunc23, 0x00000046, 0x00000046, 0x00000008, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, PlaySound, 0x0000208E, 0x00000043, 0x00000003, flo_08_UnkFunc23, 0x00000032, 0x00000032, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_8024003C_CAED7C, 0xFD050F80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002F, 0x00000043, 0x00000001, flo_08_UnkFunc22, 0x00000043, 0x00000001, flo_08_UnkPartnerPosFunc, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, flo_08_UnkPartnerPosFunc2, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, flo_08_UnkPartnerPosFunc, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_80240600_CAF340, 0xFD050F80, 0x00000008, 0x00000001, 0x0000001E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242178_CB0EB8
.word 0x0000000A, 0x00000002, 0xF84060FA, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80240D08_CAFA48, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000001, 0x00200000, 0x00000043, 0x00000001, flo_08_SetOverrideFlags_40, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x00000043, 0x00000003, flo_08_UnkFunc20, 0xFD050F80, 0xFE363C89, 0x00000043, 0x00000003, FindKeyItem, 0x0000000F, 0xFE363C8C, 0x00000043, 0x00000001, func_80240120_CAEE60, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DC, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, func_80240510_CAF250, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, flo_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D36, 0x00000000, 0x00000024, 0x00000002, 0xF8405D36, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DA, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DB, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_802401CC_CAEF0C, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000002, func_80240510_CAF250, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, flo_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000043, 0x00000002, flo_08_SwitchToPartner, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DF, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, ShowChoice, 0x001E000D, 0x00000043, 0x00000001, CloseMessage, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, func_80240510_CAF250, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, flo_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_80242014_CB0D54, 0x00000043, 0x00000003, flo_08_UnkFunc18, 0xFE363C8B, 0xFE363C8D, 0x00000024, 0x00000002, 0xF84060FA, 0x00000001, 0x00000043, 0x00000002, func_80240510_CAF250, 0xFE363C89, 0x00000043, 0x00000001, flo_08_UnkFunc19, 0x0000000A, 0x00000002, 0xFE363C8D, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DD, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DE, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, flo_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802425F8_CB1338
.word 0x00000043, 0x00000007, MakeEntity, 0x802EA910, 0xFFFFFCF4, 0x00000078, 0xFFFFFF92, 0x00000000, 0x80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000002, AssignBlockFlag, 0xF84060FA, 0x00000043, 0x00000002, AssignScript, D_80242178_CB0EB8, 0x00000043, 0x00000007, MakeItemEntity, 0x0000015C, 0x000001FE, 0x00000000, 0xFFFFFFA6, 0x00000011, 0xF84060E5, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242680_CB13C0
.word 0x0000004D, 0x00000001, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000024, 0x00000002, 0xFE363C8C, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C8D, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C8E, 0xFE363C84, 0x00000028, 0x00000002, 0xFE363C8C, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C8D, 0xFE363C81, 0x00000026, 0x00000002, 0xFE363C80, 0xFE363C8C, 0x0000002F, 0x00000002, 0xFE363C80, 0xF24C0A80, 0x00000026, 0x00000002, 0xFE363C8F, 0xF24C0A80, 0x0000002F, 0x00000002, 0xFE363C8F, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C8F, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C85, 0x000000C8, 0x0000002A, 0x00000002, 0xFE363C85, 0xFE363C8F, 0x00000027, 0x00000002, 0xFE363C85, 0x00000001, 0x00000005, 0x00000001, 0xFE363C85, 0x00000043, 0x00000003, RandInt, 0xFE363C8C, 0xFE363C80, 0x00000043, 0x00000003, RandInt, 0xFE363C8D, 0xFE363C81, 0x00000043, 0x00000003, RandInt, 0x000000C7, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C83, 0x000000D2, 0x00000028, 0x00000002, 0xFE363C83, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C8B, 0x00000027, 0x00000002, 0xFE363C82, 0xFE363C8E, 0x00000043, 0x0000000F, PlayEffect, 0x0000000D, 0xFE363C80, 0xFE363C82, 0xFE363C81, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0xFE363C8F, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0xFE363C8C, 0xFE363C80, 0x00000043, 0x00000003, RandInt, 0xFE363C8D, 0xFE363C81, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C81, 0xFE363C8B, 0x00000043, 0x0000000F, PlayEffect, 0x0000000D, 0xFE363C80, 0xFE363C8E, 0xFE363C81, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0xFE363C8F, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024292C_CB166C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80246120, 0x00000006, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242988_CB16C8
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80246128, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802429E4_CB1724
.word 0x00000047, 0x00000005, D_8024292C_CB166C, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242988_CB16C8, 0x00080000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242A2C_CB176C
.word 0x00000009, 0xC4070000, 0x00000000, 0x42480000, 0x0000000A, 0x42700000, 0x00000000, 0x42480000, 0x0000000F, 0x42700000, 0x00000000, 0x42480000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242A6C_CB17AC
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000026, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80244EC4, 0x00000046, 0x00000001, D_802425F8_CB1338, 0x00000044, 0x00000001, 0x80245F5C, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000013, 0x00000002, 0x00000056, 0x00000000, 0x00000043, 0x00000002, ResetFromLava, D_80242A2C_CB176C, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x00000016, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000017, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000019, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000001B, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000001D, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000001F, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000029, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000018, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000001A, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000001C, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000001E, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000020, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x0000008C, 0x0000000D, 0x00000002, 0xFE363C80, 0x00010000, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFF0000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFF38, 0x0000000C, 0x00000002, 0xFE363C81, 0x00000000, 0x00000027, 0x00000002, 0xFE363C81, 0x00010000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000002, 0x00000000, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000015, 0x00000006, 0x00000024, 0x00000002, 0xFE363C80, 0x0000008C, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF77, 0x00000024, 0x00000002, 0xFE363C82, 0x00000154, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFC4, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000044, 0x00000001, D_80242680_CB13C0, 0x00000024, 0x00000002, 0xFE363C80, 0x000001C2, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFF77, 0x00000024, 0x00000002, 0xFE363C82, 0x0000024E, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFC4, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000044, 0x00000001, D_80242680_CB13C0, 0x00000044, 0x00000001, 0x80245914, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000001, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000005, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, D_802429E4_CB1724, 0x00000044, 0x00000001, EnterWalk, 0x00000046, 0x00000001, D_80241F40_CB0C80, 0x0000000F, 0x00000002, 0xF5DE0180, 0x00000035, 0x00000043, 0x00000001, func_80240D40_CAFA80, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
