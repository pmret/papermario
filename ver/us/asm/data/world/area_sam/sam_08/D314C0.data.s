.include "macro.inc"

.section .data

dlabel D_80241840_D314C0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802464C0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024189C_D3151C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802464C8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802418F8_D31578
.word 0x00000047, 0x00000005, D_80241840_D314C0, 0x00080000, 0x0000000F, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024189C_D3151C, 0x00080000, 0x00000014, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000002B, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80243924, 0x00000046, 0x00000001, D_80242128_D31DA8, 0x00000046, 0x00000001, 0x80241810, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000000, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000004, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000006, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000008, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000002, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000F, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000014, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000001B, 0x7FFFFE00, 0x00000046, 0x00000001, 0x80246424, 0x00000024, 0x00000002, 0xFE363C80, D_802418F8_D31578, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel sam_08_SuperBlockDataA
.word 0x001D00F0, 0x001D00F1

dlabel sam_08_SuperBlockDataB
.word 0x00010002, 0x00030004, 0x00090006, 0x00070008

dlabel sam_08_SuperBlockDataC
.word 0x001D00E0, 0x001D00E1, 0x001D00E2, 0x001D00E3, 0x001D00E4, 0x001D00E5, 0x001D00E6, 0x001D00E7, 0x001D00E8, 0x001D00E9, 0x001D00EA, 0x001D00EB, 0x001D00EC, 0x001D00ED, 0x001D00EE, 0x001D00EF

dlabel sam_08_SuperBlockDataD
.word 0x430C0000, 0x43340000, 0x435C0000

dlabel D_80241B44_D317C4
.word 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, PlaySound, 0x0000212D, 0x00000043, 0x00000002, sam_08_UnkFunc21, 0xFD050F81, 0x00000008, 0x00000001, 0x00000055, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x0000212E, 0x00000043, 0x00000003, sam_08_UnkFunc23, 0x00000046, 0x00000046, 0x00000008, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, PlaySound, 0x0000208E, 0x00000043, 0x00000003, sam_08_UnkFunc23, 0x00000032, 0x00000032, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, sam_08_TempSuperBlockAlpha, 0xFD050F81, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002F, 0x00000043, 0x00000001, sam_08_UnkFunc22, 0x00000043, 0x00000001, sam_08_UnkPartnerPosFunc, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, sam_08_UnkPartnerPosFunc2, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, sam_08_UnkPartnerPosFunc, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, sam_08_UnkFunc60, 0xFD050F81, 0x00000008, 0x00000001, 0x0000001E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241CA8_D31928
.word 0x0000000A, 0x00000002, 0xF8406131, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, sam_08_UnkFunc40, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000001, 0x00200000, 0x00000043, 0x00000001, sam_08_SetOverrideFlags_40, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x00000043, 0x00000003, sam_08_UnkFunc20, 0xFD050F81, 0xFE363C89, 0x00000043, 0x00000003, FindKeyItem, 0x0000000F, 0xFE363C8C, 0x00000043, 0x00000001, sam_08_UnkFunc38, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DC, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, sam_08_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sam_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D36, 0x00000000, 0x00000024, 0x00000002, 0xF8405D36, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DA, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DB, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_802401CC_D2FE4C, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000002, sam_08_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sam_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000043, 0x00000002, sam_08_SwitchToPartner, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DF, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, ShowChoice, 0x001E000D, 0x00000043, 0x00000001, CloseMessage, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, sam_08_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sam_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_80241B44_D317C4, 0x00000043, 0x00000003, sam_08_UnkFunc18, 0xFE363C8B, 0xFE363C8D, 0x00000024, 0x00000002, 0xF8406131, 0x00000001, 0x00000043, 0x00000002, sam_08_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000001, sam_08_UnkFunc19, 0x0000000A, 0x00000002, 0xFE363C8D, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DD, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DE, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, sam_08_UnkFunc17, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242128_D31DA8
.word 0x00000043, 0x00000007, MakeEntity, 0x802EA910, 0xFFFFFCE0, 0x000000D2, 0xFFFFFF7E, 0x00000000, 0x80000000, 0x00000024, 0x00000002, 0xFD050F81, 0xFE363C80, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8406131, 0x00000043, 0x00000002, AssignScript, D_80241CA8_D31928, 0x00000043, 0x00000007, MakeItemEntity, 0x00000085, 0xFFFFFCFE, 0xFFFFFF10, 0x0000001E, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000004B, 0x00000043, 0x00000007, MakeEntity, Entity_BlueSwitch, 0xFFFFFC40, 0xFFFFFF88, 0xFFFFFFDB, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignAreaFlag, 0x00000006, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
