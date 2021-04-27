.include "macro.inc"

.section .data

glabel D_80246240_9247B0
.word 0x00000000, 0x00230018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630010

glabel D_8024626C_9247DC
.word 0x00000000

glabel D_80246270_9247E0
.word 0x00000000

glabel D_80246274_9247E4
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, func_802D6420, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, iwa_10_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80241434_91F9A4, 0xFE363C8A, 0x00000043, 0x00000001, func_802D6954, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802463B8_924928
.word 0x00000043, 0x00000002, func_8024146C_91F9DC, 0xFE363C80, 0x0000004E, 0x00000006, D_80246274_9247E4, 0x00000010, 0x00000000, D_80248480, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_802413E0_91F950, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C81, 0x000000D7, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xFE363C80, 0xFFFFFDA8, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000D000E, 0x00000140, 0x00000096, 0x00000056, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000043, 0x00000003, PlaySoundAtPlayer, 0x00000263, 0x00000000, 0x00000043, 0x0000000A, ShowEmote, 0x00000000, 0x00000002, 0x00000000, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8680, 0x0000001E, 0x0000012C, 0xF24AB680, 0xF24A5480, 0x00000056, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080022, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x00000037, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFFFFFE70, 0x000000D7, 0xFFFFFE02, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000004, 0x00000040, 0x00000001, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000004, 0x00000000, 0x00000000, 0x0000000F, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000004, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, SetNpcRotation, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000004, 0x0000005A, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000005, SetNpcRotation, 0x00000004, 0x00000000, 0x00000000, 0xFFFFFFF1, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000004, 0x0000010E, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFD050F8A, 0xFFFFFE02, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFE02, 0xFE363C82, 0x0000003C, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000024, 0x00000002, 0xFD050F8A, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000019, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFE70, 0xFE363C80, 0x00000037, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0xFE363C80, 0x000000DC, 0xFD050F8A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010017, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00040004, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A8280, 0x00000057, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000027, 0x00000002, 0xFE363C80, 0xFE363C83, 0x0000002A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000027, 0x00000002, 0xFE363C82, 0xFE363C85, 0x0000002A, 0x00000002, 0xFE363C82, 0x00000002, 0x00000043, 0x00000006, PlaySoundAt, 0x000000E1, 0x00000000, 0xFE363C80, 0x000000E6, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000018, 0x00000003, 0xFE363C80, 0x000000E6, 0xFE363C82, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C8B, 0x000000E6, 0x00000024, 0x00000002, 0xFE363C8C, 0xFE363C82, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000D, 0x00000002, 0xFE363C82, 0xFFFFFE84, 0x00000024, 0x00000002, 0xFE363C82, 0xFFFFFE84, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000004, 0xF24A7E80, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000006, NpcJump1, 0x00000004, 0xFE363C80, 0x000000D7, 0xFE363C82, 0x0000000F, 0x00000027, 0x00000002, 0xFE363C80, 0x0000000F, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00040005, 0x00000043, 0x00000006, NpcJump1, 0x00000004, 0xFE363C80, 0x000000D7, 0xFE363C82, 0x00000008, 0x00000057, 0x00000000, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7E80, 0x00000028, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000005, PlayerJump1, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000F, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, PlaySoundAt, 0x00000162, 0x00000000, 0xFE363C8A, 0xFE363C8B, 0xFE363C8C, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000028, 0x00000002, 0xFE363C80, 0x0000000F, 0x00000043, 0x00000003, SetPlayerFlagBits, 0x00200000, 0x00000001, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001000F, 0x00000043, 0x00000005, PlayerJump1, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000003, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, NpcFaceNpc, 0xFFFFFFFC, 0x00000004, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010030, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00040001, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000006, NpcJump1, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000043, 0x00000003, SetPlayerFlagBits, 0x00200000, 0x00000000, 0x00000043, 0x00000003, InterpPlayerYaw, 0x0000005A, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8680, 0x00000023, 0x000000FF, 0xF24AC080, 0xF24A4C80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00040002, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000003C, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000004, 0xF24A8680, 0x00000043, 0x00000005, NpcMoveTo, 0x00000004, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000004, 0x00040001, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D000F, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, NpcJump0, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0010, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080007, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0011, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFB9, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8680, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000003, BindNpcAI, 0x00000004, D_802474F8_925A68, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80246E80_9253F0
.word 0x00000036, 0x00000054, 0x00000040, 0x00000000

glabel D_80246E90_925400
.word 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000A, 0x00000002, 0xF5DE01FA, 0x00000002, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E41, 0x00000001, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E42, 0x00000001, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405E43, 0x00000001, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000003, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000005, GetNpcPos, 0x00000004, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0x0000000C, 0x00000002, 0xFE363C81, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C84, 0xFFFFFFE2, 0x00000012, 0x00000000, 0x00000027, 0x00000002, 0xFE363C84, 0x0000001E, 0x00000013, 0x00000000, 0x00000043, 0x00000004, PlayerMoveTo, 0xFE363C84, 0xFE363C86, 0x00000014, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000004, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, func_802CF56C, 0x00000002, 0x00000043, 0x00000007, AdjustCam, 0x00000000, 0xF24A8A80, 0xF24A7A80, 0xF24F2A80, 0xF24AC080, 0xF24A5280, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80246E80_9253F0, 0x00000024, 0x00000002, 0xFE363C81, 0x00000004, 0x00000046, 0x00000001, D_802463B8_924928, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000014, 0x00000001, 0xF5DE01FA, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0012, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0015, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0017, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D001C, 0x00000043, 0x00000002, ShowChoice, 0x001E000F, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D001B, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8A80, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000023, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0013, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C80, 0x00000027, 0x00000002, 0xF5DE01FA, 0x00000001, 0x00000014, 0x00000001, 0xF5DE01FA, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0014, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0016, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040007, 0x00040001, 0x00000000, 0x000D0018, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010028, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D0019, 0x00000043, 0x00000002, ShowChoice, 0x001E000F, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D001A, 0x00000043, 0x00000002, ShowChoice, 0x001E000F, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D001B, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8A80, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000023, 0x00000000, 0x00000023, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000004, 0x00040006, 0x00040001, 0x00000000, 0x000D001D, 0x00000043, 0x00000003, iwa_10_UnkFunc41, 0x00000004, 0x00000004, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFBA, 0x00000043, 0x00000001, func_80241510_91FA80, 0x00000044, 0x00000001, 0x8024187C, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D018C, 0x000000A0, 0x00000028, 0x00000044, 0x00000001, 0x802418B0, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x00040006, 0x00040001, 0x00000000, 0x000D001E, 0x00000043, 0x00000002, AddKeyItem, 0x00000036, 0x00000043, 0x00000002, AddKeyItem, 0x00000054, 0x00000043, 0x00000002, AddKeyItem, 0x00000040, 0x00000013, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802474F8_925A68
.word 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A7E80, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFD62, 0x00000027, 0x00000002, 0xFE363C82, 0xFFFFFE1B, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00040002, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00040001, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000007, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000007, 0x00000008, 0x00000001, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C80, 0x00000078, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00040002, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFE363C80, 0xFE363C82, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00040001, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000010E, 0x00000007, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000007, 0x00000008, 0x00000001, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFF88, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80247688_925BF8
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80246E90_925400, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0xFFFFFFB9, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000018, 0x00000001, 0xFFFFFFBA, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_802474F8_925A68, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000004, D_80246240_9247B0, 0xC4188000, 0x43660000, 0xC3F28000, 0x00200D09, D_80247688_925BF8, 0x00000000, 0x00000000, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00040001, 0x00040002, 0x00040003, 0x00040003, 0x00040001, 0x00040001, 0x00040000, 0x00040000, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00040001, 0x00000000, 0x00000000, 0x00000000, 0x001A0084

glabel D_80247910_925E80
.word 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C8F, 0xFE363C87, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, iwa_10_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0x00000001, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000153, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, iwa_10_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0xFFFFFFFF, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000033, 0x00000003, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000033, 0x00000003, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8A, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000046, 0x00000001, 0xFE363C84, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000004C, 0x00000001, 0xF24A8280, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C86, 0xFE363C8F, 0xFE363C88, 0x00000043, 0x00000002, PlaySound, 0x00000165, 0x00000043, 0x00000002, PlaySound, 0x00000166, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, iwa_10_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000166, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, iwa_10_SomeMatrixOperation2, 0xFE363C83, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, iwa_10_SomeMatrixOperation2, 0xFE363C84, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C84, 0x00000165, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, iwa_10_SomeMatrixOperation2, 0xFE363C84, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000005, TranslateModel, 0xFE363C84, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000000, 0x00000030, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000005, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000033, 0x00000003, 0xFE363C89, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8B, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8B, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000030, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000005, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x0000000F, PlayEffect, 0x00000014, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C85, 0x00000000, 0x00000046, 0x00000001, 0xFE363C85, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80248274_9267E4
.word 0x00000001, 0x00000010

glabel D_8024827C_9267EC
.word 0x00000001, 0x00000157, 0xFFFFFCB9, 0x0000000F, 0x00000209, 0x00000006, 0xF8405E45, 0xFAA2B58A

glabel D_8024829C_92680C
.word 0x00000001, 0xFFFFFCB9, 0x0000000F, 0x00000209

glabel D_802482AC_92681C
.word D_80248274_9267E4, D_8024827C_9267EC, D_8024829C_92680C, 0x00000000

glabel D_802482BC_92682C
.word 0x00000001, 0x00000011

glabel D_802482C4_926834
.word 0x00000001, 0x00000157, 0xFFFFFD4D, 0x00000016, 0x00000180, 0x00000006, 0xF8405E46, 0xFAA2B58B

glabel D_802482E4_926854
.word 0x00000001, 0xFFFFFD4D, 0x00000016, 0x00000180

glabel D_802482F4_926864
.word D_802482BC_92682C, D_802482C4_926834, D_802482E4_926854, 0x00000000

glabel D_80248304_926874
.word 0x00000001, 0x00000012

glabel D_8024830C_92687C
.word 0x00000001, 0x00000157, 0xFFFFFC5C, 0x00000015, 0x00000195, 0x00000006, 0xF8405E47, 0xFAA2B58C

glabel D_8024832C_92689C
.word 0x00000001, 0xFFFFFC5C, 0x00000015, 0x00000195

glabel D_8024833C_9268AC
.word D_80248304_926874, D_8024830C_92687C, D_8024832C_92689C, 0x00000000

glabel D_8024834C_9268BC
.word 0x00000001, 0x00000013

glabel D_80248354_9268C4
.word 0x00000001, 0x000000AB, 0xFFFFFCE0, 0x00000017, 0x00000118, 0x00000006, 0x00000000, 0xFAA2B58D

glabel D_80248374_9268E4
.word 0x00000001, 0xFFFFFCE0, 0x00000017, 0x00000118

glabel D_80248384_9268F4
.word D_8024834C_9268BC, D_80248354_9268C4, D_80248374_9268E4, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802482AC_92681C, 0x00000047, 0x00000005, D_80247910_925E80, 0x00000100, 0x0000005F, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802482F4_926864, 0x00000047, 0x00000005, D_80247910_925E80, 0x00000100, 0x00000060, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_8024833C_9268AC, 0x00000047, 0x00000005, D_80247910_925E80, 0x00000100, 0x00000061, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80248384_9268F4, 0x00000047, 0x00000005, D_80247910_925E80, 0x00000100, 0x00000062, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
