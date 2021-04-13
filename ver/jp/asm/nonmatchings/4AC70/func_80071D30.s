.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071D30
/* 4D130 80071D30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D134 80071D34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D138 80071D38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D13C 80071D3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D140 80071D40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D144 80071D44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D148 80071D48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D14C 80071D4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D150 80071D50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D154 80071D54 0C016885 */  jal       func_8005A214
/* 4D158 80071D58 24040062 */   addiu    $a0, $zero, 0x62
/* 4D15C 80071D5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D160 80071D60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D164 80071D64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D168 80071D68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D16C 80071D6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D170 80071D70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D174 80071D74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D178 80071D78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D17C 80071D7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D180 80071D80 3C018008 */  lui       $at, %hi(D_8007FB10)
/* 4D184 80071D84 8C21FB10 */  lw        $at, %lo(D_8007FB10)($at)
/* 4D188 80071D88 00200008 */  jr        $at
/* 4D18C 80071D8C 00000000 */   nop
