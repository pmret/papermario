.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_get_1_float
/* 0EA864 802C5EB4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA868 802C5EB8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA86C 802C5EBC 0080802D */  daddu $s0, $a0, $zero
/* 0EA870 802C5EC0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA874 802C5EC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA878 802C5EC8 8E03000C */  lw    $v1, 0xc($s0)
/* 0EA87C 802C5ECC 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA880 802C5ED0 8C710000 */  lw    $s1, ($v1)
/* 0EA884 802C5ED4 8C450000 */  lw    $a1, ($v0)
/* 0EA888 802C5ED8 24420004 */  addiu $v0, $v0, 4
/* 0EA88C 802C5EDC 0C0B210B */  jal   get_float_variable
/* 0EA890 802C5EE0 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA894 802C5EE4 0200202D */  daddu $a0, $s0, $zero
/* 0EA898 802C5EE8 44060000 */  mfc1  $a2, $f0
/* 0EA89C 802C5EEC 0C0B2190 */  jal   set_float_variable
/* 0EA8A0 802C5EF0 0220282D */   daddu $a1, $s1, $zero
/* 0EA8A4 802C5EF4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA8A8 802C5EF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA8AC 802C5EFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA8B0 802C5F00 24020002 */  addiu $v0, $zero, 2
/* 0EA8B4 802C5F04 03E00008 */  jr    $ra
/* 0EA8B8 802C5F08 27BD0020 */   addiu $sp, $sp, 0x20

