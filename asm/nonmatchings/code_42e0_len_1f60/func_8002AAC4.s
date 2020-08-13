.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8002AAC4
/* 005EC4 8002AAC4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 005EC8 8002AAC8 0080402D */  daddu $t0, $a0, $zero
/* 005ECC 8002AACC 00A0482D */  daddu $t1, $a1, $zero
/* 005ED0 8002AAD0 00C0502D */  daddu $t2, $a2, $zero
/* 005ED4 8002AAD4 00E0582D */  daddu $t3, $a3, $zero
/* 005ED8 8002AAD8 00061C00 */  sll   $v1, $a2, 0x10
/* 005EDC 8002AADC 00041400 */  sll   $v0, $a0, 0x10
/* 005EE0 8002AAE0 97AC003A */  lhu   $t4, 0x3a($sp)
/* 005EE4 8002AAE4 97AD003E */  lhu   $t5, 0x3e($sp)
/* 005EE8 8002AAE8 97AE0042 */  lhu   $t6, 0x42($sp)
/* 005EEC 8002AAEC 97AF0046 */  lhu   $t7, 0x46($sp)
/* 005EF0 8002AAF0 0062182A */  slt   $v1, $v1, $v0
/* 005EF4 8002AAF4 10600003 */  beqz  $v1, .L8002AB04
/* 005EF8 8002AAF8 AFBF0020 */   sw    $ra, 0x20($sp)
/* 005EFC 8002AAFC 0080502D */  daddu $t2, $a0, $zero
/* 005F00 8002AB00 00C0402D */  daddu $t0, $a2, $zero
.L8002AB04:
/* 005F04 8002AB04 00071400 */  sll   $v0, $a3, 0x10
/* 005F08 8002AB08 00051C00 */  sll   $v1, $a1, 0x10
/* 005F0C 8002AB0C 0043102A */  slt   $v0, $v0, $v1
/* 005F10 8002AB10 10400003 */  beqz  $v0, .L8002AB20
/* 005F14 8002AB14 3102FFFF */   andi  $v0, $t0, 0xffff
/* 005F18 8002AB18 00A0582D */  daddu $t3, $a1, $zero
/* 005F1C 8002AB1C 00E0482D */  daddu $t1, $a3, $zero
.L8002AB20:
/* 005F20 8002AB20 AFA20010 */  sw    $v0, 0x10($sp)
/* 005F24 8002AB24 3122FFFF */  andi  $v0, $t1, 0xffff
/* 005F28 8002AB28 AFA20014 */  sw    $v0, 0x14($sp)
/* 005F2C 8002AB2C 3142FFFF */  andi  $v0, $t2, 0xffff
/* 005F30 8002AB30 AFA20018 */  sw    $v0, 0x18($sp)
/* 005F34 8002AB34 3162FFFF */  andi  $v0, $t3, 0xffff
/* 005F38 8002AB38 318400FF */  andi  $a0, $t4, 0xff
/* 005F3C 8002AB3C 31A500FF */  andi  $a1, $t5, 0xff
/* 005F40 8002AB40 31C600FF */  andi  $a2, $t6, 0xff
/* 005F44 8002AB44 31E700FF */  andi  $a3, $t7, 0xff
/* 005F48 8002AB48 0C00AA41 */  jal   func_8002A904
/* 005F4C 8002AB4C AFA2001C */   sw    $v0, 0x1c($sp)
/* 005F50 8002AB50 8FBF0020 */  lw    $ra, 0x20($sp)
/* 005F54 8002AB54 03E00008 */  jr    $ra
/* 005F58 8002AB58 27BD0028 */   addiu $sp, $sp, 0x28

