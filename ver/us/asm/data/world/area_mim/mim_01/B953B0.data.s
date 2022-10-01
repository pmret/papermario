.include "macro.inc"

.section .data

dlabel D_80241F70_B953B0
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802445D0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241FCC_B9540C
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802445D8, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242028_B95468
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802445D0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242084_B954C4
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000003, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802445E0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802420E0_B95520
.word 0x00000047, 0x00000005, D_80241F70_B953B0, 0x00080000, 0x00000001, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241FCC_B9540C, 0x00080000, 0x00000010, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242028_B95468, 0x00080000, 0x0000000B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242084_B954C4, 0x00080000, 0x00000006, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000000C, 0x00000043, 0x00000002, SetSpriteShading, 0x00070000, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x0000028A, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF8406337, 0x00000001, 0x00000024, 0x00000002, 0xF70F2E82, 0xF5DE022B, 0x00000043, 0x00000002, GetMapID, 0xF5DE022B, 0x00000046, 0x00000001, 0x80243CD8, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x802445B4, 0x00000046, 0x00000001, D_80242354_B95794, 0x00000046, 0x00000001, 0x80242C40, 0x00000024, 0x00000002, 0xFE363C80, D_802420E0_B95520, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, mim_01_SetForeverForestFog, 0x00000044, 0x00000001, 0x80241F30, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802422B0_B956F0
.word 0x00000043, 0x00000002, IsStartingConversation, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000001, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D017E, 0x000000A0, 0x00000028, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242354_B95794
.word 0x00000043, 0x00000007, MakeEntity, Entity_Signpost, 0xFFFFFED4, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_802422B0_B956F0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
