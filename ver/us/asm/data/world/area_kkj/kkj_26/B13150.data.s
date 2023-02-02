.include "macro.inc"

.section .data

dlabel D_80240030_B13150
.word 0x43EC0000, 0x41F00000, 0xC1D00000, 0x42B40000, 0x44070000, 0x41F00000, 0xC1A00000, 0x42B40000, 0x43C80000, 0x41F00000, 0xC1A00000, 0x42B40000, 0x43F18000, 0x41F00000, 0x41000000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_802402B8_B133D8, D_80240030_B13150, 0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80200000, 0x0019001B, 0x00000024, 0x00000002, 0xFE363C80, 0xF5DE01CE, 0x00000043, 0x00000001, func_80240000_B13120, 0x00000043, 0x00000002, PlaySound, 0x000000DC, 0x00000043, 0x00000004, GotoMapSpecial, 0x80240C30, 0x00000001, 0x0000000C, 0x00000008, 0x00000001, 0x00000064

dlabel D_80240100_B13220
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000026, 0x00000024, 0x00000002, 0xFE363C83, 0x00000023, 0x00000024, 0x00000002, 0xFE363C84, 0x00000027, 0x00000024, 0x00000002, 0xFE363C85, 0x00000024, 0x00000044, 0x00000001, 0x80285E9C, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80240C38, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802401C4_B132E4
.word 0x00000047, 0x00000005, D_80240100_B13220, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802401F0_B13310
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000026, 0x00000024, 0x00000002, 0xFE363C83, 0x00000023, 0x00000024, 0x00000002, 0xFE363C84, 0x00000027, 0x00000024, 0x00000002, 0xFE363C85, 0x00000024, 0x00000046, 0x00000001, 0x80285EC4, 0x00000044, 0x00000001, D_802401C4_B132E4, 0x00000016, 0x00000001, 0x00000001, 0x00000044, 0x00000001, 0x80240640, 0x00000016, 0x00000001, 0x00000002, 0x00000044, 0x00000001, 0x802403E0, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802402B8_B133D8
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001A, 0x00000043, 0x00000002, SetSpriteShading, 0x0005000A, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000058, 0x00000013, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000005, 0x00000043, 0x00000002, GetDemoState, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000000, 0x00000046, 0x00000001, 0x80240B78, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_802401F0_B13310, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
