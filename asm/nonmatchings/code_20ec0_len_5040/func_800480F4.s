.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800480F4
/* 0234F4 800480F4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0234F8 800480F8 00041040 */  sll   $v0, $a0, 1
/* 0234FC 800480FC 00441021 */  addu  $v0, $v0, $a0
/* 023500 80048100 00021080 */  sll   $v0, $v0, 2
/* 023504 80048104 00441023 */  subu  $v0, $v0, $a0
/* 023508 80048108 3C03800A */  lui   $v1, 0x800a
/* 02350C 8004810C 8C630F44 */  lw    $v1, 0xf44($v1)
/* 023510 80048110 00021100 */  sll   $v0, $v0, 4
/* 023514 80048114 AFBF0010 */  sw    $ra, 0x10($sp)
/* 023518 80048118 00621821 */  addu  $v1, $v1, $v0
/* 02351C 8004811C 806200A0 */  lb    $v0, 0xa0($v1)
/* 023520 80048120 10400004 */  beqz  $v0, .L80048134
/* 023524 80048124 00000000 */   nop   
/* 023528 80048128 8C6400A4 */  lw    $a0, 0xa4($v1)
/* 02352C 8004812C 0C05123D */  jal   free_icon
/* 023530 80048130 A06000A0 */   sb    $zero, 0xa0($v1)
.L80048134:
/* 023534 80048134 8FBF0010 */  lw    $ra, 0x10($sp)
/* 023538 80048138 03E00008 */  jr    $ra
/* 02353C 8004813C 27BD0018 */   addiu $sp, $sp, 0x18

