.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071D50
/* 4D150 80071D50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D154 80071D54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D158 80071D58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D15C 80071D5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D160 80071D60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D164 80071D64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D168 80071D68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D16C 80071D6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D170 80071D70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D174 80071D74 0C016959 */  jal       load_effect
/* 4D178 80071D78 24040062 */   addiu    $a0, $zero, 0x62
/* 4D17C 80071D7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D180 80071D80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D184 80071D84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D188 80071D88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D18C 80071D8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D190 80071D90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D194 80071D94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D198 80071D98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D19C 80071D9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D1A0 80071DA0 3C018008 */  lui       $at, %hi(D_8007FB40)
/* 4D1A4 80071DA4 8C21FB40 */  lw        $at, %lo(D_8007FB40)($at)
/* 4D1A8 80071DA8 00200008 */  jr        $at
/* 4D1AC 80071DAC 00000000 */   nop
