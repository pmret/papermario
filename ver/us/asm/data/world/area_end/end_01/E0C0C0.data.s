.include "macro.inc"

.section .data

dlabel D_80246D60_E0C0C0
.word 0x00000043, 0x00000003, EnableTexPanning, 0x00000042, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000046, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x00000037, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00001000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000009, 0x00000001, 0xFE363C80, 0xFE363C80, 0x00000008, 0x00000001, 0xFE363C81, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246E18_E0C178
.word 0x00000043, 0x00000003, EnableTexPanning, 0x00000039, 0x00000001, 0x00000043, 0x00000003, EnableTexPanning, 0x0000003E, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000027, 0x00000002, 0xFE363C80, 0x00004000, 0x00000043, 0x00000005, SetTexPanOffset, 0x00000008, 0x00000000, 0xFE363C80, 0xFE363C80, 0x00000008, 0x00000001, 0x00000006, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246EAC_E0C20C
.word 0x00000038, 0x0000003A, 0x0000003B, 0x0000003C, 0x0000003D, 0x0000003E, 0x0000003F, 0x0000FFFF

dlabel D_80246ECC_E0C22C
.word 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFA6, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x00000045, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000005A, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x00000048, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000004, end_01_UnkFunc27, 0x00000000, D_80246EAC_E0C20C, 0x00000003, 0x00000043, 0x0000000B, end_01_UnkFunc26, 0x00000003, 0x000000FF, 0x000000FF, 0x000000FF, 0x00000078, 0x00000078, 0x00000050, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x0000000B, end_01_UnkFunc26, 0x00000003, 0x000000FF, 0x000000FF, 0x000000FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247098_E0C3F8
.word 0x00000024, 0x00000002, 0xFE363C80, 0x0000010E, 0x00000005, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x0000010E, 0x00000024, 0x00000002, 0xFE363C80, 0x0000005A, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x0000010E, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000001D, 0x00E7000D, 0x00000043, 0x00000004, InterpNpcYaw, 0x0000001D, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000001D, 0x00E7000E, 0x00000008, 0x00000001, 0x00000014, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247164_E0C4C4
.word 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C80, 0x00000005, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000003, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70008, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70007, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70006, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000168, 0x0000000A, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0xFE363C82, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024729C_E0C5FC
.word 0x00000008, 0x00000001, 0x0000001E, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C83, 0xFE363C81, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFE363C82, 0xF24A7C80, 0x00000043, 0x00000006, NpcJump0, 0xFE363C82, 0xFE363C83, 0x0000000A, 0x00000014, 0x00000014, 0x00000008, 0x00000001, 0x0000000A, 0x00000005, 0x00000001, 0x00000000, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70001, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70002, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70003, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70002, 0x00000008, 0x00000001, 0x00000005, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000168, 0x0000000A, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0xFE363C82, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247450_E0C7B0
.word 0x00000045, 0x00000002, D_80247098_E0C3F8, 0xFE363C87, 0x00000024, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000045, 0x00000002, D_80247164_E0C4C4, 0xFE363C88, 0x00000024, 0x00000002, 0xFE363C80, 0x0000001F, 0x00000045, 0x00000002, D_80247164_E0C4C4, 0xFE363C89, 0x00000024, 0x00000002, 0xFE363C80, 0x00000020, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFA1C, 0x00000045, 0x00000002, D_8024729C_E0C5FC, 0xFE363C8A, 0x00000024, 0x00000002, 0xFE363C80, 0x00000021, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFA44, 0x00000045, 0x00000002, D_8024729C_E0C5FC, 0xFE363C8B, 0x00000024, 0x00000002, 0xFE363C80, 0x00000022, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFA6C, 0x00000045, 0x00000002, D_8024729C_E0C5FC, 0xFE363C8C, 0x00000024, 0x00000002, 0xFE363C80, 0x00000023, 0x00000024, 0x00000002, 0xFE363C81, 0xFFFFFA94, 0x00000045, 0x00000002, D_8024729C_E0C5FC, 0xFE363C8D, 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetCamPosition, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000D, 0x00000002, 0xFE363C80, 0xFFFFFB66, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000049, 0x00000001, 0xFE363C87, 0x00000049, 0x00000001, 0xFE363C88, 0x00000049, 0x00000001, 0xFE363C89, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000049, 0x00000001, 0xFE363C8B, 0x00000049, 0x00000001, 0xFE363C8C, 0x00000049, 0x00000001, 0xFE363C8D, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000004, 0x00000045, 0x00000002, D_80246D60_E0C0C0, 0xFE363C8A, 0x00000045, 0x00000002, D_80246E18_E0C178, 0xFE363C8B, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, NpcMoveTo, 0x0000001C, 0xFFFFF990, 0x00000000, 0x00000032, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000001C, 0x00E70009, 0x00000043, 0x00000004, InterpNpcYaw, 0x0000001C, 0x0000005A, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000001C, 0x00E7000B, 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetCamPosition, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000D, 0x00000002, 0xFE363C80, 0xFFFFFA12, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000001C, 0x00E7000A, 0x00000043, 0x00000005, NpcMoveTo, 0x0000001C, 0xFFFFF92C, 0x00000000, 0x00000032, 0x00000057, 0x00000000, 0x00000044, 0x00000001, D_80247450_E0C7B0, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000045, 0x00000002, D_80246D60_E0C0C0, 0xFE363C8A, 0x00000046, 0x00000001, D_80246ECC_E0C22C, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000024, 0x00000002, 0xFE363C80, 0x00000004, 0x00000045, 0x00000002, D_80246D60_E0C0C0, 0xFE363C8A, 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetCamPosition, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000D, 0x00000002, 0xFE363C80, 0xFFFFFB66, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000049, 0x00000001, 0xFE363C8B, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247854_E0CBB4
.word 0x00000043, 0x00000005, GetNpcPos, 0x00000026, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000026, 0x00000002, 0xFE363C80, 0xFE363C80, 0x00000026, 0x00000002, 0xFE363C81, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C81, 0x0000001E, 0x00000026, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C82, 0x0000003C, 0x00000026, 0x00000002, 0xFE363C83, 0xFE363C80, 0x0000002C, 0x00000002, 0xFE363C83, 0x0000005A, 0x00000043, 0x00000005, SetNpcPos, 0x00000026, 0xFE363C80, 0x00000000, 0xFFFFFFE2, 0x00000043, 0x00000005, SetNpcPos, 0x00000027, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000028, 0xFE363C80, 0x00000000, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0x00000029, 0xFE363C81, 0x00000000, 0xFFFFFFE2, 0x00000043, 0x00000005, SetNpcPos, 0x0000002A, 0xFE363C81, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x0000002B, 0xFE363C81, 0x00000000, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0x0000002C, 0xFE363C82, 0x00000000, 0xFFFFFFE2, 0x00000043, 0x00000005, SetNpcPos, 0x0000002D, 0xFE363C82, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x0000002E, 0xFE363C82, 0x00000000, 0x0000001E, 0x00000043, 0x00000005, SetNpcPos, 0x0000002F, 0xFE363C83, 0x00000000, 0xFFFFFFE2, 0x00000043, 0x00000005, SetNpcPos, 0x00000030, 0xFE363C83, 0x00000000, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000031, 0xFE363C83, 0x00000000, 0x0000001E, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x00000027, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x00000028, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x00000029, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x0000002A, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x0000002B, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x0000002C, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x0000002D, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x0000002E, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x0000002F, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x00000030, 0x00000059, 0x00000000, 0x00000058, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x00000031, 0x00000059, 0x00000000, 0x00000043, 0x00000002, func_80242840_E07BA0, 0x00000026, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80247BB0_E0CF10
.word 0x00000043, 0x00000005, GetNpcPos, 0xFE363C80, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000027, 0x00000002, 0xFE363C82, 0xFFFFFF4C, 0x00000043, 0x00000005, NpcMoveTo, 0xFE363C80, 0xFE363C82, 0xFE363C84, 0x0000005A, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C83, 0x0000001C, 0x00000028, 0x00000002, 0xFE363C83, 0xFE363C81, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70010, 0x00000008, 0x00000001, 0xFE363C81, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E70011, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000168, 0x0000000A, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0xFE363C82, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0xFE363C83, 0x00000043, 0x00000003, SetNpcAnimation, 0xFE363C82, 0x00E7000F, 0x00000043, 0x00000005, GetNpcPos, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000027, 0x00000002, 0xFE363C83, 0xFFFFFF4C, 0x00000043, 0x00000005, NpcMoveTo, 0xFE363C82, 0xFE363C83, 0xFE363C85, 0x0000005A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000026, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x00000027, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x00000028, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C81, 0x00000008, 0x00000024, 0x00000002, 0xFE363C80, 0x00000029, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002A, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002B, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002C, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002D, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002E, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C81, 0x00000012, 0x00000024, 0x00000002, 0xFE363C80, 0x0000002F, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x00000030, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000024, 0x00000002, 0xFE363C80, 0x00000031, 0x00000044, 0x00000001, D_80247BB0_E0CF10, 0x00000008, 0x00000001, 0x0000005A, 0x00000045, 0x00000002, D_80247854_E0CBB4, 0xFE363C8A, 0x00000008, 0x00000001, 0x00000030, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000008, 0x00000001, 0x00000082, 0x00000043, 0x00000005, GetNpcPos, 0x00000032, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFF4C, 0x00000043, 0x00000005, NpcMoveTo, 0x00000032, 0xFE363C80, 0xFE363C82, 0x0000002D, 0x00000043, 0x00000003, func_802CDE68, 0x00000032, 0x0000000A, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000005, 0x00000001, 0x0000000A, 0x00000027, 0x00000002, 0xFE363C80, 0x00000009, 0x00000043, 0x00000005, SetNpcRotation, 0x00000032, 0x00000000, 0x00000000, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, SetNpcRotation, 0x00000032, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000032, 0x003B0010, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000032, 0xF24A7E80, 0x00000043, 0x00000005, GetNpcPos, 0x00000032, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFD3, 0x00000043, 0x00000006, NpcJump0, 0x00000032, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000024, 0x00000002, 0xFE363C80, 0x00000032, 0x00000045, 0x00000002, 0x80244180, 0xFE363C8A, 0x00000008, 0x00000001, 0x00000050, 0x00000043, 0x00000003, func_802CDE68, 0x00000032, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000032, 0x003B0001, 0x00000043, 0x00000005, GetNpcPos, 0x00000032, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFFB, 0x00000043, 0x00000006, NpcJump0, 0x00000032, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000A, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000032, 0x003B0004, 0x00000043, 0x00000005, GetNpcPos, 0x00000032, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFF4C, 0x00000043, 0x00000005, NpcMoveTo, 0x00000032, 0xFE363C80, 0xFE363C82, 0x0000005A, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
