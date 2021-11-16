.include "macro.inc"

.section .data

dlabel D_802400B0_B025A0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000010, 0x00000024, 0x00000002, 0xFE363C83, 0x00000012, 0x00000044, 0x00000001, ExitDoubleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80240380, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240154_B02644
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x00000007, 0x00000024, 0x00000002, 0xFE363C82, 0x00000022, 0x00000024, 0x00000002, 0xFE363C83, 0x00000024, 0x00000044, 0x00000001, ExitDoubleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80240388, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802401F8_B026E8
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000010, 0x00000024, 0x00000002, 0xFE363C83, 0x00000012, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0x00000022, 0x00000024, 0x00000002, 0xFE363C83, 0x00000024, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001A, 0x00000043, 0x00000002, SetSpriteShading, 0x00050006, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000044, 0x00000001, 0x80240060, 0x00000043, 0x00000002, UseDoorSounds, 0x00000002, 0x00000047, 0x00000005, D_802400B0_B025A0, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240154_B02644, 0x00000100, 0x00000007, 0x00000001, 0x00000000, 0x00000044, 0x00000001, D_802401F8_B026E8, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
