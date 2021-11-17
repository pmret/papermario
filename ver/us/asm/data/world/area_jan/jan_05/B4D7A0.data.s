.include "macro.inc"

.section .data

dlabel D_80242D30_B4D7A0
.word 0x0000000A, 0x00000002, 0xF8406053, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000004E, 0x7FFFFE00, 0x00000043, 0x00000003, EnableModel, 0x0000006E, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x00000071, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x0000006F, 0x00000000, 0xFFFFFF10, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFFFFFF10, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000004C, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000004D, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x0000004E, 0x7FFFFE00, 0x00000043, 0x00000003, EnableModel, 0x0000006E, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000071, 0x00000001, 0x00000043, 0x00000005, TranslateGroup, 0x0000006F, 0x00000000, 0x0000000A, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0x0000000A, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x0000006F, 0xFFFFFFA6, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateGroup, 0x00000072, 0xFFFFFFA6, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateGroup, 0x0000006F, 0x0000005A, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000072, 0xFFFFFFA6, 0x00000000, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242F00_B4D970
.word 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000004C, 0x00000165, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFF10, 0xFFFFFEFD, 0x00000005, 0x00000006, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000006F, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242FC8_B4DA38
.word 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000002, SetPlayerAnimation, 0x0001002A, 0x00000043, 0x00000003, func_80240350_B4ADC0, 0x0000006E, 0xFAA2B58B, 0x00000057, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x0000004C, 0x7FFFFE00, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFEFD, 0x0000003C, 0x0000001E, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000006F, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, MakeLerp, 0x0000003C, 0x00000000, 0x0000001E, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000006F, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000004C, 0x0000209D, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000006, 0x00000004, 0xFFFFFF47, 0x00000000, 0x00000140, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000002, 0x00000003, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243204_B4DC74
.word 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000032, 0x00000024, 0x00000002, 0xFAA2B58B, 0x00000001, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFA6, 0x0000003C, 0x00000002, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000006F, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x0000006F, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateGroup, 0x00000072, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000002, 0x00000003, 0x00000001, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024334C_B4DDBC
.word 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000004C, 0x0000209E, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000006E, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x00000071, 0x00000001, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000005A, 0x0000001E, 0x00000008, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000024, 0x00000002, 0xFE363C82, 0xFE363C80, 0x0000002F, 0x00000002, 0xFE363C82, 0x00000009, 0x00000043, 0x00000005, TranslateGroup, 0x0000006F, 0x00000000, 0xFE363C82, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFE363C82, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x0000006F, 0xFFFFFFA6, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateGroup, 0x00000072, 0xFFFFFFA6, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateGroup, 0x0000006F, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000072, 0xFE363C80, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802434DC_B4DF4C
.word 0x00000024, 0x00000002, 0xF8406053, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000046, 0x00000001, D_80242F00_B4D970, 0x00000008, 0x00000001, 0x00000001, 0x00000046, 0x00000001, D_80242FC8_B4DA38, 0x00000008, 0x00000001, 0x00000001, 0x00000046, 0x00000001, D_80243204_B4DC74, 0x00000008, 0x00000001, 0x00000001, 0x00000046, 0x00000001, D_8024334C_B4DDBC, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000044, 0x00000001, D_80242D30_B4D7A0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8406053, 0x00000000, 0x00000047, 0x00000005, D_802434DC_B4DF4C, 0x00001000, 0x0000004C, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80242D30_B4D7A0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
