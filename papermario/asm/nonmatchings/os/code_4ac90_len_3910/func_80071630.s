.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80071630
/* 04CA30 80071630 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CA34 80071634 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CA38 80071638 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CA3C 8007163C AFA60018 */  sw    $a2, 0x18($sp)
/* 04CA40 80071640 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CA44 80071644 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CA48 80071648 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CA4C 8007164C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CA50 80071650 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CA54 80071654 0C016959 */  jal   play_effect
/* 04CA58 80071658 2404004F */   addiu $a0, $zero, 0x4f
/* 04CA5C 8007165C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CA60 80071660 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CA64 80071664 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CA68 80071668 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CA6C 8007166C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CA70 80071670 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CA74 80071674 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CA78 80071678 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CA7C 8007167C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CA80 80071680 3C018008 */  lui   $at, 0x8008
/* 04CA84 80071684 8C21F978 */  lw    $at, -0x688($at)
/* 04CA88 80071688 00200008 */  jr    $at
/* 04CA8C 8007168C 00000000 */   nop   
/* 04CA90 80071690 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CA94 80071694 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CA98 80071698 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CA9C 8007169C AFA60018 */  sw    $a2, 0x18($sp)
/* 04CAA0 800716A0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CAA4 800716A4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CAA8 800716A8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CAAC 800716AC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CAB0 800716B0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CAB4 800716B4 0C016959 */  jal   play_effect
/* 04CAB8 800716B8 24040050 */   addiu $a0, $zero, 0x50
/* 04CABC 800716BC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CAC0 800716C0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CAC4 800716C4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CAC8 800716C8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CACC 800716CC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CAD0 800716D0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CAD4 800716D4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CAD8 800716D8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CADC 800716DC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CAE0 800716E0 3C018008 */  lui   $at, 0x8008
/* 04CAE4 800716E4 8C21F990 */  lw    $at, -0x670($at)
/* 04CAE8 800716E8 00200008 */  jr    $at
/* 04CAEC 800716EC 00000000 */   nop   
