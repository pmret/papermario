.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800715D0
/* 04C9D0 800715D0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C9D4 800715D4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C9D8 800715D8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C9DC 800715DC AFA60018 */  sw    $a2, 0x18($sp)
/* 04C9E0 800715E0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C9E4 800715E4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C9E8 800715E8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C9EC 800715EC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C9F0 800715F0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C9F4 800715F4 0C016959 */  jal   play_effect
/* 04C9F8 800715F8 2404004E */   addiu $a0, $zero, 0x4e
/* 04C9FC 800715FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04CA00 80071600 8FA50014 */  lw    $a1, 0x14($sp)
/* 04CA04 80071604 8FA60018 */  lw    $a2, 0x18($sp)
/* 04CA08 80071608 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04CA0C 8007160C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04CA10 80071610 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04CA14 80071614 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04CA18 80071618 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04CA1C 8007161C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04CA20 80071620 3C018008 */  lui   $at, 0x8008
/* 04CA24 80071624 8C21F960 */  lw    $at, -0x6a0($at)
/* 04CA28 80071628 00200008 */  jr    $at
/* 04CA2C 8007162C 00000000 */   nop   
