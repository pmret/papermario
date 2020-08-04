.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800719F0
/* 04CDF0 800719F0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CDF4 800719F4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CDF8 800719F8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CDFC 800719FC AFA60018 */  sw    $a2, 0x18($sp)
/* 04CE00 80071A00 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CE04 80071A04 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CE08 80071A08 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CE0C 80071A0C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CE10 80071A10 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CE14 80071A14 0C016959 */  jal   play_effect
/* 04CE18 80071A18 24040059 */   addiu $a0, $zero, 0x59
/* 04CE1C 80071A1C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CE20 80071A20 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CE24 80071A24 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CE28 80071A28 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CE2C 80071A2C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CE30 80071A30 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CE34 80071A34 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CE38 80071A38 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CE3C 80071A3C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CE40 80071A40 3C018008 */  lui   $at, 0x8008
/* 04CE44 80071A44 8C21FA68 */  lw    $at, -0x598($at)
/* 04CE48 80071A48 00200008 */  jr    $at
/* 04CE4C 80071A4C 00000000 */   nop   
