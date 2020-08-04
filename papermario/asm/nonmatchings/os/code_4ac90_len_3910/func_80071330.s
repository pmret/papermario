.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80071330
/* 04C730 80071330 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C734 80071334 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C738 80071338 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C73C 8007133C AFA60018 */  sw    $a2, 0x18($sp)
/* 04C740 80071340 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C744 80071344 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C748 80071348 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C74C 8007134C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C750 80071350 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C754 80071354 0C016959 */  jal   play_effect
/* 04C758 80071358 24040047 */   addiu $a0, $zero, 0x47
/* 04C75C 8007135C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C760 80071360 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C764 80071364 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C768 80071368 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C76C 8007136C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C770 80071370 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C774 80071374 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C778 80071378 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C77C 8007137C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C780 80071380 3C018008 */  lui   $at, 0x8008
/* 04C784 80071384 8C21F8B8 */  lw    $at, -0x748($at)
/* 04C788 80071388 00200008 */  jr    $at
/* 04C78C 8007138C 00000000 */   nop   
