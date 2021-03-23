.include "macro.inc"

.section .data

glabel D_80242830_A0E520
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D016E, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D016D, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802EAFDC, 0x000001C2, 0x0000000A, 0xFFFFFF47, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80242830_A0E520, 0x00000043, 0x00000007, MakeEntity, D_802EAFDC, 0x00000357, 0xFFFFFFF6, 0xFFFFFFD8, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignScript, 0x80242878, 0x00000043, 0x00000008, MakeEntity, 0x802EAB04, 0x0000017C, 0xFFFFFFF6, 0x00000019, 0x00000000, 0x00000010, D_80000000, 0x00000043, 0x00000002, AssignPanelFlag, 0xF8405D9A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80242970_A0E660
.word 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x40000000, 0x42920000, 0xC0C00000, 0x40000000, 0x42D40000, 0x42000000, 0x40000000, 0x428C0000, 0x422C0000, 0x40000000, 0x41F00000, 0x41400000, 0x40000000, 0xC1880000, 0xC1980000, 0x40000000, 0xC20C0000, 0x41E80000, 0x40000000, 0xC1A00000, 0x422C0000, 0x40000000, 0xC1300000, 0x421C0000, 0x40000000, 0x00000000, 0xBF800000, 0x00000000, 0x41700000, 0x432E0000, 0xC2340000, 0xC31D0000, 0x42B80000, 0xC2300000, 0xC3B98000, 0x42CE0000, 0xC2340000, 0xC3AF0000, 0x42960000, 0xC2340000, 0xC37A0000, 0x42200000, 0xC2340000, 0x00000000, 0x00000000, 0x00000000, 0xC2700000, 0x40400000, 0xC1300000, 0xC25C0000, 0x41500000, 0x00000000, 0x40800000, 0x42200000, 0xC0A00000, 0x41B80000, 0x420C0000, 0xC1200000, 0x427C0000, 0x41C80000, 0xC1A00000, 0x42BC0000, 0x41F00000, 0xC2200000, 0x43060000, 0x437A0000, 0xC2A00000, 0xC2900000, 0x439F0000, 0xC2A00000, 0xC2FE0000, 0x43190000, 0xC2700000, 0xC32E0000, 0x42E40000, 0xC2300000, 0xC3730000, 0x42B40000, 0xC2340000, 0xC3860000, 0x42480000, 0xC2380000, 0xC32E0000, 0x41200000, 0xC22C0000, 0x00000000, 0x00000000, 0x00000000, 0xC1F00000, 0x40400000, 0xC1300000, 0xC25C0000, 0x41500000, 0x00000000, 0xC2920000, 0x41A00000, 0xC0A00000, 0xC2CE0000, 0x42200000, 0x00000000, 0xC30F0000, 0x42700000, 0x00000000, 0xC32D0000, 0x42480000, 0x41D00000, 0xC2FC0000, 0x420C0000, 0x41800000, 0x448AE000, 0x440E8000, 0xC403C000

glabel D_80242B9C_A0E88C
.word 0x00000000

glabel D_80242BA0_A0E890
.word 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C85, 0x00000028, 0x00000002, 0xFE363C83, 0xFE363C86, 0x00000028, 0x00000002, 0xFE363C84, 0xFE363C87, 0x00000028, 0x00000002, 0xFE363C85, 0xFE363C88, 0x00000043, 0x00000001, func_80240A54_A0C744, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C8A, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C8B, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetAngleBetweenNPCs, 0x00000000, 0x00000001, 0xFE363C80, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000004, GetAngleBetweenNPCs, 0xFFFFFFFC, 0x00000001, 0xFE363C80, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000005A, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000003, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000005, 0x00000001, 0x00000005, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000003, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C82, 0x00000002, 0x00000043, 0x00000005, SetItemPos, 0xFD050F8A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C80, 0xFFFFFF9C, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000056, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFEC, 0x00000043, 0x00000004, PlayerMoveTo, 0xFE363C80, 0xFE363C82, 0x0000000A, 0x00000057, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000032, 0x000000B4, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFF6, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0x00000014, 0xFE363C82, 0x0000000F, 0x00000043, 0x00000003, PlaySoundAtPlayer, 0x000000E1, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010023, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0020000E, 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200016, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7CE7, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFF9C, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0x0000000A, 0xFE363C82, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A8280, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000168, 0x00000005, 0x00000001, 0x00000003, 0x00000003, 0x00000001, 0x00000016, 0x00000008, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C83, 0x0000002D, 0x0000000D, 0x00000002, 0xFE363C83, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0xFE363C83, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C83, 0x0000010E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0020001A, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C83, 0x0000005A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200016, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000016, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000A000D, 0x000000A0, 0x00000028, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000070, 0x00000000, 0x00000008, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200001, 0x00000043, 0x00000003, NpcFacePlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x0020000C, 0x00200001, 0x00000000, 0x000A000E, 0x00000043, 0x00000001, func_80240B20_A0C810, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFEC, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x00000113, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABA80, 0xF24A5880, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000028, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000043, 0x0000000A, ShowEmote, 0x00000000, 0x00000001, 0x0000002D, 0x00000014, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0020000F, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7E80, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000006, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFC, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000019, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFC, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A000F, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000043, 0x00000005, LoadPath, 0x00000046, 0x802429D4, 0x0000000A, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, GetNextPathPos, 0x0000002C, 0x00000002, 0xFE363C81, 0xFE363C84, 0x0000002C, 0x00000002, 0xFE363C82, 0xFE363C85, 0x0000002C, 0x00000002, 0xFE363C83, 0xFE363C86, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000001, func_80240994_A0C684, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0010, 0x00000043, 0x00000003, SetNpcYaw, 0x00000000, 0x0000010E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0020001A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000005, 0x000A0011, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000F, 0x00000043, 0x00000007, MakeItemEntity, 0x00000007, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFD050F8A, 0xFE363C80, 0x00000045, 0x00000002, 0x80242D8C, 0xFE363C88, 0x00000045, 0x00000002, 0x80242E98, 0xFE363C89, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200017, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000200, 0x000A0012, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C83, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C85, 0xFFFFFFE2, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFE363C85, 0xFE363C84, 0x0000000F, 0x00000049, 0x00000001, 0xFE363C89, 0x00000049, 0x00000001, 0xFE363C88, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C81, 0x00000027, 0x00000002, 0xFE363C84, 0x0000001E, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000043, 0x00000005, MakeLerp, 0xFE363C81, 0xFE363C84, 0x00000007, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetItemPos, 0xFD050F8A, 0xFE363C83, 0xFE363C80, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C83, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000027, 0x00000002, 0xFE363C86, 0x00000026, 0x00000043, 0x00000005, MakeLerp, 0xFE363C80, 0xFE363C86, 0x00000007, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetItemPos, 0xFD050F8A, 0xFE363C83, 0xFE363C80, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C83, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, RemoveItemEntity, 0xFD050F8A, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200014, 0x00000008, 0x00000001, 0x0000000B, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200015, 0x00000024, 0x00000002, 0xFE363C80, 0x00000007, 0x00000024, 0x00000002, 0xFE363C81, 0x00000004, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C80, 0x00000043, 0x00000001, func_80240908_A0C5F8, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200001, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0013, 0x00000043, 0x00000002, ShowChoice, 0x001E0013, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0014, 0x00000043, 0x00000002, ShowChoice, 0x001E0013, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0015, 0x00000012, 0x00000000, 0x00000004, 0x00000001, 0x0000000F, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000003, 0x00000001, 0x0000000F, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0016, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00010008, 0x00010001, 0x00000000, 0x000A0017, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0018, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080007, 0x00000043, 0x00000004, SetNpcVar, 0x00000000, 0x00000000, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetNpcVar, 0x00000000, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00000106, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A002F, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00010008, 0x00010001, 0x00000000, 0x000A0030, 0x00000008, 0x00000001, 0x00000014, 0x00000044, 0x00000001, 0x80241084, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000A0031, 0x00000140, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFF06, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFF06, 0x00000035, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A801A, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000045, 0x00000002, 0x80242BA4, 0xFE363C8A, 0x00000043, 0x00000005, LoadPath, 0x00000043, 0x80242A4C, 0x00000005, 0x00000000, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000058, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000002, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000002, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000006, 0x00000000, 0x00000059, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00570000, 0x00000005, 0x00000001, 0x00000003, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0x00000000, 0x0000000A, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000045, 0x00000002, 0x80242D20, 0xFE363C8A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200000, 0x00000005, 0x000A0032, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0x00000000, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24E8A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AAE80, 0xF24A5A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00570009, 0x00570000, 0x00000200, 0x000A0033, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFF06, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000004, SetNpcVar, 0x00000001, 0x00000000, 0x00000001, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_802D5830, 0x00000001, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000070, 0x00000000, 0x00000008, 0x00000008, 0x00000001, 0x0000003C, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C83, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C83, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24EC680, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABA80, 0xF24A5680, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000005A, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0034, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7C80, 0x00000043, 0x00000005, PlayerJump, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0035, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF2556A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7FB4, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000043, 0x00000005, LoadPath, 0x00000055, 0x80242A88, 0x00000008, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x0000002C, 0x00000002, 0xFE363C81, 0xFE363C84, 0x0000002C, 0x00000002, 0xFE363C82, 0xFE363C85, 0x0000002C, 0x00000002, 0xFE363C83, 0xFE363C86, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000001, func_80240994_A0C684, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000002D, 0x00000056, 0x00000000, 0x00000043, 0x00000005, LoadPath, 0x0000003C, 0x80242AE8, 0x00000006, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000001, func_80240994_A0C684, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C83, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C83, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24EC680, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABA80, 0xF24A5880, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00200009, 0x00200001, 0x00000000, 0x000A0036, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x00000043, 0x00000005, LoadPath, 0x00000078, 0x80242B30, 0x00000009, 0x00000001, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, GetNextPathPos, 0x0000002C, 0x00000002, 0xFE363C81, 0xFE363C84, 0x0000002C, 0x00000002, 0xFE363C82, 0xFE363C85, 0x0000002C, 0x00000002, 0xFE363C83, 0xFE363C86, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000001, func_80240994_A0C684, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AAC80, 0xF24A5280, 0x00000043, 0x00000001, func_80240B3C_A0C82C, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000004, SetCamPosB, 0x00000000, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7C80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000000, 0x00040000, 0x00000001, 0x00000026, 0x00000002, 0xFE363C80, 0xF24A7A80, 0x00000005, 0x00000001, 0x0000000A, 0x0000002C, 0x00000002, 0xFE363C80, 0xF24B0A80, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000000, 0x00040000, 0x00000000, 0x00000008, 0x00000001, 0x00000078, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0x0000010E, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFFFFFFFC, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24EC680, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AAE80, 0xF24A5C80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00010008, 0x00010001, 0x00000000, 0x000A0037, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010029, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFF98, 0x00000043, 0x00000002, func_802D5830, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8A80, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
