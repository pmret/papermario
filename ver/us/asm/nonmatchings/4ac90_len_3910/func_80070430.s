.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070430
/* 4B830 80070430 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B834 80070434 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B838 80070438 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B83C 8007043C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B840 80070440 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B844 80070444 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B848 80070448 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B84C 8007044C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B850 80070450 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B854 80070454 0C016959 */  jal       load_effect
/* 4B858 80070458 2404001F */   addiu    $a0, $zero, 0x1f
/* 4B85C 8007045C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B860 80070460 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B864 80070464 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B868 80070468 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B86C 8007046C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B870 80070470 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B874 80070474 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B878 80070478 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B87C 8007047C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B880 80070480 3C018008 */  lui       $at, %hi(gEffectTable+0x2E8)
/* 4B884 80070484 8C21F4F8 */  lw        $at, %lo(gEffectTable+0x2E8)($at)
/* 4B888 80070488 00200008 */  jr        $at
/* 4B88C 8007048C 00000000 */   nop
