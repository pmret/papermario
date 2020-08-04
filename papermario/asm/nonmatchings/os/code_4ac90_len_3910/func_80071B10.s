.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80071B10
/* 04CF10 80071B10 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CF14 80071B14 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CF18 80071B18 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CF1C 80071B1C AFA60018 */  sw    $a2, 0x18($sp)
/* 04CF20 80071B20 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CF24 80071B24 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CF28 80071B28 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CF2C 80071B2C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CF30 80071B30 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CF34 80071B34 0C016959 */  jal   play_effect
/* 04CF38 80071B38 2404005C */   addiu $a0, $zero, 0x5c
/* 04CF3C 80071B3C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CF40 80071B40 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CF44 80071B44 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CF48 80071B48 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CF4C 80071B4C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CF50 80071B50 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CF54 80071B54 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CF58 80071B58 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CF5C 80071B5C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CF60 80071B60 3C018008 */  lui   $at, 0x8008
/* 04CF64 80071B64 8C21FAB0 */  lw    $at, -0x550($at)
/* 04CF68 80071B68 00200008 */  jr    $at
/* 04CF6C 80071B6C 00000000 */   nop   
