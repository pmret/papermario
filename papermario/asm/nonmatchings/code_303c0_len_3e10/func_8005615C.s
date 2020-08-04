.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8005615C
/* 03155C 8005615C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 031560 80056160 AFBF0010 */  sw    $ra, 0x10($sp)
/* 031564 80056164 0C015B57 */  jal   func_80056D5C
/* 031568 80056168 24040001 */   addiu $a0, $zero, 1
/* 03156C 8005616C 0C01536A */  jal   func_80054DA8
/* 031570 80056170 0000202D */   daddu $a0, $zero, $zero
/* 031574 80056174 8FBF0010 */  lw    $ra, 0x10($sp)
/* 031578 80056178 03E00008 */  jr    $ra
/* 03157C 8005617C 27BD0018 */   addiu $sp, $sp, 0x18

