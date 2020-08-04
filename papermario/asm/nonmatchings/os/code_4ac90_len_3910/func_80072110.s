.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80072110
/* 04D510 80072110 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D514 80072114 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D518 80072118 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D51C 8007211C AFA60018 */  sw    $a2, 0x18($sp)
/* 04D520 80072120 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D524 80072124 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D528 80072128 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D52C 8007212C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D530 80072130 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D534 80072134 0C016959 */  jal   play_effect
/* 04D538 80072138 2404006C */   addiu $a0, $zero, 0x6c
/* 04D53C 8007213C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D540 80072140 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D544 80072144 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D548 80072148 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D54C 8007214C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D550 80072150 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D554 80072154 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D558 80072158 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D55C 8007215C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D560 80072160 3C018008 */  lui   $at, 0x8008
/* 04D564 80072164 8C21FC30 */  lw    $at, -0x3d0($at)
/* 04D568 80072168 00200008 */  jr    $at
/* 04D56C 8007216C 00000000 */   nop   
