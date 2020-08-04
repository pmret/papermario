.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80123550
/* 0B9C50 80123550 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0B9C54 80123554 AFB00010 */  sw    $s0, 0x10($sp)
/* 0B9C58 80123558 0000802D */  daddu $s0, $zero, $zero
/* 0B9C5C 8012355C AFBF0014 */  sw    $ra, 0x14($sp)
.L80123560:
/* 0B9C60 80123560 3C038015 */  lui   $v1, 0x8015
/* 0B9C64 80123564 8C634420 */  lw    $v1, 0x4420($v1)
/* 0B9C68 80123568 00101080 */  sll   $v0, $s0, 2
/* 0B9C6C 8012356C 00431021 */  addu  $v0, $v0, $v1
/* 0B9C70 80123570 8C430000 */  lw    $v1, ($v0)
/* 0B9C74 80123574 5060000B */  beql  $v1, $zero, .L801235A4
/* 0B9C78 80123578 26100001 */   addiu $s0, $s0, 1
/* 0B9C7C 8012357C 8C640000 */  lw    $a0, ($v1)
/* 0B9C80 80123580 30820002 */  andi  $v0, $a0, 2
/* 0B9C84 80123584 14400007 */  bnez  $v0, .L801235A4
/* 0B9C88 80123588 26100001 */   addiu $s0, $s0, 1
/* 0B9C8C 8012358C 30820008 */  andi  $v0, $a0, 8
/* 0B9C90 80123590 10400004 */  beqz  $v0, .L801235A4
/* 0B9C94 80123594 00000000 */   nop   
/* 0B9C98 80123598 8C620008 */  lw    $v0, 8($v1)
/* 0B9C9C 8012359C 0040F809 */  jalr  $v0
/* 0B9CA0 801235A0 00000000 */  nop   
.L801235A4:
/* 0B9CA4 801235A4 2A020010 */  slti  $v0, $s0, 0x10
/* 0B9CA8 801235A8 1440FFED */  bnez  $v0, .L80123560
/* 0B9CAC 801235AC 00000000 */   nop   
/* 0B9CB0 801235B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0B9CB4 801235B4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B9CB8 801235B8 03E00008 */  jr    $ra
/* 0B9CBC 801235BC 27BD0018 */   addiu $sp, $sp, 0x18

