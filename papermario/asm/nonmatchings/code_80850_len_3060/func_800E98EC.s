.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E98EC
/* 082D9C 800E98EC 24020001 */  addiu $v0, $zero, 1
/* 082DA0 800E98F0 3C018011 */  lui   $at, 0x8011
/* 082DA4 800E98F4 A022EF9E */  sb    $v0, -0x1062($at)
/* 082DA8 800E98F8 03E00008 */  jr    $ra
/* 082DAC 800E98FC 00000000 */   nop   

