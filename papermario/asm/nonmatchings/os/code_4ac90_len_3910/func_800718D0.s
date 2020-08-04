.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800718D0
/* 04CCD0 800718D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CCD4 800718D4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CCD8 800718D8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CCDC 800718DC AFA60018 */  sw    $a2, 0x18($sp)
/* 04CCE0 800718E0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CCE4 800718E4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CCE8 800718E8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CCEC 800718EC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CCF0 800718F0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CCF4 800718F4 0C016959 */  jal   play_effect
/* 04CCF8 800718F8 24040056 */   addiu $a0, $zero, 0x56
/* 04CCFC 800718FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CD00 80071900 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CD04 80071904 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CD08 80071908 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CD0C 8007190C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CD10 80071910 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CD14 80071914 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CD18 80071918 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CD1C 8007191C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CD20 80071920 3C018008 */  lui   $at, 0x8008
/* 04CD24 80071924 8C21FA20 */  lw    $at, -0x5e0($at)
/* 04CD28 80071928 00200008 */  jr    $at
/* 04CD2C 8007192C 00000000 */   nop   
