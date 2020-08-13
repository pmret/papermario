.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel sprintf
/* 0408F0 800654F0 AFA50004 */  sw    $a1, 4($sp)
/* 0408F4 800654F4 AFA60008 */  sw    $a2, 8($sp)
/* 0408F8 800654F8 AFA7000C */  sw    $a3, 0xc($sp)
/* 0408FC 800654FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 040900 80065500 AFB00010 */  sw    $s0, 0x10($sp)
/* 040904 80065504 00808021 */  addu  $s0, $a0, $zero
/* 040908 80065508 00A03021 */  addu  $a2, $a1, $zero
/* 04090C 8006550C 3C048006 */  lui   $a0, 0x8006
/* 040910 80065510 24845548 */  addiu $a0, $a0, 0x5548
/* 040914 80065514 02002821 */  addu  $a1, $s0, $zero
/* 040918 80065518 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04091C 8006551C 0C0192A8 */  jal   _Printf
/* 040920 80065520 27A70020 */   addiu $a3, $sp, 0x20
/* 040924 80065524 00401821 */  addu  $v1, $v0, $zero
/* 040928 80065528 04600002 */  bltz  $v1, .L80065534
/* 04092C 8006552C 02031021 */   addu  $v0, $s0, $v1
/* 040930 80065530 A0400000 */  sb    $zero, ($v0)
.L80065534:
/* 040934 80065534 00601021 */  addu  $v0, $v1, $zero
/* 040938 80065538 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04093C 8006553C 8FB00010 */  lw    $s0, 0x10($sp)
/* 040940 80065540 03E00008 */  jr    $ra
/* 040944 80065544 27BD0018 */   addiu $sp, $sp, 0x18

