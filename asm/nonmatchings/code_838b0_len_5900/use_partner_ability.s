.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel use_partner_ability
/* 0847C4 800EB314 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0847C8 800EB318 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0847CC 800EB31C 0C011052 */  jal   func_80044148
/* 0847D0 800EB320 00000000 */   nop   
/* 0847D4 800EB324 1440002B */  bnez  $v0, .L800EB3D4
/* 0847D8 800EB328 0000102D */   daddu $v0, $zero, $zero
/* 0847DC 800EB32C 3C028011 */  lui   $v0, 0x8011
/* 0847E0 800EB330 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 0847E4 800EB334 50400027 */  beql  $v0, $zero, .L800EB3D4
/* 0847E8 800EB338 0000102D */   daddu $v0, $zero, $zero
/* 0847EC 800EB33C 8C42002C */  lw    $v0, 0x2c($v0)
/* 0847F0 800EB340 10400007 */  beqz  $v0, .L800EB360
/* 0847F4 800EB344 00000000 */   nop   
/* 0847F8 800EB348 3C048011 */  lui   $a0, 0x8011
/* 0847FC 800EB34C 8C84C930 */  lw    $a0, -0x36d0($a0)
/* 084800 800EB350 0040F809 */  jalr  $v0
/* 084804 800EB354 00000000 */  nop   
/* 084808 800EB358 1040001E */  beqz  $v0, .L800EB3D4
/* 08480C 800EB35C 0000102D */   daddu $v0, $zero, $zero
.L800EB360:
/* 084810 800EB360 3C028007 */  lui   $v0, 0x8007
/* 084814 800EB364 8C42419C */  lw    $v0, 0x419c($v0)
/* 084818 800EB368 80420081 */  lb    $v0, 0x81($v0)
/* 08481C 800EB36C 1040000B */  beqz  $v0, .L800EB39C
/* 084820 800EB370 00000000 */   nop   
/* 084824 800EB374 3C028011 */  lui   $v0, 0x8011
/* 084828 800EB378 2442EBB0 */  addiu $v0, $v0, -0x1450
/* 08482C 800EB37C 8C420008 */  lw    $v0, 8($v0)
/* 084830 800EB380 30424000 */  andi  $v0, $v0, 0x4000
/* 084834 800EB384 10400005 */  beqz  $v0, .L800EB39C
/* 084838 800EB388 00000000 */   nop   
/* 08483C 800EB38C 0C05272D */  jal   play_sound
/* 084840 800EB390 2404021D */   addiu $a0, $zero, 0x21d
/* 084844 800EB394 0803ACF5 */  j     .L800EB3D4
/* 084848 800EB398 0000102D */   daddu $v0, $zero, $zero

.L800EB39C:
/* 08484C 800EB39C 3C028011 */  lui   $v0, 0x8011
/* 084850 800EB3A0 8C42CFD8 */  lw    $v0, -0x3028($v0)
/* 084854 800EB3A4 1040000A */  beqz  $v0, .L800EB3D0
/* 084858 800EB3A8 24020001 */   addiu $v0, $zero, 1
/* 08485C 800EB3AC 3C018011 */  lui   $at, 0x8011
/* 084860 800EB3B0 AC22CFE0 */  sw    $v0, -0x3020($at)
/* 084864 800EB3B4 24020008 */  addiu $v0, $zero, 8
/* 084868 800EB3B8 3C018011 */  lui   $at, 0x8011
/* 08486C 800EB3BC AC22CFE8 */  sw    $v0, -0x3018($at)
/* 084870 800EB3C0 0C03A9B3 */  jal   func_800EA6CC
/* 084874 800EB3C4 00000000 */   nop   
/* 084878 800EB3C8 0803ACF5 */  j     .L800EB3D4
/* 08487C 800EB3CC 24020001 */   addiu $v0, $zero, 1

.L800EB3D0:
/* 084880 800EB3D0 0000102D */  daddu $v0, $zero, $zero
.L800EB3D4:
/* 084884 800EB3D4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 084888 800EB3D8 03E00008 */  jr    $ra
/* 08488C 800EB3DC 27BD0018 */   addiu $sp, $sp, 0x18

