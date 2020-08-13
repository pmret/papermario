.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80072830
/* 04DC30 80072830 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DC34 80072834 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DC38 80072838 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DC3C 8007283C AFA60018 */  sw    $a2, 0x18($sp)
/* 04DC40 80072840 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DC44 80072844 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DC48 80072848 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DC4C 8007284C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DC50 80072850 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DC54 80072854 0C016959 */  jal   play_effect
/* 04DC58 80072858 2404007F */   addiu $a0, $zero, 0x7f
/* 04DC5C 8007285C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DC60 80072860 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DC64 80072864 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DC68 80072868 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DC6C 8007286C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DC70 80072870 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DC74 80072874 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DC78 80072878 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DC7C 8007287C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DC80 80072880 3C018008 */  lui   $at, 0x8008
/* 04DC84 80072884 8C21FDF8 */  lw    $at, -0x208($at)
/* 04DC88 80072888 00200008 */  jr    $at
/* 04DC8C 8007288C 00000000 */   nop   
