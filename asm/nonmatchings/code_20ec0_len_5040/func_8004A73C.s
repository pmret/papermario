.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004A73C
/* 025B3C 8004A73C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 025B40 8004A740 AFB10014 */  sw    $s1, 0x14($sp)
/* 025B44 8004A744 0080882D */  daddu $s1, $a0, $zero
/* 025B48 8004A748 AFBF0018 */  sw    $ra, 0x18($sp)
/* 025B4C 8004A74C AFB00010 */  sw    $s0, 0x10($sp)
/* 025B50 8004A750 8E300148 */  lw    $s0, 0x148($s1)
/* 025B54 8004A754 0C00EABB */  jal   get_npc_unsafe
/* 025B58 8004A758 86040008 */   lh    $a0, 8($s0)
/* 025B5C 8004A75C 820200B4 */  lb    $v0, 0xb4($s0)
/* 025B60 8004A760 14400003 */  bnez  $v0, .L8004A770
/* 025B64 8004A764 00000000 */   nop   
/* 025B68 8004A768 8E220074 */  lw    $v0, 0x74($s1)
/* 025B6C 8004A76C AE220070 */  sw    $v0, 0x70($s1)
.L8004A770:
/* 025B70 8004A770 8FBF0018 */  lw    $ra, 0x18($sp)
/* 025B74 8004A774 8FB10014 */  lw    $s1, 0x14($sp)
/* 025B78 8004A778 8FB00010 */  lw    $s0, 0x10($sp)
/* 025B7C 8004A77C 03E00008 */  jr    $ra
/* 025B80 8004A780 27BD0020 */   addiu $sp, $sp, 0x20

