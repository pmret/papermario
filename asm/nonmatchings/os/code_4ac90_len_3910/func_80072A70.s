.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80072A70
/* 04DE70 80072A70 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04DE74 80072A74 AFA40010 */  sw    $a0, 0x10($sp)
/* 04DE78 80072A78 AFA50014 */  sw    $a1, 0x14($sp)
/* 04DE7C 80072A7C AFA60018 */  sw    $a2, 0x18($sp)
/* 04DE80 80072A80 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04DE84 80072A84 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04DE88 80072A88 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04DE8C 80072A8C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04DE90 80072A90 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04DE94 80072A94 0C016959 */  jal   play_effect
/* 04DE98 80072A98 24040085 */   addiu $a0, $zero, 0x85
/* 04DE9C 80072A9C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04DEA0 80072AA0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04DEA4 80072AA4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04DEA8 80072AA8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04DEAC 80072AAC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04DEB0 80072AB0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04DEB4 80072AB4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04DEB8 80072AB8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04DEBC 80072ABC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04DEC0 80072AC0 3C018008 */  lui   $at, 0x8008
/* 04DEC4 80072AC4 8C21FE88 */  lw    $at, -0x178($at)
/* 04DEC8 80072AC8 00200008 */  jr    $at
/* 04DECC 80072ACC 00000000 */   nop   
