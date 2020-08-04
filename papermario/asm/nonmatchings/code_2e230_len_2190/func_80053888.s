.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80053888
/* 02EC88 80053888 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02EC8C 8005388C AFBF0010 */  sw    $ra, 0x10($sp)
/* 02EC90 80053890 90820045 */  lbu   $v0, 0x45($a0)
/* 02EC94 80053894 10400008 */  beqz  $v0, .L800538B8
/* 02EC98 80053898 24020001 */   addiu $v0, $zero, 1
/* 02EC9C 8005389C AC80001C */  sw    $zero, 0x1c($a0)
/* 02ECA0 800538A0 A0820042 */  sb    $v0, 0x42($a0)
/* 02ECA4 800538A4 A0800043 */  sb    $zero, 0x43($a0)
/* 02ECA8 800538A8 30A400FF */  andi  $a0, $a1, 0xff
/* 02ECAC 800538AC 0000282D */  daddu $a1, $zero, $zero
/* 02ECB0 800538B0 0C015DBB */  jal   func_800576EC
/* 02ECB4 800538B4 240600B8 */   addiu $a2, $zero, 0xb8
.L800538B8:
/* 02ECB8 800538B8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 02ECBC 800538BC 03E00008 */  jr    $ra
/* 02ECC0 800538C0 27BD0018 */   addiu $sp, $sp, 0x18

