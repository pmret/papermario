.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801234E0
/* 0B9BE0 801234E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0B9BE4 801234E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0B9BE8 801234E8 0000802D */  daddu $s0, $zero, $zero
/* 0B9BEC 801234EC AFBF0014 */  sw    $ra, 0x14($sp)
.L801234F0:
/* 0B9BF0 801234F0 3C038015 */  lui   $v1, 0x8015
/* 0B9BF4 801234F4 8C634420 */  lw    $v1, 0x4420($v1)
/* 0B9BF8 801234F8 00101080 */  sll   $v0, $s0, 2
/* 0B9BFC 801234FC 00431021 */  addu  $v0, $v0, $v1
/* 0B9C00 80123500 8C430000 */  lw    $v1, ($v0)
/* 0B9C04 80123504 5060000B */  beql  $v1, $zero, .L80123534
/* 0B9C08 80123508 26100001 */   addiu $s0, $s0, 1
/* 0B9C0C 8012350C 8C640000 */  lw    $a0, ($v1)
/* 0B9C10 80123510 30820002 */  andi  $v0, $a0, 2
/* 0B9C14 80123514 14400007 */  bnez  $v0, .L80123534
/* 0B9C18 80123518 26100001 */   addiu $s0, $s0, 1
/* 0B9C1C 8012351C 30820004 */  andi  $v0, $a0, 4
/* 0B9C20 80123520 10400004 */  beqz  $v0, .L80123534
/* 0B9C24 80123524 00000000 */   nop   
/* 0B9C28 80123528 8C620008 */  lw    $v0, 8($v1)
/* 0B9C2C 8012352C 0040F809 */  jalr  $v0
/* 0B9C30 80123530 00000000 */  nop   
.L80123534:
/* 0B9C34 80123534 2A020010 */  slti  $v0, $s0, 0x10
/* 0B9C38 80123538 1440FFED */  bnez  $v0, .L801234F0
/* 0B9C3C 8012353C 00000000 */   nop   
/* 0B9C40 80123540 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0B9C44 80123544 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B9C48 80123548 03E00008 */  jr    $ra
/* 0B9C4C 8012354C 27BD0018 */   addiu $sp, $sp, 0x18

