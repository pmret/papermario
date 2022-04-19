.include "macro.inc"

.section .data

dlabel D_80242C80_B75D30
.word 0x00000043, 0x00000007, MakeEntity, 0x802BC7AC, 0x00000082, 0x00000000, 0xFFFFFF92, 0x000000AA, 0x80000000, 0x00000043, 0x00000007, MakeEntity, D_802BCBD8_E31528, 0xFFFFFEA2, 0x0000001E, 0xFFFFFFC9, 0x00000019, 0x80000000, 0x00000043, 0x00000008, MakeEntity, 0x802EA588, 0xFFFFFECA, 0x0000005A, 0xFFFFFFE7, 0x00000000, 0x00000088, 0x80000000, 0x00000043, 0x00000002, AssignBlockFlag, 0xF8406062, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00420000, 0x00420003, 0x00420005, 0x00420006, 0x00420007, 0x0042000F, 0x00420010, 0x0042001A, 0x0042001B, 0xFFFFFFFF

dlabel D_80242D38_B75DE8
.word 0x00420000, 0xFFFFFFFF

dlabel D_80242D40_B75DF0
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242DFC_B75EAC
.word 0x3FD9999A, 0x00000064, 0x00000001, 0x42C80000, 0x41F00000, 0x00000001, 0x40600000, 0x00000014, 0x00000001, 0x42F00000, 0x00000000, 0x00000001

dlabel D_80242E2C_B75EDC
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x0000000C, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000009, 0x00000043, 0x00000002, jan_12_SpearGuyAI_Main, D_80242DFC_B75EAC, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242E9C_B75F4C
.word 0x00000000, 0x00170016, 0x00000000, 0x00000000, D_80242E2C_B75EDC, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00100000

dlabel D_80242EC8_B75F78
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000016, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000028, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x00000000, 0x00000043, 0x00000001, jan_12_MeleeHitbox_Control, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242F70_B76020
.word 0x00000000, 0x00080014, 0x00000000, 0x00000000, D_80242EC8_B75F78, 0x00000000, 0x00000000, D_80242D40_B75DF0, 0x00000000, 0x00000000, 0x00100008

dlabel D_80242F9C_B7604C
.word 0x00000000, D_80242E9C_B75F4C, 0x43250000, 0x00000000, 0x41700000, 0x00400D00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008F, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x000000A5, 0x00000000, 0x0000000F, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000A5, 0x00000000, 0x0000000F, 0x00000096, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00420003, 0x00420005, 0x00420006, 0x00420006, 0x00420003, 0x00420003, 0x00420007, 0x00420007, 0x0042001A, 0x0042001B, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80242F70_B76020, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00420003, 0x00420005, 0x00420006, 0x00420006, 0x00420003, 0x00420003, 0x00420007, 0x00420007, 0x0042001A, 0x0042001B, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00420003, 0x00000000, 0x00000000, D_80242D38_B75DE8, 0x00000000, 0x00000002, D_80242F9C_B7604C, 0x14060007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
