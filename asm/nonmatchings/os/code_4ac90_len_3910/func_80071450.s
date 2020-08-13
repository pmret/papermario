.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80071450
/* 04C850 80071450 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C854 80071454 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C858 80071458 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C85C 8007145C AFA60018 */  sw    $a2, 0x18($sp)
/* 04C860 80071460 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C864 80071464 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C868 80071468 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C86C 8007146C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C870 80071470 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C874 80071474 0C016959 */  jal   play_effect
/* 04C878 80071478 2404004A */   addiu $a0, $zero, 0x4a
/* 04C87C 8007147C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C880 80071480 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C884 80071484 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C888 80071488 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C88C 8007148C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C890 80071490 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C894 80071494 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C898 80071498 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C89C 8007149C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C8A0 800714A0 3C018008 */  lui   $at, 0x8008
/* 04C8A4 800714A4 8C21F900 */  lw    $at, -0x700($at)
/* 04C8A8 800714A8 00200008 */  jr    $at
/* 04C8AC 800714AC 00000000 */   nop   
