.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024A5AC
/* 13D8EC 8024A5AC 3C018027 */  lui   $at, 0x8027
/* 13D8F0 8024A5B0 A43005CC */  sh    $s0, 0x5cc($at)
/* 13D8F4 8024A5B4 0200202D */  daddu $a0, $s0, $zero
/* 13D8F8 8024A5B8 28820064 */  slti  $v0, $a0, 0x64
/* 13D8FC 8024A5BC 1040000A */  beqz  $v0, .L8024A5E8
/* 13D900 8024A5C0 24057FFF */   addiu $a1, $zero, 0x7fff
/* 13D904 8024A5C4 3C038027 */  lui   $v1, 0x8027
/* 13D908 8024A5C8 24630400 */  addiu $v1, $v1, 0x400
/* 13D90C 8024A5CC 00041040 */  sll   $v0, $a0, 1
/* 13D910 8024A5D0 00431821 */  addu  $v1, $v0, $v1
.L8024A5D4:
/* 13D914 8024A5D4 A4650000 */  sh    $a1, ($v1)
/* 13D918 8024A5D8 24840001 */  addiu $a0, $a0, 1
/* 13D91C 8024A5DC 28820064 */  slti  $v0, $a0, 0x64
/* 13D920 8024A5E0 1440FFFC */  bnez  $v0, .L8024A5D4
/* 13D924 8024A5E4 24630002 */   addiu $v1, $v1, 2
.L8024A5E8:
/* 13D928 8024A5E8 3C058027 */  lui   $a1, 0x8027
/* 13D92C 8024A5EC 24A504D0 */  addiu $a1, $a1, 0x4d0
/* 13D930 8024A5F0 0000202D */  daddu $a0, $zero, $zero
/* 13D934 8024A5F4 3C078027 */  lui   $a3, 0x8027
/* 13D938 8024A5F8 24E705CC */  addiu $a3, $a3, 0x5cc
/* 13D93C 8024A5FC 24060001 */  addiu $a2, $zero, 1
/* 13D940 8024A600 24090008 */  addiu $t1, $zero, 8
/* 13D944 8024A604 24080008 */  addiu $t0, $zero, 8
/* 13D948 8024A608 00A81821 */  addu  $v1, $a1, $t0
/* 13D94C 8024A60C 3C018027 */  lui   $at, 0x8027
/* 13D950 8024A610 AC2005C0 */  sw    $zero, 0x5c0($at)
/* 13D954 8024A614 3C018027 */  lui   $at, 0x8027
/* 13D958 8024A618 AC2005C8 */  sw    $zero, 0x5c8($at)
/* 13D95C 8024A61C 3C018027 */  lui   $at, 0x8027
/* 13D960 8024A620 AC2005C4 */  sw    $zero, 0x5c4($at)
/* 13D964 8024A624 3C018027 */  lui   $at, 0x8027
/* 13D968 8024A628 AC2005DC */  sw    $zero, 0x5dc($at)
/* 13D96C 8024A62C 3C018027 */  lui   $at, 0x8027
/* 13D970 8024A630 AC2004C8 */  sw    $zero, 0x4c8($at)
