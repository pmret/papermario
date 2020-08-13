.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8006FCB0
/* 04B0B0 8006FCB0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B0B4 8006FCB4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B0B8 8006FCB8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B0BC 8006FCBC AFA60018 */  sw    $a2, 0x18($sp)
/* 04B0C0 8006FCC0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B0C4 8006FCC4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B0C8 8006FCC8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B0CC 8006FCCC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B0D0 8006FCD0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B0D4 8006FCD4 0C016959 */  jal   play_effect
/* 04B0D8 8006FCD8 2404000B */   addiu $a0, $zero, 0xb
/* 04B0DC 8006FCDC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B0E0 8006FCE0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B0E4 8006FCE4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B0E8 8006FCE8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B0EC 8006FCEC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B0F0 8006FCF0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B0F4 8006FCF4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B0F8 8006FCF8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B0FC 8006FCFC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B100 8006FD00 3C018008 */  lui   $at, 0x8008
/* 04B104 8006FD04 8C21F318 */  lw    $at, -0xce8($at)
/* 04B108 8006FD08 00200008 */  jr    $at
/* 04B10C 8006FD0C 00000000 */   nop   
