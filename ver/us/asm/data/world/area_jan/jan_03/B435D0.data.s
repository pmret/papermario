.include "macro.inc"

.section .data

dlabel D_8024EA00_B435D0
.word 0x00000043, 0x00000003, GotoMap, 0x8024FB90, 0x00000004, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024EA30_B43600
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetCamTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024EA98_B43668
.word 0x00000043, 0x00000001, func_80242FA0_B37B70, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000006, 0x00000008, 0x00000001, 0x00000001, 0x00000045, 0x00000002, D_8024EA30_B43600, 0xFE363C8A, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7AE7, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFDD4, 0x0000012C, 0xFFFFFF3D, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000004, func_802D2884, 0xFFFFFD8A, 0xFFFFFFCE, 0x00000000, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010008, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7E80, 0x00000043, 0x00000005, PlayerJump2, 0xFFFFFDA7, 0x00000178, 0xFFFFFF97, 0x0000001E, 0x00000043, 0x00000002, SetPlayerAnimation, 0x00010002, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8406315, 0x00000000, 0x0000000A, 0x00000002, 0xF840630E, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000B, 0x00000002, 0xFE363C80, 0x00000003, 0x00000024, 0x00000002, 0xF8406315, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x0000000A, MakeEntity, Entity_BlueWarpPipe, 0xFFFFFDE4, 0x00000000, 0x000000C3, 0x0000001E, 0x00000003, D_8024EA00_B435D0, 0x00000795, 0x80000000, 0x00000043, 0x00000007, MakeEntity, Entity_SavePoint, 0x00000064, 0x0000003C, 0xFFFFFFE7, 0x00000000, 0x80000000, 0x00000043, 0x00000007, MakeEntity, 0x802EAA30, 0xFFFFFDD4, 0x00000000, 0xFFFFFF3D, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_8024EA98_B43668, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
