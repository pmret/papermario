.include "macro.inc"

.section .data

dlabel D_802462B0_C66FC0
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetCamTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246314_C67024
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000006, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, kzn_03_UnsetCamera0MoveFlag1, 0x00000045, 0x00000002, D_802462B0_C66FC0, 0xFE363C8A, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7D4D, 0x00000043, 0x00000005, PlayerJump, 0x0000014F, 0x00000122, 0x00000168, 0x00000028, 0x00000043, 0x00000003, SetPlayerFlagBits, 0x00000008, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000008, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000001, kzn_03_SetCamera0MoveFlag1, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246410_C67120
.word 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000003, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, kzn_03_UnsetCamera0MoveFlag1, 0x00000045, 0x00000002, D_802462B0_C66FC0, 0xFE363C8A, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7D4D, 0x00000043, 0x00000005, PlayerJump, 0x0000015E, 0x000001D6, 0x000000D2, 0x00000028, 0x00000043, 0x00000002, SetPlayerActionState, 0x0000000A, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000001, kzn_03_SetCamera0MoveFlag1, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802464F8_C67208
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000003, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000001, kzn_03_UnsetCamera0MoveFlag1, 0x00000045, 0x00000002, D_802462B0_C66FC0, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFD050F89, 0x00000000, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A801A, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFE2A, 0x0000029E, 0x00000047, 0x00000012, 0x00000012, 0x00000000, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7D4D, 0x00000043, 0x00000005, PlayerJump, 0xFFFFFE80, 0x00000366, 0xFFFFFFEA, 0x00000028, 0x00000013, 0x00000000, 0x00000043, 0x00000002, SetPlayerActionState, 0x0000000A, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000043, 0x00000001, kzn_03_SetCamera0MoveFlag1, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024663C_C6734C
.word 0x00000024, 0x00000002, 0xF5DE0180, 0x0000001D, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000007, MakeEntity, Entity_SavePoint, 0x0000016D, 0x00000212, 0x00000087, 0x00000000, 0x80000000, 0x00000043, 0x00000007, MakeItemEntity, 0x000000EC, 0x0000004B, 0x00000122, 0x000000EB, 0x00000011, 0xF84060B2, 0x00000043, 0x00000007, MakeEntity, Entity_BrickBlock, 0x000000D7, 0x000002E9, 0xFFFFFF97, 0x00000000, 0x80000000, 0x00000043, 0x00000007, MakeEntity, Entity_BrickBlock, 0x00000055, 0x00000302, 0xFFFFFF97, 0x00000000, 0x80000000, 0x00000043, 0x00000007, MakeItemEntity, 0x00000090, 0x00000055, 0x0000031B, 0xFFFFFF97, 0x0000000D, 0xF84060B3, 0x00000043, 0x00000008, MakeEntity, Entity_D_802EA564, 0x00000023, 0x000002DA, 0xFFFFFF97, 0x00000000, 0x00000157, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF84060B4, 0x00000043, 0x00000008, MakeEntity, Entity_D_802EA564, 0xFFFFFFF1, 0x000002DA, 0xFFFFFF97, 0x00000000, 0x00000157, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF84060B5, 0x00000043, 0x00000008, MakeEntity, Entity_D_802EA564, 0xFFFFFFBF, 0x000002DA, 0xFFFFFF97, 0x00000000, 0x00000157, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF84060B6, 0x00000043, 0x00000008, MakeEntity, Entity_D_802EA564, 0xFFFFFF8D, 0x000002DA, 0xFFFFFF97, 0x00000000, 0x00000157, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF84060B7, 0x0000000C, 0x00000002, 0xF5DE0180, 0x0000001D, 0x00000043, 0x00000007, MakeEntity, Entity_Hammer3Block, 0x000001EA, 0x000001D6, 0x000000D2, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_8024663C_C6734C, 0x00000056, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x0000000F, 0x00000002, 0xF5DE0180, 0x0000001D, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000032, 0x7FFFFE00, 0x00000057, 0x00000000, 0x00000012, 0x00000000, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000032, 0x7FFFFE00, 0x00000013, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EAA30, 0x000000A0, 0x0000001E, 0x0000015E, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80246314_C67024, 0x00000043, 0x00000007, MakeEntity, 0x802EAA30, 0x0000014F, 0x00000109, 0x00000168, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80246410_C67120, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_80242D38_C63A48, 0x00000057, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EAA30, 0xFFFFFE66, 0x00000285, 0x00000078, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_802464F8_C67208, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
