.include "macro.inc"

.section .data

glabel D_80242030_8883F0
.word 0x001D00F0, 0x001D00F1

glabel D_80242038_8883F8
.word 0x00010002, 0x00030004, 0x00090006, 0x00070008

glabel D_80242048_888408
.word 0x001D00E0, 0x001D00E1, 0x001D00E2, 0x001D00E3, 0x001D00E4, 0x001D00E5, 0x001D00E6, 0x001D00E7, 0x001D00E8, 0x001D00E9, 0x001D00EA, 0x001D00EB, 0x001D00EC, 0x001D00ED, 0x001D00EE, 0x001D00EF

glabel D_80242088_888448
.word 0x430C0000, 0x43340000, 0x435C0000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, PlaySound, 0x0000212D, 0x00000043, 0x00000002, tik_10_UnkFunc21, 0xFD050F80, 0x00000008, 0x00000001, 0x00000055, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x0000212E, 0x00000043, 0x00000003, tik_10_UnkFunc23, 0x00000046, 0x00000046, 0x00000008, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, PlaySound, 0x0000208E, 0x00000043, 0x00000003, tik_10_UnkFunc23, 0x00000032, 0x00000032, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_802406BC_886A7C, 0xFD050F80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002F, 0x00000043, 0x00000001, tik_10_UnkFunc22, 0x00000043, 0x00000001, tik_10_UnkPartnerPosFunc, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, tik_10_UnkPartnerPosFunc2, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, tik_10_UnkPartnerPosFunc, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, func_80240C80_887040, 0xFD050F80, 0x00000008, 0x00000001, 0x0000001E, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D32, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80241388_887748, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, func_802D585C, 0x00000001, 0x00200000, 0x00000043, 0x00000001, tik_10_SetOverrideFlags_40, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x00000043, 0x00000003, tik_10_UnkFunc20, 0xFD050F80, 0xFE363C89, 0x00000043, 0x00000003, FindKeyItem, 0x0000000F, 0xFE363C8C, 0x00000043, 0x00000001, func_802407A0_886B60, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DC, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, func_80240B90_886F50, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, tik_10_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D36, 0x00000000, 0x00000024, 0x00000002, 0xF8405D36, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DA, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DB, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_8024084C_886C0C, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000002, func_80240B90_886F50, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, tik_10_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000043, 0x00000002, func_80240A9C_886E5C, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DF, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, ShowChoice, 0x001E000D, 0x00000043, 0x00000001, CloseMessage, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, func_80240B90_886F50, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, tik_10_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000046, 0x00000001, 0x80242094, 0x00000043, 0x00000003, tik_10_UnkFunc18, 0xFE363C8B, 0xFE363C8D, 0x00000024, 0x00000002, 0xF8405D32, 0x00000001, 0x00000043, 0x00000002, func_80240B90_886F50, 0xFE363C89, 0x00000043, 0x00000001, tik_10_UnkFunc19, 0x0000000A, 0x00000002, 0xFE363C8D, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DD, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DE, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, func_802D585C, 0x00000000, 0x00200000, 0x00000043, 0x00000001, tik_10_UnkFunc17, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA910, 0xFFFFFF74, 0x000000A0, 0xFFFFFFD8, 0x00000000, D_80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405D32, 0x00000043, 0x00000002, AssignScript, 0x802421F8, 0x00000043, 0x00000008, CreatePushBlockGrid, 0x00000000, 0x00000007, 0x00000006, 0xFFFFFFC0, 0xFFFFFFF1, 0xFFFFFFA2, 0x00000000, 0x00000043, 0x00000005, SetPushBlock, 0x00000000, 0x00000001, 0x00000004, 0x00000001, 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0xFFFFFFCC, 0x00000046, 0xFFFFFFE0, 0x00000000, 0x00000157, D_80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405D15, 0x00000043, 0x00000002, UseDynamicShadow, 0x00000001, 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0x00000017, 0x00000046, 0xFFFFFFE0, 0x00000000, 0x00000157, D_80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405D16, 0x00000043, 0x00000002, UseDynamicShadow, 0x00000001, 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0x00000062, 0x00000046, 0xFFFFFFE0, 0x00000000, 0x00000157, D_80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405D17, 0x00000043, 0x00000002, UseDynamicShadow, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
