.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8006FEF0
/* 04B2F0 8006FEF0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B2F4 8006FEF4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B2F8 8006FEF8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B2FC 8006FEFC AFA60018 */  sw    $a2, 0x18($sp)
/* 04B300 8006FF00 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B304 8006FF04 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B308 8006FF08 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B30C 8006FF0C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B310 8006FF10 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B314 8006FF14 0C016959 */  jal   play_effect
/* 04B318 8006FF18 24040011 */   addiu $a0, $zero, 0x11
/* 04B31C 8006FF1C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B320 8006FF20 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B324 8006FF24 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B328 8006FF28 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B32C 8006FF2C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B330 8006FF30 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B334 8006FF34 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B338 8006FF38 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B33C 8006FF3C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B340 8006FF40 3C018008 */  lui   $at, 0x8008
/* 04B344 8006FF44 8C21F3A8 */  lw    $at, -0xc58($at)
/* 04B348 8006FF48 00200008 */  jr    $at
/* 04B34C 8006FF4C 00000000 */   nop   
