.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E97B8
/* 082C68 800E97B8 3C048011 */  lui   $a0, 0x8011
/* 082C6C 800E97BC 2484EF58 */  addiu $a0, $a0, -0x10a8
/* 082C70 800E97C0 8082003A */  lb    $v0, 0x3a($a0)
/* 082C74 800E97C4 24030001 */  addiu $v1, $zero, 1
/* 082C78 800E97C8 10430004 */  beq   $v0, $v1, .L800E97DC
/* 082C7C 800E97CC 00000000 */   nop   
/* 082C80 800E97D0 A083003A */  sb    $v1, 0x3a($a0)
/* 082C84 800E97D4 A4800038 */  sh    $zero, 0x38($a0)
/* 082C88 800E97D8 A083003B */  sb    $v1, 0x3b($a0)
.L800E97DC:
/* 082C8C 800E97DC 03E00008 */  jr    $ra
/* 082C90 800E97E0 00000000 */   nop   

