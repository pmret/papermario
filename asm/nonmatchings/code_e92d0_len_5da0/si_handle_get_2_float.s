.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_get_2_float
/* 0EA8BC 802C5F0C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA8C0 802C5F10 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA8C4 802C5F14 0080802D */  daddu $s0, $a0, $zero
/* 0EA8C8 802C5F18 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA8CC 802C5F1C AFB20018 */  sw    $s2, 0x18($sp)
/* 0EA8D0 802C5F20 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA8D4 802C5F24 8E11000C */  lw    $s1, 0xc($s0)
/* 0EA8D8 802C5F28 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA8DC 802C5F2C 8E320000 */  lw    $s2, ($s1)
/* 0EA8E0 802C5F30 26310004 */  addiu $s1, $s1, 4
/* 0EA8E4 802C5F34 8C450000 */  lw    $a1, ($v0)
/* 0EA8E8 802C5F38 24420004 */  addiu $v0, $v0, 4
/* 0EA8EC 802C5F3C 0C0B210B */  jal   get_float_variable
/* 0EA8F0 802C5F40 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA8F4 802C5F44 0200202D */  daddu $a0, $s0, $zero
/* 0EA8F8 802C5F48 44060000 */  mfc1  $a2, $f0
/* 0EA8FC 802C5F4C 0C0B2190 */  jal   set_float_variable
/* 0EA900 802C5F50 0240282D */   daddu $a1, $s2, $zero
/* 0EA904 802C5F54 0200202D */  daddu $a0, $s0, $zero
/* 0EA908 802C5F58 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA90C 802C5F5C 8E310000 */  lw    $s1, ($s1)
/* 0EA910 802C5F60 8C450000 */  lw    $a1, ($v0)
/* 0EA914 802C5F64 24420004 */  addiu $v0, $v0, 4
/* 0EA918 802C5F68 0C0B210B */  jal   get_float_variable
/* 0EA91C 802C5F6C AE020138 */   sw    $v0, 0x138($s0)
/* 0EA920 802C5F70 0200202D */  daddu $a0, $s0, $zero
/* 0EA924 802C5F74 44060000 */  mfc1  $a2, $f0
/* 0EA928 802C5F78 0C0B2190 */  jal   set_float_variable
/* 0EA92C 802C5F7C 0220282D */   daddu $a1, $s1, $zero
/* 0EA930 802C5F80 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA934 802C5F84 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EA938 802C5F88 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA93C 802C5F8C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA940 802C5F90 24020002 */  addiu $v0, $zero, 2
/* 0EA944 802C5F94 03E00008 */  jr    $ra
/* 0EA948 802C5F98 27BD0020 */   addiu $sp, $sp, 0x20

