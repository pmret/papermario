.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80070DF0
/* 04C1F0 80070DF0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C1F4 80070DF4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C1F8 80070DF8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C1FC 80070DFC AFA60018 */  sw    $a2, 0x18($sp)
/* 04C200 80070E00 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C204 80070E04 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C208 80070E08 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C20C 80070E0C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C210 80070E10 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C214 80070E14 0C016959 */  jal   play_effect
/* 04C218 80070E18 24040039 */   addiu $a0, $zero, 0x39
/* 04C21C 80070E1C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C220 80070E20 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C224 80070E24 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C228 80070E28 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C22C 80070E2C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C230 80070E30 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C234 80070E34 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C238 80070E38 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C23C 80070E3C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C240 80070E40 3C018008 */  lui   $at, 0x8008
/* 04C244 80070E44 8C21F768 */  lw    $at, -0x898($at)
/* 04C248 80070E48 00200008 */  jr    $at
/* 04C24C 80070E4C 00000000 */   nop   
