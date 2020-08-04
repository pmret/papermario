.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8014AF8C
/* 0E168C 8014AF8C 3C028016 */  lui   $v0, 0x8016
/* 0E1690 8014AF90 24429AF0 */  addiu $v0, $v0, -0x6510
/* 0E1694 8014AF94 AC44001C */  sw    $a0, 0x1c($v0)
/* 0E1698 8014AF98 03E00008 */  jr    $ra
/* 0E169C 8014AF9C AC450020 */   sw    $a1, 0x20($v0)

/* 0E16A0 8014AFA0 03E00008 */  jr    $ra
/* 0E16A4 8014AFA4 00000000 */   nop   

/* 0E16A8 8014AFA8 00000000 */  nop   
/* 0E16AC 8014AFAC 00000000 */  nop   

.set reorder
