.include "macro.inc"

.section .data

dlabel D_80240300_CD09C0
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024032C_CD09EC
.word 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000035, 0x00000024, 0x00000002, 0xFE363C83, 0x00000007, 0x00000024, 0x00000002, 0xFE363C84, 0x00000005, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C83, 0x0000000F, 0x00000024, 0x00000002, 0xFE363C84, 0x00000001, 0x00000013, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C85, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetNpcPos, 0x0000000B, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0xFE363C84, 0x00000006, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C85, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0xFFFFFFFF, 0x00000043, 0x00000005, SetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetNpcPos, 0x0000000B, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0xFE363C84, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000005, SetNpcPos, 0x0000000A, 0x00000000, 0x0000010E, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x0000000B, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x0000041A, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AA280, 0xF24A8A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x0000012C, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AB680, 0xF24A5280, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A9480, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x0000000A, 0x00CB0009, 0x00CB0009, 0x00000205, 0x001100C3, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000A, 0x00CB0009, 0x00000056, 0x00000000, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0x000003E8, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8E80, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, SetNpcJumpscale, 0x0000000A, 0xF24A7A80, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C81, 0x00000190, 0x00000043, 0x00000006, NpcJump0, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000043, 0x00000003, GotoMap, 0x80241768, 0x00000009, 0x00000008, 0x00000001, 0x00000046, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024079C_CD0E5C
.word 0x00000043, 0x00000003, func_802CDE68, 0x0000000B, 0x00000030, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0xFFFFFFE2, 0x0000001E, 0x00000014, 0x0000000B, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0x0000000B, 0x00000000, 0x00000000, 0xFE363C80, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000005, SetNpcPos, 0x0000000B, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x0000001E, 0xFFFFFFE2, 0x00000014, 0x0000000B, 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, SetNpcRotation, 0x0000000B, 0x00000000, 0x00000000, 0xFE363C80, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000005, SetNpcPos, 0x0000000B, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000000, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024094C_CD100C
.word 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000D, 0x00000002, 0xFE363C81, 0x000000DC, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000003, PlayerFaceNpc, 0x0000000A, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0x0000000A, 0xF24A7A80, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000028, 0x00000002, 0xFE363C81, 0x00000190, 0x00000043, 0x00000006, NpcJump0, 0x0000000A, 0xFE363C80, 0x00000113, 0xFE363C82, 0x0000001E, 0x00000045, 0x00000002, D_8024032C_CD09EC, 0xFE363C89, 0x00000005, 0x00000001, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xF97188A6, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000049, 0x00000001, 0xFE363C89, 0x00000043, 0x00000004, SetNpcFlagBits, 0x0000000A, 0x00000100, 0x00000001, 0x00000043, 0x00000005, GetNpcPos, 0x0000000A, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000006, NpcJump0, 0x0000000A, 0xFE363C80, 0x000001C2, 0xFE363C82, 0x0000001E, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000048, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240B28_CD11E8
.word 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x00000032, 0x00000043, 0x00000006, SpeakToPlayer, 0x0000000A, 0x00CB0007, 0x00CB0001, 0x00000205, 0x0011009A, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010021, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00080007, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000043, 0x00000006, SpeakToPlayer, 0x0000000A, 0x00CB0007, 0x00CB0001, 0x00000205, 0x0011009B, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000032, 0x00000018, 0x00000001, 0x00000035, 0x00000043, 0x00000006, SpeakToPlayer, 0x0000000A, 0x00CB0007, 0x00CB0001, 0x00000205, 0x0011009C, 0x00000018, 0x00000001, 0x00000039, 0x0000000A, 0x00000002, 0xF8406102, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x0000000A, 0x00CB0007, 0x00CB0001, 0x00000205, 0x0011009D, 0x00000024, 0x00000002, 0xF8406102, 0x00000001, 0x00000012, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x0000000A, 0x00CB0007, 0x00CB0001, 0x00000205, 0x0011009E, 0x00000013, 0x00000000, 0x0000001C, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x0000000A, 0x00CB0007, 0x00CB0001, 0x00000205, 0x0011009F, 0x00000023, 0x00000000, 0x00000024, 0x00000002, 0xF97188A6, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CD0_CD1390
.word 0x00000043, 0x00000004, SetNpcCollisionSize, 0x0000000A, 0x00000040, 0x00000028, 0x00000043, 0x00000003, EnableNpcShadow, 0x0000000A, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000035, 0x00000043, 0x00000005, SetNpcPos, 0x0000000A, 0x00000000, 0x0000010E, 0x00000000, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80240B28_CD11E8, 0x00000044, 0x00000001, D_8024032C_CD09EC, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x0000000A, 0x00000000, 0x000001C2, 0x00000000, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80240B28_CD11E8, 0x00000024, 0x00000002, 0xF97188A6, 0x00000000, 0x00000044, 0x00000001, D_8024094C_CD100C, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240DB4_CD1474
.word 0x00000043, 0x00000003, EnableNpcShadow, 0x0000000B, 0x00000000, 0x00000043, 0x00000003, SetNpcAnimation, 0x0000000B, 0x00CB0002, 0x00000043, 0x00000003, SetNpcPaletteSwapMode, 0x0000000A, 0x00000003, 0x00000043, 0x00000003, SetNpcPaletteSwapMode, 0x0000000B, 0x00000003, 0x00000043, 0x0000000A, SetNpcPaletteSwapping, 0x0000000A, 0x00000000, 0x00000001, 0x00000005, 0x00000005, 0x0000000D, 0x00000005, 0x00000000, 0x00000000, 0x00000043, 0x0000000A, SetNpcPaletteSwapping, 0x0000000B, 0x00000000, 0x00000001, 0x00000005, 0x00000005, 0x0000000D, 0x00000005, 0x00000000, 0x00000000, 0x0000000C, 0x00000002, 0xF5DE0180, 0x00000035, 0x00000043, 0x00000005, SetNpcPos, 0x0000000B, 0x00000000, 0x0000010E, 0xFFFFFFFB, 0x00000012, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x0000000B, 0x00000000, 0x000001C2, 0xFFFFFFFB, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, D_8024079C_CD0E5C, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240EE0_CD15A0
.word 0x0000000A, D_80240300_CD09C0, 0x00000000, 0x437A0000, 0x00000000, 0x00400D01, D_80240CD0_CD1390, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00000000, 0x00000000, 0x00000000, 0x001A00E1, 0x0000000B, D_80240300_CD09C0, 0x00000000, 0x437A0000, 0x00000000, 0x00008F01, D_80240DB4_CD1474, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00CB0001, 0x00000000, 0x00000000, 0x00000000, 0x001A00E1, 0x00000002, D_80240EE0_CD15A0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
