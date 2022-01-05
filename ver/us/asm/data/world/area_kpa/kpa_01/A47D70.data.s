.include "macro.inc"

.section .data

dlabel D_80240E10_A47D70
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40900000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_80240E40_A47DA0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kpa_01_UnkNpcAIMainFunc5, D_80240E10_A47D70, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240EB0_A47E10
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40E00000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

dlabel D_80240EE0_A47E40
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000003, 0x00000043, 0x00000002, kpa_01_UnkNpcAIMainFunc5, D_80240EB0_A47E10, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240F50_A47EB0
.word 0x3F800000, 0x00000014, 0x00000005, 0x42F00000, 0x00000000, 0x00000003, 0x40C00000, 0x00000000, 0x00000000, 0x43160000, 0x00000000, 0x00000001

dlabel D_80240F80_A47EE0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000006, 0x00000043, 0x00000002, kpa_01_UnkNpcAIMainFunc5, D_80240F50_A47EB0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240FF0_A47F50
.word 0x00000043, 0x00000001, kpa_01_func_80240814_97BE44, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0033000F, 0x00000043, 0x00000001, kpa_01_AwaitPlayerNearNpc, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00330000, 0x00000043, 0x00000001, kpa_01_func_802408B4_97BEE4, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, kpa_01_UnkNpcAIMainFunc5, D_80240E10_A47D70, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80240E40_A47DA0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80240FF0_A47F50, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80240EE0_A47E40, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000

dlabel D_80241168_A480C8
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, D_80240F80_A47EE0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

dlabel D_80241194_A480F4
.word 0x00000000, D_80241168_A480C8, 0x44D98000, 0xC3570000, 0x42700000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00040000, 0x000006CC, 0xFFFFFF29, 0x0000003C, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x000006CC, 0xFFFFFF29, 0x0000003C, 0x0000012C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00550004, 0x0055000C, 0x0055000E, 0x0055000E, 0x00550004, 0x00550004, 0x00550018, 0x00550018, 0x00550010, 0x00550016, 0x00550012, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80241384_A482E4
.word 0x00000001, D_80241168_A480C8, 0x43730000, 0x40A00000, 0x43660000, 0x00002C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008C, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980004, 0x3FFF2666, 0x4CCC0004, 0x3FFF3FFF, 0x3FFF0004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00040000, 0x000000F3, 0x00000005, 0x000000E6, 0x00000032, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000F3, 0x00000005, 0x000000E6, 0x0000012C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00550004, 0x0055000C, 0x0055000E, 0x0055000E, 0x00550004, 0x00550004, 0x00550018, 0x00550018, 0x00550010, 0x00550016, 0x00550012, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00550004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80241194_A480F4, 0x22000004, 0x00000001, D_80241384_A482E4, 0x22010004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
