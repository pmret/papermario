.include "macro.inc"

.section .data

glabel D_802405F0_B9BA70
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802424C0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024064C_B9BACC
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802424C8, 0x00000003, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802406A8_B9BB28
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000002, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802424D0, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240704_B9BB84
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000003, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x802424C0, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240760_B9BBE0
.word 0x00000047, 0x00000005, D_802405F0_B9BA70, 0x00080000, 0x00000001, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_8024064C_B9BACC, 0x00080000, 0x00000010, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_802406A8_B9BB28, 0x00080000, 0x0000000B, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80240704_B9BB84, 0x00080000, 0x00000006, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000000C, 0x00000043, 0x00000002, SetSpriteShading, 0x00070002, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x0000028A, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E82, 0xF5DE022B, 0x00000043, 0x00000002, GetMapID, 0xF5DE022B, 0x00000024, 0x00000002, 0xF9718882, 0x00000000, 0x00000046, 0x00000001, 0x80241EA0, 0x00000043, 0x00000003, MakeNpcs, 0x00000001, 0x802424A8, 0x00000046, 0x00000001, 0x802409B0, 0x00000024, 0x00000002, 0xFE363C80, D_80240760_B9BBE0, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000044, 0x00000001, 0x802405B0, 0x00000046, 0x00000001, 0x8024107C, 0x00000043, 0x00000001, mim_03_SetWorldAndEntityFog, 0x00000056, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000001, func_80240068_B9B4E8, 0x0000000C, 0x00000002, 0xFE363C80, 0x0000015E, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000012, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8680, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
