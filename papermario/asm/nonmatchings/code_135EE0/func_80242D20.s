.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80242D20
/* 136060 80242D20 26949D50 */  addiu $s4, $s4, -0x62b0
/* 136064 80242D24 00042140 */  sll   $a0, $a0, 5
/* 136068 80242D28 AFB10014 */  sw    $s1, 0x14($sp)
/* 13606C 80242D2C 3C118025 */  lui   $s1, 0x8025
/* 136070 80242D30 2631EFB4 */  addiu $s1, $s1, -0x104c
/* 136074 80242D34 AFBF0024 */  sw    $ra, 0x24($sp)
/* 136078 80242D38 AFB00010 */  sw    $s0, 0x10($sp)
/* 13607C 80242D3C 8E220000 */  lw    $v0, ($s1)
/* 136080 80242D40 14400012 */  bnez  $v0, .L80242D8C
/* 136084 80242D44 00948021 */   addu  $s0, $a0, $s4
/* 136088 80242D48 0C00CD4A */  jal   get_game_mode
/* 13608C 80242D4C 00000000 */   nop   
/* 136090 80242D50 00021400 */  sll   $v0, $v0, 0x10
