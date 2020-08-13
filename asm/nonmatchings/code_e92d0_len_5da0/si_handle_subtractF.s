.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_subtractF
/* 0EA49C 802C5AEC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EA4A0 802C5AF0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA4A4 802C5AF4 0080802D */  daddu $s0, $a0, $zero
/* 0EA4A8 802C5AF8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA4AC 802C5AFC AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA4B0 802C5B00 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0EA4B4 802C5B04 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA4B8 802C5B08 8C450004 */  lw    $a1, 4($v0)
/* 0EA4BC 802C5B0C 0C0B210B */  jal   get_float_variable
/* 0EA4C0 802C5B10 8C510000 */   lw    $s1, ($v0)
/* 0EA4C4 802C5B14 46000506 */  mov.s $f20, $f0
/* 0EA4C8 802C5B18 0200202D */  daddu $a0, $s0, $zero
/* 0EA4CC 802C5B1C 0C0B210B */  jal   get_float_variable
/* 0EA4D0 802C5B20 0220282D */   daddu $a1, $s1, $zero
/* 0EA4D4 802C5B24 46140001 */  sub.s $f0, $f0, $f20
/* 0EA4D8 802C5B28 0200202D */  daddu $a0, $s0, $zero
/* 0EA4DC 802C5B2C 44060000 */  mfc1  $a2, $f0
/* 0EA4E0 802C5B30 0C0B2190 */  jal   set_float_variable
/* 0EA4E4 802C5B34 0220282D */   daddu $a1, $s1, $zero
/* 0EA4E8 802C5B38 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA4EC 802C5B3C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA4F0 802C5B40 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA4F4 802C5B44 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0EA4F8 802C5B48 24020002 */  addiu $v0, $zero, 2
/* 0EA4FC 802C5B4C 03E00008 */  jr    $ra
/* 0EA500 802C5B50 27BD0028 */   addiu $sp, $sp, 0x28

