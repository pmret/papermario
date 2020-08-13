.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_if_greater_equal
/* 0E97DC 802C4E2C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E97E0 802C4E30 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E97E4 802C4E34 0080882D */  daddu $s1, $a0, $zero
/* 0E97E8 802C4E38 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E97EC 802C4E3C AFB00010 */  sw    $s0, 0x10($sp)
/* 0E97F0 802C4E40 8E30000C */  lw    $s0, 0xc($s1)
/* 0E97F4 802C4E44 8E050000 */  lw    $a1, ($s0)
/* 0E97F8 802C4E48 0C0B1EAF */  jal   get_variable
/* 0E97FC 802C4E4C 26100004 */   addiu $s0, $s0, 4
/* 0E9800 802C4E50 0220202D */  daddu $a0, $s1, $zero
/* 0E9804 802C4E54 8E050000 */  lw    $a1, ($s0)
/* 0E9808 802C4E58 0C0B1EAF */  jal   get_variable
/* 0E980C 802C4E5C 0040802D */   daddu $s0, $v0, $zero
/* 0E9810 802C4E60 0202802A */  slt   $s0, $s0, $v0
/* 0E9814 802C4E64 12000005 */  beqz  $s0, .L802C4E7C
/* 0E9818 802C4E68 24020002 */   addiu $v0, $zero, 2
/* 0E981C 802C4E6C 0C0B223F */  jal   si_skip_if
/* 0E9820 802C4E70 0220202D */   daddu $a0, $s1, $zero
/* 0E9824 802C4E74 AE220008 */  sw    $v0, 8($s1)
/* 0E9828 802C4E78 24020002 */  addiu $v0, $zero, 2
.L802C4E7C:
/* 0E982C 802C4E7C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9830 802C4E80 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9834 802C4E84 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9838 802C4E88 03E00008 */  jr    $ra
/* 0E983C 802C4E8C 27BD0020 */   addiu $sp, $sp, 0x20

