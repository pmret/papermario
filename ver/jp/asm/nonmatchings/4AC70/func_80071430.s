.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071430
/* 4C830 80071430 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C834 80071434 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C838 80071438 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C83C 8007143C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C840 80071440 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C844 80071444 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C848 80071448 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C84C 8007144C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C850 80071450 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C854 80071454 0C016885 */  jal       func_8005A214
/* 4C858 80071458 2404004A */   addiu    $a0, $zero, 0x4a
/* 4C85C 8007145C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C860 80071460 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C864 80071464 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C868 80071468 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C86C 8007146C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C870 80071470 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C874 80071474 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C878 80071478 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C87C 8007147C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C880 80071480 3C018008 */  lui       $at, %hi(D_8007F8D0)
/* 4C884 80071484 8C21F8D0 */  lw        $at, %lo(D_8007F8D0)($at)
/* 4C888 80071488 00200008 */  jr        $at
/* 4C88C 8007148C 00000000 */   nop
