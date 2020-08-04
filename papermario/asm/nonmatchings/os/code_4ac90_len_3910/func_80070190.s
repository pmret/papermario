.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80070190
/* 04B590 80070190 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B594 80070194 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B598 80070198 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B59C 8007019C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B5A0 800701A0 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B5A4 800701A4 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B5A8 800701A8 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B5AC 800701AC E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B5B0 800701B0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B5B4 800701B4 0C016959 */  jal   play_effect
/* 04B5B8 800701B8 24040018 */   addiu $a0, $zero, 0x18
/* 04B5BC 800701BC 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B5C0 800701C0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B5C4 800701C4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B5C8 800701C8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B5CC 800701CC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B5D0 800701D0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B5D4 800701D4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B5D8 800701D8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B5DC 800701DC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B5E0 800701E0 3C018008 */  lui   $at, 0x8008
/* 04B5E4 800701E4 8C21F450 */  lw    $at, -0xbb0($at)
/* 04B5E8 800701E8 00200008 */  jr    $at
/* 04B5EC 800701EC 00000000 */   nop   
