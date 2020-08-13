.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80072950
/* 04DD50 80072950 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DD54 80072954 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DD58 80072958 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DD5C 8007295C AFA60018 */  sw    $a2, 0x18($sp)
/* 04DD60 80072960 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DD64 80072964 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DD68 80072968 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DD6C 8007296C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DD70 80072970 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DD74 80072974 0C016959 */  jal   play_effect
/* 04DD78 80072978 24040082 */   addiu $a0, $zero, 0x82
/* 04DD7C 8007297C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DD80 80072980 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DD84 80072984 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DD88 80072988 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DD8C 8007298C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DD90 80072990 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DD94 80072994 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DD98 80072998 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DD9C 8007299C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DDA0 800729A0 3C018008 */  lui   $at, 0x8008
/* 04DDA4 800729A4 8C21FE40 */  lw    $at, -0x1c0($at)
/* 04DDA8 800729A8 00200008 */  jr    $at
/* 04DDAC 800729AC 00000000 */   nop   
