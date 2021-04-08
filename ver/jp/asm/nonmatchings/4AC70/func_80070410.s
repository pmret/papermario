.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070410
/* 4B810 80070410 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B814 80070414 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B818 80070418 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B81C 8007041C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B820 80070420 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B824 80070424 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B828 80070428 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B82C 8007042C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B830 80070430 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B834 80070434 0C016885 */  jal       func_8005A214
/* 4B838 80070438 2404001F */   addiu    $a0, $zero, 0x1f
/* 4B83C 8007043C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B840 80070440 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B844 80070444 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B848 80070448 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B84C 8007044C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B850 80070450 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B854 80070454 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B858 80070458 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B85C 8007045C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B860 80070460 3C018008 */  lui       $at, %hi(D_8007F4C8)
/* 4B864 80070464 8C21F4C8 */  lw        $at, %lo(D_8007F4C8)($at)
/* 4B868 80070468 00200008 */  jr        $at
/* 4B86C 8007046C 00000000 */   nop
