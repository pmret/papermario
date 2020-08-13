.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80072AD0
/* 04DED0 80072AD0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DED4 80072AD4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DED8 80072AD8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DEDC 80072ADC AFA60018 */  sw    $a2, 0x18($sp)
/* 04DEE0 80072AE0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DEE4 80072AE4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DEE8 80072AE8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DEEC 80072AEC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DEF0 80072AF0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DEF4 80072AF4 0C016959 */  jal   play_effect
/* 04DEF8 80072AF8 24040086 */   addiu $a0, $zero, 0x86
/* 04DEFC 80072AFC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DF00 80072B00 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DF04 80072B04 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DF08 80072B08 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DF0C 80072B0C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DF10 80072B10 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DF14 80072B14 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DF18 80072B18 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DF1C 80072B1C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DF20 80072B20 3C018008 */  lui   $at, 0x8008
/* 04DF24 80072B24 8C21FEA0 */  lw    $at, -0x160($at)
/* 04DF28 80072B28 00200008 */  jr    $at
/* 04DF2C 80072B2C 00000000 */   nop   

