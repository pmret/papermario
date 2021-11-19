.include "macro.inc"

.section .data

dlabel D_80240320_AB95D0
.word 0xFFFFFE48, 0x0000044C, 0x0000001E, 0xFFFFFF42, 0x00000406, 0x00000028, 0xFFFFFF97, 0x0000044C, 0x0000001E, 0xFFFFFEA2, 0x00000258, 0x00000037, 0xFFFFFF1A, 0x000004B0, 0x00000023, 0xFFFFFE0C, 0x0000041A, 0x0000001E, 0xFFFFFE66, 0x00000384, 0x00000023, 0x0000004F, 0x00000302, 0x00000037, 0xFFFFFFFF

dlabel D_80240384_AB9634
.word 0x00000030, 0x00000001, D_80240320_AB95D0, 0x00000005, 0x00000001, 0x00000000, 0x00000033, 0x00000003, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x0000000A, 0x00000002, 0xFE363C82, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000001F4, 0x00000000, 0xFE363C84, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000075, 0xFE363C82, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000006, RotateGroup, 0x00000075, 0xFE363C84, 0x00000001, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C84, 0x0000000F, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802404A8_AB9758
.word 0xFFFFFEAC, 0x000003C0, 0x00000032, 0xFFFFFE66, 0x00000384, 0x00000037, 0xFFFFFF1A, 0x000004B0, 0x0000002D, 0xFFFFFE0C, 0x000003AC, 0x00000028, 0xFFFFFF1A, 0x000003F2, 0x00000032, 0xFFFFFE0C, 0x000003AC, 0x00000028, 0xFFFFFEA2, 0x00000258, 0x00000037, 0xFFFFFFFF

dlabel D_80240500_AB97B0
.word 0x00000030, 0x00000001, D_802404A8_AB9758, 0x00000005, 0x00000001, 0x00000000, 0x00000033, 0x00000003, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x0000000A, 0x00000002, 0xFE363C82, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000001F4, 0x00000000, 0xFE363C84, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000077, 0xFE363C82, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000006, RotateGroup, 0x00000077, 0xFE363C84, 0x00000001, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C84, 0x0000000F, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240624_AB98D4
.word 0x00000043, 0x00000005, MakeLerp, 0x000001F4, 0x00000000, 0x00000050, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000007A, 0xFFFFFEAC, 0xFE363C80, 0x0000033E, 0x00000043, 0x00000006, RotateGroup, 0x0000007A, 0xFE363C84, 0x00000001, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C84, 0x0000001E, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802406E8_AB9998
.word 0xFFFFFEA2, 0x00000258, 0x0000003C, 0xFFFFFF1A, 0x000004B0, 0x00000028, 0xFFFFFEAC, 0x000003C0, 0x00000028, 0xFFFFFFFF

dlabel D_80240710_AB99C0
.word 0x00000030, 0x00000001, D_802406E8_AB9998, 0x00000005, 0x00000001, 0x00000000, 0x00000033, 0x00000003, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x0000000A, 0x00000002, 0xFE363C82, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000001F4, 0x00000000, 0xFE363C84, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000007C, 0xFE363C82, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000006, RotateGroup, 0x0000007C, 0xFE363C84, 0x00000001, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C84, 0x0000000F, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240834_AB9AE4
.word 0x00000043, 0x00000005, MakeLerp, 0x000001F4, 0x00000000, 0x00000050, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000007E, 0xFFFFFF42, 0xFE363C80, 0x00000406, 0x00000043, 0x00000006, RotateGroup, 0x0000007E, 0xFE363C84, 0x00000001, 0x00000001, 0x00000001, 0x00000028, 0x00000002, 0xFE363C84, 0x0000000F, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802408F8_AB9BA8
.word 0xFFFFFE0C, 0x000003AC, 0x00000014, 0x00000050, 0x00000302, 0x0000003C, 0xFFFFFEAC, 0x000003C0, 0x0000000F, 0xFFFFFEAC, 0x000003C0, 0x0000002D, 0xFFFFFE0C, 0x0000041A, 0x0000000F, 0xFFFFFF1A, 0x000004B0, 0x00000023, 0xFFFFFEA2, 0x00000258, 0x00000028, 0xFFFFFFFF

dlabel D_80240950_AB9C00
.word 0x00000030, 0x00000001, D_802408F8_AB9BA8, 0x00000005, 0x00000001, 0x00000000, 0x00000033, 0x00000003, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x0000000A, 0x00000002, 0xFE363C82, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000001F4, 0x00000000, 0xFE363C84, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000080, 0xFE363C82, 0xFE363C80, 0xFE363C83, 0x00000043, 0x00000006, RotateGroup, 0x00000080, 0xFE363C84, 0x00000001, 0x00000001, 0x00000001, 0x00000027, 0x00000002, 0xFE363C84, 0x0000000F, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A74_AB9D24
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x0000005A, 0xFFFFFFA6, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000019, 0x00000000, 0xFD050F8E, 0x00000000, 0x00000043, 0x00000002, func_80240050_AB9300, 0xFE363C80, 0x00000043, 0x00000006, RotateGroup, 0x00000019, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000005, TranslateGroup, 0x00000019, 0x00000000, 0xFD050F8E, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000019, 0xFFFFFFEC, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFA6, 0x0000005A, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000019, 0x00000000, 0xFD050F8E, 0x00000000, 0x00000043, 0x00000002, func_80240050_AB9300, 0xFE363C80, 0x00000043, 0x00000006, RotateGroup, 0x00000019, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x00000002, 0x00000043, 0x00000005, TranslateGroup, 0x00000019, 0x00000000, 0xFD050F8E, 0x00000000, 0x00000043, 0x00000006, RotateGroup, 0x00000019, 0x00000014, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CB8_AB9F68
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x0000002D, 0xFFFFFFD3, 0x0000003C, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x0000000C, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFD3, 0x0000002D, 0x0000003C, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x0000000C, 0xFE363C80, 0x00000000, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240DEC_ABA09C
.word 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000078, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x0000006B, 0x00000000, 0x00000008, 0x00000057, 0x00000000, 0x00000024, 0x00000002, 0xFD050F8E, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000009C4, 0x000001C2, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000024, 0x00000002, 0xFD050F8E, 0xFE363C80, 0x00000043, 0x00000005, TranslateGroup, 0x00000008, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x0000001D, 0x00000000, 0xFE363C80, 0x00000000, 0x00000043, 0x00000005, TranslateGroup, 0x00000045, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000044, 0x00000001, D_80240A74_AB9D24, 0x00000044, 0x00000001, D_80240CB8_AB9F68, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x0000000A, 0xFFFFFFF6, 0x00000028, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFD050F8E, 0xFE363C80, 0x00000043, 0x00000005, TranslateGroup, 0x0000000C, 0x00000000, 0xFD050F8E, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFF6, 0x0000000A, 0x00000028, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFD050F8E, 0xFE363C80, 0x00000043, 0x00000005, TranslateGroup, 0x0000000C, 0x00000000, 0xFD050F8E, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000003, 0x00000001, 0x00000016, 0x0000000C, 0x00000002, 0xFD050F8E, 0x000003E8, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000016, 0x00000013, 0x00000000, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x0000012C, 0x00000028, 0x00000002, 0xFD050F81, 0x00000003, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000003, 0x00000001, 0x00000017, 0x0000000C, 0x00000002, 0xFD050F8E, 0x0000047E, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000017, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x00000000, 0x00000044, 0x00000001, D_80240384_AB9634, 0x00000044, 0x00000001, D_80240500_AB97B0, 0x00000044, 0x00000001, D_80240950_AB9C00, 0x00000008, 0x00000001, 0x0000000A, 0x00000044, 0x00000001, D_80240624_AB98D4, 0x00000044, 0x00000001, D_80240710_AB99C0, 0x00000044, 0x00000001, D_80240834_AB9AE4, 0x00000008, 0x00000001, 0x00000096, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802411B8_ABA468
.word 0x00000024, 0x00000002, 0xFD050F81, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x00000036, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000028A, 0x00000028, 0x00000005, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000005, TranslateGroup, 0x0000006E, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000258, 0x0000028A, 0x00000019, 0x00000005, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000005, TranslateGroup, 0x0000006E, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x0000028A, 0x00000258, 0x00000023, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000005, TranslateGroup, 0x0000006E, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, PlaySound, 0x00000037, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000190, 0x0000001E, 0x00000005, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000070, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x0000015E, 0x00000190, 0x0000000C, 0x00000005, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000005, TranslateGroup, 0x00000070, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000190, 0x0000015E, 0x00000011, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000005, TranslateGroup, 0x00000070, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000002, PlaySound, 0x00000038, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x000000C8, 0x00000014, 0x00000005, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000096, 0x000000C8, 0x00000019, 0x00000005, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x000000C8, 0x00000096, 0x00000023, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000027, 0x00000002, 0xFE363C80, 0xFD050F81, 0x00000043, 0x00000005, TranslateGroup, 0x00000072, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000003, EnableGroup, 0x0000002F, 0x00000000, 0x00000043, 0x00000004, SetPlayerPos, 0x00000000, 0x00000000, 0x000007D0, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x80000057, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x000001C2, 0xF24A8280, 0x00000043, 0x00000005, ShakeCam, 0x00000000, 0x00000000, 0x00000064, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000032, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000002D, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x00000066, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x0000001E, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x00000066, 0x0000002D, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateGroup, 0x00000066, 0xFE363C80, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000066, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000002D, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000001E, 0x0000001E, 0x00000001, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x00000069, 0xFE363C80, 0x00000000, 0x00000000, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000064, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x00000069, 0x0000001E, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000006, RotateGroup, 0x00000069, 0xFE363C80, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000003, EnableGroup, 0x00000069, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000004B, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000064, 0x00000064, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000006B, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, PlaySound, 0x00000035, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000001E, 0x00000032, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000050, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000028, 0x00000028, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000052, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000014, 0x00000032, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000056, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x0000000A, 0x00000023, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x00000059, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFEC, 0x00000032, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000005B, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0xFFFFFFF6, 0x00000032, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateGroup, 0x0000005D, 0x00000000, 0xFE363C80, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000044, 0x00000001, D_802411B8_ABA468, 0x00000046, 0x00000001, D_80240DEC_ABA09C, 0x00000043, 0x00000003, GotoMap, 0x80241FCC, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
