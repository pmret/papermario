.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80245D5C
/* 13909C 80245D5C 02C0282D */  daddu $a1, $s6, $zero
/* 1390A0 80245D60 0C093BA5 */  jal   func_8024EE94
/* 1390A4 80245D64 27C60067 */   addiu $a2, $fp, 0x67
/* 1390A8 80245D68 02A0282D */  daddu $a1, $s5, $zero
/* 1390AC 80245D6C 8E240024 */  lw    $a0, 0x24($s1)
/* 1390B0 80245D70 0C051261 */  jal   set_icon_render_pos
/* 1390B4 80245D74 27C6007E */   addiu $a2, $fp, 0x7e
