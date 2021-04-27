.include "macro.inc"

.section .data

glabel D_80240000_B022A0
.word 0x43A28000, 0x00000000, 0xC1F00000, 0x43870000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80240160_B02400, D_80240000_B022A0, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00190016

glabel D_80240050_B022F0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000044, 0x00000001, ExitSingleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x80240240, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802400F4_B02394
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000002, 0x00000024, 0x00000002, 0xFE363C83, 0xFFFFFFFF, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240160_B02400
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001A, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000002, UseDoorSounds, 0x00000000, 0x00000047, 0x00000005, D_80240050_B022F0, 0x00000100, 0x00000002, 0x00000001, 0x00000000, 0x00000044, 0x00000001, D_802400F4_B02394, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
