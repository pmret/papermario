.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80071F90
/* 04D390 80071F90 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04D394 80071F94 AFA40010 */  sw    $a0, 0x10($sp)
/* 04D398 80071F98 AFA50014 */  sw    $a1, 0x14($sp)
/* 04D39C 80071F9C AFA60018 */  sw    $a2, 0x18($sp)
/* 04D3A0 80071FA0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04D3A4 80071FA4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04D3A8 80071FA8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04D3AC 80071FAC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04D3B0 80071FB0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04D3B4 80071FB4 0C016959 */  jal   play_effect
/* 04D3B8 80071FB8 24040068 */   addiu $a0, $zero, 0x68
/* 04D3BC 80071FBC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04D3C0 80071FC0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04D3C4 80071FC4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04D3C8 80071FC8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04D3CC 80071FCC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04D3D0 80071FD0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04D3D4 80071FD4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04D3D8 80071FD8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04D3DC 80071FDC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04D3E0 80071FE0 3C018008 */  lui   $at, 0x8008
/* 04D3E4 80071FE4 8C21FBD0 */  lw    $at, -0x430($at)
/* 04D3E8 80071FE8 00200008 */  jr    $at
/* 04D3EC 80071FEC 00000000 */   nop   
