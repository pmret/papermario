.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070730
/* 4BB30 80070730 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4BB34 80070734 AFA40010 */  sw        $a0, 0x10($sp)
/* 4BB38 80070738 AFA50014 */  sw        $a1, 0x14($sp)
/* 4BB3C 8007073C AFA60018 */  sw        $a2, 0x18($sp)
/* 4BB40 80070740 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4BB44 80070744 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4BB48 80070748 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4BB4C 8007074C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4BB50 80070750 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4BB54 80070754 0C016959 */  jal       load_effect
/* 4BB58 80070758 24040027 */   addiu    $a0, $zero, 0x27
/* 4BB5C 8007075C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4BB60 80070760 8FA50014 */  lw        $a1, 0x14($sp)
/* 4BB64 80070764 8FA60018 */  lw        $a2, 0x18($sp)
/* 4BB68 80070768 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4BB6C 8007076C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4BB70 80070770 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4BB74 80070774 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4BB78 80070778 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4BB7C 8007077C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4BB80 80070780 3C018008 */  lui       $at, %hi(gEffectTable+0x3A8)
/* 4BB84 80070784 8C21F5B8 */  lw        $at, %lo(gEffectTable+0x3A8)($at)
/* 4BB88 80070788 00200008 */  jr        $at
/* 4BB8C 8007078C 00000000 */   nop
