.include "macro.inc"

.section .data

dlabel D_80240D10_AF8660
.word 0x43F28000, 0x00000000, 0x41C80000, 0x43A50000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_802410C0_AF8A10, D_80240D10_AF8660, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00190014

dlabel D_80240D60_AF86B0
.word 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFF80, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x0000003F, 0x00000001, 0x00000007, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x0000003F, 0x00000001, 0x00000006, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xF5DE0180, 0x00000006, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000074, 0x00000000, 0x00000008, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240E10_AF8760
.word 0x0000005D, 0x00000011, 0x00000000, 0x0000005E, 0x00000012, 0x00000000, 0x0000005F, 0x00000013, 0x00000000, 0x00000061, 0x00000015, 0x00000000, 0x00000060, 0x00000016, 0x00000000, 0x00000062, 0x00000017, 0x00000000, 0x00000063, 0x00000018, 0x00000000, 0x00000064, 0x00000019, 0x00000000, 0x00000065, 0x00000010, 0x00000000, 0x00000066, 0x00000014, 0x00000000

dlabel D_80240E88_AF87D8
.word 0x00000000

dlabel D_80240E8C_AF87DC
.word 0x00000000

dlabel D_80240E90_AF87E0
.word 0x00000000

dlabel D_80240E94_AF87E4
.word 0x00000043, 0x00000002, func_80240000_AF7950, 0xFE363C80, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240EB8_AF8808
.word 0x00000000, 0x00000000, 0x00000000, ui_box_corners5_png, 0x31100810, 0x08100810, 0x08000000, 0x00000000, 0xFC617E60, 0xF5FFF578, 0xFC612660, 0xF5FFFF78, 0xFFB7B5FF, 0x7A593FFF

dlabel D_80240EF0_AF8840
.word 0x0A000064, 0x00420078, 0x001C0000, func_802400E4_AF7A34, 0x00000000, 0xFF000000, 0x00000002, 0x00000000, D_80240EB8_AF8808, 0x0B000020, 0x00B80100, 0x00200000, func_80240178_AF7AC8, 0x00000000, 0xFF000000, 0x00000002, 0x00000000, 0xFFFFFFFF

dlabel D_80240F38_AF8888
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000044, 0x00000001, ExitSingleDoor, 0x00000008, 0x00000001, 0x00000011, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFF80, 0x00000043, 0x00000003, GotoMap, 0x802461A8, 0x00000003, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GotoMap, 0x802461A0, 0x00000003, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241010_AF8960
.word 0x00000047, 0x00000005, D_80240F38_AF8888, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024103C_AF898C
.word 0x0000000A, 0x00000002, 0xF5DE0180, 0x00000006, 0x00000044, 0x00000001, 0x80243F14, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000044, 0x00000001, D_80241010_AF8960, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410C0_AF8A10
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001A, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000016, 0x00000001, 0xFFFFFF80, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x802416E4, 0x00000016, 0x00000001, 0x00000006, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80241AF4, 0x00000023, 0x00000000, 0x00000044, 0x00000001, D_80240D60_AF86B0, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000044, 0x00000001, D_8024103C_AF898C, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF5DE0180, 0x00000006, 0x00000043, 0x00000001, func_802401FC_AF7B4C, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
