.include "macro.inc"

.section .data

dlabel D_80241430_9553F0
.word 0x001D00F0, 0x001D00F1

dlabel D_80241438_9553F8
.word 0x00010002, 0x00030004, 0x00090006, 0x00070008

dlabel D_80241448_955408
.word 0x001D00E0, 0x001D00E1, 0x001D00E2, 0x001D00E3, 0x001D00E4, 0x001D00E5, 0x001D00E6, 0x001D00E7, 0x001D00E8, 0x001D00E9, 0x001D00EA, 0x001D00EB, 0x001D00EC, 0x001D00ED, 0x001D00EE, 0x001D00EF

dlabel D_80241488_955448
.word 0x430C0000, 0x43340000, 0x435C0000

dlabel D_80241494_955454
.word 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, PlaySound, 0x0000212D, 0x00000043, 0x00000002, sbk_56_UnkFunc21, 0xFD050F80, 0x00000008, 0x00000001, 0x00000055, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x0000212E, 0x00000043, 0x00000003, sbk_56_UnkFunc23, 0x00000046, 0x00000046, 0x00000008, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, PlaySound, 0x0000208E, 0x00000043, 0x00000003, sbk_56_UnkFunc23, 0x00000032, 0x00000032, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_802400BC_95407C, 0xFD050F80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002F, 0x00000043, 0x00000001, sbk_56_UnkFunc22, 0x00000043, 0x00000001, sbk_56_UnkPartnerPosFunc, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, sbk_56_UnkPartnerPosFunc2, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, sbk_56_UnkPartnerPosFunc, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_80240680_954640, 0xFD050F80, 0x00000008, 0x00000001, 0x0000001E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415F8_9555B8
.word 0x0000000A, 0x00000002, 0xF8405EBD, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, sbk_56_UnkFunc40, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000001, 0x00200000, 0x00000043, 0x00000001, sbk_56_SetOverrideFlags_40, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x00000043, 0x00000003, sbk_56_UnkFunc20, 0xFD050F80, 0xFE363C89, 0x00000043, 0x00000003, FindKeyItem, 0x0000000F, 0xFE363C8C, 0x00000043, 0x00000001, sbk_56_UnkFunc38, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DC, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, sbk_56_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D36, 0x00000000, 0x00000024, 0x00000002, 0xF8405D36, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DA, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DB, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_8024024C_95420C, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000002, sbk_56_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000043, 0x00000002, sbk_56_SwitchToPartner, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DF, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, ShowChoice, 0x001E000D, 0x00000043, 0x00000001, CloseMessage, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, sbk_56_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_80241494_955454, 0x00000043, 0x00000003, sbk_56_UnkFunc18, 0xFE363C8B, 0xFE363C8D, 0x00000024, 0x00000002, 0xF8405EBD, 0x00000001, 0x00000043, 0x00000002, sbk_56_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000001, sbk_56_UnkFunc19, 0x0000000A, 0x00000002, 0xFE363C8D, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DD, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DE, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sbk_56_UnkFunc17, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA7E0, 0x0000012C, 0x0000003C, 0x00000000, 0x00000000, D_80000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA910, 0xFFFFFFCE, 0x0000003C, 0x00000113, 0x00000000, D_80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405EBD, 0x00000043, 0x00000002, AssignScript, D_802415F8_9555B8, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C8F, 0xFE363C87, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0x00000001, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000153, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xFFFFFFFF, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000033, 0x00000003, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000033, 0x00000003, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8A, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000046, 0x00000001, 0xFE363C84, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241E60_955E20
.word 0x0000004C, 0x00000001, 0xF24A8280, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C86, 0xFE363C8F, 0xFE363C88, 0x00000043, 0x00000002, PlaySound, 0x00000165, 0x00000043, 0x00000002, PlaySound, 0x00000166, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000166, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, sbk_56_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, sbk_56_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C84, 0x00000165, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, sbk_56_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000005, TranslateModel, 0xFE363C84, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000000, 0x00000030, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000005, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000033, 0x00000003, 0xFE363C89, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8B, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8B, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000030, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000005, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x0000000F, PlayEffect, 0x00000014, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C85, 0x00000000, 0x00000046, 0x00000001, 0xFE363C85, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242464_956424
.word 0x00000001, 0x00000019

dlabel D_8024246C_95642C
.word 0x00000001, 0x0000001A

dlabel D_80242474_956434
.word 0x00000001, 0x0000009C, 0xFFFFFED0, 0x0000005C, 0xFFFFFF50, 0x0000000E, 0xF8405E98, 0xFAA2B58A

dlabel D_80242494_956454
.word D_80242464_956424, D_8024246C_95642C, D_80242474_956434, 0x00000000, 0x00000000

dlabel D_802424A8_956468
.word 0xC3818000, 0x00000000, 0xC3200000, 0x00000000

dlabel D_802424B8_956478
.word 0x00000001, 0x00000019

dlabel D_802424C0_956480
.word 0x00000001, 0x0000001A

dlabel D_802424C8_956488
.word 0x00000001, 0x0000009D, 0x000000E6, 0x0000004D, 0xFFFFFED0, 0x0000000E, 0xF8405E9A, 0xFAA2B58C

dlabel D_802424E8_9564A8
.word D_802424B8_956478, D_802424C0_956480, D_802424C8_956488, 0x00000000, 0x00000000

dlabel D_802424FC_9564BC
.word 0x432B0000, 0x00000000, 0xC3918000, 0x00000000

dlabel D_8024250C_9564CC
.word 0x00000001, 0x00000020

dlabel D_80242514_9564D4
.word 0x00000001, 0x0000001F

dlabel D_8024251C_9564DC
.word 0x00000001, 0x00000157, 0xFFFFFE4C, 0x00000064, 0x000000F9, 0x0000000F, 0xF8405ECE, 0x00000000

dlabel D_8024253C_9564FC
.word D_8024250C_9564CC, D_80242514_9564D4, D_8024251C_9564DC, 0x00000000, 0x00000000

dlabel D_80242550_956510
.word 0xC3DA0000, 0x00000000, 0x43600000, 0x00000000

dlabel D_80242560_956520
.word 0x00000001, 0x00000024

dlabel D_80242568_956528
.word 0x00000001, 0x00000023

dlabel D_80242570_956530
.word D_80242560_956520, D_80242568_956528, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242584_956544
.word 0xC3A00000, 0x00000000, 0xC1A80000, 0x00000000

dlabel D_80242594_956554
.word 0x00000001, 0x00000028

dlabel D_8024259C_95655C
.word 0x00000001, 0x00000027

dlabel D_802425A4_956564
.word D_80242594_956554, D_8024259C_95655C, 0x00000000, 0x00000000, 0x00000000

dlabel D_802425B8_956578
.word 0xC3720000, 0x00000000, 0x42B00000, 0x00000000

dlabel D_802425C8_956588
.word 0x00000001, 0x0000002C

dlabel D_802425D0_956590
.word 0x00000001, 0x0000002B

dlabel D_802425D8_956598
.word D_802425C8_956588, D_802425D0_956590, 0x00000000, 0x00000000, 0x00000000

dlabel D_802425EC_9565AC
.word 0xC34B0000, 0x00000000, 0xC3560000, 0x00000000

dlabel D_802425FC_9565BC
.word 0x00000001, 0x00000030

dlabel D_80242604_9565C4
.word 0x00000001, 0x0000002F

dlabel D_8024260C_9565CC
.word D_802425FC_9565BC, D_80242604_9565C4, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242620_9565E0
.word 0xC2CA0000, 0x00000000, 0xC3BC0000, 0x00000000

dlabel D_80242630_9565F0
.word 0x00000001, 0x00000034

dlabel D_80242638_9565F8
.word 0x00000001, 0x00000033

dlabel D_80242640_956600
.word D_80242630_9565F0, D_80242638_9565F8, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242654_956614
.word 0x42D00000, 0x00000000, 0xC3C10000, 0x00000000

dlabel D_80242664_956624
.word 0x00000001, 0x0000003A

dlabel D_8024266C_95662C
.word 0x00000001, 0x00000039

dlabel D_80242674_956634
.word 0x00000001, 0x00000157, 0x0000010A, 0x00000064, 0x00000095, 0x0000000F, 0xF8405ECF, 0x00000000

dlabel D_80242694_956654
.word D_80242664_956624, D_8024266C_95662C, D_80242674_956634, 0x00000000, 0x00000000

dlabel D_802426A8_956668
.word 0x43850000, 0x00000000, 0x42F80000, 0x00000000

dlabel D_802426B8_956678
.word 0x00000001, 0x0000003D

dlabel D_802426C0_956680
.word 0x00000001, 0x0000003C

dlabel D_802426C8_956688
.word D_802426B8_956678, D_802426C0_956680, 0x00000000, 0x00000000, 0x00000000

dlabel D_802426DC_95669C
.word 0x43B50000, 0x00000000, 0xC2940000, 0x00000000, 0x00000024, 0x00000002, 0xF8405E98, 0x00000000, 0x00000024, 0x00000002, 0xF8405E99, 0x00000000, 0x00000024, 0x00000002, 0xF8405E9A, 0x00000000, 0x00000024, 0x00000002, 0xF8405E9B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80242494_956454, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x00000012, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_802424A8_956468, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802424E8_9564A8, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x00000013, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_802424FC_9564BC, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_8024253C_9564FC, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x00000015, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_80242550_956510, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80242570_956530, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x00000016, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_80242584_956544, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802425A4_956564, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x00000017, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_802425B8_956578, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802425D8_956598, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x00000018, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_802425EC_9565AC, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_8024260C_9565CC, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x00000019, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_80242620_9565E0, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80242640_956600, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x0000001A, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_80242654_956614, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80242694_956654, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x0000001B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_802426A8_956668, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802426C8_956688, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00001000, 0x0000001C, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241E60_955E20, 0x00100000, D_802426DC_95669C, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
