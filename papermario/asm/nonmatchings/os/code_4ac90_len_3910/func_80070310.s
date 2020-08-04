.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070310
/* 04B710 80070310 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B714 80070314 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B718 80070318 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B71C 8007031C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B720 80070320 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B724 80070324 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B728 80070328 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B72C 8007032C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B730 80070330 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B734 80070334 0C016959 */  jal   play_effect
/* 04B738 80070338 2404001C */   addiu $a0, $zero, 0x1c
/* 04B73C 8007033C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B740 80070340 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B744 80070344 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B748 80070348 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B74C 8007034C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B750 80070350 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B754 80070354 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B758 80070358 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B75C 8007035C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B760 80070360 3C018008 */  lui   $at, 0x8008
/* 04B764 80070364 8C21F4B0 */  lw    $at, -0xb50($at)
/* 04B768 80070368 00200008 */  jr    $at
/* 04B76C 8007036C 00000000 */   nop   
