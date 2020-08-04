.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetEntryID
/* 0EEE10 802CA460 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EEE14 802CA464 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EEE18 802CA468 8C82000C */  lw    $v0, 0xc($a0)
/* 0EEE1C 802CA46C 3C038007 */  lui   $v1, 0x8007
/* 0EEE20 802CA470 8C63419C */  lw    $v1, 0x419c($v1)
/* 0EEE24 802CA474 8C450000 */  lw    $a1, ($v0)
/* 0EEE28 802CA478 0C0B2026 */  jal   set_variable
/* 0EEE2C 802CA47C 8466008E */   lh    $a2, 0x8e($v1)
/* 0EEE30 802CA480 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EEE34 802CA484 24020002 */  addiu $v0, $zero, 2
/* 0EEE38 802CA488 03E00008 */  jr    $ra
/* 0EEE3C 802CA48C 27BD0018 */   addiu $sp, $sp, 0x18

