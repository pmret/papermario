.include "macro.inc"

.section .data

dlabel D_802445D0_A3DAB0
.word 0x00000000

dlabel D_802445D4_A3DAB4
.word 0x00000000

dlabel D_802445D8_A3DAB8
.word 0x00000024, 0x00000002, 0xFE363C89, 0xFE363C81, 0x00000043, 0x00000001, ShowKeyChoicePopup, 0x00000024, 0x00000002, 0xFE363C8A, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x0000001C, 0x00000000, 0x00000043, 0x00000002, RemoveKeyItemAt, 0xFE363C81, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000004, hos_06_AddPlayerHandsOffset, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000042, 0x00000002, 0xFE363C80, 0x00050000, 0x00000043, 0x00000007, MakeItemEntity, 0xFE363C80, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00060005, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000002, RemoveItemEntity, 0xFE363C80, 0x00000023, 0x00000000, 0x00000043, 0x00000002, func_80240FD0_A3A4B0, 0xFE363C8A, 0x00000043, 0x00000001, CloseChoicePopup, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024471C_A3DBFC
.word 0x00000043, 0x00000002, func_80241008_A3A4E8, 0xFE363C80, 0x0000004E, 0x00000006, D_802445D8_A3DAB8, 0x00000010, 0x00000000, D_80246430_8E0530, 0x00000000, 0x00000001, 0x00000043, 0x00000002, func_80240F7C_A3A45C, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel dup_hos_06_varStash
.word 0x00000000

dlabel D_80244770_A3DC50
.word 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000001, 0x00000010, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802447D0_A3DCB0
.byte 0x05, 0x14, 0x1E, 0x00

dlabel D_802447D4_A3DCB4
.word 0x00220001

dlabel D_802447D8_A3DCB8
.word 0x0000010A, 0xFFFFFFF3, 0x00220002, 0x0000010C, 0x0000002B, 0x00220004, 0x0000012F, 0xFFFFFFB6, 0x00220003, 0x000000E1, 0xFFFFFFB6, 0x00220005, 0x000000EB, 0xFFFFFFCB, 0x00220007, 0x0000012E, 0xFFFFFFDF, 0x00220008, 0x000000E4, 0xFFFFFFA7, 0x00220006, 0x000000EF, 0x00000019, 0x00220000, 0x00000123, 0x0000003F, 0x00220009, 0x00000124, 0xFFFFFFC5, 0x0022000B, 0x00000109, 0xFFFFFFA7, 0x0022000C, 0x0000010B, 0x00000029, 0x0022000D, 0x000000E0, 0xFFFFFFF3, 0x00220011, 0x00000107, 0xFFFFD8F0, 0x0022000E, 0x000000E8, 0xFFFFFFB9, 0x0022000F, 0x00000117, 0x0000000B, 0x00220010, 0x00000108, 0x00000029, 0x00220012, 0x000000EE, 0xFFFFFFB6, 0x0022000A, 0x00000126, 0x0000002B, 0x00220013, 0x000000E9, 0xFFFFFFCB, 0x00220016, 0x000000ED, 0xFFFFFFD8, 0x00220041, 0x00000104, 0xFFFFFFA7, 0x00220014, 0x00000106, 0x0000004D, 0x00220017, 0x00000129, 0xFFFFFFCB, 0x00220018, 0x00000132, 0xFFFFFFF6, 0x00220019, 0x00000133, 0x0000005E, 0x0022001A, 0x000000E7, 0xFFFFFFCE, 0x0022001B, 0x00000134, 0xFFFFD8F0, 0x0022001D, 0x000000F8, 0xFFFFFFCE, 0x0022001E, 0x00000135, 0xFFFFFFA7, 0x00220020, 0x000000FF, 0x00002712, 0x00220021, 0x00000136, 0x0000000B, 0x00220022, 0x00000140, 0x00002712, 0x00220023, 0x00000141, 0x0000002B, 0x00220024, 0x00000105, 0x00002712, 0x00220025, 0x00000138, 0x0000002B, 0x00220026, 0x000000E3, 0xFFFFFFCB, 0x00220027, 0x00000116, 0x0000004D, 0x00220028, 0x00000113, 0x0000004D, 0x00220029, 0x000000F4, 0x00000007, 0x0022002A, 0x000000E2, 0x00002712, 0x0022002B, 0x0000013C, 0xFFFFFFF6, 0x0022002C, 0x000000F5, 0x00002712, 0x00220038, 0x00000100, 0x00002712, 0x00220034, 0x000000FA, 0xFFFFFFF6, 0x00220035, 0x000000EC, 0x00000019, 0x00220036, 0x000000E5, 0xFFFFFFC2, 0x0022002F, 0x00000112, 0xFFFFD8F0, 0x0022002D, 0x00000111, 0xFFFFFFF3, 0x0022002E, 0x0000010D, 0xFFFFFFCB, 0x00220030, 0x000000F9, 0xFFFFFFDF, 0x00220037, 0x000000F2, 0x00002712, 0x00220031, 0x00000130, 0x00000029, 0x00220032, 0x0000013A, 0xFFFFFFB9, 0x00220039, 0x000000F1, 0x00002712, 0x00220033, 0x000000FB, 0xFFFFFFF6, 0x0022003A, 0x00000114, 0x0000003F, 0x0022003B, 0x000000F7, 0xFFFFFFC2, 0x0022003C, 0x000000F3, 0x00002712, 0x00220042, 0x000000FC, 0x00002712, 0x00220043, 0x00000103, 0xFFFFFFBA, 0x00220044, 0x0000011A, 0x00002712, 0x00220045, 0x0000011B, 0x00002712, 0x00220046, 0x000000FD, 0x00002712, 0x0022004A, 0x0000011F, 0xFFFFFFB6, 0x00220048, 0x0000011E, 0xFFFFFFF6, 0x0022004B, 0x0000011D, 0xFFFFD8F0, 0x00220049, 0x000000FE, 0x00002712, 0x0022004E, 0x000000E6, 0xFFFFFFB6, 0x0022004C, 0x0000011C, 0xFFFFFFBA, 0x0022004D, 0x00000120, 0x0000000F, 0x00220015, 0x00000143, 0xFFFFFFF3, 0x0022003D, 0x00000145, 0xFFFFFFCB, 0x0022003E, 0x00000146, 0xFFFFD8F0, 0x0022003F, 0x00000147, 0x0000003F, 0x00220040, 0x00000148, 0xFFFFFFBA, 0x00220047, 0x00000144, 0x00002712, 0x0022001C, 0x0000014A, 0x00000007, 0x0022001F, 0x0000014D, 0x00000007

dlabel D_80244B88_A3E068
.word 0x0022004F

dlabel D_80244B8C_A3E06C
.word 0xF8405D31, 0xFFFFFFC5, 0x00220050, 0xF8405D32, 0xFFFFFFD8, 0x00220051, 0xF8405D33, 0x00000018, 0x00220052, 0xF8405D34, 0x0000003D, 0x00220053, 0xF8405D35, 0x0000000F, 0x00220054, 0xF8405E51, 0xFFFFFFC5, 0x00220055, 0xF8405EBD, 0xFFFFFFB5, 0x00220056, 0xF8405F07, 0xFFFFFFC2, 0x00220057, 0xF8405F96, 0xFFFFFFE1, 0x00220058, 0xF840602A, 0xFFFFFFF6, 0x00220059, 0xF840607E, 0x0000000B, 0x0022005A, 0xF84060B0, 0x00000018, 0x0022005B, 0xF84060B1, 0x00000018, 0x0022005C, 0xF84060FA, 0x0000002B, 0x0022005D, 0xF84060FB, 0x0000002B, 0x0022005E, 0xF8406131, 0x0000003F

dlabel D_80244C48_A3E128
.word 0x0022005F

dlabel D_80244C4C_A3E12C
.word 0xF8405BCA, 0xFFFFD8F0, 0x00220060, 0xF8405BD2, 0xFFFFD8F0, 0x00220061, 0xF8405BD6, 0xFFFFFFD8, 0x00220062, 0xF8405BD8, 0xFFFFFFD8, 0x00220063, 0xF8405BDA, 0xFFFFFFD8, 0x00220064, 0xF8405CAD, 0x0000000F, 0x00220065, 0xF8405CA7, 0xFFFFFFD8, 0x00220066, 0xF8405CA9, 0xFFFFFFD8, 0x00220067, 0xF8405CAA, 0xFFFFFFD8, 0x00220068, 0xF8405CAC, 0xFFFFFFD8, 0x00220069, 0xF8405CAE, 0xFFFFD8F0, 0x0022006A, 0xF8405D9A, 0xFFFFFFD8, 0x0022006B, 0xF8405D9B, 0xFFFFFFD8, 0x0022006C, 0xF8405D9C, 0xFFFFFFD8, 0x0022006D, 0xF8405DA0, 0xFFFFD8F0, 0x0022006E, 0xF8405D14, 0xFFFFFFC5, 0x0022006F, 0xF8405DC4, 0xFFFFFF9D, 0x00220070, 0xF8405DDE, 0xFFFFFFD8, 0x00220071, 0xF8405DE0, 0xFFFFFFD8, 0x00220072, 0xF8405DE1, 0xFFFFFFD8, 0x00220073, 0xF8405DC3, 0xFFFFFFA4, 0x00220074, 0xF8405DD1, 0xFFFFFFA4, 0x00220075, 0xF8405E2F, 0xFFFFFFB9, 0x00220076, 0xF8405E4D, 0xFFFFFFD8, 0x00220077, 0xF8405E30, 0xFFFFFFB9, 0x00220078, 0xF8405E9C, 0xFFFFFFD8, 0x00220079, 0xF8405E74, 0xFFFFFFD8, 0x0022007A, 0xF8405EF5, 0xFFFFFFC2, 0x0022007B, 0xF8405F41, 0xFFFFFFD8, 0x0022007C, 0xF8405F44, 0xFFFFFFD8, 0x0022007D, 0xF8405F4C, 0xFFFFFFD8, 0x0022007E, 0xF8405F54, 0xFFFFFFD8, 0x0022007F, 0xF8405F50, 0xFFFFFFD8, 0x00220080, 0xF8405F25, 0xFFFFFFD8, 0x00220081, 0xF8405F7B, 0xFFFFFFDF, 0x00220082, 0xF8405F92, 0xFFFFFFDF, 0x00220083, 0xF8405F9A, 0xFFFFFFDF, 0x00220084, 0xF8405FEC, 0xFFFFFFF6, 0x00220085, 0xF8406026, 0xFFFFFFF6, 0x00220086, 0xF8406027, 0xFFFFFFF6, 0x00220087, 0xF8406028, 0xFFFFFFF6, 0x00220088, 0xF8406029, 0xFFFFFFF6, 0x00220089, 0xF8405FED, 0xFFFFFFF6, 0x0022008A, 0xF8406016, 0xFFFFFFF6, 0x0022008B, 0xF8406075, 0x0000000B, 0x0022008C, 0xF8406076, 0x0000000B, 0x0022008D, 0xF840604D, 0x0000000B, 0x0022008E, 0xF8406064, 0x0000000B, 0x0022008F, 0xF8406082, 0x0000000B, 0x00220090, 0xF84060BA, 0x00000019, 0x00220091, 0xF84060BB, 0x00000019, 0x00220092, 0xF84060EC, 0x0000002B, 0x00220093, 0xF84060FC, 0x0000002B, 0x00220094, 0xF84060FE, 0x0000002B, 0x00220095, 0xF84060EB, 0x0000002B, 0x00220096, 0xF84060FF, 0x0000002B, 0x00220097, 0xF84060E5, 0x0000002B, 0x00220098, 0xF8406138, 0x0000003F, 0x00220099, 0xF840611C, 0x0000003F, 0x0022009A, 0xF8406125, 0x0000003F, 0x0022009B, 0xF8406162, 0x0000004D, 0x0022009C, 0xF8406166, 0x0000004D, 0x0022009D, 0xF8406168, 0x0000004D

dlabel D_80244F3C_A3E41C
.word 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x0000007C, 0x00000002, 0x00000008, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00B00008, 0x00000043, 0x00000002, GetModelCenter, 0x0000007E, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000006, PlaySoundAt, 0x00000207, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000052, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7E80, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF4ACD481, 0xFE363C8F, 0x00000043, 0x00000003, EnableModel, 0x0000008C, 0x00000000, 0x00000043, 0x00000003, EnableModel, 0x0000008E, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_802418E8_A3ADC8, 0x00000057, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0x0000007E, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFEC, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetCamPosA, 0x00000000, 0xF2490C80, 0xF24AC420, 0x00000043, 0x00000003, GetCamDistance, 0x00000000, 0xFE363C80, 0x0000000D, 0x00000002, 0xFE363C80, 0x00000000, 0x00000026, 0x00000002, 0xFE363C80, 0xF24EECE7, 0x00000012, 0x00000000, 0x00000026, 0x00000002, 0xFE363C80, 0xF246081A, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xFE363C80, 0x00000043, 0x00000004, GetCamPitch, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000026, 0x00000002, 0xFE363C81, 0xF24A4E80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x0000000F, PlayEffect, 0x00000053, 0x00000000, 0xFFFFFED6, 0x00000015, 0xFFFFFEB6, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF4ACD482, 0xFE363C8F, 0x00000043, 0x00000002, GetModelCenter, 0x0000007E, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x0000000F, PlayEffect, 0x00000051, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000001, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF4ACD483, 0xFE363C8F, 0x00000043, 0x0000000F, PlayEffect, 0x00000051, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000001, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF4ACD484, 0xFE363C8F, 0x00000043, 0x0000000F, PlayEffect, 0x00000051, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000001, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF4ACD485, 0xFE363C8F, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80241CCC_A3B1AC, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000032, 0x00000043, 0x00000002, GetModelCenter, 0x0000007E, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000006, PlaySoundAt, 0x00000208, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000052, 0x00000005, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7C80, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000043, 0x00000002, GetModelCenter, 0x0000007E, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000006, PlaySoundAt, 0x00000208, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000052, 0x00000005, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7C80, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80241A58_A3AF38, 0x00000057, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0x0000007E, 0x00000027, 0x00000002, 0xFE363C81, 0x00000014, 0x00000043, 0x00000006, PlaySoundAt, 0x00000208, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x0000000F, PlayEffect, 0x00000052, 0x00000006, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0xF24A7C80, 0x00000014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000046, 0x00000043, 0x00000002, func_802D7B10, 0xF4ACD482, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000006, PlaySoundAt, 0x00000607, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000002, func_80241F98_A3B478, 0xF4ACD481, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, EnableModel, 0x0000008C, 0x00000001, 0x00000043, 0x00000003, EnableModel, 0x0000008E, 0x00000001, 0x00000043, 0x00000002, func_802D7B10, 0xF4ACD481, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80241B74_A3B054, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000002E, 0x00000043, 0x00000003, ResetCam, 0x00000000, 0xF24A8E80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00B00001, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000061, 0x00000000, 0x00000008, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000001, func_802411F0_A3A6D0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245620_A3EB00
.word 0x0000000A, 0x00000002, 0xF5DE02DC, 0x00000008, 0x0000000A, 0x00000002, 0xF8405D98, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080007, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0046, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0047, 0x00000024, 0x00000002, 0xF8405D98, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802456F4_A3EBD4
.word 0x00000027, 0xFFFFFFFF

dlabel D_802456FC_A3EBDC
.word 0x0000000A, 0x00000002, 0xF8405D98, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF8405D99, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, FindKeyItem, 0x00000027, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0048, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_802456F4_A3EBD4, 0x00000024, 0x00000002, 0xFE363C81, 0x00000000, 0x00000046, 0x00000001, D_8024471C_A3DBFC, 0x0000000B, 0x00000002, 0xFE363C80, 0xFFFFFFFF, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0049, 0x00000024, 0x00000002, 0xFE363C80, 0x00000071, 0x00000024, 0x00000002, 0xFE363C81, 0x00000001, 0x00000046, 0x00000001, D_80244770_A3DC50, 0x00000043, 0x00000002, AddKeyItem, 0x00000071, 0x00000024, 0x00000002, 0xF8405D99, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0048, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, func_802CF56C, 0x00000001, 0x00000043, 0x00000004, PlayerMoveTo, 0xFFFFFFCF, 0x00000000, 0x00000006, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000000, 0x00000000, 0x0000000A, 0x00000002, 0xFD050F8A, 0x00000000, 0x0000003E, 0x00000002, 0x00000014, 0xFD050F8A, 0x00000013, 0x00000000, 0x0000003C, 0x00000001, 0xFD050F8A, 0x0000000A, 0x00000002, 0xF9718936, 0x00000000, 0x00000024, 0x00000002, 0xF9718936, 0x00000001, 0x0000000A, 0x00000002, 0xF8405D97, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0038, 0x00000024, 0x00000002, 0xF8405D97, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0039, 0x00000013, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A003A, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, ShowChoice, 0x001E0011, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A003C, 0x00000043, 0x00000002, func_802CF56C, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, ShowCoinCounter, 0x00000001, 0x00000043, 0x00000002, ShowChoice, 0x001E0000, 0x00000043, 0x00000002, ShowCoinCounter, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000004, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A003C, 0x00000043, 0x00000002, func_802CF56C, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000003, func_802417EC_A3ACCC, 0xFE363C80, 0xFE363C81, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A003D, 0x00000043, 0x00000002, func_802CF56C, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000002, func_80241860_A3AD40, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A003E, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00007, 0x00B00007, 0x00000000, 0x000A0041, 0x00000046, 0x00000001, D_80244F3C_A3E41C, 0x00000043, 0x00000001, func_80241668_A3AB48, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00006, 0x00B00006, 0x00000000, 0x000A0042, 0x00000043, 0x00000002, func_802418A4_A3AD84, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0xFE363C81, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000063, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A003F, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00007, 0x00B00007, 0x00000000, 0x000A0041, 0x00000046, 0x00000001, D_80244F3C_A3E41C, 0x00000043, 0x00000001, func_8024126C_A3A74C, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00006, 0x00B00006, 0x00000000, 0x000A0043, 0x00000043, 0x00000002, func_802418A4_A3AD84, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0xFE363C81, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000063, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000006, ContinueSpeech, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0040, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00007, 0x00B00007, 0x00000000, 0x000A0041, 0x00000046, 0x00000001, D_80244F3C_A3E41C, 0x00000043, 0x00000001, func_802414E4_A3A9C4, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00006, 0x00B00006, 0x00000000, 0x000A0044, 0x00000043, 0x00000002, func_802418A4_A3AD84, 0x00000002, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0xFE363C81, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000063, 0x00000023, 0x00000000, 0x00000003, 0x00000001, 0x00000063, 0x00000043, 0x00000002, func_802CF56C, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00B00004, 0x00B00001, 0x00000000, 0x000A0045, 0x00000046, 0x00000001, D_802456FC_A3EBDC, 0x00000046, 0x00000001, D_80245620_A3EB00, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel dup2_hos_06_varStash
.word 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245EEC_A3F3CC
.word 0x0000010D, 0x00000083, 0x00000129, 0x00000111, 0x000000A2

dlabel D_80245F00_A3F3E0
.word 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000001A, 0x0000204A, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000050, 0x00000014, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x0000009A, 0xFE363C80, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245FB0_A3F490
.word 0x00000043, 0x00000005, MakeLerp, 0x00000050, 0x00000000, 0x00000014, 0x00000004, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000006, RotateGroup, 0x0000009A, 0xFE363C80, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000004, PlaySoundAtCollider, 0x0000001A, 0x0000204B, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246060_A3F540
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000046, 0x00000001, D_80245F00_A3F3E0, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000043, 0x00000001, func_8024228C_A3B76C, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00D4, 0x000000A0, 0x00000028, 0x0000001D, 0x00000001, 0x0000010D, 0x0000001D, 0x00000001, 0x00000129, 0x0000001D, 0x00000001, 0x00000111, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000043, 0x00000003, AddBadge, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000001, func_802424CC_A3B9AC, 0x00000020, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000001, func_80242534_A3BA14, 0x0000000E, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D00D5, 0x000000A0, 0x00000028, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000002, 0x00000043, 0x00000003, AddItem, 0xFE363C80, 0xFE363C81, 0x00000043, 0x00000001, func_802424CC_A3B9AC, 0x00000013, 0x00000000, 0x00000023, 0x00000000, 0x00000046, 0x00000001, D_80245FB0_A3F490, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80246060_A3F540, 0x00000100, 0x0000001A, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
