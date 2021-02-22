.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071D90
/* 4D190 80071D90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D194 80071D94 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D198 80071D98 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D19C 80071D9C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D1A0 80071DA0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D1A4 80071DA4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D1A8 80071DA8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D1AC 80071DAC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D1B0 80071DB0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D1B4 80071DB4 0C016885 */  jal       func_8005A214
/* 4D1B8 80071DB8 24040063 */   addiu    $a0, $zero, 0x63
/* 4D1BC 80071DBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D1C0 80071DC0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D1C4 80071DC4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D1C8 80071DC8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D1CC 80071DCC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D1D0 80071DD0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D1D4 80071DD4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D1D8 80071DD8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D1DC 80071DDC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D1E0 80071DE0 3C018008 */  lui       $at, %hi(D_8007FB28)
/* 4D1E4 80071DE4 8C21FB28 */  lw        $at, %lo(D_8007FB28)($at)
/* 4D1E8 80071DE8 00200008 */  jr        $at
/* 4D1EC 80071DEC 00000000 */   nop
