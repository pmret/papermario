.include "macro.inc"

.section .data

dlabel D_802413F0_D87DF0
.word 0x00000000, 0x00320037, 0x00000000, 0x00000000, 0x00000000, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024141C_D87E1C
.word 0x00000000, 0x001A0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00140014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00160018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_802414A0_D87EA0
.word 0x00000024, 0x00000002, 0xFD050F80, 0x00000190, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000190, 0x0000012C, 0x000000C8, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000000C8, 0x00000064, 0x000000C8, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x0000024C, 0xFE363C80, 0x00000074, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C80, 0x00000027, 0x00000002, 0xFE363C85, 0xFFFFFFE2, 0x0000000F, 0x00000002, 0xFE363C85, 0x00000064, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x0000024C, 0xFE363C85, 0x00000074, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xFD050F80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241660_D88060
.word 0x00000043, 0x00000003, EnableNpcShadow, 0x00000000, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000179, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000001, func_802D2B6C, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000059, 0x00000000, 0x00000008, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x0012016A, 0x000000A0, 0x00000028, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x0000024C, 0x000000C8, 0x00000074, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFE2, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AAA80, 0xF24A5280, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF250BA80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010006, 0x00000043, 0x00000004, SetPlayerPos, 0x000001DB, 0x00000064, 0x00000074, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000002, PartnerIsFlying, 0xFE363C84, 0x0000000A, 0x00000002, 0xFE363C84, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0x000001C4, 0x00000074, 0x00000078, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFC, 0x000001C4, 0x00000064, 0x00000078, 0x00000013, 0x00000000, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000043, 0x0000000F, PlayEffect, 0x00000072, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000032, 0x00000032, 0x00000001, 0x00000028, 0x00000032, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000072, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000032, 0x00000032, 0x00000001, 0x00000028, 0x00000032, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000072, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000032, 0x00000032, 0x00000001, 0x00000028, 0x00000032, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000072, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000032, 0x00000032, 0x00000001, 0x00000014, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000072, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000032, 0x00000032, 0x00000001, 0x00000014, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000072, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000032, 0x00000032, 0x00000001, 0x00000014, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000030, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000030, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000000FF, 0x00000078, 0x00000000, 0x00000003, 0x00000001, 0x00000005, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000007, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000043, 0x00000003, EnableNpcShadow, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x0000001E, 0x00000046, 0x00000001, D_802414A0_D87EA0, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C83, 0xFE363C84, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C83, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x007F0009, 0x007F0009, 0x00000000, 0x0012016B, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010005, 0x00000043, 0x00000002, SetPlayerSpeed, 0xF24A8480, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000B, 0x00000000, 0x00000043, 0x00000004, PlayerMoveTo, 0x00000234, 0x00000074, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000002, StartBossBattle, 0x0000000F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241E44_D88844
.word 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000003, FadeOutMusic, 0x00000000, 0x000001F4, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetEncounterStatusFlags, 0x00000001, 0x00000001, 0x00000043, 0x00000004, SetPlayerPos, 0x000001DB, 0x00000064, 0x00000074, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AAA80, 0xF24A5280, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x007F0009, 0x007F0009, 0x00000000, 0x0012016C, 0x00000056, 0x00000000, 0x00000043, 0x00000003, func_802CDE68, 0x00000000, 0x0000001E, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00001AB8, 0x000000D2, 0x0000000A, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000064, 0x000000C8, 0x000000D2, 0x0000000A, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C8A, 0xF24A7A8B, 0x00000043, 0x00000005, SetNpcScale, 0x00000000, 0xFE363C8A, 0xFE363C8A, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000000FF, 0x0000007A, 0x0000001E, 0x0000000A, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000007, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x0000036B, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000038, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000001, 0x00000082, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, MakeLerp, 0x00000078, 0x00000000, 0x0000001E, 0x0000000A, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000007, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000007, func_802CFD30, 0x00000000, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000008, 0x00000001, 0x0000004B, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000B, 0x00000008, 0x00000008, 0x00000001, 0x00000019, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000044, 0x00000001, 0x80240900, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000056, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802423F4_D88DF4
.word 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80241E44_D88844, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x00000056, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241660_D88060, 0x00000016, 0x00000001, 0x00000056, 0x00000044, 0x00000001, 0x80240D3C, 0x00000019, 0x00000001, 0x00000056, 0x00000023, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x10000102, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000000, 0x00000043, 0x00000003, SetNpcYaw, 0x00000000, 0x0000010E, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802424B4_D88EB4
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802424C4_D88EC4
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802424D4_D88ED4
.word 0x00000000, D_802413F0_D87DF0, 0x00000000, 0xC47A0000, 0x00000000, 0x00640D08, D_802424B4_D88EB4, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802413F0_D87DF0, 0x00000000, 0xC47A0000, 0x00000000, 0x00640D08, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_8024141C_D87E1C, 0x00000000, 0xC47A0000, 0x00000000, 0x00640D09, D_802424C4_D88EC4, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180000, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00180001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_802413F0_D87DF0, 0x00000000, 0xC47A0000, 0x00000000, 0x00644D0C, D_802423F4_D88DF4, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x007F0009, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, D_802424D4_D88ED4, 0x20000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
