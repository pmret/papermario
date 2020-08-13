.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel al_LoadPER
/* 02F8F8 800544F8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 02F8FC 800544FC AFB20028 */  sw    $s2, 0x28($sp)
/* 02F900 80054500 0080902D */  daddu $s2, $a0, $zero
/* 02F904 80054504 AFB00020 */  sw    $s0, 0x20($sp)
/* 02F908 80054508 00A0802D */  daddu $s0, $a1, $zero
/* 02F90C 8005450C 0200202D */  daddu $a0, $s0, $zero
/* 02F910 80054510 27A50010 */  addiu $a1, $sp, 0x10
/* 02F914 80054514 24060010 */  addiu $a2, $zero, 0x10
/* 02F918 80054518 AFBF002C */  sw    $ra, 0x2c($sp)
/* 02F91C 8005451C 0C015380 */  jal   al_DmaCopy
/* 02F920 80054520 AFB10024 */   sw    $s1, 0x24($sp)
/* 02F924 80054524 26040010 */  addiu $a0, $s0, 0x10
/* 02F928 80054528 8FB00014 */  lw    $s0, 0x14($sp)
/* 02F92C 8005452C 8E450054 */  lw    $a1, 0x54($s2)
/* 02F930 80054530 2610FFF0 */  addiu $s0, $s0, -0x10
/* 02F934 80054534 0C015380 */  jal   al_DmaCopy
/* 02F938 80054538 0200302D */   daddu $a2, $s0, $zero
/* 02F93C 8005453C 3C0238E3 */  lui   $v0, 0x38e3
/* 02F940 80054540 34428E39 */  ori   $v0, $v0, 0x8e39
/* 02F944 80054544 02020019 */  multu $s0, $v0
/* 02F948 80054548 24020006 */  addiu $v0, $zero, 6
/* 02F94C 8005454C 00003810 */  mfhi  $a3
/* 02F950 80054550 00071942 */  srl   $v1, $a3, 5
/* 02F954 80054554 00438823 */  subu  $s1, $v0, $v1
/* 02F958 80054558 1A200010 */  blez  $s1, .L8005459C
/* 02F95C 8005455C 26440008 */   addiu $a0, $s2, 8
/* 02F960 80054560 2406000C */  addiu $a2, $zero, 0xc
/* 02F964 80054564 000310C0 */  sll   $v0, $v1, 3
/* 02F968 80054568 00431021 */  addu  $v0, $v0, $v1
/* 02F96C 8005456C 8E500054 */  lw    $s0, 0x54($s2)
/* 02F970 80054570 00021100 */  sll   $v0, $v0, 4
/* 02F974 80054574 02028021 */  addu  $s0, $s0, $v0
/* 02F978 80054578 0C0153DD */  jal   al_CopyWords
/* 02F97C 8005457C 0200282D */   daddu $a1, $s0, $zero
/* 02F980 80054580 0200202D */  daddu $a0, $s0, $zero
/* 02F984 80054584 2485000C */  addiu $a1, $a0, 0xc
/* 02F988 80054588 001130C0 */  sll   $a2, $s1, 3
/* 02F98C 8005458C 00D13021 */  addu  $a2, $a2, $s1
/* 02F990 80054590 00063100 */  sll   $a2, $a2, 4
/* 02F994 80054594 0C0153DD */  jal   al_CopyWords
/* 02F998 80054598 24C6FFF4 */   addiu $a2, $a2, -0xc
.L8005459C:
/* 02F99C 8005459C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 02F9A0 800545A0 8FB20028 */  lw    $s2, 0x28($sp)
/* 02F9A4 800545A4 8FB10024 */  lw    $s1, 0x24($sp)
/* 02F9A8 800545A8 8FB00020 */  lw    $s0, 0x20($sp)
/* 02F9AC 800545AC 03E00008 */  jr    $ra
/* 02F9B0 800545B0 27BD0030 */   addiu $sp, $sp, 0x30

