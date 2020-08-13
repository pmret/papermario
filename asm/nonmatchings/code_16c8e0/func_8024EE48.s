.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024EE48
/* 17D728 8024EE48 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D72C 8024EE4C AFB10014 */  sw    $s1, 0x14($sp)
/* 17D730 8024EE50 0000882D */  daddu $s1, $zero, $zero
/* 17D734 8024EE54 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D738 8024EE58 3C10802A */  lui   $s0, 0x802a
/* 17D73C 8024EE5C 2610F2C0 */  addiu $s0, $s0, -0xd40
/* 17D740 8024EE60 AFBF0018 */  sw    $ra, 0x18($sp)
.L8024EE64:
/* 17D744 8024EE64 86020010 */  lh    $v0, 0x10($s0)
/* 17D748 8024EE68 50400007 */  beql  $v0, $zero, .L8024EE88
/* 17D74C 8024EE6C 26310001 */   addiu $s1, $s1, 1
/* 17D750 8024EE70 8E020004 */  lw    $v0, 4($s0)
/* 17D754 8024EE74 50400004 */  beql  $v0, $zero, .L8024EE88
/* 17D758 8024EE78 26310001 */   addiu $s1, $s1, 1
/* 17D75C 8024EE7C 0040F809 */  jalr  $v0
/* 17D760 8024EE80 0200202D */  daddu $a0, $s0, $zero
/* 17D764 8024EE84 26310001 */  addiu $s1, $s1, 1
.L8024EE88:
/* 17D768 8024EE88 2A220020 */  slti  $v0, $s1, 0x20
/* 17D76C 8024EE8C 1440FFF5 */  bnez  $v0, .L8024EE64
/* 17D770 8024EE90 2610001C */   addiu $s0, $s0, 0x1c
/* 17D774 8024EE94 8FBF0018 */  lw    $ra, 0x18($sp)
/* 17D778 8024EE98 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D77C 8024EE9C 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D780 8024EEA0 03E00008 */  jr    $ra
/* 17D784 8024EEA4 27BD0020 */   addiu $sp, $sp, 0x20

