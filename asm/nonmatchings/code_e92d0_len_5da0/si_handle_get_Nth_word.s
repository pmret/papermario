.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_get_Nth_word
/* 0EA80C 802C5E5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA810 802C5E60 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA814 802C5E64 0080802D */  daddu $s0, $a0, $zero
/* 0EA818 802C5E68 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA81C 802C5E6C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA820 802C5E70 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA824 802C5E74 8C450004 */  lw    $a1, 4($v0)
/* 0EA828 802C5E78 0C0B1EAF */  jal   get_variable
/* 0EA82C 802C5E7C 8C510000 */   lw    $s1, ($v0)
/* 0EA830 802C5E80 0200202D */  daddu $a0, $s0, $zero
/* 0EA834 802C5E84 8C830138 */  lw    $v1, 0x138($a0)
/* 0EA838 802C5E88 00021080 */  sll   $v0, $v0, 2
/* 0EA83C 802C5E8C 00431021 */  addu  $v0, $v0, $v1
/* 0EA840 802C5E90 8C460000 */  lw    $a2, ($v0)
/* 0EA844 802C5E94 0C0B2026 */  jal   set_variable
/* 0EA848 802C5E98 0220282D */   daddu $a1, $s1, $zero
/* 0EA84C 802C5E9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA850 802C5EA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA854 802C5EA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA858 802C5EA8 24020002 */  addiu $v0, $zero, 2
/* 0EA85C 802C5EAC 03E00008 */  jr    $ra
/* 0EA860 802C5EB0 27BD0020 */   addiu $sp, $sp, 0x20

