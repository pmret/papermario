.include "macro.inc"

.section .data

dlabel D_802424B0_DB4770
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802452A0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024250C_DB47CC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802452A0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242568_DB4828
.word 0x00000047, 0x00000005, D_802424B0_DB4770, 0x00080000, 0x0000000B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024250C_DB47CC, 0x00080000, 0x0000000D, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000010, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, D_80245124_DB73E4, 0x00000046, 0x00000001, 0x80245150, 0x00000046, 0x00000001, D_80242E68_DB5128, 0x00000044, 0x00000001, 0x80242480, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000088, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFFFE, 0x00000043, 0x00000006, RotateModel, 0x0000002E, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000002F, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000030, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000032, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000033, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000034, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000000, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000001, 0x7FFFFE00, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80242568_DB4828, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802427C0_DB4A80
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFE98, 0x00000064, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000004E, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000050, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000052, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000054, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000056, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000058, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x0000005A, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x0000005C, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x0000005E, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000060, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000062, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000064, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateModel, 0x00000066, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802429EC_DB4CAC
.word 0x00000003, 0x00000001, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000000A0, 0x0000003C, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000011, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000013, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000015, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000017, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000019, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000001B, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000001D, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000001F, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000021, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000023, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000025, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000027, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000029, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000002B, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000000A0, 0x00000000, 0x0000003C, 0x0000000A, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000011, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000013, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000015, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000017, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000019, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000001B, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000001D, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000001F, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000021, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000023, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000025, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000027, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000029, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000002B, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242E68_DB5128
.word 0x00000044, 0x00000001, D_802427C0_DB4A80, 0x00000044, 0x00000001, D_802429EC_DB4CAC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242E90_DB5150
.word 0x40000000, 0x0000003C, 0x0000000F, 0x42C80000, 0x41F00000, 0x00000004, 0x40800000, 0x00000006, 0x00000001, 0x430C0000, 0x41F00000, 0x00000001

dlabel D_80242EC0_DB5180
.word 0x00000043, 0x00000002, omo_05_ShyGuyAI_Main, D_80242E90_DB5150, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_80242EC0_DB5180, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001

dlabel D_80242F0C_DB51CC
.word 0x3FD9999A, 0x00000050, 0x00000001, 0x42C80000, 0x00000000, 0x00000004, 0x40900000, 0x00000014, 0x00000001, 0x430C0000, 0x00000000, 0x00000001

dlabel D_80242F3C_DB51FC
.word 0x00000043, 0x00000002, omo_05_GrooveGuyAI_Main, D_80242F0C_DB51CC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242F5C_DB521C
.word 0x00000000, 0x00180016, 0x00000000, 0x00000000, D_80242F3C_DB51FC, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000F0001

dlabel omo_05_sixFloats
.float 4.5, 3.5, 2.6, 2.0, 1.5, 20.0

dlabel D_80242FA0_DB5260
.word 0x3FE66666, 0x00000000, 0x00000000, 0x42F00000, 0x41F00000, 0x00000003, 0x40800000, 0x0000003C, 0x00000003, 0x43160000, 0x41F00000, 0x00000001

dlabel D_80242FD0_DB5290
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0xFFFFFD76, 0x00000043, 0x00000003, SetSelfVar, 0x00000006, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000258, 0x00000043, 0x00000002, omo_05_FlyingAI_Main, D_80242FA0_DB5260, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00190016, 0x00000000, 0x00000000, D_80242FD0_DB5290, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000E0001

dlabel D_8024306C_DB532C
.word 0x00000000, 0x0044003C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80243098_DB5358
.word 0x00000000

dlabel D_8024309C_DB535C
.word 0x00000000

dlabel D_802430A0_DB5360
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowConsumableChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, omo_05_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_802421CC_DB448C, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802431D4_DB5494
.word 0x00000043, 0x00000002, func_80242204_DB44C4, 0xFE363C80, 0x0000004E, 0x00000006, D_802430A0_DB5360, 0x00000010, 0x00000000, D_80245650, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_80242178_DB4438, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243224_DB54E4
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0x00000000, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0x00000000, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x0000015E, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AC080, 0xF24A5280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000001, func_802423C8_DB4688, 0x00000043, 0x00000003, NpcFacePlayer, 0xFFFFFFFF, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C10001, 0x0000000A, 0x00000002, 0xF8405FCB, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C10004, 0x00C10001, 0x00000000, 0x000F0040, 0x00000024, 0x00000002, 0xF8405FCB, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C10004, 0x00C10001, 0x00000000, 0x000F0041, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, func_802457C0_A2FA00, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000046, 0x00000001, D_802431D4_DB5494, 0x0000000E, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C1000D, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C80, 0x00000043, 0x00000002, func_802422A0_DB4560, 0xFE363C80, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C88, 0xFFFFFF01, 0x00000023, 0x0000006E, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C80, 0x00000043, 0x00000004, SetItemFlags, 0xFE363C87, 0x00000040, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C10005, 0x00000005, 0x00000001, 0x00000006, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00002095, 0x00000000, 0x00000006, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C89, 0x00000002, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24AA280, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00002096, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C10006, 0x00000043, 0x00000004, SetItemFlags, 0xFE363C87, 0x00000040, 0x00000000, 0x00000043, 0x00000003, GetAngleToPlayer, 0xFFFFFFFF, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000007, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A7680, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A791A, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7A80, 0x0000002E, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C84, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0xF2464280, 0x0000002C, 0x00000002, 0xFE363C83, 0xF24B0680, 0x0000002C, 0x00000002, 0xFE363C84, 0xF24C3280, 0x00000043, 0x00000005, SetItemPos, 0xFE363C87, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000007, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A7680, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A7BE7, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7A80, 0x0000002E, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C84, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0xF244EE80, 0x0000002C, 0x00000002, 0xFE363C83, 0xF24A7A80, 0x0000002C, 0x00000002, 0xFE363C84, 0xF24C3280, 0x00000043, 0x00000005, SetItemPos, 0xFE363C87, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000007, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A7E80, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A791A, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7A80, 0x0000002E, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C84, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0xF246BA80, 0x0000002C, 0x00000002, 0xFE363C83, 0xF24B0680, 0x0000002C, 0x00000002, 0xFE363C84, 0xF24C3280, 0x00000043, 0x00000005, SetItemPos, 0xFE363C87, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000007, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A7E80, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A7BE7, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7A80, 0x0000002E, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C84, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0xF2480E80, 0x0000002C, 0x00000002, 0xFE363C83, 0xF24A7A80, 0x0000002C, 0x00000002, 0xFE363C84, 0xF24C3280, 0x00000043, 0x00000005, SetItemPos, 0xFE363C87, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C87, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C10001, 0x00000014, 0x00000001, 0xFE363C89, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C10004, 0x00C10001, 0x00000000, 0x000F0042, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C1000D, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C10004, 0x00C10001, 0x00000000, 0x000F0043, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C1000D, 0x00000016, 0x00000001, 0x00000002, 0x00000056, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000F0044, 0x000000A0, 0x00000028, 0x00000057, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C10007, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000002, 0x00000002, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000002, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000002, 0xF24A7AB4, 0x00000043, 0x00000006, NpcJump0, 0x00000002, 0xFE363C80, 0x00000002, 0xFE363C82, 0x00000008, 0x00000043, 0x00000003, func_802CDE68, 0x00000002, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000027, 0x00000002, 0xFE363C83, 0x00000032, 0x00000043, 0x00000005, SetNpcRotation, 0x00000002, 0x00000000, 0x00000000, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000027, 0x00000002, 0xFE363C82, 0x00000014, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000002, 0xF24A7B4D, 0x00000043, 0x00000006, NpcJump0, 0x00000002, 0xFE363C80, 0xFFFFFFF6, 0xFE363C82, 0x00000008, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, RemoveNpc, 0x00000002, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000001, 0x00000002, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000001, 0xF24A7AB4, 0x00000043, 0x00000006, NpcJump0, 0x00000001, 0xFE363C80, 0x00000002, 0xFE363C82, 0x00000008, 0x00000043, 0x00000003, func_802CDE68, 0x00000001, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000028, 0x00000002, 0xFE363C83, 0x00000032, 0x00000043, 0x00000005, SetNpcRotation, 0x00000001, 0x00000000, 0x00000000, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000027, 0x00000002, 0xFE363C82, 0x00000014, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000001, 0xF24A7B4D, 0x00000043, 0x00000006, NpcJump0, 0x00000001, 0xFE363C80, 0xFFFFFFF6, 0xFE363C82, 0x00000008, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, RemoveNpc, 0x00000001, 0x00000057, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFF06, 0x00000019, 0xFFFFFF9C, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFF06, 0x00000019, 0xFFFFFF9C, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF2510A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AAA80, 0xF24A7480, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24ADE80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000381, 0x00000000, 0x00000008, 0x00000001, 0x00000021, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F7A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AAE80, 0xF24A774D, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24ADE80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000382, 0x00000000, 0x00000008, 0x00000001, 0x00000021, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24E6280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AB280, 0xF24A7A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24ADE80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000383, 0x00000000, 0x00000008, 0x00000001, 0x00000012, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000072, 0x00000000, 0x00000008, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000008, Spawn802D9D50, 0x00000000, 0x00000000, 0x00000000, 0x00000140, 0x000000F0, 0x00000080, 0x0000000A, 0x00000005, 0x00000001, 0x00000007, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24F7A80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AB280, 0xF24A7A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24AB680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24E6280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AB280, 0xF24A7A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24AB680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000006, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000002E, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000002F, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000030, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000032, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000033, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000034, 0x00000069, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000001, func_80242328_DB45E8, 0x00000043, 0x00000001, func_80242328_DB45E8, 0x00000043, 0x00000001, func_80242328_DB45E8, 0x00000043, 0x00000008, Spawn802D9D50, 0x00000000, 0x00000000, 0x00000000, 0x00000140, 0x000000F0, 0x00000000, 0x0000000A, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFF06, 0x00000000, 0x00000064, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFF06, 0x00000000, 0x00000064, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000056, 0x00000000, 0x00000003, 0x00000001, 0x00000013, 0x00000043, 0x00000003, PlayerFaceNpc, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000013, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000384, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C10003, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000100, 0x00000001, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24ACA80, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0x00000000, 0x0000006E, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000384, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000080, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0x00000091, 0x0000006E, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFFFFFE0C, 0x0000006E, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000080, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000384, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0xFFFFFFFF, 0x00000000, 0x00000000, 0xFFFFFFD3, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFF, 0x0000005A, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x0000001E, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A8A4D, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A72E7, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7A80, 0x0000002E, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C84, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0xF2438680, 0x0000002C, 0x00000002, 0xFE363C83, 0xF24C8280, 0x0000002C, 0x00000002, 0xFE363C84, 0xF24E1280, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000384, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0xFFFFFE0C, 0x00000000, 0x0000006E, 0x00000043, 0x00000005, NpcMoveTo, 0xFFFFFFFF, 0xFFFFFF06, 0x0000006E, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C10008, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24A7080, 0xF24A1A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8080, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00000385, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C1000B, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7A82, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFFFFFF06, 0x000001F4, 0x0000006E, 0x00000028, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000002, 0x00000057, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x000F0045, 0x000000A0, 0x00000028, 0x00000003, 0x00000001, 0x0000000C, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000002, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x0000000C, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000007, MakeItemEntity, 0x00000029, 0xFE363C80, 0x00000190, 0xFE363C82, 0x0000000D, 0xF8405FD2, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010021, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24BE280, 0x00000008, 0x00000001, 0x0000003C, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000000, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000001, 0x7FFFFE00, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFFE, 0x00000023, 0x00000000, 0x00000044, 0x00000001, 0x80242480, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFFFE, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024484C_DB6B0C
.word 0x0000000F, 0x00000002, 0xF5DE0180, 0xFFFFFFFE, 0x00000043, 0x00000002, RemoveNpc, 0x00000002, 0x00000043, 0x00000002, RemoveNpc, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C1000D, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000002, 0x00C1000A, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000002, 0x00000002, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0xFFFFFEE3, 0x00000032, 0x0000005A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00C10009, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000001, 0x00000002, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFFFFFF2E, 0x00000032, 0x0000005A, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80243224_DB54E4, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80244964_DB6C24
.word 0x00000000, D_8024306C_DB532C, 0xC37A0000, 0x41200000, 0x42AA0000, 0x00400901, D_8024484C_DB6B0C, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00000000, 0x00000000, 0x00000000, 0x001A00B7, 0x00000001, D_8024306C_DB532C, 0xC37A0000, 0x41200000, 0x42AA0000, 0x00000B01, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00000000, 0x00000000, 0x00000000, 0x001A00B7, 0x00000002, D_8024306C_DB532C, 0xC37A0000, 0x41200000, 0x42AA0000, 0x00000B01, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00C10001, 0x00000000, 0x00000000, 0x00000000, 0x001A00B7

dlabel D_80244F34_DB71F4
.word 0x00000003, D_80242F5C_DB521C, 0x43A00000, 0x41200000, 0xC3110000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050080, 0x00020000, 0x00820002, 0x00000084, 0x00020000, 0x00860002, 0x00000085, 0x00020000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000140, 0x0000000A, 0xFFFFFF6F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000140, 0x0000000A, 0xFFFFFF6F, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x003C0001, 0x003C0003, 0x003C0004, 0x003C0003, 0x003C0001, 0x003C0001, 0x003C0008, 0x003C0008, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x003C0001, 0x00000001, 0x00000000, 0x00000000, 0x00000000

dlabel D_80245124_DB73E4
.word 0x00000003, D_80244964_DB6C24, 0x00000000, 0x00000001, D_80244F34_DB71F4, 0x102A0007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
