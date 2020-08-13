.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_get_3_word
/* 0EA6DC 802C5D2C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA6E0 802C5D30 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA6E4 802C5D34 0080802D */  daddu $s0, $a0, $zero
/* 0EA6E8 802C5D38 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA6EC 802C5D3C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA6F0 802C5D40 8E11000C */  lw    $s1, 0xc($s0)
/* 0EA6F4 802C5D44 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA6F8 802C5D48 8E250000 */  lw    $a1, ($s1)
/* 0EA6FC 802C5D4C 26310004 */  addiu $s1, $s1, 4
/* 0EA700 802C5D50 8C460000 */  lw    $a2, ($v0)
/* 0EA704 802C5D54 24420004 */  addiu $v0, $v0, 4
/* 0EA708 802C5D58 0C0B2026 */  jal   set_variable
/* 0EA70C 802C5D5C AE020138 */   sw    $v0, 0x138($s0)
/* 0EA710 802C5D60 8E250000 */  lw    $a1, ($s1)
/* 0EA714 802C5D64 26310004 */  addiu $s1, $s1, 4
/* 0EA718 802C5D68 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA71C 802C5D6C 0200202D */  daddu $a0, $s0, $zero
/* 0EA720 802C5D70 8C460000 */  lw    $a2, ($v0)
/* 0EA724 802C5D74 24420004 */  addiu $v0, $v0, 4
/* 0EA728 802C5D78 0C0B2026 */  jal   set_variable
/* 0EA72C 802C5D7C AE020138 */   sw    $v0, 0x138($s0)
/* 0EA730 802C5D80 0200202D */  daddu $a0, $s0, $zero
/* 0EA734 802C5D84 8C820138 */  lw    $v0, 0x138($a0)
/* 0EA738 802C5D88 8E250000 */  lw    $a1, ($s1)
/* 0EA73C 802C5D8C 8C460000 */  lw    $a2, ($v0)
/* 0EA740 802C5D90 24420004 */  addiu $v0, $v0, 4
/* 0EA744 802C5D94 0C0B2026 */  jal   set_variable
/* 0EA748 802C5D98 AC820138 */   sw    $v0, 0x138($a0)
/* 0EA74C 802C5D9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA750 802C5DA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA754 802C5DA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA758 802C5DA8 24020002 */  addiu $v0, $zero, 2
/* 0EA75C 802C5DAC 03E00008 */  jr    $ra
/* 0EA760 802C5DB0 27BD0020 */   addiu $sp, $sp, 0x20

