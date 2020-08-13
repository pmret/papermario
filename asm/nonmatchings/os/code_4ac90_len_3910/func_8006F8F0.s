.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8006F8F0
/* 04ACF0 8006F8F0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04ACF4 8006F8F4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04ACF8 8006F8F8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04ACFC 8006F8FC AFA60018 */  sw    $a2, 0x18($sp)
/* 04AD00 8006F900 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04AD04 8006F904 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04AD08 8006F908 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04AD0C 8006F90C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04AD10 8006F910 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04AD14 8006F914 0C016959 */  jal   play_effect
/* 04AD18 8006F918 24040001 */   addiu $a0, $zero, 1
/* 04AD1C 8006F91C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04AD20 8006F920 8FA50014 */  lw    $a1, 0x14($sp)
/* 04AD24 8006F924 8FA60018 */  lw    $a2, 0x18($sp)
/* 04AD28 8006F928 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04AD2C 8006F92C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04AD30 8006F930 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04AD34 8006F934 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04AD38 8006F938 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04AD3C 8006F93C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04AD40 8006F940 3C018008 */  lui   $at, 0x8008
/* 04AD44 8006F944 8C21F228 */  lw    $at, -0xdd8($at)
/* 04AD48 8006F948 00200008 */  jr    $at
/* 04AD4C 8006F94C 00000000 */   nop   
/* 04AD50 8006F950 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04AD54 8006F954 AFA40010 */  sw    $a0, 0x10($sp)
/* 04AD58 8006F958 AFA50014 */  sw    $a1, 0x14($sp)
/* 04AD5C 8006F95C AFA60018 */  sw    $a2, 0x18($sp)
/* 04AD60 8006F960 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04AD64 8006F964 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04AD68 8006F968 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04AD6C 8006F96C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04AD70 8006F970 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04AD74 8006F974 0C016959 */  jal   play_effect
/* 04AD78 8006F978 24040002 */   addiu $a0, $zero, 2
/* 04AD7C 8006F97C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04AD80 8006F980 8FA50014 */  lw    $a1, 0x14($sp)
/* 04AD84 8006F984 8FA60018 */  lw    $a2, 0x18($sp)
/* 04AD88 8006F988 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04AD8C 8006F98C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04AD90 8006F990 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04AD94 8006F994 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04AD98 8006F998 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04AD9C 8006F99C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04ADA0 8006F9A0 3C018008 */  lui   $at, 0x8008
/* 04ADA4 8006F9A4 8C21F240 */  lw    $at, -0xdc0($at)
/* 04ADA8 8006F9A8 00200008 */  jr    $at
/* 04ADAC 8006F9AC 00000000 */   nop   
/* 04ADB0 8006F9B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04ADB4 8006F9B4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04ADB8 8006F9B8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04ADBC 8006F9BC AFA60018 */  sw    $a2, 0x18($sp)
/* 04ADC0 8006F9C0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04ADC4 8006F9C4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04ADC8 8006F9C8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04ADCC 8006F9CC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04ADD0 8006F9D0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04ADD4 8006F9D4 0C016959 */  jal   play_effect
/* 04ADD8 8006F9D8 24040003 */   addiu $a0, $zero, 3
/* 04ADDC 8006F9DC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04ADE0 8006F9E0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04ADE4 8006F9E4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04ADE8 8006F9E8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04ADEC 8006F9EC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04ADF0 8006F9F0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04ADF4 8006F9F4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04ADF8 8006F9F8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04ADFC 8006F9FC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04AE00 8006FA00 3C018008 */  lui   $at, 0x8008
/* 04AE04 8006FA04 8C21F258 */  lw    $at, -0xda8($at)
/* 04AE08 8006FA08 00200008 */  jr    $at
/* 04AE0C 8006FA0C 00000000 */   nop   
/* 04AE10 8006FA10 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04AE14 8006FA14 AFA40010 */  sw    $a0, 0x10($sp)
/* 04AE18 8006FA18 AFA50014 */  sw    $a1, 0x14($sp)
/* 04AE1C 8006FA1C AFA60018 */  sw    $a2, 0x18($sp)
/* 04AE20 8006FA20 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04AE24 8006FA24 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04AE28 8006FA28 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04AE2C 8006FA2C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04AE30 8006FA30 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04AE34 8006FA34 0C016959 */  jal   play_effect
/* 04AE38 8006FA38 24040004 */   addiu $a0, $zero, 4
/* 04AE3C 8006FA3C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04AE40 8006FA40 8FA50014 */  lw    $a1, 0x14($sp)
/* 04AE44 8006FA44 8FA60018 */  lw    $a2, 0x18($sp)
/* 04AE48 8006FA48 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04AE4C 8006FA4C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04AE50 8006FA50 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04AE54 8006FA54 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04AE58 8006FA58 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04AE5C 8006FA5C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04AE60 8006FA60 3C018008 */  lui   $at, 0x8008
/* 04AE64 8006FA64 8C21F270 */  lw    $at, -0xd90($at)
/* 04AE68 8006FA68 00200008 */  jr    $at
/* 04AE6C 8006FA6C 00000000 */   nop   
/* 04AE70 8006FA70 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04AE74 8006FA74 AFA40010 */  sw    $a0, 0x10($sp)
/* 04AE78 8006FA78 AFA50014 */  sw    $a1, 0x14($sp)
/* 04AE7C 8006FA7C AFA60018 */  sw    $a2, 0x18($sp)
/* 04AE80 8006FA80 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04AE84 8006FA84 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04AE88 8006FA88 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04AE8C 8006FA8C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04AE90 8006FA90 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04AE94 8006FA94 0C016959 */  jal   play_effect
/* 04AE98 8006FA98 24040005 */   addiu $a0, $zero, 5
/* 04AE9C 8006FA9C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04AEA0 8006FAA0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04AEA4 8006FAA4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04AEA8 8006FAA8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04AEAC 8006FAAC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04AEB0 8006FAB0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04AEB4 8006FAB4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04AEB8 8006FAB8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04AEBC 8006FABC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04AEC0 8006FAC0 3C018008 */  lui   $at, 0x8008
/* 04AEC4 8006FAC4 8C21F288 */  lw    $at, -0xd78($at)
/* 04AEC8 8006FAC8 00200008 */  jr    $at
/* 04AECC 8006FACC 00000000 */   nop   
