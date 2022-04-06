.include "macro.inc"

.section .data

dlabel D_80241560_DDDD90
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80242AD0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802415BC_DDDDEC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80242AD8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241618_DDDE48
.word 0x00000047, 0x00000005, D_80241560_DDDD90, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802415BC_DDDDEC, 0x00080000, 0x00000002, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000010, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x80242AAC, 0x00000046, 0x00000001, D_80242488_DDECB8, 0x00000046, 0x00000001, 0x80241530, 0x00000046, 0x00000001, D_80241BF8_DDE428, 0x00000024, 0x00000002, 0xFE363C80, D_80241618_DDDE48, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241740_DDDF70
.word 0x00000041, 0x00000044, 0x00000047, 0x0000004D, 0x00000050, 0x00000053, 0x00000056, 0x00000059

dlabel D_80241760_DDDF90
.word 0x00000041, 0x00000042, 0x00000044, 0x00000045, 0x00000047, 0x00000048

dlabel D_80241778_DDDFA8
.word 0x00000029, 0x0000002A, 0x0000002C, 0x0000002D, 0x0000002F, 0x00000030

dlabel D_80241790_DDDFC0
.word 0x0000004D, 0x00000035, 0x0000004E, 0x00000036

dlabel D_802417A0_DDDFD0
.word 0x00000050, 0x00000038, 0x00000051, 0x00000039

dlabel D_802417B0_DDDFE0
.word 0x00000053, 0x0000003B, 0x00000054, 0x0000003C

dlabel D_802417C0_DDDFF0
.word 0x00000056, 0x0000003E, 0x00000057, 0x0000003F

dlabel D_802417D0_DDE000
.word 0x00000059, 0x00000041, 0x0000005A, 0x00000042

dlabel D_802417E0_DDE010
.word 0x00000043, 0x00000003, RandInt, 0x00000014, 0xFE363C8A, 0x00000008, 0x00000001, 0xFE363C8A, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFAE, 0x0000003C, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xFE363C86, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0xFE363C88, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C87, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C89, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFAE, 0x00000000, 0x0000003C, 0x0000000A, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xFE363C86, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0xFE363C88, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C87, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C89, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419DC_DDE20C
.word 0x00000043, 0x00000003, RandInt, 0x00000014, 0xFE363C8A, 0x00000008, 0x00000001, 0xFE363C8A, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x00000085, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000046, 0x00000033, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xFE363C86, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0xFE363C88, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C87, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C89, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, PlaySound, 0x00000087, 0x00000043, 0x00000005, MakeLerp, 0x00000046, 0x00000000, 0x00000033, 0x0000000A, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xFE363C86, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0xFE363C88, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C87, 0x00000043, 0x00000002, UpdateColliderTransform, 0xFE363C89, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241BF8_DDE428
.word 0x0000004D, 0x00000001, 0x0000000B, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000027, 0x0000003F, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000032, 0x0000004A, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000029, 0x00000041, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002A, 0x00000042, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002C, 0x00000044, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002D, 0x00000045, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002F, 0x00000047, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000030, 0x00000048, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_802401A0_DDC9D0, 0x00000057, 0x00000000, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000035, 0x0000004D, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000036, 0x0000004E, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000038, 0x00000050, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000039, 0x00000051, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000003B, 0x00000053, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000003C, 0x00000054, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000003E, 0x00000056, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000003F, 0x00000057, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000041, 0x00000059, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000042, 0x0000005A, 0x00000024, 0x00000002, 0xFE363C80, D_80241790_DDDFC0, 0x00000044, 0x00000001, D_802417E0_DDE010, 0x00000024, 0x00000002, 0xFE363C80, D_802417A0_DDDFD0, 0x00000044, 0x00000001, D_802417E0_DDE010, 0x00000024, 0x00000002, 0xFE363C80, D_802417B0_DDDFE0, 0x00000044, 0x00000001, D_802417E0_DDE010, 0x00000024, 0x00000002, 0xFE363C80, D_802417C0_DDDFF0, 0x00000044, 0x00000001, D_802419DC_DDE20C, 0x00000024, 0x00000002, 0xFE363C80, D_802417D0_DDE000, 0x00000044, 0x00000001, D_802417E0_DDE010, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80240000_DDC830, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241E40_DDE670
.word 0x001D00F0, 0x001D00F1

dlabel D_80241E48_DDE678
.word 0x00010002, 0x00030004, 0x00090006, 0x00070008

dlabel D_80241E58_DDE688
.word 0x001D00E0, 0x001D00E1, 0x001D00E2, 0x001D00E3, 0x001D00E4, 0x001D00E5, 0x001D00E6, 0x001D00E7, 0x001D00E8, 0x001D00E9, 0x001D00EA, 0x001D00EB, 0x001D00EC, 0x001D00ED, 0x001D00EE, 0x001D00EF

dlabel omo_11_SuperBlockDataD
.word 0x430C0000, 0x43340000, 0x435C0000

dlabel D_80241EA4_DDE6D4
.word 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, PlaySound, 0x0000212D, 0x00000043, 0x00000002, omo_11_UnkFunc21, 0xFD050F80, 0x00000008, 0x00000001, 0x00000055, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x0000212E, 0x00000043, 0x00000003, omo_11_UnkFunc23, 0x00000046, 0x00000046, 0x00000008, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, PlaySound, 0x0000208E, 0x00000043, 0x00000003, omo_11_UnkFunc23, 0x00000032, 0x00000032, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, omo_11_TempSuperBlockAlpha, 0xFD050F80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002F, 0x00000043, 0x00000001, omo_11_UnkFunc22, 0x00000043, 0x00000001, omo_11_UnkPartnerPosFunc, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, omo_11_UnkPartnerPosFunc2, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, omo_11_UnkPartnerPosFunc, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, omo_11_UnkFunc60, 0xFD050F80, 0x00000008, 0x00000001, 0x0000001E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242008_DDE838
.word 0x0000000A, 0x00000002, 0xF840602A, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, omo_11_UnkFunc40, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000001, 0x00200000, 0x00000043, 0x00000001, omo_11_SetOverrideFlags_40, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x00000043, 0x00000003, omo_11_UnkFunc20, 0xFD050F80, 0xFE363C89, 0x00000043, 0x00000003, FindKeyItem, 0x0000000F, 0xFE363C8C, 0x00000043, 0x00000001, omo_11_UnkFunc38, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DC, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, omo_11_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, omo_11_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D36, 0x00000000, 0x00000024, 0x00000002, 0xF8405D36, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DA, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DB, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_8024095C_DDD18C, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000002, omo_11_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, omo_11_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C81, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000043, 0x00000002, omo_11_SwitchToPartner, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DF, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, ShowChoice, 0x001E000D, 0x00000043, 0x00000001, CloseMessage, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000002, omo_11_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, omo_11_UnkFunc17, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_80241EA4_DDE6D4, 0x00000043, 0x00000003, omo_11_UnkFunc18, 0xFE363C8B, 0xFE363C8D, 0x00000024, 0x00000002, 0xF840602A, 0x00000001, 0x00000043, 0x00000002, omo_11_UnkFunc39, 0xFE363C89, 0x00000043, 0x00000001, omo_11_UnkFunc19, 0x0000000A, 0x00000002, 0xFE363C8D, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DD, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00DE, 0x000000A0, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000003, ModifyGlobalOverrideFlags, 0x00000000, 0x00200000, 0x00000043, 0x00000001, omo_11_UnkFunc17, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242488_DDECB8
.word 0x00000043, 0x00000007, MakeEntity, 0x802EA910, 0xFFFFFF8D, 0x0000010E, 0xFFFFFF88, 0x00000000, 0x80000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000043, 0x00000002, AssignBlockFlag, 0xF840602A, 0x00000043, 0x00000002, AssignScript, D_80242008_DDE838, 0x00000043, 0x00000007, MakeEntity, 0x802EA0E8, 0x0000013B, 0x0000010E, 0xFFFFFF9C, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8406019, 0x00000043, 0x00000002, UseDynamicShadow, 0x00000001, 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0x000002AD, 0x0000003C, 0xFFFFFF9C, 0x00000000, 0x0000008B, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF840601D, 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0xFFFFFDA8, 0x0000003C, 0xFFFFFFCE, 0x00000000, 0x00000081, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF840601E, 0x00000043, 0x00000008, MakeEntity, 0x802EA564, 0xFFFFFF9C, 0x0000003C, 0xFFFFFFD3, 0x00000000, 0x00000157, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF840601C, 0x00000043, 0x00000008, MakeEntity, 0x802EA5D0, 0xFFFFFF6A, 0x0000003C, 0xFFFFFFD3, 0x00000000, 0x00000132, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF840601A, 0x00000043, 0x00000008, MakeEntity, 0x802EA564, 0xFFFFFF38, 0x0000003C, 0xFFFFFFD3, 0x00000000, 0x00000157, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF840601B, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
