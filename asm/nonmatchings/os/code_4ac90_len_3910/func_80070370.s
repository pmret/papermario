.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80070370
/* 04B770 80070370 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B774 80070374 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B778 80070378 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B77C 8007037C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B780 80070380 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B784 80070384 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B788 80070388 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B78C 8007038C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B790 80070390 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B794 80070394 0C016959 */  jal   play_effect
/* 04B798 80070398 2404001D */   addiu $a0, $zero, 0x1d
/* 04B79C 8007039C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B7A0 800703A0 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B7A4 800703A4 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B7A8 800703A8 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B7AC 800703AC C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B7B0 800703B0 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B7B4 800703B4 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B7B8 800703B8 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B7BC 800703BC 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B7C0 800703C0 3C018008 */  lui   $at, 0x8008
/* 04B7C4 800703C4 8C21F4C8 */  lw    $at, -0xb38($at)
/* 04B7C8 800703C8 00200008 */  jr    $at
/* 04B7CC 800703CC 00000000 */   nop   
