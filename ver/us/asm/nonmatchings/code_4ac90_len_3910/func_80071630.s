.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071630
/* 4CA30 80071630 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CA34 80071634 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CA38 80071638 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CA3C 8007163C AFA60018 */  sw        $a2, 0x18($sp)
/* 4CA40 80071640 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CA44 80071644 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CA48 80071648 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CA4C 8007164C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CA50 80071650 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CA54 80071654 0C016959 */  jal       load_effect
/* 4CA58 80071658 2404004F */   addiu    $a0, $zero, 0x4f
/* 4CA5C 8007165C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CA60 80071660 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CA64 80071664 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CA68 80071668 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CA6C 8007166C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CA70 80071670 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CA74 80071674 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CA78 80071678 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CA7C 8007167C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CA80 80071680 3C018008 */  lui       $at, %hi(gEffectTable+0x768)
/* 4CA84 80071684 8C21F978 */  lw        $at, %lo(gEffectTable+0x768)($at)
/* 4CA88 80071688 00200008 */  jr        $at
/* 4CA8C 8007168C 00000000 */   nop
