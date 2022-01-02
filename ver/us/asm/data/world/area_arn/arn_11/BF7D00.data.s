.include "macro.inc"

.section .data

dlabel D_80240680_BF7D00
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00180018, D_80240680_BF7D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80240690, 0x00000000, 0x00000000, 0x000D0000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetCamType, 0x00000000, 0x00000006, 0x00000001, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000032, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x00000BB8, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000043, 0x00000002, StartBossBattle, 0x0000000B, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000002, 0x000001C1, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000050, 0x0000000A, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000000, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000050, 0x00000000, 0x0000000A, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000000, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000002, 0x000001C2, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000064, 0x0000001E, 0x00000046, 0x00000019, 0x0000001E, 0x00000050, 0xFFFFD8F0, 0x00000000, 0x00000000, 0xFFFFFFBA, 0x0000000A, 0x00000014, 0xFFFFFF4C, 0x00000000, 0x00000000, 0xFFFFFED4, 0x00000000, 0x00000000, 0xFFFFD8F0, 0x00000000, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetCamType, 0x00000000, 0x00000006, 0x00000001, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000032, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x000001C2, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000000, 0x00000001, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A8480, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x000020C8, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, SetCamType, 0x00000000, 0x00000004, 0x00000001, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABE80, 0xF24A5E80, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x000001C2, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0xFFFFFFC8, 0x00000046, 0x00000043, 0x00000004, SetCamPosB, 0x00000000, 0xFFFFFFA6, 0x00000028, 0x00000043, 0x00000004, SetCamPosC, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000057, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000000, 0x00000001, 0x00000030, 0x00000001, 0x80240988, 0x00000005, 0x00000001, 0x00000000, 0x00000033, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFD8F0, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x000020C8, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000044, 0x00000001, 0x8024081C, 0x00000005, 0x00000001, 0x00000000, 0x00000033, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFD8F0, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x000020C8, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000044, 0x00000001, 0x802408D8, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000004, SetCamType, 0x00000000, 0x00000006, 0x00000001, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x000001C2, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFEA, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFFEA, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, 0x802406CC, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, 0x802409DC, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x802406A0, 0x42EE0000, 0x42700000, 0x00000000, 0x00040B05, 0x80240E70, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x006C0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x80240EEC, 0x0E0F0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
