.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80070FD0
/* 04C3D0 80070FD0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04C3D4 80070FD4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04C3D8 80070FD8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04C3DC 80070FDC AFA60018 */  sw    $a2, 0x18($sp)
/* 04C3E0 80070FE0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04C3E4 80070FE4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04C3E8 80070FE8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04C3EC 80070FEC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04C3F0 80070FF0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04C3F4 80070FF4 0C016959 */  jal   play_effect
/* 04C3F8 80070FF8 2404003E */   addiu $a0, $zero, 0x3e
/* 04C3FC 80070FFC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04C400 80071000 8FA50014 */  lw    $a1, 0x14($sp)
/* 04C404 80071004 8FA60018 */  lw    $a2, 0x18($sp)
/* 04C408 80071008 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04C40C 8007100C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04C410 80071010 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04C414 80071014 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04C418 80071018 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04C41C 8007101C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04C420 80071020 3C018008 */  lui   $at, 0x8008
/* 04C424 80071024 8C21F7E0 */  lw    $at, -0x820($at)
/* 04C428 80071028 00200008 */  jr    $at
/* 04C42C 8007102C 00000000 */   nop   
