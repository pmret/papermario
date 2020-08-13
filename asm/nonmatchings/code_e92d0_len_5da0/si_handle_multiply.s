.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_multiply
/* 0EA27C 802C58CC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA280 802C58D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA284 802C58D4 0080882D */  daddu $s1, $a0, $zero
/* 0EA288 802C58D8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA28C 802C58DC AFB20018 */  sw    $s2, 0x18($sp)
/* 0EA290 802C58E0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA294 802C58E4 8E22000C */  lw    $v0, 0xc($s1)
/* 0EA298 802C58E8 8C450004 */  lw    $a1, 4($v0)
/* 0EA29C 802C58EC 0C0B1EAF */  jal   get_variable
/* 0EA2A0 802C58F0 8C520000 */   lw    $s2, ($v0)
/* 0EA2A4 802C58F4 0040802D */  daddu $s0, $v0, $zero
/* 0EA2A8 802C58F8 0220202D */  daddu $a0, $s1, $zero
/* 0EA2AC 802C58FC 0C0B1EAF */  jal   get_variable
/* 0EA2B0 802C5900 0240282D */   daddu $a1, $s2, $zero
/* 0EA2B4 802C5904 02020018 */  mult  $s0, $v0
/* 0EA2B8 802C5908 0220202D */  daddu $a0, $s1, $zero
/* 0EA2BC 802C590C 00003012 */  mflo  $a2
/* 0EA2C0 802C5910 0C0B2026 */  jal   set_variable
/* 0EA2C4 802C5914 0240282D */   daddu $a1, $s2, $zero
/* 0EA2C8 802C5918 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA2CC 802C591C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EA2D0 802C5920 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA2D4 802C5924 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA2D8 802C5928 24020002 */  addiu $v0, $zero, 2
/* 0EA2DC 802C592C 03E00008 */  jr    $ra
/* 0EA2E0 802C5930 27BD0020 */   addiu $sp, $sp, 0x20

