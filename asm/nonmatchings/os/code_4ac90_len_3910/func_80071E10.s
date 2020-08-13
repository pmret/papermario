.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80071E10
/* 04D210 80071E10 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D214 80071E14 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D218 80071E18 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D21C 80071E1C AFA60018 */  sw    $a2, 0x18($sp)
/* 04D220 80071E20 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D224 80071E24 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D228 80071E28 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D22C 80071E2C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D230 80071E30 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D234 80071E34 0C016959 */  jal   play_effect
/* 04D238 80071E38 24040064 */   addiu $a0, $zero, 0x64
/* 04D23C 80071E3C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D240 80071E40 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D244 80071E44 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D248 80071E48 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D24C 80071E4C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D250 80071E50 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D254 80071E54 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D258 80071E58 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D25C 80071E5C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D260 80071E60 3C018008 */  lui   $at, 0x8008
/* 04D264 80071E64 8C21FB70 */  lw    $at, -0x490($at)
/* 04D268 80071E68 00200008 */  jr    $at
/* 04D26C 80071E6C 00000000 */   nop   
