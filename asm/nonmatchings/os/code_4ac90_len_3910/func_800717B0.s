.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800717B0
/* 04CBB0 800717B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CBB4 800717B4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CBB8 800717B8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CBBC 800717BC AFA60018 */  sw    $a2, 0x18($sp)
/* 04CBC0 800717C0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CBC4 800717C4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CBC8 800717C8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CBCC 800717CC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CBD0 800717D0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CBD4 800717D4 0C016959 */  jal   play_effect
/* 04CBD8 800717D8 24040053 */   addiu $a0, $zero, 0x53
/* 04CBDC 800717DC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CBE0 800717E0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CBE4 800717E4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CBE8 800717E8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CBEC 800717EC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CBF0 800717F0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CBF4 800717F4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CBF8 800717F8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CBFC 800717FC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CC00 80071800 3C018008 */  lui   $at, 0x8008
/* 04CC04 80071804 8C21F9D8 */  lw    $at, -0x628($at)
/* 04CC08 80071808 00200008 */  jr    $at
/* 04CC0C 8007180C 00000000 */   nop   
/* 04CC10 80071810 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04CC14 80071814 AFA40010 */  sw    $a0, 0x10($sp)
/* 04CC18 80071818 AFA50014 */  sw    $a1, 0x14($sp)
/* 04CC1C 8007181C AFA60018 */  sw    $a2, 0x18($sp)
/* 04CC20 80071820 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04CC24 80071824 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04CC28 80071828 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04CC2C 8007182C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04CC30 80071830 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04CC34 80071834 0C016959 */  jal   play_effect
/* 04CC38 80071838 24040054 */   addiu $a0, $zero, 0x54
/* 04CC3C 8007183C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CC40 80071840 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CC44 80071844 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CC48 80071848 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CC4C 8007184C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CC50 80071850 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CC54 80071854 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CC58 80071858 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CC5C 8007185C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CC60 80071860 3C018008 */  lui   $at, 0x8008
/* 04CC64 80071864 8C21F9F0 */  lw    $at, -0x610($at)
/* 04CC68 80071868 00200008 */  jr    $at
/* 04CC6C 8007186C 00000000 */   nop   
