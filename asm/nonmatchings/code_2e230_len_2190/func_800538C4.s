.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800538C4
/* 02ECC4 800538C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02ECC8 800538C8 24020001 */  addiu $v0, $zero, 1
/* 02ECCC 800538CC AFBF0010 */  sw    $ra, 0x10($sp)
/* 02ECD0 800538D0 AC80001C */  sw    $zero, 0x1c($a0)
/* 02ECD4 800538D4 A0820042 */  sb    $v0, 0x42($a0)
/* 02ECD8 800538D8 A0800043 */  sb    $zero, 0x43($a0)
/* 02ECDC 800538DC 30A400FF */  andi  $a0, $a1, 0xff
/* 02ECE0 800538E0 0000282D */  daddu $a1, $zero, $zero
/* 02ECE4 800538E4 0C015DBB */  jal   func_800576EC
/* 02ECE8 800538E8 240600B8 */   addiu $a2, $zero, 0xb8
/* 02ECEC 800538EC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 02ECF0 800538F0 03E00008 */  jr    $ra
/* 02ECF4 800538F4 27BD0018 */   addiu $sp, $sp, 0x18

