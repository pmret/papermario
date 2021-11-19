.include "macro.inc"

.section .data

dlabel D_80240A40_AB2BB0
.word 0x00000000, 0x002E0024, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240A6C_AB2BDC
.word 0x00000000, 0x00140014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240A98_AB2C08
.word 0x00000000, 0x001A0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00140014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00160018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240B1C_AB2C8C
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B2C_AB2C9C
.word 0x00000000, 0x00180018, D_80240B1C_AB2C8C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240B58_AB2CC8
.word 0xC1200000, 0x42200000, 0x41200000, 0x41700000, 0x42040000, 0x41A00000, 0x42480000, 0x41F00000, 0x41F00000

dlabel D_80240B7C_AB2CEC
.word 0x42480000, 0x41F00000, 0x41F00000, 0x428C0000, 0x42340000, 0x41200000, 0x42B40000, 0x42700000, 0x41F00000, 0x428C0000, 0x42960000, 0x42480000, 0x42480000, 0x42B40000, 0x41F00000, 0x428C0000, 0x42D20000, 0x41200000, 0x42B40000, 0x42F00000, 0x41F00000, 0x428C0000, 0x43070000, 0x42480000, 0x42480000, 0x43160000, 0x41F00000, 0x428C0000, 0x43250000, 0x41200000, 0x42B40000, 0x43340000, 0x41F00000, 0x428C0000, 0x43430000, 0x42480000, 0x42480000, 0x43520000, 0x41F00000

dlabel D_80240C18_AB2D88
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFE363C84, 0x00040000, 0x00000001, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C84, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000006, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C84, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000008, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000708, 0x00000064, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0xFE363C84, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C84, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000043, 0x00000005, MakeLerp, 0x00000050, 0x00000104, 0x00000064, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C84, 0xFE363C87, 0xFE363C80, 0xFE363C89, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFE363C84, 0xFE363C87, 0xFFFFFC18, 0xFE363C89, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240EC0_AB3030
.word 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000006, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000008, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000870, 0x00000078, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000001, 0x00000062, 0x00000000, 0x00000043, 0x00000005, LoadPath, 0x00000078, D_80240B7C_AB2CEC, 0x0000000D, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C81, 0xFFFFFC18, 0xFE363C83, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A7C80, 0x00000000, 0x00000226, 0xF24ABE80, 0xF24A5280, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000078, 0x00000002, 0x00000008, 0x00000043, 0x00000004, SetPlayerPos, 0x0000000F, 0x00000000, 0x0000001E, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFC, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0xFFFFFFBA, 0xFE363C81, 0x0000000F, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFC, 0x0000005A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFC, 0x00000106, 0x00000043, 0x00000005, GetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A5E80, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF2556A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24FF280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000043, 0x00000005, SetNpcPos, 0x00000009, 0x0000001E, 0x00000019, 0x0000001E, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00120003, 0x00000043, 0x00000005, GetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C81, 0x00000050, 0x00000024, 0x00000002, 0xFE363C82, 0x00000023, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000009, 0xF24A7C80, 0x00000043, 0x00000006, NpcJump1, 0x00000009, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, PlaySound, 0x00000139, 0x00000005, 0x00000001, 0x00000006, 0x00000043, 0x0000000F, PlayEffect, 0x00000033, 0x00000009, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000001, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000001E, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x00000014, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000005, SetNpcPos, 0x00000009, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000009, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00120001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000002, 0x00120002, 0x00120001, 0x00000000, 0x00010000, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000002, 0xF24A7A80, 0x00000043, 0x00000006, NpcJump0, 0x00000002, 0x00000078, 0x00000050, 0x00000000, 0x00000028, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000002, 0x0000010E, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C80, 0x00000078, 0x00000024, 0x00000002, 0xFE363C81, 0x00000050, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000005, GetNpcPos, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000003, 0x00130002, 0x00130001, 0x00000000, 0x00010001, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00140002, 0x00140001, 0x00000000, 0x00010002, 0x00000043, 0x00000005, GetNpcPos, 0x00000005, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000005, 0x00150002, 0x00150001, 0x00000000, 0x00010003, 0x00000043, 0x00000005, GetNpcPos, 0x00000006, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000006, 0x00160002, 0x00160001, 0x00000000, 0x00010004, 0x00000043, 0x00000005, GetNpcPos, 0x00000007, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000007, 0x00170003, 0x00170001, 0x00000000, 0x00010005, 0x00000043, 0x00000005, GetNpcPos, 0x00000008, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000008, 0x00180002, 0x00180001, 0x00000000, 0x00010006, 0x00000043, 0x00000005, GetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000002, 0x00120002, 0x00120001, 0x00000000, 0x00010007, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A7280, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00200009, 0x00200001, 0x00000005, 0x00010008, 0x00000043, 0x00000005, GetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6280, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24EC680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000002, 0x00120002, 0x00120001, 0x00000000, 0x00010009, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24BE280, 0x00000046, 0x00000190, 0xF24ABE80, 0xF24A4E80, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0x00000002, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C84, 0x00002045, 0x00000000, 0x00000046, 0x00000001, D_80240C18_AB2D88, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000024, 0x00000002, 0xFE363C84, 0x00000006, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C84, 0x00002046, 0x00000000, 0x00000046, 0x00000001, D_80240C18_AB2D88, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000024, 0x00000002, 0xFE363C84, 0x00000004, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C84, 0x00002045, 0x00000000, 0x00000046, 0x00000001, D_80240C18_AB2D88, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000005A, 0x00000024, 0x00000002, 0xFE363C84, 0x00000003, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C84, 0x00002046, 0x00000000, 0x00000046, 0x00000001, D_80240C18_AB2D88, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000078, 0x00000024, 0x00000002, 0xFE363C84, 0x00000008, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C84, 0x00002045, 0x00000000, 0x00000046, 0x00000001, D_80240C18_AB2D88, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000096, 0x00000024, 0x00000002, 0xFE363C84, 0x00000005, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C84, 0x00002046, 0x00000000, 0x00000046, 0x00000001, D_80240C18_AB2D88, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x000000B4, 0x00000024, 0x00000002, 0xFE363C84, 0x00000007, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C84, 0x00002045, 0x00000000, 0x00000046, 0x00000001, D_80240C18_AB2D88, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000070, 0x00000001, 0x00000008, 0x00000043, 0x00000005, LoadPath, 0x0000001E, D_80240B58_AB2CC8, 0x00000003, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000001, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A6A80, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00200009, 0x00200001, 0x00000000, 0x0001000A, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x000C0000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x000C0026, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x000C0001, 0x000C0026, 0x00000005, 0x0001000B, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x000C0002, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x000A0001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00200016, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00200016, 0x00200016, 0x00000000, 0x0001000C, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00200001, 0x00000043, 0x00000005, EndSpeech, 0x00000001, 0x00200009, 0x00200001, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000044, 0x00000001, D_80240EC0_AB3030, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000008, 0x00000001, 0x000000FA, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x000A0002, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFFFFFFF6, 0x0000001E, 0x00000028, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x000A0001, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, GotoMap, 0x80244110, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802424B8_AB4628
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFFFFFFE7, 0x00000000, 0x00000028, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802424FC_AB466C
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFFFFFFF6, 0x00000028, 0x0000000A, 0x00000043, 0x00000003, SetNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024253C_AB46AC
.short 0x0001, 0x0003, 0x0005, 0x0007, 0x0007, 0x0005, 0x0003, 0x0000

dlabel D_8024254C_AB46BC
.word 0x00000043, 0x00000001, func_80240060_AB21D0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242568_AB46D8
.word 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0x0000003C, 0x00000014, 0x0000001E, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024254C_AB46BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802425BC_AB472C
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000042, 0x00000050, 0xFFFFFFE5, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024254C_AB46BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242610_AB4780
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000035, 0x00000050, 0xFFFFFFA1, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024254C_AB46BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242664_AB47D4
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x0000005B, 0x00000050, 0xFFFFFF7C, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024254C_AB46BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802426B8_AB4828
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000097, 0x00000050, 0xFFFFFF7C, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024254C_AB46BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024270C_AB487C
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x000000BD, 0x00000050, 0xFFFFFFA1, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024254C_AB46BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242760_AB48D0
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x000000B0, 0x00000050, 0xFFFFFFE5, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024254C_AB46BC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802427B4_AB4924
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802427C4_AB4934
.word 0x000A0001, 0x000A0002, 0x000C0000, 0x000C0001, 0x000C0002, 0x000C0006, 0x000C001E, 0x000C0026, 0xFFFFFFFF

dlabel D_802427E8_AB4958
.word 0x00200001, 0x00200009, 0x00200016, 0xFFFFFFFF

dlabel D_802427F8_AB4968
.word 0x00120001, 0x00120002, 0x00120003, 0xFFFFFFFF

dlabel D_80242808_AB4978
.word 0x00130001, 0x00130002, 0xFFFFFFFF

dlabel D_80242814_AB4984
.word 0x00140001, 0x00140002, 0xFFFFFFFF

dlabel D_80242820_AB4990
.word 0x00150001, 0x00150002, 0xFFFFFFFF

dlabel D_8024282C_AB499C
.word 0x00160001, 0x00160002, 0xFFFFFFFF

dlabel D_80242838_AB49A8
.word 0x00170001, 0x00170003, 0xFFFFFFFF

dlabel D_80242844_AB49B4
.word 0x00180001, 0x00180002, 0xFFFFFFFF

dlabel D_80242850_AB49C0
.word 0x00000000, D_80240A40_AB2BB0, 0x00000000, 0xC47A0000, 0x00000000, 0x00020F05, D_802424B8_AB4628, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x000A0000, 0x00000000, 0x00000000, D_802427C4_AB4934, 0x00000000, 0x00000001, D_80240A6C_AB2BDC, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_802424FC_AB466C, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00200001, 0x00200005, 0x00200008, 0x00200008, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00000000, 0x00000000, D_802427E8_AB4958, 0x00000000, 0x00000002, D_80240A98_AB2C08, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_80242568_AB46D8, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120000, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00000000, 0x00000000, D_802427F8_AB4968, 0x00000000, 0x00000003, D_80240A98_AB2C08, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_802425BC_AB472C, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130000, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00130001, 0x00000000, 0x00000000, D_80242808_AB4978, 0x00000000, 0x00000004, D_80240A98_AB2C08, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_80242610_AB4780, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140000, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00140001, 0x00000000, 0x00000000, D_80242814_AB4984, 0x00000000, 0x00000005, D_80240A98_AB2C08, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_80242664_AB47D4, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150000, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00150001, 0x00000000, 0x00000000, D_80242820_AB4990, 0x00000000, 0x00000006, D_80240A98_AB2C08, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_802426B8_AB4828, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160000, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00160001, 0x00000000, 0x00000000, D_8024282C_AB499C, 0x00000000, 0x00000007, D_80240A98_AB2C08, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_8024270C_AB487C, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170000, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00170001, 0x00000000, 0x00000000, D_80242838_AB49A8, 0x00000000, 0x00000008, D_80240A98_AB2C08, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_80242760_AB48D0, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180000, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00000000, 0x00000000, D_80242844_AB49B4, 0x00000000, 0x00000009, D_80240B2C_AB2C9C, 0x00000000, 0xC47A0000, 0x00000000, 0x00000F05, D_802427B4_AB4924, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00D30000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, D_80242850_AB49C0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
