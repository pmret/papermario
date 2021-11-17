.include "macro.inc"

.section .data

dlabel D_80241A50_996C40
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000004, isk_16_UnkFunc27, 0x00000000, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000004, isk_16_UnkFunc27, 0x00000002, 0x00000000, 0x00000001, 0x00000043, 0x0000000B, isk_16_UnkFunc26, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x000000FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x0000019A, 0xFFFFFC72, 0x0000019A, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000150, 0xFFFFFC72, 0x000001D3, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000004, SetPlayerPos, 0x00000117, 0xFFFFFC72, 0x00000208, 0x00000043, 0x00000002, GetCurrentPartnerID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000004, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFC7D, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFC72, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0x000000F3, 0xFE363C81, 0x00000217, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFC, 0x0000002D, 0x00000043, 0x00000002, ClearPartnerMoveHistory, 0xFFFFFFFC, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000040, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00000102, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFC, 0xF24A8480, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFC, 0x00000137, 0x000001E7, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00000106, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFC, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000002, SetPlayerSpeed, 0xF24A8A80, 0x00000043, 0x00000004, PlayerMoveTo, 0x00000157, 0x000001CC, 0x00000000, 0x00000046, 0x00000001, D_80241054_996244, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x0000019A, 0xFFFFFC72, 0x0000019A, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7C80, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000D00E2, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x0000019A, 0xFFFFFAEC, 0x0000019A, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000032, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002B, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000057, 0x00000000, 0x00000043, 0x00000007, func_802CFD30, 0x00000001, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0x0000019A, 0xFFFFFC77, 0x0000019A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00680010, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000000FF, 0x00000064, 0x00000001, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000007, func_802CFD30, 0x00000001, 0x00000007, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000043, 0x00000007, func_802CFD30, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000024, 0x00000002, 0xFE363C80, 0x000000FF, 0x00000005, 0x00000001, 0x0000003C, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFFC, 0x00000043, 0x0000000B, isk_16_UnkFunc26, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x0000000B, isk_16_UnkFunc26, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF252C280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7C80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000057, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000006E, 0x00000064, 0x0000000A, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x0000003C, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C85, 0xF24A7C62, 0x00000026, 0x00000002, 0xFE363C86, 0xF24A76BE, 0x0000002E, 0x00000002, 0xFE363C85, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C86, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C85, 0xFE363C82, 0x0000002C, 0x00000002, 0xFE363C86, 0xFE363C84, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C85, 0xFE363C83, 0xFE363C86, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x000001C9, 0xFFFFFCE0, 0x0000013C, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00680001, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000003B, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000003EF, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000007, 0x000000FF, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, func_802CFE2C, 0x00000000, 0x00000800, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000005, 0x0000000E, 0x00000002, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000027, 0x00000043, 0x00000003, func_802CFE2C, 0x00000000, 0x00000800, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000005, 0x0000000D, 0x00000002, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000027, 0x00000043, 0x00000003, func_802CFE2C, 0x00000000, 0x00000800, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000005, 0x0000000C, 0x00000002, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000037, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0x000001C9, 0xFFFFFAEC, 0x0000013C, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x000001B6, 0xFFFFFCE0, 0x0000014C, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24DFE80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24A5C80, 0xF24A5C80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8E80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x0068000B, 0x00680001, 0x00000000, 0x000D00E3, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000004, SetNpcVar, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242424_997614
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000002, 0x00002061, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000056, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000D00E8, 0x000000A0, 0x00000028, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00680006, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000020E3, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0x000001BA, 0xFFFFFC72, 0x00000189, 0x0000001E, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000003E2, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0x000001A0, 0xFFFFFC72, 0x000001A4, 0x00000014, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000003E2, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0x0000018B, 0xFFFFFC72, 0x000001B8, 0x0000000A, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00680001, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x0000019A, 0xFFFFFC72, 0x0000019A, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x000001EA, 0xFFFFFC72, 0x00000147, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24D9A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, EnableModel, 0x00000019, 0x00000000, 0x00000045, 0x00000002, D_80242424_997614, 0xFE363C8A, 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0x00000204, 0xFFFFFC72, 0x00000107, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000002, 0xF24A8680, 0x00000043, 0x00000005, NpcMoveTo, 0x00000002, 0x000001ED, 0x00000124, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000019, 0x00000001, 0x00000043, 0x00000004, NpcFaceNpc, 0x00000000, 0x00000002, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00680006, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000003E2, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00680001, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x0068000B, 0x00680001, 0x00000005, 0x000D00E9, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00690003, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000002, 0xF24A9A80, 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0x000001E6, 0xFFFFFC72, 0x00000154, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, NpcMoveTo, 0x00000002, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000005, NpcMoveTo, 0x00000002, 0x00000130, 0x000001B2, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000002, 0x000001BC, 0x0000013C, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000002, 0x000001D9, 0x00000151, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000002, 0x0000013E, 0x000001CC, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000002, 0x00000103, 0x0000020A, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0x00000000, 0xFFFFFA24, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000057, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000006, GetDist2D, 0xFE363C86, 0xFE363C80, 0xFE363C82, 0xFE363C83, 0xFE363C85, 0x0000000C, 0x00000002, 0xFE363C86, 0x00000032, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00680002, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080022, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0x00000130, 0x000001B2, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0x000001BC, 0x0000013C, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0x000001D9, 0x00000151, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0x0000013E, 0x000001CC, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002B, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0x00000103, 0x0000020A, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000000, 0xFFFFFA24, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000D00EA, 0x000000A0, 0x00000028, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000001, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000024, 0x00000002, 0xF8405F06, 0x00000001, 0x00000043, 0x00000003, FadeOutMusic, 0x00000000, 0x000001F4, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
