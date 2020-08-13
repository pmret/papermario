.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070A90
/* 04BE90 80070A90 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04BE94 80070A94 AFA40010 */  sw    $a0, 0x10($sp)
/* 04BE98 80070A98 AFA50014 */  sw    $a1, 0x14($sp)
/* 04BE9C 80070A9C AFA60018 */  sw    $a2, 0x18($sp)
/* 04BEA0 80070AA0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04BEA4 80070AA4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04BEA8 80070AA8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04BEAC 80070AAC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04BEB0 80070AB0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04BEB4 80070AB4 0C016959 */  jal   play_effect
/* 04BEB8 80070AB8 24040030 */   addiu $a0, $zero, 0x30
/* 04BEBC 80070ABC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04BEC0 80070AC0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04BEC4 80070AC4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04BEC8 80070AC8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04BECC 80070ACC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04BED0 80070AD0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04BED4 80070AD4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04BED8 80070AD8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04BEDC 80070ADC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04BEE0 80070AE0 3C018008 */  lui   $at, 0x8008
/* 04BEE4 80070AE4 8C21F690 */  lw    $at, -0x970($at)
/* 04BEE8 80070AE8 00200008 */  jr    $at
/* 04BEEC 80070AEC 00000000 */   nop   
