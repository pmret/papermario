.include "macro.inc"

.section .data

glabel D_802406F0_986BD0
.word 0x00000000

glabel D_802406F4_986BD4
.word 0x0000004D, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_802D5830, 0x00000002, 0x00000008, 0x00000001, 0x00000028, 0x00000043, 0x00000004, ShowGotItem, 0xFE363C80, 0x00000000, 0x00000000, 0x00000043, 0x00000002, func_802D5830, 0x00000000, 0x00000002, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024075C_986C3C
.word 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x0000000B, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000046, 0x00000001, D_802406F4_986BD4, 0x00000013, 0x00000000, 0x00000014, 0x00000001, 0xFE363C8B, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, AddItem, 0xFE363C8A, 0xFE363C80, 0x00000016, 0x00000001, 0x00000001, 0x00000043, 0x00000002, AddKeyItem, 0xFE363C8A, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000003, AddBadge, 0xFE363C8A, 0xFE363C80, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024083C_986D1C
.word 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x00000031, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000032, 0x7FFFFE00, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_8024087C_986D5C
.word 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000031, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x00000032, 0x7FFFFE00, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_802408BC_986D9C
.word 0x0000000A, 0x00000002, 0xF8405F04, 0x00000000, 0x00000046, 0x00000001, D_8024083C_986D1C, 0x00000005, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF8405F04, 0x00000001, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000002, PartnerIsFlying, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000056, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000008, NpcFlyTo, 0xFFFFFFFC, 0xFFFFFF22, 0xFFFFFEA5, 0xFFFFFDED, 0x00000014, 0x00000000, 0x00000000, 0x00000043, 0x00000004, InterpNpcYaw, 0xFFFFFFFC, 0x00000046, 0x00000000, 0x00000005, 0x00000001, 0x00000000, 0x0000000A, 0x00000002, 0xF5DE0180, 0xFFFFFFC5, 0x00000007, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000057, 0x00000000, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000003C, 0x00000044, 0x00000001, 0x8024053C, 0x00000043, 0x00000004, ShowMessageAtScreenPos, 0x001D017D, 0x000000A0, 0x00000028, 0x00000043, 0x00000001, func_802402BC_98679C, 0x00000024, 0x00000002, 0xF5DE0180, 0xFFFFFFC5, 0x00000013, 0x00000000, 0x00000046, 0x00000001, D_8024087C_986D5C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240A5C_986F3C
.word 0x00000024, 0x00000002, 0xFE363C8A, 0x000000F7, 0x00000024, 0x00000002, 0xFE363C8B, 0x00000002, 0x00000024, 0x00000002, 0xF8405F05, 0x00000001, 0x00000046, 0x00000001, D_8024075C_986C3C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240AA8_986F88
.word 0x00000024, 0x00000002, 0xF8405F00, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE0C, 0xFFFFFF62, 0xFFFFFE9A, 0xFFFFFDCE, 0x0000011B, 0x00000005, D_80000000, 0x00000043, 0x00000002, AssignFlag, 0xF8405F04, 0x00000044, 0x00000001, D_802408BC_986D9C, 0x0000000A, 0x00000002, 0xF8405F00, 0x00000000, 0x00000043, 0x00000007, MakeEntity, 0x802EA19C, 0xFFFFFEEE, 0xFFFFFE7A, 0xFFFFFDFB, 0x00000073, D_80000000, 0x00000043, 0x00000002, AssignScript, D_80240AA8_986F88, 0x00000013, 0x00000000, 0x00000043, 0x00000008, MakeEntity, 0x802EAE30, 0x00000032, 0xFFFFFF10, 0xFFFFFDE9, 0x000000DE, 0x00000000, D_80000000, 0x00000043, 0x00000002, AssignFlag, 0xF8405F05, 0x00000043, 0x00000002, AssignScript, D_80240A5C_986F3C, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE09, 0xFFFFFEBD, 0xFFFFFFD4, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE1F, 0xFFFFFEBD, 0xFFFFFF7E, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE63, 0xFFFFFEBD, 0xFFFFFEDE, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE9A, 0xFFFFFEBD, 0xFFFFFE9A, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFF2D, 0xFFFFFEBD, 0xFFFFFE35, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFF7E, 0xFFFFFEBD, 0xFFFFFE1A, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE09, 0xFFFFFF3F, 0xFFFFFFD4, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE1F, 0xFFFFFF3F, 0xFFFFFF7E, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE63, 0xFFFFFF3F, 0xFFFFFEDE, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE9A, 0xFFFFFF3F, 0xFFFFFE9A, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFF2D, 0xFFFFFF3F, 0xFFFFFE35, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFF7E, 0xFFFFFF3F, 0xFFFFFE1A, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE09, 0xFFFFFFC1, 0xFFFFFFD4, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE1F, 0xFFFFFFC1, 0xFFFFFF7E, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE63, 0xFFFFFFC1, 0xFFFFFEDE, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFE9A, 0xFFFFFFC1, 0xFFFFFE9A, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFF2D, 0xFFFFFFC1, 0xFFFFFE35, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x0000000F, PlayEffect, 0x00000020, 0x00000001, 0xFFFFFF7E, 0xFFFFFFC1, 0xFFFFFE1A, 0xF24A7BB4, 0xFE363C80, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000
