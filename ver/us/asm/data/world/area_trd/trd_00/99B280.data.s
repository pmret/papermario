.include "macro.inc"

.section .data

dlabel D_80241610_99B280
.word 0x00000000, 0x00220018, 0x00000000, 0x00000000, 0x00000000, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024163C_99B2AC
.word 0x00000000, 0x001A0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00140014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00160018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_802416C0_99B330
.word 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000001, 0x00000043, 0x00000004, AwaitPlayerApproach, 0xFFFFFDBC, 0x00000114, 0x00000032, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000006, 0x000001C3, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x0000000A, 0x0000000A, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000043, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000041, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x0000015E, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFDC6, 0x00000000, 0x000000AD, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00660003, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000040, 0x00000001, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8C80, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFFFFFDD4, 0x000000B4, 0x00000000, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000007, func_802CFD30, 0xFFFFFFFF, 0x00000005, 0x00000004, 0x00000002, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0066001E, 0x00000008, 0x00000001, 0x0000000C, 0x00000043, 0x00000007, func_802CFD30, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00660004, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00660014, 0x00660004, 0x00000000, 0x000C00D2, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00660002, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000002D, 0x00000002, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000173, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00660003, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7DB4, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000008, 0x00000001, 0x00000008, 0x00000008, 0x00000001, 0x0000000C, 0x00000056, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000174, 0x00000000, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A9A80, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFFFFFE10, 0x00000065, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000064, 0x00000000, 0x0000000A, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000043, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000041, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000006, 0x000001C4, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8880, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFA7, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C40_99B8B0
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802416C0_99B330, 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFFA7, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C8C_99B8FC
.word 0x00000005, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241D80_99B9F0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241DA4_99BA14
.word 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFFFFFDC9, 0x0000001A, 0x000000EC, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000001, 0x00000000, 0x00000043, 0x00000004, NpcFaceNpc, 0xFFFFFFFC, 0x00000001, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFDF1, 0x00000000, 0x000000D8, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFDF1, 0x00000000, 0x000000D8, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF251E680, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, WaitForPlayerInputEnabled, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00120002, 0x00120001, 0x00000200, 0x000C010D, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AC280, 0xF24A5680, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000168, 0x0000000A, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableNpcAI, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00120003, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, PlaySoundAtPlayer, 0x00000139, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001001F, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C81, 0x00000027, 0x00000002, 0xFE363C80, 0x00000005, 0x00000027, 0x00000002, 0xFE363C81, 0x00000032, 0x00000027, 0x00000002, 0xFE363C82, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C83, 0x0000001E, 0x00000005, 0x00000001, 0x00000006, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000006, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000001, 0xFE363C80, 0xFE363C83, 0xFE363C82, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000006, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000003, PlaySoundAtPlayer, 0x00000188, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000052, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000001, 0x0000001E, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00120001, 0x00000043, 0x00000003, EnableNpcAI, 0x00000001, 0x00000001, 0x00000043, 0x00000001, PostChapter1StatUpdate, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0191, 0x000000A0, 0x00000028, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00120002, 0x00120001, 0x00000200, 0x000C010E, 0x00000043, 0x00000002, ShowChoice, 0x001E0013, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000006, ContinueSpeech, 0x00000001, 0x00120002, 0x00120001, 0x00000200, 0x000C010F, 0x00000043, 0x00000002, ShowChoice, 0x001E0013, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000006, ContinueSpeech, 0x00000001, 0x00120002, 0x00120001, 0x00000200, 0x000C0110, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000001, 0x00120002, 0x00120001, 0x00000200, 0x000C0111, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000001, StartBattle, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000001, FullyRestoreSP, 0x00000043, 0x00000001, trd_00_SyncStatusMenu, 0x00000003, 0x00000001, 0x0000000A, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24E6280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00120002, 0x00120001, 0x00000200, 0x000C0112, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFDF1, 0x00000000, 0x000000D8, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F2A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AC280, 0xF24A5680, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000001, 0x00120002, 0x00120001, 0x00000200, 0x000C0113, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000001, 0x00040000, 0x00000001, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000019, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000011, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000004, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000708, 0x00000043, 0x00000005, MakeLerp, 0xFE363C82, 0xFE363C83, 0x00000064, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C85, 0x000000B4, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C85, 0x00000064, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C82, 0xFE363C80, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000001, 0x00002045, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000008, 0x00000001, 0x0000005A, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0x00000003, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFB5, 0x00000044, 0x00000001, 0x802406D0, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242830_99C4A0
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000005, 0x00000043, 0x00000002, GetLoadType, 0xFE363C81, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000012, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80241C8C_99B8FC, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80241D80_99B9F0, 0x00000044, 0x00000001, D_80241DA4_99BA14, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802428F4_99C564
.word 0x00000000, D_80241610_99B280, 0xC3EA8000, 0x00000000, 0x42CA0000, 0x00000801, D_80241C40_99B8B0, 0x00000000, 0x00000000, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00660304, 0x00660302, 0x00660303, 0x00660303, 0x00660304, 0x00660304, 0x0066030A, 0x0066030A, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00660303, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242AE4_99C754
.word 0x00000001, D_8024163C_99B2AC, 0x00000000, 0xC47A0000, 0x00000000, 0x00000805, D_80242830_99C4A0, 0x00000000, 0x00000000, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000064, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x000001F4, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120000, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00120001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802428F4_99C564, 0x00000000, 0x00000001, D_80242AE4_99C754, 0x08000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
