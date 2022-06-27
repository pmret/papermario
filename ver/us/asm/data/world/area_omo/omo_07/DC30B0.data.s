.include "macro.inc"

.section .data

dlabel omo_07_varStash
.word 0x00000000

dlabel D_80245E04_DC30B4
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, SetTimeFreezeMode, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245E6C_DC311C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000046, 0x00000001, D_80245E04_DC30B4, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8B, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, AddItem, 0xFE363C8A, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, AddBadge, 0xFE363C8A, 0xFE363C80, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245F4C_DC31FC
.word 0x00000024, 0x00000002, 0xFE363C8A, 0x00000023, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000001, 0x00000024, 0x00000002, 0xF8405FF6, 0x00000001, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFFC, 0x00000046, 0x00000001, D_80245E6C_DC311C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245FA8_DC3258
.word 0x00000024, 0x00000002, 0xFE363C8A, 0x000000FB, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000002, 0x00000024, 0x00000002, 0xF8405FF7, 0x00000001, 0x00000046, 0x00000001, D_80245E6C_DC311C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80245FF4_DC32A4
.word 0x00000024, 0x00000002, 0xFE363C8A, 0x000000FA, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000002, 0x00000024, 0x00000002, 0xF8405FF8, 0x00000001, 0x00000046, 0x00000001, D_80245E6C_DC311C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246040_DC32F0
.word 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetCamTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802460A8_DC3358
.word 0xFFFFFEAF, 0x00000050, 0xFFFFFFC9, 0xFFFFFE28, 0x00000000, 0x0000007F, 0xFFFFFF40, 0x00000000, 0x0000007F

dlabel D_802460CC_DC337C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000030, 0x00000001, D_802460A8_DC3358, 0x00000005, 0x00000001, 0xFE363C80, 0x00000033, 0x00000003, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000006, 0x00000000, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000003, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000005, 0x00000001, 0x00000004, 0x00000027, 0x00000002, 0xFE363C81, 0x0000000A, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000001, omo_07_UnsetCamera0MoveFlag1, 0x00000045, 0x00000002, D_80246040_DC32F0, 0xFE363C8A, 0x00000043, 0x00000002, SetPlayerJumpscale, 0xF24A7D4D, 0x00000043, 0x00000005, PlayerJump, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000028, 0x00000049, 0x00000001, 0xFE363C8A, 0x00000008, 0x00000001, 0x00000003, 0x00000043, 0x00000002, SetPlayerActionState, 0x00000000, 0x00000043, 0x00000001, omo_07_SetCamera0MoveFlag1, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024623C_DC34EC
.word 0x00000024, 0x00000002, 0xFE363C80, 0x00000001, 0x00000046, 0x00000001, D_802460CC_DC337C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246268_DC3518
.word 0x00000024, 0x00000002, 0xFE363C80, 0x00000002, 0x00000046, 0x00000001, D_802460CC_DC337C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80246294_DC3544
.word 0x00000024, 0x00000002, 0xFE363C80, 0x00000003, 0x00000046, 0x00000001, D_802460CC_DC337C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, D_802EAE30, 0x0000046A, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignChestFlag, 0xF8405FF6, 0x00000043, 0x00000002, AssignScript, D_80245F4C_DC31FC, 0x00000043, 0x00000008, MakeEntity, D_802EAE30, 0xFFFFFC72, 0x00000050, 0xFFFFFF9C, 0x00000000, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignChestFlag, 0xF8405FF7, 0x00000043, 0x00000002, AssignScript, D_80245FA8_DC3258, 0x00000043, 0x00000008, MakeEntity, D_802EAE30, 0x000002EE, 0x00000000, 0xFFFFFF9C, 0x00000000, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignChestFlag, 0xF8405FF8, 0x00000043, 0x00000002, AssignScript, D_80245FF4_DC32A4, 0x00000043, 0x00000008, MakeEntity, Entity_YellowBlock, 0x0000028A, 0x0000003C, 0xFFFFFFE2, 0x00000000, 0x00000157, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8405FF5, 0x00000043, 0x00000007, MakeEntity, 0x802BCB44, 0xFFFFFEB6, 0x00000000, 0x0000007F, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_8024623C_DC34EC, 0x00000043, 0x00000007, MakeEntity, 0x802BCB44, 0xFFFFFEFC, 0x00000000, 0x0000007F, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80246268_DC3518, 0x00000043, 0x00000007, MakeEntity, 0x802BCB44, 0xFFFFFF40, 0x00000050, 0xFFFFFF7C, 0x00000000, 0x80000000, 0x00000043, 0x00000002, AssignScript, D_80246294_DC3544, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000
