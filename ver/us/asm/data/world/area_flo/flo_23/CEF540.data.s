.include "macro.inc"

.section .data

glabel D_802412E0_CEF540
.word 0x00000000, 0x00380028, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

glabel D_8024130C_CEF56C
.word 0x00000000

glabel D_80241310_CEF570
.word 0x00000000

glabel D_80241314_CEF574
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowConsumableChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, flo_23_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_802402C0_CEE520, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241448_CEF6A8
.word 0x00000043, 0x00000002, func_802402F8_CEE558, 0xFE363C80, 0x0000004E, 0x00000006, D_80241314_CEF574, 0x00000010, 0x00000000, jan_02_foliage_setup_shear_mtx, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_8024026C_CEE4CC, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241498_CEF6F8
.word 0x3FC00000, 0x0000001E, 0x00000032, 0x42700000, 0x41F00000, 0x00000003, 0x40C00000, 0x00000000, 0x00000000, 0x42C80000, 0x41F00000, 0x00000003

glabel D_802414C8_CEF728
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000012, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000004, 0x00000043, 0x00000002, func_80240728_CEE988, D_80241498_CEF6F8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241538_CEF798
.word 0x00000000, 0x00150016, 0x00000000, 0x00000000, D_802414C8_CEF728, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00130000

glabel D_80241564_CEF7C4
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x0000000A, 0x00000002, 0xF84060D5, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x0000015E, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AC480, 0xF24A5C80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60002, 0x00C60001, 0x00000000, 0x00110049, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010021, 0x00000043, 0x00000001, func_80240C9C_CEEEFC, 0x00000024, 0x00000002, 0xFE363C80, D_80242850_8D3D60, 0x00000024, 0x00000002, 0xFE363C81, 0x00000002, 0x00000046, 0x00000001, D_80241448_CEF6A8, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001A, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60002, 0x00C60001, 0x00000000, 0x0011004A, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C80, 0x00000043, 0x00000002, func_80240C2C_CEEE8C, 0xFE363C80, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C88, 0x00000181, 0x00000014, 0xFFFFFFDE, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C80, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00002095, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60003, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C87, 0x00000014, 0x00000001, 0xFE363C88, 0x00000016, 0x00000001, 0x0000009E, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60004, 0x00C60001, 0x00000000, 0x0011004D, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x0000021C, 0x00000000, 0x00000043, 0x00000005, EndSpeech, 0xFFFFFFFF, 0x00C60009, 0x00C60008, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60007, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000000D, 0x000001C9, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000000D, 0x7FFFFE00, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x0000001E, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C88, 0xFE363C80, 0x00000026, 0x00000002, 0xFE363C89, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C88, 0xF24A7C80, 0x0000002E, 0x00000002, 0xFE363C89, 0xF24A7F4D, 0x00000043, 0x00000006, RotateModel, 0x0000003B, 0xFE363C88, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000003C, 0xFE363C88, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000003D, 0xFE363C88, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000037, 0xFE363C89, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000038, 0xFE363C89, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000039, 0xFE363C89, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60005, 0x00000024, 0x00000002, 0xF84060D5, 0x00000001, 0x00000016, 0x00000001, 0x0000009F, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60004, 0x00C60001, 0x00000000, 0x0011004C, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60001, 0x00000016, 0x00000001, 0x000000A0, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60004, 0x00C60001, 0x00000000, 0x0011004C, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60001, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60004, 0x00C60001, 0x00000000, 0x0011004B, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60006, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFFFFFFFF, 0x00002096, 0x00000000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C88, 0x00000177, 0x00000014, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C87, 0xFE363C80, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, GetAngleToPlayer, 0xFFFFFFFF, 0xFE363C80, 0x0000000C, 0x00000002, 0xFE363C80, 0x000000B4, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000007, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A7880, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A79B4, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7E1A, 0x0000002E, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C84, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0xF2506A80, 0x0000002C, 0x00000002, 0xFE363C83, 0xF24AB680, 0x0000002C, 0x00000002, 0xFE363C84, 0xF24A0280, 0x00000043, 0x00000005, func_80240B68_CEEDC8, 0xFE363C87, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000007, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000026, 0x00000002, 0xFE363C82, 0xF24A7C80, 0x00000026, 0x00000002, 0xFE363C83, 0xF24A79B4, 0x00000026, 0x00000002, 0xFE363C84, 0xF24A7E80, 0x0000002E, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002E, 0x00000002, 0xFE363C84, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0xF2509280, 0x0000002C, 0x00000002, 0xFE363C83, 0xF24AB680, 0x0000002C, 0x00000002, 0xFE363C84, 0xF24A0280, 0x00000043, 0x00000005, func_80240B68_CEEDC8, 0xFE363C87, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60001, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C87, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60001, 0x00000043, 0x00000005, EndSpeech, 0xFFFFFFFF, 0x00C60002, 0x00C60001, 0x00000000, 0x00000023, 0x00000000, 0x00000023, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A9280, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000012, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000039, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60009, 0x00C60008, 0x00000000, 0x0011004E, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00C60009, 0x00C60008, 0x00000000, 0x0011004F, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241E70_CF00D0
.word 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241564_CEF7C4, 0x0000000A, 0x00000002, 0xF84060D5, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00C60005, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000000D, 0x7FFFFE00, 0x00000043, 0x00000006, RotateModel, 0x0000003B, 0x00000032, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000003C, 0x00000032, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000003D, 0x00000032, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000037, 0x00000078, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000038, 0x00000078, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000039, 0x00000078, 0x00000000, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80241F98_CF01F8
.word 0x00000002, D_802412E0_CEF540, 0x43C08000, 0x00000000, 0xC20C0000, 0x00402D09, D_80241E70_CF00D0, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00C60001, 0x00000000, 0x00000000, 0x00000000, 0x001A00DC

glabel D_80242188_CF03E8
.word 0x00000000, D_80241538_CEF798, 0x42A00000, 0x00000000, 0x00000000, 0x00002800, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000050, 0x00000000, 0x00000000, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000050, 0x00000000, 0x00000000, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004A0001, 0x004A0003, 0x004A0004, 0x004A0004, 0x004A0001, 0x004A0001, 0x004A0009, 0x004A0009, 0x004A0006, 0x004A0008, 0x004A0007, 0x004A0001, 0x004A0001, 0x004A0001, 0x004A0001, 0x004A0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80242378_CF05D8
.word 0x00000001, D_80241538_CEF798, 0xC3A00000, 0x00000000, 0x00000000, 0x00002800, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0xFFFFFEC0, 0x00000000, 0x00000000, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFEC0, 0x00000000, 0x00000000, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004A0001, 0x004A0003, 0x004A0004, 0x004A0004, 0x004A0001, 0x004A0001, 0x004A0009, 0x004A0009, 0x004A0006, 0x004A0008, 0x004A0007, 0x004A0001, 0x004A0001, 0x004A0001, 0x004A0001, 0x004A0001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242188_CF03E8, 0x180C0003, 0x00000001, D_80242378_CF05D8, 0x180D0003, 0x00000001, D_80241F98_CF01F8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
