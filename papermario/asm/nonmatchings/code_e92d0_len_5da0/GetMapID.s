.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetMapID
/* 0EEE40 802CA490 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EEE44 802CA494 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EEE48 802CA498 8C82000C */  lw    $v0, 0xc($a0)
/* 0EEE4C 802CA49C 3C038007 */  lui   $v1, 0x8007
/* 0EEE50 802CA4A0 8C63419C */  lw    $v1, 0x419c($v1)
/* 0EEE54 802CA4A4 8C450000 */  lw    $a1, ($v0)
/* 0EEE58 802CA4A8 0C0B2026 */  jal   set_variable
/* 0EEE5C 802CA4AC 8466008C */   lh    $a2, 0x8c($v1)
/* 0EEE60 802CA4B0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EEE64 802CA4B4 24020002 */  addiu $v0, $zero, 2
/* 0EEE68 802CA4B8 03E00008 */  jr    $ra
/* 0EEE6C 802CA4BC 27BD0018 */   addiu $sp, $sp, 0x18

