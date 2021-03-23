.include "macro.inc"

.section .data

glabel D_80243580_DA0A50
.word 0x00000054, 0x00000056, 0x00000058, 0x0000005A, 0x0000005F, 0x00000061, 0x00000063, 0x00000065, 0x00000068, 0x0000006C, 0x0000006E, 0x00000070

glabel D_802435B0_DA0A80
.word 0x0000002C, 0x0000002E, 0x00000030, 0x00000032, 0x00000037, 0x00000039, 0x0000003B, 0x0000003D, 0x00000040, 0x00000044, 0x00000046, 0x00000048, 0xC4020000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x00000074, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_8024043C_D9D90C, 0x00000005, 0x00000001, 0x0000000A, 0x00000030, 0x00000001, D_80243580_DA0A50, 0x00000005, 0x00000001, 0x0000000C, 0x00000031, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000030, 0x00000001, D_80243580_DA0A50, 0x00000005, 0x00000001, 0x0000000C, 0x00000031, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000006, 0x00000000, 0x00000030, 0x00000001, D_802435B0_DA0A80, 0x00000005, 0x00000001, 0x0000000C, 0x00000031, 0x00000001, 0xFE363C80, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0xFE363C80, 0x7FFFFE00, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000049, 0x00000001, 0xFD050F8A, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFE84, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFE84, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFF6, 0x00000014, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000052, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000002A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFF6, 0x00000007, 0x00000028, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000052, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000002A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000007, 0xFFFFFFA6, 0x0000001E, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000052, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000002A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtModel, 0x00000052, 0x000001F4, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0x00000052, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFF6, 0x00000014, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000005D, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000035, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFF6, 0x00000007, 0x00000028, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000005D, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000035, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000007, 0xFFFFFFA6, 0x0000001E, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000005D, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000035, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtModel, 0x0000005D, 0x000001F4, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0x0000005D, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000005, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFE363C80, 0xF24A8080, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFE363C80, 0xFE363C81, 0x00000000, 0xFE363C83, 0x00000014, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFF6, 0x00000014, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000042, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFF6, 0x00000007, 0x00000028, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000042, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000007, 0xFFFFFFA6, 0x0000001E, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFE363C80, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000042, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtModel, 0x0000006A, 0x000001F4, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0x0000006A, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000004, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000023, 0x00000043, 0x00000002, PlaySound, 0x8000004D, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C85, 0x00000001, 0x00000005, 0x00000001, 0x0000000A, 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFE363C80, 0xF24A8080, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000003, RandInt, 0x0000000A, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C84, 0x0000000A, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFE363C80, 0xFE363C81, 0x00000000, 0xFE363C83, 0xFE363C84, 0x00000013, 0x00000000, 0x00000043, 0x00000004, SetNpcVar, 0xFE363C80, 0x00000000, 0x0000000B, 0x00000008, 0x00000001, 0xFE363C85, 0x00000043, 0x00000004, SetNpcVar, 0xFE363C80, 0x00000000, 0x00000014, 0x00000057, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000027, 0x00000002, 0xFE363C85, 0x0000000C, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFFFFFF83, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFFFFFF83, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x000000A5, 0x00000043, 0x00000002, PlaySound, 0x0000076D, 0x00000043, 0x00000002, func_802D62E4, 0x0000036D, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x003B0004, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFFFFFEE3, 0x00000000, 0x00000023, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A9A80, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFFFFFF79, 0x00000017, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFFFFFF92, 0xFFFFFFF3, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, func_802CDE68, 0x00000000, 0x0000000A, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFF7, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0x00000000, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, SetNpcRotation, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x003B0010, 0x00000057, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFFFFFFD3, 0x00000000, 0xFFFFFFF8, 0x0000000A, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000003E3, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000032, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000004, PlaySoundAtNpc, 0xFE363C89, 0x000003E4, 0x00000000, 0x00000008, 0x00000001, 0x00000007, 0x00000006, 0x00000000, 0x00000043, 0x00000003, func_802CDE68, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x003B0001, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0xFFFFFFCE, 0x00000000, 0xFFFFFFF8, 0x0000000A, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x0000010E, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, PlaySoundAtNpc, 0x00000000, 0x000003A2, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x003B0004, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A9280, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0x00000064, 0x00000032, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, StopSound, 0x000003A2, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF8405FD9, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002A, 0x00000052, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002C, 0x00000054, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002E, 0x00000056, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000030, 0x00000058, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000032, 0x0000005A, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000035, 0x0000005D, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000037, 0x0000005F, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000039, 0x00000061, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000003B, 0x00000063, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000003D, 0x00000065, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000040, 0x00000068, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000042, 0x0000006A, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000044, 0x0000006C, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000046, 0x0000006E, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000048, 0x00000070, 0x0000000A, 0x00000002, 0xF8405FD9, 0x00000000, 0x00000047, 0x00000005, 0x802435F0, 0x00100000, 0x802435E0, 0x00000001, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000074, 0x00000000, 0x00000030, 0x00000001, D_80243580_DA0A50, 0x00000005, 0x00000001, 0x0000000C, 0x00000031, 0x00000001, 0xFE363C80, 0x00000043, 0x00000003, EnableModel, 0xFE363C80, 0x00000000, 0x00000006, 0x00000000, 0x00000030, 0x00000001, D_802435B0_DA0A80, 0x00000005, 0x00000001, 0x0000000C, 0x00000031, 0x00000001, 0xFE363C80, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0xFE363C80, 0x7FFFFE00, 0x00000006, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000052, 0xFFFFFFA6, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000006, RotateModel, 0x0000005D, 0xFFFFFFA6, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFFFFFFA6, 0xF24A7C93, 0x00000000, 0xF24A823A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000002A, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000035, 0x00000043, 0x00000002, UpdateColliderTransform, 0x00000042, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
