.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DD820
/* 100910 802DD820 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 100914 802DD824 AFB00010 */  sw    $s0, 0x10($sp)
/* 100918 802DD828 0080802D */  daddu $s0, $a0, $zero
/* 10091C 802DD82C AFB10014 */  sw    $s1, 0x14($sp)
/* 100920 802DD830 AFBF001C */  sw    $ra, 0x1c($sp)
/* 100924 802DD834 AFB20018 */  sw    $s2, 0x18($sp)
/* 100928 802DD838 8E030000 */  lw    $v1, ($s0)
/* 10092C 802DD83C 2402FFFF */  addiu $v0, $zero, -1
/* 100930 802DD840 1062000C */  beq   $v1, $v0, .L802DD874
/* 100934 802DD844 00A0882D */   daddu $s1, $a1, $zero
/* 100938 802DD848 0040902D */  daddu $s2, $v0, $zero
.L802DD84C:
/* 10093C 802DD84C 8E040000 */  lw    $a0, ($s0)
/* 100940 802DD850 8E250000 */  lw    $a1, ($s1)
/* 100944 802DD854 0C0B75EC */  jal   func_802DD7B0
/* 100948 802DD858 26100004 */   addiu $s0, $s0, 4
/* 10094C 802DD85C 8E220000 */  lw    $v0, ($s1)
/* 100950 802DD860 54520001 */  bnel  $v0, $s2, .L802DD868
/* 100954 802DD864 26310004 */   addiu $s1, $s1, 4
.L802DD868:
/* 100958 802DD868 8E020000 */  lw    $v0, ($s0)
/* 10095C 802DD86C 1452FFF7 */  bne   $v0, $s2, .L802DD84C
/* 100960 802DD870 00000000 */   nop   
.L802DD874:
/* 100964 802DD874 8FBF001C */  lw    $ra, 0x1c($sp)
/* 100968 802DD878 8FB20018 */  lw    $s2, 0x18($sp)
/* 10096C 802DD87C 8FB10014 */  lw    $s1, 0x14($sp)
/* 100970 802DD880 8FB00010 */  lw    $s0, 0x10($sp)
/* 100974 802DD884 03E00008 */  jr    $ra
/* 100978 802DD888 27BD0020 */   addiu $sp, $sp, 0x20

