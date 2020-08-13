.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80071F30
/* 04D330 80071F30 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D334 80071F34 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D338 80071F38 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D33C 80071F3C AFA60018 */  sw    $a2, 0x18($sp)
/* 04D340 80071F40 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D344 80071F44 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D348 80071F48 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D34C 80071F4C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D350 80071F50 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D354 80071F54 0C016959 */  jal   play_effect
/* 04D358 80071F58 24040067 */   addiu $a0, $zero, 0x67
/* 04D35C 80071F5C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D360 80071F60 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D364 80071F64 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D368 80071F68 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D36C 80071F6C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D370 80071F70 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D374 80071F74 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D378 80071F78 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D37C 80071F7C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D380 80071F80 3C018008 */  lui   $at, 0x8008
/* 04D384 80071F84 8C21FBB8 */  lw    $at, -0x448($at)
/* 04D388 80071F88 00200008 */  jr    $at
/* 04D38C 80071F8C 00000000 */   nop   
