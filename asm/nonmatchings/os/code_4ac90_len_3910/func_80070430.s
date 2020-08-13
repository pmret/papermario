.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80070430
/* 04B830 80070430 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04B834 80070434 AFA40010 */  sw    $a0, 0x10($sp)
/* 04B838 80070438 AFA50014 */  sw    $a1, 0x14($sp)
/* 04B83C 8007043C AFA60018 */  sw    $a2, 0x18($sp)
/* 04B840 80070440 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04B844 80070444 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04B848 80070448 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04B84C 8007044C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04B850 80070450 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04B854 80070454 0C016959 */  jal   play_effect
/* 04B858 80070458 2404001F */   addiu $a0, $zero, 0x1f
/* 04B85C 8007045C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04B860 80070460 8FA50014 */  lw    $a1, 0x14($sp)
/* 04B864 80070464 8FA60018 */  lw    $a2, 0x18($sp)
/* 04B868 80070468 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04B86C 8007046C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04B870 80070470 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04B874 80070474 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04B878 80070478 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04B87C 8007047C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04B880 80070480 3C018008 */  lui   $at, 0x8008
/* 04B884 80070484 8C21F4F8 */  lw    $at, -0xb08($at)
/* 04B888 80070488 00200008 */  jr    $at
/* 04B88C 8007048C 00000000 */   nop   
