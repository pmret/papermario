.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8006FC50
/* 04B050 8006FC50 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B054 8006FC54 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B058 8006FC58 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B05C 8006FC5C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B060 8006FC60 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B064 8006FC64 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B068 8006FC68 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B06C 8006FC6C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B070 8006FC70 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B074 8006FC74 0C016959 */  jal   play_effect
/* 04B078 8006FC78 2404000A */   addiu $a0, $zero, 0xa
/* 04B07C 8006FC7C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B080 8006FC80 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B084 8006FC84 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B088 8006FC88 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B08C 8006FC8C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B090 8006FC90 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B094 8006FC94 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B098 8006FC98 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B09C 8006FC9C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B0A0 8006FCA0 3C018008 */  lui   $at, 0x8008
/* 04B0A4 8006FCA4 8C21F300 */  lw    $at, -0xd00($at)
/* 04B0A8 8006FCA8 00200008 */  jr    $at
/* 04B0AC 8006FCAC 00000000 */   nop   
