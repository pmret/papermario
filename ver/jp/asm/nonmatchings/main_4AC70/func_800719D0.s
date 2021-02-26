.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800719D0
/* 4CDD0 800719D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4CDD4 800719D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4CDD8 800719D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4CDDC 800719DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4CDE0 800719E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4CDE4 800719E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4CDE8 800719E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4CDEC 800719EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4CDF0 800719F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4CDF4 800719F4 0C016885 */  jal       func_8005A214
/* 4CDF8 800719F8 24040059 */   addiu    $a0, $zero, 0x59
/* 4CDFC 800719FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4CE00 80071A00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4CE04 80071A04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4CE08 80071A08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4CE0C 80071A0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4CE10 80071A10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4CE14 80071A14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4CE18 80071A18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4CE1C 80071A1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4CE20 80071A20 3C018008 */  lui       $at, %hi(D_8007FA38)
/* 4CE24 80071A24 8C21FA38 */  lw        $at, %lo(D_8007FA38)($at)
/* 4CE28 80071A28 00200008 */  jr        $at
/* 4CE2C 80071A2C 00000000 */   nop
