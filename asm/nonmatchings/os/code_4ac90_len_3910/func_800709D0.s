.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800709D0
/* 04BDD0 800709D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04BDD4 800709D4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04BDD8 800709D8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04BDDC 800709DC AFA60018 */  sw    $a2, 0x18($sp)
/* 04BDE0 800709E0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04BDE4 800709E4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04BDE8 800709E8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04BDEC 800709EC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04BDF0 800709F0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04BDF4 800709F4 0C016959 */  jal   play_effect
/* 04BDF8 800709F8 2404002E */   addiu $a0, $zero, 0x2e
/* 04BDFC 800709FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04BE00 80070A00 8FA50014 */  lw    $a1, 0x14($sp)
/* 04BE04 80070A04 8FA60018 */  lw    $a2, 0x18($sp)
/* 04BE08 80070A08 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04BE0C 80070A0C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04BE10 80070A10 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04BE14 80070A14 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04BE18 80070A18 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04BE1C 80070A1C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04BE20 80070A20 3C018008 */  lui   $at, 0x8008
/* 04BE24 80070A24 8C21F660 */  lw    $at, -0x9a0($at)
/* 04BE28 80070A28 00200008 */  jr    $at
/* 04BE2C 80070A2C 00000000 */   nop   
