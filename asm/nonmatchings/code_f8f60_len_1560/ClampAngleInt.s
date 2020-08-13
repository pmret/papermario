.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ClampAngleInt
/* 0FA408 802D5A58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA40C 802D5A5C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA410 802D5A60 0080802D */  daddu $s0, $a0, $zero
/* 0FA414 802D5A64 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA418 802D5A68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA41C 802D5A6C 8E11000C */  lw    $s1, 0xc($s0)
/* 0FA420 802D5A70 0C0B1EAF */  jal   get_variable
/* 0FA424 802D5A74 8E250000 */   lw    $a1, ($s1)
/* 0FA428 802D5A78 44826000 */  mtc1  $v0, $f12
/* 0FA42C 802D5A7C 00000000 */  nop   
/* 0FA430 802D5A80 0C00A6C9 */  jal   clamp_angle
/* 0FA434 802D5A84 46806320 */   cvt.s.w $f12, $f12
/* 0FA438 802D5A88 8E250000 */  lw    $a1, ($s1)
/* 0FA43C 802D5A8C 4600008D */  trunc.w.s $f2, $f0
/* 0FA440 802D5A90 44061000 */  mfc1  $a2, $f2
/* 0FA444 802D5A94 0C0B2026 */  jal   set_variable
/* 0FA448 802D5A98 0200202D */   daddu $a0, $s0, $zero
/* 0FA44C 802D5A9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA450 802D5AA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA454 802D5AA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA458 802D5AA8 24020002 */  addiu $v0, $zero, 2
/* 0FA45C 802D5AAC 03E00008 */  jr    $ra
/* 0FA460 802D5AB0 27BD0020 */   addiu $sp, $sp, 0x20

