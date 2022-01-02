.include "macro.inc"

.section .data

dlabel D_802416C0_91CFA0
.word 0x3F800000, 0x0000001E, 0x0000001E, 0x42F00000, 0x00000000, 0x00000003, 0x40E00000, 0x0000003C, 0x00000005, 0x42C80000, 0x42700000, 0x00000001

dlabel D_802416F0_91CFD0
.word 0x00000043, 0x00000003, func_80240D10_91C5F0, D_802416C0_91CFA0, 0x00000010, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241714_91CFF4
.word 0x00000000, 0x001A0018, 0x00000000, 0x00000000, D_802416F0_91CFD0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000

dlabel D_80241740_91D020
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x000020EF, 0x00000000, 0x00000008, 0x00000001, 0x00000010, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241788_91D068
.word 0x00000005, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetNpcAnimation, 0xFFFFFFFF, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00670002, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000045, 0x00000002, D_80241740_91D020, 0xFE363C8A, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetNpcAnimation, 0xFFFFFFFF, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00670002, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241870_91D150
.word 0x0000000A, 0x00000002, 0xF8405E44, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000012, 0x00000000, 0x00000044, 0x00000001, D_80241788_91D068, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x0000000A, 0x00000060, 0xFFFFFEA5, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802418EC_91D1CC
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x0000000C, 0x00000002, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000001, 0x0000010E, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000001, 0x0000005A, 0x00000000, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xFE363C80, 0x00000190, 0x0000000C, 0x00000002, 0xFE363C80, 0x000001C2, 0x0000000C, 0x00000002, 0xFE363C82, 0x00000064, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x0000005B, 0x00000000, 0x00000008, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, GetCurrentPartner, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000001, func_802D2B6C, 0x00000008, 0x00000001, 0x00000005, 0x00000013, 0x00000000, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000D0030, 0x000000A0, 0x00000028, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000F, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, GetAngleToPlayer, 0xFFFFFFFF, 0xFE363C8A, 0x00000008, 0x00000001, 0x00000004, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x000001AE, 0x00000000, 0xFFFFFFE7, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x0000001E, 0x000000B4, 0xFFFFFDA8, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24C0A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00670005, 0x00670005, 0x00000005, 0x000D0031, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00670002, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C85, 0x00000096, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C85, 0x0000000F, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000005, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000004, SetPlayerPos, 0x000001AE, 0x00000000, 0xFFFFFFE7, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x0000021A, 0x000000C8, 0xFFFFFFE7, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, SetCamPosB, 0x00000000, 0x00000064, 0xFFFFFF9C, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x00000258, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000056, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x00000028, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x000001F4, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0xF24A7C80, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000057, 0x00000000, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000028, 0x00000002, 0xFE363C85, 0x00000096, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C85, 0x0000000F, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000005, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00670001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00670007, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00670008, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00670009, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x0067000A, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00670001, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0x00000000, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x00000113, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00670003, 0x00670001, 0x00000000, 0x000D0032, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24BE280, 0x00000032, 0x0000015E, 0xF24AB680, 0xF24A4A80, 0x00000043, 0x00000002, ShowChoice, 0x001E0017, 0x00000043, 0x00000005, EndSpeech, 0xFFFFFFFF, 0x00670003, 0x00670001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8B, 0x000D0033, 0x00000024, 0x00000002, 0xFE363C8C, 0x00670004, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C8B, 0x000D0034, 0x00000024, 0x00000002, 0xFE363C8C, 0x00670003, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C8B, 0x000D0035, 0x00000024, 0x00000002, 0xFE363C8C, 0x00670004, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0x00000000, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x00000113, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0xFE363C8C, 0x00670001, 0x00000000, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000001, 0x00000044, 0x00000001, 0x80241140, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00670006, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00670002, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C85, 0x00000096, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C85, 0x0000000F, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000005, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x0000000A, 0x00000060, 0xFFFFFEA5, 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00670005, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, StartBossBattle, 0x00000003, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024257C_91DE5C
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF8405E44, 0x00000001, 0x00000044, 0x00000001, 0x80241140, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000212, 0x0000000F, 0xFFFFFFEC, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0067000B, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24BE280, 0x00000032, 0x0000015E, 0xF24AB680, 0xF24A4A80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x000D0036, 0x00000056, 0x00000000, 0x00000043, 0x00000003, GetNpcYaw, 0xFFFFFFFF, 0xFE363C80, 0x00000005, 0x00000001, 0x00000037, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000005, SetNpcRotation, 0xFFFFFFFF, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7D80, 0x00000043, 0x00000006, NpcJump1, 0xFFFFFFFF, 0x00000190, 0xFFFFFF38, 0xFFFFFED4, 0x0000003C, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8480, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242744_91E024
.word 0x00670005, 0x00200020, D_80241870_91D150, 0x00000000, D_802418EC_91D1CC, 0x00000000, 0x00000000, D_8024257C_91DE5C, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242770_91E050
.word 0x00000000, D_80241714_91CFF4, 0xC3CE0000, 0xC37A0000, 0x430F0000, 0x00000900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0xFFFFFE64, 0xFFFFFF06, 0x0000008F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFE9D, 0xFFFFFF06, 0x00000069, 0x000000AF, 0x000000C3, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00300002, 0x00300006, 0x00300007, 0x00300007, 0x00300002, 0x00300002, 0x00300008, 0x00300008, 0x00300014, 0x00300017, 0x00300013, 0x00300015, 0x00300010, 0x00300011, 0x00300016, 0x00300000, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242960_91E240
.word 0x00000001, D_80242744_91E024, 0x00000000, 0xC47A0000, 0x00000000, 0x00A40D04, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x0067000B, 0x0067000B, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x00670001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242770_91E050, 0x09010002, 0x00000001, D_80242960_91E240, 0x090C0003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
