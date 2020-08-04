.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_break_case
/* 0EA084 802C56D4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EA088 802C56D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA08C 802C56DC 0080802D */  daddu $s0, $a0, $zero
/* 0EA090 802C56E0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EA094 802C56E4 82020007 */  lb    $v0, 7($s0)
/* 0EA098 802C56E8 04410003 */  bgez  $v0, .L802C56F8
/* 0EA09C 802C56EC 00000000 */   nop   
.L802C56F0:
/* 0EA0A0 802C56F0 080B15BC */  j     .L802C56F0
/* 0EA0A4 802C56F4 00000000 */   nop   

.L802C56F8:
/* 0EA0A8 802C56F8 0C0B2279 */  jal   si_goto_end_case
/* 0EA0AC 802C56FC 0200202D */   daddu $a0, $s0, $zero
/* 0EA0B0 802C5700 AE020008 */  sw    $v0, 8($s0)
/* 0EA0B4 802C5704 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EA0B8 802C5708 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA0BC 802C570C 24020002 */  addiu $v0, $zero, 2
/* 0EA0C0 802C5710 03E00008 */  jr    $ra
/* 0EA0C4 802C5714 27BD0018 */   addiu $sp, $sp, 0x18

