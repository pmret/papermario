.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80245C6C
/* 138FAC 80245C6C 24070001 */  addiu $a3, $zero, 1
/* 138FB0 80245C70 AFA00010 */  sw    $zero, 0x10($sp)
/* 138FB4 80245C74 AFB20018 */  sw    $s2, 0x18($sp)
/* 138FB8 80245C78 25170069 */  addiu $s7, $t0, 0x69
/* 138FBC 80245C7C 02E0282D */  daddu $a1, $s7, $zero
/* 138FC0 80245C80 240800FF */  addiu $t0, $zero, 0xff
/* 138FC4 80245C84 0C049DA7 */  jal   draw_number
/* 138FC8 80245C88 AFA80014 */   sw    $t0, 0x14($sp)
/* 138FCC 80245C8C 24040001 */  addiu $a0, $zero, 1
/* 138FD0 80245C90 02C0282D */  daddu $a1, $s6, $zero
/* 138FD4 80245C94 0C093BA5 */  jal   func_8024EE94
/* 138FD8 80245C98 27C60045 */   addiu $a2, $fp, 0x45
/* 138FDC 80245C9C 02A0282D */  daddu $a1, $s5, $zero
/* 138FE0 80245CA0 8E240020 */  lw    $a0, 0x20($s1)
/* 138FE4 80245CA4 0C051261 */  jal   set_icon_render_pos
/* 138FE8 80245CA8 27C6005C */   addiu $a2, $fp, 0x5c
