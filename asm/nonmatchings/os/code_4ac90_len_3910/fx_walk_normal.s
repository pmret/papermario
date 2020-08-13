.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel fx_walk_normal
/* 04AF30 8006FB30 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04AF34 8006FB34 AFA40010 */  sw    $a0, 0x10($sp)
/* 04AF38 8006FB38 AFA50014 */  sw    $a1, 0x14($sp)
/* 04AF3C 8006FB3C AFA60018 */  sw    $a2, 0x18($sp)
/* 04AF40 8006FB40 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04AF44 8006FB44 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04AF48 8006FB48 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04AF4C 8006FB4C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04AF50 8006FB50 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04AF54 8006FB54 0C016959 */  jal   play_effect
/* 04AF58 8006FB58 24040007 */   addiu $a0, $zero, 7
/* 04AF5C 8006FB5C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04AF60 8006FB60 8FA50014 */  lw    $a1, 0x14($sp)
/* 04AF64 8006FB64 8FA60018 */  lw    $a2, 0x18($sp)
/* 04AF68 8006FB68 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04AF6C 8006FB6C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04AF70 8006FB70 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04AF74 8006FB74 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04AF78 8006FB78 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04AF7C 8006FB7C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04AF80 8006FB80 3C018008 */  lui   $at, 0x8008
/* 04AF84 8006FB84 8C21F2B8 */  lw    $at, -0xd48($at)
/* 04AF88 8006FB88 00200008 */  jr    $at
/* 04AF8C 8006FB8C 00000000 */   nop   
