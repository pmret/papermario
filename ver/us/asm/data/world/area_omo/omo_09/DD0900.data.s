.include "macro.inc"

.section .data

glabel D_80243C30_DD0900
.word 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000001, omo_09_SetCamera0Flag1000, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x00000217, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000217, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8080, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80243CBC_DD098C
.word 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0x00000217, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000217, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24EC680, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24ABA80, 0xF24A0280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80243D70_DD0A40
.word 0x00000003, 0x00000000, 0xFFFFFFFD, 0x00000000, 0x00000002, 0x00000000, 0xFFFFFFFE, 0x00000000, 0x00000001, 0x00000000, 0xFFFFFFFF, 0x00000000

glabel D_80243DA0_DD0A70
.word 0x00000030, 0x00000001, D_80243D70_DD0A40, 0x00000005, 0x00000001, 0x0000000C, 0x00000031, 0x00000001, 0xFE363C81, 0x00000043, 0x00000005, TranslateModel, 0xFE363C80, 0x00000000, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80243E04_DD0AD4
.word 0x0000000A, 0x00000002, 0xFAA2B580, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000029, 0x80000015, 0x00000000, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B580, 0x00000001, 0x00000024, 0x00000002, 0xF971888B, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000005C, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000005D, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x0000005C, 0x00000046, 0x00000001, D_80243DA0_DD0A70, 0x00000043, 0x00000003, EnableModel, 0x0000005C, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005D, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80243EEC_DD0BBC
.word 0x0000000A, 0x00000002, 0xFAA2B581, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B581, 0x00000001, 0x00000027, 0x00000002, 0xFD050F86, 0x00000002, 0x00000024, 0x00000002, 0xFD050F83, 0xFD050F86, 0x0000000A, 0x00000002, 0xFD050F86, 0x00000006, 0x00000044, 0x00000001, D_80243C30_DD0900, 0x00000024, 0x00000002, 0xFD050F86, 0x00000007, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF971888C, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000005F, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000065, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x0000005F, 0x00000046, 0x00000001, D_80243DA0_DD0A70, 0x00000043, 0x00000003, EnableModel, 0x0000005F, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000065, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80243FF4_DD0CC4
.word 0x0000000A, 0x00000002, 0xFAA2B582, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B582, 0x00000001, 0x00000027, 0x00000002, 0xFD050F86, 0x00000002, 0x00000024, 0x00000002, 0xFD050F84, 0xFD050F86, 0x0000000A, 0x00000002, 0xFD050F86, 0x00000006, 0x00000044, 0x00000001, D_80243C30_DD0900, 0x00000024, 0x00000002, 0xFD050F86, 0x00000007, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF971888D, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000061, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000066, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000061, 0x00000046, 0x00000001, D_80243DA0_DD0A70, 0x00000043, 0x00000003, EnableModel, 0x00000061, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000066, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802440FC_DD0DCC
.word 0x0000000A, 0x00000002, 0xFAA2B583, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B583, 0x00000001, 0x00000027, 0x00000002, 0xFD050F86, 0x00000002, 0x00000024, 0x00000002, 0xFD050F85, 0xFD050F86, 0x0000000A, 0x00000002, 0xFD050F86, 0x00000006, 0x00000044, 0x00000001, D_80243C30_DD0900, 0x00000024, 0x00000002, 0xFD050F86, 0x00000007, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF971888E, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000063, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000067, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000063, 0x00000046, 0x00000001, D_80243DA0_DD0A70, 0x00000043, 0x00000003, EnableModel, 0x00000063, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000067, 0x00000001, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80244204_DD0ED4
.word 0x00000024, 0x00000002, 0xFAA2B584, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0xFD050F80, 0x00000027, 0x00000002, 0xFE363C82, 0x00000168, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFD050F80, 0xFE363C82, 0x00000032, 0x00000001, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006B, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006C, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006D, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C88, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000007, 0xFE363C87, 0x00000029, 0x00000002, 0xFE363C87, 0x0000002D, 0x00000027, 0x00000002, 0xFE363C87, 0x000009D8, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C87, 0x0000002A, 0x00000002, 0xFE363C86, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C83, 0xFE363C87, 0x00000043, 0x00000005, MakeLerp, 0xFE363C82, 0xFE363C83, 0xFE363C86, 0x00000000, 0x00000003, 0x00000001, 0x00000005, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006B, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006C, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006D, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B581, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C80, 0x0000002B, 0x00000002, 0xFE363C89, 0x0000002D, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000000, 0x00000028, 0x00000002, 0xFD050F83, 0x00000001, 0x0000000A, 0x00000002, 0xFD050F83, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B581, 0x00000001, 0x00000027, 0x00000002, 0xFD050F86, 0x00000002, 0x00000024, 0x00000002, 0xFD050F83, 0xFD050F86, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000005, 0x00000003, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xFAA2B581, 0x00000001, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C84, 0x00000438, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C84, 0x00000028, 0x00000004, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006B, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006C, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006D, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B581, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B584, 0x00000000, 0x00000024, 0x00000002, 0xFD050F80, 0xFE363C84, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000002B, 0x000003F3, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024473C_DD140C
.word 0x00000024, 0x00000002, 0xFAA2B585, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0xFD050F81, 0x00000027, 0x00000002, 0xFE363C82, 0x00000168, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFD050F81, 0xFE363C82, 0x00000032, 0x00000001, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006F, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000070, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000071, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000072, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C88, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000007, 0xFE363C87, 0x00000029, 0x00000002, 0xFE363C87, 0x0000002D, 0x00000027, 0x00000002, 0xFE363C87, 0x00000CA8, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C87, 0x0000002A, 0x00000002, 0xFE363C86, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C83, 0xFE363C87, 0x00000043, 0x00000005, MakeLerp, 0xFE363C82, 0xFE363C83, 0xFE363C86, 0x00000000, 0x00000003, 0x00000001, 0x00000005, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006F, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000070, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000071, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000072, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B582, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C80, 0x0000002B, 0x00000002, 0xFE363C89, 0x0000002D, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000000, 0x00000028, 0x00000002, 0xFD050F84, 0x00000001, 0x0000000A, 0x00000002, 0xFD050F84, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B582, 0x00000001, 0x00000027, 0x00000002, 0xFD050F86, 0x00000002, 0x00000024, 0x00000002, 0xFD050F84, 0xFD050F86, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000005, 0x00000003, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xFAA2B582, 0x00000001, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C84, 0x00000438, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C84, 0x00000028, 0x00000004, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x0000006F, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000070, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000071, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000072, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B582, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B585, 0x00000000, 0x00000024, 0x00000002, 0xFD050F81, 0xFE363C84, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000002D, 0x000003F3, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80244C74_DD1944
.word 0x00000024, 0x00000002, 0xFAA2B586, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0xFD050F82, 0x00000027, 0x00000002, 0xFE363C82, 0x00000168, 0x00000024, 0x00000002, 0xFE363C85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFD050F82, 0xFE363C82, 0x00000032, 0x00000001, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000074, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000075, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000076, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000077, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFE363C88, 0xFE363C80, 0x00000028, 0x00000002, 0xFE363C88, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000007, 0xFE363C87, 0x00000029, 0x00000002, 0xFE363C87, 0x0000002D, 0x00000027, 0x00000002, 0xFE363C87, 0x00000F78, 0x00000024, 0x00000002, 0xFE363C86, 0xFE363C87, 0x0000002A, 0x00000002, 0xFE363C86, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C83, 0xFE363C87, 0x00000043, 0x00000005, MakeLerp, 0xFE363C82, 0xFE363C83, 0xFE363C86, 0x00000000, 0x00000003, 0x00000001, 0x00000005, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000074, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000075, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000076, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000077, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B583, 0x00000001, 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C80, 0x0000002B, 0x00000002, 0xFE363C89, 0x0000002D, 0x0000000A, 0x00000002, 0xFE363C89, 0x00000000, 0x00000028, 0x00000002, 0xFD050F85, 0x00000001, 0x0000000A, 0x00000002, 0xFD050F85, 0x00000000, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B583, 0x00000001, 0x00000027, 0x00000002, 0xFD050F86, 0x00000002, 0x00000024, 0x00000002, 0xFD050F85, 0xFD050F86, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000005, 0x00000003, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xFAA2B583, 0x00000001, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C84, 0x00000438, 0x00000043, 0x00000005, MakeLerp, 0xFE363C83, 0xFE363C84, 0x00000028, 0x00000004, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateModel, 0x00000074, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000075, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000076, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000077, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B583, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B586, 0x00000000, 0x00000024, 0x00000002, 0xFD050F82, 0xFE363C84, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000002F, 0x000003F3, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802451AC_DD1E7C
.word 0x00000001, 0x00000003, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001, 0x00000002, 0x00000003, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x00000003, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x00000002

glabel D_8024520C_DD1EDC
.word 0x00000024, 0x00000002, 0xF971888C, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005F, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000065, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005F, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000065, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000013, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000024, 0x00000002, 0xF971888C, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x0000000A, 0x00000002, 0xF971888C, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024534C_DD201C
.word 0x00000024, 0x00000002, 0xF971888D, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000061, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000066, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000061, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000066, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000013, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000024, 0x00000002, 0xF971888D, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x0000000A, 0x00000002, 0xF971888D, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024548C_DD215C
.word 0x00000024, 0x00000002, 0xF971888E, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000063, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000067, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000063, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000067, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000013, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000024, 0x00000002, 0xF971888E, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x0000000A, 0x00000002, 0xF971888E, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802455CC_DD229C
.word 0x00000024, 0x00000002, 0xF971888B, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005C, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000005D, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005C, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005D, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x0000000A, 0x00000002, 0xF971888B, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E83, 0x00000001, 0x00000044, 0x00000001, D_8024520C_DD1EDC, 0x00000044, 0x00000001, D_8024534C_DD201C, 0x00000044, 0x00000001, D_8024548C_DD215C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802456FC_DD23CC
.word 0x00000003, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B587, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFAA2B580, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B581, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B582, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B583, 0x00000000, 0x00000024, 0x00000002, 0xFD050F83, 0x00000000, 0x00000024, 0x00000002, 0xFD050F84, 0x00000000, 0x00000024, 0x00000002, 0xFD050F85, 0x00000000, 0x00000024, 0x00000002, 0xFD050F86, 0x00000000, 0x00000044, 0x00000001, D_80244204_DD0ED4, 0x00000044, 0x00000001, D_8024473C_DD140C, 0x00000044, 0x00000001, D_80244C74_DD1944, 0x00000008, 0x00000001, 0x00000003, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000005, IsPlayerWithin, 0x0000020D, 0x00000000, 0x000001F4, 0xF70F2E83, 0x0000000A, 0x00000002, 0xF70F2E83, 0x00000000, 0x00000043, 0x00000002, StopSound, 0x80000015, 0x00000008, 0x00000001, 0x00000064, 0x00000004, 0x00000001, 0x00000063, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0xFAA2B584, 0x00000027, 0x00000002, 0xFE363C81, 0xFAA2B585, 0x00000027, 0x00000002, 0xFE363C81, 0xFAA2B586, 0x0000000A, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C8A, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B584, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B585, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000001, 0x00000043, 0x00000004, func_802402D0_DCCFA0, 0xFD050F80, 0xFD050F81, 0xFFFFFFFF, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B586, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000001, 0x00000043, 0x00000004, func_802402D0_DCCFA0, 0xFD050F80, 0xFFFFFFFF, 0xFD050F82, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B585, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B586, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000001, 0x00000043, 0x00000004, func_802402D0_DCCFA0, 0xFFFFFFFF, 0xFD050F81, 0xFD050F82, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B587, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x00000025, 0x00000B88, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, StopSound, 0x80000015, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, func_802402D0_DCCFA0, 0xFD050F80, 0xFD050F81, 0xFD050F82, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B587, 0x00000001, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFD050F8B, 0xF24BE280, 0x00000014, 0x00000001, 0xFE363C8B, 0x00000016, 0x00000001, 0x00000001, 0x00000014, 0x00000001, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000003, 0x00000046, 0x00000001, D_80243CBC_DD098C, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x000001E5, 0x00000082, 0xFFFFFFCE, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7DB4, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0x000001CC, 0x00000000, 0x00000032, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000000, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0x000001FE, 0x00000082, 0xFFFFFFCE, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000001, 0xF24A7DB4, 0x00000043, 0x00000006, NpcJump0, 0x00000001, 0x000001F1, 0x00000000, 0x00000032, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000001, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000002, 0x00000217, 0x00000082, 0xFFFFFFCE, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000002, 0xF24A7DB4, 0x00000043, 0x00000006, NpcJump0, 0x00000002, 0x00000217, 0x00000000, 0x00000032, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000002, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000003, 0x00000230, 0x00000082, 0xFFFFFFCE, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000003, 0xF24A7DB4, 0x00000043, 0x00000006, NpcJump0, 0x00000003, 0x0000023D, 0x00000000, 0x00000032, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000003, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000004, 0x00000249, 0x00000082, 0xFFFFFFCE, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000004, 0xF24A7DB4, 0x00000043, 0x00000006, NpcJump0, 0x00000004, 0x00000262, 0x00000000, 0x00000032, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000004, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000016, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_80243CBC_DD098C, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0x000001FE, 0x00000082, 0xFFFFFFCE, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000001, 0xF24A7DB4, 0x00000043, 0x00000006, NpcJump0, 0x00000001, 0x000001F1, 0x00000000, 0x00000032, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000001, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000003, 0x00000230, 0x00000082, 0xFFFFFFCE, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000003, 0xF24A7DB4, 0x00000043, 0x00000006, NpcJump0, 0x00000003, 0x0000023D, 0x00000000, 0x00000032, 0x0000001E, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000003, 0x00000040, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFD050F8B, 0xF24A8280, 0x00000023, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000014, 0x00000001, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000003, 0x00000046, 0x00000001, D_80243CBC_DD098C, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x000001E0, 0x00000005, 0x00000001, 0x00000005, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0xFE363C81, 0x00000096, 0x00000032, 0x00000003, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000016, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_80243CBC_DD098C, 0x00000043, 0x00000007, MakeItemEntity, 0x00000157, 0x00000217, 0x00000096, 0x00000032, 0x00000003, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFD050F8B, 0xF24A8280, 0x00000023, 0x00000000, 0x00000016, 0x00000001, 0x00000003, 0x00000014, 0x00000001, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000003, 0x00000046, 0x00000001, D_80243CBC_DD098C, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x000001E0, 0x00000005, 0x00000001, 0x00000005, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000007, MakeItemEntity, 0x0000008A, 0xFE363C81, 0x00000096, 0x00000032, 0x00000003, 0x00000000, 0x00000008, 0x00000001, 0x00000003, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000016, 0x00000001, 0x00000002, 0x00000046, 0x00000001, D_80243CBC_DD098C, 0x00000043, 0x00000007, MakeItemEntity, 0x0000008A, 0x00000217, 0x00000096, 0x00000032, 0x00000003, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x0000001C, 0x00000000, 0x00000024, 0x00000002, 0xFD050F8B, 0xF24A8280, 0x00000023, 0x00000000, 0x00000023, 0x00000000, 0x00000043, 0x00000001, omo_09_UnsetCamera0Flag1000, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xFD050F8B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0xFFFFFFFF, 0x00000005, 0x00000001, 0x00000005, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x0000000F, 0x00000002, 0xFE363C82, 0x00000000, 0x00000024, 0x00000002, 0xFE363C84, 0x00000000, 0x00000013, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00000001, 0x00000006, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000032, 0x00000003, 0x00000001, 0x00000063, 0x00000024, 0x00000002, 0xFAA2B580, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B581, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B582, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B583, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B584, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B585, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B586, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B587, 0x00000000, 0x00000024, 0x00000002, 0xF971888C, 0x00000000, 0x00000024, 0x00000002, 0xF971888D, 0x00000000, 0x00000024, 0x00000002, 0xF971888E, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005C, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000005D, 0x00000000, 0x00000044, 0x00000001, D_802455CC_DD229C, 0x00000043, 0x00000003, EnableModel, 0x0000005F, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000065, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000061, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000066, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000063, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000067, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024636C_DD303C
.word 0x0000005C, 0x0000005F, 0x00000061, 0x00000063, 0x00000043, 0x00000003, ParentColliderToModel, 0x00000029, 0x0000005C, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002B, 0x0000005F, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002D, 0x00000061, 0x00000043, 0x00000003, ParentColliderToModel, 0x0000002F, 0x00000063, 0x00000047, 0x00000005, D_80243E04_DD0AD4, 0x00040000, 0x00000029, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80243EEC_DD0BBC, 0x00040000, 0x0000002B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80243FF4_DD0CC4, 0x00040000, 0x0000002D, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802440FC_DD0DCC, 0x00040000, 0x0000002F, 0x00000001, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000007, 0xFD050F80, 0x00000029, 0x00000002, 0xFD050F80, 0x0000002D, 0x00000043, 0x00000006, RotateModel, 0x0000006A, 0xFD050F80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006B, 0xFD050F80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006C, 0xFD050F80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x0000006D, 0xFD050F80, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000007, 0xFD050F81, 0x00000029, 0x00000002, 0xFD050F81, 0x0000002D, 0x00000043, 0x00000006, RotateModel, 0x0000006F, 0xFD050F81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000070, 0xFD050F81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000071, 0xFD050F81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000072, 0xFD050F81, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000003, RandInt, 0x00000007, 0xFD050F82, 0x00000029, 0x00000002, 0xFD050F82, 0x0000002D, 0x00000043, 0x00000006, RotateModel, 0x00000074, 0xFD050F82, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000075, 0xFD050F82, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000076, 0xFD050F82, 0x00000001, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateModel, 0x00000077, 0xFD050F82, 0x00000001, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B580, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B581, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B582, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B583, 0x00000001, 0x00000024, 0x00000002, 0xFAA2B584, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B585, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B586, 0x00000000, 0x00000024, 0x00000002, 0xFAA2B587, 0x00000000, 0x00000043, 0x00000003, EnableTexPanning, 0x0000007A, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000007B, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000007C, 0x00000001, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFAA2B587, 0x00000001, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFBAA, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetTexPanOffset, 0x0000000B, 0x00000000, 0x00000000, 0xFE363C81, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80240534_DCD204, 0x00000057, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000005C, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000005D, 0x00000000, 0x00000044, 0x00000001, D_802455CC_DD229C, 0x00000043, 0x00000003, EnableModel, 0x0000005F, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000065, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000061, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000066, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000063, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000067, 0x00000000, 0x00000044, 0x00000001, D_802456FC_DD23CC, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
