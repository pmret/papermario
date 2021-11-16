.include "macro.inc"

.section .data

dlabel D_802409F0_D55080
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C81, 0x00000011, 0x00000024, 0x00000002, 0xFE363C82, 0x00000010, 0x00000024, 0x00000002, 0xFE363C83, 0x00000001, 0x00000044, 0x00000001, ExitSingleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x802414B0, 0x00000004, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A94_D55124
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000024, 0x00000002, 0xFE363C81, 0x0000000B, 0x00000024, 0x00000002, 0xFE363C82, 0x00000012, 0x00000024, 0x00000002, 0xFE363C83, 0x00000014, 0x00000044, 0x00000001, ExitDoubleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x802414B8, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B38_D551C8
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000024, 0x00000002, 0xFE363C81, 0x00000022, 0x00000024, 0x00000002, 0xFE363C82, 0x0000002C, 0x00000024, 0x00000002, 0xFE363C83, 0x0000002E, 0x00000044, 0x00000001, ExitDoubleDoor, 0x00000008, 0x00000001, 0x00000011, 0x00000043, 0x00000003, GotoMap, 0x802414C0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240BDC_D5526C
.word 0x00000047, 0x00000005, D_802409F0_D55080, 0x00000100, 0x00000011, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240A94_D55124, 0x00000100, 0x0000000B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240B38_D551C8, 0x00000100, 0x00000022, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C40_D552D0
.word 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000010, 0x00000024, 0x00000002, 0xFE363C83, 0x00000001, 0x00000046, 0x00000001, EnterSingleDoor, 0x00000016, 0x00000001, 0x00000001, 0x00000024, 0x00000002, 0xFE363C82, 0x00000012, 0x00000024, 0x00000002, 0xFE363C83, 0x00000014, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000016, 0x00000001, 0x00000002, 0x00000024, 0x00000002, 0xFE363C82, 0x0000002C, 0x00000024, 0x00000002, 0xFE363C83, 0x0000002E, 0x00000046, 0x00000001, EnterDoubleDoor, 0x00000023, 0x00000000, 0x00000044, 0x00000001, D_80240BDC_D5526C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x00000015, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000018, 0x00000018, 0x00000028, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x80241498, 0x00000046, 0x00000001, 0x802410C0, 0x00000044, 0x00000001, 0x802409B0, 0x0000000A, 0x00000002, 0xF8406159, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000014, 0x7FFFFE00, 0x00000043, 0x00000003, EnableModel, 0x0000000A, 0x00000000, 0x00000013, 0x00000000, 0x00000044, 0x00000001, D_80240C40_D552D0, 0x00000008, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
