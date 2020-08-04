.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80053A28
/* 02EE28 80053A28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02EE2C 80053A2C AFB00010 */  sw    $s0, 0x10($sp)
/* 02EE30 80053A30 0080802D */  daddu $s0, $a0, $zero
/* 02EE34 80053A34 AFBF0014 */  sw    $ra, 0x14($sp)
/* 02EE38 80053A38 9602000A */  lhu   $v0, 0xa($s0)
/* 02EE3C 80053A3C 2442FFFF */  addiu $v0, $v0, -1
/* 02EE40 80053A40 A602000A */  sh    $v0, 0xa($s0)
/* 02EE44 80053A44 00021400 */  sll   $v0, $v0, 0x10
/* 02EE48 80053A48 10400006 */  beqz  $v0, .L80053A64
/* 02EE4C 80053A4C 00000000 */   nop   
/* 02EE50 80053A50 8E020000 */  lw    $v0, ($s0)
/* 02EE54 80053A54 8E030004 */  lw    $v1, 4($s0)
/* 02EE58 80053A58 00431021 */  addu  $v0, $v0, $v1
/* 02EE5C 80053A5C 08014EA2 */  j     .L80053A88
/* 02EE60 80053A60 AE020000 */   sw    $v0, ($s0)

.L80053A64:
/* 02EE64 80053A64 86020008 */  lh    $v0, 8($s0)
/* 02EE68 80053A68 8E03000C */  lw    $v1, 0xc($s0)
/* 02EE6C 80053A6C 00021400 */  sll   $v0, $v0, 0x10
/* 02EE70 80053A70 10600005 */  beqz  $v1, .L80053A88
/* 02EE74 80053A74 AE020000 */   sw    $v0, ($s0)
/* 02EE78 80053A78 0060F809 */  jalr  $v1
/* 02EE7C 80053A7C 00000000 */  nop   
/* 02EE80 80053A80 AE000004 */  sw    $zero, 4($s0)
/* 02EE84 80053A84 AE00000C */  sw    $zero, 0xc($s0)
.L80053A88:
/* 02EE88 80053A88 8FBF0014 */  lw    $ra, 0x14($sp)
/* 02EE8C 80053A8C 8FB00010 */  lw    $s0, 0x10($sp)
/* 02EE90 80053A90 03E00008 */  jr    $ra
/* 02EE94 80053A94 27BD0018 */   addiu $sp, $sp, 0x18

