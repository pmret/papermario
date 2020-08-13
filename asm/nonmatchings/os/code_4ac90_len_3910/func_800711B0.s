.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800711B0
/* 04C5B0 800711B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C5B4 800711B4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C5B8 800711B8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C5BC 800711BC AFA60018 */  sw    $a2, 0x18($sp)
/* 04C5C0 800711C0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C5C4 800711C4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C5C8 800711C8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C5CC 800711CC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C5D0 800711D0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C5D4 800711D4 0C016959 */  jal   play_effect
/* 04C5D8 800711D8 24040043 */   addiu $a0, $zero, 0x43
/* 04C5DC 800711DC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C5E0 800711E0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C5E4 800711E4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C5E8 800711E8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C5EC 800711EC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C5F0 800711F0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C5F4 800711F4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C5F8 800711F8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C5FC 800711FC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C600 80071200 3C018008 */  lui   $at, 0x8008
/* 04C604 80071204 8C21F858 */  lw    $at, -0x7a8($at)
/* 04C608 80071208 00200008 */  jr    $at
/* 04C60C 8007120C 00000000 */   nop   
