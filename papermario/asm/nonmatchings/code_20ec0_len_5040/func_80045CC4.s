.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80045CC4
/* 0210C4 80045CC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0210C8 80045CC8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0210CC 80045CCC 0080802D */  daddu $s0, $a0, $zero
/* 0210D0 80045CD0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0210D4 80045CD4 8E040018 */  lw    $a0, 0x18($s0)
/* 0210D8 80045CD8 50800005 */  beql  $a0, $zero, .L80045CF0
/* 0210DC 80045CDC A6000010 */   sh    $zero, 0x10($s0)
/* 0210E0 80045CE0 0C00AB4B */  jal   heap_free
/* 0210E4 80045CE4 00000000 */   nop   
/* 0210E8 80045CE8 AE000018 */  sw    $zero, 0x18($s0)
/* 0210EC 80045CEC A6000010 */  sh    $zero, 0x10($s0)
.L80045CF0:
/* 0210F0 80045CF0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0210F4 80045CF4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0210F8 80045CF8 03E00008 */  jr    $ra
/* 0210FC 80045CFC 27BD0018 */   addiu $sp, $sp, 0x18

