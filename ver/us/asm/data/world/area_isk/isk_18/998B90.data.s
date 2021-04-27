.include "macro.inc"

.section .data

glabel D_80240C20_998B90
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40900000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

glabel D_80240C50_998BC0
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, func_80240394_998304, D_80240C20_998B90, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240CC0_998C30
.word 0x3F800000, 0x0000003C, 0x0000003C, 0x42B40000, 0x42200000, 0x00000001, 0x40E00000, 0x00000000, 0x00000000, 0x42C80000, 0x42200000, 0x00000001

glabel D_80240CF0_998C60
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000004, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000003, 0x00000043, 0x00000002, func_80240394_998304, D_80240CC0_998C30, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240D60_998CD0
.word 0x3F800000, 0x00000014, 0x00000005, 0x42F00000, 0x00000000, 0x00000003, 0x40C00000, 0x00000000, 0x00000000, 0x43160000, 0x00000000, 0x00000001

glabel D_80240D90_998D00
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000003, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000008, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000006, 0x00000043, 0x00000002, func_80240394_998304, D_80240D60_998CD0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240E00_998D70
.word 0x00000043, 0x00000001, isk_18_func_80240814_97BE44, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x0033000F, 0x00000043, 0x00000001, isk_18_AwaitPlayerNearNpc, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000001, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000200, 0x00000001, 0x00000043, 0x00000003, SetNpcAnimation, 0xFFFFFFFF, 0x00330000, 0x00000043, 0x00000001, isk_18_func_802408B4_97BEE4, 0x00000043, 0x00000002, SyncOverrideEnemyPos, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000002, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000007, 0x00000002, 0x00000043, 0x00000002, func_80240394_998304, D_80240C20_998B90, 0x00000002, 0x00000000, 0x00000001, 0x00000000

glabel D_80240EF4_998E64
.word 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80240C50_998BC0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000

glabel D_80240F20_998E90
.word 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80240E00_998D70, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x000A0000, 0x00000000, 0x00140016, 0x00000000, 0x00000000, D_80240CF0_998C60, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00110000, 0x00000000, 0x00180018, 0x00000000, 0x00000000, D_80240D90_998D00, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00190000

glabel D_80240FA4_998F14
.word 0x00000000, D_80240F20_998E90, 0xC3BA0000, 0xC42F0000, 0x43DB8000, 0x00000400, 0x00000000, 0x00000001, 0x00000B0E, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x3FFF2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x33326665, 0x3FFF0002, 0x33327FFF, 0x33320002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0xFFFFFE8C, 0xFFFFFD44, 0x000001B7, 0x00000028, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFE8C, 0xFFFFFD44, 0x000001B7, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330001, 0x00330003, 0x00330004, 0x00330004, 0x00330000, 0x00330000, 0x00330007, 0x00330007, 0x0033000C, 0x00330005, 0x0033000D, 0x00330000, 0x00330000, 0x00330000, 0x00330000, 0x00330000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80241194_999104
.word 0x00000001, D_80240F20_998E90, 0xC2680000, 0xC42F0000, 0x4413C000, 0x00000400, 0x00000000, 0x00000001, 0x00000B0B, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x3FFF2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x33326665, 0x3FFF0002, 0x33327FFF, 0x33320002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0xFFFFFFC6, 0xFFFFFD44, 0x0000024F, 0x00000028, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFC6, 0xFFFFFD44, 0x0000024F, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330001, 0x00330003, 0x00330004, 0x00330004, 0x00330000, 0x00330000, 0x00330007, 0x00330007, 0x0033000C, 0x00330005, 0x0033000D, 0x00330000, 0x00330000, 0x00330000, 0x00330000, 0x00330000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

glabel D_80241384_9992F4
.word 0x00000002, D_80240EF4_998E64, 0x43920000, 0xC4430000, 0x43F40000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x3FFF2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x33326665, 0x3FFF0002, 0x33327FFF, 0x33320002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00020000, 0x00000124, 0xFFFFFCF4, 0x000001E8, 0x00000028, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000124, 0xFFFFFCF4, 0x000001E8, 0x000000C8, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00330001, 0x00330003, 0x00330004, 0x00330004, 0x00330000, 0x00330000, 0x00330007, 0x00330007, 0x0033000C, 0x00330005, 0x0033000D, 0x00330000, 0x00330000, 0x00330000, 0x00330000, 0x00330000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80240FA4_998F14, 0x0B0F0009, 0x00000001, D_80241194_999104, 0x0B130009, 0x00000001, D_80241384_9992F4, 0x0B0C0009, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
