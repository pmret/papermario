.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_set_var
/* 0EA0F4 802C5744 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA0F8 802C5748 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA0FC 802C574C 0080802D */  daddu $s0, $a0, $zero
/* 0EA100 802C5750 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA104 802C5754 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA108 802C5758 8E02000C */  lw    $v0, 0xc($s0)
/* 0EA10C 802C575C 8C450004 */  lw    $a1, 4($v0)
/* 0EA110 802C5760 0C0B1EAF */  jal   get_variable
/* 0EA114 802C5764 8C510000 */   lw    $s1, ($v0)
/* 0EA118 802C5768 0200202D */  daddu $a0, $s0, $zero
/* 0EA11C 802C576C 0220282D */  daddu $a1, $s1, $zero
/* 0EA120 802C5770 0C0B2026 */  jal   set_variable
/* 0EA124 802C5774 0040302D */   daddu $a2, $v0, $zero
/* 0EA128 802C5778 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA12C 802C577C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA130 802C5780 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA134 802C5784 24020002 */  addiu $v0, $zero, 2
/* 0EA138 802C5788 03E00008 */  jr    $ra
/* 0EA13C 802C578C 27BD0020 */   addiu $sp, $sp, 0x20

