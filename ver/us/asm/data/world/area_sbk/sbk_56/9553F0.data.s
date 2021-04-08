.include "macro.inc"

.section .data

glabel D_80241430_9553F0
.word 0x001D00F0, 0x001D00F1

glabel D_80241438_9553F8
.word 0x00010002, 0x00030004, 0x00090006, 0x00070008

glabel D_80241448_955408
.word 0x001D00E0, 0x001D00E1, 0x001D00E2, 0x001D00E3, 0x001D00E4, 0x001D00E5, 0x001D00E6, 0x001D00E7, 0x001D00E8, 0x001D00E9, 0x001D00EA, 0x001D00EB, 0x001D00EC, 0x001D00ED, 0x001D00EE, 0x001D00EF

glabel D_80241488_955448
.word 0x430C0000, 0x43340000, 0x435C0000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, PlaySound, 0x0000212D, 0x00000043, 0x00000002, func_802405C4_954584, 0xFD050F80, 0x00000008, 0x00000001, 0x00000055, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x0000212E, 0x00000043, 0x00000003, func_80240BB8_954B78, 0x00000046, 0x00000046, 0x00000008, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, PlaySound, 0x0000208E, 0x00000043, 0x00000003, func_80240BB8_954B78, 0x00000032, 0x00000032, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_802400BC_95407C, 0xFD050F80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002F, 0x00000043, 0x00000001, func_80240628_9545E8, 0x00000043, 0x00000001, sbk_56_UnkPartnerPosFunc, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, sbk_56_UnkPartnerPosFunc2, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, sbk_56_UnkPartnerPosFunc, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_80240680_954640, 0xFD050F80, 0x00000008, 0x00000001, 0x0000001E, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8405EBD, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80240D88_954D48, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, func_802D585C, 0x00000001, 0x00200000, 0x00000043, 0x00000001, sbk_56_SetOverrideFlags_40, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x00000043, 0x00000003, func_80240500_9544C0, 0xFD050F80, 0xFE363C89, 0x00000043, 0x00000003, FindKeyItem, 0x0000000F, 0xFE363C8C, 0x00000043, 0x00000001, func_802401A0_954160, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DC, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, func_80240590_954550, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D36, 0x00000000, 0x00000024, 0x00000002, 0xF8405D36, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DA, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DB, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_8024024C_95420C, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000002, func_80240590_954550, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000043, 0x00000002, func_8024049C_95445C, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DF, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, ShowChoice, 0x001E000D, 0x00000043, 0x00000001, CloseMessage, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, func_80240590_954550, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000046, 0x00000001, 0x80241494, 0x00000043, 0x00000003, sbk_56_UnkFunc18, 0xFE363C8B, 0xFE363C8D, 0x00000024, 0x00000002, 0xF8405EBD, 0x00000001, 0x00000043, 0x00000002, func_80240590_954550, 0xFE363C89, 0x00000043, 0x00000001, func_802404C8_954488, 0x0000000A, 0x00000002, 0xFE363C8D, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DD, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DE, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA7E0, 0x0000012C, 0x0000003C, 0x00000000, 0x00000000, D_80000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA910, 0xFFFFFFCE, 0x0000003C, 0x00000113, 0x00000000, D_80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405EBD, 0x00000043, 0x00000002, AssignScript, 0x802415F8, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C8F, 0xFE363C87, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0x00000001, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000153, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0xFFFFFFFF, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000033, 0x00000003, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000033, 0x00000003, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8A, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000046, 0x00000001, 0xFE363C84, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000004C, 0x00000001, 0xF24A8280, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C86, 0xFE363C8F, 0xFE363C88, 0x00000043, 0x00000002, PlaySound, 0x00000165, 0x00000043, 0x00000002, PlaySound, 0x00000166, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000166, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, sbk_56_SomeMatrixOperation2, 0xFE363C84, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C84, 0x00000165, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, sbk_56_SomeMatrixOperation2, 0xFE363C84, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000005, TranslateModel, 0xFE363C84, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000000, 0x00000030, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000005, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000033, 0x00000003, 0xFE363C89, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8B, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8B, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000030, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000005, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x0000000F, PlayEffect, 0x00000014, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C85, 0x00000000, 0x00000046, 0x00000001, 0xFE363C85, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0x00000019, 0x00000001, 0x0000001A, 0x00000001, 0x0000009C, 0xFFFFFED0, 0x0000005C, 0xFFFFFF50, 0x0000000E, 0xF8405E98, 0xFAA2B58A, 0x80242464, 0x8024246C, 0x80242474, 0x00000000, 0x00000000, 0xC3818000, 0x00000000, 0xC3200000, 0x00000000, 0x00000001, 0x00000019, 0x00000001, 0x0000001A, 0x00000001, 0x0000009D, 0x000000E6, 0x0000004D, 0xFFFFFED0, 0x0000000E, 0xF8405E9A, 0xFAA2B58C, 0x802424B8, 0x802424C0, 0x802424C8, 0x00000000, 0x00000000, 0x432B0000, 0x00000000, 0xC3918000, 0x00000000, 0x00000001, 0x00000020, 0x00000001, 0x0000001F, 0x00000001, 0x00000157, 0xFFFFFE4C, 0x00000064, 0x000000F9, 0x0000000F, 0xF8405ECE, 0x00000000, 0x8024250C, 0x80242514, 0x8024251C, 0x00000000, 0x00000000, 0xC3DA0000, 0x00000000, 0x43600000, 0x00000000, 0x00000001, 0x00000024, 0x00000001, 0x00000023, 0x80242560, 0x80242568, 0x00000000, 0x00000000, 0x00000000, 0xC3A00000, 0x00000000, 0xC1A80000, 0x00000000, 0x00000001, 0x00000028, 0x00000001, 0x00000027, 0x80242594, 0x8024259C, 0x00000000, 0x00000000, 0x00000000, 0xC3720000, 0x00000000, 0x42B00000, 0x00000000, 0x00000001, 0x0000002C, 0x00000001, 0x0000002B, 0x802425C8, 0x802425D0, 0x00000000, 0x00000000, 0x00000000, 0xC34B0000, 0x00000000, 0xC3560000, 0x00000000, 0x00000001, 0x00000030, 0x00000001, 0x0000002F, 0x802425FC, 0x80242604, 0x00000000, 0x00000000, 0x00000000, 0xC2CA0000, 0x00000000, 0xC3BC0000, 0x00000000, 0x00000001, 0x00000034, 0x00000001, 0x00000033, 0x80242630, 0x80242638, 0x00000000, 0x00000000, 0x00000000, 0x42D00000, 0x00000000, 0xC3C10000, 0x00000000, 0x00000001, 0x0000003A, 0x00000001, 0x00000039, 0x00000001, 0x00000157, 0x0000010A, 0x00000064, 0x00000095, 0x0000000F, 0xF8405ECF, 0x00000000, 0x80242664, 0x8024266C, 0x80242674, 0x00000000, 0x00000000, 0x43850000, 0x00000000, 0x42F80000, 0x00000000, 0x00000001, 0x0000003D, 0x00000001, 0x0000003C, 0x802426B8, 0x802426C0, 0x00000000, 0x00000000, 0x00000000, 0x43B50000, 0x00000000, 0xC2940000, 0x00000000, 0x00000024, 0x00000002, 0xF8405E98, 0x00000000, 0x00000024, 0x00000002, 0xF8405E99, 0x00000000, 0x00000024, 0x00000002, 0xF8405E9A, 0x00000000, 0x00000024, 0x00000002, 0xF8405E9B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x80242494, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x00000012, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x802424A8, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x802424E8, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x00000013, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x802424FC, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x8024253C, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x00000015, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x80242550, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x80242570, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x00000016, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x80242584, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x802425A4, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x00000017, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x802425B8, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x802425D8, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x00000018, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x802425EC, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x8024260C, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x00000019, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x80242620, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x80242640, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x0000001A, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x80242654, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x80242694, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x0000001B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x802426A8, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x802426C8, 0x00000047, 0x00000005, 0x80241E60, 0x00001000, 0x0000001C, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x80241E60, 0x00100000, 0x802426DC, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
