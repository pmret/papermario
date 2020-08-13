.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8006FD10
/* 04B110 8006FD10 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B114 8006FD14 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B118 8006FD18 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B11C 8006FD1C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B120 8006FD20 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B124 8006FD24 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B128 8006FD28 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B12C 8006FD2C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B130 8006FD30 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B134 8006FD34 0C016959 */  jal   play_effect
/* 04B138 8006FD38 2404000C */   addiu $a0, $zero, 0xc
/* 04B13C 8006FD3C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B140 8006FD40 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B144 8006FD44 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B148 8006FD48 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B14C 8006FD4C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B150 8006FD50 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B154 8006FD54 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B158 8006FD58 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B15C 8006FD5C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B160 8006FD60 3C018008 */  lui   $at, 0x8008
/* 04B164 8006FD64 8C21F330 */  lw    $at, -0xcd0($at)
/* 04B168 8006FD68 00200008 */  jr    $at
/* 04B16C 8006FD6C 00000000 */   nop   
