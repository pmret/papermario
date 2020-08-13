.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024EFA4
/* 17D884 8024EFA4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17D888 8024EFA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D88C 8024EFAC 0080802D */  daddu $s0, $a0, $zero
/* 17D890 8024EFB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 17D894 8024EFB4 8E040018 */  lw    $a0, 0x18($s0)
/* 17D898 8024EFB8 50800005 */  beql  $a0, $zero, .L8024EFD0
/* 17D89C 8024EFBC A6000010 */   sh    $zero, 0x10($s0)
/* 17D8A0 8024EFC0 0C00AB4B */  jal   heap_free
/* 17D8A4 8024EFC4 00000000 */   nop   
/* 17D8A8 8024EFC8 AE000018 */  sw    $zero, 0x18($s0)
/* 17D8AC 8024EFCC A6000010 */  sh    $zero, 0x10($s0)
.L8024EFD0:
/* 17D8B0 8024EFD0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 17D8B4 8024EFD4 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D8B8 8024EFD8 03E00008 */  jr    $ra
/* 17D8BC 8024EFDC 27BD0018 */   addiu $sp, $sp, 0x18

