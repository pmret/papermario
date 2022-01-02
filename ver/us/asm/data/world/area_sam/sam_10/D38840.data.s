.include "macro.inc"

.section .data

dlabel D_80241040_D38840
.word 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EA5AC, 0x00000307, 0x0000021C, 0xFFFFFFCE, 0x00000000, 0x00000123, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8406137, 0x00000043, 0x00000007, MakeItemEntity, 0x0000015C, 0xFFFFFF60, 0x0000012C, 0xFFFFFF92, 0x00000011, 0xF8406138, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000004D, 0x00000043, 0x00000007, DropItemEntityB, 0x0000006C, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_802402BC_D37ABC, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C80, 0x00000012, 0x00000000, 0x00000043, 0x00000007, DropItemEntityB, 0x0000006C, 0xFFFFFF8B, 0x000000B3, 0xFFFFFFC9, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_802402BC_D37ABC, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeEntity, D_802E9A18, 0xFFFFFF06, 0x00000366, 0xFFFFFF2E, 0x00000000, 0x80000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA7E0, 0x00000302, 0x000004B0, 0xFFFFFF1F, 0x00000000, 0x80000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411F0_D389F0
.word 0x00000028, 0xFFFFFF38, 0x0000002B, 0xFFFFFF1A, 0x0000002E, 0xFFFFFEFC, 0x00000031, 0xFFFFFEDE, 0x00000034, 0xFFFFFEC0, 0x00000037, 0xFFFFFEA2, 0x0000003A, 0xFFFFFE84, 0x0000003D, 0xFFFFFE66, 0x00000040, 0xFFFFFE48, 0x00000043, 0xFFFFFE2A, 0x00000046, 0xFFFFFDEE, 0x00000049, 0xFFFFFDD0, 0x0000004C, 0xFFFFFDB2, 0x0000004F, 0xFFFFFD94, 0x00000052, 0xFFFFFD76, 0x00000055, 0xFFFFFD58, 0x00000058, 0xFFFFFD3A, 0x0000005B, 0xFFFFFD1C, 0x0000005E, 0xFFFFFCFE, 0x00000061, 0xFFFFFCE0, 0x00000064, 0xFFFFFCA4, 0x00000067, 0xFFFFFC86, 0x0000006A, 0xFFFFFC68, 0x0000006D, 0xFFFFFC4A, 0x00000070, 0xFFFFFC2C, 0x00000073, 0xFFFFFC0E, 0x00000076, 0xFFFFFBF0, 0x00000079, 0xFFFFFBD2, 0x0000007C, 0xFFFFFBB4, 0x0000007F, 0xFFFFFB96

dlabel D_802412E0_D38AE0
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000003, FindKeyItem, 0x0000006C, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000023, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D0161, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetItemPos, 0xFD050F80, 0xFFFFFF8B, 0x000000B3, 0xFFFFFFE0, 0x00000043, 0x00000006, PlaySoundAt, 0x000001EB, 0x00000000, 0xFFFFFF8B, 0x000000B3, 0xFFFFFFE0, 0x00000008, 0x00000001, 0x0000001E, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFE0, 0xFFFFFFC9, 0x00000064, 0x0000000A, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetItemPos, 0xFD050F80, 0xFFFFFF8B, 0x000000B3, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000002B, 0x0000039C, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFE9, 0x00000064, 0x0000000A, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000008C, 0x00000000, 0x00000000, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000002B, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000002D, 0x7FFFFE00, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF253DA80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24A8280, 0xF24A8E80, 0x00000043, 0x00000001, func_802402F0_D37AF0, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000004, SetCamPosB, 0x00000000, 0xFE363C82, 0xFE363C83, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, PlaySound, 0x0000039D, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A8680, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0xFFFFFFEC, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x00000014, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x0000003C, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x00000064, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x0000008C, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x000000B4, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x000000DC, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x000000F0, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x00000118, 0xFFFFFFEC, 0xFFFFFFBE, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0xFFFFFFEC, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x00000014, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x0000003C, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x00000064, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x0000008C, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x000000B4, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x000000DC, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x000000F0, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000003, 0x00000118, 0xFFFFFFEC, 0xFFFFFF5A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000003, SetGroupEnabled, 0x0000001D, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000080, 0x00000001, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000025, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x80000040, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000258, 0xF24A7B1A, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000030, 0x00000001, D_802411F0_D389F0, 0x00000005, 0x00000001, 0x0000001E, 0x00000027, 0x00000002, 0xFE363C82, 0x00000001, 0x00000032, 0x00000002, 0xFE363C83, 0xFE363C84, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C84, 0x0000002A, 0x00000002, 0xFE363C85, 0xFFFFFFFE, 0x00000043, 0x00000005, MakeLerp, 0xFE363C84, 0x00000000, 0xFE363C85, 0x00000000, 0x00000003, 0x00000001, 0x00000003, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0xFE363C83, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000003, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000002, PlaySound, 0x0000039F, 0x00000043, 0x00000002, StopSound, 0x80000040, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A8680, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x0000000A, 0xF24A8280, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000024, 0x00000002, 0xFE363C8B, 0xFE363C80, 0x00000043, 0x00000002, GetModelCenter, 0xFE363C83, 0x00000024, 0x00000002, 0xFE363C8A, 0xFFFFFFEC, 0x00000028, 0x00000002, 0xFE363C8A, 0xFE363C8B, 0x00000012, 0x00000000, 0x00000043, 0x00000006, PlaySoundAt, 0x000001EC, 0x00000000, 0xFE363C80, 0xFE363C8A, 0xFE363C82, 0x0000002B, 0x00000002, 0xFE363C82, 0x00000003, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000005, 0xF24A7E80, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000096, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x0000008C, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF250BA80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000096, 0x0000041A, 0x000000C8, 0x00000000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x00000096, 0x00000096, 0xFFFFFFBA, 0x00000003, 0x00000001, 0x00000064, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000096, 0xFE363C80, 0xFFFFFFBA, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF2563280, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AA280, 0xF24A4280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000064, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x000001E0, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000017, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x00000022, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x0000001B, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x00000025, 0x7FFFFE00, 0x00000043, 0x00000003, SetGroupEnabled, 0x0000001D, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000080, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000025, 0x00000001, 0x00000024, 0x00000002, 0xF5DE0180, 0x0000004D, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242138_D39938
.word 0x43A88000, 0xC1A00000, 0xC2CE0000, 0x00000000

dlabel D_80242148_D39948
.word 0x00000043, 0x0000000F, PlayEffect, 0x00000042, 0x00000002, 0x00000087, 0x0000000B, 0x00000001, 0x0000000A, 0x0000001E, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000019, 0x00000001, 0x00000005, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, EnableModel, 0x00000087, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000088, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000087, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000088, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000028, 0x7FFFFE00, 0x00000024, 0x00000002, 0xF8406136, 0x00000001, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024225C_D39A5C
.word 0x0000006C, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000A, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000010, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000E, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000012, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x0000000C, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000001, 0x00000008, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000006, 0x00000008, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002B, 0x0000008A, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000004D, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000080, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000025, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000022, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000001B, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000025, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000003, 0x00000017, 0x00000008, 0x00000030, 0x00000001, D_802411F0_D389F0, 0x00000005, 0x00000001, 0x0000001E, 0x00000032, 0x00000002, 0xFE363C8A, 0xFE363C8B, 0x00000043, 0x00000005, TranslateGroup, 0xFE363C8A, 0x00000000, 0xFE363C8B, 0x00000000, 0x00000006, 0x00000000, 0x0000004E, 0x00000006, D_802412E0_D38AE0, 0x00000100, 0x0000002B, D_8024225C_D39A5C, 0x00000000, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x0000008C, 0x00000000, 0x00000000, 0xFFFFFFE9, 0x00000043, 0x00000002, UpdateColliderTransform, 0x0000002B, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000002D, 0x7FFFFE00, 0x00000043, 0x00000003, SetGroupEnabled, 0x0000001D, 0x00000000, 0x00000043, 0x00000003, SetGroupEnabled, 0x00000080, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000017, 0x7FFFFE00, 0x00000013, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0x0000004C, 0x00000024, 0x00000002, 0xF8406136, 0x00000001, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8406136, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000019, 0x00000000, 0x00000047, 0x00000005, D_80242148_D39948, 0x00100000, D_80242138_D39938, 0x00000001, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000087, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000088, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000028, 0x7FFFFE00, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242580_D39D80
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00390000, 0x00390002, 0x00390003, 0x00390004, 0x0039000C, 0x00390007, 0x00390008, 0x00390011, 0x00390012, 0xFFFFFFFF

dlabel D_80242664_D39E64
.word 0x00390000, 0xFFFFFFFF

dlabel D_8024266C_D39E6C
.word 0x3FC00000, 0x00000078, 0x0000001E, 0x42C80000, 0x42200000, 0x00000007, 0x40733333, 0x0000005A, 0x0000000F, 0x43480000, 0x43200000, 0x00000001

dlabel D_8024269C_D39E9C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000007, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000006, 0x00000043, 0x00000002, sam_10_UnkNpcAIFunc27, D_8024266C_D39E6C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024270C_D39F0C
.word 0x00000000, 0x00240022, 0x00000000, 0x00000000, D_8024269C_D39E9C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00170000

dlabel D_80242738_D39F38
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000020, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000030, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000001E, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x000020C5, 0x00000043, 0x00000001, sam_10_UnkFunc7, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802427E0_D39FE0
.word 0x00000000, 0x000E0010, 0x00000000, 0x00000000, D_80242738_D39F38, 0x00000000, 0x00000000, D_80242580_D39D80, 0x00000000, 0x00000000, 0x00170008

dlabel D_8024280C_D3A00C
.word 0x00000000, D_8024270C_D39F0C, 0x440FC000, 0x43F00000, 0xC2480000, 0x00002D00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x0000023F, 0x000001E0, 0xFFFFFFCE, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x0000023F, 0x000001E0, 0xFFFFFFCE, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00390102, 0x00390103, 0x00390104, 0x00390104, 0x00390102, 0x00390102, 0x0039010C, 0x0039010C, 0x00390111, 0x00390112, 0x00390107, 0x00390108, 0x00390102, 0x00390102, 0x00390102, 0x00390102, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_802427E0_D39FE0, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00390102, 0x00390103, 0x00390104, 0x00390104, 0x00390102, 0x00390102, 0x0039010C, 0x0039010C, 0x00390111, 0x00390112, 0x00390107, 0x00390108, 0x00390102, 0x00390102, 0x00390102, 0x00390102, 0x00000000, 0x00000000, D_80242664_D39E64, 0x00000000, 0x00000002, D_8024280C_D3A00C, 0x1D0C0003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
