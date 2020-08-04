.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800728F0
/* 04DCF0 800728F0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DCF4 800728F4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DCF8 800728F8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DCFC 800728FC AFA60018 */  sw    $a2, 0x18($sp)
/* 04DD00 80072900 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DD04 80072904 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DD08 80072908 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DD0C 8007290C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DD10 80072910 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DD14 80072914 0C016959 */  jal   play_effect
/* 04DD18 80072918 24040081 */   addiu $a0, $zero, 0x81
/* 04DD1C 8007291C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DD20 80072920 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DD24 80072924 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DD28 80072928 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DD2C 8007292C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DD30 80072930 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DD34 80072934 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DD38 80072938 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DD3C 8007293C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DD40 80072940 3C018008 */  lui   $at, 0x8008
/* 04DD44 80072944 8C21FE28 */  lw    $at, -0x1d8($at)
/* 04DD48 80072948 00200008 */  jr    $at
/* 04DD4C 8007294C 00000000 */   nop   
