.include "macro.inc"

.section .data

dlabel D_802409E0_9468B0
.word 0xC3ED8000, 0x00000000, 0x00000000, 0x42B40000, 0x43ED8000, 0x00000000, 0x00000000, 0x43870000, 0x00000000, 0x00000000, 0xC3ED8000, 0x43340000, 0x00000000, 0x00000000, 0x43ED8000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80240C50_946B20, D_802409E0_9468B0, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x0019007B

dlabel D_80240A60_946930
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802427C0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240ABC_94698C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802427C8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B18_9469E8
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802427D0, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B74_946A44
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000003, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802427D8, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240BD0_946AA0
.word 0x00000047, 0x00000005, D_80240A60_946930, 0x00080000, 0x00000009, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240ABC_94698C, 0x00080000, 0x00000005, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240B18_9469E8, 0x00080000, 0x00000003, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240B74_946A44, 0x00080000, 0x00000007, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C50_946B20
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x0000000A, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFFC1, 0x00000043, 0x00000002, DisablePulseStone, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, D_80241D90_947C60, 0x00000043, 0x00000001, sbk_34_SpawnSunEffect, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000017, 0x00000000, 0x00000008, 0x00000024, 0x00000002, 0xFE363C80, D_80240BD0_946AA0, 0x00000044, 0x00000001, EnterWalk, 0x00000044, 0x00000001, 0x80242768, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D70_946C40
.word 0x00000000, 0x00160019, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240D9C_946C6C
.word 0x00000000

dlabel D_80240DA0_946C70
.word 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240E00_946CD0
.word 0x00000000

dlabel D_80240E04_946CD4
.word 0x00000000

dlabel D_80240E08_946CD8
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, sbk_34_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_802403D8_9462A8, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_80240410_9462E0, 0xFE363C80, 0x0000004E, 0x00000006, D_80240E08_946CD8, 0x00000010, 0x00000000, D_802427E0_A517E0, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_80240384_946254, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F9C_946E6C
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, sbk_34_UnkYawFunc, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, SetItemPos, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024101C_946EEC
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, sbk_34_UnkYawFunc, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000045, 0x00000002, D_80240F9C_946E6C, 0xFE363C8A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040002, 0x00000043, 0x00000004, GetAngleBetweenNPCs, 0xFE363C89, 0xFFFFFFFC, 0xFE363C8B, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C89, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000001, 0x0000000E, 0x00000002, 0xFE363C8B, 0x000000B4, 0x00000027, 0x00000002, 0xFE363C86, 0x00000014, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C86, 0xFFFFFFEC, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C87, 0x0000000A, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000014, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000027, 0x00000002, 0xFE363C8A, 0x000000B4, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0xFE363C8A, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00040001, 0x00000043, 0x00000004, NpcFaceNpc, 0xFFFFFFFC, 0xFE363C89, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000100, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000008, 0x00000001, 0x00000005, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_802403D8_9462A8, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241340_947210
.word 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8B, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, func_80240410_9462E0, 0xFE363C80, 0x0000004E, 0x00000006, D_8024101C_946EEC, 0x00000010, 0x00000000, D_802427E0_A517E0, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_80240384_946254, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802413B0_947280
.word 0x00000024, 0x00000002, 0xFE363C8C, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0xFFFFFFBA, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_80240728_9465F8, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x00000043, 0x00000003, FindKeyItem, 0xFE363C85, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000004, 0x0000000B, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFE363C82, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C82, 0xFE363C8D, 0xFE363C80, 0xFE363C8E, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C8E, 0xFE363C8F, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0xF24A7A80, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000A, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFC, 0xFE363C8D, 0xFE363C80, 0xFE363C8F, 0x0000000A, 0x00000043, 0x00000007, SpeakToNpc, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000000, 0xFE363C82, 0xFE363C87, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000046, 0x00000001, D_80241340_947210, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C88, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000001, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000005, 0xFE363C89, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000000, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x0000000B, 0x00000002, 0xFE363C86, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C86, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000046, 0x00000001, D_80240DA0_946C70, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C86, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000023, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_8024076C_94663C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802416A8_947578
.word 0x0000003D, 0x00000000

dlabel D_802416B0_947580
.word 0x00000043, 0x0000000B, sbk_34_SetManyVars, 0x00000000, 0x00B90002, 0x00B90001, 0x0000003D, 0x00000000, 0x000D005B, 0x000D005C, 0x000D005D, 0x000D005E, D_802416A8_947578, 0x00000046, 0x00000001, D_802413B0_947280, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241700_9475D0
.word 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x0000015C, 0x00000024, 0x00000002, 0xFE363C81, 0x00000003, 0x00000046, 0x00000001, D_80240DA0_946C70, 0x00000043, 0x00000002, AddStarPieces, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241764_947634
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFBC, 0x0000000A, 0x00000002, 0xF8405E8F, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8A80, 0x00000000, 0xF24E6280, 0xF24AB680, 0xF24A6280, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B90002, 0x00B90001, 0x00000000, 0x000D0056, 0x00000024, 0x00000002, 0xF8405E8F, 0x00000001, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0x00000004, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B90002, 0x00B90001, 0x00000000, 0x000D0057, 0x00000013, 0x00000000, 0x00000018, 0x00000001, 0xFFFFFFC2, 0x0000000A, 0x00000002, 0xF8405E8F, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8A80, 0x00000000, 0xF24E6280, 0xF24AB680, 0xF24A6280, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B90002, 0x00B90001, 0x00000000, 0x000D0058, 0x00000024, 0x00000002, 0xF8405E8F, 0x00000001, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0x00000004, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B90002, 0x00B90001, 0x00000000, 0x000D0059, 0x00000013, 0x00000000, 0x0000001B, 0x00000001, 0xFFFFFFC2, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00B90002, 0x00B90001, 0x00000000, 0x000D005A, 0x00000023, 0x00000000, 0x00000046, 0x00000001, D_802416B0_947580, 0x00000046, 0x00000001, D_80241700_9475D0, 0x0000000B, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241954_947824
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241764_947634, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B90001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024198C_94785C
.word 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00B90004, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419B0_947880
.word 0x00000000, D_80240D70_946C40, 0x42E40000, 0x00000000, 0xC2480000, 0x00402D01, D_80241954_947824, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00000000, 0x00000000, 0x00000000, 0x001A008E, 0x00000001, D_80240D70_946C40, 0x43060000, 0x00000000, 0xC2480000, 0x00402D01, D_8024198C_94785C, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00B90001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241D90_947C60
.word 0x00000002, D_802419B0_947880, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
