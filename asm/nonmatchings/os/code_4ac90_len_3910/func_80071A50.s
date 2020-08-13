.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80071A50
/* 04CE50 80071A50 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CE54 80071A54 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CE58 80071A58 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CE5C 80071A5C AFA60018 */  sw    $a2, 0x18($sp)
/* 04CE60 80071A60 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CE64 80071A64 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CE68 80071A68 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CE6C 80071A6C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CE70 80071A70 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CE74 80071A74 0C016959 */  jal   play_effect
/* 04CE78 80071A78 2404005A */   addiu $a0, $zero, 0x5a
/* 04CE7C 80071A7C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CE80 80071A80 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CE84 80071A84 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CE88 80071A88 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CE8C 80071A8C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CE90 80071A90 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CE94 80071A94 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CE98 80071A98 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CE9C 80071A9C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CEA0 80071AA0 3C018008 */  lui   $at, 0x8008
/* 04CEA4 80071AA4 8C21FA80 */  lw    $at, -0x580($at)
/* 04CEA8 80071AA8 00200008 */  jr    $at
/* 04CEAC 80071AAC 00000000 */   nop   
